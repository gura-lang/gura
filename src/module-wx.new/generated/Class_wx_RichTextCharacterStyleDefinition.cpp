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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RichTextCharacterStyleDefinition, "RichTextCharacterStyleDefinition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextCharacterStyleDefinition));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextCharacterStyleDefinition)
{
	//const wxString& name = arg.GetNumber(0)
	//wxRichTextCharacterStyleDefinition(name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextCharacterStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextCharacterStyleDefinition)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextCharacterStyleDefinition);
}

Gura_ImplementDescendantCreator(wx_RichTextCharacterStyleDefinition)
{
	return new Object_wx_RichTextCharacterStyleDefinition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
