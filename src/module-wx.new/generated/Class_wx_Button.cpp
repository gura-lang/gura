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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Button, wxButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Button, wxButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Button, wxButton_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Button, wxButton_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Button, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Button, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Button, GetAuthNeeded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Button, GetAuthNeeded)
{
	Signal &sig = env.GetSignal();
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAuthNeeded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Button, GetDefaultSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Button, GetDefaultSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Button, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Button, GetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Button, SetAuthNeeded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "needed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Button, SetAuthNeeded)
{
	Signal &sig = env.GetSignal();
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int needed = arg.GetNumber(0)
	//pThis->GetEntity()->SetAuthNeeded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Button, SetDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Button, SetDefault)
{
	Signal &sig = env.GetSignal();
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SetDefault();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Button, SetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Button, SetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Button *pThis = Object_wx_Button::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->SetLabel();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Button)
{
	Gura_AssignMethod(wx_Button, wxButton);
	Gura_AssignMethod(wx_Button, wxButton_1);
	Gura_AssignMethod(wx_Button, Create);
	Gura_AssignMethod(wx_Button, GetAuthNeeded);
	Gura_AssignMethod(wx_Button, GetDefaultSize);
	Gura_AssignMethod(wx_Button, GetLabel);
	Gura_AssignMethod(wx_Button, SetAuthNeeded);
	Gura_AssignMethod(wx_Button, SetDefault);
	Gura_AssignMethod(wx_Button, SetLabel);
}

Gura_ImplementDescendantCreator(wx_Button)
{
	return new Object_wx_Button((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
