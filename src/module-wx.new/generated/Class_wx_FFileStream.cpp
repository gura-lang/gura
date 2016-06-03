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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FFileStream, "FFileStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iofileName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FFileStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FFileStream)
{
	//const wxString& iofileName = arg.GetNumber(0)
	//const wxString& mode = arg.GetNumber(1)
	//wxFFileStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FFileStream, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFileStream, __IsOk)
{
	Object_wx_FFileStream *pThis = Object_wx_FFileStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFFileStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFileStream)
{
	// Constructor assignment
	Gura_AssignFunction(__FFileStream);
	// Method assignment
	Gura_AssignMethod(wx_FFileStream, __IsOk);
}

Gura_ImplementDescendantCreator(wx_FFileStream)
{
	return new Object_wx_FFileStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
