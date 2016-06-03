//----------------------------------------------------------------------------
// wxStringInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStringInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStringInputStream
//----------------------------------------------------------------------------
Object_wx_StringInputStream::~Object_wx_StringInputStream()
{
}

Object *Object_wx_StringInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_StringInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.StringInputStream:");
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
Gura_DeclareMethodAlias(wx_StringInputStream, __wxStringInputStream, "wxStringInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StringInputStream, __wxStringInputStream)
{
	Object_wx_StringInputStream *pThis = Object_wx_StringInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->wxStringInputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStringInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringInputStream)
{
	Gura_AssignMethod(wx_StringInputStream, __wxStringInputStream);
}

Gura_ImplementDescendantCreator(wx_StringInputStream)
{
	return new Object_wx_StringInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
