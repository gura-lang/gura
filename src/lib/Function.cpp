//=============================================================================
// Function
//=============================================================================
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
	for (size_t i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].funcType == funcType) return tbl[i].name;
	}
	return "unknown";
}

//-----------------------------------------------------------------------------
// Function
//-----------------------------------------------------------------------------
bool Function::IsCustom() const { return false; }
bool Function::IsConstructorOfStruct() const { return false; }

Function::Function(const Function &func) :
	_cntRef(1),
	_pSymbol(func._pSymbol),
	_pClassToConstruct(func._pClassToConstruct),
	_pEnvScope(new Environment(func.GetEnvScope())),
	_pDeclOwner(new DeclarationOwner(func.GetDeclOwner())),
	_funcType(func._funcType),
	_resultMode(func._resultMode),
	_flags(func._flags),
	_pAttrsOptShared(func._pAttrsOptShared.IsNull()?
					 nullptr : new SymbolSetShared(*func._pAttrsOptShared)),
	_blockInfo(func._blockInfo)
{
}

Function::Function(Environment &envScope, const Symbol *pSymbol,
				   FunctionType funcType, ULong flags) :
	_cntRef(1),
	_pSymbol(pSymbol),
	_pClassToConstruct(nullptr),
	_pEnvScope(Environment::Reference(&envScope)),
	_pDeclOwner(new DeclarationOwner()),
	_funcType(funcType),
	_resultMode(RSLTMODE_Normal),
	_flags(flags),
	_pAttrsOptShared(nullptr)
{
	_blockInfo.occurPattern = OCCUR_Zero;
	_blockInfo.pSymbol = nullptr;
	_blockInfo.blockScope = BLKSCOPE_Through;
	_blockInfo.quoteFlag = false;
}

Function::~Function()
{
}

void Function::SetFuncAttr(ValueType valTypeResult, ResultMode resultMode, ULong flags)
{
	_valTypeResult = valTypeResult;
	_resultMode = resultMode;
	_flags |= flags;
}

void Function::SetClassToConstruct(Class *pClassToConstruct)
{
	_pClassToConstruct = pClassToConstruct;
	pClassToConstruct->SetConstructor(Function::Reference(this));
}

