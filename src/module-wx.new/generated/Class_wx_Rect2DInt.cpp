//----------------------------------------------------------------------------
// wxRect2DInt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRect2DInt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRect2DInt
//----------------------------------------------------------------------------
Object_wx_Rect2DInt::~Object_wx_Rect2DInt()
{
}

Object *Object_wx_Rect2DInt::Clone() const
{
	return nullptr;
}

String Object_wx_Rect2DInt::ToString(bool exprFlag)
{
	String rtn("<wx.Rect2DInt:");
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
Gura_DeclareMethod(wx_Rect2DInt, wxRect2DInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, wxRect2DInt)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRect2DInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, wxRect2DInt_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, wxRect2DInt_1)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//pThis->GetEntity()->wxRect2DInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, wxRect2DInt_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, wxRect2DInt_2)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int w = arg.GetNumber(2)
	//int h = arg.GetNumber(3)
	//pThis->GetEntity()->wxRect2DInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, wxRect2DInt_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topLeft", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottomRight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, wxRect2DInt_3)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topLeft = arg.GetNumber(0)
	//int bottomRight = arg.GetNumber(1)
	//pThis->GetEntity()->wxRect2DInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, wxRect2DInt_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, wxRect2DInt_4)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->wxRect2DInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, wxRect2DInt_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, wxRect2DInt_5)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->wxRect2DInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, GetPosition)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, GetSize)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, GetLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, GetLeft)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, SetLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, SetLeft)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, MoveLeftTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, MoveLeftTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->MoveLeftTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, GetTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, GetTop)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, SetTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, SetTop)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, MoveTopTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, MoveTopTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->MoveTopTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, GetBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, GetBottom)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, SetBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, SetBottom)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, MoveBottomTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, MoveBottomTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->MoveBottomTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, GetRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, GetRight)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, SetRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, SetRight)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, MoveRightTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, MoveRightTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->MoveRightTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, GetLeftTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, GetLeftTop)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, SetLeftTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, SetLeftTop)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetLeftTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, MoveLeftTopTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, MoveLeftTopTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveLeftTopTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, GetLeftBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, GetLeftBottom)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, SetLeftBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, SetLeftBottom)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetLeftBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, MoveLeftBottomTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, MoveLeftBottomTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveLeftBottomTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, GetRightTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, GetRightTop)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, SetRightTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, SetRightTop)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetRightTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, MoveRightTopTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, MoveRightTopTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveRightTopTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, GetRightBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, GetRightBottom)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, SetRightBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, SetRightBottom)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetRightBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, MoveRightBottomTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, MoveRightBottomTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveRightBottomTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, GetCentre)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, GetCentre)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCentre();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, SetCentre)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, SetCentre)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetCentre();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, MoveCentreTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, MoveCentreTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveCentreTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, GetOutCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, GetOutCode)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetOutCode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, GetOutcode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, GetOutcode)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetOutcode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, Contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, Contains)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, Contains_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, Contains_1)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, IsEmpty)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, HaveEqualSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, HaveEqualSize)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->HaveEqualSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, Inset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, Inset)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->Inset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, Inset_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "top", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "right", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottom", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, Inset_1)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int left = arg.GetNumber(0)
	//int top = arg.GetNumber(1)
	//int right = arg.GetNumber(2)
	//int bottom = arg.GetNumber(3)
	//pThis->GetEntity()->Inset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, Offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, Offset)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Offset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, ConstrainTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, ConstrainTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->ConstrainTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, Interpolate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "widthfactor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "heightfactor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, Interpolate)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int widthfactor = arg.GetNumber(0)
	//int heightfactor = arg.GetNumber(1)
	//pThis->GetEntity()->Interpolate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, Intersect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "src2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, Intersect)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int src1 = arg.GetNumber(0)
	//int src2 = arg.GetNumber(1)
	//int dest = arg.GetNumber(2)
	//pThis->GetEntity()->Intersect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, Intersect_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, Intersect_1)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int otherRect = arg.GetNumber(0)
	//pThis->GetEntity()->Intersect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, CreateIntersection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, CreateIntersection)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int otherRect = arg.GetNumber(0)
	//pThis->GetEntity()->CreateIntersection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, Intersects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, Intersects)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Intersects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, Union)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "src2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, Union)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int src1 = arg.GetNumber(0)
	//int src2 = arg.GetNumber(1)
	//int dest = arg.GetNumber(2)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, Union_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, Union_1)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int otherRect = arg.GetNumber(0)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, Union_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, Union_2)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, CreateUnion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, CreateUnion)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int otherRect = arg.GetNumber(0)
	//pThis->GetEntity()->CreateUnion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, Scale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "f", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, Scale)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int f = arg.GetNumber(0)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DInt, Scale_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "num", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "denum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, Scale_1)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int num = arg.GetNumber(0)
	//int denum = arg.GetNumber(1)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRect2DInt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Rect2DInt)
{
	Gura_AssignMethod(wx_Rect2DInt, wxRect2DInt);
	Gura_AssignMethod(wx_Rect2DInt, wxRect2DInt_1);
	Gura_AssignMethod(wx_Rect2DInt, wxRect2DInt_2);
	Gura_AssignMethod(wx_Rect2DInt, wxRect2DInt_3);
	Gura_AssignMethod(wx_Rect2DInt, wxRect2DInt_4);
	Gura_AssignMethod(wx_Rect2DInt, wxRect2DInt_5);
	Gura_AssignMethod(wx_Rect2DInt, GetPosition);
	Gura_AssignMethod(wx_Rect2DInt, GetSize);
	Gura_AssignMethod(wx_Rect2DInt, GetLeft);
	Gura_AssignMethod(wx_Rect2DInt, SetLeft);
	Gura_AssignMethod(wx_Rect2DInt, MoveLeftTo);
	Gura_AssignMethod(wx_Rect2DInt, GetTop);
	Gura_AssignMethod(wx_Rect2DInt, SetTop);
	Gura_AssignMethod(wx_Rect2DInt, MoveTopTo);
	Gura_AssignMethod(wx_Rect2DInt, GetBottom);
	Gura_AssignMethod(wx_Rect2DInt, SetBottom);
	Gura_AssignMethod(wx_Rect2DInt, MoveBottomTo);
	Gura_AssignMethod(wx_Rect2DInt, GetRight);
	Gura_AssignMethod(wx_Rect2DInt, SetRight);
	Gura_AssignMethod(wx_Rect2DInt, MoveRightTo);
	Gura_AssignMethod(wx_Rect2DInt, GetLeftTop);
	Gura_AssignMethod(wx_Rect2DInt, SetLeftTop);
	Gura_AssignMethod(wx_Rect2DInt, MoveLeftTopTo);
	Gura_AssignMethod(wx_Rect2DInt, GetLeftBottom);
	Gura_AssignMethod(wx_Rect2DInt, SetLeftBottom);
	Gura_AssignMethod(wx_Rect2DInt, MoveLeftBottomTo);
	Gura_AssignMethod(wx_Rect2DInt, GetRightTop);
	Gura_AssignMethod(wx_Rect2DInt, SetRightTop);
	Gura_AssignMethod(wx_Rect2DInt, MoveRightTopTo);
	Gura_AssignMethod(wx_Rect2DInt, GetRightBottom);
	Gura_AssignMethod(wx_Rect2DInt, SetRightBottom);
	Gura_AssignMethod(wx_Rect2DInt, MoveRightBottomTo);
	Gura_AssignMethod(wx_Rect2DInt, GetCentre);
	Gura_AssignMethod(wx_Rect2DInt, SetCentre);
	Gura_AssignMethod(wx_Rect2DInt, MoveCentreTo);
	Gura_AssignMethod(wx_Rect2DInt, GetOutCode);
	Gura_AssignMethod(wx_Rect2DInt, GetOutcode);
	Gura_AssignMethod(wx_Rect2DInt, Contains);
	Gura_AssignMethod(wx_Rect2DInt, Contains_1);
	Gura_AssignMethod(wx_Rect2DInt, IsEmpty);
	Gura_AssignMethod(wx_Rect2DInt, HaveEqualSize);
	Gura_AssignMethod(wx_Rect2DInt, Inset);
	Gura_AssignMethod(wx_Rect2DInt, Inset_1);
	Gura_AssignMethod(wx_Rect2DInt, Offset);
	Gura_AssignMethod(wx_Rect2DInt, ConstrainTo);
	Gura_AssignMethod(wx_Rect2DInt, Interpolate);
	Gura_AssignMethod(wx_Rect2DInt, Intersect);
	Gura_AssignMethod(wx_Rect2DInt, Intersect_1);
	Gura_AssignMethod(wx_Rect2DInt, CreateIntersection);
	Gura_AssignMethod(wx_Rect2DInt, Intersects);
	Gura_AssignMethod(wx_Rect2DInt, Union);
	Gura_AssignMethod(wx_Rect2DInt, Union_1);
	Gura_AssignMethod(wx_Rect2DInt, Union_2);
	Gura_AssignMethod(wx_Rect2DInt, CreateUnion);
	Gura_AssignMethod(wx_Rect2DInt, Scale);
	Gura_AssignMethod(wx_Rect2DInt, Scale_1);
}

Gura_ImplementDescendantCreator(wx_Rect2DInt)
{
	return new Object_wx_Rect2DInt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
