#pragma once

#include <GLFW/glfw3.h>

#include "Suppress.h"
#include "Graphics/Window.h"

namespace AE
{

class IDisplayGLFW : public virtual IDisplay
{

public:
	IDisplayGLFW();
	IDisplayGLFW(const IDisplay& other);
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
	bool bGotModes = false;
	GLFWmonitor* m_Monitor;
	std::vector<FVideoMode> m_Modes;

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
	virtual const std::vector<std::unique_ptr<IDisplay>>& GetCurrentDisplays();

	virtual void Bind();
	virtual void Resize(unsigned int width, unsigned int height);
	virtual void SetTitle(const std::string& title);
	virtual void* GetNative() const;

private:
	GLFWwindow* m_Window = nullptr;

};

}