//----------------------------------------------------------------------------
// wxComboBox
// extracted from combobox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(GetLastPosition);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ComboBox: public wxComboBox, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ComboBox *_pObj;
public:
	inline wx_ComboBox() : wxComboBox(), _pObj(nullptr) {}
	//inline wx_ComboBox(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, int n, const wxString choices[], long style, const wxValidator& validator, const wxString& name) : wxComboBox(parent, id, value, pos, size, n, choices[], style, validator, name), _pObj(nullptr) {}
	inline wx_ComboBox(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, const wxArrayString& choices, long style, const wxValidator& validator, const wxString& name) : wxComboBox(parent, id, value, pos, size, choices, style, validator, name), _pObj(nullptr) {}
	//virtual wxTextPos GetLastPosition();
	~wx_ComboBox();
	inline void AssocWithGura(Object_wx_ComboBox *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ComboBox::~wx_ComboBox()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ComboBox::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxComboBox
//----------------------------------------------------------------------------
Gura_DeclareFunction(ComboBoxEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ComboBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ComboBoxEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_ComboBox *pEntity = new wx_ComboBox();
	Object_wx_ComboBox *pObj = Object_wx_ComboBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ComboBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(ComboBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ComboBox));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_ZeroOrOnce, FLAG_List);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ComboBox)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxEmptyString;
	if (args.IsValid(2)) value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	std::unique_ptr<wxArrayString> choices;
	if (args.IsValid(5)) {
		choices.reset(CreateArrayString(args.GetList(5)));
	} else {
		choices.reset(new wxArrayString());
	}
	long style = 0;
	if (args.IsValid(6)) style = args.GetLong(6);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(7)) validator = Object_wx_Validator::GetObject(args, 7)->GetEntity();
	wxString name = wxT("comboBox");
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	wx_ComboBox *pEntity = new wx_ComboBox(parent, id, value, *pos, *size, *choices, style, *validator, name);
	Object_wx_ComboBox *pObj = Object_wx_ComboBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ComboBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_ComboBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_ZeroOrOnce, FLAG_List);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxEmptyString;
	if (args.IsValid(2)) value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	std::unique_ptr<wxArrayString> choices;
	if (args.IsValid(5)) {
		choices.reset(CreateArrayString(args.GetList(5)));
	} else {
		choices.reset(new wxArrayString());
	}
	long style = 0;
	if (args.IsValid(6)) style = args.GetLong(6);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(7)) validator = Object_wx_Validator::GetObject(args, 7)->GetEntity();
	wxString name = wxT("comboBox");
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	bool rtn = pThis->GetEntity()->Create(parent, id, value, *pos, *size, *choices, style, *validator, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, CanCopy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, CanCopy)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanCopy();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, CanCut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, CanCut)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanCut();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, CanPaste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, CanPaste)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanPaste();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, CanRedo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, CanRedo)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanRedo();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, CanUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, CanUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanUndo();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, Cut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, Cut)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Cut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, GetCurrentSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetCurrentSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetCurrentSelection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, GetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetInsertionPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetInsertionPoint();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, GetLastPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetLastPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTextPos rtn = pThis->GetEntity()->GetLastPosition();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, GetMark)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetMark)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long from;
	long to;
	pThis->GetEntity()->GetSelection(&from, &to);
	return ReturnValue(env, args, Value::CreateList(env, from, to));
}

Gura_DeclareMethod(wx_ComboBox, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ComboBox, Paste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, Paste)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Paste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, Redo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, Redo)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Redo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, Replace)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	wxString text = wxString::FromUTF8(args.GetString(2));
	pThis->GetEntity()->Replace(from, to, text);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pThis->GetEntity()->Remove(from, to);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, SetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, SetInsertionPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long pos = args.GetLong(0);
	pThis->GetEntity()->SetInsertionPoint(pos);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, SetInsertionPointEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, SetInsertionPointEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->SetInsertionPointEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, SetMark)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, SetMark)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pThis->GetEntity()->SetSelection(from, to);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetValue(text);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, Undo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, Undo)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "clientData", VTYPE_wx_ClientData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, Append)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(args.GetString(0));
	int rtn = 0;
	if (args.IsValid(1)) {
		wx_ClientData *clientData = Object_wx_ClientData::GetObject(args, 1)->GetEntity();
		rtn = pThis->GetEntity()->Append(item, new wx_ClientData(*clientData));
	} else {
		rtn = pThis->GetEntity()->Append(item);
	}
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, Delete)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = args.GetInt(0);
	pThis->GetEntity()->Delete(n);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, FindString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caseSensitive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, FindString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString string = wxString::FromUTF8(args.GetString(0));
	bool caseSensitive = false;
	if (args.IsValid(1)) caseSensitive = args.GetBoolean(1);
	int rtn = pThis->GetEntity()->FindString(string, caseSensitive);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, GetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, GetClientData)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = args.GetInt(0);
	pThis->GetEntity()->GetClientData(n);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, GetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetClientObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = args.GetInt(0);
	wx_ClientData *rtn = dynamic_cast<wx_ClientData *>(pThis->GetEntity()->GetClientObject(n));
	if (rtn == nullptr) return Value::Nil;
	return ReturnValue(env, args, Value(new Object_wx_ClientData(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ComboBox, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->GetCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetString(n);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ComboBox, GetStrings)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetStrings)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArrayString rtn = pThis->GetEntity()->GetStrings();
	return ReturnValue(env, args, ArrayStringToValue(env, rtn));
}

