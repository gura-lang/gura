//----------------------------------------------------------------------------
// wxHtmlParser
// extracted from htparser.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(AddTagHandler);
Gura_DeclarePrivUserSymbol(AddWord);
Gura_DeclarePrivUserSymbol(DoneParser);
Gura_DeclarePrivUserSymbol(GetProduct);
Gura_DeclarePrivUserSymbol(InitParser);
Gura_DeclarePrivUserSymbol(OpenURL);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlParser: public wxHtmlParser, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlParser *_pObj;
public:
	//inline wx_HtmlParser() : wxHtmlParser(), _sig(NULL), _pObj(NULL) {}
	//virtual void AddTagHandler(wxHtmlTagHandler *handler);
	//virtual void AddWord(const char* txt);
	//virtual void DoneParser();
	//virtual wxObject* GetProduct();
	//virtual void InitParser(const wxString& source);
	//virtual wxFSFile* OpenURL(wxHtmlURLType type, const wxString& url);
	~wx_HtmlParser();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlParser *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlParser::~wx_HtmlParser()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlParser::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlParser
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlParserEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HtmlParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HtmlParserEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_HtmlParser *pEntity = new wx_HtmlParser();
	Object_wx_HtmlParser *pObj = Object_wx_HtmlParser::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlParser, AddTag)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "tag", VTYPE_wx_HtmlTag, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlParser, AddTag)
{
#if 0
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlTag *tag = Object_wx_HtmlTag::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->AddTag(*tag);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlParser, AddTagHandler)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*handler", VTYPE_wx_HtmlTagHandler, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlParser, AddTagHandler)
{
#if 0
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlTagHandler **handler = Object_wx_HtmlTagHandler::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->AddTagHandler(**handler);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlParser, AddWord)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "txt", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlParser, AddWord)
{
#if 0
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	char txt = args.GetChar(0);
	pSelf->GetEntity()->AddWord(txt);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlParser, DoParsing)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "begin_pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "end_pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, DoParsing)
{
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int begin_pos = args.GetInt(0);
	int end_pos = args.GetInt(1);
	pSelf->GetEntity()->DoParsing(begin_pos, end_pos);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlParser, DoParsing_1)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, DoParsing_1)
{
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->DoParsing();
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlParser, DoneParser)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, DoneParser)
{
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->DoneParser();
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlParser, GetFS)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlParser, GetFS)
{
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFileSystem *rtn = (wxFileSystem *)pSelf->GetEntity()->GetFS();
	return ReturnValue(env, sig, args, Value(new Object_wx_FileSystem(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlParser, GetProduct)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlParser, GetProduct)
{
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxObject *rtn = (wxObject *)pSelf->GetEntity()->GetProduct();
	return ReturnValue(env, sig, args, Value(new Object_wx_Object(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlParser, GetSource)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlParser, GetSource)
{
#if 0
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetSource();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlParser, InitParser)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "source", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, InitParser)
{
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString source = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->InitParser(source);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlParser, OpenURL)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlParser, OpenURL)
{
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlURLType type = static_cast<wxHtmlURLType>(args.GetInt(0));
	wxString url = wxString::FromUTF8(args.GetString(1));
	wxFSFile *rtn = (wxFSFile *)pSelf->GetEntity()->OpenURL(type, url);
	return ReturnValue(env, sig, args, Value(new Object_wx_FSFile(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlParser, Parse)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "source", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlParser, Parse)
{
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString source = wxString::FromUTF8(args.GetString(0));
	wxObject *rtn = (wxObject *)pSelf->GetEntity()->Parse(source);
	return ReturnValue(env, sig, args, Value(new Object_wx_Object(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlParser, PushTagHandler)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_HtmlTagHandler, OCCUR_Once);
	DeclareArg(env, "tags", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, PushTagHandler)
{
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlTagHandler *handler = Object_wx_HtmlTagHandler::GetObject(args, 0)->GetEntity();
	wxString tags = wxString::FromUTF8(args.GetString(1));
	pSelf->GetEntity()->PushTagHandler(handler, tags);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlParser, PopTagHandler)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, PopTagHandler)
{
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->PopTagHandler();
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlParser, SetFS)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*fs", VTYPE_wx_FileSystem, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlParser, SetFS)
{
#if 0
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFileSystem **fs = Object_wx_FileSystem::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetFS(**fs);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlParser, StopParsing)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, StopParsing)
{
	Object_wx_HtmlParser *pSelf = Object_wx_HtmlParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->StopParsing();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlParser
//----------------------------------------------------------------------------
Object_wx_HtmlParser::~Object_wx_HtmlParser()
{
}

Object *Object_wx_HtmlParser::Clone() const
{
	return NULL;
}

String Object_wx_HtmlParser::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HtmlParser:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_HtmlParser::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(AddTagHandler);
	Gura_RealizeUserSymbol(AddWord);
	Gura_RealizeUserSymbol(DoneParser);
	Gura_RealizeUserSymbol(GetProduct);
	Gura_RealizeUserSymbol(InitParser);
	Gura_RealizeUserSymbol(OpenURL);
	Gura_AssignFunction(HtmlParserEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlParser)
{
	Gura_AssignMethod(wx_HtmlParser, AddTag);
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
	Gura_AssignMethod(wx_HtmlParser, PushTagHandler);
	Gura_AssignMethod(wx_HtmlParser, PopTagHandler);
	Gura_AssignMethod(wx_HtmlParser, SetFS);
	Gura_AssignMethod(wx_HtmlParser, StopParsing);
}

Gura_ImplementDescendantCreator(wx_HtmlParser)
{
	return new Object_wx_HtmlParser((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
