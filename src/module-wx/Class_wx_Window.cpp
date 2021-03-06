//----------------------------------------------------------------------------
// wxWindow
// extracted from window.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(AddChild);
Gura_DeclarePrivUserSymbol(CaptureMouse);
Gura_DeclarePrivUserSymbol(ClientToScreenXY);
Gura_DeclarePrivUserSymbol(ClientToScreen);
Gura_DeclarePrivUserSymbol(Destroy);
Gura_DeclarePrivUserSymbol(DestroyChildren);
Gura_DeclarePrivUserSymbol(DoGetBestSize);
Gura_DeclarePrivUserSymbol(DoUpdateWindowUI);
Gura_DeclarePrivUserSymbol(DragAcceptFiles);
Gura_DeclarePrivUserSymbol(Enable);
Gura_DeclarePrivUserSymbol(Fit);
Gura_DeclarePrivUserSymbol(FitInside);
Gura_DeclarePrivUserSymbol(Freeze);
Gura_DeclarePrivUserSymbol(GetBackgroundColour);
Gura_DeclarePrivUserSymbol(GetBackgroundStyle);
Gura_DeclarePrivUserSymbol(GetCharHeight);
Gura_DeclarePrivUserSymbol(GetCharWidth);
Gura_DeclarePrivUserSymbol(GetDefaultAttributes);
Gura_DeclarePrivUserSymbol(GetForegroundColour);
Gura_DeclarePrivUserSymbol(GetHelpTextAtPoint);
Gura_DeclarePrivUserSymbol(GetHelpText);
Gura_DeclarePrivUserSymbol(GetLabel);
Gura_DeclarePrivUserSymbol(GetMinSize);
Gura_DeclarePrivUserSymbol(GetName);
Gura_DeclarePrivUserSymbol(GetParent);
Gura_DeclarePrivUserSymbol(GetPosition);
Gura_DeclarePrivUserSymbol(GetRect);
Gura_DeclarePrivUserSymbol(GetScreenPosition);
Gura_DeclarePrivUserSymbol(GetScreenRect);
Gura_DeclarePrivUserSymbol(GetScrollPos);
Gura_DeclarePrivUserSymbol(GetScrollRange);
Gura_DeclarePrivUserSymbol(GetScrollThumb);
Gura_DeclarePrivUserSymbol(GetTextExtent);
Gura_DeclarePrivUserSymbol(GetUpdateRegion);
Gura_DeclarePrivUserSymbol(HasCapture);
Gura_DeclarePrivUserSymbol(HasMultiplePages);
Gura_DeclarePrivUserSymbol(HasScrollbar);
Gura_DeclarePrivUserSymbol(HasTransparentBackground);
Gura_DeclarePrivUserSymbol(IsDoubleBuffered);
Gura_DeclarePrivUserSymbol(IsEnabled);
Gura_DeclarePrivUserSymbol(IsFrozen);
Gura_DeclarePrivUserSymbol(IsRetained);
Gura_DeclarePrivUserSymbol(IsShown);
Gura_DeclarePrivUserSymbol(IsShownOnScreen);
Gura_DeclarePrivUserSymbol(MakeModal);
Gura_DeclarePrivUserSymbol(OnCommand);
Gura_DeclarePrivUserSymbol(OnClose);
Gura_DeclarePrivUserSymbol(OnInternalIdle);
Gura_DeclarePrivUserSymbol(Refresh);
Gura_DeclarePrivUserSymbol(ReleaseMouse);
Gura_DeclarePrivUserSymbol(RemoveChild);
Gura_DeclarePrivUserSymbol(Reparent);
Gura_DeclarePrivUserSymbol(ScreenToClient);
Gura_DeclarePrivUserSymbol(ScreenToClientXY);
Gura_DeclarePrivUserSymbol(ScrollLines);
Gura_DeclarePrivUserSymbol(ScrollPages);
Gura_DeclarePrivUserSymbol(ScrollWindow);
Gura_DeclarePrivUserSymbol(SetAcceleratorTable);
Gura_DeclarePrivUserSymbol(SetBackgroundColour);
Gura_DeclarePrivUserSymbol(SetBackgroundStyle);
Gura_DeclarePrivUserSymbol(SetClientSize);
Gura_DeclarePrivUserSymbol(SetClientSizeWH);
Gura_DeclarePrivUserSymbol(SetCursor);
Gura_DeclarePrivUserSymbol(SetInitialBestSize);
Gura_DeclarePrivUserSymbol(SetFocus);
Gura_DeclarePrivUserSymbol(SetFocusFromKbd);
Gura_DeclarePrivUserSymbol(SetForegroundColour);
Gura_DeclarePrivUserSymbol(SetHelpText);
Gura_DeclarePrivUserSymbol(SetLabel);
Gura_DeclarePrivUserSymbol(SetName);
Gura_DeclarePrivUserSymbol(SetPalette);
Gura_DeclarePrivUserSymbol(SetScrollbar);
Gura_DeclarePrivUserSymbol(SetScrollPage);
Gura_DeclarePrivUserSymbol(SetScrollPos);
Gura_DeclarePrivUserSymbol(SetScrollRange);
Gura_DeclarePrivUserSymbol(SetDimensions);
Gura_DeclarePrivUserSymbol(SetRect);
Gura_DeclarePrivUserSymbol(SetSizeWH);
Gura_DeclarePrivUserSymbol(SetSize);
Gura_DeclarePrivUserSymbol(SetThemeEnabled);
Gura_DeclarePrivUserSymbol(SetValidator);
Gura_DeclarePrivUserSymbol(SetVirtualSizeHints);
Gura_DeclarePrivUserSymbol(SetWindowStyleFlag);
Gura_DeclarePrivUserSymbol(ShouldInheritColours);
Gura_DeclarePrivUserSymbol(Show);
Gura_DeclarePrivUserSymbol(Thaw);
Gura_DeclarePrivUserSymbol(TransferDataFromWindow);
Gura_DeclarePrivUserSymbol(TransferDataToWindow);
Gura_DeclarePrivUserSymbol(Update);
Gura_DeclarePrivUserSymbol(UpdateWindowUI);
Gura_DeclarePrivUserSymbol(Validate);
Gura_DeclarePrivUserSymbol(WindowToClientSize);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Window: public wxWindow, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Window *_pObj;
public:
	inline wx_Window() : wxWindow(), _pObj(nullptr) {}
	inline wx_Window(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxWindow(parent, id, pos, size, style, name), _pObj(nullptr) {}
	//virtual void AddChild(wxWindow* child);
	//virtual void CaptureMouse();
	//virtual void ClientToScreen(int* x, int* y);
	//virtual wxPoint ClientToScreen(const wxPoint& pt);
	//virtual bool Destroy();
	//virtual void DestroyChildren();
	//virtual wxSize DoGetBestSize();
	//virtual void DoUpdateWindowUI(wxUpdateUIEvent& event);
	//virtual void DragAcceptFiles(bool accept);
	//virtual bool Enable(bool enable);
	//virtual void Fit();
	//virtual void FitInside();
	//virtual void Freeze();
	//virtual wxColour GetBackgroundColour();
	//virtual wxBackgroundStyle GetBackgroundStyle();
	//virtual int GetCharHeight();
	//virtual int GetCharWidth();
	//virtual wxVisualAttributes GetDefaultAttributes();
	//virtual wxColour GetForegroundColour();
	//virtual wxString GetHelpTextAtPoint(const wxPoint & point, wxHelpEvent::Origin origin);
	//virtual wxString GetHelpText();
	//virtual wxString GetLabel();
	//virtual wxSize GetMinSize();
	//virtual wxString GetName();
	//virtual wxWindow* GetParent();
	//virtual void GetPosition(int* x, int* y);
	//virtual wxRect GetRect();
	//virtual void GetScreenPosition(int* x, int* y);
	//virtual wxRect GetScreenRect();
	//virtual int GetScrollPos(int orientation);
	//virtual int GetScrollRange(int orientation);
	//virtual int GetScrollThumb(int orientation);
	//virtual void GetTextExtent(const wxString& string, int* x, int* y, int* descent, int* externalLeading, const wxFont* font, bool use16);
	//virtual wxRegion GetUpdateRegion();
	//virtual bool HasCapture();
	//virtual bool HasMultiplePages();
	//virtual bool HasScrollbar(int orient);
	//virtual bool HasTransparentBackground();
	//virtual bool IsDoubleBuffered();
	//virtual bool IsEnabled();
	//virtual bool IsFrozen();
	//virtual bool IsRetained();
	//virtual bool IsShown();
	//virtual bool IsShownOnScreen();
	//virtual void MakeModal(bool flag);
	//virtual void OnCommand(wxEvtHandler& object, wxCommandEvent& event);
	//virtual bool OnClose();
	//virtual void OnInternalIdle();
	//virtual void Refresh(bool eraseBackground, const wxRect* rect);
	//virtual void ReleaseMouse();
	//virtual void RemoveChild(wxWindow* child);
	//virtual bool Reparent(wxWindow* newParent);
	//virtual void ScreenToClient(int* x, int* y);
	//virtual wxPoint ScreenToClient(const wxPoint& pt);
	//virtual bool ScrollLines(int lines);
	//virtual bool ScrollPages(int pages);
	//virtual void ScrollWindow(int dx, int dy, const wxRect* rect);
	//virtual void SetAcceleratorTable(const wxAcceleratorTable& accel);
	//virtual bool SetBackgroundColour(const wxColour& colour);
	//virtual void SetBackgroundStyle(wxBackgroundStyle style);
	//virtual void SetClientSize(int width, int height);
	//virtual void SetClientSize(const wxSize& size);
	//virtual void SetCursor(const wxCursor& cursor);
	//virtual void SetInitialBestSize(const wxSize& size);
	//virtual void SetFocus();
	//virtual void SetFocusFromKbd();
	//virtual void SetForegroundColour(const wxColour& colour);
	//virtual void SetHelpText(const wxString& helpText);
	//virtual void SetLabel(const wxString& label);
	//virtual void SetName(const wxString& name);
	//virtual void SetPalette(wxPalette* palette);
	//virtual void SetScrollbar(int orientation, int position, int thumbSize, int range, bool refresh);
	//virtual void SetScrollPage(int orientation, int pageSize, bool refresh);
	//virtual void SetScrollPos(int orientation, int pos, bool refresh);
	//virtual void SetScrollRange(int orientation, int range, bool refresh);
	//virtual void SetSize(int x, int y, int width, int height, int sizeFlags);
	//virtual void SetSize(const wxRect& rect);
	//virtual void SetSize(int width, int height);
	//virtual void SetSize(const wxSize& size);
	//virtual void SetThemeEnabled(bool enable);
	//virtual void SetValidator(const wxValidator& validator);
	//virtual void SetVirtualSizeHints(int minW, int minH, int maxW, int maxH);
	//virtual void SetWindowStyleFlag(long style);
	//virtual bool ShouldInheritColours();
	//virtual bool Show(bool show);
	//virtual void Thaw();
	virtual bool TransferDataFromWindow();
	virtual bool TransferDataToWindow();
	//virtual void Update();
	//virtual void UpdateWindowUI(long flags);
	//virtual bool Validate();
	//virtual wxSize WindowToClientSize(const wxSize& size);
	~wx_Window();
	inline void AssocWithGura(Object_wx_Window *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Window::~wx_Window()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Window::GuraObjectDeleted()
{
	_pObj = nullptr;
}

bool wx_Window::TransferDataFromWindow()
{
	bool evaluatedFlag;
	Value rtn = _pObj->EvalMethod(*_pObj,
		Gura_UserSymbol(TransferDataFromWindow), ValueList::Empty, evaluatedFlag);
	if (_pObj->GetSignal().IsSignalled()) {
		SetLogError(_pObj->GetSignal());
		return false;
	}
	return rtn.GetBoolean();
}

bool wx_Window::TransferDataToWindow()
{
	bool evaluatedFlag;
	Value rtn = _pObj->EvalMethod(*_pObj,
		Gura_UserSymbol(TransferDataToWindow), ValueList::Empty, evaluatedFlag);
	if (_pObj->GetSignal().IsSignalled()) {
		SetLogError(_pObj->GetSignal());
		return false;
	}
	return rtn.GetBoolean();
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(WindowEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Window));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WindowEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Window *pEntity = new wx_Window();
	Object_wx_Window *pObj = Object_wx_Window::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Window(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Window)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Window));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Window)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = 0;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxString name = wxPanelNameStr;
	if (arg.IsValid(5)) name = wxString::FromUTF8(arg.GetString(5));
	wx_Window *pEntity = new wx_Window(parent, id, *pos, *size, style, name);
	Object_wx_Window *pObj = Object_wx_Window::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Window(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_Window, AddChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "child", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, AddChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *child = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->AddChild(child);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, CacheBestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, CacheBestSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->CacheBestSize(*size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, CaptureMouse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, CaptureMouse)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->CaptureMouse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, Center)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, Center)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int direction = arg.GetInt(0);
	pThis->GetEntity()->Center(direction);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, CenterOnParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, CenterOnParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int direction = arg.GetInt(0);
	pThis->GetEntity()->CenterOnParent(direction);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, CenterOnScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, CenterOnScreen)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int direction = arg.GetInt(0);
	pThis->GetEntity()->CenterOnScreen(direction);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, Centre)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Centre)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int direction = wxBOTH;
	if (arg.IsValid(0)) direction = arg.GetInt(0);
	pThis->GetEntity()->Centre(direction);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, CentreOnParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, CentreOnParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int direction = wxBOTH;
	if (arg.IsValid(0)) direction = arg.GetInt(0);
	pThis->GetEntity()->CentreOnParent(direction);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, ClearBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, ClearBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->ClearBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, ClientToScreenXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, ClientToScreenXY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	pThis->GetEntity()->ClientToScreen(&x, &y);
	return ReturnValue(env, arg, Value::CreateList(env, x, y));
}

