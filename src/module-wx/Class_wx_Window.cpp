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
	Gura::Signal _sig;
	Object_wx_Window *_pObj;
public:
	inline wx_Window() : wxWindow(), _sig(NULL), _pObj(NULL) {}
	inline wx_Window(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxWindow(parent, id, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
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
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Window *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Window::~wx_Window()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Window::GuraObjectDeleted()
{
	_pObj = NULL;
}

bool wx_Window::TransferDataFromWindow()
{
	bool evaluatedFlag;
	Value rtn = _pObj->EvalMethod(*_pObj, _sig,
		Gura_UserSymbol(TransferDataFromWindow), ValueList::Null, evaluatedFlag);
	if (_sig.IsSignalled()) {
		SetLogError(_sig);
		return false;
	}
	return rtn.GetBoolean();
}

bool wx_Window::TransferDataToWindow()
{
	bool evaluatedFlag;
	Value rtn = _pObj->EvalMethod(*_pObj, _sig,
		Gura_UserSymbol(TransferDataToWindow), ValueList::Null, evaluatedFlag);
	if (_sig.IsSignalled()) {
		SetLogError(_sig);
		return false;
	}
	return rtn.GetBoolean();
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(WindowEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Window));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WindowEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Window *pEntity = new wx_Window();
	Object_wx_Window *pObj = Object_wx_Window::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Window(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Window)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxPanelNameStr;
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_Window *pEntity = new wx_Window(parent, id, *pos, *size, style, name);
	Object_wx_Window *pObj = Object_wx_Window::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Window(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Window, AddChild)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "child", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, AddChild)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *child = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AddChild(child);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, CacheBestSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, CacheBestSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->CacheBestSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, CaptureMouse)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, CaptureMouse)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->CaptureMouse();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, Center)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, Center)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int direction = args.GetInt(0);
	pThis->GetEntity()->Center(direction);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, CenterOnParent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, CenterOnParent)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int direction = args.GetInt(0);
	pThis->GetEntity()->CenterOnParent(direction);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, CenterOnScreen)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, CenterOnScreen)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int direction = args.GetInt(0);
	pThis->GetEntity()->CenterOnScreen(direction);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, Centre)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Centre)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int direction = wxBOTH;
	if (args.IsValid(0)) direction = args.GetInt(0);
	pThis->GetEntity()->Centre(direction);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, CentreOnParent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, CentreOnParent)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int direction = wxBOTH;
	if (args.IsValid(0)) direction = args.GetInt(0);
	pThis->GetEntity()->CentreOnParent(direction);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, ClearBackground)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, ClearBackground)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ClearBackground();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, ClientToScreenXY)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, ClientToScreenXY)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	pThis->GetEntity()->ClientToScreen(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, x, y));
}

Gura_DeclareMethod(wx_Window, ClientToScreen)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ClientToScreen)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxPoint rtn = pThis->GetEntity()->ClientToScreen(*pt);
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, ClientToWindowSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ClientToWindowSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxSize rtn = pThis->GetEntity()->ClientToWindowSize(*size);
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, Close)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "force", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Close)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool force = false;
	if (args.IsValid(0)) force = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Close(force);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, ConvertDialogPointToPixels)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ConvertDialogPointToPixels)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxPoint rtn = pThis->GetEntity()->ConvertDialogToPixels(*pt);
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, ConvertDialogSizeToPixels)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ConvertDialogSizeToPixels)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *sz = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxSize rtn = pThis->GetEntity()->ConvertDialogToPixels(*sz);
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, ConvertPixelPointToDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ConvertPixelPointToDialog)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxPoint rtn = pThis->GetEntity()->ConvertPixelsToDialog(*pt);
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, ConvertPixelSizeToDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ConvertPixelSizeToDialog)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *sz = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxSize rtn = pThis->GetEntity()->ConvertPixelsToDialog(*sz);
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, Destroy)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Destroy)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Destroy();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, DestroyChildren)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, DestroyChildren)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DestroyChildren();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, Disable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Disable)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Disable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, DoGetBestSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, DoGetBestSize)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->DoGetBestSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, DoUpdateWindowUI)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_UpdateUIEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, DoUpdateWindowUI)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUpdateUIEvent *event = Object_wx_UpdateUIEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->DoUpdateWindowUI(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, DragAcceptFiles)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "accept", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, DragAcceptFiles)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool accept = args.GetBoolean(0);
	pThis->GetEntity()->DragAcceptFiles(accept);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, Enable)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Enable)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Enable(enable);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Window, FindFocus)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Window, FindFocus)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)wxWindow::FindFocus();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, FindWindowById)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, FindWindowById)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long id = args.GetLong(0);
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->FindWindow(id);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, FindWindowByName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, FindWindowByName)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->FindWindow(name);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

