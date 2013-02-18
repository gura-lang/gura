#include "stdafx.h"
#include <windows.h>

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD dwReason, LPVOID lpvReserved)
{
	Gura::OAL::SetModuleHandle(hInst);
	return TRUE;
}
