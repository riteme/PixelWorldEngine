#pragma once

#include <string>
#include <vector>
#include <map>

namespace PixelWorldEngine {

	typedef unsigned char byte;

}
#ifdef WINDOWS

#include <Windows.h>
#include <windowsx.h>
#include <d3d11.h>
#include <d3dcompiler.h>

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib,"Imm32.lib")

#endif // _WINDOWS_

#ifdef DEBUG
#endif