bool Function::CustomDeclare(Environment &env,
							 const CallerInfo &callerInfo, const SymbolSet &attrsAcceptable)
{
	Signal &sig = env.GetSignal();
	// declaration of arguments
	if (!GetDeclOwner().Declare(env, callerInfo)) return false;
	// declaration of attributes
	foreach_const (SymbolSet, ppSymbol, callerInfo.GetAttrs()) {
		const Symbol *pSymbol = *ppSymbol;
		if (!(pSymbol->IsIdentical(Gura_Symbol(static_)) || attrsAcceptable.IsSet(pSymbol))) {
			sig.SetError(ERR_AttributeError, "unsupported attribute '%s' for function declaration",
						 pSymbol->GetName());
			return false;
		}
	}
	_resultMode = callerInfo.ModifyResultMode(_resultMode);
	_flags = callerInfo.ModifyFlags(_flags);
	_valTypeResult = callerInfo.ModifyValueTypeResult(_valTypeResult);
	_pAttrsOptShared.reset(SymbolSetShared::Reference(callerInfo.GetAttrsOptShared()));
	// declaration of a block
	const Expr_Block *pExprBlock = callerInfo.GetBlock();
	if (pExprBlock == nullptr) return true;
	const ExprList &exprList = pExprBlock->GetExprOwner();
	if (exprList.size() != 1) {
		SetError_InvalidFunctionExpression(sig);
		return false;
	}
	const Expr *pExpr = exprList.front();
	OccurPattern occurPattern = OCCUR_Once;
	if (pExpr->IsUnaryOpSuffix()) {
		const Expr_UnaryOp *pExprUnaryOp = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		pExpr = pExprUnaryOp->GetChild();
		occurPattern = Declaration::SymbolToOccurPattern(
							pExprUnaryOp->GetOperator()->GetSymbol());
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
	if (!pExpr->IsIdentifier()) {
		sig.SetError(ERR_TypeError,
				"content of block in a function declaration must be an identifier");
		return false;
	}
	const Expr_Identifier *pExprIdentifier = dynamic_cast<const Expr_Identifier *>(pExpr);
	DeclareBlock(occurPattern, pExprIdentifier->GetSymbol(),
										BLKSCOPE_Through, quoteFlag);
	foreach_const (SymbolSet, ppSymbol, pExprIdentifier->GetAttrs()) {
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
	_pDeclOwner.reset(new DeclarationOwner(func.GetDeclOwner()));
	_resultMode	= func._resultMode;	// :list, :xlist, :set, :xset, :iter, :xiter, :void
	_flags		= func._flags;		// :map, :nomap, :nonamed, :flat, :noflat
	_pAttrsOptShared.reset(func._pAttrsOptShared.IsNull()?
						   nullptr : new SymbolSetShared(*func._pAttrsOptShared));
	_blockInfo	= func._blockInfo;
}

Declaration *Function::DeclareArg(Environment &env, const Symbol *pSymbol, ValueType valType,
				OccurPattern occurPattern, ULong flags, Expr *pExprDefault)
{
	return GetDeclOwner().Declare(env, pSymbol, valType, occurPattern, flags, pExprDefault);
}

void Function::DeclareBlock(OccurPattern occurPattern,
				const Symbol *pSymbol, BlockScope blockScope, bool quoteFlag)
{
	_blockInfo.occurPattern = occurPattern;
	_blockInfo.pSymbol =
			(occurPattern == OCCUR_Zero)? nullptr :
			(pSymbol == nullptr)? Gura_Symbol(block) : pSymbol;
	_blockInfo.blockScope = blockScope;
	_blockInfo.quoteFlag = quoteFlag;
}

void Function::AddHelp(Help *pHelp)
{
	_helpOwner.push_back(pHelp);
}

void Function::AddHelp(const Symbol *pSymbol, const String &formatName, const String &text)
{
	AddHelp(new Help(pSymbol, formatName, text));
}

void Function::LinkHelp(const Function *pFunc)
{
	_pFuncHelpLink.reset(Function::Reference(pFunc));
}

bool Function::LinkHelp(const Environment *pEnv, const Symbol *pSymbol)
{
	if (pEnv == nullptr) return false;
	const Function *pFunc = pEnv->LookupFunction(pSymbol, ENVREF_NoEscalate);
	if (pFunc == nullptr) return false;
	LinkHelp(pFunc);
	return true;
}

const Help *Function::GetHelp(const Symbol *pSymbol, bool defaultFirstFlag) const
{
	const Help *pHelp = _pFuncHelpLink.IsNull()?
		nullptr : _pFuncHelpLink->GetHelp(pSymbol, defaultFirstFlag);
	if (pHelp != nullptr) return pHelp;
	if (_helpOwner.empty()) return nullptr;
	if (pSymbol == nullptr) return _helpOwner.front();
	foreach_const (HelpOwner, ppHelp, _helpOwner) {
		Help *pHelp = *ppHelp;
		if (pHelp->GetSymbol() == pSymbol) return pHelp;
	}
	return defaultFirstFlag? _helpOwner.front() : nullptr;
}

Value Function::Call(
	Environment &env, const CallerInfo &callerInfo,
	const Value &valueThis, const Iterator *pIteratorThis, bool listThisFlag,
	const TrailCtrlHolder *pTrailCtrlHolder) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetBlock(Expr_Block::Reference(callerInfo.GetBlock()));
	pArgs->SetAttrsShared(SymbolSetShared::Reference(callerInfo.GetAttrsShared()));
	pArgs->SetAttrsOptShared(SymbolSetShared::Reference(callerInfo.GetAttrsOptShared()));
	pArgs->SetThis(valueThis);
	pArgs->SetIteratorThis(Iterator::Reference(pIteratorThis), listThisFlag);
	pArgs->SetTrailCtrlHolder(TrailCtrlHolder::Reference(pTrailCtrlHolder));
	if (GetType() == FUNCTYPE_Instance &&
			!pArgs->GetThis().IsPrimitive() && pArgs->GetThisObj() == nullptr) {
		sig.SetError(ERR_ValueError,
					 "object is expected as l-value of field");
		return Value::Nil;
	} else if (GetType() == FUNCTYPE_Class &&
		   pArgs->GetThis().GetClassItself() == nullptr && pArgs->GetThisObj() == nullptr) {
		sig.SetError(ERR_ValueError,
					 "class or object is expected as l-value of field");
		return Value::Nil;
	}
	if (pArgs->IsBlockSpecified()) {
		if (GetBlockInfo().occurPattern == OCCUR_Zero) {
			sig.SetError(ERR_ValueError,
						 "block is unnecessary for '%s'", ToString().c_str());
			return Value::Nil;
		}
	} else {
		if (GetBlockInfo().occurPattern == OCCUR_Once) {
			sig.SetError(ERR_ValueError,
						 "block must be specified for '%s'", ToString().c_str());
			return Value::Nil;
		}
	}
	foreach_const (SymbolSet, ppSymbol, pArgs->GetAttrs()) {
		const Symbol *pSymbol = *ppSymbol;
		if (!GetAttrsOpt().IsSet(pSymbol)) {
			sig.SetError(ERR_AttributeError, "unsupported attribute '%s' for '%s'",
						 pSymbol->GetName(), ToString().c_str());
			return Value::Nil;
		}
	}
	pArgs->SetResultMode(callerInfo.ModifyResultMode(GetResultMode()));
	pArgs->SetFlags(callerInfo.ModifyFlags(GetFlags()));
	pArgs->SetValueTypeResult(callerInfo.ModifyValueTypeResult(GetValueTypeResult()));
	Function::ExprMap exprMap;
	bool stayDeclPointerFlag = false;
	ValueList &valListArg = pArgs->GetValueListArg();
	ValueDict *pValDictArg = nullptr;
	bool namedArgFlag = !pArgs->GetNoNamedFlag();
	foreach_const (ExprList, ppExprArg, callerInfo.GetExprListArg()) {
		const Expr *pExprArg = *ppExprArg;
		if (namedArgFlag && pExprArg->IsBinaryOp(OPTYPE_Pair)) {
			// func(..., var => value, ...)
			const Expr_BinaryOp *pExprBinaryOp = dynamic_cast<const Expr_BinaryOp *>(pExprArg);
			const Expr *pExprLeft = pExprBinaryOp->GetLeft()->Unquote();
			const Expr *pExprRight = pExprBinaryOp->GetRight();
			if (pExprLeft->IsIdentifier()) {
				const Symbol *pSymbol = dynamic_cast<const Expr_Identifier *>(pExprLeft)->GetSymbol();
				exprMap[pSymbol] = pExprRight->Reference();
			} else if (pExprLeft->IsValue()) {
				const Value &valueKey = dynamic_cast<const Expr_Value *>(pExprLeft)->GetValue();
				Value result = pExprRight->Exec(env, nullptr);
				if (sig.IsSignalled()) return Value::Nil;
				if (pValDictArg == nullptr) pValDictArg = new ValueDict();
				(*pValDictArg)[valueKey] = result;
			} else {
				pExprBinaryOp->SetError(sig, ERR_KeyError,
					"l-value of dictionary assignment must be an identifier or a constant value");
				return Value::Nil;
			}
		} else if (Expr_UnaryOp::IsSuffixed(pExprArg, Gura_Symbol(Char_Mod))) {
			// func(..., value%, ...)
			const Expr_UnaryOp *pExprUnaryOp = dynamic_cast<const Expr_UnaryOp *>(pExprArg);
			Value result = pExprUnaryOp->GetChild()->Exec(env, nullptr);
			if (sig.IsSignalled()) return Value::Nil;
			if (!result.Is_dict()) {
				sig.SetError(ERR_ValueError, "modulo argument must take a dictionary");
				return Value::Nil;
			}
			foreach_const (ValueDict, item, result.GetDict()) {
				const Value &valueKey = item->first;
				const Value &value = item->second;
				if (valueKey.Is_symbol()) {
					Expr *pExpr = nullptr;
					if (value.Is_expr()) {
						pExpr = new Expr_Quote(Expr::Reference(value.GetExpr()));
					} else {
						pExpr = new Expr_Value(value);
					}
					exprMap[valueKey.GetSymbol()] = pExpr;
				} else {
					if (pValDictArg == nullptr) pValDictArg = new ValueDict();
					pValDictArg->insert(*item);
				}
			}
		}
	}
	DeclarationOwner::const_iterator ppDecl = GetDeclOwner().begin();
	foreach_const (ExprList, ppExprArg, callerInfo.GetExprListArg()) {
		const Expr *pExprArg = *ppExprArg;
		if ((namedArgFlag && pExprArg->IsBinaryOp(OPTYPE_Pair)) ||
			Expr_UnaryOp::IsSuffixed(pExprArg, Gura_Symbol(Char_Mod))) continue;
		if (ppDecl == GetDeclOwner().end()) {
			if (GetDeclOwner().IsAllowTooManyArgs()) break;
			Declaration::SetError_TooManyArguments(sig);
			return Value::Nil;
		}
		if (exprMap.find((*ppDecl)->GetSymbol()) != exprMap.end()) {
			sig.SetError(ERR_ValueError, "argument confliction");
			return Value::Nil;
		}
		if ((*ppDecl)->IsQuote()) {
			Object_expr *pObj = new Object_expr(env, Expr::Reference(pExprArg));
			valListArg.push_back(Value(pObj));
			if ((*ppDecl)->IsVariableLength()) {
				stayDeclPointerFlag = true;
			} else {
				ppDecl++;
			}
		} else if (Expr_UnaryOp::IsSuffixed(pExprArg, Gura_Symbol(Char_Mul))) {
			// func(..., value*, ...)
			const Expr_UnaryOp *pExprUnaryOp = dynamic_cast<const Expr_UnaryOp *>(pExprArg);
			Value result = pExprUnaryOp->GetChild()->Exec(env, nullptr);
			if (sig.IsSignalled()) return Value::Nil;
			if (result.Is_list()) {
				const ValueList &valList = result.GetList();
				foreach_const (ValueList, pValue, valList) {
					valListArg.push_back(*pValue);
					if ((*ppDecl)->IsVariableLength()) {
						stayDeclPointerFlag = true;
					} else {
						ppDecl++;
					}
				}
			} else {
				valListArg.push_back(result);
				if ((*ppDecl)->IsVariableLength()) {
					stayDeclPointerFlag = true;
				} else {
					ppDecl++;
				}
			}
		} else {
			// func(..., value, ...)
			Value result = pExprArg->Exec(env, nullptr);
			if (sig.IsSignalled()) return Value::Nil;
			valListArg.push_back(result);
			if ((*ppDecl)->IsVariableLength()) {
				stayDeclPointerFlag = true;
			} else {
				ppDecl++;
			}
		}
	}
	//-------------------------------------------------------------------------
	for ( ; !stayDeclPointerFlag && ppDecl != GetDeclOwner().end(); ppDecl++) {
		const Expr *pExprArg = (*ppDecl)->GetExprDefault();
		Function::ExprMap::iterator iter = exprMap.find((*ppDecl)->GetSymbol());
		if (iter != exprMap.end()) {
			pExprArg = iter->second;
			exprMap.erase(iter);
		}
		if (pExprArg == nullptr) {
			if ((*ppDecl)->GetOccurPattern() == OCCUR_ZeroOrOnce) {
				valListArg.push_back(Value::Undefined);
			} else if ((*ppDecl)->GetOccurPattern() == OCCUR_ZeroOrMore) {
				break;
			} else {
				Declaration::SetError_NotEnoughArguments(sig);
				return Value::Nil;
			}
		} else if ((*ppDecl)->IsQuote()) {
			valListArg.push_back(Value(new Object_expr(env, pExprArg->Reference())));
		} else {
			Value result = pExprArg->Exec(env, nullptr);
			if (sig.IsSignalled()) return Value::Nil;
			valListArg.push_back(result);
		}
	}
	//-------------------------------------------------------------------------
	if (exprMap.empty()) {
		// nothing to do
	} else if (GetDeclOwner().GetSymbolDict() == nullptr) {
		String str;
		str = "invalid argument named ";
		foreach_const (Function::ExprMap, iter, exprMap) {
			if (iter != exprMap.begin()) str += ", ";
			str += iter->first->GetName();
		}
		sig.SetError(ERR_ValueError, "%s", str.c_str());
		return Value::Nil;
	} else {
		if (pValDictArg == nullptr) pValDictArg = new ValueDict();
		foreach (Function::ExprMap, iterExprMap, exprMap) {
			const Symbol *pSymbol = iterExprMap->first;
			const Expr *pExprArg = iterExprMap->second;
			Value result = pExprArg->Exec(env, nullptr);
			if (sig.IsSignalled()) return Value::Nil;
			(*pValDictArg)[Value(pSymbol)] = result;
		}
	}
	//-------------------------------------------------------------------------
	pArgs->SetValueDictArg(pValDictArg);
	return (pArgs->GetMapFlag() && GetDeclOwner().ShouldImplicitMap(*pArgs))?
		EvalMap(env, *pArgs) : Eval(env, *pArgs);
}

Environment *Function::PrepareEnvironment(Environment &env, Args &args, bool thisAssignFlag) const
{
	Signal &sig = env.GetSignal();
	EnvType envType = (_funcType == FUNCTYPE_Block)? ENVTYPE_block : ENVTYPE_local;
	Environment *pEnvOuter = GetDynamicScopeFlag()?
							&env : const_cast<Environment *>(_pEnvScope.get());
	AutoPtr<Environment> pEnvLocal(new Environment(pEnvOuter, envType));
	if (thisAssignFlag) {
		Value valueThis(args.GetThis());
		valueThis.AddFlags(VFLAG_Privileged);
		pEnvLocal->AssignValue(Gura_Symbol(this_), valueThis, EXTRA_Public);
	}
	const ValueList &valListArg = args.GetValueListArg();
	ValueList::const_iterator pValue = valListArg.begin();
	DeclarationList::const_iterator ppDecl = GetDeclOwner().begin();
	for ( ; pValue != valListArg.end() && ppDecl != GetDeclOwner().end();
														pValue++, ppDecl++) {
		pEnvLocal->AssignValue((*ppDecl)->GetSymbol(), *pValue, EXTRA_Public);
	}
	if (GetDeclOwner().GetSymbolDict() != nullptr) {
		const ValueDict &valDictArg = args.GetValueDictArg();
		pEnvLocal->AssignValue(GetDeclOwner().GetSymbolDict(),
			   Value(new Object_dict(env, valDictArg.Reference(), false)), EXTRA_Public);
	}
	const ValueMap *pValMapHiddenArg = args.GetValueMapHiddenArg();
	if (pValMapHiddenArg != nullptr) {
		foreach_const (ValueMap, iter, *pValMapHiddenArg) {
			const Symbol *pSymbol = iter->first;
			const ValueEx &value = iter->second;
			pEnvLocal->AssignValue(pSymbol, value, EXTRA_Public);
		}
	}
	pEnvLocal->AssignValue(Gura_Symbol(__args__),
				Value(new Object_args(env, args.Reference())), EXTRA_Public);
	if (_blockInfo.pSymbol == nullptr) return pEnvLocal.release();
	const Expr_Block *pExprBlock = args.GetBlockCooked(env);
	if (sig.IsSignalled()) return nullptr;
	if (pExprBlock == nullptr) {
		// set nil value to the variable with a symbol specified by
		// _blockInfo.pSymbol
		pEnvLocal->AssignValue(_blockInfo.pSymbol, Value::Nil, EXTRA_Public);
	} else if (_blockInfo.quoteFlag) {
		Object_expr *pObj = new Object_expr(env, Expr::Reference(pExprBlock));
		pEnvLocal->AssignValue(_blockInfo.pSymbol, Value(pObj), EXTRA_Public);
	} else {
		Environment *pEnv =
			(_blockInfo.blockScope == BLKSCOPE_Inside)? pEnvLocal.get() : &env;
		FunctionType funcType = (_blockInfo.blockScope == BLKSCOPE_SameAsFunc)?
			FUNCTYPE_Function : FUNCTYPE_Block;
		FunctionCustom *pFuncBlock = FunctionCustom::CreateBlockFunc(
			*pEnv, _blockInfo.pSymbol, pExprBlock, funcType);
		if (pFuncBlock == nullptr) return nullptr;
		pEnvLocal->AssignFunction(pFuncBlock);
	}
	return pEnvLocal.release();
}

Value Function::Eval(Environment &env, Args &args) const
{
	ValueList valListCasted;
	if (!GetDeclOwner().ValidateAndCast(env, args.GetValueListArg(), valListCasted)) {
		return Value::Nil;
	}
	AutoPtr<Args> pArgsCasted(new Args(args, valListCasted));
	Value value = DoEval(env, *pArgsCasted);
	if (args.IsRsltVoid()) return Value::Undefined;
	return value;
}

Value Function::EvalMap(Environment &env, Args &args) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Iterator_ImplicitMap> pIterator(new Iterator_ImplicitMap(
				new Environment(env),
				Function::Reference(this), args.Reference(), false));
	if (sig.IsSignalled()) return Value::Nil;
	if (args.IsRsltIterator() || args.IsRsltXIterator() ||
			 (args.IsRsltNormal() && args.ShouldGenerateIterator(GetDeclOwner()))) {
		pIterator->SetSkipInvalidFlag(args.IsRsltXIterator());
		return Value(new Object_iterator(env, pIterator.release()));
	}
	Value result;
	ResultComposer resultComposer(env, args, result);
	Value value;
	size_t n = 0;
	for ( ; pIterator->Next(env, value); n++) {
		if (!resultComposer.Store(env, value)) return Value::Nil;
	}
	if (n == 0 && !args.IsRsltVoid() && !args.IsRsltReduce() && !args.IsRsltXReduce()) {
		result.InitAsList(env);
	}
	return result;
}

