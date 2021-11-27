#pragma once

// Window.h
// Contains a display and system window/drawable surface abstraction

#include "Types.h"
#include "Containers/String.h"
#include "Containers/Queue.h"
#include "Graphics/Resource.h"
#include "Graphics/Submission.h"

namespace AE
{

// Systems will fill this out personally
bool WindowSystemInitialize();
void WindowSystemTerminate();

struct VideoMode : public NonCopyable
{
	unsigned int width;
	unsigned int height;
	unsigned int refreshRate;
};

struct Display : public NonCopyable
{

public:
	Display();
	virtual ~Display();

public:
	const Array<VideoMode>& GetVideoModes();

};

class Window : public NonCopyable, public Resource
{
public:
	Window();
	Window(GraphicsDevice* device);
	Window(GraphicsDevice* device, const String& title, unsigned int width, unsigned int height, Display* display);
	virtual ~Window() = 0;

public:
	virtual bool Open(const String& title, unsigned int width, unsigned int height, Display* display) = 0;
	virtual void Close() = 0;
	virtual void Bind() const = 0; // Changes the context to this window
	virtual void Resize(unsigned int width, unsigned int height) = 0;
	virtual void SetTitle(const String& title) = 0;

public:
	virtual void SetView(const Matrix4f& view) = 0;
	virtual void SetProjection(const Matrix4f& projection) = 0;
	virtual void QueueSubmission(const Submission& submission) = 0;
	virtual void NextFrame() = 0; // Submits the framesubmissions and then clears queue

private:
	Queue<Submission> m_Submissions; // The draw calls to submit this frame

};

}