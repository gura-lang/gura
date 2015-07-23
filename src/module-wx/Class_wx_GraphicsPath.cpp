//----------------------------------------------------------------------------
// wxGraphicsPath
// extracted from graphicspath.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GraphicsPath: public wxGraphicsPath, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_GraphicsPath *_pObj;
public:
	~wx_GraphicsPath();
	inline void AssocWithGura(Object_wx_GraphicsPath *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GraphicsPath::~wx_GraphicsPath()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GraphicsPath::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsPath
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GraphicsPath, MoveToPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, MoveToPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->MoveToPoint(*x, *y);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, MoveToPoint_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "p", VTYPE_wx_Point2DDouble, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, MoveToPoint_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint2DDouble *p = Object_wx_Point2DDouble::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->MoveToPoint(*p);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, AddArc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "r", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "startAngle", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "endAngle", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "clockwise", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddArc)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *r = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *startAngle = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxDouble *endAngle = Object_wx_Double::GetObject(args, 4)->GetEntity();
	bool clockwise = args.GetBoolean(5);
	pThis->GetEntity()->AddArc(*x, *y, *r, *startAngle, *endAngle, clockwise);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, AddArc_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_wx_Point2DDouble, OCCUR_Once);
	DeclareArg(env, "r", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "startAngle", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "endAngle", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "clockwise", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddArc_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint2DDouble *c = Object_wx_Point2DDouble::GetObject(args, 0)->GetEntity();
	wxDouble *r = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *startAngle = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *endAngle = Object_wx_Double::GetObject(args, 3)->GetEntity();
	bool clockwise = args.GetBoolean(4);
	pThis->GetEntity()->AddArc(*c, *r, *startAngle, *endAngle, clockwise);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, AddArcToPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x1", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y1", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "x2", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y2", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "r", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddArcToPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x1 = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y1 = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *x2 = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *y2 = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxDouble *r = Object_wx_Double::GetObject(args, 4)->GetEntity();
	pThis->GetEntity()->AddArcToPoint(*x1, *y1, *x2, *y2, *r);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, AddCircle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "r", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddCircle)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *r = Object_wx_Double::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->AddCircle(*x, *y, *r);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, AddCurveToPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cx1", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "cy1", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "cx2", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "cy2", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddCurveToPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *cx1 = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *cy1 = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *cx2 = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *cy2 = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxDouble *x = Object_wx_Double::GetObject(args, 4)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 5)->GetEntity();
	pThis->GetEntity()->AddCurveToPoint(*cx1, *cy1, *cx2, *cy2, *x, *y);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, AddCurveToPoint_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c1", VTYPE_wx_Point2DDouble, OCCUR_Once);
	DeclareArg(env, "c2", VTYPE_wx_Point2DDouble, OCCUR_Once);
	DeclareArg(env, "e", VTYPE_wx_Point2DDouble, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddCurveToPoint_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint2DDouble *c1 = Object_wx_Point2DDouble::GetObject(args, 0)->GetEntity();
	wxPoint2DDouble *c2 = Object_wx_Point2DDouble::GetObject(args, 1)->GetEntity();
	wxPoint2DDouble *e = Object_wx_Point2DDouble::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->AddCurveToPoint(*c1, *c2, *e);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, AddEllipse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddEllipse)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *w = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *h = Object_wx_Double::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->AddEllipse(*x, *y, *w, *h);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, AddLineToPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddLineToPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->AddLineToPoint(*x, *y);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, AddLineToPoint_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "p", VTYPE_wx_Point2DDouble, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddLineToPoint_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint2DDouble *p = Object_wx_Point2DDouble::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AddLineToPoint(*p);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, AddPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "path", VTYPE_wx_GraphicsPath, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddPath)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsPath *path = Object_wx_GraphicsPath::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AddPath(*path);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, AddQuadCurveToPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cx", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "cy", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddQuadCurveToPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *cx = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *cy = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *x = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->AddQuadCurveToPoint(*cx, *cy, *x, *y);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, AddRectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddRectangle)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *w = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *h = Object_wx_Double::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->AddRectangle(*x, *y, *w, *h);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, AddRoundedRectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "radius", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddRoundedRectangle)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *w = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *h = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxDouble *radius = Object_wx_Double::GetObject(args, 4)->GetEntity();
	pThis->GetEntity()->AddRoundedRectangle(*x, *y, *w, *h, *radius);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, CloseSubpath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsPath, CloseSubpath)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->CloseSubpath();
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, Contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_wx_Point2DDouble, OCCUR_Once);
	DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsPath, Contains)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint2DDouble *c = Object_wx_Point2DDouble::GetObject(args, 0)->GetEntity();
	int fillStyle = wxODDEVEN_RULE;
	if (args.IsValid(1)) fillStyle = args.GetInt(1);
	bool rtn = pThis->GetEntity()->Contains(*c, fillStyle);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GraphicsPath, Contains_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsPath, Contains_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	int fillStyle = wxODDEVEN_RULE;
	if (args.IsValid(2)) fillStyle = args.GetInt(2);
	bool rtn = pThis->GetEntity()->Contains(*x, *y, fillStyle);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GraphicsPath, GetBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsPath, GetBox)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect2DDouble rtn = pThis->GetEntity()->GetBox();
	return ReturnValue(env, args, Value(new Object_wx_Rect2DDouble(new wxRect2DDouble(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsPath, GetBox_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, GetBox_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *w = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *h = Object_wx_Double::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->GetBox(x, y, w, h);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, GetCurrentPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, GetCurrentPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->GetCurrentPoint(x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, GetCurrentPoint_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsPath, GetCurrentPoint_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint2DDouble rtn = pThis->GetEntity()->GetCurrentPoint();
	return ReturnValue(env, args, Value(new Object_wx_Point2DDouble(new wxPoint2DDouble(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsPath, Transform)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "matrix", VTYPE_wx_GraphicsMatrix, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, Transform)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsMatrix *matrix = Object_wx_GraphicsMatrix::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Transform(*matrix);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, GetNativePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsPath, GetNativePath)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->GetNativePath();
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsPath, UnGetNativePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, UnGetNativePath)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int p = args.GetInt(0);
	pThis->GetEntity()->UnGetNativePath(p);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsPath
//----------------------------------------------------------------------------
Object_wx_GraphicsPath::~Object_wx_GraphicsPath()
{
}

Object *Object_wx_GraphicsPath::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsPath::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsPath:");
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
// Class implementation for wxGraphicsPath
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsPath)
{
	Gura_AssignMethod(wx_GraphicsPath, MoveToPoint);
	Gura_AssignMethod(wx_GraphicsPath, MoveToPoint_1);
	Gura_AssignMethod(wx_GraphicsPath, AddArc);
	Gura_AssignMethod(wx_GraphicsPath, AddArc_1);
	Gura_AssignMethod(wx_GraphicsPath, AddArcToPoint);
	Gura_AssignMethod(wx_GraphicsPath, AddCircle);
	Gura_AssignMethod(wx_GraphicsPath, AddCurveToPoint);
	Gura_AssignMethod(wx_GraphicsPath, AddCurveToPoint_1);
	Gura_AssignMethod(wx_GraphicsPath, AddEllipse);
	Gura_AssignMethod(wx_GraphicsPath, AddLineToPoint);
	Gura_AssignMethod(wx_GraphicsPath, AddLineToPoint_1);
	Gura_AssignMethod(wx_GraphicsPath, AddPath);
	Gura_AssignMethod(wx_GraphicsPath, AddQuadCurveToPoint);
	Gura_AssignMethod(wx_GraphicsPath, AddRectangle);
	Gura_AssignMethod(wx_GraphicsPath, AddRoundedRectangle);
	Gura_AssignMethod(wx_GraphicsPath, CloseSubpath);
	Gura_AssignMethod(wx_GraphicsPath, Contains);
	Gura_AssignMethod(wx_GraphicsPath, Contains_1);
	Gura_AssignMethod(wx_GraphicsPath, GetBox);
	Gura_AssignMethod(wx_GraphicsPath, GetBox_1);
	Gura_AssignMethod(wx_GraphicsPath, GetCurrentPoint);
	Gura_AssignMethod(wx_GraphicsPath, GetCurrentPoint_1);
	Gura_AssignMethod(wx_GraphicsPath, Transform);
	Gura_AssignMethod(wx_GraphicsPath, GetNativePath);
	Gura_AssignMethod(wx_GraphicsPath, UnGetNativePath);
}

Gura_ImplementDescendantCreator(wx_GraphicsPath)
{
	return new Object_wx_GraphicsPath((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
