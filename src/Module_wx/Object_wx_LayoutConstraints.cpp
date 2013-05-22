//----------------------------------------------------------------------------
// wxLayoutConstraints
// extracted from layout.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LayoutConstraints: public wxLayoutConstraints, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_LayoutConstraints *_pObj;
public:
	inline wx_LayoutConstraints() : wxLayoutConstraints(), _sig(NULL), _pObj(NULL) {}
	~wx_LayoutConstraints();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_LayoutConstraints *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LayoutConstraints::~wx_LayoutConstraints()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_LayoutConstraints::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLayoutConstraints
//----------------------------------------------------------------------------
Gura_DeclareFunction(LayoutConstraintsEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_LayoutConstraints));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LayoutConstraintsEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_LayoutConstraints *pEntity = new wx_LayoutConstraints();
	Object_wx_LayoutConstraints *pObj = Object_wx_LayoutConstraints::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_LayoutConstraints(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxLayoutConstraints
//----------------------------------------------------------------------------
Object_wx_LayoutConstraints::~Object_wx_LayoutConstraints()
{
}

Object *Object_wx_LayoutConstraints::Clone() const
{
	return NULL;
}

String Object_wx_LayoutConstraints::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.LayoutConstraints:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_LayoutConstraints::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(LayoutConstraintsEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxLayoutConstraints
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LayoutConstraints)
{
}

Gura_ImplementDescendantCreator(wx_LayoutConstraints)
{
	return new Object_wx_LayoutConstraints((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
