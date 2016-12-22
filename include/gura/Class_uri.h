//=============================================================================
// Gura class: uri
//=============================================================================
#ifndef __GURA_CLASS_URI_H__
#define __GURA_CLASS_URI_H__

#include "Class.h"
#include "Uri.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_uri
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_uri : public Class {
public:
	Class_uri(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_uri
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_uri : public Object {
public:
	Gura_DeclareObjectAccessor(uri)
private:
	Uri _uri;
public:
	inline Object_uri(Class *pClass) : Object(pClass) {}
	inline Object_uri(Environment &env) : Object(env.LookupClass(VTYPE_uri)) {}
	Object_uri(const Object_uri &obj);
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline Uri &GetUri() { return _uri; }
	inline const Uri &GetUri() const { return _uri; }
};

}

#endif
