#include "GraphicsRenderTarget.hpp"

#include "Graphics.hpp"
#include "Application.hpp"

PixelWorldEngine::Graphics::RenderTarget::RenderTarget(Graphics* Graphics,Texture2D* texture)
{
	graphics = Graphics;

	width = texture->GetWidth();
	height = texture->GetHeight();

	pixelFormat = texture->GetPixelFormat();

#ifdef _WIN32

	D3D11_RENDER_TARGET_VIEW_DESC viewDesc;

	viewDesc.Format = (DXGI_FORMAT)pixelFormat;
	viewDesc.Texture2D.MipSlice = 0;
	viewDesc.ViewDimension = D3D11_RTV_DIMENSION::D3D11_RTV_DIMENSION_TEXTURE2D;

	graphics->device->CreateRenderTargetView(texture->resource,
		&viewDesc, &renderTarget);

#endif // _WIN32

}

PixelWorldEngine::Graphics::RenderTarget::RenderTarget(Graphics* Graphics, Application* application)
{
	graphics = Graphics;

	width = application->GetWindowWidth();
	height = application->GetWindowHeight();

	pixelFormat = PixelFormat::R8G8B8A8;

#ifdef _WIN32

	ID3D11Texture2D* backBuffer = nullptr;

	application->swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer));

	graphics->device->CreateRenderTargetView(backBuffer, nullptr, &renderTarget);

	Utility::Dipose(backBuffer);
#endif // _WIN32

}

PixelWorldEngine::Graphics::RenderTarget::~RenderTarget()
{
#ifdef _WIN32
	Utility::Dipose(renderTarget);
#endif // _WIN32
}

void PixelWorldEngine::Graphics::RenderTarget::Clear(float red, float green, float blue, float alpha)
{
#ifdef _WIN32

	float color[4] = { red,green,blue,alpha };

	graphics->deviceContext->ClearRenderTargetView(renderTarget, color);

#endif // _WIN32

}

auto PixelWorldEngine::Graphics::RenderTarget::GetWidth() -> int
{
	return width;
}

auto PixelWorldEngine::Graphics::RenderTarget::GetHeight() -> int
{
	return height;
}

auto PixelWorldEngine::Graphics::RenderTarget::GetPixelFormat() -> PixelFormat
{
	return pixelFormat;
}