Gura_DeclareMethod(wx_Window, ClientToScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ClientToScreen)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	wxPoint rtn = pThis->GetEntity()->ClientToScreen(*pt);
	return ReturnValue(env, arg, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, ClientToWindowSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ClientToWindowSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	wxSize rtn = pThis->GetEntity()->ClientToWindowSize(*size);
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "force", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Close)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool force = false;
	if (arg.IsValid(0)) force = arg.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Close(force);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, ConvertDialogPointToPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ConvertDialogPointToPixels)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	wxPoint rtn = pThis->GetEntity()->ConvertDialogToPixels(*pt);
	return ReturnValue(env, arg, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, ConvertDialogSizeToPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ConvertDialogSizeToPixels)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *sz = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	wxSize rtn = pThis->GetEntity()->ConvertDialogToPixels(*sz);
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, ConvertPixelPointToDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ConvertPixelPointToDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	wxPoint rtn = pThis->GetEntity()->ConvertPixelsToDialog(*pt);
	return ReturnValue(env, arg, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, ConvertPixelSizeToDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ConvertPixelSizeToDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *sz = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	wxSize rtn = pThis->GetEntity()->ConvertPixelsToDialog(*sz);
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, Destroy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Destroy)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Destroy();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, DestroyChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, DestroyChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->DestroyChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, Disable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Disable)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Disable();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, DoGetBestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, DoGetBestSize)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->DoGetBestSize();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, DoUpdateWindowUI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_UpdateUIEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, DoUpdateWindowUI)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxUpdateUIEvent *event = Object_wx_UpdateUIEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->DoUpdateWindowUI(*event);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, DragAcceptFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "accept", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, DragAcceptFiles)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool accept = arg.GetBoolean(0);
	pThis->GetEntity()->DragAcceptFiles(accept);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Enable)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool enable = true;
	if (arg.IsValid(0)) enable = arg.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Enable(enable);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareClassMethod(wx_Window, FindFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Window, FindFocus)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)wxWindow::FindFocus();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, FindWindowById)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, FindWindowById)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long id = arg.GetLong(0);
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->FindWindow(id);
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, FindWindowByName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, FindWindowByName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->FindWindow(name);
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

