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
Gura_DeclareFunctionAlias(__wxDragImage, "wxDragImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDragImage)
{
	//wxDragImage();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDragImage_1, "wxDragImage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDragImage_1)
{
	//int image = arg.GetNumber(0)
	//int cursor = arg.GetNumber(1)
	//wxDragImage();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDragImage_2, "wxDragImage_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDragImage_2)
{
	//int image = arg.GetNumber(0)
	//int cursor = arg.GetNumber(1)
	//wxDragImage();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDragImage_3, "wxDragImage_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDragImage_3)
{
	//int text = arg.GetNumber(0)
	//int cursor = arg.GetNumber(1)
	//wxDragImage();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDragImage_4, "wxDragImage_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "treeCtrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDragImage_4)
{
	//int treeCtrl = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxDragImage();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDragImage_5, "wxDragImage_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "listCtrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDragImage_5)
{
	//int listCtrl = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxDragImage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DragImage, __BeginDrag, "BeginDrag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hotspot", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fullScreen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, __BeginDrag)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int hotspot = arg.GetNumber(0)
	//int window = arg.GetNumber(1)
	//int fullScreen = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->BeginDrag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __BeginDrag_1, "BeginDrag_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hotspot", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "boundingWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, __BeginDrag_1)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int hotspot = arg.GetNumber(0)
	//int window = arg.GetNumber(1)
	//int boundingWindow = arg.GetNumber(2)
	//pThis->GetEntity()->BeginDrag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __DoDrawImage, "DoDrawImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, __DoDrawImage)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->DoDrawImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __EndDrag, "EndDrag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DragImage, __EndDrag)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndDrag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __GetImageRect, "GetImageRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, __GetImageRect)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetImageRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __Hide, "Hide")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DragImage, __Hide)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __Move, "Move")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, __Move)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Move();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DragImage, __Show)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DragImage, __UpdateBackingFromWindow, "UpdateBackingFromWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "windowDC", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "destDC", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sourceRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "destRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, __UpdateBackingFromWindow)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int windowDC = arg.GetNumber(0)
	//int destDC = arg.GetNumber(1)
	//int sourceRect = arg.GetNumber(2)
	//int destRect = arg.GetNumber(3)
	//pThis->GetEntity()->UpdateBackingFromWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDragImage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DragImage)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDragImage);
	Gura_AssignFunction(__wxDragImage_1);
	Gura_AssignFunction(__wxDragImage_2);
	Gura_AssignFunction(__wxDragImage_3);
	Gura_AssignFunction(__wxDragImage_4);
	Gura_AssignFunction(__wxDragImage_5);
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
