#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// FunctionType
//-----------------------------------------------------------------------------
const char *GetFuncTypeName(FunctionType funcType)
{
	static const struct {
		FunctionType funcType;
		const char *name;
	} tbl[] = {
		{ FUNCTYPE_Function,	"function",		},
		{ FUNCTYPE_Class,		"class",		},
		{ FUNCTYPE_Instance,	"instance",		},
		{ FUNCTYPE_Block,		"block",		},
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].funcType == funcType) return tbl[i].name;
	}
	return "unknown";
}

//-----------------------------------------------------------------------------
// Args
//-----------------------------------------------------------------------------
Args::~Args()
{
}

const Expr_Block *Args::GetBlock(Environment &env, Signal sig) const
{
	// check if the block parameter specifies a delegated block information
	// like "g() {|block|}"
	// scope problem remains: 2010.11.02
	const Expr_Block *pExprBlock = _pExprBlock;
	while (pExprBlock != NULL) {
		const Expr_BlockParam *pExprBlockParam = pExprBlock->GetParam();
		if (pExprBlockParam == NULL || !pExprBlock->GetExprOwner().empty()) {
			break;
		}
		const ExprList &exprList = pExprBlockParam->GetExprOwner();
		if (exprList.size() != 1 || !exprList.front()->IsSymbol()) {
			break;
		}
		const Expr_Symbol *pExprSymbol =
							dynamic_cast<const Expr_Symbol *>(exprList.front());
		const Value *pValue = env.LookupValue(pExprSymbol->GetSymbol(), ENVREF_Escalate);
		if (pValue == NULL) {
			break;
		} else if (pValue->IsExpr()) {
			const Expr *pExpr = pValue->GetExpr();
			if (!pExpr->IsBlock()) {
				sig.SetError(ERR_ValueError, "invalid value for block delegation");
				return NULL;
			}
			pExprBlock = dynamic_cast<const Expr_Block *>(pExpr);
		} else if (pValue->IsInvalid()) {
			return NULL;
		} else {
			break;
		}
	}
	return pExprBlock;
}

bool Args::ShouldGenerateIterator(const DeclarationList &declList) const
{
	if (IsThisIterator()) return true;
	ValueList::const_iterator pValue = _valListArg.begin();
	DeclarationList::const_iterator ppDecl = declList.begin();
	for ( ; pValue != _valListArg.end() && ppDecl != declList.end(); pValue++) {
		const Declaration *pDecl = *ppDecl;
		if (pValue->IsIterator() &&
						pDecl->GetValueType() != VTYPE_iterator) return true;
		if (!pDecl->IsVariableLength()) ppDecl++;
	}
	return false;
}

// return NULL without error if block is not specified
const Function *Args::GetBlockFunc(Environment &env, Signal sig, const Symbol *pSymbol)
{
	const Expr_Block *pExprBlock = GetBlock(env, sig);
	if (pExprBlock == NULL || pSymbol == NULL) return NULL;
	if (_pFuncBlock.IsNull()) {
		_pFuncBlock.reset(CustomFunction::CreateBlockFunc(env, sig,
										pSymbol, pExprBlock, FUNCTYPE_Block));
	}
	return _pFuncBlock.get();
}

//-----------------------------------------------------------------------------
// Function
//-----------------------------------------------------------------------------
const char *Function::_mathSymbolTbl[] = {
	"",		// OPTYPE_None
	"+",	// OPTYPE_Pos
	"-",	// OPTYPE_Neg
	"~",	// OPTYPE_Invert
	"!",	// OPTYPE_Not
	"+",	// OPTYPE_Plus
	"-",	// OPTYPE_Minus
	"*",	// OPTYPE_Multiply
	"/",	// OPTYPE_Divide
	"%",	// OPTYPE_Modulo
	"%",	// OPTYPE_format
	"**",	// OPTYPE_Power
	"==",	// OPTYPE_Equal
	"!=",	// OPTYPE_NotEqual
	">",	// OPTYPE_Greater
	"<",	// OPTYPE_Less
	">=",	// OPTYPE_GreaterEq
	"<=",	// OPTYPE_LessEq
	"<=>",	// OPTYPE_Compare
	"in",	// OPTYPE_ContainCheck
	"|",	// OPTYPE_Or
	"&",	// OPTYPE_And
	"^",	// OPTYPE_Xor
	"<<",	// OPTYPE_ShiftL
	">>",	// OPTYPE_ShiftR
	"||",	// OPTYPE_OrOr
	"&&",	// OPTYPE_AndAnd
	"..",	// OPTYPE_Sequence
	"..",	// OPTYPE_SequenceInf
};

