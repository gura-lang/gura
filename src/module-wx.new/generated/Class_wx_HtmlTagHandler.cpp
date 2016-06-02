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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HtmlTagHandler, wxHtmlTagHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTagHandler, wxHtmlTagHandler)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxHtmlTagHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTagHandler, GetSupportedTags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTagHandler, GetSupportedTags)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSupportedTags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTagHandler, HandleTag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTagHandler, HandleTag)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tag = arg.GetNumber(0)
	//pThis->GetEntity()->HandleTag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTagHandler, SetParser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTagHandler, SetParser)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parser = arg.GetNumber(0)
	//pThis->GetEntity()->SetParser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTagHandler, GetParser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlTagHandler, GetParser)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTagHandler, ParseInner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTagHandler, ParseInner)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tag = arg.GetNumber(0)
	//pThis->GetEntity()->ParseInner();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlTagHandler, ParseInnerSource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlTagHandler, ParseInnerSource)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int source = arg.GetNumber(0)
	//pThis->GetEntity()->ParseInnerSource();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlTagHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlTagHandler)
{
	Gura_AssignMethod(wx_HtmlTagHandler, wxHtmlTagHandler);
	Gura_AssignMethod(wx_HtmlTagHandler, GetSupportedTags);
	Gura_AssignMethod(wx_HtmlTagHandler, HandleTag);
	Gura_AssignMethod(wx_HtmlTagHandler, SetParser);
	Gura_AssignMethod(wx_HtmlTagHandler, GetParser);
	Gura_AssignMethod(wx_HtmlTagHandler, ParseInner);
	Gura_AssignMethod(wx_HtmlTagHandler, ParseInnerSource);
}

Gura_ImplementDescendantCreator(wx_HtmlTagHandler)
{
	return new Object_wx_HtmlTagHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
