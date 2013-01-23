//----------------------------------------------------------------------------
// wxRichTextStyleComboCtrl
// extracted from richtextstylelistbox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextStyleComboCtrl: public wxRichTextStyleComboCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextStyleComboCtrl *_pObj;
public:
	inline wx_RichTextStyleComboCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) : wxRichTextStyleComboCtrl(parent, id, pos, size, style), _sig(NULL), _pObj(NULL) {}
	~wx_RichTextStyleComboCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextStyleComboCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextStyleComboCtrl::~wx_RichTextStyleComboCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextStyleComboCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleComboCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextStyleComboCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	wx_RichTextStyleComboCtrl *pEntity = new wx_RichTextStyleComboCtrl(parent, id, *pos, *size, style);
	Object_wx_RichTextStyleComboCtrl *pObj = Object_wx_RichTextStyleComboCtrl::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextStyleComboCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, GetRichTextCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, GetRichTextCtrl)
{
	Object_wx_RichTextStyleComboCtrl *pSelf = Object_wx_RichTextStyleComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextCtrl *rtn = (wxRichTextCtrl *)pSelf->GetEntity()->GetRichTextCtrl();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextCtrl(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, GetStyleSheet)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, GetStyleSheet)
{
	Object_wx_RichTextStyleComboCtrl *pSelf = Object_wx_RichTextStyleComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *rtn = (wxRichTextStyleSheet *)pSelf->GetEntity()->GetStyleSheet();
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextStyleSheet(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, SetRichTextCtrl)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, SetRichTextCtrl)
{
	Object_wx_RichTextStyleComboCtrl *pSelf = Object_wx_RichTextStyleComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetRichTextCtrl(ctrl);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, SetStyleSheet)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "styleSheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, SetStyleSheet)
{
	Object_wx_RichTextStyleComboCtrl *pSelf = Object_wx_RichTextStyleComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextStyleSheet *styleSheet = Object_wx_RichTextStyleSheet::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetStyleSheet(styleSheet);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextStyleComboCtrl, UpdateStyles)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleComboCtrl, UpdateStyles)
{
	Object_wx_RichTextStyleComboCtrl *pSelf = Object_wx_RichTextStyleComboCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->UpdateStyles();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleComboCtrl
//----------------------------------------------------------------------------
Object_wx_RichTextStyleComboCtrl::~Object_wx_RichTextStyleComboCtrl()
{
}

Object *Object_wx_RichTextStyleComboCtrl::Clone() const
{
	return NULL;
}

String Object_wx_RichTextStyleComboCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RichTextStyleComboCtrl:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_RichTextStyleComboCtrl::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(RichTextStyleComboCtrl);
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextStyleComboCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleComboCtrl)
{
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, GetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, GetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, SetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, SetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleComboCtrl, UpdateStyles);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleComboCtrl)
{
	return new Object_wx_RichTextStyleComboCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
