//----------------------------------------------------------------------------
// wxTopLevelWindow
// extracted from tlw.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

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
	//Gura::Signal *_pSig;
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
	inline void AssocWithGura(Object_wx_TopLevelWindow *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TopLevelWindow::~wx_TopLevelWindow()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TopLevelWindow::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTopLevelWindow
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TopLevelWindow, CanSetTransparent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, CanSetTransparent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanSetTransparent();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, CentreOnScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, CentreOnScreen)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int direction = wxBOTH;
	if (arg.IsValid(0)) direction = arg.GetInt(0);
	pThis->GetEntity()->CentreOnScreen(direction);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, EnableCloseButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, EnableCloseButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool enable = true;
	if (arg.IsValid(0)) enable = arg.GetBoolean(0);
	bool rtn = pThis->GetEntity()->EnableCloseButton(enable);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, GetDefaultItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, GetDefaultItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetDefaultItem();
	return ReturnValue(env, arg, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_TopLevelWindow, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, GetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxIcon &rtn = pThis->GetEntity()->GetIcon();
	return ReturnValue(env, arg, Value(new Object_wx_Icon(new wxIcon(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TopLevelWindow, GetIcons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, GetIcons)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxIconBundle &rtn = pThis->GetEntity()->GetIcons();
	return ReturnValue(env, arg, Value(new Object_wx_IconBundle(new wxIconBundle(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TopLevelWindow, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, GetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetTitle();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TopLevelWindow, HandleSettingChange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "wParam", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "lParam", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, HandleSettingChange)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	WXWPARAM wParam = static_cast<WXWPARAM>(arg.GetULong(0));
	WXLPARAM lParam = static_cast<WXLPARAM>(arg.GetULong(1));
	bool rtn = pThis->GetEntity()->HandleSettingChange(wParam, lParam);
	return ReturnValue(env, arg, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}

Gura_DeclareMethod(wx_TopLevelWindow, IsActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsActive)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsActive();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, IsAlwaysMaximized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsAlwaysMaximized)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsAlwaysMaximized();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, Iconize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "iconize", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, Iconize)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool iconize = arg.GetBoolean(0);
	pThis->GetEntity()->Iconize(iconize);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, IsFullScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsFullScreen)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsFullScreen();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, IsIconized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsIconized)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsIconized();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, IsMaximized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsMaximized)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsMaximized();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, IsUsingNativeDecorations)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsUsingNativeDecorations)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsUsingNativeDecorations();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, Maximize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "maximize", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, Maximize)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool maximize = arg.GetBoolean(0);
	pThis->GetEntity()->Maximize(maximize);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, RequestUserAttention)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, RequestUserAttention)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int flags = wxUSER_ATTENTION_INFO;
	if (arg.IsValid(0)) flags = arg.GetInt(0);
	pThis->GetEntity()->RequestUserAttention(flags);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetDefaultItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*win", VTYPE_wx_Window, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_TopLevelWindow, SetDefaultItem)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow **win = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetDefaultItem(**win);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxIcon *icon = Object_wx_Icon::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetIcon(*icon);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetIcons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icons", VTYPE_wx_IconBundle, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetIcons)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxIconBundle *icons = Object_wx_IconBundle::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetIcons(*icons);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetLeftMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "label", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "subMenu", VTYPE_wx_Menu, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_TopLevelWindow, SetLeftMenu)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = wxID_ANY;
	if (arg.IsValid(0)) id = arg.GetInt(0);
	wxString label = wxEmptyString;
	if (arg.IsValid(1)) label = wxString::FromUTF8(arg.GetString(1));
	wxMenu *subMenu = (wxMenu *)(nullptr);
	if (arg.IsValid(2)) subMenu = Object_wx_Menu::GetObject(arg, 2)->GetEntity();
	pThis->GetEntity()->SetLeftMenu(id, label, subMenu);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetMaxSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetMaxSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetMaxSize(*size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetMinSize(*size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetSizeHints)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "minW", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minH", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxW", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "maxH", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "incW", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "incH", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetSizeHints)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int minW = arg.GetInt(0);
	int minH = arg.GetInt(1);
	int maxW = -1;
	if (arg.IsValid(2)) maxW = arg.GetInt(2);
	int maxH = -1;
	if (arg.IsValid(3)) maxH = arg.GetInt(3);
	int incW = -1;
	if (arg.IsValid(4)) incW = arg.GetInt(4);
	int incH = -1;
	if (arg.IsValid(5)) incH = arg.GetInt(5);
	pThis->GetEntity()->SetSizeHints(minW, minH, maxW, maxH, incW, incH);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetSizeHints_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "minSize", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "maxSize", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "incSize", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetSizeHints_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *minSize = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	wxSize *maxSize = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(1)) maxSize = Object_wx_Size::GetObject(arg, 1)->GetEntity();
	wxSize *incSize = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(2)) incSize = Object_wx_Size::GetObject(arg, 2)->GetEntity();
	pThis->GetEntity()->SetSizeHints(*minSize, *maxSize, *incSize);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetRightMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "label", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "subMenu", VTYPE_wx_Menu, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_TopLevelWindow, SetRightMenu)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = wxID_ANY;
	if (arg.IsValid(0)) id = arg.GetInt(0);
	wxString label = wxEmptyString;
	if (arg.IsValid(1)) label = wxString::FromUTF8(arg.GetString(1));
	wxMenu *subMenu = (wxMenu *)(nullptr);
	if (arg.IsValid(2)) subMenu = Object_wx_Menu::GetObject(arg, 2)->GetEntity();
	pThis->GetEntity()->SetRightMenu(id, label, subMenu);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetShape)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetShape)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRegion *region = Object_wx_Region::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetShape(*region);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString title = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetTitle(title);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetTransparent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetTransparent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int alpha = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->SetTransparent(alpha);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, ShouldPreventAppExit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, ShouldPreventAppExit)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ShouldPreventAppExit();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, ShowFullScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TopLevelWindow, ShowFullScreen)
{
	Signal &sig = env.GetSignal();
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool show = arg.GetBoolean(0);
	long style = wxFULLSCREEN_ALL;
	if (arg.IsValid(1)) style = arg.GetLong(1);
	bool rtn = pThis->GetEntity()->ShowFullScreen(show, style);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TopLevelWindow, UseNativeDecorations)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "native", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_TopLevelWindow, UseNativeDecorations)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool native = ;
	if (arg.IsValid(0)) native = arg.GetBoolean(0);
	pThis->GetEntity()->UseNativeDecorations(native);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, UseNativeDecorationsByDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "native", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_TopLevelWindow, UseNativeDecorationsByDefault)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool native = ;
	if (arg.IsValid(0)) native = arg.GetBoolean(0);
	pThis->GetEntity()->UseNativeDecorationsByDefault(native);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxTopLevelWindow
//----------------------------------------------------------------------------
Object_wx_TopLevelWindow::~Object_wx_TopLevelWindow()
{
}

Object *Object_wx_TopLevelWindow::Clone() const
{
	return nullptr;
}

String Object_wx_TopLevelWindow::ToString(bool exprFlag)
{
	String rtn("<wx.TopLevelWindow:");
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
// Class implementation for wxTopLevelWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TopLevelWindow)
{
	Gura_RealizeUserSymbol(CanSetTransparent);
	Gura_RealizeUserSymbol(HandleSettingChange);
	Gura_RealizeUserSymbol(IsAlwaysMaximized);
	Gura_RealizeUserSymbol(SetSizeHints);
	Gura_RealizeUserSymbol(SetTitle);
	Gura_RealizeUserSymbol(SetTransparent);
	Gura_RealizeUserSymbol(ShouldPreventAppExit);
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
	return new Object_wx_TopLevelWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
