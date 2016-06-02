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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HtmlParser, wxHtmlParser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, wxHtmlParser)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxHtmlParser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, AddTagHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, AddTagHandler)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddTagHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, AddWord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "txt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, AddWord)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int txt = arg.GetNumber(0)
	//pThis->GetEntity()->AddWord();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, DoParsing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "begin_pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end_pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, DoParsing)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int begin_pos = arg.GetNumber(0)
	//int end_pos = arg.GetNumber(1)
	//pThis->GetEntity()->DoParsing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, DoParsing_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, DoParsing_1)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoParsing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, DoneParser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, DoneParser)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoneParser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, GetFS)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, GetFS)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFS();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, GetProduct)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, GetProduct)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProduct();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, GetSource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, GetSource)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, InitParser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, InitParser)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int source = arg.GetNumber(0)
	//pThis->GetEntity()->InitParser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, OpenURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, OpenURL)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//int url = arg.GetNumber(1)
	//pThis->GetEntity()->OpenURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, Parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, Parse)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int source = arg.GetNumber(0)
	//pThis->GetEntity()->Parse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, PopTagHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, PopTagHandler)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PopTagHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, PushTagHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, PushTagHandler)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//int tags = arg.GetNumber(1)
	//pThis->GetEntity()->PushTagHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, SetFS)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, SetFS)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fs = arg.GetNumber(0)
	//pThis->GetEntity()->SetFS();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, StopParsing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, StopParsing)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StopParsing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, AddTag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, AddTag)
{
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tag = arg.GetNumber(0)
	//pThis->GetEntity()->AddTag();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlParser)
{
	Gura_AssignMethod(wx_HtmlParser, wxHtmlParser);
	Gura_AssignMethod(wx_HtmlParser, AddTagHandler);
	Gura_AssignMethod(wx_HtmlParser, AddWord);
	Gura_AssignMethod(wx_HtmlParser, DoParsing);
	Gura_AssignMethod(wx_HtmlParser, DoParsing_1);
	Gura_AssignMethod(wx_HtmlParser, DoneParser);
	Gura_AssignMethod(wx_HtmlParser, GetFS);
	Gura_AssignMethod(wx_HtmlParser, GetProduct);
	Gura_AssignMethod(wx_HtmlParser, GetSource);
	Gura_AssignMethod(wx_HtmlParser, InitParser);
	Gura_AssignMethod(wx_HtmlParser, OpenURL);
	Gura_AssignMethod(wx_HtmlParser, Parse);
	Gura_AssignMethod(wx_HtmlParser, PopTagHandler);
	Gura_AssignMethod(wx_HtmlParser, PushTagHandler);
	Gura_AssignMethod(wx_HtmlParser, SetFS);
	Gura_AssignMethod(wx_HtmlParser, StopParsing);
	Gura_AssignMethod(wx_HtmlParser, AddTag);
}

Gura_ImplementDescendantCreator(wx_HtmlParser)
{
	return new Object_wx_HtmlParser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
