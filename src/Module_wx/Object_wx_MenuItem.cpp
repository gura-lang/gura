//----------------------------------------------------------------------------
// wxMenuItem
// extracted from menuitem.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MenuItem: public wxMenuItem, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MenuItem *_pObj;
public:
	inline wx_MenuItem(wxMenu* parentMenu, int id, const wxString& text, const wxString& helpString, wxItemKind kind, wxMenu* subMenu) : wxMenuItem(parentMenu, id, text, helpString, kind, subMenu), _sig(NULL), _pObj(NULL) {}
	~wx_MenuItem();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MenuItem *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MenuItem::~wx_MenuItem()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MenuItem::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMenuItem
//----------------------------------------------------------------------------
Gura_DeclareFunction(MenuItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MenuItem));
	DeclareArg(env, "parentMenu", VTYPE_wx_Menu, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "text", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "kind", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "subMenu", VTYPE_wx_Menu, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MenuItem)
{
	wxMenu *parentMenu = (wxMenu *)(NULL);
	if (args.IsValid(0)) parentMenu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	int id = wxID_SEPARATOR;
	if (args.IsValid(1)) id = args.GetInt(1);
	wxString text = wxT("");
	if (args.IsValid(2)) text = wxString::FromUTF8(args.GetString(2));
	wxString helpString = wxT("");
	if (args.IsValid(3)) helpString = wxString::FromUTF8(args.GetString(3));
	wxItemKind kind = wxITEM_NORMAL;
	if (args.IsValid(4)) kind = static_cast<wxItemKind>(args.GetInt(4));
	wxMenu *subMenu = (wxMenu *)(NULL);
	if (args.IsValid(5)) subMenu = Object_wx_Menu::GetObject(args, 5)->GetEntity();
	wx_MenuItem *pEntity = new wx_MenuItem(parentMenu, id, text, helpString, kind, subMenu);
	Object_wx_MenuItem *pObj = Object_wx_MenuItem::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MenuItem(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_MenuItem, Check)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "check", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, Check)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool check = true;
	if (args.IsValid(0)) check = args.GetBoolean(0);
	pSelf->GetEntity()->Check(check);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuItem, Enable)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, Enable)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	pSelf->GetEntity()->Enable(enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuItem, GetAccel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetAccel)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAcceleratorEntry *rtn = pSelf->GetEntity()->GetAccel();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_AcceleratorEntry(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_MenuItem, GetBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetBackgroundColour)
{
#if defined(__WXMSW__)
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour &rtn = pSelf->GetEntity()->GetBackgroundColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_MenuItem, GetBitmap)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "checked", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetBitmap)
{
#if defined(__WXMSW__)
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool checked = true;
	if (args.IsValid(0)) checked = args.GetBoolean(0);
	const wxBitmap &rtn = pSelf->GetEntity()->GetBitmap(checked);
	return ReturnValue(env, sig, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), NULL, OwnerTrue)));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_MenuItem, GetFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetFont)
{
#if defined(__WXMSW__)
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFont &rtn = pSelf->GetEntity()->GetFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_MenuItem, GetHelp)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetHelp)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetHelp();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MenuItem, GetId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetId)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuItem, GetItemLabel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetItemLabel)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetItemLabel();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MenuItem, GetItemLabelText)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetItemLabelText)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetItemLabelText();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MenuItem, GetKind)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetKind)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxItemKind rtn = pSelf->GetEntity()->GetKind();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuItem, GetLabel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetLabel)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetLabel();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_MenuItem, GetLabelText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_MenuItem, GetLabelText)
{
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxString rtn = wxMenuItem::GetLabelText(text);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_MenuItem, GetLabelFromText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_MenuItem, GetLabelFromText)
{
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxString rtn = wxMenuItem::GetLabelFromText(text);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MenuItem, GetMarginWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetMarginWidth)
{
#if defined(__WXMSW__)
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetMarginWidth();
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_MenuItem, GetMenu)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetMenu)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenu *rtn = (wxMenu *)pSelf->GetEntity()->GetMenu();
	return ReturnValue(env, sig, args, Value(new Object_wx_Menu(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_MenuItem, GetName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetName)
{
#if 0
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuItem, GetText)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetText)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetText();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MenuItem, GetSubMenu)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetSubMenu)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenu *rtn = (wxMenu *)pSelf->GetEntity()->GetSubMenu();
	return ReturnValue(env, sig, args, Value(new Object_wx_Menu(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_MenuItem, GetTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, GetTextColour)
{
#if defined(__WXMSW__)
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour &rtn = pSelf->GetEntity()->GetTextColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_MenuItem, IsCheckable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, IsCheckable)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsCheckable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuItem, IsChecked)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, IsChecked)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsChecked();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuItem, IsEnabled)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, IsEnabled)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsEnabled();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuItem, IsSeparator)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, IsSeparator)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsSeparator();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuItem, IsSubMenu)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, IsSubMenu)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsSubMenu();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuItem, SetBackgroundColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetBackgroundColour)
{
#if defined(__WXMSW__)
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetBackgroundColour(*colour);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_MenuItem, SetBitmap)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bmp", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetBitmap)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBitmap *bmp = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetBitmap(*bmp);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuItem, SetBitmaps)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "checked", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "unchecked", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuItem, SetBitmaps)
{
#if defined(__WXMSW__)
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBitmap *checked = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wxBitmap *unchecked = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(1)) unchecked = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	pSelf->GetEntity()->SetBitmaps(*checked, *unchecked);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_MenuItem, SetFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetFont)
{
#if defined(__WXMSW__)
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetFont(*font);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_MenuItem, SetHelp)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetHelp)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString helpString = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetHelp(helpString);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuItem, SetItemLabel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetItemLabel)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString label = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetItemLabel(label);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuItem, SetMarginWidth)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetMarginWidth)
{
#if defined(__WXMSW__)
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pSelf->GetEntity()->SetMarginWidth(width);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_MenuItem, SetMenu)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetMenu)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetMenu(menu);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuItem, SetSubMenu)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetSubMenu)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetSubMenu(menu);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuItem, SetText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetText)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetText(text);
	return Value::Null;
}

