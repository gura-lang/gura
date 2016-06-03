//----------------------------------------------------------------------------
// wxIntegerValidator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIntegerValidator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIntegerValidator
//----------------------------------------------------------------------------
Object_wx_IntegerValidator::~Object_wx_IntegerValidator()
{
}

Object *Object_wx_IntegerValidator::Clone() const
{
	return nullptr;
}

String Object_wx_IntegerValidator::ToString(bool exprFlag)
{
	String rtn("<wx.IntegerValidator:");
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
Gura_DeclareFunctionAlias(__IntegerValidator, "IntegerValidator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_IntegerValidator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__IntegerValidator)
{
	//int value = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//wxIntegerValidator();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxIntegerValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IntegerValidator)
{
	// Constructor assignment
	Gura_AssignFunction(__IntegerValidator);
}

Gura_ImplementDescendantCreator(wx_IntegerValidator)
{
	return new Object_wx_IntegerValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
