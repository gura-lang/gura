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
Gura_DeclareMethod(wx_Printer, wxPrinter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, wxPrinter)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->wxPrinter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printer, CreateAbortWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "printout", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, CreateAbortWindow)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int printout = arg.GetNumber(1)
	//pThis->GetEntity()->CreateAbortWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printer, GetAbort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printer, GetAbort)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAbort();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printer, GetLastError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printer, GetLastError)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printer, GetPrintDialogData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printer, GetPrintDialogData)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintDialogData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printer, Print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "printout", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "prompt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, Print)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int printout = arg.GetNumber(1)
	//int prompt = arg.GetNumber(2)
	//pThis->GetEntity()->Print();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printer, PrintDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, PrintDialog)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->PrintDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printer, ReportError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "printout", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, ReportError)
{
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int printout = arg.GetNumber(1)
	//int message = arg.GetNumber(2)
	//pThis->GetEntity()->ReportError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printer, Setup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, Setup)
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
	Gura_AssignMethod(wx_Printer, wxPrinter);
	Gura_AssignMethod(wx_Printer, CreateAbortWindow);
	Gura_AssignMethod(wx_Printer, GetAbort);
	Gura_AssignMethod(wx_Printer, GetLastError);
	Gura_AssignMethod(wx_Printer, GetPrintDialogData);
	Gura_AssignMethod(wx_Printer, Print);
	Gura_AssignMethod(wx_Printer, PrintDialog);
	Gura_AssignMethod(wx_Printer, ReportError);
	Gura_AssignMethod(wx_Printer, Setup);
}

Gura_ImplementDescendantCreator(wx_Printer)
{
	return new Object_wx_Printer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