bool Function::IsCustom() const			{ return false; }
bool Function::IsPos() const			{ return false; }
bool Function::IsNeg() const			{ return false; }
bool Function::IsPlus() const			{ return false; }
bool Function::IsMinus() const			{ return false; }
bool Function::IsMultiply() const		{ return false; }
bool Function::IsDivide() const			{ return false; }
bool Function::IsModulo() const			{ return false; }
bool Function::IsPower() const			{ return false; }
bool Function::IsContainCheck() const	{ return false; }
bool Function::IsSequence() const		{ return false; }
bool Function::IsConstructorOfStruct() const{ return false; }

Function::Function(const Function &func) : _cntRef(1),
	_pSymbol(func._pSymbol), _pClassToConstruct(func._pClassToConstruct),
	_envScope(func._envScope), _declOwner(func._declOwner),
	_elemType(func._elemType), _opType(OPTYPE_None),
	_funcType(func._funcType),
	_resultMode(func._resultMode), _flags(func._flags),
	_attrsOpt(func._attrsOpt), _blockInfo(func._blockInfo)
{
}

Function::Function(Environment &envScope, const Symbol *pSymbol,
								FunctionType funcType, unsigned long flags) :
	_cntRef(1),
	_pSymbol(pSymbol), _pClassToConstruct(NULL), _envScope(envScope), _funcType(funcType),
	_elemType(Parser::ETYPE_Unknown),
	_resultMode(RSLTMODE_Normal), _flags(flags)
{
	_blockInfo.occurPattern = OCCUR_Zero;
	_blockInfo.pSymbol = NULL;
	_blockInfo.blockScope = BLKSCOPE_Through;
	_blockInfo.quoteFlag = false;
}

Function::~Function()
{
}

void Function::SetClassToConstruct(Class *pClassToConstruct)
{
	_pClassToConstruct = pClassToConstruct;
	pClassToConstruct->SetConstructor(Function::Reference(this));
}

bool Function::CustomDeclare(Environment &env, Signal sig,
								const SymbolSet &attrsAcceptable, Args &args)
{
	// delcaration of arguments
	if (!_declOwner.Declare(env, sig, args.GetExprListArg())) return false;
	// declaration of attributes
	foreach_const (SymbolSet, ppSymbol, args.GetAttrs()) {
		const Symbol *pSymbol = *ppSymbol;
		if (pSymbol->IsIdentical(Gura_Symbol(map))) {
			_flags |= FLAG_Map;
		} else if (pSymbol->IsIdentical(Gura_Symbol(nomap))) {
			_flags &= ~FLAG_Map;
		} else if (pSymbol->IsIdentical(Gura_Symbol(flat))) {
			_flags |= FLAG_Flat;
		} else if (pSymbol->IsIdentical(Gura_Symbol(noflat))) {
			_flags &= ~FLAG_Flat;
		} else if (pSymbol->IsIdentical(Gura_Symbol(list))) {
			_resultMode = RSLTMODE_List;
		} else if (pSymbol->IsIdentical(Gura_Symbol(xlist))) {
			_resultMode = RSLTMODE_XList;
		} else if (pSymbol->IsIdentical(Gura_Symbol(set))) {
			_resultMode = RSLTMODE_Set;
		} else if (pSymbol->IsIdentical(Gura_Symbol(xset))) {
			_resultMode = RSLTMODE_XSet;
		} else if (pSymbol->IsIdentical(Gura_Symbol(iter))) {
			_resultMode = RSLTMODE_Iterator;
		} else if (pSymbol->IsIdentical(Gura_Symbol(xiter))) {
			_resultMode = RSLTMODE_XIterator;
		} else if (pSymbol->IsIdentical(Gura_Symbol(void_))) {
			_resultMode = RSLTMODE_Void;
		} else if (pSymbol->IsIdentical(Gura_Symbol(reduce))) {
			_resultMode = RSLTMODE_Reduce;
		} else if (pSymbol->IsIdentical(Gura_Symbol(xreduce))) {
			_resultMode = RSLTMODE_XReduce;
		} else if (pSymbol->IsIdentical(Gura_Symbol(static_))) {
			// just ignore it
		} else if (pSymbol->IsIdentical(Gura_Symbol(dynamic_scope))) {
			_flags |= FLAG_DynamicScope;
		} else if (pSymbol->IsIdentical(Gura_Symbol(symbol_func))) {
			_flags |= FLAG_SymbolFunc;
		} else if (pSymbol->IsIdentical(Gura_Symbol(leader))) {
			_flags |= FLAG_Leader;
		} else if (pSymbol->IsIdentical(Gura_Symbol(trailer))) {
			_flags |= FLAG_Trailer;
		} else if (pSymbol->IsIdentical(Gura_Symbol(end_marker))) {
			_flags |= FLAG_EndMarker;
		} else if (pSymbol->IsIdentical(Gura_Symbol(public_))) {
			_flags |= FLAG_Public;
		} else if (pSymbol->IsIdentical(Gura_Symbol(private_))) {
			_flags |= FLAG_Private;
		} else if (attrsAcceptable.IsSet(pSymbol)) {
			// nothing to do
		} else {
			sig.SetError(ERR_TypeError,
				"unsupported attribute '%s' for function declaration",
															pSymbol->GetName());
			return false;
		}
	}
	_attrsOpt = args.GetAttrsOpt();
	// declaration of a block
	if (!args.IsBlockSpecified()) return true;
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return false;
	const ExprList &exprList = pExprBlock->GetExprOwner();
	if (exprList.size() != 1) {
		SetError_InvalidFunctionExpression(sig);
		return false;
	}
	const Expr *pExpr = exprList.front();
	OccurPattern occurPattern = OCCUR_Once;
	if (pExpr->IsSuffix()) {
		const Expr_Suffix *pExprSuffix = dynamic_cast<const Expr_Suffix *>(pExpr);
		pExpr = pExprSuffix->GetChild();
		occurPattern = pExprSuffix->GetOccurPattern();
		if (occurPattern == OCCUR_Invalid) {
			SetError_InvalidFunctionExpression(sig);
			return false;
		}
	}
	bool quoteFlag = false;
	if (pExpr->IsQuote()) {
		const Expr_Quote *pExprQuote = dynamic_cast<const Expr_Quote *>(pExpr);
		quoteFlag = true;
		pExpr = pExprQuote->GetChild();
	}
	if (!pExpr->IsSymbol()) {
		sig.SetError(ERR_TypeError,
				"content of block in a function declaration must be a symbol");
		return false;
	}
	const Expr_Symbol *pExprSym = dynamic_cast<const Expr_Symbol *>(pExpr);
	DeclareBlock(occurPattern, pExprSym->GetSymbol(),
										BLKSCOPE_Through, quoteFlag);
	foreach_const (SymbolSet, ppSymbol, pExprSym->GetAttrs()) {
		const Symbol *pSymbol = *ppSymbol;
		if (pSymbol->IsIdentical(Gura_Symbol(inside_scope))) {
			_blockInfo.blockScope = BLKSCOPE_Inside;
		} else if (pSymbol->IsIdentical(Gura_Symbol(func_scope))) {
			_blockInfo.blockScope = BLKSCOPE_SameAsFunc;
		} else {
			sig.SetError(ERR_TypeError, 
				"unsupported attribute '%s' for block declaration",
														pSymbol->GetName());
			return false;
		}
	}
	return true;
}

