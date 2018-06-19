#pragma once

#include "pch.hpp"

#include "GraphicsEnum.hpp"

namespace PixelWorldEngine {

	class Utility {
	public:
		static auto CharArrayToString(char str[]) -> std::string;

		static auto WCharArrrayToWString(wchar_t str[]) -> std::wstring;

		static auto CharArrayToVector(char str[]) -> std::vector<byte>;

		static auto CountPixelFormatSize(Graphics::PixelFormat pixelFormat) -> int;

		template<typename T>
		static void Dipose(T &object);

		template<typename T>
		static void Delete(T &object);
	};

	template<typename T>
	inline void Utility::Dipose(T & object)
	{
		if (object != nullptr)
			object->Release();
		object = nullptr;
	}

	template<typename T>
	inline void Utility::Delete(T & object)
	{
		if (object != nullptr)
			delete object;
		object = nullptr;
	}


}
