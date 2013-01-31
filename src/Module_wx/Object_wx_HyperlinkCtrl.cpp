//----------------------------------------------------------------------------
// wxHyperlinkCtrl
// extracted from hyperlink.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HyperlinkCtrl: public wxHyperlinkCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HyperlinkCtrl *_pObj;
public:
	inline wx_HyperlinkCtrl(wxWindow* parent, wxWindowID id, const wxString & label, const wxString & url, const wxPoint& pos, const wxSize& size, long style, const wxString& name) :
		wxHyperlinkCtrl(parent, id, label, url, pos, size, style, name) {}
	~wx_HyperlinkCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HyperlinkCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HyperlinkCtrl::~wx_HyperlinkCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HyperlinkCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHyperlinkCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(HyperlinkCtrl)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HyperlinkCtrl)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString label = wxString::FromUTF8(args.GetString(2));
	wxString url = wxString::FromUTF8(args.GetString(3));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(4)) pos = Object_wx_Point::GetObject(args, 4)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(5)) size = Object_wx_Size::GetObject(args, 5)->GetEntity();
	long style = 0;
	if (args.IsValid(6)) style = args.GetLong(6);
	wxString name = wxT("hyperlink");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_HyperlinkCtrl *pEntity = new wx_HyperlinkCtrl(parent, id, label, url, *pos, *size, style, name);
	Object_wx_HyperlinkCtrl *pObj = Object_wx_HyperlinkCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HyperlinkCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_HyperlinkCtrl, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, Create)
{
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString label = wxString::FromUTF8(args.GetString(2));
	wxString url = wxString::FromUTF8(args.GetString(3));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(4)) pos = Object_wx_Point::GetObject(args, 4)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(5)) size = Object_wx_Size::GetObject(args, 5)->GetEntity();
	long style = 0;
	if (args.IsValid(6)) style = args.GetLong(6);
	wxString name = wxT("hyperlink");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pThis->GetEntity()->Create(parent, id, label, url, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetHoverColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetHoverColour)
{
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetHoverColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetHoverColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetHoverColour)
{
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetHoverColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetNormalColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetNormalColour)
{
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetNormalColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetNormalColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetNormalColour)
{
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetNormalColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetVisitedColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetVisitedColour)
{
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetVisitedColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetVisitedColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetVisitedColour)
{
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetVisitedColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetVisited)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetVisited)
{
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetVisited();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetVisited)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "visited", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetVisited)
{
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool visited = true;
	if (args.IsValid(0)) visited = args.GetBoolean(0);
	pThis->GetEntity()->SetVisited(visited);
	return Value::Null;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetURL)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetURL)
{
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetURL();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetURL)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetURL)
{
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString url = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetURL(url);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHyperlinkCtrl
//----------------------------------------------------------------------------
Object_wx_HyperlinkCtrl::~Object_wx_HyperlinkCtrl()
{
}

Object *Object_wx_HyperlinkCtrl::Clone() const
{
	return NULL;
}

String Object_wx_HyperlinkCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HyperlinkCtrl:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_HyperlinkCtrl::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(HyperlinkCtrl);
}

//----------------------------------------------------------------------------
// Class implementation for wxHyperlinkCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HyperlinkCtrl)
{
	Gura_AssignMethod(wx_HyperlinkCtrl, Create);
	Gura_AssignMethod(wx_HyperlinkCtrl, GetHoverColour);
	Gura_AssignMethod(wx_HyperlinkCtrl, SetHoverColour);
	Gura_AssignMethod(wx_HyperlinkCtrl, GetNormalColour);
	Gura_AssignMethod(wx_HyperlinkCtrl, SetNormalColour);
	Gura_AssignMethod(wx_HyperlinkCtrl, GetVisitedColour);
	Gura_AssignMethod(wx_HyperlinkCtrl, SetVisitedColour);
	Gura_AssignMethod(wx_HyperlinkCtrl, GetVisited);
	Gura_AssignMethod(wx_HyperlinkCtrl, SetVisited);
	Gura_AssignMethod(wx_HyperlinkCtrl, GetURL);
	Gura_AssignMethod(wx_HyperlinkCtrl, SetURL);
}

Gura_ImplementDescendantCreator(wx_HyperlinkCtrl)
{
	return new Object_wx_HyperlinkCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
