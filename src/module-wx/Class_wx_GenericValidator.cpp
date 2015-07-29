//----------------------------------------------------------------------------
// wxGenericValidator
// extracted from valgen.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(Clone);
Gura_DeclarePrivUserSymbol(TransferFromWindow);
Gura_DeclarePrivUserSymbol(TransferToWindow);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GenericValidator: public wxGenericValidator, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_GenericValidator *_pObj;
public:
	inline wx_GenericValidator(const wxGenericValidator& validator) : wxGenericValidator(validator), _pObj(nullptr) {}
	//inline wx_GenericValidator(bool* valPtr) : wxGenericValidator(valPtr), _pObj(nullptr) {}
	//inline wx_GenericValidator(wxString* valPtr) : wxGenericValidator(valPtr), _pObj(nullptr) {}
	//inline wx_GenericValidator(int* valPtr) : wxGenericValidator(valPtr), _pObj(nullptr) {}
	//inline wx_GenericValidator(wxArrayInt* valPtr) : wxGenericValidator(valPtr), _pObj(nullptr) {}
	//virtual wxValidator* Clone();
	//virtual bool TransferFromWindow();
	//virtual bool TransferToWindow();
	~wx_GenericValidator();
	inline void AssocWithGura(Object_wx_GenericValidator *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GenericValidator::~wx_GenericValidator()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GenericValidator::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGenericValidator
//----------------------------------------------------------------------------
Gura_DeclareFunction(GenericValidator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GenericValidator));
	DeclareArg(env, "validator", VTYPE_wx_GenericValidator, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GenericValidator)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxGenericValidator *validator = Object_wx_GenericValidator::GetObject(args, 0)->GetEntity();
	wx_GenericValidator *pEntity = new wx_GenericValidator(*validator);
	Object_wx_GenericValidator *pObj = Object_wx_GenericValidator::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GenericValidator(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(GenericValidator_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_GenericValidator));
	DeclareArg(env, "valPtr", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(GenericValidator_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	bool valPtr = args.GetBoolean(0);
	wx_GenericValidator *pEntity = new wx_GenericValidator(valPtr);
	Object_wx_GenericValidator *pObj = Object_wx_GenericValidator::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GenericValidator(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GenericValidator_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_GenericValidator));
	DeclareArg(env, "valPtr", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(GenericValidator_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString valPtr = wxString::FromUTF8(args.GetString(0));
	wx_GenericValidator *pEntity = new wx_GenericValidator(valPtr);
	Object_wx_GenericValidator *pObj = Object_wx_GenericValidator::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GenericValidator(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GenericValidator_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_GenericValidator));
	DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(GenericValidator_3)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int valPtr = args.GetInt(0);
	wx_GenericValidator *pEntity = new wx_GenericValidator(valPtr);
	Object_wx_GenericValidator *pObj = Object_wx_GenericValidator::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GenericValidator(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GenericValidator_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_GenericValidator));
	DeclareArg(env, "valPtr", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(GenericValidator_4)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	std::unique_ptr<wxArrayInt> valPtr(CreateArrayInt(args.GetList(0)));
	wx_GenericValidator *pEntity = new wx_GenericValidator(*valPtr);
	Object_wx_GenericValidator *pObj = Object_wx_GenericValidator::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GenericValidator(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_GenericValidator, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GenericValidator, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxValidator *rtn = (wxValidator *)pThis->GetEntity()->Clone();
	return ReturnValue(env, args, Value(new Object_wx_Validator(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GenericValidator, TransferFromWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GenericValidator, TransferFromWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->TransferFromWindow();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GenericValidator, TransferToWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GenericValidator, TransferToWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_GenericValidator *pThis = Object_wx_GenericValidator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->TransferToWindow();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxGenericValidator
//----------------------------------------------------------------------------
Object_wx_GenericValidator::~Object_wx_GenericValidator()
{
}

Object *Object_wx_GenericValidator::Clone() const
{
	return nullptr;
}

String Object_wx_GenericValidator::ToString(bool exprFlag)
{
	String rtn("<wx.GenericValidator:");
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
// Class implementation for wxGenericValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GenericValidator)
{
	Gura_RealizeUserSymbol(Clone);
	Gura_RealizeUserSymbol(TransferFromWindow);
	Gura_RealizeUserSymbol(TransferToWindow);
	Gura_AssignFunction(GenericValidator);
	Gura_AssignFunction(GenericValidator_1);
	Gura_AssignFunction(GenericValidator_2);
	Gura_AssignFunction(GenericValidator_3);
	Gura_AssignFunction(GenericValidator_4);
	Gura_AssignMethod(wx_GenericValidator, Clone);
	Gura_AssignMethod(wx_GenericValidator, TransferFromWindow);
	Gura_AssignMethod(wx_GenericValidator, TransferToWindow);
}

Gura_ImplementDescendantCreator(wx_GenericValidator)
{
	return new Object_wx_GenericValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
