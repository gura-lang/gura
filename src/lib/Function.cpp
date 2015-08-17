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
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].funcType == funcType) return tbl[i].name;
	}
	return "unknown";
}

//-----------------------------------------------------------------------------
// Function
//-----------------------------------------------------------------------------
bool Function::IsCustom() const { return false; }
bool Function::IsConstructorOfStruct() const { return false; }

Function::Function(const Function &func) : _cntRef(1),
	_pSymbol(func._pSymbol), _pClassToConstruct(func._pClassToConstruct),
	_pEnvScope(new Environment(func.GetEnvScope())),
	_pDeclOwner(new DeclarationOwner(func.GetDeclOwner())),
	_funcType(func._funcType),
	_resultMode(func._resultMode), _flags(func._flags),
	_attrsOpt(func._attrsOpt), _blockInfo(func._blockInfo)
{
}

Function::Function(Environment &envScope, const Symbol *pSymbol,
								FunctionType funcType, ULong flags) :
	_cntRef(1),
	_pSymbol(pSymbol), _pClassToConstruct(nullptr),
	_pEnvScope(Environment::Reference(&envScope)), _pDeclOwner(new DeclarationOwner()),
	_funcType(funcType), _resultMode(RSLTMODE_Normal), _flags(flags)
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

bool Function::CustomDeclare(
	Environment &env, const ExprList &exprListArg, const Expr_Block *pExprBlock,
	const SymbolSet &attrs, const SymbolSet &attrsOpt, const SymbolSet &attrsAcceptable)
{
	Signal &sig = env.GetSignal();
	// delcaration of arguments
	if (!GetDeclOwner().Declare(env, exprListArg)) return false;
	// declaration of attributes
	foreach_const (SymbolSet, ppSymbol, attrs) {
		const Symbol *pSymbol = *ppSymbol;
		if (pSymbol->IsIdentical(Gura_Symbol(map))) {
			_flags |= FLAG_Map;
		} else if (pSymbol->IsIdentical(Gura_Symbol(nomap))) {
			_flags &= ~FLAG_Map;
		} else if (pSymbol->IsIdentical(Gura_Symbol(nonamed))) {
			_flags |= FLAG_NoNamed;
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
		} else if (pSymbol->IsIdentical(Gura_Symbol(finalizer))) {
			_flags |= FLAG_Finalizer;
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
	_attrsOpt = attrsOpt;
	// declaration of a block
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
	_attrsOpt	= func._attrsOpt;
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

#if 0
Value Function::Call(Environment &env, Args &args) const
{
	Signal &sig = env.GetSignal();
	Sequence *pSequence = new SequenceEx(env.Reference(), Reference(this), args);
	return Sequence::Return(sig, pSequence);
}
#else
Value Function::Call(Environment &env, Args &args) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Args> pArgs(new Args(args, ValueList::Empty));
	if (GetType() == FUNCTYPE_Instance &&
		!pArgs->GetThis().IsPrimitive() && pArgs->GetThisObj() == nullptr) {
		sig.SetError(ERR_ValueError,
					 "object is expected as l-value of field");
		return false;
	} else if (GetType() == FUNCTYPE_Class &&
			   pArgs->GetThis().GetClassItself() == nullptr && pArgs->GetThisObj() == nullptr) {
		sig.SetError(ERR_ValueError,
					 "class or object is expected as l-value of field");
		return false;
	}
	if (pArgs->IsBlockSpecified()) {
		if (GetBlockInfo().occurPattern == OCCUR_Zero) {
			sig.SetError(ERR_ValueError,
						 "block is unnecessary for '%s'", ToString().c_str());
			return false;
		}
	} else {
		if (GetBlockInfo().occurPattern == OCCUR_Once) {
			sig.SetError(ERR_ValueError,
						 "block must be specified for '%s'", ToString().c_str());
			return false;
		}
	}
	bool mapFlag = GetMapFlag();
	do {
		ULong flags = GetFlags();
		ResultMode resultMode = GetResultMode();
		foreach_const (SymbolSet, ppSymbol, pArgs->GetAttrs()) {
			const Symbol *pSymbol = *ppSymbol;
			if (pSymbol->IsIdentical(Gura_Symbol(map))) {
				mapFlag = true;
			} else if (pSymbol->IsIdentical(Gura_Symbol(nomap))) {
				mapFlag = false;
			} else if (pSymbol->IsIdentical(Gura_Symbol(nonamed))) {
				flags |= FLAG_NoNamed;
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
			} else if (GetAttrsOpt().IsSet(pSymbol)) {
				// nothing to do
			} else {
				sig.SetError(ERR_AttributeError,
							 "unsupported attribute '%s' for '%s'",
							 pSymbol->GetName(), ToString().c_str());
				return false;
			}
		}
		pArgs->SetResultMode(resultMode);
		pArgs->SetFlags(flags);
		pArgs->SetValueTypeResult(GetValueTypeResult());
	} while (0);
	Function::ExprMap exprMap;
	bool stayDeclPointerFlag = false;
	pArgs->SetValueDictArg(new ValueDict());
	ValueList &valListArg = pArgs->GetValueListArg();
	ValueDict &valDictArg = pArgs->GetValueDictArg();
	bool namedArgFlag = !pArgs->GetNoNamedFlag();
	foreach_const (ExprList, ppExprArg, pArgs->GetExprListArg()) {
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
				if (sig.IsSignalled()) return false;
				valDictArg[valueKey] = result;
			} else {
				pExprBinaryOp->SetError(sig, ERR_KeyError,
					"l-value of dictionary assignment must be an identifier or a constant value");
				return false;
			}
		} else if (Expr_UnaryOp::IsSuffixed(pExprArg, Gura_Symbol(Char_Mod))) {
			// func(..., value%, ...)
			const Expr_UnaryOp *pExprUnaryOp = dynamic_cast<const Expr_UnaryOp *>(pExprArg);
			Value result = pExprUnaryOp->GetChild()->Exec(env, nullptr);
			if (sig.IsSignalled()) return false;
			if (!result.Is_dict()) {
				sig.SetError(ERR_ValueError, "modulo argument must take a dictionary");
				return false;
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
					valDictArg.insert(*item);
				}
			}
		}
	}
	DeclarationOwner::const_iterator ppDecl = GetDeclOwner().begin();
	foreach_const (ExprList, ppExprArg, pArgs->GetExprListArg()) {
		const Expr *pExprArg = *ppExprArg;
		if ((namedArgFlag && pExprArg->IsBinaryOp(OPTYPE_Pair)) ||
			Expr_UnaryOp::IsSuffixed(pExprArg, Gura_Symbol(Char_Mod))) continue;
		if (ppDecl == GetDeclOwner().end()) {
			if (GetDeclOwner().IsAllowTooManyArgs()) break;
			Declaration::SetError_TooManyArguments(sig);
			return false;
		}
		if (exprMap.find((*ppDecl)->GetSymbol()) != exprMap.end()) {
			sig.SetError(ERR_ValueError, "argument confliction");
			return false;
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
			if (sig.IsSignalled()) return false;
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
			if (sig.IsSignalled()) return false;
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
				return false;
			}
		} else if ((*ppDecl)->IsQuote()) {
			valListArg.push_back(Value(new Object_expr(env, pExprArg->Reference())));
		} else {
			Value result = pExprArg->Exec(env, nullptr);
			if (sig.IsSignalled()) return false;
			valListArg.push_back(result);
		}
	}
	//-------------------------------------------------------------------------
	if (GetDeclOwner().GetSymbolDict() != nullptr) {
		foreach (Function::ExprMap, iterExprMap, exprMap) {
			const Symbol *pSymbol = iterExprMap->first;
			const Expr *pExprArg = iterExprMap->second;
			Value result = pExprArg->Exec(env, nullptr);
			if (sig.IsSignalled()) return false;
			valDictArg[Value(pSymbol)] = result;
		}
	} else if (!exprMap.empty()) {
		String str;
		str = "invalid argument named ";
		foreach_const (Function::ExprMap, iter, exprMap) {
			if (iter != exprMap.begin()) str += ", ";
			str += iter->first->GetName();
		}
		sig.SetError(ERR_ValueError, "%s", str.c_str());
		return false;
	}
	//-------------------------------------------------------------------------
	return (mapFlag && GetDeclOwner().ShouldImplicitMap(*pArgs))?
		EvalMap(env, *pArgs) : Eval(env, *pArgs);
}
#endif

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
				Value(new Object_dict(env, valDictArg.Reference())), EXTRA_Public);
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
	const Expr_Block *pExprBlock = args.GetBlock(env);
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
	if (GetFinalizerFlag()) {
		str += ":";
		str += Gura_Symbol(finalizer)->GetName();
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
		str += Gura_Symbol(private_)->GetName();
	}
	if (GetNoNamedFlag()) {
		str += ":";
		str += Gura_Symbol(nonamed)->GetName();
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
	} else if (_args.IsRsltFlat() && value.Is_list()) {
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

//-----------------------------------------------------------------------------
// Function::SequenceEx
//-----------------------------------------------------------------------------
Function::SequenceEx::SequenceEx(Environment *pEnv, Function *pFunc, Args &args) :
			Sequence(pEnv), _stat(STAT_Init),
			_pFunc(pFunc), _pArgs(new Args(args, ValueList::Empty)),
			_stayDeclPointerFlag(false), _mapFlag(pFunc->GetMapFlag())
{
	_pArgs->SetValueDictArg(new ValueDict());
	_ppDecl = _pFunc->GetDeclOwner().begin();
	_ppExprArg = _pArgs->GetExprListArg().begin();
}

bool Function::SequenceEx::DoStep(Signal &sig, Value &result)
{
	Environment &env = *_pEnv;
	ValueList &valListArg = _pArgs->GetValueListArg();
	Gura_BeginPushbackRegion();
	switch (_stat) {
	//-------------------------------------------------------------------------
	case STAT_Init: {
		if (_pFunc->GetType() == FUNCTYPE_Instance &&
				!_pArgs->GetThis().IsPrimitive() && _pArgs->GetThisObj() == nullptr) {
			sig.SetError(ERR_ValueError,
				"object is expected as l-value of field");
			return false;
		} else if (_pFunc->GetType() == FUNCTYPE_Class &&
				_pArgs->GetThis().GetClassItself() == nullptr && _pArgs->GetThisObj() == nullptr) {
			sig.SetError(ERR_ValueError,
				"class or object is expected as l-value of field");
			return false;
		}
		if (_pArgs->IsBlockSpecified()) {
			if (_pFunc->GetBlockInfo().occurPattern == OCCUR_Zero) {
				sig.SetError(ERR_ValueError,
					"block is unnecessary for '%s'", _pFunc->ToString().c_str());
				return false;
			}
		} else {
			if (_pFunc->GetBlockInfo().occurPattern == OCCUR_Once) {
				sig.SetError(ERR_ValueError,
					"block must be specified for '%s'", _pFunc->ToString().c_str());
				return false;
			}
		}
		ULong flags = _pFunc->GetFlags();
		ResultMode resultMode = _pFunc->GetResultMode();
		foreach_const (SymbolSet, ppSymbol, _pArgs->GetAttrs()) {
			const Symbol *pSymbol = *ppSymbol;
			if (pSymbol->IsIdentical(Gura_Symbol(map))) {
				_mapFlag = true;
			} else if (pSymbol->IsIdentical(Gura_Symbol(nomap))) {
				_mapFlag = false;
			} else if (pSymbol->IsIdentical(Gura_Symbol(nonamed))) {
				flags |= FLAG_NoNamed;
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
			} else if (_pFunc->GetAttrsOpt().IsSet(pSymbol)) {
				// nothing to do
			} else {
				sig.SetError(ERR_AttributeError,
					"unsupported attribute '%s' for '%s'",
											pSymbol->GetName(), ToString().c_str());
				return false;
			}
		}
		_pArgs->SetResultMode(resultMode);
		_pArgs->SetFlags(flags);
		_pArgs->SetValueTypeResult(_pFunc->GetValueTypeResult());
		Gura_Pushback();
		_stat = STAT_ExprArgs;
		//if (_pFunc->GetSymbol()->IsIdentical(Symbol::Add("scope"))) {
		//	_stat = STAT_Exec;
		//}
		break;
	}
	//-------------------------------------------------------------------------
	case STAT_ExprArgs: {
		if (_ppExprArg == _pArgs->GetExprListArg().end()) {
			Gura_Pushback();
			_stat = STAT_OptArgs;
			break;
		}
		const Expr *pExprArg = *_ppExprArg++;
		bool quoteFlag = _ppDecl != _pFunc->GetDeclOwner().end() && (*_ppDecl)->IsQuote();
		if (!quoteFlag && pExprArg->IsBinaryOp(OPTYPE_Pair)) {
			const Expr_BinaryOp *pExprBinaryOp =
							dynamic_cast<const Expr_BinaryOp *>(pExprArg);
			const Expr *pExprLeft = pExprBinaryOp->GetLeft()->Unquote();
			const Expr *pExprRight = pExprBinaryOp->GetRight();
			if (pExprLeft->IsIdentifier()) {
				const Symbol *pSymbol = dynamic_cast<const Expr_Identifier *>(pExprLeft)->GetSymbol();
				_exprMap[pSymbol] = pExprRight->Reference();
			} else if (pExprLeft->IsValue()) {
				Value valueKey = dynamic_cast<const Expr_Value *>(pExprLeft)->GetValue();
				AutoPtr<SeqPostHandler> pSeqPostHandler(new SeqPostHandler_StoreDict(
							env.Reference(), dynamic_cast<SequenceEx *>(Reference()),
							valueKey));
				result = pExprRight->Exec(env, pSeqPostHandler.release());
				if (sig.IsSignalled()) return false;
			} else {
				pExprBinaryOp->SetError(sig, ERR_KeyError,
					"l-value of dictionary assignment must be an identifier or a constant value");
				return false;
			}
		} else if (!quoteFlag && Expr_UnaryOp::IsSuffixed(pExprArg, Gura_Symbol(Char_Mod))) {
			const Expr_UnaryOp *pExprUnaryOp = dynamic_cast<const Expr_UnaryOp *>(pExprArg);
			AutoPtr<SeqPostHandler> pSeqPostHandler(new SeqPostHandler_ExpandMod(
					env.Reference(), dynamic_cast<SequenceEx *>(Reference())));
			result = pExprUnaryOp->GetChild()->Exec(env, pSeqPostHandler.release());
			if (sig.IsSignalled()) return false;
		} else if (_ppDecl != _pFunc->GetDeclOwner().end()) {
			const Declaration *pDecl = *_ppDecl;
			if (_exprMap.find(pDecl->GetSymbol()) != _exprMap.end()) {
				sig.SetError(ERR_ValueError, "argument confliction");
				return false;
			}
			if (quoteFlag) {
				Object_expr *pObj = new Object_expr(env, Expr::Reference(pExprArg));
				valListArg.push_back(Value(pObj));
				SkipDeclarations(1);
			} else if (Expr_UnaryOp::IsSuffixed(pExprArg, Gura_Symbol(Char_Mul))) {
				const Expr_UnaryOp *pExprUnaryOp = dynamic_cast<const Expr_UnaryOp *>(pExprArg);
				AutoPtr<SeqPostHandler> pSeqPostHandler(new SeqPostHandler_ExpandMul(
						env.Reference(), dynamic_cast<SequenceEx *>(Reference())));
				result = pExprUnaryOp->GetChild()->Exec(env, pSeqPostHandler.release());
				if (sig.IsSignalled()) return false;
			} else {
				AutoPtr<SeqPostHandler> pSeqPostHandler(new SeqPostHandler_ValListArg(
					env.Reference(), dynamic_cast<SequenceEx *>(Reference()), true));
				result = pExprArg->Exec(env, pSeqPostHandler.release());
				if (sig.IsSignalled()) return false;
			}
		} else if (_pFunc->GetDeclOwner().IsAllowTooManyArgs()) {
			Gura_Pushback();
			_stat = STAT_OptArgs;
			break;
		} else {
			Declaration::SetError_TooManyArguments(sig);
			return false;
		}
		break;
	}
	//-------------------------------------------------------------------------
	case STAT_OptArgs: {
		if (_stayDeclPointerFlag || _ppDecl == _pFunc->GetDeclOwner().end()) {
			_iterExprMap = _exprMap.begin();
			Gura_Pushback();
			_stat = STAT_NamedArgs;
			break;
		}
		const Declaration *pDecl = *_ppDecl++;
		AutoPtr<Expr> pExprArg(Expr::Reference(pDecl->GetExprDefault()));
		ExprMap::iterator iter = _exprMap.find(pDecl->GetSymbol());
		if (iter != _exprMap.end()) {
			_exprMap.erase(iter);
			pExprArg.reset(iter->second);
		}
		Value value;
		if (pExprArg.IsNull()) {
			if (pDecl->GetOccurPattern() == OCCUR_ZeroOrOnce) {
				value = Value::Undefined;
			} else if (pDecl->GetOccurPattern() == OCCUR_ZeroOrMore) {
				_iterExprMap = _exprMap.begin();
				Gura_Pushback();
				_stat = STAT_NamedArgs;
				break;
			} else {
				Declaration::SetError_NotEnoughArguments(sig);
				return false;
			}
			valListArg.push_back(value);
		} else if (pDecl->IsQuote()) {
			value = Value(new Object_expr(env, pExprArg->Reference()));
			valListArg.push_back(value);
		} else {
			AutoPtr<SeqPostHandler> pSeqPostHandler(new SeqPostHandler_ValListArg(
				env.Reference(), dynamic_cast<SequenceEx *>(Reference()), false));
			result = pExprArg->Exec(env, pSeqPostHandler.release());
			if (sig.IsSignalled()) return false;
		}
		break;
	}
	//-------------------------------------------------------------------------
	case STAT_NamedArgs: {
		if (_pFunc->GetDeclOwner().GetSymbolDict() == nullptr) {
			if (!_exprMap.empty()) {
				String str;
				str = "invalid argument named ";
				foreach_const (ExprMap, iter, _exprMap) {
					if (iter != _exprMap.begin()) str += ", ";
					str += iter->first->GetName();
				}
				sig.SetError(ERR_ValueError, "%s", str.c_str());
				return false;
			}
			Gura_Pushback();
			_stat = STAT_Exec;
			break;
		}
		if (_iterExprMap == _exprMap.end()) {
			Gura_Pushback();
			_stat = STAT_Exec;
			break;
		}
		const Symbol *pSymbol = _iterExprMap->first;
		const Expr *pExprArg = _iterExprMap->second;
		_iterExprMap++;
		AutoPtr<SeqPostHandler> pSeqPostHandler(new SeqPostHandler_ValDictArg(
				env.Reference(), dynamic_cast<SequenceEx *>(Reference()), pSymbol));
		result = pExprArg->Exec(env, pSeqPostHandler.release());
		if (sig.IsSignalled()) return false;
		break;
	}
	//-------------------------------------------------------------------------
	case STAT_Exec: {
		if (_mapFlag && _pFunc->GetDeclOwner().ShouldImplicitMap(*_pArgs)) {
			result = _pFunc->EvalMap(env, *_pArgs);
		} else {
			result = _pFunc->Eval(env, *_pArgs);
		}
		_doneFlag = true;
		break;
	}
	}
	Gura_EndPushbackRegion();
	return !sig.IsSignalled();
}

String Function::SequenceEx::ToString() const
{
	String str;
	str += "<sequence:call>";
	return str;
}

void Function::SequenceEx::SkipDeclarations(size_t nSkipDecl)
{
	for (size_t iSkipDecl = 0; iSkipDecl < nSkipDecl &&
				_ppDecl != _pFunc->GetDeclOwner().end(); iSkipDecl++) {
		const Declaration *pDecl = *_ppDecl;
		if (pDecl->IsVariableLength()) {
			_stayDeclPointerFlag = true;
			break;
		}
		_ppDecl++;
	}
}

//-----------------------------------------------------------------------------
// Function::SeqPostHandler_StoreDict
//-----------------------------------------------------------------------------
bool Function::SeqPostHandler_StoreDict::DoPost(Signal &sig, const Value &result)
{
	ValueDict &valDictArg = _pSequenceCall->GetArgs()->GetValueDictArg();
	valDictArg[_valueKey] = result;
	return true;
}

//-----------------------------------------------------------------------------
// Function::SeqPostHandler_ExpandMod
//-----------------------------------------------------------------------------
bool Function::SeqPostHandler_ExpandMod::DoPost(Signal &sig, const Value &result)
{
	ValueDict &valDictArg = _pSequenceCall->GetArgs()->GetValueDictArg();
	ExprMap &exprMap = _pSequenceCall->GetExprMap();
	if (sig.IsSignalled()) return false;
	if (!result.Is_dict()) {
		sig.SetError(ERR_ValueError, "modulo argument must take a dictionary");
		return false;
	}
	foreach_const (ValueDict, item, result.GetDict()) {
		const Value &valueKey = item->first;
		const Value &value = item->second;
		if (valueKey.Is_symbol()) {
			Expr *pExpr;
			if (value.Is_expr()) {
				pExpr = new Expr_Quote(Expr::Reference(value.GetExpr()));
			} else {
				pExpr = new Expr_Value(value);
			}
			exprMap[valueKey.GetSymbol()] = pExpr;
		} else {
			valDictArg.insert(*item);
		}
	}
	return true;
}

//-----------------------------------------------------------------------------
// Function::SeqPostHandler_ExpandMul
//-----------------------------------------------------------------------------
bool Function::SeqPostHandler_ExpandMul::DoPost(Signal &sig, const Value &result)
{
	do {
		ValueList &valListArg = _pSequenceCall->GetArgs()->GetValueListArg();
		size_t nSkipDecl = 1;
		if (result.Is_list()) {
			const ValueList &valList = result.GetList();
			nSkipDecl = valList.size();
			foreach_const (ValueList, pValue, valList) {
				valListArg.push_back(*pValue);
			}
		} else {
			valListArg.push_back(result);
		}
		_pSequenceCall->SkipDeclarations(nSkipDecl);
	} while (0);
	return true;
}

//-----------------------------------------------------------------------------
// Function::SeqPostHandler_ValListArg
//-----------------------------------------------------------------------------
bool Function::SeqPostHandler_ValListArg::DoPost(Signal &sig, const Value &result)
{
	ValueList &valListArg = _pSequenceCall->GetArgs()->GetValueListArg();
	valListArg.push_back(result);
	if (_skipDeclFlag) _pSequenceCall->SkipDeclarations(1);
	return true;
}

//-----------------------------------------------------------------------------
// Function::SeqPostHandler_ValDictArg
//-----------------------------------------------------------------------------
bool Function::SeqPostHandler_ValDictArg::DoPost(Signal &sig, const Value &result)
{
	ValueDict &valDictArg = _pSequenceCall->GetArgs()->GetValueDictArg();
	valDictArg[Value(_pSymbol)] = result;
	return true;
}

//-----------------------------------------------------------------------------
// Args
//-----------------------------------------------------------------------------
Args::~Args()
{
}

bool Args::ShouldGenerateIterator(const DeclarationList &declList) const
{
	if (IsThisIterator()) return true;
	ValueList::const_iterator pValue = _valListArg.begin();
	DeclarationList::const_iterator ppDecl = declList.begin();
	for ( ; pValue != _valListArg.end() && ppDecl != declList.end(); pValue++) {
		const Declaration *pDecl = *ppDecl;
		if (pValue->Is_iterator() &&
						pDecl->GetValueType() != VTYPE_iterator) return true;
		if (!pDecl->IsVariableLength()) ppDecl++;
	}
	return false;
}

const Expr_Block *Args::GetBlock(Environment &env) const
{
	Signal &sig = env.GetSignal();
	// check if the block parameter specifies a delegated block information
	// like "g() {|block|}"
	// scope problem remains: 2010.11.02
	const Expr_Block *pExprBlock = _pExprBlock.get();
	while (pExprBlock != nullptr) {
		const ExprOwner *pExprOwnerParam = pExprBlock->GetExprOwnerParam();
		if (pExprOwnerParam == nullptr || !pExprBlock->GetExprOwner().empty()) {
			break;
		}
		const ExprList &exprList = *pExprOwnerParam;
		if (exprList.size() != 1 || !exprList.front()->IsIdentifier()) {
			break;
		}
		const Expr_Identifier *pExprIdentifier =
							dynamic_cast<const Expr_Identifier *>(exprList.front());
		const Value *pValue = env.LookupValue(pExprIdentifier->GetSymbol(), ENVREF_Escalate);
		if (pValue == nullptr) {
			break;
		} else if (pValue->Is_expr()) {
			const Expr *pExpr = pValue->GetExpr();
			if (!pExpr->IsBlock()) {
				sig.SetError(ERR_ValueError, "invalid value for block delegation");
				return nullptr;
			}
			pExprBlock = dynamic_cast<const Expr_Block *>(pExpr);
		} else if (pValue->IsInvalid()) {
			return nullptr;
		} else {
			break;
		}
	}
	return pExprBlock;
}

// return nullptr without error if block is not specified
const Function *Args::GetBlockFunc(Environment &env, const Symbol *pSymbol)
{
	const Expr_Block *pExprBlock = GetBlock(env);
	if (pExprBlock == nullptr || pSymbol == nullptr) return nullptr;
	if (_pFuncBlock.IsNull()) {
		_pFuncBlock.reset(FunctionCustom::CreateBlockFunc(env,
										pSymbol, pExprBlock, FUNCTYPE_Block));
	}
	return _pFuncBlock.get();
}

//-----------------------------------------------------------------------------
// Callable
//-----------------------------------------------------------------------------
bool Callable::IsLeader() const
{
	return false;
}

bool Callable::IsTrailer() const
{
	return false;
}

bool Callable::IsFinalizer() const
{
	return false;
}

bool Callable::IsEndMarker() const
{
	return false;
}

OccurPattern Callable::GetBlockOccurPattern() const
{
	return OCCUR_Zero;
}

}
