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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RegKey, __wxRegKey, "wxRegKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "viewMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegKey, __wxRegKey)
{
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int viewMode = arg.GetNumber(0)
	//pThis->GetEntity()->wxRegKey();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegKey, __wxRegKey_1, "wxRegKey_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strKey", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "viewMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegKey, __wxRegKey_1)
{
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strKey = arg.GetNumber(0)
	//int viewMode = arg.GetNumber(1)
	//pThis->GetEntity()->wxRegKey();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegKey, __wxRegKey_2, "wxRegKey_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keyParent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "strKey", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "viewMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegKey, __wxRegKey_2)
{
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int keyParent = arg.GetNumber(0)
	//int strKey = arg.GetNumber(1)
	//int viewMode = arg.GetNumber(2)
	//pThis->GetEntity()->wxRegKey();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegKey, __wxRegKey_3, "wxRegKey_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keyParent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "strKey", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegKey, __wxRegKey_3)
{
	Object_wx_RegKey *pThis = Object_wx_RegKey::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int keyParent = arg.GetNumber(0)
	//int strKey = arg.GetNumber(1)
	//pThis->GetEntity()->wxRegKey();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRegKey
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RegKey)
{
	Gura_AssignMethod(wx_RegKey, __wxRegKey);
	Gura_AssignMethod(wx_RegKey, __wxRegKey_1);
	Gura_AssignMethod(wx_RegKey, __wxRegKey_2);
	Gura_AssignMethod(wx_RegKey, __wxRegKey_3);
}

Gura_ImplementDescendantCreator(wx_RegKey)
{
	return new Object_wx_RegKey((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
