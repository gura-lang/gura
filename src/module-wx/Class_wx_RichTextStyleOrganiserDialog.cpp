//----------------------------------------------------------------------------
// wxRichTextStyleOrganiserDialog
// extracted from richtextstyleorganiserdialog.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextStyleOrganiserDialog: public wxRichTextStyleOrganiserDialog, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_RichTextStyleOrganiserDialog *_pObj;
public:
	inline wx_RichTextStyleOrganiserDialog(int flags, wxRichTextStyleSheet* sheet, wxRichTextCtrl* ctrl, wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style) : wxRichTextStyleOrganiserDialog(flags, sheet, ctrl, parent, id, caption, pos, size, style), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_RichTextStyleOrganiserDialog() : wxRichTextStyleOrganiserDialog(), _pSig(nullptr), _pObj(nullptr) {}
	~wx_RichTextStyleOrganiserDialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextStyleOrganiserDialog *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextStyleOrganiserDialog::~wx_RichTextStyleOrganiserDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextStyleOrganiserDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleOrganiserDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextStyleOrganiserDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleOrganiserDialog));
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextStyleOrganiserDialog)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int flags = args.GetInt(0);
	wxRichTextStyleSheet *sheet = Object_wx_RichTextStyleSheet::GetObject(args, 1)->GetEntity();
	wxRichTextCtrl *ctrl = nullptr;
	if (args.IsValid(2)) ctrl = Object_wx_RichTextCtrl::GetObject(args, 2)->GetEntity();
	wxWindow *parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(4)) id = static_cast<wxWindowID>(args.GetInt(4));
	wxString caption = _("Style Organiser");
	if (args.IsValid(5)) caption = wxString::FromUTF8(args.GetString(5));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(6)) pos = Object_wx_Point::GetObject(args, 6)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(7)) size = Object_wx_Size::GetObject(args, 7)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX;
	if (args.IsValid(8)) style = args.GetLong(8);
	wx_RichTextStyleOrganiserDialog *pEntity = new wx_RichTextStyleOrganiserDialog(flags, sheet, ctrl, parent, id, caption, *pos, *size, style);
	Object_wx_RichTextStyleOrganiserDialog *pObj = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextStyleOrganiserDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(RichTextStyleOrganiserDialogEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleOrganiserDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextStyleOrganiserDialogEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_RichTextStyleOrganiserDialog *pEntity = new wx_RichTextStyleOrganiserDialog();
	Object_wx_RichTextStyleOrganiserDialog *pObj = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextStyleOrganiserDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, ApplyStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, ApplyStyle)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextCtrl *ctrl = (wxRichTextCtrl *)(nullptr);
	if (args.IsValid(0)) ctrl = Object_wx_RichTextCtrl::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->ApplyStyle(ctrl);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, Create)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = args.GetInt(0);
	wxRichTextStyleSheet *sheet = Object_wx_RichTextStyleSheet::GetObject(args, 1)->GetEntity();
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(args, 2)->GetEntity();
	wxWindow *parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(4)) id = static_cast<wxWindowID>(args.GetInt(4));
	wxString caption = _("Style Organiser");
	if (args.IsValid(5)) caption = wxString::FromUTF8(args.GetString(5));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(6)) pos = Object_wx_Point::GetObject(args, 6)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(7)) size = Object_wx_Size::GetObject(args, 7)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX;
	if (args.IsValid(8)) style = args.GetLong(8);
	bool rtn = pThis->GetEntity()->Create(flags, sheet, ctrl, parent, id, caption, *pos, *size, style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, GetFlags)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, GetRestartNumbering)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, GetRestartNumbering)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetRestartNumbering();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, GetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, GetRichTextCtrl)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextCtrl *rtn = (wxRichTextCtrl *)pThis->GetEntity()->GetRichTextCtrl();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextCtrl(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, GetSelectedStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, GetSelectedStyle)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetSelectedStyle();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, GetSelectedStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, GetSelectedStyleDefinition)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleDefinition *rtn = (wxRichTextStyleDefinition *)pThis->GetEntity()->GetSelectedStyleDefinition();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextStyleDefinition(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, GetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, GetStyleSheet)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *rtn = (wxRichTextStyleSheet *)pThis->GetEntity()->GetStyleSheet();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextStyleSheet(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, SetFlags)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = args.GetInt(0);
	pThis->GetEntity()->SetFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, SetRestartNumbering)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "restartNumbering", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, SetRestartNumbering)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool restartNumbering = args.GetBoolean(0);
	pThis->GetEntity()->SetRestartNumbering(restartNumbering);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, SetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, SetRichTextCtrl)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetRichTextCtrl(ctrl);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, SetShowToolTips)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, SetShowToolTips)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool show = args.GetBoolean(0);
	pThis->GetEntity()->SetShowToolTips(show);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, SetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, SetStyleSheet)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *sheet = Object_wx_RichTextStyleSheet::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetStyleSheet(sheet);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleOrganiserDialog
//----------------------------------------------------------------------------
Object_wx_RichTextStyleOrganiserDialog::~Object_wx_RichTextStyleOrganiserDialog()
{
}

Object *Object_wx_RichTextStyleOrganiserDialog::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStyleOrganiserDialog::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleOrganiserDialog:");
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
// Class implementation for wxRichTextStyleOrganiserDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleOrganiserDialog)
{
	Gura_AssignFunction(RichTextStyleOrganiserDialog);
	Gura_AssignFunction(RichTextStyleOrganiserDialogEmpty);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, ApplyStyle);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, Create);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, GetFlags);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, GetRestartNumbering);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, GetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, GetSelectedStyle);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, GetSelectedStyleDefinition);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, GetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, SetFlags);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, SetRestartNumbering);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, SetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, SetShowToolTips);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, SetStyleSheet);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleOrganiserDialog)
{
	return new Object_wx_RichTextStyleOrganiserDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
