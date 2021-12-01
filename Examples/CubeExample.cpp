#include "Graphics/GraphicsFactory.h"

int main()
{
	// Create the graphics factory
	AE::FGraphicsOptions graphicsOptions = {};
	std::unique_ptr<AE::IGraphicsFactory> graphicsFactory = AE::CreateGraphicsFactory(graphicsOptions);

	// Get the first display listed and its video modes
	const std::vector<std::unique_ptr<AE::IDisplay>>& displays = AE::IWindow::GetCurrentDisplays();
	AE::IDisplay* display = displays[0].get();
	std::vector<AE::FVideoMode> vidModes = display->GetVideoModes();
	AE::FVideoMode& mode = vidModes.back();

	// Create a window
	std::unique_ptr<AE::IWindow> window = graphicsFactory->CreateWindow("CubeExample", mode.width, mode.height, nullptr);

	// Create the default material shader

	// Create the vertex buffer
	std::vector<AE::Vertex> vertices =
	{
		{{ 1.0f, -1.0f, -1.0f}, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f}},
		{{ 1.0f, -1.0f,  1.0f}, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f}},
		{{-1.0f, -1.0f,  1.0f}, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f}},
		{{-1.0f, -1.0f, -1.0f}, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f}},
		{{ 1.0f,  1.0f, -1.0f}, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f}},
		{{ 1.0f,  1.0f,  1.0f}, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f}},
		{{-1.0f,  1.0f,  1.0f}, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f}},
		{{-1.0f,  1.0f, -1.0f}, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f}}
	};

	std::unique_ptr<AE::IVertexBuffer> vertexBuffer = graphicsFactory->CreateVertexBuffer(AE::DefaultVertexFormat, vertices);

	// Create the index buffer
	std::vector<unsigned short> indices =
	{
		/*front*/
		0, 1, 2,
		2, 3, 0,
		/*top*/
		1, 5, 6,
		6, 2, 1,
		/*back*/
		7, 6, 5,
		5, 4, 7,
		/*bottom*/
		4, 0, 3,
		3, 7, 4,
		/*left*/
		4, 5, 1,
		1, 0, 4,
		/*right*/
		3, 2, 6,
		6, 7, 3
	};

	std::shared_ptr<AE::IIndexBuffer> indexBuffer = graphicsFactory->CreateIndexBuffer(indices);

	// The application loop
	while (!window->IsCloseRequested())
	{
		AE::FSubmission submission;

		submission
			.setVertexBuffer(vertexBuffer.get())
			.setIndexBuffer(indexBuffer.get())
			.setPipeline()

		window->Submit()

		window->NextFrame();
	}


}