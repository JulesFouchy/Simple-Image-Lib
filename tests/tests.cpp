#include <sil/sil.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Loading an image") // NOLINT
{
    sil::Image image{"images/test.png"};
    CHECK(image.width() == 300);
    CHECK(image.height() == 200);

    {
        glm::vec3 const bottom_left = image.pixel(0, 0);
        CHECK(doctest::Approx{bottom_left.r}.epsilon(1.f / 255.f) == 0.f);
        CHECK(doctest::Approx{bottom_left.g}.epsilon(1.f / 255.f) == 0.f);
        CHECK(doctest::Approx{bottom_left.b}.epsilon(1.f / 255.f) == 0.f);
    }

    {
        glm::vec3 const bottom_right = image.pixel(299, 0);
        CHECK(doctest::Approx{bottom_right.r}.epsilon(1.f / 255.f) == 1.f);
        CHECK(doctest::Approx{bottom_right.g}.epsilon(1.f / 255.f) == 0.f);
        CHECK(doctest::Approx{bottom_right.b}.epsilon(1.f / 255.f) == 0.f);
    }

    {
        glm::vec3 const top_left = image.pixel(0, 199);
        CHECK(doctest::Approx{top_left.r}.epsilon(1.f / 255.f) == 0.f);
        CHECK(doctest::Approx{top_left.g}.epsilon(1.f / 255.f) == 1.f);
        CHECK(doctest::Approx{top_left.b}.epsilon(1.f / 255.f) == 0.f);
    }

    {
        glm::vec3 const top_right = image.pixel(299, 199);
        CHECK(doctest::Approx{top_right.r}.epsilon(1.f / 255.f) == 1.f);
        CHECK(doctest::Approx{top_right.g}.epsilon(1.f / 255.f) == 1.f);
        CHECK(doctest::Approx{top_right.b}.epsilon(1.f / 255.f) == 0.f);
    }
}

TEST_CASE("Saving an image") // NOLINT
{
    sil::Image image{"images/test.png"};
    image.save("output/test_saved.png");
    image.save("output/test_saved.jpeg");
    image.save("output/test_saved.jpg");
}

TEST_CASE("Use case: remove red channel") // NOLINT
{
    sil::Image image{"images/test.png"};
    for (int x = 0; x < image.width(); ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            image.pixel(x, y).r = 0.f;
        }
    }
    image.save("output/UseCase_RemoveRedChannel.png");
}

TEST_CASE("Use case: greyscale") // NOLINT
{
    sil::Image image{"images/test.png"};
    for (int x = 0; x < image.width(); ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            glm::vec3&  pixel{image.pixel(x, y)};
            float const greyscale{(pixel.r + pixel.g + pixel.b) / 3.f};
            pixel = glm::vec3{greyscale, greyscale, greyscale};
        }
    }
    image.save("output/UseCase_Greyscale.png");
}

TEST_CASE("Use case: flip x") // NOLINT
{
    sil::Image image{"images/test.png"};
    for (int x = 0; x < image.width() / 2; ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            std::swap(
                image.pixel(x, y),
                image.pixel(image.width() - 1 - x, y));
        }
    }
    image.save("output/UseCase_FlipX.png");
}

TEST_CASE("Use case: draw disk") // NOLINT
{
    sil::Image image{200, 100};
    for (int x = 0; x < image.width(); ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            float const distance_to_center = glm::distance(
                glm::vec2{static_cast<float>(image.width()) / 2.f, static_cast<float>(image.height()) / 2.f},
                glm::vec2{x, y});
            bool const is_in_disk = distance_to_center < static_cast<float>(image.height()) / 2.f;
            image.pixel(x, y)     = is_in_disk
                                        ? glm::vec3{1.f}
                                        : glm::vec3{0.f};
        }
    }
    image.save("output/UseCase_DrawDisk.png");
}