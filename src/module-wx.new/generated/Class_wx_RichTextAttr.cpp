//----------------------------------------------------------------------------
// wxRichTextAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextAttr
//----------------------------------------------------------------------------
Object_wx_RichTextAttr::~Object_wx_RichTextAttr()
{
}

Object *Object_wx_RichTextAttr::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextAttr::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextAttr:");
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
Gura_DeclareMethod(wx_RichTextAttr, wxRichTextAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, wxRichTextAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAttr, wxRichTextAttr_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAttr, wxRichTextAttr_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAttr, wxRichTextAttr_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAttr, wxRichTextAttr_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAttr, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAttr, operator=)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, operator=)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->operator=();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAttr, operator=_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, operator=_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->operator=();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAttr, EqPartial)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, EqPartial)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAttr, Apply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, Apply)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAttr, CollectCommonAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, CollectCommonAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int clashingAttr = arg.GetNumber(1)
	//int absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAttr, RemoveStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, RemoveStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAttr, GetTextBoxAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAttr, GetTextBoxAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextBoxAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAttr, GetTextBoxAttr_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAttr, GetTextBoxAttr_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextBoxAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAttr, SetTextBoxAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetTextBoxAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextBoxAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAttr, IsDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAttr, IsDefault)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextAttr *pThis = Object_wx_RichTextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsDefault();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextAttr)
{
	Gura_AssignMethod(wx_RichTextAttr, wxRichTextAttr);
	Gura_AssignMethod(wx_RichTextAttr, wxRichTextAttr_1);
	Gura_AssignMethod(wx_RichTextAttr, wxRichTextAttr_2);
	Gura_AssignMethod(wx_RichTextAttr, Copy);
	Gura_AssignMethod(wx_RichTextAttr, operator=);
	Gura_AssignMethod(wx_RichTextAttr, operator=_1);
	Gura_AssignMethod(wx_RichTextAttr, EqPartial);
	Gura_AssignMethod(wx_RichTextAttr, Apply);
	Gura_AssignMethod(wx_RichTextAttr, CollectCommonAttributes);
	Gura_AssignMethod(wx_RichTextAttr, RemoveStyle);
	Gura_AssignMethod(wx_RichTextAttr, GetTextBoxAttr);
	Gura_AssignMethod(wx_RichTextAttr, GetTextBoxAttr_1);
	Gura_AssignMethod(wx_RichTextAttr, SetTextBoxAttr);
	Gura_AssignMethod(wx_RichTextAttr, IsDefault);
}

Gura_ImplementDescendantCreator(wx_RichTextAttr)
{
	return new Object_wx_RichTextAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
