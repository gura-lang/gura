//----------------------------------------------------------------------------
// wxComboPopup
// extracted from combopopup.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ComboPopup: public wxComboPopup, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ComboPopup *_pObj;
public:
	//inline wx_ComboPopup() : wxComboPopup(), _pObj(nullptr) {}
	~wx_ComboPopup();
	inline void AssocWithGura(Object_wx_ComboPopup *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ComboPopup::~wx_ComboPopup()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ComboPopup::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxComboPopup
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ComboPopup, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboPopup, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Create(parent);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboPopup, Dismiss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, Dismiss)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Dismiss();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, GetAdjustedSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "minWidth", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "prefHeight", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxHeight", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboPopup, GetAdjustedSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int minWidth = args.GetInt(0);
	int prefHeight = args.GetInt(1);
	int maxHeight = args.GetInt(2);
	wxSize rtn = pThis->GetEntity()->GetAdjustedSize(minWidth, prefHeight, maxHeight);
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ComboPopup, GetControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboPopup, GetControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetControl();
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ComboPopup, GetStringValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboPopup, GetStringValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetStringValue();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ComboPopup, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, Init)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, IsCreated)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboPopup, IsCreated)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsCreated();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboPopup, LazyCreate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboPopup, LazyCreate)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->LazyCreate();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboPopup, OnComboDoubleClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, OnComboDoubleClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->OnComboDoubleClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, OnComboKeyEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, OnComboKeyEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnComboKeyEvent(*event);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, OnDismiss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, OnDismiss)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->OnDismiss();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, OnPopup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, OnPopup)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->OnPopup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, PaintComboControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, PaintComboControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->PaintComboControl(*dc, *rect);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboPopup, SetStringValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, SetStringValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetStringValue(value);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxComboPopup
//----------------------------------------------------------------------------
Object_wx_ComboPopup::~Object_wx_ComboPopup()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ComboPopup::Clone() const
{
	return nullptr;
}

String Object_wx_ComboPopup::ToString(bool exprFlag)
{
	String rtn("<wx.ComboPopup:");
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
// Class implementation for wxComboPopup
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ComboPopup)
{
	Gura_AssignMethod(wx_ComboPopup, Create);
	Gura_AssignMethod(wx_ComboPopup, Dismiss);
	Gura_AssignMethod(wx_ComboPopup, GetAdjustedSize);
	Gura_AssignMethod(wx_ComboPopup, GetControl);
	Gura_AssignMethod(wx_ComboPopup, GetStringValue);
	Gura_AssignMethod(wx_ComboPopup, Init);
	Gura_AssignMethod(wx_ComboPopup, IsCreated);
	Gura_AssignMethod(wx_ComboPopup, LazyCreate);
	Gura_AssignMethod(wx_ComboPopup, OnComboDoubleClick);
	Gura_AssignMethod(wx_ComboPopup, OnComboKeyEvent);
	Gura_AssignMethod(wx_ComboPopup, OnDismiss);
	Gura_AssignMethod(wx_ComboPopup, OnPopup);
	Gura_AssignMethod(wx_ComboPopup, PaintComboControl);
	Gura_AssignMethod(wx_ComboPopup, SetStringValue);
}

Gura_ImplementDescendantCreator(wx_ComboPopup)
{
	return new Object_wx_ComboPopup((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
