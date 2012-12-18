//----------------------------------------------------------------------------
// wxComboBox
// extracted from combobox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(GetLastPosition);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ComboBox: public wxComboBox, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ComboBox *_pObj;
public:
	inline wx_ComboBox() : wxComboBox(), _sig(NULL), _pObj(NULL) {}
	//inline wx_ComboBox(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, int n, const wxString choices[], long style, const wxValidator& validator, const wxString& name) : wxComboBox(parent, id, value, pos, size, n, choices[], style, validator, name), _sig(NULL), _pObj(NULL) {}
	inline wx_ComboBox(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, const wxArrayString& choices, long style, const wxValidator& validator, const wxString& name) : wxComboBox(parent, id, value, pos, size, choices, style, validator, name), _sig(NULL), _pObj(NULL) {}
	//virtual wxTextPos GetLastPosition();
	~wx_ComboBox();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ComboBox *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ComboBox::~wx_ComboBox()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ComboBox::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxComboBox
//----------------------------------------------------------------------------
Gura_DeclareFunction(ComboBoxEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ComboBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ComboBoxEmpty)
{
	wx_ComboBox *pEntity = new wx_ComboBox();
	Object_wx_ComboBox *pObj = Object_wx_ComboBox::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ComboBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(ComboBox)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxEmptyString;
	if (args.IsValid(2)) value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	std::auto_ptr<wxArrayString> choices;
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
	Object_wx_ComboBox *pObj = Object_wx_ComboBox::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ComboBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_ComboBox, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxEmptyString;
	if (args.IsValid(2)) value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	std::auto_ptr<wxArrayString> choices;
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
	bool rtn = pSelf->GetEntity()->Create(parent, id, value, *pos, *size, *choices, style, *validator, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, CanCopy)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, CanCopy)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CanCopy();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, CanCut)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, CanCut)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CanCut();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, CanPaste)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, CanPaste)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CanPaste();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, CanRedo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, CanRedo)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CanRedo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, CanUndo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, CanUndo)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CanUndo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, Copy)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, Copy)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Copy();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboBox, Cut)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, Cut)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Cut();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboBox, GetCurrentSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetCurrentSelection)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetCurrentSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, GetInsertionPoint)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetInsertionPoint)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetInsertionPoint();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, GetLastPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetLastPosition)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextPos rtn = pSelf->GetEntity()->GetLastPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboBox, GetMark)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetMark)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long from;
	long to;
	pSelf->GetEntity()->GetSelection(&from, &to);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, from, to));
}

Gura_DeclareMethod(wx_ComboBox, GetValue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboBox, GetValue)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetValue();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ComboBox, Paste)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, Paste)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Paste();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboBox, Redo)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, Redo)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Redo();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboBox, Replace)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, Replace)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	wxString text = wxString::FromUTF8(args.GetString(2));
	pSelf->GetEntity()->Replace(from, to, text);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboBox, Remove)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, Remove)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pSelf->GetEntity()->Remove(from, to);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboBox, SetInsertionPoint)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, SetInsertionPoint)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long pos = args.GetLong(0);
	pSelf->GetEntity()->SetInsertionPoint(pos);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboBox, SetInsertionPointEnd)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, SetInsertionPointEnd)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->SetInsertionPointEnd();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboBox, SetMark)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, SetMark)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pSelf->GetEntity()->SetSelection(from, to);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboBox, SetValue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboBox, SetValue)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetValue(text);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboBox, Undo)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboBox, Undo)
{
	Object_wx_ComboBox *pSelf = Object_wx_ComboBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Undo();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxComboBox
//----------------------------------------------------------------------------
Object_wx_ComboBox::~Object_wx_ComboBox()
{
}

Object *Object_wx_ComboBox::Clone() const
{
	return NULL;
}

String Object_wx_ComboBox::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ComboBox:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ComboBox::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(GetLastPosition);
	Gura_AssignWxStringValue(ComboBoxNameStr);
	Gura_AssignFunction(ComboBoxEmpty);
	Gura_AssignFunction(ComboBox);
}

//----------------------------------------------------------------------------
// Class implementation for wxComboBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ComboBox)
{
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
}

Gura_ImplementDescendantCreator(wx_ComboBox)
{
	return new Object_wx_ComboBox((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
