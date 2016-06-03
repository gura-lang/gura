//----------------------------------------------------------------------------
// wxStdOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStdOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStdOutputStream
//----------------------------------------------------------------------------
Object_wx_StdOutputStream::~Object_wx_StdOutputStream()
{
}

Object *Object_wx_StdOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_StdOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.StdOutputStream:");
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
Gura_DeclareFunctionAlias(__wxStdOutputStream, "wxStdOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StdOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxStdOutputStream)
{
	//int stream = arg.GetNumber(0)
	//wxStdOutputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStdOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StdOutputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__wxStdOutputStream);
}

Gura_ImplementDescendantCreator(wx_StdOutputStream)
{
	return new Object_wx_StdOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