#if 0
Gura_DeclareClassMethod(wx_Window, FindWindowById)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Window, FindWindowById)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	long id = arg.GetLong(0);
	wxWindow *parent = (wxWindow *)(nullptr);
	if (arg.IsValid(1)) parent = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxWindow::FindWindowById(id, parent);
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}
#endif

Gura_DeclareClassMethod(wx_Window, FindWindowByLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Window, FindWindowByLabel)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString label = wxString::FromUTF8(arg.GetString(0));
	wxWindow *parent = (wxWindow *)(nullptr);
	if (arg.IsValid(1)) parent = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxWindow::FindWindowByLabel(label, parent);
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

#if 0
Gura_DeclareClassMethod(wx_Window, FindWindowByName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Window, FindWindowByName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxWindow *parent = (wxWindow *)(nullptr);
	if (arg.IsValid(1)) parent = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxWindow::FindWindowByName(name, parent);
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}
#endif

Gura_DeclareMethod(wx_Window, Fit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, Fit)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Fit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, FitInside)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, FitInside)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->FitInside();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, Freeze)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, Freeze)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Freeze();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetAcceleratorTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetAcceleratorTable)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAcceleratorTable *rtn = (wxAcceleratorTable *)pThis->GetEntity()->GetAcceleratorTable();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_AcceleratorTable(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetAccessible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetAccessible)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAccessible *rtn = (wxAccessible *)pThis->GetEntity()->GetAccessible();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Accessible(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetAdjustedBestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetAdjustedBestSize)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetAdjustedBestSize();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour rtn = pThis->GetEntity()->GetBackgroundColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetBackgroundStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetBackgroundStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBackgroundStyle rtn = pThis->GetEntity()->GetBackgroundStyle();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetEffectiveMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetEffectiveMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetEffectiveMinSize();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetBestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetBestSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetBestSize();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_Window, GetCapture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Window, GetCapture)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)wxWindow::GetCapture();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetCaret)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetCaret)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCaret *rtn = (wxCaret *)pThis->GetEntity()->GetCaret();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Caret(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetCharHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetCharHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetCharHeight();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetCharWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetCharWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetCharWidth();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindowList &rtn = pThis->GetEntity()->GetChildren();
	Value result;
	Object_list *pObjList = result.InitAsList(env);
	pObjList->Reserve(rtn.size());
	foreach (wxWindowList, ppWindow, rtn) {
		wxWindow *pWindow = *ppWindow;
		pObjList->Add(Value(new Object_wx_Window(pWindow, nullptr, OwnerFalse)));
	}
	return result;
}

Gura_DeclareClassMethod(wx_Window, GetClassDefaultAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "variant", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Window, GetClassDefaultAttributes)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL;
	if (arg.IsValid(0)) variant = static_cast<wxWindowVariant>(arg.GetInt(0));
	wxVisualAttributes rtn = wxWindow::GetClassDefaultAttributes(variant);
	return ReturnValue(env, arg, Value(new Object_wx_VisualAttributes(new wxVisualAttributes(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetClientSizeWH)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetClientSizeWH)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width;
	int height;
	pThis->GetEntity()->GetClientSize(&width, &height);
	return ReturnValue(env, arg, Value::CreateList(env, width, height));
}

Gura_DeclareMethod(wx_Window, GetClientSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetClientSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetClientSize();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetConstraints)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetConstraints)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLayoutConstraints *rtn = (wxLayoutConstraints *)pThis->GetEntity()->GetConstraints();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_LayoutConstraints(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetContainingSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetContainingSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizer *rtn = (wxSizer *)pThis->GetEntity()->GetContainingSizer();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Sizer(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetCursor)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxCursor &rtn = pThis->GetEntity()->GetCursor();
	return ReturnValue(env, arg, Value(new Object_wx_Cursor(new wxCursor(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetDefaultAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetDefaultAttributes)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxVisualAttributes rtn = pThis->GetEntity()->GetDefaultAttributes();
	return ReturnValue(env, arg, Value(new Object_wx_VisualAttributes(new wxVisualAttributes(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetDropTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetDropTarget)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDropTarget *rtn = (wxDropTarget *)pThis->GetEntity()->GetDropTarget();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_DropTarget(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetEventHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetEventHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxEvtHandler *rtn = (wxEvtHandler *)pThis->GetEntity()->GetEventHandler();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_EvtHandler(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetExtraStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetExtraStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetExtraStyle();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont rtn = pThis->GetEntity()->GetFont();
	return ReturnValue(env, arg, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetForegroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetForegroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour rtn = pThis->GetEntity()->GetForegroundColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetGrandParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetGrandParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetGrandParent();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetHandle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	void *rtn = pThis->GetEntity()->GetHandle();
	Value value;
	if (rtn != nullptr) value = Value(reinterpret_cast<size_t>(rtn));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetHelpTextAtPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "origin", VTYPE_wx_HelpEvent, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetHelpTextAtPoint)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *point = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	wxHelpEvent *origin = Object_wx_HelpEvent::GetObject(arg, 1)->GetEntity();
	wxString rtn = pThis->GetEntity()->GetHelpTextAtPoint(*point, *origin);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetHelpText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetHelpText)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetHelpText();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Window, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetId();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetLabel();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Window, GetMaxSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetMaxSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetMaxSize();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetMinSize();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Window, GetNextSibling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetNextSibling)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetNextSibling();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetParent();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetPositionXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetPositionXY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x;
	int y;
	pThis->GetEntity()->GetPosition(&x, &y);
	return ReturnValue(env, arg, Value::CreateList(env, x, y));
}

Gura_DeclareMethod(wx_Window, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, arg, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetPrevSibling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetPrevSibling)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetPrevSibling();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect rtn = pThis->GetEntity()->GetRect();
	return ReturnValue(env, arg, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetScreenPositionXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetScreenPositionXY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x;
	int y;
	pThis->GetEntity()->GetScreenPosition(&x, &y);
	return ReturnValue(env, arg, Value::CreateList(env, x, y));
}

Gura_DeclareMethod(wx_Window, GetScreenPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetScreenPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint rtn = pThis->GetEntity()->GetScreenPosition();
	return ReturnValue(env, arg, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetScreenRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetScreenRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect rtn = pThis->GetEntity()->GetScreenRect();
	return ReturnValue(env, arg, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetScrollPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetScrollPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int orientation = arg.GetInt(0);
	int rtn = pThis->GetEntity()->GetScrollPos(orientation);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetScrollRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetScrollRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int orientation = arg.GetInt(0);
	int rtn = pThis->GetEntity()->GetScrollRange(orientation);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetScrollThumb)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetScrollThumb)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int orientation = arg.GetInt(0);
	int rtn = pThis->GetEntity()->GetScrollThumb(orientation);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetSizeWH)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetSizeWH)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width;
	int height;
	pThis->GetEntity()->GetSize(&width, &height);
	return ReturnValue(env, arg, Value::CreateList(env, width, height));
}

Gura_DeclareMethod(wx_Window, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizer *rtn = (wxSizer *)pThis->GetEntity()->GetSizer();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Sizer(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetTextExtent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetTextExtent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString string = wxString::FromUTF8(arg.GetString(0));
	wxFont *font = (wxFont *)(nullptr);
	if (arg.IsValid(1)) font = Object_wx_Font::GetObject(arg, 1)->GetEntity();
	int x;
	int y;
	int descent;
	int externalLeading;
	pThis->GetEntity()->GetTextExtent(string, &x, &y, &descent, &externalLeading, font);
	return ReturnValue(env, arg, Value::CreateList(env, x, y, descent, externalLeading));
}

Gura_DeclareMethod(wx_Window, GetToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetToolTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxToolTip *rtn = (wxToolTip *)pThis->GetEntity()->GetToolTip();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_ToolTip(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetUpdateRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetUpdateRegion)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRegion rtn = pThis->GetEntity()->GetUpdateRegion();
	return ReturnValue(env, arg, Value(new Object_wx_Region(new wxRegion(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetValidator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetValidator)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxValidator *rtn = (wxValidator *)pThis->GetEntity()->GetValidator();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Validator(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, GetVirtualSizeWH)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetVirtualSizeWH)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width;
	int height;
	pThis->GetEntity()->GetVirtualSize(&width, &height);
	return ReturnValue(env, arg, Value::CreateList(env, width, height));
}

Gura_DeclareMethod(wx_Window, GetVirtualSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetVirtualSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetVirtualSize();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetWindowBorderSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetWindowBorderSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetWindowBorderSize();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetWindowStyleFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetWindowStyleFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetWindowStyleFlag();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetWindowVariant)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetWindowVariant)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindowVariant rtn = pThis->GetEntity()->GetWindowVariant();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, HasCapture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, HasCapture)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasCapture();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, HasFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, HasFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int flag = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->HasFlag(flag);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, HasMultiplePages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, HasMultiplePages)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasMultiplePages();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, HasScrollbar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, HasScrollbar)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int orient = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->HasScrollbar(orient);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, HasTransparentBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, HasTransparentBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasTransparentBackground();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, Hide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Hide)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Hide();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, InheritAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, InheritAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->InheritAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, InitDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, InitDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->InitDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, InvalidateBestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, InvalidateBestSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->InvalidateBestSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, IsDoubleBuffered)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsDoubleBuffered)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsDoubleBuffered();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsEnabled();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsExposed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "h", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsExposed)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	bool rtn = false;
	if (arg.Is_number(2) && arg.Is_number(3)) {
		int w = arg.GetInt(2);
		int h = arg.GetInt(3);
		rtn = pThis->GetEntity()->IsExposed(x, y, w, h);
	} else {
		rtn = pThis->GetEntity()->IsExposed(x, y);
	}
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsExposedPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsExposedPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsExposed(*pt);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsExposedRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsExposedRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsExposed(*rect);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsFrozen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsFrozen)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsFrozen();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsRetained)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsRetained)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsRetained();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsShown();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsShownOnScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsShownOnScreen)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsShownOnScreen();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsTopLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsTopLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsTopLevel();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, Layout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, Layout)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, Lower)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, Lower)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Lower();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, MakeModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, MakeModal)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool flag = arg.GetBoolean(0);
	pThis->GetEntity()->MakeModal(flag);
	return Value::Nil;
