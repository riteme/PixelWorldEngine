#ifndef _PCH_H_
#define _PCH_H_


#include <string>
#include <vector>

#ifdef WINDOWS

#include <Windows.h>
#include <windowsx.h>
#include <d3d11.h>

#endif // _WINDOWS_

#ifdef DEBUG

#include <iostream>

#endif

#endif // !_PCH_H_