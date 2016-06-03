//----------------------------------------------------------------------------
// wxStdOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStdOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStdOutputStream
//----------------------------------------------------------------------------
Object_wx_StdOutputStream::~Object_wx_StdOutputStream()
{
}

Object *Object_wx_StdOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_StdOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.StdOutputStream:");
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
Gura_DeclareMethodAlias(wx_StdOutputStream, __wxStdOutputStream, "wxStdOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdOutputStream, __wxStdOutputStream)
{
	Object_wx_StdOutputStream *pThis = Object_wx_StdOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->wxStdOutputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStdOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StdOutputStream)
{
	Gura_AssignMethod(wx_StdOutputStream, __wxStdOutputStream);
}

Gura_ImplementDescendantCreator(wx_StdOutputStream)
{
	return new Object_wx_StdOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
