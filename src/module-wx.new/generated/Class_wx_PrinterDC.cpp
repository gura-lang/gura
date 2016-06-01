//----------------------------------------------------------------------------
// wxPrinterDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPrinterDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPrinterDC
//----------------------------------------------------------------------------
Object_wx_PrinterDC::~Object_wx_PrinterDC()
{
}

Object *Object_wx_PrinterDC::Clone() const
{
	return nullptr;
}

String Object_wx_PrinterDC::ToString(bool exprFlag)
{
	String rtn("<wx.PrinterDC:");
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
Gura_DeclareMethod(wx_PrinterDC, wxPrinterDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrinterDC, wxPrinterDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrinterDC *pThis = Object_wx_PrinterDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int printData = arg.GetNumber(0)
	//pThis->GetEntity()->wxPrinterDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrinterDC, GetPaperRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrinterDC, GetPaperRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrinterDC *pThis = Object_wx_PrinterDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPaperRect();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPrinterDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrinterDC)
{
	Gura_AssignMethod(wx_PrinterDC, wxPrinterDC);
	Gura_AssignMethod(wx_PrinterDC, GetPaperRect);
}

Gura_ImplementDescendantCreator(wx_PrinterDC)
{
	return new Object_wx_PrinterDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
