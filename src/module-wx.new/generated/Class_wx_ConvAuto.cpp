//----------------------------------------------------------------------------
// wxConvAuto
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxConvAuto
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxConvAuto
//----------------------------------------------------------------------------
Object_wx_ConvAuto::~Object_wx_ConvAuto()
{
}

Object *Object_wx_ConvAuto::Clone() const
{
	return nullptr;
}

String Object_wx_ConvAuto::ToString(bool exprFlag)
{
	String rtn("<wx.ConvAuto:");
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
Gura_DeclareMethodAlias(wx_ConvAuto, __wxConvAuto, "wxConvAuto")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConvAuto, __wxConvAuto)
{
	Object_wx_ConvAuto *pThis = Object_wx_ConvAuto::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enc = arg.GetNumber(0)
	//pThis->GetEntity()->wxConvAuto();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ConvAuto, __GetBOM, "GetBOM")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ConvAuto, __GetBOM)
{
	Object_wx_ConvAuto *pThis = Object_wx_ConvAuto::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBOM();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ConvAuto, __GetBOMChars, "GetBOMChars")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConvAuto, __GetBOMChars)
{
	Object_wx_ConvAuto *pThis = Object_wx_ConvAuto::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bom = arg.GetNumber(0)
	//int count = arg.GetNumber(1)
	//pThis->GetEntity()->GetBOMChars();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ConvAuto, __DisableFallbackEncoding, "DisableFallbackEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ConvAuto, __DisableFallbackEncoding)
{
	Object_wx_ConvAuto *pThis = Object_wx_ConvAuto::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisableFallbackEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ConvAuto, __GetFallbackEncoding, "GetFallbackEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ConvAuto, __GetFallbackEncoding)
{
	Object_wx_ConvAuto *pThis = Object_wx_ConvAuto::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFallbackEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ConvAuto, __SetFallbackEncoding, "SetFallbackEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConvAuto, __SetFallbackEncoding)
{
	Object_wx_ConvAuto *pThis = Object_wx_ConvAuto::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enc = arg.GetNumber(0)
	//pThis->GetEntity()->SetFallbackEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ConvAuto, __DetectBOM, "DetectBOM")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "srcLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConvAuto, __DetectBOM)
{
	Object_wx_ConvAuto *pThis = Object_wx_ConvAuto::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int src = arg.GetNumber(0)
	//int srcLen = arg.GetNumber(1)
	//pThis->GetEntity()->DetectBOM();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxConvAuto
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ConvAuto)
{
	Gura_AssignMethod(wx_ConvAuto, __wxConvAuto);
	Gura_AssignMethod(wx_ConvAuto, __GetBOM);
	Gura_AssignMethod(wx_ConvAuto, __GetBOMChars);
	Gura_AssignMethod(wx_ConvAuto, __DisableFallbackEncoding);
	Gura_AssignMethod(wx_ConvAuto, __GetFallbackEncoding);
	Gura_AssignMethod(wx_ConvAuto, __SetFallbackEncoding);
	Gura_AssignMethod(wx_ConvAuto, __DetectBOM);
}

Gura_ImplementDescendantCreator(wx_ConvAuto)
{
	return new Object_wx_ConvAuto((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
