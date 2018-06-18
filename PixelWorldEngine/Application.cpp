#include "Application.hpp"

#ifdef WINDOWS

#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

bool sizeChange = false;

int newWidth;
int newHeight;

LRESULT PixelWorldEngine::Application::DefaultWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_SIZE: {
		sizeChange = true;

		newWidth = LOWORD(lParam);
		newHeight = HIWORD(lParam);

		break;
	}
	case WM_DESTROY: {
		PostQuitMessage(0);
		break;
	}
	default:
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);;
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
	windowWidth = eventArg->width;
	windowHeight = eventArg->height;
}

void PixelWorldEngine::Application::OnUpdate(void * sender)
{
	renderTarget->Clear(0, 0, 0);

	graphics->SetRenderTarget(renderTarget);

#ifdef WINDOWS

	swapChain->Present(0, 0);

#endif // WINDOWS

#ifdef LIUNX
	//交换后台缓冲
#endif // LIUNX


}

#ifdef WINDOWS

void PixelWorldEngine::Application::OnProcessMessage(MSG message)
{
	switch (message.message)
	{
	case WM_MOUSEMOVE: {
		auto eventArg = &Events::MouseMoveEvent();

		eventArg->x = LOWORD(message.lParam);
		eventArg->y = HIWORD(message.lParam);

		OnMouseMove(this, eventArg);
		
		break;
	}

	case WM_LBUTTONDOWN: {		
		auto eventArg = &Events::MouseClickEvent();

		eventArg->x = LOWORD(message.lParam);
		eventArg->y = HIWORD(message.lParam);

		eventArg->button = Events::MouseButton::Left;
		eventArg->isDown = true;

		OnMouseClick(this, eventArg);

		break;
	}

	case WM_LBUTTONUP: {
		auto eventArg = &Events::MouseClickEvent();

		eventArg->x = LOWORD(message.lParam);
		eventArg->y = HIWORD(message.lParam);

		eventArg->button = Events::MouseButton::Left;
		eventArg->isDown = false;

		OnMouseClick(this, eventArg);

		break;
	}

	case WM_MBUTTONDOWN: {
		auto eventArg = &Events::MouseClickEvent();

		eventArg->x = LOWORD(message.lParam);
		eventArg->y = HIWORD(message.lParam);
		eventArg->button = Events::MouseButton::Middle;
		eventArg->isDown = true;

		OnMouseClick(this, eventArg);

		break;
	}

	case WM_MBUTTONUP: {
		auto eventArg = &Events::MouseClickEvent();

		eventArg->x = LOWORD(message.lParam);
		eventArg->y = HIWORD(message.lParam);
		eventArg->button = Events::MouseButton::Middle;
		eventArg->isDown = false;

		OnMouseClick(this, eventArg);

		break;
	}

	case WM_RBUTTONDOWN: {
		auto eventArg = &Events::MouseClickEvent();

		eventArg->x = LOWORD(message.lParam);
		eventArg->y = HIWORD(message.lParam);
		eventArg->button = Events::MouseButton::Right;
		eventArg->isDown = true;

		OnMouseClick(this, eventArg);

		break;
	}

	case WM_RBUTTONUP: {
		auto eventArg = &Events::MouseClickEvent();

		eventArg->x = LOWORD(message.lParam);
		eventArg->y = HIWORD(message.lParam);
		eventArg->button = Events::MouseButton::Right;
		eventArg->isDown = false;

		OnMouseClick(this, eventArg);

		break;
	}

	case WM_KEYDOWN: {
		auto eventArg = &Events::KeyClickEvent();

		eventArg->isDown = true;
		eventArg->keyCode = (KeyCode)message.wParam;

		OnKeyClick(this, eventArg);

		break;
	}

	case WM_KEYUP: {
		auto eventArg = &Events::KeyClickEvent();

		eventArg->isDown = false;
		eventArg->keyCode = (KeyCode)message.wParam;

		OnKeyClick(this, eventArg);

		break;
	}

	case WM_MOUSEWHEEL: {
		auto eventArg = &Events::MouseWheelEvent();

		eventArg->x = GET_X_LPARAM(message.lParam);
		eventArg->y = GET_Y_LPARAM(message.lParam);
		eventArg->offset = HIWORD(message.wParam);

		OnMouseWheel(this, eventArg);

		break;
	}

	default:
		break;
	}

	if (sizeChange == true) {
		auto eventArg = &Events::SizeChangeEvent();

		eventArg->width = newWidth;
		eventArg->height = newHeight;

		OnSizeChange(this, eventArg);

		sizeChange = false;
	}
}

