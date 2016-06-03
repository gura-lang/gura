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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ProgressDialog, __wxProgressDialog, "wxProgressDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maximum", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ProgressDialog, __wxProgressDialog)
{
	Object_wx_ProgressDialog *pThis = Object_wx_ProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int maximum = arg.GetNumber(2)
	//int parent = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->wxProgressDialog();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxProgressDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ProgressDialog)
{
	Gura_AssignMethod(wx_ProgressDialog, __wxProgressDialog);
}

Gura_ImplementDescendantCreator(wx_ProgressDialog)
{
	return new Object_wx_ProgressDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
