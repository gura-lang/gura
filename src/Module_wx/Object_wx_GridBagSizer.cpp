//----------------------------------------------------------------------------
// wxGridBagSizer
// extracted from gridbagsizer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridBagSizer: public wxGridBagSizer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridBagSizer *_pObj;
public:
	inline wx_GridBagSizer(int vgap, int hgap) : wxGridBagSizer(vgap, hgap), _sig(NULL), _pObj(NULL) {}
	~wx_GridBagSizer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridBagSizer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridBagSizer::~wx_GridBagSizer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridBagSizer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridBagSizer
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridBagSizer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridBagSizer));
	DeclareArg(env, "vgap", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "hgap", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridBagSizer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int vgap = 0;
	if (args.IsValid(0)) vgap = args.GetInt(0);
	int hgap = 0;
	if (args.IsValid(1)) hgap = args.GetInt(1);
	wx_GridBagSizer *pEntity = new wx_GridBagSizer(vgap, hgap);
	Object_wx_GridBagSizer *pObj = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridBagSizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_GridBagSizer, Add)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareArg(env, "span", VTYPE_wx_GBSpan, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "border", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, Add)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 1)->GetEntity();
	wxGBSpan *span = (wxGBSpan *)(&wxDefaultSpan);
	if (args.IsValid(2)) span = Object_wx_GBSpan::GetObject(args, 2)->GetEntity();
	int flag = 0;
	if (args.IsValid(3)) flag = args.GetInt(3);
	int border = 0;
	if (args.IsValid(4)) border = args.GetInt(4);
	wxObject *userData = (wxObject *)(NULL);
	if (args.IsValid(5)) userData = Object_wx_Object::GetObject(args, 5)->GetEntity();
	wxSizerItem *rtn = NULL;
	if (args.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
		rtn = (wxSizerItem *)pSelf->GetEntity()->Add(window, *pos, *span, flag, border, userData);
	} else if (args.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
		rtn = (wxSizerItem *)pSelf->GetEntity()->Add(sizer, *pos, *span, flag, border, userData);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, AddSpacer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareArg(env, "span", VTYPE_wx_GBSpan, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "border", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, AddSpacer)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 2)->GetEntity();
	wxGBSpan *span = (wxGBSpan *)(&wxDefaultSpan);
	if (args.IsValid(3)) span = Object_wx_GBSpan::GetObject(args, 3)->GetEntity();
	int flag = 0;
	if (args.IsValid(4)) flag = args.GetInt(4);
	int border = 0;
	if (args.IsValid(5)) border = args.GetInt(5);
	wxObject *userData = (wxObject *)(NULL);
	if (args.IsValid(6)) userData = Object_wx_Object::GetObject(args, 6)->GetEntity();
	wxSizerItem *rtn = (wxSizerItem *)pSelf->GetEntity()->Add(width, height, *pos, *span, flag, border, userData);
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, AddItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_GBSizerItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, AddItem)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxGBSizerItem *item = Object_wx_GBSizerItem::GetObject(args, 0)->GetEntity();
	wxSizerItem *rtn = (wxSizerItem *)pSelf->GetEntity()->Add(item);
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, CalcMin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, CalcMin)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pSelf->GetEntity()->CalcMin();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridBagSizer, CheckForIntersection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_GBSizerItem, OCCUR_Once);
	DeclareArg(env, "excludeItem", VTYPE_wx_GBSizerItem, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, CheckForIntersection)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxGBSizerItem *item = Object_wx_GBSizerItem::GetObject(args, 0)->GetEntity();
	wxGBSizerItem *excludeItem = (wxGBSizerItem *)(NULL);
	if (args.IsValid(1)) excludeItem = Object_wx_GBSizerItem::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->CheckForIntersection(item, excludeItem);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridBagSizer, CheckForIntersectionPos)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareArg(env, "span", VTYPE_wx_GBSpan, OCCUR_Once);
	DeclareArg(env, "excludeItem", VTYPE_wx_GBSizerItem, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, CheckForIntersectionPos)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 0)->GetEntity();
	wxGBSpan *span = Object_wx_GBSpan::GetObject(args, 1)->GetEntity();
	wxGBSizerItem *excludeItem = (wxGBSizerItem *)(NULL);
	if (args.IsValid(2)) excludeItem = Object_wx_GBSizerItem::GetObject(args, 2)->GetEntity();
	bool rtn = pSelf->GetEntity()->CheckForIntersection(*pos, *span, excludeItem);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridBagSizer, FindItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, FindItem)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxGBSizerItem *rtn = NULL;
	if (args.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
		rtn = (wxGBSizerItem *)pSelf->GetEntity()->FindItem(window);
	} else if (args.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
		rtn = (wxGBSizerItem *)pSelf->GetEntity()->FindItem(sizer);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_wx_GBSizerItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, FindItemAtPoint)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, FindItemAtPoint)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxGBSizerItem *rtn = (wxGBSizerItem *)pSelf->GetEntity()->FindItemAtPoint(*pt);
	return ReturnValue(env, sig, args, Value(new Object_wx_GBSizerItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, FindItemAtPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, FindItemAtPosition)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 0)->GetEntity();
	wxGBSizerItem *rtn = (wxGBSizerItem *)pSelf->GetEntity()->FindItemAtPosition(*pos);
	return ReturnValue(env, sig, args, Value(new Object_wx_GBSizerItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, FindItemWithData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, FindItemWithData)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxObject *userData = Object_wx_Object::GetObject(args, 0)->GetEntity();
	wxGBSizerItem *rtn = (wxGBSizerItem *)pSelf->GetEntity()->FindItemWithData(userData);
	return ReturnValue(env, sig, args, Value(new Object_wx_GBSizerItem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, GetCellSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, GetCellSize)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxSize rtn = pSelf->GetEntity()->GetCellSize(row, col);
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridBagSizer, GetEmptyCellSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, GetEmptyCellSize)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pSelf->GetEntity()->GetEmptyCellSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridBagSizer, GetItemPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, GetItemPosition)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxGBPosition rtn;
	if (args.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
		rtn = pSelf->GetEntity()->GetItemPosition(window);
	} else if (args.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
		rtn = pSelf->GetEntity()->GetItemPosition(sizer);
	} else if (args.IsInstanceOf(0, VTYPE_number)) {
		size_t index = args.GetSizeT(0);
		rtn = pSelf->GetEntity()->GetItemPosition(index);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_wx_GBPosition(new wxGBPosition(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridBagSizer, GetItemSpan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, GetItemSpan)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxGBSpan rtn;
	if (args.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
		rtn = pSelf->GetEntity()->GetItemSpan(window);
	} else if (args.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
		rtn = pSelf->GetEntity()->GetItemSpan(sizer);
	} else if (args.IsInstanceOf(0, VTYPE_number)) {
		size_t index = args.GetSizeT(0);
		rtn = pSelf->GetEntity()->GetItemSpan(index);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_wx_GBSpan(new wxGBSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridBagSizer, RecalcSizes)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridBagSizer, RecalcSizes)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->RecalcSizes();
	return Value::Null;
}

Gura_DeclareMethod(wx_GridBagSizer, SetEmptyCellSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, SetEmptyCellSize)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize *sz = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetEmptyCellSize(*sz);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridBagSizer, SetItemPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, SetItemPosition)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 1)->GetEntity();
	bool rtn = false;
	if (args.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
		rtn = pSelf->GetEntity()->SetItemPosition(window, *pos);
	} else if (args.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
		rtn = pSelf->GetEntity()->SetItemPosition(sizer, *pos);
	} else if (args.IsInstanceOf(0, VTYPE_number)) {
		size_t index = args.GetSizeT(0);
		rtn = pSelf->GetEntity()->SetItemPosition(index, *pos);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridBagSizer, SetItemSpan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "span", VTYPE_wx_GBSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, SetItemSpan)
{
	Object_wx_GridBagSizer *pSelf = Object_wx_GridBagSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxGBSpan *span = Object_wx_GBSpan::GetObject(args, 1)->GetEntity();
	bool rtn = false;
	if (args.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
		rtn = pSelf->GetEntity()->SetItemSpan(window, *span);
	} else if (args.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
		rtn = pSelf->GetEntity()->SetItemSpan(sizer, *span);
	} else if (args.IsInstanceOf(0, VTYPE_number)) {
		size_t index = args.GetSizeT(0);
		bool rtn = pSelf->GetEntity()->SetItemSpan(index, *span);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxGridBagSizer
//----------------------------------------------------------------------------
Object_wx_GridBagSizer::~Object_wx_GridBagSizer()
{
}

Object *Object_wx_GridBagSizer::Clone() const
{
	return NULL;
}

String Object_wx_GridBagSizer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GridBagSizer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GridBagSizer::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(GridBagSizer);
}

//----------------------------------------------------------------------------
// Class implementation for wxGridBagSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridBagSizer)
{
	Gura_AssignMethod(wx_GridBagSizer, Add);
	Gura_AssignMethod(wx_GridBagSizer, AddSpacer);
	Gura_AssignMethod(wx_GridBagSizer, AddItem);
	Gura_AssignMethod(wx_GridBagSizer, CalcMin);
	Gura_AssignMethod(wx_GridBagSizer, CheckForIntersection);
	Gura_AssignMethod(wx_GridBagSizer, CheckForIntersectionPos);
	Gura_AssignMethod(wx_GridBagSizer, FindItem);
	Gura_AssignMethod(wx_GridBagSizer, FindItemAtPoint);
	Gura_AssignMethod(wx_GridBagSizer, FindItemAtPosition);
	Gura_AssignMethod(wx_GridBagSizer, FindItemWithData);
	Gura_AssignMethod(wx_GridBagSizer, GetCellSize);
	Gura_AssignMethod(wx_GridBagSizer, GetEmptyCellSize);
	Gura_AssignMethod(wx_GridBagSizer, GetItemPosition);
	Gura_AssignMethod(wx_GridBagSizer, GetItemSpan);
	Gura_AssignMethod(wx_GridBagSizer, RecalcSizes);
	Gura_AssignMethod(wx_GridBagSizer, SetEmptyCellSize);
	Gura_AssignMethod(wx_GridBagSizer, SetItemPosition);
	Gura_AssignMethod(wx_GridBagSizer, SetItemSpan);
}

Gura_ImplementDescendantCreator(wx_GridBagSizer)
{
	return new Object_wx_GridBagSizer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
