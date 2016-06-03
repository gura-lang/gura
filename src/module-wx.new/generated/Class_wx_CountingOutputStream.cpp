//----------------------------------------------------------------------------
// wxCountingOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCountingOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCountingOutputStream
//----------------------------------------------------------------------------
Object_wx_CountingOutputStream::~Object_wx_CountingOutputStream()
{
}

Object *Object_wx_CountingOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_CountingOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.CountingOutputStream:");
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
Gura_DeclareMethodAlias(wx_CountingOutputStream, __wxCountingOutputStream, "wxCountingOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CountingOutputStream, __wxCountingOutputStream)
{
	Object_wx_CountingOutputStream *pThis = Object_wx_CountingOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxCountingOutputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CountingOutputStream, __GetLength, "GetLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CountingOutputStream, __GetLength)
{
	Object_wx_CountingOutputStream *pThis = Object_wx_CountingOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLength();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCountingOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CountingOutputStream)
{
	Gura_AssignMethod(wx_CountingOutputStream, __wxCountingOutputStream);
	Gura_AssignMethod(wx_CountingOutputStream, __GetLength);
}

Gura_ImplementDescendantCreator(wx_CountingOutputStream)
{
	return new Object_wx_CountingOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