#endif
	SetError_Obsolete(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, MoveXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, MoveXY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	pThis->GetEntity()->Move(x, y);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, Move)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, Move)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->Move(*pt);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, MoveAfterInTabOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, MoveAfterInTabOrder)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *win = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->MoveAfterInTabOrder(win);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, MoveBeforeInTabOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, MoveBeforeInTabOrder)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *win = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->MoveBeforeInTabOrder(win);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, Navigate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Navigate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int flags = wxNavigationKeyEvent::IsForward;
	if (arg.IsValid(0)) flags = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->Navigate(flags);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, OnActivate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_ActivateEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnActivate)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxActivateEvent *event = Object_wx_ActivateEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnActivate(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnChar)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnChar(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnCharHook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnCharHook)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnCharHook(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "object", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnCommand)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxEvtHandler *object = Object_wx_EvtHandler::GetObject(arg, 0)->GetEntity();
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->OnCommand(*object, *event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnClose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, OnClose)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->OnClose();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnKeyDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnKeyDown)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnKeyDown(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnKeyUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnKeyUp)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnKeyUp(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnInitDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_InitDialogEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnInitDialog)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxInitDialogEvent *event = Object_wx_InitDialogEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnInitDialog(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnMenuHighlight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_MenuEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnMenuHighlight)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenuEvent *event = Object_wx_MenuEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnMenuHighlight(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnMouseEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_MouseEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnMouseEvent)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMouseEvent *event = Object_wx_MouseEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnMouseEvent(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnMove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_MoveEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnMove)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMoveEvent *event = Object_wx_MoveEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnMove(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnPaint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_PaintEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnPaint)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPaintEvent *event = Object_wx_PaintEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnPaint(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnScroll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_ScrollWinEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnScroll)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxScrollWinEvent *event = Object_wx_ScrollWinEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnScroll(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnSetFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_FocusEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnSetFocus)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFocusEvent *event = Object_wx_FocusEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnSetFocus(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_SizeEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnSize)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizeEvent *event = Object_wx_SizeEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnSize(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnSysColourChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_OnSysColourChangedEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnSysColourChanged)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxOnSysColourChangedEvent *event = Object_wx_OnSysColourChangedEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnSysColourChanged(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, OnInternalIdle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, OnInternalIdle)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->OnInternalIdle();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, PopEventHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "deleteHandler", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, PopEventHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool deleteHandler = false;
	if (arg.IsValid(0)) deleteHandler = arg.GetBoolean(0);
	wxEvtHandler *rtn = (wxEvtHandler *)pThis->GetEntity()->PopEventHandler(deleteHandler);
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_EvtHandler(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Window, PopupMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, PopupMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenu *menu = Object_wx_Menu::GetObject(arg, 0)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(1)) pos = Object_wx_Point::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->PopupMenu(menu, *pos);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, PopupMenuXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, PopupMenuXY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenu *menu = Object_wx_Menu::GetObject(arg, 0)->GetEntity();
	int x = arg.GetInt(1);
	int y = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->PopupMenu(menu, x, y);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, PushEventHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_EvtHandler, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, PushEventHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxEvtHandler *handler = Object_wx_EvtHandler::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->PushEventHandler(handler);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, Raise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, Raise)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Raise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, Refresh)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "eraseBackground", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Refresh)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool eraseBackground = true;
	if (arg.IsValid(0)) eraseBackground = arg.GetBoolean(0);
	wxRect *rect = (wxRect *)(nullptr);
	if (arg.IsValid(1)) rect = Object_wx_Rect::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->Refresh(eraseBackground, rect);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, RefreshRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "eraseBackground", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, RefreshRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(arg, 0)->GetEntity();
	bool eraseBackground = true;
	if (arg.IsValid(1)) eraseBackground = arg.GetBoolean(1);
	pThis->GetEntity()->RefreshRect(*rect, eraseBackground);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, RegisterHotKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hotkeyId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "modifiers", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "virtualKeyCode", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, RegisterHotKey)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int hotkeyId = arg.GetInt(0);
	int modifiers = arg.GetInt(1);
	int virtualKeyCode = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->RegisterHotKey(hotkeyId, modifiers, virtualKeyCode);
	return ReturnValue(env, arg, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}

