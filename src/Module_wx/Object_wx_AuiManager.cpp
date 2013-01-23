//----------------------------------------------------------------------------
// wxAuiManager
// extracted from auimanager.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AuiManager: public wxAuiManager, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_AuiManager *_pObj;
public:
	inline wx_AuiManager(wxWindow* managed_wnd, unsigned int flags) : wxAuiManager(managed_wnd, flags), _sig(NULL), _pObj(NULL) {}
	~wx_AuiManager();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_AuiManager *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AuiManager::~wx_AuiManager()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_AuiManager::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiManager
//----------------------------------------------------------------------------
Gura_DeclareFunction(AuiManager)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_AuiManager));
	DeclareArg(env, "managed_wnd", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AuiManager)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *managed_wnd = (wxWindow *)(NULL);
	if (args.IsValid(0)) managed_wnd = Object_wx_Window::GetObject(args, 0)->GetEntity();
	unsigned flags = wxAUI_MGR_DEFAULT;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wx_AuiManager *pEntity = new wx_AuiManager(managed_wnd, flags);
	Object_wx_AuiManager *pObj = Object_wx_AuiManager::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AuiManager(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_AuiManager, AddPane)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "pane_info", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, AddPane)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo *pane_info = Object_wx_AuiPaneInfo::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->AddPane(window, *pane_info);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiManager, AddPane_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, AddPane_1)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int direction = wxLEFT;
	if (args.IsValid(1)) direction = args.GetInt(1);
	wxString caption = wxEmptyString;
	if (args.IsValid(2)) caption = wxString::FromUTF8(args.GetString(2));
	bool rtn = pSelf->GetEntity()->AddPane(window, direction, caption);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiManager, AddPane_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "pane_info", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
	DeclareArg(env, "drop_pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, AddPane_2)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo *pane_info = Object_wx_AuiPaneInfo::GetObject(args, 1)->GetEntity();
	wxPoint *drop_pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	bool rtn = pSelf->GetEntity()->AddPane(window, *pane_info, *drop_pos);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiManager, DetachPane)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, DetachPane)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->DetachPane(window);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiManager, GetAllPanes)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, GetAllPanes)
{
#if 0
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfoArray &rtn = pSelf->GetEntity()->GetAllPanes();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfoArray(new wxAuiPaneInfoArray(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiManager, GetArtProvider)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, GetArtProvider)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiDockArt *rtn = (wxAuiDockArt *)pSelf->GetEntity()->GetArtProvider();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiDockArt(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_AuiManager, GetDockSizeConstraint)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "widthpct", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "heightpct", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_AuiManager, GetDockSizeConstraint)
{
#if 0
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	double widthpct = args.GetDouble(0);
	double heightpct = args.GetDouble(1);
	pSelf->GetEntity()->GetDockSizeConstraint(widthpct, heightpct);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiManager, GetFlags)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, GetFlags)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pSelf->GetEntity()->GetFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiManager, GetManagedWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, GetManagedWindow)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pSelf->GetEntity()->GetManagedWindow();
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_AuiManager, GetManager)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_AuiManager, GetManager)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxAuiManager *rtn = (wxAuiManager *)wxAuiManager::GetManager(window);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiManager(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_AuiManager, GetPane)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, GetPane)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->GetPane(window);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiManager, GetPane_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, GetPane_1)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->GetPane(name);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiManager, HideHint)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, HideHint)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->HideHint();
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiManager, InsertPane)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "insert_location", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
	DeclareArg(env, "insert_level", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, InsertPane)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo *insert_location = Object_wx_AuiPaneInfo::GetObject(args, 1)->GetEntity();
	int insert_level = wxAUI_INSERT_PANE;
	if (args.IsValid(2)) insert_level = args.GetInt(2);
	bool rtn = pSelf->GetEntity()->InsertPane(window, *insert_location, insert_level);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiManager, LoadPaneInfo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pane_part", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pane", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, LoadPaneInfo)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString pane_part = wxString::FromUTF8(args.GetString(0));
	wxAuiPaneInfo *pane = Object_wx_AuiPaneInfo::GetObject(args, 1)->GetEntity();
	pSelf->GetEntity()->LoadPaneInfo(pane_part, *pane);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiManager, LoadPerspective)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "perspective", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "update", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, LoadPerspective)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString perspective = wxString::FromUTF8(args.GetString(0));
	bool update = true;
	if (args.IsValid(1)) update = args.GetBoolean(1);
	bool rtn = pSelf->GetEntity()->LoadPerspective(perspective, update);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiManager, ProcessDockResult)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "target", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
	DeclareArg(env, "new_pos", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, ProcessDockResult)
{
#if 0
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo *target = Object_wx_AuiPaneInfo::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo *new_pos = Object_wx_AuiPaneInfo::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->ProcessDockResult(*target, *new_pos);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiManager, SavePaneInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pane", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, SavePaneInfo)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo *pane = Object_wx_AuiPaneInfo::GetObject(args, 0)->GetEntity();
	wxString rtn = pSelf->GetEntity()->SavePaneInfo(*pane);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_AuiManager, SavePerspective)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiManager, SavePerspective)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->SavePerspective();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_AuiManager, SetArtProvider)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "art_provider", VTYPE_wx_AuiDockArt, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, SetArtProvider)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiDockArt *art_provider = Object_wx_AuiDockArt::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetArtProvider(art_provider);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiManager, SetDockSizeConstraint)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "widthpct", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "heightpct", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, SetDockSizeConstraint)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	double widthpct = args.GetDouble(0);
	double heightpct = args.GetDouble(1);
	pSelf->GetEntity()->SetDockSizeConstraint(widthpct, heightpct);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiManager, SetFlags)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, SetFlags)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned flags = args.GetInt(0);
	pSelf->GetEntity()->SetFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiManager, SetManagedWindow)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "managed_wnd", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, SetManagedWindow)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *managed_wnd = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetManagedWindow(managed_wnd);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiManager, ShowHint)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, ShowHint)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->ShowHint(*rect);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiManager, UnInit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, UnInit)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->UnInit();
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiManager, Update)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, Update)
{
	Object_wx_AuiManager *pSelf = Object_wx_AuiManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Update();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxAuiManager
//----------------------------------------------------------------------------
Object_wx_AuiManager::~Object_wx_AuiManager()
{
}

Object *Object_wx_AuiManager::Clone() const
{
	return NULL;
}

String Object_wx_AuiManager::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.AuiManager:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_AuiManager::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(AuiManager);
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiManager)
{
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
	return new Object_wx_AuiManager((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