void Function::CopyDeclare(const Function &func)
{
	_declOwner	= func._declOwner;
	_resultMode	= func._resultMode;	// :list, :xlist, :set, :xset, :iter, :xiter, :void
	_flags		= func._flags;		// :map, :nomap, :flat, :noflat
	_attrsOpt	= func._attrsOpt;
	_blockInfo	= func._blockInfo;
}

Declaration *Function::DeclareArg(Environment &env, const Symbol *pSymbol, ValueType valType,
				OccurPattern occurPattern, unsigned long flags, Expr *pExprDefault)
{
	return _declOwner.Declare(env, pSymbol, valType, occurPattern, flags, pExprDefault);
}

void Function::DeclareBlock(OccurPattern occurPattern,
				const Symbol *pSymbol, BlockScope blockScope, bool quoteFlag)
{
	_blockInfo.occurPattern = occurPattern;
	_blockInfo.pSymbol =
			(occurPattern == OCCUR_Zero)? NULL :
			(pSymbol == NULL)? Gura_Symbol(block) : pSymbol;
	_blockInfo.blockScope = blockScope;
	_blockInfo.quoteFlag = quoteFlag;
}

void Function::AddHelp(const Symbol *pSymbol, const char *help)
{
	_helpMap[pSymbol] = help;
}

