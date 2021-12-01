#include "Graphics/OpenGL/WindowOpenGL.h"

namespace AE
{

IWindowOpenGL::IWindowOpenGL()
{
}

IWindowOpenGL::IWindowOpenGL(IGraphicsFactory* factory, const std::string& title, unsigned int width, unsigned int height, IDisplay* display)
{
}

IWindowOpenGL::~IWindowOpenGL()
{
}

IWindowOpenGL::IWindowOpenGL(const IWindowOpenGL& other)
{
}

void IWindowOpenGL::SetView(const SMatrix4f& view)
{
}

void IWindowOpenGL::SetProjection(const SMatrix4f& projection)
{
}

void IWindowOpenGL::Submit(const FSubmission& submission)
{
}

void IWindowOpenGL::NextFrame()
{
}

}