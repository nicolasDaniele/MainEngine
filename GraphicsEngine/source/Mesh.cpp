#include <vector>
#include "Mesh.h"

void Mesh::SetTriangleData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices) {
	vertices.clear();
	indices.clear();

	vertices = {
		// Vertex 0 (bottom left)
		{ 
			{ -1.0f, -1.0f, 0.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 1.0f, 0.0f, 0.0f },	// Color
			{ 0.0f, 0.0f }			// Texture Coordinate
		},
		// Vertex 1 (bottom right)
		{ 
			{ 1.0f, -1.0f, 0.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 0.0f, 1.0f, 0.0f },	// Color
			{ 1.0f, 0.0f }			// Texture Coordinate
		},
		// Vertex 2 (top)
		{ 
			{ 0.0f, 1.0f, 0.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 0.0f, 0.0f, 1.0f },	// Color
			{ 0.5f, 1.0f }			// Texture Coordinate
		}
	};

	indices = {
		0, 1, 2
	};
}

void Mesh::SetQuadData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices)
{
	vertices.clear();
	indices.clear();

	vertices = {
		// Vertex 0 (top right)
		{
			{ 1.0f, 1.0f, 0.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 1.0f, 1.0f, 1.0f },	// Color
			{ 1.0f, 1.0f }			// Texture Coordinate
		},
		// Vertex 1 (bottom right)
		{
			{ 1.0f, -1.0f, 0.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 1.0f, 1.0f, 1.0f },	// Color
			{ 1.0f, 0.0f }			// Texture Coordinate
		},
		// Vertex 2 (bottom left)
		{
			{ -1.0f, -1.0f, 0.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 1.0f, 1.0f, 1.0f },	// Color
			{ 0.0f, 0.0f }			// Texture Coordinate
		},
		// Vertex 3 (top left)
		{
			{ -1.0f, 1.0f, 0.0f },	// Position
			{ 0.0f, 0.0f, 1.0f },	// Normal
			{ 1.0f, 1.0f, 1.0f },	// Color
			{ 0.0f, 1.0f }			// Texture Coordinate
		}
	};

	indices = {
		0, 1, 3,
		1, 2, 3
	};
}

void Mesh::SetCubeData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices)
{
	vertices.clear(); 
	indices.clear();

	vertices = {
		// Position					// Normal				// Color			// TexCoord
		{ {-0.5f, -0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 0.0f} },
		{ { 0.5f, -0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 0.0f} },
		{ { 0.5f,  0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 1.0f} },
		{ { 0.5f,  0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 1.0f} },
		{ {-0.5f,  0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 1.0f} },
		{ {-0.5f, -0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 0.0f} },
		 																					 
		{ {-0.5f, -0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 0.0f} },
		{ { 0.5f, -0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 0.0f} },
		{ { 0.5f,  0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 1.0f} },
		{ { 0.5f,  0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 1.0f} },
		{ {-0.5f,  0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 1.0f} },
		{ {-0.5f, -0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 0.0f} },
		 					 																 
		{ {-0.5f,  0.5f,  0.5f}, {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 0.0f} },
		{ {-0.5f,  0.5f, -0.5f}, {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 1.0f} },
		{ {-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 1.0f} },
		{ {-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 1.0f} },
		{ {-0.5f, -0.5f,  0.5f}, {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 0.0f} },
		{ {-0.5f,  0.5f,  0.5f}, {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 0.0f} },
		 																					 
		{ { 0.5f,  0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 0.0f} },
		{ { 0.5f,  0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 1.0f} },
		{ { 0.5f, -0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 1.0f} },
		{ { 0.5f, -0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 1.0f} },
		{ { 0.5f, -0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 0.0f} },
		{ { 0.5f,  0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 0.0f} },
		 																					 
		{ {-0.5f, -0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 1.0f} },
		{ { 0.5f, -0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 1.0f} },
		{ { 0.5f, -0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 0.0f} },
		{ { 0.5f, -0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 0.0f} },
		{ {-0.5f, -0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 0.0f} },
		{ {-0.5f, -0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 1.0f} },
		 																					 
		{ {-0.5f,  0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 1.0f} },
		{ { 0.5f,  0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 1.0f} },
		{ { 0.5f,  0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 0.0f} },
		{ { 0.5f,  0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{1.0f, 0.0f} },
		{ {-0.5f,  0.5f,  0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 0.0f} },
		{ {-0.5f,  0.5f, -0.5f},  {0.0f, 0.0f, 0.0f},	 {1.0f, 1.0f, 1.0f},	{0.0f, 1.0f} }
	};

	for (uint32_t i = 0; i < vertices.size(); ++i)
		indices.push_back(i);
}

void Mesh::SetSphereData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices)
{
	vertices.clear(); 
	indices.clear();

	float x, y, z, xy;	// Vertex Position
	float nx, ny, nz;	// Vertex Normal
	float s, t;			// Vertex TexCoord
	float lengthInv = 1.0f / SPHERE_RADIUS;
	float sectorStep = 2 * PI / SECTOR_COUNT;
	float stackStep = PI / STACK_COUNT;
	float sectorAngle, stackAngle;

	for (int i = 0; i <= STACK_COUNT; ++i)
	{
		stackAngle = PI / 2 - i * stackStep;
		xy = SPHERE_RADIUS * glm::cos(stackAngle);
		z = SPHERE_RADIUS * glm::sin(stackAngle);

		for (int j = 0; j <= SECTOR_COUNT; ++j)
		{
			sectorAngle = j * sectorStep;

			x = xy * glm::cos(sectorAngle);
			y = xy * glm::sin(sectorAngle);

			nx = x * lengthInv;
			ny = y * lengthInv;
			nz = z * lengthInv;

			s = (float)j / SECTOR_COUNT;
			t = (float)i / STACK_COUNT;

			vertices.push_back({ {x, y, z}, {nx, ny, nz}, {1.0f, 1.0f, 1.0f}, {s, t}});
		}
	}

	std::vector<int> lineIndices;
	int k1, k2;
	for (int i = 0; i < STACK_COUNT; ++i)
	{
		k1 = i * (SECTOR_COUNT + 1);
		k2 = k1 + SECTOR_COUNT + 1;

		for (int j = 0; j < SECTOR_COUNT; ++j, ++k1, ++k2)
		{
			if (i != 0)
			{
				indices.push_back(k1);
				indices.push_back(k2);
				indices.push_back(k1 + 1);
			}

			if (i != (STACK_COUNT - 1))
			{
				indices.push_back(k1 + 1);
				indices.push_back(k2);
				indices.push_back(k2 + 1);
			}

			lineIndices.push_back(k1);
			lineIndices.push_back(k2);

			if (i != 0)
			{
				lineIndices.push_back(k1);
				lineIndices.push_back(k1 + 1);
			}
		}
	}
}