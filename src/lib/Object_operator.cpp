//
// Object_operator
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_operator
//-----------------------------------------------------------------------------
Object_operator::Object_operator(const Object_operator &obj) :
	Object(obj), _opTypeUnary(obj._opTypeUnary), _opTypeBinary(obj._opTypeBinary)
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
	rtn += GetMathSymbol();
	rtn += ">";
	return rtn;
}

bool Object_operator::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(symbol));
	return true;
}

Value Object_operator::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(symbol))) {
		return Value(Symbol::Add(GetMathSymbol()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_operator::DoCall(Environment &env, Signal sig, Args &args)
{
	size_t nArgs = args.CountArgs();
	if (nArgs == 1) {
		if (_opTypeUnary == OPTYPE_None) {
			sig.SetError(ERR_ArgumentError,
					"operator '%s' is not a unary one", GetMathSymbol());
			return Value::Null;
		}
		const Operator *pOperator = GetGlobal()->GetOperator(_opTypeUnary);
		return pOperator->EvalUnary(env, sig, args.GetValue(0));
	} else if (nArgs == 2) {
		if (_opTypeBinary == OPTYPE_None) {
			sig.SetError(ERR_ArgumentError,
					"operator '%s' is not a binary one", GetMathSymbol());
			return Value::Null;
		}
		const Operator *pOperator = GetGlobal()->GetOperator(_opTypeBinary);
		return pOperator->EvalBinary(env, sig, args.GetValue(0), args.GetValue(1));
	}
	sig.SetError(ERR_ArgumentError, "operator must take one or two arguments");
	return Value::Null;
}

const char *Object_operator::GetMathSymbol() const
{
	const Operator *pOperator = GetGlobal()->GetOperator(
			(_opTypeUnary != OPTYPE_None)? _opTypeUnary : _opTypeBinary);
	return pOperator->GetMathSymbol();
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
	OpType opTypeUnary = Operator::LookupUnaryOpType(pSymbolOp->GetName());
	OpType opTypeBinary = Operator::LookupBinaryOpType(pSymbolOp->GetName());
	if (opTypeUnary == OPTYPE_None && opTypeBinary == OPTYPE_None) {
		sig.SetError(ERR_ValueError,
			"invalid symbol for operator: '%s'", pSymbolOp->GetName());
		return Value::Null;
	}
	Object_operator *pObj = new Object_operator(env, opTypeUnary, opTypeBinary);
	return ReturnValue(env, sig, args, Value(pObj));
}

// operator#assign(type_l:expr, type_r?:expr):map:void {block}
Gura_DeclareMethod(operator, assign)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "type_l", VTYPE_expr);
	DeclareArg(env, "type_r", VTYPE_expr, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementMethod(operator, assign)
{
	Object_operator *pThis = Object_operator::GetThisObj(args);
	const Function *pFuncBlock =
					args.GetBlockFunc(env, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) return Value::Null;
	CustomOperatorEntry *pOperatorEntry = NULL;
	if (args.IsValid(1)) {
		// assign binary operator
		OpType opType = pThis->GetBinaryOpType();
		if (opType == OPTYPE_None) {
			sig.SetError(ERR_ValueError,
				"operator '%s' is not a binary one", pThis->GetMathSymbol());
			return Value::Null;
		}
		const ValueTypeInfo *pValueTypeInfoL = env.LookupValueType(sig, args.GetExpr(0));
		if (pValueTypeInfoL == NULL) return Value::Null;
		const ValueTypeInfo *pValueTypeInfoR = env.LookupValueType(sig, args.GetExpr(1));
		if (pValueTypeInfoR == NULL) return Value::Null;
		pOperatorEntry = new CustomOperatorEntry(opType,
				pValueTypeInfoL->GetValueType(), pValueTypeInfoR->GetValueType(), 
				Function::Reference(pFuncBlock));
	} else {
		// assign unary operator
		OpType opType = pThis->GetUnaryOpType();
		if (opType == OPTYPE_None) {
			sig.SetError(ERR_ValueError,
				"operator '%s' is not a unary one", pThis->GetMathSymbol());
			return Value::Null;
		}
		const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, args.GetExpr(0));
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

//-----------------------------------------------------------------------------
// CustomOperatorEntry
//-----------------------------------------------------------------------------
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

}
