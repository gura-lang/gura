//----------------------------------------------------------------------------
// wxHtmlParser
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlParser
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlParser
//----------------------------------------------------------------------------
Object_wx_HtmlParser::~Object_wx_HtmlParser()
{
}

Object *Object_wx_HtmlParser::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlParser::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlParser:");
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
Gura_DeclareFunctionAlias(__HtmlParser, "HtmlParser")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlParser)
{
	//wxHtmlParser();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlParser, __AddTagHandler, "AddTagHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, __AddTagHandler)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlTagHandler* handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddTagHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __AddWord, "AddWord")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "txt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, __AddWord)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& txt = arg.GetNumber(0)
	//pThis->GetEntity()->AddWord();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __DoParsing, "DoParsing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "begin_pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end_pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, __DoParsing)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const const_iterator& begin_pos = arg.GetNumber(0)
	//const const_iterator& end_pos = arg.GetNumber(1)
	//pThis->GetEntity()->DoParsing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __DoParsing_1, "DoParsing_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, __DoParsing_1)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoParsing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __DoneParser, "DoneParser")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, __DoneParser)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoneParser();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __GetFS, "GetFS")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, __GetFS)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFS();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __GetProduct, "GetProduct")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, __GetProduct)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProduct();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __GetSource, "GetSource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, __GetSource)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSource();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __InitParser, "InitParser")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, __InitParser)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& source = arg.GetNumber(0)
	//pThis->GetEntity()->InitParser();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __OpenURL, "OpenURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, __OpenURL)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlURLType type = arg.GetNumber(0)
	//const wxString& url = arg.GetNumber(1)
	//pThis->GetEntity()->OpenURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __Parse, "Parse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, __Parse)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& source = arg.GetNumber(0)
	//pThis->GetEntity()->Parse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __PopTagHandler, "PopTagHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, __PopTagHandler)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PopTagHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __PushTagHandler, "PushTagHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, __PushTagHandler)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlTagHandler* handler = arg.GetNumber(0)
	//const wxString& tags = arg.GetNumber(1)
	//pThis->GetEntity()->PushTagHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __SetFS, "SetFS")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, __SetFS)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFileSystem* fs = arg.GetNumber(0)
	//pThis->GetEntity()->SetFS();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __StopParsing, "StopParsing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, __StopParsing)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StopParsing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlParser, __AddTag, "AddTag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, __AddTag)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxHtmlTag& tag = arg.GetNumber(0)
	//pThis->GetEntity()->AddTag();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlParser)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlParser);
	// Method assignment
	Gura_AssignMethod(wx_HtmlParser, __AddTagHandler);
	Gura_AssignMethod(wx_HtmlParser, __AddWord);
	Gura_AssignMethod(wx_HtmlParser, __DoParsing);
	Gura_AssignMethod(wx_HtmlParser, __DoParsing_1);
	Gura_AssignMethod(wx_HtmlParser, __DoneParser);
	Gura_AssignMethod(wx_HtmlParser, __GetFS);
	Gura_AssignMethod(wx_HtmlParser, __GetProduct);
	Gura_AssignMethod(wx_HtmlParser, __GetSource);
	Gura_AssignMethod(wx_HtmlParser, __InitParser);
	Gura_AssignMethod(wx_HtmlParser, __OpenURL);
	Gura_AssignMethod(wx_HtmlParser, __Parse);
	Gura_AssignMethod(wx_HtmlParser, __PopTagHandler);
	Gura_AssignMethod(wx_HtmlParser, __PushTagHandler);
	Gura_AssignMethod(wx_HtmlParser, __SetFS);
	Gura_AssignMethod(wx_HtmlParser, __StopParsing);
	Gura_AssignMethod(wx_HtmlParser, __AddTag);
}

Gura_ImplementDescendantCreator(wx_HtmlParser)
{
	return new Object_wx_HtmlParser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
