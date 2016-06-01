//----------------------------------------------------------------------------
// wxScrolled
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScrolled
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScrolled
//----------------------------------------------------------------------------
Object_wx_Scrolled::~Object_wx_Scrolled()
{
}

Object *Object_wx_Scrolled::Clone() const
{
	return nullptr;
}

String Object_wx_Scrolled::ToString(bool exprFlag)
{
	String rtn("<wx.Scrolled:");
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
Gura_DeclareMethod(wx_Scrolled, wxScrolled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, wxScrolled)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxScrolled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, wxScrolled_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, wxScrolled_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxScrolled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, CalcScrolledPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, CalcScrolledPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int xx = arg.GetNumber(2)
	//int yy = arg.GetNumber(3)
	//pThis->GetEntity()->CalcScrolledPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, CalcScrolledPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, CalcScrolledPosition_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->CalcScrolledPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, CalcUnscrolledPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, CalcUnscrolledPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int xx = arg.GetNumber(2)
	//int yy = arg.GetNumber(3)
	//pThis->GetEntity()->CalcUnscrolledPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, CalcUnscrolledPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, CalcUnscrolledPosition_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->CalcUnscrolledPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_Scrolled, DisableKeyboardScrolling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, DisableKeyboardScrolling)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DisableKeyboardScrolling();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, DoPrepareDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, DoPrepareDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->DoPrepareDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, EnableScrolling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xScrolling", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yScrolling", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, EnableScrolling)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int xScrolling = arg.GetNumber(0)
	//int yScrolling = arg.GetNumber(1)
	//pThis->GetEntity()->EnableScrolling();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, ShowScrollbars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "horz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vert", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, ShowScrollbars)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int horz = arg.GetNumber(0)
	//int vert = arg.GetNumber(1)
	//pThis->GetEntity()->ShowScrollbars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, GetScrollPixelsPerUnit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xUnit", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yUnit", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, GetScrollPixelsPerUnit)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int xUnit = arg.GetNumber(0)
	//int yUnit = arg.GetNumber(1)
	//pThis->GetEntity()->GetScrollPixelsPerUnit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, GetViewStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, GetViewStart)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetViewStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, GetViewStart_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, GetViewStart_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetViewStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, GetVirtualSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, GetVirtualSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetVirtualSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, IsRetained)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, IsRetained)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsRetained();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, OnDraw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, OnDraw)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->OnDraw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, PrepareDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, PrepareDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->PrepareDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, Scroll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, Scroll)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->Scroll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, Scroll_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, Scroll_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Scroll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, SetScrollRate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xstep", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ystep", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, SetScrollRate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int xstep = arg.GetNumber(0)
	//int ystep = arg.GetNumber(1)
	//pThis->GetEntity()->SetScrollRate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, SetScrollbars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelsPerUnitX", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixelsPerUnitY", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noUnitsX", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noUnitsY", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noRefresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, SetScrollbars)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pixelsPerUnitX = arg.GetNumber(0)
	//int pixelsPerUnitY = arg.GetNumber(1)
	//int noUnitsX = arg.GetNumber(2)
	//int noUnitsY = arg.GetNumber(3)
	//int xPos = arg.GetNumber(4)
	//int yPos = arg.GetNumber(5)
	//int noRefresh = arg.GetNumber(6)
	//pThis->GetEntity()->SetScrollbars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, SetTargetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, SetTargetWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->SetTargetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, GetTargetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, GetTargetWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTargetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, SetTargetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, SetTargetRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetTargetRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, GetTargetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, GetTargetRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTargetRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, GetScrollPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, GetScrollPageSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->GetScrollPageSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, SetScrollPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, SetScrollPageSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//int pageSize = arg.GetNumber(1)
	//pThis->GetEntity()->SetScrollPageSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, GetScrollLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, GetScrollLines)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->GetScrollLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, SetScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ys", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, SetScale)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int xs = arg.GetNumber(0)
	//int ys = arg.GetNumber(1)
	//pThis->GetEntity()->SetScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, GetScaleX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, GetScaleX)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetScaleX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, GetScaleY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, GetScaleY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetScaleY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, AdjustScrollbars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, AdjustScrollbars)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AdjustScrollbars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, IsAutoScrolling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, IsAutoScrolling)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsAutoScrolling();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, StopAutoScrolling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, StopAutoScrolling)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->StopAutoScrolling();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, SendAutoScrollEvents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, SendAutoScrollEvents)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->SendAutoScrollEvents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Scrolled, GetSizeAvailableForScrollTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, GetSizeAvailableForScrollTarget)
{
	Signal &sig = env.GetSignal();
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->GetSizeAvailableForScrollTarget();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScrolled
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Scrolled)
{
	Gura_AssignMethod(wx_Scrolled, wxScrolled);
	Gura_AssignMethod(wx_Scrolled, wxScrolled_1);
	Gura_AssignMethod(wx_Scrolled, CalcScrolledPosition);
	Gura_AssignMethod(wx_Scrolled, CalcScrolledPosition_1);
	Gura_AssignMethod(wx_Scrolled, CalcUnscrolledPosition);
	Gura_AssignMethod(wx_Scrolled, CalcUnscrolledPosition_1);
	Gura_AssignMethod(wx_Scrolled, Create);
	Gura_AssignMethod(wx_Scrolled, DisableKeyboardScrolling);
	Gura_AssignMethod(wx_Scrolled, DoPrepareDC);
	Gura_AssignMethod(wx_Scrolled, EnableScrolling);
	Gura_AssignMethod(wx_Scrolled, ShowScrollbars);
	Gura_AssignMethod(wx_Scrolled, GetScrollPixelsPerUnit);
	Gura_AssignMethod(wx_Scrolled, GetViewStart);
	Gura_AssignMethod(wx_Scrolled, GetViewStart_1);
	Gura_AssignMethod(wx_Scrolled, GetVirtualSize);
	Gura_AssignMethod(wx_Scrolled, IsRetained);
	Gura_AssignMethod(wx_Scrolled, OnDraw);
	Gura_AssignMethod(wx_Scrolled, PrepareDC);
	Gura_AssignMethod(wx_Scrolled, Scroll);
	Gura_AssignMethod(wx_Scrolled, Scroll_1);
	Gura_AssignMethod(wx_Scrolled, SetScrollRate);
	Gura_AssignMethod(wx_Scrolled, SetScrollbars);
	Gura_AssignMethod(wx_Scrolled, SetTargetWindow);
	Gura_AssignMethod(wx_Scrolled, GetTargetWindow);
	Gura_AssignMethod(wx_Scrolled, SetTargetRect);
	Gura_AssignMethod(wx_Scrolled, GetTargetRect);
	Gura_AssignMethod(wx_Scrolled, GetScrollPageSize);
	Gura_AssignMethod(wx_Scrolled, SetScrollPageSize);
	Gura_AssignMethod(wx_Scrolled, GetScrollLines);
	Gura_AssignMethod(wx_Scrolled, SetScale);
	Gura_AssignMethod(wx_Scrolled, GetScaleX);
	Gura_AssignMethod(wx_Scrolled, GetScaleY);
	Gura_AssignMethod(wx_Scrolled, AdjustScrollbars);
	Gura_AssignMethod(wx_Scrolled, IsAutoScrolling);
	Gura_AssignMethod(wx_Scrolled, StopAutoScrolling);
	Gura_AssignMethod(wx_Scrolled, SendAutoScrollEvents);
	Gura_AssignMethod(wx_Scrolled, GetSizeAvailableForScrollTarget);
}

Gura_ImplementDescendantCreator(wx_Scrolled)
{
	return new Object_wx_Scrolled((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
