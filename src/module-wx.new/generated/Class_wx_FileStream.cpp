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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FileStream, "FileStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "iofileName", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileStream)
{
	//const wxString& iofileName = arg.GetNumber(0)
	//wxFileStream(iofileName);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileStream, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileStream, __IsOk)
{
	Object_wx_FileStream *pThis = Object_wx_FileStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileStream)
{
	// Constructor assignment
	Gura_AssignFunction(__FileStream);
	// Method assignment
	Gura_AssignMethod(wx_FileStream, __IsOk);
}

Gura_ImplementDescendantCreator(wx_FileStream)
{
	return new Object_wx_FileStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
