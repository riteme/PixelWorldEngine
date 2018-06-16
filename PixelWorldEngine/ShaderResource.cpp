#include "ShaderResource.hpp"

#include "Application.hpp"
#include "Graphics.hpp"

PixelWorldEngine::Graphics::Texture2D::Texture2D(void * Data, int Width, int Height, PixelFormat PixelFormat, int MipLevels)
{
	graphics = Application::GetGraphicsInstance();

	width = Width;
	height = Height;

	pixelFormat = PixelFormat;
	mipLevels = MipLevels;

	rowPitch = width * Utility::CountPixelFormatSize(pixelFormat);
	size = rowPitch * height;

#ifdef WINDOWS

	desc.ArraySize = 1;
	desc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags = 0;
	desc.Format = (DXGI_FORMAT)pixelFormat;
	desc.Height = height;
	desc.MipLevels = mipLevels;
	desc.MiscFlags = 0;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
	desc.Width = width;

	graphics->device->CreateTexture2D(&desc, nullptr, &texture);

#endif // WINDOWS

	Update(Data);
}

PixelWorldEngine::Graphics::Texture2D::~Texture2D()
{
#ifdef WINDOWS
	Utility::Dipose(texture);
#endif // WINDOWS

}

void PixelWorldEngine::Graphics::Texture2D::Update(void * data)
{
#ifdef WINDOWS

	graphics->deviceContext->UpdateSubresource(texture,
		0, nullptr, data, rowPitch, 0);

#endif // WINDOWS
}

auto PixelWorldEngine::Graphics::Texture2D::GetWidth() -> int
{
	return width;
}

auto PixelWorldEngine::Graphics::Texture2D::GetHeight() -> int
{
	return height;
}

auto PixelWorldEngine::Graphics::Texture2D::GetSize() -> int
{
	return size;
}

auto PixelWorldEngine::Graphics::Texture2D::GetMipLevels() -> int
{
	return mipLevels;
}

auto PixelWorldEngine::Graphics::Texture2D::GetPixelFormat() -> PixelFormat
{
	return pixelFormat;
}

auto PixelWorldEngine::Graphics::Texture2D::GetResource() -> void *
{
#ifdef WINDOWS
	return texture;
#endif
}
