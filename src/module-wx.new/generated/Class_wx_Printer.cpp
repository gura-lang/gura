//----------------------------------------------------------------------------
// wxPrinter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPrinter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPrinter
//----------------------------------------------------------------------------
Object_wx_Printer::~Object_wx_Printer()
{
}

Object *Object_wx_Printer::Clone() const
{
	return nullptr;
}

String Object_wx_Printer::ToString(bool exprFlag)
{
	String rtn("<wx.Printer:");
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
Gura_DeclareMethodAlias(wx_Printer, __wxPrinter, "wxPrinter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, __wxPrinter)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->wxPrinter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printer, __CreateAbortWindow, "CreateAbortWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "printout", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, __CreateAbortWindow)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int printout = arg.GetNumber(1)
	//pThis->GetEntity()->CreateAbortWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printer, __GetAbort, "GetAbort")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printer, __GetAbort)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAbort();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printer, __GetLastError, "GetLastError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printer, __GetLastError)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastError();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printer, __GetPrintDialogData, "GetPrintDialogData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printer, __GetPrintDialogData)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintDialogData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printer, __Print, "Print")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "printout", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "prompt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, __Print)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int printout = arg.GetNumber(1)
	//int prompt = arg.GetNumber(2)
	//pThis->GetEntity()->Print();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printer, __PrintDialog, "PrintDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, __PrintDialog)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->PrintDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printer, __ReportError, "ReportError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "printout", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, __ReportError)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int printout = arg.GetNumber(1)
	//int message = arg.GetNumber(2)
	//pThis->GetEntity()->ReportError();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printer, __Setup, "Setup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, __Setup)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->Setup();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPrinter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Printer)
{
	Gura_AssignMethod(wx_Printer, __wxPrinter);
	Gura_AssignMethod(wx_Printer, __CreateAbortWindow);
	Gura_AssignMethod(wx_Printer, __GetAbort);
	Gura_AssignMethod(wx_Printer, __GetLastError);
	Gura_AssignMethod(wx_Printer, __GetPrintDialogData);
	Gura_AssignMethod(wx_Printer, __Print);
	Gura_AssignMethod(wx_Printer, __PrintDialog);
	Gura_AssignMethod(wx_Printer, __ReportError);
	Gura_AssignMethod(wx_Printer, __Setup);
}

Gura_ImplementDescendantCreator(wx_Printer)
{
	return new Object_wx_Printer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
