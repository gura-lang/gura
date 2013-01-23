//----------------------------------------------------------------------------
// wxGDIObject
// extracted from gdiobj.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GDIObject: public wxGDIObject, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GDIObject *_pObj;
public:
	inline wx_GDIObject() : wxGDIObject(), _sig(NULL), _pObj(NULL) {}
	~wx_GDIObject();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GDIObject *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GDIObject::~wx_GDIObject()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GDIObject::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGDIObject
//----------------------------------------------------------------------------
Gura_DeclareFunction(GDIObjectEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GDIObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GDIObjectEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GDIObject *pEntity = new wx_GDIObject();
	Object_wx_GDIObject *pObj = Object_wx_GDIObject::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GDIObject(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxGDIObject
//----------------------------------------------------------------------------
Object_wx_GDIObject::~Object_wx_GDIObject()
{
}

Object *Object_wx_GDIObject::Clone() const
{
	return NULL;
}

String Object_wx_GDIObject::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GDIObject:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GDIObject::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(GDIObjectEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxGDIObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GDIObject)
{
}

Gura_ImplementDescendantCreator(wx_GDIObject)
{
	return new Object_wx_GDIObject((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
