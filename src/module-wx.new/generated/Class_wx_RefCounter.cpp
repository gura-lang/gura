//----------------------------------------------------------------------------
// wxRefCounter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRefCounter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRefCounter
//----------------------------------------------------------------------------
Object_wx_RefCounter::~Object_wx_RefCounter()
{
}

Object *Object_wx_RefCounter::Clone() const
{
	return nullptr;
}

String Object_wx_RefCounter::ToString(bool exprFlag)
{
	String rtn("<wx.RefCounter:");
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
Gura_DeclareMethod(wx_RefCounter, ~wxRefCounter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RefCounter, ~wxRefCounter)
{
	Signal &sig = env.GetSignal();
	Object_wx_RefCounter *pThis = Object_wx_RefCounter::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxRefCounter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RefCounter, wxRefCounter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RefCounter, wxRefCounter)
{
	Signal &sig = env.GetSignal();
	Object_wx_RefCounter *pThis = Object_wx_RefCounter::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRefCounter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RefCounter, DecRef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RefCounter, DecRef)
{
	Signal &sig = env.GetSignal();
	Object_wx_RefCounter *pThis = Object_wx_RefCounter::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DecRef();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RefCounter, GetRefCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RefCounter, GetRefCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RefCounter *pThis = Object_wx_RefCounter::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRefCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RefCounter, IncRef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RefCounter, IncRef)
{
	Signal &sig = env.GetSignal();
	Object_wx_RefCounter *pThis = Object_wx_RefCounter::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IncRef();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRefCounter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RefCounter)
{
	Gura_AssignMethod(wx_RefCounter, ~wxRefCounter);
	Gura_AssignMethod(wx_RefCounter, wxRefCounter);
	Gura_AssignMethod(wx_RefCounter, DecRef);
	Gura_AssignMethod(wx_RefCounter, GetRefCount);
	Gura_AssignMethod(wx_RefCounter, IncRef);
}

Gura_ImplementDescendantCreator(wx_RefCounter)
{
	return new Object_wx_RefCounter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
