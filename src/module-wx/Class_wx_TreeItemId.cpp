//----------------------------------------------------------------------------
// wxTreeItemId
// extracted from treectrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TreeItemId: public wxTreeItemId, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TreeItemId *_pObj;
public:
	inline wx_TreeItemId() : wxTreeItemId(), _pObj(nullptr) {}
	~wx_TreeItemId();
	inline void AssocWithGura(Object_wx_TreeItemId *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TreeItemId::~wx_TreeItemId()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TreeItemId::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeItemId
//----------------------------------------------------------------------------
Gura_DeclareFunction(TreeItemId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TreeItemId));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TreeItemId)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_TreeItemId *pEntity = new wx_TreeItemId();
	Object_wx_TreeItemId *pObj = Object_wx_TreeItemId::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_TreeItemId(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_TreeItemId, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeItemId, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeItemId *pThis = Object_wx_TreeItemId::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, arg, Value(rtn));
}

// operator ==
Gura_ImplementBinaryOperator(Eq, wx_TreeItemId, wx_TreeItemId)
{
	wxTreeItemId *item1 = Object_wx_TreeItemId::GetObject(valueLeft)->GetEntity();
	wxTreeItemId *item2 = Object_wx_TreeItemId::GetObject(valueRight)->GetEntity();
	return *item1 == *item2;
}

// operator !=
Gura_ImplementBinaryOperator(Ne, wx_TreeItemId, wx_TreeItemId)
{
	wxTreeItemId *item1 = Object_wx_TreeItemId::GetObject(valueLeft)->GetEntity();
	wxTreeItemId *item2 = Object_wx_TreeItemId::GetObject(valueRight)->GetEntity();
	return *item1 != *item2;
}

// operator !
Gura_ImplementUnaryOperator(Not, wx_TreeItemId)
{
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(value)->GetEntity();
	return Value(!*item);
}

//----------------------------------------------------------------------------
// Object implementation for wxTreeItemId
//----------------------------------------------------------------------------
Object_wx_TreeItemId::~Object_wx_TreeItemId()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_TreeItemId::Clone() const
{
	return nullptr;
}

String Object_wx_TreeItemId::ToString(bool exprFlag)
{
	String rtn("<wx.TreeItemId:");
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
// Class implementation for wxTreeItemId
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeItemId)
{
	Gura_AssignFunction(TreeItemId);
	Gura_AssignBinaryOperator(Eq, wx_TreeItemId, wx_TreeItemId);
	Gura_AssignBinaryOperator(Ne, wx_TreeItemId, wx_TreeItemId);
	Gura_AssignUnaryOperator(Not, wx_TreeItemId);
	Gura_AssignMethod(wx_TreeItemId, IsOk);
}

Gura_ImplementDescendantCreator(wx_TreeItemId)
{
	return new Object_wx_TreeItemId((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
