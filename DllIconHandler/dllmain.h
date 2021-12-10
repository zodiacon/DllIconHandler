// dllmain.h : Declaration of module class.

class CDllIconHandlerModule : public ATL::CAtlDllModuleT< CDllIconHandlerModule >
{
public :
	DECLARE_LIBID(LIBID_DllIconHandlerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DLLICONHANDLER, "{a1b4516d-9340-444b-87e2-13317a44eeb1}")
};

extern class CDllIconHandlerModule _AtlModule;
