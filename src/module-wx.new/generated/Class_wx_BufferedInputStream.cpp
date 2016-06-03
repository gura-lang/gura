//----------------------------------------------------------------------------
// wxBufferedInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBufferedInputStream
//----------------------------------------------------------------------------
Object_wx_BufferedInputStream::~Object_wx_BufferedInputStream()
{
}

Object *Object_wx_BufferedInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_BufferedInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.BufferedInputStream:");
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
Gura_DeclareMethodAlias(wx_BufferedInputStream, __wxBufferedInputStream, "wxBufferedInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedInputStream, __wxBufferedInputStream)
{
	Object_wx_BufferedInputStream *pThis = Object_wx_BufferedInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//pThis->GetEntity()->wxBufferedInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BufferedInputStream, __wxBufferedInputStream_1, "wxBufferedInputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bufsize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedInputStream, __wxBufferedInputStream_1)
{
	Object_wx_BufferedInputStream *pThis = Object_wx_BufferedInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int bufsize = arg.GetNumber(1)
	//pThis->GetEntity()->wxBufferedInputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBufferedInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedInputStream)
{
	Gura_AssignMethod(wx_BufferedInputStream, __wxBufferedInputStream);
	Gura_AssignMethod(wx_BufferedInputStream, __wxBufferedInputStream_1);
}

Gura_ImplementDescendantCreator(wx_BufferedInputStream)
{
	return new Object_wx_BufferedInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
