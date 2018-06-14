#include "pch.hpp"

#include "KeyCode.hpp"

#ifndef _EVENTS_H_
#define _EVENTS_H_

namespace PixelWorldEngine {

#define NO_MESSAGE -1

	namespace Events {

		enum class EventType :int {
			EventOther,
			EventMouseMove,
			EventMouseClick,
			EventMouseWheel,
			EventBoardClick,
			EventGetFocus,
			EventLostFocus,
			EventMouseLeave,
			EventSizeChanged
		};

		//Base Event
		struct EventBase {

		};


		//MouseMove Event
		struct MouseMoveEvent :EventBase {
			int x, y;

			MouseMoveEvent() = default;

			MouseMoveEvent(int X, int Y);
		};

		//enum of mouse button
		enum MouseButton {
			Left, Middle, Right
		};

		//MouseClick Event
		struct MouseClickEvent :EventBase {
			int x, y;
			bool isDown;
			MouseButton button;

			MouseClickEvent() = default;

			MouseClickEvent(int X, int Y, bool IsDown, MouseButton Button);
		};

		//MouseWheel Event
		struct MouseWheelEvent :EventBase {
			int x, y;
			int offset; //the mouse wheel move + is up,- is down

			MouseWheelEvent() = default;

			MouseWheelEvent(int X, int Y, int Offset);
		};

		//BoardClick Event
		struct KeyClickEvent :EventBase {
			KeyCode keyCode;
			bool isDown;

			KeyClickEvent() = default;

			KeyClickEvent(KeyCode KeyCode, bool IsDown);
		};

		//SizeChange Event
		struct SizeChangeEvent :EventBase {
			int lastWidth, lastHeight;
			int nowWidth, nowHeight;

			SizeChangeEvent() = default;

			SizeChangeEvent(int LastWidth, int LastHeight,
				int NowWidth, int NowHeight);
		};
	}
}

#endif // !_EVENTS_H_

