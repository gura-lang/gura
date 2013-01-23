//----------------------------------------------------------------------------
// wxPanel
// extracted from panel.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(SetFocus);
Gura_DeclarePrivUserSymbol(SetFocusIgnoringChildren);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Panel: public wxPanel, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Panel *_pObj;
public:
	inline wx_Panel() : wxPanel(), _sig(NULL), _pObj(NULL) {}
	inline wx_Panel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPanel(parent, id, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	//virtual void SetFocus();
	//virtual void SetFocusIgnoringChildren();
	~wx_Panel();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Panel *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Panel::~wx_Panel()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Panel::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPanel
//----------------------------------------------------------------------------
Gura_DeclareFunction(PanelEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Panel));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PanelEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Panel *pEntity = new wx_Panel();
	Object_wx_Panel *pObj = Object_wx_Panel::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Panel(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Panel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxTAB_TRAVERSAL;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("panel");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_Panel *pEntity = new wx_Panel(parent, id, *pos, *size, style, name);
	Object_wx_Panel *pObj = Object_wx_Panel::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Panel(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Panel, Create)
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

Gura_ImplementMethod(wx_Panel, Create)
{
	Object_wx_Panel *pSelf = Object_wx_Panel::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxTAB_TRAVERSAL;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("panel");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	bool rtn = pSelf->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Panel, InitDialog)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, InitDialog)
{
	Object_wx_Panel *pSelf = Object_wx_Panel::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->InitDialog();
	return Value::Null;
}

Gura_DeclareMethod(wx_Panel, OnSysColourChanged)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_SysColourChangedEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_Panel, OnSysColourChanged)
{
	Object_wx_Panel *pSelf = Object_wx_Panel::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSysColourChangedEvent *event = Object_wx_SysColourChangedEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnSysColourChanged(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_Panel, SetFocus)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, SetFocus)
{
	Object_wx_Panel *pSelf = Object_wx_Panel::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->SetFocus();
	return Value::Null;
}

Gura_DeclareMethod(wx_Panel, SetFocusIgnoringChildren)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Panel, SetFocusIgnoringChildren)
{
	Object_wx_Panel *pSelf = Object_wx_Panel::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->SetFocusIgnoringChildren();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxPanel
//----------------------------------------------------------------------------
Object_wx_Panel::~Object_wx_Panel()
{
}

Object *Object_wx_Panel::Clone() const
{
	return NULL;
}

String Object_wx_Panel::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Panel:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Panel::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(SetFocus);
	Gura_RealizeUserSymbol(SetFocusIgnoringChildren);
	Gura_AssignWxStringValue(PanelNameStr);
	Gura_AssignFunction(PanelEmpty);
	Gura_AssignFunction(Panel);
}

//----------------------------------------------------------------------------
// Class implementation for wxPanel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Panel)
{
	Gura_AssignMethod(wx_Panel, Create);
	Gura_AssignMethod(wx_Panel, InitDialog);
	Gura_AssignMethod(wx_Panel, OnSysColourChanged);
	Gura_AssignMethod(wx_Panel, SetFocus);
	Gura_AssignMethod(wx_Panel, SetFocusIgnoringChildren);
}

Gura_ImplementDescendantCreator(wx_Panel)
{
	return new Object_wx_Panel((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
