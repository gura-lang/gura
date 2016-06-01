//----------------------------------------------------------------------------
// wxPGChoices
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGChoices
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGChoices
//----------------------------------------------------------------------------
Object_wx_PGChoices::~Object_wx_PGChoices()
{
}

Object *Object_wx_PGChoices::Clone() const
{
	return nullptr;
}

String Object_wx_PGChoices::ToString(bool exprFlag)
{
	String rtn("<wx.PGChoices:");
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
Gura_DeclareMethod(wx_PGChoices, wxPGChoices)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGChoices, wxPGChoices)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPGChoices();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, wxPGChoices_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "a", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, wxPGChoices_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int a = arg.GetNumber(0)
	//pThis->GetEntity()->wxPGChoices();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, wxPGChoices_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "labels", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, wxPGChoices_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int labels = arg.GetNumber(0)
	//int values = arg.GetNumber(1)
	//pThis->GetEntity()->wxPGChoices();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, wxPGChoices_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "labels", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, wxPGChoices_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int labels = arg.GetNumber(0)
	//int values = arg.GetNumber(1)
	//pThis->GetEntity()->wxPGChoices();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, wxPGChoices_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, wxPGChoices_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->wxPGChoices();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, ~wxPGChoices)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGChoices, ~wxPGChoices)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPGChoices();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "labels", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, Add)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int labels = arg.GetNumber(0)
	//int values = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "arrint", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, Add_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int arr = arg.GetNumber(0)
	//int arrint = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Add_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, Add_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Add_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, Add_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Add_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, Add_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, AddAsSorted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, AddAsSorted)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->AddAsSorted();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Assign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "a", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, Assign)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int a = arg.GetNumber(0)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, AssignData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, AssignData)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->AssignData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGChoices, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGChoices, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, GetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ind = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGChoices, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ind = arg.GetNumber(0)
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, GetValuesForStrings)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strings", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, GetValuesForStrings)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int strings = arg.GetNumber(0)
	//pThis->GetEntity()->GetValuesForStrings();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, GetIndicesForStrings)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strings", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "unmatched", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, GetIndicesForStrings)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int strings = arg.GetNumber(0)
	//int unmatched = arg.GetNumber(1)
	//pThis->GetEntity()->GetIndicesForStrings();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Index)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, Index)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->Index();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Index_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, Index_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->Index();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, Insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Insert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, Insert_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGChoices, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Item)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, Item)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->Item();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Item_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, Item_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->Item();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, RemoveAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nIndex", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, RemoveAt)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int nIndex = arg.GetNumber(0)
	//int count = arg.GetNumber(1)
	//pThis->GetEntity()->RemoveAt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "labels", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int labels = arg.GetNumber(0)
	//int values = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, Set_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "labels", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGChoices, Set_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int labels = arg.GetNumber(0)
	//int values = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, AllocExclusive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGChoices, AllocExclusive)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AllocExclusive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGChoices, GetLabels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGChoices, GetLabels)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGChoices *pThis = Object_wx_PGChoices::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLabels();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPGChoices
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGChoices)
{
	Gura_AssignMethod(wx_PGChoices, wxPGChoices);
	Gura_AssignMethod(wx_PGChoices, wxPGChoices_1);
	Gura_AssignMethod(wx_PGChoices, wxPGChoices_2);
	Gura_AssignMethod(wx_PGChoices, wxPGChoices_3);
	Gura_AssignMethod(wx_PGChoices, wxPGChoices_4);
	Gura_AssignMethod(wx_PGChoices, ~wxPGChoices);
	Gura_AssignMethod(wx_PGChoices, Add);
	Gura_AssignMethod(wx_PGChoices, Add_1);
	Gura_AssignMethod(wx_PGChoices, Add_2);
	Gura_AssignMethod(wx_PGChoices, Add_3);
	Gura_AssignMethod(wx_PGChoices, Add_4);
	Gura_AssignMethod(wx_PGChoices, AddAsSorted);
	Gura_AssignMethod(wx_PGChoices, Assign);
	Gura_AssignMethod(wx_PGChoices, AssignData);
	Gura_AssignMethod(wx_PGChoices, Clear);
	Gura_AssignMethod(wx_PGChoices, Copy);
	Gura_AssignMethod(wx_PGChoices, GetLabel);
	Gura_AssignMethod(wx_PGChoices, GetCount);
	Gura_AssignMethod(wx_PGChoices, GetValue);
	Gura_AssignMethod(wx_PGChoices, GetValuesForStrings);
	Gura_AssignMethod(wx_PGChoices, GetIndicesForStrings);
	Gura_AssignMethod(wx_PGChoices, Index);
	Gura_AssignMethod(wx_PGChoices, Index_1);
	Gura_AssignMethod(wx_PGChoices, Insert);
	Gura_AssignMethod(wx_PGChoices, Insert_1);
	Gura_AssignMethod(wx_PGChoices, IsOk);
	Gura_AssignMethod(wx_PGChoices, Item);
	Gura_AssignMethod(wx_PGChoices, Item_1);
	Gura_AssignMethod(wx_PGChoices, RemoveAt);
	Gura_AssignMethod(wx_PGChoices, Set);
	Gura_AssignMethod(wx_PGChoices, Set_1);
	Gura_AssignMethod(wx_PGChoices, AllocExclusive);
	Gura_AssignMethod(wx_PGChoices, GetLabels);
}

Gura_ImplementDescendantCreator(wx_PGChoices)
{
	return new Object_wx_PGChoices((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
