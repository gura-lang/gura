//----------------------------------------------------------------------------
// wxAuiManager
// extracted from auimanager.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AuiManager: public wxAuiManager, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_AuiManager *_pObj;
public:
	inline wx_AuiManager(wxWindow* managed_wnd, unsigned int flags) : wxAuiManager(managed_wnd, flags), _pObj(nullptr) {}
	~wx_AuiManager();
	inline void AssocWithGura(Object_wx_AuiManager *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AuiManager::~wx_AuiManager()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_AuiManager::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiManager
//----------------------------------------------------------------------------
Gura_DeclareFunction(AuiManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_AuiManager));
	DeclareArg(env, "managed_wnd", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AuiManager)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *managed_wnd = (wxWindow *)(nullptr);
	if (arg.IsValid(0)) managed_wnd = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	unsigned flags = wxAUI_MGR_DEFAULT;
	if (arg.IsValid(1)) flags = arg.GetInt(1);
	wx_AuiManager *pEntity = new wx_AuiManager(managed_wnd, flags);
	Object_wx_AuiManager *pObj = Object_wx_AuiManager::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_AuiManager(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_AuiManager, AddPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "pane_info", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, AddPane)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxAuiPaneInfo *pane_info = Object_wx_AuiPaneInfo::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->AddPane(window, *pane_info);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiManager, AddPane_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, AddPane_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	int direction = wxLEFT;
	if (arg.IsValid(1)) direction = arg.GetInt(1);
	wxString caption = wxEmptyString;
	if (arg.IsValid(2)) caption = wxString::FromUTF8(arg.GetString(2));
	bool rtn = pThis->GetEntity()->AddPane(window, direction, caption);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiManager, AddPane_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "pane_info", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
	DeclareArg(env, "drop_pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, AddPane_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxAuiPaneInfo *pane_info = Object_wx_AuiPaneInfo::GetObject(arg, 1)->GetEntity();
	wxPoint *drop_pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->AddPane(window, *pane_info, *drop_pos);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiManager, DetachPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, DetachPane)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->DetachPane(window);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiManager, GetAllPanes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, GetAllPanes)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfoArray &rtn = pThis->GetEntity()->GetAllPanes();
	return ReturnValue(env, arg, Value(new Object_wx_AuiPaneInfoArray(new wxAuiPaneInfoArray(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, GetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, GetArtProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiDockArt *rtn = (wxAuiDockArt *)pThis->GetEntity()->GetArtProvider();
	return ReturnValue(env, arg, Value(new Object_wx_AuiDockArt(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_AuiManager, GetDockSizeConstraint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "widthpct", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "heightpct", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_AuiManager, GetDockSizeConstraint)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double widthpct = arg.GetDouble(0);
	double heightpct = arg.GetDouble(1);
	pThis->GetEntity()->GetDockSizeConstraint(widthpct, heightpct);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiManager, GetManagedWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, GetManagedWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetManagedWindow();
	return ReturnValue(env, arg, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_AuiManager, GetManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_AuiManager, GetManager)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxAuiManager *rtn = (wxAuiManager *)wxAuiManager::GetManager(window);
	return ReturnValue(env, arg, Value(new Object_wx_AuiManager(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_AuiManager, GetPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, GetPane)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxAuiPaneInfo &rtn = pThis->GetEntity()->GetPane(window);
	return ReturnValue(env, arg, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiManager, GetPane_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, GetPane_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxAuiPaneInfo &rtn = pThis->GetEntity()->GetPane(name);
	return ReturnValue(env, arg, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiManager, HideHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, HideHint)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->HideHint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, InsertPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "insert_location", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
	DeclareArg(env, "insert_level", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, InsertPane)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxAuiPaneInfo *insert_location = Object_wx_AuiPaneInfo::GetObject(arg, 1)->GetEntity();
	int insert_level = wxAUI_INSERT_PANE;
	if (arg.IsValid(2)) insert_level = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->InsertPane(window, *insert_location, insert_level);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiManager, LoadPaneInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pane_part", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pane", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, LoadPaneInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString pane_part = wxString::FromUTF8(arg.GetString(0));
	wxAuiPaneInfo *pane = Object_wx_AuiPaneInfo::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->LoadPaneInfo(pane_part, *pane);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, LoadPerspective)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "perspective", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "update", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, LoadPerspective)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString perspective = wxString::FromUTF8(arg.GetString(0));
	bool update = true;
	if (arg.IsValid(1)) update = arg.GetBoolean(1);
	bool rtn = pThis->GetEntity()->LoadPerspective(perspective, update);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AuiManager, ProcessDockResult)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "target", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
	DeclareArg(env, "new_pos", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, ProcessDockResult)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo *target = Object_wx_AuiPaneInfo::GetObject(arg, 0)->GetEntity();
	wxAuiPaneInfo *new_pos = Object_wx_AuiPaneInfo::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->ProcessDockResult(*target, *new_pos);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, SavePaneInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pane", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, SavePaneInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo *pane = Object_wx_AuiPaneInfo::GetObject(arg, 0)->GetEntity();
	wxString rtn = pThis->GetEntity()->SavePaneInfo(*pane);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_AuiManager, SavePerspective)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, SavePerspective)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->SavePerspective();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_AuiManager, SetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "art_provider", VTYPE_wx_AuiDockArt, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, SetArtProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiDockArt *art_provider = Object_wx_AuiDockArt::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetArtProvider(art_provider);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, SetDockSizeConstraint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "widthpct", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "heightpct", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, SetDockSizeConstraint)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double widthpct = arg.GetDouble(0);
	double heightpct = arg.GetDouble(1);
	pThis->GetEntity()->SetDockSizeConstraint(widthpct, heightpct);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned flags = arg.GetInt(0);
	pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, SetManagedWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "managed_wnd", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, SetManagedWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *managed_wnd = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetManagedWindow(managed_wnd);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, ShowHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, ShowHint)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->ShowHint(*rect);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, UnInit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, UnInit)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->UnInit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, Update)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, Update)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Update();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxAuiManager
