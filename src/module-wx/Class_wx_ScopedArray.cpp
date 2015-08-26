//----------------------------------------------------------------------------
// wxScopedArray
// extracted from scpdarry.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ScopedArray: public wxScopedArray, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ScopedArray *_pObj;
public:
	inline wx_ScopedArray(type * T) : wxScopedArray(* T), _pObj(nullptr) {}
	~wx_ScopedArray();
	inline void AssocWithGura(Object_wx_ScopedArray *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ScopedArray::~wx_ScopedArray()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ScopedArray::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedArray
//----------------------------------------------------------------------------
Gura_DeclareFunction(ScopedArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ScopedArray));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ScopedArray)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_ScopedArray *pEntity = new wx_ScopedArray();
	Object_wx_ScopedArray *pObj = Object_wx_ScopedArray::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ScopedArray(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_ScopedArray, reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_ScopedArray, reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedArray, get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScopedArray, get)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedArray, swap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "& ot", VTYPE_wx_ScopedPtr, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedArray, swap)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxScopedPtr *& ot = Object_wx_ScopedPtr::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->swap(*& ot);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxScopedArray
//----------------------------------------------------------------------------
Object_wx_ScopedArray::~Object_wx_ScopedArray()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ScopedArray::Clone() const
{
	return nullptr;
}

String Object_wx_ScopedArray::ToString(bool exprFlag)
{
	String rtn("<wx.ScopedArray:");
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
	return new Object_wx_ScopedArray((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
