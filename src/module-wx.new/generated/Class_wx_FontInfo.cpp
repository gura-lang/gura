//----------------------------------------------------------------------------
// wxFontInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFontInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFontInfo
//----------------------------------------------------------------------------
Object_wx_FontInfo::~Object_wx_FontInfo()
{
}

Object *Object_wx_FontInfo::Clone() const
{
	return nullptr;
}

String Object_wx_FontInfo::ToString(bool exprFlag)
{
	String rtn("<wx.FontInfo:");
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
Gura_DeclareMethod(wx_FontInfo, wxFontInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontInfo, wxFontInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxFontInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontInfo, wxFontInfo_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, wxFontInfo_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//pThis->GetEntity()->wxFontInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontInfo, wxFontInfo_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, wxFontInfo_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pixelSize = arg.GetNumber(0)
	//pThis->GetEntity()->wxFontInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontInfo, Family)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, Family)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int family = arg.GetNumber(0)
	//pThis->GetEntity()->Family();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontInfo, FaceName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, FaceName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int faceName = arg.GetNumber(0)
	//pThis->GetEntity()->FaceName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontInfo, Bold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, Bold)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bold = arg.GetNumber(0)
	//pThis->GetEntity()->Bold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontInfo, Light)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "light", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, Light)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int light = arg.GetNumber(0)
	//pThis->GetEntity()->Light();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontInfo, Italic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "italic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, Italic)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int italic = arg.GetNumber(0)
	//pThis->GetEntity()->Italic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontInfo, Slant)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "slant", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, Slant)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int slant = arg.GetNumber(0)
	//pThis->GetEntity()->Slant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontInfo, AntiAliased)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "antiAliased", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, AntiAliased)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int antiAliased = arg.GetNumber(0)
	//pThis->GetEntity()->AntiAliased();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontInfo, Underlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "underlined", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, Underlined)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int underlined = arg.GetNumber(0)
	//pThis->GetEntity()->Underlined();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontInfo, Strikethrough)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strikethrough", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, Strikethrough)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int strikethrough = arg.GetNumber(0)
	//pThis->GetEntity()->Strikethrough();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontInfo, Encoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, Encoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//pThis->GetEntity()->Encoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontInfo, AllFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, AllFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->AllFlags();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontInfo)
{
	Gura_AssignMethod(wx_FontInfo, wxFontInfo);
	Gura_AssignMethod(wx_FontInfo, wxFontInfo_1);
	Gura_AssignMethod(wx_FontInfo, wxFontInfo_2);
	Gura_AssignMethod(wx_FontInfo, Family);
	Gura_AssignMethod(wx_FontInfo, FaceName);
	Gura_AssignMethod(wx_FontInfo, Bold);
	Gura_AssignMethod(wx_FontInfo, Light);
	Gura_AssignMethod(wx_FontInfo, Italic);
	Gura_AssignMethod(wx_FontInfo, Slant);
	Gura_AssignMethod(wx_FontInfo, AntiAliased);
	Gura_AssignMethod(wx_FontInfo, Underlined);
	Gura_AssignMethod(wx_FontInfo, Strikethrough);
	Gura_AssignMethod(wx_FontInfo, Encoding);
	Gura_AssignMethod(wx_FontInfo, AllFlags);
}

Gura_ImplementDescendantCreator(wx_FontInfo)
{
	return new Object_wx_FontInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
