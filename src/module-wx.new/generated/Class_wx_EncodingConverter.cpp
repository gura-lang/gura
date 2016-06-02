//----------------------------------------------------------------------------
// wxEncodingConverter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEncodingConverter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEncodingConverter
//----------------------------------------------------------------------------
Object_wx_EncodingConverter::~Object_wx_EncodingConverter()
{
}

Object *Object_wx_EncodingConverter::Clone() const
{
	return nullptr;
}

String Object_wx_EncodingConverter::ToString(bool exprFlag)
{
	String rtn("<wx.EncodingConverter:");
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
Gura_DeclareMethod(wx_EncodingConverter, wxEncodingConverter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EncodingConverter, wxEncodingConverter)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxEncodingConverter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, CanConvert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encIn", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encOut", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, CanConvert)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int encIn = arg.GetNumber(0)
	//int encOut = arg.GetNumber(1)
	//pThis->GetEntity()->CanConvert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, Convert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "output", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, Convert)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int input = arg.GetNumber(0)
	//int output = arg.GetNumber(1)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, Convert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "output", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, Convert_1)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int input = arg.GetNumber(0)
	//int output = arg.GetNumber(1)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, Convert_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "output", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, Convert_2)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int input = arg.GetNumber(0)
	//int output = arg.GetNumber(1)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, Convert_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "output", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, Convert_3)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int input = arg.GetNumber(0)
	//int output = arg.GetNumber(1)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, Convert_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, Convert_4)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, Convert_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, Convert_5)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, Convert_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, Convert_6)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int input = arg.GetNumber(0)
	//pThis->GetEntity()->Convert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, GetAllEquivalents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, GetAllEquivalents)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enc = arg.GetNumber(0)
	//pThis->GetEntity()->GetAllEquivalents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, GetPlatformEquivalents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "platform", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, GetPlatformEquivalents)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enc = arg.GetNumber(0)
	//int platform = arg.GetNumber(1)
	//pThis->GetEntity()->GetPlatformEquivalents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EncodingConverter, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "input_enc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "output_enc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "method", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, Init)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int input_enc = arg.GetNumber(0)
	//int output_enc = arg.GetNumber(1)
	//int method = arg.GetNumber(2)
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxEncodingConverter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EncodingConverter)
{
	Gura_AssignMethod(wx_EncodingConverter, wxEncodingConverter);
	Gura_AssignMethod(wx_EncodingConverter, CanConvert);
	Gura_AssignMethod(wx_EncodingConverter, Convert);
	Gura_AssignMethod(wx_EncodingConverter, Convert_1);
	Gura_AssignMethod(wx_EncodingConverter, Convert_2);
	Gura_AssignMethod(wx_EncodingConverter, Convert_3);
	Gura_AssignMethod(wx_EncodingConverter, Convert_4);
	Gura_AssignMethod(wx_EncodingConverter, Convert_5);
	Gura_AssignMethod(wx_EncodingConverter, Convert_6);
	Gura_AssignMethod(wx_EncodingConverter, GetAllEquivalents);
	Gura_AssignMethod(wx_EncodingConverter, GetPlatformEquivalents);
	Gura_AssignMethod(wx_EncodingConverter, Init);
}

Gura_ImplementDescendantCreator(wx_EncodingConverter)
{
	return new Object_wx_EncodingConverter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
