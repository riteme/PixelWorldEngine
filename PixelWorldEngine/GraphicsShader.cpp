#include "GraphicsShader.hpp"

#include "Application.hpp"
#include "Graphics.hpp"


PixelWorldEngine::Graphics::GraphicsShader::GraphicsShader(Graphics* Graphics, std::vector<byte> ShaderCode,
	const char * VertexShaderFunction, const char * PixelShaderFunction)
{
	//没有编译过的着色器

	graphics = Graphics;
	
#ifdef _WIN32

	ID3DBlob* result;
	ID3DBlob* error;

#ifdef _DEBUG
	UINT flag = D3DCOMPILE_DEBUG;
#else
	UINT flag = D3DCOMPILE_OPTIMIZATION_LEVEL2;
#endif // DEBUG

	D3DCompile(&ShaderCode[0], ShaderCode.size(), nullptr, nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE, VertexShaderFunction, "vs_5_0", flag, 0,
		&result, &error);

	//DebugLayer::Assert(true, Error::ShaderCompiledFailed, error->GetBufferPointer());

	graphics->device->CreateVertexShader(result->GetBufferPointer(), result->GetBufferSize(),
		nullptr, &vertexShader);

	for (size_t i = 0; i < result->GetBufferSize(); i++) 
		compiledVertexShaderCode.push_back(((byte*)result->GetBufferPointer())[i]);
	
	Utility::Dispose(result);
	Utility::Dispose(error);

	D3DCompile(&ShaderCode[0], ShaderCode.size(), nullptr, nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE, PixelShaderFunction, "ps_5_0", flag, 0,
		&result, &error);

	graphics->device->CreatePixelShader(result->GetBufferPointer(), result->GetBufferSize(),
		nullptr, &pixelShader);

	for (size_t i = 0; i < result->GetBufferSize(); i++)
		compiledPixelShaderCode.push_back(((byte*)result->GetBufferPointer())[i]);

	Utility::Dispose(result);
	Utility::Dispose(error);

#endif // _WIN32
}

PixelWorldEngine::Graphics::GraphicsShader::GraphicsShader(Graphics* Graphics, std::vector<byte> VertexShaderCode, std::vector<byte> PixelShaderCode)
{
	//已经编译过的着色器

	graphics = Graphics;

#ifdef _WIN32

	graphics->device->CreateVertexShader(&VertexShaderCode[0], VertexShaderCode.size(),
		nullptr, &vertexShader);

	graphics->device->CreatePixelShader(&PixelShaderCode[0], PixelShaderCode.size(),
		nullptr, &pixelShader);

#endif // _WIN32

	compiledVertexShaderCode = std::vector<byte>(VertexShaderCode);
	compiledPixelShaderCode = std::vector<byte>(PixelShaderCode);

}

auto PixelWorldEngine::Graphics::GraphicsShader::GetVertexShaderCode() -> std::vector<byte>
{
	return std::vector<byte>(compiledVertexShaderCode);
}

auto PixelWorldEngine::Graphics::GraphicsShader::GetPixelShaderCode() -> std::vector<byte>
{
	return std::vector<byte>(compiledPixelShaderCode);
}

PixelWorldEngine::Graphics::GraphicsShader::~GraphicsShader()
{
#ifdef _WIN32
	Utility::Dispose(vertexShader);
	Utility::Dispose(pixelShader);
#endif // _WIN32

}
