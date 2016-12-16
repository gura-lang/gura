//=============================================================================
// Gura class: token
//=============================================================================
#ifndef __GURA_CLASS_TOKEN_H__
#define __GURA_CLASS_TOKEN_H__

#include "Class.h"
#include "Parser.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_token
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_token : public Class {
public:
	Class_token(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_token
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_token : public Object {
private:
	Token _token;
public:
	Gura_DeclareObjectAccessor(token)
public:
	Object_token(const Object_token &obj);
	inline Object_token(Environment &env, const Token &token) :
						Object(env.LookupClass(VTYPE_token)), _token(token) {}
	inline Object_token(Class *pClass, const Token &token) :
						Object(pClass), _token(token) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline const Token &GetToken() const { return _token; }
};

//-----------------------------------------------------------------------------
// Iterator_Token
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Iterator_Token : public Iterator {
public:
	class TokenWatcherEx : public Parser::TokenWatcher {
	private:
		size_t _iToken;
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

}

#endif
