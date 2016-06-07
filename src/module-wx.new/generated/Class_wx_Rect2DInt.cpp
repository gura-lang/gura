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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Rect2DInt, "Rect2DInt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Rect2DInt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Rect2DInt)
{
	//wxRect2DInt();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Rect2DInt_1, "Rect2DInt_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Rect2DInt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Rect2DInt_1)
{
	//const wxRect& r = arg.GetNumber(0)
	//wxRect2DInt(r);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Rect2DInt_2, "Rect2DInt_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Rect2DInt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Rect2DInt_2)
{
	//wxInt32 x = arg.GetNumber(0)
	//wxInt32 y = arg.GetNumber(1)
	//wxInt32 w = arg.GetNumber(2)
	//wxInt32 h = arg.GetNumber(3)
	//wxRect2DInt(x, y, w, h);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Rect2DInt_3, "Rect2DInt_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "topLeft", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottomRight", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Rect2DInt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Rect2DInt_3)
{
	//const wxPoint2DInt& topLeft = arg.GetNumber(0)
	//const wxPoint2DInt& bottomRight = arg.GetNumber(1)
	//wxRect2DInt(topLeft, bottomRight);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Rect2DInt_4, "Rect2DInt_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Rect2DInt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Rect2DInt_4)
{
	//const wxPoint2DInt& pos = arg.GetNumber(0)
	//const wxSize& size = arg.GetNumber(1)
	//wxRect2DInt(pos, size);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Rect2DInt_5, "Rect2DInt_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Rect2DInt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Rect2DInt_5)
{
	//const wxRect2DInt& rect = arg.GetNumber(0)
	//wxRect2DInt(rect);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Rect2DInt, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, __GetPosition)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint2DInt _rtn = pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, __GetSize)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize _rtn = pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __GetLeft, "GetLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, __GetLeft)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 _rtn = pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __SetLeft, "SetLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __SetLeft)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 n = arg.GetNumber(0)
	//pThis->GetEntity()->SetLeft(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __MoveLeftTo, "MoveLeftTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __MoveLeftTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 n = arg.GetNumber(0)
	//pThis->GetEntity()->MoveLeftTo(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __GetTop, "GetTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, __GetTop)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 _rtn = pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __SetTop, "SetTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __SetTop)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 n = arg.GetNumber(0)
	//pThis->GetEntity()->SetTop(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __MoveTopTo, "MoveTopTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __MoveTopTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 n = arg.GetNumber(0)
	//pThis->GetEntity()->MoveTopTo(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __GetBottom, "GetBottom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, __GetBottom)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 _rtn = pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __SetBottom, "SetBottom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __SetBottom)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 n = arg.GetNumber(0)
	//pThis->GetEntity()->SetBottom(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __MoveBottomTo, "MoveBottomTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __MoveBottomTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 n = arg.GetNumber(0)
	//pThis->GetEntity()->MoveBottomTo(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __GetRight, "GetRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, __GetRight)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 _rtn = pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __SetRight, "SetRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __SetRight)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 n = arg.GetNumber(0)
	//pThis->GetEntity()->SetRight(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __MoveRightTo, "MoveRightTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __MoveRightTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 n = arg.GetNumber(0)
	//pThis->GetEntity()->MoveRightTo(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __GetLeftTop, "GetLeftTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, __GetLeftTop)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint2DInt _rtn = pThis->GetEntity()->GetLeftTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __SetLeftTop, "SetLeftTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __SetLeftTop)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetLeftTop(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __MoveLeftTopTo, "MoveLeftTopTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __MoveLeftTopTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveLeftTopTo(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __GetLeftBottom, "GetLeftBottom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, __GetLeftBottom)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint2DInt _rtn = pThis->GetEntity()->GetLeftBottom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __SetLeftBottom, "SetLeftBottom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __SetLeftBottom)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetLeftBottom(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __MoveLeftBottomTo, "MoveLeftBottomTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __MoveLeftBottomTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveLeftBottomTo(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __GetRightTop, "GetRightTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, __GetRightTop)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint2DInt _rtn = pThis->GetEntity()->GetRightTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __SetRightTop, "SetRightTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __SetRightTop)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetRightTop(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __MoveRightTopTo, "MoveRightTopTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __MoveRightTopTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveRightTopTo(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __GetRightBottom, "GetRightBottom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, __GetRightBottom)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint2DInt _rtn = pThis->GetEntity()->GetRightBottom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __SetRightBottom, "SetRightBottom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __SetRightBottom)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetRightBottom(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __MoveRightBottomTo, "MoveRightBottomTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __MoveRightBottomTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveRightBottomTo(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __GetCentre, "GetCentre")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, __GetCentre)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint2DInt _rtn = pThis->GetEntity()->GetCentre();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __SetCentre, "SetCentre")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __SetCentre)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetCentre(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __MoveCentreTo, "MoveCentreTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __MoveCentreTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//pThis->GetEntity()->MoveCentreTo(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __GetOutCode, "GetOutCode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __GetOutCode)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//wxOutCode _rtn = pThis->GetEntity()->GetOutCode(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __GetOutcode, "GetOutcode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __GetOutcode)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//wxOutCode _rtn = pThis->GetEntity()->GetOutcode(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __Contains, "Contains")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __Contains)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Contains(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __Contains_1, "Contains_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __Contains_1)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect2DInt& rect = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Contains(rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Rect2DInt, __IsEmpty)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __HaveEqualSize, "HaveEqualSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __HaveEqualSize)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect2DInt& rect = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->HaveEqualSize(rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __Inset, "Inset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __Inset)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 x = arg.GetNumber(0)
	//wxInt32 y = arg.GetNumber(1)
	//pThis->GetEntity()->Inset(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __Inset_1, "Inset_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "top", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "right", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottom", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __Inset_1)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 left = arg.GetNumber(0)
	//wxInt32 top = arg.GetNumber(1)
	//wxInt32 right = arg.GetNumber(2)
	//wxInt32 bottom = arg.GetNumber(3)
	//pThis->GetEntity()->Inset(left, top, right, bottom);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __Offset, "Offset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __Offset)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//pThis->GetEntity()->Offset(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __ConstrainTo, "ConstrainTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __ConstrainTo)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect2DInt& rect = arg.GetNumber(0)
	//pThis->GetEntity()->ConstrainTo(rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __Interpolate, "Interpolate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "widthfactor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "heightfactor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __Interpolate)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 widthfactor = arg.GetNumber(0)
	//wxInt32 heightfactor = arg.GetNumber(1)
	//wxPoint2DInt _rtn = pThis->GetEntity()->Interpolate(widthfactor, heightfactor);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __Intersect, "Intersect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "src2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __Intersect)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect2DInt& src1 = arg.GetNumber(0)
	//const wxRect2DInt& src2 = arg.GetNumber(1)
	//wxRect2DInt* dest = arg.GetNumber(2)
	//pThis->GetEntity()->Intersect(src1, src2, dest);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __Intersect_1, "Intersect_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __Intersect_1)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect2DInt& otherRect = arg.GetNumber(0)
	//pThis->GetEntity()->Intersect(otherRect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __CreateIntersection, "CreateIntersection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "otherRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __CreateIntersection)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect2DInt& otherRect = arg.GetNumber(0)
	//wxRect2DInt _rtn = pThis->GetEntity()->CreateIntersection(otherRect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __Intersects, "Intersects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __Intersects)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect2DInt& rect = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Intersects(rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __Union, "Union")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "src2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __Union)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect2DInt& src1 = arg.GetNumber(0)
	//const wxRect2DInt& src2 = arg.GetNumber(1)
	//wxRect2DInt* dest = arg.GetNumber(2)
	//pThis->GetEntity()->Union(src1, src2, dest);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __Union_1, "Union_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "otherRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __Union_1)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect2DInt& otherRect = arg.GetNumber(0)
	//pThis->GetEntity()->Union(otherRect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __Union_2, "Union_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __Union_2)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint2DInt& pt = arg.GetNumber(0)
	//pThis->GetEntity()->Union(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __CreateUnion, "CreateUnion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "otherRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __CreateUnion)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect2DInt& otherRect = arg.GetNumber(0)
	//wxRect2DInt _rtn = pThis->GetEntity()->CreateUnion(otherRect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __Scale, "Scale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "f", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __Scale)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 f = arg.GetNumber(0)
	//pThis->GetEntity()->Scale(f);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect2DInt, __Scale_1, "Scale_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "num", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "denum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect2DInt, __Scale_1)
{
	Object_wx_Rect2DInt *pThis = Object_wx_Rect2DInt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInt32 num = arg.GetNumber(0)
	//wxInt32 denum = arg.GetNumber(1)
	//pThis->GetEntity()->Scale(num, denum);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRect2DInt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Rect2DInt)
{
	// Constructor assignment
	Gura_AssignFunction(__Rect2DInt);
	Gura_AssignFunction(__Rect2DInt_1);
	Gura_AssignFunction(__Rect2DInt_2);
	Gura_AssignFunction(__Rect2DInt_3);
	Gura_AssignFunction(__Rect2DInt_4);
	Gura_AssignFunction(__Rect2DInt_5);
	// Method assignment
	Gura_AssignMethod(wx_Rect2DInt, __GetPosition);
	Gura_AssignMethod(wx_Rect2DInt, __GetSize);
	Gura_AssignMethod(wx_Rect2DInt, __GetLeft);
	Gura_AssignMethod(wx_Rect2DInt, __SetLeft);
	Gura_AssignMethod(wx_Rect2DInt, __MoveLeftTo);
	Gura_AssignMethod(wx_Rect2DInt, __GetTop);
	Gura_AssignMethod(wx_Rect2DInt, __SetTop);
	Gura_AssignMethod(wx_Rect2DInt, __MoveTopTo);
	Gura_AssignMethod(wx_Rect2DInt, __GetBottom);
	Gura_AssignMethod(wx_Rect2DInt, __SetBottom);
	Gura_AssignMethod(wx_Rect2DInt, __MoveBottomTo);
	Gura_AssignMethod(wx_Rect2DInt, __GetRight);
	Gura_AssignMethod(wx_Rect2DInt, __SetRight);
	Gura_AssignMethod(wx_Rect2DInt, __MoveRightTo);
	Gura_AssignMethod(wx_Rect2DInt, __GetLeftTop);
	Gura_AssignMethod(wx_Rect2DInt, __SetLeftTop);
	Gura_AssignMethod(wx_Rect2DInt, __MoveLeftTopTo);
	Gura_AssignMethod(wx_Rect2DInt, __GetLeftBottom);
	Gura_AssignMethod(wx_Rect2DInt, __SetLeftBottom);
	Gura_AssignMethod(wx_Rect2DInt, __MoveLeftBottomTo);
	Gura_AssignMethod(wx_Rect2DInt, __GetRightTop);
	Gura_AssignMethod(wx_Rect2DInt, __SetRightTop);
	Gura_AssignMethod(wx_Rect2DInt, __MoveRightTopTo);
	Gura_AssignMethod(wx_Rect2DInt, __GetRightBottom);
	Gura_AssignMethod(wx_Rect2DInt, __SetRightBottom);
	Gura_AssignMethod(wx_Rect2DInt, __MoveRightBottomTo);
	Gura_AssignMethod(wx_Rect2DInt, __GetCentre);
	Gura_AssignMethod(wx_Rect2DInt, __SetCentre);
	Gura_AssignMethod(wx_Rect2DInt, __MoveCentreTo);
	Gura_AssignMethod(wx_Rect2DInt, __GetOutCode);
	Gura_AssignMethod(wx_Rect2DInt, __GetOutcode);
	Gura_AssignMethod(wx_Rect2DInt, __Contains);
	Gura_AssignMethod(wx_Rect2DInt, __Contains_1);
	Gura_AssignMethod(wx_Rect2DInt, __IsEmpty);
	Gura_AssignMethod(wx_Rect2DInt, __HaveEqualSize);
	Gura_AssignMethod(wx_Rect2DInt, __Inset);
	Gura_AssignMethod(wx_Rect2DInt, __Inset_1);
	Gura_AssignMethod(wx_Rect2DInt, __Offset);
	Gura_AssignMethod(wx_Rect2DInt, __ConstrainTo);
	Gura_AssignMethod(wx_Rect2DInt, __Interpolate);
	Gura_AssignMethod(wx_Rect2DInt, __Intersect);
	Gura_AssignMethod(wx_Rect2DInt, __Intersect_1);
	Gura_AssignMethod(wx_Rect2DInt, __CreateIntersection);
	Gura_AssignMethod(wx_Rect2DInt, __Intersects);
	Gura_AssignMethod(wx_Rect2DInt, __Union);
	Gura_AssignMethod(wx_Rect2DInt, __Union_1);
	Gura_AssignMethod(wx_Rect2DInt, __Union_2);
	Gura_AssignMethod(wx_Rect2DInt, __CreateUnion);
	Gura_AssignMethod(wx_Rect2DInt, __Scale);
	Gura_AssignMethod(wx_Rect2DInt, __Scale_1);
}

Gura_ImplementDescendantCreator(wx_Rect2DInt)
{
	return new Object_wx_Rect2DInt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
