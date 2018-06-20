#pragma once

#include "pch.hpp"

namespace PixelWorldEngine {

	struct Vertex {
		float x, y, z;
		float red, green, blue, alpha;
		float u0, v0;

		void SetPosition(float X, float Y, float Z) {
			x = X;
			y = Y;
			z = Z;
		}

		void SetTexturePosition1(float u, float v) {
			u0 = u;
			v0 = v;
		}
	};

	struct Rectangle {
		float left;
		float top;
		float right;
		float bottom;

		Rectangle() = default;

		Rectangle(float Left, float Top, float Right, float Bottom) {
			left = Left;
			top = Top;
			right = Right;
			bottom = Bottom;
		}
	};

}

