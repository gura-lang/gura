//----------------------------------------------------------------------------
// wxDialog
// extracted from dialog.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(DoOK);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Dialog: public wxDialog, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Dialog *_pObj;
public:
	inline wx_Dialog() : wxDialog(), _sig(NULL), _pObj(NULL) {}
	inline wx_Dialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxDialog(parent, id, title, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	//virtual bool DoOK();
	~wx_Dialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Dialog *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Dialog::~wx_Dialog()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Dialog::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(DialogEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Dialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DialogEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Dialog *pEntity = new wx_Dialog();
	Object_wx_Dialog *pObj = Object_wx_Dialog::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Dialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Dialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Dialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Dialog)
{
	if (!CheckWxReady(sig)) return Value::Null;
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
	wx_Dialog *pEntity = new wx_Dialog(parent, id, title, *pos, *size, style, name);
	Object_wx_Dialog *pObj = Object_wx_Dialog::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Dialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Dialog, AddMainButtonId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, AddMainButtonId)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(0));
	pThis->GetEntity()->AddMainButtonId(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, CanDoLayoutAdaptation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, CanDoLayoutAdaptation)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanDoLayoutAdaptation();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, Centre)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, Centre)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int direction = wxBOTH;
	if (args.IsValid(0)) direction = args.GetInt(0);
	pThis->GetEntity()->Centre(direction);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, Create)
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

Gura_ImplementMethod(wx_Dialog, Create)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
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
	bool rtn = pThis->GetEntity()->Create(parent, id, title, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, CreateButtonSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, CreateButtonSizer)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long flags = args.GetLong(0);
	wxSizer *rtn = (wxSizer *)pThis->GetEntity()->CreateButtonSizer(flags);
	return ReturnValue(env, sig, args, Value(new Object_wx_Sizer(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Dialog, CreateSeparatedButtonSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, CreateSeparatedButtonSizer)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long flags = args.GetLong(0);
	wxSizer *rtn = (wxSizer *)pThis->GetEntity()->CreateSeparatedButtonSizer(flags);
	return ReturnValue(env, sig, args, Value(new Object_wx_Sizer(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Dialog, CreateStdDialogButtonSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, CreateStdDialogButtonSizer)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long flags = args.GetLong(0);
	wxStdDialogButtonSizer *rtn = (wxStdDialogButtonSizer *)pThis->GetEntity()->CreateStdDialogButtonSizer(flags);
	return ReturnValue(env, sig, args, Value(new Object_wx_StdDialogButtonSizer(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Dialog, DoLayoutAdaptation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, DoLayoutAdaptation)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->DoLayoutAdaptation();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, DoOK)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, DoOK)
{
#if 0
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->DoOK();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, EndModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "retCode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, EndModal)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int retCode = args.GetInt(0);
	pThis->GetEntity()->EndModal(retCode);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, GetAffirmativeId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetAffirmativeId)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetAffirmativeId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetEscapeId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetEscapeId)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetEscapeId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetLayoutAdaptationDone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetLayoutAdaptationDone)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetLayoutAdaptationDone();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetLayoutAdaptationLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetLayoutAdaptationLevel)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLayoutAdaptationLevel();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetLayoutAdaptationMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetLayoutAdaptationMode)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDialogLayoutAdaptationMode rtn = pThis->GetEntity()->GetLayoutAdaptationMode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetReturnCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetReturnCode)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetReturnCode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetMainButtonIds)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetMainButtonIds)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxArrayInt &rtn = pThis->GetEntity()->GetMainButtonIds();
	return ReturnValue(env, sig, args, ArrayIntToValue(env, rtn));
}

