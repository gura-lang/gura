//----------------------------------------------------------------------------
// wxCaret
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCaret
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCaret
//----------------------------------------------------------------------------
Object_wx_Caret::~Object_wx_Caret()
{
}

Object *Object_wx_Caret::Clone() const
{
	return nullptr;
}

String Object_wx_Caret::ToString(bool exprFlag)
{
	String rtn("<wx.Caret:");
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
Gura_DeclareFunctionAlias(__Caret, "Caret")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Caret));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Caret)
{
	//wxCaret();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Caret_1, "Caret_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Caret));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Caret_1)
{
	//wxWindow* window = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//wxCaret(window, width, height);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Caret_2, "Caret_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Caret));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Caret_2)
{
	//wxWindow* window = arg.GetNumber(0)
	//const wxSize& size = arg.GetNumber(1)
	//wxCaret(window, size);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Caret, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, __Create)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//pThis->GetEntity()->Create(window, width, height);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __Create_1, "Create_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, __Create_1)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//const wxSize& size = arg.GetNumber(1)
	//pThis->GetEntity()->Create(window, size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __GetBlinkTime, "GetBlinkTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, __GetBlinkTime)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBlinkTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, __GetPosition)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int* x = arg.GetNumber(0)
	//int* y = arg.GetNumber(1)
	//pThis->GetEntity()->GetPosition(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __GetPosition_1, "GetPosition_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, __GetPosition_1)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, __GetSize)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int* width = arg.GetNumber(0)
	//int* height = arg.GetNumber(1)
	//pThis->GetEntity()->GetSize(width, height);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __GetSize_1, "GetSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, __GetSize_1)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __GetWindow, "GetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, __GetWindow)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __Hide, "Hide")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, __Hide)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, __IsOk)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __IsVisible, "IsVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, __IsVisible)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __Move, "Move")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, __Move)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->Move(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __Move_1, "Move_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, __Move_1)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//pThis->GetEntity()->Move(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __SetBlinkTime, "SetBlinkTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, __SetBlinkTime)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int milliseconds = arg.GetNumber(0)
	//pThis->GetEntity()->SetBlinkTime(milliseconds);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __SetSize, "SetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, __SetSize)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->SetSize(width, height);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __SetSize_1, "SetSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, __SetSize_1)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& size = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize(size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Caret, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, __Show)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool show = arg.GetNumber(0)
	//pThis->GetEntity()->Show(show);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCaret
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Caret)
{
	// Constructor assignment
	Gura_AssignFunction(__Caret);
	Gura_AssignFunction(__Caret_1);
	Gura_AssignFunction(__Caret_2);
	// Method assignment
	Gura_AssignMethod(wx_Caret, __Create);
	Gura_AssignMethod(wx_Caret, __Create_1);
	Gura_AssignMethod(wx_Caret, __GetBlinkTime);
	Gura_AssignMethod(wx_Caret, __GetPosition);
	Gura_AssignMethod(wx_Caret, __GetPosition_1);
	Gura_AssignMethod(wx_Caret, __GetSize);
	Gura_AssignMethod(wx_Caret, __GetSize_1);
	Gura_AssignMethod(wx_Caret, __GetWindow);
	Gura_AssignMethod(wx_Caret, __Hide);
	Gura_AssignMethod(wx_Caret, __IsOk);
	Gura_AssignMethod(wx_Caret, __IsVisible);
	Gura_AssignMethod(wx_Caret, __Move);
	Gura_AssignMethod(wx_Caret, __Move_1);
	Gura_AssignMethod(wx_Caret, __SetBlinkTime);
	Gura_AssignMethod(wx_Caret, __SetSize);
	Gura_AssignMethod(wx_Caret, __SetSize_1);
	Gura_AssignMethod(wx_Caret, __Show);
}

Gura_ImplementDescendantCreator(wx_Caret)
{
	return new Object_wx_Caret((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
