//----------------------------------------------------------------------------
// wxDragImage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDragImage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDragImage
//----------------------------------------------------------------------------
Object_wx_DragImage::~Object_wx_DragImage()
{
}

Object *Object_wx_DragImage::Clone() const
{
	return nullptr;
}

String Object_wx_DragImage::ToString(bool exprFlag)
{
	String rtn("<wx.DragImage:");
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
Gura_DeclareFunctionAlias(__DragImage, "DragImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DragImage)
{
	//wxDragImage();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DragImage_1, "DragImage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DragImage_1)
{
	//const wxBitmap& image = arg.GetNumber(0)
	//const wxCursor& cursor = arg.GetNumber(1)
	//wxDragImage(image, cursor);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DragImage_2, "DragImage_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DragImage_2)
{
	//const wxIcon& image = arg.GetNumber(0)
	//const wxCursor& cursor = arg.GetNumber(1)
	//wxDragImage(image, cursor);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DragImage_3, "DragImage_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DragImage_3)
{
	//const wxString& text = arg.GetNumber(0)
	//const wxCursor& cursor = arg.GetNumber(1)
	//wxDragImage(text, cursor);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DragImage_4, "DragImage_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "treeCtrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DragImage_4)
{
	//const wxTreeCtrl& treeCtrl = arg.GetNumber(0)
	//wxTreeItemId& id = arg.GetNumber(1)
	//wxDragImage(treeCtrl, id);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DragImage_5, "DragImage_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "listCtrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DragImage_5)
{
	//const wxListCtrl& listCtrl = arg.GetNumber(0)
	//long id = arg.GetNumber(1)
	//wxDragImage(listCtrl, id);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DragImage, __BeginDrag, "BeginDrag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "hotspot", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fullScreen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, __BeginDrag)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& hotspot = arg.GetNumber(0)
	//wxWindow* window = arg.GetNumber(1)
	//bool fullScreen = arg.GetNumber(2)
	//wxRect* rect = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->BeginDrag(hotspot, window, fullScreen, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __BeginDrag_1, "BeginDrag_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "hotspot", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "boundingWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, __BeginDrag_1)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& hotspot = arg.GetNumber(0)
	//wxWindow* window = arg.GetNumber(1)
	//wxWindow* boundingWindow = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->BeginDrag(hotspot, window, boundingWindow);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __DoDrawImage, "DoDrawImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, __DoDrawImage)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//const wxPoint& pos = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->DoDrawImage(dc, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __EndDrag, "EndDrag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DragImage, __EndDrag)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->EndDrag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __GetImageRect, "GetImageRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, __GetImageRect)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pos = arg.GetNumber(0)
	//wxRect _rtn = pThis->GetEntity()->GetImageRect(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __Hide, "Hide")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DragImage, __Hide)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __Move, "Move")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, __Move)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Move(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DragImage, __Show)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __UpdateBackingFromWindow, "UpdateBackingFromWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "windowDC", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "destDC", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sourceRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "destRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, __UpdateBackingFromWindow)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& windowDC = arg.GetNumber(0)
	//wxMemoryDC& destDC = arg.GetNumber(1)
	//const wxRect& sourceRect = arg.GetNumber(2)
	//const wxRect& destRect = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->UpdateBackingFromWindow(windowDC, destDC, sourceRect, destRect);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDragImage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DragImage)
{
	// Constructor assignment
	Gura_AssignFunction(__DragImage);
	Gura_AssignFunction(__DragImage_1);
	Gura_AssignFunction(__DragImage_2);
	Gura_AssignFunction(__DragImage_3);
	Gura_AssignFunction(__DragImage_4);
	Gura_AssignFunction(__DragImage_5);
	// Method assignment
	Gura_AssignMethod(wx_DragImage, __BeginDrag);
	Gura_AssignMethod(wx_DragImage, __BeginDrag_1);
	Gura_AssignMethod(wx_DragImage, __DoDrawImage);
	Gura_AssignMethod(wx_DragImage, __EndDrag);
	Gura_AssignMethod(wx_DragImage, __GetImageRect);
	Gura_AssignMethod(wx_DragImage, __Hide);
	Gura_AssignMethod(wx_DragImage, __Move);
	Gura_AssignMethod(wx_DragImage, __Show);
	Gura_AssignMethod(wx_DragImage, __UpdateBackingFromWindow);
}

Gura_ImplementDescendantCreator(wx_DragImage)
{
	return new Object_wx_DragImage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
