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
		};

		//MouseWheel Event
		struct MouseWheelEvent :EventBase {
			int x, y;
			int offset; //the mouse wheel move + is up,- is down

			MouseWheelEvent() = default;
		};

		//BoardClick Event
		struct KeyClickEvent :EventBase {
			KeyCode keyCode;
			bool isDown;

			KeyClickEvent() = default;
		};

		//SizeChange Event
		struct SizeChangeEvent :EventBase {
			int width;
			int height;

			SizeChangeEvent() = default;
		};
	}
}

#endif // !_EVENTS_H_

