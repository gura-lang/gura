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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__EncodingConverter, "EncodingConverter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_EncodingConverter));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__EncodingConverter)
{
	//wxEncodingConverter();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_EncodingConverter, __CanConvert, "CanConvert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "encIn", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encOut", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, __CanConvert)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding encIn = arg.GetNumber(0)
	//wxFontEncoding encOut = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->CanConvert(encIn, encOut);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EncodingConverter, __Convert, "Convert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "output", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, __Convert)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* input = arg.GetNumber(0)
	//char* output = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Convert(input, output);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EncodingConverter, __Convert_1, "Convert_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "output", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, __Convert_1)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* input = arg.GetNumber(0)
	//wchar_t* output = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Convert(input, output);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EncodingConverter, __Convert_2, "Convert_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "output", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, __Convert_2)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* input = arg.GetNumber(0)
	//wchar_t* output = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Convert(input, output);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EncodingConverter, __Convert_3, "Convert_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "output", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, __Convert_3)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* input = arg.GetNumber(0)
	//char* output = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Convert(input, output);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EncodingConverter, __Convert_4, "Convert_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, __Convert_4)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//char* str = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Convert(str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EncodingConverter, __Convert_5, "Convert_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, __Convert_5)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wchar_t* str = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Convert(str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EncodingConverter, __Convert_6, "Convert_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, __Convert_6)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& input = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->Convert(input);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EncodingConverter, __GetAllEquivalents, "GetAllEquivalents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "enc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, __GetAllEquivalents)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding enc = arg.GetNumber(0)
	//wxFontEncodingArray _rtn = pThis->GetEntity()->GetAllEquivalents(enc);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EncodingConverter, __GetPlatformEquivalents, "GetPlatformEquivalents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "enc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "platform", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, __GetPlatformEquivalents)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding enc = arg.GetNumber(0)
	//int platform = arg.GetNumber(1)
	//wxFontEncodingArray _rtn = pThis->GetEntity()->GetPlatformEquivalents(enc, platform);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EncodingConverter, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "input_enc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "output_enc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "method", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EncodingConverter, __Init)
{
	Object_wx_EncodingConverter *pThis = Object_wx_EncodingConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding input_enc = arg.GetNumber(0)
	//wxFontEncoding output_enc = arg.GetNumber(1)
	//int method = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->Init(input_enc, output_enc, method);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxEncodingConverter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EncodingConverter)
{
	// Constructor assignment
	Gura_AssignFunction(__EncodingConverter);
	// Method assignment
	Gura_AssignMethod(wx_EncodingConverter, __CanConvert);
	Gura_AssignMethod(wx_EncodingConverter, __Convert);
	Gura_AssignMethod(wx_EncodingConverter, __Convert_1);
	Gura_AssignMethod(wx_EncodingConverter, __Convert_2);
	Gura_AssignMethod(wx_EncodingConverter, __Convert_3);
	Gura_AssignMethod(wx_EncodingConverter, __Convert_4);
	Gura_AssignMethod(wx_EncodingConverter, __Convert_5);
	Gura_AssignMethod(wx_EncodingConverter, __Convert_6);
	Gura_AssignMethod(wx_EncodingConverter, __GetAllEquivalents);
	Gura_AssignMethod(wx_EncodingConverter, __GetPlatformEquivalents);
	Gura_AssignMethod(wx_EncodingConverter, __Init);
}

Gura_ImplementDescendantCreator(wx_EncodingConverter)
{
	return new Object_wx_EncodingConverter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
