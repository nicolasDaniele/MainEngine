#pragma once

#include "GraphicsTypes.h"
#include "Vectors.h"

#define	Vec3 CoreMath::Vec3
#define	Vec2 CoreMath::Vec2

const float PI = 3.141592f;
const float SPHERE_RADIUS = 1.0f;
const int SECTOR_COUNT = 36;
const int STACK_COUNT = 18;

struct Vertex
{
	Vec3 pos;
	Vec3 normal;
	Vec3 color;
	Vec2 texCoords;
};

class Mesh {
public:
	static void SetTriangleData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices, Vec3 color = Vec3(1.0f, 1.0f, 1.0f));
	static void SetQuadData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices, Vec3 color = Vec3(1.0f, 1.0f, 1.0f));
	static void SetCubeData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices, Vec3 color = Vec3(1.0f, 1.0f, 1.0f));
	static void SetSphereData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices, Vec3 color = Vec3(1.0f, 1.0f, 1.0f));
};