#pragma once

#include "pch.hpp"

#include "DataManager.hpp"
#include "Graphics.hpp"

#include "Geometry.hpp"
#include "Utility.hpp"
#include "Camera.hpp"

namespace PixelWorldEngine {

	/**
	 * @brief ����ĺ�������
	 */
	class PixelWorld {
	private:
		std::wstring worldName; //��������� 

		int resolutionWidth; //�ֱ��ʿ���
		int resolutionHeight; //�ֱ��ʸ߶�

		Camera camera; //�����

		Graphics::Graphics* graphics; //...

		Graphics::Texture2D* renderBuffer; //�洢���类��Ⱦ���������Ϣ
		Graphics::RenderTarget* renderTarget; //..

		Graphics::Rectangle* rectangle;

		std::map<int, Graphics::Texture2D> renderObjectIDGroup; //���ڴ洢��������ͬ��ID��Ӧ��ͬ������
	public:
		/**
		 * @brief ���캯��
		 * @param[in] WorldName ���������
		 * @param[in] Application ���������Ӧ�ó���
		 */
		PixelWorld(std::wstring WorldName, Application* Application);

		/**
		 * @brief ��������
		 */
		~PixelWorld();

		/**
		 * @brief ����ʹ�õķֱ��ʴ�С
		 * @param[in] width �ֱ��ʵĿ���
		 * @param[in] height �ֱ��ʵĸ߶�
		 */
		void SetResolution(int width, int height);

		/**
		 * @brief ��������ʹ�õ������
		 * @param[in] camera �����
		 */
		void SetCamera(Camera camera);

		/**
		 * @brief ע��һ����Ⱦ���壬ע����ɺ��ļ����ݾͿ����ͷ���
		 * @param[in] id ����ע�����Ⱦ�����ID
		 * @param[in] fileData ��Ⱦ�����������Ϣ
		 */
		void RegisterRenderObjectID(int id, byte* fileData);

		/**
		 * @brief �ͷ�����ע�������Ⱦ����
		 * @param[in] id ����Ҫ�ͷŵ���Ⱦ�����ID
		 */
		void UnRegisterRenderObjectID(int id);

		/**
		 * @brief ��ȡ�ڵ�ǰ״���µ������ͼ��
		 * @return �洢��ǰ�����ͼ���������ָ��
		 */
		auto GetCurrentWorld() -> Graphics::Texture2D*;
	};
}