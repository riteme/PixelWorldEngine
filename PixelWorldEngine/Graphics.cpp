#include "Graphics.hpp"

PixelWorldEngine::Graphics::Graphics::Graphics()
{
#ifdef WINDOWS

	D3D_FEATURE_LEVEL features[4] = {
		D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_10_0
	};

#ifdef DEBUG
	auto createFlag = D3D11_CREATE_DEVICE_FLAG::D3D11_CREATE_DEVICE_DEBUG;
#else
	auto createFlag = 0;
#endif

	D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_HARDWARE,
		0, createFlag, features, 4, D3D11_SDK_VERSION, &device, &feature, &deviceContext);

#endif // WINDOWS
}

PixelWorldEngine::Graphics::Graphics::~Graphics()
{
#ifdef WINDOWS
	Utility::Dipose(device);
	Utility::Dipose(deviceContext);
#endif // WINDOWS
}
