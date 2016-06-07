//----------------------------------------------------------------------------
// wxPrintData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPrintData
//----------------------------------------------------------------------------
Object_wx_PrintData::~Object_wx_PrintData()
{
}

Object *Object_wx_PrintData::Clone() const
{
	return nullptr;
}

String Object_wx_PrintData::ToString(bool exprFlag)
{
	String rtn("<wx.PrintData:");
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
Gura_DeclareFunctionAlias(__PrintData, "PrintData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PrintData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PrintData)
{
	//wxPrintData();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__PrintData_1, "PrintData_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PrintData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PrintData_1)
{
	//const wxPrintData& data = arg.GetNumber(0)
	//wxPrintData(data);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PrintData, __GetBin, "GetBin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, __GetBin)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPrintBin _rtn = pThis->GetEntity()->GetBin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __GetCollate, "GetCollate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, __GetCollate)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetCollate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __GetColour, "GetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, __GetColour)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __GetDuplex, "GetDuplex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, __GetDuplex)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDuplexMode _rtn = pThis->GetEntity()->GetDuplex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __GetNoCopies, "GetNoCopies")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, __GetNoCopies)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetNoCopies();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __GetOrientation, "GetOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, __GetOrientation)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPrintOrientation _rtn = pThis->GetEntity()->GetOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __GetPaperId, "GetPaperId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, __GetPaperId)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPaperSize _rtn = pThis->GetEntity()->GetPaperId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __GetPrinterName, "GetPrinterName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, __GetPrinterName)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetPrinterName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __GetQuality, "GetQuality")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, __GetQuality)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPrintQuality _rtn = pThis->GetEntity()->GetQuality();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, __IsOk)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __SetBin, "SetBin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, __SetBin)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPrintBin flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetBin(flag);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __SetCollate, "SetCollate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, __SetCollate)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetCollate(flag);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, __SetColour)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour(flag);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __SetDuplex, "SetDuplex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, __SetDuplex)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDuplexMode mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetDuplex(mode);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __SetNoCopies, "SetNoCopies")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, __SetNoCopies)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetNoCopies(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __SetOrientation, "SetOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, __SetOrientation)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPrintOrientation orientation = arg.GetNumber(0)
	//pThis->GetEntity()->SetOrientation(orientation);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __SetPaperId, "SetPaperId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paperId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, __SetPaperId)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPaperSize paperId = arg.GetNumber(0)
	//pThis->GetEntity()->SetPaperId(paperId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __SetPaperSize, "SetPaperSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, __SetPaperSize)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& size = arg.GetNumber(0)
	//pThis->GetEntity()->SetPaperSize(size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __SetPrinterName, "SetPrinterName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printerName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, __SetPrinterName)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& printerName = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrinterName(printerName);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __SetQuality, "SetQuality")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "quality", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, __SetQuality)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPrintQuality quality = arg.GetNumber(0)
	//pThis->GetEntity()->SetQuality(quality);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __GetFilename, "GetFilename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, __GetFilename)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetFilename();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __SetFilename, "SetFilename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, __SetFilename)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilename(filename);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __GetPrintMode, "GetPrintMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, __GetPrintMode)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPrintMode _rtn = pThis->GetEntity()->GetPrintMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintData, __SetPrintMode, "SetPrintMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, __SetPrintMode)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPrintMode printMode = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintMode(printMode);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPrintData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintData)
{
	// Constructor assignment
	Gura_AssignFunction(__PrintData);
	Gura_AssignFunction(__PrintData_1);
	// Method assignment
	Gura_AssignMethod(wx_PrintData, __GetBin);
	Gura_AssignMethod(wx_PrintData, __GetCollate);
	Gura_AssignMethod(wx_PrintData, __GetColour);
	Gura_AssignMethod(wx_PrintData, __GetDuplex);
	Gura_AssignMethod(wx_PrintData, __GetNoCopies);
	Gura_AssignMethod(wx_PrintData, __GetOrientation);
	Gura_AssignMethod(wx_PrintData, __GetPaperId);
	Gura_AssignMethod(wx_PrintData, __GetPrinterName);
	Gura_AssignMethod(wx_PrintData, __GetQuality);
	Gura_AssignMethod(wx_PrintData, __IsOk);
	Gura_AssignMethod(wx_PrintData, __SetBin);
	Gura_AssignMethod(wx_PrintData, __SetCollate);
	Gura_AssignMethod(wx_PrintData, __SetColour);
	Gura_AssignMethod(wx_PrintData, __SetDuplex);
	Gura_AssignMethod(wx_PrintData, __SetNoCopies);
	Gura_AssignMethod(wx_PrintData, __SetOrientation);
	Gura_AssignMethod(wx_PrintData, __SetPaperId);
	Gura_AssignMethod(wx_PrintData, __SetPaperSize);
	Gura_AssignMethod(wx_PrintData, __SetPrinterName);
	Gura_AssignMethod(wx_PrintData, __SetQuality);
	Gura_AssignMethod(wx_PrintData, __GetFilename);
	Gura_AssignMethod(wx_PrintData, __SetFilename);
	Gura_AssignMethod(wx_PrintData, __GetPrintMode);
	Gura_AssignMethod(wx_PrintData, __SetPrintMode);
}

Gura_ImplementDescendantCreator(wx_PrintData)
{
	return new Object_wx_PrintData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
