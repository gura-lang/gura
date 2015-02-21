//=============================================================================
// Gura class: operator
//=============================================================================
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

String Object_operator::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<operator:";
	rtn += GetSymbol()->GetName();
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
		return Value(GetSymbol());
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_operator::DoCall(Environment &env, Signal sig, Args &args)
{
	const ExprList &exprList = args.GetExprListArg();
	size_t nArgs = exprList.size();
	if (nArgs == 1) {
		bool suffixFlag = false;
		SeqPostHandler *pSeqPostHandler = NULL;
		if (_opTypeUnary == OPTYPE_None) {
			sig.SetError(ERR_ArgumentError,
					"operator '%s' is not a unary one", GetSymbol()->GetName());
			return Value::Null;
		}
		Value value = exprList[0]->Exec2(env, sig, pSeqPostHandler);
		if (sig.IsSignalled()) return Value::Null;
		const Operator *pOperator = GetOperator(_opTypeUnary);
		return pOperator->EvalUnary(env, sig, value, suffixFlag);
	} else if (nArgs == 2) {
		SeqPostHandler *pSeqPostHandlerLeft = NULL;
		SeqPostHandler *pSeqPostHandlerRight = NULL;
		if (_opTypeBinary == OPTYPE_None) {
			sig.SetError(ERR_ArgumentError,
					"operator '%s' is not a binary one", GetSymbol()->GetName());
			return Value::Null;
		}
		Value valueLeft = exprList[0]->Exec2(env, sig, pSeqPostHandlerLeft);
		if (sig.IsSignalled()) return Value::Null;
		Value valueRight = exprList[1]->Exec2(env, sig, pSeqPostHandlerRight);
		if (sig.IsSignalled()) return Value::Null;
		const Operator *pOperator = GetOperator(_opTypeBinary);
		return pOperator->EvalBinary(env, sig, valueLeft, valueRight);
	}
	sig.SetError(ERR_ArgumentError, "operator must take one or two arguments");
	return Value::Null;
}

const Symbol *Object_operator::GetSymbol() const
{
	const Operator *pOperator = GetOperator(
			(_opTypeUnary != OPTYPE_None)? _opTypeUnary : _opTypeBinary);
	return pOperator->GetSymbol();
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// operator(symbol:symbol) {block?}
Gura_DeclareFunctionAlias(operator_, "operator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_operator));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Creates an `operator` instance that is associated with the specified symbol.\n"
		"\n"
		"If `block` is specified, it would be evaluated with a block parameter `|op:operator|`,\n"
		"where `op` is the created instance.\n"
		"In this case, the block's result would become the function's returned value.\n"
		"\n"
		"Below is an example to create an `operator` instance that is associated with the plus symbol.\n"
		"\n"
		"    op = operator(`+)\n");
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

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// operator#assign(type_l:expr, type_r?:expr):map:void {block}
Gura_DeclareMethod(operator_, assign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "type_l", VTYPE_expr);
	DeclareArg(env, "type_r", VTYPE_expr, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(operator_, assign)
{
	Object_operator *pThis = Object_operator::GetThisObj(args);
	const Function *pFuncBlock = args.GetBlockFunc(env, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) return Value::Null;
	OperatorEntryCustom *pOperatorEntry = NULL;
	if (args.IsValid(1)) {
		// assign binary operator
		OpType opType = pThis->GetBinaryOpType();
		if (opType == OPTYPE_None) {
			sig.SetError(ERR_ValueError,
				"operator '%s' is not a binary one", pThis->GetSymbol()->GetName());
			return Value::Null;
		}
		const ValueTypeInfo *pValueTypeInfoL = env.LookupValueType(sig, args.GetExpr(0));
		if (pValueTypeInfoL == NULL) return Value::Null;
		const ValueTypeInfo *pValueTypeInfoR = env.LookupValueType(sig, args.GetExpr(1));
		if (pValueTypeInfoR == NULL) return Value::Null;
		pOperatorEntry = new OperatorEntryCustom(opType,
					pValueTypeInfoL->GetValueType(), pValueTypeInfoR->GetValueType(),
					Function::Reference(pFuncBlock));
	} else {
		// assign unary operator
		OpType opType = pThis->GetUnaryOpType();
		if (opType == OPTYPE_None) {
			sig.SetError(ERR_ValueError,
				"operator '%s' is not a unary one", pThis->GetSymbol()->GetName());
			return Value::Null;
		}
		const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, args.GetExpr(0));
		if (pValueTypeInfo == NULL) return Value::Null;
		pOperatorEntry = new OperatorEntryCustom(opType,
					pValueTypeInfo->GetValueType(), VTYPE_undefined,
					Function::Reference(pFuncBlock));
	}
	Operator::Assign(env, pOperatorEntry);
	return Value::Null;
}

// operator#entries(type?:symbol)
Gura_DeclareMethod(operator_, entries)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "type", VTYPE_symbol, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(operator_, entries)
{
	Object_operator *pThis = Object_operator::GetThisObj(args);
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	if (args.IsInvalid(0) || args.GetSymbol(0)->IsIdentical(Gura_Symbol(binary))) {
		OpType opType = pThis->GetBinaryOpType();
		if (opType == OPTYPE_None) {
			sig.SetError(ERR_ValueError,
				"operator '%s' is not a binary one", pThis->GetSymbol()->GetName());
			return Value::Null;
		}
		const Operator *pOperator = env.GetOperator(opType);
		const Operator::EntryDict &entryDict = pOperator->GetEntryDict();
		foreach_const (Operator::EntryDict, iter, entryDict) {
			Operator::Key key = iter->first;
			ValueType valTypeLeft = Operator::ExtractValueTypeLeft(key);
			ValueType valTypeRight = Operator::ExtractValueTypeRight(key);
			Expr *pExprLeft = ValueTypePool::GetInstance()->Lookup(valTypeLeft)->MakeExpr();
			Expr *pExprRight = ValueTypePool::GetInstance()->Lookup(valTypeRight)->MakeExpr();
			valList.push_back(Value::CreateList(env,
				Value(new Object_expr(env, pExprLeft)), Value(new Object_expr(env, pExprRight))));
		}
	} else if (args.GetSymbol(0)->IsIdentical(Gura_Symbol(unary))) {
		OpType opType = pThis->GetUnaryOpType();
		if (opType == OPTYPE_None) {
			sig.SetError(ERR_ValueError,
				"operator '%s' is not a unary one", pThis->GetSymbol()->GetName());
			return Value::Null;
		}
		const Operator *pOperator = env.GetOperator(opType);
		const Operator::EntryDict &entryDict = pOperator->GetEntryDict();
		foreach_const (Operator::EntryDict, iter, entryDict) {
			Operator::Key key = iter->first;
			ValueType valType = Operator::ExtractValueType(key);
			Expr *pExpr = ValueTypePool::GetInstance()->Lookup(valType)->MakeExpr();
			valList.push_back(Value(new Object_expr(env, pExpr)));
		}
	} else {
		sig.SetError(ERR_ValueError, "invalid symbol: %s", args.GetSymbol(0)->GetName());
		return Value::Null;
	}
	return rtn;
}

//-----------------------------------------------------------------------------
// Class implementation
//-----------------------------------------------------------------------------
Class_operator::Class_operator(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_operator)
{
}

void Class_operator::Prepare(Environment &env)
{
	Gura_AssignFunction(operator_);
	Gura_AssignMethod(operator_, assign);
	Gura_AssignMethod(operator_, entries);
}

Object *Class_operator::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
