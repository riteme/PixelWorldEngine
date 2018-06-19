#include "..\PixelWorldEngine\Application.hpp"
#include "..\PixelWorldEngine\DebugLayer.hpp"
#include "..\PixelWorldEngine\PixelWorld.hpp"

using namespace PixelWorldEngine;
using namespace PixelWorldEngine::Graphics;

#ifdef _WIN32

#ifndef _DEBUG

#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#endif // _DEBUG

#endif // !_WIN32


Application application = Application(L"Application");
PixelWorld pixelWorld = PixelWorld(L"PixelWorld", &application);

int main() {

	pixelWorld.SetResolution(1280, 720);
	application.MakeWindow(L"TestApp", 1280, 720);
	application.ShowWindow();
	application.RunLoop();
}