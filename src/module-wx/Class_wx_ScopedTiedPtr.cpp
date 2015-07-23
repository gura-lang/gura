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
	Gura::Signal *_pSig;
	Object_wx_ScopedTiedPtr *_pObj;
public:
	inline wx_ScopedTiedPtr(T ** ppTie, T * ptr) : wxScopedTiedPtr(ppTie, ptr), _pSig(nullptr), _pObj(nullptr) {}
	~wx_ScopedTiedPtr();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ScopedTiedPtr *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ScopedTiedPtr::~wx_ScopedTiedPtr()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ScopedTiedPtr::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedTiedPtr
//----------------------------------------------------------------------------
Gura_DeclareFunction(ScopedTiedPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ScopedTiedPtr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ScopedTiedPtr)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ScopedTiedPtr *pEntity = new wx_ScopedTiedPtr(, );
	Object_wx_ScopedTiedPtr *pObj = Object_wx_ScopedTiedPtr::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ScopedTiedPtr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxScopedTiedPtr
//----------------------------------------------------------------------------
Object_wx_ScopedTiedPtr::~Object_wx_ScopedTiedPtr()
{
}

Object *Object_wx_ScopedTiedPtr::Clone() const
{
	return nullptr;
}

String Object_wx_ScopedTiedPtr::ToString(bool exprFlag)
{
	String rtn("<wx.ScopedTiedPtr:");
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
// Class implementation for wxScopedTiedPtr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopedTiedPtr)
{
	Gura_AssignFunction(ScopedTiedPtr);
}

Gura_ImplementDescendantCreator(wx_ScopedTiedPtr)
{
	return new Object_wx_ScopedTiedPtr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
