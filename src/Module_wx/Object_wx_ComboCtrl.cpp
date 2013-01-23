//----------------------------------------------------------------------------
// wxComboCtrl
// extracted from comboctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(AnimateShow);
Gura_DeclarePrivUserSymbol(DoShowPopup);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ComboCtrl: public wxComboCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ComboCtrl *_pObj;
public:
	inline wx_ComboCtrl() : wxComboCtrl(), _sig(NULL), _pObj(NULL) {}
	inline wx_ComboCtrl(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxComboCtrl(parent, id, value, pos, size, style, validator, name), _sig(NULL), _pObj(NULL) {}
	//virtual bool AnimateShow(const wxRect& rect, int flags);
	//virtual void DoShowPopup(const wxRect& rect, int flags);
	~wx_ComboCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ComboCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
public:
	// reveal private or protected member functions to public
	inline bool _AnimateShow(const wxRect& rect, int flags) {
		return wxComboCtrl::AnimateShow(rect, flags);
	}
	inline void _DoSetPopupControl(wxComboPopup* popup) {
		wxComboCtrl::DoSetPopupControl(popup);
	}
	inline void _DoShowPopup(const wxRect& rect, int flags) {
		wxComboCtrl::DoShowPopup(rect, flags);
	}
};

wx_ComboCtrl::~wx_ComboCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ComboCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxComboCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(ComboCtrlEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ComboCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ComboCtrlEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ComboCtrl *pEntity = new wx_ComboCtrl();
	Object_wx_ComboCtrl *pObj = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ComboCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(ComboCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ComboCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ComboCtrl)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxT("");
	if (args.IsValid(2)) value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("comboCtrl");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_ComboCtrl *pEntity = new wx_ComboCtrl(parent, id, value, *pos, *size, style, *validator, name);
	Object_wx_ComboCtrl *pObj = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ComboCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_ComboCtrl, AnimateShow)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, AnimateShow)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	int flags = args.GetInt(1);
	bool rtn = dynamic_cast<wx_ComboCtrl *>(pSelf->GetEntity())->_AnimateShow(*rect, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, Create)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxT("");
	if (args.IsValid(2)) value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("comboCtrl");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pSelf->GetEntity()->Create(parent, id, value, *pos, *size, style, *validator, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, Copy)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, Copy)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Copy();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, Cut)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, Cut)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Cut();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, DoSetPopupControl)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "popup", VTYPE_wx_ComboPopup, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, DoSetPopupControl)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxComboPopup *popup = Object_wx_ComboPopup::GetObject(args, 0)->GetEntity();
	dynamic_cast<wx_ComboCtrl *>(pSelf->GetEntity())->_DoSetPopupControl(popup);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, DoShowPopup)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, DoShowPopup)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	int flags = args.GetInt(1);
	dynamic_cast<wx_ComboCtrl *>(pSelf->GetEntity())->_DoShowPopup(*rect, flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, EnablePopupAnimation)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, EnablePopupAnimation)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	pSelf->GetEntity()->EnablePopupAnimation(enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, GetBitmapDisabled)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetBitmapDisabled)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pSelf->GetEntity()->GetBitmapDisabled();
	return ReturnValue(env, sig, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetBitmapHover)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetBitmapHover)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pSelf->GetEntity()->GetBitmapHover();
	return ReturnValue(env, sig, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetBitmapNormal)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetBitmapNormal)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pSelf->GetEntity()->GetBitmapNormal();
	return ReturnValue(env, sig, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetBitmapPressed)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetBitmapPressed)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pSelf->GetEntity()->GetBitmapPressed();
	return ReturnValue(env, sig, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetButtonSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetButtonSize)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pSelf->GetEntity()->GetButtonSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetCustomPaintWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetCustomPaintWidth)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetCustomPaintWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_ComboCtrl, GetFeatures)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ComboCtrl, GetFeatures)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int rtn = wxComboCtrl::GetFeatures();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, GetInsertionPoint)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetInsertionPoint)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetInsertionPoint();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, IsPopupWindowState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, IsPopupWindowState)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int state = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->IsPopupWindowState(state);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, GetLastPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetLastPosition)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetLastPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, GetPopupControl)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetPopupControl)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxComboPopup *rtn = (wxComboPopup *)pSelf->GetEntity()->GetPopupControl();
	return ReturnValue(env, sig, args, Value(new Object_wx_ComboPopup(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetPopupWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetPopupWindow)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pSelf->GetEntity()->GetPopupWindow();
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetTextCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetTextCtrl)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextCtrl *rtn = (wxTextCtrl *)pSelf->GetEntity()->GetTextCtrl();
	return ReturnValue(env, sig, args, Value(new Object_wx_TextCtrl(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetTextIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetTextIndent)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pSelf->GetEntity()->GetTextIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, GetTextRect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetTextRect)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxRect &rtn = pSelf->GetEntity()->GetTextRect();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetValue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetValue)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetValue();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ComboCtrl, HidePopup)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, HidePopup)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->HidePopup();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, IsPopupShown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, IsPopupShown)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsPopupShown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, OnButtonClick)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, OnButtonClick)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->OnButtonClick();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, Paste)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, Paste)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Paste();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, Remove)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, Remove)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pSelf->GetEntity()->Remove(from, to);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, Replace)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, Replace)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	wxString value = wxString::FromUTF8(args.GetString(2));
	pSelf->GetEntity()->Replace(from, to, value);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetButtonBitmaps)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bmpNormal", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "pushButtonBg", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bmpPressed", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bmpHover", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bmpDisabled", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, SetButtonBitmaps)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBitmap *bmpNormal = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	bool pushButtonBg = false;
	if (args.IsValid(1)) pushButtonBg = args.GetBoolean(1);
	wxBitmap *bmpPressed = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(2)) bmpPressed = Object_wx_Bitmap::GetObject(args, 2)->GetEntity();
	wxBitmap *bmpHover = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(3)) bmpHover = Object_wx_Bitmap::GetObject(args, 3)->GetEntity();
	wxBitmap *bmpDisabled = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(4)) bmpDisabled = Object_wx_Bitmap::GetObject(args, 4)->GetEntity();
	pSelf->GetEntity()->SetButtonBitmaps(*bmpNormal, pushButtonBg, *bmpPressed, *bmpHover, *bmpDisabled);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetButtonPosition)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "side", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "spacingX", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, SetButtonPosition)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int width = -1;
	if (args.IsValid(0)) width = args.GetInt(0);
	int height = -1;
	if (args.IsValid(1)) height = args.GetInt(1);
	int side = wxRIGHT;
	if (args.IsValid(2)) side = args.GetInt(2);
	int spacingX = 0;
	if (args.IsValid(3)) spacingX = args.GetInt(3);
	pSelf->GetEntity()->SetButtonPosition(width, height, side, spacingX);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetCustomPaintWidth)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetCustomPaintWidth)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pSelf->GetEntity()->SetCustomPaintWidth(width);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetInsertionPoint)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetInsertionPoint)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	pSelf->GetEntity()->SetInsertionPoint(pos);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetInsertionPointEnd)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, SetInsertionPointEnd)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->SetInsertionPointEnd();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupAnchor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "anchorSide", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupAnchor)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int anchorSide = args.GetInt(0);
	pSelf->GetEntity()->SetPopupAnchor(anchorSide);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupControl)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "popup", VTYPE_wx_ComboPopup, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupControl)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxComboPopup *popup = Object_wx_ComboPopup::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetPopupControl(popup);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupExtents)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "extLeft", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "extRight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupExtents)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int extLeft = args.GetInt(0);
	int extRight = args.GetInt(1);
	pSelf->GetEntity()->SetPopupExtents(extLeft, extRight);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupMaxHeight)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupMaxHeight)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int height = args.GetInt(0);
	pSelf->GetEntity()->SetPopupMaxHeight(height);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupMinWidth)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupMinWidth)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pSelf->GetEntity()->SetPopupMinWidth(width);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetSelection)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetSelection)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pSelf->GetEntity()->SetSelection(from, to);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetText)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetText(value);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetTextIndent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetTextIndent)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int indent = args.GetInt(0);
	pSelf->GetEntity()->SetTextIndent(indent);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetValue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetValue)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetValue(value);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetValueWithEvent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "withEvent", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, SetValueWithEvent)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	bool withEvent = true;
	if (args.IsValid(1)) withEvent = args.GetBoolean(1);
	pSelf->GetEntity()->SetValueWithEvent(value, withEvent);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, ShowPopup)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, ShowPopup)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->ShowPopup();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, Undo)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, Undo)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Undo();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, UseAltPopupWindow)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, UseAltPopupWindow)
{
	Object_wx_ComboCtrl *pSelf = Object_wx_ComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	pSelf->GetEntity()->UseAltPopupWindow(enable);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxComboCtrl
//----------------------------------------------------------------------------
Object_wx_ComboCtrl::~Object_wx_ComboCtrl()
{
}

Object *Object_wx_ComboCtrl::Clone() const
{
	return NULL;
}

String Object_wx_ComboCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ComboCtrl:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ComboCtrl::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(AnimateShow);
	Gura_RealizeUserSymbol(DoShowPopup);
	Gura_AssignFunction(ComboCtrlEmpty);
	Gura_AssignFunction(ComboCtrl);
}

