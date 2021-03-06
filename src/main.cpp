#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.h"
#include "Loader.h"
#include "Renderer.h"
#include "Window.h"

int main(){
  Window window;

  float pos[] = {
    25, 25,-25, 25,-25,-25, 25,-25
  };
  unsigned int ind[] = {
    0,1,2,0,2,3
  };

  Object* obj1 = Loader::Load(pos, ind);

  std::string v = Shader::parseFile("../Vertex.glsl");
  std::string f = Shader::parseFile("../Fragment.glsl");
  Shader shader(v.c_str(), f.c_str());

  glm::mat4 proj = glm::ortho(-800.0f, 800.0f, -600.0f, 600.0f, -1.0f, 1.0f);
  Shader::SetMat4(shader.GetProgram(),"proj", proj);

  double previousTime = glfwGetTime();
  float deltaTime = 0.2;

  obj1->accelerationY = -1.0f;
  while(window.ShouldClose()){
    double currentTime = glfwGetTime();
    double deltaTime = currentTime-previousTime;
    previousTime = currentTime;

    obj1->Update(deltaTime);
    Shader::SetMat4(shader.GetProgram(),"transform", obj1->GetTransform());

    Renderer::PrepareColor();
    Renderer::Render(obj1);

    window.Update();
    window.Render();
  }

  glfwTerminate();
  return 0;
}