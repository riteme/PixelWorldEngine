#pragma once

#include "pch.hpp"

namespace PixelWorldEngine {

	/**
	 * @brief 文件数据类型，用于存储文件数据
	 */
	class FileData {
	private:
		byte* data; //指向数据内存的指针，数据按照字节存储
	public:
		/**
		 * @brief 构造函数
		 * @param[in] Data 文件数据
		 */
		FileData(byte* Data);

		/**
		 * @brief 释放存储数据的内存
		*/
		void Dipose();

		/**
		 * @brief 获取数据
		 * @return 数据所在内存的头指针
		 */
		auto GetData() -> byte*;
	};

	/**
	 * @brief 文件数据管理类型，用于读取输出以及加密数据
	 */
	class DataManager {
	private:
	public:
		/**
		 * @brief 读取文件
		 * @param[in] fileName 文件名
		 * @return 返回文件数据
		 */
		auto ReadFile(std::wstring fileName) -> FileData;

		/**
		 * @brief 写入文件
		 * @param[in] fileName 文件名
		 * @param[in] fileData 要写入的数据
		 */
		void WriteFile(std::wstring fileName, FileData fileData);
	};

}
