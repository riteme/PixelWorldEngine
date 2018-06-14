#include "pch.hpp"

#ifndef _DEBUGLAYER_H_
#define _DEBUGLAYER_H_

#define MAX_ERROR_TEXT 100

namespace PixelWorldEngine {

	enum class Error {
		//There are more than one application.
		MoreThanOneApplication,
		Count
	};

	static const char* messageTemplate[(int)Error::Count] = {
		"There are more than one application."
	};

	class DebugLayer {
	private:
		static auto GetErrorMessage(Error error, va_list args)->std::string;

		static void ReportMessage(std::string message);
	public:
		static void ReportError(Error error, ...);

		static void Assert(bool test, Error error, ...);

	};

}
#endif // !_DEBUGLAYER_H_
