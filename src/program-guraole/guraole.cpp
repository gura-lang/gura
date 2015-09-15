//=============================================================================
// Gura Programming Language
// Copyright (C) 2011-2014 ypsitau
//=============================================================================
#include "stdafx.h"

#define DBGPRINTF(x) printf##x

const CLSID CMain::ClsId = {
    0xf40b1ab6, 0x57e5, 0x4df7, 0x92, 0x8e, 0x9b, 0xfb, 0x53, 0x91, 0x76, 0x11
};

static HMODULE g_hModule;

CClassFactory g_classFactory;

inline Gura::String IIDString(REFIID riid)
{
	char buff[128];
	::sprintf(buff, "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
		riid.Data1, riid.Data2, riid.Data3, riid.Data4[0], riid.Data4[1],
		riid.Data4[2], riid.Data4[3], riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7]);
	return Gura::String(buff);
}

//-----------------------------------------------------------------------------
// CMain implementation
//-----------------------------------------------------------------------------
CMain::CMain() : _cntRef(0), _activeScriptParse32(this),
		 _objectSafety(this), _pActiveScriptSite(nullptr), _pEnv(new Gura::Environment(_sig))
{
	int argc = 0;
	const char **argv = nullptr;
	_pEnv->InitializeAsRoot(argc, argv, nullptr, 0);
}

