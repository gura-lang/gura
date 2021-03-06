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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__CmdLineParser, "CmdLineParser")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CmdLineParser)
{
	//wxCmdLineParser();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CmdLineParser_1, "CmdLineParser_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CmdLineParser_1)
{
	//int argc = arg.GetNumber(0)
	//char** argv = arg.GetNumber(1)
	//wxCmdLineParser(argc, argv);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CmdLineParser_2, "CmdLineParser_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CmdLineParser_2)
{
	//int argc = arg.GetNumber(0)
	//wchar_t** argv = arg.GetNumber(1)
	//wxCmdLineParser(argc, argv);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CmdLineParser_3, "CmdLineParser_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "cmdline", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CmdLineParser_3)
{
	//const wxString& cmdline = arg.GetNumber(0)
	//wxCmdLineParser(cmdline);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CmdLineParser_4, "CmdLineParser_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CmdLineParser_4)
{
	//const wxCmdLineEntryDesc* desc = arg.GetNumber(0)
	//wxCmdLineParser(desc);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CmdLineParser_5, "CmdLineParser_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CmdLineParser_5)
{
	//const wxCmdLineEntryDesc* desc = arg.GetNumber(0)
	//int argc = arg.GetNumber(1)
	//char** argv = arg.GetNumber(2)
	//wxCmdLineParser(desc, argc, argv);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CmdLineParser_6, "CmdLineParser_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cmdline", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CmdLineParser_6)
{
	//const wxCmdLineEntryDesc* desc = arg.GetNumber(0)
	//const wxString& cmdline = arg.GetNumber(1)
	//wxCmdLineParser(desc, cmdline);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CmdLineParser, __AddLongOption, "AddLongOption")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lng", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __AddLongOption)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& lng = arg.GetNumber(0)
	//const wxString& desc = arg.GetNumber(1)
	//wxCmdLineParamType type = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->AddLongOption(lng, desc, type, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __AddLongSwitch, "AddLongSwitch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lng", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __AddLongSwitch)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& lng = arg.GetNumber(0)
	//const wxString& desc = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->AddLongSwitch(lng, desc, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __AddOption, "AddOption")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lng", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __AddOption)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxString& lng = arg.GetNumber(1)
	//const wxString& desc = arg.GetNumber(2)
	//wxCmdLineParamType type = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->AddOption(name, lng, desc, type, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __AddParam, "AddParam")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __AddParam)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& desc = arg.GetNumber(0)
	//wxCmdLineParamType type = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->AddParam(desc, type, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __AddSwitch, "AddSwitch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lng", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __AddSwitch)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxString& lng = arg.GetNumber(1)
	//const wxString& desc = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->AddSwitch(name, lng, desc, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __AddUsageText, "AddUsageText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __AddUsageText)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->AddUsageText(text);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __AreLongOptionsEnabled, "AreLongOptionsEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, __AreLongOptionsEnabled)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->AreLongOptionsEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __ConvertStringToArgs, "ConvertStringToArgs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "cmdline", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __ConvertStringToArgs)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& cmdline = arg.GetNumber(0)
	//wxCmdLineSplitType flags = arg.GetNumber(1)
	//pThis->GetEntity()->ConvertStringToArgs(cmdline, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __DisableLongOptions, "DisableLongOptions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, __DisableLongOptions)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisableLongOptions();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __EnableLongOptions, "EnableLongOptions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __EnableLongOptions)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableLongOptions(enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __Found, "Found")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __Found)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Found(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __FoundSwitch, "FoundSwitch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __FoundSwitch)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxCmdLineSwitchState _rtn = pThis->GetEntity()->FoundSwitch(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __Found_1, "Found_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __Found_1)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxString* value = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Found(name, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __Found_2, "Found_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __Found_2)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//long* value = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Found(name, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __Found_3, "Found_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __Found_3)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//double* value = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Found(name, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __Found_4, "Found_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __Found_4)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxDateTime* value = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Found(name, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __GetParam, "GetParam")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __GetParam)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetParam(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __GetParamCount, "GetParamCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, __GetParamCount)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetParamCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __GetArguments, "GetArguments")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, __GetArguments)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCmdLineArgs _rtn = pThis->GetEntity()->GetArguments();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __Parse, "Parse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "giveUsage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __Parse)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool giveUsage = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->Parse(giveUsage);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __SetCmdLine, "SetCmdLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __SetCmdLine)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int argc = arg.GetNumber(0)
	//char** argv = arg.GetNumber(1)
	//pThis->GetEntity()->SetCmdLine(argc, argv);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __SetCmdLine_1, "SetCmdLine_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __SetCmdLine_1)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int argc = arg.GetNumber(0)
	//wchar_t** argv = arg.GetNumber(1)
	//pThis->GetEntity()->SetCmdLine(argc, argv);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __SetCmdLine_2, "SetCmdLine_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cmdline", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __SetCmdLine_2)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& cmdline = arg.GetNumber(0)
	//pThis->GetEntity()->SetCmdLine(cmdline);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __SetDesc, "SetDesc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __SetDesc)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxCmdLineEntryDesc* desc = arg.GetNumber(0)
	//pThis->GetEntity()->SetDesc(desc);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __SetLogo, "SetLogo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "logo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __SetLogo)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& logo = arg.GetNumber(0)
	//pThis->GetEntity()->SetLogo(logo);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __SetSwitchChars, "SetSwitchChars")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "switchChars", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CmdLineParser, __SetSwitchChars)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& switchChars = arg.GetNumber(0)
	//pThis->GetEntity()->SetSwitchChars(switchChars);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __Usage, "Usage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, __Usage)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Usage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineParser, __GetUsageString, "GetUsageString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, __GetUsageString)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetUsageString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCmdLineParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CmdLineParser)
{
	// Constructor assignment
	Gura_AssignFunction(__CmdLineParser);
	Gura_AssignFunction(__CmdLineParser_1);
	Gura_AssignFunction(__CmdLineParser_2);
	Gura_AssignFunction(__CmdLineParser_3);
	Gura_AssignFunction(__CmdLineParser_4);
	Gura_AssignFunction(__CmdLineParser_5);
	Gura_AssignFunction(__CmdLineParser_6);
	// Method assignment
	Gura_AssignMethod(wx_CmdLineParser, __AddLongOption);
	Gura_AssignMethod(wx_CmdLineParser, __AddLongSwitch);
	Gura_AssignMethod(wx_CmdLineParser, __AddOption);
	Gura_AssignMethod(wx_CmdLineParser, __AddParam);
	Gura_AssignMethod(wx_CmdLineParser, __AddSwitch);
	Gura_AssignMethod(wx_CmdLineParser, __AddUsageText);
	Gura_AssignMethod(wx_CmdLineParser, __AreLongOptionsEnabled);
	Gura_AssignMethod(wx_CmdLineParser, __ConvertStringToArgs);
	Gura_AssignMethod(wx_CmdLineParser, __DisableLongOptions);
	Gura_AssignMethod(wx_CmdLineParser, __EnableLongOptions);
	Gura_AssignMethod(wx_CmdLineParser, __Found);
	Gura_AssignMethod(wx_CmdLineParser, __FoundSwitch);
	Gura_AssignMethod(wx_CmdLineParser, __Found_1);
	Gura_AssignMethod(wx_CmdLineParser, __Found_2);
	Gura_AssignMethod(wx_CmdLineParser, __Found_3);
	Gura_AssignMethod(wx_CmdLineParser, __Found_4);
	Gura_AssignMethod(wx_CmdLineParser, __GetParam);
	Gura_AssignMethod(wx_CmdLineParser, __GetParamCount);
	Gura_AssignMethod(wx_CmdLineParser, __GetArguments);
	Gura_AssignMethod(wx_CmdLineParser, __Parse);
	Gura_AssignMethod(wx_CmdLineParser, __SetCmdLine);
	Gura_AssignMethod(wx_CmdLineParser, __SetCmdLine_1);
	Gura_AssignMethod(wx_CmdLineParser, __SetCmdLine_2);
	Gura_AssignMethod(wx_CmdLineParser, __SetDesc);
	Gura_AssignMethod(wx_CmdLineParser, __SetLogo);
	Gura_AssignMethod(wx_CmdLineParser, __SetSwitchChars);
	Gura_AssignMethod(wx_CmdLineParser, __Usage);
	Gura_AssignMethod(wx_CmdLineParser, __GetUsageString);
}

Gura_ImplementDescendantCreator(wx_CmdLineParser)
{
	return new Object_wx_CmdLineParser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
