//----------------------------------------------------------------------------
// wxGridUpdateLocker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridUpdateLocker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridUpdateLocker
//----------------------------------------------------------------------------
Object_wx_GridUpdateLocker::~Object_wx_GridUpdateLocker()
{
}

Object *Object_wx_GridUpdateLocker::Clone() const
{
	return nullptr;
}

String Object_wx_GridUpdateLocker::ToString(bool exprFlag)
{
	String rtn("<wx.GridUpdateLocker:");
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
Gura_DeclareFunctionAlias(__GridUpdateLocker, "GridUpdateLocker")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GridUpdateLocker));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridUpdateLocker)
{
	//wxGrid* grid = arg.GetNumber(0)
	//wxGridUpdateLocker(grid);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridUpdateLocker, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridUpdateLocker, __Create)
{
	Object_wx_GridUpdateLocker *pThis = Object_wx_GridUpdateLocker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGrid* grid = arg.GetNumber(0)
	//pThis->GetEntity()->Create(grid);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridUpdateLocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridUpdateLocker)
{
	// Constructor assignment
	Gura_AssignFunction(__GridUpdateLocker);
	// Method assignment
	Gura_AssignMethod(wx_GridUpdateLocker, __Create);
}

Gura_ImplementDescendantCreator(wx_GridUpdateLocker)
{
	return new Object_wx_GridUpdateLocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