Value Function::ReturnValue(Environment &env, Args &args, const Value &result) const
{
	Signal &sig = env.GetSignal();
	if (!args.IsBlockSpecified()) return result;
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
					args.GetBlockFunc(*pEnvBlock, GetSymbolForBlock());
	if (pFuncBlock == nullptr) return Value::Nil;
	AutoPtr<Args> pArgsSub(new Args());
	pArgsSub->SetValue(result);
	Value value = pFuncBlock->Eval(env, *pArgsSub);
	if (sig.IsBreak() || sig.IsContinue()) {
		sig.ClearSignal();
	}
	return value;
}

Value Function::ReturnValues(Environment &env, Args &args, const ValueList &valListArg) const
{
	Signal &sig = env.GetSignal();
	if (!args.IsBlockSpecified()) return valListArg.front();
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
					args.GetBlockFunc(*pEnvBlock, GetSymbolForBlock());
	if (pFuncBlock == nullptr) return Value::Nil;
	AutoPtr<Args> pArgsSub(new Args());
	pArgsSub->SetValueListArg(valListArg);
	Value value = pFuncBlock->Eval(env, *pArgsSub);
	if (sig.IsBreak() || sig.IsContinue()) {
		sig.ClearSignal();
	}
	return value;
}

Value Function::ReturnIterator(Environment &env, Args &args, Iterator *pIterator) const
{
	Signal &sig = env.GetSignal();
	if (pIterator == nullptr) return Value::Nil;
	if (sig.IsSignalled()) {
		Iterator::Delete(pIterator);
		return Value::Nil;
	}
	Value result;
	if (!pIterator->IsRepeater()) {
		if (args.IsBlockSpecified()) {
			AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
			const Function *pFuncBlock =
								args.GetBlockFunc(*pEnvBlock, GetSymbolForBlock());
			if (pFuncBlock == nullptr) return Value::Nil;
			bool genIterFlag = args.IsRsltIterator() || args.IsRsltXIterator();
			pIterator = new Iterator_Repeater(pEnvBlock->Reference(), Function::Reference(pFuncBlock),
								false, genIterFlag, pIterator);
		}
		bool skipInvalidFlag = args.IsRsltXList() || args.IsRsltXSet() || args.IsRsltXIterator();
		pIterator->SetSkipInvalidFlag(skipInvalidFlag);
	}
	if (args.IsRsltIterator() || args.IsRsltXIterator()) {
		result = Value(new Object_iterator(env, pIterator));
	} else if (args.IsRsltList() || args.IsRsltXList() ||
									args.IsRsltSet() || args.IsRsltXSet()) {
		result = pIterator->Eval(env, args);
		Iterator::Delete(pIterator);
		if (sig.IsSignalled()) return Value::Nil;
	} else if (pIterator->IsRepeater()) {
		while (pIterator->Next(env, result)) ;
		Iterator::Delete(pIterator);
		if (sig.IsSignalled()) return Value::Nil;
	} else {
		result = Value(new Object_iterator(env, pIterator));
	}
	return result;
}

