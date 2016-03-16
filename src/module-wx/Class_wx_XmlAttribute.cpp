//----------------------------------------------------------------------------
// wxXmlAttribute
// extracted from xmlproperty.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_XmlAttribute: public wxXmlAttribute, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_XmlAttribute *_pObj;
public:
	inline wx_XmlAttribute() : wxXmlAttribute(), _pObj(nullptr) {}
	inline wx_XmlAttribute(const wxString& name, const wxString& value, wxXmlAttribute* next) : wxXmlAttribute(name, value, next), _pObj(nullptr) {}
	~wx_XmlAttribute();
	inline void AssocWithGura(Object_wx_XmlAttribute *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_XmlAttribute::~wx_XmlAttribute()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_XmlAttribute::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlAttribute
//----------------------------------------------------------------------------
Gura_DeclareFunction(XmlAttributeEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_XmlAttribute));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(XmlAttributeEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_XmlAttribute *pEntity = new wx_XmlAttribute();
	Object_wx_XmlAttribute *pObj = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_XmlAttribute(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(XmlAttribute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_XmlAttribute));
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "next", VTYPE_wx_XmlAttribute, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(XmlAttribute)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxString value = wxString::FromUTF8(arg.GetString(1));
	wxXmlAttribute *next = (wxXmlAttribute *)(nullptr);
	if (arg.IsValid(2)) next = Object_wx_XmlAttribute::GetObject(arg, 2)->GetEntity();
	wx_XmlAttribute *pEntity = new wx_XmlAttribute(name, value, next);
	Object_wx_XmlAttribute *pObj = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_XmlAttribute(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_XmlAttribute, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlAttribute, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_XmlAttribute, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlAttribute, GetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlAttribute *rtn = (wxXmlAttribute *)pThis->GetEntity()->GetNext();
	return ReturnValue(env, arg, Value(new Object_wx_XmlAttribute(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlAttribute, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlAttribute, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_XmlAttribute, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlAttribute, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetName(name);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlAttribute, SetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "next", VTYPE_wx_XmlAttribute, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlAttribute, SetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlAttribute *next = Object_wx_XmlAttribute::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetNext(next);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlAttribute, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlAttribute, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString value = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetValue(value);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxXmlAttribute
//----------------------------------------------------------------------------
Object_wx_XmlAttribute::~Object_wx_XmlAttribute()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_XmlAttribute::Clone() const
{
	return nullptr;
}

String Object_wx_XmlAttribute::ToString(bool exprFlag)
{
	String rtn("<wx.XmlAttribute:");
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
// Class implementation for wxXmlAttribute
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlAttribute)
{
	Gura_AssignFunction(XmlAttributeEmpty);
	Gura_AssignFunction(XmlAttribute);
	Gura_AssignMethod(wx_XmlAttribute, GetName);
	Gura_AssignMethod(wx_XmlAttribute, GetNext);
	Gura_AssignMethod(wx_XmlAttribute, GetValue);
	Gura_AssignMethod(wx_XmlAttribute, SetName);
	Gura_AssignMethod(wx_XmlAttribute, SetNext);
	Gura_AssignMethod(wx_XmlAttribute, SetValue);
}

Gura_ImplementDescendantCreator(wx_XmlAttribute)
{
	return new Object_wx_XmlAttribute((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
