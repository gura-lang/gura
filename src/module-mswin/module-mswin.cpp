//-----------------------------------------------------------------------------
// Gura module: mswin
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include <ATLComTime.h>

Gura_BeginModuleBody(mswin)

//-----------------------------------------------------------------------------
// Object_regkey implementation
//-----------------------------------------------------------------------------
Object_regkey::~Object_regkey()
{
	if (_ownerFlag) ::RegCloseKey(_hKey);
}

Object *Object_regkey::Clone() const
{
	return NULL;
}

String Object_regkey::ToString(bool exprFlag)
{
	return String("<mswin.regkey>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_regkey
//-----------------------------------------------------------------------------
// mswin.regkey#createkey(subkey:string, option?:number, samDesired?:number):map {block?}
Gura_DeclareMethod(regkey, createkey)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "subkey", VTYPE_string);
	DeclareArg(env, "option", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "samDesired", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(regkey, createkey)
{
	Object_regkey *pThis = Object_regkey::GetThisObj(args);
	HKEY hKey = pThis->GetKey();
	const char *lpSubKey = args.GetString(0);
	DWORD dwOptions = args.Is_number(1)? args.GetULong(1) : REG_OPTION_NON_VOLATILE;
	if (sig.IsSignalled()) return Value::Null;
	REGSAM samDesired = args.Is_number(2)? args.GetULong(2) : KEY_ALL_ACCESS;
	HKEY hKeyResult;
	DWORD dwDisposition;
	DWORD dwErrCode = ::RegCreateKeyEx(hKey, OAL::ToNativeString(lpSubKey).c_str(),
			0, NULL, dwOptions, samDesired, NULL, &hKeyResult, &dwDisposition);
	if (dwErrCode != ERROR_SUCCESS) {
		SetError(sig, dwErrCode);
		return Value::Null;
	}
	Value result(new Object_regkey(hKeyResult, true));
	return ReturnValue(env, sig, args, result);
}

// mswin.regkey#openkey(subkey:string, samDesired?:number):map {block?}
Gura_DeclareMethod(regkey, openkey)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "subkey", VTYPE_string);
	DeclareArg(env, "samDesired", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(regkey, openkey)
{
	Object_regkey *pThis = Object_regkey::GetThisObj(args);
	HKEY hKey = pThis->GetKey();
	const char *lpSubKey = args.GetString(0);
	if (sig.IsSignalled()) return Value::Null;
	REGSAM samDesired = args.Is_number(1)? args.GetULong(1) : KEY_ALL_ACCESS;
	HKEY hKeyResult;
	DWORD dwErrCode = ::RegOpenKeyEx(hKey, OAL::ToNativeString(lpSubKey).c_str(),
												0, samDesired, &hKeyResult);
	if (dwErrCode != ERROR_SUCCESS) {
		SetError(sig, dwErrCode);
		return Value::Null;
	}
	Value result(new Object_regkey(hKeyResult, true));
	return ReturnValue(env, sig, args, result);
}

// mswin.regkey#deletekey(subkey:string):map:void
Gura_DeclareMethod(regkey, deletekey)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "subkey", VTYPE_string);
}

Gura_ImplementMethod(regkey, deletekey)
{
	Object_regkey *pThis = Object_regkey::GetThisObj(args);
	HKEY hKey = pThis->GetKey();
	const char *lpSubKey = args.GetString(0);
	DWORD dwErrCode = ::RegDeleteKey(hKey, OAL::ToNativeString(lpSubKey).c_str());
	if (dwErrCode != ERROR_SUCCESS) {
		SetError(sig, dwErrCode);
		return Value::Null;
	}
	return Value::Null;
}

// mswin.regkey#enumkey(samDesired?:number):[openkey] {block?}
Gura_DeclareMethod(regkey, enumkey)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "samDesired", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_UserSymbol(openkey));
}

Gura_ImplementMethod(regkey, enumkey)
{
	Object_regkey *pThis = Object_regkey::GetThisObj(args);
	REGSAM samDesired = 0;
	if (!args.IsSet(Gura_UserSymbol(openkey))) {
		// nothing to do
	} else {
		samDesired = args.Is_number(0)? args.GetULong(0) : KEY_ALL_ACCESS;
	}
	Iterator *pIterator =
			new Iterator_RegEnumKey(Object_regkey::Reference(pThis), samDesired);
	return ReturnIterator(env, sig, args, pIterator);
}

// mswin.regkey#setvalue(valueName:string, data:nomap):map
Gura_DeclareMethod(regkey, setvalue)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "valueName", VTYPE_string);
	DeclareArg(env, "data", VTYPE_any, OCCUR_Once, FLAG_NoMap);
}

Gura_ImplementMethod(regkey, setvalue)
{
	Object_regkey *pThis = Object_regkey::GetThisObj(args);
	HKEY hKey = pThis->GetKey();
	const char *lpValueName = args.GetString(0);
	DWORD dwType = 0;
	BYTE *lpData = NULL;
	DWORD cbData = 0;
	if (!ValueToRegData(env, sig, args.GetValue(1), &dwType, &lpData, &cbData)) {
		return Value::Null;
	}
	DWORD dwErrCode = ::RegSetValueEx(hKey,
			OAL::ToNativeString(lpValueName).c_str(), 0, dwType, lpData, cbData);
	::LocalFree(lpData);
	if (dwErrCode != ERROR_SUCCESS) {
		SetError(sig, dwErrCode);
		return Value::Null;
	}
	return Value::Null;
}

// mswin.regkey#deletevalue(valueName:string):map:void
Gura_DeclareMethod(regkey, deletevalue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "valueName", VTYPE_string);
}

Gura_ImplementMethod(regkey, deletevalue)
{
	Object_regkey *pThis = Object_regkey::GetThisObj(args);
	HKEY hKey = pThis->GetKey();
	const char *lpValueName = args.GetString(0);
	DWORD dwErrCode = ::RegDeleteValue(hKey, OAL::ToNativeString(lpValueName).c_str());
	if (dwErrCode != ERROR_SUCCESS) {
		SetError(sig, dwErrCode);
		return Value::Null;
	}
	return Value::Null;
}

