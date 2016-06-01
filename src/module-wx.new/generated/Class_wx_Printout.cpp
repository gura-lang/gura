//----------------------------------------------------------------------------
// wxPrintout
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintout
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPrintout
//----------------------------------------------------------------------------
Object_wx_Printout::~Object_wx_Printout()
{
}

Object *Object_wx_Printout::Clone() const
{
	return nullptr;
}

String Object_wx_Printout::ToString(bool exprFlag)
{
	String rtn("<wx.Printout:");
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
Gura_DeclareMethod(wx_Printout, wxPrintout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, wxPrintout)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->wxPrintout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, ~wxPrintout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, ~wxPrintout)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPrintout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, FitThisSizeToPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, FitThisSizeToPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int imageSize = arg.GetNumber(0)
	//pThis->GetEntity()->FitThisSizeToPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, FitThisSizeToPageMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageSetupData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, FitThisSizeToPageMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int imageSize = arg.GetNumber(0)
	//int pageSetupData = arg.GetNumber(1)
	//pThis->GetEntity()->FitThisSizeToPageMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, FitThisSizeToPaper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, FitThisSizeToPaper)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int imageSize = arg.GetNumber(0)
	//pThis->GetEntity()->FitThisSizeToPaper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, GetDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetLogicalPageMarginsRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageSetupData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, GetLogicalPageMarginsRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pageSetupData = arg.GetNumber(0)
	//pThis->GetEntity()->GetLogicalPageMarginsRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetLogicalPageRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, GetLogicalPageRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLogicalPageRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetLogicalPaperRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, GetLogicalPaperRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLogicalPaperRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetPPIPrinter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, GetPPIPrinter)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int w = arg.GetNumber(0)
	//int h = arg.GetNumber(1)
	//pThis->GetEntity()->GetPPIPrinter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetPPIScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, GetPPIScreen)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int w = arg.GetNumber(0)
	//int h = arg.GetNumber(1)
	//pThis->GetEntity()->GetPPIScreen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetPageInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minPage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxPage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageTo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, GetPageInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int minPage = arg.GetNumber(0)
	//int maxPage = arg.GetNumber(1)
	//int pageFrom = arg.GetNumber(2)
	//int pageTo = arg.GetNumber(3)
	//pThis->GetEntity()->GetPageInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetPageSizeMM)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, GetPageSizeMM)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int w = arg.GetNumber(0)
	//int h = arg.GetNumber(1)
	//pThis->GetEntity()->GetPageSizeMM();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetPageSizePixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, GetPageSizePixels)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int w = arg.GetNumber(0)
	//int h = arg.GetNumber(1)
	//pThis->GetEntity()->GetPageSizePixels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetPaperRectPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, GetPaperRectPixels)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPaperRectPixels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, GetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, HasPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, HasPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pageNum = arg.GetNumber(0)
	//pThis->GetEntity()->HasPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, IsPreview)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, IsPreview)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsPreview();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetPreview)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, GetPreview)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPreview();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, MapScreenSizeToDevice)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, MapScreenSizeToDevice)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MapScreenSizeToDevice();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, MapScreenSizeToPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, MapScreenSizeToPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MapScreenSizeToPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, MapScreenSizeToPageMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageSetupData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, MapScreenSizeToPageMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pageSetupData = arg.GetNumber(0)
	//pThis->GetEntity()->MapScreenSizeToPageMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, MapScreenSizeToPaper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, MapScreenSizeToPaper)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MapScreenSizeToPaper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, OffsetLogicalOrigin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xoff", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yoff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, OffsetLogicalOrigin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int xoff = arg.GetNumber(0)
	//int yoff = arg.GetNumber(1)
	//pThis->GetEntity()->OffsetLogicalOrigin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, OnBeginDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startPage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, OnBeginDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int startPage = arg.GetNumber(0)
	//int endPage = arg.GetNumber(1)
	//pThis->GetEntity()->OnBeginDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, OnBeginPrinting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, OnBeginPrinting)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnBeginPrinting();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, OnEndDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, OnEndDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnEndDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, OnEndPrinting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, OnEndPrinting)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnEndPrinting();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, OnPreparePrinting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, OnPreparePrinting)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnPreparePrinting();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, OnPrintPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, OnPrintPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pageNum = arg.GetNumber(0)
	//pThis->GetEntity()->OnPrintPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, SetLogicalOrigin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, SetLogicalOrigin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetLogicalOrigin();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPrintout
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Printout)
{
	Gura_AssignMethod(wx_Printout, wxPrintout);
	Gura_AssignMethod(wx_Printout, ~wxPrintout);
	Gura_AssignMethod(wx_Printout, FitThisSizeToPage);
	Gura_AssignMethod(wx_Printout, FitThisSizeToPageMargins);
	Gura_AssignMethod(wx_Printout, FitThisSizeToPaper);
	Gura_AssignMethod(wx_Printout, GetDC);
	Gura_AssignMethod(wx_Printout, GetLogicalPageMarginsRect);
	Gura_AssignMethod(wx_Printout, GetLogicalPageRect);
	Gura_AssignMethod(wx_Printout, GetLogicalPaperRect);
	Gura_AssignMethod(wx_Printout, GetPPIPrinter);
	Gura_AssignMethod(wx_Printout, GetPPIScreen);
	Gura_AssignMethod(wx_Printout, GetPageInfo);
	Gura_AssignMethod(wx_Printout, GetPageSizeMM);
	Gura_AssignMethod(wx_Printout, GetPageSizePixels);
	Gura_AssignMethod(wx_Printout, GetPaperRectPixels);
	Gura_AssignMethod(wx_Printout, GetTitle);
	Gura_AssignMethod(wx_Printout, HasPage);
	Gura_AssignMethod(wx_Printout, IsPreview);
	Gura_AssignMethod(wx_Printout, GetPreview);
	Gura_AssignMethod(wx_Printout, MapScreenSizeToDevice);
	Gura_AssignMethod(wx_Printout, MapScreenSizeToPage);
	Gura_AssignMethod(wx_Printout, MapScreenSizeToPageMargins);
	Gura_AssignMethod(wx_Printout, MapScreenSizeToPaper);
	Gura_AssignMethod(wx_Printout, OffsetLogicalOrigin);
	Gura_AssignMethod(wx_Printout, OnBeginDocument);
	Gura_AssignMethod(wx_Printout, OnBeginPrinting);
	Gura_AssignMethod(wx_Printout, OnEndDocument);
	Gura_AssignMethod(wx_Printout, OnEndPrinting);
	Gura_AssignMethod(wx_Printout, OnPreparePrinting);
	Gura_AssignMethod(wx_Printout, OnPrintPage);
	Gura_AssignMethod(wx_Printout, SetLogicalOrigin);
}

Gura_ImplementDescendantCreator(wx_Printout)
{
	return new Object_wx_Printout((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
