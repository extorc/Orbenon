#pragma once
#include "glad/glad.h"
#include "Object.h"

class Loader{
public:
  static Object* Load(float* pos, unsigned int* ind);
};