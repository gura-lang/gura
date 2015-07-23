//----------------------------------------------------------------------------
// wxLayoutConstraints
// extracted from layout.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LayoutConstraints: public wxLayoutConstraints, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_LayoutConstraints *_pObj;
public:
	inline wx_LayoutConstraints() : wxLayoutConstraints(), _pObj(nullptr) {}
	~wx_LayoutConstraints();
	inline void AssocWithGura(Object_wx_LayoutConstraints *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LayoutConstraints::~wx_LayoutConstraints()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_LayoutConstraints::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLayoutConstraints
//----------------------------------------------------------------------------
Gura_DeclareFunction(LayoutConstraintsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_LayoutConstraints));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LayoutConstraintsEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_LayoutConstraints *pEntity = new wx_LayoutConstraints();
	Object_wx_LayoutConstraints *pObj = Object_wx_LayoutConstraints::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_LayoutConstraints(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxLayoutConstraints
//----------------------------------------------------------------------------
Object_wx_LayoutConstraints::~Object_wx_LayoutConstraints()
{
}

Object *Object_wx_LayoutConstraints::Clone() const
{
	return nullptr;
}

String Object_wx_LayoutConstraints::ToString(bool exprFlag)
{
	String rtn("<wx.LayoutConstraints:");
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
// Class implementation for wxLayoutConstraints
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LayoutConstraints)
{
	Gura_AssignFunction(LayoutConstraintsEmpty);
}

Gura_ImplementDescendantCreator(wx_LayoutConstraints)
{
	return new Object_wx_LayoutConstraints((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
