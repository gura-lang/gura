//----------------------------------------------------------------------------
// wxProgressDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxProgressDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxProgressDialog
//----------------------------------------------------------------------------
Object_wx_ProgressDialog::~Object_wx_ProgressDialog()
{
}

Object *Object_wx_ProgressDialog::Clone() const
{
	return nullptr;
}

String Object_wx_ProgressDialog::ToString(bool exprFlag)
{
	String rtn("<wx.ProgressDialog:");
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
Gura_DeclareFunctionAlias(__wxProgressDialog, "wxProgressDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maximum", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ProgressDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxProgressDialog)
{
	//int title = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int maximum = arg.GetNumber(2)
	//int parent = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//wxProgressDialog();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxProgressDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ProgressDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__wxProgressDialog);
}

Gura_ImplementDescendantCreator(wx_ProgressDialog)
{
	return new Object_wx_ProgressDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
