#pragma once

#include "pch.hpp"

#include "KeyCode.hpp"
#include "Events.hpp"

#include "Graphics.hpp"
#include "GraphicsRenderTarget.hpp"

namespace PixelWorldEngine {

	class Application {
	private:
		std::wstring applicationName;

		int windowWidth = 0;
		int windowHeight = 0;

		std::wstring windowName;
		std::wstring iconName;

		bool isWindowCreated = false;

		int mousePositionX;
		int mousePositionY;

		Graphics::Graphics* graphics;
		Graphics::RenderTarget* renderTarget;

#ifdef _WIN32
		HWND hwnd = nullptr;

		static LRESULT CALLBACK DefaultWindowProc(HWND hWnd, UINT message,
			WPARAM wParam, LPARAM lParam);
#endif // _WIN32

	public:

#ifdef _WIN32
		DXGI_SWAP_CHAIN_DESC swapDesc;

		IDXGISwapChain* swapChain;


#endif //_WIN32

	private:
		void OnMouseMove(void* sender, PixelWorldEngine::Events::MouseMoveEvent* eventArg);

		void OnMouseWheel(void* sender, PixelWorldEngine::Events::MouseWheelEvent* eventArg);

		void OnMouseClick(void* sender, PixelWorldEngine::Events::MouseClickEvent* eventArg);

		void OnKeyClick(void* sender, PixelWorldEngine::Events::KeyClickEvent* eventArg);

		void OnSizeChange(void* sender, PixelWorldEngine::Events::SizeChangeEvent* eventArg);

		void OnUpdate(void* sender);

#ifdef _WIN32
		void OnProcessMessage(MSG message);
#endif // _WIN32


	public:
		Application(const wchar_t* ApplicationName);

		~Application();

		void MakeWindow(const wchar_t* WindowName, int Width, int Height, const wchar_t* IconName = L"");

		void ShowWindow();

		void HideWindow();

		void RunLoop();

		auto GetWindowWidth() -> int;

		auto GetWindowHeight() -> int;

		auto GetGraphics() -> Graphics::Graphics*;
	};

}
