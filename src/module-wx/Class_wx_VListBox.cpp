//----------------------------------------------------------------------------
// wxVListBox
// extracted from vlbox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_VListBox: public wxVListBox, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_VListBox *_pObj;
public:
	//inline wx_VListBox(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxVListBox(parent, id, pos, size, style, name), _pObj(nullptr) {}
	//inline wx_VListBox() : wxVListBox(), _pObj(nullptr) {}
	~wx_VListBox();
	inline void AssocWithGura(Object_wx_VListBox *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_VListBox::~wx_VListBox()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_VListBox::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxVListBox
//----------------------------------------------------------------------------
Gura_DeclareFunction(VListBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_VListBox));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(VListBox)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxVListBoxNameStr;
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_VListBox *pEntity = new wx_VListBox(parent, id, *pos, *size, style, name);
	Object_wx_VListBox *pObj = Object_wx_VListBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_VListBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(VListBoxEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_VListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(VListBoxEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_VListBox *pEntity = new wx_VListBox();
	Object_wx_VListBox *pObj = Object_wx_VListBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_VListBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
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
	wxString name = wxVListBoxNameStr;
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, DeselectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, DeselectAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->DeselectAll();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, GetFirstSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, GetFirstSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned long cookie = args.GetULong(0);
	int rtn = pThis->GetEntity()->GetFirstSelected(cookie);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, GetItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, GetItemCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetItemCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, GetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, GetMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint rtn = pThis->GetEntity()->GetMargins();
	return ReturnValue(env, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_VListBox, GetNextSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, GetNextSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned long cookie = args.GetULong(0);
	int rtn = pThis->GetEntity()->GetNextSelected(cookie);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, GetSelectedCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, GetSelectedCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetSelectedCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, GetSelectionBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, GetSelectionBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetSelectionBackground();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_VListBox, HasMultipleSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, HasMultipleSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasMultipleSelection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, IsCurrent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, IsCurrent)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t item = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->IsCurrent(item);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, IsSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, IsSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t item = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->IsSelected(item);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, OnDrawBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_VListBox, OnDrawBackground)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	size_t n = args.GetSizeT(2);
	pThis->GetEntity()->OnDrawBackground(*dc, *rect, n);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, OnDrawItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_VListBox, OnDrawItem)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	size_t n = args.GetSizeT(2);
	pThis->GetEntity()->OnDrawItem(*dc, *rect, n);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, OnDrawSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_VListBox, OnDrawSeparator)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	size_t n = args.GetSizeT(2);
	pThis->GetEntity()->OnDrawSeparator(*dc, *rect, n);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, OnMeasureItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, OnMeasureItem)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = args.GetSizeT(0);
	wxCoord rtn = pThis->GetEntity()->OnMeasureItem(n);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, Select)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "select", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, Select)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t item = args.GetSizeT(0);
	bool select = true;
	if (args.IsValid(1)) select = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->Select(item, select);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, SelectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, SelectAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->SelectAll();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, SelectRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, SelectRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t from = args.GetSizeT(0);
	size_t to = args.GetSizeT(1);
	bool rtn = pThis->GetEntity()->SelectRange(from, to);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, SetItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetItemCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t count = args.GetSizeT(0);
	pThis->GetEntity()->SetItemCount(count);
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, SetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetMargins(*pt);
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, SetMargins_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetMargins_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->SetMargins(x, y);
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int selection = args.GetInt(0);
	pThis->GetEntity()->SetSelection(selection);
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, SetSelectionBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetSelectionBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *col = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetSelectionBackground(*col);
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, Toggle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, Toggle)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t item = args.GetSizeT(0);
	pThis->GetEntity()->Toggle(item);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxVListBox
//----------------------------------------------------------------------------
Object_wx_VListBox::~Object_wx_VListBox()
{
}

Object *Object_wx_VListBox::Clone() const
{
	return nullptr;
}

String Object_wx_VListBox::ToString(bool exprFlag)
{
	String rtn("<wx.VListBox:");
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
// Class implementation for wxVListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VListBox)
{
	Gura_AssignWxStringValue(VListBoxNameStr);
	Gura_AssignFunction(VListBox);
	Gura_AssignFunction(VListBoxEmpty);
	Gura_AssignMethod(wx_VListBox, Clear);
	Gura_AssignMethod(wx_VListBox, Create);
	Gura_AssignMethod(wx_VListBox, DeselectAll);
	Gura_AssignMethod(wx_VListBox, GetFirstSelected);
	Gura_AssignMethod(wx_VListBox, GetItemCount);
	Gura_AssignMethod(wx_VListBox, GetMargins);
	Gura_AssignMethod(wx_VListBox, GetNextSelected);
	Gura_AssignMethod(wx_VListBox, GetSelectedCount);
	Gura_AssignMethod(wx_VListBox, GetSelection);
	Gura_AssignMethod(wx_VListBox, GetSelectionBackground);
	Gura_AssignMethod(wx_VListBox, HasMultipleSelection);
	Gura_AssignMethod(wx_VListBox, IsCurrent);
	Gura_AssignMethod(wx_VListBox, IsSelected);
	Gura_AssignMethod(wx_VListBox, OnDrawBackground);
	Gura_AssignMethod(wx_VListBox, OnDrawItem);
	Gura_AssignMethod(wx_VListBox, OnDrawSeparator);
	Gura_AssignMethod(wx_VListBox, OnMeasureItem);
	Gura_AssignMethod(wx_VListBox, Select);
	Gura_AssignMethod(wx_VListBox, SelectAll);
	Gura_AssignMethod(wx_VListBox, SelectRange);
	Gura_AssignMethod(wx_VListBox, SetItemCount);
	Gura_AssignMethod(wx_VListBox, SetMargins);
	Gura_AssignMethod(wx_VListBox, SetMargins_1);
	Gura_AssignMethod(wx_VListBox, SetSelection);
	Gura_AssignMethod(wx_VListBox, SetSelectionBackground);
	Gura_AssignMethod(wx_VListBox, Toggle);
}

Gura_ImplementDescendantCreator(wx_VListBox)
{
	return new Object_wx_VListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
