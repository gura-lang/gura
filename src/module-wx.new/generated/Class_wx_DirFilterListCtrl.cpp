//----------------------------------------------------------------------------
// wxDirFilterListCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDirFilterListCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDirFilterListCtrl
//----------------------------------------------------------------------------
Object_wx_DirFilterListCtrl::~Object_wx_DirFilterListCtrl()
{
}

Object *Object_wx_DirFilterListCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_DirFilterListCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.DirFilterListCtrl:");
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
Gura_DeclareMethodAlias(wx_DirFilterListCtrl, __wxDirFilterListCtrl, "wxDirFilterListCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DirFilterListCtrl, __wxDirFilterListCtrl)
{
	Object_wx_DirFilterListCtrl *pThis = Object_wx_DirFilterListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxDirFilterListCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirFilterListCtrl, __wxDirFilterListCtrl_1, "wxDirFilterListCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirFilterListCtrl, __wxDirFilterListCtrl_1)
{
	Object_wx_DirFilterListCtrl *pThis = Object_wx_DirFilterListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->wxDirFilterListCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirFilterListCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirFilterListCtrl, __Create)
{
	Object_wx_DirFilterListCtrl *pThis = Object_wx_DirFilterListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirFilterListCtrl, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DirFilterListCtrl, __Init)
{
	Object_wx_DirFilterListCtrl *pThis = Object_wx_DirFilterListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirFilterListCtrl, __FillFilterList, "FillFilterList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultFilter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirFilterListCtrl, __FillFilterList)
{
	Object_wx_DirFilterListCtrl *pThis = Object_wx_DirFilterListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filter = arg.GetNumber(0)
	//int defaultFilter = arg.GetNumber(1)
	//pThis->GetEntity()->FillFilterList();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDirFilterListCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DirFilterListCtrl)
{
	Gura_AssignMethod(wx_DirFilterListCtrl, __wxDirFilterListCtrl);
	Gura_AssignMethod(wx_DirFilterListCtrl, __wxDirFilterListCtrl_1);
	Gura_AssignMethod(wx_DirFilterListCtrl, __Create);
	Gura_AssignMethod(wx_DirFilterListCtrl, __Init);
	Gura_AssignMethod(wx_DirFilterListCtrl, __FillFilterList);
}

Gura_ImplementDescendantCreator(wx_DirFilterListCtrl)
{
	return new Object_wx_DirFilterListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
