#pragma once

#include <vector>
#include "Mesh.h"

class Camera;

class MeshRenderer
{
public:
	MeshRenderer(MeshType modelType, Camera* _camera);
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

