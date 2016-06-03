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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Bitmap, "Bitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Bitmap)
{
	//wxBitmap();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Bitmap_1, "Bitmap_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Bitmap_1)
{
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//wxBitmap();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Bitmap_2, "Bitmap_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bits", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Bitmap_2)
{
	//const char bits = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//int depth = arg.GetNumber(3)
	//wxBitmap();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Bitmap_3, "Bitmap_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Bitmap_3)
{
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int depth = arg.GetNumber(2)
	//wxBitmap();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Bitmap_4, "Bitmap_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Bitmap_4)
{
	//const wxSize& sz = arg.GetNumber(0)
	//int depth = arg.GetNumber(1)
	//wxBitmap();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Bitmap_5, "Bitmap_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bits", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Bitmap_5)
{
	//const char* const* bits = arg.GetNumber(0)
	//wxBitmap();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Bitmap_6, "Bitmap_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Bitmap_6)
{
	//const wxString& name = arg.GetNumber(0)
	//wxBitmapType type = arg.GetNumber(1)
	//wxBitmap();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Bitmap_7, "Bitmap_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "img", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Bitmap_7)
{
	//const wxImage& img = arg.GetNumber(0)
	//int depth = arg.GetNumber(1)
	//wxBitmap();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Bitmap_8, "Bitmap_8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Bitmap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Bitmap_8)
{
	//const wxCursor& cursor = arg.GetNumber(0)
	//wxBitmap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Bitmap, __AddHandler, "AddHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __AddHandler)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBitmapHandler* handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __CleanUpHandlers, "CleanUpHandlers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, __CleanUpHandlers)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CleanUpHandlers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __ConvertToImage, "ConvertToImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, __ConvertToImage)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ConvertToImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __CopyFromIcon, "CopyFromIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __CopyFromIcon)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxIcon& icon = arg.GetNumber(0)
	//pThis->GetEntity()->CopyFromIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __Create)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int depth = arg.GetNumber(2)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __Create_1, "Create_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __Create_1)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& sz = arg.GetNumber(0)
	//int depth = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __Create_2, "Create_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __Create_2)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//const wxDC& dc = arg.GetNumber(2)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __CreateScaled, "CreateScaled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "logwidth", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "logheight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "logicalScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __CreateScaled)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int logwidth = arg.GetNumber(0)
	//int logheight = arg.GetNumber(1)
	//int depth = arg.GetNumber(2)
	//double logicalScale = arg.GetNumber(3)
	//pThis->GetEntity()->CreateScaled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __FindHandler, "FindHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __FindHandler)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->FindHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __FindHandler_1, "FindHandler_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extension", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __FindHandler_1)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& extension = arg.GetNumber(0)
	//wxBitmapType bitmapType = arg.GetNumber(1)
	//pThis->GetEntity()->FindHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __FindHandler_2, "FindHandler_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __FindHandler_2)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBitmapType bitmapType = arg.GetNumber(0)
	//pThis->GetEntity()->FindHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __GetDepth, "GetDepth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, __GetDepth)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDepth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __GetHandlers, "GetHandlers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, __GetHandlers)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHandlers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __GetHeight, "GetHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, __GetHeight)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __GetMask, "GetMask")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, __GetMask)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMask();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __GetPalette, "GetPalette")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, __GetPalette)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPalette();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __GetSubBitmap, "GetSubBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __GetSubBitmap)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->GetSubBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, __GetSize)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __ConvertToDisabled, "ConvertToDisabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brightness", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __ConvertToDisabled)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned char brightness = arg.GetNumber(0)
	//pThis->GetEntity()->ConvertToDisabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, __GetWidth)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __InitStandardHandlers, "InitStandardHandlers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, __InitStandardHandlers)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->InitStandardHandlers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __InsertHandler, "InsertHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __InsertHandler)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBitmapHandler* handler = arg.GetNumber(0)
	//pThis->GetEntity()->InsertHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Bitmap, __IsOk)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __LoadFile)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxBitmapType type = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __NewFromPNGData, "NewFromPNGData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __NewFromPNGData)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const void* data = arg.GetNumber(0)
	//size_t size = arg.GetNumber(1)
	//pThis->GetEntity()->NewFromPNGData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __RemoveHandler, "RemoveHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __RemoveHandler)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __SaveFile, "SaveFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __SaveFile)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxBitmapType type = arg.GetNumber(1)
	//const wxPalette* palette = arg.GetNumber(2)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __SetDepth, "SetDepth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __SetDepth)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int depth = arg.GetNumber(0)
	//pThis->GetEntity()->SetDepth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __SetHeight, "SetHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __SetHeight)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __SetMask, "SetMask")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __SetMask)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMask* mask = arg.GetNumber(0)
	//pThis->GetEntity()->SetMask();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __SetPalette, "SetPalette")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __SetPalette)
{
	Object_wx_Bitmap *pThis = Object_wx_Bitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPalette& palette = arg.GetNumber(0)
	//pThis->GetEntity()->SetPalette();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Bitmap, __SetWidth, "SetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Bitmap, __SetWidth)
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
	// Constructor assignment
	Gura_AssignFunction(__Bitmap);
	Gura_AssignFunction(__Bitmap_1);
	Gura_AssignFunction(__Bitmap_2);
	Gura_AssignFunction(__Bitmap_3);
	Gura_AssignFunction(__Bitmap_4);
	Gura_AssignFunction(__Bitmap_5);
	Gura_AssignFunction(__Bitmap_6);
	Gura_AssignFunction(__Bitmap_7);
	Gura_AssignFunction(__Bitmap_8);
	// Method assignment
	Gura_AssignMethod(wx_Bitmap, __AddHandler);
	Gura_AssignMethod(wx_Bitmap, __CleanUpHandlers);
	Gura_AssignMethod(wx_Bitmap, __ConvertToImage);
	Gura_AssignMethod(wx_Bitmap, __CopyFromIcon);
	Gura_AssignMethod(wx_Bitmap, __Create);
	Gura_AssignMethod(wx_Bitmap, __Create_1);
	Gura_AssignMethod(wx_Bitmap, __Create_2);
	Gura_AssignMethod(wx_Bitmap, __CreateScaled);
	Gura_AssignMethod(wx_Bitmap, __FindHandler);
	Gura_AssignMethod(wx_Bitmap, __FindHandler_1);
	Gura_AssignMethod(wx_Bitmap, __FindHandler_2);
	Gura_AssignMethod(wx_Bitmap, __GetDepth);
	Gura_AssignMethod(wx_Bitmap, __GetHandlers);
	Gura_AssignMethod(wx_Bitmap, __GetHeight);
	Gura_AssignMethod(wx_Bitmap, __GetMask);
	Gura_AssignMethod(wx_Bitmap, __GetPalette);
	Gura_AssignMethod(wx_Bitmap, __GetSubBitmap);
	Gura_AssignMethod(wx_Bitmap, __GetSize);
	Gura_AssignMethod(wx_Bitmap, __ConvertToDisabled);
	Gura_AssignMethod(wx_Bitmap, __GetWidth);
	Gura_AssignMethod(wx_Bitmap, __InitStandardHandlers);
	Gura_AssignMethod(wx_Bitmap, __InsertHandler);
	Gura_AssignMethod(wx_Bitmap, __IsOk);
	Gura_AssignMethod(wx_Bitmap, __LoadFile);
	Gura_AssignMethod(wx_Bitmap, __NewFromPNGData);
	Gura_AssignMethod(wx_Bitmap, __RemoveHandler);
	Gura_AssignMethod(wx_Bitmap, __SaveFile);
	Gura_AssignMethod(wx_Bitmap, __SetDepth);
	Gura_AssignMethod(wx_Bitmap, __SetHeight);
	Gura_AssignMethod(wx_Bitmap, __SetMask);
	Gura_AssignMethod(wx_Bitmap, __SetPalette);
	Gura_AssignMethod(wx_Bitmap, __SetWidth);
}

Gura_ImplementDescendantCreator(wx_Bitmap)
{
	return new Object_wx_Bitmap((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
