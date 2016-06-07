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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__BitmapComboBox, "BitmapComboBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_BitmapComboBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BitmapComboBox)
{
	//wxBitmapComboBox();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__BitmapComboBox_1, "BitmapComboBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg6", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BitmapComboBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BitmapComboBox_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//int n = arg.GetNumber(5)
	//const wxString choices[] _arg6 = arg.GetNumber(6)
	//long style = arg.GetNumber(7)
	//const wxValidator& validator = arg.GetNumber(8)
	//const wxString& name = arg.GetNumber(9)
	//wxBitmapComboBox(parent, id, value, pos, size, n, _arg6, style, validator, name);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__BitmapComboBox_2, "BitmapComboBox_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BitmapComboBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BitmapComboBox_2)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//const wxArrayString& choices = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//wxBitmapComboBox(parent, id, value, pos, size, choices, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_BitmapComboBox, __Append, "Append")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, __Append)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->Append(item, bitmap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BitmapComboBox, __Append_1, "Append_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, __Append_1)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//void* clientData = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->Append(item, bitmap, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BitmapComboBox, __Append_2, "Append_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, __Append_2)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//wxClientData* clientData = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->Append(item, bitmap, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BitmapComboBox, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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

Gura_ImplementMethod(wx_BitmapComboBox, __Create)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//int n = arg.GetNumber(5)
	//const wxString choices = arg.GetNumber(6)
	//long style = arg.GetNumber(7)
	//const wxValidator& validator = arg.GetNumber(8)
	//const wxString& name = arg.GetNumber(9)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, value, pos, size, n, choices, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BitmapComboBox, __Create_1, "Create_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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

Gura_ImplementMethod(wx_BitmapComboBox, __Create_1)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//const wxArrayString& choices = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, value, pos, size, choices, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BitmapComboBox, __GetBitmapSize, "GetBitmapSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_BitmapComboBox, __GetBitmapSize)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize _rtn = pThis->GetEntity()->GetBitmapSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BitmapComboBox, __GetItemBitmap, "GetItemBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, __GetItemBitmap)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//wxBitmap _rtn = pThis->GetEntity()->GetItemBitmap(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BitmapComboBox, __Insert, "Insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, __Insert)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//unsigned int pos = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->Insert(item, bitmap, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BitmapComboBox, __Insert_1, "Insert_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, __Insert_1)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//unsigned int pos = arg.GetNumber(2)
	//void* clientData = arg.GetNumber(3)
	//int _rtn = pThis->GetEntity()->Insert(item, bitmap, pos, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BitmapComboBox, __Insert_2, "Insert_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, __Insert_2)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//unsigned int pos = arg.GetNumber(2)
	//wxClientData* clientData = arg.GetNumber(3)
	//int _rtn = pThis->GetEntity()->Insert(item, bitmap, pos, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BitmapComboBox, __SetItemBitmap, "SetItemBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, __SetItemBitmap)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemBitmap(n, bitmap);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBitmapComboBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapComboBox)
{
	// Constructor assignment
	Gura_AssignFunction(__BitmapComboBox);
	Gura_AssignFunction(__BitmapComboBox_1);
	Gura_AssignFunction(__BitmapComboBox_2);
	// Method assignment
	Gura_AssignMethod(wx_BitmapComboBox, __Append);
	Gura_AssignMethod(wx_BitmapComboBox, __Append_1);
	Gura_AssignMethod(wx_BitmapComboBox, __Append_2);
	Gura_AssignMethod(wx_BitmapComboBox, __Create);
	Gura_AssignMethod(wx_BitmapComboBox, __Create_1);
	Gura_AssignMethod(wx_BitmapComboBox, __GetBitmapSize);
	Gura_AssignMethod(wx_BitmapComboBox, __GetItemBitmap);
	Gura_AssignMethod(wx_BitmapComboBox, __Insert);
	Gura_AssignMethod(wx_BitmapComboBox, __Insert_1);
	Gura_AssignMethod(wx_BitmapComboBox, __Insert_2);
	Gura_AssignMethod(wx_BitmapComboBox, __SetItemBitmap);
}

Gura_ImplementDescendantCreator(wx_BitmapComboBox)
{
	return new Object_wx_BitmapComboBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
