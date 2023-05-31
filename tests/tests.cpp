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
    image.save("images/test_saved.png");
    image.save("images/test_saved.jpeg");
    image.save("images/test_saved.jpg");
}

// int main()
// {
//     for (int x = 0; x < image.width(); ++x)
//     {
//         for (int y = 0; y < image.height(); ++y)
//         {
//             glm::vec3&  pixel{image.pixel(x, y)};
//             float const greyscale{(pixel.r + pixel.g + pixel.b) / 3.f};
//             pixel = glm::vec3{greyscale, greyscale, greyscale};
//         }
//     }
//     image.save("images/output.png");
// }