// mswin.regkey#queryvalue(valueName?:string):map
Gura_DeclareMethod(regkey, queryvalue)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "valueName", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(regkey, queryvalue)
{
	Object_regkey *pThis = Object_regkey::GetThisObj(args);
	HKEY hKey = pThis->GetKey();
	const char *lpValueName = args.Is_string(0)? args.GetString(0) : NULL;
	DWORD dwType;
	DWORD cbData;
	DWORD dwErrCode = ::RegQueryValueEx(hKey,
		OAL::ToNativeString(lpValueName).c_str(), NULL, &dwType, NULL, &cbData);
	if (dwErrCode != ERROR_SUCCESS) {
		SetError(sig, dwErrCode);
		return Value::Null;
	}
	LPBYTE lpData = reinterpret_cast<LPBYTE>(::LocalAlloc(LMEM_FIXED, cbData));
	dwErrCode = ::RegQueryValueEx(hKey,
		OAL::ToNativeString(lpValueName).c_str(), NULL, &dwType, lpData, &cbData);
	if (dwErrCode != ERROR_SUCCESS) {
		::LocalFree(lpData);
		SetError(sig, dwErrCode);
		return Value::Null;
	}
	Value result = RegDataToValue(env, sig, dwType, lpData, cbData);
	::LocalFree(lpData);
	return result;
}

