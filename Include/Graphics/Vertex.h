#pragma once

// Vertex.h
// Contains a number of useful vertex and formatting classes

#include <initializer_list>
#include <functional>

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

static inline unsigned int VertexTypeToSize(const VertexType type)
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
	VertexElement()
	{
	}

	VertexElement(VertexAttribute _attrib, VertexType _type, unsigned int _elementCount, bool _normalized)
		: attrib(_attrib), type(_type), elementCount(_elementCount), normalized(_normalized)
	{
	}

	VertexAttribute attrib;
	VertexType type;
	unsigned int elementCount;
	bool normalized;
};

class VertexFormat
{

public:
	VertexFormat()
	{
	}

	VertexFormat(std::initializer_list<VertexElement> elements) // Do it my way so you're cool
	{
		typename std::initializer_list<VertexElement>::iterator it;
		for (it = elements.begin(); it != elements.end(); ++it)
		{
			m_Elements.Push((VertexElement&)*it);
		}
	}

	~VertexFormat()
	{
	}

public:
	VertexFormat& Add(VertexAttribute attrib, VertexType type, unsigned int elementCount, bool normalized) // Do it the BGFX way instead
	{
		m_Elements.Push(VertexElement(attrib, type, elementCount, normalized));
	}

	unsigned int Stride() const
	{
		unsigned int stride = 0;
		for (unsigned int i = 0; i < m_Elements.Count(); i++)
			stride += VertexTypeToSize(m_Elements[i].type);

		return stride;
	}

private:
	TArray<VertexElement> m_Elements;

};

// Define the default vertices and the cooresponding formats

struct Vertex2D
{
	Vector2f position;
	Vector2f texCoord;
};

static VertexFormat DefaultVertex2DFormat({ VertexElement(ePosition, eFloat, 2, false), VertexElement(eTexCoords, eFloat, 2, false) });

struct Vertex
{
	Vector3f position;
	Vector3f normal;
	Vector2f texCoord;
};

static VertexFormat DefaultVertexFormat({
		VertexElement(VertexAttribute::ePosition, VertexType::eFloat, 3, false),
		VertexElement(VertexAttribute::eNormal, VertexType::eFloat, 3, false),
		VertexElement(VertexAttribute::eTexCoords, VertexType::eFloat, 2, true)
	});

struct VertexSkinned
{
	Vector3f position;
	Vector3f normal;
	Vector2f texCoord;
	SVector4f indices;
	SVector4f weights;
};

static VertexFormat DefaultVertexSkinnedFormat({
		VertexElement(VertexAttribute::ePosition, VertexType::eFloat, 3, false),
		VertexElement(VertexAttribute::eNormal, VertexType::eFloat, 3, false),
		VertexElement(VertexAttribute::eTexCoords, VertexType::eFloat, 2, true),
		VertexElement(VertexAttribute::eIndices, VertexType::eInt16, 4, false),
		VertexElement(VertexAttribute::eWeights, VertexType::eFloat, 4, true)
	});

}