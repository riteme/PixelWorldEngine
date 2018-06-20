#include "DataManager.hpp"

PixelWorldEngine::FileData::FileData(byte * Data)
{
	if (Data == nullptr) return;
	
	auto length = strlen((char*)Data);

	data.resize(length);

	for (size_t i = 0; i < length; i++)
		data[i] = Data[i];
}

auto PixelWorldEngine::FileData::GetSize() -> size_t
{
	return data.size();
}

auto PixelWorldEngine::FileData::GetData() -> byte *
{
	return &data[0];
}

auto PixelWorldEngine::FileData::GetVector() -> std::vector<byte>
{
	return std::vector<byte>(data);
}

auto PixelWorldEngine::DataManager::ReadFile(std::wstring fileName) -> FileData
{
	FileData result;

#ifdef _DEBUG
	std::ifstream file;

	file.open(fileName, std::ios::binary | std::ios::ate);

	size_t size = (size_t)file.tellg();

	result.data.resize(size);

	file.seekg(0, std::ios::beg);
	file.read((char*)&result.data[0], size);
	file.close();

	return result;
#else
	//对于release版本我们会考虑打包文件
#endif // _DEBUG

}