#if 0
Gura_DeclareClassMethod(wx_Window, FindWindowById)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Window, FindWindowById)
{
	if (!CheckWxReady(sig)) return Value::Null;
	long id = args.GetLong(0);
	wxWindow *parent = (wxWindow *)(NULL);
	if (args.IsValid(1)) parent = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxWindow::FindWindowById(id, parent);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}
#endif

Gura_DeclareClassMethod(wx_Window, FindWindowByLabel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Window, FindWindowByLabel)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString label = wxString::FromUTF8(args.GetString(0));
	wxWindow *parent = (wxWindow *)(NULL);
	if (args.IsValid(1)) parent = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxWindow::FindWindowByLabel(label, parent);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

#if 0
Gura_DeclareClassMethod(wx_Window, FindWindowByName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Window, FindWindowByName)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxWindow *parent = (wxWindow *)(NULL);
	if (args.IsValid(1)) parent = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxWindow::FindWindowByName(name, parent);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}
#endif

Gura_DeclareMethod(wx_Window, Fit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, Fit)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Fit();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, FitInside)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, FitInside)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->FitInside();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, Freeze)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, Freeze)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Freeze();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, GetAcceleratorTable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetAcceleratorTable)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxAcceleratorTable *rtn = (wxAcceleratorTable *)pThis->GetEntity()->GetAcceleratorTable();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_AcceleratorTable(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetAccessible)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetAccessible)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxAccessible *rtn = (wxAccessible *)pThis->GetEntity()->GetAccessible();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Accessible(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, GetAdjustedBestSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetAdjustedBestSize)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetAdjustedBestSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, GetBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetBackgroundColour)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetBackgroundColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetBackgroundStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetBackgroundStyle)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBackgroundStyle rtn = pThis->GetEntity()->GetBackgroundStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetEffectiveMinSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetEffectiveMinSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetEffectiveMinSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetBestSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetBestSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetBestSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_Window, GetCapture)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Window, GetCapture)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)wxWindow::GetCapture();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetCaret)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetCaret)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCaret *rtn = (wxCaret *)pThis->GetEntity()->GetCaret();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Caret(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetCharHeight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetCharHeight)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetCharHeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetCharWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetCharWidth)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetCharWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetChildren)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetChildren)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowList &rtn = pThis->GetEntity()->GetChildren();
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(rtn.size());
	foreach (wxWindowList, ppWindow, rtn) {
		wxWindow *pWindow = *ppWindow;
		valList.push_back(Value(new Object_wx_Window(pWindow, NULL, OwnerFalse)));
	}
	return result;
}

Gura_DeclareClassMethod(wx_Window, GetClassDefaultAttributes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "variant", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Window, GetClassDefaultAttributes)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL;
	if (args.IsValid(0)) variant = static_cast<wxWindowVariant>(args.GetInt(0));
	wxVisualAttributes rtn = wxWindow::GetClassDefaultAttributes(variant);
	return ReturnValue(env, sig, args, Value(new Object_wx_VisualAttributes(new wxVisualAttributes(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, GetClientSizeWH)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetClientSizeWH)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width;
	int height;
	pThis->GetEntity()->GetClientSize(&width, &height);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, width, height));
}

