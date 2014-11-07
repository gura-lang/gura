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
	Gura::Signal _sig;
	Object_wx_HashSet *_pObj;
public:
	inline wx_HashSet(size_type size) : wxHashSet(size), _sig(NULL), _pObj(NULL) {}
	inline wx_HashSet(const wxHashSet& set) : wxHashSet(set), _sig(NULL), _pObj(NULL) {}
	~wx_HashSet();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HashSet *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HashSet::~wx_HashSet()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HashSet::GuraObjectDeleted()
{
	_pObj = NULL;
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
	if (!CheckWxReady(sig)) return Value::Null;
	wx_HashSet *pEntity = new wx_HashSet();
	Object_wx_HashSet *pObj = Object_wx_HashSet::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HashSet(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxHashSet *set = Object_wx_HashSet::GetObject(args, 0)->GetEntity();
	wx_HashSet *pEntity = new wx_HashSet(*set);
	Object_wx_HashSet *pObj = Object_wx_HashSet::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HashSet(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_HashSet, begin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, begin)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashSet, begin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, begin_1)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashSet, clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, clear)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->clear();
	return Value::Null;
}

Gura_DeclareMethod(wx_HashSet, count)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, count)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashSet, empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, empty)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->empty();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HashSet, end)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, end)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashSet, end_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, end_1)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashSet, erase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, erase)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashSet, erase_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_HashSet, erase_1)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->erase();
	return Value::Null;
}

Gura_DeclareMethod(wx_HashSet, erase_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_HashSet, erase_2)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->erase();
	return Value::Null;
}

Gura_DeclareMethod(wx_HashSet, find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, find)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashSet, find_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, find_1)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashSet, insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, insert)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashSet, size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashSet, size)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHashSet
//----------------------------------------------------------------------------
Object_wx_HashSet::~Object_wx_HashSet()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_HashSet::Clone() const
{
	return NULL;
}

String Object_wx_HashSet::ToString(bool exprFlag)
{
	String rtn("<wx.HashSet:");
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
	return new Object_wx_HashSet((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
