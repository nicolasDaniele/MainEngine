#pragma once

#include <glad/glad.h>
#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include "Utils.h"

class Camera
{
public:
	Camera(GLfloat FOV, GLfloat width, GLfloat height, GLfloat nearPlane, 
		GLfloat farPlane, glm::vec3 pos);
	~Camera() {}
	void MoveCamera(Utils::Direction direction, float deltaTime);
	void RotateCamera(float xOffset, float yOffset, GLboolean constrainPitch = true);
	void Zoom(float yOffset);

	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix() const;
	glm::vec3 GetCameraPosition() const;
	float GetZoomAmount() const;
	void SetMovementSpeed(const float _speed);
	void SetSensitivity(const float _sensitivity);
	void SetZoomAmount(const float _zoomAmount);

private:
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;
	float yaw;
	float pitch;
	float movementSpeed;
	float sensitivity;
	float zoomAmount;

	void UpdateVectors();
};

