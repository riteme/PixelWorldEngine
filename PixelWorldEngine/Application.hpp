#include "pch.hpp"

#include "KeyCode.hpp"
#include "Events.hpp"

#include "Graphics.hpp"

#ifndef _APPLICATION_H_
#define _APPLICATION_H_

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
#endif // _WINDOWS_
	private:
		void OnMouseMove(void* sender, PixelWorldEngine::Events::MouseMoveEvent* eventArg);

		void OnMouseWheel(void* sender, PixelWorldEngine::Events::MouseWheelEvent* eventArg);

		void OnMouseClick(void* sender, PixelWorldEngine::Events::MouseClickEvent* eventArg);

		void OnKeyClick(void* sender, PixelWorldEngine::Events::KeyClickEvent* eventArg);

		void OnSizeChange(void* sender, PixelWorldEngine::Events::SizeChangeEvent* eventArg);
	public:
		Application(const wchar_t* ApplicationName);

		void MakeWindow(const wchar_t* WindowName, int Width, int Height, const wchar_t* IconName = L"");

		void MakeSurface();

		void ShowWindow();

		void HideWindow();

		void RunLoop();

		static auto GetGraphicsInstance() -> Graphics::Graphics*;
	};

}

#endif // !_APPLICATION_H_
