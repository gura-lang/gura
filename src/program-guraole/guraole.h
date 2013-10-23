#ifndef __GURAOLE_H__
#define __GURAOLE_H__

#include <windows.h>
#include <stdio.h>
#include <objsafe.h>
#include <activscp.h>
#include <gura.h>

class CMain;
class CActiveScriptParse32;

//-----------------------------------------------------------------------------
// CActiveScriptParse32 declaration
//-----------------------------------------------------------------------------
class CActiveScriptParse32 : public IActiveScriptParse32 {
private:
	CMain *_pMain;
public:
	inline CActiveScriptParse32(CMain *pMain) : _pMain(pMain) {}
	// virtual functions of IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void **ppv);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();
	// virtual functions of IActiveScriptParse32
	virtual HRESULT STDMETHODCALLTYPE InitNew(void);
	virtual HRESULT STDMETHODCALLTYPE AddScriptlet(
		/* [in] */ LPCOLESTR pstrDefaultName,
		/* [in] */ LPCOLESTR pstrCode,
		/* [in] */ LPCOLESTR pstrItemName,
		/* [in] */ LPCOLESTR pstrSubItemName,
		/* [in] */ LPCOLESTR pstrEventName,
		/* [in] */ LPCOLESTR pstrDelimiter,
		/* [in] */ DWORD dwSourceContextCookie,
		/* [in] */ ULONG ulStartingLineNumber,
		/* [in] */ DWORD dwFlags,
		/* [out] */ BSTR *pbstrName,
		/* [out] */ EXCEPINFO *pexcepinfo);
	virtual HRESULT STDMETHODCALLTYPE ParseScriptText(
		/* [in] */ LPCOLESTR pstrCode,
		/* [in] */ LPCOLESTR pstrItemName,
		/* [in] */ IUnknown *punkContext,
		/* [in] */ LPCOLESTR pstrDelimiter,
		/* [in] */ DWORD dwSourceContextCookie,
		/* [in] */ ULONG ulStartingLineNumber,
		/* [in] */ DWORD dwFlags,
		/* [out] */ VARIANT *pvarResult,
		/* [out] */ EXCEPINFO *pexcepinfo);
};

//-----------------------------------------------------------------------------
// CObjectSafety declaration
//-----------------------------------------------------------------------------
class CObjectSafety : public IObjectSafety {
private:
	CMain *_pMain;
public:
	inline CObjectSafety(CMain *pMain) : _pMain(pMain) {}
	// virtual functions of IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void **ppv);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();
	// virtual functions of IObjectSafety
	virtual HRESULT STDMETHODCALLTYPE GetInterfaceSafetyOptions( 
		/* [in] */ REFIID riid,
		/* [out] */ DWORD *pdwSupportedOptions,
		/* [out] */ DWORD *pdwEnabledOptions);
	virtual HRESULT STDMETHODCALLTYPE SetInterfaceSafetyOptions( 
		/* [in] */ REFIID riid,
		/* [in] */ DWORD dwOptionSetMask,
		/* [in] */ DWORD dwEnabledOptions);
};

