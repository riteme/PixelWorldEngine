#include "pch.hpp"

#include "GraphicsEnum.hpp"

#ifndef _UTILITY_H_
#define _UTILITY_H_

namespace PixelWorldEngine {

	class Utility {
	public:
		static auto CharArrayToString(char str[]) -> std::string;

		static auto CountPixelFormatSize(Graphics::PixelFormat pixelFormat) -> int;

		template<typename T>
		static void Dipose(T &object);

	};

	template<typename T>
	inline void Utility::Dipose(T & object)
	{
		if (object != nullptr)
			object->Release();
		object = nullptr;
	}

}
#endif // !_UTILITY_H_
