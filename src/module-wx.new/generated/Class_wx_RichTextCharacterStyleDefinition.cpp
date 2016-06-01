//----------------------------------------------------------------------------
// wxRichTextCharacterStyleDefinition
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextCharacterStyleDefinition
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextCharacterStyleDefinition
//----------------------------------------------------------------------------
Object_wx_RichTextCharacterStyleDefinition::~Object_wx_RichTextCharacterStyleDefinition()
{
}

Object *Object_wx_RichTextCharacterStyleDefinition::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextCharacterStyleDefinition::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextCharacterStyleDefinition:");
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
Gura_DeclareMethod(wx_RichTextCharacterStyleDefinition, wxRichTextCharacterStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCharacterStyleDefinition, wxRichTextCharacterStyleDefinition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCharacterStyleDefinition *pThis = Object_wx_RichTextCharacterStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextCharacterStyleDefinition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCharacterStyleDefinition, ~wxRichTextCharacterStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCharacterStyleDefinition, ~wxRichTextCharacterStyleDefinition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCharacterStyleDefinition *pThis = Object_wx_RichTextCharacterStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxRichTextCharacterStyleDefinition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextCharacterStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextCharacterStyleDefinition)
{
	Gura_AssignMethod(wx_RichTextCharacterStyleDefinition, wxRichTextCharacterStyleDefinition);
	Gura_AssignMethod(wx_RichTextCharacterStyleDefinition, ~wxRichTextCharacterStyleDefinition);
}

Gura_ImplementDescendantCreator(wx_RichTextCharacterStyleDefinition)
{
	return new Object_wx_RichTextCharacterStyleDefinition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
