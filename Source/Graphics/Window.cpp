#include "Graphics/Window.h"

namespace AE
{

IDisplay::IDisplay()
{
}

IDisplay::~IDisplay()
{
}

IDisplay::IDisplay(const IDisplay& other)
{
}

IDisplay* IDisplay::Clone()
{
	return new IDisplay(*this);
}

const void* IDisplay::GetNative() const
{
	return nullptr;
}

const const std::vector<FVideoMode>& IDisplay::GetVideoModes()
{
	return m_VideoModes;
}

IWindow()
{
}

IWindow(IGraphicsFactory* factory, const std::string& title, unsigned int width, unsigned int height, IDisplay* display)
{
}

~IWindow()
{
}

IWindow(const IWindow& other)
{
}


IWindow* IWindow::Clone()
{
	return new IWindow(*this);
}

const std::vector<std::unique_ptr<IDisplay>> IWindow::GetCurrentDisplays()
{
	return std::vector<std::unique_ptr<IDisplay>>();
}

virtual void IWindow::Bind()
{	
}

void* IWindow::GetNative() const
{
	return nullptr;
}

void IWindow::Resize(unsigned int width, unsigned int height)
{
}

void IWindow::SetTitle(const std::string& title)
{
}

void IWindow::SetView(const SMatrix4f& view)
{
}

void IWindow::SetProjection(const SMatrix4f& projection)
{
}

void IWindow::SubmitToQueue(const FSubmission& submission)
{
}

void IWindow::NextFrame()
{
}


}