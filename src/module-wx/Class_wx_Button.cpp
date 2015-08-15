//----------------------------------------------------------------------------
// wxButton
// extracted from button.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Button: public wxButton, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Button *_pObj;
public:
	inline wx_Button() : wxButton(), _pObj(nullptr) {}
	inline wx_Button(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxButton(parent, id, label, pos, size, style, validator, name), _pObj(nullptr) {}
	~wx_Button();
	inline void AssocWithGura(Object_wx_Button *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Button::~wx_Button()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Button::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxButton
//----------------------------------------------------------------------------
Gura_DeclareFunction(ButtonEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Button));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ButtonEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Button *pEntity = new wx_Button();
	Object_wx_Button *pObj = Object_wx_Button::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Button(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Button)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Button));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Constructor, creating and showing a button.\n"
	"\n"
	"The preferred way to create standard buttons is to use default value of label.\n"
	"If no label is supplied and id is one of standard IDs from this list, standard label will be used.\n"
	"In addition to that, the button will be decorated with stock icons under GTK+ 2.\n"
	"\n"
	"**Parameters**\n"
	"\n"
	"- parent - Parent window.\n"
	"- id - Button identifier. A value of wxID_ANY indicates a default value.\n"
	"- label - Text to be displayed on the button.\n"
	"- pos - Button position.\n"
	"- size - Button size. If the default size is specified then the button is sized appropriately for the text.\n"
	"- style - Window style. See wxButton.\n"
	"- validator - Window validator.\n"
	"- name - Window name.\n"
	);
}

Gura_ImplementFunction(Button)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString label = wxEmptyString;
	if (args.IsValid(2)) label = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("button");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_Button *pEntity = new wx_Button(parent, id, label, *pos, *size, style, *validator, name);
	Object_wx_Button *pObj = Object_wx_Button::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Button(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_Button, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Button, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Button *pThis = Object_wx_Button::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString label = wxEmptyString;
	if (args.IsValid(2)) label = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("button");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pThis->GetEntity()->Create(parent, id, label, *pos, *size, style, *validator, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Button, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Returns the string label for the button.\n"
	"\n"
	"**Return value** The button's label.\n"
	);
}

Gura_ImplementMethod(wx_Button, GetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Button *pThis = Object_wx_Button::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetLabel();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Button, GetDefaultSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Returns the default size for the buttons.\n"
	"It is advised to make all the dialog buttons of the same size and this function allows to retrieve the\n"
	"(platform and current font dependent size) which should be the best suited for this.\n"
	);
}

Gura_ImplementMethod(wx_Button, GetDefaultSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Button *pThis = Object_wx_Button::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetDefaultSize();
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Button, SetDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Button, SetDefault)
{
	Signal &sig = env.GetSignal();
	Object_wx_Button *pThis = Object_wx_Button::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->SetDefault();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Button, SetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the string label for the button.\n"
	"\n"
	"**Parameters**\n"
	"\n"
	"- label - The label to set.\n"
	);
}

Gura_ImplementMethod(wx_Button, SetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Button *pThis = Object_wx_Button::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString label = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetLabel(label);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxButton
//----------------------------------------------------------------------------
Object_wx_Button::~Object_wx_Button()
{
}

Object *Object_wx_Button::Clone() const
{
	return nullptr;
}

String Object_wx_Button::ToString(bool exprFlag)
{
	String rtn("<wx.Button:");
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
// Class implementation for wxButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Button)
{
	Gura_AssignWxStringValue(ButtonNameStr);
	Gura_AssignFunction(ButtonEmpty);
	Gura_AssignFunction(Button);
	Gura_AssignMethod(wx_Button, Create);
	Gura_AssignMethod(wx_Button, GetLabel);
	Gura_AssignMethod(wx_Button, GetDefaultSize);
	Gura_AssignMethod(wx_Button, SetDefault);
	Gura_AssignMethod(wx_Button, SetLabel);
}

Gura_ImplementDescendantCreator(wx_Button)
{
	return new Object_wx_Button((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
