#pragma once
#include "glad/glad.h"

struct Object{
  unsigned int vao;
  int count;
};

class Loader{
public:
  static Object Load(float* pos, unsigned int* ind);
};