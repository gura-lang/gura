//----------------------------------------------------------------------------
// wxHashTable
// extracted from hash.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HashTable: public wxHashTable, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HashTable *_pObj;
public:
	//inline wx_HashTable(unsigned int key_type, int size) : wxHashTable(key_type, size), _sig(NULL), _pObj(NULL) {}
	~wx_HashTable();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HashTable *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HashTable::~wx_HashTable()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HashTable::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHashTable
//----------------------------------------------------------------------------
Gura_DeclareFunction(HashTable)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HashTable));
	DeclareArg(env, "key_type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HashTable)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	unsigned key_type = args.GetInt(0);
	int size = 1000;
	if (args.IsValid(1)) size = args.GetInt(1);
	wx_HashTable *pEntity = new wx_HashTable(key_type, size);
	Object_wx_HashTable *pObj = Object_wx_HashTable::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HashTable(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HashTable, BeginFind)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashTable, BeginFind)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->BeginFind();
	return Value::Null;
}

Gura_DeclareMethod(wx_HashTable, Clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashTable, Clear)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Clear();
	return Value::Null;
}

Gura_DeclareMethod(wx_HashTable, Delete)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashTable, Delete)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long key = args.GetLong(0);
	wxObject *rtn = (wxObject *)pThis->GetEntity()->Delete(key);
	return ReturnValue(env, sig, args, Value(new Object_wx_Object(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HashTable, Delete_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashTable, Delete_1)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	wxObject *rtn = (wxObject *)pThis->GetEntity()->Delete(key);
	return ReturnValue(env, sig, args, Value(new Object_wx_Object(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HashTable, DeleteContents)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, DeleteContents)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->DeleteContents(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_HashTable, Get)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashTable, Get)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long key = args.GetLong(0);
	wxObject *rtn = (wxObject *)pThis->GetEntity()->Get(key);
	return ReturnValue(env, sig, args, Value(new Object_wx_Object(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HashTable, Get_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashTable, Get_1)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char key = args.GetChar(0);
	wxObject *rtn = (wxObject *)pThis->GetEntity()->Get(key);
	return ReturnValue(env, sig, args, Value(new Object_wx_Object(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HashTable, MakeKey)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashTable, MakeKey)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString string = wxString::FromUTF8(args.GetString(0));
	long rtn = pThis->GetEntity()->MakeKey(string);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HashTable, Next)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashTable, Next)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_HashTable, Put)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "object", VTYPE_wx_Object, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, Put)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long key = args.GetLong(0);
	wxObject *object = Object_wx_Object::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->Put(key, object);
	return Value::Null;
}

Gura_DeclareMethod(wx_HashTable, Put_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "object", VTYPE_wx_Object, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, Put_1)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char key = args.GetChar(0);
	wxObject *object = Object_wx_Object::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->Put(key, object);
	return Value::Null;
}

Gura_DeclareMethod(wx_HashTable, GetCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HashTable, GetCount)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxHashTable
//----------------------------------------------------------------------------
Object_wx_HashTable::~Object_wx_HashTable()
{
}

Object *Object_wx_HashTable::Clone() const
{
	return NULL;
}

String Object_wx_HashTable::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HashTable:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_HashTable::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(HashTable);
}

//----------------------------------------------------------------------------
// Class implementation for wxHashTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HashTable)
{
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
	return new Object_wx_HashTable((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
