//-----------------------------------------------------------------------------
// Gura module: lexer
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(lexer)

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
	_parser.SetTokenWatcher(&_tokenWatcher);
}

Iterator *Iterator_Token::GetSource()
{
	return nullptr;
}

bool Iterator_Token::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	while (_continueFlag) {
		int chRaw = _pStream->GetChar(sig);
		if (sig.IsSignalled()) {
			sig.SetError(ERR_CodecError, "stream can not be recognized as %s encoded string",
						 _pStream->GetCodec()->GetEncoding());
			return false;
		}
		char ch = (chRaw < 0)? '\0' : static_cast<UChar>(chRaw);
		if (!_parser.ParseChar(env, ch)) {
			//if (!sig.IsDetectEncoding()) return false;
			
		}
		if (chRaw < 0) _continueFlag = false;
		if (_tokenWatcher.IsObjectReady()) {
			value = Value(_tokenWatcher.ReleaseObject());
			return true;
		}
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
	::printf("%s", token.GetSource());
	_pObjToken.reset(new Object_token(env, token));
}

Gura_EndModuleBody(lexer, lexer)

Gura_RegisterModule(lexer)
