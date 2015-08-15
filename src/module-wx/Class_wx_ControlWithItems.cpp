//----------------------------------------------------------------------------
// wxControlWithItems
// extracted from ctrlsub.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ControlWithItems: public wxControlWithItems, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ControlWithItems *_pObj;
public:
	~wx_ControlWithItems();
	inline void AssocWithGura(Object_wx_ControlWithItems *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ControlWithItems::~wx_ControlWithItems()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ControlWithItems::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxControlWithItems
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ControlWithItems, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "clientData", VTYPE_wx_ClientData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ControlWithItems, Append)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(args.GetString(0));
	int rtn = 0;
	if (args.IsValid(1)) {
		wx_ClientData *clientData = Object_wx_ClientData::GetObject(args, 1)->GetEntity();
		rtn = pThis->GetEntity()->Append(item, new wx_ClientData(*clientData));
	} else {
		rtn = pThis->GetEntity()->Append(item);
	}
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ControlWithItems, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ControlWithItems, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ControlWithItems, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ControlWithItems, Delete)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = args.GetInt(0);
	pThis->GetEntity()->Delete(n);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ControlWithItems, FindString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caseSensitive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ControlWithItems, FindString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString string = wxString::FromUTF8(args.GetString(0));
	bool caseSensitive = false;
	if (args.IsValid(1)) caseSensitive = args.GetBoolean(1);
	int rtn = pThis->GetEntity()->FindString(string, caseSensitive);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ControlWithItems, GetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ControlWithItems, GetClientData)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = args.GetInt(0);
	pThis->GetEntity()->GetClientData(n);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ControlWithItems, GetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ControlWithItems, GetClientObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = args.GetInt(0);
	wx_ClientData *rtn = dynamic_cast<wx_ClientData *>(pThis->GetEntity()->GetClientObject(n));
	if (rtn == nullptr) return Value::Nil;
	return ReturnValue(env, args, Value(new Object_wx_ClientData(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ControlWithItems, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ControlWithItems, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->GetCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ControlWithItems, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ControlWithItems, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ControlWithItems, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ControlWithItems, GetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetString(n);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ControlWithItems, GetStrings)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ControlWithItems, GetStrings)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArrayString rtn = pThis->GetEntity()->GetStrings();
	return ReturnValue(env, args, ArrayStringToValue(env, rtn));
}

Gura_DeclareMethod(wx_ControlWithItems, GetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ControlWithItems, GetStringSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetStringSelection();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ControlWithItems, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "clientData", VTYPE_wx_ClientData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ControlWithItems, Insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(args.GetString(0));
	unsigned pos = args.GetInt(1);
	int rtn = 0;
	if (args.IsValid(2)) {
		wx_ClientData *clientData = Object_wx_ClientData::GetObject(args, 2)->GetEntity();
		rtn = pThis->GetEntity()->Insert(item, pos, new wx_ClientData(clientData));
	} else {
		rtn = pThis->GetEntity()->Insert(item, pos);
	}
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ControlWithItems, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ControlWithItems, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsEmpty();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ControlWithItems, Select)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ControlWithItems, Select)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int n = args.GetInt(0);
	pThis->GetEntity()->Select(n);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ControlWithItems, SetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_wx_ClientData, OCCUR_Once);
}

Gura_ImplementMethod(wx_ControlWithItems, SetClientObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = args.GetInt(0);
	wx_ClientData *data = Object_wx_ClientData::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetClientObject(n, new wx_ClientData(*data));
	return Value::Nil;
}

Gura_DeclareMethod(wx_ControlWithItems, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ControlWithItems, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int n = args.GetInt(0);
	pThis->GetEntity()->SetSelection(n);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ControlWithItems, SetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ControlWithItems, SetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = args.GetInt(0);
	wxString string = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetString(n, string);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ControlWithItems, SetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ControlWithItems, SetStringSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ControlWithItems *pThis = Object_wx_ControlWithItems::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString string = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->SetStringSelection(string);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxControlWithItems
//----------------------------------------------------------------------------
Object_wx_ControlWithItems::~Object_wx_ControlWithItems()
{
}

Object *Object_wx_ControlWithItems::Clone() const
{
	return nullptr;
}

String Object_wx_ControlWithItems::ToString(bool exprFlag)
{
	String rtn("<wx.ControlWithItems:");
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
// Class implementation for wxControlWithItems
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ControlWithItems)
{
	Gura_AssignMethod(wx_ControlWithItems, Append);
	Gura_AssignMethod(wx_ControlWithItems, Clear);
	Gura_AssignMethod(wx_ControlWithItems, Delete);
	Gura_AssignMethod(wx_ControlWithItems, FindString);
	Gura_AssignMethod(wx_ControlWithItems, GetClientData);
	Gura_AssignMethod(wx_ControlWithItems, GetClientObject);
	Gura_AssignMethod(wx_ControlWithItems, GetCount);
	Gura_AssignMethod(wx_ControlWithItems, GetSelection);
	Gura_AssignMethod(wx_ControlWithItems, GetString);
	Gura_AssignMethod(wx_ControlWithItems, GetStrings);
	Gura_AssignMethod(wx_ControlWithItems, GetStringSelection);
	Gura_AssignMethod(wx_ControlWithItems, Insert);
	Gura_AssignMethod(wx_ControlWithItems, IsEmpty);
	Gura_AssignMethod(wx_ControlWithItems, Select);
	Gura_AssignMethod(wx_ControlWithItems, SetClientObject);
	Gura_AssignMethod(wx_ControlWithItems, SetSelection);
	Gura_AssignMethod(wx_ControlWithItems, SetString);
	Gura_AssignMethod(wx_ControlWithItems, SetStringSelection);
}

Gura_ImplementDescendantCreator(wx_ControlWithItems)
{
	return new Object_wx_ControlWithItems((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
