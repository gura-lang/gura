//----------------------------------------------------------------------------
// wxTopLevelWindow
// extracted from tlw.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(CanSetTransparent);
Gura_DeclarePrivUserSymbol(HandleSettingChange);
Gura_DeclarePrivUserSymbol(IsAlwaysMaximized);
Gura_DeclarePrivUserSymbol(SetSizeHints);
Gura_DeclarePrivUserSymbol(SetTitle);
Gura_DeclarePrivUserSymbol(SetTransparent);
Gura_DeclarePrivUserSymbol(ShouldPreventAppExit);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TopLevelWindow: public wxTopLevelWindow, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TopLevelWindow *_pObj;
public:
	//virtual bool CanSetTransparent();
	//virtual bool HandleSettingChange(WXWPARAM wParam, WXLPARAM lParam);
	//virtual bool IsAlwaysMaximized();
	//virtual void SetSizeHints(int minW, int minH, int maxW, int maxH, int incW, int incH);
	//virtual void SetTitle(const wxString& title);
	//virtual bool SetTransparent(int alpha);
	//virtual bool ShouldPreventAppExit();
	~wx_TopLevelWindow();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TopLevelWindow *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TopLevelWindow::~wx_TopLevelWindow()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TopLevelWindow::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTopLevelWindow
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TopLevelWindow, CanSetTransparent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, CanSetTransparent)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanSetTransparent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, CentreOnScreen)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, CentreOnScreen)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int direction = wxBOTH;
	if (args.IsValid(0)) direction = args.GetInt(0);
	pThis->GetEntity()->CentreOnScreen(direction);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, EnableCloseButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, EnableCloseButton)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->EnableCloseButton(enable);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, GetDefaultItem)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, GetDefaultItem)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetDefaultItem();
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_TopLevelWindow, GetIcon)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, GetIcon)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxIcon &rtn = pThis->GetEntity()->GetIcon();
	return ReturnValue(env, sig, args, Value(new Object_wx_Icon(new wxIcon(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TopLevelWindow, GetIcons)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, GetIcons)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxIconBundle &rtn = pThis->GetEntity()->GetIcons();
	return ReturnValue(env, sig, args, Value(new Object_wx_IconBundle(new wxIconBundle(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TopLevelWindow, GetTitle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, GetTitle)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetTitle();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TopLevelWindow, HandleSettingChange)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "wParam", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "lParam", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, HandleSettingChange)
{
#if defined(__WXMSW__)
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	WXWPARAM wParam = static_cast<WXWPARAM>(args.GetULong(0));
	WXLPARAM lParam = static_cast<WXLPARAM>(args.GetULong(1));
	bool rtn = pThis->GetEntity()->HandleSettingChange(wParam, lParam);
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_TopLevelWindow, IsActive)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsActive)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsActive();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, IsAlwaysMaximized)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsAlwaysMaximized)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsAlwaysMaximized();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, Iconize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "iconize", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, Iconize)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool iconize = args.GetBoolean(0);
	pThis->GetEntity()->Iconize(iconize);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, IsFullScreen)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsFullScreen)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsFullScreen();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, IsIconized)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsIconized)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsIconized();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, IsMaximized)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsMaximized)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsMaximized();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, IsUsingNativeDecorations)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsUsingNativeDecorations)
{
#if 0
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsUsingNativeDecorations();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, Maximize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "maximize", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, Maximize)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool maximize = args.GetBoolean(0);
	pThis->GetEntity()->Maximize(maximize);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, RequestUserAttention)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, RequestUserAttention)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = wxUSER_ATTENTION_INFO;
	if (args.IsValid(0)) flags = args.GetInt(0);
	pThis->GetEntity()->RequestUserAttention(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetDefaultItem)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*win", VTYPE_wx_Window, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_TopLevelWindow, SetDefaultItem)
{
#if 0
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow **win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDefaultItem(**win);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetIcon)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetIcon)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxIcon *icon = Object_wx_Icon::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetIcon(*icon);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetIcons)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icons", VTYPE_wx_IconBundle, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetIcons)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxIconBundle *icons = Object_wx_IconBundle::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetIcons(*icons);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetLeftMenu)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "label", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "subMenu", VTYPE_wx_Menu, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_TopLevelWindow, SetLeftMenu)
{
#if 0
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = wxID_ANY;
	if (args.IsValid(0)) id = args.GetInt(0);
	wxString label = wxEmptyString;
	if (args.IsValid(1)) label = wxString::FromUTF8(args.GetString(1));
	wxMenu *subMenu = (wxMenu *)(NULL);
	if (args.IsValid(2)) subMenu = Object_wx_Menu::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->SetLeftMenu(id, label, subMenu);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetMaxSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetMaxSize)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetMaxSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetMinSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetMinSize)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetMinSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetSizeHints)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "minW", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minH", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxW", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "maxH", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "incW", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "incH", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetSizeHints)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int minW = args.GetInt(0);
	int minH = args.GetInt(1);
	int maxW = -1;
	if (args.IsValid(2)) maxW = args.GetInt(2);
	int maxH = -1;
	if (args.IsValid(3)) maxH = args.GetInt(3);
	int incW = -1;
	if (args.IsValid(4)) incW = args.GetInt(4);
	int incH = -1;
	if (args.IsValid(5)) incH = args.GetInt(5);
	pThis->GetEntity()->SetSizeHints(minW, minH, maxW, maxH, incW, incH);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetSizeHints_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "minSize", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "maxSize", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "incSize", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetSizeHints_1)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *minSize = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxSize *maxSize = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(1)) maxSize = Object_wx_Size::GetObject(args, 1)->GetEntity();
	wxSize *incSize = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(2)) incSize = Object_wx_Size::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->SetSizeHints(*minSize, *maxSize, *incSize);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetRightMenu)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "label", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "subMenu", VTYPE_wx_Menu, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_TopLevelWindow, SetRightMenu)
{
#if 0
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = wxID_ANY;
	if (args.IsValid(0)) id = args.GetInt(0);
	wxString label = wxEmptyString;
	if (args.IsValid(1)) label = wxString::FromUTF8(args.GetString(1));
	wxMenu *subMenu = (wxMenu *)(NULL);
	if (args.IsValid(2)) subMenu = Object_wx_Menu::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->SetRightMenu(id, label, subMenu);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetShape)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetShape)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetShape(*region);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, SetTitle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetTitle)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString title = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetTitle(title);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetTransparent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetTransparent)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int alpha = args.GetInt(0);
	bool rtn = pThis->GetEntity()->SetTransparent(alpha);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, ShouldPreventAppExit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, ShouldPreventAppExit)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ShouldPreventAppExit();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, ShowFullScreen)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, ShowFullScreen)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool show = args.GetBoolean(0);
	long style = wxFULLSCREEN_ALL;
	if (args.IsValid(1)) style = args.GetLong(1);
	bool rtn = pThis->GetEntity()->ShowFullScreen(show, style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, UseNativeDecorations)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "native", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_TopLevelWindow, UseNativeDecorations)
{
#if 0
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool native = ;
	if (args.IsValid(0)) native = args.GetBoolean(0);
	pThis->GetEntity()->UseNativeDecorations(native);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TopLevelWindow, UseNativeDecorationsByDefault)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "native", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_TopLevelWindow, UseNativeDecorationsByDefault)
{
#if 0
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool native = ;
	if (args.IsValid(0)) native = args.GetBoolean(0);
	pThis->GetEntity()->UseNativeDecorationsByDefault(native);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTopLevelWindow
//----------------------------------------------------------------------------
Object_wx_TopLevelWindow::~Object_wx_TopLevelWindow()
{
}

Object *Object_wx_TopLevelWindow::Clone() const
{
	return NULL;
}

String Object_wx_TopLevelWindow::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TopLevelWindow:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_TopLevelWindow::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(CanSetTransparent);
	Gura_RealizeUserSymbol(HandleSettingChange);
	Gura_RealizeUserSymbol(IsAlwaysMaximized);
	Gura_RealizeUserSymbol(SetSizeHints);
	Gura_RealizeUserSymbol(SetTitle);
	Gura_RealizeUserSymbol(SetTransparent);
	Gura_RealizeUserSymbol(ShouldPreventAppExit);
}

