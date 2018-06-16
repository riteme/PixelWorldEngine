#include "Application.hpp"
#include "DebugLayer.hpp"

#pragma comment(lib,"Imm32.lib")

#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)


static bool isApplicationCreated = false;

PixelWorldEngine::Application* self = nullptr;

#ifdef WINDOWS

LRESULT PixelWorldEngine::Application::DefaultWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_MOUSEMOVE: {
		auto eventArg = &Events::MouseMoveEvent();

		eventArg->x = LOWORD(lParam);
		eventArg->y = HIWORD(lParam);

		self->OnMouseMove(self, eventArg);

		break;
	}

	case WM_LBUTTONDOWN: {
		auto eventArg = &Events::MouseClickEvent();

		eventArg->x = LOWORD(lParam);
		eventArg->y = HIWORD(lParam);
		eventArg->button = Events::MouseButton::Left;
		eventArg->isDown = true;

		self->OnMouseClick(self, eventArg);

		break;
	}

	case WM_LBUTTONUP: {
		auto eventArg = &Events::MouseClickEvent();

		eventArg->x = LOWORD(lParam);
		eventArg->y = HIWORD(lParam);
		eventArg->button = Events::MouseButton::Left;
		eventArg->isDown = false;

		self->OnMouseClick(self, eventArg);

		break;
	}

	case WM_MBUTTONDOWN: {
		auto eventArg = &Events::MouseClickEvent();

		eventArg->x = LOWORD(lParam);
		eventArg->y = HIWORD(lParam);
		eventArg->button = Events::MouseButton::Middle;
		eventArg->isDown = true;

		self->OnMouseClick(self, eventArg);

		break;
	}

	case WM_MBUTTONUP: {
		auto eventArg = &Events::MouseClickEvent();

		eventArg->x = LOWORD(lParam);
		eventArg->y = HIWORD(lParam);
		eventArg->button = Events::MouseButton::Middle;
		eventArg->isDown = false;

		self->OnMouseClick(self, eventArg);

		break;
	}

	case WM_RBUTTONDOWN: {
		auto eventArg = &Events::MouseClickEvent();

		eventArg->x = LOWORD(lParam);
		eventArg->y = HIWORD(lParam);
		eventArg->button = Events::MouseButton::Right;
		eventArg->isDown = true;

		self->OnMouseClick(self, eventArg);

		break;
	}

	case WM_RBUTTONUP: {
		auto eventArg = &Events::MouseClickEvent();

		eventArg->x = LOWORD(lParam);
		eventArg->y = HIWORD(lParam);
		eventArg->button = Events::MouseButton::Right;
		eventArg->isDown = false;

		self->OnMouseClick(self, eventArg);

		break;
	}

	case WM_KEYDOWN: {
		auto eventArg = &Events::KeyClickEvent();

		eventArg->isDown = true;
		eventArg->keyCode = (KeyCode)wParam;

		self->OnKeyClick(self, eventArg);

		break;
	}

	case WM_KEYUP: {
		auto eventArg = &Events::KeyClickEvent();

		eventArg->isDown = false;
		eventArg->keyCode = (KeyCode)wParam;

		self->OnKeyClick(self, eventArg);

		break;
	}

	case WM_MOUSEWHEEL: {
		auto eventArg = &Events::MouseWheelEvent();

		eventArg->x = GET_X_LPARAM(lParam);
		eventArg->y = GET_Y_LPARAM(lParam);
		eventArg->offset = HIWORD(wParam);

		self->OnMouseWheel(self, eventArg);

		break;
	}

	case WM_SIZE: {
		auto eventArg = &Events::SizeChangeEvent();

		eventArg->lastWidth = self->windowWidth;
		eventArg->lastHeight = self->windowHeight;
		eventArg->nowWidth = LOWORD(lParam);
		eventArg->nowHeight = HIWORD(lParam);

		self->OnSizeChange(self, eventArg);

		break;
	}

	case WM_DESTROY: {
		PostQuitMessage(0);
		break;
	}
	default:
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

#endif // WINDOWS

void PixelWorldEngine::Application::OnMouseMove(void * sender, PixelWorldEngine::Events::MouseMoveEvent * eventArg)
{
	mousePositionX = eventArg->x;
	mousePositionY = eventArg->y;
}

void PixelWorldEngine::Application::OnMouseWheel(void * sender, PixelWorldEngine::Events::MouseWheelEvent * eventArg)
{

}

void PixelWorldEngine::Application::OnMouseClick(void * sender, PixelWorldEngine::Events::MouseClickEvent * eventArg)
{

}

void PixelWorldEngine::Application::OnKeyClick(void * sender, PixelWorldEngine::Events::KeyClickEvent * eventArg)
{

}

