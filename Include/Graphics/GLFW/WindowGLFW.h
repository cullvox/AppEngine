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

public:
	IDisplay& operator=(const IDisplay& other);

public:
	const TArray<SVideoMode>& GetVideoModes();
	const void* GetNative() const;

private:
	GLFWmonitor* m_Monitor;

};

class IWindowGLFW : public virtual IWindow
{

public:
	IWindowGLFW(); // Default
	IWindowGLFW(const IWindowGLFW& other); // Preforms a Shallow Copy
	IWindowGLFW(IGraphicsFactory* factory, const SString& title, unsigned int width, unsigned int height, IDisplay* display);
	~IWindowGLFW();

public:
	IWindowGLFW& operator=(const IWindowGLFW& other);

public:
	virtual void Bind();
	virtual void Resize(unsigned int width, unsigned int height);
	virtual void SetTitle(const SString& title);
	virtual void* GetNative() const;

protected:
	virtual IResource* ShallowCopy(const IResource* other);

private:
	GLFWwindow* m_Window = nullptr;

};

}