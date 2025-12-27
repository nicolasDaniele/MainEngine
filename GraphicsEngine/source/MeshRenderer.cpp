#include <glad/glad.h>
#include "MeshRenderer.h"
#include "Mesh.h"
#include "MeshBuffer.h"

void MeshRenderer::Draw(const Mat4& vp)
{
	Mat4 translationMat = CoreMath::Translation(position);
	Mat4 scaleMat = CoreMath::Scale(scale);

	Mat4 modelMat = translationMat * scaleMat;

	glUseProgram(shader);
	GLint vpLoc = glGetUniformLocation(shader, "vp");
	glUniformMatrix4fv(vpLoc, 1, GL_FALSE, vp.asArray);
	
	GLint modelLoc = glGetUniformLocation(shader, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, modelMat.asArray);

	meshBuffer->Bind();
	glDrawElements(GL_TRIANGLES, meshBuffer->GetIndexCount(),
		GL_UNSIGNED_INT, nullptr);

	meshBuffer->Unbind();
}

void MeshRenderer::SetShaderProgram(uint32_t _shader)
{
	shader = _shader;
}

void MeshRenderer::SetMeshBuffer(MeshBuffer* _meshBuffer)
{
	meshBuffer = _meshBuffer;
}

Vec3 MeshRenderer::GetPosition() const
{
	return position;
}

void MeshRenderer::SetPosition(const Vec3& _position)
{
	position = _position;
}

void MeshRenderer::SetScale(const Vec3& _scale)
{
	scale = _scale;
}