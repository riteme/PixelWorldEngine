#include "ShaderResource.hpp"

#include "Application.hpp"
#include "Graphics.hpp"

PixelWorldEngine::Graphics::Texture2D::Texture2D(Graphics* Graphics, void * Data, int Width, int Height, PixelFormat PixelFormat, int MipLevels)
{
	graphics = Graphics;

	width = Width;
	height = Height;

	pixelFormat = PixelFormat;
	mipLevels = MipLevels;

	rowPitch = width * Utility::CountPixelFormatSize(pixelFormat);
	size = rowPitch * height;

#ifdef _WIN32

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

	graphics->device->CreateTexture2D(&desc, nullptr, (ID3D11Texture2D**)&resource);

	D3D11_SHADER_RESOURCE_VIEW_DESC desc;
	desc.Format = (DXGI_FORMAT)pixelFormat;
	desc.Texture2D.MipLevels = mipLevels;
	desc.Texture2D.MostDetailedMip = mipLevels - 1;
	desc.ViewDimension = D3D11_SRV_DIMENSION::D3D10_1_SRV_DIMENSION_TEXTURE2D;

	graphics->device->CreateShaderResourceView(resource, &desc, &resourceView);

#endif // _WIN32

	Update(Data);
}

PixelWorldEngine::Graphics::Texture2D::~Texture2D()
{

}

void PixelWorldEngine::Graphics::Texture2D::Update(void * data)
{
	if (data == nullptr) return;

#ifdef _WIN32

	graphics->deviceContext->UpdateSubresource(resource,
		0, nullptr, data, rowPitch, 0);

#endif // _WIN32
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

PixelWorldEngine::Graphics::ShaderResource::~ShaderResource()
{
#ifdef _WIN32
	Utility::Dipose(resource);
	Utility::Dipose(resourceView);
#endif // _WIN32

}
