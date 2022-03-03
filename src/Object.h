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
    objectTransform = glm::translate(objectTransform, glm::vec3(x/800, y/600,0));
  }

  glm::mat4 GetTransform(){
    return objectTransform;
  }

  void Update(float deltaTime){
    velocityX += accelerationX;
    velocityY += accelerationY;
    Displace(velocityX*deltaTime, velocityY*deltaTime);
  }

  float velocityX = 0.0f;
  float velocityY = 0.0f;
  float accelerationX = 0.0f;
  float accelerationY = 0.0f;
};