//----------------------------------------------------------------------------
// wxHtmlParser
// extracted from htparser.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

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
	//Gura::Signal *_pSig;
	Object_wx_HtmlParser *_pObj;
public:
	//inline wx_HtmlParser() : wxHtmlParser(), _pObj(nullptr) {}
	//virtual void AddTagHandler(wxHtmlTagHandler *handler);
	//virtual void AddWord(const char* txt);
	//virtual void DoneParser();
	//virtual wxObject* GetProduct();
	//virtual void InitParser(const wxString& source);
	//virtual wxFSFile* OpenURL(wxHtmlURLType type, const wxString& url);
	~wx_HtmlParser();
	inline void AssocWithGura(Object_wx_HtmlParser *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlParser::~wx_HtmlParser()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlParser::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlParser
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlParserEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HtmlParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HtmlParserEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_HtmlParser *pEntity = new wx_HtmlParser();
	Object_wx_HtmlParser *pObj = Object_wx_HtmlParser::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, AddTag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "tag", VTYPE_wx_HtmlTag, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlParser, AddTag)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlTag *tag = Object_wx_HtmlTag::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AddTag(*tag);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, AddTagHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*handler", VTYPE_wx_HtmlTagHandler, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlParser, AddTagHandler)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlTagHandler **handler = Object_wx_HtmlTagHandler::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AddTagHandler(**handler);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, AddWord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "txt", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlParser, AddWord)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char txt = args.GetChar(0);
	pThis->GetEntity()->AddWord(txt);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

#if 0
Gura_DeclareMethod(wx_HtmlParser, DoParsing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "begin_pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "end_pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, DoParsing)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int begin_pos = args.GetInt(0);
	int end_pos = args.GetInt(1);
	pThis->GetEntity()->DoParsing(begin_pos, end_pos);
	return Value::Nil;
}
#endif

Gura_DeclareMethod(wx_HtmlParser, DoParsing_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, DoParsing_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->DoParsing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, DoneParser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, DoneParser)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->DoneParser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, GetFS)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlParser, GetFS)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFileSystem *rtn = (wxFileSystem *)pThis->GetEntity()->GetFS();
	return ReturnValue(env, args, Value(new Object_wx_FileSystem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlParser, GetProduct)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlParser, GetProduct)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObject *rtn = (wxObject *)pThis->GetEntity()->GetProduct();
	return ReturnValue(env, args, Value(new Object_wx_Object(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlParser, GetSource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlParser, GetSource)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetSource();
	return ReturnValue(env, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, InitParser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "source", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, InitParser)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString source = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->InitParser(source);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, OpenURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlParser, OpenURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlURLType type = static_cast<wxHtmlURLType>(args.GetInt(0));
	wxString url = wxString::FromUTF8(args.GetString(1));
	wxFSFile *rtn = (wxFSFile *)pThis->GetEntity()->OpenURL(type, url);
	return ReturnValue(env, args, Value(new Object_wx_FSFile(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlParser, Parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "source", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlParser, Parse)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString source = wxString::FromUTF8(args.GetString(0));
	wxObject *rtn = (wxObject *)pThis->GetEntity()->Parse(source);
	return ReturnValue(env, args, Value(new Object_wx_Object(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlParser, PushTagHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_HtmlTagHandler, OCCUR_Once);
	DeclareArg(env, "tags", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlParser, PushTagHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlTagHandler *handler = Object_wx_HtmlTagHandler::GetObject(args, 0)->GetEntity();
	wxString tags = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->PushTagHandler(handler, tags);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, PopTagHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, PopTagHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->PopTagHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, SetFS)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*fs", VTYPE_wx_FileSystem, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlParser, SetFS)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFileSystem **fs = Object_wx_FileSystem::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFS(**fs);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlParser, StopParsing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlParser, StopParsing)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlParser *pThis = Object_wx_HtmlParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->StopParsing();
	return Value::Nil;
}

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
// Class implementation for wxHtmlParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlParser)
{
	Gura_RealizeUserSymbol(AddTagHandler);
	Gura_RealizeUserSymbol(AddWord);
	Gura_RealizeUserSymbol(DoneParser);
	Gura_RealizeUserSymbol(GetProduct);
	Gura_RealizeUserSymbol(InitParser);
	Gura_RealizeUserSymbol(OpenURL);
	Gura_AssignFunction(HtmlParserEmpty);
	Gura_AssignMethod(wx_HtmlParser, AddTag);
	Gura_AssignMethod(wx_HtmlParser, AddTagHandler);
	Gura_AssignMethod(wx_HtmlParser, AddWord);
	//Gura_AssignMethod(wx_HtmlParser, DoParsing);
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
	return new Object_wx_HtmlParser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
