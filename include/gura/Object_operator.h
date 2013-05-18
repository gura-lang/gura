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
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoCall(Environment &env, Signal sig, Args &args);
	virtual String ToString(Signal sig, bool exprFlag);
	const char *GetMathSymbol() const;
	inline OpType GetUnaryOpType() const { return _opTypeUnary; }
	inline OpType GetBinaryOpType() const { return _opTypeBinary; }
};

//-----------------------------------------------------------------------------
// CustomOperatorEntry
//-----------------------------------------------------------------------------
class CustomOperatorEntry : public OperatorEntry {
private:
	AutoPtr<Function> _pFunc;
public:
	inline CustomOperatorEntry(OpType opType, ValueType valType, Function *pFunc) :
					OperatorEntry(opType, valType), _pFunc(pFunc) {}
	inline CustomOperatorEntry(OpType opType, ValueType valTypeL, ValueType valTypeR, Function *pFunc) :
					OperatorEntry(opType, valTypeL, valTypeR), _pFunc(pFunc) {}
	virtual Value DoEval(Environment &env, Signal sig, const Value &value) const;
	virtual Value DoEval(Environment &env, Signal sig,
				const Value &valueLeft, const Value &valueRight) const;
};

}

#endif
