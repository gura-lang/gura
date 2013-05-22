//----------------------------------------------------------------------------
// wxGraphicsObject
// extracted from graphicsobject.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GraphicsObject: public wxGraphicsObject, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GraphicsObject *_pObj;
public:
	~wx_GraphicsObject();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GraphicsObject *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GraphicsObject::~wx_GraphicsObject()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GraphicsObject::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsObject
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GraphicsObject, GetRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsObject, GetRenderer)
{
	Object_wx_GraphicsObject *pThis = Object_wx_GraphicsObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsRenderer *rtn = (wxGraphicsRenderer *)pThis->GetEntity()->GetRenderer();
	return ReturnValue(env, sig, args, Value(new Object_wx_GraphicsRenderer(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_GraphicsObject, IsNull)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
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
	return NULL;
}

String Object_wx_GraphicsObject::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GraphicsObject:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GraphicsObject::DoAssignConstructor(Environment &env, Signal sig)
{
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
	return new Object_wx_GraphicsObject((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
