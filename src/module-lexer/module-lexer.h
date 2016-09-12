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
		int _iToken;
		TokenList _tokenList;
	public:
		inline TokenWatcherEx() : _iToken(0) {}
		virtual void FeedToken(Environment &env, const Token &token);
		inline bool IsTokenReady() const { return _iToken < _tokenList.size(); }
		inline Token &PickToken() { return _tokenList[_iToken++]; }
		inline void ClearTokens() { _iToken = 0, _tokenList.clear(); }
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
