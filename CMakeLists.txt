cmake_minimum_required(VERSION 3.14)

include_directories(vendor/glm)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/glm)

project("Orbenon")

add_executable(${PROJECT_NAME} src/main.cpp src/Shader.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC glfw GLAD)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw GLAD)