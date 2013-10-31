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
	Gura::Signal _sig;
	Object_wx_CmdLineParser *_pObj;
public:
	//inline wx_CmdLineParser() : wxCmdLineParser(), _sig(NULL), _pObj(NULL) {}
	//inline wx_CmdLineParser(int argc, char** argv) : wxCmdLineParser(argc, argv), _sig(NULL), _pObj(NULL) {}
	//inline wx_CmdLineParser(int argc, wchar_t** argv) : wxCmdLineParser(argc, argv), _sig(NULL), _pObj(NULL) {}
	//inline wx_CmdLineParser(const wxString& cmdline) : wxCmdLineParser(cmdline), _sig(NULL), _pObj(NULL) {}
	//inline wx_CmdLineParser(const wxCmdLineEntryDesc* desc) : wxCmdLineParser(desc), _sig(NULL), _pObj(NULL) {}
	//inline wx_CmdLineParser(const wxCmdLineEntryDesc* desc, int argc, char** argv) : wxCmdLineParser(desc, argc, argv), _sig(NULL), _pObj(NULL) {}
	//inline wx_CmdLineParser(const wxCmdLineEntryDesc* desc, const wxString& cmdline) : wxCmdLineParser(desc, cmdline), _sig(NULL), _pObj(NULL) {}
	~wx_CmdLineParser();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CmdLineParser *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CmdLineParser::~wx_CmdLineParser()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_CmdLineParser::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCmdLineParser
