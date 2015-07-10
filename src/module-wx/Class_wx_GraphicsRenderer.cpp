//----------------------------------------------------------------------------
// wxGraphicsRenderer
// extracted from graphicsrenderer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GraphicsRenderer: public wxGraphicsRenderer, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_GraphicsRenderer *_pObj;
public:
	~wx_GraphicsRenderer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GraphicsRenderer *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GraphicsRenderer::~wx_GraphicsRenderer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GraphicsRenderer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsRenderer
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GraphicsRenderer, GetDefaultRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsRenderer, GetDefaultRenderer)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsRenderer *rtn = (wxGraphicsRenderer *)pThis->GetEntity()->GetDefaultRenderer();
	return ReturnValue(env, sig, args, Value(new Object_wx_GraphicsRenderer(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_WindowDC, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateContext)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowDC *dc = Object_wx_WindowDC::GetObject(args, 0)->GetEntity();
	wxGraphicsContext *rtn = (wxGraphicsContext *)pThis->GetEntity()->CreateContext(*dc);
	return ReturnValue(env, sig, args, Value(new Object_wx_GraphicsContext(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateContext_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateContext_1)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxGraphicsContext *rtn = (wxGraphicsContext *)pThis->GetEntity()->CreateContext(window);
	return ReturnValue(env, sig, args, Value(new Object_wx_GraphicsContext(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateContextFromNativeContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateContextFromNativeContext)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int context = args.GetInt(0);
	wxGraphicsContext *rtn = (wxGraphicsContext *)pThis->GetEntity()->CreateContextFromNativeContext(context);
	return ReturnValue(env, sig, args, Value(new Object_wx_GraphicsContext(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateContextFromNativeWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateContextFromNativeWindow)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int window = args.GetInt(0);
	wxGraphicsContext *rtn = (wxGraphicsContext *)pThis->GetEntity()->CreateContextFromNativeWindow(window);
	return ReturnValue(env, sig, args, Value(new Object_wx_GraphicsContext(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreatePen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pen", VTYPE_wx_Pen, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreatePen)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPen *pen = Object_wx_Pen::GetObject(args, 0)->GetEntity();
	wxGraphicsPen rtn = pThis->GetEntity()->CreatePen(*pen);
	return ReturnValue(env, sig, args, Value(new Object_wx_GraphicsPen(new wxGraphicsPen(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "brush", VTYPE_wx_Brush, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateBrush)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBrush *brush = Object_wx_Brush::GetObject(args, 0)->GetEntity();
	wxGraphicsBrush rtn = pThis->GetEntity()->CreateBrush(*brush);
	return ReturnValue(env, sig, args, Value(new Object_wx_GraphicsBrush(new wxGraphicsBrush(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateLinearGradientBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x1", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y1", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "x2", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y2", VTYPE_wx_Double, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateLinearGradientBrush)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x1 = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y1 = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *x2 = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *y2 = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxGraphicsBrush rtn = pThis->GetEntity()->CreateLinearGradientBrush(*x1, *y1, *x2, *y2, , );
	return ReturnValue(env, sig, args, Value(new Object_wx_GraphicsBrush(new wxGraphicsBrush(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateRadialGradientBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "xo", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "yo", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "xc", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "yc", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "radius", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "oColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "cColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateRadialGradientBrush)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *xo = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *yo = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *xc = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *yc = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxDouble *radius = Object_wx_Double::GetObject(args, 4)->GetEntity();
	wxColour *oColour = Object_wx_Colour::GetObject(args, 5)->GetEntity();
	wxColour *cColour = Object_wx_Colour::GetObject(args, 6)->GetEntity();
	wxGraphicsBrush rtn = pThis->GetEntity()->CreateRadialGradientBrush(*xo, *yo, *xc, *yc, *radius, *oColour, *cColour);
	return ReturnValue(env, sig, args, Value(new Object_wx_GraphicsBrush(new wxGraphicsBrush(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateFont)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	wxColour *col = (wxColour *)(&*wxBLACK);
	if (args.IsValid(1)) col = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxGraphicsFont rtn = pThis->GetEntity()->CreateFont(*font, *col);
	return ReturnValue(env, sig, args, Value(new Object_wx_GraphicsFont(new wxGraphicsFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreateMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "a", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "b", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "c", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "d", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "tx", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ty", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreateMatrix)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *a = (wxDouble *)(&1.0);
	if (args.IsValid(0)) a = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *b = (wxDouble *)(&0.0);
	if (args.IsValid(1)) b = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *c = (wxDouble *)(&0.0);
	if (args.IsValid(2)) c = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *d = (wxDouble *)(&1.0);
	if (args.IsValid(3)) d = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxDouble *tx = (wxDouble *)(&0.0);
	if (args.IsValid(4)) tx = Object_wx_Double::GetObject(args, 4)->GetEntity();
	wxDouble *ty = (wxDouble *)(&0.0);
	if (args.IsValid(5)) ty = Object_wx_Double::GetObject(args, 5)->GetEntity();
	wxGraphicsMatrix rtn = pThis->GetEntity()->CreateMatrix(*a, *b, *c, *d, *tx, *ty);
	return ReturnValue(env, sig, args, Value(new Object_wx_GraphicsMatrix(new wxGraphicsMatrix(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsRenderer, CreatePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsRenderer, CreatePath)
{
	Object_wx_GraphicsRenderer *pThis = Object_wx_GraphicsRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsPath rtn = pThis->GetEntity()->CreatePath();
	return ReturnValue(env, sig, args, Value(new Object_wx_GraphicsPath(new wxGraphicsPath(rtn), nullptr, OwnerTrue)));
}

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
// Class implementation for wxGraphicsRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsRenderer)
{
	Gura_AssignMethod(wx_GraphicsRenderer, GetDefaultRenderer);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateContext);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateContext_1);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateContextFromNativeContext);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateContextFromNativeWindow);
	Gura_AssignMethod(wx_GraphicsRenderer, CreatePen);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateBrush);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateLinearGradientBrush);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateRadialGradientBrush);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateFont);
	Gura_AssignMethod(wx_GraphicsRenderer, CreateMatrix);
	Gura_AssignMethod(wx_GraphicsRenderer, CreatePath);
}

Gura_ImplementDescendantCreator(wx_GraphicsRenderer)
{
	return new Object_wx_GraphicsRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
