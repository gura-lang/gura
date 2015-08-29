//----------------------------------------------------------------------------
// wxSymbolPickerDialog
// extracted from symbolpickerdialog.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SymbolPickerDialog: public wxSymbolPickerDialog, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SymbolPickerDialog *_pObj;
public:
	inline wx_SymbolPickerDialog(const wxString& symbol, const wxString& initialFont, const wxString& normalTextFont, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxSymbolPickerDialog(symbol, initialFont, normalTextFont, parent, id, title, pos, size, style), _pObj(nullptr) {}
	inline wx_SymbolPickerDialog() : wxSymbolPickerDialog(), _pObj(nullptr) {}
	~wx_SymbolPickerDialog();
	inline void AssocWithGura(Object_wx_SymbolPickerDialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SymbolPickerDialog::~wx_SymbolPickerDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SymbolPickerDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSymbolPickerDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(SymbolPickerDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SymbolPickerDialog));
	DeclareArg(env, "symbol", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "initialFont", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "normalTextFont", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SymbolPickerDialog)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString symbol = wxString::FromUTF8(arg.GetString(0));
	wxString initialFont = wxString::FromUTF8(arg.GetString(1));
	wxString normalTextFont = wxString::FromUTF8(arg.GetString(2));
	wxWindow *parent = Object_wx_Window::GetObject(arg, 3)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (arg.IsValid(4)) id = static_cast<wxWindowID>(arg.GetInt(4));
	wxString title = _("Symbols");
	if (arg.IsValid(5)) title = wxString::FromUTF8(arg.GetString(5));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(6)) pos = Object_wx_Point::GetObject(arg, 6)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(7)) size = Object_wx_Size::GetObject(arg, 7)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX;
	if (arg.IsValid(8)) style = arg.GetLong(8);
	wx_SymbolPickerDialog *pEntity = new wx_SymbolPickerDialog(symbol, initialFont, normalTextFont, parent, id, title, *pos, *size, style);
	Object_wx_SymbolPickerDialog *pObj = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_SymbolPickerDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(SymbolPickerDialogEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SymbolPickerDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SymbolPickerDialogEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_SymbolPickerDialog *pEntity = new wx_SymbolPickerDialog();
	Object_wx_SymbolPickerDialog *pObj = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_SymbolPickerDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_SymbolPickerDialog, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "initialFont", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "normalTextFont", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString symbol = wxString::FromUTF8(arg.GetString(0));
	wxString initialFont = wxString::FromUTF8(arg.GetString(1));
	wxString normalTextFont = wxString::FromUTF8(arg.GetString(2));
	wxWindow *parent = Object_wx_Window::GetObject(arg, 3)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (arg.IsValid(4)) id = static_cast<wxWindowID>(arg.GetInt(4));
	wxString title = _("Symbols");
	if (arg.IsValid(5)) title = wxString::FromUTF8(arg.GetString(5));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(6)) pos = Object_wx_Point::GetObject(arg, 6)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(7)) size = Object_wx_Size::GetObject(arg, 7)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX;
	if (arg.IsValid(8)) style = arg.GetLong(8);
	bool rtn = pThis->GetEntity()->Create(symbol, initialFont, normalTextFont, parent, id, title, *pos, *size, style);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetFontName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetFontName)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetFontName();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetFromUnicode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetFromUnicode)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetFromUnicode();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetNormalTextFontName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetNormalTextFontName)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetNormalTextFontName();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetSymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetSymbol)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetSymbol();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetSymbolChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetSymbolChar)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSymbolChar();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SymbolPickerDialog, HasSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, HasSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasSelection();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetFontName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetFontName)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString value = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetFontName(value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetFromUnicode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetFromUnicode)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool value = arg.GetBoolean(0);
	pThis->GetEntity()->SetFromUnicode(value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetNormalTextFontName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetNormalTextFontName)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString value = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetNormalTextFontName(value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetSymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetSymbol)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString value = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetSymbol(value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetUnicodeMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "unicodeMode", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetUnicodeMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool unicodeMode = arg.GetBoolean(0);
	pThis->GetEntity()->SetUnicodeMode(unicodeMode);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, UseNormalFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, UseNormalFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->UseNormalFont();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSymbolPickerDialog
//----------------------------------------------------------------------------
Object_wx_SymbolPickerDialog::~Object_wx_SymbolPickerDialog()
{
}

Object *Object_wx_SymbolPickerDialog::Clone() const
{
	return nullptr;
}

String Object_wx_SymbolPickerDialog::ToString(bool exprFlag)
{
	String rtn("<wx.SymbolPickerDialog:");
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
// Class implementation for wxSymbolPickerDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SymbolPickerDialog)
{
	Gura_AssignFunction(SymbolPickerDialog);
	Gura_AssignFunction(SymbolPickerDialogEmpty);
	Gura_AssignMethod(wx_SymbolPickerDialog, Create);
	Gura_AssignMethod(wx_SymbolPickerDialog, GetFontName);
	Gura_AssignMethod(wx_SymbolPickerDialog, GetFromUnicode);
	Gura_AssignMethod(wx_SymbolPickerDialog, GetNormalTextFontName);
	Gura_AssignMethod(wx_SymbolPickerDialog, GetSymbol);
	Gura_AssignMethod(wx_SymbolPickerDialog, GetSymbolChar);
	Gura_AssignMethod(wx_SymbolPickerDialog, HasSelection);
	Gura_AssignMethod(wx_SymbolPickerDialog, SetFontName);
	Gura_AssignMethod(wx_SymbolPickerDialog, SetFromUnicode);
	Gura_AssignMethod(wx_SymbolPickerDialog, SetNormalTextFontName);
	Gura_AssignMethod(wx_SymbolPickerDialog, SetSymbol);
	Gura_AssignMethod(wx_SymbolPickerDialog, SetUnicodeMode);
	Gura_AssignMethod(wx_SymbolPickerDialog, UseNormalFont);
}

Gura_ImplementDescendantCreator(wx_SymbolPickerDialog)
{
	return new Object_wx_SymbolPickerDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
