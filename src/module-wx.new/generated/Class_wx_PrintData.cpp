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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_PrintData, wxPrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, wxPrintData)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPrintData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, wxPrintData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, wxPrintData_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->wxPrintData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, ~wxPrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, ~wxPrintData)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPrintData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, GetBin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, GetBin)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, GetCollate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, GetCollate)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCollate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, GetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, GetDuplex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, GetDuplex)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDuplex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, GetNoCopies)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, GetNoCopies)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNoCopies();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, GetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, GetOrientation)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, GetPaperId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, GetPaperId)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPaperId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, GetPrinterName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, GetPrinterName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPrinterName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, GetQuality)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, GetQuality)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetQuality();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, SetBin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetBin)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetBin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, SetCollate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetCollate)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetCollate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, SetDuplex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetDuplex)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetDuplex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, SetNoCopies)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetNoCopies)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetNoCopies();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, SetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetOrientation)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->SetOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, SetPaperId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paperId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetPaperId)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int paperId = arg.GetNumber(0)
	//pThis->GetEntity()->SetPaperId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, SetPaperSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetPaperSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetPaperSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, SetPrinterName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printerName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetPrinterName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int printerName = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrinterName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, SetQuality)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "quality", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetQuality)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int quality = arg.GetNumber(0)
	//pThis->GetEntity()->SetQuality();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, GetFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, GetFilename)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFilename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, SetFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetFilename)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, GetPrintMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintData, GetPrintMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPrintMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintData, SetPrintMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetPrintMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int printMode = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintMode();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPrintData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintData)
{
	Gura_AssignMethod(wx_PrintData, wxPrintData);
	Gura_AssignMethod(wx_PrintData, wxPrintData_1);
	Gura_AssignMethod(wx_PrintData, ~wxPrintData);
	Gura_AssignMethod(wx_PrintData, GetBin);
	Gura_AssignMethod(wx_PrintData, GetCollate);
	Gura_AssignMethod(wx_PrintData, GetColour);
	Gura_AssignMethod(wx_PrintData, GetDuplex);
	Gura_AssignMethod(wx_PrintData, GetNoCopies);
	Gura_AssignMethod(wx_PrintData, GetOrientation);
	Gura_AssignMethod(wx_PrintData, GetPaperId);
	Gura_AssignMethod(wx_PrintData, GetPrinterName);
	Gura_AssignMethod(wx_PrintData, GetQuality);
	Gura_AssignMethod(wx_PrintData, IsOk);
	Gura_AssignMethod(wx_PrintData, SetBin);
	Gura_AssignMethod(wx_PrintData, SetCollate);
	Gura_AssignMethod(wx_PrintData, SetColour);
	Gura_AssignMethod(wx_PrintData, SetDuplex);
	Gura_AssignMethod(wx_PrintData, SetNoCopies);
	Gura_AssignMethod(wx_PrintData, SetOrientation);
	Gura_AssignMethod(wx_PrintData, SetPaperId);
	Gura_AssignMethod(wx_PrintData, SetPaperSize);
	Gura_AssignMethod(wx_PrintData, SetPrinterName);
	Gura_AssignMethod(wx_PrintData, SetQuality);
	Gura_AssignMethod(wx_PrintData, GetFilename);
	Gura_AssignMethod(wx_PrintData, SetFilename);
	Gura_AssignMethod(wx_PrintData, GetPrintMode);
	Gura_AssignMethod(wx_PrintData, SetPrintMode);
}

Gura_ImplementDescendantCreator(wx_PrintData)
{
	return new Object_wx_PrintData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
