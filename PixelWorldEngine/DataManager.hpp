#pragma once

#include "pch.hpp"

namespace PixelWorldEngine {

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
	public:
		/**
		 * @brief ��ȡ�ļ�
		 * @param[in] fileName �ļ���
		 * @return �����ļ�����
		 */
		auto ReadFile(std::wstring fileName) -> FileData;

		/**
		 * @brief д���ļ�
		 * @param[in] fileName �ļ���
		 * @param[in] fileData Ҫд�������
		 */
		void WriteFile(std::wstring fileName, FileData fileData);
	};

}
