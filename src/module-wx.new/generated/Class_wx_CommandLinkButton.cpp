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
Gura_DeclareFunctionAlias(__CommandLinkButton, "CommandLinkButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CommandLinkButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CommandLinkButton)
{
	//wxCommandLinkButton();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CommandLinkButton_1, "CommandLinkButton_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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

Gura_ImplementFunction(__CommandLinkButton_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& mainLabel = arg.GetNumber(2)
	//const wxString& note = arg.GetNumber(3)
	//const wxPoint& pos = arg.GetNumber(4)
	//const wxSize& size = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//wxCommandLinkButton(parent, id, mainLabel, note, pos, size, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CommandLinkButton, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& mainLabel = arg.GetNumber(2)
	//const wxString& note = arg.GetNumber(3)
	//const wxPoint& pos = arg.GetNumber(4)
	//const wxSize& size = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, mainLabel, note, pos, size, style, validator, name);
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
	//const wxString& mainLabel = arg.GetNumber(0)
	//const wxString& note = arg.GetNumber(1)
	//pThis->GetEntity()->SetMainLabelAndNote(mainLabel, note);
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
	//const wxString& label = arg.GetNumber(0)
	//pThis->GetEntity()->SetLabel(label);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandLinkButton, __GetLabel, "GetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CommandLinkButton, __GetLabel)
{
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetLabel();
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
	//const wxString& mainLabel = arg.GetNumber(0)
	//pThis->GetEntity()->SetMainLabel(mainLabel);
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
	//const wxString& note = arg.GetNumber(0)
	//pThis->GetEntity()->SetNote(note);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandLinkButton, __GetMainLabel, "GetMainLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CommandLinkButton, __GetMainLabel)
{
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetMainLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandLinkButton, __GetNote, "GetNote")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CommandLinkButton, __GetNote)
{
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetNote();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCommandLinkButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CommandLinkButton)
{
	// Constructor assignment
	Gura_AssignFunction(__CommandLinkButton);
	Gura_AssignFunction(__CommandLinkButton_1);
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
