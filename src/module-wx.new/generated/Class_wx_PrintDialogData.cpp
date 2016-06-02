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
Gura_DeclareMethod(wx_PrintDialogData, wxPrintDialogData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, wxPrintDialogData)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPrintDialogData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, wxPrintDialogData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dialogData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, wxPrintDialogData_1)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dialogData = arg.GetNumber(0)
	//pThis->GetEntity()->wxPrintDialogData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, wxPrintDialogData_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, wxPrintDialogData_2)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int printData = arg.GetNumber(0)
	//pThis->GetEntity()->wxPrintDialogData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, EnableHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, EnableHelp)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnableHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, EnablePageNumbers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, EnablePageNumbers)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnablePageNumbers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, EnablePrintToFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, EnablePrintToFile)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnablePrintToFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, EnableSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, EnableSelection)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnableSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, GetAllPages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, GetAllPages)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAllPages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, GetCollate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, GetCollate)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCollate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, GetFromPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, GetFromPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFromPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, GetMaxPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, GetMaxPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, GetMinPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, GetMinPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, GetNoCopies)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, GetNoCopies)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNoCopies();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, GetPrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, GetPrintData)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, GetPrintToFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, GetPrintToFile)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintToFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, GetSelection)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, GetToPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, GetToPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialogData, IsOk)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, SetCollate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetCollate)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetCollate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, SetFromPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetFromPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetFromPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, SetMaxPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetMaxPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, SetMinPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetMinPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, SetNoCopies)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetNoCopies)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetNoCopies();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, SetPrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetPrintData)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int printData = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, SetPrintToFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetPrintToFile)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintToFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetSelection)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, SetSetupDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetSetupDialog)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetSetupDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialogData, SetToPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetToPage)
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
	Gura_AssignMethod(wx_PrintDialogData, wxPrintDialogData);
	Gura_AssignMethod(wx_PrintDialogData, wxPrintDialogData_1);
	Gura_AssignMethod(wx_PrintDialogData, wxPrintDialogData_2);
	Gura_AssignMethod(wx_PrintDialogData, EnableHelp);
	Gura_AssignMethod(wx_PrintDialogData, EnablePageNumbers);
	Gura_AssignMethod(wx_PrintDialogData, EnablePrintToFile);
	Gura_AssignMethod(wx_PrintDialogData, EnableSelection);
	Gura_AssignMethod(wx_PrintDialogData, GetAllPages);
	Gura_AssignMethod(wx_PrintDialogData, GetCollate);
	Gura_AssignMethod(wx_PrintDialogData, GetFromPage);
	Gura_AssignMethod(wx_PrintDialogData, GetMaxPage);
	Gura_AssignMethod(wx_PrintDialogData, GetMinPage);
	Gura_AssignMethod(wx_PrintDialogData, GetNoCopies);
	Gura_AssignMethod(wx_PrintDialogData, GetPrintData);
	Gura_AssignMethod(wx_PrintDialogData, GetPrintToFile);
	Gura_AssignMethod(wx_PrintDialogData, GetSelection);
	Gura_AssignMethod(wx_PrintDialogData, GetToPage);
	Gura_AssignMethod(wx_PrintDialogData, IsOk);
	Gura_AssignMethod(wx_PrintDialogData, SetCollate);
	Gura_AssignMethod(wx_PrintDialogData, SetFromPage);
	Gura_AssignMethod(wx_PrintDialogData, SetMaxPage);
	Gura_AssignMethod(wx_PrintDialogData, SetMinPage);
	Gura_AssignMethod(wx_PrintDialogData, SetNoCopies);
	Gura_AssignMethod(wx_PrintDialogData, SetPrintData);
	Gura_AssignMethod(wx_PrintDialogData, SetPrintToFile);
	Gura_AssignMethod(wx_PrintDialogData, SetSelection);
	Gura_AssignMethod(wx_PrintDialogData, SetSetupDialog);
	Gura_AssignMethod(wx_PrintDialogData, SetToPage);
}

Gura_ImplementDescendantCreator(wx_PrintDialogData)
{
	return new Object_wx_PrintDialogData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
