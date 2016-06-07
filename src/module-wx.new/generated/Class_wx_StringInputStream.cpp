//----------------------------------------------------------------------------
// wxStringInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStringInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStringInputStream
//----------------------------------------------------------------------------
Object_wx_StringInputStream::~Object_wx_StringInputStream()
{
}

Object *Object_wx_StringInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_StringInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.StringInputStream:");
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
Gura_DeclareFunctionAlias(__StringInputStream, "StringInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StringInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StringInputStream)
{
	//const wxString& s = arg.GetNumber(0)
	//wxStringInputStream(s);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStringInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringInputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__StringInputStream);
}

Gura_ImplementDescendantCreator(wx_StringInputStream)
{
	return new Object_wx_StringInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
