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
	if (!CheckWxReady(sig)) return Value::Nil;
	int vgap = 0;
	if (arg.IsValid(0)) vgap = arg.GetInt(0);
	int hgap = 0;
	if (arg.IsValid(1)) hgap = arg.GetInt(1);
	wx_GridBagSizer *pEntity = new wx_GridBagSizer(vgap, hgap);
	Object_wx_GridBagSizer *pObj = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridBagSizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
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
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(arg, 1)->GetEntity();
	wxGBSpan *span = (wxGBSpan *)(&wxDefaultSpan);
	if (arg.IsValid(2)) span = Object_wx_GBSpan::GetObject(arg, 2)->GetEntity();
	int flag = 0;
	if (arg.IsValid(3)) flag = arg.GetInt(3);
	int border = 0;
	if (arg.IsValid(4)) border = arg.GetInt(4);
	wxObject *userData = (wxObject *)(nullptr);
	if (arg.IsValid(5)) userData = Object_wx_Object::GetObject(arg, 5)->GetEntity();
	wxSizerItem *rtn = nullptr;
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->Add(window, *pos, *span, flag, border, userData);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->Add(sizer, *pos, *span, flag, border, userData);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
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
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(arg, 2)->GetEntity();
	wxGBSpan *span = (wxGBSpan *)(&wxDefaultSpan);
	if (arg.IsValid(3)) span = Object_wx_GBSpan::GetObject(arg, 3)->GetEntity();
	int flag = 0;
	if (arg.IsValid(4)) flag = arg.GetInt(4);
	int border = 0;
	if (arg.IsValid(5)) border = arg.GetInt(5);
	wxObject *userData = (wxObject *)(nullptr);
	if (arg.IsValid(6)) userData = Object_wx_Object::GetObject(arg, 6)->GetEntity();
	wxSizerItem *rtn = (wxSizerItem *)pThis->GetEntity()->Add(width, height, *pos, *span, flag, border, userData);
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
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
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBSizerItem *item = Object_wx_GBSizerItem::GetObject(arg, 0)->GetEntity();
	wxSizerItem *rtn = (wxSizerItem *)pThis->GetEntity()->Add(item);
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridBagSizer, CalcMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, CalcMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->CalcMin();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
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
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBSizerItem *item = Object_wx_GBSizerItem::GetObject(arg, 0)->GetEntity();
	wxGBSizerItem *excludeItem = (wxGBSizerItem *)(nullptr);
	if (arg.IsValid(1)) excludeItem = Object_wx_GBSizerItem::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->CheckForIntersection(item, excludeItem);
	return ReturnValue(env, arg, Value(rtn));
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
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(arg, 0)->GetEntity();
	wxGBSpan *span = Object_wx_GBSpan::GetObject(arg, 1)->GetEntity();
	wxGBSizerItem *excludeItem = (wxGBSizerItem *)(nullptr);
	if (arg.IsValid(2)) excludeItem = Object_wx_GBSizerItem::GetObject(arg, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->CheckForIntersection(*pos, *span, excludeItem);
	return ReturnValue(env, arg, Value(rtn));
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
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBSizerItem *rtn = nullptr;
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		rtn = (wxGBSizerItem *)pThis->GetEntity()->FindItem(window);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		rtn = (wxGBSizerItem *)pThis->GetEntity()->FindItem(sizer);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(new Object_wx_GBSizerItem(rtn, nullptr, OwnerFalse)));
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
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	wxGBSizerItem *rtn = (wxGBSizerItem *)pThis->GetEntity()->FindItemAtPoint(*pt);
	return ReturnValue(env, arg, Value(new Object_wx_GBSizerItem(rtn, nullptr, OwnerFalse)));
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
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(arg, 0)->GetEntity();
	wxGBSizerItem *rtn = (wxGBSizerItem *)pThis->GetEntity()->FindItemAtPosition(*pos);
	return ReturnValue(env, arg, Value(new Object_wx_GBSizerItem(rtn, nullptr, OwnerFalse)));
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
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObject *userData = Object_wx_Object::GetObject(arg, 0)->GetEntity();
	wxGBSizerItem *rtn = (wxGBSizerItem *)pThis->GetEntity()->FindItemWithData(userData);
	return ReturnValue(env, arg, Value(new Object_wx_GBSizerItem(rtn, nullptr, OwnerFalse)));
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
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	wxSize rtn = pThis->GetEntity()->GetCellSize(row, col);
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridBagSizer, GetEmptyCellSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridBagSizer, GetEmptyCellSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetEmptyCellSize();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
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
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBPosition rtn;
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->GetItemPosition(window);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->GetItemPosition(sizer);
	} else if (arg.IsInstanceOf(0, VTYPE_number)) {
		size_t index = arg.GetSizeT(0);
		rtn = pThis->GetEntity()->GetItemPosition(index);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(new Object_wx_GBPosition(new wxGBPosition(rtn), nullptr, OwnerTrue)));
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
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBSpan rtn;
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->GetItemSpan(window);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->GetItemSpan(sizer);
	} else if (arg.IsInstanceOf(0, VTYPE_number)) {
		size_t index = arg.GetSizeT(0);
		rtn = pThis->GetEntity()->GetItemSpan(index);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(new Object_wx_GBSpan(new wxGBSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridBagSizer, RecalcSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridBagSizer, RecalcSizes)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, SetEmptyCellSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, SetEmptyCellSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *sz = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetEmptyCellSize(*sz);
	return Value::Nil;
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
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBPosition *pos = Object_wx_GBPosition::GetObject(arg, 1)->GetEntity();
	bool rtn = false;
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->SetItemPosition(window, *pos);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->SetItemPosition(sizer, *pos);
	} else if (arg.IsInstanceOf(0, VTYPE_number)) {
		size_t index = arg.GetSizeT(0);
		rtn = pThis->GetEntity()->SetItemPosition(index, *pos);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(rtn));
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
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGBSpan *span = Object_wx_GBSpan::GetObject(arg, 1)->GetEntity();
	bool rtn = false;
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->SetItemSpan(window, *span);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->SetItemSpan(sizer, *span);
	} else if (arg.IsInstanceOf(0, VTYPE_number)) {
		size_t index = arg.GetSizeT(0);
		bool rtn = pThis->GetEntity()->SetItemSpan(index, *span);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(rtn));
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
