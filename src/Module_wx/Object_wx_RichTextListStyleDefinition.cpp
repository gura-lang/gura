//----------------------------------------------------------------------------
// wxRichTextListStyleDefinition
// extracted from richtextliststyledefinition.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextListStyleDefinition: public wxRichTextListStyleDefinition, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextListStyleDefinition *_pObj;
public:
	inline wx_RichTextListStyleDefinition(const wxString& name) : wxRichTextListStyleDefinition(name), _sig(NULL), _pObj(NULL) {}
	~wx_RichTextListStyleDefinition();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextListStyleDefinition *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextListStyleDefinition::~wx_RichTextListStyleDefinition()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextListStyleDefinition::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextListStyleDefinition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextListStyleDefinition));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextListStyleDefinition)
{
	wxString name = wxEmptyString;
	if (args.IsValid(0)) name = wxString::FromUTF8(args.GetString(0));
	wx_RichTextListStyleDefinition *pEntity = new wx_RichTextListStyleDefinition(name);
	Object_wx_RichTextListStyleDefinition *pObj = Object_wx_RichTextListStyleDefinition::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextListStyleDefinition(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, CombineWithParagraphStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "paraStyle", VTYPE_wx_RichTextAttr, OCCUR_Once);
	DeclareArg(env, "styleSheet", VTYPE_wx_RichTextStyleSheet, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, CombineWithParagraphStyle)
{
	Object_wx_RichTextListStyleDefinition *pSelf = Object_wx_RichTextListStyleDefinition::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int indent = args.GetInt(0);
	wxRichTextAttr *paraStyle = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
	wxRichTextStyleSheet *styleSheet = (wxRichTextStyleSheet *)(NULL);
	if (args.IsValid(2)) styleSheet = Object_wx_RichTextStyleSheet::GetObject(args, 2)->GetEntity();
	wxRichTextAttr rtn = pSelf->GetEntity()->CombineWithParagraphStyle(indent, *paraStyle, styleSheet);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextAttr(new wxRichTextAttr(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, FindLevelForIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, FindLevelForIndent)
{
	Object_wx_RichTextListStyleDefinition *pSelf = Object_wx_RichTextListStyleDefinition::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int indent = args.GetInt(0);
	int rtn = pSelf->GetEntity()->FindLevelForIndent(indent);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, GetCombinedStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "styleSheet", VTYPE_wx_RichTextStyleSheet, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, GetCombinedStyle)
{
	Object_wx_RichTextListStyleDefinition *pSelf = Object_wx_RichTextListStyleDefinition::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int indent = args.GetInt(0);
	wxRichTextStyleSheet *styleSheet = (wxRichTextStyleSheet *)(NULL);
	if (args.IsValid(1)) styleSheet = Object_wx_RichTextStyleSheet::GetObject(args, 1)->GetEntity();
	wxRichTextAttr rtn = pSelf->GetEntity()->GetCombinedStyle(indent, styleSheet);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextAttr(new wxRichTextAttr(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, GetCombinedStyleLevel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "styleSheet", VTYPE_wx_RichTextStyleSheet, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, GetCombinedStyleLevel)
{
#if 0
	Object_wx_RichTextListStyleDefinition *pSelf = Object_wx_RichTextListStyleDefinition::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int level = args.GetInt(0);
	wxRichTextStyleSheet *styleSheet = (wxRichTextStyleSheet *)(NULL);
	if (args.IsValid(1)) styleSheet = Object_wx_RichTextStyleSheet::GetObject(args, 1)->GetEntity();
	wxRichTextAttr rtn = pSelf->GetEntity()->GetCombinedStyleLevel(level, styleSheet);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextAttr(new wxRichTextAttr(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, GetLevelAttributes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, GetLevelAttributes)
{
	Object_wx_RichTextListStyleDefinition *pSelf = Object_wx_RichTextListStyleDefinition::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int level = args.GetInt(0);
	wxRichTextAttr *rtn = (wxRichTextAttr *)pSelf->GetEntity()->GetLevelAttributes(level);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextAttr(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, GetLevelCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, GetLevelCount)
{
	Object_wx_RichTextListStyleDefinition *pSelf = Object_wx_RichTextListStyleDefinition::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetLevelCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, IsNumbered)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, IsNumbered)
{
	Object_wx_RichTextListStyleDefinition *pSelf = Object_wx_RichTextListStyleDefinition::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int level = args.GetInt(0);
	int rtn = pSelf->GetEntity()->IsNumbered(level);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, SetLevelAttributes)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "attr", VTYPE_wx_RichTextAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, SetLevelAttributes)
{
	Object_wx_RichTextListStyleDefinition *pSelf = Object_wx_RichTextListStyleDefinition::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int level = args.GetInt(0);
	wxRichTextAttr *attr = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
	pSelf->GetEntity()->SetLevelAttributes(level, *attr);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
Object_wx_RichTextListStyleDefinition::~Object_wx_RichTextListStyleDefinition()
{
}

Object *Object_wx_RichTextListStyleDefinition::Clone() const
{
	return NULL;
}

String Object_wx_RichTextListStyleDefinition::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RichTextListStyleDefinition:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_RichTextListStyleDefinition::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(RichTextListStyleDefinition);
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextListStyleDefinition)
{
	Gura_AssignMethod(wx_RichTextListStyleDefinition, CombineWithParagraphStyle);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, FindLevelForIndent);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, GetCombinedStyle);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, GetCombinedStyleLevel);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, GetLevelAttributes);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, GetLevelCount);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, IsNumbered);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, SetLevelAttributes);
}

Gura_ImplementDescendantCreator(wx_RichTextListStyleDefinition)
{
	return new Object_wx_RichTextListStyleDefinition((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
