#include <iostream>
#include "glad/glad.h"
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

  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    std::cout << "Failed to initialize OpenGL context" << std::endl;
  }

  while(!glfwWindowShouldClose(window)){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,0,0,1);
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}