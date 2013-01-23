//----------------------------------------------------------------------------
// wxVListBox
// extracted from vlbox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_VListBox: public wxVListBox, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_VListBox *_pObj;
public:
	//inline wx_VListBox(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxVListBox(parent, id, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	//inline wx_VListBox() : wxVListBox(), _sig(NULL), _pObj(NULL) {}
	~wx_VListBox();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_VListBox *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_VListBox::~wx_VListBox()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_VListBox::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxVListBox
//----------------------------------------------------------------------------
Gura_DeclareFunction(VListBox)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
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
	Object_wx_VListBox *pObj = Object_wx_VListBox::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_VListBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(VListBoxEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_VListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(VListBoxEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_VListBox *pEntity = new wx_VListBox();
	Object_wx_VListBox *pObj = Object_wx_VListBox::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_VListBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_VListBox, Clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, Clear)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Clear();
	return Value::Null;
}

Gura_DeclareMethod(wx_VListBox, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
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
	bool rtn = pSelf->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, DeselectAll)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, DeselectAll)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->DeselectAll();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, GetFirstSelected)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, GetFirstSelected)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned long cookie = args.GetULong(0);
	int rtn = pSelf->GetEntity()->GetFirstSelected(cookie);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, GetItemCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, GetItemCount)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t rtn = pSelf->GetEntity()->GetItemCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, GetMargins)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, GetMargins)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pSelf->GetEntity()->GetMargins();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_VListBox, GetNextSelected)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, GetNextSelected)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned long cookie = args.GetULong(0);
	int rtn = pSelf->GetEntity()->GetNextSelected(cookie);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, GetSelectedCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, GetSelectedCount)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t rtn = pSelf->GetEntity()->GetSelectedCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, GetSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, GetSelection)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, GetSelectionBackground)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, GetSelectionBackground)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pSelf->GetEntity()->GetSelectionBackground();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_VListBox, HasMultipleSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, HasMultipleSelection)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasMultipleSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, IsCurrent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, IsCurrent)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t item = args.GetSizeT(0);
	bool rtn = pSelf->GetEntity()->IsCurrent(item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, IsSelected)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, IsSelected)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t item = args.GetSizeT(0);
	bool rtn = pSelf->GetEntity()->IsSelected(item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, OnDrawBackground)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_VListBox, OnDrawBackground)
{
#if 0
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	size_t n = args.GetSizeT(2);
	pSelf->GetEntity()->OnDrawBackground(*dc, *rect, n);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_VListBox, OnDrawItem)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_VListBox, OnDrawItem)
{
#if 0
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	size_t n = args.GetSizeT(2);
	pSelf->GetEntity()->OnDrawItem(*dc, *rect, n);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_VListBox, OnDrawSeparator)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_VListBox, OnDrawSeparator)
{
#if 0
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	size_t n = args.GetSizeT(2);
	pSelf->GetEntity()->OnDrawSeparator(*dc, *rect, n);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_VListBox, OnMeasureItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, OnMeasureItem)
{
#if 0
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxCoord rtn = pSelf->GetEntity()->OnMeasureItem(n);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_VListBox, Select)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "select", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, Select)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t item = args.GetSizeT(0);
	bool select = true;
	if (args.IsValid(1)) select = args.GetBoolean(1);
	bool rtn = pSelf->GetEntity()->Select(item, select);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, SelectAll)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, SelectAll)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->SelectAll();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, SelectRange)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VListBox, SelectRange)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t from = args.GetSizeT(0);
	size_t to = args.GetSizeT(1);
	bool rtn = pSelf->GetEntity()->SelectRange(from, to);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VListBox, SetItemCount)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetItemCount)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t count = args.GetSizeT(0);
	pSelf->GetEntity()->SetItemCount(count);
	return Value::Null;
}

Gura_DeclareMethod(wx_VListBox, SetMargins)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetMargins)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetMargins(*pt);
	return Value::Null;
}

Gura_DeclareMethod(wx_VListBox, SetMargins_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetMargins_1)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	pSelf->GetEntity()->SetMargins(x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_VListBox, SetSelection)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetSelection)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int selection = args.GetInt(0);
	pSelf->GetEntity()->SetSelection(selection);
	return Value::Null;
}

Gura_DeclareMethod(wx_VListBox, SetSelectionBackground)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetSelectionBackground)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *col = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetSelectionBackground(*col);
	return Value::Null;
}

Gura_DeclareMethod(wx_VListBox, Toggle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, Toggle)
{
	Object_wx_VListBox *pSelf = Object_wx_VListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t item = args.GetSizeT(0);
	pSelf->GetEntity()->Toggle(item);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxVListBox
//----------------------------------------------------------------------------
Object_wx_VListBox::~Object_wx_VListBox()
{
}

Object *Object_wx_VListBox::Clone() const
{
	return NULL;
}

String Object_wx_VListBox::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.VListBox:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_VListBox::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignWxStringValue(VListBoxNameStr);
	Gura_AssignFunction(VListBox);
	Gura_AssignFunction(VListBoxEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxVListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VListBox)
{
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
	return new Object_wx_VListBox((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
