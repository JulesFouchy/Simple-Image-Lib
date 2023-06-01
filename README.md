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
    GIT_TAG 10a75ab4888c62ae91f96822dd8adc558d622365
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

<figure>
  <img src="https://github.com/JulesFouchy/Simple-Image-Lib/assets/45451201/9b9e070d-6024-45f6-bde9-c819595ba853" alt="input" />
  <figcaption>input.png</figcaption>
</figure>

<figure>
  <img src="https://github.com/JulesFouchy/Simple-Image-Lib/assets/45451201/f6afbfc9-d062-4f6d-8ff0-88f09c848be1" alt="output" />
  <figcaption>output.png</figcaption>
</figure>
