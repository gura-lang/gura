//----------------------------------------------------------------------------
// wxGridBagSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridBagSizer
//----------------------------------------------------------------------------

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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GridBagSizer, wxGridBagSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vgap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hgap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, wxGridBagSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int vgap = arg.GetNumber(0)
	//int hgap = arg.GetNumber(1)
	//pThis->GetEntity()->wxGridBagSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, Add)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int span = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//int userData = arg.GetNumber(5)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, Add_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int span = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//int userData = arg.GetNumber(5)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, Add_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, Add_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, Add_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, Add_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int span = arg.GetNumber(3)
	//int flag = arg.GetNumber(4)
	//int border = arg.GetNumber(5)
	//int userData = arg.GetNumber(6)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, CalcMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridBagSizer, CalcMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, CheckForIntersection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "excludeItem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, CheckForIntersection)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int excludeItem = arg.GetNumber(1)
	//pThis->GetEntity()->CheckForIntersection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, CheckForIntersection_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "excludeItem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, CheckForIntersection_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int span = arg.GetNumber(1)
	//int excludeItem = arg.GetNumber(2)
	//pThis->GetEntity()->CheckForIntersection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, FindItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, FindItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, FindItem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, FindItem_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, FindItemAtPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, FindItemAtPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->FindItemAtPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, FindItemAtPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, FindItemAtPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->FindItemAtPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, FindItemWithData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, FindItemWithData)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int userData = arg.GetNumber(0)
	//pThis->GetEntity()->FindItemWithData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, GetCellSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, GetCellSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetCellSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, GetEmptyCellSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridBagSizer, GetEmptyCellSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEmptyCellSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, GetItemPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, GetItemPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, GetItemPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, GetItemPosition_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, GetItemPosition_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, GetItemPosition_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, GetItemSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, GetItemSpan)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, GetItemSpan_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, GetItemSpan_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, GetItemSpan_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, GetItemSpan_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemSpan();
	return Value::Nil;
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
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, SetEmptyCellSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, SetEmptyCellSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetEmptyCellSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, SetItemPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, SetItemPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, SetItemPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, SetItemPosition_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, SetItemPosition_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, SetItemPosition_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, SetItemSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, SetItemSpan)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int span = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, SetItemSpan_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, SetItemSpan_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int span = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridBagSizer, SetItemSpan_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, SetItemSpan_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int span = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemSpan();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridBagSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridBagSizer)
{
	Gura_AssignMethod(wx_GridBagSizer, wxGridBagSizer);
	Gura_AssignMethod(wx_GridBagSizer, Add);
	Gura_AssignMethod(wx_GridBagSizer, Add_1);
	Gura_AssignMethod(wx_GridBagSizer, Add_2);
	Gura_AssignMethod(wx_GridBagSizer, Add_3);
	Gura_AssignMethod(wx_GridBagSizer, CalcMin);
	Gura_AssignMethod(wx_GridBagSizer, CheckForIntersection);
	Gura_AssignMethod(wx_GridBagSizer, CheckForIntersection_1);
	Gura_AssignMethod(wx_GridBagSizer, FindItem);
	Gura_AssignMethod(wx_GridBagSizer, FindItem_1);
	Gura_AssignMethod(wx_GridBagSizer, FindItemAtPoint);
	Gura_AssignMethod(wx_GridBagSizer, FindItemAtPosition);
	Gura_AssignMethod(wx_GridBagSizer, FindItemWithData);
	Gura_AssignMethod(wx_GridBagSizer, GetCellSize);
	Gura_AssignMethod(wx_GridBagSizer, GetEmptyCellSize);
	Gura_AssignMethod(wx_GridBagSizer, GetItemPosition);
	Gura_AssignMethod(wx_GridBagSizer, GetItemPosition_1);
	Gura_AssignMethod(wx_GridBagSizer, GetItemPosition_2);
	Gura_AssignMethod(wx_GridBagSizer, GetItemSpan);
	Gura_AssignMethod(wx_GridBagSizer, GetItemSpan_1);
	Gura_AssignMethod(wx_GridBagSizer, GetItemSpan_2);
	Gura_AssignMethod(wx_GridBagSizer, RecalcSizes);
	Gura_AssignMethod(wx_GridBagSizer, SetEmptyCellSize);
	Gura_AssignMethod(wx_GridBagSizer, SetItemPosition);
	Gura_AssignMethod(wx_GridBagSizer, SetItemPosition_1);
	Gura_AssignMethod(wx_GridBagSizer, SetItemPosition_2);
	Gura_AssignMethod(wx_GridBagSizer, SetItemSpan);
	Gura_AssignMethod(wx_GridBagSizer, SetItemSpan_1);
	Gura_AssignMethod(wx_GridBagSizer, SetItemSpan_2);
}

Gura_ImplementDescendantCreator(wx_GridBagSizer)
{
	return new Object_wx_GridBagSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
