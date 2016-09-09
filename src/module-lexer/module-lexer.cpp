//-----------------------------------------------------------------------------
// Gura module: lexer
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(lexer)

//-----------------------------------------------------------------------------
// Iterator_Token
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Iterator_Token : public Iterator {
public:
	class TokenWatcherEx : public Parser::TokenWatcher {
	private:
		AutoPtr<Object_token> _pObjToken;
	public:
		virtual void FeedToken(Environment &env, const Token &token);
		inline bool IsObjectReady() const { return !_pObjToken.IsNull(); }
		inline Object_token *ReleaseObject() { return _pObjToken.release(); }
	};
private:
	bool _continueFlag;
	AutoPtr<Stream> _pStream;
	Parser _parser;
	TokenWatcherEx _tokenWatcher;
public:
	Iterator_Token(Stream *pStream);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Gura module functions
//-----------------------------------------------------------------------------
// lexer.tokens(stream:stream):map {block?}
Gura_DeclareFunction(tokens)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(tokens)
{
	Stream &stream = arg.GetStream(0);
	AutoPtr<Iterator> pIterator(new Iterator_Token(stream.Reference()));
	return ReturnIterator(env, arg, pIterator.release());
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	Gura_AssignFunction(tokens);
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// Iterator_Token
//-----------------------------------------------------------------------------
Iterator_Token::Iterator_Token(Stream *pStream) :
	Iterator(false), _continueFlag(true), _pStream(pStream),
	_parser(pStream->GetSignal(), pStream->GetName())
{
	//_parser.SetTokenWatcher(&_tokenWatcher);
}

Iterator *Iterator_Token::GetSource()
{
	return nullptr;
}

bool Iterator_Token::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	while (_continueFlag) {
		::printf("%d\n", _continueFlag);
		int chRaw = _pStream->GetChar(sig);
		::printf("check %d\n", __LINE__);
		if (sig.IsSignalled()) {
			sig.SetError(ERR_CodecError, "stream can not be recognized as %s encoded string",
										_pStream->GetCodec()->GetEncoding());
			return false;
		}
		char ch = (chRaw < 0)? '\0' : static_cast<UChar>(chRaw);
		::printf("check %d  %d\n", __LINE__, ch);
		if (!_parser.ParseChar(env, ch)) {
			//if (!sig.IsDetectEncoding()) return false;
			
		}
		::printf("check %d\n", __LINE__);
		if (chRaw < 0) _continueFlag = false;
#if 0
		if (_tokenWatcher.IsObjectReady()) {
			::printf("check\n");
			value = Value(_tokenWatcher.ReleaseObject());
			return true;
		}
#endif
		::printf("%d\n", _continueFlag);
	}
	return false;
}

String Iterator_Token::ToString() const
{
	String rtn = "token(";
	rtn += ")";
	return rtn;
}

void Iterator_Token::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_Token::TokenWatcherEx
//-----------------------------------------------------------------------------
void Iterator_Token::TokenWatcherEx::FeedToken(Environment &env, const Token &token)
{
	::printf("%s\n", token.GetString());
	//_pObjToken.reset(new Object_token(env, token));
}

Gura_EndModuleBody(lexer, lexer)

Gura_RegisterModule(lexer)
