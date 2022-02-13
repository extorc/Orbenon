#include "Renderer.h"

void Renderer::Render(Object obj){
  glBindVertexArray(obj.vao);
  glDrawElements(GL_TRIANGLES, obj.count, GL_UNSIGNED_INT, nullptr);
}