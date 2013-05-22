//----------------------------------------------------------------------------
// wxHelpProvider
// extracted from helpprov.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(AddHelp);
Gura_DeclarePrivUserSymbol(AddHelp_1);
Gura_DeclarePrivUserSymbol(GetHelp);
Gura_DeclarePrivUserSymbol(RemoveHelp);
Gura_DeclarePrivUserSymbol(ShowHelpAtPoint);
Gura_DeclarePrivUserSymbol(ShowHelp);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HelpProvider: public wxHelpProvider, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HelpProvider *_pObj;
public:
	//virtual void AddHelp(wxWindowBase* window, const wxString& text);
	//virtual void AddHelp(wxWindowID id, const wxString& text);
	//virtual wxString GetHelp(const wxWindowBase* window);
	//virtual void RemoveHelp(wxWindowBase* window);
	//virtual bool ShowHelpAtPoint(wxWindowBase* window, const wxPoint & point, wxHelpEvent::Origin origin);
	//virtual bool ShowHelp(wxWindowBase* window);
	~wx_HelpProvider();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HelpProvider *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HelpProvider::~wx_HelpProvider()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HelpProvider::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHelpProvider
//----------------------------------------------------------------------------
Gura_DeclareFunction(HelpProvider)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HelpProvider));
}

Gura_ImplementFunction(HelpProvider)
{
	if (!CheckWxReady(sig)) return Value::Null;
	return Value::Null;
}

Gura_DeclareMethod(wx_HelpProvider, AddHelp)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, AddHelp)
{
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowBase *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->AddHelp(window, text);
	return Value::Null;
}

Gura_DeclareMethod(wx_HelpProvider, AddHelp_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, AddHelp_1)
{
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(0));
	wxString text = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->AddHelp(id, text);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_HelpProvider, Get)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_HelpProvider, Get)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxHelpProvider *rtn = (wxHelpProvider *)wxHelpProvider::Get();
	return ReturnValue(env, sig, args, Value(new Object_wx_HelpProvider(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HelpProvider, GetHelp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpProvider, GetHelp)
{
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowBase *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxString rtn = pThis->GetEntity()->GetHelp(window);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HelpProvider, RemoveHelp)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, RemoveHelp)
{
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowBase *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->RemoveHelp(window);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_HelpProvider, Set)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "helpProvider", VTYPE_wx_HelpProvider, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_HelpProvider, Set)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxHelpProvider *helpProvider = Object_wx_HelpProvider::GetObject(args, 0)->GetEntity();
	wxHelpProvider *rtn = (wxHelpProvider *)wxHelpProvider::Set(helpProvider);
	return ReturnValue(env, sig, args, Value(new Object_wx_HelpProvider(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HelpProvider, ShowHelpAtPoint)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "origin", VTYPE_wx_HelpEvent, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpProvider, ShowHelpAtPoint)
{
#if 0
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowBase *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxPoint *point = Object_wx_Point::GetObject(args, 1)->GetEntity();
	wxHelpEvent *origin = Object_wx_HelpEvent::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->ShowHelpAtPoint(window, *point, *origin);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HelpProvider, ShowHelp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpProvider, ShowHelp)
{
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowBase *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->ShowHelp(window);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxHelpProvider
//----------------------------------------------------------------------------
Object_wx_HelpProvider::~Object_wx_HelpProvider()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_HelpProvider::Clone() const
{
	return NULL;
}

String Object_wx_HelpProvider::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HelpProvider:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_HelpProvider::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(AddHelp);
	Gura_RealizeUserSymbol(AddHelp_1);
	Gura_RealizeUserSymbol(GetHelp);
	Gura_RealizeUserSymbol(RemoveHelp);
	Gura_RealizeUserSymbol(ShowHelpAtPoint);
	Gura_RealizeUserSymbol(ShowHelp);
	Gura_AssignFunction(HelpProvider);
}

//----------------------------------------------------------------------------
// Class implementation for wxHelpProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpProvider)
{
	Gura_AssignMethod(wx_HelpProvider, AddHelp);
	Gura_AssignMethod(wx_HelpProvider, AddHelp_1);
	Gura_AssignMethod(wx_HelpProvider, Get);
	Gura_AssignMethod(wx_HelpProvider, GetHelp);
	Gura_AssignMethod(wx_HelpProvider, RemoveHelp);
	Gura_AssignMethod(wx_HelpProvider, Set);
	Gura_AssignMethod(wx_HelpProvider, ShowHelpAtPoint);
	Gura_AssignMethod(wx_HelpProvider, ShowHelp);
}

Gura_ImplementDescendantCreator(wx_HelpProvider)
{
	return new Object_wx_HelpProvider((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
