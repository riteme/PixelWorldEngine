#include "Events.hpp"

PixelWorldEngine::Events::MouseMoveEvent::MouseMoveEvent(int X, int Y)
{
	x = X;
	y = Y;
}

PixelWorldEngine::Events::MouseClickEvent::MouseClickEvent(int X, int Y, bool IsDown, MouseButton Button)
{
	x = X;
	y = Y;
	isDown = IsDown;
	button = Button;
}

PixelWorldEngine::Events::MouseWheelEvent::MouseWheelEvent(int X, int Y, int Offset)
{
	x = X;
	y = Y;
	offset= Offset;
}

PixelWorldEngine::Events::KeyClickEvent::KeyClickEvent(KeyCode KeyCode, bool IsDown)
{
	keyCode = KeyCode;
	isDown = IsDown;
}

PixelWorldEngine::Events::SizeChangeEvent::SizeChangeEvent(int LastWidth, int LastHeight, int NowWidth, int NowHeight)
{
	lastWidth = LastWidth;
	lastHeight = LastHeight;

	nowWidth = NowWidth;
	nowHeight = NowHeight;
}
