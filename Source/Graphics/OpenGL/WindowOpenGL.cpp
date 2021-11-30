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

void SetView(const SMatrix4f& view)
{
}

void SetProjection(const SMatrix4f& projection)
{
}

void SubmitToQueue(const FSubmission& submission)
{
}

void NextFrame()
{
}


}