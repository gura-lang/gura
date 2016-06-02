//----------------------------------------------------------------------------
// wxPageSetupDialogData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPageSetupDialogData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPageSetupDialogData
//----------------------------------------------------------------------------
Object_wx_PageSetupDialogData::~Object_wx_PageSetupDialogData()
{
}

Object *Object_wx_PageSetupDialogData::Clone() const
{
	return nullptr;
}

String Object_wx_PageSetupDialogData::ToString(bool exprFlag)
{
	String rtn("<wx.PageSetupDialogData:");
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
Gura_DeclareMethod(wx_PageSetupDialogData, wxPageSetupDialogData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, wxPageSetupDialogData)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPageSetupDialogData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, wxPageSetupDialogData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, wxPageSetupDialogData_1)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->wxPageSetupDialogData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, wxPageSetupDialogData_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, wxPageSetupDialogData_2)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int printData = arg.GetNumber(0)
	//pThis->GetEntity()->wxPageSetupDialogData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, EnableHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, EnableHelp)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnableHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, EnableMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, EnableMargins)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnableMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, EnableOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, EnableOrientation)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnableOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, EnablePaper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, EnablePaper)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnablePaper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, EnablePrinter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, EnablePrinter)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnablePrinter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetDefaultInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetDefaultInfo)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetDefaultMinMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetDefaultMinMargins)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultMinMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetEnableHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetEnableHelp)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnableHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetEnableMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetEnableMargins)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnableMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetEnableOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetEnableOrientation)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnableOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetEnablePaper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetEnablePaper)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnablePaper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetEnablePrinter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetEnablePrinter)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnablePrinter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetMarginBottomRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetMarginBottomRight)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMarginBottomRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetMarginTopLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetMarginTopLeft)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMarginTopLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetMinMarginBottomRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetMinMarginBottomRight)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinMarginBottomRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetMinMarginTopLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetMinMarginTopLeft)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinMarginTopLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetPaperId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetPaperId)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPaperId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetPaperSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetPaperSize)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPaperSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetPrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetPrintData)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetPrintData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetPrintData_1)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, IsOk)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetDefaultInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetDefaultInfo)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetDefaultMinMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetDefaultMinMargins)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultMinMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetMarginBottomRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetMarginBottomRight)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMarginBottomRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetMarginTopLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetMarginTopLeft)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMarginTopLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetMinMarginBottomRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetMinMarginBottomRight)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinMarginBottomRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetMinMarginTopLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetMinMarginTopLeft)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinMarginTopLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetPaperId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetPaperId)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetPaperId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetPaperSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetPaperSize)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetPaperSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetPrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetPrintData)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int printData = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPageSetupDialogData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PageSetupDialogData)
{
	Gura_AssignMethod(wx_PageSetupDialogData, wxPageSetupDialogData);
	Gura_AssignMethod(wx_PageSetupDialogData, wxPageSetupDialogData_1);
	Gura_AssignMethod(wx_PageSetupDialogData, wxPageSetupDialogData_2);
	Gura_AssignMethod(wx_PageSetupDialogData, EnableHelp);
	Gura_AssignMethod(wx_PageSetupDialogData, EnableMargins);
	Gura_AssignMethod(wx_PageSetupDialogData, EnableOrientation);
	Gura_AssignMethod(wx_PageSetupDialogData, EnablePaper);
	Gura_AssignMethod(wx_PageSetupDialogData, EnablePrinter);
	Gura_AssignMethod(wx_PageSetupDialogData, GetDefaultInfo);
	Gura_AssignMethod(wx_PageSetupDialogData, GetDefaultMinMargins);
	Gura_AssignMethod(wx_PageSetupDialogData, GetEnableHelp);
	Gura_AssignMethod(wx_PageSetupDialogData, GetEnableMargins);
	Gura_AssignMethod(wx_PageSetupDialogData, GetEnableOrientation);
	Gura_AssignMethod(wx_PageSetupDialogData, GetEnablePaper);
	Gura_AssignMethod(wx_PageSetupDialogData, GetEnablePrinter);
	Gura_AssignMethod(wx_PageSetupDialogData, GetMarginBottomRight);
	Gura_AssignMethod(wx_PageSetupDialogData, GetMarginTopLeft);
	Gura_AssignMethod(wx_PageSetupDialogData, GetMinMarginBottomRight);
	Gura_AssignMethod(wx_PageSetupDialogData, GetMinMarginTopLeft);
	Gura_AssignMethod(wx_PageSetupDialogData, GetPaperId);
	Gura_AssignMethod(wx_PageSetupDialogData, GetPaperSize);
	Gura_AssignMethod(wx_PageSetupDialogData, GetPrintData);
	Gura_AssignMethod(wx_PageSetupDialogData, GetPrintData_1);
	Gura_AssignMethod(wx_PageSetupDialogData, IsOk);
	Gura_AssignMethod(wx_PageSetupDialogData, SetDefaultInfo);
	Gura_AssignMethod(wx_PageSetupDialogData, SetDefaultMinMargins);
	Gura_AssignMethod(wx_PageSetupDialogData, SetMarginBottomRight);
	Gura_AssignMethod(wx_PageSetupDialogData, SetMarginTopLeft);
	Gura_AssignMethod(wx_PageSetupDialogData, SetMinMarginBottomRight);
	Gura_AssignMethod(wx_PageSetupDialogData, SetMinMarginTopLeft);
	Gura_AssignMethod(wx_PageSetupDialogData, SetPaperId);
	Gura_AssignMethod(wx_PageSetupDialogData, SetPaperSize);
	Gura_AssignMethod(wx_PageSetupDialogData, SetPrintData);
}

Gura_ImplementDescendantCreator(wx_PageSetupDialogData)
{
	return new Object_wx_PageSetupDialogData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
