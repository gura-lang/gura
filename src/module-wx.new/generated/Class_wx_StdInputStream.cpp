//----------------------------------------------------------------------------
// wxStdInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStdInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStdInputStream
//----------------------------------------------------------------------------
Object_wx_StdInputStream::~Object_wx_StdInputStream()
{
}

Object *Object_wx_StdInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_StdInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.StdInputStream:");
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
Gura_DeclareMethodAlias(wx_StdInputStream, __wxStdInputStream, "wxStdInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdInputStream, __wxStdInputStream)
{
	Object_wx_StdInputStream *pThis = Object_wx_StdInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->wxStdInputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStdInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StdInputStream)
{
	Gura_AssignMethod(wx_StdInputStream, __wxStdInputStream);
}

Gura_ImplementDescendantCreator(wx_StdInputStream)
{
	return new Object_wx_StdInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
