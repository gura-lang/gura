//----------------------------------------------------------------------------
// wxHashTable
// extracted from hash.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HashTable: public wxHashTable, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HashTable *_pObj;
public:
	//inline wx_HashTable(unsigned int key_type, int size) : wxHashTable(key_type, size), _pObj(nullptr) {}
	~wx_HashTable();
	inline void AssocWithGura(Object_wx_HashTable *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HashTable::~wx_HashTable()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HashTable::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHashTable
//----------------------------------------------------------------------------
Gura_DeclareFunction(HashTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HashTable));
	DeclareArg(env, "key_type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HashTable)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	unsigned key_type = args.GetInt(0);
	int size = 1000;
	if (args.IsValid(1)) size = args.GetInt(1);
	wx_HashTable *pEntity = new wx_HashTable(key_type, size);
	Object_wx_HashTable *pObj = Object_wx_HashTable::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HashTable(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HashTable, BeginFind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashTable, BeginFind)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->BeginFind();
	return Value::Null;
}

Gura_DeclareMethod(wx_HashTable, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashTable, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Clear();
	return Value::Null;
}

Gura_DeclareMethod(wx_HashTable, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashTable, Delete)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long key = args.GetLong(0);
	wxObject *rtn = (wxObject *)pThis->GetEntity()->Delete(key);
	return ReturnValue(env, args, Value(new Object_wx_Object(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HashTable, Delete_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashTable, Delete_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	wxObject *rtn = (wxObject *)pThis->GetEntity()->Delete(key);
	return ReturnValue(env, args, Value(new Object_wx_Object(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HashTable, DeleteContents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, DeleteContents)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->DeleteContents(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_HashTable, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashTable, Get)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long key = args.GetLong(0);
	wxObject *rtn = (wxObject *)pThis->GetEntity()->Get(key);
	return ReturnValue(env, args, Value(new Object_wx_Object(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HashTable, Get_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashTable, Get_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char key = args.GetChar(0);
	wxObject *rtn = (wxObject *)pThis->GetEntity()->Get(key);
	return ReturnValue(env, args, Value(new Object_wx_Object(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HashTable, MakeKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashTable, MakeKey)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString string = wxString::FromUTF8(args.GetString(0));
	long rtn = pThis->GetEntity()->MakeKey(string);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HashTable, Next)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashTable, Next)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashTable, Put)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "object", VTYPE_wx_Object, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, Put)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long key = args.GetLong(0);
	wxObject *object = Object_wx_Object::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->Put(key, object);
	return Value::Null;
}

Gura_DeclareMethod(wx_HashTable, Put_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "object", VTYPE_wx_Object, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, Put_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char key = args.GetChar(0);
	wxObject *object = Object_wx_Object::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->Put(key, object);
	return Value::Null;
}

Gura_DeclareMethod(wx_HashTable, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashTable, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetCount();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxHashTable
//----------------------------------------------------------------------------
Object_wx_HashTable::~Object_wx_HashTable()
{
}

Object *Object_wx_HashTable::Clone() const
{
	return nullptr;
}

String Object_wx_HashTable::ToString(bool exprFlag)
{
	String rtn("<wx.HashTable:");
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
// Class implementation for wxHashTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HashTable)
{
	Gura_AssignFunction(HashTable);
	Gura_AssignMethod(wx_HashTable, BeginFind);
	Gura_AssignMethod(wx_HashTable, Clear);
	Gura_AssignMethod(wx_HashTable, Delete);
	Gura_AssignMethod(wx_HashTable, Delete_1);
	Gura_AssignMethod(wx_HashTable, DeleteContents);
	Gura_AssignMethod(wx_HashTable, Get);
	Gura_AssignMethod(wx_HashTable, Get_1);
	Gura_AssignMethod(wx_HashTable, MakeKey);
	Gura_AssignMethod(wx_HashTable, Next);
	Gura_AssignMethod(wx_HashTable, Put);
	Gura_AssignMethod(wx_HashTable, Put_1);
	Gura_AssignMethod(wx_HashTable, GetCount);
}

Gura_ImplementDescendantCreator(wx_HashTable)
{
	return new Object_wx_HashTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
