//----------------------------------------------------------------------------
// wxBoxSizer
// extracted from boxsizer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BoxSizer));
	DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BoxSizer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int orient = args.GetInt(0);
	wx_BoxSizer *pEntity = new wx_BoxSizer(orient);
	Object_wx_BoxSizer *pObj = Object_wx_BoxSizer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_BoxSizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_BoxSizer, RecalcSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BoxSizer, RecalcSizes)
{
	Object_wx_BoxSizer *pThis = Object_wx_BoxSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->RecalcSizes();
	return Value::Null;
}

Gura_DeclareMethod(wx_BoxSizer, CalcMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BoxSizer, CalcMin)
{
	Object_wx_BoxSizer *pThis = Object_wx_BoxSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->CalcMin();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_BoxSizer, GetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BoxSizer, GetOrientation)
{
	Object_wx_BoxSizer *pThis = Object_wx_BoxSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetOrientation();
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

String Object_wx_BoxSizer::ToString(bool exprFlag)
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

//----------------------------------------------------------------------------
// Class implementation for wxBoxSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BoxSizer)
{
	Gura_AssignFunction(BoxSizer);
	Gura_AssignMethod(wx_BoxSizer, RecalcSizes);
	Gura_AssignMethod(wx_BoxSizer, CalcMin);
	Gura_AssignMethod(wx_BoxSizer, GetOrientation);
}

Gura_ImplementDescendantCreator(wx_BoxSizer)
{
	return new Object_wx_BoxSizer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
