#pragma once

#include <vector>
#include "Mesh.h"

class Camera;

class MeshRenderer
{
public:
	MeshRenderer(MeshType _modelType, Camera* _camera,
		glm::vec3 _position = glm::vec3(0.0f),
		glm::vec3 _scale = glm::vec3(1.0f),
		glm::vec3 _color = glm::vec3(1.0f));
	~MeshRenderer() {}

	void Draw();

	glm::vec3 GetPosition() const;
	void SetPosition(glm::vec3 _position);
	void SetScale(glm::vec3 _scale);
	void SetRotation(float _rotation, glm::vec3 _rotattionAxis);
	void SetProgram(GLuint _program);
	void SetTexture(GLuint _textureID);

private:
	std::vector<Vertex>vertices;
	std::vector<GLuint>indices;
	glm::mat4 modelMatrix;
	Camera* camera;
	glm::vec3 position, scale, rotationAxis;
	float rotation;
	GLuint vao, vbo, ebo, texture, program;
};