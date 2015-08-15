//----------------------------------------------------------------------------
// wxRichTextListStyleDefinition
// extracted from richtextliststyledefinition.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextListStyleDefinition: public wxRichTextListStyleDefinition, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RichTextListStyleDefinition *_pObj;
public:
	inline wx_RichTextListStyleDefinition(const wxString& name) : wxRichTextListStyleDefinition(name), _pObj(nullptr) {}
	~wx_RichTextListStyleDefinition();
	inline void AssocWithGura(Object_wx_RichTextListStyleDefinition *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextListStyleDefinition::~wx_RichTextListStyleDefinition()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextListStyleDefinition::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextListStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextListStyleDefinition));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextListStyleDefinition)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxEmptyString;
	if (args.IsValid(0)) name = wxString::FromUTF8(args.GetString(0));
	wx_RichTextListStyleDefinition *pEntity = new wx_RichTextListStyleDefinition(name);
	Object_wx_RichTextListStyleDefinition *pObj = Object_wx_RichTextListStyleDefinition::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextListStyleDefinition(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, CombineWithParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "paraStyle", VTYPE_wx_RichTextAttr, OCCUR_Once);
	DeclareArg(env, "styleSheet", VTYPE_wx_RichTextStyleSheet, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, CombineWithParagraphStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int indent = args.GetInt(0);
	wxRichTextAttr *paraStyle = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
	wxRichTextStyleSheet *styleSheet = (wxRichTextStyleSheet *)(nullptr);
	if (args.IsValid(2)) styleSheet = Object_wx_RichTextStyleSheet::GetObject(args, 2)->GetEntity();
	wxRichTextAttr rtn = pThis->GetEntity()->CombineWithParagraphStyle(indent, *paraStyle, styleSheet);
	return ReturnValue(env, args, Value(new Object_wx_RichTextAttr(new wxRichTextAttr(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, FindLevelForIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, FindLevelForIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int indent = args.GetInt(0);
	int rtn = pThis->GetEntity()->FindLevelForIndent(indent);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, GetCombinedStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "styleSheet", VTYPE_wx_RichTextStyleSheet, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, GetCombinedStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int indent = args.GetInt(0);
	wxRichTextStyleSheet *styleSheet = (wxRichTextStyleSheet *)(nullptr);
	if (args.IsValid(1)) styleSheet = Object_wx_RichTextStyleSheet::GetObject(args, 1)->GetEntity();
	wxRichTextAttr rtn = pThis->GetEntity()->GetCombinedStyle(indent, styleSheet);
	return ReturnValue(env, args, Value(new Object_wx_RichTextAttr(new wxRichTextAttr(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, GetCombinedStyleLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "styleSheet", VTYPE_wx_RichTextStyleSheet, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, GetCombinedStyleLevel)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int level = args.GetInt(0);
	wxRichTextStyleSheet *styleSheet = (wxRichTextStyleSheet *)(nullptr);
	if (args.IsValid(1)) styleSheet = Object_wx_RichTextStyleSheet::GetObject(args, 1)->GetEntity();
	wxRichTextAttr rtn = pThis->GetEntity()->GetCombinedStyleLevel(level, styleSheet);
	return ReturnValue(env, args, Value(new Object_wx_RichTextAttr(new wxRichTextAttr(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, GetLevelAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, GetLevelAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int level = args.GetInt(0);
	wxRichTextAttr *rtn = (wxRichTextAttr *)pThis->GetEntity()->GetLevelAttributes(level);
	return ReturnValue(env, args, Value(new Object_wx_RichTextAttr(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, GetLevelCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, GetLevelCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetLevelCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, IsNumbered)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, IsNumbered)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int level = args.GetInt(0);
	int rtn = pThis->GetEntity()->IsNumbered(level);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, SetLevelAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "attr", VTYPE_wx_RichTextAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, SetLevelAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int level = args.GetInt(0);
	wxRichTextAttr *attr = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetLevelAttributes(level, *attr);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
Object_wx_RichTextListStyleDefinition::~Object_wx_RichTextListStyleDefinition()
{
}

Object *Object_wx_RichTextListStyleDefinition::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextListStyleDefinition::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextListStyleDefinition:");
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
// Class implementation for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextListStyleDefinition)
{
	Gura_AssignFunction(RichTextListStyleDefinition);
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
	return new Object_wx_RichTextListStyleDefinition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
