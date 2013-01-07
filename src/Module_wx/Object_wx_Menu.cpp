//----------------------------------------------------------------------------
// wxMenu
// extracted from menu.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Value MenuItemListToValue(Environment &env, const wxMenuItemList &list);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Menu: public wxMenu, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Menu *_pObj;
public:
	inline wx_Menu(const wxString& title, long style) : wxMenu(title, style), _sig(NULL), _pObj(NULL) {}
	inline wx_Menu(long style) : wxMenu(style), _sig(NULL), _pObj(NULL) {}
	~wx_Menu();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Menu *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Menu::~wx_Menu()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Menu::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMenu
//----------------------------------------------------------------------------
Gura_DeclareFunction(Menu)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Menu));
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Menu)
{
	wxString title = wxT("");
	if (args.IsValid(0)) title = wxString::FromUTF8(args.GetString(0));
	long style = 0;
	if (args.IsValid(1)) style = args.GetLong(1);
	wx_Menu *pEntity = new wx_Menu(title, style);
	Object_wx_Menu *pObj = Object_wx_Menu::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Menu(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Menu_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Menu));
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Menu_1)
{
	long style = args.GetLong(0);
	wx_Menu *pEntity = new wx_Menu(style);
	Object_wx_Menu *pObj = Object_wx_Menu::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Menu(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Menu, Append)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce, FLAG_NoCast);
	DeclareArg(env, "kind", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, Append)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString item = wxT("");
	if (args.IsValid(1)) item = wxString::FromUTF8(args.GetString(1));
	wxString helpString = wxT("");
	if (args.IsValid(2)) helpString = wxString::FromUTF8(args.GetString(2));
	wxItemKind kind = wxITEM_NORMAL;
	if (args.IsValid(3)) kind = static_cast<wxItemKind>(args.GetInt(3));
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->Append(id, item, helpString, kind);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, AppendMenu_)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "subMenu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, AppendMenu_)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString item = wxString::FromUTF8(args.GetString(1));
	wxMenu *subMenu = Object_wx_Menu::GetObject(args, 2)->GetEntity();
	wxString helpString = wxT("");
	if (args.IsValid(3)) helpString = wxString::FromUTF8(args.GetString(3));
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->Append(id, item, subMenu, helpString);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, AppendItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "menuItem", VTYPE_wx_MenuItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, AppendItem)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenuItem *menuItem = Object_wx_MenuItem::GetObject(args, 0)->GetEntity();
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->Append(menuItem);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, AppendCheckItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, AppendCheckItem)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString item = wxString::FromUTF8(args.GetString(1));
	wxString helpString = wxT("");
	if (args.IsValid(2)) helpString = wxString::FromUTF8(args.GetString(2));
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->AppendCheckItem(id, item, helpString);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, AppendRadioItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, AppendRadioItem)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString item = wxString::FromUTF8(args.GetString(1));
	wxString helpString = wxT("");
	if (args.IsValid(2)) helpString = wxString::FromUTF8(args.GetString(2));
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->AppendRadioItem(id, item, helpString);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, AppendSeparator)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, AppendSeparator)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->AppendSeparator();
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, AppendSubMenu)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "submenu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "help", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, AppendSubMenu)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenu *submenu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(1));
	wxString help = wxEmptyString;
	if (args.IsValid(2)) help = wxString::FromUTF8(args.GetString(2));
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->AppendSubMenu(submenu, text, help);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, Break)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, Break)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Break();
	return Value::Null;
}

Gura_DeclareMethod(wx_Menu, Check)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "check", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Check)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	bool check = args.GetBoolean(1);
	pSelf->GetEntity()->Check(id, check);
	return Value::Null;
}

Gura_DeclareMethod(wx_Menu, Delete)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Delete)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	pSelf->GetEntity()->Delete(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_Menu, DeleteItem)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_MenuItem, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, DeleteItem)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenuItem *item = Object_wx_MenuItem::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->Delete(item);
	return Value::Null;
}

Gura_DeclareMethod(wx_Menu, Destroy)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Destroy)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	pSelf->GetEntity()->Destroy(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_Menu, DestroyItem)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_MenuItem, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, DestroyItem)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenuItem *item = Object_wx_MenuItem::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->Destroy(item);
	return Value::Null;
}

Gura_DeclareMethod(wx_Menu, Enable)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Enable)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	bool enable = args.GetBoolean(1);
	pSelf->GetEntity()->Enable(id, enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_Menu, FindItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "itemString", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, FindItem)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString itemString = wxString::FromUTF8(args.GetString(0));
	int rtn = pSelf->GetEntity()->FindItem(itemString);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Menu, FindItemById)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, FindItemById)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxMenu **menu = NULL;
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->FindItem(id, menu);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Menu, FindItemByPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, FindItemByPosition)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t position = args.GetSizeT(0);
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->FindItemByPosition(position);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Menu, GetHelpString)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, GetHelpString)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString rtn = pSelf->GetEntity()->GetHelpString(id);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Menu, GetLabel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, GetLabel)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString rtn = pSelf->GetEntity()->GetLabel(id);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Menu, GetLabelText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, GetLabelText)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString rtn = pSelf->GetEntity()->GetLabelText(id);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Menu, GetMenuItemCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, GetMenuItemCount)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t rtn = pSelf->GetEntity()->GetMenuItemCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Menu, GetMenuItems)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, GetMenuItems)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenuItemList &rtn = pSelf->GetEntity()->GetMenuItems();
	return ReturnValue(env, sig, args, MenuItemListToValue(env, rtn));
}

