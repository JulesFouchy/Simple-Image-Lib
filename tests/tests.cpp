#include <iostream>
#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/input.png"};
    for (int x = 0; x < image.width(); ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            glm::vec3&  pixel{image.pixel(x, y)};
            float const greyscale{(pixel.r + pixel.g + pixel.b) / 3.f};
            pixel = glm::vec3{greyscale, greyscale, greyscale};
        }
    }
    image.save("images/output.png");
}