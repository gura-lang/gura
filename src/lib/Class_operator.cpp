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

bool Object_operator::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(symbol));
	return true;
}

Value Object_operator::DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(symbol))) {
		return Value(GetSymbol());
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_operator::DoCall(
	Environment &env, const CallerInfo &callerInfo,
	const Value &valueThis, const Iterator *pIteratorThis, bool listThisFlag,
	const TrailCtrlHolder *pTrailCtrlHolder)
{
	Signal &sig = env.GetSignal();
	const ExprList &exprListArg = callerInfo.GetExprListArg();
	if (exprListArg.size() == 1) {
		bool suffixFlag = false;
		SeqPostHandler *pSeqPostHandler = nullptr;
		if (_opTypeUnary == OPTYPE_None) {
			sig.SetError(ERR_ArgumentError,
					"operator '%s' is not a unary one", GetSymbol()->GetName());
			return Value::Nil;
		}
		Value value = exprListArg[0]->Exec2(env, pSeqPostHandler);
		if (sig.IsSignalled()) return Value::Nil;
		const Operator *pOperator = GetOperator(_opTypeUnary);
		return pOperator->EvalUnary(env, value, suffixFlag);
	} else if (exprListArg.size() == 2) {
		SeqPostHandler *pSeqPostHandlerLeft = nullptr;
		SeqPostHandler *pSeqPostHandlerRight = nullptr;
		if (_opTypeBinary == OPTYPE_None) {
			sig.SetError(ERR_ArgumentError,
					"operator '%s' is not a binary one", GetSymbol()->GetName());
			return Value::Nil;
		}
		Value valueLeft = exprListArg[0]->Exec2(env, pSeqPostHandlerLeft);
		if (sig.IsSignalled()) return Value::Nil;
		Value valueRight = exprListArg[1]->Exec2(env, pSeqPostHandlerRight);
		if (sig.IsSignalled()) return Value::Nil;
		const Operator *pOperator = GetOperator(_opTypeBinary);
		return pOperator->EvalBinary(env, valueLeft, valueRight);
	} else {
		sig.SetError(ERR_ArgumentError, "operator must take one or two arguments");
		return Value::Nil;
	}
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
		GURA_HELPTEXT_BLOCK_en("op", "operator")
		"\n"
		"Below is an example to create an `operator` instance that is associated with the plus symbol.\n"
		"\n"
		"    op = operator(`+)\n");
}

Gura_ImplementFunction(operator_)
{
	Signal &sig = env.GetSignal();
	const Symbol *pSymbolOp = args.GetSymbol(0);
	OpType opTypeUnary = Operator::LookupUnaryOpType(pSymbolOp->GetName());
	OpType opTypeBinary = Operator::LookupBinaryOpType(pSymbolOp->GetName());
	if (opTypeUnary == OPTYPE_None && opTypeBinary == OPTYPE_None) {
		sig.SetError(ERR_ValueError,
			"invalid symbol for operator: '%s'", pSymbolOp->GetName());
		return Value::Nil;
	}
	Object_operator *pObj = new Object_operator(env, opTypeUnary, opTypeBinary);
	return ReturnValue(env, args, Value(pObj));
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
		"Associates the `operator` instance with a procedure described in `block`\n"
		"that takes values as a block parameter and returns its operation result.\n"
		"\n"
		"Some `operator` instances have two forms of expression: unary and binary.\n"
		"This method assignes the procedure to one of them according to\n"
		"how it takes its arguments as below:"
		"\n"
		"- `operator#assign(type:expr)` .. Assigns procedure to the unary form.\n"
		"- `operator#assign(type_l:expr, type_r:expr)` .. Assignes procedure to the binary form.\n"
		"\n"
		"They take different format of block parameters as below:\n"
		"\n"
		"- `|value|` .. For unary form.\n"
		"- `|value_l, value_r|` .. For binary form.\n"
		"\n"
		"Below is an example to assign a procedure to a unary form of operator `-`.\n"
		"\n"
		"    operator(`-).assign(`string) = {|value|\n"
		"        // any job\n"
		"    }\n"
		"\n"
		"Below is an example to assign a procedure to a binary form of operator `-`.\n"
		"\n"
		"    operator(`-).assign(`string, `number) = {|value_l, value_r|\n"
		"        // any job\n"
		"    }\n"
		"\n");
}

Gura_ImplementMethod(operator_, assign)
{
	Signal &sig = env.GetSignal();
	Object_operator *pThis = Object_operator::GetThisObj(args);
	const Function *pFuncBlock = args.GetBlockFunc(env, GetSymbolForBlock());
	if (pFuncBlock == nullptr) return Value::Nil;
	OperatorEntryCustom *pOperatorEntry = nullptr;
	if (args.IsValid(1)) {
		// assign binary operator
		OpType opType = pThis->GetBinaryOpType();
		if (opType == OPTYPE_None) {
			sig.SetError(ERR_ValueError,
				"operator '%s' is not a binary one", pThis->GetSymbol()->GetName());
			return Value::Nil;
		}
		const ValueTypeInfo *pValueTypeInfoL = env.LookupValueType(sig, args.GetExpr(0));
		if (pValueTypeInfoL == nullptr) return Value::Nil;
		const ValueTypeInfo *pValueTypeInfoR = env.LookupValueType(sig, args.GetExpr(1));
		if (pValueTypeInfoR == nullptr) return Value::Nil;
		pOperatorEntry = new OperatorEntryCustom(opType,
					pValueTypeInfoL->GetValueType(), pValueTypeInfoR->GetValueType(),
					Function::Reference(pFuncBlock));
	} else {
		// assign unary operator
		OpType opType = pThis->GetUnaryOpType();
		if (opType == OPTYPE_None) {
			sig.SetError(ERR_ValueError,
				"operator '%s' is not a unary one", pThis->GetSymbol()->GetName());
			return Value::Nil;
		}
		const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, args.GetExpr(0));
		if (pValueTypeInfo == nullptr) return Value::Nil;
		pOperatorEntry = new OperatorEntryCustom(opType,
					pValueTypeInfo->GetValueType(), VTYPE_undefined,
					Function::Reference(pFuncBlock));
	}
	Operator::Assign(env, pOperatorEntry);
	return Value::Nil;
}

// operator#entries(type?:symbol)
Gura_DeclareMethod(operator_, entries)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "type", VTYPE_symbol, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a list that contains type expressions\n"
		"that the operator can accept as its arguments.\n"
		"\n"
		"The argument `type` takes a symbol `` `binary`` or `` `unary``.\n"
		"\n"
		"- If it's omitted or specified with `` `binary``,\n"
		"  the method would return a list of pairs of type expressions\n"
		"  for its left element and right one.\n"
		"- If it's specified with `` `unary``, the method would return a list of type expressions\n"
		"  for its single element.\n");
}

Gura_ImplementMethod(operator_, entries)
{
	Signal &sig = env.GetSignal();
	Object_operator *pThis = Object_operator::GetThisObj(args);
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	if (args.IsInvalid(0) || args.GetSymbol(0)->IsIdentical(Gura_Symbol(binary))) {
		OpType opType = pThis->GetBinaryOpType();
		if (opType == OPTYPE_None) {
			sig.SetError(ERR_ValueError,
				"operator '%s' is not a binary one", pThis->GetSymbol()->GetName());
			return Value::Nil;
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
			return Value::Nil;
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
		return Value::Nil;
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

Object *Class_operator::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
