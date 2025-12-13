#include <glad/glad.h>
#include <iostream>
#include "GraphicsApi.h"
#include "MeshRenderer.h"
#include "Camera.h"
#include "ShaderLoader.h"

Graphics::Graphics(int width, int height, MeshType meshType, GLFWwindow* context)
{
	glfwMakeContextCurrent(context);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "[GraphicsEngine] Failed to initialize GLAD\n";;
	}

	if (!glad_glClear) 
	{
		std::cout << "[GraphicsEngine] GLAD not loaded!\n" << std::endl;
	}

	glEnable(GL_DEPTH_TEST);

	shaderLoader = new ShaderLoader();
	// @TODO: Create enum for shader types and pass it as parameter
	GLuint shaderProgram = shaderLoader->CreateProgram("Assets/Shaders/FlatModel.vs",
		"Assets/Shaders/FlatModel.fs");

	// @TODO: Pass in Camera parameters in Init function
	camera = new Camera(45.0f, width, height, 0.1f, 100.0f, glm::vec3(0.0f, 0.0f, 3.0f));

	if (meshType < 0 || meshType > 4)
	{
		std::cout << "meshType value is invalid. Must be a value between 0 and 4";
		return;
	}

	meshRenderer = new MeshRenderer(meshType, camera);
	meshRenderer->SetProgram(shaderProgram);
	meshRenderer->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	meshRenderer->SetScale(glm::vec3(1.0f));
}

Graphics::~Graphics()
{
	delete shaderLoader;
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
	GRAPHICS_API Graphics* GetGraphicsEngine(int width, int height, MeshType meshType, GLFWwindow* context)
	{
		return new Graphics(width, height, meshType, context);
	}

	GRAPHICS_API void DeleteGraphicsEngine(Graphics* graphicsEngine)
	{
		delete graphicsEngine;
	}
}