#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Window{
public:
  Window();
  bool ShouldClose();
  void Update();
  void Render();
  GLFWwindow* window;
};