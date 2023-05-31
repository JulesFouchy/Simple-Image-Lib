cmake_minimum_required(VERSION 3.20)
project(sil-tests)

add_executable(${PROJECT_NAME} tests.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

add_subdirectory(.. ${CMAKE_CURRENT_SOURCE_DIR}/build/sil)
target_link_libraries(${PROJECT_NAME} PRIVATE sil::sil)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})