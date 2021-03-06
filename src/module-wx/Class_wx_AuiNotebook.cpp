//----------------------------------------------------------------------------
// wxAuiNotebook
// extracted from auinotebook.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AuiNotebook: public wxAuiNotebook, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_AuiNotebook *_pObj;
public:
	inline wx_AuiNotebook() : wxAuiNotebook(), _pObj(nullptr) {}
	inline wx_AuiNotebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) : wxAuiNotebook(parent, id, pos, size, style), _pObj(nullptr) {}
	~wx_AuiNotebook();
	inline void AssocWithGura(Object_wx_AuiNotebook *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AuiNotebook::~wx_AuiNotebook()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_AuiNotebook::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiNotebook
//----------------------------------------------------------------------------
Gura_DeclareFunction(AuiNotebookEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AuiNotebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AuiNotebookEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_AuiNotebook *pEntity = new wx_AuiNotebook();
	Object_wx_AuiNotebook *pObj = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_AuiNotebook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(AuiNotebook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_AuiNotebook));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AuiNotebook)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (arg.IsValid(1)) id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = wxAUI_NB_DEFAULT_STYLE;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wx_AuiNotebook *pEntity = new wx_AuiNotebook(parent, id, *pos, *size, style);
	Object_wx_AuiNotebook *pObj = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_AuiNotebook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_AuiNotebook, AddPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "select", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, AddPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *page = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxString caption = wxString::FromUTF8(arg.GetString(1));
	bool select = false;
	if (arg.IsValid(2)) select = arg.GetBoolean(2);
	wxBitmap *bitmap = (wxBitmap *)(&wxNullBitmap);
	if (arg.IsValid(3)) bitmap = Object_wx_Bitmap::GetObject(arg, 3)->GetEntity();
	bool rtn = pThis->GetEntity()->AddPage(page, caption, select, *bitmap);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, AdvanceSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "forward", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, AdvanceSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool forward = true;
	if (arg.IsValid(0)) forward = arg.GetBoolean(0);
	pThis->GetEntity()->AdvanceSelection(forward);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (arg.IsValid(1)) id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = 0;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, DeletePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, DeletePage)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = arg.GetSizeT(0);
	bool rtn = pThis->GetEntity()->DeletePage(page);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, GetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetArtProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiTabArt *rtn = (wxAuiTabArt *)pThis->GetEntity()->GetArtProvider();
	return ReturnValue(env, arg, Value(new Object_wx_AuiTabArt(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_AuiNotebook, GetHeightForPageHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pageHeight", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetHeightForPageHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pageHeight = arg.GetInt(0);
	int rtn = pThis->GetEntity()->GetHeightForPageHeight(pageHeight);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, GetPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page_idx", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page_idx = arg.GetSizeT(0);
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetPage(page_idx);
	return ReturnValue(env, arg, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_AuiNotebook, GetPageBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPageBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = arg.GetSizeT(0);
	wxBitmap rtn = pThis->GetEntity()->GetPageBitmap(page);
	return ReturnValue(env, arg, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiNotebook, GetPageCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPageCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetPageCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, GetPageIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page_wnd", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPageIndex)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *page_wnd = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	int rtn = pThis->GetEntity()->GetPageIndex(page_wnd);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, GetPageText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPageText)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = arg.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->GetPageText(page);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_AuiNotebook, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, GetTabCtrlHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetTabCtrlHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetTabCtrlHeight();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, InsertPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page_idx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "select", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, InsertPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page_idx = arg.GetSizeT(0);
	wxWindow *page = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxString caption = wxString::FromUTF8(arg.GetString(2));
	bool select = false;
	if (arg.IsValid(3)) select = arg.GetBoolean(3);
	wxBitmap *bitmap = (wxBitmap *)(&wxNullBitmap);
	if (arg.IsValid(4)) bitmap = Object_wx_Bitmap::GetObject(arg, 4)->GetEntity();
	bool rtn = pThis->GetEntity()->InsertPage(page_idx, page, caption, select, *bitmap);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, RemovePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, RemovePage)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = arg.GetSizeT(0);
	bool rtn = pThis->GetEntity()->RemovePage(page);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, SetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "art", VTYPE_wx_AuiTabArt, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetArtProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiTabArt *art = Object_wx_AuiTabArt::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetArtProvider(art);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetFont(*font);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, SetNormalFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetNormalFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetNormalFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetSelectedFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetSelectedFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetSelectedFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetMeasuringFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetMeasuringFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetMeasuringFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetPageBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, SetPageBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = arg.GetSizeT(0);
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->SetPageBitmap(page, *bitmap);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, SetPageText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, SetPageText)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = arg.GetSizeT(0);
	wxString text = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->SetPageText(page, text);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "new_page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t new_page = arg.GetSizeT(0);
	size_t rtn = pThis->GetEntity()->SetSelection(new_page);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, SetTabCtrlHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetTabCtrlHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int height = arg.GetInt(0);
	pThis->GetEntity()->SetTabCtrlHeight(height);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetUniformBitmapSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetUniformBitmapSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetUniformBitmapSize(*size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, Split)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, Split)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = arg.GetSizeT(0);
	int direction = arg.GetInt(1);
	pThis->GetEntity()->Split(page, direction);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, ShowWindowMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, ShowWindowMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ShowWindowMenu();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxAuiNotebook
//----------------------------------------------------------------------------
Object_wx_AuiNotebook::~Object_wx_AuiNotebook()
{
}

Object *Object_wx_AuiNotebook::Clone() const
{
	return nullptr;
}

String Object_wx_AuiNotebook::ToString(bool exprFlag)
{
	String rtn("<wx.AuiNotebook:");
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
// Class implementation for wxAuiNotebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiNotebook)
{
	Gura_AssignFunction(AuiNotebookEmpty);
	Gura_AssignFunction(AuiNotebook);
	Gura_AssignMethod(wx_AuiNotebook, AddPage);
	Gura_AssignMethod(wx_AuiNotebook, AdvanceSelection);
	Gura_AssignMethod(wx_AuiNotebook, Create);
	Gura_AssignMethod(wx_AuiNotebook, DeletePage);
	Gura_AssignMethod(wx_AuiNotebook, GetArtProvider);
	Gura_AssignMethod(wx_AuiNotebook, GetHeightForPageHeight);
	Gura_AssignMethod(wx_AuiNotebook, GetPage);
	Gura_AssignMethod(wx_AuiNotebook, GetPageBitmap);
	Gura_AssignMethod(wx_AuiNotebook, GetPageCount);
	Gura_AssignMethod(wx_AuiNotebook, GetPageIndex);
	Gura_AssignMethod(wx_AuiNotebook, GetPageText);
	Gura_AssignMethod(wx_AuiNotebook, GetSelection);
	Gura_AssignMethod(wx_AuiNotebook, GetTabCtrlHeight);
	Gura_AssignMethod(wx_AuiNotebook, InsertPage);
	Gura_AssignMethod(wx_AuiNotebook, RemovePage);
	Gura_AssignMethod(wx_AuiNotebook, SetArtProvider);
	Gura_AssignMethod(wx_AuiNotebook, SetFont);
	Gura_AssignMethod(wx_AuiNotebook, SetNormalFont);
	Gura_AssignMethod(wx_AuiNotebook, SetSelectedFont);
	Gura_AssignMethod(wx_AuiNotebook, SetMeasuringFont);
	Gura_AssignMethod(wx_AuiNotebook, SetPageBitmap);
	Gura_AssignMethod(wx_AuiNotebook, SetPageText);
	Gura_AssignMethod(wx_AuiNotebook, SetSelection);
	Gura_AssignMethod(wx_AuiNotebook, SetTabCtrlHeight);
	Gura_AssignMethod(wx_AuiNotebook, SetUniformBitmapSize);
	Gura_AssignMethod(wx_AuiNotebook, Split);
	Gura_AssignMethod(wx_AuiNotebook, ShowWindowMenu);
}

Gura_ImplementDescendantCreator(wx_AuiNotebook)
{
	return new Object_wx_AuiNotebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
