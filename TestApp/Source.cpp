#include "..\PixelWorldEngine\Application.hpp"
#include "..\PixelWorldEngine\DebugLayer.hpp"

using namespace PixelWorldEngine;

Application app = Application(L"Application");

int main() {
	app.MakeWindow(L"TestApp", 1280, 720);
	app.ShowWindow();

	app.RunLoop();

}