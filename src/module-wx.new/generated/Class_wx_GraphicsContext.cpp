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
Gura_DeclareMethod(wx_GraphicsContext, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "windowDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Create_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int windowDC = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, Create_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "memoryDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Create_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int memoryDC = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, Create_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printerDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Create_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int printerDC = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, Create_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "metaFileDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Create_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int metaFileDC = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, Create_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Create_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, Create_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, Create_6)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, Clip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Clip)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->Clip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, Clip_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Clip_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int w = arg.GetNumber(2)
	//int h = arg.GetNumber(3)
	//pThis->GetEntity()->Clip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, ConcatTransform)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "matrix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, ConcatTransform)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int matrix = arg.GetNumber(0)
	//pThis->GetEntity()->ConcatTransform();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreateBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->CreateBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreateBitmapFromImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateBitmapFromImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//pThis->GetEntity()->CreateBitmapFromImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreateSubBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateSubBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int w = arg.GetNumber(3)
	//int h = arg.GetNumber(4)
	//pThis->GetEntity()->CreateSubBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreateBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateBrush)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int brush = arg.GetNumber(0)
	//pThis->GetEntity()->CreateBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreateFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->CreateFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreateFont_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizeInPixels", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateFont_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizeInPixels = arg.GetNumber(0)
	//int facename = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int col = arg.GetNumber(3)
	//pThis->GetEntity()->CreateFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreateFromNative)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateFromNative)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//pThis->GetEntity()->CreateFromNative();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreateFromNativeWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateFromNativeWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->CreateFromNativeWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreateLinearGradientBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "c1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "c2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateLinearGradientBrush)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x1 = arg.GetNumber(0)
	//int y1 = arg.GetNumber(1)
	//int x2 = arg.GetNumber(2)
	//int y2 = arg.GetNumber(3)
	//int c1 = arg.GetNumber(4)
	//int c2 = arg.GetNumber(5)
	//pThis->GetEntity()->CreateLinearGradientBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreateLinearGradientBrush_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stops", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateLinearGradientBrush_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x1 = arg.GetNumber(0)
	//int y1 = arg.GetNumber(1)
	//int x2 = arg.GetNumber(2)
	//int y2 = arg.GetNumber(3)
	//int stops = arg.GetNumber(4)
	//pThis->GetEntity()->CreateLinearGradientBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreateMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "a", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateMatrix)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_GraphicsContext, CreateMatrix_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateMatrix_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mat = arg.GetNumber(0)
	//pThis->GetEntity()->CreateMatrix();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreatePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, CreatePath)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CreatePath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreatePen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, CreatePen)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pen = arg.GetNumber(0)
	//pThis->GetEntity()->CreatePen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreateRadialGradientBrush)
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

Gura_ImplementMethod(wx_GraphicsContext, CreateRadialGradientBrush)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int xo = arg.GetNumber(0)
	//int yo = arg.GetNumber(1)
	//int xc = arg.GetNumber(2)
	//int yc = arg.GetNumber(3)
	//int radius = arg.GetNumber(4)
	//int oColor = arg.GetNumber(5)
	//int cColor = arg.GetNumber(6)
	//pThis->GetEntity()->CreateRadialGradientBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, CreateRadialGradientBrush_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xo", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yo", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stops", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateRadialGradientBrush_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_GraphicsContext, DrawBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int w = arg.GetNumber(3)
	//int h = arg.GetNumber(4)
	//pThis->GetEntity()->DrawBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawBitmap_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawBitmap_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int w = arg.GetNumber(3)
	//int h = arg.GetNumber(4)
	//pThis->GetEntity()->DrawBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawEllipse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawEllipse)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int w = arg.GetNumber(2)
	//int h = arg.GetNumber(3)
	//pThis->GetEntity()->DrawEllipse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int w = arg.GetNumber(3)
	//int h = arg.GetNumber(4)
	//pThis->GetEntity()->DrawIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawLines)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int points = arg.GetNumber(1)
	//int fillStyle = arg.GetNumber(2)
	//pThis->GetEntity()->DrawLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int fillStyle = arg.GetNumber(1)
	//pThis->GetEntity()->DrawPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawRectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawRectangle)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int w = arg.GetNumber(2)
	//int h = arg.GetNumber(3)
	//pThis->GetEntity()->DrawRectangle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawRoundedRectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawRoundedRectangle)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int w = arg.GetNumber(2)
	//int h = arg.GetNumber(3)
	//int radius = arg.GetNumber(4)
	//pThis->GetEntity()->DrawRoundedRectangle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawText)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->DrawText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawText_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawText_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int angle = arg.GetNumber(3)
	//pThis->GetEntity()->DrawText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawText_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "backgroundBrush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawText_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int backgroundBrush = arg.GetNumber(3)
	//pThis->GetEntity()->DrawText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawText_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "backgroundBrush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawText_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int angle = arg.GetNumber(3)
	//int backgroundBrush = arg.GetNumber(4)
	//pThis->GetEntity()->DrawText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, FillPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, FillPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int fillStyle = arg.GetNumber(1)
	//pThis->GetEntity()->FillPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, GetNativeContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, GetNativeContext)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNativeContext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, GetPartialTextExtents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "widths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, GetPartialTextExtents)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int widths = arg.GetNumber(1)
	//pThis->GetEntity()->GetPartialTextExtents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, GetTextExtent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "externalLeading", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, GetTextExtent)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//int descent = arg.GetNumber(3)
	//int externalLeading = arg.GetNumber(4)
	//pThis->GetEntity()->GetTextExtent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, GetTransform)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, GetTransform)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTransform();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, ResetClip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, ResetClip)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ResetClip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, Rotate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Rotate)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int angle = arg.GetNumber(0)
	//pThis->GetEntity()->Rotate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, Scale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xScale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Scale)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int xScale = arg.GetNumber(0)
	//int yScale = arg.GetNumber(1)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, SetBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetBrush)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int brush = arg.GetNumber(0)
	//pThis->GetEntity()->SetBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, SetBrush_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetBrush_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int brush = arg.GetNumber(0)
	//pThis->GetEntity()->SetBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//int colour = arg.GetNumber(1)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, SetFont_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetFont_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, SetPen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetPen)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pen = arg.GetNumber(0)
	//pThis->GetEntity()->SetPen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, SetPen_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetPen_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pen = arg.GetNumber(0)
	//pThis->GetEntity()->SetPen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, SetTransform)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "matrix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetTransform)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int matrix = arg.GetNumber(0)
	//pThis->GetEntity()->SetTransform();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, StrokeLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, StrokeLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x1 = arg.GetNumber(0)
	//int y1 = arg.GetNumber(1)
	//int x2 = arg.GetNumber(2)
	//int y2 = arg.GetNumber(3)
	//pThis->GetEntity()->StrokeLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, StrokeLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "beginPoints", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPoints", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, StrokeLines)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int beginPoints = arg.GetNumber(1)
	//int endPoints = arg.GetNumber(2)
	//pThis->GetEntity()->StrokeLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, StrokeLines_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, StrokeLines_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int points = arg.GetNumber(1)
	//pThis->GetEntity()->StrokeLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, StrokePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, StrokePath)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->StrokePath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, Translate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Translate)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//pThis->GetEntity()->Translate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, BeginLayer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "opacity", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, BeginLayer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int opacity = arg.GetNumber(0)
	//pThis->GetEntity()->BeginLayer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, EndLayer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, EndLayer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndLayer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, SetAntialiasMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "antialias", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetAntialiasMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int antialias = arg.GetNumber(0)
	//pThis->GetEntity()->SetAntialiasMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, GetAntialiasMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, GetAntialiasMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAntialiasMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, SetInterpolationQuality)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "interpolation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetInterpolationQuality)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int interpolation = arg.GetNumber(0)
	//pThis->GetEntity()->SetInterpolationQuality();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, GetInterpolationQuality)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, GetInterpolationQuality)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetInterpolationQuality();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, SetCompositionMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "op", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetCompositionMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int op = arg.GetNumber(0)
	//pThis->GetEntity()->SetCompositionMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, GetCompositionMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, GetCompositionMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCompositionMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, PushState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, PushState)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PushState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, PopState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, PopState)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PopState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, ShouldOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, ShouldOffset)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShouldOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, EnableOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, EnableOffset)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, DisableOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, DisableOffset)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DisableOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, OffsetEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, OffsetEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OffsetEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, StartDoc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, StartDoc)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int message = arg.GetNumber(0)
	//pThis->GetEntity()->StartDoc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, EndDoc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, EndDoc)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndDoc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, StartPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, StartPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->StartPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, EndPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, EndPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, Flush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, Flush)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsContext, GetDPI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dpiX", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dpiY", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, GetDPI)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dpiX = arg.GetNumber(0)
	//int dpiY = arg.GetNumber(1)
	//pThis->GetEntity()->GetDPI();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsContext)
{
	Gura_AssignMethod(wx_GraphicsContext, Create);
	Gura_AssignMethod(wx_GraphicsContext, Create_1);
	Gura_AssignMethod(wx_GraphicsContext, Create_2);
	Gura_AssignMethod(wx_GraphicsContext, Create_3);
	Gura_AssignMethod(wx_GraphicsContext, Create_4);
	Gura_AssignMethod(wx_GraphicsContext, Create_5);
	Gura_AssignMethod(wx_GraphicsContext, Create_6);
	Gura_AssignMethod(wx_GraphicsContext, Clip);
	Gura_AssignMethod(wx_GraphicsContext, Clip_1);
	Gura_AssignMethod(wx_GraphicsContext, ConcatTransform);
	Gura_AssignMethod(wx_GraphicsContext, CreateBitmap);
	Gura_AssignMethod(wx_GraphicsContext, CreateBitmapFromImage);
	Gura_AssignMethod(wx_GraphicsContext, CreateSubBitmap);
	Gura_AssignMethod(wx_GraphicsContext, CreateBrush);
	Gura_AssignMethod(wx_GraphicsContext, CreateFont);
	Gura_AssignMethod(wx_GraphicsContext, CreateFont_1);
	Gura_AssignMethod(wx_GraphicsContext, CreateFromNative);
	Gura_AssignMethod(wx_GraphicsContext, CreateFromNativeWindow);
	Gura_AssignMethod(wx_GraphicsContext, CreateLinearGradientBrush);
	Gura_AssignMethod(wx_GraphicsContext, CreateLinearGradientBrush_1);
	Gura_AssignMethod(wx_GraphicsContext, CreateMatrix);
	Gura_AssignMethod(wx_GraphicsContext, CreateMatrix_1);
	Gura_AssignMethod(wx_GraphicsContext, CreatePath);
	Gura_AssignMethod(wx_GraphicsContext, CreatePen);
	Gura_AssignMethod(wx_GraphicsContext, CreateRadialGradientBrush);
	Gura_AssignMethod(wx_GraphicsContext, CreateRadialGradientBrush_1);
	Gura_AssignMethod(wx_GraphicsContext, DrawBitmap);
	Gura_AssignMethod(wx_GraphicsContext, DrawBitmap_1);
	Gura_AssignMethod(wx_GraphicsContext, DrawEllipse);
	Gura_AssignMethod(wx_GraphicsContext, DrawIcon);
	Gura_AssignMethod(wx_GraphicsContext, DrawLines);
	Gura_AssignMethod(wx_GraphicsContext, DrawPath);
	Gura_AssignMethod(wx_GraphicsContext, DrawRectangle);
	Gura_AssignMethod(wx_GraphicsContext, DrawRoundedRectangle);
	Gura_AssignMethod(wx_GraphicsContext, DrawText);
	Gura_AssignMethod(wx_GraphicsContext, DrawText_1);
	Gura_AssignMethod(wx_GraphicsContext, DrawText_2);
	Gura_AssignMethod(wx_GraphicsContext, DrawText_3);
	Gura_AssignMethod(wx_GraphicsContext, FillPath);
	Gura_AssignMethod(wx_GraphicsContext, GetNativeContext);
	Gura_AssignMethod(wx_GraphicsContext, GetPartialTextExtents);
	Gura_AssignMethod(wx_GraphicsContext, GetTextExtent);
	Gura_AssignMethod(wx_GraphicsContext, GetTransform);
	Gura_AssignMethod(wx_GraphicsContext, ResetClip);
	Gura_AssignMethod(wx_GraphicsContext, Rotate);
	Gura_AssignMethod(wx_GraphicsContext, Scale);
	Gura_AssignMethod(wx_GraphicsContext, SetBrush);
	Gura_AssignMethod(wx_GraphicsContext, SetBrush_1);
	Gura_AssignMethod(wx_GraphicsContext, SetFont);
	Gura_AssignMethod(wx_GraphicsContext, SetFont_1);
	Gura_AssignMethod(wx_GraphicsContext, SetPen);
	Gura_AssignMethod(wx_GraphicsContext, SetPen_1);
	Gura_AssignMethod(wx_GraphicsContext, SetTransform);
	Gura_AssignMethod(wx_GraphicsContext, StrokeLine);
	Gura_AssignMethod(wx_GraphicsContext, StrokeLines);
	Gura_AssignMethod(wx_GraphicsContext, StrokeLines_1);
	Gura_AssignMethod(wx_GraphicsContext, StrokePath);
	Gura_AssignMethod(wx_GraphicsContext, Translate);
	Gura_AssignMethod(wx_GraphicsContext, BeginLayer);
	Gura_AssignMethod(wx_GraphicsContext, EndLayer);
	Gura_AssignMethod(wx_GraphicsContext, SetAntialiasMode);
	Gura_AssignMethod(wx_GraphicsContext, GetAntialiasMode);
	Gura_AssignMethod(wx_GraphicsContext, SetInterpolationQuality);
	Gura_AssignMethod(wx_GraphicsContext, GetInterpolationQuality);
	Gura_AssignMethod(wx_GraphicsContext, SetCompositionMode);
	Gura_AssignMethod(wx_GraphicsContext, GetCompositionMode);
	Gura_AssignMethod(wx_GraphicsContext, PushState);
	Gura_AssignMethod(wx_GraphicsContext, PopState);
	Gura_AssignMethod(wx_GraphicsContext, ShouldOffset);
	Gura_AssignMethod(wx_GraphicsContext, EnableOffset);
	Gura_AssignMethod(wx_GraphicsContext, DisableOffset);
	Gura_AssignMethod(wx_GraphicsContext, OffsetEnabled);
	Gura_AssignMethod(wx_GraphicsContext, StartDoc);
	Gura_AssignMethod(wx_GraphicsContext, EndDoc);
	Gura_AssignMethod(wx_GraphicsContext, StartPage);
	Gura_AssignMethod(wx_GraphicsContext, EndPage);
	Gura_AssignMethod(wx_GraphicsContext, Flush);
	Gura_AssignMethod(wx_GraphicsContext, GetSize);
	Gura_AssignMethod(wx_GraphicsContext, GetDPI);
}

Gura_ImplementDescendantCreator(wx_GraphicsContext)
{
	return new Object_wx_GraphicsContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
