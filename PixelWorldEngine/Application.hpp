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

#ifdef WINDOWS
		HWND hwnd = nullptr;

		static LRESULT CALLBACK DefaultWindowProc(HWND hWnd, UINT message,
			WPARAM wParam, LPARAM lParam);
#endif // WINDOWS

	public:

#ifdef WINDOWS
		DXGI_SWAP_CHAIN_DESC swapDesc;

		IDXGISwapChain* swapChain;


#endif //WINDOWS

	private:
		void OnMouseMove(void* sender, PixelWorldEngine::Events::MouseMoveEvent* eventArg);

		void OnMouseWheel(void* sender, PixelWorldEngine::Events::MouseWheelEvent* eventArg);

		void OnMouseClick(void* sender, PixelWorldEngine::Events::MouseClickEvent* eventArg);

		void OnKeyClick(void* sender, PixelWorldEngine::Events::KeyClickEvent* eventArg);

		void OnSizeChange(void* sender, PixelWorldEngine::Events::SizeChangeEvent* eventArg);

		void OnUpdate(void* sender);

#ifdef WINDOWS
		void OnProcessMessage(MSG message);
#endif // WINDOWS


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
