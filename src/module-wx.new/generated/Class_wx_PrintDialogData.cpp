//----------------------------------------------------------------------------
// wxPrintDialogData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintDialogData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPrintDialogData
//----------------------------------------------------------------------------
Object_wx_PrintDialogData::~Object_wx_PrintDialogData()
{
}

Object *Object_wx_PrintDialogData::Clone() const
{
	return nullptr;
}

String Object_wx_PrintDialogData::ToString(bool exprFlag)
{
	String rtn("<wx.PrintDialogData:");
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
Gura_DeclareMethodAlias(wx_PrintDialogData, __wxPrintDialogData, "wxPrintDialogData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, __wxPrintDialogData)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPrintDialogData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __wxPrintDialogData_1, "wxPrintDialogData_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dialogData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __wxPrintDialogData_1)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dialogData = arg.GetNumber(0)
	//pThis->GetEntity()->wxPrintDialogData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __wxPrintDialogData_2, "wxPrintDialogData_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __wxPrintDialogData_2)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int printData = arg.GetNumber(0)
	//pThis->GetEntity()->wxPrintDialogData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __EnableHelp, "EnableHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __EnableHelp)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnableHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __EnablePageNumbers, "EnablePageNumbers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __EnablePageNumbers)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnablePageNumbers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __EnablePrintToFile, "EnablePrintToFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __EnablePrintToFile)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnablePrintToFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __EnableSelection, "EnableSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __EnableSelection)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnableSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __GetAllPages, "GetAllPages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, __GetAllPages)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAllPages();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __GetCollate, "GetCollate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, __GetCollate)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCollate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __GetFromPage, "GetFromPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, __GetFromPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFromPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __GetMaxPage, "GetMaxPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, __GetMaxPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __GetMinPage, "GetMinPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, __GetMinPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __GetNoCopies, "GetNoCopies")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, __GetNoCopies)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNoCopies();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __GetPrintData, "GetPrintData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, __GetPrintData)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __GetPrintToFile, "GetPrintToFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, __GetPrintToFile)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintToFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, __GetSelection)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __GetToPage, "GetToPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, __GetToPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, __IsOk)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __SetCollate, "SetCollate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __SetCollate)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetCollate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __SetFromPage, "SetFromPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __SetFromPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetFromPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __SetMaxPage, "SetMaxPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __SetMaxPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __SetMinPage, "SetMinPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __SetMinPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __SetNoCopies, "SetNoCopies")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __SetNoCopies)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetNoCopies();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __SetPrintData, "SetPrintData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __SetPrintData)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int printData = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __SetPrintToFile, "SetPrintToFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __SetPrintToFile)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintToFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __SetSelection)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __SetSetupDialog, "SetSetupDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __SetSetupDialog)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetSetupDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialogData, __SetToPage, "SetToPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, __SetToPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetToPage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPrintDialogData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintDialogData)
{
	Gura_AssignMethod(wx_PrintDialogData, __wxPrintDialogData);
	Gura_AssignMethod(wx_PrintDialogData, __wxPrintDialogData_1);
	Gura_AssignMethod(wx_PrintDialogData, __wxPrintDialogData_2);
	Gura_AssignMethod(wx_PrintDialogData, __EnableHelp);
	Gura_AssignMethod(wx_PrintDialogData, __EnablePageNumbers);
	Gura_AssignMethod(wx_PrintDialogData, __EnablePrintToFile);
	Gura_AssignMethod(wx_PrintDialogData, __EnableSelection);
	Gura_AssignMethod(wx_PrintDialogData, __GetAllPages);
	Gura_AssignMethod(wx_PrintDialogData, __GetCollate);
	Gura_AssignMethod(wx_PrintDialogData, __GetFromPage);
	Gura_AssignMethod(wx_PrintDialogData, __GetMaxPage);
	Gura_AssignMethod(wx_PrintDialogData, __GetMinPage);
	Gura_AssignMethod(wx_PrintDialogData, __GetNoCopies);
	Gura_AssignMethod(wx_PrintDialogData, __GetPrintData);
	Gura_AssignMethod(wx_PrintDialogData, __GetPrintToFile);
	Gura_AssignMethod(wx_PrintDialogData, __GetSelection);
	Gura_AssignMethod(wx_PrintDialogData, __GetToPage);
	Gura_AssignMethod(wx_PrintDialogData, __IsOk);
	Gura_AssignMethod(wx_PrintDialogData, __SetCollate);
	Gura_AssignMethod(wx_PrintDialogData, __SetFromPage);
	Gura_AssignMethod(wx_PrintDialogData, __SetMaxPage);
	Gura_AssignMethod(wx_PrintDialogData, __SetMinPage);
	Gura_AssignMethod(wx_PrintDialogData, __SetNoCopies);
	Gura_AssignMethod(wx_PrintDialogData, __SetPrintData);
	Gura_AssignMethod(wx_PrintDialogData, __SetPrintToFile);
	Gura_AssignMethod(wx_PrintDialogData, __SetSelection);
	Gura_AssignMethod(wx_PrintDialogData, __SetSetupDialog);
	Gura_AssignMethod(wx_PrintDialogData, __SetToPage);
}

Gura_ImplementDescendantCreator(wx_PrintDialogData)
{
	return new Object_wx_PrintDialogData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
