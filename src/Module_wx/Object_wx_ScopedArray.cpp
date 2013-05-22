//----------------------------------------------------------------------------
// wxScopedArray
// extracted from scpdarry.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ScopedArray: public wxScopedArray, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ScopedArray *_pObj;
public:
	inline wx_ScopedArray(type * T) : wxScopedArray(* T), _sig(NULL), _pObj(NULL) {}
	~wx_ScopedArray();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ScopedArray *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ScopedArray::~wx_ScopedArray()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ScopedArray::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedArray
//----------------------------------------------------------------------------
Gura_DeclareFunction(ScopedArray)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ScopedArray));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ScopedArray)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ScopedArray *pEntity = new wx_ScopedArray();
	Object_wx_ScopedArray *pObj = Object_wx_ScopedArray::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ScopedArray(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ScopedArray, reset)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_ScopedArray, reset)
{
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->reset();
	return Value::Null;
}

Gura_DeclareMethod(wx_ScopedArray, get)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScopedArray, get)
{
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_ScopedArray, swap)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "& ot", VTYPE_wx_ScopedPtr, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedArray, swap)
{
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxScopedPtr *& ot = Object_wx_ScopedPtr::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->swap(*& ot);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxScopedArray
//----------------------------------------------------------------------------
Object_wx_ScopedArray::~Object_wx_ScopedArray()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ScopedArray::Clone() const
{
	return NULL;
}

String Object_wx_ScopedArray::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ScopedArray:");
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
// Class implementation for wxScopedArray
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopedArray)
{
	Gura_AssignFunction(ScopedArray);
	Gura_AssignMethod(wx_ScopedArray, reset);
	Gura_AssignMethod(wx_ScopedArray, get);
	Gura_AssignMethod(wx_ScopedArray, swap);
}

Gura_ImplementDescendantCreator(wx_ScopedArray)
{
	return new Object_wx_ScopedArray((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
