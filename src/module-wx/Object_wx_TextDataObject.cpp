//----------------------------------------------------------------------------
// wxTextDataObject
// extracted from txtdatob.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(GetTextLength);
Gura_DeclarePrivUserSymbol(GetText);
Gura_DeclarePrivUserSymbol(SetText);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TextDataObject: public wxTextDataObject, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TextDataObject *_pObj;
public:
	inline wx_TextDataObject(const wxString& text) : wxTextDataObject(text), _sig(NULL), _pObj(NULL) {}
	//virtual size_t GetTextLength();
	//virtual wxString GetText();
	//virtual void SetText(const wxString& strText);
	~wx_TextDataObject();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TextDataObject *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextDataObject::~wx_TextDataObject()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TextDataObject::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextDataObject
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextDataObject)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TextDataObject));
	DeclareArg(env, "text", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextDataObject)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString text = wxEmptyString;
	if (args.IsValid(0)) text = wxString::FromUTF8(args.GetString(0));
	wx_TextDataObject *pEntity = new wx_TextDataObject(text);
	Object_wx_TextDataObject *pObj = Object_wx_TextDataObject::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TextDataObject(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TextDataObject, GetTextLength)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextDataObject, GetTextLength)
{
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetTextLength();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextDataObject, GetText)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextDataObject, GetText)
{
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetText();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextDataObject, SetText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "strText", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextDataObject, SetText)
{
	Object_wx_TextDataObject *pThis = Object_wx_TextDataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString strText = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetText(strText);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTextDataObject
//----------------------------------------------------------------------------
Object_wx_TextDataObject::~Object_wx_TextDataObject()
{
}

Object *Object_wx_TextDataObject::Clone() const
{
	return NULL;
}

String Object_wx_TextDataObject::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TextDataObject:");
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
// Class implementation for wxTextDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextDataObject)
{
	Gura_RealizeUserSymbol(GetTextLength);
	Gura_RealizeUserSymbol(GetText);
	Gura_RealizeUserSymbol(SetText);
	Gura_AssignFunction(TextDataObject);
	Gura_AssignMethod(wx_TextDataObject, GetTextLength);
	Gura_AssignMethod(wx_TextDataObject, GetText);
	Gura_AssignMethod(wx_TextDataObject, SetText);
}

Gura_ImplementDescendantCreator(wx_TextDataObject)
{
	return new Object_wx_TextDataObject((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