//----------------------------------------------------------------------------
// Class implementation for wxTopLevelWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TopLevelWindow)
{
	Gura_AssignMethod(wx_TopLevelWindow, CanSetTransparent);
	Gura_AssignMethod(wx_TopLevelWindow, CentreOnScreen);
	Gura_AssignMethod(wx_TopLevelWindow, EnableCloseButton);
	Gura_AssignMethod(wx_TopLevelWindow, GetDefaultItem);
	Gura_AssignMethod(wx_TopLevelWindow, GetIcon);
	Gura_AssignMethod(wx_TopLevelWindow, GetIcons);
	Gura_AssignMethod(wx_TopLevelWindow, GetTitle);
	Gura_AssignMethod(wx_TopLevelWindow, HandleSettingChange);
	Gura_AssignMethod(wx_TopLevelWindow, IsActive);
	Gura_AssignMethod(wx_TopLevelWindow, IsAlwaysMaximized);
	Gura_AssignMethod(wx_TopLevelWindow, Iconize);
	Gura_AssignMethod(wx_TopLevelWindow, IsFullScreen);
	Gura_AssignMethod(wx_TopLevelWindow, IsIconized);
	Gura_AssignMethod(wx_TopLevelWindow, IsMaximized);
	Gura_AssignMethod(wx_TopLevelWindow, IsUsingNativeDecorations);
	Gura_AssignMethod(wx_TopLevelWindow, Maximize);
	Gura_AssignMethod(wx_TopLevelWindow, RequestUserAttention);
	Gura_AssignMethod(wx_TopLevelWindow, SetDefaultItem);
	Gura_AssignMethod(wx_TopLevelWindow, SetIcon);
	Gura_AssignMethod(wx_TopLevelWindow, SetIcons);
	Gura_AssignMethod(wx_TopLevelWindow, SetLeftMenu);
	Gura_AssignMethod(wx_TopLevelWindow, SetMaxSize);
	Gura_AssignMethod(wx_TopLevelWindow, SetMinSize);
	Gura_AssignMethod(wx_TopLevelWindow, SetSizeHints);
	Gura_AssignMethod(wx_TopLevelWindow, SetSizeHints_1);
	Gura_AssignMethod(wx_TopLevelWindow, SetRightMenu);
	Gura_AssignMethod(wx_TopLevelWindow, SetShape);
	Gura_AssignMethod(wx_TopLevelWindow, SetTitle);
	Gura_AssignMethod(wx_TopLevelWindow, SetTransparent);
	Gura_AssignMethod(wx_TopLevelWindow, ShouldPreventAppExit);
	Gura_AssignMethod(wx_TopLevelWindow, ShowFullScreen);
	Gura_AssignMethod(wx_TopLevelWindow, UseNativeDecorations);
	Gura_AssignMethod(wx_TopLevelWindow, UseNativeDecorationsByDefault);
}

Gura_ImplementDescendantCreator(wx_TopLevelWindow)
{
	return new Object_wx_TopLevelWindow((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
