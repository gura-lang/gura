//----------------------------------------------------------------------------
// wxSystemOptions
// extracted from sysopt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SystemOptions: public wxSystemOptions, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SystemOptions *_pObj;
public:
	inline wx_SystemOptions() : wxSystemOptions(), _pObj(nullptr) {}
	~wx_SystemOptions();
	inline void AssocWithGura(Object_wx_SystemOptions *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SystemOptions::~wx_SystemOptions()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SystemOptions::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSystemOptions
//----------------------------------------------------------------------------
Gura_DeclareFunction(SystemOptions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SystemOptions));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SystemOptions)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_SystemOptions *pEntity = new wx_SystemOptions();
	Object_wx_SystemOptions *pObj = Object_wx_SystemOptions::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SystemOptions(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_SystemOptions, GetOption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SystemOptions, GetOption)
{
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->GetOption(name);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_SystemOptions, GetOptionInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SystemOptions, GetOptionInt)
{
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	int rtn = pThis->GetEntity()->GetOptionInt(name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SystemOptions, HasOption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SystemOptions, HasOption)
{
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->HasOption(name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SystemOptions, IsFalse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SystemOptions, IsFalse)
{
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->IsFalse(name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SystemOptions, SetOption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemOptions, SetOption)
{
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxString value = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetOption(name, value);
	return Value::Null;
}

Gura_DeclareMethod(wx_SystemOptions, SetOption_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemOptions, SetOption_1)
{
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	int value = args.GetInt(1);
	pThis->GetEntity()->SetOption(name, value);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxSystemOptions
//----------------------------------------------------------------------------
Object_wx_SystemOptions::~Object_wx_SystemOptions()
{
}

Object *Object_wx_SystemOptions::Clone() const
{
	return nullptr;
}

String Object_wx_SystemOptions::ToString(bool exprFlag)
{
	String rtn("<wx.SystemOptions:");
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
// Class implementation for wxSystemOptions
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SystemOptions)
{
	Gura_AssignFunction(SystemOptions);
	Gura_AssignMethod(wx_SystemOptions, GetOption);
	Gura_AssignMethod(wx_SystemOptions, GetOptionInt);
	Gura_AssignMethod(wx_SystemOptions, HasOption);
	Gura_AssignMethod(wx_SystemOptions, IsFalse);
	Gura_AssignMethod(wx_SystemOptions, SetOption);
	Gura_AssignMethod(wx_SystemOptions, SetOption_1);
}

Gura_ImplementDescendantCreator(wx_SystemOptions)
{
	return new Object_wx_SystemOptions((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
