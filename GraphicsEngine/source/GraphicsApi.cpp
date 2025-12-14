#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include "GraphicsApi.h"
#include "MeshRenderer.h"
#include "Camera.h"
#include "ShaderLoader.h"

Graphics::Graphics(GLFWwindow* context, CameraParams cameraParams)
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

	camera = new Camera(cameraParams);
}

Graphics::~Graphics()
{
	delete camera;
	
	for (MeshRenderer* renderer : meshRenderers)
		delete renderer;
}

void Graphics::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1f, 0.0f, 0.12f, 1.0f);

	for (MeshRenderer* renderer : meshRenderers)
		renderer->Draw();
}

Camera* Graphics::GetCamera()
{
	return camera;
}

void Graphics::AddMeshRenderer(MeshRenderer* meshRenderer)
{
	meshRenderers.push_back(meshRenderer);
}

extern "C"
{
	GRAPHICS_API Graphics* GetGraphicsEngine(GLFWwindow* context, CameraParams cameraParams)
	{
		return new Graphics(context, cameraParams);
	}

	GRAPHICS_API void DestroyGraphicsEngine(Graphics* graphicsEngine)
	{
		delete graphicsEngine;
	}

	GRAPHICS_API MeshRenderer* CreateMeshRenderer(MeshType meshType, Camera* camera,
		glm::vec3 position, glm::vec3 scale, glm::vec3 color,
		const char* vertexShaderPath, const char* fragmentShaderPath)
	{
		ShaderLoader shaderLoader;
		GLuint shaderProgram = shaderLoader.CreateProgram(vertexShaderPath,
														fragmentShaderPath);

		MeshRenderer* newMeshRenderer = new MeshRenderer(meshType, camera, 
											position, scale, color);
		newMeshRenderer->SetProgram(shaderProgram);

		return newMeshRenderer;
	}

	GRAPHICS_API void AddMeshRendererToGraphicsEngine(MeshRenderer* meshRenderer, Graphics* graphicsEngine)
	{
		graphicsEngine->AddMeshRenderer(meshRenderer);
	}

	GRAPHICS_API void DestroyMeshRenderer(MeshRenderer* meshRendererToDestroy)
	{
		delete meshRendererToDestroy;
	}
}