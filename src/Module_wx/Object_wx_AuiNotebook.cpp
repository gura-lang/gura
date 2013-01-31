//----------------------------------------------------------------------------
// wxAuiNotebook
// extracted from auinotebook.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AuiNotebook: public wxAuiNotebook, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_AuiNotebook *_pObj;
public:
	inline wx_AuiNotebook() : wxAuiNotebook(), _sig(NULL), _pObj(NULL) {}
	inline wx_AuiNotebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) : wxAuiNotebook(parent, id, pos, size, style), _sig(NULL), _pObj(NULL) {}
	~wx_AuiNotebook();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_AuiNotebook *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AuiNotebook::~wx_AuiNotebook()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_AuiNotebook::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiNotebook
//----------------------------------------------------------------------------
Gura_DeclareFunction(AuiNotebookEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AuiNotebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AuiNotebookEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_AuiNotebook *pEntity = new wx_AuiNotebook();
	Object_wx_AuiNotebook *pObj = Object_wx_AuiNotebook::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AuiNotebook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(AuiNotebook)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxAUI_NB_DEFAULT_STYLE;
	if (args.IsValid(4)) style = args.GetLong(4);
	wx_AuiNotebook *pEntity = new wx_AuiNotebook(parent, id, *pos, *size, style);
	Object_wx_AuiNotebook *pObj = Object_wx_AuiNotebook::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AuiNotebook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_AuiNotebook, AddPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "select", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, AddPage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *page = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxString caption = wxString::FromUTF8(args.GetString(1));
	bool select = false;
	if (args.IsValid(2)) select = args.GetBoolean(2);
	wxBitmap *bitmap = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(3)) bitmap = Object_wx_Bitmap::GetObject(args, 3)->GetEntity();
	bool rtn = pThis->GetEntity()->AddPage(page, caption, select, *bitmap);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, AdvanceSelection)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "forward", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, AdvanceSelection)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool forward = true;
	if (args.IsValid(0)) forward = args.GetBoolean(0);
	pThis->GetEntity()->AdvanceSelection(forward);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiNotebook, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, Create)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, DeletePage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, DeletePage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->DeletePage(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, GetArtProvider)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetArtProvider)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxAuiTabArt *rtn = (wxAuiTabArt *)pThis->GetEntity()->GetArtProvider();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiTabArt(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_AuiNotebook, GetHeightForPageHeight)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pageHeight", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetHeightForPageHeight)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pageHeight = args.GetInt(0);
	int rtn = pThis->GetEntity()->GetHeightForPageHeight(pageHeight);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, GetPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page_idx", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page_idx = args.GetSizeT(0);
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetPage(page_idx);
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_AuiNotebook, GetPageBitmap)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPageBitmap)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	wxBitmap rtn = pThis->GetEntity()->GetPageBitmap(page);
	return ReturnValue(env, sig, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiNotebook, GetPageCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPageCount)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetPageCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, GetPageIndex)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page_wnd", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPageIndex)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *page_wnd = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int rtn = pThis->GetEntity()->GetPageIndex(page_wnd);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, GetPageText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPageText)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->GetPageText(page);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_AuiNotebook, GetSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetSelection)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, GetTabCtrlHeight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, GetTabCtrlHeight)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetTabCtrlHeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, InsertPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page_idx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "select", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, InsertPage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page_idx = args.GetSizeT(0);
	wxWindow *page = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxString caption = wxString::FromUTF8(args.GetString(2));
	bool select = false;
	if (args.IsValid(3)) select = args.GetBoolean(3);
	wxBitmap *bitmap = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(4)) bitmap = Object_wx_Bitmap::GetObject(args, 4)->GetEntity();
	bool rtn = pThis->GetEntity()->InsertPage(page_idx, page, caption, select, *bitmap);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, RemovePage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, RemovePage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->RemovePage(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, SetArtProvider)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "art", VTYPE_wx_AuiTabArt, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetArtProvider)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxAuiTabArt *art = Object_wx_AuiTabArt::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetArtProvider(art);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiNotebook, SetFont)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, SetFont)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetFont(*font);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, SetNormalFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetNormalFont)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetNormalFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiNotebook, SetSelectedFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetSelectedFont)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetSelectedFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiNotebook, SetMeasuringFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetMeasuringFont)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetMeasuringFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiNotebook, SetPageBitmap)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, SetPageBitmap)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->SetPageBitmap(page, *bitmap);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, SetPageText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, SetPageText)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	wxString text = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->SetPageText(page, text);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, SetSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "new_page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, SetSelection)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t new_page = args.GetSizeT(0);
	size_t rtn = pThis->GetEntity()->SetSelection(new_page);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiNotebook, SetTabCtrlHeight)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetTabCtrlHeight)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int height = args.GetInt(0);
	pThis->GetEntity()->SetTabCtrlHeight(height);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiNotebook, SetUniformBitmapSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetUniformBitmapSize)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetUniformBitmapSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiNotebook, Split)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, Split)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	int direction = args.GetInt(1);
	pThis->GetEntity()->Split(page, direction);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiNotebook, ShowWindowMenu)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiNotebook, ShowWindowMenu)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ShowWindowMenu();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxAuiNotebook
//----------------------------------------------------------------------------
Object_wx_AuiNotebook::~Object_wx_AuiNotebook()
{
}

Object *Object_wx_AuiNotebook::Clone() const
{
	return NULL;
}

String Object_wx_AuiNotebook::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.AuiNotebook:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_AuiNotebook::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(AuiNotebookEmpty);
	Gura_AssignFunction(AuiNotebook);
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiNotebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiNotebook)
{
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
	return new Object_wx_AuiNotebook((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
