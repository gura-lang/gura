//----------------------------------------------------------------------------
// wxHashMap
// extracted from hashmap.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HashMap: public wxHashMap, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_HashMap *_pObj;
public:
	inline wx_HashMap(size_type size) : wxHashMap(size), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_HashMap(const wxHashMap& map) : wxHashMap(map), _pSig(nullptr), _pObj(nullptr) {}
	~wx_HashMap();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HashMap *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HashMap::~wx_HashMap()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HashMap::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHashMap
//----------------------------------------------------------------------------
Gura_DeclareFunction(HashMap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HashMap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HashMap)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_HashMap *pEntity = new wx_HashMap();
	Object_wx_HashMap *pObj = Object_wx_HashMap::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HashMap(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(HashMap_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HashMap));
	DeclareArg(env, "map", VTYPE_wx_HashMap, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HashMap_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxHashMap *map = Object_wx_HashMap::GetObject(args, 0)->GetEntity();
	wx_HashMap *pEntity = new wx_HashMap(*map);
	Object_wx_HashMap *pObj = Object_wx_HashMap::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HashMap(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_HashMap, begin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, begin)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashMap, begin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, begin_1)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashMap, clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, clear)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->clear();
	return Value::Null;
}

Gura_DeclareMethod(wx_HashMap, count)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, count)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashMap, empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, empty)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->empty();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HashMap, end)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, end)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashMap, end_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, end_1)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashMap, erase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, erase)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashMap, erase_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_HashMap, erase_1)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->erase();
	return Value::Null;
}

Gura_DeclareMethod(wx_HashMap, erase_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_HashMap, erase_2)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->erase();
	return Value::Null;
}

Gura_DeclareMethod(wx_HashMap, find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, find)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashMap, find_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, find_1)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashMap, insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, insert)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashMap, size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, size)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHashMap
//----------------------------------------------------------------------------
Object_wx_HashMap::~Object_wx_HashMap()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_HashMap::Clone() const
{
	return nullptr;
}

String Object_wx_HashMap::ToString(bool exprFlag)
{
	String rtn("<wx.HashMap:");
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
// Class implementation for wxHashMap
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HashMap)
{
	Gura_AssignFunction(HashMap);
	Gura_AssignFunction(HashMap_1);
	Gura_AssignMethod(wx_HashMap, begin);
	Gura_AssignMethod(wx_HashMap, begin_1);
	Gura_AssignMethod(wx_HashMap, clear);
	Gura_AssignMethod(wx_HashMap, count);
	Gura_AssignMethod(wx_HashMap, empty);
	Gura_AssignMethod(wx_HashMap, end);
	Gura_AssignMethod(wx_HashMap, end_1);
	Gura_AssignMethod(wx_HashMap, erase);
	Gura_AssignMethod(wx_HashMap, erase_1);
	Gura_AssignMethod(wx_HashMap, erase_2);
	Gura_AssignMethod(wx_HashMap, find);
	Gura_AssignMethod(wx_HashMap, find_1);
	Gura_AssignMethod(wx_HashMap, insert);
	Gura_AssignMethod(wx_HashMap, size);
}

Gura_ImplementDescendantCreator(wx_HashMap)
{
	return new Object_wx_HashMap((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
