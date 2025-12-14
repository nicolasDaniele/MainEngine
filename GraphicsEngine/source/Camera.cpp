#include <glad/glad.h>
#include "glm/glm/gtc/matrix_transform.hpp"
#include "Camera.h"

Camera::Camera(GLfloat FOV, GLfloat width, GLfloat height, GLfloat nearPlane, GLfloat farPlane, glm::vec3 pos)
{
	position = pos;

	forward = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	worldUp = up;

	viewMatrix = glm::lookAt(position, forward, up);
	projectionMatrix = glm::perspective(FOV, width / height, nearPlane, farPlane);

	yaw = -90.0f;
	pitch = 0.0f;
	movementSpeed = 2.5f;
	sensitivity = 0.5f;
	zoomAmount = 45.0f;

	UpdateVectors();
}

void Camera::MoveCamera(Utils::Direction direction, float deltaTime)
{
	float velocity = movementSpeed * deltaTime;

	switch (direction)
	{
	case Utils::FORWARD:
		position += forward * velocity; break;
	case Utils::BACKWARD:
		position -= forward * velocity; break;
	case Utils::UP:
		position += up * velocity; break;
	case Utils::DOWN:
		position -= up * velocity; break;
	case Utils::LEFT:
		position -= right * velocity; break;
	case Utils::RIGHT:
		position += right * velocity; break;
	default:
		break;
	}
}

void Camera::RotateCamera(float xOffset, float yOffset, GLboolean constrainPitch)
{
	xOffset *= sensitivity;
	yOffset *= sensitivity;

	yaw += xOffset;
	pitch += yOffset;

	if (constrainPitch)
		Utils::Clamp(pitch, -89.0f, 89.f);

	UpdateVectors();
}

void Camera::Zoom(const float yOffset)
{
	zoomAmount -= yOffset;
	Utils::Clamp(zoomAmount, 1.0f, 45.0f);
}

void Camera::UpdateVectors()
{
	glm::vec3 fwd;
	fwd.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	fwd.y = sin(glm::radians(pitch));
	fwd.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	forward = glm::normalize(fwd);

	right = glm::normalize(glm::cross(forward, worldUp));
	up = glm::normalize(glm::cross(right, forward));
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(position, position + forward, up);
}

glm::mat4 Camera::GetProjectionMatrix() const
{
	return projectionMatrix;
}

glm::vec3 Camera::GetCameraPosition() const
{
	return position;
}

float Camera::GetZoomAmount() const
{
	return zoomAmount;
}

void Camera::SetMovementSpeed(const float _speed)
{
	movementSpeed = _speed;
}

void Camera::SetSensitivity(const float _sensitivity)
{
	sensitivity = _sensitivity;
}

void Camera::SetZoomAmount(const float _zoomAmount)
{
	zoomAmount = _zoomAmount;
}