//----------------------------------------------------------------------------
// wxBoxSizer
// extracted from boxsizer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BoxSizer: public wxBoxSizer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_BoxSizer *_pObj;
public:
	inline wx_BoxSizer(int orient) : wxBoxSizer(orient), _sig(NULL), _pObj(NULL) {}
	~wx_BoxSizer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_BoxSizer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BoxSizer::~wx_BoxSizer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_BoxSizer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBoxSizer
//----------------------------------------------------------------------------
Gura_DeclareFunction(BoxSizer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BoxSizer));
	DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BoxSizer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int orient = args.GetInt(0);
	wx_BoxSizer *pEntity = new wx_BoxSizer(orient);
	Object_wx_BoxSizer *pObj = Object_wx_BoxSizer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_BoxSizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_BoxSizer, RecalcSizes)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BoxSizer, RecalcSizes)
{
	Object_wx_BoxSizer *pSelf = Object_wx_BoxSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->RecalcSizes();
	return Value::Null;
}

Gura_DeclareMethod(wx_BoxSizer, CalcMin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BoxSizer, CalcMin)
{
	Object_wx_BoxSizer *pSelf = Object_wx_BoxSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pSelf->GetEntity()->CalcMin();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_BoxSizer, GetOrientation)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BoxSizer, GetOrientation)
{
	Object_wx_BoxSizer *pSelf = Object_wx_BoxSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetOrientation();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxBoxSizer
//----------------------------------------------------------------------------
Object_wx_BoxSizer::~Object_wx_BoxSizer()
{
}

Object *Object_wx_BoxSizer::Clone() const
{
	return NULL;
}

String Object_wx_BoxSizer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.BoxSizer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_BoxSizer::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(BoxSizer);
}

//----------------------------------------------------------------------------
// Class implementation for wxBoxSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BoxSizer)
{
	Gura_AssignMethod(wx_BoxSizer, RecalcSizes);
	Gura_AssignMethod(wx_BoxSizer, CalcMin);
	Gura_AssignMethod(wx_BoxSizer, GetOrientation);
}

Gura_ImplementDescendantCreator(wx_BoxSizer)
{
	return new Object_wx_BoxSizer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
