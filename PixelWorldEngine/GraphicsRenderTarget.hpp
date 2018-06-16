#include "pch.hpp"

#ifndef _GRAPHICSRENDERTARGET_H_
#define _GRAPHICSRENDERTARGET_H_

#include "GraphicsEnum.hpp"
#include "ShaderResource.hpp"

namespace PixelWorldEngine {

	class Application;

	namespace Graphics {

		class Graphics;

		class RenderTarget {
		private:
			Graphics* graphics;
			
			int width, height;

			PixelFormat pixelFormat;

#ifdef WINDOWS
			ID3D11RenderTargetView* renderTarget;
#endif // WINDOWS

		public:
			RenderTarget(Texture2D texture);

			RenderTarget(Application application);

			~RenderTarget();

			auto GetWidth() -> int;

			auto GetHeight() -> int;

			auto GetPixelFormat() -> PixelFormat;
		};

	}

}

#endif // !_GRAPHICSRENDERTARGET_H_
