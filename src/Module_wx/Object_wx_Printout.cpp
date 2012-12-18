//----------------------------------------------------------------------------
// wxPrintout
// extracted from print.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Printout: public wxPrintout, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Printout *_pObj;
public:
	//inline wx_Printout(const wxString& title) : wxPrintout(title), _sig(NULL), _pObj(NULL) {}
	~wx_Printout();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Printout *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Printout::~wx_Printout()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Printout::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintout
//----------------------------------------------------------------------------
Gura_DeclareFunction(Printout)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Printout));
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Printout)
{
#if 0
	wxString title = wxT("Printout");
	if (args.IsValid(0)) title = wxString::FromUTF8(args.GetString(0));
	wx_Printout *pEntity = new wx_Printout(title);
	Object_wx_Printout *pObj = Object_wx_Printout::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Printout(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, GetDC)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, GetDC)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *rtn = (wxDC *)pSelf->GetEntity()->GetDC();
	return ReturnValue(env, sig, args, Value(new Object_wx_DC(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Printout, GetPageInfo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "minPage", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxPage", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pageFrom", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pageTo", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Printout, GetPageInfo)
{
#if 0
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int minPage = args.GetInt(0);
	int maxPage = args.GetInt(1);
	int pageFrom = args.GetInt(2);
	int pageTo = args.GetInt(3);
	pSelf->GetEntity()->GetPageInfo(minPage, maxPage, pageFrom, pageTo);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, GetPageSizeMM)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Printout, GetPageSizeMM)
{
#if 0
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int w = args.GetInt(0);
	int h = args.GetInt(1);
	pSelf->GetEntity()->GetPageSizeMM(w, h);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, GetPageSizePixels)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Printout, GetPageSizePixels)
{
#if 0
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int w = args.GetInt(0);
	int h = args.GetInt(1);
	pSelf->GetEntity()->GetPageSizePixels(w, h);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, GetPaperRectPixels)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, GetPaperRectPixels)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pSelf->GetEntity()->GetPaperRectPixels();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Printout, GetPPIPrinter)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Printout, GetPPIPrinter)
{
#if 0
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int w = args.GetInt(0);
	int h = args.GetInt(1);
	pSelf->GetEntity()->GetPPIPrinter(w, h);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, GetPPIScreen)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Printout, GetPPIScreen)
{
#if 0
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int w = args.GetInt(0);
	int h = args.GetInt(1);
	pSelf->GetEntity()->GetPPIScreen(w, h);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, GetTitle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, GetTitle)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetTitle();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Printout, HasPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, HasPage)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int pageNum = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->HasPage(pageNum);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Printout, IsPreview)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, IsPreview)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsPreview();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Printout, FitThisSizeToPaper)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageSize", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, FitThisSizeToPaper)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize *imageSize = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->FitThisSizeToPaper(*imageSize);
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, FitThisSizeToPage)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageSize", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, FitThisSizeToPage)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize *imageSize = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->FitThisSizeToPage(*imageSize);
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, FitThisSizeToPageMargins)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageSize", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "pageSetupData", VTYPE_wx_PageSetupDialogData, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, FitThisSizeToPageMargins)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize *imageSize = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxPageSetupDialogData *pageSetupData = Object_wx_PageSetupDialogData::GetObject(args, 1)->GetEntity();
	pSelf->GetEntity()->FitThisSizeToPageMargins(*imageSize, *pageSetupData);
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, MapScreenSizeToPaper)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, MapScreenSizeToPaper)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->MapScreenSizeToPaper();
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, MapScreenSizeToPage)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, MapScreenSizeToPage)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->MapScreenSizeToPage();
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, MapScreenSizeToPageMargins)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pageSetupData", VTYPE_wx_PageSetupDialogData, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, MapScreenSizeToPageMargins)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPageSetupDialogData *pageSetupData = Object_wx_PageSetupDialogData::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->MapScreenSizeToPageMargins(*pageSetupData);
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, MapScreenSizeToDevice)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, MapScreenSizeToDevice)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->MapScreenSizeToDevice();
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, GetLogicalPaperRect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, GetLogicalPaperRect)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pSelf->GetEntity()->GetLogicalPaperRect();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Printout, GetLogicalPageRect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, GetLogicalPageRect)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pSelf->GetEntity()->GetLogicalPageRect();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Printout, GetLogicalPageMarginsRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pageSetupData", VTYPE_wx_PageSetupDialogData, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, GetLogicalPageMarginsRect)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPageSetupDialogData *pageSetupData = Object_wx_PageSetupDialogData::GetObject(args, 0)->GetEntity();
	wxRect rtn = pSelf->GetEntity()->GetLogicalPageMarginsRect(*pageSetupData);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Printout, SetLogicalOrigin)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, SetLogicalOrigin)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	pSelf->GetEntity()->SetLogicalOrigin(x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, OffsetLogicalOrigin)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "xoff", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "yoff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printout, OffsetLogicalOrigin)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCoord xoff = static_cast<wxCoord>(args.GetInt(0));
	wxCoord yoff = static_cast<wxCoord>(args.GetInt(1));
	pSelf->GetEntity()->OffsetLogicalOrigin(xoff, yoff);
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, OnBeginDocument)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "startPage", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "endPage", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, OnBeginDocument)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int startPage = args.GetInt(0);
	int endPage = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->OnBeginDocument(startPage, endPage);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Printout, OnEndDocument)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, OnEndDocument)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->OnEndDocument();
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, OnBeginPrinting)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, OnBeginPrinting)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->OnBeginPrinting();
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, OnEndPrinting)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, OnEndPrinting)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->OnEndPrinting();
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, OnPreparePrinting)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Printout, OnPreparePrinting)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->OnPreparePrinting();
	return Value::Null;
}

Gura_DeclareMethod(wx_Printout, OnPrintPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printout, OnPrintPage)
{
	Object_wx_Printout *pSelf = Object_wx_Printout::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int pageNum = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->OnPrintPage(pageNum);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxPrintout
//----------------------------------------------------------------------------
Object_wx_Printout::~Object_wx_Printout()
{
}

Object *Object_wx_Printout::Clone() const
{
	return NULL;
}

String Object_wx_Printout::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Printout:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Printout::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(Printout);
}

//----------------------------------------------------------------------------
// Class implementation for wxPrintout
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Printout)
{
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
	return new Object_wx_Printout((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
