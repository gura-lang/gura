//
// Object_operator
//

#include "stdafx.h"

namespace Gura {

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

Value CustomOperatorEntry::DoEval(Environment &env, Signal sig, const Value &value) const
{
	ValueList valListArg(value);
	Args args(valListArg);
	return _pFunc->Eval(env, sig, args);
}

Value CustomOperatorEntry::DoEval(Environment &env, Signal sig,
					const Value &valueLeft, const Value &valueRight) const
{
	ValueList valListArg(valueLeft, valueRight);
	Args args(valListArg);
	return _pFunc->Eval(env, sig, args);
}

//-----------------------------------------------------------------------------
// Object_operator
//-----------------------------------------------------------------------------
Object_operator::Object_operator(const Object_operator &obj) :
										Object(obj), _opType(obj._opType)
{
}

Object_operator::~Object_operator()
{
}

Object *Object_operator::Clone() const
{
	return new Object_operator(*this);
}

String Object_operator::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<operator:";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_operator
//-----------------------------------------------------------------------------
// operator(op:symbol) {block?}
Gura_DeclareFunctionAlias(operator_, "operator")
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "op", VTYPE_symbol);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_operator));
	AddHelp(Gura_Symbol(en), 
	"Returns an operator object");
}

Gura_ImplementFunction(operator_)
{
	const Symbol *pSymbolOp = args.GetSymbol(0);
	OpType opType = Operator::LookupBinaryOpType(pSymbolOp->GetName());
	if (opType == OPTYPE_None) {
		sig.SetError(ERR_ValueError,
			"invalid symbol for binary operator: '%s'", pSymbolOp->GetName());
		return Value::Null;
	}
	Object_operator *pObj = new Object_operator(env, opType);
	return ReturnValue(env, sig, args, Value(pObj));
}

// operator.assign(op:symbol, type_l:expr, type_r?:expr):map:void {block}
Gura_DeclareClassMethod(operator, assign)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "op", VTYPE_symbol);
	DeclareArg(env, "type_l", VTYPE_expr);
	DeclareArg(env, "type_r", VTYPE_expr, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementClassMethod(operator, assign)
{
	const Function *pFuncBlock =
					args.GetBlockFunc(env, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) return Value::Null;
	const Symbol *pSymbolOp = args.GetSymbol(0);
	CustomOperatorEntry *pOperatorEntry = NULL;
	if (args.IsValid(2)) {
		// assign binary operator
		OpType opType = Operator::LookupBinaryOpType(pSymbolOp->GetName());
		if (opType == OPTYPE_None) {
			sig.SetError(ERR_ValueError,
				"invalid symbol for binary operator: '%s'", pSymbolOp->GetName());
			return Value::Null;
		}
		const ValueTypeInfo *pValueTypeInfoL = env.LookupValueType(sig, args.GetExpr(1));
		if (pValueTypeInfoL == NULL) return Value::Null;
		const ValueTypeInfo *pValueTypeInfoR = env.LookupValueType(sig, args.GetExpr(2));
		if (pValueTypeInfoR == NULL) return Value::Null;
		pOperatorEntry = new CustomOperatorEntry(opType,
				pValueTypeInfoL->GetValueType(), pValueTypeInfoR->GetValueType(), 
				Function::Reference(pFuncBlock));
	} else {
		// assign unary operator
		OpType opType = Operator::LookupUnaryOpType(pSymbolOp->GetName());
		if (opType == OPTYPE_None) {
			sig.SetError(ERR_ValueError,
				"invalid symbol for unary operator: '%s'", pSymbolOp->GetName());
			return Value::Null;
		}
		const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, args.GetExpr(1));
		if (pValueTypeInfo == NULL) return Value::Null;
		pOperatorEntry = new CustomOperatorEntry(opType,
				pValueTypeInfo->GetValueType(), Function::Reference(pFuncBlock));
	}
	Operator::Assign(env, pOperatorEntry);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_operator::Class_operator(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_operator)
{
	Gura_AssignMethod(operator, assign);
}

Object *Class_operator::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

void Class_operator::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(operator_);
}

}
