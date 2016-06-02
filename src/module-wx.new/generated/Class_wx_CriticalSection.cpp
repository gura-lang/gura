//----------------------------------------------------------------------------
// wxCriticalSection
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCriticalSection
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCriticalSection
//----------------------------------------------------------------------------
Object_wx_CriticalSection::~Object_wx_CriticalSection()
{
}

Object *Object_wx_CriticalSection::Clone() const
{
	return nullptr;
}

String Object_wx_CriticalSection::ToString(bool exprFlag)
{
	String rtn("<wx.CriticalSection:");
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
Gura_DeclareMethod(wx_CriticalSection, wxCriticalSection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "critSecType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CriticalSection, wxCriticalSection)
{
	Object_wx_CriticalSection *pThis = Object_wx_CriticalSection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int critSecType = arg.GetNumber(0)
	//pThis->GetEntity()->wxCriticalSection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CriticalSection, Enter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CriticalSection, Enter)
{
	Object_wx_CriticalSection *pThis = Object_wx_CriticalSection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Enter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CriticalSection, TryEnter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CriticalSection, TryEnter)
{
	Object_wx_CriticalSection *pThis = Object_wx_CriticalSection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TryEnter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CriticalSection, Leave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CriticalSection, Leave)
{
	Object_wx_CriticalSection *pThis = Object_wx_CriticalSection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Leave();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCriticalSection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CriticalSection)
{
	Gura_AssignMethod(wx_CriticalSection, wxCriticalSection);
	Gura_AssignMethod(wx_CriticalSection, Enter);
	Gura_AssignMethod(wx_CriticalSection, TryEnter);
	Gura_AssignMethod(wx_CriticalSection, Leave);
}

Gura_ImplementDescendantCreator(wx_CriticalSection)
{
	return new Object_wx_CriticalSection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
