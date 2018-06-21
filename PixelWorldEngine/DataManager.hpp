#pragma once

#include "pch.hpp"

#include "Graphics.hpp"

namespace PixelWorldEngine {

	class Application;

	/**
	 * @brief �ļ��������ͣ����ڴ洢�ļ�����
	 */
	class FileData {
	private:
		std::vector<byte> data; //����
		
		friend class DataManager;
	public:
		/**
		 * @brief ���캯��
		 * @param[in] Data �ļ�����
		 */
		FileData(byte* Data = nullptr);

		/**
		 * @brief ��ȡ���ݴ�С�����ֽ�
		 * @return ���ݴ�С
		 */
		auto GetSize() -> size_t;

		/**
		 * @brief ��ȡ����
		 * @return ���������ڴ��ͷָ��
		 */
		auto GetData() -> byte*;

		/**
		 * @brief ��ȡ����
		 * @return ������ݵĶ�̬����
		 */
		auto GetVector() -> std::vector<byte>;
	};

	/**
	 * @brief �ļ����ݹ������ͣ����ڶ�ȡ����Լ���������
	 */
	class DataManager {
	private:
		Graphics::Graphics* graphics;

		std::map<std::wstring, Graphics::Texture2D*> textures;
	public:
		/**
		 * @breif ���캯��
		 * @param[in] application
		 */
		DataManager(Application* application);

		/**
		 * @brief ��������
		 */
		~DataManager();
		
		/**
		 * @brief ��ȡ�ļ�
		 * @param[in] fileName �ļ���
		 * @return �����ļ�����
		 */
		auto ReadFile(std::wstring fileName) -> FileData;

		/**
		 * @brief ��ȡ������Դ������ע�ᣬ����ļ��Ѿ���ȡ��ô�����ظ���ȡ����ֱ�ӷ�������
		 * @param[in] fileName �����ļ�·����Ŀǰֻ֧��bmp, jpeg, png 
		 * @return �����ļ�
		 */
		auto RegisterTexture(std::wstring fileName) -> Graphics::Texture2D*;

		/**
		 * @brief �ͷ�����ע���������Դ�����һ��������Ҫʹ�õĻ������ͷ��Խ�Լ�ڴ�
		 * @param[in] �ļ���
		 */
		auto UnRegisterTexture(std::wstring fileName);

		/**
		 * @brief д���ļ�
		 * @param[in] fileName �ļ���
		 * @param[in] fileData Ҫд�������
		 */
		void WriteFile(std::wstring fileName, FileData fileData);
	};

}
