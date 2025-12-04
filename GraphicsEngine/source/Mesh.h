#pragma once

#include <vector>
#include "glm/glm/glm.hpp"
#include "GraphicsTypes.h"

const float PI = 3.141592f;
const float SPHERE_RADIUS = 1.0f;
const int SECTOR_COUNT = 36;
const int STACK_COUNT = 18;

struct Vertex {
	glm::vec3 pos;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texCoords;
};

class Mesh {
public:
	static void SetTriangleData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
	static void SetQuadData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
	static void SetCubeData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
	static void SetSphereData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
};