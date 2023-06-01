cmake_minimum_required(VERSION 3.20)
project(sil)

add_library(sil)
add_library(sil::sil ALIAS sil)
target_compile_features(sil PRIVATE cxx_std_17)

# ---Add source files---
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*)
target_sources(sil PRIVATE ${SOURCES})
target_include_directories(sil SYSTEM PUBLIC include)

# ---Pass the CMAKE_SOURCE_DIR to the code, so that we can make our paths relative to it---
target_compile_definitions(sil PRIVATE
    SIL_CMAKE_SOURCE_DIR=\"${CMAKE_SOURCE_DIR}\"
)

# ---Add libraries---
include(FetchContent)

# ---glm---
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm
    GIT_TAG efec5db081e3aad807d0731e172ac597f6a39447
)
FetchContent_MakeAvailable(glm)
target_link_libraries(sil PUBLIC glm)

# ---img---
FetchContent_Declare(
    img
    GIT_REPOSITORY https://github.com/CoolLibs/img
    GIT_TAG 46abe69077db8427471eb82b270f10cd4cde9812
)
FetchContent_MakeAvailable(img)
target_link_libraries(sil PRIVATE img::img)