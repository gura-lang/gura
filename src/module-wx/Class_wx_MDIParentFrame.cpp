//----------------------------------------------------------------------------
// wxMDIParentFrame
// extracted from mdi.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(GetClientSize);
Gura_DeclarePrivUserSymbol(GetToolBar);
Gura_DeclarePrivUserSymbol(OnCreateClient);
Gura_DeclarePrivUserSymbol(SetToolBar);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MDIParentFrame: public wxMDIParentFrame, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MDIParentFrame *_pObj;
public:
	inline wx_MDIParentFrame() : wxMDIParentFrame(), _pObj(nullptr) {}
	inline wx_MDIParentFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxMDIParentFrame(parent, id, title, pos, size, style, name), _pObj(nullptr) {}
	//virtual void GetClientSize(int* width, int* height);
	//virtual wxWindow* GetToolBar();
	//virtual wxMDIClientWindow* OnCreateClient();
	//virtual void SetToolBar(wxWindow* toolbar);
	~wx_MDIParentFrame();
	inline void AssocWithGura(Object_wx_MDIParentFrame *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MDIParentFrame::~wx_MDIParentFrame()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MDIParentFrame::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMDIParentFrame
//----------------------------------------------------------------------------
Gura_DeclareFunction(MDIParentFrameEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MDIParentFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MDIParentFrameEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_MDIParentFrame *pEntity = new wx_MDIParentFrame();
	Object_wx_MDIParentFrame *pObj = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MDIParentFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(MDIParentFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MDIParentFrame));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MDIParentFrame)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = arg.IsValid(0)?
			Object_wx_Window::GetObject(arg, 0)->GetEntity() : nullptr;
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString title = wxString::FromUTF8(arg.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxDEFAULT_FRAME_STYLE | wxVSCROLL | wxHSCROLL;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxT("frame");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	wx_MDIParentFrame *pEntity = new wx_MDIParentFrame(parent, id, title, *pos, *size, style, name);
	Object_wx_MDIParentFrame *pObj = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MDIParentFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_MDIParentFrame, ActivateNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, ActivateNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->ActivateNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, ActivatePrevious)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, ActivatePrevious)
{
	Signal &sig = env.GetSignal();
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->ActivatePrevious();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, ArrangeIcons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, ArrangeIcons)
{
	Signal &sig = env.GetSignal();
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->ArrangeIcons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, Cascade)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, Cascade)
{
	Signal &sig = env.GetSignal();
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Cascade();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MDIParentFrame, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = arg.IsValid(0)?
			Object_wx_Window::GetObject(arg, 0)->GetEntity() : nullptr;
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString title = wxString::FromUTF8(arg.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxDEFAULT_FRAME_STYLE | wxVSCROLL | wxHSCROLL;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxT("frame");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	bool rtn = pThis->GetEntity()->Create(parent, id, title, *pos, *size, style, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MDIParentFrame, GetClientSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_MDIParentFrame, GetClientSize)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	pThis->GetEntity()->GetClientSize(width, height);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, GetActiveChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MDIParentFrame, GetActiveChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMDIChildFrame *rtn = (wxMDIChildFrame *)pThis->GetEntity()->GetActiveChild();
	return ReturnValue(env, arg, Value(new Object_wx_MDIChildFrame(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_MDIParentFrame, GetClientWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MDIParentFrame, GetClientWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMDIClientWindow *rtn = (wxMDIClientWindow *)pThis->GetEntity()->GetClientWindow();
	return ReturnValue(env, arg, Value(new Object_wx_MDIClientWindow(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_MDIParentFrame, GetToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MDIParentFrame, GetToolBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxToolBar *rtn = (wxToolBar *)pThis->GetEntity()->GetToolBar();
	return ReturnValue(env, arg, Value(new Object_wx_ToolBar(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_MDIParentFrame, GetWindowMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MDIParentFrame, GetWindowMenu)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenu *rtn = (wxMenu *)pThis->GetEntity()->GetWindowMenu();
	return ReturnValue(env, arg, Value(new Object_wx_Menu(rtn, nullptr, OwnerFalse)));
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}

Gura_DeclareMethod(wx_MDIParentFrame, OnCreateClient)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MDIParentFrame, OnCreateClient)
{
	Signal &sig = env.GetSignal();
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMDIClientWindow *rtn = (wxMDIClientWindow *)pThis->GetEntity()->OnCreateClient();
	return ReturnValue(env, arg, Value(new Object_wx_MDIClientWindow(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_MDIParentFrame, SetToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "toolbar", VTYPE_wx_Window, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_MDIParentFrame, SetToolBar)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *toolbar = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetToolBar(toolbar);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, SetWindowMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
}

Gura_ImplementMethod(wx_MDIParentFrame, SetWindowMenu)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenu *menu = Object_wx_Menu::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetWindowMenu(menu);
	return Value::Nil;
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}

Gura_DeclareMethod(wx_MDIParentFrame, Tile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "orient", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MDIParentFrame, Tile)
{
	Signal &sig = env.GetSignal();
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxOrientation orient = wxHORIZONTAL;
	if (arg.IsValid(0)) orient = static_cast<wxOrientation>(arg.GetInt(0));
	pThis->GetEntity()->Tile(orient);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxMDIParentFrame
//----------------------------------------------------------------------------
Object_wx_MDIParentFrame::~Object_wx_MDIParentFrame()
{
}

Object *Object_wx_MDIParentFrame::Clone() const
{
	return nullptr;
}

String Object_wx_MDIParentFrame::ToString(bool exprFlag)
{
	String rtn("<wx.MDIParentFrame:");
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
// Class implementation for wxMDIParentFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MDIParentFrame)
{
	Gura_RealizeUserSymbol(GetClientSize);
	Gura_RealizeUserSymbol(GetToolBar);
	Gura_RealizeUserSymbol(OnCreateClient);
	Gura_RealizeUserSymbol(SetToolBar);
	Gura_AssignFunction(MDIParentFrameEmpty);
	Gura_AssignFunction(MDIParentFrame);
	Gura_AssignMethod(wx_MDIParentFrame, ActivateNext);
	Gura_AssignMethod(wx_MDIParentFrame, ActivatePrevious);
	Gura_AssignMethod(wx_MDIParentFrame, ArrangeIcons);
	Gura_AssignMethod(wx_MDIParentFrame, Cascade);
	Gura_AssignMethod(wx_MDIParentFrame, Create);
	Gura_AssignMethod(wx_MDIParentFrame, GetClientSize);
	Gura_AssignMethod(wx_MDIParentFrame, GetActiveChild);
	Gura_AssignMethod(wx_MDIParentFrame, GetClientWindow);
	Gura_AssignMethod(wx_MDIParentFrame, GetToolBar);
	Gura_AssignMethod(wx_MDIParentFrame, GetWindowMenu);
	Gura_AssignMethod(wx_MDIParentFrame, OnCreateClient);
	Gura_AssignMethod(wx_MDIParentFrame, SetToolBar);
	Gura_AssignMethod(wx_MDIParentFrame, SetWindowMenu);
	Gura_AssignMethod(wx_MDIParentFrame, Tile);
}

Gura_ImplementDescendantCreator(wx_MDIParentFrame)
{
	return new Object_wx_MDIParentFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
