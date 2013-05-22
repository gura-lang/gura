//----------------------------------------------------------------------------
// wxXmlProperty
// extracted from xmlproperty.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_XmlProperty: public wxXmlProperty, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_XmlProperty *_pObj;
public:
	inline wx_XmlProperty() : wxXmlProperty(), _sig(NULL), _pObj(NULL) {}
	inline wx_XmlProperty(const wxString& name, const wxString& value, wxXmlProperty* next) : wxXmlProperty(name, value, next), _sig(NULL), _pObj(NULL) {}
	~wx_XmlProperty();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_XmlProperty *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_XmlProperty::~wx_XmlProperty()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_XmlProperty::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlProperty
//----------------------------------------------------------------------------
Gura_DeclareFunction(XmlPropertyEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_XmlProperty));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(XmlPropertyEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_XmlProperty *pEntity = new wx_XmlProperty();
	Object_wx_XmlProperty *pObj = Object_wx_XmlProperty::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_XmlProperty(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(XmlProperty)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_XmlProperty));
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "next", VTYPE_wx_XmlProperty, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(XmlProperty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxString value = wxString::FromUTF8(args.GetString(1));
	wxXmlProperty *next = (wxXmlProperty *)(NULL);
	if (args.IsValid(2)) next = Object_wx_XmlProperty::GetObject(args, 2)->GetEntity();
	wx_XmlProperty *pEntity = new wx_XmlProperty(name, value, next);
	Object_wx_XmlProperty *pObj = Object_wx_XmlProperty::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_XmlProperty(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_XmlProperty, GetName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlProperty, GetName)
{
	Object_wx_XmlProperty *pThis = Object_wx_XmlProperty::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_XmlProperty, GetNext)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlProperty, GetNext)
{
	Object_wx_XmlProperty *pThis = Object_wx_XmlProperty::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlProperty *rtn = (wxXmlProperty *)pThis->GetEntity()->GetNext();
	return ReturnValue(env, sig, args, Value(new Object_wx_XmlProperty(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlProperty, GetValue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlProperty, GetValue)
{
	Object_wx_XmlProperty *pThis = Object_wx_XmlProperty::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_XmlProperty, SetName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlProperty, SetName)
{
	Object_wx_XmlProperty *pThis = Object_wx_XmlProperty::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlProperty, SetNext)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "next", VTYPE_wx_XmlProperty, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlProperty, SetNext)
{
	Object_wx_XmlProperty *pThis = Object_wx_XmlProperty::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlProperty *next = Object_wx_XmlProperty::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetNext(next);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlProperty, SetValue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlProperty, SetValue)
{
	Object_wx_XmlProperty *pThis = Object_wx_XmlProperty::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetValue(value);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxXmlProperty
//----------------------------------------------------------------------------
Object_wx_XmlProperty::~Object_wx_XmlProperty()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_XmlProperty::Clone() const
{
	return NULL;
}

String Object_wx_XmlProperty::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.XmlProperty:");
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
	return new Object_wx_XmlProperty((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
