//----------------------------------------------------------------------------
// wxXmlProperty
// extracted from xmlproperty.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_XmlProperty: public wxXmlProperty, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_XmlProperty *_pObj;
public:
	inline wx_XmlProperty() : wxXmlProperty(), _pObj(nullptr) {}
	inline wx_XmlProperty(const wxString& name, const wxString& value, wxXmlProperty* next) : wxXmlProperty(name, value, next), _pObj(nullptr) {}
	~wx_XmlProperty();
	inline void AssocWithGura(Object_wx_XmlProperty *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_XmlProperty::~wx_XmlProperty()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_XmlProperty::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlProperty
//----------------------------------------------------------------------------
Gura_DeclareFunction(XmlPropertyEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_XmlProperty));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(XmlPropertyEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_XmlProperty *pEntity = new wx_XmlProperty();
	Object_wx_XmlProperty *pObj = Object_wx_XmlProperty::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_XmlProperty(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(XmlProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_XmlProperty));
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "next", VTYPE_wx_XmlProperty, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(XmlProperty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxString value = wxString::FromUTF8(arg.GetString(1));
	wxXmlProperty *next = (wxXmlProperty *)(nullptr);
	if (arg.IsValid(2)) next = Object_wx_XmlProperty::GetObject(arg, 2)->GetEntity();
	wx_XmlProperty *pEntity = new wx_XmlProperty(name, value, next);
	Object_wx_XmlProperty *pObj = Object_wx_XmlProperty::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_XmlProperty(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_XmlProperty, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlProperty, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlProperty *pThis = Object_wx_XmlProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_XmlProperty, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlProperty, GetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlProperty *pThis = Object_wx_XmlProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlProperty *rtn = (wxXmlProperty *)pThis->GetEntity()->GetNext();
	return ReturnValue(env, arg, Value(new Object_wx_XmlProperty(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlProperty, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlProperty, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlProperty *pThis = Object_wx_XmlProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_XmlProperty, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlProperty, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlProperty *pThis = Object_wx_XmlProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetName(name);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlProperty, SetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "next", VTYPE_wx_XmlProperty, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlProperty, SetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlProperty *pThis = Object_wx_XmlProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlProperty *next = Object_wx_XmlProperty::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetNext(next);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlProperty, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlProperty, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlProperty *pThis = Object_wx_XmlProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString value = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetValue(value);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxXmlProperty
//----------------------------------------------------------------------------
Object_wx_XmlProperty::~Object_wx_XmlProperty()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_XmlProperty::Clone() const
{
	return nullptr;
}

String Object_wx_XmlProperty::ToString(bool exprFlag)
{
	String rtn("<wx.XmlProperty:");
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
// Class implementation for wxXmlProperty
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlProperty)
{
	Gura_AssignFunction(XmlPropertyEmpty);
	Gura_AssignFunction(XmlProperty);
	Gura_AssignMethod(wx_XmlProperty, GetName);
	Gura_AssignMethod(wx_XmlProperty, GetNext);
	Gura_AssignMethod(wx_XmlProperty, GetValue);
	Gura_AssignMethod(wx_XmlProperty, SetName);
	Gura_AssignMethod(wx_XmlProperty, SetNext);
	Gura_AssignMethod(wx_XmlProperty, SetValue);
}

Gura_ImplementDescendantCreator(wx_XmlProperty)
{
	return new Object_wx_XmlProperty((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
