cmake_minimum_required(VERSION 3.14)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)

project("Orbenon++")

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC glfw GLAD)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw GLAD)