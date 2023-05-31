#include "sil.hpp"
#include <exe_path/exe_path.h>
#include <img/img.hpp>
#include <iostream>

namespace sil {

static std::filesystem::path make_absolute_path(std::filesystem::path path)
{
    auto const res = [&]() {
        if (!path.is_relative())
            return path;
        return exe_path::dir() / path;
    }();

    if (!std::filesystem::exists(res))
    {
        using namespace std::literals;
        auto const msg = "Path \""s + res.string() + "\" does not exist. Make sure you didn't misspell it or made it relative to the wrong folder. All relative paths will be relative to your executable's directory.";
        std::cerr << msg << '\n';
        throw std::runtime_error{msg};
    }

    return res;
}

Image::Image(std::filesystem::path const& path)
{
    auto const image = img::load(make_absolute_path(path), 3);
    _width           = static_cast<int>(image.width());
    _height          = static_cast<int>(image.height());
    _pixels.resize(static_cast<size_t>(_width) * static_cast<size_t>(_height));
    for (size_t i = 0; i < _pixels.size(); ++i)
    {
        _pixels[i].r = static_cast<float>(image.data()[3 * i + 0]) / 255.f; // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
        _pixels[i].g = static_cast<float>(image.data()[3 * i + 1]) / 255.f; // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
        _pixels[i].b = static_cast<float>(image.data()[3 * i + 2]) / 255.f; // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
    }
}

Image::Image(int width, int height)
    : _pixels(static_cast<size_t>(width) * static_cast<size_t>(height))
    , _width{width}
    , _height{height}
{
}

glm::vec3& Image::pixel(int x, int y)
{
    assert(x >= 0);
    assert(x < _width);
    assert(y >= 0);
    assert(y < _height);
    return _pixels[x + y * _width];
}

glm::vec3 const& Image::pixel(int x, int y) const
{
    assert(x >= 0);
    assert(x < _width);
    assert(y >= 0);
    assert(y < _height);
    return _pixels[x + y * _width];
}

} // namespace sil