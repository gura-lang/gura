//----------------------------------------------------------------------------
// wxCommandLinkButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCommandLinkButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCommandLinkButton
//----------------------------------------------------------------------------
Object_wx_CommandLinkButton::~Object_wx_CommandLinkButton()
{
}

Object *Object_wx_CommandLinkButton::Clone() const
{
	return nullptr;
}

String Object_wx_CommandLinkButton::ToString(bool exprFlag)
{
	String rtn("<wx.CommandLinkButton:");
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
Gura_DeclareFunctionAlias(__wxCommandLinkButton, "wxCommandLinkButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CommandLinkButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxCommandLinkButton)
{
	//wxCommandLinkButton();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxCommandLinkButton_1, "wxCommandLinkButton_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mainLabel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "note", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CommandLinkButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxCommandLinkButton_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int mainLabel = arg.GetNumber(2)
	//int note = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int size = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//wxCommandLinkButton();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CommandLinkButton, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mainLabel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "note", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandLinkButton, __Create)
{
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int mainLabel = arg.GetNumber(2)
	//int note = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int size = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandLinkButton, __SetMainLabelAndNote, "SetMainLabelAndNote")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mainLabel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "note", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandLinkButton, __SetMainLabelAndNote)
{
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mainLabel = arg.GetNumber(0)
	//int note = arg.GetNumber(1)
	//pThis->GetEntity()->SetMainLabelAndNote();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandLinkButton, __SetLabel, "SetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandLinkButton, __SetLabel)
{
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->SetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandLinkButton, __GetLabel, "GetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandLinkButton, __GetLabel)
{
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandLinkButton, __SetMainLabel, "SetMainLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mainLabel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandLinkButton, __SetMainLabel)
{
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mainLabel = arg.GetNumber(0)
	//pThis->GetEntity()->SetMainLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandLinkButton, __SetNote, "SetNote")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "note", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandLinkButton, __SetNote)
{
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int note = arg.GetNumber(0)
	//pThis->GetEntity()->SetNote();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandLinkButton, __GetMainLabel, "GetMainLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandLinkButton, __GetMainLabel)
{
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMainLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandLinkButton, __GetNote, "GetNote")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandLinkButton, __GetNote)
{
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNote();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCommandLinkButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CommandLinkButton)
{
	// Constructor assignment
	Gura_AssignFunction(__wxCommandLinkButton);
	Gura_AssignFunction(__wxCommandLinkButton_1);
	// Method assignment
	Gura_AssignMethod(wx_CommandLinkButton, __Create);
	Gura_AssignMethod(wx_CommandLinkButton, __SetMainLabelAndNote);
	Gura_AssignMethod(wx_CommandLinkButton, __SetLabel);
	Gura_AssignMethod(wx_CommandLinkButton, __GetLabel);
	Gura_AssignMethod(wx_CommandLinkButton, __SetMainLabel);
	Gura_AssignMethod(wx_CommandLinkButton, __SetNote);
	Gura_AssignMethod(wx_CommandLinkButton, __GetMainLabel);
	Gura_AssignMethod(wx_CommandLinkButton, __GetNote);
}

Gura_ImplementDescendantCreator(wx_CommandLinkButton)
{
	return new Object_wx_CommandLinkButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