//-----------------------------------------------------------------------------
// CMain declaration
//-----------------------------------------------------------------------------
class CMain : public IActiveScript, public IActiveScriptError,
				public IActiveScriptGarbageCollector, public IDispatch {
private:
	LONG _cntRef;
	CActiveScriptParse32 _activeScriptParse32;
	CObjectSafety _objectSafety;
	IActiveScriptSite *_pActiveScriptSite;
	Gura::Signal _sig;
	Gura::AutoPtr<Gura::Environment> _pEnv;
	Gura::ValueList _valListDispatched;
public:
	static const CLSID ClsId;
public:
	CMain();
	// virtual functions of IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void **ppv);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();
	// virtual functions of IActiveScript
	virtual HRESULT STDMETHODCALLTYPE SetScriptSite( 
		/* [in] */ IActiveScriptSite *pScriptSite);
	virtual HRESULT STDMETHODCALLTYPE GetScriptSite( 
		/* [in] */ REFIID riid,
		/* [iid_is][out] */ void **ppvObject);
	virtual HRESULT STDMETHODCALLTYPE SetScriptState( 
		/* [in] */ SCRIPTSTATE ss);
	virtual HRESULT STDMETHODCALLTYPE GetScriptState( 
		/* [out] */ SCRIPTSTATE *pssState);
	virtual HRESULT STDMETHODCALLTYPE Close( void);
	virtual HRESULT STDMETHODCALLTYPE AddNamedItem( 
		/* [in] */ LPCOLESTR pstrName,
		/* [in] */ DWORD dwFlags);
	virtual HRESULT STDMETHODCALLTYPE AddTypeLib( 
		/* [in] */ REFGUID rguidTypeLib,
		/* [in] */ DWORD dwMajor,
		/* [in] */ DWORD dwMinor,
		/* [in] */ DWORD dwFlags);
	virtual HRESULT STDMETHODCALLTYPE GetScriptDispatch( 
		/* [in] */ LPCOLESTR pstrItemName,
		/* [out] */ IDispatch **ppdisp);
	virtual HRESULT STDMETHODCALLTYPE GetCurrentScriptThreadID( 
		/* [out] */ SCRIPTTHREADID *pstidThread);
	virtual HRESULT STDMETHODCALLTYPE GetScriptThreadID( 
		/* [in] */ DWORD dwWin32ThreadId,
		/* [out] */ SCRIPTTHREADID *pstidThread);
	virtual HRESULT STDMETHODCALLTYPE GetScriptThreadState( 
		/* [in] */ SCRIPTTHREADID stidThread,
		/* [out] */ SCRIPTTHREADSTATE *pstsState);
	virtual HRESULT STDMETHODCALLTYPE InterruptScriptThread( 
		/* [in] */ SCRIPTTHREADID stidThread,
		/* [in] */ const EXCEPINFO *pexcepinfo,
		/* [in] */ DWORD dwFlags);
	virtual HRESULT STDMETHODCALLTYPE Clone( 
		/* [out] */ IActiveScript **ppscript);
	// methods for IActiveScriptParse32
	HRESULT InitNew(void);
	HRESULT AddScriptlet(
		/* [in] */ LPCOLESTR pstrDefaultName,
		/* [in] */ LPCOLESTR pstrCode,
		/* [in] */ LPCOLESTR pstrItemName,
		/* [in] */ LPCOLESTR pstrSubItemName,
		/* [in] */ LPCOLESTR pstrEventName,
		/* [in] */ LPCOLESTR pstrDelimiter,
		/* [in] */ DWORD dwSourceContextCookie,
		/* [in] */ ULONG ulStartingLineNumber,
		/* [in] */ DWORD dwFlags,
		/* [out] */ BSTR *pbstrName,
		/* [out] */ EXCEPINFO *pexcepinfo);
	HRESULT ParseScriptText(
		/* [in] */ LPCOLESTR pstrCode,
		/* [in] */ LPCOLESTR pstrItemName,
		/* [in] */ IUnknown *punkContext,
		/* [in] */ LPCOLESTR pstrDelimiter,
		/* [in] */ DWORD dwSourceContextCookie,
		/* [in] */ ULONG ulStartingLineNumber,
		/* [in] */ DWORD dwFlags,
		/* [out] */ VARIANT *pvarResult,
		/* [out] */ EXCEPINFO *pexcepinfo);
	// virtual functions of IActiveScriptError
	virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetExceptionInfo( 
		/* [out] */ EXCEPINFO *pexcepinfo);
	virtual HRESULT STDMETHODCALLTYPE GetSourcePosition( 
		/* [out] */ DWORD *pdwSourceContext,
		/* [out] */ ULONG *pulLineNumber,
		/* [out] */ LONG *plCharacterPosition);
	virtual HRESULT STDMETHODCALLTYPE GetSourceLineText( 
		/* [out] */ BSTR *pbstrSourceLine);
	// virtual functions of IActiveScriptGarbageCollector
	virtual HRESULT STDMETHODCALLTYPE CollectGarbage( 
		SCRIPTGCTYPE scriptgctype);
	// virtual functions of IDispatch
	virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount( 
		/* [out] */ UINT *pctinfo);
	virtual HRESULT STDMETHODCALLTYPE GetTypeInfo( 
		/* [in] */ UINT iTInfo,
		/* [in] */ LCID lcid,
		/* [out] */ ITypeInfo **ppTInfo);
	virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames( 
		/* [in] */ REFIID riid,
		/* [size_is][in] */ LPOLESTR *rgszNames,
		/* [in] */ UINT cNames,
		/* [in] */ LCID lcid,
		/* [size_is][out] */ DISPID *rgDispId);
	virtual /* [local] */ HRESULT STDMETHODCALLTYPE Invoke( 
		/* [in] */ DISPID dispIdMember,
		/* [in] */ REFIID riid,
		/* [in] */ LCID lcid,
		/* [in] */ WORD wFlags,
		/* [out][in] */ DISPPARAMS *pDispParams,
		/* [out] */ VARIANT *pVarResult,
		/* [out] */ EXCEPINFO *pExcepInfo,
		/* [out] */ UINT *puArgErr);
	// other methods
	inline void NotifyScriptError() {
		if (_pActiveScriptSite != NULL) {
			::printf("check\n");
			_pActiveScriptSite->OnScriptError(this);
		}
	}
};

//-----------------------------------------------------------------------------
// CClassFactory declaration
//-----------------------------------------------------------------------------
class CClassFactory : public IClassFactory {
private:
	LONG _cntRef;
public:
	inline CClassFactory() : _cntRef(0) {}
	// virtual functions of IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void **ppv);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();
	// virtual functions of IClassFactory
	STDMETHODIMP LockServer(BOOL bLock);
	STDMETHODIMP CreateInstance(IUnknown *pUnknownOuter, REFIID riid, void **ppv);
};


#endif
