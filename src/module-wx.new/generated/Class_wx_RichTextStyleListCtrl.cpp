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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxRichTextStyleListCtrl, "wxRichTextStyleListCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleListCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextStyleListCtrl)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//wxRichTextStyleListCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRichTextStyleListCtrl_1, "wxRichTextStyleListCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleListCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextStyleListCtrl_1)
{
	//wxRichTextStyleListCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextStyleListCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, __Create)
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

Gura_DeclareMethodAlias(wx_RichTextStyleListCtrl, __GetRichTextCtrl, "GetRichTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, __GetRichTextCtrl)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleListCtrl, __GetStyleChoice, "GetStyleChoice")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, __GetStyleChoice)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleChoice();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleListCtrl, __GetStyleListBox, "GetStyleListBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, __GetStyleListBox)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleListBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleListCtrl, __GetStyleSheet, "GetStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, __GetStyleSheet)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleListCtrl, __GetStyleType, "GetStyleType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, __GetStyleType)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleListCtrl, __SetRichTextCtrl, "SetRichTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, __SetRichTextCtrl)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->SetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleListCtrl, __SetStyleSheet, "SetStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, __SetStyleSheet)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleListCtrl, __SetStyleType, "SetStyleType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, __SetStyleType)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleType = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleListCtrl, __UpdateStyles, "UpdateStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, __UpdateStyles)
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
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextStyleListCtrl);
	Gura_AssignFunction(__wxRichTextStyleListCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextStyleListCtrl, __Create);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, __GetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, __GetStyleChoice);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, __GetStyleListBox);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, __GetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, __GetStyleType);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, __SetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, __SetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, __SetStyleType);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, __UpdateStyles);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleListCtrl)
{
	return new Object_wx_RichTextStyleListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
