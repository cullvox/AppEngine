#pragma once

#include <glad/glad.h>

#include "Graphics/VertexBuffer.h"

namespace AE
{

class GraphicsDeviceOpenGL;

class VertexBufferOpenGL
{

public:
	VertexBufferOpenGL(); // Default
	VertexBufferOpenGL(const VertexBufferOpenGL& other); // Copy
	VertexBufferOpenGL(GraphicsDeviceOpenGL& device, const void* vertices, unsigned int verticesCount);
	~VertexBufferOpenGL();

public:
	virtual IResource* ShallowCopy(const IResource* other);

public:
	void Bind();

private:
	GLuint m_VertexBufferID;

};

}