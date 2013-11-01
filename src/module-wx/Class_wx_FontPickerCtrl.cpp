//----------------------------------------------------------------------------
// wxFontPickerCtrl
// extracted from fontpicker.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FontPickerCtrl: public wxFontPickerCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FontPickerCtrl *_pObj;
public:
	inline wx_FontPickerCtrl(wxWindow * parent, wxWindowID id, const wxFont& font, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxFontPickerCtrl(parent, id, font, pos, size, style, validator, name), _sig(NULL), _pObj(NULL) {}
	~wx_FontPickerCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FontPickerCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FontPickerCtrl::~wx_FontPickerCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FontPickerCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFontPickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(FontPickerCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FontPickerCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FontPickerCtrl)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxFont *font = (wxFont *)(&wxNullFont);
	if (args.IsValid(2)) font = Object_wx_Font::GetObject(args, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxFNTP_DEFAULT_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("fontpickerctrl");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_FontPickerCtrl *pEntity = new wx_FontPickerCtrl(parent, id, *font, *pos, *size, style, *validator, name);
	Object_wx_FontPickerCtrl *pObj = Object_wx_FontPickerCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FontPickerCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_FontPickerCtrl, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontPickerCtrl, Create)
{
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxFont *font = (wxFont *)(&wxNullFont);
	if (args.IsValid(2)) font = Object_wx_Font::GetObject(args, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxFNTP_DEFAULT_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("fontpickerctrl");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pThis->GetEntity()->Create(parent, id, *font, *pos, *size, style, *validator, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FontPickerCtrl, GetSelectedFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontPickerCtrl, GetSelectedFont)
{
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont rtn = pThis->GetEntity()->GetSelectedFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_FontPickerCtrl, SetSelectedFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerCtrl, SetSelectedFont)
{
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetSelectedFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_FontPickerCtrl, GetMaxPointSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontPickerCtrl, GetMaxPointSize)
{
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned int rtn = pThis->GetEntity()->GetMaxPointSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FontPickerCtrl, SetMaxPointSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerCtrl, SetMaxPointSize)
{
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned max = args.GetInt(0);
	pThis->GetEntity()->SetMaxPointSize(max);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFontPickerCtrl
//----------------------------------------------------------------------------
Object_wx_FontPickerCtrl::~Object_wx_FontPickerCtrl()
{
}

Object *Object_wx_FontPickerCtrl::Clone() const
{
	return NULL;
}

String Object_wx_FontPickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.FontPickerCtrl:");
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
// Class implementation for wxFontPickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontPickerCtrl)
{
	Gura_AssignFunction(FontPickerCtrl);
	Gura_AssignMethod(wx_FontPickerCtrl, Create);
	Gura_AssignMethod(wx_FontPickerCtrl, GetSelectedFont);
	Gura_AssignMethod(wx_FontPickerCtrl, SetSelectedFont);
	Gura_AssignMethod(wx_FontPickerCtrl, GetMaxPointSize);
	Gura_AssignMethod(wx_FontPickerCtrl, SetMaxPointSize);
}

Gura_ImplementDescendantCreator(wx_FontPickerCtrl)
{
	return new Object_wx_FontPickerCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
