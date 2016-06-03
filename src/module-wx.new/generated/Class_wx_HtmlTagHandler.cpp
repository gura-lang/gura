//----------------------------------------------------------------------------
// wxHtmlTagHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlTagHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlTagHandler
//----------------------------------------------------------------------------
Object_wx_HtmlTagHandler::~Object_wx_HtmlTagHandler()
{
}

Object *Object_wx_HtmlTagHandler::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlTagHandler::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlTagHandler:");
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
Gura_DeclareFunctionAlias(__HtmlTagHandler, "HtmlTagHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlTagHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlTagHandler)
{
	//wxHtmlTagHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlTagHandler, __GetSupportedTags, "GetSupportedTags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTagHandler, __GetSupportedTags)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSupportedTags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTagHandler, __HandleTag, "HandleTag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTagHandler, __HandleTag)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxHtmlTag& tag = arg.GetNumber(0)
	//pThis->GetEntity()->HandleTag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTagHandler, __SetParser, "SetParser")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTagHandler, __SetParser)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlParser* parser = arg.GetNumber(0)
	//pThis->GetEntity()->SetParser();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTagHandler, __GetParser, "GetParser")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTagHandler, __GetParser)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParser();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTagHandler, __ParseInner, "ParseInner")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTagHandler, __ParseInner)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxHtmlTag& tag = arg.GetNumber(0)
	//pThis->GetEntity()->ParseInner();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlTagHandler, __ParseInnerSource, "ParseInnerSource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTagHandler, __ParseInnerSource)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& source = arg.GetNumber(0)
	//pThis->GetEntity()->ParseInnerSource();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlTagHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlTagHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlTagHandler);
	// Method assignment
	Gura_AssignMethod(wx_HtmlTagHandler, __GetSupportedTags);
	Gura_AssignMethod(wx_HtmlTagHandler, __HandleTag);
	Gura_AssignMethod(wx_HtmlTagHandler, __SetParser);
	Gura_AssignMethod(wx_HtmlTagHandler, __GetParser);
	Gura_AssignMethod(wx_HtmlTagHandler, __ParseInner);
	Gura_AssignMethod(wx_HtmlTagHandler, __ParseInnerSource);
}

Gura_ImplementDescendantCreator(wx_HtmlTagHandler)
{
	return new Object_wx_HtmlTagHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
