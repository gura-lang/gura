//----------------------------------------------------------------------------
// wxNode
// extracted from node.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Node: public wxNode, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Node *_pObj;
public:
	~wx_Node();
	inline void AssocWithGura(Object_wx_Node *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Node::~wx_Node()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Node::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxNode
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Node, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Node, GetData)
{
	Object_wx_Node *pThis = Object_wx_Node::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_Node, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Node, GetNext)
{
	Object_wx_Node *pThis = Object_wx_Node::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_Node, GetPrevious)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Node, GetPrevious)
{
	Object_wx_Node *pThis = Object_wx_Node::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_Node, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
#endif
}

Gura_ImplementMethod(wx_Node, SetData)
{
#if 0
	Object_wx_Node *pThis = Object_wx_Node::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->SetData();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Node, IndexOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Node, IndexOf)
{
#if 0
	Object_wx_Node *pThis = Object_wx_Node::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->IndexOf();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxNode
//----------------------------------------------------------------------------
Object_wx_Node::~Object_wx_Node()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_Node::Clone() const
{
	return nullptr;
}

String Object_wx_Node::ToString(bool exprFlag)
{
	String rtn("<wx.Node:");
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
// Class implementation for wxNode
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Node)
{
	Gura_AssignMethod(wx_Node, GetData);
	Gura_AssignMethod(wx_Node, GetNext);
	Gura_AssignMethod(wx_Node, GetPrevious);
	Gura_AssignMethod(wx_Node, SetData);
	Gura_AssignMethod(wx_Node, IndexOf);
}

Gura_ImplementDescendantCreator(wx_Node)
{
	return new Object_wx_Node((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
