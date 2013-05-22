//----------------------------------------------------------------------------
// wxSymbolPickerDialog
// extracted from symbolpickerdialog.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SymbolPickerDialog: public wxSymbolPickerDialog, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SymbolPickerDialog *_pObj;
public:
	inline wx_SymbolPickerDialog(const wxString& symbol, const wxString& initialFont, const wxString& normalTextFont, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxSymbolPickerDialog(symbol, initialFont, normalTextFont, parent, id, title, pos, size, style), _sig(NULL), _pObj(NULL) {}
	inline wx_SymbolPickerDialog() : wxSymbolPickerDialog(), _sig(NULL), _pObj(NULL) {}
	~wx_SymbolPickerDialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SymbolPickerDialog *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SymbolPickerDialog::~wx_SymbolPickerDialog()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SymbolPickerDialog::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSymbolPickerDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(SymbolPickerDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxString symbol = wxString::FromUTF8(args.GetString(0));
	wxString initialFont = wxString::FromUTF8(args.GetString(1));
	wxString normalTextFont = wxString::FromUTF8(args.GetString(2));
	wxWindow *parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(4)) id = static_cast<wxWindowID>(args.GetInt(4));
	wxString title = _("Symbols");
	if (args.IsValid(5)) title = wxString::FromUTF8(args.GetString(5));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(6)) pos = Object_wx_Point::GetObject(args, 6)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(7)) size = Object_wx_Size::GetObject(args, 7)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX;
	if (args.IsValid(8)) style = args.GetLong(8);
	wx_SymbolPickerDialog *pEntity = new wx_SymbolPickerDialog(symbol, initialFont, normalTextFont, parent, id, title, *pos, *size, style);
	Object_wx_SymbolPickerDialog *pObj = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SymbolPickerDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(SymbolPickerDialogEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SymbolPickerDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SymbolPickerDialogEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_SymbolPickerDialog *pEntity = new wx_SymbolPickerDialog();
	Object_wx_SymbolPickerDialog *pObj = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SymbolPickerDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_SymbolPickerDialog, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString symbol = wxString::FromUTF8(args.GetString(0));
	wxString initialFont = wxString::FromUTF8(args.GetString(1));
	wxString normalTextFont = wxString::FromUTF8(args.GetString(2));
	wxWindow *parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(4)) id = static_cast<wxWindowID>(args.GetInt(4));
	wxString title = _("Symbols");
	if (args.IsValid(5)) title = wxString::FromUTF8(args.GetString(5));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(6)) pos = Object_wx_Point::GetObject(args, 6)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(7)) size = Object_wx_Size::GetObject(args, 7)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX;
	if (args.IsValid(8)) style = args.GetLong(8);
	bool rtn = pThis->GetEntity()->Create(symbol, initialFont, normalTextFont, parent, id, title, *pos, *size, style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetFontName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetFontName)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetFontName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetFromUnicode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetFromUnicode)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetFromUnicode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetNormalTextFontName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetNormalTextFontName)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetNormalTextFontName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetSymbol)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetSymbol)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetSymbol();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_SymbolPickerDialog, GetSymbolChar)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, GetSymbolChar)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetSymbolChar();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SymbolPickerDialog, HasSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, HasSelection)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetFontName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetFontName)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetFontName(value);
	return Value::Null;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetFromUnicode)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetFromUnicode)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool value = args.GetBoolean(0);
	pThis->GetEntity()->SetFromUnicode(value);
	return Value::Null;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetNormalTextFontName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetNormalTextFontName)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetNormalTextFontName(value);
	return Value::Null;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetSymbol)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetSymbol)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetSymbol(value);
	return Value::Null;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, SetUnicodeMode)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "unicodeMode", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, SetUnicodeMode)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool unicodeMode = args.GetBoolean(0);
	pThis->GetEntity()->SetUnicodeMode(unicodeMode);
	return Value::Null;
}

Gura_DeclareMethod(wx_SymbolPickerDialog, UseNormalFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SymbolPickerDialog, UseNormalFont)
{
	Object_wx_SymbolPickerDialog *pThis = Object_wx_SymbolPickerDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->UseNormalFont();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSymbolPickerDialog
//----------------------------------------------------------------------------
Object_wx_SymbolPickerDialog::~Object_wx_SymbolPickerDialog()
{
}

Object *Object_wx_SymbolPickerDialog::Clone() const
{
	return NULL;
}

String Object_wx_SymbolPickerDialog::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.SymbolPickerDialog:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_SymbolPickerDialog::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(SymbolPickerDialog);
	Gura_AssignFunction(SymbolPickerDialogEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxSymbolPickerDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SymbolPickerDialog)
{
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
	return new Object_wx_SymbolPickerDialog((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
