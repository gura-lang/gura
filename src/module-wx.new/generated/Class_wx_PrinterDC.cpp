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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxPrinterDC, "wxPrinterDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printData", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PrinterDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxPrinterDC)
{
	//int printData = arg.GetNumber(0)
	//wxPrinterDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PrinterDC, __GetPaperRect, "GetPaperRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrinterDC, __GetPaperRect)
{
	Object_wx_PrinterDC *pThis = Object_wx_PrinterDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPaperRect();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPrinterDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrinterDC)
{
	// Constructor assignment
	Gura_AssignFunction(__wxPrinterDC);
	// Method assignment
	Gura_AssignMethod(wx_PrinterDC, __GetPaperRect);
}

Gura_ImplementDescendantCreator(wx_PrinterDC)
{
	return new Object_wx_PrinterDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
