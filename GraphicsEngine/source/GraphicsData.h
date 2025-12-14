#pragma once

#include <glad/glad.h>
#include "glm/glm.hpp"

struct CameraParams
{
	GLfloat fieldOfView;
	GLfloat width;
	GLfloat height;
	GLfloat nearPlane;
	GLfloat farPlane;
	glm::vec3 position;
};