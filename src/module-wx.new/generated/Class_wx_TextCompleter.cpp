//----------------------------------------------------------------------------
// wxTextCompleter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextCompleter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextCompleter
//----------------------------------------------------------------------------
Object_wx_TextCompleter::~Object_wx_TextCompleter()
{
}

Object *Object_wx_TextCompleter::Clone() const
{
	return nullptr;
}

String Object_wx_TextCompleter::ToString(bool exprFlag)
{
	String rtn("<wx.TextCompleter:");
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
Gura_DeclareMethodAlias(wx_TextCompleter, __Start, "Start")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCompleter, __Start)
{
	Object_wx_TextCompleter *pThis = Object_wx_TextCompleter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//pThis->GetEntity()->Start();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCompleter, __GetNext, "GetNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCompleter, __GetNext)
{
	Object_wx_TextCompleter *pThis = Object_wx_TextCompleter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNext();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextCompleter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextCompleter)
{
	// Method assignment
	Gura_AssignMethod(wx_TextCompleter, __Start);
	Gura_AssignMethod(wx_TextCompleter, __GetNext);
}

Gura_ImplementDescendantCreator(wx_TextCompleter)
{
	return new Object_wx_TextCompleter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
