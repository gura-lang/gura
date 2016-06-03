//----------------------------------------------------------------------------
// wxWrapperInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWrapperInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWrapperInputStream
//----------------------------------------------------------------------------
Object_wx_WrapperInputStream::~Object_wx_WrapperInputStream()
{
}

Object *Object_wx_WrapperInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_WrapperInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.WrapperInputStream:");
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
Gura_DeclareMethodAlias(wx_WrapperInputStream, __wxWrapperInputStream, "wxWrapperInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WrapperInputStream, __wxWrapperInputStream)
{
	Object_wx_WrapperInputStream *pThis = Object_wx_WrapperInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->wxWrapperInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WrapperInputStream, __wxWrapperInputStream_1, "wxWrapperInputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WrapperInputStream, __wxWrapperInputStream_1)
{
	Object_wx_WrapperInputStream *pThis = Object_wx_WrapperInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->wxWrapperInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WrapperInputStream, __wxWrapperInputStream_2, "wxWrapperInputStream_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WrapperInputStream, __wxWrapperInputStream_2)
{
	Object_wx_WrapperInputStream *pThis = Object_wx_WrapperInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxWrapperInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WrapperInputStream, __InitParentStream, "InitParentStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WrapperInputStream, __InitParentStream)
{
	Object_wx_WrapperInputStream *pThis = Object_wx_WrapperInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->InitParentStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WrapperInputStream, __InitParentStream_1, "InitParentStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WrapperInputStream, __InitParentStream_1)
{
	Object_wx_WrapperInputStream *pThis = Object_wx_WrapperInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->InitParentStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWrapperInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WrapperInputStream)
{
	Gura_AssignMethod(wx_WrapperInputStream, __wxWrapperInputStream);
	Gura_AssignMethod(wx_WrapperInputStream, __wxWrapperInputStream_1);
	Gura_AssignMethod(wx_WrapperInputStream, __wxWrapperInputStream_2);
	Gura_AssignMethod(wx_WrapperInputStream, __InitParentStream);
	Gura_AssignMethod(wx_WrapperInputStream, __InitParentStream_1);
}

Gura_ImplementDescendantCreator(wx_WrapperInputStream)
{
	return new Object_wx_WrapperInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
