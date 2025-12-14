#pragma once

#ifdef GRAPHICSENGINE_EXPORTS
	#define GRAPHICS_API __declspec(dllexport)
#else
	#define GRAPHICS_API __declspec(dllimport)
#endif

#include <vector>
#include "GraphicsTypes.h"
#include "GraphicsData.h"
#include "glm/glm.hpp"

class MeshRenderer;
class Camera;

class GRAPHICS_API Graphics
{
public:
	Graphics(GLFWwindow* context, CameraParams cameraParams);
	~Graphics();
	void Render();
	Camera* GetCamera();
	void AddMeshRenderer(MeshRenderer* meshRenderer);

private:
	Camera* camera = nullptr;
	std::vector<MeshRenderer*> meshRenderers;
};

extern "C"
{
	GRAPHICS_API Graphics* GetGraphicsEngine(GLFWwindow* context, CameraParams cameraParams);
	GRAPHICS_API void DestroyGraphicsEngine(Graphics* graphicsEngineToDestroy);

	GRAPHICS_API MeshRenderer* CreateMeshRenderer(MeshType meshType, Camera* camera, 
										glm::vec3 position = glm::vec3(0.0f),
										glm::vec3 scale = glm::vec3(1.0f),
										glm::vec3 color = glm::vec3(1.0f),
										const char* vertexShaderPath = "", 
										const char* fragmentShaderPath = "");
	GRAPHICS_API void AddMeshRendererToGraphicsEngine(MeshRenderer* meshRenderer, Graphics* graphicsEngine);
	GRAPHICS_API void DestroyMeshRenderer(MeshRenderer* meshRendererToDestroy);
}