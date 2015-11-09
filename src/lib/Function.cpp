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
	_pEnvScope(func.GetEnvScope().Clone()),
	_funcType(func._funcType),
	_pDeclOwner(func.GetDeclOwner().Clone()),
	_valTypeResult(func._valTypeResult),
	_resultMode(func._resultMode),
	_flags(func._flags),
	_pAttrsOptShared(func._pAttrsOptShared.IsNull()?
					 nullptr : new SymbolSetShared(*func._pAttrsOptShared)),
	_blockInfo(func._blockInfo),
	_pSymbolDict(func._pSymbolDict)
{
}

Function::Function(Environment &envScope, const Symbol *pSymbol,
				   FunctionType funcType, ULong flags) :
	_cntRef(1),
	_pSymbol(pSymbol),
	_pClassToConstruct(nullptr),
	_pEnvScope(Environment::Reference(&envScope)),
	_funcType(funcType),
	_pDeclOwner(new DeclarationOwner()),
	_valTypeResult(VTYPE_any),
	_resultMode(RSLTMODE_Normal),
	_flags(flags),
	_pAttrsOptShared(nullptr),
	_pSymbolDict(nullptr)
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
	if (::strcmp(GetName(), pClassToConstruct->GetName()) == 0) {
		_pClassToConstruct = pClassToConstruct;
		pClassToConstruct->SetConstructor(Function::Reference(this));
	} else {
		//::printf("%s %s\n", GetName(), pClassToConstruct->GetName());
	}
}

