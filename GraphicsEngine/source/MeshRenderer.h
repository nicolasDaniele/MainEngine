#pragma once

#include <vector>
#include "Mesh.h"
#include "Vectors.h"
#include "Matrices.h"

#define	Vec3 CoreMath::Vec3
#define Mat4 CoreMath::Mat4

class Camera;

class MeshRenderer
{
public:
	
	MeshRenderer(MeshType _modelType, Camera* _camera,
		Vec3 _position = Vec3(0.0f, 0.0f, 0.0f),
		Vec3 _scale = Vec3(1.0f, 1.0f, 1.0f),
		Vec3 _color = Vec3(1.0f, 1.0f, 1.0f));
	~MeshRenderer() {}

	void Draw();

	Vec3 GetPosition() const;
	void SetPosition(Vec3 _position);
	void SetScale(Vec3 _scale);
	void SetRotation(float _rotation, Vec3 _rotattionAxis);
	void SetProgram(GLuint _program);
	void SetTexture(GLuint _textureID);

private:
	std::vector<Vertex>vertices;
	std::vector<GLuint>indices;
	Mat4 modelMat;
	Camera* camera;
	Vec3 position, scale;
	float rotation;
	GLuint vao, vbo, ebo, texture, program;
};