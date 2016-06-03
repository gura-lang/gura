//----------------------------------------------------------------------------
// wxRect
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRect
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRect
//----------------------------------------------------------------------------
Object_wx_Rect::~Object_wx_Rect()
{
}

Object *Object_wx_Rect::Clone() const
{
	return nullptr;
}

String Object_wx_Rect::ToString(bool exprFlag)
{
	String rtn("<wx.Rect:");
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
Gura_DeclareFunctionAlias(__Rect, "Rect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Rect));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Rect)
{
	//wxRect();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Rect_1, "Rect_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Rect));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Rect_1)
{
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//wxRect();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Rect_2, "Rect_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topLeft", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottomRight", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Rect));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Rect_2)
{
	//int topLeft = arg.GetNumber(0)
	//int bottomRight = arg.GetNumber(1)
	//wxRect();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Rect_3, "Rect_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Rect));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Rect_3)
{
	//int pos = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//wxRect();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Rect_4, "Rect_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Rect));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Rect_4)
{
	//int size = arg.GetNumber(0)
	//wxRect();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Rect, __CentreIn, "CentreIn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __CentreIn)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//int dir = arg.GetNumber(1)
	//pThis->GetEntity()->CentreIn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __CenterIn, "CenterIn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __CenterIn)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//int dir = arg.GetNumber(1)
	//pThis->GetEntity()->CenterIn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Contains, "Contains")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Contains)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Contains_1, "Contains_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Contains_1)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Contains_2, "Contains_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Contains_2)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Deflate, "Deflate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Deflate)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Deflate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Deflate_1, "Deflate_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Deflate_1)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Deflate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Deflate_2, "Deflate_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Deflate_2)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Deflate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Deflate_3, "Deflate_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Deflate_3)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Deflate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __GetBottom, "GetBottom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __GetBottom)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __GetBottomLeft, "GetBottomLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __GetBottomLeft)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __GetBottomRight, "GetBottomRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __GetBottomRight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __GetHeight, "GetHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __GetHeight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __GetLeft, "GetLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __GetLeft)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __GetPosition)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __GetRight, "GetRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __GetRight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __GetSize)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __GetTop, "GetTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __GetTop)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __GetTopLeft, "GetTopLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __GetTopLeft)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __GetTopRight, "GetTopRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __GetTopRight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __GetWidth)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __GetX, "GetX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __GetX)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __GetY, "GetY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __GetY)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Inflate, "Inflate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Inflate)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Inflate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Inflate_1, "Inflate_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Inflate_1)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Inflate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Inflate_2, "Inflate_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Inflate_2)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Inflate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Inflate_3, "Inflate_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Inflate_3)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Inflate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Intersect, "Intersect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Intersect)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Intersect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Intersect_1, "Intersect_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Intersect_1)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Intersect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Intersects, "Intersects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Intersects)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Intersects();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, __IsEmpty)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Offset, "Offset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Offset)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Offset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Offset_1, "Offset_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Offset_1)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Offset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __SetHeight, "SetHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __SetHeight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __SetPosition, "SetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __SetPosition)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __SetSize, "SetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __SetSize)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __SetWidth, "SetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __SetWidth)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __SetX, "SetX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __SetX)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->SetX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __SetY, "SetY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __SetY)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int y = arg.GetNumber(0)
	//pThis->GetEntity()->SetY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __SetLeft, "SetLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __SetLeft)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int left = arg.GetNumber(0)
	//pThis->GetEntity()->SetLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __SetRight, "SetRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "right", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __SetRight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int right = arg.GetNumber(0)
	//pThis->GetEntity()->SetRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __SetTop, "SetTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "top", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __SetTop)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int top = arg.GetNumber(0)
	//pThis->GetEntity()->SetTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __SetBottom, "SetBottom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bottom", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __SetBottom)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bottom = arg.GetNumber(0)
	//pThis->GetEntity()->SetBottom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __SetTopLeft, "SetTopLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __SetTopLeft)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->SetTopLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __SetBottomRight, "SetBottomRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __SetBottomRight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->SetBottomRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __SetTopRight, "SetTopRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __SetTopRight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->SetTopRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __SetBottomLeft, "SetBottomLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __SetBottomLeft)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->SetBottomLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Union, "Union")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Union)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Rect, __Union_1, "Union_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, __Union_1)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRect
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Rect)
{
	// Constructor assignment
	Gura_AssignFunction(__Rect);
	Gura_AssignFunction(__Rect_1);
	Gura_AssignFunction(__Rect_2);
	Gura_AssignFunction(__Rect_3);
	Gura_AssignFunction(__Rect_4);
	// Method assignment
	Gura_AssignMethod(wx_Rect, __CentreIn);
	Gura_AssignMethod(wx_Rect, __CenterIn);
	Gura_AssignMethod(wx_Rect, __Contains);
	Gura_AssignMethod(wx_Rect, __Contains_1);
	Gura_AssignMethod(wx_Rect, __Contains_2);
	Gura_AssignMethod(wx_Rect, __Deflate);
	Gura_AssignMethod(wx_Rect, __Deflate_1);
	Gura_AssignMethod(wx_Rect, __Deflate_2);
	Gura_AssignMethod(wx_Rect, __Deflate_3);
	Gura_AssignMethod(wx_Rect, __GetBottom);
	Gura_AssignMethod(wx_Rect, __GetBottomLeft);
	Gura_AssignMethod(wx_Rect, __GetBottomRight);
	Gura_AssignMethod(wx_Rect, __GetHeight);
	Gura_AssignMethod(wx_Rect, __GetLeft);
	Gura_AssignMethod(wx_Rect, __GetPosition);
	Gura_AssignMethod(wx_Rect, __GetRight);
	Gura_AssignMethod(wx_Rect, __GetSize);
	Gura_AssignMethod(wx_Rect, __GetTop);
	Gura_AssignMethod(wx_Rect, __GetTopLeft);
	Gura_AssignMethod(wx_Rect, __GetTopRight);
	Gura_AssignMethod(wx_Rect, __GetWidth);
	Gura_AssignMethod(wx_Rect, __GetX);
	Gura_AssignMethod(wx_Rect, __GetY);
	Gura_AssignMethod(wx_Rect, __Inflate);
	Gura_AssignMethod(wx_Rect, __Inflate_1);
	Gura_AssignMethod(wx_Rect, __Inflate_2);
	Gura_AssignMethod(wx_Rect, __Inflate_3);
	Gura_AssignMethod(wx_Rect, __Intersect);
	Gura_AssignMethod(wx_Rect, __Intersect_1);
	Gura_AssignMethod(wx_Rect, __Intersects);
	Gura_AssignMethod(wx_Rect, __IsEmpty);
	Gura_AssignMethod(wx_Rect, __Offset);
	Gura_AssignMethod(wx_Rect, __Offset_1);
	Gura_AssignMethod(wx_Rect, __SetHeight);
	Gura_AssignMethod(wx_Rect, __SetPosition);
	Gura_AssignMethod(wx_Rect, __SetSize);
	Gura_AssignMethod(wx_Rect, __SetWidth);
	Gura_AssignMethod(wx_Rect, __SetX);
	Gura_AssignMethod(wx_Rect, __SetY);
	Gura_AssignMethod(wx_Rect, __SetLeft);
	Gura_AssignMethod(wx_Rect, __SetRight);
	Gura_AssignMethod(wx_Rect, __SetTop);
	Gura_AssignMethod(wx_Rect, __SetBottom);
	Gura_AssignMethod(wx_Rect, __SetTopLeft);
	Gura_AssignMethod(wx_Rect, __SetBottomRight);
	Gura_AssignMethod(wx_Rect, __SetTopRight);
	Gura_AssignMethod(wx_Rect, __SetBottomLeft);
	Gura_AssignMethod(wx_Rect, __Union);
	Gura_AssignMethod(wx_Rect, __Union_1);
}

Gura_ImplementDescendantCreator(wx_Rect)
{
	return new Object_wx_Rect((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
