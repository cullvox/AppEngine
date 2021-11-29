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
	const TArray<SVideoMode>& GetVideoModes();
	const void* GetNative() const;

private:
	bool bGotModes = false;
	GLFWmonitor* m_Monitor;
	TArray<SVideoMode> m_Modes;

};

class IWindowGLFW : public virtual IWindow
{

public:
	IWindowGLFW(); // Default
	IWindowGLFW(const IWindowGLFW& other); // Preforms a Shallow Copy
	IWindowGLFW(IGraphicsFactory* factory, const FString& title, unsigned int width, unsigned int height, IDisplay* display);
	~IWindowGLFW();

protected:
	virtual IResource* ShallowCopy(const IResource* other);

public:
	IWindowGLFW& operator=(const IWindowGLFW& other);

public:
	virtual const TArray<IDisplay*> GetCurrentDisplays();

	virtual void Bind();
	virtual void Resize(unsigned int width, unsigned int height);
	virtual void SetTitle(const FString& title);
	virtual void* GetNative() const;

private:
	GLFWwindow* m_Window = nullptr;

};

}