Gura_DeclareMethod(wx_Window, GetClientSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetClientSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetClientSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetConstraints)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetConstraints)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLayoutConstraints *rtn = (wxLayoutConstraints *)pThis->GetEntity()->GetConstraints();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_LayoutConstraints(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetContainingSizer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetContainingSizer)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizer *rtn = (wxSizer *)pThis->GetEntity()->GetContainingSizer();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Sizer(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetCursor)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxCursor &rtn = pThis->GetEntity()->GetCursor();
	return ReturnValue(env, sig, args, Value(new Object_wx_Cursor(new wxCursor(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetDefaultAttributes)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetDefaultAttributes)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxVisualAttributes rtn = pThis->GetEntity()->GetDefaultAttributes();
	return ReturnValue(env, sig, args, Value(new Object_wx_VisualAttributes(new wxVisualAttributes(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, GetDropTarget)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetDropTarget)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDropTarget *rtn = (wxDropTarget *)pThis->GetEntity()->GetDropTarget();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_DropTarget(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetEventHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetEventHandler)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvtHandler *rtn = (wxEvtHandler *)pThis->GetEntity()->GetEventHandler();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_EvtHandler(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetExtraStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetExtraStyle)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetExtraStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetFont)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont rtn = pThis->GetEntity()->GetFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetForegroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetForegroundColour)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetForegroundColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetGrandParent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetGrandParent)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetGrandParent();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetHandle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetHandle)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	void *rtn = pThis->GetEntity()->GetHandle();
	Value value;
	if (rtn != NULL) value = Value(reinterpret_cast<int>(rtn));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetHelpTextAtPoint)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "origin", VTYPE_wx_HelpEvent, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetHelpTextAtPoint)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *point = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxHelpEvent *origin = Object_wx_HelpEvent::GetObject(args, 1)->GetEntity();
	wxString rtn = pThis->GetEntity()->GetHelpTextAtPoint(*point, *origin);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, GetHelpText)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetHelpText)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetHelpText();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Window, GetId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetId)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetLabel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetLabel)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetLabel();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Window, GetMaxSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetMaxSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetMaxSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetMinSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetMinSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetMinSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetName)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Window, GetNextSibling)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetNextSibling)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetNextSibling();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetParent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetParent)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetParent();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetPositionXY)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetPositionXY)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x;
	int y;
	pThis->GetEntity()->GetPosition(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, x, y));
}

Gura_DeclareMethod(wx_Window, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetPosition)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetPrevSibling)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetPrevSibling)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetPrevSibling();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetRect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetRect)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pThis->GetEntity()->GetRect();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetScreenPositionXY)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetScreenPositionXY)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x;
	int y;
	pThis->GetEntity()->GetScreenPosition(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, x, y));
}

Gura_DeclareMethod(wx_Window, GetScreenPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetScreenPosition)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetScreenPosition();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetScreenRect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetScreenRect)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pThis->GetEntity()->GetScreenRect();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetScrollPos)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetScrollPos)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int orientation = args.GetInt(0);
	int rtn = pThis->GetEntity()->GetScrollPos(orientation);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetScrollRange)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetScrollRange)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int orientation = args.GetInt(0);
	int rtn = pThis->GetEntity()->GetScrollRange(orientation);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetScrollThumb)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetScrollThumb)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int orientation = args.GetInt(0);
	int rtn = pThis->GetEntity()->GetScrollThumb(orientation);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetSizeWH)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetSizeWH)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width;
	int height;
	pThis->GetEntity()->GetSize(&width, &height);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, width, height));
}

Gura_DeclareMethod(wx_Window, GetSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetSizer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetSizer)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizer *rtn = (wxSizer *)pThis->GetEntity()->GetSizer();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Sizer(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetTextExtent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetTextExtent)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString string = wxString::FromUTF8(args.GetString(0));
	wxFont *font = (wxFont *)(NULL);
	if (args.IsValid(1)) font = Object_wx_Font::GetObject(args, 1)->GetEntity();
	int x;
	int y;
	int descent;
	int externalLeading;
	pThis->GetEntity()->GetTextExtent(string, &x, &y, &descent, &externalLeading, font);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, x, y, descent, externalLeading));
}

Gura_DeclareMethod(wx_Window, GetToolTip)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetToolTip)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxToolTip *rtn = (wxToolTip *)pThis->GetEntity()->GetToolTip();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_ToolTip(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetUpdateRegion)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetUpdateRegion)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRegion rtn = pThis->GetEntity()->GetUpdateRegion();
	return ReturnValue(env, sig, args, Value(new Object_wx_Region(new wxRegion(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetValidator)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetValidator)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxValidator *rtn = (wxValidator *)pThis->GetEntity()->GetValidator();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Validator(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, GetVirtualSizeWH)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetVirtualSizeWH)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width;
	int height;
	pThis->GetEntity()->GetVirtualSize(&width, &height);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, width, height));
}

