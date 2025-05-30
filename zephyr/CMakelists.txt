cmake_minimum_required(VERSION 3.13.1)
set(BOARD nucleo_g070rb)
# include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
find_package(Zephyr)
project(test)

FILE(GLOB app_sources ../src/*.c*)
target_sources(app PRIVATE ${app_sources})
