//----------------------------------------------------------------------------
// wxDataViewItemAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewItemAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewItemAttr
//----------------------------------------------------------------------------
Object_wx_DataViewItemAttr::~Object_wx_DataViewItemAttr()
{
}

Object *Object_wx_DataViewItemAttr::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewItemAttr::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewItemAttr:");
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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DataViewItemAttr, wxDataViewItemAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, wxDataViewItemAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDataViewItemAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItemAttr, SetBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewItemAttr, SetBold)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int set = arg.GetNumber(0)
	//pThis->GetEntity()->SetBold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItemAttr, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewItemAttr, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItemAttr, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewItemAttr, SetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItemAttr, SetItalic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewItemAttr, SetItalic)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int set = arg.GetNumber(0)
	//pThis->GetEntity()->SetItalic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItemAttr, HasColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, HasColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItemAttr, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, GetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItemAttr, HasFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, HasFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItemAttr, GetBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, GetBold)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItemAttr, GetItalic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, GetItalic)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetItalic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItemAttr, HasBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, HasBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItemAttr, GetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, GetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItemAttr, IsDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, IsDefault)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsDefault();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItemAttr, GetEffectiveFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewItemAttr, GetEffectiveFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->GetEffectiveFont();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewItemAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewItemAttr)
{
	Gura_AssignMethod(wx_DataViewItemAttr, wxDataViewItemAttr);
	Gura_AssignMethod(wx_DataViewItemAttr, SetBold);
	Gura_AssignMethod(wx_DataViewItemAttr, SetColour);
	Gura_AssignMethod(wx_DataViewItemAttr, SetBackgroundColour);
	Gura_AssignMethod(wx_DataViewItemAttr, SetItalic);
	Gura_AssignMethod(wx_DataViewItemAttr, HasColour);
	Gura_AssignMethod(wx_DataViewItemAttr, GetColour);
	Gura_AssignMethod(wx_DataViewItemAttr, HasFont);
	Gura_AssignMethod(wx_DataViewItemAttr, GetBold);
	Gura_AssignMethod(wx_DataViewItemAttr, GetItalic);
	Gura_AssignMethod(wx_DataViewItemAttr, HasBackgroundColour);
	Gura_AssignMethod(wx_DataViewItemAttr, GetBackgroundColour);
	Gura_AssignMethod(wx_DataViewItemAttr, IsDefault);
	Gura_AssignMethod(wx_DataViewItemAttr, GetEffectiveFont);
}

Gura_ImplementDescendantCreator(wx_DataViewItemAttr)
{
	return new Object_wx_DataViewItemAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
