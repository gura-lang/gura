//----------------------------------------------------------------------------
// wxColourPickerCtrl
// extracted from clrpicker.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ColourPickerCtrl: public wxColourPickerCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ColourPickerCtrl *_pObj;
public:
	inline wx_ColourPickerCtrl(wxWindow * parent, wxWindowID id, const wxColour& colour, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxColourPickerCtrl(parent, id, colour, pos, size, style, validator, name), _sig(NULL), _pObj(NULL) {}
	~wx_ColourPickerCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ColourPickerCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ColourPickerCtrl::~wx_ColourPickerCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ColourPickerCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxColourPickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(ColourPickerCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ColourPickerCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ColourPickerCtrl)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxColour *colour = (wxColour *)(&*wxBLACK);
	if (args.IsValid(2)) colour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxCLRP_DEFAULT_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("colourpickerctrl");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_ColourPickerCtrl *pEntity = new wx_ColourPickerCtrl(parent, id, *colour, *pos, *size, style, *validator, name);
	Object_wx_ColourPickerCtrl *pObj = Object_wx_ColourPickerCtrl::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ColourPickerCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_ColourPickerCtrl, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourPickerCtrl, Create)
{
	Object_wx_ColourPickerCtrl *pSelf = Object_wx_ColourPickerCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxColour *colour = (wxColour *)(&*wxBLACK);
	if (args.IsValid(2)) colour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxCLRP_DEFAULT_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("colourpickerctrl");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pSelf->GetEntity()->Create(parent, id, *colour, *pos, *size, style, *validator, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ColourPickerCtrl, GetColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourPickerCtrl, GetColour)
{
	Object_wx_ColourPickerCtrl *pSelf = Object_wx_ColourPickerCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pSelf->GetEntity()->GetColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ColourPickerCtrl, SetColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourPickerCtrl, SetColour)
{
	Object_wx_ColourPickerCtrl *pSelf = Object_wx_ColourPickerCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *col = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetColour(*col);
	return Value::Null;
}

Gura_DeclareMethod(wx_ColourPickerCtrl, SetColour_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colname", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourPickerCtrl, SetColour_1)
{
	Object_wx_ColourPickerCtrl *pSelf = Object_wx_ColourPickerCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString colname = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetColour(colname);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxColourPickerCtrl
//----------------------------------------------------------------------------
Object_wx_ColourPickerCtrl::~Object_wx_ColourPickerCtrl()
{
}

Object *Object_wx_ColourPickerCtrl::Clone() const
{
	return NULL;
}

String Object_wx_ColourPickerCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ColourPickerCtrl:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ColourPickerCtrl::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ColourPickerCtrl);
}

//----------------------------------------------------------------------------
// Class implementation for wxColourPickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourPickerCtrl)
{
	Gura_AssignMethod(wx_ColourPickerCtrl, Create);
	Gura_AssignMethod(wx_ColourPickerCtrl, GetColour);
	Gura_AssignMethod(wx_ColourPickerCtrl, SetColour);
	Gura_AssignMethod(wx_ColourPickerCtrl, SetColour_1);
}

Gura_ImplementDescendantCreator(wx_ColourPickerCtrl)
{
	return new Object_wx_ColourPickerCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
