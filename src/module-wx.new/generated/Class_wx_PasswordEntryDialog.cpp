//----------------------------------------------------------------------------
// wxPasswordEntryDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPasswordEntryDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPasswordEntryDialog
//----------------------------------------------------------------------------
Object_wx_PasswordEntryDialog::~Object_wx_PasswordEntryDialog()
{
}

Object *Object_wx_PasswordEntryDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PasswordEntryDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PasswordEntryDialog:");
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
Gura_DeclareFunctionAlias(__PasswordEntryDialog, "PasswordEntryDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultValue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PasswordEntryDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PasswordEntryDialog)
{
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& message = arg.GetNumber(1)
	//const wxString& caption = arg.GetNumber(2)
	//const wxString& defaultValue = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxPoint& pos = arg.GetNumber(5)
	//wxPasswordEntryDialog(parent, message, caption, defaultValue, style, pos);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPasswordEntryDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PasswordEntryDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__PasswordEntryDialog);
}

Gura_ImplementDescendantCreator(wx_PasswordEntryDialog)
{
	return new Object_wx_PasswordEntryDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
