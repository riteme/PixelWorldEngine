#include "DebugLayer.hpp"
#include "Utility.hpp"

auto PixelWorldEngine::DebugLayer::GetErrorMessage(Error error, va_list args) -> std::string
{
	char result[MAX_ERROR_TEXT];

	vsprintf_s(result, messageTemplate[(int)error], args);

	return Utility::CharArrayToString(result);
}

void PixelWorldEngine::DebugLayer::ReportMessage(std::string message) 
{
#ifdef DEBUG
	std::cout << message << std::endl;
#endif // DEBUG
}

void PixelWorldEngine::DebugLayer::ReportError(Error error, ...)
{
	va_list args;

	va_start(args, error);
	std::string errorMessage = GetErrorMessage(error, args);
	va_end(args);

	ReportMessage(errorMessage);
}

void PixelWorldEngine::DebugLayer::Assert(bool test, Error error, ...)
{
	va_list args;

	va_start(args, error);
	std::string errorMessage = GetErrorMessage(error, args);
	va_end(args);

	if (test == true) ReportMessage(errorMessage);
}