Gura_DeclareMethod(wx_Menu, GetTitle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, GetTitle)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetTitle();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Menu, InsertItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_wx_MenuItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, InsertItem)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	wxMenuItem *item = Object_wx_MenuItem::GetObject(args, 1)->GetEntity();
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->Insert(pos, item);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, Insert)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "kind", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, Insert)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	int id = args.GetInt(1);
	wxString item = wxT("");
	if (args.IsValid(2)) item = wxString::FromUTF8(args.GetString(2));
	wxString helpString = wxT("");
	if (args.IsValid(3)) helpString = wxString::FromUTF8(args.GetString(3));
	wxItemKind kind = wxITEM_NORMAL;
	if (args.IsValid(4)) kind = static_cast<wxItemKind>(args.GetInt(4));
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->Insert(pos, id, item, helpString, kind);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, InsertCheckItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, InsertCheckItem)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	int id = args.GetInt(1);
	wxString item = wxString::FromUTF8(args.GetString(2));
	wxString helpString = wxT("");
	if (args.IsValid(3)) helpString = wxString::FromUTF8(args.GetString(3));
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->InsertCheckItem(pos, id, item, helpString);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, InsertRadioItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, InsertRadioItem)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	int id = args.GetInt(1);
	wxString item = wxString::FromUTF8(args.GetString(2));
	wxString helpString = wxT("");
	if (args.IsValid(3)) helpString = wxString::FromUTF8(args.GetString(3));
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->InsertRadioItem(pos, id, item, helpString);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, InsertSeparator)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, InsertSeparator)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->InsertSeparator(pos);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, IsChecked)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, IsChecked)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->IsChecked(id);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Menu, IsEnabled)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, IsEnabled)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->IsEnabled(id);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Menu, PrependItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_MenuItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, PrependItem)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenuItem *item = Object_wx_MenuItem::GetObject(args, 0)->GetEntity();
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->Prepend(item);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, Prepend)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "kind", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, Prepend)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString item = wxT("");
	if (args.IsValid(1)) item = wxString::FromUTF8(args.GetString(1));
	wxString helpString = wxT("");
	if (args.IsValid(2)) helpString = wxString::FromUTF8(args.GetString(2));
	wxItemKind kind = wxITEM_NORMAL;
	if (args.IsValid(3)) kind = static_cast<wxItemKind>(args.GetInt(3));
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->Prepend(id, item, helpString, kind);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, PrependCheckItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, PrependCheckItem)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString item = wxString::FromUTF8(args.GetString(1));
	wxString helpString = wxT("");
	if (args.IsValid(2)) helpString = wxString::FromUTF8(args.GetString(2));
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->PrependCheckItem(id, item, helpString);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, PrependRadioItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, PrependRadioItem)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString item = wxString::FromUTF8(args.GetString(1));
	wxString helpString = wxT("");
	if (args.IsValid(2)) helpString = wxString::FromUTF8(args.GetString(2));
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->PrependRadioItem(id, item, helpString);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, PrependSeparator)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, PrependSeparator)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->PrependSeparator();
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, Remove)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, Remove)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->Remove(id);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, RemoveItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_MenuItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, RemoveItem)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenuItem *item = Object_wx_MenuItem::GetObject(args, 0)->GetEntity();
	wxMenuItem *rtn = (wxMenuItem *)pSelf->GetEntity()->Remove(item);
	return ReturnValue(env, sig, args, Value(new Object_wx_MenuItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Menu, SetHelpString)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, SetHelpString)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString helpString = wxString::FromUTF8(args.GetString(1));
	pSelf->GetEntity()->SetHelpString(id, helpString);
	return Value::Null;
}

Gura_DeclareMethod(wx_Menu, SetLabel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, SetLabel)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxString label = wxString::FromUTF8(args.GetString(1));
	pSelf->GetEntity()->SetLabel(id, label);
	return Value::Null;
}

Gura_DeclareMethod(wx_Menu, SetTitle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, SetTitle)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString title = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetTitle(title);
	return Value::Null;
}

Gura_DeclareMethod(wx_Menu, UpdateUI)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "source", VTYPE_wx_EvtHandler, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Menu, UpdateUI)
{
	Object_wx_Menu *pSelf = Object_wx_Menu::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxEvtHandler *source = (wxEvtHandler *)(NULL);
	if (args.IsValid(0)) source = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->UpdateUI(source);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxMenu
//----------------------------------------------------------------------------
Object_wx_Menu::~Object_wx_Menu()
{
}

Object *Object_wx_Menu::Clone() const
{
	return NULL;
}

String Object_wx_Menu::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Menu:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Menu::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(Menu);
	Gura_AssignFunction(Menu_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxMenu
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Menu)
{
	Gura_AssignMethod(wx_Menu, Append);
	Gura_AssignMethodEx(wx_Menu, AppendMenu_, "AppendMenu");
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
	return new Object_wx_Menu((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Value MenuItemListToValue(Environment &env, const wxMenuItemList &list)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(list.GetCount());
	foreach_const (wxMenuItemList, pItem, list) {
		valList.push_back(Value(new Object_wx_MenuItem(*pItem, NULL, OwnerFalse)));
	}
	return rtn;
}

}}
