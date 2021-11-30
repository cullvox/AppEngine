#pragma once

// IWindow.h
// Contains a display and system window/drawable surface abstraction

#include <memory>
#include <vector>
#include <string>

#include "Containers/Queue.h"
#include "Graphics/Resource.h"
#include "Graphics/Submission.h"

namespace AE
{

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
struct FVideoMode
{
	FVideoMode()
	{
	}

	FVideoMode(unsigned int _width, unsigned int _height, unsigned int _refreshRate)
		: width(_width), height(_height), refreshRate(_refreshRate)
	{
	}

	unsigned int width;
	unsigned int height;
	unsigned int refreshRate;
};


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class IDisplay : public virtual ICloneable
{

public:
	IDisplay();
	virtual ~IDisplay();
protected:
	IDisplay(const IDisplay& other);

public:
	virtual IDisplay* Clone();

	virtual const void* GetNative() const;
	virtual const std::vector<FVideoMode>& GetVideoModes();

protected:
	std::vector<FVideoMode> m_VideoModes;

};


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class IWindow : public virtual IResource
{
public:
	IWindow();
	IWindow(IGraphicsFactory* factory, const std::string& title, unsigned int width, unsigned int height, IDisplay* display);
	virtual ~IWindow() {}
protected:
	IWindow(const IWindow& other);

public:
	virtual IWindow* Clone();

	virtual const std::vector<std::unique_ptr<IDisplay>>& GetCurrentDisplays();

	virtual void Bind();
	virtual void* GetNative() const;
	virtual void Resize(unsigned int width, unsigned int height);
	virtual void SetTitle(const std::string& title);

//	Drawing
	virtual void SetView(const SMatrix4f& view);
	virtual void SetProjection(const SMatrix4f& projection);
	virtual void SubmitToQueue(const FSubmission& submission);
	virtual void NextFrame(); // Submits the framesubmissions and then clears queue

protected:
	static std::vector<std::unique_ptr<IDisplay>> mg_Displays;
	Queue<FSubmission> m_Submissions; // The draw calls to submit this frame

};

}