//----------------------------------------------------------------------------
// wxStdDialogButtonSizer
// extracted from stdbtnsz.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StdDialogButtonSizer: public wxStdDialogButtonSizer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_StdDialogButtonSizer *_pObj;
public:
	inline wx_StdDialogButtonSizer() : wxStdDialogButtonSizer(), _sig(NULL), _pObj(NULL) {}
	~wx_StdDialogButtonSizer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StdDialogButtonSizer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StdDialogButtonSizer::~wx_StdDialogButtonSizer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StdDialogButtonSizer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStdDialogButtonSizer
//----------------------------------------------------------------------------
Gura_DeclareFunction(StdDialogButtonSizer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StdDialogButtonSizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StdDialogButtonSizer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_StdDialogButtonSizer *pEntity = new wx_StdDialogButtonSizer();
	Object_wx_StdDialogButtonSizer *pObj = Object_wx_StdDialogButtonSizer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StdDialogButtonSizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, AddButton)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "button", VTYPE_wx_Button, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, AddButton)
{
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxButton *button = Object_wx_Button::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AddButton(button);
	return Value::Null;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, Realize)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, Realize)
{
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Realize();
	return Value::Null;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, SetAffirmativeButton)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "button", VTYPE_wx_Button, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, SetAffirmativeButton)
{
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxButton *button = Object_wx_Button::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetAffirmativeButton(button);
	return Value::Null;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, SetCancelButton)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "button", VTYPE_wx_Button, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, SetCancelButton)
{
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxButton *button = Object_wx_Button::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetCancelButton(button);
	return Value::Null;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, SetNegativeButton)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "button", VTYPE_wx_Button, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, SetNegativeButton)
{
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxButton *button = Object_wx_Button::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetNegativeButton(button);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxStdDialogButtonSizer
//----------------------------------------------------------------------------
Object_wx_StdDialogButtonSizer::~Object_wx_StdDialogButtonSizer()
{
}

Object *Object_wx_StdDialogButtonSizer::Clone() const
{
	return NULL;
}

String Object_wx_StdDialogButtonSizer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.StdDialogButtonSizer:");
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
// Class implementation for wxStdDialogButtonSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StdDialogButtonSizer)
{
	Gura_AssignFunction(StdDialogButtonSizer);
	Gura_AssignMethod(wx_StdDialogButtonSizer, AddButton);
	Gura_AssignMethod(wx_StdDialogButtonSizer, Realize);
	Gura_AssignMethod(wx_StdDialogButtonSizer, SetAffirmativeButton);
	Gura_AssignMethod(wx_StdDialogButtonSizer, SetCancelButton);
	Gura_AssignMethod(wx_StdDialogButtonSizer, SetNegativeButton);
}

Gura_ImplementDescendantCreator(wx_StdDialogButtonSizer)
{
	return new Object_wx_StdDialogButtonSizer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
