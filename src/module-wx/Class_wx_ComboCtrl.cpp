//----------------------------------------------------------------------------
// wxComboCtrl
// extracted from comboctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(AnimateShow);
Gura_DeclarePrivUserSymbol(DoShowPopup);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ComboCtrl: public wxComboCtrl, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ComboCtrl *_pObj;
public:
	inline wx_ComboCtrl() : wxComboCtrl(), _pObj(nullptr) {}
	inline wx_ComboCtrl(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxComboCtrl(parent, id, value, pos, size, style, validator, name), _pObj(nullptr) {}
	//virtual bool AnimateShow(const wxRect& rect, int flags);
	//virtual void DoShowPopup(const wxRect& rect, int flags);
	~wx_ComboCtrl();
	inline void AssocWithGura(Object_wx_ComboCtrl *pObj) {
		_pObj = pObj;
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
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ComboCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxComboCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(ComboCtrlEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ComboCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ComboCtrlEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ComboCtrl *pEntity = new wx_ComboCtrl();
	Object_wx_ComboCtrl *pObj = Object_wx_ComboCtrl::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ComboCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(ComboCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
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
	Object_wx_ComboCtrl *pObj = Object_wx_ComboCtrl::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ComboCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_ComboCtrl, AnimateShow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, AnimateShow)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	int flags = args.GetInt(1);
	bool rtn = dynamic_cast<wx_ComboCtrl *>(pThis->GetEntity())->_AnimateShow(*rect, flags);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
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
	bool rtn = pThis->GetEntity()->Create(parent, id, value, *pos, *size, style, *validator, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Copy();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, Cut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, Cut)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Cut();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, DoSetPopupControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "popup", VTYPE_wx_ComboPopup, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, DoSetPopupControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxComboPopup *popup = Object_wx_ComboPopup::GetObject(args, 0)->GetEntity();
	dynamic_cast<wx_ComboCtrl *>(pThis->GetEntity())->_DoSetPopupControl(popup);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, DoShowPopup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, DoShowPopup)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	int flags = args.GetInt(1);
	dynamic_cast<wx_ComboCtrl *>(pThis->GetEntity())->_DoShowPopup(*rect, flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, EnablePopupAnimation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, EnablePopupAnimation)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	pThis->GetEntity()->EnablePopupAnimation(enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, GetBitmapDisabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetBitmapDisabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmapDisabled();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetBitmapHover)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetBitmapHover)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmapHover();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetBitmapNormal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetBitmapNormal)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmapNormal();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetBitmapPressed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetBitmapPressed)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmapPressed();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetButtonSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetButtonSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetButtonSize();
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetCustomPaintWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetCustomPaintWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetCustomPaintWidth();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_ComboCtrl, GetFeatures)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ComboCtrl, GetFeatures)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int rtn = wxComboCtrl::GetFeatures();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, GetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetInsertionPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetInsertionPoint();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, IsPopupWindowState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, IsPopupWindowState)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int state = args.GetInt(0);
	bool rtn = pThis->GetEntity()->IsPopupWindowState(state);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, GetLastPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetLastPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetLastPosition();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, GetPopupControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetPopupControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxComboPopup *rtn = (wxComboPopup *)pThis->GetEntity()->GetPopupControl();
	return ReturnValue(env, args, Value(new Object_wx_ComboPopup(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetPopupWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetPopupWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetPopupWindow();
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTextCtrl *rtn = (wxTextCtrl *)pThis->GetEntity()->GetTextCtrl();
	return ReturnValue(env, args, Value(new Object_wx_TextCtrl(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetTextIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetTextIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->GetTextIndent();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, GetTextRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetTextRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxRect &rtn = pThis->GetEntity()->GetTextRect();
	return ReturnValue(env, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ComboCtrl, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ComboCtrl, HidePopup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, HidePopup)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->HidePopup();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, IsPopupShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, IsPopupShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsPopupShown();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboCtrl, OnButtonClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, OnButtonClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->OnButtonClick();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, Paste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, Paste)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Paste();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pThis->GetEntity()->Remove(from, to);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, Replace)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	wxString value = wxString::FromUTF8(args.GetString(2));
	pThis->GetEntity()->Replace(from, to, value);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetButtonBitmaps)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bmpNormal", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "pushButtonBg", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bmpPressed", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bmpHover", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bmpDisabled", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, SetButtonBitmaps)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bmpNormal = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	bool pushButtonBg = false;
	if (args.IsValid(1)) pushButtonBg = args.GetBoolean(1);
	wxBitmap *bmpPressed = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(2)) bmpPressed = Object_wx_Bitmap::GetObject(args, 2)->GetEntity();
	wxBitmap *bmpHover = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(3)) bmpHover = Object_wx_Bitmap::GetObject(args, 3)->GetEntity();
	wxBitmap *bmpDisabled = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(4)) bmpDisabled = Object_wx_Bitmap::GetObject(args, 4)->GetEntity();
	pThis->GetEntity()->SetButtonBitmaps(*bmpNormal, pushButtonBg, *bmpPressed, *bmpHover, *bmpDisabled);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetButtonPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "side", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "spacingX", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, SetButtonPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = -1;
	if (args.IsValid(0)) width = args.GetInt(0);
	int height = -1;
	if (args.IsValid(1)) height = args.GetInt(1);
	int side = wxRIGHT;
	if (args.IsValid(2)) side = args.GetInt(2);
	int spacingX = 0;
	if (args.IsValid(3)) spacingX = args.GetInt(3);
	pThis->GetEntity()->SetButtonPosition(width, height, side, spacingX);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetCustomPaintWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetCustomPaintWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetCustomPaintWidth(width);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetInsertionPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	pThis->GetEntity()->SetInsertionPoint(pos);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetInsertionPointEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, SetInsertionPointEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->SetInsertionPointEnd();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "anchorSide", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupAnchor)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int anchorSide = args.GetInt(0);
	pThis->GetEntity()->SetPopupAnchor(anchorSide);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "popup", VTYPE_wx_ComboPopup, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxComboPopup *popup = Object_wx_ComboPopup::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPopupControl(popup);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupExtents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "extLeft", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "extRight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupExtents)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int extLeft = args.GetInt(0);
	int extRight = args.GetInt(1);
	pThis->GetEntity()->SetPopupExtents(extLeft, extRight);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupMaxHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupMaxHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int height = args.GetInt(0);
	pThis->GetEntity()->SetPopupMaxHeight(height);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupMinWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupMinWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetPopupMinWidth(width);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pThis->GetEntity()->SetSelection(from, to);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetText(value);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetTextIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetTextIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int indent = args.GetInt(0);
	pThis->GetEntity()->SetTextIndent(indent);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetValue(value);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, SetValueWithEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "withEvent", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, SetValueWithEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	bool withEvent = true;
	if (args.IsValid(1)) withEvent = args.GetBoolean(1);
	pThis->GetEntity()->SetValueWithEvent(value, withEvent);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, ShowPopup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, ShowPopup)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ShowPopup();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, Undo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, Undo)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Undo();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboCtrl, UseAltPopupWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboCtrl, UseAltPopupWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	pThis->GetEntity()->UseAltPopupWindow(enable);
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
	return nullptr;
}

String Object_wx_ComboCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.ComboCtrl:");
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
// Class implementation for wxComboCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ComboCtrl)
{
	Gura_RealizeUserSymbol(AnimateShow);
	Gura_RealizeUserSymbol(DoShowPopup);
	Gura_AssignFunction(ComboCtrlEmpty);
	Gura_AssignFunction(ComboCtrl);
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
	return new Object_wx_ComboCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
