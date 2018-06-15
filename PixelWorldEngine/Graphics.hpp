#include "pch.hpp"

#include "Utility.hpp"
#include "DebugLayer.hpp"

#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

namespace PixelWorldEngine {

	namespace Graphics {

		class Graphics {
		public:
#ifdef WINDOWS
			ID3D11Device* device;
			ID3D11DeviceContext* deviceContext;

			D3D_FEATURE_LEVEL feature;
#endif // WINDOWS
		public:
			Graphics();

			~Graphics();
		};
	}

}

#endif // !_GRAPHICS_H_
