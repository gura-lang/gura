#ifndef __GURA_OBJECT_ERROR_H__
#define __GURA_OBJECT_ERROR_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_error / Object_error
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_error : public Class {
public:
	Class_error(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

class GURA_DLLDECLARE Object_error : public Object {
public:
	Gura_DeclareObjectAccessor(error)
private:
	ErrorType _errType;
	String _str;
	std::auto_ptr<Value> _pValue;
	std::auto_ptr<ExprOwner> _pExprCauseOwner;
public:
	inline Object_error(Environment &env, ErrorType errType) :
					Object(env.LookupClass(VTYPE_error)), _errType(errType) {}
	inline Object_error(Class *pClass, ErrorType errType) :
					Object(pClass), _errType(errType) {}
	Object_error(const Object_error &obj);
	virtual ~Object_error();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	void SetSnapshot(const Signal &sig);
	inline ErrorType GetErrorType() const { return _errType; }
};

}

#endif
