#include "Shader.h"

Shader::Shader(const char* vSource, const char* fSource) {
	unsigned int vertex = CreateShader(vSource, GL_VERTEX_SHADER);
	unsigned int fragment = CreateShader(fSource, GL_FRAGMENT_SHADER);
	
	int success;
	char infoLog[512];

	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "Error in Program\n" << infoLog << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	glUseProgram(program);
}
unsigned int Shader::CreateShader(const char* source, unsigned int type) {
	unsigned int shader;
	int success;
	char infoLog[512];

	shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::string str_type;
		if (type == GL_VERTEX_SHADER)
			str_type = "Vertex";
		else
			str_type = "Fragment";
		std::cout << "Error in " << str_type << "Shader" << infoLog << std::endl;
	};

	return shader;
}
std::string Shader::parseFile(std::string path) {
	std::string file;
	std::stringstream ss;
	std::fstream stream(path);
	while (std::getline(stream, file)) {
		ss << file << "\n";
	}
	return ss.str();
}