Gura_DeclareMethod(wx_Window, ReleaseMouse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, ReleaseMouse)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->ReleaseMouse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, RemoveChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "child", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, RemoveChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *child = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->RemoveChild(child);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, RemoveEventHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, RemoveEventHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxEvtHandler *handler = Object_wx_EvtHandler::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->RemoveEventHandler(handler);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, Reparent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "newParent", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Reparent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *newParent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Reparent(newParent);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, ScreenToClientXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ScreenToClientXY)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	pThis->GetEntity()->ScreenToClient(&x, &y);
	return ReturnValue(env, arg, Value::CreateList(env, x, y));
}

Gura_DeclareMethod(wx_Window, ScreenToClient)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ScreenToClient)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	wxPoint rtn = pThis->GetEntity()->ScreenToClient(*pt);
	return ReturnValue(env, arg, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, ScrollLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lines", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ScrollLines)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int lines = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->ScrollLines(lines);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, ScrollPages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ScrollPages)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pages = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->ScrollPages(pages);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, ScrollWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ScrollWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int dx = arg.GetInt(0);
	int dy = arg.GetInt(1);
	wxRect *rect = (wxRect *)(nullptr);
	if (arg.IsValid(2)) rect = Object_wx_Rect::GetObject(arg, 2)->GetEntity();
	pThis->GetEntity()->ScrollWindow(dx, dy, rect);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetAcceleratorTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "accel", VTYPE_wx_AcceleratorTable, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetAcceleratorTable)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAcceleratorTable *accel = Object_wx_AcceleratorTable::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetAcceleratorTable(*accel);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetAccessible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "accessible", VTYPE_wx_Accessible, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, SetAccessible)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAccessible *accessible = Object_wx_Accessible::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetAccessible(accessible);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetAutoLayout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "autoLayout", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetAutoLayout)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool autoLayout = arg.GetBoolean(0);
	pThis->GetEntity()->SetAutoLayout(autoLayout);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetBackgroundColour(*colour);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, SetBackgroundStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetBackgroundStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBackgroundStyle style = static_cast<wxBackgroundStyle>(arg.GetInt(0));
	pThis->GetEntity()->SetBackgroundStyle(style);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetInitialSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetInitialSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(0)) size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetInitialSize(*size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetCaret)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "caret", VTYPE_wx_Caret, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetCaret)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCaret *caret = Object_wx_Caret::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetCaret(caret);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetClientSizeWH)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetClientSizeWH)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	pThis->GetEntity()->SetClientSize(width, height);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetClientSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetClientSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetClientSize(*size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetConstraints)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "constraints", VTYPE_wx_LayoutConstraints, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetConstraints)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLayoutConstraints *constraints = Object_wx_LayoutConstraints::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetConstraints(constraints);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetContainingSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizer", VTYPE_wx_Sizer, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetContainingSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetContainingSizer(sizer);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetCursor)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCursor *cursor = Object_wx_Cursor::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetCursor(*cursor);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetDropTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_wx_DropTarget, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetDropTarget)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDropTarget *target = Object_wx_DropTarget::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetDropTarget(target);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetInitialBestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, SetInitialBestSize)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetInitialBestSize(*size);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetEventHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_EvtHandler, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetEventHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxEvtHandler *handler = Object_wx_EvtHandler::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetEventHandler(handler);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetExtraStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "exStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetExtraStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long exStyle = arg.GetLong(0);
	pThis->GetEntity()->SetExtraStyle(exStyle);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, SetFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->SetFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetFocusFromKbd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, SetFocusFromKbd)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->SetFocusFromKbd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetForegroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetForegroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetForegroundColour(*colour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetHelpText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "helpText", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetHelpText)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString helpText = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetHelpText(helpText);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	pThis->GetEntity()->SetId(id);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString label = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetLabel(label);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetMaxSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetMaxSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetMaxSize(*size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetMinSize(*size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetName(name);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetOwnBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetOwnBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetOwnBackgroundColour(*colour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetOwnFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetOwnFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetOwnFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetOwnForegroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetOwnForegroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetOwnForegroundColour(*colour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetPalette)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, SetPalette)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPalette *palette = Object_wx_Palette::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetPalette(palette);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetScrollbar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "thumbSize", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "refresh", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetScrollbar)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int orientation = arg.GetInt(0);
	int position = arg.GetInt(1);
	int thumbSize = arg.GetInt(2);
	int range = arg.GetInt(3);
	bool refresh = true;
	if (arg.IsValid(4)) refresh = arg.GetBoolean(4);
	pThis->GetEntity()->SetScrollbar(orientation, position, thumbSize, range, refresh);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetScrollPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pageSize", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "refresh", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_Window, SetScrollPage)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int orientation = arg.GetInt(0);
	int pageSize = arg.GetInt(1);
	bool refresh = true;
	if (arg.IsValid(2)) refresh = arg.GetBoolean(2);
	pThis->GetEntity()->SetScrollPage(orientation, pageSize, refresh);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetScrollPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "refresh", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetScrollPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int orientation = arg.GetInt(0);
	int pos = arg.GetInt(1);
	bool refresh = true;
	if (arg.IsValid(2)) refresh = arg.GetBoolean(2);
	pThis->GetEntity()->SetScrollPos(orientation, pos, refresh);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetScrollRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "refresh", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_Window, SetScrollRange)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int orientation = arg.GetInt(0);
	int range = arg.GetInt(1);
	bool refresh = true;
	if (arg.IsValid(2)) refresh = arg.GetBoolean(2);
	pThis->GetEntity()->SetScrollRange(orientation, range, refresh);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetDimensions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sizeFlags", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetDimensions)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	int width = arg.GetInt(2);
	int height = arg.GetInt(3);
	int sizeFlags = wxSIZE_AUTO;
	if (arg.IsValid(4)) sizeFlags = arg.GetInt(4);
	pThis->GetEntity()->SetSize(x, y, width, height, sizeFlags);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetSize(*rect);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetSizeWH)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetSizeWH)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	pThis->GetEntity()->SetSize(width, height);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetSize(*size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizer", VTYPE_wx_Sizer, OCCUR_Once);
	DeclareArg(env, "deleteOld", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
	bool deleteOld = true;
	if (arg.IsValid(1)) deleteOld = arg.GetBoolean(1);
	pThis->GetEntity()->SetSizer(sizer, deleteOld);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetSizerAndFit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizer", VTYPE_wx_Sizer, OCCUR_Once);
	DeclareArg(env, "deleteOld", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetSizerAndFit)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
	bool deleteOld = true;
	if (arg.IsValid(1)) deleteOld = arg.GetBoolean(1);
	pThis->GetEntity()->SetSizerAndFit(sizer, deleteOld);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetThemeEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetThemeEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool enable = arg.GetBoolean(0);
	pThis->GetEntity()->SetThemeEnabled(enable);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetToolTipString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tip", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetToolTipString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString tip = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetToolTip(tip);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tip", VTYPE_wx_ToolTip, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetToolTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxToolTip *tip = Object_wx_ToolTip::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetToolTip(tip);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetValidator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetValidator)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxValidator *validator = Object_wx_Validator::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetValidator(*validator);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetVirtualSizeWH)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetVirtualSizeWH)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	pThis->GetEntity()->SetVirtualSize(width, height);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetVirtualSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetVirtualSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetVirtualSize(*size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetVirtualSizeHintsWH)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "minW", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minH", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxW", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "maxH", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetVirtualSizeHintsWH)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int minW = arg.GetInt(0);
	int minH = arg.GetInt(1);
	int maxW = -1;
	if (arg.IsValid(2)) maxW = arg.GetInt(2);
	int maxH = -1;
	if (arg.IsValid(3)) maxH = arg.GetInt(3);
	pThis->GetEntity()->SetVirtualSizeHints(minW, minH, maxW, maxH);
	return Value::Nil;
