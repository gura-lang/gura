//----------------------------------------------------------------------------
// wxTextValidator
// extracted from valtext.tex
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
class wx_TextValidator: public wxTextValidator, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TextValidator *_pObj;
public:
	inline wx_TextValidator(const wxTextValidator& validator) : wxTextValidator(validator), _pObj(nullptr) {}
	//inline wx_TextValidator(long style, wxString* valPtr) : wxTextValidator(style, valPtr), _pObj(nullptr) {}
	//virtual wxValidator* Clone();
	//virtual bool TransferFromWindow();
	//virtual bool TransferToWindow();
	//virtual bool Validate(wxWindow* parent);
	~wx_TextValidator();
	inline void AssocWithGura(Object_wx_TextValidator *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextValidator::~wx_TextValidator()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TextValidator::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextValidator
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextValidator_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TextValidator));
	DeclareArg(env, "validator", VTYPE_wx_TextValidator, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextValidator_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxTextValidator *validator = Object_wx_TextValidator::GetObject(args, 0)->GetEntity();
	wx_TextValidator *pEntity = new wx_TextValidator(*validator);
	Object_wx_TextValidator *pObj = Object_wx_TextValidator::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextValidator(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(TextValidator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TextValidator));
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "valPtr", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextValidator)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	long style = wxFILTER_NONE;
	if (args.IsValid(0)) style = args.GetLong(0);
	wxString valPtr = nullptr;
	if (args.IsValid(1)) valPtr = wxString::FromUTF8(args.GetString(1));
	wx_TextValidator *pEntity = new wx_TextValidator(style, valPtr);
	Object_wx_TextValidator *pObj = Object_wx_TextValidator::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextValidator(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextValidator, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxValidator *rtn = (wxValidator *)pThis->GetEntity()->Clone();
	return ReturnValue(env, args, Value(new Object_wx_Validator(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_TextValidator, GetExcludes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextValidator, GetExcludes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArrayString rtn = pThis->GetEntity()->GetExcludes();
	return ReturnValue(env, args, ArrayStringToValue(env, rtn));
}

Gura_DeclareMethod(wx_TextValidator, GetIncludes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextValidator, GetIncludes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArrayString rtn = pThis->GetEntity()->GetIncludes();
	return ReturnValue(env, args, ArrayStringToValue(env, rtn));
}

Gura_DeclareMethod(wx_TextValidator, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextValidator, GetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetStyle();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextValidator, OnChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, OnChar)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnChar(*event);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, SetExcludes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "stringList", VTYPE_string, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_TextValidator, SetExcludes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> stringList(CreateArrayString(args.GetList(0)));
	pThis->GetEntity()->SetExcludes(*stringList);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, SetIncludes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "stringList", VTYPE_string, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_TextValidator, SetIncludes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> stringList(CreateArrayString(args.GetList(0)));
	pThis->GetEntity()->SetIncludes(*stringList);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextValidator, SetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long style = args.GetLong(0);
	pThis->GetEntity()->SetStyle(style);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextValidator, TransferFromWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextValidator, TransferFromWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->TransferFromWindow();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextValidator, TransferToWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextValidator, TransferToWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->TransferToWindow();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextValidator, Validate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextValidator, Validate)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextValidator *pThis = Object_wx_TextValidator::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Validate(parent);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTextValidator
//----------------------------------------------------------------------------
Object_wx_TextValidator::~Object_wx_TextValidator()
{
}

Object *Object_wx_TextValidator::Clone() const
{
	return nullptr;
}

String Object_wx_TextValidator::ToString(bool exprFlag)
{
	String rtn("<wx.TextValidator:");
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
// Class implementation for wxTextValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextValidator)
{
	Gura_RealizeUserSymbol(Clone);
	Gura_RealizeUserSymbol(TransferFromWindow);
	Gura_RealizeUserSymbol(TransferToWindow);
	Gura_RealizeUserSymbol(Validate);
	Gura_AssignFunction(TextValidator);
	Gura_AssignFunction(TextValidator_1);
	Gura_AssignMethod(wx_TextValidator, Clone);
	Gura_AssignMethod(wx_TextValidator, GetExcludes);
	Gura_AssignMethod(wx_TextValidator, GetIncludes);
	Gura_AssignMethod(wx_TextValidator, GetStyle);
	Gura_AssignMethod(wx_TextValidator, OnChar);
	Gura_AssignMethod(wx_TextValidator, SetExcludes);
	Gura_AssignMethod(wx_TextValidator, SetIncludes);
	Gura_AssignMethod(wx_TextValidator, SetStyle);
	Gura_AssignMethod(wx_TextValidator, TransferFromWindow);
	Gura_AssignMethod(wx_TextValidator, TransferToWindow);
	Gura_AssignMethod(wx_TextValidator, Validate);
}

Gura_ImplementDescendantCreator(wx_TextValidator)
{
	return new Object_wx_TextValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
