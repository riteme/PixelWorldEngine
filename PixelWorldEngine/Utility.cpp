#include "Utility.hpp"

auto PixelWorldEngine::Utility::CharArrayToString(char str[]) -> std::string
{
	auto length = strlen(str);

	std::string result;
	
	for (size_t i = 0; i < length; i++) 
		result.push_back(str[i]);

	return result;
}

auto PixelWorldEngine::Utility::CountPixelFormatSize(Graphics::PixelFormat pixelFormat) -> int
{
	switch (pixelFormat)
	{
	case PixelWorldEngine::Graphics::PixelFormat::Unknown:
		return 0;
	case PixelWorldEngine::Graphics::PixelFormat::R32G32B32A32_Float:
		return 16;
	case PixelWorldEngine::Graphics::PixelFormat::R8G8B8A8:
		return 8;
	default:
		return 0;
	}
}
