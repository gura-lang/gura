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
	//Gura::Signal *_pSig;
	Object_wx_FontPickerCtrl *_pObj;
public:
	inline wx_FontPickerCtrl(wxWindow * parent, wxWindowID id, const wxFont& font, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxFontPickerCtrl(parent, id, font, pos, size, style, validator, name), _pObj(nullptr) {}
	~wx_FontPickerCtrl();
	inline void AssocWithGura(Object_wx_FontPickerCtrl *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FontPickerCtrl::~wx_FontPickerCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FontPickerCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFontPickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(FontPickerCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
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
	Object_wx_FontPickerCtrl *pObj = Object_wx_FontPickerCtrl::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FontPickerCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_FontPickerCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_FontPickerCtrl, GetSelectedFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontPickerCtrl, GetSelectedFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont rtn = pThis->GetEntity()->GetSelectedFont();
	return ReturnValue(env, args, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_FontPickerCtrl, SetSelectedFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerCtrl, SetSelectedFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetSelectedFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontPickerCtrl, GetMaxPointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontPickerCtrl, GetMaxPointSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned int rtn = pThis->GetEntity()->GetMaxPointSize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_FontPickerCtrl, SetMaxPointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerCtrl, SetMaxPointSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned max = args.GetInt(0);
	pThis->GetEntity()->SetMaxPointSize(max);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxFontPickerCtrl
//----------------------------------------------------------------------------
Object_wx_FontPickerCtrl::~Object_wx_FontPickerCtrl()
{
}

Object *Object_wx_FontPickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_FontPickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.FontPickerCtrl:");
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
	return new Object_wx_FontPickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
