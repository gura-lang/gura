//----------------------------------------------------------------------------
// wxMessageOutputStderr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMessageOutputStderr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMessageOutputStderr
//----------------------------------------------------------------------------
Object_wx_MessageOutputStderr::~Object_wx_MessageOutputStderr()
{
}

Object *Object_wx_MessageOutputStderr::Clone() const
{
	return nullptr;
}

String Object_wx_MessageOutputStderr::ToString(bool exprFlag)
{
	String rtn("<wx.MessageOutputStderr:");
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
Gura_DeclareMethodAlias(wx_MessageOutputStderr, __wxMessageOutputStderr, "wxMessageOutputStderr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageOutputStderr, __wxMessageOutputStderr)
{
	Object_wx_MessageOutputStderr *pThis = Object_wx_MessageOutputStderr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fp = arg.GetNumber(0)
	//pThis->GetEntity()->wxMessageOutputStderr();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMessageOutputStderr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageOutputStderr)
{
	Gura_AssignMethod(wx_MessageOutputStderr, __wxMessageOutputStderr);
}

Gura_ImplementDescendantCreator(wx_MessageOutputStderr)
{
	return new Object_wx_MessageOutputStderr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
