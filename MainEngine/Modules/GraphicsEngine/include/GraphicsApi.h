#pragma once

#ifdef GRAPHICSENGINE_EXPORTS
	#define GRAPHICS_API __declspec(dllexport)
#else
	#define GRAPHICS_API __declspec(dllimport)
#endif

#include <glad/glad.h>
#include <glfw3.h>
#include "GraphicsTypes.h"

class MeshRenderer;
class Camera;
class ShaderLoader;

class GRAPHICS_API Graphics
{
public:
	Graphics(int width, int height, MeshType meshType, GLFWwindow* context,
		const char* vertexShaderPath = "", const char* fragmentShaderPath = "");
	~Graphics();
	void Render();
	MeshRenderer* GetMesh();
	Camera* GetCamera();

private:
	Camera* camera = nullptr;
	MeshRenderer* meshRenderer = nullptr;
	ShaderLoader* shaderLoader = nullptr;
};

extern "C"
{
	GRAPHICS_API Graphics* GetGraphicsEngine(int width, int height, MeshType meshType, GLFWwindow* context,
		const char* vertexShaderPath = "", const char* fragmentShaderPath = "");
	GRAPHICS_API void DeleteGraphicsEngine(Graphics* graphicsEngine);
}