#endif // WINDOWS


PixelWorldEngine::Application::Application(const wchar_t * ApplicationName)
{
	applicationName = (wchar_t*)ApplicationName;

#ifdef WINDOWS
	ImmDisableIME(0);
#endif // WINDOWS

#ifdef LIUNX
	//禁用输入法
#endif // LIUNX
}

PixelWorldEngine::Application::~Application()
{
	delete renderTarget;
	delete graphics;

	renderTarget = nullptr;
	graphics = nullptr;
}

void PixelWorldEngine::Application::MakeWindow(const wchar_t * WindowName, int Width, int Height, const wchar_t * IconName)
{
	windowName = (wchar_t*)WindowName;
	windowWidth = Width;
	windowHeight = Height;
	iconName = (wchar_t*)IconName;

	if (isWindowCreated == true) {

#ifdef WINDOWS
		SetWindowText(hwnd, windowName);

		RECT rect;

		rect.top = 0;
		rect.left = 0;
		rect.right = windowWidth;
		rect.bottom = windowHeight;

		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

		SetWindowPos(hwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top,
			SWP_NOZORDER ^ SWP_NOMOVE);
#endif // WINDOWS

#ifdef LIUNX
		//当窗口已经创建的话，修改他的标题以及宽度和高度
#endif // LIUNX
	}
	else {

		graphics = new Graphics::Graphics();

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
		appInfo.lpszClassName = windowName;

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

		graphics->device->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&device));
		device->GetParent(__uuidof(IDXGIAdapter), reinterpret_cast<void**>(&adapter));
		adapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&factory));

		factory->CreateSwapChain(graphics->device, &swapDesc, &swapChain);

		Utility::Dipose(device);
		Utility::Dipose(adapter);
		Utility::Dipose(factory);
#endif // WINDOWS

#ifdef LIUNX
		//创建了一个窗口，请禁用放大以及使用鼠标改变其大小。窗口默认不显示
		//创建了交换链，请注意不使用多重采样，且后台缓冲格式是R8G8B8A8。
#endif // LIUNX

		renderTarget = new Graphics::RenderTarget(graphics, this);

		isWindowCreated = true;
	}
}

void PixelWorldEngine::Application::ShowWindow()
{

#ifdef WINDOWS

	::ShowWindow(hwnd, SW_SHOW);

#endif // WINDOWS

#ifdef LIUNX
	//显示窗口
#endif // LIUNX

}

void PixelWorldEngine::Application::HideWindow()
{

#ifdef WINDOWS

	::ShowWindow(hwnd, SW_HIDE);

#endif // WINDOWS

#ifdef LIUNX
	//隐藏窗口
#endif // LIUNX


}

void PixelWorldEngine::Application::RunLoop()
{
	while (isWindowCreated == true) {

#ifdef WINDOWS
		MSG message;

		if (PeekMessage(&message, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);

			OnProcessMessage(message);
		}

		if (message.message == WM_QUIT) isWindowCreated = false;
#endif // WINDOWS

#ifdef LIUNX
		//处理消息循环
#endif // LIUNX


		OnUpdate(this);
	}
}

auto PixelWorldEngine::Application::GetWindowWidth() -> int
{
	return windowWidth;
}

auto PixelWorldEngine::Application::GetWindowHeight() -> int
{
	return windowHeight;
}

auto PixelWorldEngine::Application::GetGraphics() -> Graphics::Graphics *
{
	return graphics;
}


