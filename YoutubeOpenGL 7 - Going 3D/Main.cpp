//------- Ignore this ----------
#include<filesystem>
namespace fs = std::filesystem;
//------------------------------
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
//#include"poligonClass.h"

const unsigned int width = 1280;
const unsigned int height = 720;
//Translate
int Scale = 3;
float y = 0.9f;
float z = 5.9f;

// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES												/        COLORS      /   TexCoord  //
Scale * 0,      Scale*-(sqrt(6) / 3) / 2	,		Scale*   -.5773502691896f,			0.83f, 0.70f, 0.44f,	0.294f, 0.668f, //0
Scale * 0.5f,   Scale*-(sqrt(6) / 3) / 2	,		Scale*		sqrt(3) / 6  ,			0.83f, 0.70f, 0.44f,	0.432f, 0.347f,//1
Scale * -0.5f,  Scale*-(sqrt(6) / 3) / 2	,		Scale*		sqrt(3) / 6  ,			0.83f, 0.70f, 0.44f,	0.159f, 0.347f,//2
Scale * 0,      Scale* (sqrt(6) / 3) / 2	,		Scale*				  0  ,			0.92f, 0.86f, 0.76f,	0.582f, 0.668f,//3
Scale * 0,      Scale* (sqrt(6) / 3) / 2	,		Scale*				  0  ,			0.92f, 0.86f, 0.76f,	0.0f, 0.668f,//4
Scale * 0,      Scale* (sqrt(6) / 3) / 2	,		Scale*				  0  ,			0.92f, 0.86f, 0.76f,	0.293f, 0.0f,//5

};

// Indices for vertices order
GLuint indices[] =
{
	0,1,2,
	0,3,1,
	1,5,2,
	2,4,0,

};

/*

0,      -(sqrt(6) / 3) / 2 ,   0 - 0.5773507f,									0.83f, 0.70f, 0.44f,	0.489f,	0.333f,//6
0.5f,   -(sqrt(6) / 3) / 2 ,   sqrt(3) / 2 - 0.5773507f,						0.83f, 0.70f, 0.44f,	0.611f,	0.056f,//7
-0.5f,  -(sqrt(6) / 3) / 2 ,   sqrt(3) / 2 - 0.5773507f,						0.83f, 0.70f, 0.44f,	0.731f,	0.333f,//8
0,       (sqrt(6) / 3) / 2 ,   (sqrt(3) / 2) + .2886756f - 0.5773507f,			0.92f, 0.86f, 0.76f,	0.863f,	0.622f,//9
0.5f,    (sqrt(6) / 3) / 2 ,   .2886756f - 0.5773507f,							0.92f, 0.86f, 0.76f,	0.365f,	0.625f,//10
-0.5f,   (sqrt(6) / 3) / 2 ,   .2886756f - 0.5773507f,							0.92f, 0.86f, 0.76f,	0.62f,	0.62f,//11
0.5f,   -(sqrt(6) / 3) / 2 ,   sqrt(3) / 2 - 0.5773507f,						0.83f, 0.70f, 0.44f,	0.249f,	0.333f,//12
-0.5f,	-(sqrt(6) / 3) / 2 ,   sqrt(3) / 2 - 0.5773507f,						0.83f, 0.70f, 0.44f,	0,		0.33f,//13
0,       (sqrt(6) / 3) / 2 ,   (sqrt(3) / 2) + .2886756f - 0.5773507f,			0.83f, 0.70f, 0.44f,	0.122f,	0.627f,//14
-0.5f,   (sqrt(6) / 3) / 2 ,   .2886756f - 0.5773507f,							0.92f, 0.86f, 0.76f,	0.251f,	0.904f//15



	0 + 6,1 + 6,2 + 6,
	8 + 6,4 + 6,9 + 6,
	0 + 6,4 + 6,6 + 6,
	2 + 6,5 + 6,0 + 6,
	7 + 6,6 + 6,8 + 6,
	4 + 6,8 + 6,6 + 6,
	2 + 6,3 + 6,5 + 6,
	0 + 6,5 + 6,4 + 6

*/


