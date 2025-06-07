# Require a minimum version of CMake 
cmake_minimum_required(VERSION 3.10) 
 
# Set the project name and C++ version 
project(PersonalFinanceManager VERSION 1.0 LANGUAGES CXX) 
 
# Set the C++ standard to C++17 
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED True) 
set(CMAKE_CXX_EXTENSIONS OFF) 
 
# Add include directory for header files 
include_directories(include) 
 
# Define the executable 
file(GLOB_RECURSE SOURCES "src/*.cpp") 
add_executable(personal_finance_manager ${SOURCES}) 
 
# Set output directory for executables 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}) 
 
# Optional: Add compiler flags 
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_CLANG) 
    target_compile_options(personal_finance_manager PRIVATE -Wall -Wextra -Wpedantic) 
endif() 
 
# Message to confirm CMake configuration 
message(STATUS "Configuring PersonalFinanceManager") 
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}") 
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}") 
