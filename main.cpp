#include <iostream>
#include "GLFW/glfw3.h"

int main(){
  GLFWwindow* window;

  if(!glfwInit()){
    std::cout<<"GLFW not initialized"<<std::endl;
  }

  window = glfwCreateWindow(800,600, "Orbenon++", 0, 0);

  if(!window){
    std::cout<<"Window not created"<<std::endl;
  }

  glfwMakeContextCurrent(window);

  while(!glfwWindowShouldClose(window)){
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}