//----------------------------------------------------------------------------
// Class implementation for wxComboCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ComboCtrl)
{
	Gura_AssignMethod(wx_ComboCtrl, AnimateShow);
	Gura_AssignMethod(wx_ComboCtrl, Create);
	Gura_AssignMethod(wx_ComboCtrl, Copy);
	Gura_AssignMethod(wx_ComboCtrl, Cut);
	Gura_AssignMethod(wx_ComboCtrl, DoSetPopupControl);
	Gura_AssignMethod(wx_ComboCtrl, DoShowPopup);
	Gura_AssignMethod(wx_ComboCtrl, EnablePopupAnimation);
	Gura_AssignMethod(wx_ComboCtrl, GetBitmapDisabled);
	Gura_AssignMethod(wx_ComboCtrl, GetBitmapHover);
	Gura_AssignMethod(wx_ComboCtrl, GetBitmapNormal);
	Gura_AssignMethod(wx_ComboCtrl, GetBitmapPressed);
	Gura_AssignMethod(wx_ComboCtrl, GetButtonSize);
	Gura_AssignMethod(wx_ComboCtrl, GetCustomPaintWidth);
	Gura_AssignMethod(wx_ComboCtrl, GetFeatures);
	Gura_AssignMethod(wx_ComboCtrl, GetInsertionPoint);
	Gura_AssignMethod(wx_ComboCtrl, IsPopupWindowState);
	Gura_AssignMethod(wx_ComboCtrl, GetLastPosition);
	Gura_AssignMethod(wx_ComboCtrl, GetPopupControl);
	Gura_AssignMethod(wx_ComboCtrl, GetPopupWindow);
	Gura_AssignMethod(wx_ComboCtrl, GetTextCtrl);
	Gura_AssignMethod(wx_ComboCtrl, GetTextIndent);
	Gura_AssignMethod(wx_ComboCtrl, GetTextRect);
	Gura_AssignMethod(wx_ComboCtrl, GetValue);
	Gura_AssignMethod(wx_ComboCtrl, HidePopup);
	Gura_AssignMethod(wx_ComboCtrl, IsPopupShown);
	Gura_AssignMethod(wx_ComboCtrl, OnButtonClick);
	Gura_AssignMethod(wx_ComboCtrl, Paste);
	Gura_AssignMethod(wx_ComboCtrl, Remove);
	Gura_AssignMethod(wx_ComboCtrl, Replace);
	Gura_AssignMethod(wx_ComboCtrl, SetButtonBitmaps);
	Gura_AssignMethod(wx_ComboCtrl, SetButtonPosition);
	Gura_AssignMethod(wx_ComboCtrl, SetCustomPaintWidth);
	Gura_AssignMethod(wx_ComboCtrl, SetInsertionPoint);
	Gura_AssignMethod(wx_ComboCtrl, SetInsertionPointEnd);
	Gura_AssignMethod(wx_ComboCtrl, SetPopupAnchor);
	Gura_AssignMethod(wx_ComboCtrl, SetPopupControl);
	Gura_AssignMethod(wx_ComboCtrl, SetPopupExtents);
	Gura_AssignMethod(wx_ComboCtrl, SetPopupMaxHeight);
	Gura_AssignMethod(wx_ComboCtrl, SetPopupMinWidth);
	Gura_AssignMethod(wx_ComboCtrl, SetSelection);
	Gura_AssignMethod(wx_ComboCtrl, SetText);
	Gura_AssignMethod(wx_ComboCtrl, SetTextIndent);
	Gura_AssignMethod(wx_ComboCtrl, SetValue);
	Gura_AssignMethod(wx_ComboCtrl, SetValueWithEvent);
	Gura_AssignMethod(wx_ComboCtrl, ShowPopup);
	Gura_AssignMethod(wx_ComboCtrl, Undo);
	Gura_AssignMethod(wx_ComboCtrl, UseAltPopupWindow);
}

Gura_ImplementDescendantCreator(wx_ComboCtrl)
{
	return new Object_wx_ComboCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
