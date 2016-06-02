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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Caret, wxCaret)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, wxCaret)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxCaret();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, wxCaret_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, wxCaret_1)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//pThis->GetEntity()->wxCaret();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, wxCaret_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, wxCaret_2)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->wxCaret();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, Create)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, Create_1)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, GetBlinkTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, GetBlinkTime)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBlinkTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, GetPosition)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, GetPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, GetPosition_1)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, GetSize)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, GetSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, GetSize_1)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, GetWindow)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, Hide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, Hide)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, IsOk)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, IsVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, IsVisible)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, Move)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, Move)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->Move();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, Move_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, Move_1)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Move();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, SetBlinkTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, SetBlinkTime)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int milliseconds = arg.GetNumber(0)
	//pThis->GetEntity()->SetBlinkTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, SetSize)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, SetSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, SetSize_1)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Caret, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, Show)
{
	Object_wx_Caret *pThis = Object_wx_Caret::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCaret
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Caret)
{
	Gura_AssignMethod(wx_Caret, wxCaret);
	Gura_AssignMethod(wx_Caret, wxCaret_1);
	Gura_AssignMethod(wx_Caret, wxCaret_2);
	Gura_AssignMethod(wx_Caret, Create);
	Gura_AssignMethod(wx_Caret, Create_1);
	Gura_AssignMethod(wx_Caret, GetBlinkTime);
	Gura_AssignMethod(wx_Caret, GetPosition);
	Gura_AssignMethod(wx_Caret, GetPosition_1);
	Gura_AssignMethod(wx_Caret, GetSize);
	Gura_AssignMethod(wx_Caret, GetSize_1);
	Gura_AssignMethod(wx_Caret, GetWindow);
	Gura_AssignMethod(wx_Caret, Hide);
	Gura_AssignMethod(wx_Caret, IsOk);
	Gura_AssignMethod(wx_Caret, IsVisible);
	Gura_AssignMethod(wx_Caret, Move);
	Gura_AssignMethod(wx_Caret, Move_1);
	Gura_AssignMethod(wx_Caret, SetBlinkTime);
	Gura_AssignMethod(wx_Caret, SetSize);
	Gura_AssignMethod(wx_Caret, SetSize_1);
	Gura_AssignMethod(wx_Caret, Show);
}

Gura_ImplementDescendantCreator(wx_Caret)
{
	return new Object_wx_Caret((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
