//----------------------------------------------------------------------------
// wxBitmapComboBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmapComboBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBitmapComboBox
//----------------------------------------------------------------------------
Object_wx_BitmapComboBox::~Object_wx_BitmapComboBox()
{
}

Object *Object_wx_BitmapComboBox::Clone() const
{
	return nullptr;
}

String Object_wx_BitmapComboBox::ToString(bool exprFlag)
{
	String rtn("<wx.BitmapComboBox:");
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
Gura_DeclareMethod(wx_BitmapComboBox, wxBitmapComboBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BitmapComboBox, wxBitmapComboBox)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxBitmapComboBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapComboBox, wxBitmapComboBox_1)
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

Gura_ImplementMethod(wx_BitmapComboBox, wxBitmapComboBox_1)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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
	//pThis->GetEntity()->wxBitmapComboBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapComboBox, wxBitmapComboBox_2)
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

Gura_ImplementMethod(wx_BitmapComboBox, wxBitmapComboBox_2)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int choices = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->wxBitmapComboBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapComboBox, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, Append)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapComboBox, Append_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, Append_1)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapComboBox, Append_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, Append_2)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapComboBox, Create)
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

Gura_ImplementMethod(wx_BitmapComboBox, Create)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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

Gura_DeclareMethod(wx_BitmapComboBox, Create_1)
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

Gura_ImplementMethod(wx_BitmapComboBox, Create_1)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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

Gura_DeclareMethod(wx_BitmapComboBox, GetBitmapSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BitmapComboBox, GetBitmapSize)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapComboBox, GetItemBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, GetItemBitmap)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapComboBox, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, Insert)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapComboBox, Insert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, Insert_1)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int clientData = arg.GetNumber(3)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapComboBox, Insert_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, Insert_2)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int clientData = arg.GetNumber(3)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapComboBox, SetItemBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, SetItemBitmap)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemBitmap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBitmapComboBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapComboBox)
{
	Gura_AssignMethod(wx_BitmapComboBox, wxBitmapComboBox);
	Gura_AssignMethod(wx_BitmapComboBox, wxBitmapComboBox_1);
	Gura_AssignMethod(wx_BitmapComboBox, wxBitmapComboBox_2);
	Gura_AssignMethod(wx_BitmapComboBox, Append);
	Gura_AssignMethod(wx_BitmapComboBox, Append_1);
	Gura_AssignMethod(wx_BitmapComboBox, Append_2);
	Gura_AssignMethod(wx_BitmapComboBox, Create);
	Gura_AssignMethod(wx_BitmapComboBox, Create_1);
	Gura_AssignMethod(wx_BitmapComboBox, GetBitmapSize);
	Gura_AssignMethod(wx_BitmapComboBox, GetItemBitmap);
	Gura_AssignMethod(wx_BitmapComboBox, Insert);
	Gura_AssignMethod(wx_BitmapComboBox, Insert_1);
	Gura_AssignMethod(wx_BitmapComboBox, Insert_2);
	Gura_AssignMethod(wx_BitmapComboBox, SetItemBitmap);
}

Gura_ImplementDescendantCreator(wx_BitmapComboBox)
{
	return new Object_wx_BitmapComboBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
