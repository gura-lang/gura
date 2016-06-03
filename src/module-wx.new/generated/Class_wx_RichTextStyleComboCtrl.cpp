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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxRichTextStyleComboCtrl, "wxRichTextStyleComboCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleComboCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextStyleComboCtrl)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//wxRichTextStyleComboCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRichTextStyleComboCtrl_1, "wxRichTextStyleComboCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleComboCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextStyleComboCtrl_1)
{
	//wxRichTextStyleComboCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextStyleComboCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, __Create)
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

Gura_DeclareMethodAlias(wx_RichTextStyleComboCtrl, __GetRichTextCtrl, "GetRichTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, __GetRichTextCtrl)
{
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleComboCtrl, __GetStyleSheet, "GetStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, __GetStyleSheet)
{
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleComboCtrl, __SetRichTextCtrl, "SetRichTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, __SetRichTextCtrl)
{
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->SetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleComboCtrl, __SetStyleSheet, "SetStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, __SetStyleSheet)
{
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleComboCtrl, __UpdateStyles, "UpdateStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, __UpdateStyles)
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
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextStyleComboCtrl);
	Gura_AssignFunction(__wxRichTextStyleComboCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, __Create);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, __GetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, __GetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, __SetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, __SetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, __UpdateStyles);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleComboCtrl)
{
	return new Object_wx_RichTextStyleComboCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
