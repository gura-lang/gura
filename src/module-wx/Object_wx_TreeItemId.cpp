//----------------------------------------------------------------------------
// wxTreeItemId
// extracted from treectrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TreeItemId: public wxTreeItemId, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TreeItemId *_pObj;
public:
	inline wx_TreeItemId() : wxTreeItemId(), _sig(NULL), _pObj(NULL) {}
	~wx_TreeItemId();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TreeItemId *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TreeItemId::~wx_TreeItemId()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TreeItemId::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeItemId
//----------------------------------------------------------------------------
Gura_DeclareFunction(TreeItemId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TreeItemId));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TreeItemId)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_TreeItemId *pEntity = new wx_TreeItemId();
	Object_wx_TreeItemId *pObj = Object_wx_TreeItemId::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TreeItemId(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TreeItemId, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeItemId, IsOk)
{
	Object_wx_TreeItemId *pThis = Object_wx_TreeItemId::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
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
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_TreeItemId::Clone() const
{
	return NULL;
}

String Object_wx_TreeItemId::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TreeItemId:");
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
	return new Object_wx_TreeItemId((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
