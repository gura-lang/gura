//----------------------------------------------------------------------------
// wxNativeFontInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNativeFontInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNativeFontInfo
//----------------------------------------------------------------------------
Object_wx_NativeFontInfo::~Object_wx_NativeFontInfo()
{
}

Object *Object_wx_NativeFontInfo::Clone() const
{
	return nullptr;
}

String Object_wx_NativeFontInfo::ToString(bool exprFlag)
{
	String rtn("<wx.NativeFontInfo:");
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
Gura_DeclareFunctionAlias(__NativeFontInfo, "NativeFontInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_NativeFontInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__NativeFontInfo)
{
	//wxNativeFontInfo();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__NativeFontInfo_1, "NativeFontInfo_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_NativeFontInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__NativeFontInfo_1)
{
	//const wxNativeFontInfo& info = arg.GetNumber(0)
	//wxNativeFontInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_NativeFontInfo, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, __Init)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __InitFromFont, "InitFromFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, __InitFromFont)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->InitFromFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __GetPointSize, "GetPointSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, __GetPointSize)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPointSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __GetPixelSize, "GetPixelSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, __GetPixelSize)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPixelSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, __GetStyle)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __GetWeight, "GetWeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, __GetWeight)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __GetUnderlined, "GetUnderlined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, __GetUnderlined)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUnderlined();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __GetFaceName, "GetFaceName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, __GetFaceName)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFaceName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __GetFamily, "GetFamily")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, __GetFamily)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFamily();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __GetEncoding, "GetEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, __GetEncoding)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __SetPointSize, "SetPointSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointsize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, __SetPointSize)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pointsize = arg.GetNumber(0)
	//pThis->GetEntity()->SetPointSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __SetPixelSize, "SetPixelSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, __SetPixelSize)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& pixelSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetPixelSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, __SetStyle)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontStyle style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __SetWeight, "SetWeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, __SetWeight)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontWeight weight = arg.GetNumber(0)
	//pThis->GetEntity()->SetWeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __SetUnderlined, "SetUnderlined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "underlined", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, __SetUnderlined)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool underlined = arg.GetNumber(0)
	//pThis->GetEntity()->SetUnderlined();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __SetFaceName, "SetFaceName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, __SetFaceName)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& facename = arg.GetNumber(0)
	//pThis->GetEntity()->SetFaceName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __SetFamily, "SetFamily")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, __SetFamily)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontFamily family = arg.GetNumber(0)
	//pThis->GetEntity()->SetFamily();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __SetEncoding, "SetEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, __SetEncoding)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding encoding = arg.GetNumber(0)
	//pThis->GetEntity()->SetEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __SetFaceName_1, "SetFaceName_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "facenames", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, __SetFaceName_1)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& facenames = arg.GetNumber(0)
	//pThis->GetEntity()->SetFaceName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __FromString, "FromString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, __FromString)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& s = arg.GetNumber(0)
	//pThis->GetEntity()->FromString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __ToString, "ToString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, __ToString)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __FromUserString, "FromUserString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, __FromUserString)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& s = arg.GetNumber(0)
	//pThis->GetEntity()->FromUserString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NativeFontInfo, __ToUserString, "ToUserString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, __ToUserString)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToUserString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxNativeFontInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NativeFontInfo)
{
	// Constructor assignment
	Gura_AssignFunction(__NativeFontInfo);
	Gura_AssignFunction(__NativeFontInfo_1);
	// Method assignment
	Gura_AssignMethod(wx_NativeFontInfo, __Init);
	Gura_AssignMethod(wx_NativeFontInfo, __InitFromFont);
	Gura_AssignMethod(wx_NativeFontInfo, __GetPointSize);
	Gura_AssignMethod(wx_NativeFontInfo, __GetPixelSize);
	Gura_AssignMethod(wx_NativeFontInfo, __GetStyle);
	Gura_AssignMethod(wx_NativeFontInfo, __GetWeight);
	Gura_AssignMethod(wx_NativeFontInfo, __GetUnderlined);
	Gura_AssignMethod(wx_NativeFontInfo, __GetFaceName);
	Gura_AssignMethod(wx_NativeFontInfo, __GetFamily);
	Gura_AssignMethod(wx_NativeFontInfo, __GetEncoding);
	Gura_AssignMethod(wx_NativeFontInfo, __SetPointSize);
	Gura_AssignMethod(wx_NativeFontInfo, __SetPixelSize);
	Gura_AssignMethod(wx_NativeFontInfo, __SetStyle);
	Gura_AssignMethod(wx_NativeFontInfo, __SetWeight);
	Gura_AssignMethod(wx_NativeFontInfo, __SetUnderlined);
	Gura_AssignMethod(wx_NativeFontInfo, __SetFaceName);
	Gura_AssignMethod(wx_NativeFontInfo, __SetFamily);
	Gura_AssignMethod(wx_NativeFontInfo, __SetEncoding);
	Gura_AssignMethod(wx_NativeFontInfo, __SetFaceName_1);
	Gura_AssignMethod(wx_NativeFontInfo, __FromString);
	Gura_AssignMethod(wx_NativeFontInfo, __ToString);
	Gura_AssignMethod(wx_NativeFontInfo, __FromUserString);
	Gura_AssignMethod(wx_NativeFontInfo, __ToUserString);
}

Gura_ImplementDescendantCreator(wx_NativeFontInfo)
{
	return new Object_wx_NativeFontInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
