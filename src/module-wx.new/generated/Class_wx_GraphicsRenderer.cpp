//----------------------------------------------------------------------------
// wxGraphicsRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsRenderer
//----------------------------------------------------------------------------
Object_wx_GraphicsRenderer::~Object_wx_GraphicsRenderer()
{
}

Object *Object_wx_GraphicsRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsRenderer:");
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
Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateBitmap, "CreateBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateBitmap)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//wxGraphicsBitmap _rtn = pThis->GetEntity()->CreateBitmap(bitmap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateBitmapFromImage, "CreateBitmapFromImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateBitmapFromImage)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxImage& image = arg.GetNumber(0)
	//wxGraphicsBitmap _rtn = pThis->GetEntity()->CreateBitmapFromImage(image);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateImageFromBitmap, "CreateImageFromBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateImageFromBitmap)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsBitmap& bmp = arg.GetNumber(0)
	//wxImage _rtn = pThis->GetEntity()->CreateImageFromBitmap(bmp);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateBitmapFromNativeBitmap, "CreateBitmapFromNativeBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateBitmapFromNativeBitmap)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* bitmap = arg.GetNumber(0)
	//wxGraphicsBitmap _rtn = pThis->GetEntity()->CreateBitmapFromNativeBitmap(bitmap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateContext, "CreateContext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateContext)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//wxGraphicsContext* _rtn = pThis->GetEntity()->CreateContext(window);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateContext_1, "CreateContext_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "windowDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateContext_1)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxWindowDC& windowDC = arg.GetNumber(0)
	//wxGraphicsContext* _rtn = pThis->GetEntity()->CreateContext(windowDC);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateContext_2, "CreateContext_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "memoryDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateContext_2)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxMemoryDC& memoryDC = arg.GetNumber(0)
	//wxGraphicsContext* _rtn = pThis->GetEntity()->CreateContext(memoryDC);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateContext_3, "CreateContext_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "printerDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateContext_3)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPrinterDC& printerDC = arg.GetNumber(0)
	//wxGraphicsContext* _rtn = pThis->GetEntity()->CreateContext(printerDC);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateContext_4, "CreateContext_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "metaFileDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateContext_4)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxEnhMetaFileDC& metaFileDC = arg.GetNumber(0)
	//wxGraphicsContext* _rtn = pThis->GetEntity()->CreateContext(metaFileDC);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateContextFromImage, "CreateContextFromImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateContextFromImage)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImage& image = arg.GetNumber(0)
	//wxGraphicsContext* _rtn = pThis->GetEntity()->CreateContextFromImage(image);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateBrush, "CreateBrush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateBrush)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBrush& brush = arg.GetNumber(0)
	//wxGraphicsBrush _rtn = pThis->GetEntity()->CreateBrush(brush);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateContextFromNativeContext, "CreateContextFromNativeContext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateContextFromNativeContext)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* context = arg.GetNumber(0)
	//wxGraphicsContext* _rtn = pThis->GetEntity()->CreateContextFromNativeContext(context);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateContextFromNativeWindow, "CreateContextFromNativeWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateContextFromNativeWindow)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* window = arg.GetNumber(0)
	//wxGraphicsContext* _rtn = pThis->GetEntity()->CreateContextFromNativeWindow(window);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateMeasuringContext, "CreateMeasuringContext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateMeasuringContext)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGraphicsContext* _rtn = pThis->GetEntity()->CreateMeasuringContext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateFont, "CreateFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateFont)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//const wxColour& col = arg.GetNumber(1)
	//wxGraphicsFont _rtn = pThis->GetEntity()->CreateFont(font, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateFont_1, "CreateFont_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "sizeInPixels", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateFont_1)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double sizeInPixels = arg.GetNumber(0)
	//const wxString& facename = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//const wxColour& col = arg.GetNumber(3)
	//wxGraphicsFont _rtn = pThis->GetEntity()->CreateFont(sizeInPixels, facename, flags, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateLinearGradientBrush, "CreateLinearGradientBrush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stops", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateLinearGradientBrush)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble x1 = arg.GetNumber(0)
	//wxDouble y1 = arg.GetNumber(1)
	//wxDouble x2 = arg.GetNumber(2)
	//wxDouble y2 = arg.GetNumber(3)
	//const wxGraphicsGradientStops& stops = arg.GetNumber(4)
	//wxGraphicsBrush _rtn = pThis->GetEntity()->CreateLinearGradientBrush(x1, y1, x2, y2, stops);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateMatrix, "CreateMatrix")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "a", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateMatrix)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble a = arg.GetNumber(0)
	//wxDouble b = arg.GetNumber(1)
	//wxDouble c = arg.GetNumber(2)
	//wxDouble d = arg.GetNumber(3)
	//wxDouble tx = arg.GetNumber(4)
	//wxDouble ty = arg.GetNumber(5)
	//wxGraphicsMatrix _rtn = pThis->GetEntity()->CreateMatrix(a, b, c, d, tx, ty);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreatePath, "CreatePath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreatePath)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGraphicsPath _rtn = pThis->GetEntity()->CreatePath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreatePen, "CreatePen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreatePen)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPen& pen = arg.GetNumber(0)
	//wxGraphicsPen _rtn = pThis->GetEntity()->CreatePen(pen);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateRadialGradientBrush, "CreateRadialGradientBrush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "xo", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yo", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stops", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateRadialGradientBrush)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDouble xo = arg.GetNumber(0)
	//wxDouble yo = arg.GetNumber(1)
	//wxDouble xc = arg.GetNumber(2)
	//wxDouble yc = arg.GetNumber(3)
	//wxDouble radius = arg.GetNumber(4)
	//const wxGraphicsGradientStops& stops = arg.GetNumber(5)
	//wxGraphicsBrush _rtn = pThis->GetEntity()->CreateRadialGradientBrush(xo, yo, xc, yc, radius, stops);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __CreateSubBitmap, "CreateSubBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __CreateSubBitmap)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsBitmap& bitmap = arg.GetNumber(0)
	//wxDouble x = arg.GetNumber(1)
	//wxDouble y = arg.GetNumber(2)
	//wxDouble w = arg.GetNumber(3)
	//wxDouble h = arg.GetNumber(4)
	//wxGraphicsBitmap _rtn = pThis->GetEntity()->CreateSubBitmap(bitmap, x, y, w, h);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __GetName)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __GetVersion, "GetVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "micro", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __GetVersion)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int* major = arg.GetNumber(0)
	//int* minor = arg.GetNumber(1)
	//int* micro = arg.GetNumber(2)
	//pThis->GetEntity()->GetVersion(major, minor, micro);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __GetDefaultRenderer, "GetDefaultRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __GetDefaultRenderer)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGraphicsRenderer* _rtn = pThis->GetEntity()->GetDefaultRenderer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsRenderer, __GetCairoRenderer, "GetCairoRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsRenderer, __GetCairoRenderer)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGraphicsRenderer* _rtn = pThis->GetEntity()->GetCairoRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsRenderer)
{
	// Class assignment
	Gura_AssignValueEx("GraphicsRenderer", Reference());
	// Method assignment
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateBitmap);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateBitmapFromImage);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateImageFromBitmap);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateBitmapFromNativeBitmap);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateContext);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateContext_1);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateContext_2);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateContext_3);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateContext_4);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateContextFromImage);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateBrush);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateContextFromNativeContext);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateContextFromNativeWindow);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateMeasuringContext);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateFont);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateFont_1);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateLinearGradientBrush);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateMatrix);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreatePath);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreatePen);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateRadialGradientBrush);
	Gura_AssignMethod(wx_GraphicsRenderer, __CreateSubBitmap);
	Gura_AssignMethod(wx_GraphicsRenderer, __GetName);
	Gura_AssignMethod(wx_GraphicsRenderer, __GetVersion);
	Gura_AssignMethod(wx_GraphicsRenderer, __GetDefaultRenderer);
	Gura_AssignMethod(wx_GraphicsRenderer, __GetCairoRenderer);
}

Gura_ImplementDescendantCreator(wx_GraphicsRenderer)
{
	return new Object_wx_GraphicsRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
