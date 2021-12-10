// dllmain.cpp : Implementation of DllMain.

#include "pch.h"
#include "resource.h"
#include "DllIconHandler_i.h"
#include "dllmain.h"

CDllIconHandlerModule _AtlModule;

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved) {
	hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved);
}