// mswin.regkey#enumvalue() {block?}
Gura_DeclareMethod(regkey, enumvalue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(regkey, enumvalue)
{
	Object_regkey *pThis = Object_regkey::GetThisObj(args);
	HKEY hKey = pThis->GetKey();
	Iterator *pIterator =
			new Iterator_RegEnumValue(Object_regkey::Reference(pThis));
	return ReturnIterator(env, sig, args, pIterator);
}

// implementation of class RegKey
Gura_ImplementUserClass(regkey)
{
	Gura_AssignMethod(regkey, createkey);
	Gura_AssignMethod(regkey, openkey);
	Gura_AssignMethod(regkey, deletekey);
	Gura_AssignMethod(regkey, enumkey);
	Gura_AssignMethod(regkey, setvalue);
	Gura_AssignMethod(regkey, deletevalue);
	Gura_AssignMethod(regkey, queryvalue);
	Gura_AssignMethod(regkey, enumvalue);
}

//-----------------------------------------------------------------------------
// Object_ole implementation
//-----------------------------------------------------------------------------
Object_ole::~Object_ole()
{
	if (_pDispatch != NULL) {
		_pDispatch->Release();
	}
}

Object *Object_ole::Clone() const
{
	return NULL;
}

bool Object_ole::Create(Signal sig, const char *progID)
{
	HRESULT hr;
	CLSID clsid;
	do {
		OLECHAR *progID_W = StringToBSTR(progID);
		::CLSIDFromProgID(progID_W, &clsid);
		::SysFreeString(progID_W);
	} while (0);
	hr = ::CoCreateInstance(clsid,
					NULL, CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER,
					IID_IDispatch, reinterpret_cast<LPVOID *>(&_pDispatch));
	if (FAILED(hr)) {
		SetError(sig, hr);
		return false;
	}
	return true;
}

bool Object_ole::Connect(Signal sig, const char *progID)
{
	HRESULT hr;
	CLSID clsid;
	do {
		OLECHAR *progID_W = StringToBSTR(progID);
		::CLSIDFromProgID(progID_W, &clsid);
		::SysFreeString(progID_W);
	} while (0);
	IUnknown *pUnknown = NULL;
	hr = ::GetActiveObject(clsid, 0, &pUnknown);
	if (FAILED(hr)) {
		SetError(sig, hr);
		return false;
	}
	hr = pUnknown->QueryInterface(IID_IDispatch,
								reinterpret_cast<LPVOID *>(&_pDispatch));
	if (FAILED(hr)) {
		pUnknown->Release();
		SetError(sig, hr);
		return false;
	}
	pUnknown->Release();
	return true;
}

bool Object_ole::ImportConstant(Environment &env, Signal sig)
{
	HRESULT hr;
	//hr = _pDispatch->GetTypeInfoCount(&cnt); // 0 or 1
	ITypeLib *pTypeLib = NULL;
	do {
		ITypeInfo *pTypeInfo = NULL;
		do {
			hr = _pDispatch->GetTypeInfo(0, LOCALE_SYSTEM_DEFAULT, &pTypeInfo);
			if (FAILED(hr)) {
				SetError(sig, hr);
				return false;
			}
		} while (0);
		do {
			unsigned int index; // not necessary for the actual use?
			hr = pTypeInfo->GetContainingTypeLib(&pTypeLib, &index);
			if (FAILED(hr)) {
				SetError(sig, hr);
				pTypeInfo->Release();
				return false;
			}
		} while (0);
		pTypeInfo->Release();
	} while (0);
	long cntTypeInfo = pTypeLib->GetTypeInfoCount();
	for (long iTypeInfo = 0; iTypeInfo < cntTypeInfo; iTypeInfo++) {
		ITypeInfo *pTypeInfo = NULL;
		do {
			hr = pTypeLib->GetTypeInfo(iTypeInfo, &pTypeInfo);
			if (FAILED(hr)) {
				SetError(sig, hr);
				pTypeLib->Release();
				return false;
			}
		} while (0);
		int cVars = 0;
		do {
			TYPEATTR *pTypeAttr = NULL;
			hr = pTypeInfo->GetTypeAttr(&pTypeAttr);
			if (FAILED(hr)) {
				SetError(sig, hr);
				pTypeInfo->Release();
				pTypeLib->Release();
				return false;
			}
			cVars = pTypeAttr->cVars;
			pTypeInfo->ReleaseTypeAttr(pTypeAttr);
		} while (0);
		for (int iVar = 0; iVar < cVars; iVar++) {
			VARDESC *pVarDesc = NULL;
			hr = pTypeInfo->GetVarDesc(iVar, &pVarDesc);
			if (FAILED(hr)) continue;
			if (pVarDesc->varkind != VAR_CONST) {
				pTypeInfo->ReleaseVarDesc(pVarDesc);
				continue;
			}
			const Symbol *pSymbol = NULL;
			do {
				OLECHAR *nameOle;
				unsigned int len;
				hr = pTypeInfo->GetNames(pVarDesc->memid, &nameOle, 1, &len);
				if (FAILED(hr)) break;
				pSymbol = Symbol::Add(BSTRToString(nameOle).c_str());
				::SysFreeString(nameOle);
			} while (0);
			if (pSymbol != NULL) {
				Value value;
				if (!VariantToValue(*this, sig, value, *pVarDesc->lpvarValue)) return false;
				env.AssignValue(pSymbol, value, EXTRA_Public);
			}
			pTypeInfo->ReleaseVarDesc(pVarDesc);
		}
		pTypeInfo->Release();
	}
	pTypeLib->Release();
	return true;
}

HRESULT Object_ole::GetDispID(const char *name, DISPID &dispid)
{
	OLECHAR *wszName = StringToBSTR(name);
	HRESULT hr = _pDispatch->GetIDsOfNames(IID_NULL,
							&wszName, 1, LOCALE_USER_DEFAULT, &dispid);
	::SysFreeString(wszName);
	return hr;
}

HRESULT Object_ole::GetDispIDOfNamedArg(
				const char *nameMethod, const char *nameArg, DISPID &dispid)
{
	// named argument have to be looked up with a method name. see MSDN KB223165.
	OLECHAR *wszNames[2];
	DISPID dispids[2];
	wszNames[0] = StringToBSTR(nameMethod);
	wszNames[1] = StringToBSTR(nameArg);
	HRESULT hr = _pDispatch->GetIDsOfNames(IID_NULL,
							wszNames, 2, LOCALE_USER_DEFAULT, dispids);
	::SysFreeString(wszNames[0]);
	::SysFreeString(wszNames[1]);
	dispid = dispids[1];
	return hr;
}

Iterator *Object_ole::CreateIterator(Signal sig)
{
	VARIANT var;
	HRESULT hr;
	::VariantInit(&var);
	do {
		DISPPARAMS dispParams = { NULL, NULL, 0, 0 };
	    EXCEPINFO exceptInfo;
		unsigned int argErr;
		::memset(&exceptInfo, 0, sizeof(exceptInfo));
		hr = _pDispatch->Invoke(DISPID_NEWENUM, IID_NULL, LOCALE_USER_DEFAULT,
					DISPATCH_METHOD | DISPATCH_PROPERTYGET,
					&dispParams, &var, &exceptInfo, &argErr);
		if (FAILED(hr)) {
			sig.SetError(ERR_RuntimeError, "OLE object is not iteratable");
			return NULL;
		}
	} while (0);
	IEnumVARIANT *pEnum = NULL;
	VARTYPE type = var.vt & VT_TYPEMASK;
	if (type == VT_UNKNOWN) {
		IUnknown *pUnknown = (var.vt & VT_BYREF)? *var.ppunkVal : var.punkVal;
		hr = pUnknown->QueryInterface(IID_IEnumVARIANT,
										reinterpret_cast<LPVOID *>(&pEnum));
	} else if (type == VT_DISPATCH) {
		IDispatch *pDispatch = (var.vt & VT_BYREF)? *var.ppdispVal : var.pdispVal;
		hr = pDispatch->QueryInterface(IID_IEnumVARIANT,
										reinterpret_cast<LPVOID *>(&pEnum));
	} else {
		sig.SetError(ERR_RuntimeError, "unexpected return value");
		return NULL;
	}
	::VariantClear(&var);
	if (FAILED(hr)) {
		SetError(sig, hr);
		return NULL;
	}
	Iterator *pIterator = new IteratorEx(Object_ole::Reference(this), pEnum);
	return pIterator;
}

bool Object_ole::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	HRESULT hr;
	//hr = _pDispatch->GetTypeInfoCount(&cnt); // 0 or 1
	ITypeLib *pTypeLib = NULL;
	do {
		ITypeInfo *pTypeInfo = NULL;
		do {
			hr = _pDispatch->GetTypeInfo(0, LOCALE_SYSTEM_DEFAULT, &pTypeInfo);
			if (FAILED(hr)) {
				SetError(sig, hr);
				return false;
			}
		} while (0);
		do {
			unsigned int index; // not necessary for the actual use?
			hr = pTypeInfo->GetContainingTypeLib(&pTypeLib, &index);
			if (FAILED(hr)) {
				SetError(sig, hr);
				pTypeInfo->Release();
				return false;
			}
		} while (0);
		pTypeInfo->Release();
	} while (0);
	long cntTypeInfo = pTypeLib->GetTypeInfoCount();
	for (long iTypeInfo = 0; iTypeInfo < cntTypeInfo; iTypeInfo++) {
		ITypeInfo *pTypeInfo = NULL;
		do {
			hr = pTypeLib->GetTypeInfo(iTypeInfo, &pTypeInfo);
			if (FAILED(hr)) {
				SetError(sig, hr);
				pTypeLib->Release();
				return false;
			}
		} while (0);
		int cFuncs = 0;
		int cVars = 0;
		do {
			TYPEATTR *pTypeAttr = NULL;
			hr = pTypeInfo->GetTypeAttr(&pTypeAttr);
			if (FAILED(hr)) {
				SetError(sig, hr);
				pTypeInfo->Release();
				pTypeLib->Release();
				return false;
			}
			cFuncs = pTypeAttr->cFuncs;
			cVars = pTypeAttr->cVars;
			pTypeInfo->ReleaseTypeAttr(pTypeAttr);
		} while (0);
		for (int iFunc = 0; iFunc < cFuncs; iFunc++) {
			FUNCDESC *pFuncDesc = NULL;
			hr = pTypeInfo->GetFuncDesc(iFunc, &pFuncDesc);
			if (FAILED(hr)) continue;
			const Symbol *pSymbol = NULL;
			do {
				OLECHAR *nameOle;
				unsigned int len;
				hr = pTypeInfo->GetNames(pFuncDesc->memid, &nameOle, 1, &len);
				if (FAILED(hr)) break;
				pSymbol = Symbol::Add(BSTRToString(nameOle).c_str());
				::SysFreeString(nameOle);
			} while (0);
			if (pSymbol != NULL) symbols.insert(pSymbol);
			pTypeInfo->ReleaseFuncDesc(pFuncDesc);
		}
#if 0
		for (int iVar = 0; iVar < cVars; iVar++) {
			VARDESC *pVarDesc = NULL;
			hr = pTypeInfo->GetVarDesc(iVar, &pVarDesc);
			if (FAILED(hr)) continue;
			const Symbol *pSymbol = NULL;
			do {
				OLECHAR *nameOle;
				unsigned int len;
				hr = pTypeInfo->GetNames(pVarDesc->memid, &nameOle, 1, &len);
				if (FAILED(hr)) break;
				pSymbol = Symbol::Add(BSTRToString(nameOle).c_str());
				::SysFreeString(nameOle);
			} while (0);
			if (pSymbol != NULL) symbols.insert(pSymbol);
			pTypeInfo->ReleaseVarDesc(pVarDesc);
		}
#endif
		pTypeInfo->Release();
	}
	pTypeLib->Release();
	return true;
}