Value Function::EvalExpr(Environment &env, Signal sig, Args &args) const
{
	if (GetType() == FUNCTYPE_Instance && args.GetThisObj() == NULL) {
		sig.SetError(ERR_ValueError,
			"object is expected as l-value of field");
		return Value::Null;
	} else if (GetType() == FUNCTYPE_Class &&
				args.GetThisClass() == NULL && args.GetThisObj() == NULL) {
		sig.SetError(ERR_ValueError,
			"class or object is expected as l-value of field");
		return Value::Null;
	}
	if (args.IsBlockSpecified()) {
		if (_blockInfo.occurPattern == OCCUR_Zero) {
			sig.SetError(ERR_ValueError,
				"block is unnecessary for '%s'", ToString().c_str());
			return Value::Null;
		}
	} else {
		if (_blockInfo.occurPattern == OCCUR_Once) {
			sig.SetError(ERR_ValueError,
				"block must be specified for '%s'", ToString().c_str());
			return Value::Null;
		}
	}
	bool mapFlag = GetMapFlag();
	unsigned long flags = _flags;
	ResultMode resultMode = _resultMode;
	foreach_const (SymbolSet, ppSymbol, args.GetAttrs()) {
		const Symbol *pSymbol = *ppSymbol;
		if (pSymbol->IsIdentical(Gura_Symbol(map))) {
			mapFlag = true;
		} else if (pSymbol->IsIdentical(Gura_Symbol(nomap))) {
			mapFlag = false;
		} else if (pSymbol->IsIdentical(Gura_Symbol(flat))) {
			flags |= FLAG_Flat;
		} else if (pSymbol->IsIdentical(Gura_Symbol(noflat))) {
			flags &= ~FLAG_Flat;
		} else if (pSymbol->IsIdentical(Gura_Symbol(list))) {
			resultMode = RSLTMODE_List;
		} else if (pSymbol->IsIdentical(Gura_Symbol(xlist))) {
			resultMode = RSLTMODE_XList;
		} else if (pSymbol->IsIdentical(Gura_Symbol(set))) {
			resultMode = RSLTMODE_Set;
		} else if (pSymbol->IsIdentical(Gura_Symbol(xset))) {
			resultMode = RSLTMODE_XSet;
		} else if (pSymbol->IsIdentical(Gura_Symbol(iter))) {
			resultMode = RSLTMODE_Iterator;
		} else if (pSymbol->IsIdentical(Gura_Symbol(xiter))) {
			resultMode = RSLTMODE_XIterator;
		} else if (pSymbol->IsIdentical(Gura_Symbol(void_))) {
			resultMode = RSLTMODE_Void;
		} else if (pSymbol->IsIdentical(Gura_Symbol(reduce))) {
			resultMode = RSLTMODE_Reduce;
		} else if (pSymbol->IsIdentical(Gura_Symbol(xreduce))) {
			resultMode = RSLTMODE_XReduce;
		} else if (_attrsOpt.IsSet(pSymbol)) {
			// nothing to do
		} else {
			sig.SetError(ERR_AttributeError,
				"unsupported attribute '%s' for '%s'",
										pSymbol->GetName(), ToString().c_str());
			return Value::Null;
		}
	}
	const ExprList &exprListArg = args.GetExprListArg();
	ValueList valListArg;
	Value valueWithDict;
	valueWithDict.InitAsDict(env, false);
	if (!_declOwner.PrepareArgs(env, sig, exprListArg, valListArg, valueWithDict)) {
		return Value::Null;
	}
	Args argsSub(args, valListArg, valueWithDict, resultMode, flags);
	if (!mapFlag) {
		return Eval(env, sig, argsSub);
	} else if (_declOwner.ShouldImplicitMap(argsSub)) {
		return EvalMap(env, sig, argsSub);
	} else {
		return Eval(env, sig, argsSub);
	}
}

Value Function::Eval(Environment &env, Signal sig, Args &args) const
{
	bool exprFlag = false;
	ValueList valListCasted;
	if (!_declOwner.ValidateAndCast(env, sig, args.GetArgs(), valListCasted)) {
		return Value::Null;
	}
	Args argsCasted(args, valListCasted, args.GetValueWithDict(),
									args.GetResultMode(), args.GetFlatFlag());
	Value value = DoEval(env, sig, argsCasted);
	if (args.IsRsltVoid()) return Value::Undefined;
	return value;
}

Value Function::EvalMap(Environment &env, Signal sig, Args &args) const
{
	if (args.IsRsltIterator() || args.IsRsltXIterator()) {
		// nothing to do
	} else if (!args.IsRsltNormal() || !args.ShouldGenerateIterator(_declOwner)) {
		// List, XList, Set, XSet, Void, Reduce, XReduce
		return EvalMapRecursive(env, sig, NULL, args);
	}
	bool skipInvalidFlag = args.IsRsltXIterator();
	AutoPtr<Iterator_ImplicitMap> pIterator(new Iterator_ImplicitMap(env, sig,
			Function::Reference(this),
			args.GetThis(), Iterator::Reference(args.GetIteratorThis()),
			args.GetArgs(), skipInvalidFlag));
	if (sig.IsSignalled()) {
		return Value::Null;
	}
	return Value(env, pIterator.release());
}

