//----------------------------------------------------------------------------
// wxSearchCtrl
// extracted from srchctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(SetMenu);
Gura_DeclarePrivUserSymbol(GetMenu);
Gura_DeclarePrivUserSymbol(ShowSearchButton);
Gura_DeclarePrivUserSymbol(IsSearchButtonVisible);
Gura_DeclarePrivUserSymbol(ShowCancelButton);
Gura_DeclarePrivUserSymbol(IsCancelButtonVisible);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SearchCtrl: public wxSearchCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SearchCtrl *_pObj;
public:
	inline wx_SearchCtrl() : wxSearchCtrl(), _sig(nullptr), _pObj(nullptr) {}
	inline wx_SearchCtrl(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxSearchCtrl(parent, id, value, pos, size, style, validator, name), _sig(nullptr), _pObj(nullptr) {}
	//virtual void SetMenu(wxMenu* menu);
	//virtual wxMenu* GetMenu();
	//virtual void ShowSearchButton(bool show);
	//virtual bool IsSearchButtonVisible();
	//virtual void ShowCancelButton(bool show);
	//virtual bool IsCancelButtonVisible();
	~wx_SearchCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SearchCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SearchCtrl::~wx_SearchCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SearchCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSearchCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(SearchCtrlEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SearchCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SearchCtrlEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_SearchCtrl *pEntity = new wx_SearchCtrl();
	Object_wx_SearchCtrl *pObj = Object_wx_SearchCtrl::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SearchCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(SearchCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SearchCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SearchCtrl)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxT("");
	if (args.IsValid(2)) value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxSearchCtrlNameStr;
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_SearchCtrl *pEntity = new wx_SearchCtrl(parent, id, value, *pos, *size, style, *validator, name);
	Object_wx_SearchCtrl *pObj = Object_wx_SearchCtrl::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SearchCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_SearchCtrl, SetMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
}

Gura_ImplementMethod(wx_SearchCtrl, SetMenu)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetMenu(menu);
	return Value::Null;
}

Gura_DeclareMethod(wx_SearchCtrl, GetMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SearchCtrl, GetMenu)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMenu *rtn = (wxMenu *)pThis->GetEntity()->GetMenu();
	return ReturnValue(env, sig, args, Value(new Object_wx_Menu(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_SearchCtrl, ShowSearchButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_SearchCtrl, ShowSearchButton)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool show = args.GetBoolean(0);
	pThis->GetEntity()->ShowSearchButton(show);
	return Value::Null;
}

Gura_DeclareMethod(wx_SearchCtrl, IsSearchButtonVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SearchCtrl, IsSearchButtonVisible)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsSearchButtonVisible();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SearchCtrl, ShowCancelButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_SearchCtrl, ShowCancelButton)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool show = args.GetBoolean(0);
	pThis->GetEntity()->ShowCancelButton(show);
	return Value::Null;
}

Gura_DeclareMethod(wx_SearchCtrl, IsCancelButtonVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SearchCtrl, IsCancelButtonVisible)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsCancelButtonVisible();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSearchCtrl
//----------------------------------------------------------------------------
Object_wx_SearchCtrl::~Object_wx_SearchCtrl()
{
}

Object *Object_wx_SearchCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_SearchCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.SearchCtrl:");
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
// Class implementation for wxSearchCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SearchCtrl)
{
	Gura_RealizeUserSymbol(SetMenu);
	Gura_RealizeUserSymbol(GetMenu);
	Gura_RealizeUserSymbol(ShowSearchButton);
	Gura_RealizeUserSymbol(IsSearchButtonVisible);
	Gura_RealizeUserSymbol(ShowCancelButton);
	Gura_RealizeUserSymbol(IsCancelButtonVisible);
	Gura_AssignWxStringValue(SearchCtrlNameStr);
	Gura_AssignFunction(SearchCtrlEmpty);
	Gura_AssignFunction(SearchCtrl);
	Gura_AssignMethod(wx_SearchCtrl, SetMenu);
	Gura_AssignMethod(wx_SearchCtrl, GetMenu);
	Gura_AssignMethod(wx_SearchCtrl, ShowSearchButton);
	Gura_AssignMethod(wx_SearchCtrl, IsSearchButtonVisible);
	Gura_AssignMethod(wx_SearchCtrl, ShowCancelButton);
	Gura_AssignMethod(wx_SearchCtrl, IsCancelButtonVisible);
}

Gura_ImplementDescendantCreator(wx_SearchCtrl)
{
	return new Object_wx_SearchCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
