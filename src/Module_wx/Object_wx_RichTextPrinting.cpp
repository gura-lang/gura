//----------------------------------------------------------------------------
// wxRichTextPrinting
// extracted from richtextprinting.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextPrinting: public wxRichTextPrinting, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextPrinting *_pObj;
public:
	inline wx_RichTextPrinting(const wxString& name, wxWindow* parentWindow) : wxRichTextPrinting(name, parentWindow), _sig(NULL), _pObj(NULL) {}
	~wx_RichTextPrinting();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextPrinting *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextPrinting::~wx_RichTextPrinting()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextPrinting::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextPrinting
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextPrinting)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextPrinting));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "parentWindow", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextPrinting)
{
	wxString name = wxT("Printing");
	if (args.IsValid(0)) name = wxString::FromUTF8(args.GetString(0));
	wxWindow *parentWindow = (wxWindow *)(NULL);
	if (args.IsValid(1)) parentWindow = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wx_RichTextPrinting *pEntity = new wx_RichTextPrinting(name, parentWindow);
	Object_wx_RichTextPrinting *pObj = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextPrinting(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_RichTextPrinting, GetFooterText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "location", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetFooterText)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_EVEN;
	if (args.IsValid(0)) page = static_cast<wxRichTextOddEvenPage>(args.GetInt(0));
	wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE;
	if (args.IsValid(1)) location = static_cast<wxRichTextPageLocation>(args.GetInt(1));
	wxString rtn = pSelf->GetEntity()->GetFooterText(page, location);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextPrinting, GetHeaderFooterData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetHeaderFooterData)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxRichTextHeaderFooterData &rtn = pSelf->GetEntity()->GetHeaderFooterData();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextHeaderFooterData(new wxRichTextHeaderFooterData(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextPrinting, GetHeaderText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "location", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetHeaderText)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_EVEN;
	if (args.IsValid(0)) page = static_cast<wxRichTextOddEvenPage>(args.GetInt(0));
	wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE;
	if (args.IsValid(1)) location = static_cast<wxRichTextPageLocation>(args.GetInt(1));
	wxString rtn = pSelf->GetEntity()->GetHeaderText(page, location);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextPrinting, GetPageSetupData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetPageSetupData)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPageSetupDialogData *rtn = (wxPageSetupDialogData *)pSelf->GetEntity()->GetPageSetupData();
	return ReturnValue(env, sig, args, Value(new Object_wx_PageSetupDialogData(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextPrinting, GetParentWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetParentWindow)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pSelf->GetEntity()->GetParentWindow();
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextPrinting, GetPreviewRect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetPreviewRect)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxRect &rtn = pSelf->GetEntity()->GetPreviewRect();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextPrinting, GetPrintData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetPrintData)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPrintData *rtn = (wxPrintData *)pSelf->GetEntity()->GetPrintData();
	return ReturnValue(env, sig, args, Value(new Object_wx_PrintData(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextPrinting, GetTitle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetTitle)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetTitle();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextPrinting, PageSetup)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, PageSetup)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->PageSetup();
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrinting, PreviewBuffer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, PreviewBuffer)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->PreviewBuffer(*buffer);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextPrinting, PreviewFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "richTextFile", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, PreviewFile)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString richTextFile = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->PreviewFile(richTextFile);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextPrinting, PrintBuffer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, PrintBuffer)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->PrintBuffer(*buffer);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextPrinting, PrintFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "richTextFile", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, PrintFile)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString richTextFile = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->PrintFile(richTextFile);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextPrinting, SetFooterText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "location", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetFooterText)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_ALL;
	if (args.IsValid(1)) page = static_cast<wxRichTextOddEvenPage>(args.GetInt(1));
	wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE;
	if (args.IsValid(2)) location = static_cast<wxRichTextPageLocation>(args.GetInt(2));
	pSelf->GetEntity()->SetFooterText(text, page, location);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetHeaderFooterData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_RichTextHeaderFooterData, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetHeaderFooterData)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextHeaderFooterData *data = Object_wx_RichTextHeaderFooterData::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetHeaderFooterData(*data);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetHeaderFooterFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetHeaderFooterFont)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetHeaderFooterFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetHeaderFooterTextColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetHeaderFooterTextColour)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetHeaderFooterTextColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetHeaderText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "location", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetHeaderText)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_ALL;
	if (args.IsValid(1)) page = static_cast<wxRichTextOddEvenPage>(args.GetInt(1));
	wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE;
	if (args.IsValid(2)) location = static_cast<wxRichTextPageLocation>(args.GetInt(2));
	pSelf->GetEntity()->SetHeaderText(text, page, location);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetPageSetupData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pageSetupData", VTYPE_wx_PageSetupData, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetPageSetupData)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPageSetupData *pageSetupData = Object_wx_PageSetupData::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetPageSetupData(*pageSetupData);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetParentWindow)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetParentWindow)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetParentWindow(parent);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetPreviewRect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetPreviewRect)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetPreviewRect(*rect);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetPrintData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "printData", VTYPE_wx_PrintData, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetPrintData)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPrintData *printData = Object_wx_PrintData::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetPrintData(*printData);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetShowOnFirstPage)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetShowOnFirstPage)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool show = args.GetBoolean(0);
	pSelf->GetEntity()->SetShowOnFirstPage(show);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetTitle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetTitle)
{
	Object_wx_RichTextPrinting *pSelf = Object_wx_RichTextPrinting::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString title = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetTitle(title);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextPrinting
//----------------------------------------------------------------------------
Object_wx_RichTextPrinting::~Object_wx_RichTextPrinting()
{
}

Object *Object_wx_RichTextPrinting::Clone() const
{
	return NULL;
}

String Object_wx_RichTextPrinting::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RichTextPrinting:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_RichTextPrinting::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(RichTextPrinting);
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextPrinting
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextPrinting)
{
	Gura_AssignMethod(wx_RichTextPrinting, GetFooterText);
	Gura_AssignMethod(wx_RichTextPrinting, GetHeaderFooterData);
	Gura_AssignMethod(wx_RichTextPrinting, GetHeaderText);
	Gura_AssignMethod(wx_RichTextPrinting, GetPageSetupData);
	Gura_AssignMethod(wx_RichTextPrinting, GetParentWindow);
	Gura_AssignMethod(wx_RichTextPrinting, GetPreviewRect);
	Gura_AssignMethod(wx_RichTextPrinting, GetPrintData);
	Gura_AssignMethod(wx_RichTextPrinting, GetTitle);
	Gura_AssignMethod(wx_RichTextPrinting, PageSetup);
	Gura_AssignMethod(wx_RichTextPrinting, PreviewBuffer);
	Gura_AssignMethod(wx_RichTextPrinting, PreviewFile);
	Gura_AssignMethod(wx_RichTextPrinting, PrintBuffer);
	Gura_AssignMethod(wx_RichTextPrinting, PrintFile);
	Gura_AssignMethod(wx_RichTextPrinting, SetFooterText);
	Gura_AssignMethod(wx_RichTextPrinting, SetHeaderFooterData);
	Gura_AssignMethod(wx_RichTextPrinting, SetHeaderFooterFont);
	Gura_AssignMethod(wx_RichTextPrinting, SetHeaderFooterTextColour);
	Gura_AssignMethod(wx_RichTextPrinting, SetHeaderText);
	Gura_AssignMethod(wx_RichTextPrinting, SetPageSetupData);
	Gura_AssignMethod(wx_RichTextPrinting, SetParentWindow);
	Gura_AssignMethod(wx_RichTextPrinting, SetPreviewRect);
	Gura_AssignMethod(wx_RichTextPrinting, SetPrintData);
	Gura_AssignMethod(wx_RichTextPrinting, SetShowOnFirstPage);
	Gura_AssignMethod(wx_RichTextPrinting, SetTitle);
}

Gura_ImplementDescendantCreator(wx_RichTextPrinting)
{
	return new Object_wx_RichTextPrinting((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
