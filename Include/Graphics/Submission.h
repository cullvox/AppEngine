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
	eDefault,
	eDrawLine,
	eDrawTriangleStrip,
	eDrawPoint
};

struct Submission
{
	Submission()
	{
	}

	~Submission()
	{
	}

	Submission& setModel(const Matrix4f& _model)
	{
		model = _model;
	}

	Submission& setVertexBuffer(const VertexBuffer* _vertexBuffer)
	{
		vertexBuffer = _vertexBuffer;
	}

	Submission& setIndexBuffer(const IndexBuffer* _indexBuffer)
	{
		indexBuffer = _indexBuffer;
	}

	Submission& setInstanceBuffer(const InstanceBuffer* _instanceBuffer)
	{
		instanceBuffer = _instanceBuffer;
	}

	Submission& setPipeline(const Pipeline* _pipeline)
	{
		pipeline = _pipeline;
	}

	Submission& setState(State _state)
	{
		state = _state;
	}

	Matrix4f model;
	const VertexBuffer* vertexBuffer;
	const IndexBuffer* indexBuffer;
	const InstanceBuffer* instanceBuffer; // If instance buffer is nullptr, draw without instancing.
	const Pipeline* pipeline;
	State state = State::eDefault;
};

};