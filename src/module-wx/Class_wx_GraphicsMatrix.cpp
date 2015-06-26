//----------------------------------------------------------------------------
// wxGraphicsMatrix
// extracted from graphicsmatrix.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GraphicsMatrix: public wxGraphicsMatrix, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GraphicsMatrix *_pObj;
public:
	~wx_GraphicsMatrix();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GraphicsMatrix *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GraphicsMatrix::~wx_GraphicsMatrix()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GraphicsMatrix::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsMatrix
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GraphicsMatrix, Concat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "t", VTYPE_wx_GraphicsMatrix, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Concat)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsMatrix *t = Object_wx_GraphicsMatrix::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Concat(t);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsMatrix, Concat_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "t", VTYPE_wx_GraphicsMatrix, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Concat_1)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsMatrix *t = Object_wx_GraphicsMatrix::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Concat(*t);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsMatrix, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "a", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "b", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "c", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "d", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "tx", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ty", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Get)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *a = (wxDouble *)(nullptr);
	if (args.IsValid(0)) a = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *b = (wxDouble *)(nullptr);
	if (args.IsValid(1)) b = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *c = (wxDouble *)(nullptr);
	if (args.IsValid(2)) c = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *d = (wxDouble *)(nullptr);
	if (args.IsValid(3)) d = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxDouble *tx = (wxDouble *)(nullptr);
	if (args.IsValid(4)) tx = Object_wx_Double::GetObject(args, 4)->GetEntity();
	wxDouble *ty = (wxDouble *)(nullptr);
	if (args.IsValid(5)) ty = Object_wx_Double::GetObject(args, 5)->GetEntity();
	pThis->GetEntity()->Get(a, b, c, d, tx, ty);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsMatrix, GetNativeMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsMatrix, GetNativeMatrix)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->GetNativeMatrix();
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsMatrix, Invert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Invert)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Invert();
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsMatrix, IsEqual)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "t", VTYPE_wx_GraphicsMatrix, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsMatrix, IsEqual)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsMatrix *t = Object_wx_GraphicsMatrix::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsEqual(*t);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GraphicsMatrix, IsIdentity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsMatrix, IsIdentity)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsIdentity();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GraphicsMatrix, Rotate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Rotate)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *angle = Object_wx_Double::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Rotate(*angle);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsMatrix, Scale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "xScale", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "yScale", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Scale)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *xScale = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *yScale = Object_wx_Double::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->Scale(*xScale, *yScale);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsMatrix, Translate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "dy", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Translate)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *dx = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *dy = Object_wx_Double::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->Translate(*dx, *dy);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsMatrix, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "a", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "b", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "c", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "d", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "tx", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ty", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsMatrix, Set)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetThisObj(args);
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
	pThis->GetEntity()->Set(*a, *b, *c, *d, *tx, *ty);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsMatrix, TransformPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, TransformPoint)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->TransformPoint(x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsMatrix, TransformDistance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "dy", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsMatrix, TransformDistance)
{
	Object_wx_GraphicsMatrix *pThis = Object_wx_GraphicsMatrix::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *dx = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *dy = Object_wx_Double::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->TransformDistance(dx, dy);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsMatrix
//----------------------------------------------------------------------------
Object_wx_GraphicsMatrix::~Object_wx_GraphicsMatrix()
{
}

Object *Object_wx_GraphicsMatrix::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsMatrix::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsMatrix:");
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
// Class implementation for wxGraphicsMatrix
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsMatrix)
{
	Gura_AssignMethod(wx_GraphicsMatrix, Concat);
	Gura_AssignMethod(wx_GraphicsMatrix, Concat_1);
	Gura_AssignMethod(wx_GraphicsMatrix, Get);
	Gura_AssignMethod(wx_GraphicsMatrix, GetNativeMatrix);
	Gura_AssignMethod(wx_GraphicsMatrix, Invert);
	Gura_AssignMethod(wx_GraphicsMatrix, IsEqual);
	Gura_AssignMethod(wx_GraphicsMatrix, IsIdentity);
	Gura_AssignMethod(wx_GraphicsMatrix, Rotate);
	Gura_AssignMethod(wx_GraphicsMatrix, Scale);
	Gura_AssignMethod(wx_GraphicsMatrix, Translate);
	Gura_AssignMethod(wx_GraphicsMatrix, Set);
	Gura_AssignMethod(wx_GraphicsMatrix, TransformPoint);
	Gura_AssignMethod(wx_GraphicsMatrix, TransformDistance);
}

Gura_ImplementDescendantCreator(wx_GraphicsMatrix)
{
	return new Object_wx_GraphicsMatrix((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
