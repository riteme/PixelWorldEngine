#pragma once

#include "pch.hpp"

#include "BaseStruct.hpp"

namespace PixelWorldEngine {

	namespace Graphics {

		class Graphics;

		class GraphicsShader {
		private:
			Graphics* graphics;

			std::vector<byte> compiledVertexShaderCode;
			std::vector<byte> compiledPixelShaderCode;

#ifdef WINDOWS
		public:
			ID3D11VertexShader* vertexShader;
			ID3D11PixelShader* pixelShader;
#endif // WINDOWS

		public:
			GraphicsShader(Graphics* graphics, std::vector<byte> ShaderCode,
				const char* VertexShaderFunction = "vs_main", const char* PixelShaderFunction = "ps_main");

			GraphicsShader(Graphics* graphics, std::vector<byte> VertexShaderCode, std::vector<byte> PixelShaderCode);

			auto GetVertexShaderCode() -> std::vector<byte>;

			auto GetPixelShaderCode() -> std::vector<byte>;

			~GraphicsShader();
		};

	}

}