Value Object_ole::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	DISPID dispid;
	do {
		HRESULT hr = GetDispID(pSymbol->GetName(), dispid);
		if (FAILED(hr)) {
			SetError(sig, hr);
			return Value::Null;
		}
	} while (0);
	evaluatedFlag = true;
	VARIANT var;
	do {
		DISPPARAMS dispParams = { NULL, NULL, 0, 0 };
		HRESULT hr = _pDispatch->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT,
						DISPATCH_PROPERTYGET, &dispParams, &var, NULL, NULL);
		if (FAILED(hr)) {
			SetError(sig, hr);
			return Value::Null;
		}
	} while (0);
	Value result;
	VariantToValue(*this, sig, result, var);
	::VariantClear(&var);
	return result;
}

Value Object_ole::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	DISPID dispid;
	do {
		HRESULT hr = GetDispID(pSymbol->GetName(), dispid);
		if (FAILED(hr)) {
			SetError(sig, hr);
			return Value::Null;
		}
	} while (0);
	do {
		VARIANTARG varArgs[1];
		DISPID dispidNamedArgs[1] = { DISPID_PROPERTYPUT };
		if (!ValueToVariant(sig, varArgs[0], value)) return Value::Null;
		DISPPARAMS dispParams;
		dispParams.rgvarg = varArgs;
		dispParams.rgdispidNamedArgs = dispidNamedArgs;
		dispParams.cArgs = 1;
		dispParams.cNamedArgs = 1;
		HRESULT hr = _pDispatch->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT,
							DISPATCH_PROPERTYPUT, &dispParams, NULL, NULL, NULL);
		::VariantClear(&varArgs[0]);
		if (FAILED(hr)) {
			sig.SetError(ERR_RuntimeError, "can't change OLE property %s", pSymbol->GetName());
			return Value::Null;
		}
	} while (0);
	return value;
}

Callable *Object_ole::GetCallable(Signal sig, const Symbol *pSymbol)
{
	foreach (CallableOLEOwner, ppCallableOLE, _callableOLEOwner) {
		CallableOLE *pCallableOLE = *ppCallableOLE;
		if (pCallableOLE->GetSymbol() == pSymbol) return pCallableOLE;
	}
	DISPID dispid;
	HRESULT hr = GetDispID(pSymbol->GetName(), dispid);
	if (FAILED(hr)) {
		Object_ole::SetError(sig, hr);
		return NULL;
	}
	CallableOLE *pCallableOLE = new CallableOLE(this, pSymbol, dispid);
	_callableOLEOwner.push_back(pCallableOLE);
	return pCallableOLE;
}

String Object_ole::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<mswin.ole:";
	do {
		HRESULT hr;
		ITypeInfo *pTypeInfo = NULL;
		do {
			hr = _pDispatch->GetTypeInfo(0, LOCALE_SYSTEM_DEFAULT, &pTypeInfo);
			if (FAILED(hr)) {
				rtn += "*error*>";
				return rtn;
			}
		} while (0);
		TYPEKIND typekind;
		do {
			TYPEATTR *pTypeAttr = NULL;
			hr = pTypeInfo->GetTypeAttr(&pTypeAttr);
			if (FAILED(hr)) {
				rtn += "*error*>";
				pTypeInfo->Release();
				return rtn;
			}
			typekind = pTypeAttr->typekind;
			pTypeInfo->ReleaseTypeAttr(pTypeAttr);
		} while (0);
		if (typekind == TKIND_ALIAS) {
			rtn += "alias";
		} else if (typekind == TKIND_COCLASS) {
			rtn += "coclass";
		} else if (typekind == TKIND_DISPATCH) {
			rtn += "dispatch";
		} else if (typekind == TKIND_ENUM) {
			rtn += "enum";
		} else if (typekind == TKIND_INTERFACE) {
			rtn += "interface";
		} else if (typekind == TKIND_MAX) {
			rtn += "max";
		} else if (typekind == TKIND_MODULE) {
			rtn += "module";
		} else if (typekind == TKIND_RECORD) {
			rtn += "record";
		} else if (typekind == TKIND_UNION) {
			rtn += "union";
		} else {
			rtn += "(unknown)";
		}
		pTypeInfo->Release();
	} while (0);
	rtn += ">";
	return rtn;
}

void Object_ole::SetError(Signal sig, HRESULT hr)
{
	LPWSTR errMsg = NULL;
	::FormatMessageW(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, hr, LOCALE_SYSTEM_DEFAULT, reinterpret_cast<LPWSTR>(&errMsg), 0, NULL);
	if (errMsg == NULL) {
		sig.SetError(ERR_RuntimeError, "COM error [%08x]", hr);
	} else {
		int len = static_cast<int>(::wcslen(errMsg));
		if (len > 0 && errMsg[len - 1] == '\n') len--;
		int bytes = ::WideCharToMultiByte(CP_UTF8, 0, errMsg, len, NULL, 0, NULL, NULL);
		char *pszErrMsg = new char [bytes];
		::WideCharToMultiByte(CP_UTF8, 0, errMsg, len, pszErrMsg, bytes, NULL, NULL);
		pszErrMsg[bytes] = '\0';
		sig.SetError(ERR_RuntimeError, "COM error [%08x] %s", hr, pszErrMsg);
		::LocalFree(errMsg);
	}
}

