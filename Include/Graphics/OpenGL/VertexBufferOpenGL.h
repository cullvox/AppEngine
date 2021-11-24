#pragma once

#include "Containers/Array.h"

namespace AE
{

class GraphicsDeviceOpenGL;

class VertexBufferOpenGL
{

public:
	VertexBufferOpenGL(GraphicsDeviceOpenGL& device, Array<Vertex> verts);
	~VertexBufferOpenGL();

public:
	void Bind();

private:


};

}