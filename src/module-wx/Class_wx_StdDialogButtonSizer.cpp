//----------------------------------------------------------------------------
// wxStdDialogButtonSizer
// extracted from stdbtnsz.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StdDialogButtonSizer: public wxStdDialogButtonSizer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_StdDialogButtonSizer *_pObj;
public:
	inline wx_StdDialogButtonSizer() : wxStdDialogButtonSizer(), _pObj(nullptr) {}
	~wx_StdDialogButtonSizer();
	inline void AssocWithGura(Object_wx_StdDialogButtonSizer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StdDialogButtonSizer::~wx_StdDialogButtonSizer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_StdDialogButtonSizer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStdDialogButtonSizer
//----------------------------------------------------------------------------
Gura_DeclareFunction(StdDialogButtonSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StdDialogButtonSizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StdDialogButtonSizer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_StdDialogButtonSizer *pEntity = new wx_StdDialogButtonSizer();
	Object_wx_StdDialogButtonSizer *pObj = Object_wx_StdDialogButtonSizer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_StdDialogButtonSizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, AddButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "button", VTYPE_wx_Button, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, AddButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxButton *button = Object_wx_Button::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AddButton(button);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, Realize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, Realize)
{
	Signal &sig = env.GetSignal();
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, SetAffirmativeButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "button", VTYPE_wx_Button, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, SetAffirmativeButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxButton *button = Object_wx_Button::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetAffirmativeButton(button);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, SetCancelButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "button", VTYPE_wx_Button, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, SetCancelButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxButton *button = Object_wx_Button::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetCancelButton(button);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, SetNegativeButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "button", VTYPE_wx_Button, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, SetNegativeButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxButton *button = Object_wx_Button::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetNegativeButton(button);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxStdDialogButtonSizer
//----------------------------------------------------------------------------
Object_wx_StdDialogButtonSizer::~Object_wx_StdDialogButtonSizer()
{
}

Object *Object_wx_StdDialogButtonSizer::Clone() const
{
	return nullptr;
}

String Object_wx_StdDialogButtonSizer::ToString(bool exprFlag)
{
	String rtn("<wx.StdDialogButtonSizer:");
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
	return new Object_wx_StdDialogButtonSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
