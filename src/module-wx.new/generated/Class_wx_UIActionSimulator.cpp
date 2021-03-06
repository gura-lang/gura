//----------------------------------------------------------------------------
// wxUIActionSimulator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxUIActionSimulator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxUIActionSimulator
//----------------------------------------------------------------------------
Object_wx_UIActionSimulator::~Object_wx_UIActionSimulator()
{
}

Object *Object_wx_UIActionSimulator::Clone() const
{
	return nullptr;
}

String Object_wx_UIActionSimulator::ToString(bool exprFlag)
{
	String rtn("<wx.UIActionSimulator:");
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
Gura_DeclareFunctionAlias(__UIActionSimulator, "UIActionSimulator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_UIActionSimulator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UIActionSimulator)
{
	//wxUIActionSimulator();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_UIActionSimulator, __MouseMove, "MouseMove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UIActionSimulator, __MouseMove)
{
	Object_wx_UIActionSimulator *pThis = Object_wx_UIActionSimulator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long x = arg.GetNumber(0)
	//long y = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->MouseMove(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UIActionSimulator, __MouseMove_1, "MouseMove_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UIActionSimulator, __MouseMove_1)
{
	Object_wx_UIActionSimulator *pThis = Object_wx_UIActionSimulator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& point = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->MouseMove(point);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UIActionSimulator, __MouseDown, "MouseDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UIActionSimulator, __MouseDown)
{
	Object_wx_UIActionSimulator *pThis = Object_wx_UIActionSimulator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->MouseDown(button);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UIActionSimulator, __MouseUp, "MouseUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UIActionSimulator, __MouseUp)
{
	Object_wx_UIActionSimulator *pThis = Object_wx_UIActionSimulator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->MouseUp(button);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UIActionSimulator, __MouseClick, "MouseClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UIActionSimulator, __MouseClick)
{
	Object_wx_UIActionSimulator *pThis = Object_wx_UIActionSimulator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->MouseClick(button);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UIActionSimulator, __MouseDblClick, "MouseDblClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UIActionSimulator, __MouseDblClick)
{
	Object_wx_UIActionSimulator *pThis = Object_wx_UIActionSimulator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->MouseDblClick(button);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UIActionSimulator, __MouseDragDrop, "MouseDragDrop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UIActionSimulator, __MouseDragDrop)
{
	Object_wx_UIActionSimulator *pThis = Object_wx_UIActionSimulator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long x1 = arg.GetNumber(0)
	//long y1 = arg.GetNumber(1)
	//long x2 = arg.GetNumber(2)
	//long y2 = arg.GetNumber(3)
	//int button = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->MouseDragDrop(x1, y1, x2, y2, button);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UIActionSimulator, __KeyDown, "KeyDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "keycode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "modifiers", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UIActionSimulator, __KeyDown)
{
	Object_wx_UIActionSimulator *pThis = Object_wx_UIActionSimulator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int keycode = arg.GetNumber(0)
	//int modifiers = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->KeyDown(keycode, modifiers);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UIActionSimulator, __KeyUp, "KeyUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "keycode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "modifiers", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UIActionSimulator, __KeyUp)
{
	Object_wx_UIActionSimulator *pThis = Object_wx_UIActionSimulator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int keycode = arg.GetNumber(0)
	//int modifiers = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->KeyUp(keycode, modifiers);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UIActionSimulator, __Char, "Char")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "keycode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "modifiers", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UIActionSimulator, __Char)
{
	Object_wx_UIActionSimulator *pThis = Object_wx_UIActionSimulator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int keycode = arg.GetNumber(0)
	//int modifiers = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Char(keycode, modifiers);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UIActionSimulator, __Select, "Select")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UIActionSimulator, __Select)
{
	Object_wx_UIActionSimulator *pThis = Object_wx_UIActionSimulator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Select(text);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UIActionSimulator, __Text, "Text")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UIActionSimulator, __Text)
{
	Object_wx_UIActionSimulator *pThis = Object_wx_UIActionSimulator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Text(text);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxUIActionSimulator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_UIActionSimulator)
{
	// Constructor assignment
	Gura_AssignFunction(__UIActionSimulator);
	// Method assignment
	Gura_AssignMethod(wx_UIActionSimulator, __MouseMove);
	Gura_AssignMethod(wx_UIActionSimulator, __MouseMove_1);
	Gura_AssignMethod(wx_UIActionSimulator, __MouseDown);
	Gura_AssignMethod(wx_UIActionSimulator, __MouseUp);
	Gura_AssignMethod(wx_UIActionSimulator, __MouseClick);
	Gura_AssignMethod(wx_UIActionSimulator, __MouseDblClick);
	Gura_AssignMethod(wx_UIActionSimulator, __MouseDragDrop);
	Gura_AssignMethod(wx_UIActionSimulator, __KeyDown);
	Gura_AssignMethod(wx_UIActionSimulator, __KeyUp);
	Gura_AssignMethod(wx_UIActionSimulator, __Char);
	Gura_AssignMethod(wx_UIActionSimulator, __Select);
	Gura_AssignMethod(wx_UIActionSimulator, __Text);
}

Gura_ImplementDescendantCreator(wx_UIActionSimulator)
{
	return new Object_wx_UIActionSimulator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
