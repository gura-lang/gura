//----------------------------------------------------------------------------
// wxScrolledWindow
// extracted from scrolwin.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(OnDraw);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ScrolledWindow: public wxScrolledWindow, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	AutoPtr<Object_wx_ScrolledWindow> _pObj;
public:
	inline wx_ScrolledWindow() : wxScrolledWindow(), _sig(NULL), _pObj(NULL) {}
	inline wx_ScrolledWindow(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxScrolledWindow(parent, id, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	virtual void OnDraw(wxDC& dc);
	~wx_ScrolledWindow();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ScrolledWindow *pObj) {
		_sig = sig, _pObj.reset(Object_wx_ScrolledWindow::Reference(pObj));
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ScrolledWindow::~wx_ScrolledWindow()
{
}

void wx_ScrolledWindow::GuraObjectDeleted()
{
}

void wx_ScrolledWindow::OnDraw(wxDC& dc)
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(OnDraw), true);
	if (pFunc == NULL) {
		wxScrolledWindow::OnDraw(dc);
		return;
	}
	ValueList valList;
	valList.push_back(Value(new Object_wx_DC(&dc, NULL, OwnerFalse)));
	_pObj->EvalMethod(_sig, pFunc, valList);
	CheckMethodResult(_sig);
}

//----------------------------------------------------------------------------
// Gura interfaces for wxScrolledWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(ScrolledWindowEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ScrolledWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ScrolledWindowEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ScrolledWindow *pEntity = new wx_ScrolledWindow();
	Object_wx_ScrolledWindow *pObj = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ScrolledWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(ScrolledWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ScrolledWindow));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ScrolledWindow)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = -1;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxHSCROLL | wxVSCROLL;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("scrolledWindow");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_ScrolledWindow *pEntity = new wx_ScrolledWindow(parent, id, *pos, *size, style, name);
	Object_wx_ScrolledWindow *pObj = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ScrolledWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_ScrolledWindow, CalcScrolledPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrolledWindow, CalcScrolledPosition)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	int xx;
	int yy;
	pSelf->GetEntity()->CalcScrolledPosition(x, y, &xx, &yy);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, xx, yy));
}

Gura_DeclareMethod(wx_ScrolledWindow, CalcUnscrolledPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrolledWindow, CalcUnscrolledPosition)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	int xx;
	int yy;
	pSelf->GetEntity()->CalcUnscrolledPosition(x, y, &xx, &yy);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, xx, yy));
}

Gura_DeclareMethod(wx_ScrolledWindow, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrolledWindow, Create)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = -1;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxHSCROLL | wxVSCROLL;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("scrolledWindow");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	bool rtn = pSelf->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ScrolledWindow, EnableScrolling)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "xScrolling", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "yScrolling", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrolledWindow, EnableScrolling)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool xScrolling = args.GetBoolean(0);
	bool yScrolling = args.GetBoolean(1);
	pSelf->GetEntity()->EnableScrolling(xScrolling, yScrolling);
	return Value::Null;
}

Gura_DeclareMethod(wx_ScrolledWindow, GetScrollPixelsPerUnit)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrolledWindow, GetScrollPixelsPerUnit)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int xUnit;
	int yUnit;
	pSelf->GetEntity()->GetScrollPixelsPerUnit(&xUnit, &yUnit);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, xUnit, yUnit));
}

Gura_DeclareMethod(wx_ScrolledWindow, GetViewStart)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrolledWindow, GetViewStart)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x;
	int y;
	pSelf->GetEntity()->GetViewStart(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, x, y));
}

Gura_DeclareMethod(wx_ScrolledWindow, GetVirtualSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrolledWindow, GetVirtualSize)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x;
	int y;
	pSelf->GetEntity()->GetVirtualSize(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, x, y));
}

Gura_DeclareMethod(wx_ScrolledWindow, IsRetained)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrolledWindow, IsRetained)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsRetained();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ScrolledWindow, DoPrepareDC)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrolledWindow, DoPrepareDC)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->DoPrepareDC(*dc);
	return Value::Null;
}