Value Function::EvalMapRecursive(Environment &env, Signal sig,
				ResultComposer *pResultComposer, Args &args) const
{
	IteratorOwner iterOwner;
	if (!iterOwner.PrepareForMap(sig, GetDeclOwner(), args.GetArgs())) {
		return Value::Null;
	}
	Value result;
	std::auto_ptr<ResultComposer> pResultComposerOwner;
	if (pResultComposer == NULL) {
		pResultComposer = new ResultComposer(env, args, result);
		pResultComposerOwner.reset(pResultComposer);
	}
	bool doneThisFlag = false;
	Iterator *pIteratorThis = args.GetIteratorThis();
	for (size_t n = 0; ; n++) {
		ValueList valListArg;
		if (doneThisFlag || !iterOwner.Next(env, sig, valListArg)) {
			if (sig.IsSignalled()) return Value::Null;
			if (n == 0 && !args.IsRsltVoid() && pResultComposerOwner.get() != NULL) {
				result.InitAsList(env);
			}
			break;
		}
		Args argsEach(args, valListArg, args.GetValueWithDict(),
									args.GetResultMode(), args.GetFlatFlag());
		if (!_declOwner.ShouldImplicitMap(valListArg)) {
			Value valueEach = Eval(env, sig, argsEach);
			if (sig.IsSignalled()) return Value::Null;
			pResultComposer->Store(valueEach);
		} else if (args.IsRsltFlat()) {
			EvalMapRecursive(env, sig, pResultComposer, argsEach);
			if (sig.IsSignalled()) return Value::Null;
		} else {
			Value valueEach = EvalMapRecursive(env, sig, NULL, argsEach);
			if (sig.IsSignalled()) return Value::Null;
			pResultComposer->Store(valueEach);
		}
		if (pIteratorThis != NULL) {
			Value valueThis;
			doneThisFlag = !pIteratorThis->Next(env, sig, valueThis);
			if (sig.IsSignalled()) return Value::Null;
			args.SetThis(valueThis);
		}
	}
	return result;
}

Value Function::EvalOverrideUnary(Environment &env, Signal sig, Args &args, bool &evaluatedFlag) const
{
	const Value &value = args.GetValue(0);
	Object *pObj = NULL;
	if (value.IsObject()) {
		Value valueObj = value;
		pObj = valueObj.GetObject();
	} else {
		evaluatedFlag = false;
		return Value::Null;
	}
	evaluatedFlag = true;
	return pObj->EvalMethod(env, sig, GetSymbol(), args.GetArgs(), evaluatedFlag);
}

Value Function::EvalOverrideBinary(Environment &env, Signal sig, Args &args, bool &evaluatedFlag) const
{
	const Value &valueLeft = args.GetValue(0);
	const Value &valueRight = args.GetValue(1);
	Object *pObj = NULL;
	if (valueLeft.IsObject()) {
		Value valueObj = valueLeft;
		pObj = valueObj.GetObject();
	} else if (valueRight.IsObject()) {
		Value valueObj = valueRight;
		pObj = valueObj.GetObject();
	} else {
		evaluatedFlag = false;
		return Value::Null;
	}
	evaluatedFlag = true;
	return pObj->EvalMethod(env, sig, GetSymbol(), args.GetArgs(), evaluatedFlag);
}

Environment *Function::PrepareEnvironment(Environment &env, Signal sig, Args &args) const
{
	EnvType envType = (_funcType == FUNCTYPE_Block)? ENVTYPE_block : ENVTYPE_local;
	Environment *pEnvOuter = GetDynamicScopeFlag()?
							&env : const_cast<Environment *>(&_envScope);
	std::auto_ptr<Environment> pEnvLocal(new Environment(pEnvOuter, envType));
	const ValueList &valListArg = args.GetArgs();
	ValueList::const_iterator pValue = valListArg.begin();
	DeclarationList::const_iterator ppDecl = _declOwner.begin();
	for ( ; pValue != valListArg.end() && ppDecl != _declOwner.end();
														pValue++, ppDecl++) {
		pEnvLocal->AssignValue((*ppDecl)->GetSymbol(), *pValue, EXTRA_Public);
	}
	if (_declOwner.GetSymbolDict() != NULL) {
		Value valueWithDict = args.GetValueWithDict();
		if (valueWithDict.IsInvalid()) {
			valueWithDict.InitAsDict(env, false);
		}
		pEnvLocal->AssignValue(_declOwner.GetSymbolDict(), valueWithDict, EXTRA_Public);
	}
	if (_blockInfo.pSymbol == NULL) return pEnvLocal.release();
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return NULL;
	if (pExprBlock == NULL) {
		// set nil value to the variable with a symbol specified by
		// _blockInfo.pSymbol
		pEnvLocal->AssignValue(_blockInfo.pSymbol, Value::Null, EXTRA_Public);
	} else if (_blockInfo.quoteFlag) {
		Object_expr *pObj = new Object_expr(env, Expr::Reference(pExprBlock));
		pEnvLocal->AssignValue(_blockInfo.pSymbol, Value(pObj), EXTRA_Public);
	} else {
		Environment *pEnv =
				(_blockInfo.blockScope == BLKSCOPE_Inside)? pEnvLocal.get() : &env;
		FunctionType funcType = (_blockInfo.blockScope == BLKSCOPE_SameAsFunc)?
											FUNCTYPE_Function : FUNCTYPE_Block;
		CustomFunction *pFuncBlock = CustomFunction::CreateBlockFunc(*pEnv, sig,
								_blockInfo.pSymbol, pExprBlock, funcType);
		if (pFuncBlock == NULL) return NULL;
		pEnvLocal->AssignFunction(pFuncBlock);
	}
	return pEnvLocal.release();
}

bool Function::CheckIfTrailer(const ICallable *pCallable) const
{
	return false;
}

