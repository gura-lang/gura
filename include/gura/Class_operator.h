//=============================================================================
// Gura class: operator
//=============================================================================
#ifndef __GURA_CLASS_OPERATOR_H__
#define __GURA_CLASS_OPERATOR_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_operator / Object_operator
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_operator : public Class {
public:
	Class_operator(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Signal &__to_delete__, Class *pClass);
};

class GURA_DLLDECLARE Object_operator : public Object {
public:
	Gura_DeclareObjectAccessor(operator)
private:
	OpType _opTypeUnary;
	OpType _opTypeBinary;
public:
	inline Object_operator(Environment &env, OpType opTypeUnary, OpType opTypeBinary) :
					Object(env.LookupClass(VTYPE_operator)),
					_opTypeUnary(opTypeUnary), _opTypeBinary(opTypeBinary) {}
	inline Object_operator(Class *pClass, OpType opTypeUnary, OpType opTypeBinary) :
					Object(pClass), _opTypeUnary(opTypeUnary), _opTypeBinary(opTypeBinary) {}
	Object_operator(const Object_operator &obj);
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoCall(Environment &env, Signal &sig, Args &args);
	virtual String ToString(bool exprFlag);
	const Symbol *GetSymbol() const;
	inline OpType GetUnaryOpType() const { return _opTypeUnary; }
	inline OpType GetBinaryOpType() const { return _opTypeBinary; }
};

}

#endif
