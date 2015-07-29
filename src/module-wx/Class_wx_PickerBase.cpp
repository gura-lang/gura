//----------------------------------------------------------------------------
// wxPickerBase
// extracted from pickerbase.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PickerBase: public wxPickerBase, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PickerBase *_pObj;
public:
	~wx_PickerBase();
	inline void AssocWithGura(Object_wx_PickerBase *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PickerBase::~wx_PickerBase()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PickerBase::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPickerBase
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_PickerBase, SetInternalMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, SetInternalMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int margin = args.GetInt(0);
	pThis->GetEntity()->SetInternalMargin(margin);
	return Value::Null;
}

Gura_DeclareMethod(wx_PickerBase, GetInternalMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, GetInternalMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetInternalMargin();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_PickerBase, SetTextCtrlProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, SetTextCtrlProportion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int prop = args.GetInt(0);
	pThis->GetEntity()->SetTextCtrlProportion(prop);
	return Value::Null;
}

Gura_DeclareMethod(wx_PickerBase, SetPickerCtrlProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, SetPickerCtrlProportion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int prop = args.GetInt(0);
	pThis->GetEntity()->SetPickerCtrlProportion(prop);
	return Value::Null;
}

Gura_DeclareMethod(wx_PickerBase, GetTextCtrlProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, GetTextCtrlProportion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetTextCtrlProportion();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_PickerBase, GetPickerCtrlProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, GetPickerCtrlProportion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetPickerCtrlProportion();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_PickerBase, HasTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, HasTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasTextCtrl();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_PickerBase, GetTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, GetTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTextCtrl *rtn = (wxTextCtrl *)pThis->GetEntity()->GetTextCtrl();
	return ReturnValue(env, args, Value(new Object_wx_TextCtrl(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_PickerBase, IsTextCtrlGrowable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, IsTextCtrlGrowable)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsTextCtrlGrowable();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_PickerBase, SetPickerCtrlGrowable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "grow", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, SetPickerCtrlGrowable)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool grow = true;
	if (args.IsValid(0)) grow = args.GetBoolean(0);
	pThis->GetEntity()->SetPickerCtrlGrowable(grow);
	return Value::Null;
}

Gura_DeclareMethod(wx_PickerBase, SetTextCtrlGrowable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "grow", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, SetTextCtrlGrowable)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool grow = true;
	if (args.IsValid(0)) grow = args.GetBoolean(0);
	pThis->GetEntity()->SetTextCtrlGrowable(grow);
	return Value::Null;
}

Gura_DeclareMethod(wx_PickerBase, IsPickerCtrlGrowable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, IsPickerCtrlGrowable)
{
	Signal &sig = env.GetSignal();
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsPickerCtrlGrowable();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxPickerBase
//----------------------------------------------------------------------------
Object_wx_PickerBase::~Object_wx_PickerBase()
{
}

Object *Object_wx_PickerBase::Clone() const
{
	return nullptr;
}

String Object_wx_PickerBase::ToString(bool exprFlag)
{
	String rtn("<wx.PickerBase:");
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
// Class implementation for wxPickerBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PickerBase)
{
	Gura_AssignMethod(wx_PickerBase, SetInternalMargin);
	Gura_AssignMethod(wx_PickerBase, GetInternalMargin);
	Gura_AssignMethod(wx_PickerBase, SetTextCtrlProportion);
	Gura_AssignMethod(wx_PickerBase, SetPickerCtrlProportion);
	Gura_AssignMethod(wx_PickerBase, GetTextCtrlProportion);
	Gura_AssignMethod(wx_PickerBase, GetPickerCtrlProportion);
	Gura_AssignMethod(wx_PickerBase, HasTextCtrl);
	Gura_AssignMethod(wx_PickerBase, GetTextCtrl);
	Gura_AssignMethod(wx_PickerBase, IsTextCtrlGrowable);
	Gura_AssignMethod(wx_PickerBase, SetPickerCtrlGrowable);
	Gura_AssignMethod(wx_PickerBase, SetTextCtrlGrowable);
	Gura_AssignMethod(wx_PickerBase, IsPickerCtrlGrowable);
}

Gura_ImplementDescendantCreator(wx_PickerBase)
{
	return new Object_wx_PickerBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
