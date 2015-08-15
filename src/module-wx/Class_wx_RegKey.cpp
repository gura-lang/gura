//----------------------------------------------------------------------------
// wxRegKey
// extracted from regkey.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RegKey: public wxRegKey, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RegKey *_pObj;
public:
	inline wx_RegKey() : wxRegKey(), _pObj(nullptr) {}
	inline wx_RegKey(const wxString& strKey) : wxRegKey(strKey), _pObj(nullptr) {}
	inline wx_RegKey(const wxRegKey& keyParent, const wxString& strKey) : wxRegKey(keyParent, strKey), _pObj(nullptr) {}
	~wx_RegKey();
	inline void AssocWithGura(Object_wx_RegKey *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RegKey::~wx_RegKey()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RegKey::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRegKey
//----------------------------------------------------------------------------
Gura_DeclareFunction(RegKeyEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RegKey));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegKeyEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_RegKey *pEntity = new wx_RegKey();
	Object_wx_RegKey *pObj = Object_wx_RegKey::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RegKey(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(RegKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RegKey));
	DeclareArg(env, "strKey", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegKey)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString strKey = wxString::FromUTF8(args.GetString(0));
	wx_RegKey *pEntity = new wx_RegKey(strKey);
	Object_wx_RegKey *pObj = Object_wx_RegKey::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RegKey(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(RegKey_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RegKey));
	DeclareArg(env, "keyParent", VTYPE_wx_RegKey, OCCUR_Once);
	DeclareArg(env, "strKey", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegKey_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxRegKey *keyParent = Object_wx_RegKey::GetObject(args, 0)->GetEntity();
	wxString strKey = wxString::FromUTF8(args.GetString(1));
	wx_RegKey *pEntity = new wx_RegKey(*keyParent, strKey);
	Object_wx_RegKey *pObj = Object_wx_RegKey::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RegKey(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_RegKey, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegKey, Close)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegKey, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bOkIfExists", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool bOkIfExists = true;
	if (args.IsValid(0)) bOkIfExists = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Create(bOkIfExists);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, DeleteSelf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegKey, DeleteSelf)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->DeleteSelf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegKey, DeleteKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "szKey", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegKey, DeleteKey)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString szKey = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->DeleteKey(szKey);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegKey, DeleteValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "szKey", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegKey, DeleteValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString szKey = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->DeleteValue(szKey);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_RegKey, Exists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_RegKey, Exists)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	bool rtn = wxRegKey::Exists();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegKey, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bShortPrefix", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool bShortPrefix = true;
	if (args.IsValid(0)) bShortPrefix = args.GetBoolean(0);
	wxString rtn = pThis->GetEntity()->GetName(bShortPrefix);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RegKey, GetFirstKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "strKeyName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "lIndex", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, GetFirstKey)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString strKeyName = wxString::FromUTF8(args.GetString(0));
	long lIndex = args.GetLong(1);
	bool rtn = pThis->GetEntity()->GetFirstKey(strKeyName, lIndex);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, GetFirstValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "strValueName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "lIndex", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, GetFirstValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString strValueName = wxString::FromUTF8(args.GetString(0));
	long lIndex = args.GetLong(1);
	bool rtn = pThis->GetEntity()->GetFirstValue(strValueName, lIndex);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, Exists_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pnSubKeys", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pnValues", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pnMaxValueLen", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, Exists_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pnSubKeys = args.GetSizeT(0);
	size_t pnValues = args.GetSizeT(1);
	size_t pnMaxValueLen = args.GetSizeT(2);
	bool rtn = pThis->GetEntity()->Exists(pnSubKeys, pnValues, pnMaxValueLen);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegKey, GetNextKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "strKeyName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "lIndex", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, GetNextKey)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString strKeyName = wxString::FromUTF8(args.GetString(0));
	long lIndex = args.GetLong(1);
	bool rtn = pThis->GetEntity()->GetNextKey(strKeyName, lIndex);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, GetNextValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "strValueName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "lIndex", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, GetNextValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString strValueName = wxString::FromUTF8(args.GetString(0));
	long lIndex = args.GetLong(1);
	bool rtn = pThis->GetEntity()->GetNextValue(strValueName, lIndex);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, HasValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "szValue", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, HasValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString szValue = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->HasValue(szValue);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, HasValues)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, HasValues)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasValues();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, HasSubKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "szKey", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, HasSubKey)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString szKey = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->HasSubKey(szKey);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, HasSubKeys)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, HasSubKeys)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasSubKeys();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegKey, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsEmpty();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, IsOpened)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, IsOpened)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOpened();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, Open)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, Open)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRegKey::AccessMode mode = Write;
	if (args.IsValid(0)) mode = static_cast<wxRegKey::AccessMode>(args.GetInt(0));
	bool rtn = pThis->GetEntity()->Open(mode);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegKey, QueryValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "szValue", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "strValue", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, QueryValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString szValue = wxString::FromUTF8(args.GetString(0));
	wxString strValue = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->QueryValue(szValue, strValue);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, QueryValue_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "szValue", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "plValue", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, QueryValue_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString szValue = wxString::FromUTF8(args.GetString(0));
	long plValue = args.GetLong(1);
	bool rtn = pThis->GetEntity()->QueryValue(szValue, plValue);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegKey, Rename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "szNewName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, Rename)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString szNewName = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Rename(szNewName);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, RenameValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "szValueOld", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "szValueNew", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, RenameValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString szValueOld = wxString::FromUTF8(args.GetString(0));
	wxString szValueNew = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->RenameValue(szValueOld, szValueNew);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "szValue", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "lValue", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString szValue = wxString::FromUTF8(args.GetString(0));
	long lValue = args.GetLong(1);
	bool rtn = pThis->GetEntity()->SetValue(szValue, lValue);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, SetValue_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "szValue", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "strValue", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, SetValue_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString szValue = wxString::FromUTF8(args.GetString(0));
	wxString strValue = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->SetValue(szValue, strValue);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegKey, SetValue_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "szValue", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "buf", VTYPE_wx_MemoryBuffer, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegKey, SetValue_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString szValue = wxString::FromUTF8(args.GetString(0));
	wxMemoryBuffer *buf = Object_wx_MemoryBuffer::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->SetValue(szValue, *buf);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxRegKey
