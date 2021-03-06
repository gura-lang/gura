//----------------------------------------------------------------------------
// wxMenu
// extracted from menu.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Value MenuItemListToValue(Environment &env, const wxMenuItemList &list);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Menu: public wxMenu, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Menu *_pObj;
public:
	inline wx_Menu(const wxString& title, long style) : wxMenu(title, style), _pObj(nullptr) {}
	inline wx_Menu(long style) : wxMenu(style), _pObj(nullptr) {}
	~wx_Menu();
	inline void AssocWithGura(Object_wx_Menu *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Menu::~wx_Menu()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Menu::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMenu
//----------------------------------------------------------------------------
Gura_DeclareFunction(Menu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Menu));
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Menu)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString title = wxT("");
	if (arg.IsValid(0)) title = wxString::FromUTF8(arg.GetString(0));
	long style = 0;
	if (arg.IsValid(1)) style = arg.GetLong(1);
	wx_Menu *pEntity = new wx_Menu(title, style);
	Object_wx_Menu *pObj = Object_wx_Menu::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Menu(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Menu_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Menu));
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Menu_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	long style = arg.GetLong(0);
	wx_Menu *pEntity = new wx_Menu(style);
	Object_wx_Menu *pObj = Object_wx_Menu::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Menu(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_Menu, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce, FLAG_NoCast);
	DeclareArg(env, "kind", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, Append)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString item = wxT("");
	if (arg.IsValid(1)) item = wxString::FromUTF8(arg.GetString(1));
	wxString helpString = wxT("");
	if (arg.IsValid(2)) helpString = wxString::FromUTF8(arg.GetString(2));
	wxItemKind kind = wxITEM_NORMAL;
	if (arg.IsValid(3)) kind = static_cast<wxItemKind>(arg.GetInt(3));
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->Append(id, item, helpString, kind);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethodAlias(wx_Menu, AppendMenu_, "AppendMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "subMenu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, AppendMenu_)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString item = wxString::FromUTF8(arg.GetString(1));
	wxMenu *subMenu = Object_wx_Menu::GetObject(arg, 2)->GetEntity();
	wxString helpString = wxT("");
	if (arg.IsValid(3)) helpString = wxString::FromUTF8(arg.GetString(3));
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->Append(id, item, subMenu, helpString);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, AppendItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "menuItem", VTYPE_wx_MenuItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, AppendItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenuItem *menuItem = Object_wx_MenuItem::GetObject(arg, 0)->GetEntity();
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->Append(menuItem);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, AppendCheckItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, AppendCheckItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString item = wxString::FromUTF8(arg.GetString(1));
	wxString helpString = wxT("");
	if (arg.IsValid(2)) helpString = wxString::FromUTF8(arg.GetString(2));
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->AppendCheckItem(id, item, helpString);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, AppendRadioItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, AppendRadioItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString item = wxString::FromUTF8(arg.GetString(1));
	wxString helpString = wxT("");
	if (arg.IsValid(2)) helpString = wxString::FromUTF8(arg.GetString(2));
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->AppendRadioItem(id, item, helpString);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, AppendSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, AppendSeparator)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->AppendSeparator();
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, AppendSubMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "submenu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "help", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, AppendSubMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenu *submenu = Object_wx_Menu::GetObject(arg, 0)->GetEntity();
	wxString text = wxString::FromUTF8(arg.GetString(1));
	wxString help = wxEmptyString;
	if (arg.IsValid(2)) help = wxString::FromUTF8(arg.GetString(2));
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->AppendSubMenu(submenu, text, help);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, Break)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, Break)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Break();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Check)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "check", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Check)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	bool check = arg.GetBoolean(1);
	pThis->GetEntity()->Check(id, check);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Delete)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	pThis->GetEntity()->Delete(id);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, DeleteItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_MenuItem, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, DeleteItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenuItem *item = Object_wx_MenuItem::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->Delete(item);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Destroy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Destroy)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	pThis->GetEntity()->Destroy(id);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, DestroyItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_MenuItem, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, DestroyItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenuItem *item = Object_wx_MenuItem::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->Destroy(item);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Enable)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	bool enable = arg.GetBoolean(1);
	pThis->GetEntity()->Enable(id, enable);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, FindItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "itemString", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, FindItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString itemString = wxString::FromUTF8(arg.GetString(0));
	int rtn = pThis->GetEntity()->FindItem(itemString);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Menu, FindItemById)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, FindItemById)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxMenu **menu = nullptr;
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->FindItem(id, menu);
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Menu, FindItemByPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, FindItemByPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t position = arg.GetSizeT(0);
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->FindItemByPosition(position);
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Menu, GetHelpString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, GetHelpString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetHelpString(id);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Menu, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, GetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetLabel(id);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Menu, GetLabelText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, GetLabelText)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetLabelText(id);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Menu, GetMenuItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, GetMenuItemCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetMenuItemCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Menu, GetMenuItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, GetMenuItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenuItemList &rtn = pThis->GetEntity()->GetMenuItems();
	return ReturnValue(env, arg, MenuItemListToValue(env, rtn));
}

