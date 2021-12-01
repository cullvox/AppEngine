#pragma once

#include <GLFW/glfw3.h>

#include "Suppress.h"
#include "Graphics/Window.h"

namespace AE
{

class IDisplayGLFW : public IDisplay
{

public:
	IDisplayGLFW();
	IDisplayGLFW(const IDisplayGLFW& other);
	IDisplayGLFW(GLFWmonitor* monitor);
	~IDisplayGLFW();

protected:
	IDisplayGLFW(const ICloneable& other);

public:
	IDisplay& operator=(const IDisplay& other);

public:
	IDisplayGLFW* Clone();
	const std::vector<FVideoMode>& GetVideoModes();
	const void* GetNative() const;

private:
	GLFWmonitor* m_Monitor = nullptr;
	std::vector<FVideoMode> m_VideoModes;
	bool bGotModes = false;

};

class IWindowGLFW : public virtual IWindow
{

public:
	IWindowGLFW(); // Default
	IWindowGLFW(IGraphicsFactory* factory, const std::string& title, unsigned int width, unsigned int height, IDisplay* display);
	~IWindowGLFW();
protected:
	IWindowGLFW(const IWindowGLFW& other);

public:
	virtual void Bind();
	virtual void* GetNative() const;
	virtual void Resize(unsigned int width, unsigned int height);
	virtual void SetTitle(const std::string& title);
	virtual bool IsCloseRequested();

private:
	GLFWwindow* m_Window = nullptr;

};

}