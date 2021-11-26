#pragma once

// Window.h
// Contains a display and system window/drawable surface abstraction

#include "Types.h"
#include "String.h"
#include "Graphics/Resource.h"
#include "Graphics/Submission.h"

namespace AE
{
	
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
	Window(GraphicsDevice& device, const String& title, unsigned int width, unsigned int height);
	virtual ~Window() = 0;

public:
	virtual void Bind() = 0; // Changes the context to this window
	virtual void Resize(unsigned int width, unsigned int height) = 0;
	virtual void UpdateTitle(const String& title) = 0;

private:
	Queue<Submission> frameSubmissions; // The draw calls to submit this frame

}

}