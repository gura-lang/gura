//----------------------------------------------------------------------------
// wxContextHelpButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxContextHelpButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxContextHelpButton
//----------------------------------------------------------------------------
Object_wx_ContextHelpButton::~Object_wx_ContextHelpButton()
{
}

Object *Object_wx_ContextHelpButton::Clone() const
{
	return nullptr;
}

String Object_wx_ContextHelpButton::ToString(bool exprFlag)
{
	String rtn("<wx.ContextHelpButton:");
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
Gura_DeclareFunctionAlias(__ContextHelpButton, "ContextHelpButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ContextHelpButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ContextHelpButton)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//wxContextHelpButton();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxContextHelpButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ContextHelpButton)
{
	// Constructor assignment
	Gura_AssignFunction(__ContextHelpButton);
}

Gura_ImplementDescendantCreator(wx_ContextHelpButton)
{
	return new Object_wx_ContextHelpButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
