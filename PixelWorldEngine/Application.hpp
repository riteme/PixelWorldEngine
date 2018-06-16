#include "pch.hpp"

#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "KeyCode.hpp"
#include "Events.hpp"

#include "Graphics.hpp"

namespace PixelWorldEngine {

	class Application {
	private:
		wchar_t* applicationName;

		int windowWidth = 0;
		int windowHeight = 0;

		wchar_t* windowName;
		wchar_t* iconName;

		bool isWindowCreated = false;

		int mousePositionX;
		int mousePositionY;

		Graphics::Graphics graphics;

#ifdef WINDOWS
		HWND hwnd = nullptr;

		static LRESULT CALLBACK DefaultWindowProc(HWND hWnd, UINT message,
			WPARAM wParam, LPARAM lParam);
#endif // WINDOWS

	public:

#ifdef WINDOWS

		IDXGISwapChain* swapChain;

		DXGI_SWAP_CHAIN_DESC swapDesc;

#endif //WINDOWS

	private:
		void OnMouseMove(void* sender, PixelWorldEngine::Events::MouseMoveEvent* eventArg);

		void OnMouseWheel(void* sender, PixelWorldEngine::Events::MouseWheelEvent* eventArg);

		void OnMouseClick(void* sender, PixelWorldEngine::Events::MouseClickEvent* eventArg);

		void OnKeyClick(void* sender, PixelWorldEngine::Events::KeyClickEvent* eventArg);

		void OnSizeChange(void* sender, PixelWorldEngine::Events::SizeChangeEvent* eventArg);

		void OnUpdate(void* sender);
	public:
		Application(const wchar_t* ApplicationName);

		void MakeWindow(const wchar_t* WindowName, int Width, int Height, const wchar_t* IconName = L"");

		void ShowWindow();

		void HideWindow();

		void RunLoop();

		auto GetWindowWidth() -> int;

		auto GetWindowHeight() -> int;

		static auto GetGraphicsInstance() -> Graphics::Graphics*;
	};

}

#endif // !_APPLICATION_H_