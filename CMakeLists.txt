cmake_minimum_required(VERSION 3.20)
project(sil)

add_library(sil)
add_library(sil::sil ALIAS sil)
target_compile_features(sil PRIVATE cxx_std_17)

# ---Add source files---
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*)
target_sources(sil PRIVATE ${SOURCES})
target_include_directories(sil SYSTEM PUBLIC include)

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

# # ---Functions to copy files and folders---
# include("third-party/CMakeUtils/files_and_folders.cmake")