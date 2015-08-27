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
	//Gura::Signal *_pSig;
	Object_wx_HashMap *_pObj;
public:
	inline wx_HashMap(size_type size) : wxHashMap(size), _pObj(nullptr) {}
	inline wx_HashMap(const wxHashMap& map) : wxHashMap(map), _pObj(nullptr) {}
	~wx_HashMap();
	inline void AssocWithGura(Object_wx_HashMap *pObj) {
		_pObj = pObj;
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_HashMap *pEntity = new wx_HashMap();
	Object_wx_HashMap *pObj = Object_wx_HashMap::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HashMap(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxHashMap *map = Object_wx_HashMap::GetObject(args, 0)->GetEntity();
	wx_HashMap *pEntity = new wx_HashMap(*map);
	Object_wx_HashMap *pObj = Object_wx_HashMap::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HashMap(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_HashMap, begin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, begin)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, begin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, begin_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, count)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, count)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, empty)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->empty();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HashMap, end)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, end)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, end_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, end_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, erase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, erase)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, erase_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_HashMap, erase_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, erase_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_HashMap, erase_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, find)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, find_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, find_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashMap, size)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
