//----------------------------------------------------------------------------
// wxCmdLineParser
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCmdLineParser
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCmdLineParser
//----------------------------------------------------------------------------
Object_wx_CmdLineParser::~Object_wx_CmdLineParser()
{
}

Object *Object_wx_CmdLineParser::Clone() const
{
	return nullptr;
}

String Object_wx_CmdLineParser::ToString(bool exprFlag)
{
	String rtn("<wx.CmdLineParser:");
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
Gura_DeclareMethod(wx_CmdLineParser, wxCmdLineParser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, wxCmdLineParser)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxCmdLineParser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, wxCmdLineParser_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, wxCmdLineParser_1)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int argc = arg.GetNumber(0)
	//int argv = arg.GetNumber(1)
	//pThis->GetEntity()->wxCmdLineParser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, wxCmdLineParser_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, wxCmdLineParser_2)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int argc = arg.GetNumber(0)
	//int argv = arg.GetNumber(1)
	//pThis->GetEntity()->wxCmdLineParser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, wxCmdLineParser_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cmdline", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, wxCmdLineParser_3)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cmdline = arg.GetNumber(0)
	//pThis->GetEntity()->wxCmdLineParser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, wxCmdLineParser_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, wxCmdLineParser_4)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int desc = arg.GetNumber(0)
	//pThis->GetEntity()->wxCmdLineParser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, wxCmdLineParser_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, wxCmdLineParser_5)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int desc = arg.GetNumber(0)
	//int argc = arg.GetNumber(1)
	//int argv = arg.GetNumber(2)
	//pThis->GetEntity()->wxCmdLineParser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, wxCmdLineParser_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cmdline", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, wxCmdLineParser_6)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int desc = arg.GetNumber(0)
	//int cmdline = arg.GetNumber(1)
	//pThis->GetEntity()->wxCmdLineParser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, AddLongOption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lng", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, AddLongOption)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lng = arg.GetNumber(0)
	//int desc = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->AddLongOption();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, AddLongSwitch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lng", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, AddLongSwitch)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lng = arg.GetNumber(0)
	//int desc = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->AddLongSwitch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, AddOption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lng", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, AddOption)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int lng = arg.GetNumber(1)
	//int desc = arg.GetNumber(2)
	//int type = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->AddOption();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, AddParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, AddParam)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int desc = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->AddParam();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, AddSwitch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lng", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, AddSwitch)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int lng = arg.GetNumber(1)
	//int desc = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->AddSwitch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, AddUsageText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, AddUsageText)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->AddUsageText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, AreLongOptionsEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, AreLongOptionsEnabled)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AreLongOptionsEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, ConvertStringToArgs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cmdline", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, ConvertStringToArgs)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cmdline = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->ConvertStringToArgs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, DisableLongOptions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, DisableLongOptions)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisableLongOptions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, EnableLongOptions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, EnableLongOptions)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableLongOptions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, Found)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, Found)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->Found();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, FoundSwitch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, FoundSwitch)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->FoundSwitch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, Found_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, Found_1)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->Found();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, Found_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, Found_2)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->Found();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, Found_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, Found_3)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->Found();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, Found_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, Found_4)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->Found();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, GetParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, GetParam)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetParam();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, GetParamCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, GetParamCount)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParamCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, GetArguments)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, GetArguments)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetArguments();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, Parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "giveUsage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, Parse)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int giveUsage = arg.GetNumber(0)
	//pThis->GetEntity()->Parse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, SetCmdLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, SetCmdLine)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int argc = arg.GetNumber(0)
	//int argv = arg.GetNumber(1)
	//pThis->GetEntity()->SetCmdLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, SetCmdLine_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, SetCmdLine_1)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int argc = arg.GetNumber(0)
	//int argv = arg.GetNumber(1)
	//pThis->GetEntity()->SetCmdLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, SetCmdLine_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cmdline", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, SetCmdLine_2)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cmdline = arg.GetNumber(0)
	//pThis->GetEntity()->SetCmdLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, SetDesc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, SetDesc)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int desc = arg.GetNumber(0)
	//pThis->GetEntity()->SetDesc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, SetLogo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "logo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, SetLogo)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int logo = arg.GetNumber(0)
	//pThis->GetEntity()->SetLogo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, SetSwitchChars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "switchChars", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, SetSwitchChars)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int switchChars = arg.GetNumber(0)
	//pThis->GetEntity()->SetSwitchChars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, Usage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, Usage)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Usage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, GetUsageString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, GetUsageString)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUsageString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCmdLineParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CmdLineParser)
{
	Gura_AssignMethod(wx_CmdLineParser, wxCmdLineParser);
	Gura_AssignMethod(wx_CmdLineParser, wxCmdLineParser_1);
	Gura_AssignMethod(wx_CmdLineParser, wxCmdLineParser_2);
	Gura_AssignMethod(wx_CmdLineParser, wxCmdLineParser_3);
	Gura_AssignMethod(wx_CmdLineParser, wxCmdLineParser_4);
	Gura_AssignMethod(wx_CmdLineParser, wxCmdLineParser_5);
	Gura_AssignMethod(wx_CmdLineParser, wxCmdLineParser_6);
	Gura_AssignMethod(wx_CmdLineParser, AddLongOption);
	Gura_AssignMethod(wx_CmdLineParser, AddLongSwitch);
	Gura_AssignMethod(wx_CmdLineParser, AddOption);
	Gura_AssignMethod(wx_CmdLineParser, AddParam);
	Gura_AssignMethod(wx_CmdLineParser, AddSwitch);
	Gura_AssignMethod(wx_CmdLineParser, AddUsageText);
	Gura_AssignMethod(wx_CmdLineParser, AreLongOptionsEnabled);
	Gura_AssignMethod(wx_CmdLineParser, ConvertStringToArgs);
	Gura_AssignMethod(wx_CmdLineParser, DisableLongOptions);
	Gura_AssignMethod(wx_CmdLineParser, EnableLongOptions);
	Gura_AssignMethod(wx_CmdLineParser, Found);
	Gura_AssignMethod(wx_CmdLineParser, FoundSwitch);
	Gura_AssignMethod(wx_CmdLineParser, Found_1);
	Gura_AssignMethod(wx_CmdLineParser, Found_2);
	Gura_AssignMethod(wx_CmdLineParser, Found_3);
	Gura_AssignMethod(wx_CmdLineParser, Found_4);
	Gura_AssignMethod(wx_CmdLineParser, GetParam);
	Gura_AssignMethod(wx_CmdLineParser, GetParamCount);
	Gura_AssignMethod(wx_CmdLineParser, GetArguments);
	Gura_AssignMethod(wx_CmdLineParser, Parse);
	Gura_AssignMethod(wx_CmdLineParser, SetCmdLine);
	Gura_AssignMethod(wx_CmdLineParser, SetCmdLine_1);
	Gura_AssignMethod(wx_CmdLineParser, SetCmdLine_2);
	Gura_AssignMethod(wx_CmdLineParser, SetDesc);
	Gura_AssignMethod(wx_CmdLineParser, SetLogo);
	Gura_AssignMethod(wx_CmdLineParser, SetSwitchChars);
	Gura_AssignMethod(wx_CmdLineParser, Usage);
	Gura_AssignMethod(wx_CmdLineParser, GetUsageString);
}

Gura_ImplementDescendantCreator(wx_CmdLineParser)
{
	return new Object_wx_CmdLineParser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
