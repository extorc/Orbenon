#version 330 core

layout (location = 0) in vec3 pos;
out vec4 vcol;

uniform mat4 proj;
uniform mat4 transform;

void main(){
  gl_Position = transform * proj * vec4(pos, 1.0);
  vcol = vec4(1, 0, 0, 1.0);  
}