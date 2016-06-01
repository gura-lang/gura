//----------------------------------------------------------------------------
// wxHtmlTag
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlTag
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlTag
//----------------------------------------------------------------------------
Object_wx_HtmlTag::~Object_wx_HtmlTag()
{
}

Object *Object_wx_HtmlTag::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlTag::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlTag:");
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
Gura_DeclareMethod(wx_HtmlTag, wxHtmlTag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end_pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cache", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "entParser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, wxHtmlTag)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int source = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int end_pos = arg.GetNumber(3)
	//int cache = arg.GetNumber(4)
	//int entParser = arg.GetNumber(5)
	//pThis->GetEntity()->wxHtmlTag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, GetAllParams)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTag, GetAllParams)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAllParams();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, GetBeginPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTag, GetBeginPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBeginPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, GetEndPos1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTag, GetEndPos1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEndPos1();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, GetEndPos2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTag, GetEndPos2)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEndPos2();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTag, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, GetParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "par", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "with_quotes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, GetParam)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int par = arg.GetNumber(0)
	//int with_quotes = arg.GetNumber(1)
	//pThis->GetEntity()->GetParam();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, GetParamAsColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "par", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, GetParamAsColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int par = arg.GetNumber(0)
	//int clr = arg.GetNumber(1)
	//pThis->GetEntity()->GetParamAsColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, GetParamAsInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "par", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, GetParamAsInt)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int par = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->GetParamAsInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, GetParamAsString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "par", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, GetParamAsString)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int par = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->GetParamAsString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, HasEnding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTag, HasEnding)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasEnding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, HasParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "par", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, HasParam)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int par = arg.GetNumber(0)
	//pThis->GetEntity()->HasParam();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, ParseAsColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, ParseAsColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int clr = arg.GetNumber(1)
	//pThis->GetEntity()->ParseAsColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, ScanParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "par", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, ScanParam)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int par = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->ScanParam();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTag, ScanParam_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "par", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, ScanParam_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int par = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->ScanParam();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlTag
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlTag)
{
	Gura_AssignMethod(wx_HtmlTag, wxHtmlTag);
	Gura_AssignMethod(wx_HtmlTag, GetAllParams);
	Gura_AssignMethod(wx_HtmlTag, GetBeginPos);
	Gura_AssignMethod(wx_HtmlTag, GetEndPos1);
	Gura_AssignMethod(wx_HtmlTag, GetEndPos2);
	Gura_AssignMethod(wx_HtmlTag, GetName);
	Gura_AssignMethod(wx_HtmlTag, GetParam);
	Gura_AssignMethod(wx_HtmlTag, GetParamAsColour);
	Gura_AssignMethod(wx_HtmlTag, GetParamAsInt);
	Gura_AssignMethod(wx_HtmlTag, GetParamAsString);
	Gura_AssignMethod(wx_HtmlTag, HasEnding);
	Gura_AssignMethod(wx_HtmlTag, HasParam);
	Gura_AssignMethod(wx_HtmlTag, ParseAsColour);
	Gura_AssignMethod(wx_HtmlTag, ScanParam);
	Gura_AssignMethod(wx_HtmlTag, ScanParam_1);
}

Gura_ImplementDescendantCreator(wx_HtmlTag)
{
	return new Object_wx_HtmlTag((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
