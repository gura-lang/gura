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
	Gura::Signal _sig;
	Object_wx_RichTextStyleListCtrl *_pObj;
public:
	inline wx_RichTextStyleListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) : wxRichTextStyleListCtrl(parent, id, pos, size, style), _sig(NULL), _pObj(NULL) {}
	inline wx_RichTextStyleListCtrl() : wxRichTextStyleListCtrl(), _sig(NULL), _pObj(NULL) {}
	~wx_RichTextStyleListCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextStyleListCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextStyleListCtrl::~wx_RichTextStyleListCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextStyleListCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleListCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextStyleListCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
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
	Object_wx_RichTextStyleListCtrl *pObj = Object_wx_RichTextStyleListCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextStyleListCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(RichTextStyleListCtrlEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleListCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextStyleListCtrlEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_RichTextStyleListCtrl *pEntity = new wx_RichTextStyleListCtrl();
	Object_wx_RichTextStyleListCtrl *pObj = Object_wx_RichTextStyleListCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextStyleListCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, Create)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
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
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetRichTextCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetRichTextCtrl)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextCtrl *rtn = (wxRichTextCtrl *)pThis->GetEntity()->GetRichTextCtrl();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextCtrl(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetStyleChoice)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetStyleChoice)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxChoice *rtn = (wxChoice *)pThis->GetEntity()->GetStyleChoice();
	return ReturnValue(env, sig, args, Value(new Object_wx_Choice(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetStyleListBox)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetStyleListBox)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleListBox *rtn = (wxRichTextStyleListBox *)pThis->GetEntity()->GetStyleListBox();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextStyleListBox(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetStyleSheet)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetStyleSheet)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *rtn = (wxRichTextStyleSheet *)pThis->GetEntity()->GetStyleSheet();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextStyleSheet(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, GetStyleType)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, GetStyleType)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, SetRichTextCtrl)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, SetRichTextCtrl)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetRichTextCtrl(ctrl);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, SetStyleSheet)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "styleSheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, SetStyleSheet)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *styleSheet = Object_wx_RichTextStyleSheet::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetStyleSheet(styleSheet);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, SetStyleType)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "styleType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, SetStyleType)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleListBox::wxRichTextStyleType styleType =
			static_cast<wxRichTextStyleListBox::wxRichTextStyleType>(args.GetInt(0));
	pThis->GetEntity()->SetStyleType(styleType);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextStyleListCtrl, UpdateStyles)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListCtrl, UpdateStyles)
{
	Object_wx_RichTextStyleListCtrl *pThis = Object_wx_RichTextStyleListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->UpdateStyles();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleListCtrl
//----------------------------------------------------------------------------
Object_wx_RichTextStyleListCtrl::~Object_wx_RichTextStyleListCtrl()
{
}

Object *Object_wx_RichTextStyleListCtrl::Clone() const
{
	return NULL;
}

String Object_wx_RichTextStyleListCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RichTextStyleListCtrl:");
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
	return new Object_wx_RichTextStyleListCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
