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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Rect, wxRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, wxRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, wxRect_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, wxRect_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->wxRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, wxRect_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topLeft", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottomRight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, wxRect_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topLeft = arg.GetNumber(0)
	//int bottomRight = arg.GetNumber(1)
	//pThis->GetEntity()->wxRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, wxRect_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, wxRect_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->wxRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, wxRect_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, wxRect_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->wxRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, CentreIn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, CentreIn)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//int dir = arg.GetNumber(1)
	//pThis->GetEntity()->CentreIn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, CenterIn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, CenterIn)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//int dir = arg.GetNumber(1)
	//pThis->GetEntity()->CenterIn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Contains)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Contains_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Contains_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Contains_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Contains_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Deflate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Deflate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Deflate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Deflate_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Deflate_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Deflate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Deflate_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Deflate_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Deflate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Deflate_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Deflate_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Deflate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, GetBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, GetBottom)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, GetBottomLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, GetBottomLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBottomLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, GetBottomRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, GetBottomRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBottomRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, GetHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, GetLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, GetLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, GetRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, GetRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, GetTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, GetTop)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, GetTopLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, GetTopLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTopLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, GetTopRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, GetTopRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTopRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, GetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, GetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, GetX)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, GetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, GetY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Inflate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Inflate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Inflate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Inflate_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Inflate_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Inflate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Inflate_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Inflate_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Inflate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Inflate_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Inflate_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Inflate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Intersect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Intersect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Intersect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Intersect_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Intersect_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Intersect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Intersects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Intersects)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Intersects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Rect, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Offset)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Offset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Offset_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Offset_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Offset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, SetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, SetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetX)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->SetX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, SetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int y = arg.GetNumber(0)
	//pThis->GetEntity()->SetY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, SetLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int left = arg.GetNumber(0)
	//pThis->GetEntity()->SetLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, SetRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "right", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int right = arg.GetNumber(0)
	//pThis->GetEntity()->SetRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, SetTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "top", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetTop)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int top = arg.GetNumber(0)
	//pThis->GetEntity()->SetTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, SetBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bottom", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetBottom)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bottom = arg.GetNumber(0)
	//pThis->GetEntity()->SetBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, SetTopLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetTopLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->SetTopLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, SetBottomRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetBottomRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->SetBottomRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, SetTopRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetTopRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->SetTopRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, SetBottomLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetBottomLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->SetBottomLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Union)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Union)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Rect, Union_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Union_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Rect *pThis = Object_wx_Rect::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRect
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Rect)
{
	Gura_AssignMethod(wx_Rect, wxRect);
	Gura_AssignMethod(wx_Rect, wxRect_1);
	Gura_AssignMethod(wx_Rect, wxRect_2);
	Gura_AssignMethod(wx_Rect, wxRect_3);
	Gura_AssignMethod(wx_Rect, wxRect_4);
	Gura_AssignMethod(wx_Rect, CentreIn);
	Gura_AssignMethod(wx_Rect, CenterIn);
	Gura_AssignMethod(wx_Rect, Contains);
	Gura_AssignMethod(wx_Rect, Contains_1);
	Gura_AssignMethod(wx_Rect, Contains_2);
	Gura_AssignMethod(wx_Rect, Deflate);
	Gura_AssignMethod(wx_Rect, Deflate_1);
	Gura_AssignMethod(wx_Rect, Deflate_2);
	Gura_AssignMethod(wx_Rect, Deflate_3);
	Gura_AssignMethod(wx_Rect, GetBottom);
	Gura_AssignMethod(wx_Rect, GetBottomLeft);
	Gura_AssignMethod(wx_Rect, GetBottomRight);
	Gura_AssignMethod(wx_Rect, GetHeight);
	Gura_AssignMethod(wx_Rect, GetLeft);
	Gura_AssignMethod(wx_Rect, GetPosition);
	Gura_AssignMethod(wx_Rect, GetRight);
	Gura_AssignMethod(wx_Rect, GetSize);
	Gura_AssignMethod(wx_Rect, GetTop);
	Gura_AssignMethod(wx_Rect, GetTopLeft);
	Gura_AssignMethod(wx_Rect, GetTopRight);
	Gura_AssignMethod(wx_Rect, GetWidth);
	Gura_AssignMethod(wx_Rect, GetX);
	Gura_AssignMethod(wx_Rect, GetY);
	Gura_AssignMethod(wx_Rect, Inflate);
	Gura_AssignMethod(wx_Rect, Inflate_1);
	Gura_AssignMethod(wx_Rect, Inflate_2);
	Gura_AssignMethod(wx_Rect, Inflate_3);
	Gura_AssignMethod(wx_Rect, Intersect);
	Gura_AssignMethod(wx_Rect, Intersect_1);
	Gura_AssignMethod(wx_Rect, Intersects);
	Gura_AssignMethod(wx_Rect, IsEmpty);
	Gura_AssignMethod(wx_Rect, Offset);
	Gura_AssignMethod(wx_Rect, Offset_1);
	Gura_AssignMethod(wx_Rect, SetHeight);
	Gura_AssignMethod(wx_Rect, SetPosition);
	Gura_AssignMethod(wx_Rect, SetSize);
	Gura_AssignMethod(wx_Rect, SetWidth);
	Gura_AssignMethod(wx_Rect, SetX);
	Gura_AssignMethod(wx_Rect, SetY);
	Gura_AssignMethod(wx_Rect, SetLeft);
	Gura_AssignMethod(wx_Rect, SetRight);
	Gura_AssignMethod(wx_Rect, SetTop);
	Gura_AssignMethod(wx_Rect, SetBottom);
	Gura_AssignMethod(wx_Rect, SetTopLeft);
	Gura_AssignMethod(wx_Rect, SetBottomRight);
	Gura_AssignMethod(wx_Rect, SetTopRight);
	Gura_AssignMethod(wx_Rect, SetBottomLeft);
	Gura_AssignMethod(wx_Rect, Union);
	Gura_AssignMethod(wx_Rect, Union_1);
}

Gura_ImplementDescendantCreator(wx_Rect)
{
	return new Object_wx_Rect((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
