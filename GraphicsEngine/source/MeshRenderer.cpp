#include <glad/glad.h>
#include "glm/glm/gtc/type_ptr.hpp"
#include "MeshRenderer.h"
#include "Camera.h"

MeshRenderer::MeshRenderer(MeshType modelType, Camera* _camera)
{
	camera = _camera;
	scale = glm::vec3(1.0f, 1.0f, 1.0f);
	position = glm::vec3(0.0f, 0.0f, 0.0f);

	switch (modelType)
	{
	case TRIANGLE: Mesh::SetTriangleData(vertices, indices);
		break;
	case QUAD: Mesh::SetQuadData(vertices, indices);
		break;
	case CUBE: Mesh::SetCubeData(vertices, indices);
		break;
	case SPHERE: Mesh::SetSphereData(vertices, indices);
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

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	
	// Enable Color
	/*glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void*)(offsetof(Vertex, Vertex::color)));*/

	// Enable TexCoord
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void*)(offsetof(Vertex, Vertex::texCoords)));

	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void MeshRenderer::Draw()
{
	glm::mat4 translation_m = glm::translate(glm::mat4(1.0f), position);
	glm::mat4 scale_m = glm::scale(glm::mat4(1.0f), scale);

	modelMatrix = glm::mat4(1.0f);
	modelMatrix = translation_m * scale_m;

	glm::mat4 vp = camera->GetProjectionMatrix() * camera->GetViewMatrix();

	glUseProgram(this->program);
	GLint vpLoc = glGetUniformLocation(program, "vp");
	glUniformMatrix4fv(vpLoc, 1, GL_FALSE, glm::value_ptr(vp));
	GLint modelLoc = glGetUniformLocation(program, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

glm::vec3 MeshRenderer::GetPosition() const
{
	return position;
}

void MeshRenderer::SetPosition(glm::vec3 _position)
{
	this->position = _position;
}

void MeshRenderer::SetScale(glm::vec3 _scale)
{
	this->scale = _scale;
}

void MeshRenderer::SetRotation(float _rotation, glm::vec3 _rotattionAxis)
{
	rotation = _rotation;
	rotationAxis = _rotattionAxis;

	glm::mat4 rotation_m = glm::rotate(modelMatrix, glm::radians(rotation), rotationAxis);
}

void MeshRenderer::SetProgram(GLuint _program)
{
	this->program = _program;
}

void MeshRenderer::SetTexture(GLuint _textureID)
{
	this->texture = _textureID;
}
