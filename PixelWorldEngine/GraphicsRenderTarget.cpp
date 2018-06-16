#include "GraphicsRenderTarget.hpp"

#include "Graphics.hpp"
#include "Application.hpp"

PixelWorldEngine::Graphics::RenderTarget::RenderTarget(Texture2D texture)
{
	graphics = Application::GetGraphicsInstance();

	width = texture.GetWidth();
	height = texture.GetHeight();

	pixelFormat = texture.GetPixelFormat();

#ifdef WINDOWS

	D3D11_RENDER_TARGET_VIEW_DESC viewDesc;

	viewDesc.Format = (DXGI_FORMAT)pixelFormat;
	viewDesc.Texture2D.MipSlice = 0;
	viewDesc.ViewDimension = D3D11_RTV_DIMENSION::D3D11_RTV_DIMENSION_TEXTURE2D;

	graphics->device->CreateRenderTargetView((ID3D11Resource*)texture.GetResource(),
		&viewDesc, &renderTarget);

#endif // WINDOWS

}

PixelWorldEngine::Graphics::RenderTarget::RenderTarget(Application application)
{
	graphics = Application::GetGraphicsInstance();

	width = application.GetWindowWidth();
	height = application.GetWindowHeight();

	pixelFormat = PixelFormat::R8G8B8A8;

#ifdef WINDOWS

	ID3D11Texture2D* backBuffer = nullptr;

	application.swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer));

	graphics->device->CreateRenderTargetView(backBuffer, nullptr, &renderTarget);

	Utility::Dipose(backBuffer);
#endif // WINDOWS

}

PixelWorldEngine::Graphics::RenderTarget::~RenderTarget()
{
#ifdef WINDOWS
	Utility::Dipose(renderTarget);
#endif // WINDOWS
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


