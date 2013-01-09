//----------------------------------------------------------------------------
// wxRichTextFormattingDialog
// extracted from richtextformattingdialog.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextFormattingDialog: public wxRichTextFormattingDialog, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextFormattingDialog *_pObj;
public:
	inline wx_RichTextFormattingDialog(long flags, wxWindow* parent, const wxString& title, wxWindowID id, const wxPoint& pos, const wxSize& sz, long style) : wxRichTextFormattingDialog(flags, parent, title, id, pos, sz, style), _sig(NULL), _pObj(NULL) {}
	inline wx_RichTextFormattingDialog() : wxRichTextFormattingDialog(), _sig(NULL), _pObj(NULL) {}
	~wx_RichTextFormattingDialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextFormattingDialog *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextFormattingDialog::~wx_RichTextFormattingDialog()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextFormattingDialog::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextFormattingDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextFormattingDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextFormattingDialog));
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextFormattingDialog)
{
	long flags = args.GetLong(0);
	wxWindow *parent = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxString title = _("Formatting");
	if (args.IsValid(2)) title = wxString::FromUTF8(args.GetString(2));
	wxWindowID id = wxID_ANY;
	if (args.IsValid(3)) id = static_cast<wxWindowID>(args.GetInt(3));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(4)) pos = Object_wx_Point::GetObject(args, 4)->GetEntity();
	wxSize *sz = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(5)) sz = Object_wx_Size::GetObject(args, 5)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE;
	if (args.IsValid(6)) style = args.GetLong(6);
	wx_RichTextFormattingDialog *pEntity = new wx_RichTextFormattingDialog(flags, parent, title, id, *pos, *sz, style);
	Object_wx_RichTextFormattingDialog *pObj = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextFormattingDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(RichTextFormattingDialogEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextFormattingDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextFormattingDialogEmpty)
{
	wx_RichTextFormattingDialog *pEntity = new wx_RichTextFormattingDialog();
	Object_wx_RichTextFormattingDialog *pObj = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextFormattingDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, ApplyStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, ApplyStyle)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(args, 0)->GetEntity();
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 1)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO|wxRICHTEXT_SETSTYLE_OPTIMIZE;
	if (args.IsValid(2)) flags = args.GetInt(2);
	bool rtn = pSelf->GetEntity()->ApplyStyle(ctrl, *range, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, Create)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long flags = args.GetLong(0);
	wxWindow *parent = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxString title = wxString::FromUTF8(args.GetString(2));
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(3));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(4)) pos = Object_wx_Point::GetObject(args, 4)->GetEntity();
	wxSize *sz = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(5)) sz = Object_wx_Size::GetObject(args, 5)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE;
	if (args.IsValid(6)) style = args.GetLong(6);
	bool rtn = pSelf->GetEntity()->Create(flags, parent, title, id, *pos, *sz, style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetAttributes)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetAttributes)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxTextAttrEx &rtn = pSelf->GetEntity()->GetAttributes();
	return ReturnValue(env, sig, args, Value(new Object_wx_TextAttrEx(new wxTextAttrEx(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetAttributes_1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetAttributes_1)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrEx &rtn = pSelf->GetEntity()->GetAttributes();
	return ReturnValue(env, sig, args, Value(new Object_wx_TextAttrEx(new wxTextAttrEx(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetDialog)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxRichTextFormattingDialog *rtn = (wxRichTextFormattingDialog *)pSelf->GetEntity()->GetDialog(win);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextFormattingDialog(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetDialogAttributes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetDialogAttributes)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxTextAttrEx *rtn = (wxTextAttrEx *)pSelf->GetEntity()->GetDialogAttributes(win);
	return ReturnValue(env, sig, args, Value(new Object_wx_TextAttrEx(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetDialogStyleDefinition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetDialogStyleDefinition)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxRichTextStyleDefinition *rtn = (wxRichTextStyleDefinition *)pSelf->GetEntity()->GetDialogStyleDefinition(win);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextStyleDefinition(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetFormattingDialogFactory)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetFormattingDialogFactory)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextFormattingDialogFactory *rtn = (wxRichTextFormattingDialogFactory *)pSelf->GetEntity()->GetFormattingDialogFactory();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextFormattingDialogFactory(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetImageList)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetImageList)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxImageList *rtn = (wxImageList *)pSelf->GetEntity()->GetImageList();
	return ReturnValue(env, sig, args, Value(new Object_wx_ImageList(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetStyle)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(args, 0)->GetEntity();
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->GetStyle(ctrl, *range);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetStyleDefinition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetStyleDefinition)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleDefinition *rtn = (wxRichTextStyleDefinition *)pSelf->GetEntity()->GetStyleDefinition();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextStyleDefinition(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetStyleSheet)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetStyleSheet)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *rtn = (wxRichTextStyleSheet *)pSelf->GetEntity()->GetStyleSheet();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextStyleSheet(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, SetAttributes)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "attr", VTYPE_wx_TextAttrEx, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, SetAttributes)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrEx *attr = Object_wx_TextAttrEx::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetAttributes(*attr);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, SetFormattingDialogFactory)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "factory", VTYPE_wx_RichTextFormattingDialogFactory, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, SetFormattingDialogFactory)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextFormattingDialogFactory *factory = Object_wx_RichTextFormattingDialogFactory::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetFormattingDialogFactory(factory);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, SetImageList)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once, FLAG_Nil);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, SetImageList)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxImageList *imageList = NULL;
	if (args.IsValid(0)) imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetImageList(imageList);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, SetStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareArg(env, "update", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, SetStyle)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(args, 0)->GetEntity();
	bool update = true;
	if (args.IsValid(1)) update = args.GetBoolean(1);
	bool rtn = pSelf->GetEntity()->SetStyle(*style, update);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, SetStyleDefinition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "styleDef", VTYPE_wx_RichTextStyleDefinition, OCCUR_Once);
	DeclareArg(env, "sheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
	DeclareArg(env, "update", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, SetStyleDefinition)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleDefinition *styleDef = Object_wx_RichTextStyleDefinition::GetObject(args, 0)->GetEntity();
	wxRichTextStyleSheet *sheet = Object_wx_RichTextStyleSheet::GetObject(args, 1)->GetEntity();
	bool update = true;
	if (args.IsValid(2)) update = args.GetBoolean(2);
	bool rtn = pSelf->GetEntity()->SetStyleDefinition(*styleDef, sheet, update);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, UpdateDisplay)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, UpdateDisplay)
{
	Object_wx_RichTextFormattingDialog *pSelf = Object_wx_RichTextFormattingDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->UpdateDisplay();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextFormattingDialog
//----------------------------------------------------------------------------
Object_wx_RichTextFormattingDialog::~Object_wx_RichTextFormattingDialog()
{
}

Object *Object_wx_RichTextFormattingDialog::Clone() const
{
	return NULL;
}

String Object_wx_RichTextFormattingDialog::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RichTextFormattingDialog:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_RichTextFormattingDialog::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(RichTextFormattingDialog);
	Gura_AssignFunction(RichTextFormattingDialogEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextFormattingDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFormattingDialog)
{
	Gura_AssignMethod(wx_RichTextFormattingDialog, ApplyStyle);
	Gura_AssignMethod(wx_RichTextFormattingDialog, Create);
	Gura_AssignMethod(wx_RichTextFormattingDialog, GetAttributes);
	Gura_AssignMethod(wx_RichTextFormattingDialog, GetAttributes_1);
	Gura_AssignMethod(wx_RichTextFormattingDialog, GetDialog);
	Gura_AssignMethod(wx_RichTextFormattingDialog, GetDialogAttributes);
	Gura_AssignMethod(wx_RichTextFormattingDialog, GetDialogStyleDefinition);
	Gura_AssignMethod(wx_RichTextFormattingDialog, GetFormattingDialogFactory);
	Gura_AssignMethod(wx_RichTextFormattingDialog, GetImageList);
	Gura_AssignMethod(wx_RichTextFormattingDialog, GetStyle);
	Gura_AssignMethod(wx_RichTextFormattingDialog, GetStyleDefinition);
	Gura_AssignMethod(wx_RichTextFormattingDialog, GetStyleSheet);
	Gura_AssignMethod(wx_RichTextFormattingDialog, SetAttributes);
	Gura_AssignMethod(wx_RichTextFormattingDialog, SetFormattingDialogFactory);
	Gura_AssignMethod(wx_RichTextFormattingDialog, SetImageList);
	Gura_AssignMethod(wx_RichTextFormattingDialog, SetStyle);
	Gura_AssignMethod(wx_RichTextFormattingDialog, SetStyleDefinition);
	Gura_AssignMethod(wx_RichTextFormattingDialog, UpdateDisplay);
}

Gura_ImplementDescendantCreator(wx_RichTextFormattingDialog)
{
	return new Object_wx_RichTextFormattingDialog((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
