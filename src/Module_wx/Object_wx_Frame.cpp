//----------------------------------------------------------------------------
// wxFrame
// extracted from frame.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(CreateStatusBar);
Gura_DeclarePrivUserSymbol(CreateToolBar);
Gura_DeclarePrivUserSymbol(OnCreateStatusBar);
Gura_DeclarePrivUserSymbol(OnCreateToolBar);
Gura_DeclarePrivUserSymbol(SetStatusText);
Gura_DeclarePrivUserSymbol(SetStatusWidths);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Frame: public wxFrame, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Frame *_pObj;
public:
	inline wx_Frame() : wxFrame(), _sig(NULL), _pObj(NULL) {}
	inline wx_Frame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxFrame(parent, id, title, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	//virtual wxStatusBar* CreateStatusBar(int number, long style, wxWindowID id, const wxString& name);
	//virtual wxToolBar* CreateToolBar(long style, wxWindowID id, const wxString& name);
	//virtual wxStatusBar* OnCreateStatusBar(int number, long style, wxWindowID id, const wxString& name);
	//virtual wxToolBar* OnCreateToolBar(long style, wxWindowID id, const wxString& name);
	//virtual void SetStatusText(const wxString& text, int number);
	//virtual void SetStatusWidths(int n, int * widths);
	~wx_Frame();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Frame *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
public:
	// reveal private or protected member functions to public
	void _PositionMenuBar() { wxFrame::PositionMenuBar(); }
	void _DetachMenuBar() { wxFrame::DetachMenuBar(); }
	void _AttachMenuBar(wxMenuBar *menubar) { wxFrame::AttachMenuBar(menubar); }
	void _PositionStatusBar() { wxFrame::PositionStatusBar(); }
	void _PositionToolBar() { wxFrame::PositionToolBar(); }
};

wx_Frame::~wx_Frame()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Frame::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFrame
//----------------------------------------------------------------------------
Gura_DeclareFunction(FrameEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Frame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FrameEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Frame *pEntity = new wx_Frame();
	Object_wx_Frame *pObj = Object_wx_Frame::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Frame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Frame)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Frame));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Frame)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : NULL;
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString title = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxDEFAULT_FRAME_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("frame");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	wx_Frame *pEntity = new wx_Frame(parent, id, title, *pos, *size, style, name);
	Object_wx_Frame *pObj = Object_wx_Frame::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Frame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Frame, Centre)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Frame, Centre)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int direction = wxBOTH;
	if (args.IsValid(0)) direction = args.GetInt(0);
	pSelf->GetEntity()->Centre(direction);
	return Value::Null;
}

