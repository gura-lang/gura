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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Panel, "Panel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Panel));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Panel)
{
	//wxPanel();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Panel_1, "Panel_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Panel));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Panel_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//wxPanel();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Panel, __AcceptsFocus, "AcceptsFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, __AcceptsFocus)
{
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Panel, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Panel, __Create)
{
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Panel, __InitDialog, "InitDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, __InitDialog)
{
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->InitDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Panel, __Layout, "Layout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, __Layout)
{
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Panel, __OnSysColourChanged, "OnSysColourChanged")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Panel, __OnSysColourChanged)
{
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnSysColourChanged();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Panel, __SetFocus, "SetFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, __SetFocus)
{
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Panel, __SetFocusIgnoringChildren, "SetFocusIgnoringChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, __SetFocusIgnoringChildren)
{
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetFocusIgnoringChildren();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPanel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Panel)
{
	// Constructor assignment
	Gura_AssignFunction(__Panel);
	Gura_AssignFunction(__Panel_1);
	// Method assignment
	Gura_AssignMethod(wx_Panel, __AcceptsFocus);
	Gura_AssignMethod(wx_Panel, __Create);
	Gura_AssignMethod(wx_Panel, __InitDialog);
	Gura_AssignMethod(wx_Panel, __Layout);
	Gura_AssignMethod(wx_Panel, __OnSysColourChanged);
	Gura_AssignMethod(wx_Panel, __SetFocus);
	Gura_AssignMethod(wx_Panel, __SetFocusIgnoringChildren);
}

Gura_ImplementDescendantCreator(wx_Panel)
{
	return new Object_wx_Panel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
