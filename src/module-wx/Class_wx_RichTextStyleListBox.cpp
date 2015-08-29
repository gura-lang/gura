//----------------------------------------------------------------------------
// wxRichTextStyleListBox
// extracted from richtextstylelistbox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextStyleListBox: public wxRichTextStyleListBox, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RichTextStyleListBox *_pObj;
public:
	inline wx_RichTextStyleListBox(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) : wxRichTextStyleListBox(parent, id, pos, size, style), _pObj(nullptr) {}
	~wx_RichTextStyleListBox();
	inline void AssocWithGura(Object_wx_RichTextStyleListBox *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextStyleListBox::~wx_RichTextStyleListBox()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextStyleListBox::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleListBox
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextStyleListBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleListBox));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextStyleListBox)
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
	wx_RichTextStyleListBox *pEntity = new wx_RichTextStyleListBox(parent, id, *pos, *size, style);
	Object_wx_RichTextStyleListBox *pObj = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextStyleListBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_RichTextStyleListBox, ApplyStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListBox, ApplyStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int i = arg.GetInt(0);
	pThis->GetEntity()->ApplyStyle(i);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListBox, ConvertTenthsMMToPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListBox, ConvertTenthsMMToPixels)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(arg, 0)->GetEntity();
	int units = arg.GetInt(1);
	int rtn = pThis->GetEntity()->ConvertTenthsMMToPixels(*dc, units);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleListBox, CreateHTML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "def", VTYPE_wx_RichTextStyleDefinition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListBox, CreateHTML)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleDefinition *def = Object_wx_RichTextStyleDefinition::GetObject(arg, 0)->GetEntity();
	wxString rtn = pThis->GetEntity()->CreateHTML(def);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextStyleListBox, GetApplyOnSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListBox, GetApplyOnSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetApplyOnSelection();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextStyleListBox, GetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListBox, GetRichTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextCtrl *rtn = (wxRichTextCtrl *)pThis->GetEntity()->GetRichTextCtrl();
	return ReturnValue(env, arg, Value(new Object_wx_RichTextCtrl(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleListBox, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListBox, GetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t i = arg.GetSizeT(0);
	wxRichTextStyleDefinition *rtn = (wxRichTextStyleDefinition *)pThis->GetEntity()->GetStyle(i);
	return ReturnValue(env, arg, Value(new Object_wx_RichTextStyleDefinition(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleListBox, GetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListBox, GetStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleSheet *rtn = (wxRichTextStyleSheet *)pThis->GetEntity()->GetStyleSheet();
	return ReturnValue(env, arg, Value(new Object_wx_RichTextStyleSheet(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_RichTextStyleListBox, GetStyleType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListBox, GetStyleType)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListBox, OnGetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextStyleListBox, OnGetItem)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = arg.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->OnGetItem(n);
	return ReturnValue(env, arg, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListBox, OnLeftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_MouseEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListBox, OnLeftDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMouseEvent *event = Object_wx_MouseEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnLeftDown(*event);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListBox, OnSelect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_RichTextStyleListBox, OnSelect)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnSelect(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListBox, SetApplyOnSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "applyOnSelection", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListBox, SetApplyOnSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool applyOnSelection = arg.GetBoolean(0);
	pThis->GetEntity()->SetApplyOnSelection(applyOnSelection);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListBox, SetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "ctrl", VTYPE_wx_RichTextCtrl, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListBox, SetRichTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextCtrl *ctrl = Object_wx_RichTextCtrl::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetRichTextCtrl(ctrl);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListBox, SetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "styleSheet", VTYPE_wx_RichTextStyleSheet, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleListBox, SetStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleSheet *styleSheet = Object_wx_RichTextStyleSheet::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetStyleSheet(styleSheet);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListBox, SetStyleType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "styleType", VTYPE_wx_RichTextStyleListBox, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_RichTextStyleListBox, SetStyleType)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextStyleListBox *styleType = Object_wx_RichTextStyleListBox::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetStyleType(*styleType);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleListBox, UpdateStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleListBox, UpdateStyles)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleListBox *pThis = Object_wx_RichTextStyleListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->UpdateStyles();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleListBox
//----------------------------------------------------------------------------
Object_wx_RichTextStyleListBox::~Object_wx_RichTextStyleListBox()
{
}

Object *Object_wx_RichTextStyleListBox::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStyleListBox::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleListBox:");
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
// Class implementation for wxRichTextStyleListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleListBox)
{
	Gura_AssignFunction(RichTextStyleListBox);
	Gura_AssignMethod(wx_RichTextStyleListBox, ApplyStyle);
	Gura_AssignMethod(wx_RichTextStyleListBox, ConvertTenthsMMToPixels);
	Gura_AssignMethod(wx_RichTextStyleListBox, CreateHTML);
	Gura_AssignMethod(wx_RichTextStyleListBox, GetApplyOnSelection);
	Gura_AssignMethod(wx_RichTextStyleListBox, GetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleListBox, GetStyle);
	Gura_AssignMethod(wx_RichTextStyleListBox, GetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleListBox, GetStyleType);
	Gura_AssignMethod(wx_RichTextStyleListBox, OnGetItem);
	Gura_AssignMethod(wx_RichTextStyleListBox, OnLeftDown);
	Gura_AssignMethod(wx_RichTextStyleListBox, OnSelect);
	Gura_AssignMethod(wx_RichTextStyleListBox, SetApplyOnSelection);
	Gura_AssignMethod(wx_RichTextStyleListBox, SetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleListBox, SetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleListBox, SetStyleType);
	Gura_AssignMethod(wx_RichTextStyleListBox, UpdateStyles);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleListBox)
{
	return new Object_wx_RichTextStyleListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
