//----------------------------------------------------------------------------
// wxAcceleratorTable
// extracted from accel.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AcceleratorTable: public wxAcceleratorTable, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_AcceleratorTable *_pObj;
public:
	inline wx_AcceleratorTable() : wxAcceleratorTable(), _sig(NULL), _pObj(NULL) {}
	inline wx_AcceleratorTable(const wxAcceleratorTable& table) : wxAcceleratorTable(table), _sig(NULL), _pObj(NULL) {}
	inline wx_AcceleratorTable(int n, wxAcceleratorEntry entries[]) : wxAcceleratorTable(n, entries), _sig(NULL), _pObj(NULL) {}
#if defined(__WXMSW__)
	inline wx_AcceleratorTable(const wxString& resource) : wxAcceleratorTable(resource), _sig(NULL), _pObj(NULL) {}
#endif
	~wx_AcceleratorTable();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_AcceleratorTable *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AcceleratorTable::~wx_AcceleratorTable()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_AcceleratorTable::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAcceleratorTable
//----------------------------------------------------------------------------
Gura_DeclareFunction(AcceleratorTableEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AcceleratorTable));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AcceleratorTableEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_AcceleratorTable *pEntity = new wx_AcceleratorTable();
	Object_wx_AcceleratorTable *pObj = Object_wx_AcceleratorTable::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AcceleratorTable(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(AcceleratorTable)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_AcceleratorTable));
	DeclareArg(env, "entries", VTYPE_wx_AcceleratorEntry, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AcceleratorTable)
{
	if (!CheckWxReady(sig)) return Value::Null;
	CArrayOfAcceleratorEntry entries(args.GetList(0));
	wx_AcceleratorTable *pEntity = new wx_AcceleratorTable(entries.Count(), entries.Data());
	Object_wx_AcceleratorTable *pObj = Object_wx_AcceleratorTable::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AcceleratorTable(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

#if 0
Gura_DeclareFunction(AcceleratorTable_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_AcceleratorTable));
	DeclareArg(env, "resource", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AcceleratorTable_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString resource = wxString::FromUTF8(args.GetString(0));
	wx_AcceleratorTable *pEntity = new wx_AcceleratorTable(resource);
	Object_wx_AcceleratorTable *pObj = Object_wx_AcceleratorTable::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AcceleratorTable(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}
#endif

Gura_DeclareMethod(wx_AcceleratorTable, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AcceleratorTable, IsOk)
{
	Object_wx_AcceleratorTable *pThis = Object_wx_AcceleratorTable::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxAcceleratorTable
//----------------------------------------------------------------------------
Object_wx_AcceleratorTable::~Object_wx_AcceleratorTable()
{
}

Object *Object_wx_AcceleratorTable::Clone() const
{
	return NULL;
}

String Object_wx_AcceleratorTable::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.AcceleratorTable:");
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
// Class implementation for wxAcceleratorTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AcceleratorTable)
{
	Gura_AssignFunction(AcceleratorTableEmpty);
	Gura_AssignFunction(AcceleratorTable);
	//Gura_AssignFunction(AcceleratorTable_2);
	Gura_AssignMethod(wx_AcceleratorTable, IsOk);
}

Gura_ImplementDescendantCreator(wx_AcceleratorTable)
{
	return new Object_wx_AcceleratorTable((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