Gura_DeclareMethod(wx_Menu, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, GetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetTitle();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Menu, InsertItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_wx_MenuItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, InsertItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = arg.GetSizeT(0);
	wxMenuItem *item = Object_wx_MenuItem::GetObject(arg, 1)->GetEntity();
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->Insert(pos, item);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "kind", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, Insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = arg.GetSizeT(0);
	int id = arg.GetInt(1);
	wxString item = wxT("");
	if (arg.IsValid(2)) item = wxString::FromUTF8(arg.GetString(2));
	wxString helpString = wxT("");
	if (arg.IsValid(3)) helpString = wxString::FromUTF8(arg.GetString(3));
	wxItemKind kind = wxITEM_NORMAL;
	if (arg.IsValid(4)) kind = static_cast<wxItemKind>(arg.GetInt(4));
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->Insert(pos, id, item, helpString, kind);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, InsertCheckItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, InsertCheckItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = arg.GetSizeT(0);
	int id = arg.GetInt(1);
	wxString item = wxString::FromUTF8(arg.GetString(2));
	wxString helpString = wxT("");
	if (arg.IsValid(3)) helpString = wxString::FromUTF8(arg.GetString(3));
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->InsertCheckItem(pos, id, item, helpString);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, InsertRadioItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, InsertRadioItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = arg.GetSizeT(0);
	int id = arg.GetInt(1);
	wxString item = wxString::FromUTF8(arg.GetString(2));
	wxString helpString = wxT("");
	if (arg.IsValid(3)) helpString = wxString::FromUTF8(arg.GetString(3));
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->InsertRadioItem(pos, id, item, helpString);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, InsertSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, InsertSeparator)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = arg.GetSizeT(0);
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->InsertSeparator(pos);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, IsChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, IsChecked)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->IsChecked(id);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Menu, IsEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, IsEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->IsEnabled(id);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Menu, PrependItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_MenuItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, PrependItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenuItem *item = Object_wx_MenuItem::GetObject(arg, 0)->GetEntity();
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->Prepend(item);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, Prepend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "kind", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, Prepend)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString item = wxT("");
	if (arg.IsValid(1)) item = wxString::FromUTF8(arg.GetString(1));
	wxString helpString = wxT("");
	if (arg.IsValid(2)) helpString = wxString::FromUTF8(arg.GetString(2));
	wxItemKind kind = wxITEM_NORMAL;
	if (arg.IsValid(3)) kind = static_cast<wxItemKind>(arg.GetInt(3));
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->Prepend(id, item, helpString, kind);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, PrependCheckItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, PrependCheckItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString item = wxString::FromUTF8(arg.GetString(1));
	wxString helpString = wxT("");
	if (arg.IsValid(2)) helpString = wxString::FromUTF8(arg.GetString(2));
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->PrependCheckItem(id, item, helpString);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, PrependRadioItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, PrependRadioItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString item = wxString::FromUTF8(arg.GetString(1));
	wxString helpString = wxT("");
	if (arg.IsValid(2)) helpString = wxString::FromUTF8(arg.GetString(2));
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->PrependRadioItem(id, item, helpString);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, PrependSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, PrependSeparator)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->PrependSeparator();
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->Remove(id);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, RemoveItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_MenuItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, RemoveItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenuItem *item = Object_wx_MenuItem::GetObject(arg, 0)->GetEntity();
	wxMenuItem *rtn = (wxMenuItem *)pThis->GetEntity()->Remove(item);
	return ReturnValue(env, arg, Value(new Object_wx_MenuItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, SetHelpString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, SetHelpString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString helpString = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->SetHelpString(id, helpString);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, SetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, SetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxString label = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->SetLabel(id, label);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, SetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString title = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetTitle(title);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, UpdateUI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "source", VTYPE_wx_EvtHandler, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, UpdateUI)
{
	Signal &sig = env.GetSignal();
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxEvtHandler *source = (wxEvtHandler *)(nullptr);
	if (arg.IsValid(0)) source = Object_wx_EvtHandler::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->UpdateUI(source);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxMenu
//----------------------------------------------------------------------------
Object_wx_Menu::~Object_wx_Menu()
{
}

Object *Object_wx_Menu::Clone() const
{
	return nullptr;
}

String Object_wx_Menu::ToString(bool exprFlag)
{
	String rtn("<wx.Menu:");
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
// Class implementation for wxMenu
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Menu)
{
	Gura_AssignFunction(Menu);
	Gura_AssignFunction(Menu_1);
	Gura_AssignMethod(wx_Menu, Append);
	Gura_AssignMethod(wx_Menu, AppendMenu_);
	Gura_AssignMethod(wx_Menu, AppendItem);
	Gura_AssignMethod(wx_Menu, AppendCheckItem);
	Gura_AssignMethod(wx_Menu, AppendRadioItem);
	Gura_AssignMethod(wx_Menu, AppendSeparator);
	Gura_AssignMethod(wx_Menu, AppendSubMenu);
	Gura_AssignMethod(wx_Menu, Break);
	Gura_AssignMethod(wx_Menu, Check);
	Gura_AssignMethod(wx_Menu, Delete);
	Gura_AssignMethod(wx_Menu, DeleteItem);
	Gura_AssignMethod(wx_Menu, Destroy);
	Gura_AssignMethod(wx_Menu, DestroyItem);
	Gura_AssignMethod(wx_Menu, Enable);
	Gura_AssignMethod(wx_Menu, FindItem);
	Gura_AssignMethod(wx_Menu, FindItemById);
	Gura_AssignMethod(wx_Menu, FindItemByPosition);
	Gura_AssignMethod(wx_Menu, GetHelpString);
	Gura_AssignMethod(wx_Menu, GetLabel);
	Gura_AssignMethod(wx_Menu, GetLabelText);
	Gura_AssignMethod(wx_Menu, GetMenuItemCount);
	Gura_AssignMethod(wx_Menu, GetMenuItems);
	Gura_AssignMethod(wx_Menu, GetTitle);
	Gura_AssignMethod(wx_Menu, InsertItem);
	Gura_AssignMethod(wx_Menu, Insert);
	Gura_AssignMethod(wx_Menu, InsertCheckItem);
	Gura_AssignMethod(wx_Menu, InsertRadioItem);
	Gura_AssignMethod(wx_Menu, InsertSeparator);
	Gura_AssignMethod(wx_Menu, IsChecked);
	Gura_AssignMethod(wx_Menu, IsEnabled);
	Gura_AssignMethod(wx_Menu, PrependItem);
	Gura_AssignMethod(wx_Menu, Prepend);
	Gura_AssignMethod(wx_Menu, PrependCheckItem);
	Gura_AssignMethod(wx_Menu, PrependRadioItem);
	Gura_AssignMethod(wx_Menu, PrependSeparator);
	Gura_AssignMethod(wx_Menu, Remove);
	Gura_AssignMethod(wx_Menu, RemoveItem);
	Gura_AssignMethod(wx_Menu, SetHelpString);
	Gura_AssignMethod(wx_Menu, SetLabel);
	Gura_AssignMethod(wx_Menu, SetTitle);
	Gura_AssignMethod(wx_Menu, UpdateUI);
}

Gura_ImplementDescendantCreator(wx_Menu)
{
	return new Object_wx_Menu((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Value MenuItemListToValue(Environment &env, const wxMenuItemList &list)
{
	Value rtn;
	Object_list *pObjList = rtn.InitAsList(env);
	pObjList->Reserve(list.GetCount());
	foreach_const (wxMenuItemList, pItem, list) {
		pObjList->Add(Value(new Object_wx_MenuItem(*pItem, nullptr, OwnerFalse)));
	}
	return rtn;
}

Gura_EndModuleScope(wx)
