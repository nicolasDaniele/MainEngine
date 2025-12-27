#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include "GraphicsEngine/GraphicsApi.h"
#include "Vectors.h"

using Vec3 = CoreMath::Vec3;

const int WIDTH = 960;
const int HEIGHT = 600;

const char* FLAT_VS_PATH = "Assets/Shaders/FlatModel.vs";
const char* FLAT_FS_PATH = "Assets/Shaders/FlatModel.fs";
const char* TEXTURED_VS_PATH = "Assets/Shaders/TexturedModel.vs";
const char* TEXTURED_FS_PATH = "Assets/Shaders/TexturedModel.fs";

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

	// -------------------- GRAHICS SETUP -------------------- \\

	CameraParams cameraParams;
	cameraParams.fieldOfView = 45.0f;
	cameraParams.width = WIDTH;
	cameraParams.height = HEIGHT;
	cameraParams.nearPlane = 0.1f;
	cameraParams.farPlane = 100.0f;
	cameraParams.position = Vec3(0.0f, 0.0f, 8.0f);

	Graphics* graphics = GetGraphicsEngine(/*window, */cameraParams);

	Vec3 ballPosition = Vec3(0.0f, 1.0f, 0.0f);
	MeshRenderer* ball = CreateMeshRenderer(graphics, MeshType::M_SPHERE,
		ballPosition,
		//Vec3(1.0f, 1.0f, 1.0f),
		Vec3(0.5f, 0.5f, 0.5f),
		Vec3(0.9f, 0.2f, 0.0f),
		FLAT_VS_PATH, FLAT_FS_PATH);

	Vec3 floorPosition = Vec3(0.0f, -1.0f, 0.0f);
	MeshRenderer* floor = CreateMeshRenderer(graphics, MeshType::M_CUBE,
		floorPosition,
		//Vec3(0.5f, 0.5f, 0.5f),
		Vec3(4.0f, 0.2f, 4.0f),
		Vec3(0.2f, 0.8f, .2f),
		FLAT_VS_PATH, FLAT_FS_PATH);

	// ------------------- END GRAHICS SETUP ------------------- \\


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

	DestroyGraphicsEngine(graphics);
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