#endif
	SetError_Obsolete(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetVirtualSizeHints)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "minSize", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "maxSize", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetVirtualSizeHints)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *minSize = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(0)) minSize = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	wxSize *maxSize = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(1)) maxSize = Object_wx_Size::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->SetVirtualSizeHints(*minSize, *maxSize);
	return Value::Nil;
#endif
	SetError_Obsolete(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetWindowStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetWindowStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long style = arg.GetLong(0);
	pThis->GetEntity()->SetWindowStyle(style);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetWindowStyleFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetWindowStyleFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long style = arg.GetLong(0);
	pThis->GetEntity()->SetWindowStyleFlag(style);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetWindowVariant)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetWindowVariant)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindowVariant variant = static_cast<wxWindowVariant>(arg.GetInt(0));
	pThis->GetEntity()->SetWindowVariant(variant);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, ShouldInheritColours)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ShouldInheritColours)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ShouldInheritColours();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool show = true;
	if (arg.IsValid(0)) show = arg.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Show(show);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, Thaw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, Thaw)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Thaw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, ToggleWindowStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ToggleWindowStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int flag = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->ToggleWindowStyle(flag);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, TransferDataFromWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, TransferDataFromWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->TransferDataFromWindow();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, TransferDataToWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, TransferDataToWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->TransferDataToWindow();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, UnregisterHotKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hotkeyId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, UnregisterHotKey)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int hotkeyId = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->UnregisterHotKey(hotkeyId);
	return ReturnValue(env, arg, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}

Gura_DeclareMethod(wx_Window, Update)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, Update)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Update();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, UpdateWindowUI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, UpdateWindowUI)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long flags = wxUPDATE_UI_NONE;
	if (arg.IsValid(0)) flags = arg.GetLong(0);
	pThis->GetEntity()->UpdateWindowUI(flags);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, Validate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Validate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Validate();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Window, WarpPointer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, WarpPointer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	pThis->GetEntity()->WarpPointer(x, y);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, WindowToClientSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, WindowToClientSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	wxSize rtn = pThis->GetEntity()->WindowToClientSize(*size);
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxWindow
//----------------------------------------------------------------------------
Object_wx_Window::~Object_wx_Window()
{
}

Object *Object_wx_Window::Clone() const
{
	return nullptr;
}

