//----------------------------------------------------------------------------
// wxNumValidator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNumValidator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNumValidator
//----------------------------------------------------------------------------
Object_wx_NumValidator::~Object_wx_NumValidator()
{
}

Object *Object_wx_NumValidator::Clone() const
{
	return nullptr;
}

String Object_wx_NumValidator::ToString(bool exprFlag)
{
	String rtn("<wx.NumValidator:");
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
Gura_DeclareMethodAlias(wx_NumValidator, __SetMin, "SetMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NumValidator, __SetMin)
{
	Object_wx_NumValidator *pThis = Object_wx_NumValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//pThis->GetEntity()->SetMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NumValidator, __SetMax, "SetMax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NumValidator, __SetMax)
{
	Object_wx_NumValidator *pThis = Object_wx_NumValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int max = arg.GetNumber(0)
	//pThis->GetEntity()->SetMax();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NumValidator, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NumValidator, __SetRange)
{
	Object_wx_NumValidator *pThis = Object_wx_NumValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//int max = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NumValidator, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NumValidator, __SetStyle)
{
	Object_wx_NumValidator *pThis = Object_wx_NumValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NumValidator, __TransferToWindow, "TransferToWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NumValidator, __TransferToWindow)
{
	Object_wx_NumValidator *pThis = Object_wx_NumValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TransferToWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NumValidator, __TransferFromWindow, "TransferFromWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NumValidator, __TransferFromWindow)
{
	Object_wx_NumValidator *pThis = Object_wx_NumValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TransferFromWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxNumValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NumValidator)
{
	// Method assignment
	Gura_AssignMethod(wx_NumValidator, __SetMin);
	Gura_AssignMethod(wx_NumValidator, __SetMax);
	Gura_AssignMethod(wx_NumValidator, __SetRange);
	Gura_AssignMethod(wx_NumValidator, __SetStyle);
	Gura_AssignMethod(wx_NumValidator, __TransferToWindow);
	Gura_AssignMethod(wx_NumValidator, __TransferFromWindow);
}

Gura_ImplementDescendantCreator(wx_NumValidator)
{
	return new Object_wx_NumValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
