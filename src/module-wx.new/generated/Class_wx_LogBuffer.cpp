//----------------------------------------------------------------------------
// wxLogBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogBuffer
//----------------------------------------------------------------------------
Object_wx_LogBuffer::~Object_wx_LogBuffer()
{
}

Object *Object_wx_LogBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_LogBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.LogBuffer:");
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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__LogBuffer, "LogBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_LogBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__LogBuffer)
{
	//wxLogBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_LogBuffer, __Flush, "Flush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogBuffer, __Flush)
{
	Object_wx_LogBuffer *pThis = Object_wx_LogBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LogBuffer, __GetBuffer, "GetBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_LogBuffer, __GetBuffer)
{
	Object_wx_LogBuffer *pThis = Object_wx_LogBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLogBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogBuffer)
{
	// Constructor assignment
	Gura_AssignFunction(__LogBuffer);
	// Method assignment
	Gura_AssignMethod(wx_LogBuffer, __Flush);
	Gura_AssignMethod(wx_LogBuffer, __GetBuffer);
}

Gura_ImplementDescendantCreator(wx_LogBuffer)
{
	return new Object_wx_LogBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
