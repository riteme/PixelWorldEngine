#include "PixelWorld.hpp"

#include "Application.hpp"
#include "EngineDefaultResource.hpp"

PixelWorldEngine::PixelWorld::PixelWorld(std::wstring WorldName, Application * Application)
{
	worldName = WorldName;
	graphics = Application->GetGraphics();

	square = new Graphics::Rectangle(0, 0, 1, 1, graphics);

	defaultShader = new Graphics::GraphicsShader(graphics, Utility::CharArrayToVector((char*)defaultShaderCode));

	SetShader();
}

PixelWorldEngine::PixelWorld::~PixelWorld()
{
	Utility::Delete(defaultShader);
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

void PixelWorldEngine::PixelWorld::SetShader(Graphics::GraphicsShader * Shader)
{
	shader = Shader;

	graphics->SetShader(shader);
}

void PixelWorldEngine::PixelWorld::SetShader()
{
	shader = defaultShader;

	graphics->SetShader(shader);
}

auto PixelWorldEngine::PixelWorld::GetCurrentWorld() -> Graphics::Texture2D *
{
	renderTarget->Clear(0, 0, 0);

	graphics->SetRenderTarget(renderTarget);

	graphics->SetVertexBuffer(square->GetVertexBuffer());
	graphics->SetIndexBuffer(square->GetIndexBuffer());

	return renderBuffer;
}