STDMETHODIMP CMain::QueryInterface(REFIID riid, void **ppv)
{
	//DBGPRINTF(("IUnknown::QueryInterface(%s)\n", IIDString(riid).c_str()));
	if (riid == IID_IUnknown) {
		//DBGPRINTF(("IUnknown\n"));
		*ppv = this;
		AddRef();
		return S_OK;
	} else if (riid == IID_IActiveScript) {
		//DBGPRINTF(("IActiveScript\n"));
		*ppv = this;
		AddRef();
		return S_OK;
	} else if (riid == IID_IActiveScriptGarbageCollector) {
		//DBGPRINTF(("IActiveScriptGarbageCollector\n"));
		*ppv = this;
		AddRef();
		return S_OK;
	} else if (riid == IID_IActiveScriptParse32) {
		//DBGPRINTF(("IActiveScriptParse32\n"));
		*ppv = &_activeScriptParse32;
		_activeScriptParse32.AddRef();
		return S_OK;
	} else if (riid == IID_IActiveScriptParse64) {
		//DBGPRINTF(("IActiveScriptParse64\n"));
	} else if (riid == IID_IObjectSafety) {
		//DBGPRINTF(("IObjectSafety\n"));
		*ppv = &_objectSafety;
		_objectSafety.AddRef();
		return S_OK;
	}
	*ppv = nullptr;
	return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CMain::AddRef()
{
	return InterlockedIncrement(&_cntRef);
}

STDMETHODIMP_(ULONG) CMain::Release()
{
	ULONG ul = InterlockedDecrement(&_cntRef);
	if (ul == 0) delete this;
	return ul;
}

// virtual functions of IActiveScript
HRESULT STDMETHODCALLTYPE CMain::SetScriptSite( 
	/* [in] */ IActiveScriptSite *pScriptSite)
{
	DBGPRINTF(("IActiveScript::SetScriptSite(0x%p)\n", pScriptSite));
	if (reinterpret_cast<size_t>(pScriptSite) < 0x100) return E_FAIL;
	pScriptSite->AddRef();
	_pActiveScriptSite = pScriptSite;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CMain::GetScriptSite( 
	/* [in] */ REFIID riid,
	/* [iid_is][out] */ void **ppvObject)
{
	DBGPRINTF(("IActiveScript::GetScriptSite()\n"));
	if (_pActiveScriptSite == nullptr) return S_FALSE;
	return _pActiveScriptSite->QueryInterface(riid, ppvObject);
}

HRESULT STDMETHODCALLTYPE CMain::SetScriptState( 
	/* [in] */ SCRIPTSTATE ss)
{
	DBGPRINTF(("IActiveScript::SetScriptState(%s)\n",
		(ss == SCRIPTSTATE_UNINITIALIZED)? "uninitialized" :
		(ss == SCRIPTSTATE_INITIALIZED)? "initialized" :
		(ss == SCRIPTSTATE_STARTED)? "started" :
		(ss == SCRIPTSTATE_CONNECTED)? "connected" :
		(ss == SCRIPTSTATE_DISCONNECTED)? "disconnected" :
		(ss == SCRIPTSTATE_CLOSED)? "closed" : "(unknown)"));
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CMain::GetScriptState( 
	/* [out] */ SCRIPTSTATE *pssState)
{
	DBGPRINTF(("IActiveScript::GetScriptState()\n"));
	*pssState = SCRIPTSTATE_STARTED;
	//SCRIPTSTATE_UNINITIALIZED;
	//SCRIPTSTATE_INITIALIZED;
	//SCRIPTSTATE_STARTED;
	//SCRIPTSTATE_CONNECTED;
	//SCRIPTSTATE_DISCONNECTED;
	//SCRIPTSTATE_CLOSED;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CMain::Close( void)
{
	DBGPRINTF(("IActiveScript::Close()\n"));
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CMain::AddNamedItem( 
	/* [in] */ LPCOLESTR pstrName,
	/* [in] */ DWORD dwFlags)
{
	DBGPRINTF(("IActiveScript::AddNamedItem()\n"));
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CMain::AddTypeLib( 
	/* [in] */ REFGUID rguidTypeLib,
	/* [in] */ DWORD dwMajor,
	/* [in] */ DWORD dwMinor,
	/* [in] */ DWORD dwFlags)
{
	DBGPRINTF(("IActiveScript::AddTypeLib()\n"));
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CMain::GetScriptDispatch( 
	/* [in] */ LPCOLESTR pstrItemName,
	/* [out] */ IDispatch **ppdisp)
{
	DBGPRINTF(("IActiveScript::GetScriptDispatch(%S)\n", pstrItemName));
	AddRef();
	*ppdisp = this;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CMain::GetCurrentScriptThreadID( 
	/* [out] */ SCRIPTTHREADID *pstidThread)
{
	DBGPRINTF(("IActiveScript::GetCurrentScriptThreadID()\n"));
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CMain::GetScriptThreadID( 
	/* [in] */ DWORD dwWin32ThreadId,
	/* [out] */ SCRIPTTHREADID *pstidThread)
{
	DBGPRINTF(("IActiveScript::GetScriptThreadID()\n"));
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CMain::GetScriptThreadState( 
	/* [in] */ SCRIPTTHREADID stidThread,
	/* [out] */ SCRIPTTHREADSTATE *pstsState)
{
	DBGPRINTF(("IActiveScript::GetScriptThreadState()\n"));
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CMain::InterruptScriptThread( 
	/* [in] */ SCRIPTTHREADID stidThread,
	/* [in] */ const EXCEPINFO *pexcepinfo,
	/* [in] */ DWORD dwFlags)
{
	DBGPRINTF(("IActiveScript::InterruptScriptThread()\n"));
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CMain::Clone( 
	/* [out] */ IActiveScript **ppscript)
{
	DBGPRINTF(("IActiveScript::Clone()\n"));
	return E_NOTIMPL;
}

HRESULT CMain::InitNew(void)
{
	DBGPRINTF(("CActiveScriptParse32::InitNew()\n"));
	return S_OK;
}

HRESULT CMain::AddScriptlet(
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
	/* [out] */ EXCEPINFO *pexcepinfo)
{
	DBGPRINTF(("CActiveScriptParse32::AddScriptlet()\n"));
	return E_NOTIMPL;
}

HRESULT CMain::ParseScriptText(
	/* [in] */ LPCOLESTR pstrCode,
	/* [in] */ LPCOLESTR pstrItemName,
	/* [in] */ IUnknown *punkContext,
	/* [in] */ LPCOLESTR pstrDelimiter,
	/* [in] */ DWORD dwSourceContextCookie,
	/* [in] */ ULONG ulStartingLineNumber,
	/* [in] */ DWORD dwFlags,
	/* [out] */ VARIANT *pvarResult,
	/* [out] */ EXCEPINFO *pexcepinfo)
{
	DBGPRINTF(("CActiveScriptParse32::ParseScriptText(0x%p)\n", punkContext));
	DBGPRINTF(("pstrCode              %S\n", pstrCode));
	DBGPRINTF(("pstrItemName          %S\n", pstrItemName));
	DBGPRINTF(("pstrDelimiter         %S\n", pstrDelimiter));
	DBGPRINTF(("dwSourceContextCookie %08x\n", dwSourceContextCookie));
	DBGPRINTF(("ulStartingLineNumber  %d\n", ulStartingLineNumber));
	DBGPRINTF(("dwFlags               %08x\n", dwFlags));
	Gura::Gura_Module(mswin)::Import(*_pEnv);
	Gura::Stream *pConsole = _pEnv->GetConsole();
	Gura::AutoPtr<Gura::Expr_Root> pExprRoot(new Gura::Expr_Root());
	Gura::ExprOwner &exprOwner = pExprRoot->GetExprOwner();
	int cntLineOffset = static_cast<int>(ulStartingLineNumber) - 1;
	if (cntLineOffset < 0) cntLineOffset = 0;
	Gura::Parser parser("<ole>", cntLineOffset);
	if (!parser.ParseString(*_pEnv, exprOwner,
			Gura::Gura_Module(mswin)::BSTRToString(pstrCode).c_str(), true)) {
		pexcepinfo->bstrDescription = L"*************";
		pexcepinfo->bstrHelpFile = L"";
		pexcepinfo->bstrSource = L"Gura";
		pexcepinfo->dwHelpContext = 0;
		pexcepinfo->pfnDeferredFillIn = nullptr;
		pexcepinfo->pvReserved = nullptr;
		pexcepinfo->wCode = ERROR_INVALID_FUNCTION;
		pexcepinfo->wReserved = 0;
		_sig.PrintSignal(*pConsole);
		NotifyScriptError();
		return DISP_E_EXCEPTION;
	}
	if (exprOwner.empty()) {
		pConsole->Println(_sig, "incomplete command");
	} else {
		Gura::Value result = pExprRoot->Exec(*_pEnv);
		if (_sig.IsSignalled()) {
			_sig.PrintSignal(*pConsole);
			NotifyScriptError();
			return DISP_E_EXCEPTION;
		}
		if (result.IsValid() && pvarResult != nullptr) {
			Gura::Gura_Module(mswin)::ValueToVariant(_sig, *pvarResult, result);
		}
	}
	return S_OK;
}

// virtual functions of IActiveScriptError
HRESULT STDMETHODCALLTYPE CMain::GetExceptionInfo( 
	/* [out] */ EXCEPINFO *pexcepinfo)
{
	DBGPRINTF(("IActiveScriptError::GetExceptionInfo()\n"));
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CMain::GetSourcePosition( 
	/* [out] */ DWORD *pdwSourceContext,
	/* [out] */ ULONG *pulLineNumber,
	/* [out] */ LONG *plCharacterPosition)
{
	DBGPRINTF(("IActiveScriptError::GetSourcePosition()\n"));
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CMain::GetSourceLineText( 
	/* [out] */ BSTR *pbstrSourceLine)
{
	DBGPRINTF(("IActiveScriptError::GetSourceLineText()\n"));
	return E_NOTIMPL;
}

// virtual functions of IActiveScriptGarbageCollector
HRESULT STDMETHODCALLTYPE CMain::CollectGarbage(
	SCRIPTGCTYPE scriptgctype)
{
	DBGPRINTF(("IActiveScriptGarbageCollector::CollectGarbage()\n"));
	return S_OK;
}

// virtual functions of IDispatch
HRESULT STDMETHODCALLTYPE CMain::GetTypeInfoCount( 
	/* [out] */ UINT *pctinfo)
{
	DBGPRINTF(("IDispatch::GetTypeInfoCount()\n"));
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CMain::GetTypeInfo( 
	/* [in] */ UINT iTInfo,
	/* [in] */ LCID lcid,
	/* [out] */ ITypeInfo **ppTInfo)
{
	DBGPRINTF(("IDispatch::GetTypeInfo()\n"));
	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CMain::GetIDsOfNames( 
	/* [in] */ REFIID riid,
	/* [size_is][in] */ LPOLESTR *rgszNames,
	/* [in] */ UINT cNames,
	/* [in] */ LCID lcid,
	/* [size_is][out] */ DISPID *rgDispId)
{
	DBGPRINTF(("IDispatch::GetIDsOfNames(%S)\n", *rgszNames));
	for (UINT iName = 0; iName < cNames; iName++) {
		const Gura::Symbol *pSymbol =
			Gura::Symbol::Add(Gura::Gura_Module(mswin)::BSTRToString(rgszNames[iName]).c_str());
		const Gura::Value *pValue = _pEnv->LookupValue(pSymbol, Gura::ENVREF_NoEscalate);
		if (pValue == nullptr) {
			return E_INVALIDARG;
		} else {
			rgDispId[iName] = static_cast<DISPID>(_valListDispatched.size());
			_valListDispatched.push_back(*pValue);
		}
	}
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CMain::Invoke( 
	/* [in] */ DISPID dispIdMember,
	/* [in] */ REFIID riid,
	/* [in] */ LCID lcid,
	/* [in] */ WORD wFlags,
	/* [out][in] */ DISPPARAMS *pDispParams,
	/* [out] */ VARIANT *pVarResult,
	/* [out] */ EXCEPINFO *pExcepInfo,
	/* [out] */ UINT *puArgErr)
{
	DBGPRINTF(("IDispatch::Invoke(%d)\n", dispIdMember));
	size_t idx = static_cast<size_t>(dispIdMember);
	if (idx >= _valListDispatched.size()) {
		return E_HANDLE;
	}
	Gura::Stream *pConsole = _pEnv->GetConsole();
	Gura::Value value = _valListDispatched[idx];
	Gura::ValueList valListArg;
	for (UINT iArg = 0; iArg < pDispParams->cArgs; iArg++) {
		Gura::Value value;
		if (!Gura::Gura_Module(mswin)::VariantToValue(*_pEnv, _sig,
										value, pDispParams->rgvarg[iArg])) {
			pExcepInfo->bstrDescription = L"*************";
			pExcepInfo->bstrHelpFile = L"";
			pExcepInfo->bstrSource = L"Gura";
			pExcepInfo->dwHelpContext = 0;
			pExcepInfo->pfnDeferredFillIn = nullptr;
			pExcepInfo->pvReserved = nullptr;
			pExcepInfo->wCode = ERROR_INVALID_DATA;
			pExcepInfo->wReserved = 0;
			_sig.PrintSignal(*pConsole);
			return DISP_E_EXCEPTION;
		}
		valListArg.push_back(value);
	}
	for (UINT iArg = 0; iArg < pDispParams->cNamedArgs; iArg++) {
		DISPID dispId = pDispParams->rgdispidNamedArgs[iArg];
	}
	if (wFlags == DISPATCH_METHOD) {
		if (!value.Is_function()) return E_INVALIDARG;
		Gura::Object_function *pObjFunc = Gura::Object_function::GetObject(value);
		Gura::Value result = pObjFunc->Eval(*_pEnv, valListArg);
		if (_sig.IsSignalled()) {
			pExcepInfo->bstrDescription = L"*************";
			pExcepInfo->bstrHelpFile = L"";
			pExcepInfo->bstrSource = L"Gura";
			pExcepInfo->dwHelpContext = 0;
			pExcepInfo->pfnDeferredFillIn = nullptr;
			pExcepInfo->pvReserved = nullptr;
			pExcepInfo->wCode = ERROR_INVALID_FUNCTION;
			pExcepInfo->wReserved = 0;
			_sig.PrintSignal(*pConsole);
			return DISP_E_EXCEPTION;
		}
		if (pVarResult != nullptr) {
			Gura::Gura_Module(mswin)::ValueToVariant(_sig, *pVarResult, result);
		}
	} else if (wFlags == DISPATCH_PROPERTYGET) {
		if (pVarResult != nullptr) {
			Gura::Gura_Module(mswin)::ValueToVariant(_sig, *pVarResult, value);
		}
	} else if (wFlags == DISPATCH_PROPERTYPUT) {
		return E_INVALIDARG;
	} else if (wFlags == DISPATCH_PROPERTYPUTREF) {
		return E_INVALIDARG;
	} else {
		return E_INVALIDARG;
	}
	return S_OK;
}

//-----------------------------------------------------------------------------
// CActiveScriptParse32 implementation
//-----------------------------------------------------------------------------
STDMETHODIMP CActiveScriptParse32::QueryInterface(REFIID riid, void **ppv)
{
	return _pMain->QueryInterface(riid, ppv);
}

STDMETHODIMP_(ULONG) CActiveScriptParse32::AddRef()
{
	return _pMain->AddRef();
}

STDMETHODIMP_(ULONG) CActiveScriptParse32::Release()
{
	return _pMain->Release();
}

HRESULT STDMETHODCALLTYPE CActiveScriptParse32::InitNew(void)
{
	return _pMain->InitNew();
}

HRESULT STDMETHODCALLTYPE CActiveScriptParse32::AddScriptlet( 
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
	/* [out] */ EXCEPINFO *pexcepinfo)
{
	return _pMain->AddScriptlet(pstrDefaultName, pstrCode, pstrItemName,
		pstrSubItemName, pstrEventName, pstrDelimiter, dwSourceContextCookie,
		ulStartingLineNumber, dwFlags, pbstrName, pexcepinfo);
}

HRESULT STDMETHODCALLTYPE CActiveScriptParse32::ParseScriptText( 
	/* [in] */ LPCOLESTR pstrCode,
	/* [in] */ LPCOLESTR pstrItemName,
	/* [in] */ IUnknown *punkContext,
	/* [in] */ LPCOLESTR pstrDelimiter,
	/* [in] */ DWORD dwSourceContextCookie,
	/* [in] */ ULONG ulStartingLineNumber,
	/* [in] */ DWORD dwFlags,
	/* [out] */ VARIANT *pvarResult,
	/* [out] */ EXCEPINFO *pexcepinfo)
{
	return _pMain->ParseScriptText(pstrCode, pstrItemName, punkContext, pstrDelimiter,
		dwSourceContextCookie, ulStartingLineNumber, dwFlags, pvarResult, pexcepinfo);
}

//-----------------------------------------------------------------------------
// CObjectSafety implementation
//-----------------------------------------------------------------------------
STDMETHODIMP CObjectSafety::QueryInterface(REFIID riid, void **ppv)
{
	return _pMain->QueryInterface(riid, ppv);
}

STDMETHODIMP_(ULONG) CObjectSafety::AddRef()
{
	return _pMain->AddRef();
}

STDMETHODIMP_(ULONG) CObjectSafety::Release()
{
	return _pMain->Release();
}

HRESULT STDMETHODCALLTYPE CObjectSafety::GetInterfaceSafetyOptions( 
	/* [in] */ REFIID riid,
	/* [out] */ DWORD *pdwSupportedOptions,
	/* [out] */ DWORD *pdwEnabledOptions)
{
	DBGPRINTF(("CObjectSafety::GetInterfaceSafetyOptions()\n"));
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CObjectSafety::SetInterfaceSafetyOptions( 
	/* [in] */ REFIID riid,
	/* [in] */ DWORD dwOptionSetMask,
	/* [in] */ DWORD dwEnabledOptions)
{
	DBGPRINTF(("CObjectSafety::SetInterfaceSafetyOptions()\n"));
	
	return S_OK;
}

//-----------------------------------------------------------------------------
// CClassFactory implementation
//-----------------------------------------------------------------------------
STDMETHODIMP CClassFactory::QueryInterface(REFIID riid, void **ppv)
{
	DBGPRINTF(("CClassFactory::QueryInterface(%s)\n", IIDString(riid).c_str()));
	if (riid == IID_IClassFactory) {
		*ppv = &g_classFactory;
		return S_OK;
	}
	*ppv = nullptr;
	return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CClassFactory::AddRef()
{
	DBGPRINTF(("CClassFactory::AddRef()\n"));
	return InterlockedIncrement(&_cntRef);
}

STDMETHODIMP_(ULONG) CClassFactory::Release()
{
	DBGPRINTF(("CClassFactory::Release()\n"));
	return InterlockedDecrement(&_cntRef);
}

STDMETHODIMP CClassFactory::LockServer(BOOL bLock)
{
	DBGPRINTF(("CClassFactory::LockServer()\n"));
	return S_OK;
}

STDMETHODIMP CClassFactory::CreateInstance(IUnknown *pUnknownOuter, REFIID riid, void **ppv)
{
	DBGPRINTF(("CClassFactory::CreateInstance(%s)\n", IIDString(riid).c_str()));
	if (pUnknownOuter != nullptr) return CLASS_E_NOAGGREGATION;
	CMain *pMain = new CMain();
	return pMain->QueryInterface(riid, ppv);
}

//-----------------------------------------------------------------------------
// DLL entries
//-----------------------------------------------------------------------------
BOOL WINAPI DllMain(HINSTANCE hInst, DWORD dwReason, LPVOID lpvReserved)
{
	g_hModule = hInst;
	Gura::OAL::SetModuleHandle(hInst);
	return TRUE;
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
{
	if (rclsid == CMain::ClsId) {
		return g_classFactory.QueryInterface(riid, ppv);
	}
	*ppv = nullptr;
	return CLASS_E_CLASSNOTAVAILABLE;
}

STDAPI DllRegisterServer()
{
	const char *progId = "Gura.1";
	const char *comment = "Gura Programming Language";
	HKEY hKey, hKeyParent;
	char clsIdStr[128];
	const CLSID &clsId = CMain::ClsId;
	::sprintf(clsIdStr, "{%s}", IIDString(clsId).c_str());
	do {
		if (::RegOpenKeyEx(HKEY_CLASSES_ROOT, "CLSID", 0, KEY_ALL_ACCESS, &hKey)
												!= ERROR_SUCCESS) goto error_done;
		hKeyParent = hKey;
		do {
			HKEY hKey;
			if (::RegCreateKeyEx(hKeyParent, clsIdStr, 0, nullptr,
				REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, nullptr, &hKey, nullptr) != ERROR_SUCCESS) goto error_done;
			if (::RegSetValueEx(hKey, "", 0, REG_SZ,
				reinterpret_cast<const BYTE *>(progId),
				static_cast<DWORD>(::strlen(progId) + 1)) != ERROR_SUCCESS) goto error_done;
			hKeyParent = hKey;
			do {
				HKEY hKey;
				char fileName[MAX_PATH];
				::GetModuleFileName(g_hModule, fileName, MAX_PATH);
				if (::RegCreateKeyEx(hKeyParent, "InprocServer32", 0, nullptr,
					REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, nullptr, &hKey, nullptr) != ERROR_SUCCESS) goto error_done;
				if (::RegSetValueEx(hKey, "", 0, REG_SZ,
					reinterpret_cast<const BYTE *>(fileName),
					static_cast<DWORD>(::strlen(fileName) + 1)) != ERROR_SUCCESS) goto error_done;
				::RegCloseKey(hKey);
			} while (0);
			do {
				HKEY hKey;
				if (::RegCreateKeyEx(hKeyParent, "ProgID", 0, nullptr,
					REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, nullptr, &hKey, nullptr) != ERROR_SUCCESS) goto error_done;
				if (::RegSetValueEx(hKey, "", 0, REG_SZ,
					reinterpret_cast<const BYTE *>(progId),
					static_cast<DWORD>(::strlen(progId) + 1)) != ERROR_SUCCESS) goto error_done;
				::RegCloseKey(hKey);
			} while (0);
			::RegCloseKey(hKey);
		} while (0);
		::RegCloseKey(hKey);
	} while (0);
	do {
		if (::RegCreateKeyEx(HKEY_CLASSES_ROOT, "Gura", 0, nullptr,
			REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, nullptr, &hKey, nullptr) != ERROR_SUCCESS) goto error_done;
		if (::RegSetValueEx(hKey, "", 0, REG_SZ,
			reinterpret_cast<const BYTE *>(comment),
			static_cast<DWORD>(::strlen(comment) + 1)) != ERROR_SUCCESS) goto error_done;
		hKeyParent = hKey;
		do {
			HKEY hKey;
			if (::RegCreateKeyEx(hKeyParent, "CLSID", 0, nullptr,
				REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, nullptr, &hKey, nullptr) != ERROR_SUCCESS) goto error_done;
			if (::RegSetValueEx(hKey, "", 0, REG_SZ,
				reinterpret_cast<const BYTE *>(clsIdStr),
				static_cast<DWORD>(::strlen(clsIdStr) + 1)) != ERROR_SUCCESS) goto error_done;
			::RegCloseKey(hKey);
		} while (0);
		do {
			HKEY hKey;
			if (::RegCreateKeyEx(hKeyParent, "OLEScript", 0, nullptr,
				REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, nullptr, &hKey, nullptr) != ERROR_SUCCESS) goto error_done;
			::RegCloseKey(hKey);
		} while (0);
		::RegCloseKey(hKey);
	} while (0);
	return S_OK;
error_done:
	DWORD dwErrCode = ::GetLastError();
	return HRESULT_FROM_WIN32(dwErrCode);
}

STDAPI DllUnregisterServer()
{
	HKEY hKey, hKeyParent;
	char clsIdStr[128];
	const CLSID &clsId = CMain::ClsId;
	::sprintf(clsIdStr, "{%s}", IIDString(clsId).c_str());
	do {
		if (::RegOpenKeyEx(HKEY_CLASSES_ROOT, "CLSID", 0, KEY_ALL_ACCESS, &hKey)
												!= ERROR_SUCCESS) goto error_done;
		hKeyParent = hKey;
		do {
			HKEY hKey;
			::RegOpenKeyEx(hKeyParent, clsIdStr, 0, KEY_ALL_ACCESS, &hKey);
			::RegDeleteKey(hKey, "InprocServer32");
			::RegDeleteKey(hKey, "ProgID");
			::RegCloseKey(hKey);
		} while (0);
		::RegDeleteKey(hKey, clsIdStr);
		::RegCloseKey(hKey);
	} while (0);
	do {
		do {
			HKEY hKey;
			::RegOpenKeyEx(HKEY_CLASSES_ROOT, "Gura", 0, KEY_ALL_ACCESS, &hKey);
			::RegDeleteKey(hKey, "CLSID");
			::RegDeleteKey(hKey, "OLEScript");
			::RegCloseKey(hKey);
		} while (0);
		::RegDeleteKey(HKEY_CLASSES_ROOT, "Gura");
	} while (0);
	return S_OK;
error_done:
	DWORD dwErrCode = ::GetLastError();
	return HRESULT_FROM_WIN32(dwErrCode);
}
