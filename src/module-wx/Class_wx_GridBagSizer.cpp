//----------------------------------------------------------------------------
// wxGridBagSizer
// extracted from gridbagsizer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridBagSizer: public wxGridBagSizer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_GridBagSizer *_pObj;
public:
	inline wx_GridBagSizer(int vgap, int hgap) : wxGridBagSizer(vgap, hgap), _pObj(nullptr) {}
	~wx_GridBagSizer();
	inline void AssocWithGura(Object_wx_GridBagSizer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridBagSizer::~wx_GridBagSizer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridBagSizer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridBagSizer
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridBagSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridBagSizer));
	DeclareArg(env, "vgap", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "hgap", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridBagSizer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int vgap = 0;
	if (args.IsValid(0)) vgap = args.GetInt(0);
	int hgap = 0;
	if (args.IsValid(1)) hgap = args.GetInt(1);
	wx_GridBagSizer *pEntity = new wx_GridBagSizer(vgap, hgap);
	Object_wx_GridBagSizer *pObj = Object_wx_GridBagSizer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridBagSizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_GridBagSizer, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 1)->GetEntity();
	wxGBSpan *span = (wxGBSpan *)(&wxDefaultSpan);
	if (args.IsValid(2)) span = Object_wx_GBSpan::GetObject(args, 2)->GetEntity();
	int flag = 0;
	if (args.IsValid(3)) flag = args.GetInt(3);
	int border = 0;
	if (args.IsValid(4)) border = args.GetInt(4);
	wxObject *userData = (wxObject *)(nullptr);
	if (args.IsValid(5)) userData = Object_wx_Object::GetObject(args, 5)->GetEntity();
	wxSizerItem *rtn = nullptr;
	if (args.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->Add(window, *pos, *span, flag, border, userData);
	} else if (args.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->Add(sizer, *pos, *span, flag, border, userData);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, args, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, AddSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 2)->GetEntity();
	wxGBSpan *span = (wxGBSpan *)(&wxDefaultSpan);
	if (args.IsValid(3)) span = Object_wx_GBSpan::GetObject(args, 3)->GetEntity();
	int flag = 0;
	if (args.IsValid(4)) flag = args.GetInt(4);
	int border = 0;
	if (args.IsValid(5)) border = args.GetInt(5);
	wxObject *userData = (wxObject *)(nullptr);
	if (args.IsValid(6)) userData = Object_wx_Object::GetObject(args, 6)->GetEntity();
	wxSizerItem *rtn = (wxSizerItem *)pThis->GetEntity()->Add(width, height, *pos, *span, flag, border, userData);
	return ReturnValue(env, args, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, AddItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_GBSizerItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, AddItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBSizerItem *item = Object_wx_GBSizerItem::GetObject(args, 0)->GetEntity();
	wxSizerItem *rtn = (wxSizerItem *)pThis->GetEntity()->Add(item);
	return ReturnValue(env, args, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, CalcMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, CalcMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->CalcMin();
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridBagSizer, CheckForIntersection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_GBSizerItem, OCCUR_Once);
	DeclareArg(env, "excludeItem", VTYPE_wx_GBSizerItem, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, CheckForIntersection)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBSizerItem *item = Object_wx_GBSizerItem::GetObject(args, 0)->GetEntity();
	wxGBSizerItem *excludeItem = (wxGBSizerItem *)(nullptr);
	if (args.IsValid(1)) excludeItem = Object_wx_GBSizerItem::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->CheckForIntersection(item, excludeItem);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridBagSizer, CheckForIntersectionPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareArg(env, "span", VTYPE_wx_GBSpan, OCCUR_Once);
	DeclareArg(env, "excludeItem", VTYPE_wx_GBSizerItem, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, CheckForIntersectionPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 0)->GetEntity();
	wxGBSpan *span = Object_wx_GBSpan::GetObject(args, 1)->GetEntity();
	wxGBSizerItem *excludeItem = (wxGBSizerItem *)(nullptr);
	if (args.IsValid(2)) excludeItem = Object_wx_GBSizerItem::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->CheckForIntersection(*pos, *span, excludeItem);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridBagSizer, FindItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, FindItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBSizerItem *rtn = nullptr;
	if (args.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
		rtn = (wxGBSizerItem *)pThis->GetEntity()->FindItem(window);
	} else if (args.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
		rtn = (wxGBSizerItem *)pThis->GetEntity()->FindItem(sizer);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, args, Value(new Object_wx_GBSizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, FindItemAtPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, FindItemAtPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxGBSizerItem *rtn = (wxGBSizerItem *)pThis->GetEntity()->FindItemAtPoint(*pt);
	return ReturnValue(env, args, Value(new Object_wx_GBSizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, FindItemAtPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, FindItemAtPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 0)->GetEntity();
	wxGBSizerItem *rtn = (wxGBSizerItem *)pThis->GetEntity()->FindItemAtPosition(*pos);
	return ReturnValue(env, args, Value(new Object_wx_GBSizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, FindItemWithData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, FindItemWithData)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxObject *userData = Object_wx_Object::GetObject(args, 0)->GetEntity();
	wxGBSizerItem *rtn = (wxGBSizerItem *)pThis->GetEntity()->FindItemWithData(userData);
	return ReturnValue(env, args, Value(new Object_wx_GBSizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, GetCellSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, GetCellSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxSize rtn = pThis->GetEntity()->GetCellSize(row, col);
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridBagSizer, GetEmptyCellSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, GetEmptyCellSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetEmptyCellSize();
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridBagSizer, GetItemPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, GetItemPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBPosition rtn;
	if (args.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
		rtn = pThis->GetEntity()->GetItemPosition(window);
	} else if (args.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
		rtn = pThis->GetEntity()->GetItemPosition(sizer);
	} else if (args.IsInstanceOf(0, VTYPE_number)) {
		size_t index = args.GetSizeT(0);
		rtn = pThis->GetEntity()->GetItemPosition(index);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, args, Value(new Object_wx_GBPosition(new wxGBPosition(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridBagSizer, GetItemSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, GetItemSpan)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBSpan rtn;
	if (args.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
		rtn = pThis->GetEntity()->GetItemSpan(window);
	} else if (args.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
		rtn = pThis->GetEntity()->GetItemSpan(sizer);
	} else if (args.IsInstanceOf(0, VTYPE_number)) {
		size_t index = args.GetSizeT(0);
		rtn = pThis->GetEntity()->GetItemSpan(index);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, args, Value(new Object_wx_GBSpan(new wxGBSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridBagSizer, RecalcSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridBagSizer, RecalcSizes)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->RecalcSizes();
	return Value::Null;
}

Gura_DeclareMethod(wx_GridBagSizer, SetEmptyCellSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, SetEmptyCellSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *sz = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetEmptyCellSize(*sz);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridBagSizer, SetItemPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, SetItemPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(args, 1)->GetEntity();
	bool rtn = false;
	if (args.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
		rtn = pThis->GetEntity()->SetItemPosition(window, *pos);
	} else if (args.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
		rtn = pThis->GetEntity()->SetItemPosition(sizer, *pos);
	} else if (args.IsInstanceOf(0, VTYPE_number)) {
		size_t index = args.GetSizeT(0);
		rtn = pThis->GetEntity()->SetItemPosition(index, *pos);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridBagSizer, SetItemSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "span", VTYPE_wx_GBSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, SetItemSpan)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGBSpan *span = Object_wx_GBSpan::GetObject(args, 1)->GetEntity();
	bool rtn = false;
	if (args.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
		rtn = pThis->GetEntity()->SetItemSpan(window, *span);
	} else if (args.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(args, 0)->GetEntity();
		rtn = pThis->GetEntity()->SetItemSpan(sizer, *span);
	} else if (args.IsInstanceOf(0, VTYPE_number)) {
		size_t index = args.GetSizeT(0);
		bool rtn = pThis->GetEntity()->SetItemSpan(index, *span);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxGridBagSizer
//----------------------------------------------------------------------------
Object_wx_GridBagSizer::~Object_wx_GridBagSizer()
{
}

Object *Object_wx_GridBagSizer::Clone() const
{
	return nullptr;
}

String Object_wx_GridBagSizer::ToString(bool exprFlag)
{
	String rtn("<wx.GridBagSizer:");
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
// Class implementation for wxGridBagSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridBagSizer)
{
	Gura_AssignFunction(GridBagSizer);
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
	return new Object_wx_GridBagSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