Expr *Function::MathDiff(Environment &env, const Expr *pExprArg, const Symbol *pSymbol) const
{
	Signal &sig = env.GetSignal();
	SetError_MathDiffError(sig);
	return nullptr;
}

Expr *Function::MathOptimize(Environment &env, Expr *pExprOpt) const
{
	Signal &sig = env.GetSignal();
	SetError_MathOptimizeError(sig);
	return nullptr;
}

void Function::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1 && _pEnvScope->GetFrameOwner().DoesExist(pFrame)) {
		envSet.insert(_pEnvScope.get());
	}
}

String Function::MakeFullName() const
{
	String str;
	if (_pEnvScope->IsModule()) {
		const Module *pModule = dynamic_cast<const Module *>(_pEnvScope.get());
		str += pModule->GetName();
		str += ".";
	} else if (_pEnvScope->IsClass()) {
		const Class *pClass = dynamic_cast<const Class *>(_pEnvScope.get());
		str += pClass->MakeValueTypeName();
		str += (GetType() == FUNCTYPE_Instance)? "#" : ".";
	} else if (_pEnvScope->IsObject()) {
		const Object *pObject = dynamic_cast<const Object *>(_pEnvScope.get());
		const Class *pClass = pObject->GetClass();
		str += pClass->MakeValueTypeName();
		str += "#";
	}
	str += GetName();
	return str;
}

