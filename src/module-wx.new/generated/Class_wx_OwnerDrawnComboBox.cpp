//----------------------------------------------------------------------------
// wxOwnerDrawnComboBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxOwnerDrawnComboBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxOwnerDrawnComboBox
//----------------------------------------------------------------------------
Object_wx_OwnerDrawnComboBox::~Object_wx_OwnerDrawnComboBox()
{
}

Object *Object_wx_OwnerDrawnComboBox::Clone() const
{
	return nullptr;
}

String Object_wx_OwnerDrawnComboBox::ToString(bool exprFlag)
{
	String rtn("<wx.OwnerDrawnComboBox:");
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
Gura_DeclareMethod(wx_OwnerDrawnComboBox, wxOwnerDrawnComboBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, wxOwnerDrawnComboBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxOwnerDrawnComboBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, wxOwnerDrawnComboBox_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, wxOwnerDrawnComboBox_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int n = arg.GetNumber(5)
	//int choices = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//int validator = arg.GetNumber(8)
	//int name = arg.GetNumber(9)
	//pThis->GetEntity()->wxOwnerDrawnComboBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, wxOwnerDrawnComboBox_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, wxOwnerDrawnComboBox_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int choices = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->wxOwnerDrawnComboBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, ~wxOwnerDrawnComboBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, ~wxOwnerDrawnComboBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxOwnerDrawnComboBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, Create_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int n = arg.GetNumber(5)
	//int choices = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//int validator = arg.GetNumber(8)
	//int name = arg.GetNumber(9)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, Create_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, Create_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int choices = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, IsListEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, IsListEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsListEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, IsTextEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, IsTextEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsTextEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, GetWidestItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, GetWidestItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWidestItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, GetWidestItemWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, GetWidestItemWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWidestItemWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, OnDrawBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, OnDrawBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->OnDrawBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, OnDrawItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, OnDrawItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->OnDrawItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, OnMeasureItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, OnMeasureItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->OnMeasureItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, OnMeasureItemWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, OnMeasureItemWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->OnMeasureItemWidth();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxOwnerDrawnComboBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_OwnerDrawnComboBox)
{
	Gura_AssignMethod(wx_OwnerDrawnComboBox, wxOwnerDrawnComboBox);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, wxOwnerDrawnComboBox_1);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, wxOwnerDrawnComboBox_2);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, ~wxOwnerDrawnComboBox);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, Create);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, Create_1);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, Create_2);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, IsEmpty);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, IsListEmpty);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, IsTextEmpty);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, GetWidestItem);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, GetWidestItemWidth);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, OnDrawBackground);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, OnDrawItem);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, OnMeasureItem);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, OnMeasureItemWidth);
}

Gura_ImplementDescendantCreator(wx_OwnerDrawnComboBox)
{
	return new Object_wx_OwnerDrawnComboBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
