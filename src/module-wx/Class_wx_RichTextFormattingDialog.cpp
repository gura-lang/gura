//----------------------------------------------------------------------------
// wxRichTextFormattingDialog
// extracted from richtextformattingdialog.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextFormattingDialog: public wxRichTextFormattingDialog, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RichTextFormattingDialog *_pObj;
public:
	inline wx_RichTextFormattingDialog(long flags, wxWindow* parent, const wxString& title, wxWindowID id, const wxPoint& pos, const wxSize& sz, long style) : wxRichTextFormattingDialog(flags, parent, title, id, pos, sz, style), _pObj(nullptr) {}
	inline wx_RichTextFormattingDialog() : wxRichTextFormattingDialog(), _pObj(nullptr) {}
	~wx_RichTextFormattingDialog();
	inline void AssocWithGura(Object_wx_RichTextFormattingDialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextFormattingDialog::~wx_RichTextFormattingDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextFormattingDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextFormattingDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextFormattingDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	long flags = arg.GetLong(0);
	wxWindow *parent = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxString title = _("Formatting");
	if (arg.IsValid(2)) title = wxString::FromUTF8(arg.GetString(2));
	wxWindowID id = wxID_ANY;
	if (arg.IsValid(3)) id = static_cast<wxWindowID>(arg.GetInt(3));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(4)) pos = Object_wx_Point::GetObject(arg, 4)->GetEntity();
	wxSize *sz = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(5)) sz = Object_wx_Size::GetObject(arg, 5)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE;
	if (arg.IsValid(6)) style = arg.GetLong(6);
	wx_RichTextFormattingDialog *pEntity = new wx_RichTextFormattingDialog(flags, parent, title, id, *pos, *sz, style);
	Object_wx_RichTextFormattingDialog *pObj = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextFormattingDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(RichTextFormattingDialogEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextFormattingDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextFormattingDialogEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_RichTextFormattingDialog *pEntity = new wx_RichTextFormattingDialog();
	Object_wx_RichTextFormattingDialog *pObj = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextFormattingDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, ApplyStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, ApplyStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(arg, 0)->GetEntity();
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(arg, 1)->GetEntity();
	int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO|wxRICHTEXT_SETSTYLE_OPTIMIZE;
	if (arg.IsValid(2)) flags = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->ApplyStyle(ctrl, *range, flags);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long flags = arg.GetLong(0);
	wxWindow *parent = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxString title = wxString::FromUTF8(arg.GetString(2));
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(3));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(4)) pos = Object_wx_Point::GetObject(arg, 4)->GetEntity();
	wxSize *sz = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(5)) sz = Object_wx_Size::GetObject(arg, 5)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE;
	if (arg.IsValid(6)) style = arg.GetLong(6);
	bool rtn = pThis->GetEntity()->Create(flags, parent, title, id, *pos, *sz, style);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxTextAttrEx &rtn = pThis->GetEntity()->GetAttributes();
	return ReturnValue(env, arg, Value(new Object_wx_TextAttrEx(new wxTextAttrEx(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetAttributes_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetAttributes_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTextAttrEx &rtn = pThis->GetEntity()->GetAttributes();
	return ReturnValue(env, arg, Value(new Object_wx_TextAttrEx(new wxTextAttrEx(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *win = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxRichTextFormattingDialog *rtn = (wxRichTextFormattingDialog *)pThis->GetEntity()->GetDialog(win);
	return ReturnValue(env, arg, Value(new Object_wx_RichTextFormattingDialog(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetDialogAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetDialogAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *win = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxTextAttrEx *rtn = (wxTextAttrEx *)pThis->GetEntity()->GetDialogAttributes(win);
	return ReturnValue(env, arg, Value(new Object_wx_TextAttrEx(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetDialogStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetDialogStyleDefinition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *win = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxRichTextStyleDefinition *rtn = (wxRichTextStyleDefinition *)pThis->GetEntity()->GetDialogStyleDefinition(win);
	return ReturnValue(env, arg, Value(new Object_wx_RichTextStyleDefinition(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetFormattingDialogFactory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetFormattingDialogFactory)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextFormattingDialogFactory *rtn = (wxRichTextFormattingDialogFactory *)pThis->GetEntity()->GetFormattingDialogFactory();
	return ReturnValue(env, arg, Value(new Object_wx_RichTextFormattingDialogFactory(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImageList *rtn = (wxImageList *)pThis->GetEntity()->GetImageList();
	return ReturnValue(env, arg, Value(new Object_wx_ImageList(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_wx_RichTextRange, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(arg, 0)->GetEntity();
	wxRichTextRange *range = Object_wx_RichTextRange::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->GetStyle(ctrl, *range);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetStyleDefinition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleDefinition *rtn = (wxRichTextStyleDefinition *)pThis->GetEntity()->GetStyleDefinition();
	return ReturnValue(env, arg, Value(new Object_wx_RichTextStyleDefinition(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, GetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, GetStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleSheet *rtn = (wxRichTextStyleSheet *)pThis->GetEntity()->GetStyleSheet();
	return ReturnValue(env, arg, Value(new Object_wx_RichTextStyleSheet(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, SetAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "attr", VTYPE_wx_TextAttrEx, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, SetAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTextAttrEx *attr = Object_wx_TextAttrEx::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetAttributes(*attr);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, SetFormattingDialogFactory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "factory", VTYPE_wx_RichTextFormattingDialogFactory, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, SetFormattingDialogFactory)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextFormattingDialogFactory *factory = Object_wx_RichTextFormattingDialogFactory::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetFormattingDialogFactory(factory);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, SetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once, FLAG_Nil);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, SetImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImageList *imageList = nullptr;
	if (arg.IsValid(0)) imageList = Object_wx_ImageList::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetImageList(imageList);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "style", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareArg(env, "update", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, SetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTextAttrEx *style = Object_wx_TextAttrEx::GetObject(arg, 0)->GetEntity();
	bool update = true;
	if (arg.IsValid(1)) update = arg.GetBoolean(1);
	bool rtn = pThis->GetEntity()->SetStyle(*style, update);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, SetStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "styleDef", VTYPE_wx_RichTextStyleDefinition, OCCUR_Once);
	DeclareArg(env, "sheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
	DeclareArg(env, "update", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, SetStyleDefinition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleDefinition *styleDef = Object_wx_RichTextStyleDefinition::GetObject(arg, 0)->GetEntity();
	wxRichTextStyleSheet *sheet = Object_wx_RichTextStyleSheet::GetObject(arg, 1)->GetEntity();
	bool update = true;
	if (arg.IsValid(2)) update = arg.GetBoolean(2);
	bool rtn = pThis->GetEntity()->SetStyleDefinition(*styleDef, sheet, update);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextFormattingDialog, UpdateDisplay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextFormattingDialog, UpdateDisplay)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialog *pThis = Object_wx_RichTextFormattingDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->UpdateDisplay();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextFormattingDialog
//----------------------------------------------------------------------------
Object_wx_RichTextFormattingDialog::~Object_wx_RichTextFormattingDialog()
{
}

Object *Object_wx_RichTextFormattingDialog::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextFormattingDialog::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextFormattingDialog:");
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
// Class implementation for wxRichTextFormattingDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFormattingDialog)
{
	Gura_AssignFunction(RichTextFormattingDialog);
	Gura_AssignFunction(RichTextFormattingDialogEmpty);
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
	return new Object_wx_RichTextFormattingDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
