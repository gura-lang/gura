//----------------------------------------------------------------------------
// wxTextAttrSize
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrSize
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrSize
//----------------------------------------------------------------------------
Object_wx_TextAttrSize::~Object_wx_TextAttrSize()
{
}

Object *Object_wx_TextAttrSize::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrSize::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrSize:");
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
Gura_DeclareMethodAlias(wx_TextAttrSize, __wxTextAttrSize, "wxTextAttrSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrSize, __wxTextAttrSize)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTextAttrSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrSize, __Reset)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __EqPartial, "EqPartial")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, __EqPartial)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __Apply, "Apply")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dims", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, __Apply)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dims = arg.GetNumber(0)
	//int compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __CollectCommonAttributes, "CollectCommonAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, __CollectCommonAttributes)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int clashingAttr = arg.GetNumber(1)
	//int absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __RemoveStyle, "RemoveStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, __RemoveStyle)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrSize, __GetWidth)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __GetWidth_1, "GetWidth_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrSize, __GetWidth_1)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __SetWidth, "SetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, __SetWidth)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __SetWidth_1, "SetWidth_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, __SetWidth_1)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __SetWidth_2, "SetWidth_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dim", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, __SetWidth_2)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dim = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __GetHeight, "GetHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrSize, __GetHeight)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __GetHeight_1, "GetHeight_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrSize, __GetHeight_1)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __SetHeight, "SetHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, __SetHeight)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __SetHeight_1, "SetHeight_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, __SetHeight_1)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//pThis->GetEntity()->SetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __SetHeight_2, "SetHeight_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dim", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrSize, __SetHeight_2)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dim = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrSize, __IsValid, "IsValid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrSize, __IsValid)
{
	Object_wx_TextAttrSize *pThis = Object_wx_TextAttrSize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextAttrSize
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrSize)
{
	Gura_AssignMethod(wx_TextAttrSize, __wxTextAttrSize);
	Gura_AssignMethod(wx_TextAttrSize, __Reset);
	Gura_AssignMethod(wx_TextAttrSize, __EqPartial);
	Gura_AssignMethod(wx_TextAttrSize, __Apply);
	Gura_AssignMethod(wx_TextAttrSize, __CollectCommonAttributes);
	Gura_AssignMethod(wx_TextAttrSize, __RemoveStyle);
	Gura_AssignMethod(wx_TextAttrSize, __GetWidth);
	Gura_AssignMethod(wx_TextAttrSize, __GetWidth_1);
	Gura_AssignMethod(wx_TextAttrSize, __SetWidth);
	Gura_AssignMethod(wx_TextAttrSize, __SetWidth_1);
	Gura_AssignMethod(wx_TextAttrSize, __SetWidth_2);
	Gura_AssignMethod(wx_TextAttrSize, __GetHeight);
	Gura_AssignMethod(wx_TextAttrSize, __GetHeight_1);
	Gura_AssignMethod(wx_TextAttrSize, __SetHeight);
	Gura_AssignMethod(wx_TextAttrSize, __SetHeight_1);
	Gura_AssignMethod(wx_TextAttrSize, __SetHeight_2);
	Gura_AssignMethod(wx_TextAttrSize, __IsValid);
}

Gura_ImplementDescendantCreator(wx_TextAttrSize)
{
	return new Object_wx_TextAttrSize((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