Gura_DeclareMethod(wx_ScrolledWindow, OnDraw)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrolledWindow, OnDraw)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->wxScrolledWindow::OnDraw(*dc);
	return Value::Null;
}

Gura_DeclareMethod(wx_ScrolledWindow, PrepareDC)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrolledWindow, PrepareDC)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->PrepareDC(*dc);
	return Value::Null;
}

Gura_DeclareMethod(wx_ScrolledWindow, Scroll)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrolledWindow, Scroll)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	pSelf->GetEntity()->Scroll(x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_ScrolledWindow, SetScrollbars)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pixelsPerUnitX", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pixelsPerUnitY", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "noUnitsX", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "noUnitsY", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xPos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "yPos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "noRefresh", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrolledWindow, SetScrollbars)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int pixelsPerUnitX = args.GetInt(0);
	int pixelsPerUnitY = args.GetInt(1);
	int noUnitsX = args.GetInt(2);
	int noUnitsY = args.GetInt(3);
	int xPos = 0;
	if (args.IsValid(4)) xPos = args.GetInt(4);
	int yPos = 0;
	if (args.IsValid(5)) yPos = args.GetInt(5);
	bool noRefresh = false;
	if (args.IsValid(6)) noRefresh = args.GetBoolean(6);
	pSelf->GetEntity()->SetScrollbars(pixelsPerUnitX, pixelsPerUnitY, noUnitsX, noUnitsY, xPos, yPos, noRefresh);
	return Value::Null;
}

Gura_DeclareMethod(wx_ScrolledWindow, SetScrollRate)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "xstep", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ystep", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrolledWindow, SetScrollRate)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int xstep = args.GetInt(0);
	int ystep = args.GetInt(1);
	pSelf->GetEntity()->SetScrollRate(xstep, ystep);
	return Value::Null;
}

Gura_DeclareMethod(wx_ScrolledWindow, SetTargetWindow)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrolledWindow, SetTargetWindow)
{
	Object_wx_ScrolledWindow *pSelf = Object_wx_ScrolledWindow::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetTargetWindow(window);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxScrolledWindow
//----------------------------------------------------------------------------
Object_wx_ScrolledWindow::~Object_wx_ScrolledWindow()
{
}

Object *Object_wx_ScrolledWindow::Clone() const
{
	return NULL;
}

String Object_wx_ScrolledWindow::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ScrolledWindow:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ScrolledWindow::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(OnDraw);
	Gura_AssignFunction(ScrolledWindowEmpty);
	Gura_AssignFunction(ScrolledWindow);
}

//----------------------------------------------------------------------------
// Class implementation for wxScrolledWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScrolledWindow)
{
	Gura_AssignMethod(wx_ScrolledWindow, CalcScrolledPosition);
	Gura_AssignMethod(wx_ScrolledWindow, CalcUnscrolledPosition);
	Gura_AssignMethod(wx_ScrolledWindow, Create);
	Gura_AssignMethod(wx_ScrolledWindow, EnableScrolling);
	Gura_AssignMethod(wx_ScrolledWindow, GetScrollPixelsPerUnit);
	Gura_AssignMethod(wx_ScrolledWindow, GetViewStart);
	Gura_AssignMethod(wx_ScrolledWindow, GetVirtualSize);
	Gura_AssignMethod(wx_ScrolledWindow, IsRetained);
	Gura_AssignMethod(wx_ScrolledWindow, DoPrepareDC);
	Gura_AssignMethod(wx_ScrolledWindow, OnDraw);
	Gura_AssignMethod(wx_ScrolledWindow, PrepareDC);
	Gura_AssignMethod(wx_ScrolledWindow, Scroll);
	Gura_AssignMethod(wx_ScrolledWindow, SetScrollbars);
	Gura_AssignMethod(wx_ScrolledWindow, SetScrollRate);
	Gura_AssignMethod(wx_ScrolledWindow, SetTargetWindow);
}

Gura_ImplementDescendantCreator(wx_ScrolledWindow)
{
	return new Object_wx_ScrolledWindow((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
