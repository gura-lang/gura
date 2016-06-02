//----------------------------------------------------------------------------
// wxRichTextStyleComboCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleComboCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleComboCtrl
//----------------------------------------------------------------------------
Object_wx_RichTextStyleComboCtrl::~Object_wx_RichTextStyleComboCtrl()
{
}

Object *Object_wx_RichTextStyleComboCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStyleComboCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleComboCtrl:");
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
Gura_DeclareMethod(wx_RichTextStyleComboCtrl, wxRichTextStyleComboCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, wxRichTextStyleComboCtrl)
{
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->wxRichTextStyleComboCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, wxRichTextStyleComboCtrl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, wxRichTextStyleComboCtrl_1)
{
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextStyleComboCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, Create)
{
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, GetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, GetRichTextCtrl)
{
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, GetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, GetStyleSheet)
{
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, SetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, SetRichTextCtrl)
{
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->SetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, SetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, SetStyleSheet)
{
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, UpdateStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, UpdateStyles)
{
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UpdateStyles();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextStyleComboCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleComboCtrl)
{
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, wxRichTextStyleComboCtrl);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, wxRichTextStyleComboCtrl_1);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, Create);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, GetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, GetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, SetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, SetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, UpdateStyles);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleComboCtrl)
{
	return new Object_wx_RichTextStyleComboCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
