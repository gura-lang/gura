//----------------------------------------------------------------------------
// wxGraphicsObject
// extracted from graphicsobject.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GraphicsObject: public wxGraphicsObject, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_GraphicsObject *_pObj;
public:
	~wx_GraphicsObject();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GraphicsObject *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GraphicsObject::~wx_GraphicsObject()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GraphicsObject::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsObject
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GraphicsObject, GetRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsObject, GetRenderer)
{
	Object_wx_GraphicsObject *pThis = Object_wx_GraphicsObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsRenderer *rtn = (wxGraphicsRenderer *)pThis->GetEntity()->GetRenderer();
	return ReturnValue(env, sig, args, Value(new Object_wx_GraphicsRenderer(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GraphicsObject, IsNull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsObject, IsNull)
{
	Object_wx_GraphicsObject *pThis = Object_wx_GraphicsObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsNull();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsObject
//----------------------------------------------------------------------------
Object_wx_GraphicsObject::~Object_wx_GraphicsObject()
{
}

Object *Object_wx_GraphicsObject::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsObject::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsObject:");
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
// Class implementation for wxGraphicsObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsObject)
{
	Gura_AssignMethod(wx_GraphicsObject, GetRenderer);
	Gura_AssignMethod(wx_GraphicsObject, IsNull);
}

Gura_ImplementDescendantCreator(wx_GraphicsObject)
{
	return new Object_wx_GraphicsObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
