# Simple-Image-Lib

*sil* is a minimalistic library that allows you to load an image, edit its pixels, and save it back.

- [Installation](#installation)
- [Usage](#usage)
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
target_link_libraries(${PROJECT_NAME} PRIVATE sil::sil)
```

## Usage

⚠️ All the image paths must be relative to the directory containing your *CMakeLists.txt*. So for example if your "hello.png" image is in the same folder as your *CMakeLists.txt*, the path to use would simply be "hello.png".

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
    image.save("output/output.png");
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
