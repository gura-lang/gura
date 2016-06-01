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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ListView, wxListView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListView, wxListView)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxListView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListView, wxListView_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, wxListView_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxListView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListView, ~wxListView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListView, ~wxListView)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxListView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListView, ClearColumnImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, ClearColumnImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->ClearColumnImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListView, Focus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, Focus)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->Focus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListView, GetFirstSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListView, GetFirstSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFirstSelected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListView, GetFocusedItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListView, GetFocusedItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFocusedItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListView, GetNextSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, GetNextSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetNextSelected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListView, IsSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, IsSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->IsSelected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListView, Select)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "on", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, Select)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int on = arg.GetNumber(1)
	//pThis->GetEntity()->Select();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListView, SetColumnImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, SetColumnImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_ListView, wxListView);
	Gura_AssignMethod(wx_ListView, wxListView_1);
	Gura_AssignMethod(wx_ListView, ~wxListView);
	Gura_AssignMethod(wx_ListView, ClearColumnImage);
	Gura_AssignMethod(wx_ListView, Focus);
	Gura_AssignMethod(wx_ListView, GetFirstSelected);
	Gura_AssignMethod(wx_ListView, GetFocusedItem);
	Gura_AssignMethod(wx_ListView, GetNextSelected);
	Gura_AssignMethod(wx_ListView, IsSelected);
	Gura_AssignMethod(wx_ListView, Select);
	Gura_AssignMethod(wx_ListView, SetColumnImage);
}

Gura_ImplementDescendantCreator(wx_ListView)
{
	return new Object_wx_ListView((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
