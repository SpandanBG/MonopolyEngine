# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Monopoly TXT")

# Include sub-projects.
include_directories(${CMAKE_SOURCE_DIR}/src)
add_subdirectory ("src")
