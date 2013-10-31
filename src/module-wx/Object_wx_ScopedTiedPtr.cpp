//----------------------------------------------------------------------------
// wxScopedTiedPtr
// extracted from scpdptr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ScopedTiedPtr: public wxScopedTiedPtr, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ScopedTiedPtr *_pObj;
public:
	inline wx_ScopedTiedPtr(T ** ppTie, T * ptr) : wxScopedTiedPtr(ppTie, ptr), _sig(NULL), _pObj(NULL) {}
	~wx_ScopedTiedPtr();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ScopedTiedPtr *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ScopedTiedPtr::~wx_ScopedTiedPtr()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ScopedTiedPtr::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedTiedPtr
//----------------------------------------------------------------------------
Gura_DeclareFunction(ScopedTiedPtr)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ScopedTiedPtr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ScopedTiedPtr)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ScopedTiedPtr *pEntity = new wx_ScopedTiedPtr(, );
	Object_wx_ScopedTiedPtr *pObj = Object_wx_ScopedTiedPtr::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ScopedTiedPtr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxScopedTiedPtr
//----------------------------------------------------------------------------
Object_wx_ScopedTiedPtr::~Object_wx_ScopedTiedPtr()
{
}

Object *Object_wx_ScopedTiedPtr::Clone() const
{
	return NULL;
}

String Object_wx_ScopedTiedPtr::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ScopedTiedPtr:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxScopedTiedPtr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopedTiedPtr)
{
	Gura_AssignFunction(ScopedTiedPtr);
}

Gura_ImplementDescendantCreator(wx_ScopedTiedPtr)
{
	return new Object_wx_ScopedTiedPtr((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
