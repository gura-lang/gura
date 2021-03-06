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
	//Gura::Signal *_pSig;
	Object_wx_Dialog *_pObj;
public:
	inline wx_Dialog() : wxDialog(), _pObj(nullptr) {}
	inline wx_Dialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxDialog(parent, id, title, pos, size, style, name), _pObj(nullptr) {}
	//virtual bool DoOK();
	~wx_Dialog();
	inline void AssocWithGura(Object_wx_Dialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Dialog::~wx_Dialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Dialog::GuraObjectDeleted()
{
	_pObj = nullptr;
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Dialog *pEntity = new wx_Dialog();
	Object_wx_Dialog *pObj = Object_wx_Dialog::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Dialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
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
	wx_Dialog *pEntity = new wx_Dialog(parent, id, title, *pos, *size, style, name);
	Object_wx_Dialog *pObj = Object_wx_Dialog::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Dialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_Dialog, AddMainButtonId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, AddMainButtonId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(0));
	pThis->GetEntity()->AddMainButtonId(id);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, CanDoLayoutAdaptation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, CanDoLayoutAdaptation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanDoLayoutAdaptation();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, Centre)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, Centre)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int direction = wxBOTH;
	if (arg.IsValid(0)) direction = arg.GetInt(0);
	pThis->GetEntity()->Centre(direction);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_Dialog, CreateButtonSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, CreateButtonSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long flags = arg.GetLong(0);
	wxSizer *rtn = (wxSizer *)pThis->GetEntity()->CreateButtonSizer(flags);
	return ReturnValue(env, arg, Value(new Object_wx_Sizer(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Dialog, CreateSeparatedButtonSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, CreateSeparatedButtonSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long flags = arg.GetLong(0);
	wxSizer *rtn = (wxSizer *)pThis->GetEntity()->CreateSeparatedButtonSizer(flags);
	return ReturnValue(env, arg, Value(new Object_wx_Sizer(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Dialog, CreateStdDialogButtonSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, CreateStdDialogButtonSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long flags = arg.GetLong(0);
	wxStdDialogButtonSizer *rtn = (wxStdDialogButtonSizer *)pThis->GetEntity()->CreateStdDialogButtonSizer(flags);
	return ReturnValue(env, arg, Value(new Object_wx_StdDialogButtonSizer(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Dialog, DoLayoutAdaptation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, DoLayoutAdaptation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->DoLayoutAdaptation();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, DoOK)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, DoOK)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->DoOK();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, EndModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "retCode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, EndModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int retCode = arg.GetInt(0);
	pThis->GetEntity()->EndModal(retCode);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, GetAffirmativeId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetAffirmativeId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetAffirmativeId();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetEscapeId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetEscapeId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetEscapeId();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetLayoutAdaptationDone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetLayoutAdaptationDone)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetLayoutAdaptationDone();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetLayoutAdaptationLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetLayoutAdaptationLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetLayoutAdaptationLevel();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetLayoutAdaptationMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetLayoutAdaptationMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDialogLayoutAdaptationMode rtn = pThis->GetEntity()->GetLayoutAdaptationMode();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetReturnCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetReturnCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetReturnCode();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetMainButtonIds)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetMainButtonIds)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArrayInt &rtn = pThis->GetEntity()->GetMainButtonIds();
	return ReturnValue(env, arg, ArrayIntToValue(env, rtn));
}

Gura_DeclareMethod(wx_Dialog, GetToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetToolBar)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxToolBar *rtn = (wxToolBar *)pThis->GetEntity()->GetToolBar();
	return ReturnValue(env, arg, Value(new Object_wx_ToolBar(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, Iconize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "iconize", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, Iconize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool iconize = arg.GetBoolean(0);
	pThis->GetEntity()->Iconize(iconize);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, IsIconized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, IsIconized)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsIconized();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, IsMainButtonId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, IsMainButtonId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(0));
	bool rtn = pThis->GetEntity()->IsMainButtonId(id);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, IsModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, IsModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsModal();
	return ReturnValue(env, arg, Value(rtn));
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSysColourChangedEvent *event = Object_wx_SysColourChangedEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnSysColourChanged(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetAffirmativeId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetAffirmativeId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	pThis->GetEntity()->SetAffirmativeId(id);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetEscapeId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetEscapeId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	pThis->GetEntity()->SetEscapeId(id);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxIcon *icon = Object_wx_Icon::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetIcon(*icon);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetIcons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icons", VTYPE_wx_IconBundle, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetIcons)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxIconBundle *icons = Object_wx_IconBundle::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetIcons(*icons);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetLayoutAdaptationDone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "done", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetLayoutAdaptationDone)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool done = arg.GetBoolean(0);
	pThis->GetEntity()->SetLayoutAdaptationDone(done);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetLayoutAdaptationLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetLayoutAdaptationLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int level = arg.GetInt(0);
	pThis->GetEntity()->SetLayoutAdaptationLevel(level);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetLayoutAdaptationMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetLayoutAdaptationMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDialogLayoutAdaptationMode mode = static_cast<wxDialogLayoutAdaptationMode>(arg.GetInt(0));
	pThis->GetEntity()->SetLayoutAdaptationMode(mode);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetReturnCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "retCode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetReturnCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int retCode = arg.GetInt(0);
	pThis->GetEntity()->SetReturnCode(retCode);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool show = arg.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Show(show);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, ShowWindowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, ShowWindowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->ShowWindowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDialog
//----------------------------------------------------------------------------
Object_wx_Dialog::~Object_wx_Dialog()
{
}

Object *Object_wx_Dialog::Clone() const
{
	return nullptr;
}

String Object_wx_Dialog::ToString(bool exprFlag)
{
	String rtn("<wx.Dialog:");
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
	return new Object_wx_Dialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
