//----------------------------------------------------------------------------
// wxPanel
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPanel
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPanel
//----------------------------------------------------------------------------
Object_wx_Panel::~Object_wx_Panel()
{
}

Object *Object_wx_Panel::Clone() const
{
	return nullptr;
}

String Object_wx_Panel::ToString(bool exprFlag)
{
	String rtn("<wx.Panel:");
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
Gura_DeclareMethod(wx_Panel, wxPanel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, wxPanel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPanel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Panel, wxPanel_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Panel, wxPanel_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxPanel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Panel, ~wxPanel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, ~wxPanel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPanel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Panel, AcceptsFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, AcceptsFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Panel, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Panel, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Panel, InitDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, InitDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->InitDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Panel, Layout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, Layout)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Panel, OnSysColourChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Panel, OnSysColourChanged)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnSysColourChanged();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Panel, SetFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, SetFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SetFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Panel, SetFocusIgnoringChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, SetFocusIgnoringChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SetFocusIgnoringChildren();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPanel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Panel)
{
	Gura_AssignMethod(wx_Panel, wxPanel);
	Gura_AssignMethod(wx_Panel, wxPanel_1);
	Gura_AssignMethod(wx_Panel, ~wxPanel);
	Gura_AssignMethod(wx_Panel, AcceptsFocus);
	Gura_AssignMethod(wx_Panel, Create);
	Gura_AssignMethod(wx_Panel, InitDialog);
	Gura_AssignMethod(wx_Panel, Layout);
	Gura_AssignMethod(wx_Panel, OnSysColourChanged);
	Gura_AssignMethod(wx_Panel, SetFocus);
	Gura_AssignMethod(wx_Panel, SetFocusIgnoringChildren);
}

Gura_ImplementDescendantCreator(wx_Panel)
{
	return new Object_wx_Panel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
