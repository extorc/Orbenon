#pragma once
#include "glad/glad.h"
#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Shader {
public:
    Shader(const char* vSource, const char* fSource);
    unsigned int CreateShader(const char* source, unsigned int type);
    static std::string parseFile(std::string path);

    static void Set4F(unsigned int program, const char* variable, float v0, float v1, float v2, float v3)
    {
        glUniform4f(glGetUniformLocation(program, variable), v0, v1, v2, v3);
    }
    static void Set1i(unsigned int program, const char* variable, int v0)
    {
        glUniform1i(glGetUniformLocation(program, variable), v0);
    }
    static void SetMat4(unsigned int program, const char* variable, glm::mat4 v0)
    {
        glUniformMatrix4fv(glGetUniformLocation(program, variable), 1, GL_FALSE, &v0[0][0]);
    }
    static void Set1f(unsigned int program, const char* variable, double v0)
    {
        glUniform1f(glGetUniformLocation(program, variable), (float)v0);
    }
    static void SetVec3(unsigned int program, const char* variable, glm::vec3 v0)
    {
        glUniform3fv(glGetUniformLocation(program, variable), 1, &v0[0]);
    }
    unsigned int GetProgram() const { return program; }

private:
    unsigned int program;
};