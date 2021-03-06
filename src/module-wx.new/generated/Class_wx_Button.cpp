//----------------------------------------------------------------------------
// wxButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxButton
//----------------------------------------------------------------------------
Object_wx_Button::~Object_wx_Button()
{
}

Object *Object_wx_Button::Clone() const
{
	return nullptr;
}

String Object_wx_Button::ToString(bool exprFlag)
{
	String rtn("<wx.Button:");
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
Gura_DeclareFunctionAlias(__Button, "Button")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Button));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Button)
{
	//wxButton();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Button_1, "Button_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Button));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Button_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxButton(parent, id, label, pos, size, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Button, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Button, __Create)
{
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, label, pos, size, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Button, __GetAuthNeeded, "GetAuthNeeded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Button, __GetAuthNeeded)
{
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetAuthNeeded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Button, __GetDefaultSize, "GetDefaultSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Button, __GetDefaultSize)
{
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize _rtn = pThis->GetEntity()->GetDefaultSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Button, __GetLabel, "GetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Button, __GetLabel)
{
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Button, __SetAuthNeeded, "SetAuthNeeded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "needed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Button, __SetAuthNeeded)
{
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool needed = arg.GetNumber(0)
	//pThis->GetEntity()->SetAuthNeeded(needed);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Button, __SetDefault, "SetDefault")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Button, __SetDefault)
{
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* _rtn = pThis->GetEntity()->SetDefault();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Button, __SetLabel, "SetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Button, __SetLabel)
{
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& label = arg.GetNumber(0)
	//pThis->GetEntity()->SetLabel(label);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Button)
{
	// Constructor assignment
	Gura_AssignFunction(__Button);
	Gura_AssignFunction(__Button_1);
	// Method assignment
	Gura_AssignMethod(wx_Button, __Create);
	Gura_AssignMethod(wx_Button, __GetAuthNeeded);
	Gura_AssignMethod(wx_Button, __GetDefaultSize);
	Gura_AssignMethod(wx_Button, __GetLabel);
	Gura_AssignMethod(wx_Button, __SetAuthNeeded);
	Gura_AssignMethod(wx_Button, __SetDefault);
	Gura_AssignMethod(wx_Button, __SetLabel);
}

Gura_ImplementDescendantCreator(wx_Button)
{
	return new Object_wx_Button((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
