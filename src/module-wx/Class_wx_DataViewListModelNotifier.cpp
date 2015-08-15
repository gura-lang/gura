//----------------------------------------------------------------------------
// wxDataViewListModelNotifier
// extracted from dataviewlistmodelnotifier.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewListModelNotifier: public wxDataViewListModelNotifier, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DataViewListModelNotifier *_pObj;
public:
	//inline wx_DataViewListModelNotifier() : wxDataViewListModelNotifier(), _pObj(nullptr) {}
	~wx_DataViewListModelNotifier();
	inline void AssocWithGura(Object_wx_DataViewListModelNotifier *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewListModelNotifier::~wx_DataViewListModelNotifier()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataViewListModelNotifier::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewListModelNotifier
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewListModelNotifierEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DataViewListModelNotifier));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DataViewListModelNotifierEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_DataViewListModelNotifier *pEntity = new wx_DataViewListModelNotifier();
	Object_wx_DataViewListModelNotifier *pObj = Object_wx_DataViewListModelNotifier::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataViewListModelNotifier(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListModelNotifier, Cleared)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModelNotifier, Cleared)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListModelNotifier *pThis = Object_wx_DataViewListModelNotifier::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Cleared();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewListModelNotifier, GetOwner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModelNotifier, GetOwner)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListModelNotifier *pThis = Object_wx_DataViewListModelNotifier::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataViewListModel *rtn = (wxDataViewListModel *)pThis->GetEntity()->GetOwner();
	return ReturnValue(env, args, Value(new Object_wx_DataViewListModel(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DataViewListModelNotifier, RowAppended)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModelNotifier, RowAppended)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListModelNotifier *pThis = Object_wx_DataViewListModelNotifier::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->RowAppended();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewListModelNotifier, RowChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModelNotifier, RowChanged)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListModelNotifier *pThis = Object_wx_DataViewListModelNotifier::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned row = args.GetInt(0);
	bool rtn = pThis->GetEntity()->RowChanged(row);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewListModelNotifier, RowDeleted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModelNotifier, RowDeleted)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListModelNotifier *pThis = Object_wx_DataViewListModelNotifier::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned row = args.GetInt(0);
	bool rtn = pThis->GetEntity()->RowDeleted(row);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewListModelNotifier, RowInserted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModelNotifier, RowInserted)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListModelNotifier *pThis = Object_wx_DataViewListModelNotifier::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned before = args.GetInt(0);
	bool rtn = pThis->GetEntity()->RowInserted(before);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewListModelNotifier, RowPrepended)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModelNotifier, RowPrepended)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListModelNotifier *pThis = Object_wx_DataViewListModelNotifier::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->RowPrepended();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewListModelNotifier, RowsReordered)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "new_order", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModelNotifier, RowsReordered)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataViewListModelNotifier *pThis = Object_wx_DataViewListModelNotifier::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned int new_order = args.GetUInt(0);
	bool rtn = pThis->GetEntity()->RowsReordered(new_order);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListModelNotifier, SetOwner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "owner", VTYPE_wx_DataViewListModel, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListModelNotifier, SetOwner)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListModelNotifier *pThis = Object_wx_DataViewListModelNotifier::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataViewListModel *owner = Object_wx_DataViewListModel::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetOwner(owner);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListModelNotifier, ValueChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModelNotifier, ValueChanged)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListModelNotifier *pThis = Object_wx_DataViewListModelNotifier::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned col = args.GetInt(0);
	unsigned row = args.GetInt(1);
	bool rtn = pThis->GetEntity()->ValueChanged(col, row);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewListModelNotifier
//----------------------------------------------------------------------------
Object_wx_DataViewListModelNotifier::~Object_wx_DataViewListModelNotifier()
{
}

Object *Object_wx_DataViewListModelNotifier::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewListModelNotifier::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewListModelNotifier:");
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
// Class implementation for wxDataViewListModelNotifier
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewListModelNotifier)
{
	Gura_AssignFunction(DataViewListModelNotifierEmpty);
	Gura_AssignMethod(wx_DataViewListModelNotifier, Cleared);
	Gura_AssignMethod(wx_DataViewListModelNotifier, GetOwner);
	Gura_AssignMethod(wx_DataViewListModelNotifier, RowAppended);
	Gura_AssignMethod(wx_DataViewListModelNotifier, RowChanged);
	Gura_AssignMethod(wx_DataViewListModelNotifier, RowDeleted);
	Gura_AssignMethod(wx_DataViewListModelNotifier, RowInserted);
	Gura_AssignMethod(wx_DataViewListModelNotifier, RowPrepended);
	Gura_AssignMethod(wx_DataViewListModelNotifier, RowsReordered);
	Gura_AssignMethod(wx_DataViewListModelNotifier, SetOwner);
	Gura_AssignMethod(wx_DataViewListModelNotifier, ValueChanged);
}

Gura_ImplementDescendantCreator(wx_DataViewListModelNotifier)
{
	return new Object_wx_DataViewListModelNotifier((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
