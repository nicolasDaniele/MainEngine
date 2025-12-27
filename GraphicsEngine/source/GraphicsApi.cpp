#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include "GraphicsApi.h"
#include "Mesh.h"
#include "MeshBuffer.h"
#include "MeshRenderer.h"
#include "MeshFactory.h"
#include "Camera.h"
#include "ShaderLoader.h"

Graphics::Graphics(CameraParams cameraParams)
{
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

uint32_t Graphics::CreateShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath)
{
	ShaderLoader shaderLoader;
	return shaderLoader.CreateProgram(vertexShaderPath,
		fragmentShaderPath);
}

void Graphics::DrawDebugLines(const Vec3* vertices, int count, const Mat4& vp, unsigned int shader)
{
}

void Graphics::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1f, 0.0f, 0.12f, 1.0f);

	if (camera == nullptr)
	{
		std::cout << "[Grahics::Render] Camera is null." << std::endl;
		return;
	}

	for (MeshRenderer* renderer : meshRenderers)
		renderer->Draw(camera->GetProjectionMatrix() * camera->GetViewMatrix());
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
	GRAPHICS_API Graphics* GetGraphicsEngine(CameraParams cameraParams)
	{
		return new Graphics(cameraParams);
	}

	GRAPHICS_API void DestroyGraphicsEngine(Graphics* graphicsEngine)
	{
		delete graphicsEngine;
	}

	GRAPHICS_API MeshRenderer* CreateMeshRenderer(Graphics* graphics, MeshType meshType,
		Vec3 position, Vec3 scale, Vec3 color,
		const char* vertexShaderPath, const char* fragmentShaderPath)
	{
		Mesh mesh = MeshFactory::CreateMesh(meshType, color);
		MeshBuffer* meshBuffer = new MeshBuffer();
		meshBuffer->LoadMeshData(mesh);

		MeshRenderer* newMeshRenderer = new MeshRenderer(meshBuffer, position, scale);

		if (graphics == nullptr)
			return newMeshRenderer;

		uint32_t shaderProgram = graphics->CreateShaderProgram(vertexShaderPath, fragmentShaderPath);
		newMeshRenderer->SetShaderProgram(shaderProgram);
		graphics->AddMeshRenderer(newMeshRenderer);

		return newMeshRenderer;
	}

	GRAPHICS_API void UpdateMeshRendererPosition(MeshRenderer* meshRenderer, Vec3 newPosition)
	{
		meshRenderer->SetPosition(newPosition);
	}
}