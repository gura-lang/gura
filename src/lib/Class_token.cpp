//=============================================================================
// Gura class: token
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_token
//-----------------------------------------------------------------------------
Object_token::Object_token(const Object_token &obj) : Object(obj), _token(obj.GetToken())
{
}

Object *Object_token::Clone() const
{
	return new Object_token(*this);
}

String Object_token::ToString(bool exprFlag)
{
	String str;
	str += "<token:";
	str += _token.GetTypeName();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// tokens(stream:stream):map {block?}
Gura_DeclareFunction(tokens)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(tokens)
{
	Stream &stream = arg.GetStream(0);
	AutoPtr<Iterator> pIterator(new Iterator_Token(stream.Reference()));
	return ReturnIterator(env, arg, pIterator.release());
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// token#type
Gura_DeclareProperty_R(token, type)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(token, type)
{
	const Token &token = Object_token::GetObject(valueThis)->GetToken();
	return Value(Symbol::Add(token.GetTypeName()));
}

// token#source
Gura_DeclareProperty_R(token, source)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(token, source)
{
	const Token &token = Object_token::GetObject(valueThis)->GetToken();
	return Value(token.GetSource());
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_token::Class_token(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_token)
{
}

void Class_token::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(tokens);
	// Assignment of properties
	Gura_AssignProperty(token, type);
	Gura_AssignProperty(token, source);
	// Assignment of value
	Gura_AssignValue(token, Value(Reference()));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_token::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

//-----------------------------------------------------------------------------
// Iterator_Token
//-----------------------------------------------------------------------------
Iterator_Token::Iterator_Token(Stream *pStream) :
	Iterator(Finite), _continueFlag(true), _pStream(pStream),
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
	while (_continueFlag && !_tokenWatcher.IsTokenReady()) {
		int chRaw = _pStream->GetChar(sig);
		if (sig.IsSignalled()) {
			sig.SetError(ERR_CodecError, "stream can not be recognized as %s encoded string",
						 _pStream->GetCodec()->GetEncoding());
			return false;
		}
		char ch = (chRaw < 0)? '\0' : static_cast<UChar>(chRaw);
		if (!_parser.ParseChar(env, ch)) {
			if (!sig.IsDetectEncoding()) return false;
			sig.ClearSignal();
			Value value = sig.GetValue();
			if (value.Is_string()) {
				const char *encoding = value.GetString();
				AutoPtr<Codec> pCodec(Codec::CreateCodec(sig, encoding, true, false));
				if (sig.IsSignalled()) return false;
				_pStream->SetCodec(pCodec.release());
			}
		}
		if (chRaw < 0) _continueFlag = false;
	}
	if (_tokenWatcher.IsTokenReady()) {
		value = Value(new Object_token(env, _tokenWatcher.PickToken()));
		if (!_tokenWatcher.IsTokenReady()) _tokenWatcher.ClearTokens();
		return true;
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
	//::printf("%s", token.GetSource());
	//_pObjToken.reset(new Object_token(env, token));
	_tokenList.push_back(token);
}

}
