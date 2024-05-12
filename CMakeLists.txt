cmake_minimum_required(VERSION 3.16.3)
project(IMR_writer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

file(GLOB IMR_WRITER_SOURCE "IMR_writer/*.cc")
add_library(IMR_core STATIC ${IMR_WRITER_SOURCE})
target_include_directories(IMR_core PUBLIC IMR_writer)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)
file(GLOB IMR_WRITER_HEADERS "IMR_writer/*.h")
install(FILES ${IMR_WRITER_HEADERS}
    DESTINATION include/IMR_writer
)
install(TARGETS IMR_core
    LIBRARY DESTINATION lib
)

# example
add_executable(simple_example example/main.cc)
target_link_libraries(simple_example PRIVATE IMR_core)
target_include_directories(simple_example PRIVATE IMR_writer)