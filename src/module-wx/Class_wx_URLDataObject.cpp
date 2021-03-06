//----------------------------------------------------------------------------
// wxURLDataObject
// extracted from urldataob.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_URLDataObject: public wxURLDataObject, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_URLDataObject *_pObj;
public:
	inline wx_URLDataObject(const wxString& url) : wxURLDataObject(url), _pObj(nullptr) {}
	~wx_URLDataObject();
	inline void AssocWithGura(Object_wx_URLDataObject *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_URLDataObject::~wx_URLDataObject()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_URLDataObject::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxURLDataObject
//----------------------------------------------------------------------------
Gura_DeclareFunction(URLDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_URLDataObject));
	DeclareArg(env, "url", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(URLDataObject)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString url = wxEmptyString;
	if (arg.IsValid(0)) url = wxString::FromUTF8(arg.GetString(0));
	wx_URLDataObject *pEntity = new wx_URLDataObject(url);
	Object_wx_URLDataObject *pObj = Object_wx_URLDataObject::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_URLDataObject(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_URLDataObject, GetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URLDataObject, GetURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_URLDataObject *pThis = Object_wx_URLDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetURL();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URLDataObject, SetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_URLDataObject, SetURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_URLDataObject *pThis = Object_wx_URLDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString url = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetURL(url);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxURLDataObject
//----------------------------------------------------------------------------
Object_wx_URLDataObject::~Object_wx_URLDataObject()
{
}

Object *Object_wx_URLDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_URLDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.URLDataObject:");
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
// Class implementation for wxURLDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_URLDataObject)
{
	Gura_AssignFunction(URLDataObject);
	Gura_AssignMethod(wx_URLDataObject, GetURL);
	Gura_AssignMethod(wx_URLDataObject, SetURL);
}

Gura_ImplementDescendantCreator(wx_URLDataObject)
{
	return new Object_wx_URLDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
