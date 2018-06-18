#include "..\PixelWorldEngine\Application.hpp"
#include "..\PixelWorldEngine\DebugLayer.hpp"
#include "..\PixelWorldEngine\PixelWorld.hpp"

using namespace PixelWorldEngine;

#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

Application application = Application(L"Application");
PixelWorld pixelWorld = PixelWorld(L"PixelWorld", &application);

int main() {


	pixelWorld.SetResolution(1280, 720);
	application.MakeWindow(L"TestApp", 1280, 720);
	application.ShowWindow();
	application.RunLoop();
}