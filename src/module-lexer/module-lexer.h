//-----------------------------------------------------------------------------
// Gura module: math
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_LEXER_H__
#define __GURA_MODULE_LEXER_H__
#include <gura.h>

Gura_BeginModuleHeader(lexer)

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

Gura_EndModuleHeader(lexer)

#endif
