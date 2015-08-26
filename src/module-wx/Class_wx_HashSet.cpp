//----------------------------------------------------------------------------
// wxHashSet
// extracted from hashset.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HashSet: public wxHashSet, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HashSet *_pObj;
public:
	inline wx_HashSet(size_type size) : wxHashSet(size), _pObj(nullptr) {}
	inline wx_HashSet(const wxHashSet& set) : wxHashSet(set), _pObj(nullptr) {}
	~wx_HashSet();
	inline void AssocWithGura(Object_wx_HashSet *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HashSet::~wx_HashSet()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HashSet::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHashSet
//----------------------------------------------------------------------------
Gura_DeclareFunction(HashSet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HashSet));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HashSet)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_HashSet *pEntity = new wx_HashSet();
	Object_wx_HashSet *pObj = Object_wx_HashSet::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HashSet(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(HashSet_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HashSet));
	DeclareArg(env, "set", VTYPE_wx_HashSet, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HashSet_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxHashSet *set = Object_wx_HashSet::GetObject(args, 0)->GetEntity();
	wx_HashSet *pEntity = new wx_HashSet(*set);
	Object_wx_HashSet *pObj = Object_wx_HashSet::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HashSet(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_HashSet, begin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, begin)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, begin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, begin_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, count)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, count)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, empty)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->empty();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HashSet, end)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, end)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, end_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, end_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, erase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, erase)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, erase_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_HashSet, erase_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, erase_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_HashSet, erase_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, find)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, find_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, find_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, size)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxHashSet
//----------------------------------------------------------------------------
Object_wx_HashSet::~Object_wx_HashSet()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_HashSet::Clone() const
{
	return nullptr;
}

String Object_wx_HashSet::ToString(bool exprFlag)
{
	String rtn("<wx.HashSet:");
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
// Class implementation for wxHashSet
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HashSet)
{
	Gura_AssignFunction(HashSet);
	Gura_AssignFunction(HashSet_1);
	Gura_AssignMethod(wx_HashSet, begin);
	Gura_AssignMethod(wx_HashSet, begin_1);
	Gura_AssignMethod(wx_HashSet, clear);
	Gura_AssignMethod(wx_HashSet, count);
	Gura_AssignMethod(wx_HashSet, empty);
	Gura_AssignMethod(wx_HashSet, end);
	Gura_AssignMethod(wx_HashSet, end_1);
	Gura_AssignMethod(wx_HashSet, erase);
	Gura_AssignMethod(wx_HashSet, erase_1);
	Gura_AssignMethod(wx_HashSet, erase_2);
	Gura_AssignMethod(wx_HashSet, find);
	Gura_AssignMethod(wx_HashSet, find_1);
	Gura_AssignMethod(wx_HashSet, insert);
	Gura_AssignMethod(wx_HashSet, size);
}

Gura_ImplementDescendantCreator(wx_HashSet)
{
	return new Object_wx_HashSet((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
