#pragma once

#include "Vectors.h"
#include "Matrices.h"

using Vec3 = CoreMath::Vec3;
using Mat4 = CoreMath::Mat4;

class IGraphics
{
public:
    virtual ~IGraphics() = default;

    virtual unsigned int CreateShaderProgram(
        const char* vertexShaderPath,
        const char* fragmentShaderPath) = 0;

    virtual void DrawDebugLines(
        const Vec3* vertices,
        int vertexCount,
        const Mat4& vp,
        unsigned int shader) = 0;
};