//----------------------------------------------------------------------------
// wxValidator
// extracted from validatr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(Clone);
Gura_DeclarePrivUserSymbol(TransferFromWindow);
Gura_DeclarePrivUserSymbol(TransferToWindow);
Gura_DeclarePrivUserSymbol(Validate);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Validator: public wxValidator, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Validator *_pObj;
public:
	inline wx_Validator() : wxValidator(), _pObj(nullptr) {}
	//virtual wxObject* Clone();
	virtual bool TransferFromWindow();
	virtual bool TransferToWindow();
	//virtual bool Validate(wxWindow* parent);
	~wx_Validator();
	inline void AssocWithGura(Object_wx_Validator *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Validator::~wx_Validator()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Validator::GuraObjectDeleted()
{
	_pObj = nullptr;
}

bool wx_Validator::TransferFromWindow()
{
	bool evaluatedFlag;
	Value rtn = _pObj->EvalMethod(*_pObj,
		Gura_UserSymbol(TransferFromWindow), ValueList::Empty, evaluatedFlag);
	if (_pObj->GetSignal().IsSignalled()) {
		SetLogError(_pObj->GetSignal());
		return false;
	}
	return rtn.GetBoolean();
}

bool wx_Validator::TransferToWindow()
{
	bool evaluatedFlag;
	Value rtn = _pObj->EvalMethod(*_pObj,
		Gura_UserSymbol(TransferToWindow), ValueList::Empty, evaluatedFlag);
	if (_pObj->GetSignal().IsSignalled()) {
		SetLogError(_pObj->GetSignal());
		return false;
	}
	return rtn.GetBoolean();
}

//bool wx_Validator::Validate(wxWindow* parent);
//{
//	
//}

//----------------------------------------------------------------------------
// Gura interfaces for wxValidator
//----------------------------------------------------------------------------
Gura_DeclareFunction(Validator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Validator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Validator)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Validator *pEntity = new wx_Validator();
	Object_wx_Validator *pObj = Object_wx_Validator::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Validator(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_Validator, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Validator, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObject *rtn = (wxObject *)pThis->GetEntity()->Clone();
	return ReturnValue(env, arg, Value(new Object_wx_Object(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Validator, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Validator, GetWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetWindow();
	return ReturnValue(env, arg, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_Validator, IsSilent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Validator, IsSilent)
{
	bool rtn = wxValidator::IsSilent();
	return ReturnValue(env, arg, Value(rtn));
}


Gura_DeclareClassMethod(wx_Validator, SuppressBellOnError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "suppress", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Validator, SuppressBellOnError)
{
	bool suppress = true;
	if (arg.IsValid(0)) suppress = arg.GetBoolean(0);
	wxValidator::SuppressBellOnError(suppress);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Validator, SetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_Validator, SetWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetWindow(window);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Validator, TransferToWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Validator, TransferToWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->TransferToWindow();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Validator, TransferToWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Validator, TransferToWindow_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->TransferToWindow();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Validator, Validate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Validator, Validate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Validator *pThis = Object_wx_Validator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Validate(parent);
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxValidator
//----------------------------------------------------------------------------
Object_wx_Validator::~Object_wx_Validator()
{
}

Object *Object_wx_Validator::Clone() const
{
	return nullptr;
}

String Object_wx_Validator::ToString(bool exprFlag)
{
	String rtn("<wx.Validator:");
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
// Class implementation for wxValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Validator)
{
	Gura_RealizeUserSymbol(Clone);
	Gura_RealizeUserSymbol(TransferFromWindow);
	Gura_RealizeUserSymbol(TransferToWindow);
	Gura_RealizeUserSymbol(Validate);
	Gura_AssignFunction(Validator);
	Gura_AssignMethod(wx_Validator, Clone);
	Gura_AssignMethod(wx_Validator, GetWindow);
	Gura_AssignMethod(wx_Validator, IsSilent);
	Gura_AssignMethod(wx_Validator, SuppressBellOnError);
	Gura_AssignMethod(wx_Validator, SetWindow);
	Gura_AssignMethod(wx_Validator, TransferToWindow);
	Gura_AssignMethod(wx_Validator, TransferToWindow_1);
	Gura_AssignMethod(wx_Validator, Validate);
}

Gura_ImplementDescendantCreator(wx_Validator)
{
	return new Object_wx_Validator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
