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

# ---img---
FetchContent_Declare(
    img
    GIT_REPOSITORY https://github.com/CoolLibs/img
    GIT_TAG 46abe69077db8427471eb82b270f10cd4cde9812
)
FetchContent_MakeAvailable(img)
target_link_libraries(sil PRIVATE img::img)

# ---exe_path---
FetchContent_Declare(
    exe_path
    GIT_REPOSITORY https://github.com/coolLibs/exe_path
    GIT_TAG 1d487a1317c36b61fea79f3a3fee188d323a71d4
)
FetchContent_MakeAvailable(exe_path)
target_link_libraries(sil PRIVATE exe_path::exe_path)

# ---CMakeUtils---
FetchContent_Declare(
    CMakeUtils
    GIT_REPOSITORY https://github.com/CoolLibs/CMakeUtils
    GIT_TAG 7ed041143da324d9c6a943009952c6c83b494fae
)
FetchContent_MakeAvailable(CMakeUtils)
include(${cmakeutils_SOURCE_DIR}/files_and_folders.cmake)

# # ---Functions to copy files and folders---
# include("third-party/CMakeUtils/files_and_folders.cmake")