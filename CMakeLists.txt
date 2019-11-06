cmake_minimum_required(VERSION 3.0.0)
project(RailTracking VERSION 0.1.0)

find_package(Eigen3 REQUIRED)
find_package(Ceres)
enable_testing()
find_package(GTest REQUIRED)

include_directories(/usr/local/include/eigen3) #find package??
include_directories(include)

add_library(RailTracking
src/rail.cc
src/camera.cc)
target_link_libraries(RailTracking ceres)

add_executable(utest test/tests.cc)
target_link_libraries(utest gtest gtest_main -lpthread)

add_executable(cereseigen test/cereseigen.cc)