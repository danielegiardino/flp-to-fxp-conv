cmake_minimum_required(VERSION 3.10)
project(flp_to_fxp_conv)

# Add include directory for lib_fun.h
include_directories(lib)

# Add executable
add_executable(flp_to_fxp_conv main.c lib/lib_fun.c lib/lib_config.c)

# Link math library
target_link_libraries(flp_to_fxp_conv m)