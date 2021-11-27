#include "Graphics/OpenGL/VertexBufferOpenGL.h"

namespace AE
{

VertexBufferOpenGL::VertexBufferOpenGL()
{
}

VertexBufferOpenGL::VertexBufferOpenGL(const VertexBufferOpenGL& other)
	: m_VertexBufferID(other.m_VertexBufferID)
{
}

}