Gura_DeclareMethod(wx_Frame, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Frame, Create)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : NULL;
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString title = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxDEFAULT_FRAME_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("frame");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	bool rtn = pSelf->GetEntity()->Create(parent, id, title, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Frame, CreateStatusBar)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "number", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Frame, CreateStatusBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int number = 1;
	if (args.IsValid(0)) number = args.GetInt(0);
	long style = wxST_SIZEGRIP | wxFULL_REPAINT_ON_RESIZE;
	if (args.IsValid(1)) style = args.GetLong(1);
	wxWindowID id = 0;
	if (args.IsValid(2)) id = static_cast<wxWindowID>(args.GetInt(2));
	wxString name = wxT("statusBar");
	if (args.IsValid(3)) name = wxString::FromUTF8(args.GetString(3));
	wxStatusBar *rtn = (wxStatusBar *)pSelf->GetEntity()->CreateStatusBar(number, style, id, name);
	return ReturnValue(env, sig, args, Value(new Object_wx_StatusBar(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Frame, CreateToolBar)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Frame, CreateToolBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long style = wxNO_BORDER | wxTB_HORIZONTAL;
	if (args.IsValid(0)) style = args.GetLong(0);
	wxWindowID id = -1;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxString name = wxT("toolBar");
	if (args.IsValid(2)) name = wxString::FromUTF8(args.GetString(2));
	wxToolBar *rtn = (wxToolBar *)pSelf->GetEntity()->CreateToolBar(style, id, name);
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBar(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Frame, GetClientAreaOrigin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Frame, GetClientAreaOrigin)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pSelf->GetEntity()->GetClientAreaOrigin();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Frame, GetMenuBar)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Frame, GetMenuBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenuBar *rtn = (wxMenuBar *)pSelf->GetEntity()->GetMenuBar();
	Value value;
	if (rtn != NULL) {
		value = Value(new Object_wx_MenuBar(rtn, NULL, OwnerFalse));
	}
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Frame, GetStatusBar)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Frame, GetStatusBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxStatusBar *rtn = (wxStatusBar *)pSelf->GetEntity()->GetStatusBar();
	Value value;
	if (rtn != NULL) {
		value = Value(new Object_wx_StatusBar(rtn, NULL, OwnerFalse));
	}
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Frame, GetStatusBarPane)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Frame, GetStatusBarPane)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetStatusBarPane();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Frame, GetToolBar)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Frame, GetToolBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxToolBar *rtn = (wxToolBar *)pSelf->GetEntity()->GetToolBar();
	Value value;
	if (rtn != NULL) {
		value = Value(new Object_wx_ToolBar(rtn, NULL, OwnerFalse));
	}
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Frame, OnCreateStatusBar)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Frame, OnCreateStatusBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int number = args.GetInt(0);
	long style = args.GetLong(1);
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(2));
	wxString name = wxString::FromUTF8(args.GetString(3));
	wxStatusBar *rtn = (wxStatusBar *)pSelf->GetEntity()->OnCreateStatusBar(number, style, id, name);
	return ReturnValue(env, sig, args, Value(new Object_wx_StatusBar(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Frame, OnCreateToolBar)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Frame, OnCreateToolBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long style = args.GetLong(0);
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString name = wxString::FromUTF8(args.GetString(2));
	wxToolBar *rtn = (wxToolBar *)pSelf->GetEntity()->OnCreateToolBar(style, id, name);
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBar(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Frame, ProcessCommand)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, ProcessCommand)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	pSelf->GetEntity()->ProcessCommand(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_Frame, SendSizeEvent)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, SendSizeEvent)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->SendSizeEvent();
	return Value::Null;
}

Gura_DeclareMethod(wx_Frame, SetMenuBar)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "menuBar", VTYPE_wx_MenuBar, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, SetMenuBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenuBar *menuBar = Object_wx_MenuBar::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetMenuBar(menuBar);
	return Value::Null;
}

Gura_DeclareMethod(wx_Frame, SetStatusBar)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "statusBar", VTYPE_wx_StatusBar, OCCUR_Once, FLAG_Nil);
}

Gura_ImplementMethod(wx_Frame, SetStatusBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxStatusBar *statusBar = args.IsValid(0)?
			Object_wx_StatusBar::GetObject(args, 0)->GetEntity() : NULL;
	pSelf->GetEntity()->SetStatusBar(statusBar);
	return Value::Null;
}

Gura_DeclareMethod(wx_Frame, SetStatusBarPane)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, SetStatusBarPane)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	pSelf->GetEntity()->SetStatusBarPane(n);
	return Value::Null;
}

Gura_DeclareMethod(wx_Frame, SetStatusText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "number", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Frame, SetStatusText)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	int number = 0;
	if (args.IsValid(1)) number = args.GetInt(1);
	pSelf->GetEntity()->SetStatusText(text, number);
	return Value::Null;
}

Gura_DeclareMethod(wx_Frame, SetStatusWidths)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "widths", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_Frame, SetStatusWidths)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	CArrayOfInt widths(args.GetList(0));
	pSelf->GetEntity()->SetStatusWidths(widths.Count(), widths.Data());
	return Value::Null;
}

Gura_DeclareMethod(wx_Frame, SetToolBar)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "toolBar", VTYPE_wx_ToolBar, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, SetToolBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxToolBar *toolBar = Object_wx_ToolBar::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetToolBar(toolBar);
	return Value::Null;
}

