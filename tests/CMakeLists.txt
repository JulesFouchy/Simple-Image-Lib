cmake_minimum_required(VERSION 3.20)
project(sil-tests)

add_executable(${PROJECT_NAME} tests.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

add_subdirectory(.. ${CMAKE_CURRENT_SOURCE_DIR}/build/sil)
target_link_libraries(${PROJECT_NAME} PRIVATE sil::sil)

# ---Add doctest---
include(FetchContent)
FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/doctest/doctest
    GIT_TAG b7c21ec5ceeadb4951b00396fc1e4642dd347e5f
)
FetchContent_MakeAvailable(doctest)
target_link_libraries(${PROJECT_NAME} PRIVATE doctest::doctest)