//----------------------------------------------------------------------------
Gura_DeclareFunction(CmdLineParserEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(CmdLineParserEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_CmdLineParser *pEntity = new wx_CmdLineParser();
	Object_wx_CmdLineParser *pObj = Object_wx_CmdLineParser::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CmdLineParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CmdLineParser)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(CmdLineParser)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int argc = args.GetInt(0);
	char argv = args.GetChar(1);
	wx_CmdLineParser *pEntity = new wx_CmdLineParser(argc, argv);
	Object_wx_CmdLineParser *pObj = Object_wx_CmdLineParser::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CmdLineParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CmdLineParser_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(CmdLineParser_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int argc = args.GetInt(0);
	wchar_t argv = static_cast<wchar_t>(args.GetUShort(1));
	wx_CmdLineParser *pEntity = new wx_CmdLineParser(argc, argv);
	Object_wx_CmdLineParser *pObj = Object_wx_CmdLineParser::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CmdLineParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CmdLineParser_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareArg(env, "cmdline", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(CmdLineParser_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString cmdline = wxString::FromUTF8(args.GetString(0));
	wx_CmdLineParser *pEntity = new wx_CmdLineParser(cmdline);
	Object_wx_CmdLineParser *pObj = Object_wx_CmdLineParser::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CmdLineParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CmdLineParser_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareArg(env, "desc", VTYPE_wx_CmdLineEntryDesc, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(CmdLineParser_3)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCmdLineEntryDesc *desc = Object_wx_CmdLineEntryDesc::GetObject(args, 0)->GetEntity();
	wx_CmdLineParser *pEntity = new wx_CmdLineParser(desc);
	Object_wx_CmdLineParser *pObj = Object_wx_CmdLineParser::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CmdLineParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CmdLineParser_4)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCmdLineEntryDesc *desc = Object_wx_CmdLineEntryDesc::GetObject(args, 0)->GetEntity();
	int argc = args.GetInt(1);
	char argv = args.GetChar(2);
	wx_CmdLineParser *pEntity = new wx_CmdLineParser(desc, argc, argv);
	Object_wx_CmdLineParser *pObj = Object_wx_CmdLineParser::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CmdLineParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CmdLineParser_5)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_CmdLineParser));
	DeclareArg(env, "desc", VTYPE_wx_CmdLineEntryDesc, OCCUR_Once);
	DeclareArg(env, "cmdline", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(CmdLineParser_5)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCmdLineEntryDesc *desc = Object_wx_CmdLineEntryDesc::GetObject(args, 0)->GetEntity();
	wxString cmdline = wxString::FromUTF8(args.GetString(1));
	wx_CmdLineParser *pEntity = new wx_CmdLineParser(desc, cmdline);
	Object_wx_CmdLineParser *pObj = Object_wx_CmdLineParser::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CmdLineParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_CmdLineParser, ConvertStringToArgs)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*cmdline", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_CmdLineParser, ConvertStringToArgs)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxChar *cmdline = static_cast<wxChar>(args.GetInt(0));
	wxArrayString rtn = wxCmdLineParser::ConvertStringToArgs(*cmdline);
	return ReturnValue(env, sig, args, ArrayStringToValue(env, rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, SetCmdLine)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, SetCmdLine)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int argc = args.GetInt(0);
	char argv = args.GetChar(1);
	pThis->GetEntity()->SetCmdLine(argc, argv);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, SetCmdLine_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, SetCmdLine_1)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int argc = args.GetInt(0);
	wchar_t argv = static_cast<wchar_t>(args.GetUShort(1));
	pThis->GetEntity()->SetCmdLine(argc, argv);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, SetCmdLine_2)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "cmdline", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, SetCmdLine_2)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString cmdline = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetCmdLine(cmdline);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, SetSwitchChars)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "switchChars", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, SetSwitchChars)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString switchChars = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetSwitchChars(switchChars);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, EnableLongOptions)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, EnableLongOptions)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	pThis->GetEntity()->EnableLongOptions(enable);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, DisableLongOptions)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, DisableLongOptions)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DisableLongOptions();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, AreLongOptionsEnabled)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, AreLongOptionsEnabled)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->AreLongOptionsEnabled();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, SetLogo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "logo", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, SetLogo)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString logo = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetLogo(logo);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, SetDesc)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "desc", VTYPE_wx_CmdLineEntryDesc, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, SetDesc)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCmdLineEntryDesc *desc = Object_wx_CmdLineEntryDesc::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDesc(desc);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, AddSwitch)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "lng", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "desc", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, AddSwitch)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxString lng = wxEmptyString;
	if (args.IsValid(1)) lng = wxString::FromUTF8(args.GetString(1));
	wxString desc = wxEmptyString;
	if (args.IsValid(2)) desc = wxString::FromUTF8(args.GetString(2));
	int flags = 0;
	if (args.IsValid(3)) flags = args.GetInt(3);
	pThis->GetEntity()->AddSwitch(name, lng, desc, flags);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, AddOption)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
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
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxString lng = wxEmptyString;
	if (args.IsValid(1)) lng = wxString::FromUTF8(args.GetString(1));
	wxString desc = wxEmptyString;
	if (args.IsValid(2)) desc = wxString::FromUTF8(args.GetString(2));
	wxCmdLineParamType type = wxCMD_LINE_VAL_STRING;
	if (args.IsValid(3)) type = static_cast<wxCmdLineParamType>(args.GetInt(3));
	int flags = 0;
	if (args.IsValid(4)) flags = args.GetInt(4);
	pThis->GetEntity()->AddOption(name, lng, desc, type, flags);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, AddParam)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "desc", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_CmdLineParser, AddParam)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString desc = wxEmptyString;
	if (args.IsValid(0)) desc = wxString::FromUTF8(args.GetString(0));
	wxCmdLineParamType type = wxCMD_LINE_VAL_STRING;
	if (args.IsValid(1)) type = static_cast<wxCmdLineParamType>(args.GetInt(1));
	int flags = 0;
	if (args.IsValid(2)) flags = args.GetInt(2);
	pThis->GetEntity()->AddParam(desc, type, flags);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, Parse)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "giveUsage", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, Parse)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool giveUsage = true;
	if (args.IsValid(0)) giveUsage = args.GetBoolean(0);
	int rtn = pThis->GetEntity()->Parse(giveUsage);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, Usage)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineParser, Usage)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Usage();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, Found)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, Found)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Found(name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CmdLineParser, Found_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, Found_1)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxString value = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->Found(name, value);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, Found_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, Found_2)
{
#if 0
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	long value = args.GetLong(1);
	bool rtn = pThis->GetEntity()->Found(name, value);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CmdLineParser, Found_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, Found_3)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxDateTime *value = Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Found(name, value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CmdLineParser, GetParamCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, GetParamCount)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetParamCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CmdLineParser, GetParam)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CmdLineParser, GetParam)
{
	Object_wx_CmdLineParser *pThis = Object_wx_CmdLineParser::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t n = 0u;
	if (args.IsValid(0)) n = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->GetParam(n);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxCmdLineParser
//----------------------------------------------------------------------------
Object_wx_CmdLineParser::~Object_wx_CmdLineParser()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_CmdLineParser::Clone() const
{
	return NULL;
}

String Object_wx_CmdLineParser::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.CmdLineParser:");
	if (GetEntity() == NULL) {
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
	return new Object_wx_CmdLineParser((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
