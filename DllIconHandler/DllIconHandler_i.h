

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 05:14:07 2038
 */
/* Compiler settings for DllIconHandler.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0626 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __DllIconHandler_i_h__
#define __DllIconHandler_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if _CONTROL_FLOW_GUARD_XFG
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IIconHandler_FWD_DEFINED__
#define __IIconHandler_FWD_DEFINED__
typedef interface IIconHandler IIconHandler;

#endif 	/* __IIconHandler_FWD_DEFINED__ */


#ifndef __IconHandler_FWD_DEFINED__
#define __IconHandler_FWD_DEFINED__

#ifdef __cplusplus
typedef class IconHandler IconHandler;
#else
typedef struct IconHandler IconHandler;
#endif /* __cplusplus */

#endif 	/* __IconHandler_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IIconHandler_INTERFACE_DEFINED__
#define __IIconHandler_INTERFACE_DEFINED__

/* interface IIconHandler */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IIconHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2d6a2331-a2a2-4e6f-acb6-01143af75404")
    IIconHandler : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IIconHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIconHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIconHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIconHandler * This);
        
        END_INTERFACE
    } IIconHandlerVtbl;

    interface IIconHandler
    {
        CONST_VTBL struct IIconHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIconHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIconHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIconHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIconHandler_INTERFACE_DEFINED__ */



#ifndef __DllIconHandlerLib_LIBRARY_DEFINED__
#define __DllIconHandlerLib_LIBRARY_DEFINED__

/* library DllIconHandlerLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_DllIconHandlerLib;

EXTERN_C const CLSID CLSID_IconHandler;

#ifdef __cplusplus

class DECLSPEC_UUID("d913f592-08f1-418a-9428-cc33db97ed60")
IconHandler;
#endif
#endif /* __DllIconHandlerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


