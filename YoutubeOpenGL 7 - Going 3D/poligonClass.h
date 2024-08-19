#ifndef POLIGON_CLASS_H

#define POLIGON_CLASS_H
#include<filesystem>
namespace fs = std::filesystem;
#include"Windows.h"
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include "Main.h"

class Poligon {
public:
	GLfloat vertices[1];
	GLuint indices[1];

	Poligon(int width, int length, int height)
		: m_width(width), m_length(length), m_height(height)
	{};

	void Render(Shader& shaderProgram, GLFWwindow* window) {};
	void Clear() {};
	void Init(Shader& shaderProgram) {};

private: 
	VAO VAO1;
	VBO VBO1;
	EBO EBO1;
	Texture brickTex;
	std::string texPath;
	std::string parentDir;
	float rotation;
	double prevTime;
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 proj;
	GLuint uniID;

	int m_width{ 0 };
	int m_length{ 0 };
	int m_height{ 0 };
};				


#endif