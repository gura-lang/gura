//----------------------------------------------------------------------------
// wxSocketOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSocketOutputStream
//----------------------------------------------------------------------------
Object_wx_SocketOutputStream::~Object_wx_SocketOutputStream()
{
}

Object *Object_wx_SocketOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_SocketOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.SocketOutputStream:");
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
Gura_DeclareMethodAlias(wx_SocketOutputStream, __wxSocketOutputStream, "wxSocketOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketOutputStream, __wxSocketOutputStream)
{
	Object_wx_SocketOutputStream *pThis = Object_wx_SocketOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->wxSocketOutputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketOutputStream)
{
	Gura_AssignMethod(wx_SocketOutputStream, __wxSocketOutputStream);
}

Gura_ImplementDescendantCreator(wx_SocketOutputStream)
{
	return new Object_wx_SocketOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
