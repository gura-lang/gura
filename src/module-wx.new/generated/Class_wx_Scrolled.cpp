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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxScrolled, "wxScrolled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxScrolled)
{
	//wxScrolled();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxScrolled_1, "wxScrolled_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxScrolled_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//wxScrolled();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Scrolled, __CalcScrolledPosition, "CalcScrolledPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __CalcScrolledPosition)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int xx = arg.GetNumber(2)
	//int yy = arg.GetNumber(3)
	//pThis->GetEntity()->CalcScrolledPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __CalcScrolledPosition_1, "CalcScrolledPosition_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __CalcScrolledPosition_1)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->CalcScrolledPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __CalcUnscrolledPosition, "CalcUnscrolledPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __CalcUnscrolledPosition)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int xx = arg.GetNumber(2)
	//int yy = arg.GetNumber(3)
	//pThis->GetEntity()->CalcUnscrolledPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __CalcUnscrolledPosition_1, "CalcUnscrolledPosition_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __CalcUnscrolledPosition_1)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->CalcUnscrolledPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __Create)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_Scrolled, __DisableKeyboardScrolling, "DisableKeyboardScrolling")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, __DisableKeyboardScrolling)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisableKeyboardScrolling();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __DoPrepareDC, "DoPrepareDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __DoPrepareDC)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->DoPrepareDC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __EnableScrolling, "EnableScrolling")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xScrolling", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yScrolling", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __EnableScrolling)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xScrolling = arg.GetNumber(0)
	//int yScrolling = arg.GetNumber(1)
	//pThis->GetEntity()->EnableScrolling();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __ShowScrollbars, "ShowScrollbars")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "horz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vert", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __ShowScrollbars)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int horz = arg.GetNumber(0)
	//int vert = arg.GetNumber(1)
	//pThis->GetEntity()->ShowScrollbars();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __GetScrollPixelsPerUnit, "GetScrollPixelsPerUnit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xUnit", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yUnit", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __GetScrollPixelsPerUnit)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xUnit = arg.GetNumber(0)
	//int yUnit = arg.GetNumber(1)
	//pThis->GetEntity()->GetScrollPixelsPerUnit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __GetViewStart, "GetViewStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __GetViewStart)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetViewStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __GetViewStart_1, "GetViewStart_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, __GetViewStart_1)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetViewStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __GetVirtualSize, "GetVirtualSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __GetVirtualSize)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetVirtualSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __IsRetained, "IsRetained")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, __IsRetained)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsRetained();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __OnDraw, "OnDraw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __OnDraw)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->OnDraw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __PrepareDC, "PrepareDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __PrepareDC)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->PrepareDC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __Scroll, "Scroll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __Scroll)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->Scroll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __Scroll_1, "Scroll_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __Scroll_1)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Scroll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __SetScrollRate, "SetScrollRate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xstep", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ystep", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __SetScrollRate)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xstep = arg.GetNumber(0)
	//int ystep = arg.GetNumber(1)
	//pThis->GetEntity()->SetScrollRate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __SetScrollbars, "SetScrollbars")
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

Gura_ImplementMethod(wx_Scrolled, __SetScrollbars)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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

Gura_DeclareMethodAlias(wx_Scrolled, __SetTargetWindow, "SetTargetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __SetTargetWindow)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->SetTargetWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __GetTargetWindow, "GetTargetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, __GetTargetWindow)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTargetWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __SetTargetRect, "SetTargetRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __SetTargetRect)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetTargetRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __GetTargetRect, "GetTargetRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, __GetTargetRect)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTargetRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __GetScrollPageSize, "GetScrollPageSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __GetScrollPageSize)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->GetScrollPageSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __SetScrollPageSize, "SetScrollPageSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __SetScrollPageSize)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//int pageSize = arg.GetNumber(1)
	//pThis->GetEntity()->SetScrollPageSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __GetScrollLines, "GetScrollLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __GetScrollLines)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->GetScrollLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __SetScale, "SetScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ys", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __SetScale)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xs = arg.GetNumber(0)
	//int ys = arg.GetNumber(1)
	//pThis->GetEntity()->SetScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __GetScaleX, "GetScaleX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, __GetScaleX)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetScaleX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __GetScaleY, "GetScaleY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, __GetScaleY)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetScaleY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __AdjustScrollbars, "AdjustScrollbars")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, __AdjustScrollbars)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AdjustScrollbars();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __IsAutoScrolling, "IsAutoScrolling")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, __IsAutoScrolling)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAutoScrolling();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __StopAutoScrolling, "StopAutoScrolling")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Scrolled, __StopAutoScrolling)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StopAutoScrolling();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __SendAutoScrollEvents, "SendAutoScrollEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __SendAutoScrollEvents)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->SendAutoScrollEvents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Scrolled, __GetSizeAvailableForScrollTarget, "GetSizeAvailableForScrollTarget")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Scrolled, __GetSizeAvailableForScrollTarget)
{
	Object_wx_Scrolled *pThis = Object_wx_Scrolled::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->GetSizeAvailableForScrollTarget();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScrolled
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Scrolled)
{
	// Constructor assignment
	Gura_AssignFunction(__wxScrolled);
	Gura_AssignFunction(__wxScrolled_1);
	// Method assignment
	Gura_AssignMethod(wx_Scrolled, __CalcScrolledPosition);
	Gura_AssignMethod(wx_Scrolled, __CalcScrolledPosition_1);
	Gura_AssignMethod(wx_Scrolled, __CalcUnscrolledPosition);
	Gura_AssignMethod(wx_Scrolled, __CalcUnscrolledPosition_1);
	Gura_AssignMethod(wx_Scrolled, __Create);
	Gura_AssignMethod(wx_Scrolled, __DisableKeyboardScrolling);
	Gura_AssignMethod(wx_Scrolled, __DoPrepareDC);
	Gura_AssignMethod(wx_Scrolled, __EnableScrolling);
	Gura_AssignMethod(wx_Scrolled, __ShowScrollbars);
	Gura_AssignMethod(wx_Scrolled, __GetScrollPixelsPerUnit);
	Gura_AssignMethod(wx_Scrolled, __GetViewStart);
	Gura_AssignMethod(wx_Scrolled, __GetViewStart_1);
	Gura_AssignMethod(wx_Scrolled, __GetVirtualSize);
	Gura_AssignMethod(wx_Scrolled, __IsRetained);
	Gura_AssignMethod(wx_Scrolled, __OnDraw);
	Gura_AssignMethod(wx_Scrolled, __PrepareDC);
	Gura_AssignMethod(wx_Scrolled, __Scroll);
	Gura_AssignMethod(wx_Scrolled, __Scroll_1);
	Gura_AssignMethod(wx_Scrolled, __SetScrollRate);
	Gura_AssignMethod(wx_Scrolled, __SetScrollbars);
	Gura_AssignMethod(wx_Scrolled, __SetTargetWindow);
	Gura_AssignMethod(wx_Scrolled, __GetTargetWindow);
	Gura_AssignMethod(wx_Scrolled, __SetTargetRect);
	Gura_AssignMethod(wx_Scrolled, __GetTargetRect);
	Gura_AssignMethod(wx_Scrolled, __GetScrollPageSize);
	Gura_AssignMethod(wx_Scrolled, __SetScrollPageSize);
	Gura_AssignMethod(wx_Scrolled, __GetScrollLines);
	Gura_AssignMethod(wx_Scrolled, __SetScale);
	Gura_AssignMethod(wx_Scrolled, __GetScaleX);
	Gura_AssignMethod(wx_Scrolled, __GetScaleY);
	Gura_AssignMethod(wx_Scrolled, __AdjustScrollbars);
	Gura_AssignMethod(wx_Scrolled, __IsAutoScrolling);
	Gura_AssignMethod(wx_Scrolled, __StopAutoScrolling);
	Gura_AssignMethod(wx_Scrolled, __SendAutoScrollEvents);
	Gura_AssignMethod(wx_Scrolled, __GetSizeAvailableForScrollTarget);
}

Gura_ImplementDescendantCreator(wx_Scrolled)
{
	return new Object_wx_Scrolled((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
