//----------------------------------------------------------------------------
// wxCmdLineParser
// extracted from cmdlpars.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CmdLineParser: public wxCmdLineParser, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_CmdLineParser *_pObj;
public:
	//inline wx_CmdLineParser() : wxCmdLineParser(), _pObj(nullptr) {}
	//inline wx_CmdLineParser(int argc, char** argv) : wxCmdLineParser(argc, argv), _pObj(nullptr) {}
	//inline wx_CmdLineParser(int argc, wchar_t** argv) : wxCmdLineParser(argc, argv), _pObj(nullptr) {}
	//inline wx_CmdLineParser(const wxString& cmdline) : wxCmdLineParser(cmdline), _pObj(nullptr) {}
	//inline wx_CmdLineParser(const wxCmdLineEntryDesc* desc) : wxCmdLineParser(desc), _pObj(nullptr) {}
	//inline wx_CmdLineParser(const wxCmdLineEntryDesc* desc, int argc, char** argv) : wxCmdLineParser(desc, argc, argv), _pObj(nullptr) {}
	//inline wx_CmdLineParser(const wxCmdLineEntryDesc* desc, const wxString& cmdline) : wxCmdLineParser(desc, cmdline), _pObj(nullptr) {}
	~wx_CmdLineParser();
	inline void AssocWithGura(Object_wx_CmdLineParser *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CmdLineParser::~wx_CmdLineParser()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_CmdLineParser::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCmdLineParser
//----------------------------------------------------------------------------
Gura_DeclareFunction(CmdLineParserEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(CmdLineParserEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_CmdLineParser *pEntity = new wx_CmdLineParser();
	Object_wx_CmdLineParser *pObj = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CmdLineParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(CmdLineParser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(CmdLineParser)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	int argc = arg.GetInt(0);
	char argv = arg.GetChar(1);
	wx_CmdLineParser *pEntity = new wx_CmdLineParser(argc, argv);
	Object_wx_CmdLineParser *pObj = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CmdLineParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(CmdLineParser_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(CmdLineParser_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	int argc = arg.GetInt(0);
	wchar_t argv = static_cast<wchar_t>(arg.GetUShort(1));
	wx_CmdLineParser *pEntity = new wx_CmdLineParser(argc, argv);
	Object_wx_CmdLineParser *pObj = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CmdLineParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(CmdLineParser_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareArg(env, "cmdline", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(CmdLineParser_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString cmdline = wxString::FromUTF8(arg.GetString(0));
	wx_CmdLineParser *pEntity = new wx_CmdLineParser(cmdline);
	Object_wx_CmdLineParser *pObj = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CmdLineParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(CmdLineParser_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareArg(env, "desc", VTYPE_wx_CmdLineEntryDesc, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(CmdLineParser_3)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxCmdLineEntryDesc *desc = Object_wx_CmdLineEntryDesc::GetObject(arg, 0)->GetEntity();
	wx_CmdLineParser *pEntity = new wx_CmdLineParser(desc);
	Object_wx_CmdLineParser *pObj = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CmdLineParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(CmdLineParser_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareArg(env, "desc", VTYPE_wx_CmdLineEntryDesc, OCCUR_Once);
	DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(CmdLineParser_4)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxCmdLineEntryDesc *desc = Object_wx_CmdLineEntryDesc::GetObject(arg, 0)->GetEntity();
	int argc = arg.GetInt(1);
	char argv = arg.GetChar(2);
	wx_CmdLineParser *pEntity = new wx_CmdLineParser(desc, argc, argv);
	Object_wx_CmdLineParser *pObj = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CmdLineParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(CmdLineParser_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareArg(env, "desc", VTYPE_wx_CmdLineEntryDesc, OCCUR_Once);
	DeclareArg(env, "cmdline", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(CmdLineParser_5)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxCmdLineEntryDesc *desc = Object_wx_CmdLineEntryDesc::GetObject(arg, 0)->GetEntity();
	wxString cmdline = wxString::FromUTF8(arg.GetString(1));
	wx_CmdLineParser *pEntity = new wx_CmdLineParser(desc, cmdline);
	Object_wx_CmdLineParser *pObj = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CmdLineParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_CmdLineParser, ConvertStringToArgs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*cmdline", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_CmdLineParser, ConvertStringToArgs)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxChar *cmdline = static_cast<wxChar>(arg.GetInt(0));
	wxArrayString rtn = wxCmdLineParser::ConvertStringToArgs(*cmdline);
	return ReturnValue(env, arg, ArrayStringToValue(env, rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, SetCmdLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, SetCmdLine)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int argc = arg.GetInt(0);
	char argv = arg.GetChar(1);
	pThis->GetEntity()->SetCmdLine(argc, argv);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, SetCmdLine_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, SetCmdLine_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int argc = arg.GetInt(0);
	wchar_t argv = static_cast<wchar_t>(arg.GetUShort(1));
	pThis->GetEntity()->SetCmdLine(argc, argv);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, SetCmdLine_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "cmdline", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, SetCmdLine_2)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString cmdline = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetCmdLine(cmdline);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, SetSwitchChars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "switchChars", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, SetSwitchChars)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString switchChars = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetSwitchChars(switchChars);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, EnableLongOptions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, EnableLongOptions)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool enable = true;
	if (arg.IsValid(0)) enable = arg.GetBoolean(0);
	pThis->GetEntity()->EnableLongOptions(enable);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, DisableLongOptions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, DisableLongOptions)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->DisableLongOptions();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, AreLongOptionsEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, AreLongOptionsEnabled)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->AreLongOptionsEnabled();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, SetLogo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "logo", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, SetLogo)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString logo = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetLogo(logo);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, SetDesc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "desc", VTYPE_wx_CmdLineEntryDesc, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, SetDesc)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCmdLineEntryDesc *desc = Object_wx_CmdLineEntryDesc::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetDesc(desc);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, AddSwitch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "lng", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "desc", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, AddSwitch)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxString lng = wxEmptyString;
	if (arg.IsValid(1)) lng = wxString::FromUTF8(arg.GetString(1));
	wxString desc = wxEmptyString;
	if (arg.IsValid(2)) desc = wxString::FromUTF8(arg.GetString(2));
	int flags = 0;
	if (arg.IsValid(3)) flags = arg.GetInt(3);
	pThis->GetEntity()->AddSwitch(name, lng, desc, flags);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, AddOption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "lng", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "desc", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, AddOption)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxString lng = wxEmptyString;
	if (arg.IsValid(1)) lng = wxString::FromUTF8(arg.GetString(1));
	wxString desc = wxEmptyString;
	if (arg.IsValid(2)) desc = wxString::FromUTF8(arg.GetString(2));
	wxCmdLineParamType type = wxCMD_LINE_VAL_STRING;
	if (arg.IsValid(3)) type = static_cast<wxCmdLineParamType>(arg.GetInt(3));
	int flags = 0;
	if (arg.IsValid(4)) flags = arg.GetInt(4);
	pThis->GetEntity()->AddOption(name, lng, desc, type, flags);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, AddParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "desc", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, AddParam)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString desc = wxEmptyString;
	if (arg.IsValid(0)) desc = wxString::FromUTF8(arg.GetString(0));
	wxCmdLineParamType type = wxCMD_LINE_VAL_STRING;
	if (arg.IsValid(1)) type = static_cast<wxCmdLineParamType>(arg.GetInt(1));
	int flags = 0;
	if (arg.IsValid(2)) flags = arg.GetInt(2);
	pThis->GetEntity()->AddParam(desc, type, flags);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, Parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "giveUsage", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, Parse)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool giveUsage = true;
	if (arg.IsValid(0)) giveUsage = arg.GetBoolean(0);
	int rtn = pThis->GetEntity()->Parse(giveUsage);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, Usage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, Usage)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Usage();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, Found)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, Found)
{
	Signal &sig = env.GetSignal();
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->Found(name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_CmdLineParser, Found_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, Found_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxString value = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->Found(name, value);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, Found_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, Found_2)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	long value = arg.GetLong(1);
	bool rtn = pThis->GetEntity()->Found(name, value);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CmdLineParser, Found_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, Found_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxDateTime *value = Object_wx_DateTime::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Found(name, value);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_CmdLineParser, GetParamCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, GetParamCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetParamCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_CmdLineParser, GetParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, GetParam)
{
	Signal &sig = env.GetSignal();
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = 0u;
	if (arg.IsValid(0)) n = arg.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->GetParam(n);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxCmdLineParser
//----------------------------------------------------------------------------
Object_wx_CmdLineParser::~Object_wx_CmdLineParser()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
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
// Class implementation for wxCmdLineParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CmdLineParser)
{
	Gura_AssignFunction(CmdLineParserEmpty);
	Gura_AssignFunction(CmdLineParser);
	Gura_AssignFunction(CmdLineParser_1);
	Gura_AssignFunction(CmdLineParser_2);
	Gura_AssignFunction(CmdLineParser_3);
	Gura_AssignFunction(CmdLineParser_4);
	Gura_AssignFunction(CmdLineParser_5);
	Gura_AssignMethod(wx_CmdLineParser, ConvertStringToArgs);
	Gura_AssignMethod(wx_CmdLineParser, SetCmdLine);
	Gura_AssignMethod(wx_CmdLineParser, SetCmdLine_1);
	Gura_AssignMethod(wx_CmdLineParser, SetCmdLine_2);
	Gura_AssignMethod(wx_CmdLineParser, SetSwitchChars);
	Gura_AssignMethod(wx_CmdLineParser, EnableLongOptions);
	Gura_AssignMethod(wx_CmdLineParser, DisableLongOptions);
	Gura_AssignMethod(wx_CmdLineParser, AreLongOptionsEnabled);
	Gura_AssignMethod(wx_CmdLineParser, SetLogo);
	Gura_AssignMethod(wx_CmdLineParser, SetDesc);
	Gura_AssignMethod(wx_CmdLineParser, AddSwitch);
	Gura_AssignMethod(wx_CmdLineParser, AddOption);
	Gura_AssignMethod(wx_CmdLineParser, AddParam);
	Gura_AssignMethod(wx_CmdLineParser, Parse);
	Gura_AssignMethod(wx_CmdLineParser, Usage);
	Gura_AssignMethod(wx_CmdLineParser, Found);
	Gura_AssignMethod(wx_CmdLineParser, Found_1);
	Gura_AssignMethod(wx_CmdLineParser, Found_2);
	Gura_AssignMethod(wx_CmdLineParser, Found_3);
	Gura_AssignMethod(wx_CmdLineParser, GetParamCount);
	Gura_AssignMethod(wx_CmdLineParser, GetParam);
}

Gura_ImplementDescendantCreator(wx_CmdLineParser)
{
	return new Object_wx_CmdLineParser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
