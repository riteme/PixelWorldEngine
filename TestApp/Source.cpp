#include "..\PixelWorldEngine\Application.hpp"
#include "..\PixelWorldEngine\DebugLayer.hpp"

using namespace PixelWorldEngine;

Application application(L"Application");

int main() {
	
	application.MakeWindow(L"TestApp", 1280, 720, nullptr);
	application.ShowWindow();
	application.RunLoop();
}