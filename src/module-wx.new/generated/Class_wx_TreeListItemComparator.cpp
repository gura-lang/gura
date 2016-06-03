//----------------------------------------------------------------------------
// wxTreeListItemComparator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeListItemComparator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeListItemComparator
//----------------------------------------------------------------------------
Object_wx_TreeListItemComparator::~Object_wx_TreeListItemComparator()
{
}

Object *Object_wx_TreeListItemComparator::Clone() const
{
	return nullptr;
}

String Object_wx_TreeListItemComparator::ToString(bool exprFlag)
{
	String rtn("<wx.TreeListItemComparator:");
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
Gura_DeclareMethodAlias(wx_TreeListItemComparator, __wxTreeListItemComparator, "wxTreeListItemComparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListItemComparator, __wxTreeListItemComparator)
{
	Object_wx_TreeListItemComparator *pThis = Object_wx_TreeListItemComparator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTreeListItemComparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListItemComparator, __Compare, "Compare")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "treelist", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "second", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeListItemComparator, __Compare)
{
	Object_wx_TreeListItemComparator *pThis = Object_wx_TreeListItemComparator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int treelist = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//int first = arg.GetNumber(2)
	//int second = arg.GetNumber(3)
	//pThis->GetEntity()->Compare();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeListItemComparator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeListItemComparator)
{
	Gura_AssignMethod(wx_TreeListItemComparator, __wxTreeListItemComparator);
	Gura_AssignMethod(wx_TreeListItemComparator, __Compare);
}

Gura_ImplementDescendantCreator(wx_TreeListItemComparator)
{
	return new Object_wx_TreeListItemComparator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
