//----------------------------------------------------------------------------
// wxFilterOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFilterOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFilterOutputStream
//----------------------------------------------------------------------------
Object_wx_FilterOutputStream::~Object_wx_FilterOutputStream()
{
}

Object *Object_wx_FilterOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FilterOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FilterOutputStream:");
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
Gura_DeclareFunctionAlias(__wxFilterOutputStream, "wxFilterOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxFilterOutputStream)
{
	//int stream = arg.GetNumber(0)
	//wxFilterOutputStream();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxFilterOutputStream_1, "wxFilterOutputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxFilterOutputStream_1)
{
	//int stream = arg.GetNumber(0)
	//wxFilterOutputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFilterOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilterOutputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__wxFilterOutputStream);
	Gura_AssignFunction(__wxFilterOutputStream_1);
}

Gura_ImplementDescendantCreator(wx_FilterOutputStream)
{
	return new Object_wx_FilterOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
