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
	virtual void Prepare(Environment &env);
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
	virtual String ToString(bool exprFlag);
	inline const Token &GetToken() const { return _token; }
};

}

#endif
