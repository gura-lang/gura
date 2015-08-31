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
	//Gura::Signal *_pSig;
	Object_wx_AcceleratorTable *_pObj;
public:
	inline wx_AcceleratorTable() : wxAcceleratorTable(), _pObj(nullptr) {}
	inline wx_AcceleratorTable(const wxAcceleratorTable& table) : wxAcceleratorTable(table), _pObj(nullptr) {}
	inline wx_AcceleratorTable(int n, wxAcceleratorEntry entries[]) : wxAcceleratorTable(n, entries), _pObj(nullptr) {}
#if defined(__WXMSW__)
	inline wx_AcceleratorTable(const wxString& resource) : wxAcceleratorTable(resource), _pObj(nullptr) {}
#endif
	~wx_AcceleratorTable();
	inline void AssocWithGura(Object_wx_AcceleratorTable *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AcceleratorTable::~wx_AcceleratorTable()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_AcceleratorTable::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAcceleratorTable
//----------------------------------------------------------------------------
Gura_DeclareFunction(AcceleratorTableEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AcceleratorTable));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AcceleratorTableEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_AcceleratorTable *pEntity = new wx_AcceleratorTable();
	Object_wx_AcceleratorTable *pObj = Object_wx_AcceleratorTable::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_AcceleratorTable(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(AcceleratorTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_AcceleratorTable));
	DeclareArg(env, "entries", VTYPE_wx_AcceleratorEntry, OCCUR_Once, FLAG_ListVar);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AcceleratorTable)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	CArrayOfAcceleratorEntry entries(arg.GetList(0));
	wx_AcceleratorTable *pEntity = new wx_AcceleratorTable(entries.Count(), entries.Data());
	Object_wx_AcceleratorTable *pObj = Object_wx_AcceleratorTable::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_AcceleratorTable(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

#if 0
Gura_DeclareFunction(AcceleratorTable_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_AcceleratorTable));
	DeclareArg(env, "resource", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AcceleratorTable_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString resource = wxString::FromUTF8(arg.GetString(0));
	wx_AcceleratorTable *pEntity = new wx_AcceleratorTable(resource);
	Object_wx_AcceleratorTable *pObj = Object_wx_AcceleratorTable::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_AcceleratorTable(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}
#endif

Gura_DeclareMethod(wx_AcceleratorTable, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AcceleratorTable, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorTable *pThis = Object_wx_AcceleratorTable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxAcceleratorTable
//----------------------------------------------------------------------------
Object_wx_AcceleratorTable::~Object_wx_AcceleratorTable()
{
}

Object *Object_wx_AcceleratorTable::Clone() const
{
	return nullptr;
}

String Object_wx_AcceleratorTable::ToString(bool exprFlag)
{
	String rtn("<wx.AcceleratorTable:");
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
	return new Object_wx_AcceleratorTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
