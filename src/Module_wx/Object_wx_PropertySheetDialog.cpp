//----------------------------------------------------------------------------
// wxPropertySheetDialog
// extracted from propdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(AddBookCtrl);
Gura_DeclarePrivUserSymbol(CreateBookCtrl);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PropertySheetDialog: public wxPropertySheetDialog, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PropertySheetDialog *_pObj;
public:
	inline wx_PropertySheetDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPropertySheetDialog(parent, id, title, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	//virtual void AddBookCtrl(wxSizer* sizer);
	//virtual wxBookCtrlBase* CreateBookCtrl();
	~wx_PropertySheetDialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PropertySheetDialog *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PropertySheetDialog::~wx_PropertySheetDialog()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PropertySheetDialog::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertySheetDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(PropertySheetDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : NULL;
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString title = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("dialogBox");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	wx_PropertySheetDialog *pEntity = new wx_PropertySheetDialog(parent, id, title, *pos, *size, style, name);
	Object_wx_PropertySheetDialog *pObj = Object_wx_PropertySheetDialog::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PropertySheetDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_PropertySheetDialog, AddBookCtrl)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizer", VTYPE_wx_Sizer, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, AddBookCtrl)
{
	Object_wx_PropertySheetDialog *pSelf = Object_wx_PropertySheetDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->AddBookCtrl(sizer);
	return Value::Null;
}

Gura_DeclareMethod(wx_PropertySheetDialog, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_PropertySheetDialog *pSelf = Object_wx_PropertySheetDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : NULL;
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString title = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("dialogBox");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	bool rtn = pSelf->GetEntity()->Create(parent, id, title, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PropertySheetDialog, CreateBookCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PropertySheetDialog, CreateBookCtrl)
{
	Object_wx_PropertySheetDialog *pSelf = Object_wx_PropertySheetDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBookCtrlBase *rtn = (wxBookCtrlBase *)pSelf->GetEntity()->CreateBookCtrl();
	return ReturnValue(env, sig, args, Value(new Object_wx_BookCtrlBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_PropertySheetDialog, CreateButtons)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PropertySheetDialog, CreateButtons)
{
	Object_wx_PropertySheetDialog *pSelf = Object_wx_PropertySheetDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int flags = wxOK|wxCANCEL;
	if (args.IsValid(0)) flags = args.GetInt(0);
	pSelf->GetEntity()->CreateButtons(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_PropertySheetDialog, GetBookCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PropertySheetDialog, GetBookCtrl)
{
	Object_wx_PropertySheetDialog *pSelf = Object_wx_PropertySheetDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBookCtrlBase *rtn = (wxBookCtrlBase *)pSelf->GetEntity()->GetBookCtrl();
	return ReturnValue(env, sig, args, Value(new Object_wx_BookCtrlBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_PropertySheetDialog, GetInnerSizer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PropertySheetDialog, GetInnerSizer)
{
	Object_wx_PropertySheetDialog *pSelf = Object_wx_PropertySheetDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSizer *rtn = (wxSizer *)pSelf->GetEntity()->GetInnerSizer();
	return ReturnValue(env, sig, args, Value(new Object_wx_Sizer(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_PropertySheetDialog, GetSheetStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PropertySheetDialog, GetSheetStyle)
{
	Object_wx_PropertySheetDialog *pSelf = Object_wx_PropertySheetDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetSheetStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PropertySheetDialog, LayoutDialog)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "centreFlags", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PropertySheetDialog, LayoutDialog)
{
	Object_wx_PropertySheetDialog *pSelf = Object_wx_PropertySheetDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int centreFlags = wxBOTH;
	if (args.IsValid(0)) centreFlags = args.GetInt(0);
	pSelf->GetEntity()->LayoutDialog(centreFlags);
	return Value::Null;
}

Gura_DeclareMethod(wx_PropertySheetDialog, SetBookCtrl)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bookCtrl", VTYPE_wx_BookCtrlBase, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, SetBookCtrl)
{
	Object_wx_PropertySheetDialog *pSelf = Object_wx_PropertySheetDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBookCtrlBase *bookCtrl = Object_wx_BookCtrlBase::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetBookCtrl(bookCtrl);
	return Value::Null;
}

Gura_DeclareMethod(wx_PropertySheetDialog, SetInnerSizer)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "sizer", VTYPE_wx_Sizer, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_PropertySheetDialog, SetInnerSizer)
{
#if 0
	Object_wx_PropertySheetDialog *pSelf = Object_wx_PropertySheetDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetInnerSizer(sizer);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_PropertySheetDialog, SetSheetStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, SetSheetStyle)
{
	Object_wx_PropertySheetDialog *pSelf = Object_wx_PropertySheetDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long style = args.GetLong(0);
	pSelf->GetEntity()->SetSheetStyle(style);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxPropertySheetDialog
//----------------------------------------------------------------------------
Object_wx_PropertySheetDialog::~Object_wx_PropertySheetDialog()
{
}

Object *Object_wx_PropertySheetDialog::Clone() const
{
	return NULL;
}

String Object_wx_PropertySheetDialog::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PropertySheetDialog:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PropertySheetDialog::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(AddBookCtrl);
	Gura_RealizeUserSymbol(CreateBookCtrl);
	Gura_AssignFunction(PropertySheetDialog);
}

//----------------------------------------------------------------------------
// Class implementation for wxPropertySheetDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertySheetDialog)
{
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
}

Gura_ImplementDescendantCreator(wx_PropertySheetDialog)
{
	return new Object_wx_PropertySheetDialog((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
