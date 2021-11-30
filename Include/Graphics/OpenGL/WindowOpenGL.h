#pragma once

#include "Graphics/Window.h"

namespace AE
{

class IGraphicsFactory;

class IWindowOpenGL : public virtual IWindow
{

public:
	IWindowOpenGL();
	IWindowOpenGL(IGraphicsFactory* factory, const std::string& title = "AppEngine", unsigned int width = 720, unsigned int height = 1080, IDisplay* display = nullptr);
	~IWindowOpenGL();
protected:
	IWindowOpenGL(const IWindowOpenGL& other);

public:
	static void* GetLoadProc();
	void SetView(const SMatrix4f& view) final;
	void SetProjection(const SMatrix4f& projection) final;
	void SubmitToQueue(const FSubmission& submission) final;
	void NextFrame() final;

};

}