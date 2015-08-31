//----------------------------------------------------------------------------
// wxRadioBox
// extracted from radiobox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(Enable);
Gura_DeclarePrivUserSymbol(EnableItem);
Gura_DeclarePrivUserSymbol(Show);
Gura_DeclarePrivUserSymbol(ShowItem);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RadioBox: public wxRadioBox, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RadioBox *_pObj;
public:
	inline wx_RadioBox() : wxRadioBox(), _pObj(nullptr) {}
	//inline wx_RadioBox(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& point, const wxSize& size, int n, const wxString choices[], int majorDimension, long style, const wxValidator& validator, const wxString& name) : wxRadioBox(parent, id, label, point, size, n, choices[], majorDimension, style, validator, name), _pObj(nullptr) {}
	inline wx_RadioBox(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& point, const wxSize& size, const wxArrayString& choices, int majorDimension, long style, const wxValidator& validator, const wxString& name) : wxRadioBox(parent, id, label, point, size, choices, majorDimension, style, validator, name), _pObj(nullptr) {}
	//virtual bool Enable(bool enable);
	//virtual bool Enable(unsigned int n, bool enable);
	//virtual bool Show(const bool show);
	//virtual bool Show(unsigned int item, const bool show);
	~wx_RadioBox();
	inline void AssocWithGura(Object_wx_RadioBox *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RadioBox::~wx_RadioBox()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RadioBox::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRadioBox
//----------------------------------------------------------------------------
Gura_DeclareFunction(RadioBoxEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RadioBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RadioBoxEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_RadioBox *pEntity = new wx_RadioBox();
	Object_wx_RadioBox *pObj = Object_wx_RadioBox::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RadioBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(RadioBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RadioBox));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareArg(env, "majorDimension", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RadioBox)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString label = wxString::FromUTF8(arg.GetString(2));
	wxPoint *point = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) point = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	std::unique_ptr<wxArrayString> choices;
	if (arg.IsValid(5)) {
		choices.reset(CreateArrayString(arg.GetList(5)));
	} else {
		choices.reset(new wxArrayString());
	}
	int majorDimension = 0;
	if (arg.IsValid(6)) majorDimension = arg.GetInt(6);
	long style = wxRA_SPECIFY_COLS;
	if (arg.IsValid(7)) style = arg.GetLong(7);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (arg.IsValid(8)) validator = Object_wx_Validator::GetObject(arg, 8)->GetEntity();
	wxString name = wxT("radioBox");
	if (arg.IsValid(9)) name = wxString::FromUTF8(arg.GetString(9));
	wx_RadioBox *pEntity = new wx_RadioBox(parent, id, label, *point, *size, *choices, majorDimension, style, *validator, name);
	Object_wx_RadioBox *pObj = Object_wx_RadioBox::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RadioBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_RadioBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "majorDimension", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString label = wxString::FromUTF8(arg.GetString(2));
	wxPoint *point = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	std::unique_ptr<wxArrayString> choices(CreateArrayString(arg.GetList(5)));
	int majorDimension = 0;
	if (arg.IsValid(6)) majorDimension = arg.GetInt(6);
	long style = wxRA_SPECIFY_COLS;
	if (arg.IsValid(7)) style = arg.GetLong(7);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (arg.IsValid(8)) validator = Object_wx_Validator::GetObject(arg, 8)->GetEntity();
	wxString name = wxT("radioBox");
	if (arg.IsValid(9)) name = wxString::FromUTF8(arg.GetString(9));
	bool rtn = pThis->GetEntity()->Create(parent, id, label, *point, *size, *choices, majorDimension, style, *validator, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, Enable)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool enable = true;
	if (arg.IsValid(0)) enable = arg.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Enable(enable);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, EnableItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, EnableItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = arg.GetInt(0);
	bool enable = true;
	if (arg.IsValid(1)) enable = arg.GetBoolean(1);
	bool rtn = pThis->GetEntity()->Enable(n, enable);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, FindString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, FindString)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString string = wxString::FromUTF8(arg.GetString(0));
	int rtn = pThis->GetEntity()->FindString(string);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, GetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetColumnCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->GetColumnCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, GetItemHelpText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetItemHelpText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned item = arg.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetItemHelpText(item);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RadioBox, GetItemToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetItemToolTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned item = arg.GetInt(0);
	wxToolTip *rtn = (wxToolTip *)pThis->GetEntity()->GetItemToolTip(item);
	return ReturnValue(env, arg, Value(new Object_wx_ToolTip(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RadioBox, GetItemFromPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetItemFromPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	int rtn = pThis->GetEntity()->GetItemFromPoint(*pt);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetLabel();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RadioBox, GetRowCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetRowCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->GetRowCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, GetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetStringSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetStringSelection();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RadioBox, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = arg.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetString(n);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RadioBox, IsItemEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, IsItemEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->IsItemEnabled(n);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, IsItemShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, IsItemShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->IsItemShown(n);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, SetItemHelpText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "helptext", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, SetItemHelpText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned item = arg.GetInt(0);
	wxString helptext = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->SetItemHelpText(item, helptext);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, SetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, SetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString label = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetLabel(label);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int n = arg.GetInt(0);
	pThis->GetEntity()->SetSelection(n);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, SetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, SetStringSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString string = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetStringSelection(string);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, SetItemToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, SetItemToolTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned item = arg.GetInt(0);
	wxString text = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->SetItemToolTip(item, text);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RadioBox, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool show = true;
	if (arg.IsValid(0)) show = arg.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Show(show);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, ShowItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, ShowItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned item = arg.GetInt(0);
	bool show = true;
	if (arg.IsValid(1)) show = arg.GetBoolean(1);
	bool rtn = pThis->GetEntity()->Show(item, show);
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxRadioBox
//----------------------------------------------------------------------------
Object_wx_RadioBox::~Object_wx_RadioBox()
{
}

Object *Object_wx_RadioBox::Clone() const
{
	return nullptr;
}

String Object_wx_RadioBox::ToString(bool exprFlag)
{
	String rtn("<wx.RadioBox:");
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
// Class implementation for wxRadioBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RadioBox)
{
	Gura_RealizeUserSymbol(Enable);
	Gura_RealizeUserSymbol(EnableItem);
	Gura_RealizeUserSymbol(Show);
	Gura_RealizeUserSymbol(ShowItem);
	Gura_AssignWxStringValue(RadioBoxNameStr);
	Gura_AssignFunction(RadioBoxEmpty);
	Gura_AssignFunction(RadioBox);
	Gura_AssignMethod(wx_RadioBox, Create);
	Gura_AssignMethod(wx_RadioBox, Enable);
	Gura_AssignMethod(wx_RadioBox, EnableItem);
	Gura_AssignMethod(wx_RadioBox, FindString);
	Gura_AssignMethod(wx_RadioBox, GetColumnCount);
	Gura_AssignMethod(wx_RadioBox, GetItemHelpText);
	Gura_AssignMethod(wx_RadioBox, GetItemToolTip);
	Gura_AssignMethod(wx_RadioBox, GetItemFromPoint);
	Gura_AssignMethod(wx_RadioBox, GetLabel);
	Gura_AssignMethod(wx_RadioBox, GetRowCount);
	Gura_AssignMethod(wx_RadioBox, GetSelection);
	Gura_AssignMethod(wx_RadioBox, GetStringSelection);
	Gura_AssignMethod(wx_RadioBox, GetString);
	Gura_AssignMethod(wx_RadioBox, IsItemEnabled);
	Gura_AssignMethod(wx_RadioBox, IsItemShown);
	Gura_AssignMethod(wx_RadioBox, SetItemHelpText);
	Gura_AssignMethod(wx_RadioBox, SetLabel);
	Gura_AssignMethod(wx_RadioBox, SetSelection);
	Gura_AssignMethod(wx_RadioBox, SetStringSelection);
	Gura_AssignMethod(wx_RadioBox, SetItemToolTip);
	Gura_AssignMethod(wx_RadioBox, Show);
	Gura_AssignMethod(wx_RadioBox, ShowItem);
}

Gura_ImplementDescendantCreator(wx_RadioBox)
{
	return new Object_wx_RadioBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
