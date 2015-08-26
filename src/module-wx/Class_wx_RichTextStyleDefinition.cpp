//----------------------------------------------------------------------------
// wxRichTextStyleDefinition
// extracted from richtextstyledefinition.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextStyleDefinition: public wxRichTextStyleDefinition, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RichTextStyleDefinition *_pObj;
public:
	//inline wx_RichTextStyleDefinition(const wxString& name) : wxRichTextStyleDefinition(name), _pObj(nullptr) {}
	~wx_RichTextStyleDefinition();
	inline void AssocWithGura(Object_wx_RichTextStyleDefinition *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextStyleDefinition::~wx_RichTextStyleDefinition()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextStyleDefinition::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleDefinition
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleDefinition));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(RichTextStyleDefinition)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString name = wxEmptyString;
	if (args.IsValid(0)) name = wxString::FromUTF8(args.GetString(0));
	wx_RichTextStyleDefinition *pEntity = new wx_RichTextStyleDefinition(name);
	Object_wx_RichTextStyleDefinition *pObj = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextStyleDefinition(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetBaseStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetBaseStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetBaseStyle();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetDescription();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextAttr &rtn = pThis->GetEntity()->GetStyle();
	return ReturnValue(env, args, Value(new Object_wx_RichTextAttr(new wxRichTextAttr(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetStyle_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetStyle_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxRichTextAttr &rtn = pThis->GetEntity()->GetStyle();
	return ReturnValue(env, args, Value(new Object_wx_RichTextAttr(new wxRichTextAttr(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetStyleMergedWithBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetStyleMergedWithBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleSheet *sheet = Object_wx_RichTextStyleSheet::GetObject(args, 0)->GetEntity();
	wxRichTextAttr rtn = pThis->GetEntity()->GetStyleMergedWithBase(sheet);
	return ReturnValue(env, args, Value(new Object_wx_RichTextAttr(new wxRichTextAttr(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, SetBaseStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, SetBaseStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetBaseStyle(name);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, SetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "descr", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, SetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString descr = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetDescription(descr);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetName(name);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_wx_RichTextAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, SetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetStyle(*style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleDefinition
//----------------------------------------------------------------------------
Object_wx_RichTextStyleDefinition::~Object_wx_RichTextStyleDefinition()
{
}

Object *Object_wx_RichTextStyleDefinition::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStyleDefinition::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleDefinition:");
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
// Class implementation for wxRichTextStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleDefinition)
{
	Gura_AssignFunction(RichTextStyleDefinition);
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
	return new Object_wx_RichTextStyleDefinition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
