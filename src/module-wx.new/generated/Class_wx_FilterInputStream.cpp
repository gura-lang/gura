//----------------------------------------------------------------------------
// wxFilterInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFilterInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFilterInputStream
//----------------------------------------------------------------------------
Object_wx_FilterInputStream::~Object_wx_FilterInputStream()
{
}

Object *Object_wx_FilterInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FilterInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FilterInputStream:");
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
Gura_DeclareFunctionAlias(__wxFilterInputStream, "wxFilterInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FilterInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFilterInputStream)
{
	//int stream = arg.GetNumber(0)
	//wxFilterInputStream();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxFilterInputStream_1, "wxFilterInputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FilterInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFilterInputStream_1)
{
	//int stream = arg.GetNumber(0)
	//wxFilterInputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFilterInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilterInputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__wxFilterInputStream);
	Gura_AssignFunction(__wxFilterInputStream_1);
}

Gura_ImplementDescendantCreator(wx_FilterInputStream)
{
	return new Object_wx_FilterInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
