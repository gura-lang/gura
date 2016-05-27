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
// Class implementation for wxPrinterDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrinterDC)
{
}

Gura_ImplementDescendantCreator(wx_PrinterDC)
{
	return new Object_wx_PrinterDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
