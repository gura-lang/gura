//-----------------------------------------------------------------------------
// Gura operator module
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include <gura.h>

Gura_BeginModule(operator)

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
// Gura module functions: operator
//-----------------------------------------------------------------------------
// operator.assign(op:symbol, type_l:expr, type_r?:expr):map:void {block}
Gura_DeclareFunction(assign)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "op", VTYPE_symbol);
	DeclareArg(env, "type_l", VTYPE_expr);
	DeclareArg(env, "type_r", VTYPE_expr, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementFunction(assign)
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

Gura_ModuleEntry()
{
	Gura_AssignFunction(assign);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(operator, operator)

Gura_RegisterModule(operator)
