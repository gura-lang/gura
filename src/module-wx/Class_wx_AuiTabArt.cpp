//----------------------------------------------------------------------------
// wxAuiTabArt
// extracted from auitabart.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AuiTabArt: public wxAuiTabArt, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_AuiTabArt *_pObj;
public:
	//inline wx_AuiTabArt() : wxAuiTabArt(), _pObj(nullptr) {}
	~wx_AuiTabArt();
	inline void AssocWithGura(Object_wx_AuiTabArt *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AuiTabArt::~wx_AuiTabArt()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_AuiTabArt::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiTabArt
//----------------------------------------------------------------------------
Gura_DeclareFunction(AuiTabArtEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_AuiTabArt));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(AuiTabArtEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_AuiTabArt *pEntity = new wx_AuiTabArt();
	Object_wx_AuiTabArt *pObj = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_AuiTabArt(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiTabArt, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiTabArt *rtn = (wxAuiTabArt *)pThis->GetEntity()->Clone();
	return ReturnValue(env, arg, Value(new Object_wx_AuiTabArt(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_AuiTabArt, DrawBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "wnd", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, DrawBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(arg, 0)->GetEntity();
	wxWindow *wnd = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(arg, 2)->GetEntity();
	pThis->GetEntity()->DrawBackground(*dc, wnd, *rect);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, DrawButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(arg, 0)->GetEntity();
	wxWindow *wnd = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxRect *in_rect = Object_wx_Rect::GetObject(arg, 2)->GetEntity();
	int bitmap_id = arg.GetInt(3);
	int button_state = arg.GetInt(4);
	int orientation = arg.GetInt(5);
	wxBitmap *bitmap_override = Object_wx_Bitmap::GetObject(arg, 6)->GetEntity();
	wxRect *out_rect = Object_wx_Rect::GetObject(arg, 7)->GetEntity();
	pThis->GetEntity()->DrawButton(*dc, wnd, *in_rect, bitmap_id, button_state, orientation, *bitmap_override, out_rect);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, DrawTab)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(arg, 0)->GetEntity();
	wxWindow *wnd = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxRect *in_rect = Object_wx_Rect::GetObject(arg, 2)->GetEntity();
	wxString caption = wxString::FromUTF8(arg.GetString(3));
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 4)->GetEntity();
	bool active = arg.GetBoolean(5);
	int close_button_state = arg.GetInt(6);
	wxRect *out_tab_rect = Object_wx_Rect::GetObject(arg, 7)->GetEntity();
	wxRect *out_button_rect = Object_wx_Rect::GetObject(arg, 8)->GetEntity();
	int x_extent = arg.GetInt(9);
	pThis->GetEntity()->DrawTab(*dc, wnd, *in_rect, caption, *bitmap, active, close_button_state, out_tab_rect, out_button_rect, x_extent);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, GetBestTabCtrlSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "wnd", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "pages", VTYPE_wx_AuiNotebookPageArray, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiTabArt, GetBestTabCtrlSize)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *wnd = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxAuiNotebookPageArray *pages = Object_wx_AuiNotebookPageArray::GetObject(arg, 1)->GetEntity();
	int rtn = pThis->GetEntity()->GetBestTabCtrlSize(wnd, *pages);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, GetIndentSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiTabArt, GetIndentSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetIndentSize();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiTabArt, GetTabSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(arg, 0)->GetEntity();
	wxWindow *wnd = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxString caption = wxString::FromUTF8(arg.GetString(2));
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 3)->GetEntity();
	bool active = arg.GetBoolean(4);
	int close_button_state = arg.GetInt(5);
	int x_extent = arg.GetInt(6);
	wxSize rtn = pThis->GetEntity()->GetTabSize(*dc, wnd, caption, *bitmap, active, close_button_state, x_extent);
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned flags = arg.GetInt(0);
	pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, SetMeasuringFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetMeasuringFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetMeasuringFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, SetNormalFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetNormalFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetNormalFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, SetSelectedFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetSelectedFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetSelectedFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, SetSizingInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tab_ctrl_size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "tab_count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetSizingInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *tab_ctrl_size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	size_t tab_count = arg.GetSizeT(1);
	pThis->GetEntity()->SetSizingInfo(*tab_ctrl_size, tab_count);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, ShowWindowList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "wnd", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "items", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "active_idx", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiTabArt, ShowWindowList)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *wnd = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	std::unique_ptr<wxArrayString> items(CreateArrayString(arg.GetList(1)));
	int active_idx = arg.GetInt(2);
	int rtn = pThis->GetEntity()->ShowWindowList(wnd, *items, active_idx);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxAuiTabArt
//----------------------------------------------------------------------------
Object_wx_AuiTabArt::~Object_wx_AuiTabArt()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_AuiTabArt::Clone() const
{
	return nullptr;
}

String Object_wx_AuiTabArt::ToString(bool exprFlag)
{
	String rtn("<wx.AuiTabArt:");
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
// Class implementation for wxAuiTabArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiTabArt)
{
	Gura_AssignFunction(AuiTabArtEmpty);
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
	return new Object_wx_AuiTabArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
