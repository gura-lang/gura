//----------------------------------------------------------------------------
// wxRichTextStyleDefinition
// extracted from richtextstyledefinition.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextStyleDefinition: public wxRichTextStyleDefinition, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextStyleDefinition *_pObj;
public:
	//inline wx_RichTextStyleDefinition(const wxString& name) : wxRichTextStyleDefinition(name), _sig(NULL), _pObj(NULL) {}
	~wx_RichTextStyleDefinition();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextStyleDefinition *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextStyleDefinition::~wx_RichTextStyleDefinition()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextStyleDefinition::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleDefinition
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextStyleDefinition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleDefinition));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(RichTextStyleDefinition)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString name = wxEmptyString;
	if (args.IsValid(0)) name = wxString::FromUTF8(args.GetString(0));
	wx_RichTextStyleDefinition *pEntity = new wx_RichTextStyleDefinition(name);
	Object_wx_RichTextStyleDefinition *pObj = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextStyleDefinition(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetBaseStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetBaseStyle)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetBaseStyle();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetDescription)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetDescription)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetDescription();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetName)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetStyle)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextAttr &rtn = pThis->GetEntity()->GetStyle();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextAttr(new wxRichTextAttr(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetStyle_1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetStyle_1)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxRichTextAttr &rtn = pThis->GetEntity()->GetStyle();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextAttr(new wxRichTextAttr(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetStyleMergedWithBase)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetStyleMergedWithBase)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *sheet = Object_wx_RichTextStyleSheet::GetObject(args, 0)->GetEntity();
	wxRichTextAttr rtn = pThis->GetEntity()->GetStyleMergedWithBase(sheet);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextAttr(new wxRichTextAttr(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, SetBaseStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, SetBaseStyle)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetBaseStyle(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, SetDescription)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "descr", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, SetDescription)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString descr = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetDescription(descr);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, SetName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, SetName)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, SetStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_wx_RichTextAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, SetStyle)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetStyle(*style);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleDefinition
//----------------------------------------------------------------------------
Object_wx_RichTextStyleDefinition::~Object_wx_RichTextStyleDefinition()
{
}

Object *Object_wx_RichTextStyleDefinition::Clone() const
{
	return NULL;
}

String Object_wx_RichTextStyleDefinition::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RichTextStyleDefinition:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_RichTextStyleDefinition::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(RichTextStyleDefinition);
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleDefinition)
{
	Gura_AssignMethod(wx_RichTextStyleDefinition, GetBaseStyle);
	Gura_AssignMethod(wx_RichTextStyleDefinition, GetDescription);
	Gura_AssignMethod(wx_RichTextStyleDefinition, GetName);
	Gura_AssignMethod(wx_RichTextStyleDefinition, GetStyle);
	Gura_AssignMethod(wx_RichTextStyleDefinition, GetStyle_1);
	Gura_AssignMethod(wx_RichTextStyleDefinition, GetStyleMergedWithBase);
	Gura_AssignMethod(wx_RichTextStyleDefinition, SetBaseStyle);
	Gura_AssignMethod(wx_RichTextStyleDefinition, SetDescription);
	Gura_AssignMethod(wx_RichTextStyleDefinition, SetName);
	Gura_AssignMethod(wx_RichTextStyleDefinition, SetStyle);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleDefinition)
{
	return new Object_wx_RichTextStyleDefinition((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
