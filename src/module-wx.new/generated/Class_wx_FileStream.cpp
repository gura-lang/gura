//----------------------------------------------------------------------------
// wxFileStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileStream
//----------------------------------------------------------------------------
Object_wx_FileStream::~Object_wx_FileStream()
{
}

Object *Object_wx_FileStream::Clone() const
{
	return nullptr;
}

String Object_wx_FileStream::ToString(bool exprFlag)
{
	String rtn("<wx.FileStream:");
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
Gura_DeclareMethodAlias(wx_FileStream, __wxFileStream, "wxFileStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iofileName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileStream, __wxFileStream)
{
	Object_wx_FileStream *pThis = Object_wx_FileStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int iofileName = arg.GetNumber(0)
	//pThis->GetEntity()->wxFileStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileStream, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileStream, __IsOk)
{
	Object_wx_FileStream *pThis = Object_wx_FileStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileStream)
{
	Gura_AssignMethod(wx_FileStream, __wxFileStream);
	Gura_AssignMethod(wx_FileStream, __IsOk);
}

Gura_ImplementDescendantCreator(wx_FileStream)
{
	return new Object_wx_FileStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