//-----------------------------------------------------------------------------
// Object_ole::CallableOLE
//-----------------------------------------------------------------------------
Value Object_ole::CallableOLE::DoCall(Environment &env, Signal sig, Args &argsExpr)
{
	Value result;
	HRESULT hr;
	const ExprList &exprListArg = argsExpr.GetExprListArg();
	VARIANTARG *varArgs = NULL;
	DISPID *dispidNamedArgs = NULL;
	ValueList valueArgs;
	ValueList valueArgsNamed;
	StringList argNames;
	foreach_const (ExprList, ppExpr, exprListArg) {
		const Expr *pExpr = *ppExpr;
		if (pExpr->IsOperatorPair()) {
			const Expr_BinaryOp *pExprBinaryOp =
						dynamic_cast<const Expr_BinaryOp *>(pExpr);
			const Expr *pExprLeft = pExprBinaryOp->GetLeft()->Unquote();
			if (pExprLeft->IsSymbol()) {
				const Symbol *pSymbol = dynamic_cast<const Expr_Symbol *>(pExprLeft)->GetSymbol();
				argNames.push_back(pSymbol->GetName());
			} else if (pExprLeft->IsValue() &&
					dynamic_cast<const Expr_Value *>(pExprLeft)->GetValue().Is_string()) {
				const char *str = dynamic_cast<const Expr_Value *>(pExprLeft)->GetValue().GetString();
				argNames.push_back(str);
			} else {
				sig.SetError(ERR_ValueError,
						"a key for named argument of OLE must be a string or symbol");
				goto error_done;
			}
			SeqPostHandler *pSeqPostHandler = NULL;
			Value value = pExprBinaryOp->GetRight()->Exec2(env, sig, pSeqPostHandler);
			if (sig.IsSignalled()) goto error_done;
			valueArgsNamed.push_back(value);
		} else {
			SeqPostHandler *pSeqPostHandler = NULL;
			Value value = pExpr->Exec2(env, sig, pSeqPostHandler);
			if (sig.IsSignalled()) goto error_done;
			valueArgs.push_back(value);
		}
	}
	size_t cArgs = valueArgsNamed.size() + valueArgs.size();
	if (cArgs > 0) {
		varArgs = new VARIANTARG[cArgs];
		for (size_t iArg = 0; iArg < cArgs; iArg++) {
			::VariantInit(&varArgs[iArg]); // to avoid failure in ::VariantClear() after error
		}
	}
	if (!valueArgsNamed.empty()) {
		dispidNamedArgs = new DISPID[valueArgsNamed.size()];
		size_t iArg = 0;
		StringList::iterator pArgName = argNames.begin();
		foreach (ValueList, pValueArgNamed, valueArgsNamed) {
			const char *argName = pArgName->c_str();
			Value &valueArgNamed = *pValueArgNamed;
			hr = _pObj->GetDispIDOfNamedArg(_pSymbol->GetName(),
											argName, dispidNamedArgs[iArg]);
			if (FAILED(hr)) {
				Object_ole::SetError(sig, hr);
				goto error_done;
			}
			if (!ValueToVariant(sig, varArgs[iArg], valueArgNamed)) goto error_done;
			pArgName++;
			iArg++;
		}
	}
	if (!valueArgs.empty()) {
		size_t iArg = cArgs;
		foreach (ValueList, pValueArg, valueArgs) {
			Value &valueArg = *pValueArg;
			iArg--;
			if (!ValueToVariant(sig, varArgs[iArg], valueArg)) goto error_done;
		}
	}
	DISPPARAMS dispParams;
	dispParams.rgvarg = varArgs;
	dispParams.cArgs = static_cast<UINT>(cArgs);
	dispParams.rgdispidNamedArgs = dispidNamedArgs;
	dispParams.cNamedArgs = static_cast<UINT>(argNames.size());
	VARIANT varResult;
	hr = _pObj->GetDispatch()->Invoke(_dispid, IID_NULL, LOCALE_USER_DEFAULT,
					DISPATCH_METHOD | DISPATCH_PROPERTYGET,
					&dispParams, &varResult, NULL, NULL);
	if (varArgs != NULL) {
		for (size_t iArg = 0; iArg < cArgs; iArg++) {
			::VariantClear(&varArgs[iArg]);
		}
	}
	delete[] varArgs;
	delete[] dispidNamedArgs;
	if (FAILED(hr)) {
		::VariantClear(&varResult);
		Object_ole::SetError(sig, hr);
		return Value::Null;
	}
	VariantToValue(env, sig, result, varResult);
	::VariantClear(&varResult);
	return result;
error_done:
	if (varArgs != NULL) {
		for (size_t iArg = 0; iArg < cArgs; iArg++) {
			::VariantClear(&varArgs[iArg]);
		}
	}
	delete[] varArgs;
	delete[] dispidNamedArgs;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Object_ole::CallableOLEOwner
//-----------------------------------------------------------------------------
Object_ole::CallableOLEOwner::~CallableOLEOwner()
{
	Clear();
}

void Object_ole::CallableOLEOwner::Clear()
{
	foreach (CallableOLEOwner, ppCallableOLE, *this) {
		CallableOLE *pCallableOLE = *ppCallableOLE;
		delete pCallableOLE;
	}
	clear();
}

//-----------------------------------------------------------------------------
// Object_ole::IteratorEx
//-----------------------------------------------------------------------------
Object_ole::IteratorEx::~IteratorEx()
{
	_pEnum->Release();
}

Iterator *Object_ole::IteratorEx::GetSource()
{
	return NULL;
}

bool Object_ole::IteratorEx::DoNext(Environment &env, Signal sig, Value &value)
{
	VARIANT var;
	::VariantInit(&var);
	if (_pEnum->Next(1, &var, NULL) != S_OK) return false;
	VariantToValue(*_pObj, sig, value, var);
	::VariantClear(&var);
	return true;
}

String Object_ole::IteratorEx::ToString() const
{
	return String("<iterator:mswin.ole>");
}

void Object_ole::IteratorEx::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Gura Interface for Object_ole
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(ole)
{
}

//-----------------------------------------------------------------------------
// Iterator_RegEnumKey implementation
//-----------------------------------------------------------------------------
Iterator_RegEnumKey::Iterator_RegEnumKey(Object_regkey *pObjRegKey, REGSAM samDesired) :
	Iterator(false), _pObjRegKey(pObjRegKey), _samDesired(samDesired), _dwIndex(0)
{
}

Iterator *Iterator_RegEnumKey::GetSource()
{
	return NULL;
}

bool Iterator_RegEnumKey::DoNext(Environment &env, Signal sig, Value &value)
{
	char name[256];
	FILETIME ftLastWriteTime;
	HKEY hKey = _pObjRegKey->GetKey();
	DWORD pcName = ArraySizeOf(name);
	DWORD dwErrCode = ::RegEnumKeyEx(hKey, _dwIndex, name, &pcName,
										NULL, NULL, NULL, &ftLastWriteTime);
	if (dwErrCode != ERROR_SUCCESS) {
		if (dwErrCode != ERROR_NO_MORE_ITEMS) SetError(sig, dwErrCode);
		return false;
	}
	if (_samDesired == 0) {
		value = Value(OAL::FromNativeString(name));
	} else {
		HKEY hKeyResult;
		DWORD dwErrCode = ::RegOpenKeyEx(hKey, name, 0, _samDesired, &hKeyResult);
		if (dwErrCode != ERROR_SUCCESS) {
			SetError(sig, dwErrCode);
			return false;
		}
		value = Value(new Object_regkey(hKeyResult, true));
	}
	_dwIndex++;
	return true;
}

String Iterator_RegEnumKey::ToString() const
{
	return String("<iterator:mswin.regenumkey>");
}

void Iterator_RegEnumKey::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_RegEnumValue implementation
//-----------------------------------------------------------------------------
Iterator_RegEnumValue::Iterator_RegEnumValue(Object_regkey *pObjRegKey) :
	Iterator(false), _pObjRegKey(pObjRegKey), _dwIndex(0)
{
}

Iterator *Iterator_RegEnumValue::GetSource()
{
	return NULL;
}

bool Iterator_RegEnumValue::DoNext(Environment &env, Signal sig, Value &value)
{
	char valueName[256];
	DWORD cValueName = ArraySizeOf(valueName);
	HKEY hKey = _pObjRegKey->GetKey();
	DWORD dwType;
	DWORD cbData;
	DWORD dwErrCode = ::RegEnumValue(hKey, _dwIndex, 
						valueName, &cValueName, NULL, &dwType, NULL, &cbData);
	if (dwErrCode != ERROR_SUCCESS) {
		if (dwErrCode != ERROR_NO_MORE_ITEMS) SetError(sig, dwErrCode);
		return false;
	}
	cValueName = ArraySizeOf(valueName);
	LPBYTE lpData = reinterpret_cast<LPBYTE>(::LocalAlloc(LMEM_FIXED, cbData));
	dwErrCode = ::RegEnumValue(hKey, _dwIndex, 
						valueName, &cValueName, NULL, &dwType, lpData, &cbData);
	if (dwErrCode != ERROR_SUCCESS) {
		::LocalFree(lpData);
		if (dwErrCode != ERROR_NO_MORE_ITEMS) SetError(sig, dwErrCode);
		return false;
	}
	ValueList &valList = value.InitAsList(env);
	Value valueWk(OAL::FromNativeString(valueName));
	valList.push_back(valueWk);
	valList.push_back(RegDataToValue(env, sig, dwType, lpData, cbData));
	::LocalFree(lpData);
	if (sig.IsSignalled()) return false;
	_dwIndex++;
	return true;
}

String Iterator_RegEnumValue::ToString() const
{
	return String("<iterator:mswin.regenumvalue>");
}

void Iterator_RegEnumValue::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Gura module functions: mswin
//-----------------------------------------------------------------------------
// obj = mswin.ole(progid:string):map:[no_const,connect] {block?}
Gura_DeclareFunction(ole)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "progid", VTYPE_string);
	DeclareAttr(Gura_UserSymbol(no_const));
	DeclareAttr(Gura_UserSymbol(connect));
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(ole));
}

