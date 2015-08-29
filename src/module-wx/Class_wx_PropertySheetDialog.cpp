//----------------------------------------------------------------------------
// wxPropertySheetDialog
// extracted from propdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(AddBookCtrl);
Gura_DeclarePrivUserSymbol(CreateBookCtrl);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PropertySheetDialog: public wxPropertySheetDialog, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PropertySheetDialog *_pObj;
public:
	inline wx_PropertySheetDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPropertySheetDialog(parent, id, title, pos, size, style, name), _pObj(nullptr) {}
	//virtual void AddBookCtrl(wxSizer* sizer);
	//virtual wxBookCtrlBase* CreateBookCtrl();
	~wx_PropertySheetDialog();
	inline void AssocWithGura(Object_wx_PropertySheetDialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PropertySheetDialog::~wx_PropertySheetDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PropertySheetDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertySheetDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(PropertySheetDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PropertySheetDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PropertySheetDialog)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = arg.IsValid(0)?
			Object_wx_Window::GetObject(arg, 0)->GetEntity() : nullptr;
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString title = wxString::FromUTF8(arg.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxT("dialogBox");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	wx_PropertySheetDialog *pEntity = new wx_PropertySheetDialog(parent, id, title, *pos, *size, style, name);
	Object_wx_PropertySheetDialog *pObj = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_PropertySheetDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_PropertySheetDialog, AddBookCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizer", VTYPE_wx_Sizer, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, AddBookCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->AddBookCtrl(sizer);
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PropertySheetDialog, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = arg.IsValid(0)?
			Object_wx_Window::GetObject(arg, 0)->GetEntity() : nullptr;
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString title = wxString::FromUTF8(arg.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxT("dialogBox");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	bool rtn = pThis->GetEntity()->Create(parent, id, title, *pos, *size, style, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_PropertySheetDialog, CreateBookCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PropertySheetDialog, CreateBookCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBookCtrlBase *rtn = (wxBookCtrlBase *)pThis->GetEntity()->CreateBookCtrl();
	return ReturnValue(env, arg, Value(new Object_wx_BookCtrlBase(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_PropertySheetDialog, CreateButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PropertySheetDialog, CreateButtons)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int flags = wxOK|wxCANCEL;
	if (arg.IsValid(0)) flags = arg.GetInt(0);
	pThis->GetEntity()->CreateButtons(flags);
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, GetBookCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PropertySheetDialog, GetBookCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBookCtrlBase *rtn = (wxBookCtrlBase *)pThis->GetEntity()->GetBookCtrl();
	return ReturnValue(env, arg, Value(new Object_wx_BookCtrlBase(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_PropertySheetDialog, GetInnerSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PropertySheetDialog, GetInnerSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizer *rtn = (wxSizer *)pThis->GetEntity()->GetInnerSizer();
	return ReturnValue(env, arg, Value(new Object_wx_Sizer(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_PropertySheetDialog, GetSheetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PropertySheetDialog, GetSheetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetSheetStyle();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_PropertySheetDialog, LayoutDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "centreFlags", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PropertySheetDialog, LayoutDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int centreFlags = wxBOTH;
	if (arg.IsValid(0)) centreFlags = arg.GetInt(0);
	pThis->GetEntity()->LayoutDialog(centreFlags);
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, SetBookCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bookCtrl", VTYPE_wx_BookCtrlBase, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, SetBookCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBookCtrlBase *bookCtrl = Object_wx_BookCtrlBase::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetBookCtrl(bookCtrl);
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, SetInnerSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "sizer", VTYPE_wx_Sizer, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_PropertySheetDialog, SetInnerSizer)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetInnerSizer(sizer);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, SetSheetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, SetSheetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long style = arg.GetLong(0);
	pThis->GetEntity()->SetSheetStyle(style);
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, SetSheetOuterBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, SetSheetOuterBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int border = arg.GetInt(0);
	pThis->GetEntity()->SetSheetOuterBorder(border);
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, SetSheetInnerBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, SetSheetInnerBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int border = arg.GetInt(0);
	pThis->GetEntity()->SetSheetInnerBorder(border);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxPropertySheetDialog
//----------------------------------------------------------------------------
Object_wx_PropertySheetDialog::~Object_wx_PropertySheetDialog()
{
}

Object *Object_wx_PropertySheetDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PropertySheetDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PropertySheetDialog:");
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
// Class implementation for wxPropertySheetDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertySheetDialog)
{
	Gura_RealizeUserSymbol(AddBookCtrl);
	Gura_RealizeUserSymbol(CreateBookCtrl);
	Gura_AssignFunction(PropertySheetDialog);
	Gura_AssignMethod(wx_PropertySheetDialog, AddBookCtrl);
	Gura_AssignMethod(wx_PropertySheetDialog, Create);
	Gura_AssignMethod(wx_PropertySheetDialog, CreateBookCtrl);
	Gura_AssignMethod(wx_PropertySheetDialog, CreateButtons);
	Gura_AssignMethod(wx_PropertySheetDialog, GetBookCtrl);
	Gura_AssignMethod(wx_PropertySheetDialog, GetInnerSizer);
	Gura_AssignMethod(wx_PropertySheetDialog, GetSheetStyle);
	Gura_AssignMethod(wx_PropertySheetDialog, LayoutDialog);
	Gura_AssignMethod(wx_PropertySheetDialog, SetBookCtrl);
	Gura_AssignMethod(wx_PropertySheetDialog, SetInnerSizer);
	Gura_AssignMethod(wx_PropertySheetDialog, SetSheetStyle);
	Gura_AssignMethod(wx_PropertySheetDialog, SetSheetOuterBorder);
	Gura_AssignMethod(wx_PropertySheetDialog, SetSheetInnerBorder);
}

Gura_ImplementDescendantCreator(wx_PropertySheetDialog)
{
	return new Object_wx_PropertySheetDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
