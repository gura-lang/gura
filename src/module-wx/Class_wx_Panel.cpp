//----------------------------------------------------------------------------
// wxPanel
// extracted from panel.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(SetFocus);
Gura_DeclarePrivUserSymbol(SetFocusIgnoringChildren);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Panel: public wxPanel, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Panel *_pObj;
public:
	inline wx_Panel() : wxPanel(), _pObj(nullptr) {}
	inline wx_Panel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPanel(parent, id, pos, size, style, name), _pObj(nullptr) {}
	//virtual void SetFocus();
	//virtual void SetFocusIgnoringChildren();
	~wx_Panel();
	inline void AssocWithGura(Object_wx_Panel *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Panel::~wx_Panel()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Panel::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPanel
//----------------------------------------------------------------------------
Gura_DeclareFunction(PanelEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Panel));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PanelEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Panel *pEntity = new wx_Panel();
	Object_wx_Panel *pObj = Object_wx_Panel::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Panel(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Panel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Panel));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Panel)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (arg.IsValid(1)) id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = wxTAB_TRAVERSAL;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxString name = wxT("panel");
	if (arg.IsValid(5)) name = wxString::FromUTF8(arg.GetString(5));
	wx_Panel *pEntity = new wx_Panel(parent, id, *pos, *size, style, name);
	Object_wx_Panel *pObj = Object_wx_Panel::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Panel(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_Panel, Create)
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

Gura_ImplementMethod(wx_Panel, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (arg.IsValid(1)) id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = wxTAB_TRAVERSAL;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxString name = wxT("panel");
	if (arg.IsValid(5)) name = wxString::FromUTF8(arg.GetString(5));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Panel, InitDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, InitDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->InitDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Panel, OnSysColourChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_SysColourChangedEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_Panel, OnSysColourChanged)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSysColourChangedEvent *event = Object_wx_SysColourChangedEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnSysColourChanged(*event);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Panel, SetFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, SetFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->SetFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Panel, SetFocusIgnoringChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, SetFocusIgnoringChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_Panel *pThis = Object_wx_Panel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->SetFocusIgnoringChildren();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxPanel
//----------------------------------------------------------------------------
Object_wx_Panel::~Object_wx_Panel()
{
}

Object *Object_wx_Panel::Clone() const
{
	return nullptr;
}

String Object_wx_Panel::ToString(bool exprFlag)
{
	String rtn("<wx.Panel:");
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
// Class implementation for wxPanel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Panel)
{
	Gura_RealizeUserSymbol(SetFocus);
	Gura_RealizeUserSymbol(SetFocusIgnoringChildren);
	Gura_AssignWxStringValue(PanelNameStr);
	Gura_AssignFunction(PanelEmpty);
	Gura_AssignFunction(Panel);
	Gura_AssignMethod(wx_Panel, Create);
	Gura_AssignMethod(wx_Panel, InitDialog);
	Gura_AssignMethod(wx_Panel, OnSysColourChanged);
	Gura_AssignMethod(wx_Panel, SetFocus);
	Gura_AssignMethod(wx_Panel, SetFocusIgnoringChildren);
}

Gura_ImplementDescendantCreator(wx_Panel)
{
	return new Object_wx_Panel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
