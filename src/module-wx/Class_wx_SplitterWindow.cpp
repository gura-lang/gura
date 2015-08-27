//----------------------------------------------------------------------------
// wxSplitterWindow
// extracted from splitter.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(OnDoubleClickSash);
Gura_DeclarePrivUserSymbol(OnUnsplit);
Gura_DeclarePrivUserSymbol(OnSashPositionChange);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SplitterWindow: public wxSplitterWindow, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SplitterWindow *_pObj;
public:
	inline wx_SplitterWindow() : wxSplitterWindow(), _pObj(nullptr) {}
	inline wx_SplitterWindow(wxWindow* parent, wxWindowID id, const wxPoint& point, const wxSize& size, long style, const wxString& name) : wxSplitterWindow(parent, id, point, size, style, name), _pObj(nullptr) {}
	//virtual void OnDoubleClickSash(int x, int y);
	//virtual void OnUnsplit(wxWindow* removed);
	//virtual bool OnSashPositionChange(int newSashPosition);
	~wx_SplitterWindow();
	inline void AssocWithGura(Object_wx_SplitterWindow *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SplitterWindow::~wx_SplitterWindow()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SplitterWindow::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSplitterWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(SplitterWindowEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SplitterWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SplitterWindowEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_SplitterWindow *pEntity = new wx_SplitterWindow();
	Object_wx_SplitterWindow *pObj = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SplitterWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(SplitterWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SplitterWindow));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SplitterWindow)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *point = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) point = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxSP_3D;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("splitterWindow");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_SplitterWindow *pEntity = new wx_SplitterWindow(parent, id, *point, *size, style, name);
	Object_wx_SplitterWindow *pObj = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SplitterWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_SplitterWindow, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterWindow, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *point = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) point = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxSP_3D;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("splitterWindow");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	bool rtn = pThis->GetEntity()->Create(parent, id, *point, *size, style, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplitterWindow, GetMinimumPaneSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterWindow, GetMinimumPaneSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetMinimumPaneSize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplitterWindow, GetSashGravity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterWindow, GetSashGravity)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double rtn = pThis->GetEntity()->GetSashGravity();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplitterWindow, GetSashPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterWindow, GetSashPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSashPosition();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplitterWindow, GetSplitMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterWindow, GetSplitMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSplitMode();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplitterWindow, GetWindow1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterWindow, GetWindow1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetWindow1();
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_SplitterWindow, GetWindow2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterWindow, GetWindow2)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetWindow2();
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_SplitterWindow, Initialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, Initialize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Initialize(window);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, IsSplit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterWindow, IsSplit)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsSplit();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplitterWindow, OnDoubleClickSash)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, OnDoubleClickSash)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	pThis->GetEntity()->OnDoubleClickSash(x, y);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, OnUnsplit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "removed", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, OnUnsplit)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *removed = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnUnsplit(removed);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, OnSashPositionChange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "newSashPosition", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterWindow, OnSashPositionChange)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int newSashPosition = args.GetInt(0);
	bool rtn = pThis->GetEntity()->OnSashPositionChange(newSashPosition);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplitterWindow, ReplaceWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "winOld", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "winNew", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterWindow, ReplaceWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *winOld = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindow *winNew = Object_wx_Window::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->ReplaceWindow(winOld, winNew);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplitterWindow, SetSashGravity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "gravity", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, SetSashGravity)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double gravity = args.GetDouble(0);
	pThis->GetEntity()->SetSashGravity(gravity);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, SetSashPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "redraw", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterWindow, SetSashPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int position = args.GetInt(0);
	bool redraw = true;
	if (args.IsValid(1)) redraw = args.GetBoolean(1);
	pThis->GetEntity()->SetSashPosition(position, redraw);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, SetSashSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, SetSashSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int size = args.GetInt(0);
	pThis->GetEntity()->SetSashSize(size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, SetMinimumPaneSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "paneSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, SetMinimumPaneSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int paneSize = args.GetInt(0);
	pThis->GetEntity()->SetMinimumPaneSize(paneSize);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, SetSplitMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, SetSplitMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int mode = args.GetInt(0);
	pThis->GetEntity()->SetSplitMode(mode);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, SplitHorizontally)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window1", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "window2", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "sashPosition", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterWindow, SplitHorizontally)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window1 = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindow *window2 = Object_wx_Window::GetObject(args, 1)->GetEntity();
	int sashPosition = 0;
	if (args.IsValid(2)) sashPosition = args.GetInt(2);
	bool rtn = pThis->GetEntity()->SplitHorizontally(window1, window2, sashPosition);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplitterWindow, SplitVertically)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window1", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "window2", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "sashPosition", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterWindow, SplitVertically)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window1 = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindow *window2 = Object_wx_Window::GetObject(args, 1)->GetEntity();
	int sashPosition = 0;
	if (args.IsValid(2)) sashPosition = args.GetInt(2);
	bool rtn = pThis->GetEntity()->SplitVertically(window1, window2, sashPosition);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplitterWindow, Unsplit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "toRemove", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplitterWindow, Unsplit)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *toRemove = (wxWindow *)(nullptr);
	if (args.IsValid(0)) toRemove = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Unsplit(toRemove);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplitterWindow, UpdateSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, UpdateSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->UpdateSize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxSplitterWindow
