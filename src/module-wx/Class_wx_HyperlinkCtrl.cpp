//----------------------------------------------------------------------------
// wxHyperlinkCtrl
// extracted from hyperlink.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HyperlinkCtrl: public wxHyperlinkCtrl, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HyperlinkCtrl *_pObj;
public:
	inline wx_HyperlinkCtrl(wxWindow* parent, wxWindowID id, const wxString & label, const wxString & url, const wxPoint& pos, const wxSize& size, long style, const wxString& name) :
		wxHyperlinkCtrl(parent, id, label, url, pos, size, style, name) {}
	~wx_HyperlinkCtrl();
	inline void AssocWithGura(Object_wx_HyperlinkCtrl *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HyperlinkCtrl::~wx_HyperlinkCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HyperlinkCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHyperlinkCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(HyperlinkCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString label = wxString::FromUTF8(arg.GetString(2));
	wxString url = wxString::FromUTF8(arg.GetString(3));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(4)) pos = Object_wx_Point::GetObject(arg, 4)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(5)) size = Object_wx_Size::GetObject(arg, 5)->GetEntity();
	long style = wxHL_DEFAULT_STYLE;
	if (arg.IsValid(6)) style = arg.GetLong(6);
	wxString name = wxHyperlinkCtrlNameStr;
	if (arg.IsValid(7)) name = wxString::FromUTF8(arg.GetString(7));
	wx_HyperlinkCtrl *pEntity = new wx_HyperlinkCtrl(parent, id, label, url, *pos, *size, style, name);
	Object_wx_HyperlinkCtrl *pObj = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_HyperlinkCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_HyperlinkCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString label = wxString::FromUTF8(arg.GetString(2));
	wxString url = wxString::FromUTF8(arg.GetString(3));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(4)) pos = Object_wx_Point::GetObject(arg, 4)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(5)) size = Object_wx_Size::GetObject(arg, 5)->GetEntity();
	long style = wxHL_DEFAULT_STYLE;
	if (arg.IsValid(6)) style = arg.GetLong(6);
	wxString name = wxHyperlinkCtrlNameStr;
	if (arg.IsValid(7)) name = wxString::FromUTF8(arg.GetString(7));
	bool rtn = pThis->GetEntity()->Create(parent, id, label, url, *pos, *size, style, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetHoverColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetHoverColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour rtn = pThis->GetEntity()->GetHoverColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetHoverColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetHoverColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetHoverColour(*colour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetNormalColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetNormalColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour rtn = pThis->GetEntity()->GetNormalColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetNormalColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetNormalColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetNormalColour(*colour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetVisitedColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetVisitedColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour rtn = pThis->GetEntity()->GetVisitedColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetVisitedColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetVisitedColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetVisitedColour(*colour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetVisited)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetVisited)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetVisited();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetVisited)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "visited", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetVisited)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool visited = true;
	if (arg.IsValid(0)) visited = arg.GetBoolean(0);
	pThis->GetEntity()->SetVisited(visited);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetURL();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString url = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetURL(url);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxHyperlinkCtrl
//----------------------------------------------------------------------------
Object_wx_HyperlinkCtrl::~Object_wx_HyperlinkCtrl()
{
}

Object *Object_wx_HyperlinkCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_HyperlinkCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.HyperlinkCtrl:");
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
// Class implementation for wxHyperlinkCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HyperlinkCtrl)
{
	Gura_AssignFunction(HyperlinkCtrl);
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
	return new Object_wx_HyperlinkCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
