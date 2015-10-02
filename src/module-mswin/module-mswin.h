//-----------------------------------------------------------------------------
// Gura module: mswin
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_MSWIN_H__
#define __GURA_MODULE_MSWIN_H__

#include <gura.h>

Gura_BeginModuleHeader(mswin)

Gura_DeclareUserSymbol(connect);
Gura_DeclareUserSymbol(no_const);
Gura_DeclareUserSymbol(openkey);

//-----------------------------------------------------------------------------
// Object_regkey declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(regkey);

class Object_regkey : public Object {
private:
	HKEY _hKey;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(regkey)
public:
	inline Object_regkey(HKEY hKey, bool ownerFlag) :
		Object(Gura_UserClass(regkey)), _hKey(hKey), _ownerFlag(ownerFlag) {}
	inline Object_regkey(const Object_regkey &obj) :
		Object(obj), _hKey(obj._hKey), _ownerFlag(false) {}
	virtual ~Object_regkey();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline HKEY GetKey() { return _hKey; }
};

//-----------------------------------------------------------------------------
// Object_ole declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(ole);

class Object_ole : public Object {
public:
	class IteratorEx : public Iterator {
	private:
		AutoPtr<Object_ole> _pObj;
		IEnumVARIANT *_pEnum;
		bool _validFlag;
		Value _value;
	public:
		inline IteratorEx(Object_ole *pObj, IEnumVARIANT *pEnum) :
				Iterator(false), _pObj(pObj), _pEnum(pEnum), _validFlag(false) {}
		virtual ~IteratorEx();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
public:
	class CallableOLE : public Callable {
	private:
		Object_ole *_pObj;
		const Symbol *_pSymbol;
		DISPID _dispid;
	public:
		inline CallableOLE(Object_ole *pObj, const Symbol *pSymbol, DISPID dispid) :
								_pObj(pObj), _pSymbol(pSymbol), _dispid(dispid) {}
		virtual Value DoCall(
			Environment &env, const CallerInfo &callerInfo,
			const Value &valueThis, const Iterator *pIteratorThis,
			const TrailCtrlHolder *pTrailCtrlHolder);
		inline const Symbol *GetSymbol() const { return _pSymbol; }
	};
	class CallableOLEList : public std::vector<CallableOLE *> {
	};
	class CallableOLEOwner : public CallableOLEList {
	public:
		~CallableOLEOwner();
		void Clear();
	};
private:
	IDispatch *_pDispatch;
	CallableOLEOwner _callableOLEOwner;
public:
	Gura_DeclareObjectAccessor(ole)
public:
	inline Object_ole(Environment &env) :
		Object(env.LookupClass(VTYPE_ole)), _pDispatch(nullptr) {}
	inline Object_ole(Environment &env, IDispatch *pDispatch) :
		Object(env.LookupClass(VTYPE_ole)), _pDispatch(pDispatch) {}
	virtual ~Object_ole();
	virtual Object *Clone() const;
	inline IDispatch *GetDispatch() { return _pDispatch; }
	bool Create(Signal &sig, const char *progID);
	bool Connect(Signal &sig, const char *progID);
	bool ImportConstant(Environment &env, Signal &sig);
	HRESULT GetDispID(const char *name, DISPID &dispid);
	HRESULT GetDispIDOfNamedArg(
				const char *nameMethod, const char *name, DISPID &dispid);
	virtual Iterator *CreateIterator(Signal &sig);
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Callable *GetCallable(Signal &sig, const Symbol *pSymbol);
	virtual String ToString(bool exprFlag);
	static void SetError(Signal &sig, HRESULT hr);
};

//-----------------------------------------------------------------------------
// Iterator_RegEnumKey declaration
//-----------------------------------------------------------------------------
class Iterator_RegEnumKey : public Iterator {
private:
	AutoPtr<Object_regkey> _pObjRegKey;
	REGSAM _samDesired;
	DWORD _dwIndex;
public:
	Iterator_RegEnumKey(Object_regkey *pObjRegKey, REGSAM samDesired);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_RegEnumValue declaration
//-----------------------------------------------------------------------------
class Iterator_RegEnumValue : public Iterator {
private:
	AutoPtr<Object_regkey> _pObjRegKey;
	DWORD _dwIndex;
public:
	Iterator_RegEnumValue(Object_regkey *pObjRegKey);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void SetError(Signal &sig, DWORD dwErrCode);
OLECHAR *StringToBSTR(const char *psz);
String BSTRToString(const OLECHAR *bstr);
bool ValueToVariant(Signal &sig, VARIANT &var, const Value &value);
bool VariantToValue(Environment &env, Signal &sig, Value &value, const VARIANT &var);
Value RegDataToValue(Environment &env, Signal &sig,
							DWORD dwType, LPCBYTE lpData, DWORD cbData);
bool ValueToRegData(Environment &env, Signal &sig, const Value &value,
							DWORD *pdwType, LPBYTE *lppData, DWORD *pcbData);

Gura_EndModuleHeader(mswin)

#endif