//----------------------------------------------------------------------------
Object_wx_RegKey::~Object_wx_RegKey()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_RegKey::Clone() const
{
	return nullptr;
}

String Object_wx_RegKey::ToString(bool exprFlag)
{
	String rtn("<wx.RegKey:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxRegKey
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RegKey)
{
	Gura_AssignFunction(RegKeyEmpty);
	Gura_AssignFunction(RegKey);
	Gura_AssignFunction(RegKey_1);
	Gura_AssignMethod(wx_RegKey, Close);
	Gura_AssignMethod(wx_RegKey, Create);
	Gura_AssignMethod(wx_RegKey, DeleteSelf);
	Gura_AssignMethod(wx_RegKey, DeleteKey);
	Gura_AssignMethod(wx_RegKey, DeleteValue);
	Gura_AssignMethod(wx_RegKey, Exists);
	Gura_AssignMethod(wx_RegKey, GetName);
	Gura_AssignMethod(wx_RegKey, GetFirstKey);
	Gura_AssignMethod(wx_RegKey, GetFirstValue);
	Gura_AssignMethod(wx_RegKey, Exists_1);
	Gura_AssignMethod(wx_RegKey, GetNextKey);
	Gura_AssignMethod(wx_RegKey, GetNextValue);
	Gura_AssignMethod(wx_RegKey, HasValue);
	Gura_AssignMethod(wx_RegKey, HasValues);
	Gura_AssignMethod(wx_RegKey, HasSubKey);
	Gura_AssignMethod(wx_RegKey, HasSubKeys);
	Gura_AssignMethod(wx_RegKey, IsEmpty);
	Gura_AssignMethod(wx_RegKey, IsOpened);
	Gura_AssignMethod(wx_RegKey, Open);
	Gura_AssignMethod(wx_RegKey, QueryValue);
	Gura_AssignMethod(wx_RegKey, QueryValue_1);
	Gura_AssignMethod(wx_RegKey, Rename);
	Gura_AssignMethod(wx_RegKey, RenameValue);
	Gura_AssignMethod(wx_RegKey, SetValue);
	Gura_AssignMethod(wx_RegKey, SetValue_1);
	Gura_AssignMethod(wx_RegKey, SetValue_2);
}

Gura_ImplementDescendantCreator(wx_RegKey)
{
	return new Object_wx_RegKey((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
