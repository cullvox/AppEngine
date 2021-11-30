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
	IDisplay() {};
	virtual ~IDisplay() = 0 {};
protected:
	IDisplay(const IDisplay& other) {};

public:
	virtual IDisplay* Clone() = 0;
	virtual const void* GetNative() const = 0;
	virtual const std::vector<FVideoMode>& GetVideoModes() = 0;

};


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class IWindow : public virtual IResource
{
public:
	IWindow() {};
	IWindow(IGraphicsFactory* factory, const std::string& title, unsigned int width, unsigned int height, IDisplay* display) {};
	virtual ~IWindow() = 0 {};
protected:
	IWindow(const IWindow& other) {};

public:
	static const std::vector<std::unique_ptr<IDisplay>>& GetCurrentDisplays();

public:
	virtual IWindow* Clone() = 0;

	virtual void Bind() = 0;
	virtual void* GetNative() const = 0;
	virtual void Resize(unsigned int width, unsigned int height) = 0;
	virtual void SetTitle(const std::string& title) = 0;

//	Drawing
	virtual void SetView(const SMatrix4f& view) = 0;
	virtual void SetProjection(const SMatrix4f& projection) = 0;
	virtual void SubmitToQueue(const FSubmission& submission) = 0;
	virtual void NextFrame() = 0;

};

}