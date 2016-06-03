//----------------------------------------------------------------------------
// wxGraphicsContext
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsContext
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsContext
//----------------------------------------------------------------------------
Object_wx_GraphicsContext::~Object_wx_GraphicsContext()
{
}

Object *Object_wx_GraphicsContext::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsContext::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsContext:");
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
Gura_DeclareMethodAlias(wx_GraphicsContext, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __Create)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __Create_1, "Create_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "windowDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __Create_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxWindowDC& windowDC = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __Create_2, "Create_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "memoryDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __Create_2)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxMemoryDC& memoryDC = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __Create_3, "Create_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printerDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __Create_3)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPrinterDC& printerDC = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __Create_4, "Create_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "metaFileDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __Create_4)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxEnhMetaFileDC& metaFileDC = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __Create_5, "Create_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __Create_5)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImage& image = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __Create_6, "Create_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __Create_6)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __Clip, "Clip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __Clip)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRegion& region = arg.GetNumber(0)
	//pThis->GetEntity()->Clip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __Clip_1, "Clip_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __Clip_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble x = arg.GetNumber(0)
	//wxDouble y = arg.GetNumber(1)
	//wxDouble w = arg.GetNumber(2)
	//wxDouble h = arg.GetNumber(3)
	//pThis->GetEntity()->Clip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __ConcatTransform, "ConcatTransform")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "matrix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __ConcatTransform)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsMatrix& matrix = arg.GetNumber(0)
	//pThis->GetEntity()->ConcatTransform();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreateBitmap, "CreateBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreateBitmap)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->CreateBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreateBitmapFromImage, "CreateBitmapFromImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreateBitmapFromImage)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxImage& image = arg.GetNumber(0)
	//pThis->GetEntity()->CreateBitmapFromImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreateSubBitmap, "CreateSubBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreateSubBitmap)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsBitmap& bitmap = arg.GetNumber(0)
	//wxDouble x = arg.GetNumber(1)
	//wxDouble y = arg.GetNumber(2)
	//wxDouble w = arg.GetNumber(3)
	//wxDouble h = arg.GetNumber(4)
	//pThis->GetEntity()->CreateSubBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreateBrush, "CreateBrush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreateBrush)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBrush& brush = arg.GetNumber(0)
	//pThis->GetEntity()->CreateBrush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreateFont, "CreateFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreateFont)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//const wxColour& col = arg.GetNumber(1)
	//pThis->GetEntity()->CreateFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreateFont_1, "CreateFont_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizeInPixels", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreateFont_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double sizeInPixels = arg.GetNumber(0)
	//const wxString& facename = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//const wxColour& col = arg.GetNumber(3)
	//pThis->GetEntity()->CreateFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreateFromNative, "CreateFromNative")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreateFromNative)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* context = arg.GetNumber(0)
	//pThis->GetEntity()->CreateFromNative();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreateFromNativeWindow, "CreateFromNativeWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreateFromNativeWindow)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* window = arg.GetNumber(0)
	//pThis->GetEntity()->CreateFromNativeWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreateLinearGradientBrush, "CreateLinearGradientBrush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "c1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "c2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreateLinearGradientBrush)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble x1 = arg.GetNumber(0)
	//wxDouble y1 = arg.GetNumber(1)
	//wxDouble x2 = arg.GetNumber(2)
	//wxDouble y2 = arg.GetNumber(3)
	//const wxColour& c1 = arg.GetNumber(4)
	//const wxColour& c2 = arg.GetNumber(5)
	//pThis->GetEntity()->CreateLinearGradientBrush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreateLinearGradientBrush_1, "CreateLinearGradientBrush_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stops", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreateLinearGradientBrush_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble x1 = arg.GetNumber(0)
	//wxDouble y1 = arg.GetNumber(1)
	//wxDouble x2 = arg.GetNumber(2)
	//wxDouble y2 = arg.GetNumber(3)
	//const wxGraphicsGradientStops& stops = arg.GetNumber(4)
	//pThis->GetEntity()->CreateLinearGradientBrush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreateMatrix, "CreateMatrix")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "a", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreateMatrix)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble a = arg.GetNumber(0)
	//wxDouble b = arg.GetNumber(1)
	//wxDouble c = arg.GetNumber(2)
	//wxDouble d = arg.GetNumber(3)
	//wxDouble tx = arg.GetNumber(4)
	//wxDouble ty = arg.GetNumber(5)
	//pThis->GetEntity()->CreateMatrix();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreateMatrix_1, "CreateMatrix_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreateMatrix_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxAffineMatrix2DBase& mat = arg.GetNumber(0)
	//pThis->GetEntity()->CreateMatrix();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreatePath, "CreatePath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreatePath)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreatePath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreatePen, "CreatePen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreatePen)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPen& pen = arg.GetNumber(0)
	//pThis->GetEntity()->CreatePen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreateRadialGradientBrush, "CreateRadialGradientBrush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xo", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yo", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oColor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cColor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreateRadialGradientBrush)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble xo = arg.GetNumber(0)
	//wxDouble yo = arg.GetNumber(1)
	//wxDouble xc = arg.GetNumber(2)
	//wxDouble yc = arg.GetNumber(3)
	//wxDouble radius = arg.GetNumber(4)
	//const wxColour& oColor = arg.GetNumber(5)
	//const wxColour& cColor = arg.GetNumber(6)
	//pThis->GetEntity()->CreateRadialGradientBrush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __CreateRadialGradientBrush_1, "CreateRadialGradientBrush_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xo", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yo", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stops", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __CreateRadialGradientBrush_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble xo = arg.GetNumber(0)
	//wxDouble yo = arg.GetNumber(1)
	//wxDouble xc = arg.GetNumber(2)
	//wxDouble yc = arg.GetNumber(3)
	//wxDouble radius = arg.GetNumber(4)
	//const wxGraphicsGradientStops& stops = arg.GetNumber(5)
	//pThis->GetEntity()->CreateRadialGradientBrush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __DrawBitmap, "DrawBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __DrawBitmap)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsBitmap& bmp = arg.GetNumber(0)
	//wxDouble x = arg.GetNumber(1)
	//wxDouble y = arg.GetNumber(2)
	//wxDouble w = arg.GetNumber(3)
	//wxDouble h = arg.GetNumber(4)
	//pThis->GetEntity()->DrawBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __DrawBitmap_1, "DrawBitmap_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __DrawBitmap_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bmp = arg.GetNumber(0)
	//wxDouble x = arg.GetNumber(1)
	//wxDouble y = arg.GetNumber(2)
	//wxDouble w = arg.GetNumber(3)
	//wxDouble h = arg.GetNumber(4)
	//pThis->GetEntity()->DrawBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __DrawEllipse, "DrawEllipse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __DrawEllipse)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble x = arg.GetNumber(0)
	//wxDouble y = arg.GetNumber(1)
	//wxDouble w = arg.GetNumber(2)
	//wxDouble h = arg.GetNumber(3)
	//pThis->GetEntity()->DrawEllipse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __DrawIcon, "DrawIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __DrawIcon)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxIcon& icon = arg.GetNumber(0)
	//wxDouble x = arg.GetNumber(1)
	//wxDouble y = arg.GetNumber(2)
	//wxDouble w = arg.GetNumber(3)
	//wxDouble h = arg.GetNumber(4)
	//pThis->GetEntity()->DrawIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __DrawLines, "DrawLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __DrawLines)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//const wxPoint2DDouble* points = arg.GetNumber(1)
	//wxPolygonFillMode fillStyle = arg.GetNumber(2)
	//pThis->GetEntity()->DrawLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __DrawPath, "DrawPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __DrawPath)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsPath& path = arg.GetNumber(0)
	//wxPolygonFillMode fillStyle = arg.GetNumber(1)
	//pThis->GetEntity()->DrawPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __DrawRectangle, "DrawRectangle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __DrawRectangle)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble x = arg.GetNumber(0)
	//wxDouble y = arg.GetNumber(1)
	//wxDouble w = arg.GetNumber(2)
	//wxDouble h = arg.GetNumber(3)
	//pThis->GetEntity()->DrawRectangle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __DrawRoundedRectangle, "DrawRoundedRectangle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __DrawRoundedRectangle)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble x = arg.GetNumber(0)
	//wxDouble y = arg.GetNumber(1)
	//wxDouble w = arg.GetNumber(2)
	//wxDouble h = arg.GetNumber(3)
	//wxDouble radius = arg.GetNumber(4)
	//pThis->GetEntity()->DrawRoundedRectangle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __DrawText, "DrawText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __DrawText)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//wxDouble x = arg.GetNumber(1)
	//wxDouble y = arg.GetNumber(2)
	//pThis->GetEntity()->DrawText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __DrawText_1, "DrawText_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __DrawText_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//wxDouble x = arg.GetNumber(1)
	//wxDouble y = arg.GetNumber(2)
	//wxDouble angle = arg.GetNumber(3)
	//pThis->GetEntity()->DrawText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __DrawText_2, "DrawText_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "backgroundBrush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __DrawText_2)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//wxDouble x = arg.GetNumber(1)
	//wxDouble y = arg.GetNumber(2)
	//const wxGraphicsBrush& backgroundBrush = arg.GetNumber(3)
	//pThis->GetEntity()->DrawText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __DrawText_3, "DrawText_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "backgroundBrush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __DrawText_3)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//wxDouble x = arg.GetNumber(1)
	//wxDouble y = arg.GetNumber(2)
	//wxDouble angle = arg.GetNumber(3)
	//const wxGraphicsBrush& backgroundBrush = arg.GetNumber(4)
	//pThis->GetEntity()->DrawText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __FillPath, "FillPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __FillPath)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsPath& path = arg.GetNumber(0)
	//wxPolygonFillMode fillStyle = arg.GetNumber(1)
	//pThis->GetEntity()->FillPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __GetNativeContext, "GetNativeContext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __GetNativeContext)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNativeContext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __GetPartialTextExtents, "GetPartialTextExtents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "widths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __GetPartialTextExtents)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//wxArrayDouble& widths = arg.GetNumber(1)
	//pThis->GetEntity()->GetPartialTextExtents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __GetTextExtent, "GetTextExtent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "externalLeading", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __GetTextExtent)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//wxDouble* width = arg.GetNumber(1)
	//wxDouble* height = arg.GetNumber(2)
	//wxDouble* descent = arg.GetNumber(3)
	//wxDouble* externalLeading = arg.GetNumber(4)
	//pThis->GetEntity()->GetTextExtent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __GetTransform, "GetTransform")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __GetTransform)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTransform();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __ResetClip, "ResetClip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __ResetClip)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResetClip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __Rotate, "Rotate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __Rotate)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble angle = arg.GetNumber(0)
	//pThis->GetEntity()->Rotate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __Scale, "Scale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xScale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __Scale)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble xScale = arg.GetNumber(0)
	//wxDouble yScale = arg.GetNumber(1)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __SetBrush, "SetBrush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __SetBrush)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBrush& brush = arg.GetNumber(0)
	//pThis->GetEntity()->SetBrush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __SetBrush_1, "SetBrush_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __SetBrush_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsBrush& brush = arg.GetNumber(0)
	//pThis->GetEntity()->SetBrush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __SetFont)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//const wxColour& colour = arg.GetNumber(1)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __SetFont_1, "SetFont_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __SetFont_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __SetPen, "SetPen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __SetPen)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPen& pen = arg.GetNumber(0)
	//pThis->GetEntity()->SetPen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __SetPen_1, "SetPen_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __SetPen_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsPen& pen = arg.GetNumber(0)
	//pThis->GetEntity()->SetPen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __SetTransform, "SetTransform")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "matrix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __SetTransform)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsMatrix& matrix = arg.GetNumber(0)
	//pThis->GetEntity()->SetTransform();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __StrokeLine, "StrokeLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __StrokeLine)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble x1 = arg.GetNumber(0)
	//wxDouble y1 = arg.GetNumber(1)
	//wxDouble x2 = arg.GetNumber(2)
	//wxDouble y2 = arg.GetNumber(3)
	//pThis->GetEntity()->StrokeLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __StrokeLines, "StrokeLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "beginPoints", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPoints", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __StrokeLines)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//const wxPoint2DDouble* beginPoints = arg.GetNumber(1)
	//const wxPoint2DDouble* endPoints = arg.GetNumber(2)
	//pThis->GetEntity()->StrokeLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __StrokeLines_1, "StrokeLines_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __StrokeLines_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//const wxPoint2DDouble* points = arg.GetNumber(1)
	//pThis->GetEntity()->StrokeLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __StrokePath, "StrokePath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __StrokePath)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsPath& path = arg.GetNumber(0)
	//pThis->GetEntity()->StrokePath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __Translate, "Translate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __Translate)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble dx = arg.GetNumber(0)
	//wxDouble dy = arg.GetNumber(1)
	//pThis->GetEntity()->Translate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __BeginLayer, "BeginLayer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "opacity", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __BeginLayer)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble opacity = arg.GetNumber(0)
	//pThis->GetEntity()->BeginLayer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __EndLayer, "EndLayer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __EndLayer)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndLayer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __SetAntialiasMode, "SetAntialiasMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "antialias", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __SetAntialiasMode)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAntialiasMode antialias = arg.GetNumber(0)
	//pThis->GetEntity()->SetAntialiasMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __GetAntialiasMode, "GetAntialiasMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __GetAntialiasMode)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAntialiasMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __SetInterpolationQuality, "SetInterpolationQuality")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "interpolation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __SetInterpolationQuality)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInterpolationQuality interpolation = arg.GetNumber(0)
	//pThis->GetEntity()->SetInterpolationQuality();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __GetInterpolationQuality, "GetInterpolationQuality")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __GetInterpolationQuality)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInterpolationQuality();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __SetCompositionMode, "SetCompositionMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "op", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __SetCompositionMode)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCompositionMode op = arg.GetNumber(0)
	//pThis->GetEntity()->SetCompositionMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __GetCompositionMode, "GetCompositionMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __GetCompositionMode)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCompositionMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __PushState, "PushState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __PushState)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PushState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __PopState, "PopState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __PopState)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PopState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __ShouldOffset, "ShouldOffset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __ShouldOffset)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShouldOffset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __EnableOffset, "EnableOffset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __EnableOffset)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableOffset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __DisableOffset, "DisableOffset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __DisableOffset)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisableOffset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __OffsetEnabled, "OffsetEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __OffsetEnabled)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OffsetEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __StartDoc, "StartDoc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __StartDoc)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& message = arg.GetNumber(0)
	//pThis->GetEntity()->StartDoc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __EndDoc, "EndDoc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __EndDoc)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndDoc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __StartPage, "StartPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __StartPage)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble width = arg.GetNumber(0)
	//wxDouble height = arg.GetNumber(1)
	//pThis->GetEntity()->StartPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __EndPage, "EndPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __EndPage)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __Flush, "Flush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, __Flush)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __GetSize)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble* width = arg.GetNumber(0)
	//wxDouble* height = arg.GetNumber(1)
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsContext, __GetDPI, "GetDPI")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dpiX", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dpiY", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, __GetDPI)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble* dpiX = arg.GetNumber(0)
	//wxDouble* dpiY = arg.GetNumber(1)
	//pThis->GetEntity()->GetDPI();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsContext)
{
	// Class assignment
	Gura_AssignValueEx("GraphicsContext", Reference());
	// Method assignment
	Gura_AssignMethod(wx_GraphicsContext, __Create);
	Gura_AssignMethod(wx_GraphicsContext, __Create_1);
	Gura_AssignMethod(wx_GraphicsContext, __Create_2);
	Gura_AssignMethod(wx_GraphicsContext, __Create_3);
	Gura_AssignMethod(wx_GraphicsContext, __Create_4);
	Gura_AssignMethod(wx_GraphicsContext, __Create_5);
	Gura_AssignMethod(wx_GraphicsContext, __Create_6);
	Gura_AssignMethod(wx_GraphicsContext, __Clip);
	Gura_AssignMethod(wx_GraphicsContext, __Clip_1);
	Gura_AssignMethod(wx_GraphicsContext, __ConcatTransform);
	Gura_AssignMethod(wx_GraphicsContext, __CreateBitmap);
	Gura_AssignMethod(wx_GraphicsContext, __CreateBitmapFromImage);
	Gura_AssignMethod(wx_GraphicsContext, __CreateSubBitmap);
	Gura_AssignMethod(wx_GraphicsContext, __CreateBrush);
	Gura_AssignMethod(wx_GraphicsContext, __CreateFont);
	Gura_AssignMethod(wx_GraphicsContext, __CreateFont_1);
	Gura_AssignMethod(wx_GraphicsContext, __CreateFromNative);
	Gura_AssignMethod(wx_GraphicsContext, __CreateFromNativeWindow);
	Gura_AssignMethod(wx_GraphicsContext, __CreateLinearGradientBrush);
	Gura_AssignMethod(wx_GraphicsContext, __CreateLinearGradientBrush_1);
	Gura_AssignMethod(wx_GraphicsContext, __CreateMatrix);
	Gura_AssignMethod(wx_GraphicsContext, __CreateMatrix_1);
	Gura_AssignMethod(wx_GraphicsContext, __CreatePath);
	Gura_AssignMethod(wx_GraphicsContext, __CreatePen);
	Gura_AssignMethod(wx_GraphicsContext, __CreateRadialGradientBrush);
	Gura_AssignMethod(wx_GraphicsContext, __CreateRadialGradientBrush_1);
	Gura_AssignMethod(wx_GraphicsContext, __DrawBitmap);
	Gura_AssignMethod(wx_GraphicsContext, __DrawBitmap_1);
	Gura_AssignMethod(wx_GraphicsContext, __DrawEllipse);
	Gura_AssignMethod(wx_GraphicsContext, __DrawIcon);
	Gura_AssignMethod(wx_GraphicsContext, __DrawLines);
	Gura_AssignMethod(wx_GraphicsContext, __DrawPath);
	Gura_AssignMethod(wx_GraphicsContext, __DrawRectangle);
	Gura_AssignMethod(wx_GraphicsContext, __DrawRoundedRectangle);
	Gura_AssignMethod(wx_GraphicsContext, __DrawText);
	Gura_AssignMethod(wx_GraphicsContext, __DrawText_1);
	Gura_AssignMethod(wx_GraphicsContext, __DrawText_2);
	Gura_AssignMethod(wx_GraphicsContext, __DrawText_3);
	Gura_AssignMethod(wx_GraphicsContext, __FillPath);
	Gura_AssignMethod(wx_GraphicsContext, __GetNativeContext);
	Gura_AssignMethod(wx_GraphicsContext, __GetPartialTextExtents);
	Gura_AssignMethod(wx_GraphicsContext, __GetTextExtent);
	Gura_AssignMethod(wx_GraphicsContext, __GetTransform);
	Gura_AssignMethod(wx_GraphicsContext, __ResetClip);
	Gura_AssignMethod(wx_GraphicsContext, __Rotate);
	Gura_AssignMethod(wx_GraphicsContext, __Scale);
	Gura_AssignMethod(wx_GraphicsContext, __SetBrush);
	Gura_AssignMethod(wx_GraphicsContext, __SetBrush_1);
	Gura_AssignMethod(wx_GraphicsContext, __SetFont);
	Gura_AssignMethod(wx_GraphicsContext, __SetFont_1);
	Gura_AssignMethod(wx_GraphicsContext, __SetPen);
	Gura_AssignMethod(wx_GraphicsContext, __SetPen_1);
	Gura_AssignMethod(wx_GraphicsContext, __SetTransform);
	Gura_AssignMethod(wx_GraphicsContext, __StrokeLine);
	Gura_AssignMethod(wx_GraphicsContext, __StrokeLines);
	Gura_AssignMethod(wx_GraphicsContext, __StrokeLines_1);
	Gura_AssignMethod(wx_GraphicsContext, __StrokePath);
	Gura_AssignMethod(wx_GraphicsContext, __Translate);
	Gura_AssignMethod(wx_GraphicsContext, __BeginLayer);
	Gura_AssignMethod(wx_GraphicsContext, __EndLayer);
	Gura_AssignMethod(wx_GraphicsContext, __SetAntialiasMode);
	Gura_AssignMethod(wx_GraphicsContext, __GetAntialiasMode);
	Gura_AssignMethod(wx_GraphicsContext, __SetInterpolationQuality);
	Gura_AssignMethod(wx_GraphicsContext, __GetInterpolationQuality);
	Gura_AssignMethod(wx_GraphicsContext, __SetCompositionMode);
	Gura_AssignMethod(wx_GraphicsContext, __GetCompositionMode);
	Gura_AssignMethod(wx_GraphicsContext, __PushState);
	Gura_AssignMethod(wx_GraphicsContext, __PopState);
	Gura_AssignMethod(wx_GraphicsContext, __ShouldOffset);
	Gura_AssignMethod(wx_GraphicsContext, __EnableOffset);
	Gura_AssignMethod(wx_GraphicsContext, __DisableOffset);
	Gura_AssignMethod(wx_GraphicsContext, __OffsetEnabled);
	Gura_AssignMethod(wx_GraphicsContext, __StartDoc);
	Gura_AssignMethod(wx_GraphicsContext, __EndDoc);
	Gura_AssignMethod(wx_GraphicsContext, __StartPage);
	Gura_AssignMethod(wx_GraphicsContext, __EndPage);
	Gura_AssignMethod(wx_GraphicsContext, __Flush);
	Gura_AssignMethod(wx_GraphicsContext, __GetSize);
	Gura_AssignMethod(wx_GraphicsContext, __GetDPI);
}

Gura_ImplementDescendantCreator(wx_GraphicsContext)
{
	return new Object_wx_GraphicsContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
