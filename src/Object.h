#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Object{
public:
  Object(unsigned int pvao, int pcount):vao(pvao), count(pcount){}

  unsigned int vao;
  int count;
  glm::mat4 objectTransform = glm::mat4(1.0f);

  void Displace(float x, float y){
    objectTransform = glm::translate(objectTransform, glm::vec3(x, y,0));
  }

  glm::mat4 GetTransform(){
    return objectTransform;
  }
};