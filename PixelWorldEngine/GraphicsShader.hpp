#include "pch.hpp"

#include "Graphics.hpp"

#ifndef _GRAPHICSSHADER_H_
#define _GRAPHICSSHADER_H_

namespace PixelWorldEngine {

	namespace Graphics {

		class GraphicsShader {
		private:
			Graphics* graphics;

#if WINDOWS
			ID3D11VertexShader* vertexShader;
			ID3D11PixelShader* pixelShader;
#endif // WINDOWS

		public:
			GraphicsShader(std::vector<byte> ShaderCode,
				const char* VertexShaderFunction = "vs_main", const char* PixelShaderFunction = "ps_main");

			GraphicsShader(std::vector<byte> VertexShaderCode, std::vector<byte> PixelShaderCode);

			~GraphicsShader();
		};

	}

}

#endif // !_GRAPHICSSHADER_H_