Gura_ImplementFunction(ole)
{
	AutoPtr<Object_ole> pObj(new Object_ole(env));
	if (args.IsSet(Gura_UserSymbol(connect))) {
		if (!pObj->Connect(sig, args.GetString(0))) return Value::Null;
	} else {
		if (!pObj->Create(sig, args.GetString(0))) return Value::Null;
	}
	if (!args.IsSet(Gura_UserSymbol(no_const))) {
		pObj->ImportConstant(*pObj, sig);
		if (sig.IsSignalled()) return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(pObj.release()));
}

Gura_ModuleEntry()
{
	::CoInitialize(0);
	// symbol realization
	Gura_RealizeUserSymbol(connect);
	Gura_RealizeUserSymbol(no_const);
	Gura_RealizeUserSymbol(openkey);
	// class realization
	Gura_RealizeUserClass(regkey, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(ole, env.LookupClass(VTYPE_object));
	// value assignment
	Gura_AssignValue(HKEY_CLASSES_ROOT,			Value(new Object_regkey(HKEY_CLASSES_ROOT, false)));
	Gura_AssignValue(HKEY_CURRENT_CONFIG,		Value(new Object_regkey(HKEY_CURRENT_CONFIG, false)));
	Gura_AssignValue(HKEY_CURRENT_USER,			Value(new Object_regkey(HKEY_CURRENT_USER, false)));
	Gura_AssignValue(HKEY_LOCAL_MACHINE,		Value(new Object_regkey(HKEY_LOCAL_MACHINE, false)));
	Gura_AssignValue(HKEY_USERS,				Value(new Object_regkey(HKEY_USERS, false)));
	Gura_AssignValue(HKEY_PERFORMANCE_DATA,		Value(new Object_regkey(HKEY_PERFORMANCE_DATA, false)));
	Gura_AssignValue(HKEY_DYN_DATA,				Value(new Object_regkey(HKEY_DYN_DATA, false)));
	Gura_AssignValue(REG_OPTION_NON_VOLATILE,	Value(REG_OPTION_NON_VOLATILE));
	Gura_AssignValue(REG_OPTION_VOLATILE,		Value(REG_OPTION_VOLATILE));
	Gura_AssignValue(REG_OPTION_BACKUP_RESTORE,	Value(REG_OPTION_BACKUP_RESTORE));
	Gura_AssignValue(KEY_CREATE_LINK,			Value(KEY_CREATE_LINK));
	Gura_AssignValue(KEY_CREATE_SUB_KEY,		Value(KEY_CREATE_SUB_KEY));
	Gura_AssignValue(KEY_ENUMERATE_SUB_KEYS,	Value(KEY_ENUMERATE_SUB_KEYS));
	Gura_AssignValue(KEY_EXECUTE,				Value(KEY_EXECUTE));
	Gura_AssignValue(KEY_NOTIFY,				Value(KEY_NOTIFY));
	Gura_AssignValue(KEY_QUERY_VALUE,			Value(KEY_QUERY_VALUE));
	Gura_AssignValue(KEY_SET_VALUE,				Value(KEY_SET_VALUE));
	Gura_AssignValue(KEY_ALL_ACCESS,			Value(KEY_ALL_ACCESS));
	Gura_AssignValue(KEY_READ,					Value(KEY_READ));
	Gura_AssignValue(KEY_WRITE,					Value(KEY_WRITE));
	do {
		char dirName[MAX_PATH];
		::GetWindowsDirectory(dirName, MAX_PATH);
		Gura_AssignValue(WindowsDirectory,
				Value(OAL::FromNativeString(dirName)));
		::GetSystemDirectory(dirName, MAX_PATH);
		Gura_AssignValue(SystemDirectory,
				Value(OAL::FromNativeString(dirName)));
		::GetSystemWindowsDirectory(dirName, MAX_PATH);
		Gura_AssignValue(SystemWindowsDirectory,
				Value(OAL::FromNativeString(dirName)));
	} while (0);
	do {
		char computerName[MAX_COMPUTERNAME_LENGTH + 1];
		DWORD nSize = MAX_COMPUTERNAME_LENGTH;
		::GetComputerName(computerName, &nSize);
		Gura_AssignValue(ComputerName,
				Value(OAL::FromNativeString(computerName)));
	} while (0);
	do {
		char userName[512 + 1];
		DWORD nSize = 512;
		::GetUserName(userName, &nSize);
		Gura_AssignValue(UserName,
				Value(OAL::FromNativeString(userName)));
	} while (0);
	// function assignment
	Gura_AssignFunction(ole);
}

Gura_ModuleTerminate()
{
	::CoUninitialize();
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void SetError(Signal &sig, DWORD dwErrCode)
{
	LPVOID lpMsgBuf;
	::FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS, NULL, dwErrCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&lpMsgBuf, 0, NULL);
	sig.SetError(ERR_SystemError, "Error: %s",
			BSTRToString(reinterpret_cast<OLECHAR *>(lpMsgBuf)).c_str());
	::LocalFree(lpMsgBuf);
}

OLECHAR *StringToBSTR(const char *psz)
{
	// cnt includes null-terminater
	int cnt = ::MultiByteToWideChar(CP_UTF8, 0, psz, -1, NULL, 0);
	OLECHAR *bstr = ::SysAllocStringByteLen(NULL, (cnt + 1) * sizeof(OLECHAR));
	::MultiByteToWideChar(CP_UTF8, 0, psz, -1, bstr, cnt);
	bstr[cnt] = 0;
	return bstr;
}

String BSTRToString(const OLECHAR *bstr)
{
	// cnt includes null-terminater
	int cnt = ::WideCharToMultiByte(CP_UTF8, 0, bstr, -1, NULL, 0, NULL, NULL);
	char *psz = new char [cnt + 1];
	::WideCharToMultiByte(CP_UTF8, 0, bstr, -1, psz, cnt, NULL, NULL);
	psz[cnt] = '\0';
	return String(psz);
}

bool ValueToVariant(Signal sig, VARIANT &var, const Value &value)
{
	//::printf("ValueToVariant(%s %s)\n", value.GetTypeName(), value.ToString().c_str());
	::VariantInit(&var);
	if (value.Is_number()) {
		Number num = value.GetNumber();
		if (static_cast<Number>(static_cast<long>(num)) == num) {
			var.vt = VT_I4;
			var.lVal = static_cast<long>(value.GetNumber());
		} else {
			var.vt = VT_R8;
			var.dblVal = value.GetNumber();
		}
	} else if (value.Is_string()) {
		var.vt = VT_BSTR;
		var.bstrVal = StringToBSTR(value.GetString());
	} else if (value.Is_boolean()) {
		var.vt = VT_BOOL;
		var.boolVal = value.GetBoolean()? VARIANT_TRUE : VARIANT_FALSE;
	} else if (value.Is_list()) {
		const ValueList &valList = value.GetList();
		SAFEARRAYBOUND safeArrayBound;
		safeArrayBound.lLbound = 0;
		safeArrayBound.cElements = static_cast<ULONG>(valList.size());
		SAFEARRAY *pSafeArray = ::SafeArrayCreate(VT_VARIANT, 1, &safeArrayBound);
		//::printf("%p\n", pSafeArray);
		var.vt = VT_VARIANT | VT_ARRAY;
		var.parray = pSafeArray;
		//::SafeArrayLock(pSafeArray);
		foreach_const (ValueList, pValue, valList) {
			VARIANT varElem;
			if (!ValueToVariant(sig, varElem, *pValue)) return false;
			long index = static_cast<long>(pValue - valList.begin());
			::SafeArrayPutElement(pSafeArray, &index, &varElem);
		}
		//::SafeArrayUnlock(pSafeArray);
	} else if (value.IsType(VTYPE_ole)) {
		IDispatch *pDispatch = Object_ole::GetObject(value)->GetDispatch();
		pDispatch->AddRef();
		var.vt = VT_DISPATCH;
		var.pdispVal = pDispatch;
	} else if (value.Is_datetime()) {
		const DateTime &dateTime = value.GetDateTime();
		COleDateTime oledt(dateTime.GetYear(), dateTime.GetMonth(), dateTime.GetDay(),
				dateTime.GetHour(), dateTime.GetMin(), dateTime.GetSec());
		var.vt = VT_DATE;
		var.date = oledt.m_dt;
	} else {
		sig.SetError(ERR_ValueError, "cannot convert to ole variant");
		return false;
	}
	return true;
}

bool VariantToValue(Environment &env, Signal sig, Value &value, const VARIANT &var)
{
	VARTYPE type = var.vt & VT_TYPEMASK;
	if (var.vt & VT_ARRAY) {
		var.byref;
	} else if (type == VT_UI1) {
		value = Value(static_cast<Number>((var.vt & VT_BYREF)? *var.pbVal : var.bVal));
	} else if (type == VT_I2) {
		value = Value(static_cast<Number>((var.vt & VT_BYREF)? *var.piVal : var.iVal));
	} else if (type == VT_I4) {
		value = Value(static_cast<Number>((var.vt & VT_BYREF)? *var.plVal : var.lVal));
	} else if (type == VT_R4) {
		value = Value(static_cast<Number>((var.vt & VT_BYREF)? *var.pfltVal : var.fltVal));
	} else if (type == VT_R8) {
		value = Value(static_cast<Number>((var.vt & VT_BYREF)? *var.pdblVal :var.dblVal));
	} else if (type == VT_BOOL) {
		bool result = !((static_cast<Number>((var.vt & VT_BYREF)?
											*var.pboolVal : var.boolVal)) == 0);
		value = Value(result);
	} else if (type == VT_ERROR) {
		sig.SetError(ERR_ValueError, "cantnot convert from ole variant ERROR");
		//value = Value(static_cast<Number>((var.vt & VT_BYREF)? *var.pscode : var.code));
	} else if (type == VT_CY) {
		sig.SetError(ERR_ValueError, "cantnot convert from ole variant CY");
		//value = Value(static_cast<Number>((var.vt & VT_BYREF)? *var.pcyVal : var.cyVal));
	} else if (type == VT_DATE) {
		COleDateTime oledt((var.vt & VT_BYREF)? *var.pdate : var.date);
		DateTime dateTime(oledt.GetYear(), oledt.GetMonth(), oledt.GetDay(),
				oledt.GetHour() * 3600 + oledt.GetMinute() * 60 + oledt.GetSecond(),
				0, OAL::GetSecsOffsetTZ());
		value = Value(new Object_datetime(env, dateTime));
	} else if (type == VT_BSTR) {
		value = Value(BSTRToString(var.bstrVal));
	} else if (type == VT_UNKNOWN) {
		sig.SetError(ERR_ValueError, "cantnot convert from ole variant UNKNOWN");
		//value = Value(static_cast<Number>((var.vt & VT_BYREF)? *var.ppunkVal : var.punkVal));
	} else if (type == VT_DISPATCH) {
		IDispatch *pDispatch = (var.vt & VT_BYREF)? *var.ppdispVal : var.pdispVal;
		pDispatch->AddRef(); // prevent deletion by VariantClear()
		Object_ole *pObj = new Object_ole(env, pDispatch);
		value = Value(pObj);
	} else if (type == VT_VARIANT) {
		sig.SetError(ERR_ValueError, "cantnot convert from ole variant VARIANT");
		//value = Value(static_cast<Number>(*var.pvarVal));
	}
	return true;
}

Value RegDataToValue(Environment &env, Signal sig,
								DWORD dwType, LPCBYTE lpData, DWORD cbData)
{
	Value result;
	if (dwType == REG_BINARY) {
		result = Value(new Object_binary(env, reinterpret_cast<const char *>(lpData), cbData, true));
	} else if (dwType == REG_DWORD || dwType == REG_DWORD_LITTLE_ENDIAN) {
		result = Value(*reinterpret_cast<const DWORD *>(lpData));
	} else if (dwType == REG_DWORD_BIG_ENDIAN) {
		sig.SetError(ERR_ValueError, "cantnot convert from registry value REG_DWORD_BIG_ENDIAN");
	} else if (dwType == REG_EXPAND_SZ) {
		sig.SetError(ERR_ValueError, "cantnot convert from registry value REG_EXPAND_SZ");
	} else if (dwType == REG_LINK) {
		sig.SetError(ERR_ValueError, "cantnot convert from registry value REG_LINK");
	} else if (dwType == REG_MULTI_SZ) {
		ValueList &valList = result.InitAsList(env);
		size_t bytesSum = 0;
		while (bytesSum + 1 < static_cast<size_t>(cbData)) {
			Value value(OAL::FromNativeString(
								reinterpret_cast<const char *>(lpData)));
			valList.push_back(value);
			size_t bytes = ::strlen(reinterpret_cast<const char *>(lpData)) + 1;
			lpData += bytes;
			bytesSum += bytes;
		}
	} else if (dwType == REG_NONE) {
		// nothing to do
	} else if (dwType == REG_QWORD || dwType == REG_QWORD_LITTLE_ENDIAN) {
		sig.SetError(ERR_ValueError, "cantnot convert from registry value REG_QWORD");
	} else if (dwType == REG_RESOURCE_LIST) {
		sig.SetError(ERR_ValueError, "cantnot convert from registry value REG_RESOURCE_LIST");
	} else if (dwType == REG_SZ) {
		result = Value(OAL::FromNativeString(
								reinterpret_cast<const char *>(lpData)));
	}
	return result;
}

bool ValueToRegData(Environment &env, Signal sig, const Value &value,
								DWORD *pdwType, LPBYTE *lppData, DWORD *pcbData)
{
	if (value.Is_number()) {
		*pdwType = REG_DWORD;
		*pcbData = sizeof(DWORD);
		*lppData = reinterpret_cast<LPBYTE>(::LocalAlloc(LMEM_FIXED, *pcbData));
		*reinterpret_cast<DWORD *>(*lppData) = value.GetULong();
		return true;
	} else if (value.Is_binary()) {
		const Binary &buff = value.GetBinary();
		*pdwType = REG_BINARY;
		*pcbData = static_cast<DWORD>(buff.size());
		*lppData = reinterpret_cast<LPBYTE>(::LocalAlloc(LMEM_FIXED, *pcbData));
		::memcpy(*lppData, buff.data(), *pcbData);
		return true;
	} else if (value.Is_list()) {
		size_t bytesSum = 0;
		foreach_const (ValueList, pValue, value.GetList()) {
			if (!pValue->Is_string()) goto error_done;
			String str = OAL::ToNativeString(pValue->GetString());
			size_t bytes = str.size() + 1;
			bytesSum += bytes;
		}
		bytesSum++;
		*pdwType = REG_MULTI_SZ;
		*pcbData = static_cast<DWORD>(bytesSum);
		*lppData = reinterpret_cast<LPBYTE>(::LocalAlloc(LMEM_FIXED, *pcbData));
		BYTE *p = *lppData;
		foreach_const (ValueList, pValue, value.GetList()) {
			if (!pValue->Is_string()) goto error_done;
			String str = OAL::ToNativeString(pValue->GetString());
			size_t bytes = str.size() + 1;
			::memcpy(p, str.c_str(), bytes);
			p += bytes;
		}
		*p = '\0';
		return true;
	} else if (value.Is_string()) {
		String str = OAL::ToNativeString(value.GetString());
		*pdwType = REG_SZ;
		*pcbData = static_cast<DWORD>(str.size() + 1);
		*lppData = reinterpret_cast<LPBYTE>(::LocalAlloc(LMEM_FIXED, *pcbData));
		::memcpy(*lppData, str.c_str(), *pcbData);
		return true;
	}
error_done:
	sig.SetError(ERR_ValueError, "invalid data type for registry");
	return false;
}

Gura_EndModuleBody(mswin, mswin)

Gura_RegisterModule(mswin)