Gura_DeclareMethod(wx_Window, GetVirtualSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetVirtualSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetVirtualSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetWindowBorderSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetWindowBorderSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetWindowBorderSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, GetWindowStyleFlag)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetWindowStyleFlag)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetWindowStyleFlag();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, GetWindowVariant)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, GetWindowVariant)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowVariant rtn = pThis->GetEntity()->GetWindowVariant();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, HasCapture)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, HasCapture)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasCapture();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, HasFlag)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, HasFlag)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flag = args.GetInt(0);
	bool rtn = pThis->GetEntity()->HasFlag(flag);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, HasMultiplePages)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, HasMultiplePages)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasMultiplePages();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, HasScrollbar)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, HasScrollbar)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int orient = args.GetInt(0);
	bool rtn = pThis->GetEntity()->HasScrollbar(orient);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, HasTransparentBackground)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, HasTransparentBackground)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasTransparentBackground();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, Hide)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Hide)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Hide();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, InheritAttributes)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, InheritAttributes)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->InheritAttributes();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, InitDialog)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, InitDialog)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->InitDialog();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, InvalidateBestSize)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, InvalidateBestSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->InvalidateBestSize();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, IsDoubleBuffered)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsDoubleBuffered)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsDoubleBuffered();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsEnabled)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsEnabled)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsEnabled();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsExposed)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "h", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsExposed)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	bool rtn = false;
	if (args.Is_number(2) && args.Is_number(3)) {
		int w = args.GetInt(2);
		int h = args.GetInt(3);
		rtn = pThis->GetEntity()->IsExposed(x, y, w, h);
	} else {
		rtn = pThis->GetEntity()->IsExposed(x, y);
	}
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsExposedPoint)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsExposedPoint)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsExposed(*pt);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsExposedRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsExposedRect)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsExposed(*rect);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsFrozen)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsFrozen)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsFrozen();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsRetained)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsRetained)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsRetained();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsShown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsShown)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsShown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsShownOnScreen)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsShownOnScreen)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsShownOnScreen();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, IsTopLevel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, IsTopLevel)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsTopLevel();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, Layout)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, Layout)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Layout();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, Lower)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, Lower)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Lower();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, MakeModal)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, MakeModal)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->MakeModal(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, MoveXY)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, MoveXY)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	pThis->GetEntity()->Move(x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, Move)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, Move)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Move(*pt);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, MoveAfterInTabOrder)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, MoveAfterInTabOrder)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->MoveAfterInTabOrder(win);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, MoveBeforeInTabOrder)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, MoveBeforeInTabOrder)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->MoveBeforeInTabOrder(win);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, Navigate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Navigate)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = wxNavigationKeyEvent::IsForward;
	if (args.IsValid(0)) flags = args.GetInt(0);
	bool rtn = pThis->GetEntity()->Navigate(flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, OnActivate)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_ActivateEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnActivate)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxActivateEvent *event = Object_wx_ActivateEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnActivate(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnChar)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnChar)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnChar(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnCharHook)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnCharHook)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnCharHook(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnCommand)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "object", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnCommand)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvtHandler *object = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->OnCommand(*object, *event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnClose)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, OnClose)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->OnClose();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnKeyDown)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnKeyDown)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnKeyDown(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnKeyUp)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnKeyUp)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnKeyUp(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnInitDialog)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_InitDialogEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnInitDialog)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInitDialogEvent *event = Object_wx_InitDialogEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnInitDialog(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnMenuHighlight)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_MenuEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnMenuHighlight)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMenuEvent *event = Object_wx_MenuEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnMenuHighlight(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnMouseEvent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_MouseEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnMouseEvent)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMouseEvent *event = Object_wx_MouseEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnMouseEvent(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnMove)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_MoveEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnMove)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMoveEvent *event = Object_wx_MoveEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnMove(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnPaint)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_PaintEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnPaint)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPaintEvent *event = Object_wx_PaintEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnPaint(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnScroll)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_ScrollWinEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnScroll)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxScrollWinEvent *event = Object_wx_ScrollWinEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnScroll(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnSetFocus)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_FocusEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnSetFocus)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFocusEvent *event = Object_wx_FocusEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnSetFocus(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_SizeEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnSize)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizeEvent *event = Object_wx_SizeEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnSize(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnSysColourChanged)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_OnSysColourChangedEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, OnSysColourChanged)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOnSysColourChangedEvent *event = Object_wx_OnSysColourChangedEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnSysColourChanged(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, OnInternalIdle)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, OnInternalIdle)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->OnInternalIdle();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, PopEventHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "deleteHandler", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, PopEventHandler)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool deleteHandler = false;
	if (args.IsValid(0)) deleteHandler = args.GetBoolean(0);
	wxEvtHandler *rtn = (wxEvtHandler *)pThis->GetEntity()->PopEventHandler(deleteHandler);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_EvtHandler(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Window, PopupMenu)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, PopupMenu)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(1)) pos = Object_wx_Point::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->PopupMenu(menu, *pos);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, PopupMenuXY)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, PopupMenuXY)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	bool rtn = pThis->GetEntity()->PopupMenu(menu, x, y);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, PushEventHandler)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_EvtHandler, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, PushEventHandler)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvtHandler *handler = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->PushEventHandler(handler);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, Raise)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, Raise)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Raise();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, Refresh)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "eraseBackground", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Refresh)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool eraseBackground = true;
	if (args.IsValid(0)) eraseBackground = args.GetBoolean(0);
	wxRect *rect = (wxRect *)(NULL);
	if (args.IsValid(1)) rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->Refresh(eraseBackground, rect);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, RefreshRect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "eraseBackground", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, RefreshRect)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	bool eraseBackground = true;
	if (args.IsValid(1)) eraseBackground = args.GetBoolean(1);
	pThis->GetEntity()->RefreshRect(*rect, eraseBackground);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, RegisterHotKey)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hotkeyId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "modifiers", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "virtualKeyCode", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, RegisterHotKey)
{
#if defined(__WXMSW__)
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int hotkeyId = args.GetInt(0);
	int modifiers = args.GetInt(1);
	int virtualKeyCode = args.GetInt(2);
	bool rtn = pThis->GetEntity()->RegisterHotKey(hotkeyId, modifiers, virtualKeyCode);
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_Window, ReleaseMouse)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, ReleaseMouse)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ReleaseMouse();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, RemoveChild)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "child", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, RemoveChild)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *child = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->RemoveChild(child);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, RemoveEventHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, RemoveEventHandler)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvtHandler *handler = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->RemoveEventHandler(handler);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, Reparent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "newParent", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Reparent)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *newParent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Reparent(newParent);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, ScreenToClientXY)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ScreenToClientXY)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	pThis->GetEntity()->ScreenToClient(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, x, y));
}

