//----------------------------------------------------------------------------
// wxAuiTabArt
// extracted from auitabart.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AuiTabArt: public wxAuiTabArt, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_AuiTabArt *_pObj;
public:
	//inline wx_AuiTabArt() : wxAuiTabArt(), _sig(NULL), _pObj(NULL) {}
	~wx_AuiTabArt();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_AuiTabArt *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AuiTabArt::~wx_AuiTabArt()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_AuiTabArt::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiTabArt
//----------------------------------------------------------------------------
Gura_DeclareFunction(AuiTabArtEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_AuiTabArt));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(AuiTabArtEmpty)
{
#if 0
	wx_AuiTabArt *pEntity = new wx_AuiTabArt();
	Object_wx_AuiTabArt *pObj = Object_wx_AuiTabArt::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AuiTabArt(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_AuiTabArt, Clone)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiTabArt, Clone)
{
	Object_wx_AuiTabArt *pSelf = Object_wx_AuiTabArt::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiTabArt *rtn = (wxAuiTabArt *)pSelf->GetEntity()->Clone();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiTabArt(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_AuiTabArt, DrawBackground)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "wnd", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, DrawBackground)
{
	Object_wx_AuiTabArt *pSelf = Object_wx_AuiTabArt::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxWindow *wnd = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	pSelf->GetEntity()->DrawBackground(*dc, wnd, *rect);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiTabArt, DrawButton)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "wnd", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "in_rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "bitmap_id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "button_state", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bitmap_override", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "out_rect", VTYPE_wx_Rect, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_AuiTabArt, DrawButton)
{
#if 0
	Object_wx_AuiTabArt *pSelf = Object_wx_AuiTabArt::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxWindow *wnd = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxRect *in_rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	int bitmap_id = args.GetInt(3);
	int button_state = args.GetInt(4);
	int orientation = args.GetInt(5);
	wxBitmap *bitmap_override = Object_wx_Bitmap::GetObject(args, 6)->GetEntity();
	wxRect *out_rect = Object_wx_Rect::GetObject(args, 7)->GetEntity();
	pSelf->GetEntity()->DrawButton(*dc, wnd, *in_rect, bitmap_id, button_state, orientation, *bitmap_override, out_rect);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiTabArt, DrawTab)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "wnd", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "in_rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "active", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "close_button_state", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "out_tab_rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "out_button_rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "x_extent", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_AuiTabArt, DrawTab)
{
#if 0
	Object_wx_AuiTabArt *pSelf = Object_wx_AuiTabArt::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxWindow *wnd = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxRect *in_rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	wxString caption = wxString::FromUTF8(args.GetString(3));
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 4)->GetEntity();
	bool active = args.GetBoolean(5);
	int close_button_state = args.GetInt(6);
	wxRect *out_tab_rect = Object_wx_Rect::GetObject(args, 7)->GetEntity();
	wxRect *out_button_rect = Object_wx_Rect::GetObject(args, 8)->GetEntity();
	int x_extent = args.GetInt(9);
	pSelf->GetEntity()->DrawTab(*dc, wnd, *in_rect, caption, *bitmap, active, close_button_state, out_tab_rect, out_button_rect, x_extent);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiTabArt, GetBestTabCtrlSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "wnd", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "pages", VTYPE_wx_AuiNotebookPageArray, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiTabArt, GetBestTabCtrlSize)
{
#if 0
	Object_wx_AuiTabArt *pSelf = Object_wx_AuiTabArt::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *wnd = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxAuiNotebookPageArray *pages = Object_wx_AuiNotebookPageArray::GetObject(args, 1)->GetEntity();
	int rtn = pSelf->GetEntity()->GetBestTabCtrlSize(wnd, *pages);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiTabArt, GetIndentSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiTabArt, GetIndentSize)
{
	Object_wx_AuiTabArt *pSelf = Object_wx_AuiTabArt::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetIndentSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiTabArt, GetTabSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "wnd", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "active", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "close_button_state", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "x_extent", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiTabArt, GetTabSize)
{
#if 0
	Object_wx_AuiTabArt *pSelf = Object_wx_AuiTabArt::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxWindow *wnd = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxString caption = wxString::FromUTF8(args.GetString(2));
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 3)->GetEntity();
	bool active = args.GetBoolean(4);
	int close_button_state = args.GetInt(5);
	int x_extent = args.GetInt(6);
	wxSize rtn = pSelf->GetEntity()->GetTabSize(*dc, wnd, caption, *bitmap, active, close_button_state, x_extent);
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiTabArt, SetFlags)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetFlags)
{
	Object_wx_AuiTabArt *pSelf = Object_wx_AuiTabArt::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned flags = args.GetInt(0);
	pSelf->GetEntity()->SetFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiTabArt, SetMeasuringFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetMeasuringFont)
{
	Object_wx_AuiTabArt *pSelf = Object_wx_AuiTabArt::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetMeasuringFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiTabArt, SetNormalFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetNormalFont)
{
	Object_wx_AuiTabArt *pSelf = Object_wx_AuiTabArt::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetNormalFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiTabArt, SetSelectedFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetSelectedFont)
{
	Object_wx_AuiTabArt *pSelf = Object_wx_AuiTabArt::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetSelectedFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiTabArt, SetSizingInfo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tab_ctrl_size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "tab_count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetSizingInfo)
{
	Object_wx_AuiTabArt *pSelf = Object_wx_AuiTabArt::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize *tab_ctrl_size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	size_t tab_count = args.GetSizeT(1);
	pSelf->GetEntity()->SetSizingInfo(*tab_ctrl_size, tab_count);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiTabArt, ShowWindowList)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "wnd", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "items", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "active_idx", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiTabArt, ShowWindowList)
{
#if 0
	Object_wx_AuiTabArt *pSelf = Object_wx_AuiTabArt::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *wnd = Object_wx_Window::GetObject(args, 0)->GetEntity();
	std::auto_ptr<wxArrayString> items(CreateArrayString(args.GetList(1)));
	int active_idx = args.GetInt(2);
	int rtn = pSelf->GetEntity()->ShowWindowList(wnd, *items, active_idx);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxAuiTabArt
//----------------------------------------------------------------------------
Object_wx_AuiTabArt::~Object_wx_AuiTabArt()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_AuiTabArt::Clone() const
{
	return NULL;
}

String Object_wx_AuiTabArt::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.AuiTabArt:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_AuiTabArt::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(AuiTabArtEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiTabArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiTabArt)
{
	Gura_AssignMethod(wx_AuiTabArt, Clone);
	Gura_AssignMethod(wx_AuiTabArt, DrawBackground);
	Gura_AssignMethod(wx_AuiTabArt, DrawButton);
	Gura_AssignMethod(wx_AuiTabArt, DrawTab);
	Gura_AssignMethod(wx_AuiTabArt, GetBestTabCtrlSize);
	Gura_AssignMethod(wx_AuiTabArt, GetIndentSize);
	Gura_AssignMethod(wx_AuiTabArt, GetTabSize);
	Gura_AssignMethod(wx_AuiTabArt, SetFlags);
	Gura_AssignMethod(wx_AuiTabArt, SetMeasuringFont);
	Gura_AssignMethod(wx_AuiTabArt, SetNormalFont);
	Gura_AssignMethod(wx_AuiTabArt, SetSelectedFont);
	Gura_AssignMethod(wx_AuiTabArt, SetSizingInfo);
	Gura_AssignMethod(wx_AuiTabArt, ShowWindowList);
}

Gura_ImplementDescendantCreator(wx_AuiTabArt)
{
	return new Object_wx_AuiTabArt((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
