#include "pch.hpp"

#include "Graphics.hpp"

#ifndef _BUFFERRESOURCE_H_
#define _BUFFERRESOURCE_H_

namespace PixelWorldEngine {

	namespace Graphics {

		enum class BufferType {
			VertexBuffer = 1,
			IndexBuffer = 2,
			ConstantBuffer = 4
		};

		class Buffer {
		private:
			Graphics * graphics;

			int size;
			int count;

			BufferType type;
#if WINDOWS
			D3D11_BUFFER_DESC desc;

			ID3D11Buffer* buffer;
#endif // WINDOWS

		public:
			Buffer(void* data, int dataSize, int dataCount = 1, BufferType bufferType = BufferType::ConstantBuffer);
			
			~Buffer();

			void Update(void* data);

			auto GetSize() -> int;

			auto GetCount() -> int;

			auto GetType()->BufferType;

			auto GetResource() -> void*;
		};
	}
}

#endif // !_BUFFERRESOURCE_H_
