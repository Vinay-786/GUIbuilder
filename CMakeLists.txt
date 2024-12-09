cmake_minimum_required(VERSION 3.22.1)

project(imguiExample)

#points to the vcpkg instance/ VCPKG_DIR should be set in
#your environment variable

set(VCPKG_DIR $ENV{VCPKG_DIR})
include(${VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake)

add_executable(${PROJECT_NAME} helloworld.cpp)

# set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1 CACHE INTERNAL "")



find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

