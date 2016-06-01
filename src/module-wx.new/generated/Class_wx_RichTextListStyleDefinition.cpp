//----------------------------------------------------------------------------
// wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------

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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextListStyleDefinition, wxRichTextListStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, wxRichTextListStyleDefinition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextListStyleDefinition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, ~wxRichTextListStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, ~wxRichTextListStyleDefinition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxRichTextListStyleDefinition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, CombineWithParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paraStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, CombineWithParagraphStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//int paraStyle = arg.GetNumber(1)
	//int styleSheet = arg.GetNumber(2)
	//pThis->GetEntity()->CombineWithParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, FindLevelForIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, FindLevelForIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//pThis->GetEntity()->FindLevelForIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, GetCombinedStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, GetCombinedStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//int styleSheet = arg.GetNumber(1)
	//pThis->GetEntity()->GetCombinedStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, GetCombinedStyleForLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, GetCombinedStyleForLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//int styleSheet = arg.GetNumber(1)
	//pThis->GetEntity()->GetCombinedStyleForLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, GetLevelAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, GetLevelAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//pThis->GetEntity()->GetLevelAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, GetLevelCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, GetLevelCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLevelCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, IsNumbered)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, IsNumbered)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//pThis->GetEntity()->IsNumbered();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextListStyleDefinition, SetLevelAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, SetLevelAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//pThis->GetEntity()->SetLevelAttributes();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextListStyleDefinition)
{
	Gura_AssignMethod(wx_RichTextListStyleDefinition, wxRichTextListStyleDefinition);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, ~wxRichTextListStyleDefinition);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, CombineWithParagraphStyle);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, FindLevelForIndent);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, GetCombinedStyle);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, GetCombinedStyleForLevel);
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
