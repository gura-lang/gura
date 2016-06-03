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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxPageSetupDialogData, "wxPageSetupDialogData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxPageSetupDialogData)
{
	//wxPageSetupDialogData();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxPageSetupDialogData_1, "wxPageSetupDialogData_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxPageSetupDialogData_1)
{
	//int data = arg.GetNumber(0)
	//wxPageSetupDialogData();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxPageSetupDialogData_2, "wxPageSetupDialogData_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxPageSetupDialogData_2)
{
	//int printData = arg.GetNumber(0)
	//wxPageSetupDialogData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PageSetupDialogData, __EnableHelp, "EnableHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __EnableHelp)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnableHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __EnableMargins, "EnableMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __EnableMargins)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnableMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __EnableOrientation, "EnableOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __EnableOrientation)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnableOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __EnablePaper, "EnablePaper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __EnablePaper)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnablePaper();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __EnablePrinter, "EnablePrinter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __EnablePrinter)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->EnablePrinter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetDefaultInfo, "GetDefaultInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetDefaultInfo)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetDefaultMinMargins, "GetDefaultMinMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetDefaultMinMargins)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultMinMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetEnableHelp, "GetEnableHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetEnableHelp)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnableHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetEnableMargins, "GetEnableMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetEnableMargins)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnableMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetEnableOrientation, "GetEnableOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetEnableOrientation)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnableOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetEnablePaper, "GetEnablePaper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetEnablePaper)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnablePaper();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetEnablePrinter, "GetEnablePrinter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetEnablePrinter)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnablePrinter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetMarginBottomRight, "GetMarginBottomRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetMarginBottomRight)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMarginBottomRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetMarginTopLeft, "GetMarginTopLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetMarginTopLeft)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMarginTopLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetMinMarginBottomRight, "GetMinMarginBottomRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetMinMarginBottomRight)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinMarginBottomRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetMinMarginTopLeft, "GetMinMarginTopLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetMinMarginTopLeft)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinMarginTopLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetPaperId, "GetPaperId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetPaperId)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPaperId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetPaperSize, "GetPaperSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetPaperSize)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPaperSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetPrintData, "GetPrintData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetPrintData)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __GetPrintData_1, "GetPrintData_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __GetPrintData_1)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __IsOk)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __SetDefaultInfo, "SetDefaultInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __SetDefaultInfo)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __SetDefaultMinMargins, "SetDefaultMinMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __SetDefaultMinMargins)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultMinMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __SetMarginBottomRight, "SetMarginBottomRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __SetMarginBottomRight)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMarginBottomRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __SetMarginTopLeft, "SetMarginTopLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __SetMarginTopLeft)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMarginTopLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __SetMinMarginBottomRight, "SetMinMarginBottomRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __SetMinMarginBottomRight)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinMarginBottomRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __SetMinMarginTopLeft, "SetMinMarginTopLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __SetMinMarginTopLeft)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinMarginTopLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __SetPaperId, "SetPaperId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __SetPaperId)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetPaperId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __SetPaperSize, "SetPaperSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __SetPaperSize)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetPaperSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PageSetupDialogData, __SetPrintData, "SetPrintData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, __SetPrintData)
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
	// Constructor assignment
	Gura_AssignFunction(__wxPageSetupDialogData);
	Gura_AssignFunction(__wxPageSetupDialogData_1);
	Gura_AssignFunction(__wxPageSetupDialogData_2);
	// Method assignment
	Gura_AssignMethod(wx_PageSetupDialogData, __EnableHelp);
	Gura_AssignMethod(wx_PageSetupDialogData, __EnableMargins);
	Gura_AssignMethod(wx_PageSetupDialogData, __EnableOrientation);
	Gura_AssignMethod(wx_PageSetupDialogData, __EnablePaper);
	Gura_AssignMethod(wx_PageSetupDialogData, __EnablePrinter);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetDefaultInfo);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetDefaultMinMargins);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetEnableHelp);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetEnableMargins);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetEnableOrientation);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetEnablePaper);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetEnablePrinter);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetMarginBottomRight);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetMarginTopLeft);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetMinMarginBottomRight);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetMinMarginTopLeft);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetPaperId);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetPaperSize);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetPrintData);
	Gura_AssignMethod(wx_PageSetupDialogData, __GetPrintData_1);
	Gura_AssignMethod(wx_PageSetupDialogData, __IsOk);
	Gura_AssignMethod(wx_PageSetupDialogData, __SetDefaultInfo);
	Gura_AssignMethod(wx_PageSetupDialogData, __SetDefaultMinMargins);
	Gura_AssignMethod(wx_PageSetupDialogData, __SetMarginBottomRight);
	Gura_AssignMethod(wx_PageSetupDialogData, __SetMarginTopLeft);
	Gura_AssignMethod(wx_PageSetupDialogData, __SetMinMarginBottomRight);
	Gura_AssignMethod(wx_PageSetupDialogData, __SetMinMarginTopLeft);
	Gura_AssignMethod(wx_PageSetupDialogData, __SetPaperId);
	Gura_AssignMethod(wx_PageSetupDialogData, __SetPaperSize);
	Gura_AssignMethod(wx_PageSetupDialogData, __SetPrintData);
}

Gura_ImplementDescendantCreator(wx_PageSetupDialogData)
{
	return new Object_wx_PageSetupDialogData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
