//----------------------------------------------------------------------------
// wxPropertyGridIterator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertyGridIterator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertyGridIterator
//----------------------------------------------------------------------------
Object_wx_PropertyGridIterator::~Object_wx_PropertyGridIterator()
{
}

Object *Object_wx_PropertyGridIterator::Clone() const
{
	return nullptr;
}

String Object_wx_PropertyGridIterator::ToString(bool exprFlag)
{
	String rtn("<wx.PropertyGridIterator:");
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
Gura_DeclareMethodAlias(wx_PropertyGridIterator, __Assign, "Assign")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridIterator, __Assign)
{
	Object_wx_PropertyGridIterator *pThis = Object_wx_PropertyGridIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridIterator, __AtEnd, "AtEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridIterator, __AtEnd)
{
	Object_wx_PropertyGridIterator *pThis = Object_wx_PropertyGridIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AtEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridIterator, __GetProperty, "GetProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridIterator, __GetProperty)
{
	Object_wx_PropertyGridIterator *pThis = Object_wx_PropertyGridIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProperty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridIterator, __Next, "Next")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iterateChildren", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridIterator, __Next)
{
	Object_wx_PropertyGridIterator *pThis = Object_wx_PropertyGridIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int iterateChildren = arg.GetNumber(0)
	//pThis->GetEntity()->Next();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridIterator, __Prev, "Prev")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridIterator, __Prev)
{
	Object_wx_PropertyGridIterator *pThis = Object_wx_PropertyGridIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Prev();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropertyGridIterator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGridIterator)
{
	Gura_AssignMethod(wx_PropertyGridIterator, __Assign);
	Gura_AssignMethod(wx_PropertyGridIterator, __AtEnd);
	Gura_AssignMethod(wx_PropertyGridIterator, __GetProperty);
	Gura_AssignMethod(wx_PropertyGridIterator, __Next);
	Gura_AssignMethod(wx_PropertyGridIterator, __Prev);
}

Gura_ImplementDescendantCreator(wx_PropertyGridIterator)
{
	return new Object_wx_PropertyGridIterator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
