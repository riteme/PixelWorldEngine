#include "pch.hpp"

#ifndef _SHADERRESOURCE_H_
#define _SHADERRESOURCE_H_

#include "Utility.hpp"
#include "GraphicsEnum.hpp"

namespace PixelWorldEngine {

	namespace Graphics {

		class Graphics;

		class ShaderResource {
		public:
			virtual auto GetResource() -> void* { return nullptr; };
		};

		class Texture2D :ShaderResource {
		protected:
			Graphics* graphics;

			int width, height;

			int size;
			int rowPitch;
			int mipLevels;

			PixelFormat pixelFormat;

#ifdef WINDOWS
			D3D11_TEXTURE2D_DESC desc;

			ID3D11Texture2D* texture;
#endif // WINDOWS

		public:
			Texture2D(void* Data, int Width, int Height, PixelFormat PixelFormat = PixelFormat::Unknown, int MipLevels = 1);

			~Texture2D();

			void Update(void* data);

			auto GetWidth() -> int;

			auto GetHeight() -> int;

			auto GetSize() -> int;

			auto GetMipLevels() -> int;

			auto GetPixelFormat()->PixelFormat;

			auto GetResource() -> void* override;
		};
	}
}

#endif // !_SHADERRESOURCE_H_
