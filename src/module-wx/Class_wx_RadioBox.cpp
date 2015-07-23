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
	Gura::Signal *_pSig;
	Object_wx_RadioBox *_pObj;
public:
	inline wx_RadioBox() : wxRadioBox(), _pSig(nullptr), _pObj(nullptr) {}
	//inline wx_RadioBox(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& point, const wxSize& size, int n, const wxString choices[], int majorDimension, long style, const wxValidator& validator, const wxString& name) : wxRadioBox(parent, id, label, point, size, n, choices[], majorDimension, style, validator, name), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_RadioBox(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& point, const wxSize& size, const wxArrayString& choices, int majorDimension, long style, const wxValidator& validator, const wxString& name) : wxRadioBox(parent, id, label, point, size, choices, majorDimension, style, validator, name), _pSig(nullptr), _pObj(nullptr) {}
	//virtual bool Enable(bool enable);
	//virtual bool Enable(unsigned int n, bool enable);
	//virtual bool Show(const bool show);
	//virtual bool Show(unsigned int item, const bool show);
	~wx_RadioBox();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RadioBox *pObj) {
		_pSig = &sig, _pObj = pObj;
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
	if (!CheckWxReady(sig)) return Value::Null;
	wx_RadioBox *pEntity = new wx_RadioBox();
	Object_wx_RadioBox *pObj = Object_wx_RadioBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RadioBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
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
	DeclareArg(env, "choices", VTYPE_string, OCCUR_ZeroOrOnce, FLAG_List);
	DeclareArg(env, "majorDimension", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RadioBox)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString label = wxString::FromUTF8(args.GetString(2));
	wxPoint *point = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) point = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	std::unique_ptr<wxArrayString> choices;
	if (args.IsValid(5)) {
		choices.reset(CreateArrayString(args.GetList(5)));
	} else {
		choices.reset(new wxArrayString());
	}
	int majorDimension = 0;
	if (args.IsValid(6)) majorDimension = args.GetInt(6);
	long style = wxRA_SPECIFY_COLS;
	if (args.IsValid(7)) style = args.GetLong(7);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(8)) validator = Object_wx_Validator::GetObject(args, 8)->GetEntity();
	wxString name = wxT("radioBox");
	if (args.IsValid(9)) name = wxString::FromUTF8(args.GetString(9));
	wx_RadioBox *pEntity = new wx_RadioBox(parent, id, label, *point, *size, *choices, majorDimension, style, *validator, name);
	Object_wx_RadioBox *pObj = Object_wx_RadioBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RadioBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_RadioBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "majorDimension", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, Create)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString label = wxString::FromUTF8(args.GetString(2));
	wxPoint *point = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	std::unique_ptr<wxArrayString> choices(CreateArrayString(args.GetList(5)));
	int majorDimension = 0;
	if (args.IsValid(6)) majorDimension = args.GetInt(6);
	long style = wxRA_SPECIFY_COLS;
	if (args.IsValid(7)) style = args.GetLong(7);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(8)) validator = Object_wx_Validator::GetObject(args, 8)->GetEntity();
	wxString name = wxT("radioBox");
	if (args.IsValid(9)) name = wxString::FromUTF8(args.GetString(9));
	bool rtn = pThis->GetEntity()->Create(parent, id, label, *point, *size, *choices, majorDimension, style, *validator, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, Enable)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Enable(enable);
	return ReturnValue(env, args, Value(rtn));
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
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned n = args.GetInt(0);
	bool enable = true;
	if (args.IsValid(1)) enable = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->Enable(n, enable);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, FindString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, FindString)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString string = wxString::FromUTF8(args.GetString(0));
	int rtn = pThis->GetEntity()->FindString(string);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, GetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetColumnCount)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->GetColumnCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, GetItemHelpText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetItemHelpText)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned item = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetItemHelpText(item);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RadioBox, GetItemToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetItemToolTip)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned item = args.GetInt(0);
	wxToolTip *rtn = (wxToolTip *)pThis->GetEntity()->GetItemToolTip(item);
	return ReturnValue(env, args, Value(new Object_wx_ToolTip(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RadioBox, GetItemFromPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetItemFromPoint)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	int rtn = pThis->GetEntity()->GetItemFromPoint(*pt);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetLabel)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetLabel();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RadioBox, GetRowCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetRowCount)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->GetRowCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetSelection)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, GetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetStringSelection)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetStringSelection();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RadioBox, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, GetString)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned n = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetString(n);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RadioBox, IsItemEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, IsItemEnabled)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned n = args.GetInt(0);
	bool rtn = pThis->GetEntity()->IsItemEnabled(n);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, IsItemShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, IsItemShown)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned n = args.GetInt(0);
	bool rtn = pThis->GetEntity()->IsItemShown(n);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RadioBox, SetItemHelpText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "helptext", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, SetItemHelpText)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned item = args.GetInt(0);
	wxString helptext = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetItemHelpText(item, helptext);
	return Value::Null;
}

Gura_DeclareMethod(wx_RadioBox, SetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, SetLabel)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString label = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetLabel(label);
	return Value::Null;
}

Gura_DeclareMethod(wx_RadioBox, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, SetSelection)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	pThis->GetEntity()->SetSelection(n);
	return Value::Null;
}

Gura_DeclareMethod(wx_RadioBox, SetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, SetStringSelection)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString string = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetStringSelection(string);
	return Value::Null;
}

Gura_DeclareMethod(wx_RadioBox, SetItemToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioBox, SetItemToolTip)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned item = args.GetInt(0);
	wxString text = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetItemToolTip(item, text);
	return Value::Null;
}

Gura_DeclareMethod(wx_RadioBox, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioBox, Show)
{
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool show = true;
	if (args.IsValid(0)) show = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Show(show);
	return ReturnValue(env, args, Value(rtn));
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
	Object_wx_RadioBox *pThis = Object_wx_RadioBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned item = args.GetInt(0);
	bool show = true;
	if (args.IsValid(1)) show = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->Show(item, show);
	return ReturnValue(env, args, Value(rtn));
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
