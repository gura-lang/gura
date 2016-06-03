//----------------------------------------------------------------------------
// wxListView
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxListView
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxListView
//----------------------------------------------------------------------------
Object_wx_ListView::~Object_wx_ListView()
{
}

Object *Object_wx_ListView::Clone() const
{
	return nullptr;
}

String Object_wx_ListView::ToString(bool exprFlag)
{
	String rtn("<wx.ListView:");
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
Gura_DeclareFunctionAlias(__ListView, "ListView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ListView));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ListView)
{
	//wxListView();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ListView_1, "ListView_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ListView));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ListView_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID winid = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxValidator& validator = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//wxListView();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ListView, __ClearColumnImage, "ClearColumnImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, __ClearColumnImage)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->ClearColumnImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListView, __Focus, "Focus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, __Focus)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long index = arg.GetNumber(0)
	//pThis->GetEntity()->Focus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListView, __GetFirstSelected, "GetFirstSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListView, __GetFirstSelected)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirstSelected();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListView, __GetFocusedItem, "GetFocusedItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListView, __GetFocusedItem)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFocusedItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListView, __GetNextSelected, "GetNextSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, __GetNextSelected)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long item = arg.GetNumber(0)
	//pThis->GetEntity()->GetNextSelected();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListView, __IsSelected, "IsSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, __IsSelected)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long index = arg.GetNumber(0)
	//pThis->GetEntity()->IsSelected();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListView, __Select, "Select")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "on", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, __Select)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long n = arg.GetNumber(0)
	//bool on = arg.GetNumber(1)
	//pThis->GetEntity()->Select();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListView, __SetColumnImage, "SetColumnImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, __SetColumnImage)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int image = arg.GetNumber(1)
	//pThis->GetEntity()->SetColumnImage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxListView
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListView)
{
	// Constructor assignment
	Gura_AssignFunction(__ListView);
	Gura_AssignFunction(__ListView_1);
	// Method assignment
	Gura_AssignMethod(wx_ListView, __ClearColumnImage);
	Gura_AssignMethod(wx_ListView, __Focus);
	Gura_AssignMethod(wx_ListView, __GetFirstSelected);
	Gura_AssignMethod(wx_ListView, __GetFocusedItem);
	Gura_AssignMethod(wx_ListView, __GetNextSelected);
	Gura_AssignMethod(wx_ListView, __IsSelected);
	Gura_AssignMethod(wx_ListView, __Select);
	Gura_AssignMethod(wx_ListView, __SetColumnImage);
}

Gura_ImplementDescendantCreator(wx_ListView)
{
	return new Object_wx_ListView((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
