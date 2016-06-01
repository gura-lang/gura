//----------------------------------------------------------------------------
// wxFFileStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFFileStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFFileStream
//----------------------------------------------------------------------------
Object_wx_FFileStream::~Object_wx_FFileStream()
{
}

Object *Object_wx_FFileStream::Clone() const
{
	return nullptr;
}

String Object_wx_FFileStream::ToString(bool exprFlag)
{
	String rtn("<wx.FFileStream:");
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
Gura_DeclareMethod(wx_FFileStream, wxFFileStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iofileName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFileStream, wxFFileStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_FFileStream *pThis = Object_wx_FFileStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int iofileName = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->wxFFileStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFileStream, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFileStream, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_FFileStream *pThis = Object_wx_FFileStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFFileStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFileStream)
{
	Gura_AssignMethod(wx_FFileStream, wxFFileStream);
	Gura_AssignMethod(wx_FFileStream, IsOk);
}

Gura_ImplementDescendantCreator(wx_FFileStream)
{
	return new Object_wx_FFileStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
