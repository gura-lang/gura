//----------------------------------------------------------------------------
// wxPageSetupDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPageSetupDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPageSetupDialog
//----------------------------------------------------------------------------
Object_wx_PageSetupDialog::~Object_wx_PageSetupDialog()
{
}

Object *Object_wx_PageSetupDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PageSetupDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PageSetupDialog:");
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
Gura_DeclareFunctionAlias(__PageSetupDialog, "PageSetupDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PageSetupDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PageSetupDialog)
{
	//int parent = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//wxPageSetupDialog();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PageSetupDialog, __GetPageSetupData, "GetPageSetupData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialog, __GetPageSetupData)
{
	Object_wx_PageSetupDialog *pThis = Object_wx_PageSetupDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageSetupData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialog, __ShowModal, "ShowModal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialog, __ShowModal)
{
	Object_wx_PageSetupDialog *pThis = Object_wx_PageSetupDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPageSetupDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PageSetupDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__PageSetupDialog);
	// Method assignment
	Gura_AssignMethod(wx_PageSetupDialog, __GetPageSetupData);
	Gura_AssignMethod(wx_PageSetupDialog, __ShowModal);
}

Gura_ImplementDescendantCreator(wx_PageSetupDialog)
{
	return new Object_wx_PageSetupDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
