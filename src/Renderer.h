#pragma once
#include "glad/glad.h"
#include "Loader.h"

class Renderer{
public:
  static void PrepareColor(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(.84, .84, .84, 1);
  }

  static void Render(Object obj);
};