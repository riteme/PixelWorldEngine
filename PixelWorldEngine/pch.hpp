#pragma once

#include <string>
#include <vector>
#include <map>
#include <fstream>

namespace PixelWorldEngine {

	typedef unsigned char byte;

}
#ifdef _WIN32

#include <Windows.h>
#include <windowsx.h>
#include <d3d11.h>
#include <d3dcompiler.h>

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib,"Imm32.lib")

#endif // _WIN32

#ifdef DEBUG
#endif
