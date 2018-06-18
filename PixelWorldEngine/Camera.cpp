#include "Camera.hpp"

PixelWorldEngine::Camera::Camera(Rectangle rectangle)
{
	rect = rectangle;

	project = glm::ortho(rect.left, rect.right, rect.bottom, rect.top);
}

auto PixelWorldEngine::Camera::GetRectangle() -> Rectangle
{
	return rect;
}

auto PixelWorldEngine::Camera::GetMatrix() -> glm::mat4x4
{
	return project;
}