String Function::ToString() const
{
	String str(MakeFullName());
	if (GetSymbol()->IsFlowControlSymbol()) {
		str += " ";
	}
	str += "(";
	str += GetDeclOwner().ToString();
	str += ")";
	if (_funcType == FUNCTYPE_Class) {
		str += ":";
		str += Gura_Symbol(static_)->GetName();
	} else if (_funcType == FUNCTYPE_Block) {
		str += ":";
		str += Gura_Symbol(block)->GetName();
	}
	str += CallerInfo::MakeAttrForFlags(_flags, 0);
	str += CallerInfo::MakeAttrForResultMode(_resultMode);
	if (!GetAttrsOpt().empty()) {
		str += ":[";
		foreach_const (SymbolSet, ppSymbol, GetAttrsOpt()) {
			const Symbol *pSymbol = *ppSymbol;
			if (ppSymbol != GetAttrsOpt().begin()) str += ",";
			str += pSymbol->GetName();
		}
		str += "]";
	}
	if (_blockInfo.pSymbol != nullptr) {
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

void Function::SetError_UnsupportedAttr(Signal &sig, const SymbolSet &attrs) const
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

void Function::SetError_DivideByZero(Signal &sig) const
{
	sig.SetError(ERR_ZeroDivisionError, "divide by zero");
}

void Function::SetError_NotConstructor(Signal &sig) const
{
	sig.SetError(ERR_ValueError, "'%s' is not a constructor", GetName());
}

void Function::SetError_ArgumentTypeByIndex(Signal &sig, Args &args, size_t idxArg) const
{
	if (idxArg < GetDeclOwner().size()) {
		const Declaration *pDecl = GetDeclOwner()[idxArg];
		pDecl->SetError_ArgumentType(sig, args.GetValue(idxArg));
	} else {
		sig.SetError(ERR_TypeError, "argument error");
	}
}

void Function::SetError_InvalidValue(Signal &sig, const Value &value) const
{
	sig.SetError(ERR_TypeError, "can't evaluate %s(%s)",
				GetName(), value.ToString().c_str());
}

void Function::SetError_InvalidValue(Signal &sig, const Value &value1, const Value &value2) const
{
	sig.SetError(ERR_TypeError, "can't evaluate %s(%s, %s)",
				GetName(), value1.ToString().c_str(), value2.MakeValueTypeName().c_str());
}

void Function::SetError_InvalidValType(Signal &sig, const Value &value) const
{
	sig.SetError(ERR_TypeError, "can't evaluate %s(%s)",
				GetName(), value.MakeValueTypeName().c_str());
}

void Function::SetError_InvalidValType(Signal &sig, const Value &value1, const Value &value2) const
{
	sig.SetError(ERR_TypeError, "can't evaluate %s(%s, %s)",
				GetName(), value1.MakeValueTypeName().c_str(), value2.MakeValueTypeName().c_str());
}

void Function::SetError_InvalidFunctionExpression(Signal &sig) const
{
	sig.SetError(ERR_SyntaxError, "invalid function expression");
}

void Function::SetError_MathDiffError(Signal &sig) const
{
	sig.SetError(ERR_ValueError, "failed to generate a differential function");
}

void Function::SetError_MathOptimizeError(Signal &sig) const
{
	sig.SetError(ERR_ValueError, "mathematical optimization is not supported");
}

//-----------------------------------------------------------------------------
// Function::ResultComposer
// this function's behaviour is affected by the following attributes.
//   :void, :reduce, :xreduce, :list, :xlist, :set, :xet, :flat
//-----------------------------------------------------------------------------
Function::ResultComposer::ResultComposer(Environment &env, Args &args, Value &result) :
	_args(args), _result(result), _pValList(nullptr), _cnt(0),
	_excludeNilFlag(args.IsRsltXList() || args.IsRsltXSet()),
	_setFlag(args.IsRsltSet() || args.IsRsltXSet())
{
	if (_args.IsRsltList() || _args.IsRsltXList() ||
							_args.IsRsltSet() || _args.IsRsltXSet()) {
		_pValList = &_result.InitAsList(env);
	}
}

bool Function::ResultComposer::Store(Environment &env, const Value &value)
{
	Signal &sig = env.GetSignal();
	if (_args.IsRsltVoid()) {
		// nothing to do
	} else if (_args.IsRsltReduce()) {
		_result = value;
	} else if (_args.IsRsltXReduce()) {
		if (value.IsValid()) _result = value;
	} else if (_args.GetFlatFlag() && value.Is_list()) {
		foreach_const (ValueList, pValue, value.GetList()) {
			if (!Store(env, *pValue)) return false;
		}
	} else {
		if (_args.IsRsltList()) {
			_pValList->push_back(value);
		} else if (value.IsValid()) {
			if (_pValList == nullptr) {
				_pValList = &_result.InitAsList(env, _cnt, Value::Nil);
			}
			if (!_setFlag || !_pValList->DoesContain(env, value)) {
				_pValList->push_back(value);
			}
			if (sig.IsSignalled()) return false;
		} else if (_excludeNilFlag) {
			// nothing to do
		} else if (_pValList != nullptr) {
			if (!_setFlag || !_pValList->DoesContain(env, value)) {
				_pValList->push_back(value);
			}
			if (sig.IsSignalled()) return false;
		}
		_cnt++;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Function::ExprMap
//-----------------------------------------------------------------------------
Function::ExprMap::~ExprMap()
{
	foreach (ExprMap, iter, *this) {
		Expr *pExpr = iter->second;
		Expr::Delete(pExpr);
	}
}

}
