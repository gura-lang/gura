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

bool Object_token::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(type));
	symbols.insert(Gura_Symbol(source));
	return true;
}

Value Object_token::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(type))) {
		return Value(Symbol::Add(_token.GetTypeName()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(source))) {
		return Value(_token.GetSource());
	}
	evaluatedFlag = false;
	return Value::Nil;
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
// Implementation of methods
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_token::Class_token(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_token)
{
}

void Class_token::Prepare(Environment &env)
{
	Gura_AssignFunction(tokens);
	Gura_AssignValue(token, Value(Reference()));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en + 1);
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
				if (sig.IsSignalled()) return nullptr;
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
