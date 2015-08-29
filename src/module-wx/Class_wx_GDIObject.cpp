//----------------------------------------------------------------------------
// wxGDIObject
// extracted from gdiobj.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GDIObject: public wxGDIObject, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_GDIObject *_pObj;
public:
	inline wx_GDIObject() : wxGDIObject(), _pObj(nullptr) {}
	~wx_GDIObject();
	inline void AssocWithGura(Object_wx_GDIObject *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GDIObject::~wx_GDIObject()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GDIObject::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGDIObject
//----------------------------------------------------------------------------
#if 0
Gura_DeclareFunction(GDIObjectEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GDIObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GDIObjectEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_GDIObject *pEntity = new wx_GDIObject();
	Object_wx_GDIObject *pObj = Object_wx_GDIObject::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GDIObject(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}
#endif

//----------------------------------------------------------------------------
// Object implementation for wxGDIObject
//----------------------------------------------------------------------------
Object_wx_GDIObject::~Object_wx_GDIObject()
{
}

Object *Object_wx_GDIObject::Clone() const
{
	return nullptr;
}

String Object_wx_GDIObject::ToString(bool exprFlag)
{
	String rtn("<wx.GDIObject:");
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
// Class implementation for wxGDIObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GDIObject)
{
	//Gura_AssignFunction(GDIObjectEmpty);
}

Gura_ImplementDescendantCreator(wx_GDIObject)
{
	return new Object_wx_GDIObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
