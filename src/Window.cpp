#include "Window.h"
#include <iostream>

Window::Window(){
  if(!glfwInit()){
    std::cout<<"GLFW not initialized"<<std::endl;
  }

  window = glfwCreateWindow(800,600, "Orbenon", 0, 0);

  if(!window){
    std::cout<<"Window not created"<<std::endl;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    std::cout << "Failed to initialize OpenGL context" << std::endl;
  }
}
bool Window::ShouldClose(){
  return !glfwWindowShouldClose(window);
}
void Window::Update(){
  glfwPollEvents();
}
void Window::Render(){
  glfwSwapBuffers(window);
}