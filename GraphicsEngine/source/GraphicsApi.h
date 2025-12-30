#pragma once

#ifdef GRAPHICSENGINE_EXPORTS
	#define GRAPHICS_API __declspec(dllexport)
#else
	#define GRAPHICS_API __declspec(dllimport)
#endif

#include <vector>
#include "IGraphics.h"
#include "GraphicsTypes.h"
#include "GraphicsData.h"

using Vec3 = CoreMath::Vec3;

class MeshRenderer;
class Camera;

class GRAPHICS_API Graphics : public IGraphics
{
public:
	Graphics(CameraParams cameraParams);
	~Graphics();

	uint32_t CreateShaderProgram(const char* vertexShaderPath,
		const char* fragmentShaderPath) override;
	void DrawDebugLines(const Vec3* vertices, int vertexCount,
		uint32_t shaderProgram, Vec3 color = Vec3(1.0f, 1.0f, 1.0f)) override;

	void Render();
	Camera* GetCamera();
	void AddMeshRenderer(MeshRenderer* meshRenderer);

private:
	Camera* camera = nullptr;
	std::vector<MeshRenderer*> meshRenderers;

	uint32_t debugVAO = 0;
	uint32_t debugVBO = 0;
};

extern "C"
{
	GRAPHICS_API Graphics* GetGraphicsEngine(/*GLFWwindow* context, */CameraParams cameraParams);
	GRAPHICS_API void DestroyGraphicsEngine(Graphics* graphicsEngineToDestroy);

	GRAPHICS_API MeshRenderer* CreateMeshRenderer(Graphics* graphics, MeshType meshType,
										Vec3 position = Vec3(0.0f, 0.0f, 0.0f),
										Vec3 scale = Vec3(1.0f, 1.0f, 1.0f),
										Vec3 color = Vec3(1.0f, 1.0f, 1.0f),
										const char* vertexShaderPath = "", 
										const char* fragmentShaderPath = "");
	GRAPHICS_API void UpdateMeshRendererPosition(MeshRenderer* meshRenderer, Vec3 newPosition);
}