//----------------------------------------------------------------------------
// wxRichTextStyleComboCtrl
// extracted from richtextstylelistbox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextStyleComboCtrl: public wxRichTextStyleComboCtrl, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RichTextStyleComboCtrl *_pObj;
public:
	inline wx_RichTextStyleComboCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) : wxRichTextStyleComboCtrl(parent, id, pos, size, style), _pObj(nullptr) {}
	~wx_RichTextStyleComboCtrl();
	inline void AssocWithGura(Object_wx_RichTextStyleComboCtrl *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextStyleComboCtrl::~wx_RichTextStyleComboCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextStyleComboCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleComboCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextStyleComboCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleComboCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextStyleComboCtrl)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (arg.IsValid(1)) id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = 0;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wx_RichTextStyleComboCtrl *pEntity = new wx_RichTextStyleComboCtrl(parent, id, *pos, *size, style);
	Object_wx_RichTextStyleComboCtrl *pObj = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextStyleComboCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, GetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, GetRichTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextCtrl *rtn = (wxRichTextCtrl *)pThis->GetEntity()->GetRichTextCtrl();
	return ReturnValue(env, arg, Value(new Object_wx_RichTextCtrl(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, GetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, GetStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleSheet *rtn = (wxRichTextStyleSheet *)pThis->GetEntity()->GetStyleSheet();
	return ReturnValue(env, arg, Value(new Object_wx_RichTextStyleSheet(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, SetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, SetRichTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetRichTextCtrl(ctrl);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, SetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "styleSheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, SetStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleSheet *styleSheet = Object_wx_RichTextStyleSheet::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetStyleSheet(styleSheet);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, UpdateStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, UpdateStyles)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleComboCtrl *pThis = Object_wx_RichTextStyleComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->UpdateStyles();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleComboCtrl
//----------------------------------------------------------------------------
Object_wx_RichTextStyleComboCtrl::~Object_wx_RichTextStyleComboCtrl()
{
}

Object *Object_wx_RichTextStyleComboCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStyleComboCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleComboCtrl:");
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
// Class implementation for wxRichTextStyleComboCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleComboCtrl)
{
	Gura_AssignFunction(RichTextStyleComboCtrl);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, GetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, GetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, SetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, SetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, UpdateStyles);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleComboCtrl)
{
	return new Object_wx_RichTextStyleComboCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
