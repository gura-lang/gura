//-----------------------------------------------------------------------------
// Gura module: lexer
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(lexer)

//-----------------------------------------------------------------------------
// Gura module functions
//-----------------------------------------------------------------------------
// lexer.tokens(stream:stream):map
Gura_DeclareFunction(tokens)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(tokens)
{
	return Value::Nil;
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
class GURA_DLLDECLARE Iterator_Token : public Iterator {
private:
	AutoPtr<Stream> _pStream;
public:
	inline Iterator_Token(Stream *pStream) : Iterator(false), _pStream(pStream) {}
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Iterator *Iterator_Token::GetSource()
{
	return nullptr;
}

bool Iterator_Token::DoNext(Environment &env, Value &value)
{
	return true;
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


Gura_EndModuleBody(lexer, lexer)

Gura_RegisterModule(lexer)
