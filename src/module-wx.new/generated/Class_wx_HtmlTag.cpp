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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HtmlTag, "HtmlTag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end_pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cache", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "entParser", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlTag));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlTag)
{
	//wxHtmlTag* parent = arg.GetNumber(0)
	//const wxString* source = arg.GetNumber(1)
	//const const_iterator& pos = arg.GetNumber(2)
	//const const_iterator& end_pos = arg.GetNumber(3)
	//wxHtmlTagsCache* cache = arg.GetNumber(4)
	//wxHtmlEntitiesParser* entParser = arg.GetNumber(5)
	//wxHtmlTag(parent, source, pos, end_pos, cache, entParser);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlTag, __GetAllParams, "GetAllParams")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTag, __GetAllParams)
{
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAllParams();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTag, __GetBeginPos, "GetBeginPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTag, __GetBeginPos)
{
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBeginPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTag, __GetEndPos1, "GetEndPos1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTag, __GetEndPos1)
{
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEndPos1();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTag, __GetEndPos2, "GetEndPos2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTag, __GetEndPos2)
{
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEndPos2();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTag, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTag, __GetName)
{
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTag, __GetParam, "GetParam")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "par", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "with_quotes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, __GetParam)
{
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& par = arg.GetNumber(0)
	//bool with_quotes = arg.GetNumber(1)
	//pThis->GetEntity()->GetParam(par, with_quotes);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTag, __GetParamAsColour, "GetParamAsColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "par", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, __GetParamAsColour)
{
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& par = arg.GetNumber(0)
	//wxColour* clr = arg.GetNumber(1)
	//pThis->GetEntity()->GetParamAsColour(par, clr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTag, __GetParamAsInt, "GetParamAsInt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "par", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, __GetParamAsInt)
{
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& par = arg.GetNumber(0)
	//int* value = arg.GetNumber(1)
	//pThis->GetEntity()->GetParamAsInt(par, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTag, __GetParamAsString, "GetParamAsString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "par", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, __GetParamAsString)
{
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& par = arg.GetNumber(0)
	//wxString* value = arg.GetNumber(1)
	//pThis->GetEntity()->GetParamAsString(par, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTag, __HasEnding, "HasEnding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTag, __HasEnding)
{
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasEnding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTag, __HasParam, "HasParam")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "par", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, __HasParam)
{
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& par = arg.GetNumber(0)
	//pThis->GetEntity()->HasParam(par);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTag, __ParseAsColour, "ParseAsColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, __ParseAsColour)
{
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//wxColour* clr = arg.GetNumber(1)
	//pThis->GetEntity()->ParseAsColour(str, clr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTag, __ScanParam, "ScanParam")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "par", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, __ScanParam)
{
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& par = arg.GetNumber(0)
	//const wchar_t* format = arg.GetNumber(1)
	//void* value = arg.GetNumber(2)
	//pThis->GetEntity()->ScanParam(par, format, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTag, __ScanParam_1, "ScanParam_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "par", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTag, __ScanParam_1)
{
	Object_wx_HtmlTag *pThis = Object_wx_HtmlTag::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& par = arg.GetNumber(0)
	//const char* format = arg.GetNumber(1)
	//void* value = arg.GetNumber(2)
	//pThis->GetEntity()->ScanParam(par, format, value);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlTag
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlTag)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlTag);
	// Method assignment
	Gura_AssignMethod(wx_HtmlTag, __GetAllParams);
	Gura_AssignMethod(wx_HtmlTag, __GetBeginPos);
	Gura_AssignMethod(wx_HtmlTag, __GetEndPos1);
	Gura_AssignMethod(wx_HtmlTag, __GetEndPos2);
	Gura_AssignMethod(wx_HtmlTag, __GetName);
	Gura_AssignMethod(wx_HtmlTag, __GetParam);
	Gura_AssignMethod(wx_HtmlTag, __GetParamAsColour);
	Gura_AssignMethod(wx_HtmlTag, __GetParamAsInt);
	Gura_AssignMethod(wx_HtmlTag, __GetParamAsString);
	Gura_AssignMethod(wx_HtmlTag, __HasEnding);
	Gura_AssignMethod(wx_HtmlTag, __HasParam);
	Gura_AssignMethod(wx_HtmlTag, __ParseAsColour);
	Gura_AssignMethod(wx_HtmlTag, __ScanParam);
	Gura_AssignMethod(wx_HtmlTag, __ScanParam_1);
}

Gura_ImplementDescendantCreator(wx_HtmlTag)
{
	return new Object_wx_HtmlTag((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