//----------------------------------------------------------------------------
Object_wx_AuiManager::~Object_wx_AuiManager()
{
}

Object *Object_wx_AuiManager::Clone() const
{
	return nullptr;
}

String Object_wx_AuiManager::ToString(bool exprFlag)
{
	String rtn("<wx.AuiManager:");
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
// Class implementation for wxAuiManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiManager)
{
	Gura_AssignFunction(AuiManager);
	Gura_AssignMethod(wx_AuiManager, AddPane);
	Gura_AssignMethod(wx_AuiManager, AddPane_1);
	Gura_AssignMethod(wx_AuiManager, AddPane_2);
	Gura_AssignMethod(wx_AuiManager, DetachPane);
	Gura_AssignMethod(wx_AuiManager, GetAllPanes);
	Gura_AssignMethod(wx_AuiManager, GetArtProvider);
	Gura_AssignMethod(wx_AuiManager, GetDockSizeConstraint);
	Gura_AssignMethod(wx_AuiManager, GetFlags);
	Gura_AssignMethod(wx_AuiManager, GetManagedWindow);
	Gura_AssignMethod(wx_AuiManager, GetManager);
	Gura_AssignMethod(wx_AuiManager, GetPane);
	Gura_AssignMethod(wx_AuiManager, GetPane_1);
	Gura_AssignMethod(wx_AuiManager, HideHint);
	Gura_AssignMethod(wx_AuiManager, InsertPane);
	Gura_AssignMethod(wx_AuiManager, LoadPaneInfo);
	Gura_AssignMethod(wx_AuiManager, LoadPerspective);
	Gura_AssignMethod(wx_AuiManager, ProcessDockResult);
	Gura_AssignMethod(wx_AuiManager, SavePaneInfo);
	Gura_AssignMethod(wx_AuiManager, SavePerspective);
	Gura_AssignMethod(wx_AuiManager, SetArtProvider);
	Gura_AssignMethod(wx_AuiManager, SetDockSizeConstraint);
	Gura_AssignMethod(wx_AuiManager, SetFlags);
	Gura_AssignMethod(wx_AuiManager, SetManagedWindow);
	Gura_AssignMethod(wx_AuiManager, ShowHint);
	Gura_AssignMethod(wx_AuiManager, UnInit);
	Gura_AssignMethod(wx_AuiManager, Update);
}

Gura_ImplementDescendantCreator(wx_AuiManager)
{
	return new Object_wx_AuiManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
