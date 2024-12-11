cmake_minimum_required(VERSION 3.22.1)

project(imguiExample)

#points to the vcpkg instance/ VCPKG_DIR should be set in
#your environment variable

set(VCPKG_DIR $ENV{VCPKG_DIR})
include(${VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake)

add_executable(${PROJECT_NAME} main.cpp guiClass.cpp)

# set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1 CACHE INTERNAL "")


find_package(glad CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)
