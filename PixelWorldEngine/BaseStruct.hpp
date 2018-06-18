#pragma once

#include "pch.hpp"

namespace PixelWorldEngine {

	struct Vertex {
		float x, y, z;
		float red, green, blue, alpha;
		float u1, v1;

		void SetPosition(float X, float Y, float Z) {
			x = X;
			y = Y;
			z = Z;
		}

		void SetTexturePosition1(float u, float v) {
			u1 = u;
			v1 = v;
		}
	};

	struct Rectangle {
		int left;
		int top;
		int right;
		int bottom;

		Rectangle() = default;
	};

}

