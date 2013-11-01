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
	Gura::Signal _sig;
	Object_wx_URLDataObject *_pObj;
public:
	inline wx_URLDataObject(const wxString& url) : wxURLDataObject(url), _sig(NULL), _pObj(NULL) {}
	~wx_URLDataObject();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_URLDataObject *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_URLDataObject::~wx_URLDataObject()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_URLDataObject::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxURLDataObject
//----------------------------------------------------------------------------
Gura_DeclareFunction(URLDataObject)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_URLDataObject));
	DeclareArg(env, "url", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(URLDataObject)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString url = wxEmptyString;
	if (args.IsValid(0)) url = wxString::FromUTF8(args.GetString(0));
	wx_URLDataObject *pEntity = new wx_URLDataObject(url);
	Object_wx_URLDataObject *pObj = Object_wx_URLDataObject::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_URLDataObject(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_URLDataObject, GetURL)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URLDataObject, GetURL)
{
	Object_wx_URLDataObject *pThis = Object_wx_URLDataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetURL();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URLDataObject, SetURL)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_URLDataObject, SetURL)
{
	Object_wx_URLDataObject *pThis = Object_wx_URLDataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString url = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetURL(url);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxURLDataObject
//----------------------------------------------------------------------------
Object_wx_URLDataObject::~Object_wx_URLDataObject()
{
}

Object *Object_wx_URLDataObject::Clone() const
{
	return NULL;
}

String Object_wx_URLDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.URLDataObject:");
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
	return new Object_wx_URLDataObject((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
