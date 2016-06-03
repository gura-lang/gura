//----------------------------------------------------------------------------
// wxStreamBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStreamBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStreamBase
//----------------------------------------------------------------------------
Object_wx_StreamBase::~Object_wx_StreamBase()
{
}

Object *Object_wx_StreamBase::Clone() const
{
	return nullptr;
}

String Object_wx_StreamBase::ToString(bool exprFlag)
{
	String rtn("<wx.StreamBase:");
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
Gura_DeclareMethodAlias(wx_StreamBase, __wxStreamBase, "wxStreamBase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, __wxStreamBase)
{
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxStreamBase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StreamBase, __GetLastError, "GetLastError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, __GetLastError)
{
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastError();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StreamBase, __GetLength, "GetLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, __GetLength)
{
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StreamBase, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, __GetSize)
{
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StreamBase, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, __IsOk)
{
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StreamBase, __IsSeekable, "IsSeekable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, __IsSeekable)
{
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSeekable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StreamBase, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "error", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StreamBase, __Reset)
{
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int error = arg.GetNumber(0)
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StreamBase, __OnSysSeek, "OnSysSeek")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StreamBase, __OnSysSeek)
{
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->OnSysSeek();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StreamBase, __OnSysTell, "OnSysTell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, __OnSysTell)
{
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnSysTell();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStreamBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StreamBase)
{
	Gura_AssignMethod(wx_StreamBase, __wxStreamBase);
	Gura_AssignMethod(wx_StreamBase, __GetLastError);
	Gura_AssignMethod(wx_StreamBase, __GetLength);
	Gura_AssignMethod(wx_StreamBase, __GetSize);
	Gura_AssignMethod(wx_StreamBase, __IsOk);
	Gura_AssignMethod(wx_StreamBase, __IsSeekable);
	Gura_AssignMethod(wx_StreamBase, __Reset);
	Gura_AssignMethod(wx_StreamBase, __OnSysSeek);
	Gura_AssignMethod(wx_StreamBase, __OnSysTell);
}

Gura_ImplementDescendantCreator(wx_StreamBase)
{
	return new Object_wx_StreamBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