Gura_DeclareMethod(wx_ComboBox, GetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetStringSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetStringSelection();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ComboBox, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "clientData", VTYPE_wx_ClientData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, Insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(args.GetString(0));
	unsigned pos = args.GetInt(1);
	int rtn = 0;
	if (args.IsValid(2)) {
		wx_ClientData *clientData = Object_wx_ClientData::GetObject(args, 2)->GetEntity();
		rtn = pThis->GetEntity()->Insert(item, pos, new wx_ClientData(clientData));
	} else {
		rtn = pThis->GetEntity()->Insert(item, pos);
	}
	return ReturnValue(env, args, Value(rtn));
}

#if 0
Gura_DeclareMethod(wx_ComboBox, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsEmpty();
	return ReturnValue(env, args, Value(rtn));
}
#endif

Gura_DeclareMethod(wx_ComboBox, Select)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, Select)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int n = args.GetInt(0);
	pThis->GetEntity()->Select(n);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, SetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_wx_ClientData, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, SetClientObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = args.GetInt(0);
	wx_ClientData *data = Object_wx_ClientData::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetClientObject(n, new wx_ClientData(*data));
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int n = args.GetInt(0);
	pThis->GetEntity()->SetSelection(n);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, SetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, SetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned n = args.GetInt(0);
	wxString string = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetString(n, string);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboBox, SetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, SetStringSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboBox *pThis = Object_wx_ComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString string = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->SetStringSelection(string);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxComboBox
//----------------------------------------------------------------------------
Object_wx_ComboBox::~Object_wx_ComboBox()
{
}

Object *Object_wx_ComboBox::Clone() const
{
	return nullptr;
}

String Object_wx_ComboBox::ToString(bool exprFlag)
{
	String rtn("<wx.ComboBox:");
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
// Class implementation for wxComboBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ComboBox)
{
	Gura_RealizeUserSymbol(GetLastPosition);
	Gura_AssignWxStringValue(ComboBoxNameStr);
	Gura_AssignFunction(ComboBoxEmpty);
	Gura_AssignFunction(ComboBox);
	Gura_AssignMethod(wx_ComboBox, Create);
	Gura_AssignMethod(wx_ComboBox, CanCopy);
	Gura_AssignMethod(wx_ComboBox, CanCut);
	Gura_AssignMethod(wx_ComboBox, CanPaste);
	Gura_AssignMethod(wx_ComboBox, CanRedo);
	Gura_AssignMethod(wx_ComboBox, CanUndo);
	Gura_AssignMethod(wx_ComboBox, Copy);
	Gura_AssignMethod(wx_ComboBox, Cut);
	Gura_AssignMethod(wx_ComboBox, GetCurrentSelection);
	Gura_AssignMethod(wx_ComboBox, GetInsertionPoint);
	Gura_AssignMethod(wx_ComboBox, GetLastPosition);
	Gura_AssignMethod(wx_ComboBox, GetMark);
	Gura_AssignMethod(wx_ComboBox, GetValue);
	Gura_AssignMethod(wx_ComboBox, Paste);
	Gura_AssignMethod(wx_ComboBox, Redo);
	Gura_AssignMethod(wx_ComboBox, Replace);
	Gura_AssignMethod(wx_ComboBox, Remove);
	Gura_AssignMethod(wx_ComboBox, SetInsertionPoint);
	Gura_AssignMethod(wx_ComboBox, SetInsertionPointEnd);
	Gura_AssignMethod(wx_ComboBox, SetMark);
	Gura_AssignMethod(wx_ComboBox, SetValue);
	Gura_AssignMethod(wx_ComboBox, Undo);
	// methods of ComboBox
	Gura_AssignMethod(wx_ComboBox, Append);
	Gura_AssignMethod(wx_ComboBox, Clear);
	Gura_AssignMethod(wx_ComboBox, Delete);
	Gura_AssignMethod(wx_ComboBox, FindString);
	Gura_AssignMethod(wx_ComboBox, GetClientData);
	Gura_AssignMethod(wx_ComboBox, GetClientObject);
	Gura_AssignMethod(wx_ComboBox, GetCount);
	Gura_AssignMethod(wx_ComboBox, GetSelection);
	Gura_AssignMethod(wx_ComboBox, GetString);
	Gura_AssignMethod(wx_ComboBox, GetStrings);
	Gura_AssignMethod(wx_ComboBox, GetStringSelection);
	Gura_AssignMethod(wx_ComboBox, Insert);
	//Gura_AssignMethod(wx_ComboBox, IsEmpty);
	Gura_AssignMethod(wx_ComboBox, Select);
	Gura_AssignMethod(wx_ComboBox, SetClientObject);
	Gura_AssignMethod(wx_ComboBox, SetSelection);
	Gura_AssignMethod(wx_ComboBox, SetString);
	Gura_AssignMethod(wx_ComboBox, SetStringSelection);
}

Gura_ImplementDescendantCreator(wx_ComboBox)
{
	return new Object_wx_ComboBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
