//----------------------------------------------------------------------------
// wxRegKey
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRegKey
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRegKey
//----------------------------------------------------------------------------
Object_wx_RegKey::~Object_wx_RegKey()
{
}

Object *Object_wx_RegKey::Clone() const
{
	return nullptr;
}

String Object_wx_RegKey::ToString(bool exprFlag)
{
	String rtn("<wx.RegKey:");
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
Gura_DeclareFunctionAlias(__wxRegKey, "wxRegKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "viewMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRegKey)
{
	//int viewMode = arg.GetNumber(0)
	//wxRegKey();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRegKey_1, "wxRegKey_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strKey", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "viewMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRegKey_1)
{
	//int strKey = arg.GetNumber(0)
	//int viewMode = arg.GetNumber(1)
	//wxRegKey();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRegKey_2, "wxRegKey_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keyParent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "strKey", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "viewMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRegKey_2)
{
	//int keyParent = arg.GetNumber(0)
	//int strKey = arg.GetNumber(1)
	//int viewMode = arg.GetNumber(2)
	//wxRegKey();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRegKey_3, "wxRegKey_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keyParent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "strKey", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRegKey_3)
{
	//int keyParent = arg.GetNumber(0)
	//int strKey = arg.GetNumber(1)
	//wxRegKey();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRegKey
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RegKey)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRegKey);
	Gura_AssignFunction(__wxRegKey_1);
	Gura_AssignFunction(__wxRegKey_2);
	Gura_AssignFunction(__wxRegKey_3);
}

Gura_ImplementDescendantCreator(wx_RegKey)
{
	return new Object_wx_RegKey((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
