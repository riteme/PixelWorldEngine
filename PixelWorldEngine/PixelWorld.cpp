#include "PixelWorld.hpp"

#include "Application.hpp"

PixelWorldEngine::PixelWorld::PixelWorld(std::wstring WorldName, Application * Application)
{
	worldName = WorldName;
	graphics = Application->GetGraphics();

	rectangle = new Graphics::Rectangle(0, 0, 1, 1, graphics);
}

PixelWorldEngine::PixelWorld::~PixelWorld()
{
	Utility::Delete(renderBuffer);
	Utility::Delete(renderTarget);
}

void PixelWorldEngine::PixelWorld::SetResolution(int width, int height)
{
	if (width == resolutionWidth || height == resolutionHeight) return;

	Utility::Delete(renderBuffer);
	Utility::Delete(renderTarget);

	resolutionWidth = width;
	resolutionHeight = height;

	renderBuffer = new Graphics::Texture2D(graphics, nullptr, resolutionWidth, resolutionHeight,
		Graphics::PixelFormat::R8G8B8A8);

	renderTarget = new Graphics::RenderTarget(graphics, renderBuffer);
}

void PixelWorldEngine::PixelWorld::SetCamera(Camera Camera)
{
	camera = Camera;
}

auto PixelWorldEngine::PixelWorld::GetCurrentWorld() -> Graphics::Texture2D *
{
	renderTarget->Clear(0, 0, 0);

	graphics->SetRenderTarget(renderTarget);

	return renderBuffer;
}





