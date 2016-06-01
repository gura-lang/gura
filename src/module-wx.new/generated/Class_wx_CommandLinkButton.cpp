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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_CommandLinkButton, wxCommandLinkButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandLinkButton, wxCommandLinkButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxCommandLinkButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandLinkButton, wxCommandLinkButton_1)
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

Gura_ImplementMethod(wx_CommandLinkButton, wxCommandLinkButton_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int mainLabel = arg.GetNumber(2)
	//int note = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int size = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->wxCommandLinkButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandLinkButton, Create)
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

Gura_ImplementMethod(wx_CommandLinkButton, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_CommandLinkButton, SetMainLabelAndNote)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mainLabel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "note", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandLinkButton, SetMainLabelAndNote)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mainLabel = arg.GetNumber(0)
	//int note = arg.GetNumber(1)
	//pThis->GetEntity()->SetMainLabelAndNote();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandLinkButton, SetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandLinkButton, SetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->SetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandLinkButton, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandLinkButton, GetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandLinkButton, SetMainLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mainLabel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandLinkButton, SetMainLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mainLabel = arg.GetNumber(0)
	//pThis->GetEntity()->SetMainLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandLinkButton, SetNote)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "note", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandLinkButton, SetNote)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int note = arg.GetNumber(0)
	//pThis->GetEntity()->SetNote();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandLinkButton, GetMainLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandLinkButton, GetMainLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMainLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandLinkButton, GetNote)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandLinkButton, GetNote)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandLinkButton *pThis = Object_wx_CommandLinkButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNote();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCommandLinkButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CommandLinkButton)
{
	Gura_AssignMethod(wx_CommandLinkButton, wxCommandLinkButton);
	Gura_AssignMethod(wx_CommandLinkButton, wxCommandLinkButton_1);
	Gura_AssignMethod(wx_CommandLinkButton, Create);
	Gura_AssignMethod(wx_CommandLinkButton, SetMainLabelAndNote);
	Gura_AssignMethod(wx_CommandLinkButton, SetLabel);
	Gura_AssignMethod(wx_CommandLinkButton, GetLabel);
	Gura_AssignMethod(wx_CommandLinkButton, SetMainLabel);
	Gura_AssignMethod(wx_CommandLinkButton, SetNote);
	Gura_AssignMethod(wx_CommandLinkButton, GetMainLabel);
	Gura_AssignMethod(wx_CommandLinkButton, GetNote);
}

Gura_ImplementDescendantCreator(wx_CommandLinkButton)
{
	return new Object_wx_CommandLinkButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