Value Function::ReturnIterator(Environment &env, Signal sig,
								Args &args, Iterator *pIterator) const
{
	if (pIterator == NULL) return Value::Null;
	if (sig.IsSignalled()) {
		Iterator::Delete(pIterator);
		return Value::Null;
	}
	Value result;
	if (args.IsBlockSpecified()) {
		Environment envBlock(&env, ENVTYPE_block);
		const Function *pFuncBlock =
						args.GetBlockFunc(envBlock, sig, GetSymbolForBlock());
		if (pFuncBlock == NULL) return Value::Null;
		// :iter and :xiter must be effective here
		result = pIterator->Eval(envBlock, sig, args, pFuncBlock);
		Iterator::Delete(pIterator);
		if (sig.IsSignalled()) return Value::Null;
	} else if (args.IsRsltList() || args.IsRsltXList() ||
								args.IsRsltSet() || args.IsRsltXSet()) {
		result = pIterator->Eval(env, sig, args);
		Iterator::Delete(pIterator);
		if (sig.IsSignalled()) return Value::Null;
	} else {
		pIterator->SetSkipInvalidFlag(args.IsRsltXIterator());
		result = Value(env, pIterator);
	}
	return result;
}

Value Function::ReturnValue(Environment &env, Signal sig,
									Args &args, const Value &result) const
{
	if (!args.IsBlockSpecified()) return result;
	if (sig.IsSignalled()) return Value::Null;
	Environment envBlock(&env, ENVTYPE_block);
	const Function *pFuncBlock =
					args.GetBlockFunc(envBlock, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) return Value::Null;
	ValueList valListArg(result);
	Args argsSub(valListArg);
	Value value = pFuncBlock->Eval(env, sig, argsSub);
	if (sig.IsBreak() || sig.IsContinue()) {
		sig.ClearSignal();
	}
	return value;
}

Value Function::ReturnValue(Environment &env, Signal sig,
								Args &args, const ValueList &valListArg) const
{
	if (!args.IsBlockSpecified()) return valListArg.front();
	if (sig.IsSignalled()) return Value::Null;
	Environment envBlock(&env, ENVTYPE_block);
	const Function *pFuncBlock =
					args.GetBlockFunc(envBlock, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) return Value::Null;
	Args argsSub(valListArg);
	Value value = pFuncBlock->Eval(env, sig, argsSub);
	if (sig.IsBreak() || sig.IsContinue()) {
		sig.ClearSignal();
	}
	return value;
}

Value Function::DoRepeater(Environment &env, Signal sig,
								Args &args, Iterator *pIterator) const
{
	if (sig.IsSignalled()) {
		Iterator::Delete(pIterator);
		return Value::Null;
	}
	Value result;
	if (args.IsRsltIterator() || args.IsRsltXIterator()) {
		result = Value(env, pIterator);
	} else if (args.IsRsltList() || args.IsRsltXList() ||
									args.IsRsltSet() || args.IsRsltXSet()) {
		result = pIterator->Eval(env, sig, args);
		Iterator::Delete(pIterator);
		if (sig.IsSignalled()) return Value::Null;
	} else {
		while (pIterator->Next(env, sig, result)) ;
		Iterator::Delete(pIterator);
		if (sig.IsSignalled()) return Value::Null;
	}
	return result;
}

Expr *Function::DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const
{
	SetError_MathDiffError(sig);
	return NULL;
}

Expr *Function::DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const
{
	SetError_MathDiffError(sig);
	return NULL;
}

Expr *Function::OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const
{
	SetError_MathOptimizeError(sig);
	return NULL;
}

Expr *Function::OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const
{
	SetError_MathOptimizeError(sig);
	return NULL;
}

void Function::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1 && _envScope.GetFrameOwner().IsExist(pFrame)) {
		envSet.insert(&_envScope);
	}
}

