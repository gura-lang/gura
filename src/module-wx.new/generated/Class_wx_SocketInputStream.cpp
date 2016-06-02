//----------------------------------------------------------------------------
// wxSocketInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSocketInputStream
//----------------------------------------------------------------------------
Object_wx_SocketInputStream::~Object_wx_SocketInputStream()
{
}

Object *Object_wx_SocketInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_SocketInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.SocketInputStream:");
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
Gura_DeclareMethod(wx_SocketInputStream, wxSocketInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketInputStream, wxSocketInputStream)
{
	Object_wx_SocketInputStream *pThis = Object_wx_SocketInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->wxSocketInputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketInputStream)
{
	Gura_AssignMethod(wx_SocketInputStream, wxSocketInputStream);
}

Gura_ImplementDescendantCreator(wx_SocketInputStream)
{
	return new Object_wx_SocketInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
