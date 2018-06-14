#include "Utility.hpp"

auto PixelWorldEngine::Utility::CharArrayToString(char str[]) -> std::string
{
	auto length = strlen(str);

	std::string result;
	
	for (size_t i = 0; i < length; i++) 
		result.push_back(str[i]);

	return result;
}