Gura_DeclareMethod(wx_Window, ScreenToClient)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ScreenToClient)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxPoint rtn = pThis->GetEntity()->ScreenToClient(*pt);
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Window, ScrollLines)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lines", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ScrollLines)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int lines = args.GetInt(0);
	bool rtn = pThis->GetEntity()->ScrollLines(lines);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, ScrollPages)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ScrollPages)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pages = args.GetInt(0);
	bool rtn = pThis->GetEntity()->ScrollPages(pages);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, ScrollWindow)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ScrollWindow)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int dx = args.GetInt(0);
	int dy = args.GetInt(1);
	wxRect *rect = (wxRect *)(NULL);
	if (args.IsValid(2)) rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->ScrollWindow(dx, dy, rect);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetAcceleratorTable)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "accel", VTYPE_wx_AcceleratorTable, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetAcceleratorTable)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxAcceleratorTable *accel = Object_wx_AcceleratorTable::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetAcceleratorTable(*accel);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetAccessible)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "accessible", VTYPE_wx_Accessible, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, SetAccessible)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxAccessible *accessible = Object_wx_Accessible::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetAccessible(accessible);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetAutoLayout)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "autoLayout", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetAutoLayout)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool autoLayout = args.GetBoolean(0);
	pThis->GetEntity()->SetAutoLayout(autoLayout);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetBackgroundColour)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetBackgroundColour(*colour);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, SetBackgroundStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetBackgroundStyle)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBackgroundStyle style = static_cast<wxBackgroundStyle>(args.GetInt(0));
	pThis->GetEntity()->SetBackgroundStyle(style);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetInitialSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetInitialSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(0)) size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetInitialSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetCaret)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "caret", VTYPE_wx_Caret, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetCaret)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCaret *caret = Object_wx_Caret::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetCaret(caret);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetClientSizeWH)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetClientSizeWH)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	pThis->GetEntity()->SetClientSize(width, height);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetClientSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetClientSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetClientSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetConstraints)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "constraints", VTYPE_wx_LayoutConstraints, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetConstraints)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLayoutConstraints *constraints = Object_wx_LayoutConstraints::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetConstraints(constraints);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetContainingSizer)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizer", VTYPE_wx_Sizer, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetContainingSizer)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetContainingSizer(sizer);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetCursor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetCursor)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCursor *cursor = Object_wx_Cursor::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetCursor(*cursor);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetDropTarget)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "target", VTYPE_wx_DropTarget, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetDropTarget)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDropTarget *target = Object_wx_DropTarget::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDropTarget(target);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetInitialBestSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, SetInitialBestSize)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetInitialBestSize(*size);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetEventHandler)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_EvtHandler, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetEventHandler)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvtHandler *handler = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetEventHandler(handler);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetExtraStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "exStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetExtraStyle)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long exStyle = args.GetLong(0);
	pThis->GetEntity()->SetExtraStyle(exStyle);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetFocus)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, SetFocus)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->SetFocus();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetFocusFromKbd)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, SetFocusFromKbd)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->SetFocusFromKbd();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetFont)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetForegroundColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetForegroundColour)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetForegroundColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetHelpText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "helpText", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetHelpText)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString helpText = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetHelpText(helpText);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetId)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetId)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	pThis->GetEntity()->SetId(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetLabel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetLabel)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString label = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetLabel(label);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetMaxSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetMaxSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetMaxSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetMinSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetMinSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetMinSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetName)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetOwnBackgroundColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetOwnBackgroundColour)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetOwnBackgroundColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetOwnFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetOwnFont)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetOwnFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetOwnForegroundColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetOwnForegroundColour)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetOwnForegroundColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetPalette)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Window, SetPalette)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPalette *palette = Object_wx_Palette::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPalette(palette);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetScrollbar)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "thumbSize", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "refresh", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetScrollbar)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int orientation = args.GetInt(0);
	int position = args.GetInt(1);
	int thumbSize = args.GetInt(2);
	int range = args.GetInt(3);
	bool refresh = true;
	if (args.IsValid(4)) refresh = args.GetBoolean(4);
	pThis->GetEntity()->SetScrollbar(orientation, position, thumbSize, range, refresh);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetScrollPage)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pageSize", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "refresh", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_Window, SetScrollPage)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int orientation = args.GetInt(0);
	int pageSize = args.GetInt(1);
	bool refresh = true;
	if (args.IsValid(2)) refresh = args.GetBoolean(2);
	pThis->GetEntity()->SetScrollPage(orientation, pageSize, refresh);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetScrollPos)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "refresh", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetScrollPos)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int orientation = args.GetInt(0);
	int pos = args.GetInt(1);
	bool refresh = true;
	if (args.IsValid(2)) refresh = args.GetBoolean(2);
	pThis->GetEntity()->SetScrollPos(orientation, pos, refresh);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetScrollRange)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "refresh", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_Window, SetScrollRange)
{
#if 0
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int orientation = args.GetInt(0);
	int range = args.GetInt(1);
	bool refresh = true;
	if (args.IsValid(2)) refresh = args.GetBoolean(2);
	pThis->GetEntity()->SetScrollRange(orientation, range, refresh);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetDimensions)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sizeFlags", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetDimensions)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	int width = args.GetInt(2);
	int height = args.GetInt(3);
	int sizeFlags = wxSIZE_AUTO;
	if (args.IsValid(4)) sizeFlags = args.GetInt(4);
	pThis->GetEntity()->SetSize(x, y, width, height, sizeFlags);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetRect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetRect)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetSize(*rect);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetSizeWH)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetSizeWH)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	pThis->GetEntity()->SetSize(width, height);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetSizer)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizer", VTYPE_wx_Sizer, OCCUR_Once);
	DeclareArg(env, "deleteOld", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetSizer)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
	bool deleteOld = true;
	if (args.IsValid(1)) deleteOld = args.GetBoolean(1);
	pThis->GetEntity()->SetSizer(sizer, deleteOld);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetSizerAndFit)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizer", VTYPE_wx_Sizer, OCCUR_Once);
	DeclareArg(env, "deleteOld", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetSizerAndFit)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
	bool deleteOld = true;
	if (args.IsValid(1)) deleteOld = args.GetBoolean(1);
	pThis->GetEntity()->SetSizerAndFit(sizer, deleteOld);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetThemeEnabled)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetThemeEnabled)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = args.GetBoolean(0);
	pThis->GetEntity()->SetThemeEnabled(enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetToolTipString)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tip", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetToolTipString)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString tip = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetToolTip(tip);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetToolTip)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tip", VTYPE_wx_ToolTip, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetToolTip)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxToolTip *tip = Object_wx_ToolTip::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetToolTip(tip);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetValidator)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetValidator)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxValidator *validator = Object_wx_Validator::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetValidator(*validator);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetVirtualSizeWH)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetVirtualSizeWH)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	pThis->GetEntity()->SetVirtualSize(width, height);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetVirtualSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetVirtualSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetVirtualSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetVirtualSizeHintsWH)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "minW", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minH", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxW", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "maxH", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetVirtualSizeHintsWH)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int minW = args.GetInt(0);
	int minH = args.GetInt(1);
	int maxW = -1;
	if (args.IsValid(2)) maxW = args.GetInt(2);
	int maxH = -1;
	if (args.IsValid(3)) maxH = args.GetInt(3);
	pThis->GetEntity()->SetVirtualSizeHints(minW, minH, maxW, maxH);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetVirtualSizeHints)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "minSize", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "maxSize", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, SetVirtualSizeHints)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *minSize = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(0)) minSize = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxSize *maxSize = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(1)) maxSize = Object_wx_Size::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetVirtualSizeHints(*minSize, *maxSize);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetWindowStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetWindowStyle)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long style = args.GetLong(0);
	pThis->GetEntity()->SetWindowStyle(style);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetWindowStyleFlag)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetWindowStyleFlag)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long style = args.GetLong(0);
	pThis->GetEntity()->SetWindowStyleFlag(style);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, SetWindowVariant)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetWindowVariant)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowVariant variant = static_cast<wxWindowVariant>(args.GetInt(0));
	pThis->GetEntity()->SetWindowVariant(variant);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, ShouldInheritColours)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ShouldInheritColours)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ShouldInheritColours();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, Show)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Show)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool show = true;
	if (args.IsValid(0)) show = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Show(show);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, Thaw)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, Thaw)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Thaw();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, ToggleWindowStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, ToggleWindowStyle)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flag = args.GetInt(0);
	bool rtn = pThis->GetEntity()->ToggleWindowStyle(flag);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, TransferDataFromWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, TransferDataFromWindow)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->TransferDataFromWindow();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, TransferDataToWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, TransferDataToWindow)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->TransferDataToWindow();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, UnregisterHotKey)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hotkeyId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, UnregisterHotKey)
{
#if defined(__WXMSW__)
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int hotkeyId = args.GetInt(0);
	bool rtn = pThis->GetEntity()->UnregisterHotKey(hotkeyId);
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_Window, Update)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, Update)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Update();
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, UpdateWindowUI)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, UpdateWindowUI)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long flags = wxUPDATE_UI_NONE;
	if (args.IsValid(0)) flags = args.GetLong(0);
	pThis->GetEntity()->UpdateWindowUI(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, Validate)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, Validate)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Validate();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Window, WarpPointer)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, WarpPointer)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	pThis->GetEntity()->WarpPointer(x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_Window, WindowToClientSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Window, WindowToClientSize)
{
	Object_wx_Window *pThis = Object_wx_Window::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxSize rtn = pThis->GetEntity()->WindowToClientSize(*size);
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxWindow
//----------------------------------------------------------------------------
Object_wx_Window::~Object_wx_Window()
{
}

Object *Object_wx_Window::Clone() const
{
	return NULL;
}

String Object_wx_Window::ToString(bool exprFlag)
{
	String rtn("<wx.Window:");
	if (GetEntity() == NULL) {
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
	return new Object_wx_Window((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
