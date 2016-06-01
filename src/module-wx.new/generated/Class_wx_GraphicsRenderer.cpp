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
Gura_DeclareMethod(wx_GraphicsRenderer, CreateBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->CreateBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateBitmapFromImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateBitmapFromImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//pThis->GetEntity()->CreateBitmapFromImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateImageFromBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateImageFromBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//pThis->GetEntity()->CreateImageFromBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateBitmapFromNativeBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateBitmapFromNativeBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->CreateBitmapFromNativeBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateContext)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->CreateContext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateContext_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "windowDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateContext_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int windowDC = arg.GetNumber(0)
	//pThis->GetEntity()->CreateContext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateContext_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "memoryDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateContext_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int memoryDC = arg.GetNumber(0)
	//pThis->GetEntity()->CreateContext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateContext_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printerDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateContext_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int printerDC = arg.GetNumber(0)
	//pThis->GetEntity()->CreateContext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateContext_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "metaFileDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateContext_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int metaFileDC = arg.GetNumber(0)
	//pThis->GetEntity()->CreateContext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateContextFromImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateContextFromImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//pThis->GetEntity()->CreateContextFromImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateBrush)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int brush = arg.GetNumber(0)
	//pThis->GetEntity()->CreateBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateContextFromNativeContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateContextFromNativeContext)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//pThis->GetEntity()->CreateContextFromNativeContext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateContextFromNativeWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateContextFromNativeWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->CreateContextFromNativeWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateMeasuringContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateMeasuringContext)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CreateMeasuringContext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->CreateFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateFont_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizeInPixels", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateFont_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizeInPixels = arg.GetNumber(0)
	//int facename = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int col = arg.GetNumber(3)
	//pThis->GetEntity()->CreateFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateLinearGradientBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stops", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateLinearGradientBrush)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x1 = arg.GetNumber(0)
	//int y1 = arg.GetNumber(1)
	//int x2 = arg.GetNumber(2)
	//int y2 = arg.GetNumber(3)
	//int stops = arg.GetNumber(4)
	//pThis->GetEntity()->CreateLinearGradientBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "a", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateMatrix)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int a = arg.GetNumber(0)
	//int b = arg.GetNumber(1)
	//int c = arg.GetNumber(2)
	//int d = arg.GetNumber(3)
	//int tx = arg.GetNumber(4)
	//int ty = arg.GetNumber(5)
	//pThis->GetEntity()->CreateMatrix();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreatePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreatePath)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CreatePath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreatePen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreatePen)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pen = arg.GetNumber(0)
	//pThis->GetEntity()->CreatePen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateRadialGradientBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xo", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yo", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stops", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateRadialGradientBrush)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int xo = arg.GetNumber(0)
	//int yo = arg.GetNumber(1)
	//int xc = arg.GetNumber(2)
	//int yc = arg.GetNumber(3)
	//int radius = arg.GetNumber(4)
	//int stops = arg.GetNumber(5)
	//pThis->GetEntity()->CreateRadialGradientBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateSubBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateSubBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int w = arg.GetNumber(3)
	//int h = arg.GetNumber(4)
	//pThis->GetEntity()->CreateSubBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsRenderer, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, GetVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "micro", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsRenderer, GetVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int major = arg.GetNumber(0)
	//int minor = arg.GetNumber(1)
	//int micro = arg.GetNumber(2)
	//pThis->GetEntity()->GetVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, GetDefaultRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsRenderer, GetDefaultRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsRenderer, GetCairoRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsRenderer, GetCairoRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCairoRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsRenderer)
{
	Gura_AssignMethod(wx_GraphicsRenderer, CreateBitmap);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateBitmapFromImage);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateImageFromBitmap);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateBitmapFromNativeBitmap);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateContext);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateContext_1);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateContext_2);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateContext_3);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateContext_4);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateContextFromImage);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateBrush);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateContextFromNativeContext);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateContextFromNativeWindow);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateMeasuringContext);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateFont);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateFont_1);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateLinearGradientBrush);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateMatrix);
	Gura_AssignMethod(wx_GraphicsRenderer, CreatePath);
	Gura_AssignMethod(wx_GraphicsRenderer, CreatePen);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateRadialGradientBrush);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateSubBitmap);
	Gura_AssignMethod(wx_GraphicsRenderer, GetName);
	Gura_AssignMethod(wx_GraphicsRenderer, GetVersion);
	Gura_AssignMethod(wx_GraphicsRenderer, GetDefaultRenderer);
	Gura_AssignMethod(wx_GraphicsRenderer, GetCairoRenderer);
}

Gura_ImplementDescendantCreator(wx_GraphicsRenderer)
{
	return new Object_wx_GraphicsRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
