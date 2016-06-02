//----------------------------------------------------------------------------
// wxBitmap
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmap
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBitmap
//----------------------------------------------------------------------------
Object_wx_Bitmap::~Object_wx_Bitmap()
{
}

Object *Object_wx_Bitmap::Clone() const
{
	return nullptr;
}

String Object_wx_Bitmap::ToString(bool exprFlag)
{
	String rtn("<wx.Bitmap:");
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
Gura_DeclareMethod(wx_Bitmap, wxBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, wxBitmap)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, wxBitmap_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, wxBitmap_1)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->wxBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, wxBitmap_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bits", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, wxBitmap_2)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bits = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//int depth = arg.GetNumber(3)
	//pThis->GetEntity()->wxBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, wxBitmap_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, wxBitmap_3)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int depth = arg.GetNumber(2)
	//pThis->GetEntity()->wxBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, wxBitmap_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, wxBitmap_4)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int depth = arg.GetNumber(1)
	//pThis->GetEntity()->wxBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, wxBitmap_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bits", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, wxBitmap_5)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bits = arg.GetNumber(0)
	//pThis->GetEntity()->wxBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, wxBitmap_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, wxBitmap_6)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->wxBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, wxBitmap_7)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "img", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, wxBitmap_7)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int img = arg.GetNumber(0)
	//int depth = arg.GetNumber(1)
	//pThis->GetEntity()->wxBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, wxBitmap_8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, wxBitmap_8)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cursor = arg.GetNumber(0)
	//pThis->GetEntity()->wxBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, AddHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, AddHandler)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, CleanUpHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, CleanUpHandlers)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CleanUpHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, ConvertToImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, ConvertToImage)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ConvertToImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, CopyFromIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, CopyFromIcon)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//pThis->GetEntity()->CopyFromIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, Create)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int depth = arg.GetNumber(2)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, Create_1)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int depth = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, Create_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, Create_2)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int dc = arg.GetNumber(2)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, CreateScaled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "logwidth", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "logheight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "logicalScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, CreateScaled)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int logwidth = arg.GetNumber(0)
	//int logheight = arg.GetNumber(1)
	//int depth = arg.GetNumber(2)
	//int logicalScale = arg.GetNumber(3)
	//pThis->GetEntity()->CreateScaled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, FindHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, FindHandler)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->FindHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, FindHandler_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extension", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, FindHandler_1)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extension = arg.GetNumber(0)
	//int bitmapType = arg.GetNumber(1)
	//pThis->GetEntity()->FindHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, FindHandler_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, FindHandler_2)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmapType = arg.GetNumber(0)
	//pThis->GetEntity()->FindHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, GetDepth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, GetDepth)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDepth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, GetHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, GetHandlers)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, GetHeight)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, GetMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, GetMask)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, GetPalette)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, GetPalette)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPalette();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, GetSubBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, GetSubBitmap)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->GetSubBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, GetSize)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, ConvertToDisabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brightness", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, ConvertToDisabled)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int brightness = arg.GetNumber(0)
	//pThis->GetEntity()->ConvertToDisabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, GetWidth)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, InitStandardHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, InitStandardHandlers)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->InitStandardHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, InsertHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, InsertHandler)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->InsertHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, IsOk)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, LoadFile)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, NewFromPNGData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, NewFromPNGData)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->NewFromPNGData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, RemoveHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, RemoveHandler)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, SaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SaveFile)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//int palette = arg.GetNumber(2)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, SetDepth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetDepth)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int depth = arg.GetNumber(0)
	//pThis->GetEntity()->SetDepth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, SetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetHeight)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, SetMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetMask)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mask = arg.GetNumber(0)
	//pThis->GetEntity()->SetMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, SetPalette)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetPalette)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int palette = arg.GetNumber(0)
	//pThis->GetEntity()->SetPalette();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Bitmap, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, SetWidth)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBitmap
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Bitmap)
{
	Gura_AssignMethod(wx_Bitmap, wxBitmap);
	Gura_AssignMethod(wx_Bitmap, wxBitmap_1);
	Gura_AssignMethod(wx_Bitmap, wxBitmap_2);
	Gura_AssignMethod(wx_Bitmap, wxBitmap_3);
	Gura_AssignMethod(wx_Bitmap, wxBitmap_4);
	Gura_AssignMethod(wx_Bitmap, wxBitmap_5);
	Gura_AssignMethod(wx_Bitmap, wxBitmap_6);
	Gura_AssignMethod(wx_Bitmap, wxBitmap_7);
	Gura_AssignMethod(wx_Bitmap, wxBitmap_8);
	Gura_AssignMethod(wx_Bitmap, AddHandler);
	Gura_AssignMethod(wx_Bitmap, CleanUpHandlers);
	Gura_AssignMethod(wx_Bitmap, ConvertToImage);
	Gura_AssignMethod(wx_Bitmap, CopyFromIcon);
	Gura_AssignMethod(wx_Bitmap, Create);
	Gura_AssignMethod(wx_Bitmap, Create_1);
	Gura_AssignMethod(wx_Bitmap, Create_2);
	Gura_AssignMethod(wx_Bitmap, CreateScaled);
	Gura_AssignMethod(wx_Bitmap, FindHandler);
	Gura_AssignMethod(wx_Bitmap, FindHandler_1);
	Gura_AssignMethod(wx_Bitmap, FindHandler_2);
	Gura_AssignMethod(wx_Bitmap, GetDepth);
	Gura_AssignMethod(wx_Bitmap, GetHandlers);
	Gura_AssignMethod(wx_Bitmap, GetHeight);
	Gura_AssignMethod(wx_Bitmap, GetMask);
	Gura_AssignMethod(wx_Bitmap, GetPalette);
	Gura_AssignMethod(wx_Bitmap, GetSubBitmap);
	Gura_AssignMethod(wx_Bitmap, GetSize);
	Gura_AssignMethod(wx_Bitmap, ConvertToDisabled);
	Gura_AssignMethod(wx_Bitmap, GetWidth);
	Gura_AssignMethod(wx_Bitmap, InitStandardHandlers);
	Gura_AssignMethod(wx_Bitmap, InsertHandler);
	Gura_AssignMethod(wx_Bitmap, IsOk);
	Gura_AssignMethod(wx_Bitmap, LoadFile);
	Gura_AssignMethod(wx_Bitmap, NewFromPNGData);
	Gura_AssignMethod(wx_Bitmap, RemoveHandler);
	Gura_AssignMethod(wx_Bitmap, SaveFile);
	Gura_AssignMethod(wx_Bitmap, SetDepth);
	Gura_AssignMethod(wx_Bitmap, SetHeight);
	Gura_AssignMethod(wx_Bitmap, SetMask);
	Gura_AssignMethod(wx_Bitmap, SetPalette);
	Gura_AssignMethod(wx_Bitmap, SetWidth);
}

Gura_ImplementDescendantCreator(wx_Bitmap)
{
	return new Object_wx_Bitmap((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
