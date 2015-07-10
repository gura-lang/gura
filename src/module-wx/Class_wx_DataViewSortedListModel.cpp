//----------------------------------------------------------------------------
// wxDataViewSortedListModel
// extracted from dataviewmodel.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewSortedListModel: public wxDataViewSortedListModel, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_DataViewSortedListModel *_pObj;
public:
	inline wx_DataViewSortedListModel(wxDataViewListModel* child) : wxDataViewSortedListModel(child), _pSig(nullptr), _pObj(nullptr) {}
	~wx_DataViewSortedListModel();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataViewSortedListModel *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewSortedListModel::~wx_DataViewSortedListModel()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataViewSortedListModel::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewSortedListModel
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewSortedListModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataViewSortedListModel));
	DeclareArg(env, "child", VTYPE_wx_DataViewListModel, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewSortedListModel)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDataViewListModel *child = Object_wx_DataViewListModel::GetObject(args, 0)->GetEntity();
	wx_DataViewSortedListModel *pEntity = new wx_DataViewSortedListModel(child);
	Object_wx_DataViewSortedListModel *pObj = Object_wx_DataViewSortedListModel::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataViewSortedListModel(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_DataViewSortedListModel, GetAscending)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewSortedListModel, GetAscending)
{
	Object_wx_DataViewSortedListModel *pThis = Object_wx_DataViewSortedListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetAscending();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewSortedListModel, Resort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewSortedListModel, Resort)
{
	Object_wx_DataViewSortedListModel *pThis = Object_wx_DataViewSortedListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Resort();
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewSortedListModel, SetAscending)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "ascending", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewSortedListModel, SetAscending)
{
	Object_wx_DataViewSortedListModel *pThis = Object_wx_DataViewSortedListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool ascending = args.GetBoolean(0);
	pThis->GetEntity()->SetAscending(ascending);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewSortedListModel
//----------------------------------------------------------------------------
Object_wx_DataViewSortedListModel::~Object_wx_DataViewSortedListModel()
{
}

Object *Object_wx_DataViewSortedListModel::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewSortedListModel::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewSortedListModel:");
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
// Class implementation for wxDataViewSortedListModel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewSortedListModel)
{
	Gura_AssignFunction(DataViewSortedListModel);
	Gura_AssignMethod(wx_DataViewSortedListModel, GetAscending);
	Gura_AssignMethod(wx_DataViewSortedListModel, Resort);
	Gura_AssignMethod(wx_DataViewSortedListModel, SetAscending);
}

Gura_ImplementDescendantCreator(wx_DataViewSortedListModel)
{
	return new Object_wx_DataViewSortedListModel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
