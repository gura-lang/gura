//----------------------------------------------------------------------------
// wxBitmapButton
// extracted from bbutton.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BitmapButton: public wxBitmapButton, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_BitmapButton *_pObj;
public:
	inline wx_BitmapButton() : wxBitmapButton(), _pObj(nullptr) {}
	inline wx_BitmapButton(wxWindow* parent, wxWindowID id, const wxBitmap& bitmap, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxBitmapButton(parent, id, bitmap, pos, size, style, validator, name), _pObj(nullptr) {}
	~wx_BitmapButton();
	inline void AssocWithGura(Object_wx_BitmapButton *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BitmapButton::~wx_BitmapButton()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_BitmapButton::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmapButton
//----------------------------------------------------------------------------
Gura_DeclareFunction(BitmapButtonEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_BitmapButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BitmapButtonEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_BitmapButton *pEntity = new wx_BitmapButton();
	Object_wx_BitmapButton *pObj = Object_wx_BitmapButton::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_BitmapButton(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(BitmapButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BitmapButton));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BitmapButton)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxBU_AUTODRAW;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("button");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_BitmapButton *pEntity = new wx_BitmapButton(parent, id, *bitmap, *pos, *size, style, *validator, name);
	Object_wx_BitmapButton *pObj = Object_wx_BitmapButton::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_BitmapButton(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_BitmapButton, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapButton, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 2)->GetEntity();
	wxPoint *pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("button");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pThis->GetEntity()->Create(parent, id, *bitmap, *pos, *size, style, *validator, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_BitmapButton, GetBitmapDisabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapButton, GetBitmapDisabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmapDisabled();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_BitmapButton, GetBitmapDisabled_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapButton, GetBitmapDisabled_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmapDisabled();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_BitmapButton, GetBitmapFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapButton, GetBitmapFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmapFocus();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_BitmapButton, GetBitmapFocus_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapButton, GetBitmapFocus_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmapFocus();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_BitmapButton, GetBitmapHover)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapButton, GetBitmapHover)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmapHover();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_BitmapButton, GetBitmapHover_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapButton, GetBitmapHover_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmapHover();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_BitmapButton, GetBitmapLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapButton, GetBitmapLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmapLabel();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_BitmapButton, GetBitmapLabel_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapButton, GetBitmapLabel_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmapLabel();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_BitmapButton, GetBitmapSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapButton, GetBitmapSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmapSelected();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_BitmapButton, GetBitmapSelected_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapButton, GetBitmapSelected_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmapSelected();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_BitmapButton, SetBitmapDisabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapButton, SetBitmapDisabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBitmapDisabled(*bitmap);
	return Value::Null;
}

Gura_DeclareMethod(wx_BitmapButton, SetBitmapFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapButton, SetBitmapFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBitmapFocus(*bitmap);
	return Value::Null;
}

Gura_DeclareMethod(wx_BitmapButton, SetBitmapHover)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapButton, SetBitmapHover)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBitmapHover(*bitmap);
	return Value::Null;
}

Gura_DeclareMethod(wx_BitmapButton, SetBitmapLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapButton, SetBitmapLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBitmapLabel(*bitmap);
	return Value::Null;
}

Gura_DeclareMethod(wx_BitmapButton, SetBitmapSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapButton, SetBitmapSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBitmapSelected(*bitmap);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxBitmapButton
//----------------------------------------------------------------------------
Object_wx_BitmapButton::~Object_wx_BitmapButton()
{
}

Object *Object_wx_BitmapButton::Clone() const
{
	return nullptr;
}

String Object_wx_BitmapButton::ToString(bool exprFlag)
{
	String rtn("<wx.BitmapButton:");
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
// Class implementation for wxBitmapButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapButton)
{
	Gura_AssignFunction(BitmapButtonEmpty);
	Gura_AssignFunction(BitmapButton);
	Gura_AssignMethod(wx_BitmapButton, Create);
	Gura_AssignMethod(wx_BitmapButton, GetBitmapDisabled);
	Gura_AssignMethod(wx_BitmapButton, GetBitmapDisabled_1);
	Gura_AssignMethod(wx_BitmapButton, GetBitmapFocus);
	Gura_AssignMethod(wx_BitmapButton, GetBitmapFocus_1);
	Gura_AssignMethod(wx_BitmapButton, GetBitmapHover);
	Gura_AssignMethod(wx_BitmapButton, GetBitmapHover_1);
	Gura_AssignMethod(wx_BitmapButton, GetBitmapLabel);
	Gura_AssignMethod(wx_BitmapButton, GetBitmapLabel_1);
	Gura_AssignMethod(wx_BitmapButton, GetBitmapSelected);
	Gura_AssignMethod(wx_BitmapButton, GetBitmapSelected_1);
	Gura_AssignMethod(wx_BitmapButton, SetBitmapDisabled);
	Gura_AssignMethod(wx_BitmapButton, SetBitmapFocus);
	Gura_AssignMethod(wx_BitmapButton, SetBitmapHover);
	Gura_AssignMethod(wx_BitmapButton, SetBitmapLabel);
	Gura_AssignMethod(wx_BitmapButton, SetBitmapSelected);
}

Gura_ImplementDescendantCreator(wx_BitmapButton)
{
	return new Object_wx_BitmapButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
