#pragma once

#include "pch.hpp"

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

#ifdef _WIN32
		public:
			ID3D11RenderTargetView* renderTarget;
#endif // _WIN32

		public:
			RenderTarget(Graphics* graphics, Texture2D* texture);

			RenderTarget(Graphics* graphics, Application* application);

			~RenderTarget();

			void Clear(float red, float green, float blue, float alpha = 1);

			auto GetWidth() -> int;

			auto GetHeight() -> int;

			auto GetPixelFormat() -> PixelFormat;
		};

	}

}
