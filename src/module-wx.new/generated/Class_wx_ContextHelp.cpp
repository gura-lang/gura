//----------------------------------------------------------------------------
// wxContextHelp
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxContextHelp
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxContextHelp
//----------------------------------------------------------------------------
Object_wx_ContextHelp::~Object_wx_ContextHelp()
{
}

Object *Object_wx_ContextHelp::Clone() const
{
	return nullptr;
}

String Object_wx_ContextHelp::ToString(bool exprFlag)
{
	String rtn("<wx.ContextHelp:");
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
Gura_DeclareMethodAlias(wx_ContextHelp, __wxContextHelp, "wxContextHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "doNow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ContextHelp, __wxContextHelp)
{
	Object_wx_ContextHelp *pThis = Object_wx_ContextHelp::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int doNow = arg.GetNumber(1)
	//pThis->GetEntity()->wxContextHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ContextHelp, __BeginContextHelp, "BeginContextHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ContextHelp, __BeginContextHelp)
{
	Object_wx_ContextHelp *pThis = Object_wx_ContextHelp::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->BeginContextHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ContextHelp, __EndContextHelp, "EndContextHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ContextHelp, __EndContextHelp)
{
	Object_wx_ContextHelp *pThis = Object_wx_ContextHelp::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndContextHelp();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxContextHelp
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ContextHelp)
{
	Gura_AssignMethod(wx_ContextHelp, __wxContextHelp);
	Gura_AssignMethod(wx_ContextHelp, __BeginContextHelp);
	Gura_AssignMethod(wx_ContextHelp, __EndContextHelp);
}

Gura_ImplementDescendantCreator(wx_ContextHelp)
{
	return new Object_wx_ContextHelp((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
