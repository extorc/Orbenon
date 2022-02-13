#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.h"
#include "Loader.h"
#include "Renderer.h"

int main(){
  GLFWwindow* window;

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

  float pos[] = {
    0.025, 0.025,-0.025, 0.025,-0.025,-0.025, 0.025,-0.025
  };
  unsigned int ind[] = {
    0,1,2,0,2,3
  };

  Object obj1 = Loader::Load(pos, ind);

  std::string v = Shader::parseFile("C:/dev/Orbenon++/Vertex.glsl");
  std::string f = Shader::parseFile("C:/dev/Orbenon++/Fragment.glsl");
  Shader shader(v.c_str(), f.c_str());

  glm::mat4 proj = glm::ortho(-1.33f, 1.33f, -1.0f, 1.0f, -1.0f, 1.0f);
  Shader::SetMat4(shader.GetProgram(),"proj", proj);

  while(!glfwWindowShouldClose(window)){
    Renderer::PrepareColor();
    Renderer::Render(obj1);
    
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}