void PixelWorldEngine::Application::OnSizeChange(void * sender, PixelWorldEngine::Events::SizeChangeEvent * eventArg)
{
	windowWidth = eventArg->nowWidth;
	windowHeight = eventArg->nowHeight;
}

void PixelWorldEngine::Application::OnUpdate(void * sender)
{
	swapChain->Present(0, 0);
}

PixelWorldEngine::Application::Application(const wchar_t* ApplicationName)
{
	DebugLayer::Assert(isApplicationCreated, Error::MoreThanOneInstance);

	applicationName = (wchar_t*)ApplicationName;

	ImmDisableIME(0);

	isApplicationCreated = true;

	self = this;
}

void PixelWorldEngine::Application::MakeWindow(const wchar_t* WindowName, int Width, int Height,const wchar_t* IconName)
{
	windowName = (wchar_t*)WindowName;
	windowWidth = Width;
	windowHeight = Height;
	iconName = (wchar_t*)IconName;

	if (isWindowCreated == true) {

#ifdef WINDOWS

		SetWindowText(hwnd, &windowName[0]);
		SetWindowPos(hwnd, nullptr, 0, 0, windowWidth, windowHeight,
			SWP_NOZORDER ^ SWP_NOMOVE);

#endif // WINDOWS

	}
	else {

#ifdef WINDOWS

		auto hInstance = GetModuleHandle(0);

		WNDCLASS appInfo;

		appInfo.style = CS_HREDRAW | CS_VREDRAW;
		appInfo.lpfnWndProc = DefaultWindowProc;
		appInfo.cbClsExtra = 0;
		appInfo.cbWndExtra = 0;
		appInfo.hInstance = hInstance;
		appInfo.hIcon = (HICON)LoadImage(0, &iconName[0], IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
		appInfo.hCursor = LoadCursor(nullptr, IDC_ARROW);
		appInfo.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		appInfo.lpszMenuName = NULL;
		appInfo.lpszClassName = &windowName[0];

		RegisterClass(&appInfo);

		RECT rect;

		rect.top = 0;
		rect.left = 0;
		rect.right = windowWidth;
		rect.bottom = windowHeight;

		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

		hwnd = CreateWindow(&windowName[0], &windowName[0], WS_OVERLAPPEDWINDOW ^ 
			WS_SIZEBOX ^ WS_MAXIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT,
			rect.right - rect.left, rect.bottom - rect.top, nullptr, nullptr, hInstance, nullptr);

		swapDesc.BufferCount = 1;
		swapDesc.BufferDesc.Format = (DXGI_FORMAT)Graphics::PixelFormat::R8G8B8A8;
		swapDesc.BufferDesc.Height = windowHeight;
		swapDesc.BufferDesc.RefreshRate.Denominator = 1;
		swapDesc.BufferDesc.RefreshRate.Numerator = 60;
		swapDesc.BufferDesc.Scaling = DXGI_MODE_SCALING::DXGI_MODE_SCALING_UNSPECIFIED;
		swapDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER::DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		swapDesc.BufferDesc.Width = windowWidth;
		swapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapDesc.Flags = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
		swapDesc.OutputWindow = hwnd;
		swapDesc.SampleDesc.Count = 1;
		swapDesc.SampleDesc.Quality = 0;
		swapDesc.SwapEffect = DXGI_SWAP_EFFECT::DXGI_SWAP_EFFECT_DISCARD;
		swapDesc.Windowed = true;

		IDXGIDevice* device = nullptr;
		IDXGIAdapter* adapter = nullptr;
		IDXGIFactory* factory = nullptr;

		graphics.device->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&device));
		device->GetParent(__uuidof(IDXGIAdapter), reinterpret_cast<void**>(&adapter));
		adapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&factory));

		factory->CreateSwapChain(graphics.device, &swapDesc, &swapChain);

		Utility::Dipose(device);
		Utility::Dipose(adapter);
		Utility::Dipose(factory);
#endif // WINDOWS

		isWindowCreated = true;

	}
}

void PixelWorldEngine::Application::ShowWindow()
{
#ifdef WINDOWS

	::ShowWindow(hwnd, SW_SHOW);

#endif // WINDOWS
}

void PixelWorldEngine::Application::HideWindow() 
{
#ifdef WINDOWS

	::ShowWindow(hwnd, SW_HIDE);

#endif // WINDOWS
}

void PixelWorldEngine::Application::RunLoop()
{
#ifdef WINDOWS

	MSG message = { 0 };

	while (message.message != WM_QUIT) {
		if (PeekMessage(&message, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		OnUpdate(this);
	}

#endif // WINDOWS
}

auto PixelWorldEngine::Application::GetWindowWidth() -> int
{
	return windowWidth;
}

auto PixelWorldEngine::Application::GetWindowHeight() -> int
{
	return windowHeight;
}

auto PixelWorldEngine::Application::GetGraphicsInstance() -> Graphics::Graphics*
{
	return &self->graphics;
}