// Vertices coordinates
GLfloat verticesC[] =
{ //     COORDINATES															/        COLORS      /   TexCoord  //
0,      -(sqrt(6)/3)/2 ,   0							-0.5773507f,				0.83f, 0.70f, 0.44f,	0.489f,	0.333f,//0
0.5f,   -(sqrt(6)/3)/2 ,   sqrt(3)/2					-0.5773507f,					0.83f, 0.70f, 0.44f,	0.611f,	0.056f,//1
-0.5f,  -(sqrt(6)/3)/2 ,   sqrt(3)/2					-0.5773507f,					0.83f, 0.70f, 0.44f,	0.731f,	0.333f,//2
0,       (sqrt(6)/3)/2 ,   (sqrt(3)/2)+.2886756f		-0.5773507f,					0.92f, 0.86f, 0.76f,	0.863f,	0.622f,//3
0.5f,    (sqrt(6)/3)/2 ,   .2886756f					-0.5773507f,				0.92f, 0.86f, 0.76f,	0.365f,	0.625f,//4
-0.5f,   (sqrt(6)/3)/2 ,   .2886756f					-0.5773507f,				0.92f, 0.86f, 0.76f,	0.62f,	0.62f,//5
0.5f,   -(sqrt(6) / 3) / 2 ,   sqrt(3) / 2				-0.5773507f,						0.83f, 0.70f, 0.44f,	0.249f,	0.333f,//6
- 0.5f, -(sqrt(6) / 3) / 2 ,   sqrt(3) / 2				-0.5773507f,						0.83f, 0.70f, 0.44f,	0,		0.33f,//7
0,       (sqrt(6) / 3) / 2 ,   (sqrt(3) / 2) +.2886756f	-0.5773507f,			0.83f, 0.70f, 0.44f,	0.122f,	0.627f,//8
- 0.5f,  (sqrt(6) / 3) / 2 ,   .2886756f				-0.5773507f,							0.92f, 0.86f, 0.76f,	0.251f,	0.904f//9
};																				

// Indices for vertices order
GLuint indicesC[] =
{
	0,1,2,
	8,4,9,
	0,4,6,
	2,5,0,
	7,6,8,
	4,8,6,
	2,3,5,
	0,5,4

};


