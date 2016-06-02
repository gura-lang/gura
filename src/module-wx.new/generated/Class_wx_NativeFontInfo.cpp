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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_NativeFontInfo, wxNativeFontInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, wxNativeFontInfo)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxNativeFontInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, wxNativeFontInfo_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, wxNativeFontInfo_1)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->wxNativeFontInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, Init)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, InitFromFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, InitFromFont)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->InitFromFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, GetPointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, GetPointSize)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPointSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, GetPixelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, GetPixelSize)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPixelSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, GetStyle)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, GetWeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, GetWeight)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, GetUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, GetUnderlined)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUnderlined();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, GetFaceName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, GetFaceName)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFaceName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, GetFamily)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, GetFamily)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFamily();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, GetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, GetEncoding)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, SetPointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointsize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, SetPointSize)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pointsize = arg.GetNumber(0)
	//pThis->GetEntity()->SetPointSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, SetPixelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, SetPixelSize)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixelSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetPixelSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, SetStyle)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, SetWeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, SetWeight)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int weight = arg.GetNumber(0)
	//pThis->GetEntity()->SetWeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, SetUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "underlined", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, SetUnderlined)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int underlined = arg.GetNumber(0)
	//pThis->GetEntity()->SetUnderlined();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, SetFaceName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, SetFaceName)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int facename = arg.GetNumber(0)
	//pThis->GetEntity()->SetFaceName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, SetFamily)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, SetFamily)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int family = arg.GetNumber(0)
	//pThis->GetEntity()->SetFamily();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, SetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, SetEncoding)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//pThis->GetEntity()->SetEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, SetFaceName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "facenames", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, SetFaceName_1)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int facenames = arg.GetNumber(0)
	//pThis->GetEntity()->SetFaceName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, FromString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, FromString)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->FromString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, ToString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, ToString)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, FromUserString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeFontInfo, FromUserString)
{
	Object_wx_NativeFontInfo *pThis = Object_wx_NativeFontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->FromUserString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeFontInfo, ToUserString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeFontInfo, ToUserString)
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
	Gura_AssignMethod(wx_NativeFontInfo, wxNativeFontInfo);
	Gura_AssignMethod(wx_NativeFontInfo, wxNativeFontInfo_1);
	Gura_AssignMethod(wx_NativeFontInfo, Init);
	Gura_AssignMethod(wx_NativeFontInfo, InitFromFont);
	Gura_AssignMethod(wx_NativeFontInfo, GetPointSize);
	Gura_AssignMethod(wx_NativeFontInfo, GetPixelSize);
	Gura_AssignMethod(wx_NativeFontInfo, GetStyle);
	Gura_AssignMethod(wx_NativeFontInfo, GetWeight);
	Gura_AssignMethod(wx_NativeFontInfo, GetUnderlined);
	Gura_AssignMethod(wx_NativeFontInfo, GetFaceName);
	Gura_AssignMethod(wx_NativeFontInfo, GetFamily);
	Gura_AssignMethod(wx_NativeFontInfo, GetEncoding);
	Gura_AssignMethod(wx_NativeFontInfo, SetPointSize);
	Gura_AssignMethod(wx_NativeFontInfo, SetPixelSize);
	Gura_AssignMethod(wx_NativeFontInfo, SetStyle);
	Gura_AssignMethod(wx_NativeFontInfo, SetWeight);
	Gura_AssignMethod(wx_NativeFontInfo, SetUnderlined);
	Gura_AssignMethod(wx_NativeFontInfo, SetFaceName);
	Gura_AssignMethod(wx_NativeFontInfo, SetFamily);
	Gura_AssignMethod(wx_NativeFontInfo, SetEncoding);
	Gura_AssignMethod(wx_NativeFontInfo, SetFaceName_1);
	Gura_AssignMethod(wx_NativeFontInfo, FromString);
	Gura_AssignMethod(wx_NativeFontInfo, ToString);
	Gura_AssignMethod(wx_NativeFontInfo, FromUserString);
	Gura_AssignMethod(wx_NativeFontInfo, ToUserString);
}

Gura_ImplementDescendantCreator(wx_NativeFontInfo)
{
	return new Object_wx_NativeFontInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
