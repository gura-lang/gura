//----------------------------------------------------------------------------
// wxStringBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStringBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStringBuffer
//----------------------------------------------------------------------------
Object_wx_StringBuffer::~Object_wx_StringBuffer()
{
}

Object *Object_wx_StringBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_StringBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.StringBuffer:");
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
Gura_DeclareFunctionAlias(__StringBuffer, "StringBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StringBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StringBuffer)
{
	//const wxString& str = arg.GetNumber(0)
	//size_t len = arg.GetNumber(1)
	//wxStringBuffer(str, len);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStringBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringBuffer)
{
	// Constructor assignment
	Gura_AssignFunction(__StringBuffer);
}

Gura_ImplementDescendantCreator(wx_StringBuffer)
{
	return new Object_wx_StringBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
