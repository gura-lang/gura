//----------------------------------------------------------------------------
// wxMessageOutput
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMessageOutput
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMessageOutput
//----------------------------------------------------------------------------
Object_wx_MessageOutput::~Object_wx_MessageOutput()
{
}

Object *Object_wx_MessageOutput::Clone() const
{
	return nullptr;
}

String Object_wx_MessageOutput::ToString(bool exprFlag)
{
	String rtn("<wx.MessageOutput:");
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
Gura_DeclareMethodAlias(wx_MessageOutput, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MessageOutput, __Get)
{
	Object_wx_MessageOutput *pThis = Object_wx_MessageOutput::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MessageOutput, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msgout", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageOutput, __Set)
{
	Object_wx_MessageOutput *pThis = Object_wx_MessageOutput::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msgout = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MessageOutput, __Printf, "Printf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageOutput, __Printf)
{
	Object_wx_MessageOutput *pThis = Object_wx_MessageOutput::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->Printf();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MessageOutput, __Output, "Output")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageOutput, __Output)
{
	Object_wx_MessageOutput *pThis = Object_wx_MessageOutput::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->Output();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMessageOutput
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageOutput)
{
	// Class assignment
	Gura_AssignValueEx("MessageOutput", Reference());
	// Method assignment
	Gura_AssignMethod(wx_MessageOutput, __Get);
	Gura_AssignMethod(wx_MessageOutput, __Set);
	Gura_AssignMethod(wx_MessageOutput, __Printf);
	Gura_AssignMethod(wx_MessageOutput, __Output);
}

Gura_ImplementDescendantCreator(wx_MessageOutput)
{
	return new Object_wx_MessageOutput((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