bool Function::CustomDeclare(Environment &env,
							 const CallerInfo &callerInfo, const SymbolSet &attrsAcceptable)
{
	Signal &sig = env.GetSignal();
	// declaration of arguments
	foreach_const (ExprList, ppExpr, callerInfo.GetExprListArg()) {
		const Expr *pExpr = *ppExpr;
		if (pExpr->IsUnaryOpSuffix()) {
			const Expr_UnaryOp *pExprUnaryOp =
									dynamic_cast<const Expr_UnaryOp *>(pExpr);
			const Symbol *pSymbol = pExprUnaryOp->GetOperator()->GetSymbol();
			if (pSymbol->IsIdentical(Symbol::Percnt)) {
				const Expr *pExprChild = pExprUnaryOp->GetChild();
				if (!pExprChild->IsIdentifier()) {
					sig.SetError(ERR_SyntaxError,
									"invalid expression for declaration");
					return false;
				}
				_pSymbolDict = dynamic_cast<const Expr_Identifier *>(pExprChild)->GetSymbol();
				continue;
			}
		}
		AutoPtr<Declaration> pDecl(Declaration::Create(env, pExpr));
		if (pDecl.IsNull()) return false;
		if (_pDeclOwner->IsVariableLength()) {
			sig.SetError(ERR_TypeError,
				"any parameters cannot follow after a parameter with variable length");
			return false;
		}
		if (pDecl->IsMandatory() && pDecl->GetExprDefault() == nullptr &&
				!_pDeclOwner->empty() && _pDeclOwner->back()->IsOptional()) {
			sig.SetError(ERR_TypeError,
				"mandatory parameters cannot follow after a parameter with variable length");
			return false;
		}
		_pDeclOwner->push_back(pDecl.release());
	}
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
		occurPattern = Symbol::ToOccurPattern(pExprUnaryOp->GetOperator()->GetSymbol());
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

void Function::CopyDeclarationInfo(const Function &func)
{
	_pDeclOwner.reset(func.GetDeclOwner().Clone());
	_valTypeResult = func._valTypeResult;
	_resultMode = func._resultMode;
	_flags = func._flags;
	_pAttrsOptShared.reset(func._pAttrsOptShared.IsNull()?
						   nullptr : new SymbolSetShared(*func._pAttrsOptShared));
	_blockInfo	= func._blockInfo;
	_pSymbolDict = func._pSymbolDict;
}

Declaration *Function::DeclareArg(Environment &env, const Symbol *pSymbol, ValueType valType,
				OccurPattern occurPattern, ULong flags, Expr *pExprDefault)
{
	Declaration *pDecl =
			new Declaration(pSymbol, valType, occurPattern, flags, pExprDefault);
	GURA_ASSUME(env, !_pDeclOwner->IsVariableLength());
	GURA_ASSUME(env, !(!(pDecl->IsOptional() || occurPattern == OCCUR_ZeroOrMore) &&
				!_pDeclOwner->empty() && _pDeclOwner->back()->IsOptional()));
	_pDeclOwner->push_back(pDecl);
	return pDecl;
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

Value Function::DoEval(Environment &env, Argument &arg) const
{
	return Value::Nil;
}

Value Function::EvalAuto(Environment &env, Argument &arg) const
{
	Argument::MapMode mapMode = arg.GetMapMode();
	if (mapMode == Argument::MAPMODE_None) return Eval(env, arg);
	AutoPtr<Iterator_ImplicitMap> pIterator(
		new Iterator_ImplicitMap(env.Clone(), arg.Reference(), false));
	if (arg.IsResultIterator() || arg.IsResultXIterator() ||
			(arg.IsResultNormal() && mapMode == Argument::MAPMODE_ToIter)) {
		pIterator->SetSkipInvalidFlag(arg.IsResultXIterator());
		return Value(new Object_iterator(env, pIterator.release()));
	}
	ResultComposer resultComposer(env, arg);
	if (!resultComposer.StoreValues(env, pIterator.get())) return Value::Nil;
	if (resultComposer.CountAdded() == 0 &&
			!arg.IsResultVoid() && !arg.IsResultReduce() && !arg.IsResultXReduce()) {
		Value valueResult;
		valueResult.InitAsList(env);
		return valueResult;
	}
	return resultComposer.GetValueResult();
}

Value Function::ReturnValue(Environment &env, Argument &arg, const Value &result) const
{
	Signal &sig = env.GetSignal();
	if (!arg.IsBlockSpecified()) return result;
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Environment> pEnvBlock(env.Derive(ENVTYPE_block));
	const Function *pFuncBlock =
					arg.GetBlockFunc(*pEnvBlock, GetSymbolForBlock());
	if (pFuncBlock == nullptr) return Value::Nil;
	AutoPtr<Argument> pArgSub(new Argument(pFuncBlock));
	if (!pArgSub->StoreValue(env, result)) return Value::Nil;
	Value value = pFuncBlock->Eval(env, *pArgSub);
	if (sig.IsBreak() || sig.IsContinue()) {
		sig.ClearSignal();
	}
	return value;
}

Value Function::ReturnValues(Environment &env, Argument &arg, const ValueList &valListArg) const
{
	Signal &sig = env.GetSignal();
	if (!arg.IsBlockSpecified()) return valListArg.front();
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Environment> pEnvBlock(env.Derive(ENVTYPE_block));
	const Function *pFuncBlock =
					arg.GetBlockFunc(*pEnvBlock, GetSymbolForBlock());
	if (pFuncBlock == nullptr) return Value::Nil;
	AutoPtr<Argument> pArgSub(new Argument(pFuncBlock));
	if (!pArgSub->StoreValues(env, valListArg)) return Value::Nil;
	Value value = pFuncBlock->Eval(env, *pArgSub);
	if (sig.IsBreak() || sig.IsContinue()) {
		sig.ClearSignal();
	}
	return value;
}

Value Function::ReturnIterator(Environment &env, Argument &arg, Iterator *pIterator) const
{
	Signal &sig = env.GetSignal();
	if (pIterator == nullptr) return Value::Nil;
	if (sig.IsSignalled()) {
		Iterator::Delete(pIterator);
		return Value::Nil;
	}
	Value result;
	if (!pIterator->IsRepeater()) {
		if (arg.IsBlockSpecified()) {
			AutoPtr<Environment> pEnvBlock(env.Derive(ENVTYPE_block));
			const Function *pFuncBlock =
								arg.GetBlockFunc(*pEnvBlock, GetSymbolForBlock());
			if (pFuncBlock == nullptr) return Value::Nil;
			bool genIterFlag = arg.IsResultIterator() || arg.IsResultXIterator();
			pIterator = new Iterator_Repeater(
				pEnvBlock->Reference(), Function::Reference(pFuncBlock),
				false, genIterFlag, pIterator);
		}
		bool skipInvalidFlag = arg.IsResultXList() || arg.IsResultXSet() || arg.IsResultXIterator();
		pIterator->SetSkipInvalidFlag(skipInvalidFlag);
	}
	if (arg.IsResultIterator() || arg.IsResultXIterator()) {
		result = Value(new Object_iterator(env, pIterator));
	} else if (arg.IsResultList() || arg.IsResultXList() ||
			   arg.IsResultSet() || arg.IsResultXSet()) {
		ResultComposer resultComposer(env, arg);
		resultComposer.StoreValues(env, pIterator);
		Iterator::Delete(pIterator);
		if (sig.IsSignalled()) return Value::Nil;
		result = resultComposer.GetValueResult();
	} else if (pIterator->IsRepeater()) {
		while (pIterator->Next(env, result)) ;
		Iterator::Delete(pIterator);
		if (sig.IsSignalled()) return Value::Nil;
	} else {
		result = Value(new Object_iterator(env, pIterator));
	}
	return result;
}

Expr_Caller *Function::GenerateSpecificExpr(
	Environment &env, Expr *pExprCar, Expr_Lister *pExprLister,
	Expr_Block *pExprBlock, const Expr_Caller *pExprLeader) const
{
	return nullptr;
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
	str += _pDeclOwner->ToString();
	if (_pSymbolDict != nullptr) {
		if (!_pDeclOwner->empty()) str += ", ";
		str += _pSymbolDict->GetName();
		str += (Symbol::Percnt)->GetName();
	}
	str += ")";
	if (_funcType == FUNCTYPE_Class) {
		str += ":";
		str += Gura_Symbol(static_)->GetName();
	} else if (_funcType == FUNCTYPE_Block) {
		str += ":";
		str += Gura_Symbol(block)->GetName();
	}
	str += Symbol::MakeAttrForFlags(_flags, 0);
	str += Symbol::MakeAttrForResultMode(_resultMode);
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
		const Symbol *pSymbol = Symbol::FromOccurPattern(_blockInfo.occurPattern);
		if (pSymbol != nullptr) str += pSymbol->GetName();
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

void Function::SetError_ArgumentTypeByIndex(Environment &env, Argument &arg, size_t idxArg) const
{
	if (idxArg < _pDeclOwner->size()) {
		const Declaration *pDecl = GetDeclOwner()[idxArg];
		pDecl->SetError_ArgumentType(env, arg.GetValue(idxArg));
	} else {
		env.SetError(ERR_TypeError, "argument error");
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
// ResultComposer
// this function's behaviour is affected by the following attributes.
//   :void, :reduce, :xreduce, :list, :xlist, :set, :xet, :flat
//-----------------------------------------------------------------------------
ResultComposer::ResultComposer(Environment &env, ValueType valTypeResult,
							   ResultMode resultMode, ULong flags) :
	_valTypeResult(valTypeResult), _resultMode(resultMode), _flags(flags),
	_pValList(nullptr), _cntAdded(0)
{
	Initialize(env);
}

ResultComposer::ResultComposer(Environment &env, const Function *pFunc) :
	_valTypeResult(pFunc->GetValueTypeResult()),
	_resultMode(pFunc->GetResultMode()), _flags(pFunc->GetFlags()),
	_pValList(nullptr), _cntAdded(0)
{
	Initialize(env);
}

ResultComposer::ResultComposer(Environment &env, Argument &arg) :
	_valTypeResult(arg.GetValueTypeResult()),
	_resultMode(arg.GetResultMode()), _flags(arg.GetFlags()),
	_pValList(nullptr), _cntAdded(0)
{
	Initialize(env);
}

bool ResultComposer::StoreValue(Environment &env, const Value &value)
{
	Signal &sig = env.GetSignal();
	if (_resultMode == RSLTMODE_Void) {
		// nothing to do
	} else if (_resultMode == RSLTMODE_Reduce) {
		_valueResult = value;
	} else if (_resultMode == RSLTMODE_XReduce) {
		if (value.IsValid()) _valueResult = value;
	} else if (GetFlag(FLAG_Flat) && value.Is_list()) {
		foreach_const (ValueList, pValue, value.GetList()) {
			if (!StoreValue(env, *pValue)) return false;
		}
	} else if (_resultMode == RSLTMODE_List) {
		_pValList->push_back(value);
	} else if (value.IsValid()) {
		if (_pValList == nullptr) {
			_pValList = &_valueResult.InitAsList(env, _cntAdded, Value::Nil);
		}
		if (!(_resultMode == RSLTMODE_Set || _resultMode == RSLTMODE_XSet) ||
			!_pValList->DoesContain(env, value)) {
			_pValList->push_back(value);
		}
		if (sig.IsSignalled()) return false;
	} else if (_resultMode == RSLTMODE_XList || _resultMode == RSLTMODE_XSet) {
		// nothing to do
	} else if (_pValList != nullptr) {
		if (!(_resultMode == RSLTMODE_Set || _resultMode == RSLTMODE_XSet) ||
			!_pValList->DoesContain(env, value)) {
			_pValList->push_back(value);
		}
		if (sig.IsSignalled()) return false;
	}
	_cntAdded++;
	return true;
}

bool ResultComposer::StoreValues(Environment &env, Iterator *pIterator)
{
	Signal &sig = env.GetSignal();
	if (pIterator->IsInfinite()) {
		Iterator::SetError_InfiniteNotAllowed(sig);
		return false;
	}
	Value value;
	while (pIterator->Next(env, value)) {
		if (!StoreValue(env, value)) return false;
	}
	return sig.IsNoSignalled();
}

}
