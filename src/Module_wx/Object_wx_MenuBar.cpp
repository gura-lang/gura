//----------------------------------------------------------------------------
// wxMenuBar
// extracted from menu.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MenuBar: public wxMenuBar, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MenuBar *_pObj;
public:
	inline wx_MenuBar(long style) : wxMenuBar(style), _sig(NULL), _pObj(NULL) {}
	//inline wx_MenuBar(size_t n, wxMenu* menus[], const wxString titles[], long style) : wxMenuBar(n, menus[], titles[], style), _sig(NULL), _pObj(NULL) {}
	~wx_MenuBar();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MenuBar *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MenuBar::~wx_MenuBar()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MenuBar::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMenuBar
//----------------------------------------------------------------------------
Gura_DeclareFunction(MenuBar)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MenuBar));
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MenuBar)
{
	if (!CheckWxReady(sig)) return Value::Null;
	long style = 0;
	if (args.IsValid(0)) style = args.GetLong(0);
	wx_MenuBar *pEntity = new wx_MenuBar(style);
	Object_wx_MenuBar *pObj = Object_wx_MenuBar::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MenuBar(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(MenuBar_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_MenuBar));
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "menus[]", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "titles[]", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(MenuBar_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	size_t n = args.GetSizeT(0);
	wxMenu *menus[] = Object_wx_Menu::GetObject(args, 1)->GetEntity();
	wxString titles[] = wxString::FromUTF8(args.GetString(2));
	long style = 0;
	if (args.IsValid(3)) style = args.GetLong(3);
	wx_MenuBar *pEntity = new wx_MenuBar(n, menus[], titles[], style);
	Object_wx_MenuBar *pObj = Object_wx_MenuBar::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MenuBar(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuBar, Append)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, Append)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	wxString title = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->Append(menu, title);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuBar, Check)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "check", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, Check)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	bool check = args.GetBoolean(1);
	pThis->GetEntity()->Check(id, check);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuBar, Enable)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, Enable)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	bool enable = args.GetBoolean(1);
	pThis->GetEntity()->Enable(id, enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuBar, EnableTop)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, EnableTop)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pos = args.GetInt(0);
	bool enable = args.GetBoolean(1);
	pThis->GetEntity()->EnableTop(pos, enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuBar, FindMenu)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, FindMenu)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString title = wxString::FromUTF8(args.GetString(0));
	int rtn = pThis->GetEntity()->FindMenu(title);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuBar, FindMenuItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "menuString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "itemString", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, FindMenuItem)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString menuString = wxString::FromUTF8(args.GetString(0));
	wxString itemString = wxString::FromUTF8(args.GetString(1));
	int rtn = pThis->GetEntity()->FindMenuItem(menuString, itemString);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuBar, FindItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "**menu", VTYPE_wx_Menu, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, FindItem)
{
#if 0
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxMenu ***menu = (wxMenu *)(&NULL);
	if (args.IsValid(1)) **menu = Object_wx_Menu::GetObject(args, 1)->GetEntity();
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->FindItem(id, ***menu);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuBar, GetHelpString)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, GetHelpString)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetHelpString(id);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MenuBar, GetLabel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, GetLabel)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetLabel(id);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MenuBar, GetLabelTop)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, GetLabelTop)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pos = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetLabelTop(pos);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MenuBar, GetMenu)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "menuIndex", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, GetMenu)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int menuIndex = args.GetInt(0);
	wxMenu *rtn = (wxMenu *)pThis->GetEntity()->GetMenu(menuIndex);
	return ReturnValue(env, sig, args, Value(new Object_wx_Menu(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_MenuBar, GetMenuCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, GetMenuCount)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMenuCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuBar, GetMenuLabel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, GetMenuLabel)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pos = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetMenuLabel(pos);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MenuBar, GetMenuLabelText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, GetMenuLabelText)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pos = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetMenuLabelText(pos);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MenuBar, Insert)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, Insert)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	wxMenu *menu = Object_wx_Menu::GetObject(args, 1)->GetEntity();
	wxString title = wxString::FromUTF8(args.GetString(2));
	bool rtn = pThis->GetEntity()->Insert(pos, menu, title);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuBar, IsChecked)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, IsChecked)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	bool rtn = pThis->GetEntity()->IsChecked(id);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuBar, IsEnabled)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, IsEnabled)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	bool rtn = pThis->GetEntity()->IsEnabled(id);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuBar, Refresh)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, Refresh)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Refresh();
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuBar, Remove)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, Remove)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	wxMenu *rtn = (wxMenu *)pThis->GetEntity()->Remove(pos);
	return ReturnValue(env, sig, args, Value(new Object_wx_Menu(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_MenuBar, Replace)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, Replace)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	wxMenu *menu = Object_wx_Menu::GetObject(args, 1)->GetEntity();
	wxString title = wxString::FromUTF8(args.GetString(2));
	wxMenu *rtn = (wxMenu *)pThis->GetEntity()->Replace(pos, menu, title);
	return ReturnValue(env, sig, args, Value(new Object_wx_Menu(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_MenuBar, SetHelpString)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, SetHelpString)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString helpString = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetHelpString(id, helpString);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuBar, SetLabel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, SetLabel)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString label = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetLabel(id, label);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuBar, SetLabelTop)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, SetLabelTop)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pos = args.GetInt(0);
	wxString label = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetLabelTop(pos, label);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuBar, SetMenuLabel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, SetMenuLabel)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pos = args.GetInt(0);
	wxString label = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetMenuLabel(pos, label);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxMenuBar
