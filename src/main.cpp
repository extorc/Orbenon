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

  std::string v = Shader::parseFile("C:/dev/Orbenon++/Vertex.glsl");
  std::string f = Shader::parseFile("C:/dev/Orbenon++/Fragment.glsl");
  Shader shader(v.c_str(), f.c_str());

  glm::mat4 proj = glm::ortho(-800.0f, 800.0f, -600.0f, 600.0f, -1.0f, 1.0f);
  Shader::SetMat4(shader.GetProgram(),"proj", proj);


  while(window.ShouldClose()){
    // obj1->Displace(.00005, .00005);
    Shader::SetMat4(shader.GetProgram(),"transform", obj1->GetTransform());

    Renderer::PrepareColor();
    Renderer::Render(obj1);

    window.Update();
    window.Render();
  }

  glfwTerminate();
  return 0;
}