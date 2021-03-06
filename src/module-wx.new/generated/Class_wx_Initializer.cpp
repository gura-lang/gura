//----------------------------------------------------------------------------
// wxInitializer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxInitializer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxInitializer
//----------------------------------------------------------------------------
Object_wx_Initializer::~Object_wx_Initializer()
{
}

Object *Object_wx_Initializer::Clone() const
{
	return nullptr;
}

String Object_wx_Initializer::ToString(bool exprFlag)
{
	String rtn("<wx.Initializer:");
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
Gura_DeclareFunctionAlias(__Initializer, "Initializer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Initializer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Initializer)
{
	//int argc = arg.GetNumber(0)
	//wxChar** argv = arg.GetNumber(1)
	//wxInitializer(argc, argv);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Initializer, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Initializer, __IsOk)
{
	Object_wx_Initializer *pThis = Object_wx_Initializer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxInitializer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Initializer)
{
	// Constructor assignment
	Gura_AssignFunction(__Initializer);
	// Method assignment
	Gura_AssignMethod(wx_Initializer, __IsOk);
}

Gura_ImplementDescendantCreator(wx_Initializer)
{
	return new Object_wx_Initializer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
