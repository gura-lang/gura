//----------------------------------------------------------------------------
// wxPickerBase
// extracted from pickerbase.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PickerBase: public wxPickerBase, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PickerBase *_pObj;
public:
	~wx_PickerBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PickerBase *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PickerBase::~wx_PickerBase()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PickerBase::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPickerBase
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_PickerBase, SetInternalMargin)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, SetInternalMargin)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int margin = args.GetInt(0);
	pThis->GetEntity()->SetInternalMargin(margin);
	return Value::Null;
}

Gura_DeclareMethod(wx_PickerBase, GetInternalMargin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, GetInternalMargin)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetInternalMargin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PickerBase, SetTextCtrlProportion)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, SetTextCtrlProportion)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int prop = args.GetInt(0);
	pThis->GetEntity()->SetTextCtrlProportion(prop);
	return Value::Null;
}

Gura_DeclareMethod(wx_PickerBase, SetPickerCtrlProportion)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PickerBase, SetPickerCtrlProportion)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int prop = args.GetInt(0);
	pThis->GetEntity()->SetPickerCtrlProportion(prop);
	return Value::Null;
}

Gura_DeclareMethod(wx_PickerBase, GetTextCtrlProportion)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, GetTextCtrlProportion)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetTextCtrlProportion();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PickerBase, GetPickerCtrlProportion)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, GetPickerCtrlProportion)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetPickerCtrlProportion();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PickerBase, HasTextCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, HasTextCtrl)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasTextCtrl();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PickerBase, GetTextCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, GetTextCtrl)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTextCtrl *rtn = (wxTextCtrl *)pThis->GetEntity()->GetTextCtrl();
	return ReturnValue(env, sig, args, Value(new Object_wx_TextCtrl(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_PickerBase, IsTextCtrlGrowable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, IsTextCtrlGrowable)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsTextCtrlGrowable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PickerBase, SetPickerCtrlGrowable)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "grow", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, SetPickerCtrlGrowable)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool grow = true;
	if (args.IsValid(0)) grow = args.GetBoolean(0);
	pThis->GetEntity()->SetPickerCtrlGrowable(grow);
	return Value::Null;
}

Gura_DeclareMethod(wx_PickerBase, SetTextCtrlGrowable)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "grow", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, SetTextCtrlGrowable)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool grow = true;
	if (args.IsValid(0)) grow = args.GetBoolean(0);
	pThis->GetEntity()->SetTextCtrlGrowable(grow);
	return Value::Null;
}

Gura_DeclareMethod(wx_PickerBase, IsPickerCtrlGrowable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PickerBase, IsPickerCtrlGrowable)
{
	Object_wx_PickerBase *pThis = Object_wx_PickerBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsPickerCtrlGrowable();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxPickerBase
//----------------------------------------------------------------------------
Object_wx_PickerBase::~Object_wx_PickerBase()
{
}

Object *Object_wx_PickerBase::Clone() const
{
	return NULL;
}

String Object_wx_PickerBase::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PickerBase:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PickerBase::DoAssignConstructor(Environment &env, Signal sig)
{
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
	return new Object_wx_PickerBase((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
