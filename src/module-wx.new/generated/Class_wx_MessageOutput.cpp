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
Gura_DeclareMethod(wx_MessageOutput, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MessageOutput, Get)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageOutput *pThis = Object_wx_MessageOutput::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MessageOutput, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msgout", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageOutput, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageOutput *pThis = Object_wx_MessageOutput::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int msgout = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MessageOutput, Printf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageOutput, Printf)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageOutput *pThis = Object_wx_MessageOutput::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->Printf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MessageOutput, Output)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageOutput, Output)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageOutput *pThis = Object_wx_MessageOutput::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->Output();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMessageOutput
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageOutput)
{
	Gura_AssignMethod(wx_MessageOutput, Get);
	Gura_AssignMethod(wx_MessageOutput, Set);
	Gura_AssignMethod(wx_MessageOutput, Printf);
	Gura_AssignMethod(wx_MessageOutput, Output);
}

Gura_ImplementDescendantCreator(wx_MessageOutput)
{
	return new Object_wx_MessageOutput((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
