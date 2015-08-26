//----------------------------------------------------------------------------
// wxIndividualLayoutConstraint
// extracted from ilayout.tex
//----------------------------------------------------------------------------
#include "stdafx.h"
#undef Above
#undef Below

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_IndividualLayoutConstraint: public wxIndividualLayoutConstraint, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_IndividualLayoutConstraint *_pObj;
public:
	inline wx_IndividualLayoutConstraint() : wxIndividualLayoutConstraint(), _pObj(nullptr) {}
	~wx_IndividualLayoutConstraint();
	inline void AssocWithGura(Object_wx_IndividualLayoutConstraint *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_IndividualLayoutConstraint::~wx_IndividualLayoutConstraint()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_IndividualLayoutConstraint::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
Gura_DeclareFunction(IndividualLayoutConstraintEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_IndividualLayoutConstraint));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IndividualLayoutConstraintEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_IndividualLayoutConstraint *pEntity = new wx_IndividualLayoutConstraint();
	Object_wx_IndividualLayoutConstraint *pObj = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_IndividualLayoutConstraint(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Above)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "otherWin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "margin", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Above)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *otherWin = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int margin = 0;
	if (args.IsValid(1)) margin = args.GetInt(1);
	pThis->GetEntity()->Above(otherWin, margin);
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Absolute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Absolute)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int value = args.GetInt(0);
	pThis->GetEntity()->Absolute(value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, AsIs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, AsIs)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->AsIs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Below)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "otherWin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "margin", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Below)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *otherWin = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int margin = 0;
	if (args.IsValid(1)) margin = args.GetInt(1);
	pThis->GetEntity()->Below(otherWin, margin);
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Unconstrained)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Unconstrained)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Unconstrained();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, LeftOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "otherWin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "margin", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, LeftOf)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *otherWin = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int margin = 0;
	if (args.IsValid(1)) margin = args.GetInt(1);
	pThis->GetEntity()->LeftOf(otherWin, margin);
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, PercentOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "otherWin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "per", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, PercentOf)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *otherWin = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxEdge edge = static_cast<wxEdge>(args.GetInt(1));
	int per = args.GetInt(2);
	pThis->GetEntity()->PercentOf(otherWin, edge, per);
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, RightOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "otherWin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "margin", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, RightOf)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *otherWin = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int margin = 0;
	if (args.IsValid(1)) margin = args.GetInt(1);
	pThis->GetEntity()->RightOf(otherWin, margin);
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, SameAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "otherWin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "margin", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, SameAs)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *otherWin = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxEdge edge = static_cast<wxEdge>(args.GetInt(1));
	int margin = 0;
	if (args.IsValid(2)) margin = args.GetInt(2);
	pThis->GetEntity()->SameAs(otherWin, edge, margin);
	return Value::Nil;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rel", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "otherWin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "otherEdge", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "margin", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRelationship rel = static_cast<wxRelationship>(args.GetInt(0));
	wxWindow *otherWin = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxEdge otherEdge = static_cast<wxEdge>(args.GetInt(2));
	int value = 0;
	if (args.IsValid(3)) value = args.GetInt(3);
	int margin = 0;
	if (args.IsValid(4)) margin = args.GetInt(4);
	pThis->GetEntity()->Set(rel, otherWin, otherEdge, value, margin);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
Object_wx_IndividualLayoutConstraint::~Object_wx_IndividualLayoutConstraint()
{
}

Object *Object_wx_IndividualLayoutConstraint::Clone() const
{
	return nullptr;
}

String Object_wx_IndividualLayoutConstraint::ToString(bool exprFlag)
{
	String rtn("<wx.IndividualLayoutConstraint:");
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
// Class implementation for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IndividualLayoutConstraint)
{
	Gura_AssignFunction(IndividualLayoutConstraintEmpty);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, Above);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, Absolute);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, AsIs);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, Below);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, Unconstrained);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, LeftOf);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, PercentOf);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, RightOf);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, SameAs);
	Gura_AssignMethod(wx_IndividualLayoutConstraint, Set);
}

Gura_ImplementDescendantCreator(wx_IndividualLayoutConstraint)
{
	return new Object_wx_IndividualLayoutConstraint((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
