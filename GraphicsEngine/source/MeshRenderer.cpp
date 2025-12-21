#include <glad/glad.h>
#include "MeshRenderer.h"
#include "Camera.h"
#include "Matrices.h"

MeshRenderer::MeshRenderer(MeshType _modelType, Camera* _camera,
	Vec3 _position, Vec3 _scale, Vec3 _color)
{
	camera = _camera;
	scale = _scale;
	position = _position;

	switch (_modelType)
	{
	case TRIANGLE: Mesh::SetTriangleData(vertices, indices, _color);
		break;
	case QUAD: Mesh::SetQuadData(vertices, indices, _color);
		break;
	case CUBE: Mesh::SetCubeData(vertices, indices, _color);
		break;
	case SPHERE: Mesh::SetSphereData(vertices, indices, _color);
		break;
	}

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(),	&vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) *	indices.size(), &indices[0], GL_STATIC_DRAW);

	// Enable Position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	
	// Enable Color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void*)(offsetof(Vertex, Vertex::color)));

	// Enable TexCoord
	/*glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void*)(offsetof(Vertex, Vertex::texCoords)));*/


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void MeshRenderer::Draw()
{
	Mat4 translationMat = CoreMath::Translation(position);
	Mat4 scaleMat = CoreMath::Scale(scale);

	modelMat = Mat4();
	modelMat = translationMat * scaleMat;

	Mat4 vp = camera->GetProjectionMatrix() * camera->GetViewMatrix();

	glUseProgram(program);
	GLint vpLoc = glGetUniformLocation(program, "vp");
	glUniformMatrix4fv(vpLoc, 1, GL_FALSE, vp.asArray);
	
	GLint modelLoc = glGetUniformLocation(program, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, modelMat.asArray);

	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

Vec3 MeshRenderer::GetPosition() const
{
	return position;
}

void MeshRenderer::SetPosition(Vec3 _position)
{
	position = _position;
}

void MeshRenderer::SetScale(Vec3 _scale)
{
	scale = _scale;
}

void MeshRenderer::SetRotation(float rotation, Vec3 rotationAxis)
{

	Vec3 rotationVec = rotationAxis * rotation;

	modelMat = modelMat * CoreMath::Rotation(rotationVec.x, rotationVec.y, rotationVec.z);
}

void MeshRenderer::SetProgram(GLuint _program)
{
	program = _program;
}

void MeshRenderer::SetTexture(GLuint _textureID)
{
	texture = _textureID;
}