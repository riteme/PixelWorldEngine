#pragma once

#include "pch.hpp"

#include "DataManager.hpp"
#include "Graphics.hpp"

#include "Geometry.hpp"
#include "Utility.hpp"
#include "Camera.hpp"

namespace PixelWorldEngine {

	/**
	 * 用来表述用途不同的缓冲的在着色器以及数组的ID
	 */
	enum class BufferIndex : int {
		CameraBuffer, //摄像机矩阵缓冲
		TransformBuffer, //变换矩阵缓冲
		Count
	};

	/**
	 * @brief 引擎的核心世界
	 */
	class PixelWorld {
	private:
		std::wstring worldName; //世界的名字 

		int resolutionWidth; //分辨率宽度
		int resolutionHeight; //分辨率高度

		Camera camera; //摄像机

		Graphics::Graphics* graphics; //...

		Graphics::Texture2D* renderBuffer; //存储世界被渲染后的像素信息
		Graphics::RenderTarget* renderTarget; //..

		Graphics::GraphicsShader* defaultShader; //默认着色器
		Graphics::GraphicsShader* shader; //使用的着色器

		std::vector<Graphics::Buffer*> buffers; //缓冲数组

		Graphics::Rectangle* square; //正方形
		Graphics::Rectangle* renderObject; //画布

		Graphics::StaticSampler* defaultSampler; //默认的采样器

		std::map<int, Graphics::Texture2D*> renderObjectIDGroup; //用于存储纹理，不同的ID对应不同的纹理

		friend class Application;
	public:
		/**
		 * @brief 构造函数
		 * @param[in] WorldName 世界的名字
		 * @param[in] Application 呈现世界的应用程序
		 */
		PixelWorld(std::wstring WorldName, Application* Application);

		/**
		 * @brief 析构函数
		 */
		~PixelWorld();

		/**
		 * @brief 设置使用的分辨率大小
		 * @param[in] width 分辨率的宽度
		 * @param[in] height 分辨率的高度
		 */
		void SetResolution(int width, int height);

		/**
		 * @brief 设置我们使用的摄像机
		 * @param[in] camera 摄像机
		 */
		void SetCamera(Camera camera);

		/**
		 * @brief 设置我们使用的着色器
		 * @param[in] shader 着色器的指针，注意请保持它的生命周期
		 */
		void SetShader(Graphics::GraphicsShader* shader);

		/**
		 * @brief 设置我们使用的着色器为默认着色器，初始值就是默认着色器
		 */
		void SetShader();

		/**
		 * @brief 注册一个渲染物体，注册完成后文件数据就可以释放了
		 * @param[in] id 我们注册的渲染物体的ID
		 * @param[in] fileData 渲染物体的数据信息，注意数据必须是数据格式R8G8B8A8，然后图形的长宽必须一样
		 */
		void RegisterRenderObjectID(int id, Graphics::Texture2D* texture);

		/**
		 * @brief 释放我们注册过的渲染物体
		 * @param[in] id 我们要释放的渲染物体的ID
		 */
		void UnRegisterRenderObjectID(int id);

		/**
		 * @brief 获取在当前状况下的世界的图像
		 * @return 存储当前世界的图像的纹理的指针
		 */
		auto GetCurrentWorld() -> Graphics::Texture2D*;
	};
}
