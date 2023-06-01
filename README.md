# Simple-Image-Lib

*sil* is a minimalistic library that allows you to load an image, edit its pixels, and save it back.

- [Installation](#installation)
- [Examples](#examples)
  - [Remove red channel](#remove-red-channel)

## Installation

Simply add these lines to your *CMakeLists.txt*:

```cmake
# Download the library
include(FetchContent)
FetchContent_Declare(
    sil
    GIT_REPOSITORY https://github.com/JulesFouchy/Simple-Image-Lib
    GIT_TAG 5037b3f9ca83f88a6efa270cc30f19d7b0150aa7
)
FetchContent_MakeAvailable(sil)

# Link the library into your project
target_link_libraries(${PROJECT_NAME} PRIVATE sil)

# Declare your image folder.s
sil_image_folder(${PROJECT_NAME} "images")
```

⚠️ All your images must be in the folder.s declared in the *CMakeLists.txt* with `sil_image_folder(...)`. In this example you would have an *images* folder at the root of your project (alongside your *CMakeLists.txt*). This ensures that the relative paths will be correct no matter your setup / current working directory.

## Examples

### Remove red channel

```cpp
#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/input.png"};
    for (int x = 0; x < image.width(); ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            image.pixel(x, y).r = 0.f;
        }
    }
    image.save("images/output.png");
}
```