String Function::ToString() const
{
	String str(GetName());
	if (GetSymbol()->IsFlowControlSymbol()) {
		str += " ";
	}
	str += "(";
	str += _declOwner.ToString();
	str += ")";
	if (_funcType == FUNCTYPE_Class) {
		str += ":";
		str += Gura_Symbol(static_)->GetName();
	} else if (_funcType == FUNCTYPE_Block) {
		str += ":";
		str += Gura_Symbol(block)->GetName();
	}
	if (GetMapFlag()) {
		str += ":";
		str += Gura_Symbol(map)->GetName();
	}
	if (GetFlatFlag()) {
		str += ":";
		str += Gura_Symbol(flat)->GetName();
	}
	if (GetDynamicScopeFlag()) {
		str += ":";
		str += Gura_Symbol(dynamic_scope)->GetName();
	}
	if (GetSymbolFuncFlag()) {
		str += ":";
		str += Gura_Symbol(symbol_func)->GetName();
	}
	if (GetLeaderFlag()) {
		str += ":";
		str += Gura_Symbol(leader)->GetName();
	}
	if (GetTrailerFlag()) {
		str += ":";
		str += Gura_Symbol(trailer)->GetName();
	}
	if (GetEndMarkerFlag()) {
		str += ":";
		str += Gura_Symbol(end_marker)->GetName();
	}
	if (GetPublicFlag()) {
		str += ":";
		str += Gura_Symbol(public_)->GetName();
	}
	if (GetPrivateFlag()) {
		str += ":";
		str += Gura_Symbol(end_marker)->GetName();
	}
	if (_resultMode == RSLTMODE_List) {
		str += ":";
		str += Gura_Symbol(list)->GetName();
	} else if (_resultMode == RSLTMODE_XList) {
		str += ":";
		str += Gura_Symbol(xlist)->GetName();
	} else if (_resultMode == RSLTMODE_Set) {
		str += ":";
		str += Gura_Symbol(set)->GetName();
	} else if (_resultMode == RSLTMODE_XSet) {
		str += ":";
		str += Gura_Symbol(xset)->GetName();
	} else if (_resultMode == RSLTMODE_Void) {
		str += ":";
		str += Gura_Symbol(void_)->GetName();
	} else if (_resultMode == RSLTMODE_Reduce) {
		str += ":";
		str += Gura_Symbol(reduce)->GetName();
	} else if (_resultMode == RSLTMODE_XReduce) {
		str += ":";
		str += Gura_Symbol(xreduce)->GetName();
	} else if (_resultMode == RSLTMODE_Iterator) {
		str += ":";
		str += Gura_Symbol(iter)->GetName();
	} else if (_resultMode == RSLTMODE_XIterator) {
		str += ":";
		str += Gura_Symbol(xiter)->GetName();
	}
	if (!_attrsOpt.empty()) {
		str += ":[";
		foreach_const (SymbolSet, ppSymbol, _attrsOpt) {
			const Symbol *pSymbol = *ppSymbol;
			if (ppSymbol != _attrsOpt.begin()) str += ",";
			str += pSymbol->GetName();
		}
		str += "]";
	}
	if (_blockInfo.pSymbol != NULL) {
		str += " {";
		if (_blockInfo.quoteFlag) str += "`";
		str += _blockInfo.pSymbol->GetName();
		str += GetOccurPatternSymbol(_blockInfo.occurPattern)->GetName();
		if (_blockInfo.blockScope == BLKSCOPE_Inside) {
			str += ":inside_scope";
		} else if (_blockInfo.blockScope == BLKSCOPE_SameAsFunc) {
			str += ":func_scope";
		}
		str += "}";
	}
	return str;
}

void Function::SetError_UnsupportedAttr(Signal sig, const SymbolSet &attrs) const
{
	String str;
	str += "function '";
	str += GetName();
	str += "' doesn't support attribute ";
	foreach_const (SymbolSet, ppSymbol, attrs) {
		if (ppSymbol != attrs.begin()) str += ", ";
		str += "'";
		str += (*ppSymbol)->GetName();
		str += "'";
	}
	sig.SetError(ERR_AttributeError, "%s", str.c_str());
}

void Function::SetError_DivideByZero(Signal sig) const
{
	sig.SetError(ERR_ZeroDivisionError, "divide by zero");
}

void Function::SetError_NotConstructor(Signal sig) const
{
	sig.SetError(ERR_ValueError, "'%s' is not a constructor", GetName());
}

void Function::SetError_ArgumentTypeByIndex(Signal sig, Args &args, size_t idxArg) const
{
	if (idxArg < _declOwner.size()) {
		const Declaration *pDecl = _declOwner[idxArg];
		pDecl->SetError_ArgumentType(sig, args.GetValue(idxArg));
	} else {
		sig.SetError(ERR_TypeError, "argument error");
	}
}

void Function::SetError_InvalidValue(Signal sig, const Value &value) const
{
	sig.SetError(ERR_TypeError, "can't evaluate %s(%s)",
				GetName(), value.ToString(sig).c_str());
}

void Function::SetError_InvalidValue(Signal sig, const Value &value1, const Value &value2) const
{
	sig.SetError(ERR_TypeError, "can't evaluate %s(%s, %s)",
				GetName(), value1.ToString(sig).c_str(), value2.GetTypeName());
}

void Function::SetError_InvalidValType(Signal sig, const Value &value) const
{
	sig.SetError(ERR_TypeError, "can't evaluate %s(%s)",
				GetName(), value.GetTypeName());
}

void Function::SetError_InvalidValType(Signal sig, const Value &value1, const Value &value2) const
{
	sig.SetError(ERR_TypeError, "can't evaluate %s(%s, %s)",
				GetName(), value1.GetTypeName(), value2.GetTypeName());
}

void Function::SetError_InvalidValTypeM(Signal sig, const Value &value1, const Value &value2) const
{
	sig.SetError(ERR_TypeError, "can't evaluate (%s %s %s)",
				value1.GetTypeName(), GetMathSymbol(), value2.GetTypeName());
}

