//----------------------------------------------------------------------------
// wxMenuBar
// extracted from menu.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MenuBar: public wxMenuBar, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MenuBar *_pObj;
public:
	inline wx_MenuBar(long style) : wxMenuBar(style), _pObj(nullptr) {}
	//inline wx_MenuBar(size_t n, wxMenu* menus[], const wxString titles[], long style) : wxMenuBar(n, menus[], titles[], style), _pObj(nullptr) {}
	~wx_MenuBar();
	inline void AssocWithGura(Object_wx_MenuBar *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MenuBar::~wx_MenuBar()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MenuBar::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMenuBar
//----------------------------------------------------------------------------
Gura_DeclareFunction(MenuBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MenuBar));
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MenuBar)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	long style = 0;
	if (arg.IsValid(0)) style = arg.GetLong(0);
	wx_MenuBar *pEntity = new wx_MenuBar(style);
	Object_wx_MenuBar *pObj = Object_wx_MenuBar::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MenuBar(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(MenuBar_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	size_t n = arg.GetSizeT(0);
	wxMenu *menus[] = Object_wx_Menu::GetObject(arg, 1)->GetEntity();
	wxString titles[] = wxString::FromUTF8(arg.GetString(2));
	long style = 0;
	if (arg.IsValid(3)) style = arg.GetLong(3);
	wx_MenuBar *pEntity = new wx_MenuBar(n, menus[], titles[], style);
	Object_wx_MenuBar *pObj = Object_wx_MenuBar::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MenuBar(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, Append)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenu *menu = Object_wx_Menu::GetObject(arg, 0)->GetEntity();
	wxString title = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->Append(menu, title);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MenuBar, Check)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "check", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, Check)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	bool check = arg.GetBoolean(1);
	pThis->GetEntity()->Check(id, check);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, Enable)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	bool enable = arg.GetBoolean(1);
	pThis->GetEntity()->Enable(id, enable);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, EnableTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, EnableTop)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pos = arg.GetInt(0);
	bool enable = arg.GetBoolean(1);
	pThis->GetEntity()->EnableTop(pos, enable);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, FindMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, FindMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString title = wxString::FromUTF8(arg.GetString(0));
	int rtn = pThis->GetEntity()->FindMenu(title);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MenuBar, FindMenuItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "menuString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "itemString", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, FindMenuItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString menuString = wxString::FromUTF8(arg.GetString(0));
	wxString itemString = wxString::FromUTF8(arg.GetString(1));
	int rtn = pThis->GetEntity()->FindMenuItem(menuString, itemString);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MenuBar, FindItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "**menu", VTYPE_wx_Menu, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, FindItem)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxMenu ***menu = (wxMenu *)(&nullptr);
	if (arg.IsValid(1)) **menu = Object_wx_Menu::GetObject(arg, 1)->GetEntity();
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->FindItem(id, ***menu);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, GetHelpString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, GetHelpString)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetHelpString(id);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MenuBar, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, GetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetLabel(id);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MenuBar, GetLabelTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, GetLabelTop)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pos = arg.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetLabelTop(pos);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_Obsolete(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, GetMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "menuIndex", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, GetMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int menuIndex = arg.GetInt(0);
	wxMenu *rtn = (wxMenu *)pThis->GetEntity()->GetMenu(menuIndex);
	return ReturnValue(env, arg, Value(new Object_wx_Menu(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_MenuBar, GetMenuCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, GetMenuCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetMenuCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MenuBar, GetMenuLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, GetMenuLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pos = arg.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetMenuLabel(pos);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MenuBar, GetMenuLabelText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, GetMenuLabelText)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pos = arg.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetMenuLabelText(pos);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MenuBar, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, Insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = arg.GetSizeT(0);
	wxMenu *menu = Object_wx_Menu::GetObject(arg, 1)->GetEntity();
	wxString title = wxString::FromUTF8(arg.GetString(2));
	bool rtn = pThis->GetEntity()->Insert(pos, menu, title);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MenuBar, IsChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, IsChecked)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->IsChecked(id);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MenuBar, IsEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, IsEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->IsEnabled(id);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_MenuBar, Refresh)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, Refresh)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Refresh();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = arg.GetSizeT(0);
	wxMenu *rtn = (wxMenu *)pThis->GetEntity()->Remove(pos);
	return ReturnValue(env, arg, Value(new Object_wx_Menu(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_MenuBar, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuBar, Replace)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = arg.GetSizeT(0);
	wxMenu *menu = Object_wx_Menu::GetObject(arg, 1)->GetEntity();
	wxString title = wxString::FromUTF8(arg.GetString(2));
	wxMenu *rtn = (wxMenu *)pThis->GetEntity()->Replace(pos, menu, title);
	return ReturnValue(env, arg, Value(new Object_wx_Menu(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_MenuBar, SetHelpString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, SetHelpString)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString helpString = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->SetHelpString(id, helpString);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, SetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, SetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString label = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->SetLabel(id, label);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, SetLabelTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, SetLabelTop)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pos = arg.GetInt(0);
	wxString label = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->SetLabelTop(pos, label);
	return Value::Nil;
#endif
	SetError_Obsolete(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, SetMenuLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, SetMenuLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pos = arg.GetInt(0);
	wxString label = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->SetMenuLabel(pos, label);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxMenuBar
//----------------------------------------------------------------------------
Object_wx_MenuBar::~Object_wx_MenuBar()
{
}

Object *Object_wx_MenuBar::Clone() const
{
	return nullptr;
}

String Object_wx_MenuBar::ToString(bool exprFlag)
{
	String rtn("<wx.MenuBar:");
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
// Class implementation for wxMenuBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MenuBar)
{
	Gura_AssignFunction(MenuBar);
	Gura_AssignFunction(MenuBar_1);
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
	return new Object_wx_MenuBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
