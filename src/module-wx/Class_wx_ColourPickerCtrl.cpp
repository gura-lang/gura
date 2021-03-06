//----------------------------------------------------------------------------
// wxColourPickerCtrl
// extracted from clrpicker.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ColourPickerCtrl: public wxColourPickerCtrl, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ColourPickerCtrl *_pObj;
public:
	inline wx_ColourPickerCtrl(wxWindow * parent, wxWindowID id, const wxColour& colour, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxColourPickerCtrl(parent, id, colour, pos, size, style, validator, name), _pObj(nullptr) {}
	~wx_ColourPickerCtrl();
	inline void AssocWithGura(Object_wx_ColourPickerCtrl *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ColourPickerCtrl::~wx_ColourPickerCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ColourPickerCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxColourPickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(ColourPickerCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxColour *colour = (wxColour *)(&*wxBLACK);
	if (arg.IsValid(2)) colour = Object_wx_Colour::GetObject(arg, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxCLRP_DEFAULT_STYLE;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (arg.IsValid(6)) validator = Object_wx_Validator::GetObject(arg, 6)->GetEntity();
	wxString name = wxT("colourpickerctrl");
	if (arg.IsValid(7)) name = wxString::FromUTF8(arg.GetString(7));
	wx_ColourPickerCtrl *pEntity = new wx_ColourPickerCtrl(parent, id, *colour, *pos, *size, style, *validator, name);
	Object_wx_ColourPickerCtrl *pObj = Object_wx_ColourPickerCtrl::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_ColourPickerCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_ColourPickerCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	Object_wx_ColourPickerCtrl *pThis = Object_wx_ColourPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxColour *colour = (wxColour *)(&*wxBLACK);
	if (arg.IsValid(2)) colour = Object_wx_Colour::GetObject(arg, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxCLRP_DEFAULT_STYLE;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (arg.IsValid(6)) validator = Object_wx_Validator::GetObject(arg, 6)->GetEntity();
	wxString name = wxT("colourpickerctrl");
	if (arg.IsValid(7)) name = wxString::FromUTF8(arg.GetString(7));
	bool rtn = pThis->GetEntity()->Create(parent, id, *colour, *pos, *size, style, *validator, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ColourPickerCtrl, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourPickerCtrl, GetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourPickerCtrl *pThis = Object_wx_ColourPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour rtn = pThis->GetEntity()->GetColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ColourPickerCtrl, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourPickerCtrl, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourPickerCtrl *pThis = Object_wx_ColourPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *col = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetColour(*col);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ColourPickerCtrl, SetColour_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colname", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourPickerCtrl, SetColour_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourPickerCtrl *pThis = Object_wx_ColourPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString colname = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetColour(colname);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxColourPickerCtrl
//----------------------------------------------------------------------------
Object_wx_ColourPickerCtrl::~Object_wx_ColourPickerCtrl()
{
}

Object *Object_wx_ColourPickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_ColourPickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.ColourPickerCtrl:");
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
// Class implementation for wxColourPickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourPickerCtrl)
{
	Gura_AssignFunction(ColourPickerCtrl);
	Gura_AssignMethod(wx_ColourPickerCtrl, Create);
	Gura_AssignMethod(wx_ColourPickerCtrl, GetColour);
	Gura_AssignMethod(wx_ColourPickerCtrl, SetColour);
	Gura_AssignMethod(wx_ColourPickerCtrl, SetColour_1);
}

Gura_ImplementDescendantCreator(wx_ColourPickerCtrl)
{
	return new Object_wx_ColourPickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
