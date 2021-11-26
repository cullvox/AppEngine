#pragma once

// Vertex.h
// Contains a number of useful vertex and formatting classes

#include <initializer_list>

#include "Math/Vector.h"
#include "Containers/Array.h"

namespace AE
{

enum VertexAttribute
{
	ePosition,
	eNormal,
	eTangent,
	eColor,
	eColor1,
	eColor2,
	eIndices,
	eWeights,
	eTexCoords,
	eTexCoords1,
	eTexCoords2,
	eTexCoords3,
	eTexCoords4,
	eTexCoords5,
	eTexCoords6
};

enum VertexType
{
	eFloat,
	eInt16,
	eUnsignedInt8
};

static inline VertexTypeToSize(const VertexType type)
{
	switch (type)
	{
	case eFloat:
		return 4;

	case eInt16:
		return 2;
	
	case eUnsignedInt8:
		return 1;

	default:
		return 0;
	}
}

struct VertexElement
{
	VertexAttribute(VertexAttributeType _attrib, VertexType _type, unsigned int _elementCount, bool _normalized)
		: attrib(_attrib), type(_type), elementCount(_elementType), normalized(_normalized)
	{
	}

	VertexAttributeType attrib;
	VertexType type;
	unsigned int elementCount;
	bool normalized;
};

class VertexFormat
{

public:
	VertexFormat();
	VertexFormat(std::initializer_list<VertexElement> elements) // Do it my way so you're cool
	{
		typename std::initializer_list<VertexElement>::iterator it;
		for (it = attributes.begin(); it != attributes.end(); it++)
		{
			m_Attributes.Push(it);
		}
	}

	~VertexFormat();

public:
	VertexFormat& Add(VertexAttributeType attrib, VertexType type, unsigned int elementCount, bool normalized) // Do it the BGFX way instead
	{
		m_Attributes.Push(VertexAttribute(attrib, type, elementCount, normalized));
	}

	unsigned int Stride() const
	{
		unsigned int stride = 0;
		for (unsigned int i = 0; i < m_Attributes.Count(); i++)
			stride += VertexTypeToSize(m_Attributes[i].type);

		return stride;
	}

private:
	Array<VertexAttribute> m_Attributes;

};

// Define the default vertices and the cooresponding formats

struct Vertex2D
{
	Vector2f position;
	Vector2f texCoord;
}

VertexFormat DefaultVertex2DFormat({
		(VertexAttribute::ePosition, VertexType::eFloat, 2, false),
		(VertexAttribute::eTexCoords, VertexType::eFloat, 2, true)
	});

struct Vertex
{
	Vector3f position;
	Vector3f normal;
	Vector2f texCoord;
};

VertexFormat DefaultVertexFormat({
		(VertexAttribute::ePosition, VertexType::eFloat, 3, false),
		(VertexAttribute::eNormal, VertexType::eFloat, 3, false),
		(VertexAttribute::eTexCoords, VertexType::eFloat, 2, true)
	});

struct VertexSkinned
{
	Vector3f position;
	Vector3f normal;
	Vector2f texCoord;
	Vector4f indices;
	Vector4f weights;
};

VertexFormat DefaultVertexSkinnedFormat({
		(VertexAttribute::ePosition, VertexType::eFloat, 3, false),
		(VertexAttribute::eNormal, VertexType::eFloat, 3, false),
		(VertexAttribute::eTexCoords, VertexType::eFloat, 2, true),
		(VertexAttribute::eIndices, VertexType::eInt16, 4, false),
		(VertexAttribute::eWeights, VertexType::eFloat, 4, true)
	});

}