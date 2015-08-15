//----------------------------------------------------------------------------
// wxScrolledWindow
// extracted from scrolwin.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(OnDraw);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ScrolledWindow: public wxScrolledWindow, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	AutoPtr<Object_wx_ScrolledWindow> _pObj;
public:
	inline wx_ScrolledWindow() : wxScrolledWindow(), _pObj(nullptr) {}
	inline wx_ScrolledWindow(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxScrolledWindow(parent, id, pos, size, style, name), _pObj(nullptr) {}
	virtual void OnDraw(wxDC& dc);
	~wx_ScrolledWindow();
	inline void AssocWithGura(Object_wx_ScrolledWindow *pObj) {
		_pObj.reset(Object_wx_ScrolledWindow::Reference(pObj));
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
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnDraw);
	if (pFunc == nullptr) {
		wxScrolledWindow::OnDraw(dc);
		return;
	}
	ValueList valList;
	valList.push_back(Value(new Object_wx_DC(&dc, nullptr, OwnerFalse)));
	_pObj->EvalMethod(*_pObj, pFunc, valList);
	CheckMethodResult(_pObj->GetSignal());
}

//----------------------------------------------------------------------------
// Gura interfaces for wxScrolledWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(ScrolledWindowEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ScrolledWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ScrolledWindowEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_ScrolledWindow *pEntity = new wx_ScrolledWindow();
	Object_wx_ScrolledWindow *pObj = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ScrolledWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(ScrolledWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
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
	Object_wx_ScrolledWindow *pObj = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ScrolledWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_ScrolledWindow, CalcScrolledPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrolledWindow, CalcScrolledPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	int xx;
	int yy;
	pThis->GetEntity()->CalcScrolledPosition(x, y, &xx, &yy);
	return ReturnValue(env, args, Value::CreateList(env, xx, yy));
}

Gura_DeclareMethod(wx_ScrolledWindow, CalcUnscrolledPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrolledWindow, CalcUnscrolledPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	int xx;
	int yy;
	pThis->GetEntity()->CalcUnscrolledPosition(x, y, &xx, &yy);
	return ReturnValue(env, args, Value::CreateList(env, xx, yy));
}

Gura_DeclareMethod(wx_ScrolledWindow, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ScrolledWindow, EnableScrolling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "xScrolling", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "yScrolling", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrolledWindow, EnableScrolling)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool xScrolling = args.GetBoolean(0);
	bool yScrolling = args.GetBoolean(1);
	pThis->GetEntity()->EnableScrolling(xScrolling, yScrolling);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrolledWindow, GetScrollPixelsPerUnit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrolledWindow, GetScrollPixelsPerUnit)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int xUnit;
	int yUnit;
	pThis->GetEntity()->GetScrollPixelsPerUnit(&xUnit, &yUnit);
	return ReturnValue(env, args, Value::CreateList(env, xUnit, yUnit));
}

Gura_DeclareMethod(wx_ScrolledWindow, GetViewStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrolledWindow, GetViewStart)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x;
	int y;
	pThis->GetEntity()->GetViewStart(&x, &y);
	return ReturnValue(env, args, Value::CreateList(env, x, y));
}

Gura_DeclareMethod(wx_ScrolledWindow, GetVirtualSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrolledWindow, GetVirtualSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x;
	int y;
	pThis->GetEntity()->GetVirtualSize(&x, &y);
	return ReturnValue(env, args, Value::CreateList(env, x, y));
}

Gura_DeclareMethod(wx_ScrolledWindow, IsRetained)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrolledWindow, IsRetained)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsRetained();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ScrolledWindow, DoPrepareDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrolledWindow, DoPrepareDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->DoPrepareDC(*dc);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrolledWindow, OnDraw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrolledWindow, OnDraw)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->wxScrolledWindow::OnDraw(*dc);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrolledWindow, PrepareDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrolledWindow, PrepareDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->PrepareDC(*dc);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrolledWindow, Scroll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrolledWindow, Scroll)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	pThis->GetEntity()->Scroll(x, y);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrolledWindow, SetScrollbars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	pThis->GetEntity()->SetScrollbars(pixelsPerUnitX, pixelsPerUnitY, noUnitsX, noUnitsY, xPos, yPos, noRefresh);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrolledWindow, SetScrollRate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "xstep", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ystep", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrolledWindow, SetScrollRate)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int xstep = args.GetInt(0);
	int ystep = args.GetInt(1);
	pThis->GetEntity()->SetScrollRate(xstep, ystep);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrolledWindow, SetTargetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrolledWindow, SetTargetWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrolledWindow *pThis = Object_wx_ScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTargetWindow(window);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxScrolledWindow
//----------------------------------------------------------------------------
Object_wx_ScrolledWindow::~Object_wx_ScrolledWindow()
{
}

Object *Object_wx_ScrolledWindow::Clone() const
{
	return nullptr;
}

String Object_wx_ScrolledWindow::ToString(bool exprFlag)
{
	String rtn("<wx.ScrolledWindow:");
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
// Class implementation for wxScrolledWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScrolledWindow)
{
	Gura_RealizeUserSymbol(OnDraw);
	Gura_AssignFunction(ScrolledWindowEmpty);
	Gura_AssignFunction(ScrolledWindow);
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
	return new Object_wx_ScrolledWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
