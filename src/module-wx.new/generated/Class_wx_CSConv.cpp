//----------------------------------------------------------------------------
// wxCSConv
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCSConv
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCSConv
//----------------------------------------------------------------------------
Object_wx_CSConv::~Object_wx_CSConv()
{
}

Object *Object_wx_CSConv::Clone() const
{
	return nullptr;
}

String Object_wx_CSConv::ToString(bool exprFlag)
{
	String rtn("<wx.CSConv:");
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
Gura_DeclareMethodAlias(wx_CSConv, __wxCSConv, "wxCSConv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "charset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CSConv, __wxCSConv)
{
	Object_wx_CSConv *pThis = Object_wx_CSConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int charset = arg.GetNumber(0)
	//pThis->GetEntity()->wxCSConv();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CSConv, __wxCSConv_1, "wxCSConv_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CSConv, __wxCSConv_1)
{
	Object_wx_CSConv *pThis = Object_wx_CSConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//pThis->GetEntity()->wxCSConv();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CSConv, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CSConv, __IsOk)
{
	Object_wx_CSConv *pThis = Object_wx_CSConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCSConv
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CSConv)
{
	Gura_AssignMethod(wx_CSConv, __wxCSConv);
	Gura_AssignMethod(wx_CSConv, __wxCSConv_1);
	Gura_AssignMethod(wx_CSConv, __IsOk);
}

Gura_ImplementDescendantCreator(wx_CSConv)
{
	return new Object_wx_CSConv((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
