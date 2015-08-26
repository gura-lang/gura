//----------------------------------------------------------------------------
// wxPrintout
// extracted from print.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Printout: public wxPrintout, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Printout *_pObj;
public:
	//inline wx_Printout(const wxString& title) : wxPrintout(title), _pObj(nullptr) {}
	~wx_Printout();
	inline void AssocWithGura(Object_wx_Printout *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Printout::~wx_Printout()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Printout::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintout
//----------------------------------------------------------------------------
Gura_DeclareFunction(Printout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Printout));
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Printout)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString title = wxT("Printout");
	if (args.IsValid(0)) title = wxString::FromUTF8(args.GetString(0));
	wx_Printout *pEntity = new wx_Printout(title);
	Object_wx_Printout *pObj = Object_wx_Printout::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Printout(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, GetDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *rtn = (wxDC *)pThis->GetEntity()->GetDC();
	return ReturnValue(env, args, Value(new Object_wx_DC(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Printout, GetPageInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "minPage", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxPage", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pageFrom", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pageTo", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Printout, GetPageInfo)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int minPage = args.GetInt(0);
	int maxPage = args.GetInt(1);
	int pageFrom = args.GetInt(2);
	int pageTo = args.GetInt(3);
	pThis->GetEntity()->GetPageInfo(minPage, maxPage, pageFrom, pageTo);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetPageSizeMM)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Printout, GetPageSizeMM)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int w = args.GetInt(0);
	int h = args.GetInt(1);
	pThis->GetEntity()->GetPageSizeMM(w, h);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetPageSizePixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Printout, GetPageSizePixels)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int w = args.GetInt(0);
	int h = args.GetInt(1);
	pThis->GetEntity()->GetPageSizePixels(w, h);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetPaperRectPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, GetPaperRectPixels)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect rtn = pThis->GetEntity()->GetPaperRectPixels();
	return ReturnValue(env, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Printout, GetPPIPrinter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Printout, GetPPIPrinter)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int w = args.GetInt(0);
	int h = args.GetInt(1);
	pThis->GetEntity()->GetPPIPrinter(w, h);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetPPIScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Printout, GetPPIScreen)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int w = args.GetInt(0);
	int h = args.GetInt(1);
	pThis->GetEntity()->GetPPIScreen(w, h);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, GetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetTitle();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Printout, HasPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, HasPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pageNum = args.GetInt(0);
	bool rtn = pThis->GetEntity()->HasPage(pageNum);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Printout, IsPreview)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, IsPreview)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsPreview();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Printout, FitThisSizeToPaper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageSize", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, FitThisSizeToPaper)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *imageSize = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->FitThisSizeToPaper(*imageSize);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, FitThisSizeToPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageSize", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, FitThisSizeToPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *imageSize = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->FitThisSizeToPage(*imageSize);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, FitThisSizeToPageMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageSize", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "pageSetupData", VTYPE_wx_PageSetupDialogData, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, FitThisSizeToPageMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *imageSize = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxPageSetupDialogData *pageSetupData = Object_wx_PageSetupDialogData::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->FitThisSizeToPageMargins(*imageSize, *pageSetupData);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, MapScreenSizeToPaper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, MapScreenSizeToPaper)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->MapScreenSizeToPaper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, MapScreenSizeToPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, MapScreenSizeToPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->MapScreenSizeToPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, MapScreenSizeToPageMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pageSetupData", VTYPE_wx_PageSetupDialogData, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, MapScreenSizeToPageMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPageSetupDialogData *pageSetupData = Object_wx_PageSetupDialogData::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->MapScreenSizeToPageMargins(*pageSetupData);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, MapScreenSizeToDevice)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, MapScreenSizeToDevice)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->MapScreenSizeToDevice();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, GetLogicalPaperRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, GetLogicalPaperRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect rtn = pThis->GetEntity()->GetLogicalPaperRect();
	return ReturnValue(env, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Printout, GetLogicalPageRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, GetLogicalPageRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect rtn = pThis->GetEntity()->GetLogicalPageRect();
	return ReturnValue(env, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Printout, GetLogicalPageMarginsRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pageSetupData", VTYPE_wx_PageSetupDialogData, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, GetLogicalPageMarginsRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPageSetupDialogData *pageSetupData = Object_wx_PageSetupDialogData::GetObject(args, 0)->GetEntity();
	wxRect rtn = pThis->GetEntity()->GetLogicalPageMarginsRect(*pageSetupData);
	return ReturnValue(env, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Printout, SetLogicalOrigin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, SetLogicalOrigin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->SetLogicalOrigin(x, y);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, OffsetLogicalOrigin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "xoff", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "yoff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, OffsetLogicalOrigin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord xoff = static_cast<wxCoord>(args.GetInt(0));
	wxCoord yoff = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->OffsetLogicalOrigin(xoff, yoff);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, OnBeginDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "startPage", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "endPage", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, OnBeginDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int startPage = args.GetInt(0);
	int endPage = args.GetInt(1);
	bool rtn = pThis->GetEntity()->OnBeginDocument(startPage, endPage);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Printout, OnEndDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, OnEndDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->OnEndDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, OnBeginPrinting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, OnBeginPrinting)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->OnBeginPrinting();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, OnEndPrinting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, OnEndPrinting)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->OnEndPrinting();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, OnPreparePrinting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, OnPreparePrinting)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->OnPreparePrinting();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printout, OnPrintPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, OnPrintPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printout *pThis = Object_wx_Printout::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pageNum = args.GetInt(0);
	bool rtn = pThis->GetEntity()->OnPrintPage(pageNum);
	return ReturnValue(env, args, Value(rtn));
}

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
// Class implementation for wxPrintout
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Printout)
{
	Gura_AssignFunction(Printout);
	Gura_AssignMethod(wx_Printout, GetDC);
	Gura_AssignMethod(wx_Printout, GetPageInfo);
	Gura_AssignMethod(wx_Printout, GetPageSizeMM);
	Gura_AssignMethod(wx_Printout, GetPageSizePixels);
	Gura_AssignMethod(wx_Printout, GetPaperRectPixels);
	Gura_AssignMethod(wx_Printout, GetPPIPrinter);
	Gura_AssignMethod(wx_Printout, GetPPIScreen);
	Gura_AssignMethod(wx_Printout, GetTitle);
	Gura_AssignMethod(wx_Printout, HasPage);
	Gura_AssignMethod(wx_Printout, IsPreview);
	Gura_AssignMethod(wx_Printout, FitThisSizeToPaper);
	Gura_AssignMethod(wx_Printout, FitThisSizeToPage);
	Gura_AssignMethod(wx_Printout, FitThisSizeToPageMargins);
	Gura_AssignMethod(wx_Printout, MapScreenSizeToPaper);
	Gura_AssignMethod(wx_Printout, MapScreenSizeToPage);
	Gura_AssignMethod(wx_Printout, MapScreenSizeToPageMargins);
	Gura_AssignMethod(wx_Printout, MapScreenSizeToDevice);
	Gura_AssignMethod(wx_Printout, GetLogicalPaperRect);
	Gura_AssignMethod(wx_Printout, GetLogicalPageRect);
	Gura_AssignMethod(wx_Printout, GetLogicalPageMarginsRect);
	Gura_AssignMethod(wx_Printout, SetLogicalOrigin);
	Gura_AssignMethod(wx_Printout, OffsetLogicalOrigin);
	Gura_AssignMethod(wx_Printout, OnBeginDocument);
	Gura_AssignMethod(wx_Printout, OnEndDocument);
	Gura_AssignMethod(wx_Printout, OnBeginPrinting);
	Gura_AssignMethod(wx_Printout, OnEndPrinting);
	Gura_AssignMethod(wx_Printout, OnPreparePrinting);
	Gura_AssignMethod(wx_Printout, OnPrintPage);
}

Gura_ImplementDescendantCreator(wx_Printout)
{
	return new Object_wx_Printout((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
