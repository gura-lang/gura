//----------------------------------------------------------------------------
// wxRichTextPrinting
// extracted from richtextprinting.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextPrinting: public wxRichTextPrinting, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RichTextPrinting *_pObj;
public:
	inline wx_RichTextPrinting(const wxString& name, wxWindow* parentWindow) : wxRichTextPrinting(name, parentWindow), _pObj(nullptr) {}
	~wx_RichTextPrinting();
	inline void AssocWithGura(Object_wx_RichTextPrinting *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextPrinting::~wx_RichTextPrinting()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextPrinting::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextPrinting
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextPrinting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextPrinting));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "parentWindow", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextPrinting)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxT("Printing");
	if (arg.IsValid(0)) name = wxString::FromUTF8(arg.GetString(0));
	wxWindow *parentWindow = (wxWindow *)(nullptr);
	if (arg.IsValid(1)) parentWindow = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wx_RichTextPrinting *pEntity = new wx_RichTextPrinting(name, parentWindow);
	Object_wx_RichTextPrinting *pObj = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextPrinting(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_RichTextPrinting, GetFooterText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "location", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetFooterText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_EVEN;
	if (arg.IsValid(0)) page = static_cast<wxRichTextOddEvenPage>(arg.GetInt(0));
	wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE;
	if (arg.IsValid(1)) location = static_cast<wxRichTextPageLocation>(arg.GetInt(1));
	wxString rtn = pThis->GetEntity()->GetFooterText(page, location);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextPrinting, GetHeaderFooterData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetHeaderFooterData)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxRichTextHeaderFooterData &rtn = pThis->GetEntity()->GetHeaderFooterData();
	return ReturnValue(env, arg, Value(new Object_wx_RichTextHeaderFooterData(new wxRichTextHeaderFooterData(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextPrinting, GetHeaderText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "location", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetHeaderText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_EVEN;
	if (arg.IsValid(0)) page = static_cast<wxRichTextOddEvenPage>(arg.GetInt(0));
	wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE;
	if (arg.IsValid(1)) location = static_cast<wxRichTextPageLocation>(arg.GetInt(1));
	wxString rtn = pThis->GetEntity()->GetHeaderText(page, location);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextPrinting, GetPageSetupData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetPageSetupData)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPageSetupDialogData *rtn = (wxPageSetupDialogData *)pThis->GetEntity()->GetPageSetupData();
	return ReturnValue(env, arg, Value(new Object_wx_PageSetupDialogData(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextPrinting, GetParentWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetParentWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetParentWindow();
	return ReturnValue(env, arg, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextPrinting, GetPreviewRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetPreviewRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxRect &rtn = pThis->GetEntity()->GetPreviewRect();
	return ReturnValue(env, arg, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextPrinting, GetPrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetPrintData)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPrintData *rtn = (wxPrintData *)pThis->GetEntity()->GetPrintData();
	return ReturnValue(env, arg, Value(new Object_wx_PrintData(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextPrinting, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetTitle();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextPrinting, PageSetup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, PageSetup)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->PageSetup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, PreviewBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, PreviewBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->PreviewBuffer(*buffer);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextPrinting, PreviewFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "richTextFile", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, PreviewFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString richTextFile = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->PreviewFile(richTextFile);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextPrinting, PrintBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, PrintBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->PrintBuffer(*buffer);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextPrinting, PrintFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "richTextFile", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, PrintFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString richTextFile = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->PrintFile(richTextFile);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextPrinting, SetFooterText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "location", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetFooterText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(arg.GetString(0));
	wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_ALL;
	if (arg.IsValid(1)) page = static_cast<wxRichTextOddEvenPage>(arg.GetInt(1));
	wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE;
	if (arg.IsValid(2)) location = static_cast<wxRichTextPageLocation>(arg.GetInt(2));
	pThis->GetEntity()->SetFooterText(text, page, location);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetHeaderFooterData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_RichTextHeaderFooterData, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetHeaderFooterData)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextHeaderFooterData *data = Object_wx_RichTextHeaderFooterData::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetHeaderFooterData(*data);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetHeaderFooterFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetHeaderFooterFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetHeaderFooterFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetHeaderFooterTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetHeaderFooterTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetHeaderFooterTextColour(*colour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetHeaderText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "location", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetHeaderText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(arg.GetString(0));
	wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_ALL;
	if (arg.IsValid(1)) page = static_cast<wxRichTextOddEvenPage>(arg.GetInt(1));
	wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE;
	if (arg.IsValid(2)) location = static_cast<wxRichTextPageLocation>(arg.GetInt(2));
	pThis->GetEntity()->SetHeaderText(text, page, location);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetPageSetupData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pageSetupData", VTYPE_wx_PageSetupData, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetPageSetupData)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPageSetupData *pageSetupData = Object_wx_PageSetupData::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetPageSetupData(*pageSetupData);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetParentWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetParentWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetParentWindow(parent);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetPreviewRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetPreviewRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetPreviewRect(*rect);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetPrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "printData", VTYPE_wx_PrintData, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetPrintData)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPrintData *printData = Object_wx_PrintData::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetPrintData(*printData);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetShowOnFirstPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetShowOnFirstPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool show = arg.GetBoolean(0);
	pThis->GetEntity()->SetShowOnFirstPage(show);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString title = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetTitle(title);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextPrinting
//----------------------------------------------------------------------------
Object_wx_RichTextPrinting::~Object_wx_RichTextPrinting()
{
}

Object *Object_wx_RichTextPrinting::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextPrinting::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextPrinting:");
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
// Class implementation for wxRichTextPrinting
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextPrinting)
{
	Gura_AssignFunction(RichTextPrinting);
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
	return new Object_wx_RichTextPrinting((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
