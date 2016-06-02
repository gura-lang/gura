//----------------------------------------------------------------------------
// wxRichTextStyleListCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleListCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleListCtrl
//----------------------------------------------------------------------------
Object_wx_RichTextStyleListCtrl::~Object_wx_RichTextStyleListCtrl()
{
}

Object *Object_wx_RichTextStyleListCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStyleListCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleListCtrl:");
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
Gura_DeclareMethod(wx_RichTextStyleListCtrl, wxRichTextStyleListCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, wxRichTextStyleListCtrl)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->wxRichTextStyleListCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, wxRichTextStyleListCtrl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, wxRichTextStyleListCtrl_1)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextStyleListCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, Create)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetRichTextCtrl)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetStyleChoice)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetStyleChoice)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleChoice();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetStyleListBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetStyleListBox)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleListBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetStyleSheet)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetStyleType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetStyleType)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, SetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, SetRichTextCtrl)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->SetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, SetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, SetStyleSheet)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, SetStyleType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, SetStyleType)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleType = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, UpdateStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, UpdateStyles)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UpdateStyles();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextStyleListCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleListCtrl)
{
	Gura_AssignMethod(wx_RichTextStyleListCtrl, wxRichTextStyleListCtrl);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, wxRichTextStyleListCtrl_1);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, Create);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, GetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, GetStyleChoice);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, GetStyleListBox);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, GetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, GetStyleType);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, SetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, SetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, SetStyleType);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, UpdateStyles);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleListCtrl)
{
	return new Object_wx_RichTextStyleListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
