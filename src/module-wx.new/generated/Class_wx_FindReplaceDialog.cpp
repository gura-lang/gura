//----------------------------------------------------------------------------
// wxFindReplaceDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFindReplaceDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFindReplaceDialog
//----------------------------------------------------------------------------
Object_wx_FindReplaceDialog::~Object_wx_FindReplaceDialog()
{
}

Object *Object_wx_FindReplaceDialog::Clone() const
{
	return nullptr;
}

String Object_wx_FindReplaceDialog::ToString(bool exprFlag)
{
	String rtn("<wx.FindReplaceDialog:");
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
Gura_DeclareMethodAlias(wx_FindReplaceDialog, __wxFindReplaceDialog, "wxFindReplaceDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindReplaceDialog, __wxFindReplaceDialog)
{
	Object_wx_FindReplaceDialog *pThis = Object_wx_FindReplaceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxFindReplaceDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindReplaceDialog, __wxFindReplaceDialog_1, "wxFindReplaceDialog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindReplaceDialog, __wxFindReplaceDialog_1)
{
	Object_wx_FindReplaceDialog *pThis = Object_wx_FindReplaceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//pThis->GetEntity()->wxFindReplaceDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindReplaceDialog, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindReplaceDialog, __Create)
{
	Object_wx_FindReplaceDialog *pThis = Object_wx_FindReplaceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindReplaceDialog, __GetData, "GetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindReplaceDialog, __GetData)
{
	Object_wx_FindReplaceDialog *pThis = Object_wx_FindReplaceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFindReplaceDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FindReplaceDialog)
{
	Gura_AssignMethod(wx_FindReplaceDialog, __wxFindReplaceDialog);
	Gura_AssignMethod(wx_FindReplaceDialog, __wxFindReplaceDialog_1);
	Gura_AssignMethod(wx_FindReplaceDialog, __Create);
	Gura_AssignMethod(wx_FindReplaceDialog, __GetData);
}

Gura_ImplementDescendantCreator(wx_FindReplaceDialog)
{
	return new Object_wx_FindReplaceDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
