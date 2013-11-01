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
	Gura::Signal _sig;
	Object_wx_ComboPopup *_pObj;
public:
	//inline wx_ComboPopup() : wxComboPopup(), _sig(NULL), _pObj(NULL) {}
	~wx_ComboPopup();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ComboPopup *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ComboPopup::~wx_ComboPopup()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ComboPopup::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxComboPopup
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ComboPopup, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboPopup, Create)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Create(parent);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboPopup, Dismiss)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, Dismiss)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Dismiss();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboPopup, GetAdjustedSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "minWidth", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "prefHeight", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxHeight", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboPopup, GetAdjustedSize)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int minWidth = args.GetInt(0);
	int prefHeight = args.GetInt(1);
	int maxHeight = args.GetInt(2);
	wxSize rtn = pThis->GetEntity()->GetAdjustedSize(minWidth, prefHeight, maxHeight);
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ComboPopup, GetControl)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboPopup, GetControl)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetControl();
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ComboPopup, GetStringValue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboPopup, GetStringValue)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetStringValue();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ComboPopup, Init)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, Init)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Init();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboPopup, IsCreated)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboPopup, IsCreated)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsCreated();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboPopup, LazyCreate)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ComboPopup, LazyCreate)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->LazyCreate();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ComboPopup, OnComboDoubleClick)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, OnComboDoubleClick)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->OnComboDoubleClick();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboPopup, OnComboKeyEvent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, OnComboKeyEvent)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnComboKeyEvent(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboPopup, OnDismiss)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, OnDismiss)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->OnDismiss();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboPopup, OnPopup)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboPopup, OnPopup)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->OnPopup();
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboPopup, PaintComboControl)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, PaintComboControl)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->PaintComboControl(*dc, *rect);
	return Value::Null;
}

Gura_DeclareMethod(wx_ComboPopup, SetStringValue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboPopup, SetStringValue)
{
	Object_wx_ComboPopup *pThis = Object_wx_ComboPopup::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetStringValue(value);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxComboPopup
//----------------------------------------------------------------------------
Object_wx_ComboPopup::~Object_wx_ComboPopup()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ComboPopup::Clone() const
{
	return NULL;
}

String Object_wx_ComboPopup::ToString(bool exprFlag)
{
	String rtn("<wx.ComboPopup:");
	if (GetEntity() == NULL) {
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
	return new Object_wx_ComboPopup((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
