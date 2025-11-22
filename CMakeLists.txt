cmake_minimum_required(VERSION 3.15)
project(MyApp)

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/cpp/*.cpp
)

add_executable(MyApp ${SOURCES})

find_package(fmt REQUIRED)
target_link_libraries(MyApp PRIVATE fmt::fmt)

# Find Python + headers + numpy
find_package(Python3 REQUIRED COMPONENTS Interpreter Development NumPy)

# Include Python and NumPy headers
target_include_directories(MyApp PRIVATE
    ${Python3_INCLUDE_DIRS}
    ${Python3_NumPy_INCLUDE_DIRS}
)

# Link against Python library
target_link_libraries(MyApp PRIVATE Python3::Python)

# matplotlibcpp location
target_include_directories(MyApp PRIVATE cpp/external)
