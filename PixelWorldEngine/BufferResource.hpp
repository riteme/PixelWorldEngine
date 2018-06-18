#pragma once

#include "pch.hpp"

namespace PixelWorldEngine {

	namespace Graphics {

		class Graphics;

		enum class BufferType {
			VertexBuffer = 1,
			IndexBuffer = 2,
			ConstantBuffer = 4
		};

		class Buffer {
		private:
			Graphics* graphics;

			int size;
			int count;

			BufferType type;

#ifdef _WIN32
		public:
			D3D11_BUFFER_DESC desc;

			ID3D11Buffer* buffer;
#endif // _WIN32

		public:
			Buffer(Graphics* graphics, void* data, int dataSize, int dataCount = 1, BufferType bufferType = BufferType::ConstantBuffer);
			
			~Buffer();

			void Update(void* data);

			auto GetSize() -> int;

			auto GetCount() -> int;

			auto GetType()->BufferType;
		};
	}
}
