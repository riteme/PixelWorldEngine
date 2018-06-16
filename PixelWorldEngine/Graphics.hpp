#include "pch.hpp"

#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "Utility.hpp"
#include "DebugLayer.hpp"

#include "GraphicsEnum.hpp"
#include "GraphicsShader.hpp"
#include "BufferResource.hpp"
#include "ShaderResource.hpp"

namespace PixelWorldEngine {

	namespace Graphics {

		class Graphics {
		public:

#ifdef WINDOWS
			ID3D11Device* device;
			ID3D11DeviceContext* deviceContext;

			ID3D11InputLayout* inputLayout;

			D3D_FEATURE_LEVEL feature;
#endif // WINDOWS

		public:
			Graphics();
			
			void SetVertexBuffer(Buffer buffer);
			
			void SetIndexBuffer(Buffer buffer);

			void SetConstantBuffer(Buffer buffer, int id);

			void SetShader(GraphicsShader shader);

			void SetVertexShaderResource(ShaderResource shaderResource, int id);

			void SetPixelShaderResource(ShaderResource shaderResource, int id);

			void DrawIndexed(int indexCount, int startIndexLocation = 0, int baseVertexLocation = 0);

			~Graphics();
		};
	}

}

#endif // !_GRAPHICS_H_
