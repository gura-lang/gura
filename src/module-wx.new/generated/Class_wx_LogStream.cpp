//----------------------------------------------------------------------------
// wxLogStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogStream
//----------------------------------------------------------------------------
Object_wx_LogStream::~Object_wx_LogStream()
{
}

Object *Object_wx_LogStream::Clone() const
{
	return nullptr;
}

String Object_wx_LogStream::ToString(bool exprFlag)
{
	String rtn("<wx.LogStream:");
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
Gura_DeclareMethod(wx_LogStream, wxLogStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ostr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogStream, wxLogStream)
{
	Object_wx_LogStream *pThis = Object_wx_LogStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ostr = arg.GetNumber(0)
	//pThis->GetEntity()->wxLogStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLogStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogStream)
{
	Gura_AssignMethod(wx_LogStream, wxLogStream);
}

Gura_ImplementDescendantCreator(wx_LogStream)
{
	return new Object_wx_LogStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
