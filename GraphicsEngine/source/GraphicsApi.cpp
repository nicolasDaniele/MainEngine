#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include "GraphicsApi.h"
#include "MeshRenderer.h"
#include "Camera.h"
#include "ShaderLoader.h"
#include "TextureLoader.h"

Graphics::Graphics(int width, int height, MeshType meshType, GLFWwindow* context, 
					const char* vertexShaderPath, const char* fragmentShaderPath)
{
	glfwMakeContextCurrent(context);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "[GraphicsEngine] Failed to initialize GLAD\n";
		return;
	}

	if (!glad_glClear) 
	{
		std::cout << "[GraphicsEngine] GLAD not loaded!\n" << std::endl;
		return;
	}

	glEnable(GL_DEPTH_TEST);

	shaderLoader = new ShaderLoader();

	GLuint shaderProgram = shaderLoader->CreateProgram(vertexShaderPath,
		fragmentShaderPath);

	TextureLoader tLoader;
	GLuint texture = tLoader.GetTextureID("Assets/Textures/wood.jpg");

	// @TODO: Pass in Camera parameters in Init function
	// Sugestion: Created a CameraParams struct
	camera = new Camera(45.0f, width, height, 0.1f, 100.0f, glm::vec3(0.0f, 0.0f, 3.0f));

	meshRenderer = new MeshRenderer(meshType, camera);
	meshRenderer->SetProgram(shaderProgram);
	meshRenderer->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	meshRenderer->SetScale(glm::vec3(1.0f));
}

Graphics::~Graphics()
{
	delete shaderLoader;
	delete camera;
	delete meshRenderer;
}

void Graphics::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1f, 0.0f, 0.12f, 1.0f);

	if (meshRenderer)
		meshRenderer->Draw();
}

MeshRenderer* Graphics::GetMesh()
{
	return meshRenderer;
}

Camera* Graphics::GetCamera()
{
	return camera;
}

extern "C"
{
	GRAPHICS_API Graphics* GetGraphicsEngine(int width, int height, MeshType meshType, GLFWwindow* context,
		const char* vertexShaderPath, const char* fragmentShaderPath)
	{
		return new Graphics(width, height, meshType, context, vertexShaderPath, fragmentShaderPath);
	}

	GRAPHICS_API void DeleteGraphicsEngine(Graphics* graphicsEngine)
	{
		delete graphicsEngine;
	}
}