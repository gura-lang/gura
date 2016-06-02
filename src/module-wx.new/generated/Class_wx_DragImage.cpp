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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DragImage, wxDragImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DragImage, wxDragImage)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxDragImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, wxDragImage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, wxDragImage_1)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int cursor = arg.GetNumber(1)
	//pThis->GetEntity()->wxDragImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, wxDragImage_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, wxDragImage_2)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int cursor = arg.GetNumber(1)
	//pThis->GetEntity()->wxDragImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, wxDragImage_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, wxDragImage_3)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int cursor = arg.GetNumber(1)
	//pThis->GetEntity()->wxDragImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, wxDragImage_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "treeCtrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, wxDragImage_4)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int treeCtrl = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxDragImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, wxDragImage_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "listCtrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, wxDragImage_5)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int listCtrl = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxDragImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, BeginDrag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hotspot", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fullScreen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, BeginDrag)
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

Gura_DeclareMethod(wx_DragImage, BeginDrag_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hotspot", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "boundingWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, BeginDrag_1)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int hotspot = arg.GetNumber(0)
	//int window = arg.GetNumber(1)
	//int boundingWindow = arg.GetNumber(2)
	//pThis->GetEntity()->BeginDrag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, DoDrawImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, DoDrawImage)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->DoDrawImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, EndDrag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DragImage, EndDrag)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndDrag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, GetImageRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, GetImageRect)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetImageRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, Hide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DragImage, Hide)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, Move)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, Move)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Move();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DragImage, Show)
{
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, UpdateBackingFromWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "windowDC", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "destDC", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sourceRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "destRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DragImage, UpdateBackingFromWindow)
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
	Gura_AssignMethod(wx_DragImage, wxDragImage);
	Gura_AssignMethod(wx_DragImage, wxDragImage_1);
	Gura_AssignMethod(wx_DragImage, wxDragImage_2);
	Gura_AssignMethod(wx_DragImage, wxDragImage_3);
	Gura_AssignMethod(wx_DragImage, wxDragImage_4);
	Gura_AssignMethod(wx_DragImage, wxDragImage_5);
	Gura_AssignMethod(wx_DragImage, BeginDrag);
	Gura_AssignMethod(wx_DragImage, BeginDrag_1);
	Gura_AssignMethod(wx_DragImage, DoDrawImage);
	Gura_AssignMethod(wx_DragImage, EndDrag);
	Gura_AssignMethod(wx_DragImage, GetImageRect);
	Gura_AssignMethod(wx_DragImage, Hide);
	Gura_AssignMethod(wx_DragImage, Move);
	Gura_AssignMethod(wx_DragImage, Show);
	Gura_AssignMethod(wx_DragImage, UpdateBackingFromWindow);
}

Gura_ImplementDescendantCreator(wx_DragImage)
{
	return new Object_wx_DragImage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
