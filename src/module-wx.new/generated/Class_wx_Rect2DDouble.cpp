//----------------------------------------------------------------------------
// wxRect2DDouble
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRect2DDouble
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRect2DDouble
//----------------------------------------------------------------------------
Object_wx_Rect2DDouble::~Object_wx_Rect2DDouble()
{
}

Object *Object_wx_Rect2DDouble::Clone() const
{
	return nullptr;
}

String Object_wx_Rect2DDouble::ToString(bool exprFlag)
{
	String rtn("<wx.Rect2DDouble:");
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
Gura_DeclareMethod(wx_Rect2DDouble, wxRect2DDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DDouble, wxRect2DDouble)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRect2DDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, wxRect2DDouble_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, wxRect2DDouble_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int w = arg.GetNumber(2)
	//int h = arg.GetNumber(3)
	//pThis->GetEntity()->wxRect2DDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DDouble, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DDouble, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, GetLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DDouble, GetLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, SetLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, SetLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, MoveLeftTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, MoveLeftTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->MoveLeftTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, GetTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DDouble, GetTop)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, SetTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, SetTop)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, MoveTopTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, MoveTopTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->MoveTopTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, GetBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DDouble, GetBottom)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, SetBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, SetBottom)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, MoveBottomTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, MoveBottomTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->MoveBottomTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, GetRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DDouble, GetRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, SetRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, SetRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, MoveRightTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, MoveRightTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->MoveRightTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, GetLeftTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DDouble, GetLeftTop)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLeftTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, SetLeftTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, SetLeftTop)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetLeftTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, MoveLeftTopTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, MoveLeftTopTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveLeftTopTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, GetLeftBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DDouble, GetLeftBottom)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLeftBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, SetLeftBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, SetLeftBottom)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetLeftBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, MoveLeftBottomTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, MoveLeftBottomTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveLeftBottomTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, GetRightTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DDouble, GetRightTop)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRightTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, SetRightTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, SetRightTop)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetRightTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, MoveRightTopTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, MoveRightTopTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveRightTopTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, GetRightBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DDouble, GetRightBottom)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRightBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, SetRightBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, SetRightBottom)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetRightBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, MoveRightBottomTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, MoveRightBottomTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveRightBottomTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, GetCentre)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DDouble, GetCentre)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCentre();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, SetCentre)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, SetCentre)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetCentre();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, MoveCentreTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, MoveCentreTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveCentreTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, GetOutCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, GetOutCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetOutCode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, GetOutcode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, GetOutcode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetOutcode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, Contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, Contains)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, Contains_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, Contains_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DDouble, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, HaveEqualSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, HaveEqualSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->HaveEqualSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, Inset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, Inset)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->Inset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, Inset_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "top", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "right", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottom", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, Inset_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int left = arg.GetNumber(0)
	//int top = arg.GetNumber(1)
	//int right = arg.GetNumber(2)
	//int bottom = arg.GetNumber(3)
	//pThis->GetEntity()->Inset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, Offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, Offset)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Offset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, ConstrainTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, ConstrainTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->ConstrainTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, Interpolate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "widthfactor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "heightfactor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, Interpolate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int widthfactor = arg.GetNumber(0)
	//int heightfactor = arg.GetNumber(1)
	//pThis->GetEntity()->Interpolate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, Intersect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "src2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, Intersect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int src1 = arg.GetNumber(0)
	//int src2 = arg.GetNumber(1)
	//int dest = arg.GetNumber(2)
	//pThis->GetEntity()->Intersect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, Intersect_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, Intersect_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int otherRect = arg.GetNumber(0)
	//pThis->GetEntity()->Intersect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, CreateIntersection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, CreateIntersection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int otherRect = arg.GetNumber(0)
	//pThis->GetEntity()->CreateIntersection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, Intersects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, Intersects)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Intersects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, Union)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "src2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, Union)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int src1 = arg.GetNumber(0)
	//int src2 = arg.GetNumber(1)
	//int dest = arg.GetNumber(2)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, Union_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, Union_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int otherRect = arg.GetNumber(0)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, Union_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, Union_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, CreateUnion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, CreateUnion)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int otherRect = arg.GetNumber(0)
	//pThis->GetEntity()->CreateUnion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, Scale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "f", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, Scale)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int f = arg.GetNumber(0)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect2DDouble, Scale_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "num", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "denum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DDouble, Scale_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect2DDouble *pThis = Object_wx_Rect2DDouble::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int num = arg.GetNumber(0)
	//int denum = arg.GetNumber(1)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRect2DDouble
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Rect2DDouble)
{
	Gura_AssignMethod(wx_Rect2DDouble, wxRect2DDouble);
	Gura_AssignMethod(wx_Rect2DDouble, wxRect2DDouble_1);
	Gura_AssignMethod(wx_Rect2DDouble, GetPosition);
	Gura_AssignMethod(wx_Rect2DDouble, GetSize);
	Gura_AssignMethod(wx_Rect2DDouble, GetLeft);
	Gura_AssignMethod(wx_Rect2DDouble, SetLeft);
	Gura_AssignMethod(wx_Rect2DDouble, MoveLeftTo);
	Gura_AssignMethod(wx_Rect2DDouble, GetTop);
	Gura_AssignMethod(wx_Rect2DDouble, SetTop);
	Gura_AssignMethod(wx_Rect2DDouble, MoveTopTo);
	Gura_AssignMethod(wx_Rect2DDouble, GetBottom);
	Gura_AssignMethod(wx_Rect2DDouble, SetBottom);
	Gura_AssignMethod(wx_Rect2DDouble, MoveBottomTo);
	Gura_AssignMethod(wx_Rect2DDouble, GetRight);
	Gura_AssignMethod(wx_Rect2DDouble, SetRight);
	Gura_AssignMethod(wx_Rect2DDouble, MoveRightTo);
	Gura_AssignMethod(wx_Rect2DDouble, GetLeftTop);
	Gura_AssignMethod(wx_Rect2DDouble, SetLeftTop);
	Gura_AssignMethod(wx_Rect2DDouble, MoveLeftTopTo);
	Gura_AssignMethod(wx_Rect2DDouble, GetLeftBottom);
	Gura_AssignMethod(wx_Rect2DDouble, SetLeftBottom);
	Gura_AssignMethod(wx_Rect2DDouble, MoveLeftBottomTo);
	Gura_AssignMethod(wx_Rect2DDouble, GetRightTop);
	Gura_AssignMethod(wx_Rect2DDouble, SetRightTop);
	Gura_AssignMethod(wx_Rect2DDouble, MoveRightTopTo);
	Gura_AssignMethod(wx_Rect2DDouble, GetRightBottom);
	Gura_AssignMethod(wx_Rect2DDouble, SetRightBottom);
	Gura_AssignMethod(wx_Rect2DDouble, MoveRightBottomTo);
	Gura_AssignMethod(wx_Rect2DDouble, GetCentre);
	Gura_AssignMethod(wx_Rect2DDouble, SetCentre);
	Gura_AssignMethod(wx_Rect2DDouble, MoveCentreTo);
	Gura_AssignMethod(wx_Rect2DDouble, GetOutCode);
	Gura_AssignMethod(wx_Rect2DDouble, GetOutcode);
	Gura_AssignMethod(wx_Rect2DDouble, Contains);
	Gura_AssignMethod(wx_Rect2DDouble, Contains_1);
	Gura_AssignMethod(wx_Rect2DDouble, IsEmpty);
	Gura_AssignMethod(wx_Rect2DDouble, HaveEqualSize);
	Gura_AssignMethod(wx_Rect2DDouble, Inset);
	Gura_AssignMethod(wx_Rect2DDouble, Inset_1);
	Gura_AssignMethod(wx_Rect2DDouble, Offset);
	Gura_AssignMethod(wx_Rect2DDouble, ConstrainTo);
	Gura_AssignMethod(wx_Rect2DDouble, Interpolate);
	Gura_AssignMethod(wx_Rect2DDouble, Intersect);
	Gura_AssignMethod(wx_Rect2DDouble, Intersect_1);
	Gura_AssignMethod(wx_Rect2DDouble, CreateIntersection);
	Gura_AssignMethod(wx_Rect2DDouble, Intersects);
	Gura_AssignMethod(wx_Rect2DDouble, Union);
	Gura_AssignMethod(wx_Rect2DDouble, Union_1);
	Gura_AssignMethod(wx_Rect2DDouble, Union_2);
	Gura_AssignMethod(wx_Rect2DDouble, CreateUnion);
	Gura_AssignMethod(wx_Rect2DDouble, Scale);
	Gura_AssignMethod(wx_Rect2DDouble, Scale_1);
}

Gura_ImplementDescendantCreator(wx_Rect2DDouble)
{
	return new Object_wx_Rect2DDouble((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