Gura_DeclareMethod(wx_Dialog, GetToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetToolBar)
{
#if 0
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxToolBar *rtn = (wxToolBar *)pThis->GetEntity()->GetToolBar();
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBar(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, Iconize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "iconize", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, Iconize)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool iconize = args.GetBoolean(0);
	pThis->GetEntity()->Iconize(iconize);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, IsIconized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, IsIconized)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsIconized();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, IsMainButtonId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, IsMainButtonId)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(0));
	bool rtn = pThis->GetEntity()->IsMainButtonId(id);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, IsModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, IsModal)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsModal();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, OnSysColourChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_SysColourChangedEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Dialog, OnSysColourChanged)
{
#if 0
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSysColourChangedEvent *event = Object_wx_SysColourChangedEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnSysColourChanged(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, SetAffirmativeId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetAffirmativeId)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	pThis->GetEntity()->SetAffirmativeId(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, SetEscapeId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetEscapeId)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	pThis->GetEntity()->SetEscapeId(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, SetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetIcon)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxIcon *icon = Object_wx_Icon::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetIcon(*icon);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, SetIcons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icons", VTYPE_wx_IconBundle, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetIcons)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxIconBundle *icons = Object_wx_IconBundle::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetIcons(*icons);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, SetLayoutAdaptationDone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "done", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetLayoutAdaptationDone)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool done = args.GetBoolean(0);
	pThis->GetEntity()->SetLayoutAdaptationDone(done);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, SetLayoutAdaptationLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetLayoutAdaptationLevel)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int level = args.GetInt(0);
	pThis->GetEntity()->SetLayoutAdaptationLevel(level);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, SetLayoutAdaptationMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetLayoutAdaptationMode)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDialogLayoutAdaptationMode mode = static_cast<wxDialogLayoutAdaptationMode>(args.GetInt(0));
	pThis->GetEntity()->SetLayoutAdaptationMode(mode);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, SetReturnCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "retCode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetReturnCode)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int retCode = args.GetInt(0);
	pThis->GetEntity()->SetReturnCode(retCode);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, Show)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool show = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Show(show);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, ShowModal)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, ShowWindowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, ShowWindowModal)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ShowWindowModal();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDialog
//----------------------------------------------------------------------------
Object_wx_Dialog::~Object_wx_Dialog()
{
}

Object *Object_wx_Dialog::Clone() const
{
	return NULL;
}

String Object_wx_Dialog::ToString(bool exprFlag)
{
	String rtn("<wx.Dialog:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Dialog)
{
	Gura_RealizeUserSymbol(DoOK);
	Gura_AssignFunction(DialogEmpty);
	Gura_AssignFunction(Dialog);
	Gura_AssignMethod(wx_Dialog, AddMainButtonId);
	Gura_AssignMethod(wx_Dialog, CanDoLayoutAdaptation);
	Gura_AssignMethod(wx_Dialog, Centre);
	Gura_AssignMethod(wx_Dialog, Create);
	Gura_AssignMethod(wx_Dialog, CreateButtonSizer);
	Gura_AssignMethod(wx_Dialog, CreateSeparatedButtonSizer);
	Gura_AssignMethod(wx_Dialog, CreateStdDialogButtonSizer);
	Gura_AssignMethod(wx_Dialog, DoLayoutAdaptation);
	Gura_AssignMethod(wx_Dialog, DoOK);
	Gura_AssignMethod(wx_Dialog, EndModal);
	Gura_AssignMethod(wx_Dialog, GetAffirmativeId);
	Gura_AssignMethod(wx_Dialog, GetEscapeId);
	Gura_AssignMethod(wx_Dialog, GetLayoutAdaptationDone);
	Gura_AssignMethod(wx_Dialog, GetLayoutAdaptationLevel);
	Gura_AssignMethod(wx_Dialog, GetLayoutAdaptationMode);
	Gura_AssignMethod(wx_Dialog, GetMainButtonIds);
	Gura_AssignMethod(wx_Dialog, GetReturnCode);
	Gura_AssignMethod(wx_Dialog, GetToolBar);
	Gura_AssignMethod(wx_Dialog, Iconize);
	Gura_AssignMethod(wx_Dialog, IsIconized);
	Gura_AssignMethod(wx_Dialog, IsMainButtonId);
	Gura_AssignMethod(wx_Dialog, IsModal);
	Gura_AssignMethod(wx_Dialog, OnSysColourChanged);
	Gura_AssignMethod(wx_Dialog, SetAffirmativeId);
	Gura_AssignMethod(wx_Dialog, SetEscapeId);
	Gura_AssignMethod(wx_Dialog, SetIcon);
	Gura_AssignMethod(wx_Dialog, SetIcons);
	Gura_AssignMethod(wx_Dialog, SetLayoutAdaptationDone);
	Gura_AssignMethod(wx_Dialog, SetLayoutAdaptationLevel);
	Gura_AssignMethod(wx_Dialog, SetLayoutAdaptationMode);
	Gura_AssignMethod(wx_Dialog, SetReturnCode);
	Gura_AssignMethod(wx_Dialog, Show);
	Gura_AssignMethod(wx_Dialog, ShowModal);
	Gura_AssignMethod(wx_Dialog, ShowWindowModal);
}

Gura_ImplementDescendantCreator(wx_Dialog)
{
	return new Object_wx_Dialog((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
