//----------------------------------------------------------------------------
// wxNode
// extracted from node.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Node: public wxNode, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Node *_pObj;
public:
	~wx_Node();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Node *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Node::~wx_Node()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Node::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxNode
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Node, GetData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Node, GetData)
{
	Object_wx_Node *pThis = Object_wx_Node::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_Node, GetNext)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Node, GetNext)
{
	Object_wx_Node *pThis = Object_wx_Node::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_Node, GetPrevious)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Node, GetPrevious)
{
	Object_wx_Node *pThis = Object_wx_Node::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_Node, SetData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Node, IndexOf)
{
#if 0
	Object_wx_Node *pThis = Object_wx_Node::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->IndexOf();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxNode
//----------------------------------------------------------------------------
Object_wx_Node::~Object_wx_Node()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_Node::Clone() const
{
	return NULL;
}

String Object_wx_Node::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Node:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Node::DoAssignConstructor(Environment &env, Signal sig)
{
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
	return new Object_wx_Node((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
