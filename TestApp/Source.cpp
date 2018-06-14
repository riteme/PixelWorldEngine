#include "..\PixelWorldEngine\Application.hpp"
#include "..\PixelWorldEngine\DebugLayer.hpp"

using namespace PixelWorldEngine;

Application app = Application(L"Application");

int main() {
	

	app.MakeWindow(L"TestApp", 800, 600);
	app.ShowWindow();

	app.RunLoop();

}