//----------------------------------------------------------------------------
Object_wx_MenuBar::~Object_wx_MenuBar()
{
}

Object *Object_wx_MenuBar::Clone() const
{
	return NULL;
}

String Object_wx_MenuBar::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MenuBar:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_MenuBar::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(MenuBar);
	Gura_AssignFunction(MenuBar_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxMenuBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MenuBar)
{
	Gura_AssignMethod(wx_MenuBar, Append);
	Gura_AssignMethod(wx_MenuBar, Check);
	Gura_AssignMethod(wx_MenuBar, Enable);
	Gura_AssignMethod(wx_MenuBar, EnableTop);
	Gura_AssignMethod(wx_MenuBar, FindMenu);
	Gura_AssignMethod(wx_MenuBar, FindMenuItem);
	Gura_AssignMethod(wx_MenuBar, FindItem);
	Gura_AssignMethod(wx_MenuBar, GetHelpString);
	Gura_AssignMethod(wx_MenuBar, GetLabel);
	Gura_AssignMethod(wx_MenuBar, GetLabelTop);
	Gura_AssignMethod(wx_MenuBar, GetMenu);
	Gura_AssignMethod(wx_MenuBar, GetMenuCount);
	Gura_AssignMethod(wx_MenuBar, GetMenuLabel);
	Gura_AssignMethod(wx_MenuBar, GetMenuLabelText);
	Gura_AssignMethod(wx_MenuBar, Insert);
	Gura_AssignMethod(wx_MenuBar, IsChecked);
	Gura_AssignMethod(wx_MenuBar, IsEnabled);
	Gura_AssignMethod(wx_MenuBar, Refresh);
	Gura_AssignMethod(wx_MenuBar, Remove);
	Gura_AssignMethod(wx_MenuBar, Replace);
	Gura_AssignMethod(wx_MenuBar, SetHelpString);
	Gura_AssignMethod(wx_MenuBar, SetLabel);
	Gura_AssignMethod(wx_MenuBar, SetLabelTop);
	Gura_AssignMethod(wx_MenuBar, SetMenuLabel);
}

Gura_ImplementDescendantCreator(wx_MenuBar)
{
	return new Object_wx_MenuBar((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