//----------------------------------------------------------------------------
Object_wx_SplitterWindow::~Object_wx_SplitterWindow()
{
}

Object *Object_wx_SplitterWindow::Clone() const
{
	return nullptr;
}

String Object_wx_SplitterWindow::ToString(bool exprFlag)
{
	String rtn("<wx.SplitterWindow:");
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
// Class implementation for wxSplitterWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SplitterWindow)
{
	Gura_RealizeUserSymbol(OnDoubleClickSash);
	Gura_RealizeUserSymbol(OnUnsplit);
	Gura_RealizeUserSymbol(OnSashPositionChange);
	Gura_AssignFunction(SplitterWindowEmpty);
	Gura_AssignFunction(SplitterWindow);
	Gura_AssignMethod(wx_SplitterWindow, Create);
	Gura_AssignMethod(wx_SplitterWindow, GetMinimumPaneSize);
	Gura_AssignMethod(wx_SplitterWindow, GetSashGravity);
	Gura_AssignMethod(wx_SplitterWindow, GetSashPosition);
	Gura_AssignMethod(wx_SplitterWindow, GetSplitMode);
	Gura_AssignMethod(wx_SplitterWindow, GetWindow1);
	Gura_AssignMethod(wx_SplitterWindow, GetWindow2);
	Gura_AssignMethod(wx_SplitterWindow, Initialize);
	Gura_AssignMethod(wx_SplitterWindow, IsSplit);
	Gura_AssignMethod(wx_SplitterWindow, OnDoubleClickSash);
	Gura_AssignMethod(wx_SplitterWindow, OnUnsplit);
	Gura_AssignMethod(wx_SplitterWindow, OnSashPositionChange);
	Gura_AssignMethod(wx_SplitterWindow, ReplaceWindow);
	Gura_AssignMethod(wx_SplitterWindow, SetSashGravity);
	Gura_AssignMethod(wx_SplitterWindow, SetSashPosition);
	Gura_AssignMethod(wx_SplitterWindow, SetSashSize);
	Gura_AssignMethod(wx_SplitterWindow, SetMinimumPaneSize);
	Gura_AssignMethod(wx_SplitterWindow, SetSplitMode);
	Gura_AssignMethod(wx_SplitterWindow, SplitHorizontally);
	Gura_AssignMethod(wx_SplitterWindow, SplitVertically);
	Gura_AssignMethod(wx_SplitterWindow, Unsplit);
	Gura_AssignMethod(wx_SplitterWindow, UpdateSize);
}

Gura_ImplementDescendantCreator(wx_SplitterWindow)
{
	return new Object_wx_SplitterWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
