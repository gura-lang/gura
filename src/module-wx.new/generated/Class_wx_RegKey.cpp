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
Gura_DeclareFunctionAlias(__RegKey, "RegKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "viewMode", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RegKey));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RegKey)
{
	//WOW64ViewMode viewMode = arg.GetNumber(0)
	//wxRegKey(viewMode);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RegKey_1, "RegKey_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strKey", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "viewMode", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RegKey));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RegKey_1)
{
	//const wxString& strKey = arg.GetNumber(0)
	//WOW64ViewMode viewMode = arg.GetNumber(1)
	//wxRegKey(strKey, viewMode);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RegKey_2, "RegKey_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keyParent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "strKey", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "viewMode", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RegKey));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RegKey_2)
{
	//StdKey keyParent = arg.GetNumber(0)
	//const wxString& strKey = arg.GetNumber(1)
	//WOW64ViewMode viewMode = arg.GetNumber(2)
	//wxRegKey(keyParent, strKey, viewMode);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RegKey_3, "RegKey_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keyParent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "strKey", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RegKey));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RegKey_3)
{
	//const wxRegKey& keyParent = arg.GetNumber(0)
	//const wxString& strKey = arg.GetNumber(1)
	//wxRegKey(keyParent, strKey);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRegKey
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RegKey)
{
	// Constructor assignment
	Gura_AssignFunction(__RegKey);
	Gura_AssignFunction(__RegKey_1);
	Gura_AssignFunction(__RegKey_2);
	Gura_AssignFunction(__RegKey_3);
}

Gura_ImplementDescendantCreator(wx_RegKey)
{
	return new Object_wx_RegKey((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
