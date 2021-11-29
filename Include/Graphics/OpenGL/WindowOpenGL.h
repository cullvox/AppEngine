#pragma once

#include "Graphics/Window.h"

namespace AE
{

class IGraphicsFactory;

class IWindowOpenGL : public virtual IWindow
{

public:
	IWindowOpenGL();
	IWindowOpenGL(const IWindowOpenGL& other);
	IWindowOpenGL(IGraphicsFactory* factory, const FString& title = "AppEngine", unsigned int width = 720, unsigned int height = 1080, IDisplay* display = nullptr);
	~IWindowOpenGL();

public:
	virtual IResource* ShallowCopy(const IResource* other);

public:
	IWindowOpenGL& operator=(const IWindowOpenGL& other);

public:
	void SetView(const SMatrix4f& view) final;
	void SetProjection(const SMatrix4f& projection) final;
	void SubmitToQueue(const SSubmission& submission) final;
	void NextFrame() final;

public:
	static void* GetLoadProc();

};

}