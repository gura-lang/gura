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
Gura_DeclareMethod(wx_NumValidator, SetMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NumValidator, SetMin)
{
	Object_wx_NumValidator *pThis = Object_wx_NumValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//pThis->GetEntity()->SetMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NumValidator, SetMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NumValidator, SetMax)
{
	Object_wx_NumValidator *pThis = Object_wx_NumValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int max = arg.GetNumber(0)
	//pThis->GetEntity()->SetMax();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NumValidator, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NumValidator, SetRange)
{
	Object_wx_NumValidator *pThis = Object_wx_NumValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//int max = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NumValidator, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NumValidator, SetStyle)
{
	Object_wx_NumValidator *pThis = Object_wx_NumValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NumValidator, TransferToWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NumValidator, TransferToWindow)
{
	Object_wx_NumValidator *pThis = Object_wx_NumValidator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TransferToWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NumValidator, TransferFromWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NumValidator, TransferFromWindow)
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
	Gura_AssignMethod(wx_NumValidator, SetMin);
	Gura_AssignMethod(wx_NumValidator, SetMax);
	Gura_AssignMethod(wx_NumValidator, SetRange);
	Gura_AssignMethod(wx_NumValidator, SetStyle);
	Gura_AssignMethod(wx_NumValidator, TransferToWindow);
	Gura_AssignMethod(wx_NumValidator, TransferFromWindow);
}

Gura_ImplementDescendantCreator(wx_NumValidator)
{
	return new Object_wx_NumValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
