//----------------------------------------------------------------------------
// wxRichTextStyleListCtrl
// extracted from richtextstylelistbox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextStyleListCtrl: public wxRichTextStyleListCtrl, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RichTextStyleListCtrl *_pObj;
public:
	inline wx_RichTextStyleListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) : wxRichTextStyleListCtrl(parent, id, pos, size, style), _pObj(nullptr) {}
	inline wx_RichTextStyleListCtrl() : wxRichTextStyleListCtrl(), _pObj(nullptr) {}
	~wx_RichTextStyleListCtrl();
	inline void AssocWithGura(Object_wx_RichTextStyleListCtrl *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextStyleListCtrl::~wx_RichTextStyleListCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextStyleListCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleListCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextStyleListCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleListCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextStyleListCtrl)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wx_RichTextStyleListCtrl *pEntity = new wx_RichTextStyleListCtrl(parent, id, *pos, *size, style);
	Object_wx_RichTextStyleListCtrl *pObj = Object_wx_RichTextStyleListCtrl::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextStyleListCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(RichTextStyleListCtrlEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleListCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextStyleListCtrlEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_RichTextStyleListCtrl *pEntity = new wx_RichTextStyleListCtrl();
	Object_wx_RichTextStyleListCtrl *pObj = Object_wx_RichTextStyleListCtrl::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextStyleListCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetRichTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextCtrl *rtn = (wxRichTextCtrl *)pThis->GetEntity()->GetRichTextCtrl();
	return ReturnValue(env, args, Value(new Object_wx_RichTextCtrl(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetStyleChoice)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetStyleChoice)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChoice *rtn = (wxChoice *)pThis->GetEntity()->GetStyleChoice();
	return ReturnValue(env, args, Value(new Object_wx_Choice(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetStyleListBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetStyleListBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleListBox *rtn = (wxRichTextStyleListBox *)pThis->GetEntity()->GetStyleListBox();
	return ReturnValue(env, args, Value(new Object_wx_RichTextStyleListBox(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleSheet *rtn = (wxRichTextStyleSheet *)pThis->GetEntity()->GetStyleSheet();
	return ReturnValue(env, args, Value(new Object_wx_RichTextStyleSheet(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetStyleType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetStyleType)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, SetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, SetRichTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetRichTextCtrl(ctrl);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, SetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "styleSheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, SetStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleSheet *styleSheet = Object_wx_RichTextStyleSheet::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetStyleSheet(styleSheet);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, SetStyleType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "styleType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, SetStyleType)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleListBox::wxRichTextStyleType styleType =
			static_cast<wxRichTextStyleListBox::wxRichTextStyleType>(args.GetInt(0));
	pThis->GetEntity()->SetStyleType(styleType);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, UpdateStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, UpdateStyles)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->UpdateStyles();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleListCtrl
//----------------------------------------------------------------------------
Object_wx_RichTextStyleListCtrl::~Object_wx_RichTextStyleListCtrl()
{
}

Object *Object_wx_RichTextStyleListCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStyleListCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleListCtrl:");
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
// Class implementation for wxRichTextStyleListCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleListCtrl)
{
	Gura_AssignFunction(RichTextStyleListCtrl);
	Gura_AssignFunction(RichTextStyleListCtrlEmpty);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, Create);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, GetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, GetStyleChoice);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, GetStyleListBox);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, GetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, GetStyleType);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, SetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, SetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, SetStyleType);
	Gura_AssignMethod(wx_RichTextStyleListCtrl, UpdateStyles);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleListCtrl)
{
	return new Object_wx_RichTextStyleListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
