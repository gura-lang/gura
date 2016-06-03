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
Gura_DeclareMethodAlias(wx_Printout, __wxPrintout, "wxPrintout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __wxPrintout)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->wxPrintout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __FitThisSizeToPage, "FitThisSizeToPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __FitThisSizeToPage)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageSize = arg.GetNumber(0)
	//pThis->GetEntity()->FitThisSizeToPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __FitThisSizeToPageMargins, "FitThisSizeToPageMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageSetupData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __FitThisSizeToPageMargins)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageSize = arg.GetNumber(0)
	//int pageSetupData = arg.GetNumber(1)
	//pThis->GetEntity()->FitThisSizeToPageMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __FitThisSizeToPaper, "FitThisSizeToPaper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __FitThisSizeToPaper)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageSize = arg.GetNumber(0)
	//pThis->GetEntity()->FitThisSizeToPaper();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __GetDC, "GetDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, __GetDC)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __GetLogicalPageMarginsRect, "GetLogicalPageMarginsRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageSetupData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __GetLogicalPageMarginsRect)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pageSetupData = arg.GetNumber(0)
	//pThis->GetEntity()->GetLogicalPageMarginsRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __GetLogicalPageRect, "GetLogicalPageRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, __GetLogicalPageRect)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLogicalPageRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __GetLogicalPaperRect, "GetLogicalPaperRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, __GetLogicalPaperRect)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLogicalPaperRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __GetPPIPrinter, "GetPPIPrinter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __GetPPIPrinter)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int w = arg.GetNumber(0)
	//int h = arg.GetNumber(1)
	//pThis->GetEntity()->GetPPIPrinter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __GetPPIScreen, "GetPPIScreen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __GetPPIScreen)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int w = arg.GetNumber(0)
	//int h = arg.GetNumber(1)
	//pThis->GetEntity()->GetPPIScreen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __GetPageInfo, "GetPageInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minPage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxPage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageTo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __GetPageInfo)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minPage = arg.GetNumber(0)
	//int maxPage = arg.GetNumber(1)
	//int pageFrom = arg.GetNumber(2)
	//int pageTo = arg.GetNumber(3)
	//pThis->GetEntity()->GetPageInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __GetPageSizeMM, "GetPageSizeMM")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __GetPageSizeMM)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int w = arg.GetNumber(0)
	//int h = arg.GetNumber(1)
	//pThis->GetEntity()->GetPageSizeMM();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __GetPageSizePixels, "GetPageSizePixels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __GetPageSizePixels)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int w = arg.GetNumber(0)
	//int h = arg.GetNumber(1)
	//pThis->GetEntity()->GetPageSizePixels();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __GetPaperRectPixels, "GetPaperRectPixels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, __GetPaperRectPixels)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPaperRectPixels();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __GetTitle, "GetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, __GetTitle)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __HasPage, "HasPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __HasPage)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pageNum = arg.GetNumber(0)
	//pThis->GetEntity()->HasPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __IsPreview, "IsPreview")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, __IsPreview)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsPreview();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __GetPreview, "GetPreview")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, __GetPreview)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPreview();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __MapScreenSizeToDevice, "MapScreenSizeToDevice")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, __MapScreenSizeToDevice)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MapScreenSizeToDevice();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __MapScreenSizeToPage, "MapScreenSizeToPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, __MapScreenSizeToPage)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MapScreenSizeToPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __MapScreenSizeToPageMargins, "MapScreenSizeToPageMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageSetupData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __MapScreenSizeToPageMargins)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pageSetupData = arg.GetNumber(0)
	//pThis->GetEntity()->MapScreenSizeToPageMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __MapScreenSizeToPaper, "MapScreenSizeToPaper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, __MapScreenSizeToPaper)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MapScreenSizeToPaper();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __OffsetLogicalOrigin, "OffsetLogicalOrigin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xoff", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yoff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __OffsetLogicalOrigin)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xoff = arg.GetNumber(0)
	//int yoff = arg.GetNumber(1)
	//pThis->GetEntity()->OffsetLogicalOrigin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __OnBeginDocument, "OnBeginDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startPage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __OnBeginDocument)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startPage = arg.GetNumber(0)
	//int endPage = arg.GetNumber(1)
	//pThis->GetEntity()->OnBeginDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __OnBeginPrinting, "OnBeginPrinting")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, __OnBeginPrinting)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnBeginPrinting();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __OnEndDocument, "OnEndDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, __OnEndDocument)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnEndDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __OnEndPrinting, "OnEndPrinting")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, __OnEndPrinting)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnEndPrinting();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __OnPreparePrinting, "OnPreparePrinting")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, __OnPreparePrinting)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnPreparePrinting();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __OnPrintPage, "OnPrintPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __OnPrintPage)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pageNum = arg.GetNumber(0)
	//pThis->GetEntity()->OnPrintPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Printout, __SetLogicalOrigin, "SetLogicalOrigin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, __SetLogicalOrigin)
{
	Object_wx_Printout *pThis = Object_wx_Printout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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
	Gura_AssignMethod(wx_Printout, __wxPrintout);
	Gura_AssignMethod(wx_Printout, __FitThisSizeToPage);
	Gura_AssignMethod(wx_Printout, __FitThisSizeToPageMargins);
	Gura_AssignMethod(wx_Printout, __FitThisSizeToPaper);
	Gura_AssignMethod(wx_Printout, __GetDC);
	Gura_AssignMethod(wx_Printout, __GetLogicalPageMarginsRect);
	Gura_AssignMethod(wx_Printout, __GetLogicalPageRect);
	Gura_AssignMethod(wx_Printout, __GetLogicalPaperRect);
	Gura_AssignMethod(wx_Printout, __GetPPIPrinter);
	Gura_AssignMethod(wx_Printout, __GetPPIScreen);
	Gura_AssignMethod(wx_Printout, __GetPageInfo);
	Gura_AssignMethod(wx_Printout, __GetPageSizeMM);
	Gura_AssignMethod(wx_Printout, __GetPageSizePixels);
	Gura_AssignMethod(wx_Printout, __GetPaperRectPixels);
	Gura_AssignMethod(wx_Printout, __GetTitle);
	Gura_AssignMethod(wx_Printout, __HasPage);
	Gura_AssignMethod(wx_Printout, __IsPreview);
	Gura_AssignMethod(wx_Printout, __GetPreview);
	Gura_AssignMethod(wx_Printout, __MapScreenSizeToDevice);
	Gura_AssignMethod(wx_Printout, __MapScreenSizeToPage);
	Gura_AssignMethod(wx_Printout, __MapScreenSizeToPageMargins);
	Gura_AssignMethod(wx_Printout, __MapScreenSizeToPaper);
	Gura_AssignMethod(wx_Printout, __OffsetLogicalOrigin);
	Gura_AssignMethod(wx_Printout, __OnBeginDocument);
	Gura_AssignMethod(wx_Printout, __OnBeginPrinting);
	Gura_AssignMethod(wx_Printout, __OnEndDocument);
	Gura_AssignMethod(wx_Printout, __OnEndPrinting);
	Gura_AssignMethod(wx_Printout, __OnPreparePrinting);
	Gura_AssignMethod(wx_Printout, __OnPrintPage);
	Gura_AssignMethod(wx_Printout, __SetLogicalOrigin);
}

Gura_ImplementDescendantCreator(wx_Printout)
{
	return new Object_wx_Printout((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
