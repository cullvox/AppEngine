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

struct SSubmission
{
	SSubmission(const SMatrix4f& _model, const IVertexBuffer* _vertexBuffer, const IIndexBuffer* _indexBuffer, const IInstanceBuffer* _instanceBuffer, const IPipeline* _pipeline, State _state)
		: model(_model), vertexBuffer(_vertexBuffer), indexBuffer(_indexBuffer), instanceBuffer(_instanceBuffer), pipeline(_pipeline), state(_state)
	{
	}

	SSubmission& setModel(const SMatrix4f& _model)
	{
		model = _model;
	}

	SSubmission& setVertexBuffer(const IVertexBuffer* _vertexBuffer)
	{
		vertexBuffer = _vertexBuffer;
	}

	SSubmission& setIndexBuffer(const IIndexBuffer* _indexBuffer)
	{
		indexBuffer = _indexBuffer;
	}

	SSubmission& setInstanceBuffer(const IInstanceBuffer* _instanceBuffer)
	{
		instanceBuffer = _instanceBuffer;
	}

	SSubmission& setState(State _state)
	{
		state = _state;
	}

	SSubmission& setPipeline(const IPipeline* _pipeline)
	{
		pipeline = _pipeline;
	}

	SMatrix4f model;
	const IVertexBuffer* vertexBuffer;
	const IIndexBuffer* indexBuffer;
	const IInstanceBuffer* instanceBuffer; // If instance buffer is nullptr, draw without instancing.
	State state;
	const IPipeline* pipeline;

};

};