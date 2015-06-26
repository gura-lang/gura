//----------------------------------------------------------------------------
// wxAutomationObject
// extracted from autoobj.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AutomationObject: public wxAutomationObject, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_AutomationObject *_pObj;
public:
	inline wx_AutomationObject() : _sig(nullptr), _pObj(nullptr) {}
	inline wx_AutomationObject(WXIDISPATCH* dispatchPtr) : wxAutomationObject(dispatchPtr), _sig(nullptr), _pObj(nullptr) {}
	~wx_AutomationObject();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_AutomationObject *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AutomationObject::~wx_AutomationObject()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_AutomationObject::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAutomationObject
//----------------------------------------------------------------------------
Gura_DeclareFunction(AutomationObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_AutomationObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AutomationObject)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_AutomationObject *pEntity = new wx_AutomationObject();
	Object_wx_AutomationObject *pObj = Object_wx_AutomationObject::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_AutomationObject(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_AutomationObject, CallMethod)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "method", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "noArgs", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "args[]", VTYPE_wx_Variant, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AutomationObject, CallMethod)
{
#if 0
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString method = wxString::FromUTF8(args.GetString(0));
	int noArgs = args.GetInt(1);
	wxVariant *args[] = Object_wx_Variant::GetObject(args, 2)->GetEntity();
	wxVariant rtn = pThis->GetEntity()->CallMethod(method, noArgs, *args[]);
	return ReturnValue(env, sig, args, Value(new Object_wx_Variant(new wxVariant(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AutomationObject, CallMethod_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "method", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AutomationObject, CallMethod_1)
{
#if 0
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString method = wxString::FromUTF8(args.GetString(0));
	wxVariant rtn = pThis->GetEntity()->CallMethod(method, );
	return ReturnValue(env, sig, args, Value(new Object_wx_Variant(new wxVariant(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AutomationObject, CreateInstance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "classId", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AutomationObject, CreateInstance)
{
#if 0
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString classId = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->CreateInstance(classId);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AutomationObject, GetDispatchPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AutomationObject, GetDispatchPtr)
{
#if 0
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AutomationObject, GetInstance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "classId", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AutomationObject, GetInstance)
{
#if 0
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString classId = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->GetInstance(classId);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AutomationObject, GetObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "obj", VTYPE_wx_AutomationObject, OCCUR_Once);
	DeclareArg(env, "property", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "noArgs", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "args[]", VTYPE_wx_Variant, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AutomationObject, GetObject)
{
#if 0
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxAutomationObject *obj = Object_wx_AutomationObject::GetObject(args, 0)->GetEntity();
	wxString property = wxString::FromUTF8(args.GetString(1));
	int noArgs = 0;
	if (args.IsValid(2)) noArgs = args.GetInt(2);
	wxVariant *args[] = (wxVariant *)(&nullptr);
	if (args.IsValid(3)) args[] = Object_wx_Variant::GetObject(args, 3)->GetEntity();
	bool rtn = pThis->GetEntity()->GetObject(*obj, property, noArgs, *args[]);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AutomationObject, GetProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "property", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "noArgs", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "args[]", VTYPE_wx_Variant, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AutomationObject, GetProperty)
{
#if 0
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString property = wxString::FromUTF8(args.GetString(0));
	int noArgs = args.GetInt(1);
	wxVariant *args[] = Object_wx_Variant::GetObject(args, 2)->GetEntity();
	wxVariant rtn = pThis->GetEntity()->GetProperty(property, noArgs, *args[]);
	return ReturnValue(env, sig, args, Value(new Object_wx_Variant(new wxVariant(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AutomationObject, GetProperty_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "property", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AutomationObject, GetProperty_1)
{
#if 0
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString property = wxString::FromUTF8(args.GetString(0));
	wxVariant rtn = pThis->GetEntity()->GetProperty(property, );
	return ReturnValue(env, sig, args, Value(new Object_wx_Variant(new wxVariant(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AutomationObject, Invoke)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "member", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "retValue", VTYPE_wx_Variant, OCCUR_Once);
	DeclareArg(env, "noArgs", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "args[]", VTYPE_wx_Variant, OCCUR_Once);
	DeclareArg(env, "ptrArgs[]", VTYPE_wx_Variant, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AutomationObject, Invoke)
{
#if 0
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString member = wxString::FromUTF8(args.GetString(0));
	int action = args.GetInt(1);
	wxVariant *retValue = Object_wx_Variant::GetObject(args, 2)->GetEntity();
	int noArgs = args.GetInt(3);
	wxVariant *args[] = Object_wx_Variant::GetObject(args, 4)->GetEntity();
	wxVariant *ptrArgs[] = (wxVariant *)(0);
	if (args.IsValid(5)) ptrArgs[] = Object_wx_Variant::GetObject(args, 5)->GetEntity();
	bool rtn = pThis->GetEntity()->Invoke(member, action, *retValue, noArgs, *args[], ptrArgs[]);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AutomationObject, PutProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "property", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "noArgs", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "args[]", VTYPE_wx_Variant, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AutomationObject, PutProperty)
{
#if 0
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString property = wxString::FromUTF8(args.GetString(0));
	int noArgs = args.GetInt(1);
	wxVariant *args[] = Object_wx_Variant::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->PutProperty(property, noArgs, *args[]);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AutomationObject, PutProperty_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "property", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AutomationObject, PutProperty_1)
{
#if 0
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString property = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->PutProperty(property, );
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AutomationObject, SetDispatchPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
#endif
}

Gura_ImplementMethod(wx_AutomationObject, SetDispatchPtr)
{
#if 0
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->SetDispatchPtr();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxAutomationObject
//----------------------------------------------------------------------------
Object_wx_AutomationObject::~Object_wx_AutomationObject()
{
}

Object *Object_wx_AutomationObject::Clone() const
{
	return nullptr;
}

String Object_wx_AutomationObject::ToString(bool exprFlag)
{
	String rtn("<wx.AutomationObject:");
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
// Class implementation for wxAutomationObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AutomationObject)
{
	Gura_AssignFunction(AutomationObject);
	Gura_AssignMethod(wx_AutomationObject, CallMethod);
	Gura_AssignMethod(wx_AutomationObject, CallMethod_1);
	Gura_AssignMethod(wx_AutomationObject, CreateInstance);
	Gura_AssignMethod(wx_AutomationObject, GetDispatchPtr);
	Gura_AssignMethod(wx_AutomationObject, GetInstance);
	Gura_AssignMethod(wx_AutomationObject, GetObject);
	Gura_AssignMethod(wx_AutomationObject, GetProperty);
	Gura_AssignMethod(wx_AutomationObject, GetProperty_1);
	Gura_AssignMethod(wx_AutomationObject, Invoke);
	Gura_AssignMethod(wx_AutomationObject, PutProperty);
	Gura_AssignMethod(wx_AutomationObject, PutProperty_1);
	Gura_AssignMethod(wx_AutomationObject, SetDispatchPtr);
}

Gura_ImplementDescendantCreator(wx_AutomationObject)
{
	return new Object_wx_AutomationObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