Gura_DeclareMethod(wx_MenuItem, SetTextColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetTextColour)
{
#if defined(__WXMSW__)
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetTextColour(*colour);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_MenuItem, Toggle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_MenuItem, Toggle)
{
	Object_wx_MenuItem *pSelf = Object_wx_MenuItem::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->Toggle();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxMenuItem
//----------------------------------------------------------------------------
Object_wx_MenuItem::~Object_wx_MenuItem()
{
}

Object *Object_wx_MenuItem::Clone() const
{
	return NULL;
}

String Object_wx_MenuItem::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MenuItem:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_MenuItem::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(MenuItem);
}

//----------------------------------------------------------------------------
// Class implementation for wxMenuItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MenuItem)
{
	Gura_AssignMethod(wx_MenuItem, Check);
	Gura_AssignMethod(wx_MenuItem, Enable);
	Gura_AssignMethod(wx_MenuItem, GetAccel);
	Gura_AssignMethod(wx_MenuItem, GetBackgroundColour);
	Gura_AssignMethod(wx_MenuItem, GetBitmap);
	Gura_AssignMethod(wx_MenuItem, GetFont);
	Gura_AssignMethod(wx_MenuItem, GetHelp);
	Gura_AssignMethod(wx_MenuItem, GetId);
	Gura_AssignMethod(wx_MenuItem, GetItemLabel);
	Gura_AssignMethod(wx_MenuItem, GetItemLabelText);
	Gura_AssignMethod(wx_MenuItem, GetKind);
	Gura_AssignMethod(wx_MenuItem, GetLabel);
	Gura_AssignMethod(wx_MenuItem, GetLabelText);
	Gura_AssignMethod(wx_MenuItem, GetLabelFromText);
	Gura_AssignMethod(wx_MenuItem, GetMarginWidth);
	Gura_AssignMethod(wx_MenuItem, GetMenu);
	Gura_AssignMethod(wx_MenuItem, GetName);
	Gura_AssignMethod(wx_MenuItem, GetText);
	Gura_AssignMethod(wx_MenuItem, GetSubMenu);
	Gura_AssignMethod(wx_MenuItem, GetTextColour);
	Gura_AssignMethod(wx_MenuItem, IsCheckable);
	Gura_AssignMethod(wx_MenuItem, IsChecked);
	Gura_AssignMethod(wx_MenuItem, IsEnabled);
	Gura_AssignMethod(wx_MenuItem, IsSeparator);
	Gura_AssignMethod(wx_MenuItem, IsSubMenu);
	Gura_AssignMethod(wx_MenuItem, SetBackgroundColour);
	Gura_AssignMethod(wx_MenuItem, SetBitmap);
	Gura_AssignMethod(wx_MenuItem, SetBitmaps);
	Gura_AssignMethod(wx_MenuItem, SetFont);
	Gura_AssignMethod(wx_MenuItem, SetHelp);
	Gura_AssignMethod(wx_MenuItem, SetItemLabel);
	Gura_AssignMethod(wx_MenuItem, SetMarginWidth);
	Gura_AssignMethod(wx_MenuItem, SetMenu);
	Gura_AssignMethod(wx_MenuItem, SetSubMenu);
	Gura_AssignMethod(wx_MenuItem, SetText);
	Gura_AssignMethod(wx_MenuItem, SetTextColour);
	Gura_AssignMethod(wx_MenuItem, Toggle);
}

Gura_ImplementDescendantCreator(wx_MenuItem)
{
	return new Object_wx_MenuItem((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
