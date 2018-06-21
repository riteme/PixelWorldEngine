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
DataManager dataManger = DataManager(&application);

int main() {
	auto texture = dataManger.RegisterTexture(L"C:/Users/LinkC/Pictures/T1.jpg");
	pixelWorld.SetResolution(1920, 1080);
	pixelWorld.SetCamera(Camera(PixelWorldEngine::Rectangle(0, 0, 1920, 1080)));
	pixelWorld.RegisterRenderObjectID(0, texture);

	application.MakeWindow(L"TestApp", 1920, 1080);
	application.SetWorld(&pixelWorld);
	application.ShowWindow();
	application.RunLoop();
}