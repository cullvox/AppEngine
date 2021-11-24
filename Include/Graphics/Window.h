#pragma once

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
	Window(GraphicsDevice& device, const String& name, unsigned int width, unsigned int height);
	virtual ~Window() = 0;

public:
	virtual void Bind() = 0; // Changes the context to this window
	virtual void Rename(const String& name);
	virtual void Resize(unsigned int width, unsigned int height) = 0;

}

}