#pragma once

// IWindow.h
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

struct SVideoMode : public INonCopyable
{
	SVideoMode(unsigned int _width, unsigned int _height, unsigned int _refreshRate)
		: width(_width), height(_height), refreshRate(_refreshRate)
	{
	}

	unsigned int width;
	unsigned int height;
	unsigned int refreshRate;
};

class IDisplay
{

public:
	IDisplay();
	IDisplay(const IDisplay& other);
	virtual ~IDisplay();

public:
	IDisplay& operator=(const IDisplay& other);

public:
	const TArray<SVideoMode>& GetVideoModes();
	const void* GetNative() const;

};

class IWindow : public IResource
{
public:
	IWindow();
	IWindow(const IWindow& other); // Preforms a Shallow Copy
	IWindow(IGraphicsFactory* factory);
	IWindow(IGraphicsFactory* factory, const SString& title, unsigned int width, unsigned int height, IDisplay* display);
	virtual ~IWindow() = 0;

public:
	virtual void Resize(unsigned int width, unsigned int height) = 0;
	virtual void SetTitle(const SString& title) = 0;
	virtual void* GetNative () const = 0;

// Drawing
public:
	virtual void SetView(const SMatrix4f& view) = 0;
	virtual void SetProjection(const SMatrix4f& projection) = 0;
	virtual void SubmitToQueue(const SSubmission& submission) = 0;
	virtual void NextFrame() = 0; // Submits the framesubmissions and then clears queue

private:
	Queue<SSubmission> m_Submissions; // The draw calls to submit this frame

};

}