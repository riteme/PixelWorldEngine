#include "pch.hpp"

#ifndef _BASESTRUCT_H_
#define _BASESTRUCT_H_

namespace PixelWorldEngine {

	struct Vertex {
		float x, y, z;
		float red, green, blue, alpha;
		float u1, v1;
	};

	typedef unsigned char byte;

}

#endif // !_BASESTRUCT_H_
