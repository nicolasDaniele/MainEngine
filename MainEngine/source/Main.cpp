#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include "GraphicsApi.h"

const int WIDTH = 800;
const int HEIGHT = 600;

const char* flatVSPath = "Assets/Shaders/FlatModel.vs";
const char* flatFSPath = "Assets/Shaders/FlatModel.fs";
const char* texturedVSPath = "Assets/Shaders/TexturedModel.vs";
const char* texturedFSPath = "Assets/Shaders/TexturedModel.fs";

float lastMouseXPos = WIDTH / 2.0f;
float lastMouseYPos = HEIGHT / 2.0f;
bool firstMouse = true;
float deltaTime = 0.0f;
float lastFrame = 0.0f;

void HandleInput(GLFWwindow* window);
void MouseMoveCallback(GLFWwindow* window, double xposIn, double yposIn);

static void glfwError(int id, const char* description)
{
	std::cout << description << std::endl;
}

int main()
{
	glfwSetErrorCallback(&glfwError);
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Main Engine", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "[MainEngine] Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwSetCursorPosCallback(window, MouseMoveCallback);
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "[MainEngine] Failed to initialize GLAD";
		return -1;
	}

	Graphics* graphics = GetGraphicsEngine(WIDTH, HEIGHT, MeshType::CUBE, window,
							texturedVSPath, texturedFSPath);

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		graphics->Render();

		glfwSwapBuffers(window);
		glfwPollEvents();
		HandleInput(window);
	}

	DeleteGraphicsEngine(graphics);
	glfwTerminate();

	return 0;
}

void HandleInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void MouseMoveCallback(GLFWwindow* window, double xposIn, double yposIn)
{
	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (firstMouse)
	{
		lastMouseXPos = xpos;
		lastMouseYPos = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastMouseXPos;
	float yoffset = lastMouseYPos - ypos;

	lastMouseXPos = xpos;
	lastMouseYPos = ypos;
}