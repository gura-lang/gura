//----------------------------------------------------------------------------
// wxPrintAbortDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintAbortDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPrintAbortDialog
//----------------------------------------------------------------------------
Object_wx_PrintAbortDialog::~Object_wx_PrintAbortDialog()
{
}

Object *Object_wx_PrintAbortDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PrintAbortDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PrintAbortDialog:");
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
Gura_DeclareMethodAlias(wx_PrintAbortDialog, __wxPrintAbortDialog, "wxPrintAbortDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "documentTitle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintAbortDialog, __wxPrintAbortDialog)
{
	Object_wx_PrintAbortDialog *pThis = Object_wx_PrintAbortDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int documentTitle = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxPrintAbortDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintAbortDialog, __SetProgress, "SetProgress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "currentPage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "totalPages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "currentCopy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "totalCopies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintAbortDialog, __SetProgress)
{
	Object_wx_PrintAbortDialog *pThis = Object_wx_PrintAbortDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int currentPage = arg.GetNumber(0)
	//int totalPages = arg.GetNumber(1)
	//int currentCopy = arg.GetNumber(2)
	//int totalCopies = arg.GetNumber(3)
	//pThis->GetEntity()->SetProgress();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPrintAbortDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintAbortDialog)
{
	Gura_AssignMethod(wx_PrintAbortDialog, __wxPrintAbortDialog);
	Gura_AssignMethod(wx_PrintAbortDialog, __SetProgress);
}

Gura_ImplementDescendantCreator(wx_PrintAbortDialog)
{
	return new Object_wx_PrintAbortDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