void Piramid1(Shader& shaderProgram, GLFWwindow* window)
{


	// Generates Vertex Array Object and binds it
	VAO VAO2;
	VAO2.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO2(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO2(indices, sizeof(indices));

	// Links VBO attributes such as coordinates and colors to VAO
	VAO2.LinkAttrib(VBO2, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO2.LinkAttrib(VBO2, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO2.LinkAttrib(VBO2, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO2.Unbind();
	VBO2.Unbind();
	EBO2.Unbind();

	// Gets ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	/*
	* I'm doing this relative path thing in order to centralize all the resources into one folder and not
	* duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
	* folder and then give a relative path from this folder to whatever resource you want to get to.
	* Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
	*/
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string texPath = "/Resources/YoutubeOpenGL 7 - Going 3D/";

	// Texture
	Texture brickTex((parentDir + texPath + "FlaurosC.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);

	// Original code from the tutorial
	/*Texture brickTex("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);*/

	// Variables that help the rotation of the pyramid
	float rotation = 0.0f;
	double prevTime = glfwGetTime();

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();

		// Simple timer
		double crntTime = glfwGetTime();
		if (crntTime - prevTime >= 1 / 60)
		{
			rotation += 0.5f;
			prevTime = crntTime;
		}

		// Initializes matrices so they are not the null matrix
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		// Assigns different transformations to each matrix
		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.5f, -5.0f));
		proj = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

		// Outputs the matrices into the Vertex Shader
		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

		// Assigns a value to the uniform; NOTE: Must always be done after activating the Shader Program
		glUniform1f(uniID, 0.5f);
		// Binds texture so that is appears in rendering
		brickTex.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO2.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO2.Delete();
	VBO2.Delete();
	EBO2.Delete();
	brickTex.Delete();


}

void Center(Shader& shaderProgram, GLFWwindow* window)
{

	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(verticesC, sizeof(verticesC));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indicesC, sizeof(indicesC));

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// Gets ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	/*
	* I'm doing this relative path thing in order to centralize all the resources into one folder and not
	* duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
	* folder and then give a relative path from this folder to whatever resource you want to get to.
	* Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
	*/
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string texPath = "/Resources/YoutubeOpenGL 7 - Going 3D/";

	// Texture
	Texture brickTex((parentDir + texPath + "DadoCentro.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);

	// Original code from the tutorial
	/*Texture brickTex("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);*/

	// Variables that help the rotation of the pyramid
	float rotation = 0.0f;
	double prevTime = glfwGetTime();

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();

		// Simple timer
		double crntTime = glfwGetTime();
		if (crntTime - prevTime >= 1 / 60)
		{
			rotation += 0.5f;
			prevTime = crntTime;
		}

		// Initializes matrices so they are not the null matrix
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		// Assigns different transformations to each matrix
		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0, -5.0f));
		proj = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

		// Outputs the matrices into the Vertex Shader
		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

		// Assigns a value to the uniform; NOTE: Must always be done after activating the Shader Program
		glUniform1f(uniID, 0.5f);
		// Binds texture so that is appears in rendering
		brickTex.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(indicesC) / sizeof(int), GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	brickTex.Delete();
}


int main()
{

	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);
	Shader shaderProgram("default.vert", "default.frag");

	Piramid1(shaderProgram,window);

	/*
	Poligon center = Poligon(verticesC, indicesC, 80, 20);
	Poligon piramid1 = Poligon(vertices, indices, 36,12);

	piramid1.Init(shaderProgram);
	center.Init(shaderProgram);

	//Piramid1(shaderProgram,window);
	//Center(shaderProgram,window);
	while (!glfwWindowShouldClose(window))
	{
		piramid1.Render(shaderProgram,window);
		center.Render(shaderProgram, window);
	}

	piramid1.Clear();
	*/


	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}


void Test2V(GLFWwindow* window) {



	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");
	Shader shaderProgram1("default.vert", "default.frag");

	//Piramid1(shaderProgram, window);
		// Generates Vertex Array Object and binds it
	VAO VAO2;
	VAO2.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO2(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO2(indices, sizeof(indices));

	// Links VBO attributes such as coordinates and colors to VAO
	VAO2.LinkAttrib(VBO2, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO2.LinkAttrib(VBO2, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO2.LinkAttrib(VBO2, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO2.Unbind();
	VBO2.Unbind();
	EBO2.Unbind();

	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(verticesC, sizeof(verticesC));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indicesC, sizeof(indicesC));

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();



	// Gets ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");
	GLuint uniID1 = glGetUniformLocation(shaderProgram1.ID, "scale");

	/*
	* I'm doing this relative path thing in order to centralize all the resources into one folder and not
	* duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
	* folder and then give a relative path from this folder to whatever resource you want to get to.
	* Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
	*/
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string texPath = "/Resources/YoutubeOpenGL 7 - Going 3D/";

	// Texture
	Texture brickTex((parentDir + texPath + "CD1.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);

	std::string parentDir1 = (fs::current_path().fs::path::parent_path()).string();
	std::string texPath1 = "/Resources/YoutubeOpenGL 7 - Going 3D/";

	// Texture
	Texture brickTex1((parentDir1 + texPath1 + "DadoCentro.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex1.texUnit(shaderProgram1, "tex0", 0);

	// Original code from the tutorial
	/*Texture brickTex("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);*/

	// Variables that help the rotation of the pyramid
	float rotation = 0.0f;
	double prevTime = glfwGetTime();

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		shaderProgram1.Activate();

		// Simple timer
		double crntTime = glfwGetTime();
		if (crntTime - prevTime >= 1 / 60)
		{
			rotation += 0.5f;
			prevTime = crntTime;
		}

		// Initializes matrices so they are not the null matrix
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		// Assigns different transformations to each matrix
		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
		proj = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

		// Outputs the matrices into the Vertex Shader
		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

		// Outputs the matrices into the Vertex Shader
		int modelLoc1 = glGetUniformLocation(shaderProgram1.ID, "model");
		glUniformMatrix4fv(modelLoc1, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc1 = glGetUniformLocation(shaderProgram1.ID, "view");
		glUniformMatrix4fv(viewLoc1, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc1 = glGetUniformLocation(shaderProgram1.ID, "proj");
		glUniformMatrix4fv(projLoc1, 1, GL_FALSE, glm::value_ptr(proj));

		// Assigns a value to the uniform; NOTE: Must always be done after activating the Shader Program
		glUniform1f(uniID, 0.5f);
		glUniform1f(uniID1, 0.5f);
		// Binds texture so that is appears in rendering
		brickTex.Bind();
		brickTex1.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO2.Bind();
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
		glDrawElements(GL_TRIANGLES, sizeof(indicesC) / sizeof(int), GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}


	// Delete all the objects we've created
	VAO2.Delete();
	VBO2.Delete();
	EBO2.Delete();
	brickTex.Delete();

	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	brickTex.Delete();


	shaderProgram.Delete();
	shaderProgram1.Delete();
}