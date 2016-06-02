//----------------------------------------------------------------------------
// wxHtmlWinTagHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWinTagHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWinTagHandler
//----------------------------------------------------------------------------
Object_wx_HtmlWinTagHandler::~Object_wx_HtmlWinTagHandler()
{
}

Object *Object_wx_HtmlWinTagHandler::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWinTagHandler::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWinTagHandler:");
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
Gura_DeclareMethod(wx_HtmlWinTagHandler, wxHtmlWinTagHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinTagHandler, wxHtmlWinTagHandler)
{
	Object_wx_HtmlWinTagHandler *pThis = Object_wx_HtmlWinTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxHtmlWinTagHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinTagHandler, SetParser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinTagHandler, SetParser)
{
	Object_wx_HtmlWinTagHandler *pThis = Object_wx_HtmlWinTagHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parser = arg.GetNumber(0)
	//pThis->GetEntity()->SetParser();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlWinTagHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWinTagHandler)
{
	Gura_AssignMethod(wx_HtmlWinTagHandler, wxHtmlWinTagHandler);
	Gura_AssignMethod(wx_HtmlWinTagHandler, SetParser);
}

Gura_ImplementDescendantCreator(wx_HtmlWinTagHandler)
{
	return new Object_wx_HtmlWinTagHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
