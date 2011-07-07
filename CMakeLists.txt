
cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

SET(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)

project(demo_embed) 
       
include_directories("C:/Python27/include")
include_directories("C:/Python27/lib/site-packages/numpy/core/include")
link_directories("C:/Python27/libs")
 
add_executable(run_demo sample_application.cpp wrapper_outer.hpp)