void Function::SetError_InvalidFunctionExpression(Signal sig) const
{
	sig.SetError(ERR_SyntaxError, "invalid function expression");
}

void Function::SetError_MathDiffError(Signal sig) const
{
	sig.SetError(ERR_ValueError, "failed to generate a differential function");
}

void Function::SetError_MathOptimizeError(Signal sig) const
{
	sig.SetError(ERR_ValueError, "mathematical optimization is not supported");
}

//-----------------------------------------------------------------------------
// Function::ResultComposer
// this function's behaviour is affected by the following attributes.
//   :void, :reduce, :xreduce, :list, :xlist, :set, :xet, :flat
//-----------------------------------------------------------------------------
Function::ResultComposer::ResultComposer(Environment &env, Args &args, Value &result) :
	_env(env), _args(args), _result(result), _pValList(NULL), _cnt(0),
	_excludeNilFlag(args.IsRsltXList() || args.IsRsltXSet()),
	_setFlag(args.IsRsltSet() || args.IsRsltXSet())
{
	if (_args.IsRsltList() || _args.IsRsltXList() ||
							_args.IsRsltSet() || _args.IsRsltXSet()) {
		_pValList = &_result.InitAsList(_env);
	}
}

void Function::ResultComposer::Store(const Value &value)
{
	if (_args.IsRsltVoid()) {
		// nothing to do
	} else if (_args.IsRsltReduce()) {
		_result = value;
	} else if (_args.IsRsltXReduce()) {
		if (value.IsValid()) _result = value;
	} else if (_args.IsRsltFlat() && value.IsList()) {
		const ValueList &valList = value.GetList();
		foreach_const (ValueList, pValue, value.GetList()) {
			Store(*pValue);
		}
	} else {
		if (_args.IsRsltList()) {
			_pValList->push_back(value);
		} else if (value.IsValid()) {
			if (_pValList == NULL) {
				_pValList = &_result.InitAsList(_env, _cnt, Value::Null);
			}
			if (!_setFlag || !_pValList->IsContain(value)) {
				_pValList->push_back(value);
			}
		} else if (_excludeNilFlag) {
			// nothing to do
		} else if (_pValList != NULL) {
			if (!_setFlag || !_pValList->IsContain(value)) {
				_pValList->push_back(value);
			}
		}
		_cnt++;
	}
}

//-----------------------------------------------------------------------------
// CustomFunction
//-----------------------------------------------------------------------------
bool CustomFunction::IsCustom() const { return true; }

CustomFunction::CustomFunction(Environment &envScope,
				const Symbol *pSymbol, Expr *pExprBody, FunctionType funcType) :
		Function(envScope, pSymbol, funcType, FLAG_None), _pExprBody(pExprBody)
{
}

CustomFunction::~CustomFunction()
{
}

Value CustomFunction::DoEval(Environment &env, Signal sig, Args &args) const
{
	std::auto_ptr<Environment> pEnvLocal(PrepareEnvironment(env, sig, args));
	if (pEnvLocal.get() == NULL) return Value::Null;
	if (_funcType != FUNCTYPE_Block) {
		Value valueThis(args.GetThis());
		valueThis.AddFlags(VFLAG_Privileged);
		pEnvLocal->AssignValue(Gura_Symbol(this), valueThis, EXTRA_Public);
	}
	do {
		Object_args *pObjArgs = new Object_args(env, args);
		pEnvLocal->AssignValue(Gura_Symbol(__args__), Value(pObjArgs), EXTRA_Public);
	} while (0);
	EnvType envType = pEnvLocal->GetEnvType();
	Value result = GetExprBody()->Exec(*pEnvLocal, sig);
	if (envType == ENVTYPE_block) {
		// nothing to do. simply pass the signal to the outside.
	} else if (!sig.IsSignalled()) {
		// nothing to do
	} else if (sig.IsBreak()) {
		sig.ClearSignal();
	} else if (sig.IsContinue()) {
		sig.ClearSignal();
	} else if (sig.IsReturn()) {
		result = sig.GetValue();
		sig.ClearSignal();
	}
	return result;
}

Expr *CustomFunction::DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const
{
	SetError_MathDiffError(sig);
	return NULL;
}

CustomFunction *CustomFunction::CreateBlockFunc(Environment &env, Signal sig,
	const Symbol *pSymbol, const Expr_Block *pExprBlock, FunctionType funcType)
{
	const Expr_BlockParam *pExprBlockParam = pExprBlock->GetParam();
	AutoPtr<CustomFunction> pFunc(new CustomFunction(env,
							pSymbol, Expr::Reference(pExprBlock), funcType));
	pFunc->_declOwner.AllowTooManyArgs(true);
	Args args(pExprBlockParam->GetExprOwner());
	if (pExprBlockParam != NULL &&
			!pFunc->CustomDeclare(env, sig, SymbolSet::Null, args)) {
		return NULL;
	}
	return pFunc.release();
}

}
