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

  float pos[] = {
    0,0,0.5,0,0,0.5
  };

  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), pos, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

  while(!glfwWindowShouldClose(window)){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,0,0,1);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}