Gura_DeclareMethod(wx_Frame, PositionMenuBar)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, PositionMenuBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	dynamic_cast<wx_Frame *>(pSelf->GetEntity())->_PositionMenuBar();
	return Value::Null;
}

Gura_DeclareMethod(wx_Frame, DetachMenuBar)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, DetachMenuBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	dynamic_cast<wx_Frame *>(pSelf->GetEntity())->_DetachMenuBar();
	return Value::Null;
}

Gura_DeclareMethod(wx_Frame, AttachMenuBar)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "menuBar", VTYPE_wx_MenuBar, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, AttachMenuBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenuBar *menuBar = Object_wx_MenuBar::GetObject(args, 0)->GetEntity();
	dynamic_cast<wx_Frame *>(pSelf->GetEntity())->_AttachMenuBar(menuBar);
	return Value::Null;
}

Gura_DeclareMethod(wx_Frame, PositionStatusBar)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, PositionStatusBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	dynamic_cast<wx_Frame *>(pSelf->GetEntity())->_PositionStatusBar();
	return Value::Null;
}

Gura_DeclareMethod(wx_Frame, PositionToolBar)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, PositionToolBar)
{
	Object_wx_Frame *pSelf = Object_wx_Frame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	dynamic_cast<wx_Frame *>(pSelf->GetEntity())->_PositionToolBar();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFrame
//----------------------------------------------------------------------------
Object_wx_Frame::~Object_wx_Frame()
{
}

Object *Object_wx_Frame::Clone() const
{
	return NULL;
}

String Object_wx_Frame::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Frame:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Frame::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(CreateStatusBar);
	Gura_RealizeUserSymbol(CreateToolBar);
	Gura_RealizeUserSymbol(OnCreateStatusBar);
	Gura_RealizeUserSymbol(OnCreateToolBar);
	Gura_RealizeUserSymbol(SetStatusText);
	Gura_RealizeUserSymbol(SetStatusWidths);
	Gura_AssignFunction(FrameEmpty);
	Gura_AssignFunction(Frame);
}

//----------------------------------------------------------------------------
// Class implementation for wxFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Frame)
{
	Gura_AssignMethod(wx_Frame, Centre);
	Gura_AssignMethod(wx_Frame, Create);
	Gura_AssignMethod(wx_Frame, CreateStatusBar);
	Gura_AssignMethod(wx_Frame, CreateToolBar);
	Gura_AssignMethod(wx_Frame, GetClientAreaOrigin);
	Gura_AssignMethod(wx_Frame, GetMenuBar);
	Gura_AssignMethod(wx_Frame, GetStatusBar);
	Gura_AssignMethod(wx_Frame, GetStatusBarPane);
	Gura_AssignMethod(wx_Frame, GetToolBar);
	Gura_AssignMethod(wx_Frame, OnCreateStatusBar);
	Gura_AssignMethod(wx_Frame, OnCreateToolBar);
	Gura_AssignMethod(wx_Frame, ProcessCommand);
	Gura_AssignMethod(wx_Frame, SendSizeEvent);
	Gura_AssignMethod(wx_Frame, SetMenuBar);
	Gura_AssignMethod(wx_Frame, SetStatusBar);
	Gura_AssignMethod(wx_Frame, SetStatusBarPane);
	Gura_AssignMethod(wx_Frame, SetStatusText);
	Gura_AssignMethod(wx_Frame, SetStatusWidths);
	Gura_AssignMethod(wx_Frame, SetToolBar);
	Gura_AssignMethod(wx_Frame, PositionMenuBar);
	Gura_AssignMethod(wx_Frame, DetachMenuBar);
	Gura_AssignMethod(wx_Frame, AttachMenuBar);
	Gura_AssignMethod(wx_Frame, PositionStatusBar);
	Gura_AssignMethod(wx_Frame, PositionToolBar);
}

Gura_ImplementDescendantCreator(wx_Frame)
{
	return new Object_wx_Frame((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
