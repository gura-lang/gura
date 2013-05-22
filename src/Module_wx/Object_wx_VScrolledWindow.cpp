//----------------------------------------------------------------------------
// wxVScrolledWindow
// extracted from vscroll.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(EstimateTotalHeight);
Gura_DeclarePrivUserSymbol(OnGetLineHeight);
Gura_DeclarePrivUserSymbol(OnGetLinesHint);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_VScrolledWindow: public wxVScrolledWindow, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_VScrolledWindow *_pObj;
public:
	//inline wx_VScrolledWindow(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxVScrolledWindow(parent, id, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	//inline wx_VScrolledWindow() : wxVScrolledWindow(), _sig(NULL), _pObj(NULL) {}
	//virtual wxCoord EstimateTotalHeight();
	//virtual wxCoord OnGetLineHeight(size_t n);
	//virtual void OnGetLinesHint(size_t lineMin, size_t lineMax);
	~wx_VScrolledWindow();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_VScrolledWindow *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_VScrolledWindow::~wx_VScrolledWindow()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_VScrolledWindow::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxVScrolledWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(VScrolledWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_VScrolledWindow));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(VScrolledWindow)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxPanelNameStr;
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_VScrolledWindow *pEntity = new wx_VScrolledWindow(parent, id, *pos, *size, style, name);
	Object_wx_VScrolledWindow *pObj = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_VScrolledWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(VScrolledWindowEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_VScrolledWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(VScrolledWindowEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_VScrolledWindow *pEntity = new wx_VScrolledWindow();
	Object_wx_VScrolledWindow *pObj = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_VScrolledWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_VScrolledWindow, Create)
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

Gura_ImplementMethod(wx_VScrolledWindow, Create)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxPanelNameStr;
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VScrolledWindow, EstimateTotalHeight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VScrolledWindow, EstimateTotalHeight)
{
#if 0
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->EstimateTotalHeight();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_VScrolledWindow, GetFirstVisibleLine)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VScrolledWindow, GetFirstVisibleLine)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetFirstVisibleLine();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VScrolledWindow, GetLastVisibleLine)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VScrolledWindow, GetLastVisibleLine)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetLastVisibleLine();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VScrolledWindow, GetLineCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VScrolledWindow, GetLineCount)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetLineCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VScrolledWindow, GetVisibleBegin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VScrolledWindow, GetVisibleBegin)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetVisibleBegin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VScrolledWindow, GetVisibleEnd)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VScrolledWindow, GetVisibleEnd)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetVisibleEnd();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VScrolledWindow, HitTest)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VScrolledWindow, HitTest)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	int rtn = pThis->GetEntity()->HitTest(x, y);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VScrolledWindow, HitTest_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VScrolledWindow, HitTest_1)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	int rtn = pThis->GetEntity()->HitTest(*pt);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VScrolledWindow, IsVisible)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VScrolledWindow, IsVisible)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t line = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->IsVisible(line);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VScrolledWindow, OnGetLineHeight)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VScrolledWindow, OnGetLineHeight)
{
#if 0
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxCoord rtn = pThis->GetEntity()->OnGetLineHeight(n);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_VScrolledWindow, OnGetLinesHint)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "lineMin", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "lineMax", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_VScrolledWindow, OnGetLinesHint)
{
#if 0
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t lineMin = args.GetSizeT(0);
	size_t lineMax = args.GetSizeT(1);
	pThis->GetEntity()->OnGetLinesHint(lineMin, lineMax);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_VScrolledWindow, RefreshLine)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VScrolledWindow, RefreshLine)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t line = args.GetSizeT(0);
	pThis->GetEntity()->RefreshLine(line);
	return Value::Null;
}

Gura_DeclareMethod(wx_VScrolledWindow, RefreshLines)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VScrolledWindow, RefreshLines)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t from = args.GetSizeT(0);
	size_t to = args.GetSizeT(1);
	pThis->GetEntity()->RefreshLines(from, to);
	return Value::Null;
}

Gura_DeclareMethod(wx_VScrolledWindow, RefreshAll)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VScrolledWindow, RefreshAll)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->RefreshAll();
	return Value::Null;
}

Gura_DeclareMethod(wx_VScrolledWindow, ScrollLines)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lines", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VScrolledWindow, ScrollLines)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int lines = args.GetInt(0);
	bool rtn = pThis->GetEntity()->ScrollLines(lines);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VScrolledWindow, ScrollPages)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VScrolledWindow, ScrollPages)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pages = args.GetInt(0);
	bool rtn = pThis->GetEntity()->ScrollPages(pages);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VScrolledWindow, ScrollToLine)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VScrolledWindow, ScrollToLine)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t line = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->ScrollToLine(line);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VScrolledWindow, SetLineCount)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VScrolledWindow, SetLineCount)
{
	Object_wx_VScrolledWindow *pThis = Object_wx_VScrolledWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t count = args.GetSizeT(0);
	pThis->GetEntity()->SetLineCount(count);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxVScrolledWindow
//----------------------------------------------------------------------------
Object_wx_VScrolledWindow::~Object_wx_VScrolledWindow()
{
}

Object *Object_wx_VScrolledWindow::Clone() const
{
	return NULL;
}

String Object_wx_VScrolledWindow::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.VScrolledWindow:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_VScrolledWindow::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(EstimateTotalHeight);
	Gura_RealizeUserSymbol(OnGetLineHeight);
	Gura_RealizeUserSymbol(OnGetLinesHint);
	Gura_AssignFunction(VScrolledWindow);
	Gura_AssignFunction(VScrolledWindowEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxVScrolledWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VScrolledWindow)
{
	Gura_AssignMethod(wx_VScrolledWindow, Create);
	Gura_AssignMethod(wx_VScrolledWindow, EstimateTotalHeight);
	Gura_AssignMethod(wx_VScrolledWindow, GetFirstVisibleLine);
	Gura_AssignMethod(wx_VScrolledWindow, GetLastVisibleLine);
	Gura_AssignMethod(wx_VScrolledWindow, GetLineCount);
	Gura_AssignMethod(wx_VScrolledWindow, GetVisibleBegin);
	Gura_AssignMethod(wx_VScrolledWindow, GetVisibleEnd);
	Gura_AssignMethod(wx_VScrolledWindow, HitTest);
	Gura_AssignMethod(wx_VScrolledWindow, HitTest_1);
	Gura_AssignMethod(wx_VScrolledWindow, IsVisible);
	Gura_AssignMethod(wx_VScrolledWindow, OnGetLineHeight);
	Gura_AssignMethod(wx_VScrolledWindow, OnGetLinesHint);
	Gura_AssignMethod(wx_VScrolledWindow, RefreshLine);
	Gura_AssignMethod(wx_VScrolledWindow, RefreshLines);
	Gura_AssignMethod(wx_VScrolledWindow, RefreshAll);
	Gura_AssignMethod(wx_VScrolledWindow, ScrollLines);
	Gura_AssignMethod(wx_VScrolledWindow, ScrollPages);
	Gura_AssignMethod(wx_VScrolledWindow, ScrollToLine);
	Gura_AssignMethod(wx_VScrolledWindow, SetLineCount);
}

Gura_ImplementDescendantCreator(wx_VScrolledWindow)
{
	return new Object_wx_VScrolledWindow((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
