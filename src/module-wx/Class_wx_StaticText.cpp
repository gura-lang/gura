//----------------------------------------------------------------------------
// wxStaticText
// extracted from stattext.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(SetLabel);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StaticText: public wxStaticText, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_StaticText *_pObj;
public:
	inline wx_StaticText() : wxStaticText(), _sig(NULL), _pObj(NULL) {}
	inline wx_StaticText(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxStaticText(parent, id, label, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	//virtual void SetLabel(const wxString& label);
	~wx_StaticText();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StaticText *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StaticText::~wx_StaticText()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StaticText::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStaticText
//----------------------------------------------------------------------------
Gura_DeclareFunction(StaticTextEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StaticText));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StaticTextEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_StaticText *pEntity = new wx_StaticText();
	Object_wx_StaticText *pObj = Object_wx_StaticText::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StaticText(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(StaticText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StaticText));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StaticText)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString label = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("staticText");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	wx_StaticText *pEntity = new wx_StaticText(parent, id, label, *pos, *size, style, name);
	Object_wx_StaticText *pObj = Object_wx_StaticText::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StaticText(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_StaticText, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StaticText, Create)
{
	Object_wx_StaticText *pThis = Object_wx_StaticText::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString label = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("staticText");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	bool rtn = pThis->GetEntity()->Create(parent, id, label, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StaticText, GetLabel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StaticText, GetLabel)
{
	Object_wx_StaticText *pThis = Object_wx_StaticText::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetLabel();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StaticText, SetLabel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_StaticText, SetLabel)
{
	Object_wx_StaticText *pThis = Object_wx_StaticText::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString label = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetLabel(label);
	return Value::Null;
}

Gura_DeclareMethod(wx_StaticText, Wrap)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StaticText, Wrap)
{
	Object_wx_StaticText *pThis = Object_wx_StaticText::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->Wrap(width);
	return Value::Null;
}

Gura_DeclareMethod(wx_StaticText, IsEllipsized)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StaticText, IsEllipsized)
{
	Object_wx_StaticText *pThis = Object_wx_StaticText::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsEllipsized();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxStaticText
//----------------------------------------------------------------------------
Object_wx_StaticText::~Object_wx_StaticText()
{
}

Object *Object_wx_StaticText::Clone() const
{
	return NULL;
}

String Object_wx_StaticText::ToString(bool exprFlag)
{
	String rtn("<wx.StaticText:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxStaticText
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticText)
{
	Gura_RealizeUserSymbol(SetLabel);
	Gura_AssignWxStringValue(StaticTextNameStr);
	Gura_AssignFunction(StaticTextEmpty);
	Gura_AssignFunction(StaticText);
	Gura_AssignMethod(wx_StaticText, Create);
	Gura_AssignMethod(wx_StaticText, GetLabel);
	Gura_AssignMethod(wx_StaticText, SetLabel);
	Gura_AssignMethod(wx_StaticText, Wrap);
	Gura_AssignMethod(wx_StaticText, IsEllipsized);
}

Gura_ImplementDescendantCreator(wx_StaticText)
{
	return new Object_wx_StaticText((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
