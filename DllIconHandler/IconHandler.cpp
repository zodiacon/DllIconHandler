// IconHandler.cpp : Implementation of CIconHandler

#include "pch.h"
#include "IconHandler.h"
#include <DbgHelp.h>

#pragma comment(lib, "dbghelp")

// CIconHandler

CIconHandler::ModuleBitness CIconHandler::GetModuleBitness(PCWSTR path) {
    auto bitness = ModuleBitness::Unknown;
    //
    // open the DLL as a data file
    //
    auto hFile = ::CreateFile(path, GENERIC_READ, FILE_SHARE_READ, 
        nullptr, OPEN_EXISTING, 0, nullptr);
    if (hFile == INVALID_HANDLE_VALUE)
        return bitness;

    //
    // create a memory mapped file to read the PE header
    //
    auto hMemMap = ::CreateFileMapping(hFile, nullptr, PAGE_READONLY, 0, 0, nullptr);
    ::CloseHandle(hFile);
    if (!hMemMap)
        return bitness;

    //
    // map the first page (where the header is located)
    //
    auto p = ::MapViewOfFile(hMemMap, FILE_MAP_READ, 0, 0, 1 << 12);
    if (p) {
        auto header = ::ImageNtHeader(p);
        if (header) {
            bitness = header->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC ? ModuleBitness::Bit64 : ModuleBitness::Bit32;
        }
        ::UnmapViewOfFile(p);
    }
    ::CloseHandle(hMemMap);
    
    return bitness;
}

HRESULT __stdcall CIconHandler::GetIconLocation(UINT uFlags, PWSTR pszIconFile, UINT cchMax, int* piIndex, UINT* pwFlags) {
    if (s_ModulePath[0] == 0) {
        ::GetModuleFileName(_pModule->GetModuleInstance(), 
            s_ModulePath, _countof(s_ModulePath));
        ATLTRACE(L"Module path: %s\n", s_ModulePath);
    }
    if (s_ModulePath[0] == 0)
        return S_FALSE;

    if (m_Bitness == ModuleBitness::Unknown)
        return S_FALSE;

    wcscpy_s(pszIconFile, std::min((UINT)wcslen(s_ModulePath) + 1, cchMax), s_ModulePath);
    ATLTRACE(L"CIconHandler::GetIconLocation: %s bitness: %d\n", 
        pszIconFile, m_Bitness);
    *piIndex = m_Bitness == ModuleBitness::Bit32 ? 0 : 1;
    *pwFlags = GIL_PERINSTANCE;

    return S_OK;
}

HRESULT __stdcall CIconHandler::Extract(PCWSTR pszFile, UINT nIconIndex, HICON* phiconLarge, HICON* phiconSmall, UINT nIconSize) {
    return S_FALSE;
}

HRESULT __stdcall CIconHandler::GetClassID(CLSID* pClassID) {
    return E_NOTIMPL;
}

HRESULT __stdcall CIconHandler::IsDirty(void) {
    return E_NOTIMPL;
}

HRESULT __stdcall CIconHandler::Load(LPCOLESTR pszFileName, DWORD dwMode) {
    ATLTRACE(L"CIconHandler::Load %s\n", pszFileName);

    m_Bitness = GetModuleBitness(pszFileName);

    return S_OK;
}

HRESULT __stdcall CIconHandler::Save(LPCOLESTR pszFileName, BOOL fRemember) {
    return E_NOTIMPL;
}

HRESULT __stdcall CIconHandler::SaveCompleted(LPCOLESTR pszFileName) {
    return E_NOTIMPL;
}

HRESULT __stdcall CIconHandler::GetCurFile(LPOLESTR* ppszFileName) {
    return E_NOTIMPL;
}
