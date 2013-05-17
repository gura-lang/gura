#ifndef __GURA_OBJECT_OPERATOR_H__
#define __GURA_OBJECT_OPERATOR_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_operator / Object_operator
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_operator : public Class {
public:
	Class_operator(Environment *pEnvOuter);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void OnModuleEntry(Environment &env, Signal sig);
};

class GURA_DLLDECLARE Object_operator : public Object {
public:
	Gura_DeclareObjectAccessor(operator)
private:
	OpType _opType;
public:
	inline Object_operator(Environment &env, OpType opType) :
					Object(env.LookupClass(VTYPE_operator)), _opType(opType) {}
	inline Object_operator(Class *pClass, OpType opType) :
					Object(pClass), _opType(opType) {}
	Object_operator(const Object_operator &obj);
	virtual ~Object_operator();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline OpType GetOpType() const { return _opType; }
	inline Operator *GetOperator() const { return GetGlobal()->GetOperator(_opType); }
};

}

#endif
