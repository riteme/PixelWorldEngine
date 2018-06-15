#include "GraphicsShader.hpp"
#include "Application.hpp"

PixelWorldEngine::Graphics::GraphicsShader::GraphicsShader(std::vector<byte> ShaderCode,
	const char * VertexShaderFunction, const char * PixelShaderFunction)
{
	graphics = Application::GetGraphicsInstance();
	
#if WINDOWS

	ID3DBlob* result;
	ID3DBlob* error;

#if DEBUG
	UINT flag = D3DCOMPILE_DEBUG;
#else
	UINT flag = D3DCOMPILE_OPTIMIZATION_LEVEL2;
#endif // DEBUG

	D3DCompile(&ShaderCode[0], ShaderCode.size(), nullptr, nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE, VertexShaderFunction, "vs_5_0", flag, 0,
		&result, &error);

	graphics->device->CreateVertexShader(result->GetBufferPointer(), result->GetBufferSize(),
		nullptr, &vertexShader);
	
	Utility::Dipose(result);
	Utility::Dipose(error);

	D3DCompile(&ShaderCode[0], ShaderCode.size(), nullptr, nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE, PixelShaderFunction, "ps_5_0", flag, 0,
		&result, &error);

	graphics->device->CreatePixelShader(result->GetBufferPointer(), result->GetBufferSize(),
		nullptr, &pixelShader);

	Utility::Dipose(result);
	Utility::Dipose(error);

#endif // WINDOWS
}

PixelWorldEngine::Graphics::GraphicsShader::GraphicsShader(std::vector<byte> VertexShaderCode, std::vector<byte> PixelShaderCode)
{
	graphics = Application::GetGraphicsInstance();

#if WINDOWS

	graphics->device->CreateVertexShader(&VertexShaderCode[0], VertexShaderCode.size(),
		nullptr, &vertexShader);

	graphics->device->CreatePixelShader(&PixelShaderCode[0], PixelShaderCode.size(),
		nullptr, &pixelShader);

#endif // WINDOWS

}

PixelWorldEngine::Graphics::GraphicsShader::~GraphicsShader()
{
#if WINDOWS
	Utility::Dipose(vertexShader);
	Utility::Dipose(pixelShader);
#endif // WINDOWS

}
