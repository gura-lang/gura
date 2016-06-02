//----------------------------------------------------------------------------
// wxPGVIterator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGVIterator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGVIterator
//----------------------------------------------------------------------------
Object_wx_PGVIterator::~Object_wx_PGVIterator()
{
}

Object *Object_wx_PGVIterator::Clone() const
{
	return nullptr;
}

String Object_wx_PGVIterator::ToString(bool exprFlag)
{
	String rtn("<wx.PGVIterator:");
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
Gura_DeclareMethod(wx_PGVIterator, wxPGVIterator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGVIterator, wxPGVIterator)
{
	Object_wx_PGVIterator *pThis = Object_wx_PGVIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPGVIterator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGVIterator, wxPGVIterator_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGVIterator, wxPGVIterator_1)
{
	Object_wx_PGVIterator *pThis = Object_wx_PGVIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->wxPGVIterator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGVIterator, UnRef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGVIterator, UnRef)
{
	Object_wx_PGVIterator *pThis = Object_wx_PGVIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UnRef();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGVIterator, wxPGVIterator_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGVIterator, wxPGVIterator_2)
{
	Object_wx_PGVIterator *pThis = Object_wx_PGVIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//pThis->GetEntity()->wxPGVIterator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGVIterator, Next)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGVIterator, Next)
{
	Object_wx_PGVIterator *pThis = Object_wx_PGVIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Next();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGVIterator, AtEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGVIterator, AtEnd)
{
	Object_wx_PGVIterator *pThis = Object_wx_PGVIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AtEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGVIterator, GetProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGVIterator, GetProperty)
{
	Object_wx_PGVIterator *pThis = Object_wx_PGVIterator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProperty();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPGVIterator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGVIterator)
{
	Gura_AssignMethod(wx_PGVIterator, wxPGVIterator);
	Gura_AssignMethod(wx_PGVIterator, wxPGVIterator_1);
	Gura_AssignMethod(wx_PGVIterator, UnRef);
	Gura_AssignMethod(wx_PGVIterator, wxPGVIterator_2);
	Gura_AssignMethod(wx_PGVIterator, Next);
	Gura_AssignMethod(wx_PGVIterator, AtEnd);
	Gura_AssignMethod(wx_PGVIterator, GetProperty);
}

Gura_ImplementDescendantCreator(wx_PGVIterator)
{
	return new Object_wx_PGVIterator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
