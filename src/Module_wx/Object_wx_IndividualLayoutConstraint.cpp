//----------------------------------------------------------------------------
// wxIndividualLayoutConstraint
// extracted from ilayout.tex
//----------------------------------------------------------------------------
#include "stdafx.h"
#undef Above
#undef Below

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_IndividualLayoutConstraint: public wxIndividualLayoutConstraint, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_IndividualLayoutConstraint *_pObj;
public:
	inline wx_IndividualLayoutConstraint() : wxIndividualLayoutConstraint(), _sig(NULL), _pObj(NULL) {}
	~wx_IndividualLayoutConstraint();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_IndividualLayoutConstraint *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_IndividualLayoutConstraint::~wx_IndividualLayoutConstraint()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_IndividualLayoutConstraint::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
Gura_DeclareFunction(IndividualLayoutConstraintEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_IndividualLayoutConstraint));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IndividualLayoutConstraintEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_IndividualLayoutConstraint *pEntity = new wx_IndividualLayoutConstraint();
	Object_wx_IndividualLayoutConstraint *pObj = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_IndividualLayoutConstraint(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Above)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "otherWin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "margin", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Above)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *otherWin = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int margin = 0;
	if (args.IsValid(1)) margin = args.GetInt(1);
	pThis->GetEntity()->Above(otherWin, margin);
	return Value::Null;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Absolute)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Absolute)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int value = args.GetInt(0);
	pThis->GetEntity()->Absolute(value);
	return Value::Null;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, AsIs)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, AsIs)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->AsIs();
	return Value::Null;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Below)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "otherWin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "margin", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Below)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *otherWin = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int margin = 0;
	if (args.IsValid(1)) margin = args.GetInt(1);
	pThis->GetEntity()->Below(otherWin, margin);
	return Value::Null;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Unconstrained)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Unconstrained)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Unconstrained();
	return Value::Null;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, LeftOf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "otherWin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "margin", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, LeftOf)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *otherWin = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int margin = 0;
	if (args.IsValid(1)) margin = args.GetInt(1);
	pThis->GetEntity()->LeftOf(otherWin, margin);
	return Value::Null;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, PercentOf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "otherWin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "per", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, PercentOf)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *otherWin = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxEdge edge = static_cast<wxEdge>(args.GetInt(1));
	int per = args.GetInt(2);
	pThis->GetEntity()->PercentOf(otherWin, edge, per);
	return Value::Null;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, RightOf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "otherWin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "margin", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, RightOf)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *otherWin = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int margin = 0;
	if (args.IsValid(1)) margin = args.GetInt(1);
	pThis->GetEntity()->RightOf(otherWin, margin);
	return Value::Null;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, SameAs)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "otherWin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "margin", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, SameAs)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *otherWin = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxEdge edge = static_cast<wxEdge>(args.GetInt(1));
	int margin = 0;
	if (args.IsValid(2)) margin = args.GetInt(2);
	pThis->GetEntity()->SameAs(otherWin, edge, margin);
	return Value::Null;
}

Gura_DeclareMethod(wx_IndividualLayoutConstraint, Set)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rel", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "otherWin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "otherEdge", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "margin", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IndividualLayoutConstraint, Set)
{
	Object_wx_IndividualLayoutConstraint *pThis = Object_wx_IndividualLayoutConstraint::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRelationship rel = static_cast<wxRelationship>(args.GetInt(0));
	wxWindow *otherWin = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxEdge otherEdge = static_cast<wxEdge>(args.GetInt(2));
	int value = 0;
	if (args.IsValid(3)) value = args.GetInt(3);
	int margin = 0;
	if (args.IsValid(4)) margin = args.GetInt(4);
	pThis->GetEntity()->Set(rel, otherWin, otherEdge, value, margin);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
Object_wx_IndividualLayoutConstraint::~Object_wx_IndividualLayoutConstraint()
{
}

Object *Object_wx_IndividualLayoutConstraint::Clone() const
{
	return NULL;
}

String Object_wx_IndividualLayoutConstraint::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.IndividualLayoutConstraint:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_IndividualLayoutConstraint::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(IndividualLayoutConstraintEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IndividualLayoutConstraint)
{
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
	return new Object_wx_IndividualLayoutConstraint((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
