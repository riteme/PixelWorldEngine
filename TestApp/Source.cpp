#include "..\PixelWorldEngine\Application.hpp"
#include "..\PixelWorldEngine\DebugLayer.hpp"

using namespace PixelWorldEngine;

int main() {
	Application application(L"Application");

	application.MakeWindow(L"TestApp", 1280, 720, nullptr);
	application.ShowWindow();
	application.RunLoop();
}