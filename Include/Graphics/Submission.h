#pragma once

#include "Math/Matrix.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/Pipeline.h"
#include "Graphics/InstanceBuffer.h"

namespace AE
{

enum State
{
	eDrawLine,
	eDrawTriangleStrip,
	eDrawPoint
};

struct Submission
{
	Matrix4f view;
	Matrix4f projection;
	Matrix4f model;

	VertexBuffer* vertexBuffer;
	IndexBuffer* indexBuffer;
	InstanceBuffer* instanceBuffer; // If instance buffer is nullptr, draw without instancing.
	Pipeline* pipeline;
	State state;
};

};