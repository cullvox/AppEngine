#pragma once

#include <GLFW/glfw3.h>

#include "Graphics/Window.h"

namespace AE
{

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
	IResource* ShallowCopy(const IResource* other);

private:
	GLFWwindow* m_Window = nullptr;

};

}