String Object_wx_Window::ToString(bool exprFlag)
{
	String rtn("<wx.Window:");
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
// Class implementation for wxWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Window)
{
	Gura_RealizeUserSymbol(AddChild);
	Gura_RealizeUserSymbol(CaptureMouse);
	Gura_RealizeUserSymbol(ClientToScreenXY);
	Gura_RealizeUserSymbol(ClientToScreen);
	Gura_RealizeUserSymbol(Destroy);
	Gura_RealizeUserSymbol(DestroyChildren);
	Gura_RealizeUserSymbol(DoGetBestSize);
	Gura_RealizeUserSymbol(DoUpdateWindowUI);
	Gura_RealizeUserSymbol(DragAcceptFiles);
	Gura_RealizeUserSymbol(Enable);
	Gura_RealizeUserSymbol(Fit);
	Gura_RealizeUserSymbol(FitInside);
	Gura_RealizeUserSymbol(Freeze);
	Gura_RealizeUserSymbol(GetBackgroundColour);
	Gura_RealizeUserSymbol(GetBackgroundStyle);
	Gura_RealizeUserSymbol(GetCharHeight);
	Gura_RealizeUserSymbol(GetCharWidth);
	Gura_RealizeUserSymbol(GetDefaultAttributes);
	Gura_RealizeUserSymbol(GetForegroundColour);
	Gura_RealizeUserSymbol(GetHelpTextAtPoint);
	Gura_RealizeUserSymbol(GetHelpText);
	Gura_RealizeUserSymbol(GetLabel);
	Gura_RealizeUserSymbol(GetMinSize);
	Gura_RealizeUserSymbol(GetName);
	Gura_RealizeUserSymbol(GetParent);
	Gura_RealizeUserSymbol(GetPosition);
	Gura_RealizeUserSymbol(GetRect);
	Gura_RealizeUserSymbol(GetScreenPosition);
	Gura_RealizeUserSymbol(GetScreenRect);
	Gura_RealizeUserSymbol(GetScrollPos);
	Gura_RealizeUserSymbol(GetScrollRange);
	Gura_RealizeUserSymbol(GetScrollThumb);
	Gura_RealizeUserSymbol(GetTextExtent);
	Gura_RealizeUserSymbol(GetUpdateRegion);
	Gura_RealizeUserSymbol(HasCapture);
	Gura_RealizeUserSymbol(HasMultiplePages);
	Gura_RealizeUserSymbol(HasScrollbar);
	Gura_RealizeUserSymbol(HasTransparentBackground);
	Gura_RealizeUserSymbol(IsDoubleBuffered);
	Gura_RealizeUserSymbol(IsEnabled);
	Gura_RealizeUserSymbol(IsFrozen);
	Gura_RealizeUserSymbol(IsRetained);
	Gura_RealizeUserSymbol(IsShown);
	Gura_RealizeUserSymbol(IsShownOnScreen);
	Gura_RealizeUserSymbol(MakeModal);
	Gura_RealizeUserSymbol(OnCommand);
	Gura_RealizeUserSymbol(OnClose);
	Gura_RealizeUserSymbol(OnInternalIdle);
	Gura_RealizeUserSymbol(Refresh);
	Gura_RealizeUserSymbol(ReleaseMouse);
	Gura_RealizeUserSymbol(RemoveChild);
	Gura_RealizeUserSymbol(Reparent);
	Gura_RealizeUserSymbol(ScreenToClient);
	Gura_RealizeUserSymbol(ScreenToClientXY);
	Gura_RealizeUserSymbol(ScrollLines);
	Gura_RealizeUserSymbol(ScrollPages);
	Gura_RealizeUserSymbol(ScrollWindow);
	Gura_RealizeUserSymbol(SetAcceleratorTable);
	Gura_RealizeUserSymbol(SetBackgroundColour);
	Gura_RealizeUserSymbol(SetBackgroundStyle);
	Gura_RealizeUserSymbol(SetClientSize);
	Gura_RealizeUserSymbol(SetClientSizeWH);
	Gura_RealizeUserSymbol(SetCursor);
	Gura_RealizeUserSymbol(SetInitialBestSize);
	Gura_RealizeUserSymbol(SetFocus);
	Gura_RealizeUserSymbol(SetFocusFromKbd);
	Gura_RealizeUserSymbol(SetForegroundColour);
	Gura_RealizeUserSymbol(SetHelpText);
	Gura_RealizeUserSymbol(SetLabel);
	Gura_RealizeUserSymbol(SetName);
	Gura_RealizeUserSymbol(SetPalette);
	Gura_RealizeUserSymbol(SetScrollbar);
	Gura_RealizeUserSymbol(SetScrollPage);
	Gura_RealizeUserSymbol(SetScrollPos);
	Gura_RealizeUserSymbol(SetScrollRange);
	Gura_RealizeUserSymbol(SetDimensions);
	Gura_RealizeUserSymbol(SetRect);
	Gura_RealizeUserSymbol(SetSizeWH);
	Gura_RealizeUserSymbol(SetSize);
	Gura_RealizeUserSymbol(SetThemeEnabled);
	Gura_RealizeUserSymbol(SetValidator);
	Gura_RealizeUserSymbol(SetVirtualSizeHints);
	Gura_RealizeUserSymbol(SetWindowStyleFlag);
	Gura_RealizeUserSymbol(ShouldInheritColours);
	Gura_RealizeUserSymbol(Show);
	Gura_RealizeUserSymbol(Thaw);
	Gura_RealizeUserSymbol(TransferDataFromWindow);
	Gura_RealizeUserSymbol(TransferDataToWindow);
	Gura_RealizeUserSymbol(Update);
	Gura_RealizeUserSymbol(UpdateWindowUI);
	Gura_RealizeUserSymbol(Validate);
	Gura_RealizeUserSymbol(WindowToClientSize);
	Gura_AssignFunction(WindowEmpty);
	Gura_AssignFunction(Window);
	Gura_AssignMethod(wx_Window, AddChild);
	Gura_AssignMethod(wx_Window, CacheBestSize);
	Gura_AssignMethod(wx_Window, CaptureMouse);
	Gura_AssignMethod(wx_Window, Center);
	Gura_AssignMethod(wx_Window, CenterOnParent);
	Gura_AssignMethod(wx_Window, CenterOnScreen);
	Gura_AssignMethod(wx_Window, Centre);
	Gura_AssignMethod(wx_Window, CentreOnParent);
	Gura_AssignMethod(wx_Window, ClearBackground);
	Gura_AssignMethod(wx_Window, ClientToScreenXY);
	Gura_AssignMethod(wx_Window, ClientToScreen);
	Gura_AssignMethod(wx_Window, ClientToWindowSize);
	Gura_AssignMethod(wx_Window, Close);
	Gura_AssignMethod(wx_Window, ConvertDialogPointToPixels);
	Gura_AssignMethod(wx_Window, ConvertDialogSizeToPixels);
	Gura_AssignMethod(wx_Window, ConvertPixelPointToDialog);
	Gura_AssignMethod(wx_Window, ConvertPixelSizeToDialog);
	Gura_AssignMethod(wx_Window, Destroy);
	Gura_AssignMethod(wx_Window, DestroyChildren);
	Gura_AssignMethod(wx_Window, Disable);
	Gura_AssignMethod(wx_Window, DoGetBestSize);
	Gura_AssignMethod(wx_Window, DoUpdateWindowUI);
	Gura_AssignMethod(wx_Window, DragAcceptFiles);
	Gura_AssignMethod(wx_Window, Enable);
	Gura_AssignMethod(wx_Window, FindFocus);
	Gura_AssignMethod(wx_Window, FindWindowById);
	Gura_AssignMethod(wx_Window, FindWindowByName);
	//Gura_AssignMethod(wx_Window, FindWindowById);
	Gura_AssignMethod(wx_Window, FindWindowByLabel);
	//Gura_AssignMethod(wx_Window, FindWindowByName);
	Gura_AssignMethod(wx_Window, Fit);
	Gura_AssignMethod(wx_Window, FitInside);
	Gura_AssignMethod(wx_Window, Freeze);
	Gura_AssignMethod(wx_Window, GetAcceleratorTable);
	Gura_AssignMethod(wx_Window, GetAccessible);
	Gura_AssignMethod(wx_Window, GetAdjustedBestSize);
	Gura_AssignMethod(wx_Window, GetBackgroundColour);
	Gura_AssignMethod(wx_Window, GetBackgroundStyle);
	Gura_AssignMethod(wx_Window, GetEffectiveMinSize);
	Gura_AssignMethod(wx_Window, GetBestSize);
	Gura_AssignMethod(wx_Window, GetCapture);
	Gura_AssignMethod(wx_Window, GetCaret);
	Gura_AssignMethod(wx_Window, GetCharHeight);
	Gura_AssignMethod(wx_Window, GetCharWidth);
	Gura_AssignMethod(wx_Window, GetChildren);
	Gura_AssignMethod(wx_Window, GetClassDefaultAttributes);
	Gura_AssignMethod(wx_Window, GetClientSizeWH);
	Gura_AssignMethod(wx_Window, GetClientSize);
	Gura_AssignMethod(wx_Window, GetConstraints);
	Gura_AssignMethod(wx_Window, GetContainingSizer);
	Gura_AssignMethod(wx_Window, GetCursor);
	Gura_AssignMethod(wx_Window, GetDefaultAttributes);
	Gura_AssignMethod(wx_Window, GetDropTarget);
	Gura_AssignMethod(wx_Window, GetEventHandler);
	Gura_AssignMethod(wx_Window, GetExtraStyle);
	Gura_AssignMethod(wx_Window, GetFont);
	Gura_AssignMethod(wx_Window, GetForegroundColour);
	Gura_AssignMethod(wx_Window, GetGrandParent);
	Gura_AssignMethod(wx_Window, GetHandle);
	Gura_AssignMethod(wx_Window, GetHelpTextAtPoint);
	Gura_AssignMethod(wx_Window, GetHelpText);
	Gura_AssignMethod(wx_Window, GetId);
	Gura_AssignMethod(wx_Window, GetLabel);
	Gura_AssignMethod(wx_Window, GetMaxSize);
	Gura_AssignMethod(wx_Window, GetMinSize);
	Gura_AssignMethod(wx_Window, GetName);
	Gura_AssignMethod(wx_Window, GetNextSibling);
	Gura_AssignMethod(wx_Window, GetParent);
	Gura_AssignMethod(wx_Window, GetPositionXY);
	Gura_AssignMethod(wx_Window, GetPosition);
	Gura_AssignMethod(wx_Window, GetPrevSibling);
	Gura_AssignMethod(wx_Window, GetRect);
	Gura_AssignMethod(wx_Window, GetScreenPositionXY);
	Gura_AssignMethod(wx_Window, GetScreenPosition);
	Gura_AssignMethod(wx_Window, GetScreenRect);
	Gura_AssignMethod(wx_Window, GetScrollPos);
	Gura_AssignMethod(wx_Window, GetScrollRange);
	Gura_AssignMethod(wx_Window, GetScrollThumb);
	Gura_AssignMethod(wx_Window, GetSizeWH);
	Gura_AssignMethod(wx_Window, GetSize);
	Gura_AssignMethod(wx_Window, GetSizer);
	Gura_AssignMethod(wx_Window, GetTextExtent);
	Gura_AssignMethod(wx_Window, GetToolTip);
	Gura_AssignMethod(wx_Window, GetUpdateRegion);
	Gura_AssignMethod(wx_Window, GetValidator);
	Gura_AssignMethod(wx_Window, GetVirtualSizeWH);
	Gura_AssignMethod(wx_Window, GetVirtualSize);
	Gura_AssignMethod(wx_Window, GetWindowBorderSize);
	Gura_AssignMethod(wx_Window, GetWindowStyleFlag);
	Gura_AssignMethodEx(wx_Window, GetWindowStyleFlag, "GetWindowStyle");
	Gura_AssignMethod(wx_Window, GetWindowVariant);
	Gura_AssignMethod(wx_Window, HasCapture);
	Gura_AssignMethod(wx_Window, HasFlag);
	Gura_AssignMethod(wx_Window, HasMultiplePages);
	Gura_AssignMethod(wx_Window, HasScrollbar);
	Gura_AssignMethod(wx_Window, HasTransparentBackground);
	Gura_AssignMethod(wx_Window, Hide);
	Gura_AssignMethod(wx_Window, InheritAttributes);
	Gura_AssignMethod(wx_Window, InitDialog);
	Gura_AssignMethod(wx_Window, InvalidateBestSize);
	Gura_AssignMethod(wx_Window, IsDoubleBuffered);
	Gura_AssignMethod(wx_Window, IsEnabled);
	Gura_AssignMethod(wx_Window, IsExposed);
	Gura_AssignMethod(wx_Window, IsExposedPoint);
	Gura_AssignMethod(wx_Window, IsExposedRect);
	Gura_AssignMethod(wx_Window, IsFrozen);
	Gura_AssignMethod(wx_Window, IsRetained);
	Gura_AssignMethod(wx_Window, IsShown);
	Gura_AssignMethod(wx_Window, IsShownOnScreen);
	Gura_AssignMethod(wx_Window, IsTopLevel);
	Gura_AssignMethod(wx_Window, Layout);
	Gura_AssignMethod(wx_Window, Lower);
	Gura_AssignMethod(wx_Window, MakeModal);
	Gura_AssignMethod(wx_Window, MoveXY);
	Gura_AssignMethod(wx_Window, Move);
	Gura_AssignMethod(wx_Window, MoveAfterInTabOrder);
	Gura_AssignMethod(wx_Window, MoveBeforeInTabOrder);
	Gura_AssignMethod(wx_Window, Navigate);
	Gura_AssignMethod(wx_Window, OnActivate);
	Gura_AssignMethod(wx_Window, OnChar);
	Gura_AssignMethod(wx_Window, OnCharHook);
	Gura_AssignMethod(wx_Window, OnCommand);
	Gura_AssignMethod(wx_Window, OnClose);
	Gura_AssignMethod(wx_Window, OnKeyDown);
	Gura_AssignMethod(wx_Window, OnKeyUp);
	Gura_AssignMethod(wx_Window, OnInitDialog);
	Gura_AssignMethod(wx_Window, OnMenuHighlight);
	Gura_AssignMethod(wx_Window, OnMouseEvent);
	Gura_AssignMethod(wx_Window, OnMove);
	Gura_AssignMethod(wx_Window, OnPaint);
	Gura_AssignMethod(wx_Window, OnScroll);
	Gura_AssignMethod(wx_Window, OnSetFocus);
	Gura_AssignMethod(wx_Window, OnSize);
	Gura_AssignMethod(wx_Window, OnSysColourChanged);
	Gura_AssignMethod(wx_Window, OnInternalIdle);
	Gura_AssignMethod(wx_Window, PopEventHandler);
	Gura_AssignMethod(wx_Window, PopupMenu);
	Gura_AssignMethod(wx_Window, PopupMenuXY);
	Gura_AssignMethod(wx_Window, PushEventHandler);
	Gura_AssignMethod(wx_Window, Raise);
	Gura_AssignMethod(wx_Window, Refresh);
	Gura_AssignMethod(wx_Window, RefreshRect);
	Gura_AssignMethod(wx_Window, RegisterHotKey);
	Gura_AssignMethod(wx_Window, ReleaseMouse);
	Gura_AssignMethod(wx_Window, RemoveChild);
	Gura_AssignMethod(wx_Window, RemoveEventHandler);
	Gura_AssignMethod(wx_Window, Reparent);
	Gura_AssignMethod(wx_Window, ScreenToClientXY);
	Gura_AssignMethod(wx_Window, ScreenToClient);
	Gura_AssignMethod(wx_Window, ScrollLines);
	Gura_AssignMethod(wx_Window, ScrollPages);
	Gura_AssignMethod(wx_Window, ScrollWindow);
	Gura_AssignMethod(wx_Window, SetAcceleratorTable);
	Gura_AssignMethod(wx_Window, SetAccessible);
	Gura_AssignMethod(wx_Window, SetAutoLayout);
	Gura_AssignMethod(wx_Window, SetBackgroundColour);
	Gura_AssignMethod(wx_Window, SetBackgroundStyle);
	Gura_AssignMethod(wx_Window, SetInitialSize);
	Gura_AssignMethod(wx_Window, SetCaret);
	Gura_AssignMethod(wx_Window, SetClientSizeWH);
	Gura_AssignMethod(wx_Window, SetClientSize);
	Gura_AssignMethod(wx_Window, SetConstraints);
	Gura_AssignMethod(wx_Window, SetContainingSizer);
	Gura_AssignMethod(wx_Window, SetCursor);
	Gura_AssignMethod(wx_Window, SetDropTarget);
	Gura_AssignMethod(wx_Window, SetInitialBestSize);
	Gura_AssignMethod(wx_Window, SetEventHandler);
	Gura_AssignMethod(wx_Window, SetExtraStyle);
	Gura_AssignMethod(wx_Window, SetFocus);
	Gura_AssignMethod(wx_Window, SetFocusFromKbd);
	Gura_AssignMethod(wx_Window, SetFont);
	Gura_AssignMethod(wx_Window, SetForegroundColour);
	Gura_AssignMethod(wx_Window, SetHelpText);
	Gura_AssignMethod(wx_Window, SetId);
	Gura_AssignMethod(wx_Window, SetLabel);
	Gura_AssignMethod(wx_Window, SetMaxSize);
	Gura_AssignMethod(wx_Window, SetMinSize);
	Gura_AssignMethod(wx_Window, SetName);
	Gura_AssignMethod(wx_Window, SetOwnBackgroundColour);
	Gura_AssignMethod(wx_Window, SetOwnFont);
	Gura_AssignMethod(wx_Window, SetOwnForegroundColour);
	Gura_AssignMethod(wx_Window, SetPalette);
	Gura_AssignMethod(wx_Window, SetScrollbar);
	Gura_AssignMethod(wx_Window, SetScrollPage);
	Gura_AssignMethod(wx_Window, SetScrollPos);
	Gura_AssignMethod(wx_Window, SetScrollRange);
	Gura_AssignMethod(wx_Window, SetDimensions);
	Gura_AssignMethod(wx_Window, SetRect);
	Gura_AssignMethod(wx_Window, SetSizeWH);
	Gura_AssignMethod(wx_Window, SetSize);
	Gura_AssignMethod(wx_Window, SetSizer);
	Gura_AssignMethod(wx_Window, SetSizerAndFit);
	Gura_AssignMethod(wx_Window, SetThemeEnabled);
	Gura_AssignMethod(wx_Window, SetToolTipString);
	Gura_AssignMethod(wx_Window, SetToolTip);
	Gura_AssignMethod(wx_Window, SetValidator);
	Gura_AssignMethod(wx_Window, SetVirtualSizeWH);
	Gura_AssignMethod(wx_Window, SetVirtualSize);
	Gura_AssignMethod(wx_Window, SetVirtualSizeHintsWH);
	Gura_AssignMethod(wx_Window, SetVirtualSizeHints);
	Gura_AssignMethod(wx_Window, SetWindowStyle);
	Gura_AssignMethod(wx_Window, SetWindowStyleFlag);
	Gura_AssignMethod(wx_Window, SetWindowVariant);
	Gura_AssignMethod(wx_Window, ShouldInheritColours);
	Gura_AssignMethod(wx_Window, Show);
	Gura_AssignMethod(wx_Window, Thaw);
	Gura_AssignMethod(wx_Window, ToggleWindowStyle);
	Gura_AssignMethod(wx_Window, TransferDataFromWindow);
	Gura_AssignMethod(wx_Window, TransferDataToWindow);
	Gura_AssignMethod(wx_Window, UnregisterHotKey);
	Gura_AssignMethod(wx_Window, Update);
	Gura_AssignMethod(wx_Window, UpdateWindowUI);
	Gura_AssignMethod(wx_Window, Validate);
	Gura_AssignMethod(wx_Window, WarpPointer);
	Gura_AssignMethod(wx_Window, WindowToClientSize);
}

Gura_ImplementDescendantCreator(wx_Window)
{
	return new Object_wx_Window((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
