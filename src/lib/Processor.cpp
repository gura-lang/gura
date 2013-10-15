#include "stdafx.h"

#define DBGPARSER(x)

namespace Gura {

//-----------------------------------------------------------------------------
// Sequence
//-----------------------------------------------------------------------------
Sequence::Sequence(Environment *pEnv) : _cntRef(1), _pEnv(pEnv), _doneFlag(false)
{
}

Sequence::~Sequence()
{
}

Value Sequence::Return(Signal sig, Sequence *pSequence)
{
	Value result;
	while (!pSequence->CheckDone()) {
		if (!pSequence->Step(sig, result)) {
			result = Value::Null;
			break;
		}
	}
	Sequence::Delete(pSequence);
	return result;
}

//-----------------------------------------------------------------------------
// Sequence_Root
//-----------------------------------------------------------------------------
Sequence_Root::Sequence_Root(Environment *pEnv, ExprOwner *pExprOwner) :
						Sequence(pEnv), _pExprOwner(pExprOwner), _idxExpr(0)
{
}

bool Sequence_Root::Step(Signal sig, Value &result)
{
	if (CheckDone()) return false;
	if (_idxExpr >= GetExprOwner().size()) {
		_doneFlag = true;
		return false;
	}
	Environment &env = *_pEnv;
	const Expr *pExpr = GetExprOwner()[_idxExpr++];
	//::printf("# %s\n", pExpr->ToString(Expr::SCRSTYLE_Brief).c_str());
	result = pExpr->Exec(env, sig);
	if (sig.IsError()) {
		sig.AddExprCause(pExpr);
		result = Value::Null;
		_doneFlag = true;
		return false;
	} else if (sig.IsTerminate()) {
		env.GetConsoleErr()->PrintSignal(sig, sig);
		sig.ClearSignal();
		result = Value::Null;
		_doneFlag = true;
		return false;
	} else if (sig.IsSignalled()) {
		env.GetConsoleErr()->PrintSignal(sig, sig);
		sig.ClearSignal();
	} else if (!env.GetGlobal()->GetEchoFlag()) {
		// nothing to do
	} else if (result.IsValid()) {
		env.GetConsole()->Println(sig, result.ToString(sig).c_str());
	}
	return true;
}

String Sequence_Root::ToString() const
{
	String str;
	str += "<sequence:root>";
	return str;
}

//-----------------------------------------------------------------------------
// Sequence_Expr
//-----------------------------------------------------------------------------
Sequence_Expr::Sequence_Expr(Environment *pEnv, ExprOwner *pExprOwner, bool evalSymFuncFlag) :
						Sequence(pEnv), _pExprOwner(pExprOwner), _idxExpr(0),
						_evalSymFuncFlag(evalSymFuncFlag)
{
}

bool Sequence_Expr::Step(Signal sig, Value &result)
{
	if (CheckDone()) return false;
	if (_idxExpr >= GetExprOwner().size()) {
		_doneFlag = true;
		return false;
	}
	Environment &env = *_pEnv;
	const Expr *pExpr = GetExprOwner()[_idxExpr++];
	result = pExpr->Exec(env, sig);
	if (sig.IsSignalled()) {
		sig.AddExprCause(pExpr);
		_doneFlag = true;
		return false;
	}
	if (_evalSymFuncFlag && result.IsFunction() &&
								result.GetFunction()->IsSymbolFunc()) {
		// symbol functions are only evaluated by a sequence of block.
		// in the folloiwng example, "return" shall be evaluated by a block
		// of "if" function.
		//   repeat { if (flag) { return } }
		// in the following example, "&&" operator returns "return" function
		// object as its result, and then the block of "repeat" shall evaluate it.
		//   repeat { flag && return }
		const Function *pFunc = result.GetFunction();
		AutoPtr<Args> pArgs(new Args());
		Value result = pFunc->Call(env, sig, *pArgs);
		if (sig.IsSignalled()) {
			sig.AddExprCause(pExpr);
			_doneFlag = true;
			return false;
		}
	}
	if (_idxExpr >= GetExprOwner().size()) _doneFlag = true;
	return true;
}

String Sequence_Expr::ToString() const
{
	String str;
	str += "<sequence:expr>";
	return str;
}

//-----------------------------------------------------------------------------
// Sequence_CustomFunction
//-----------------------------------------------------------------------------
Sequence_CustomFunction::Sequence_CustomFunction(Environment *pEnv, CustomFunction *pCustomFunction) :
			Sequence_Expr(pEnv, NULL, true), _pCustomFunction(pCustomFunction)
{
	const Expr *pExprBody = _pCustomFunction->GetExprBody();
	if (pExprBody == NULL) {
		_pExprOwner.reset(new ExprOwner());
	} else if (pExprBody->IsBlock()) {
		const Expr_Block *pExprBlock = dynamic_cast<const Expr_Block *>(pExprBody);
		_pExprOwner.reset(pExprBlock->GetExprOwner().Reference());
	} else {
		_pExprOwner.reset(new ExprOwner());
		_pExprOwner->push_back(pExprBody->Reference());
	}
}

bool Sequence_CustomFunction::Step(Signal sig, Value &result)
{
	Environment &env = *_pEnv;
	if (!Sequence_Expr::Step(sig, result)) return false;
	if (env.GetEnvType() == ENVTYPE_block) {
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
	return true;
}

String Sequence_CustomFunction::ToString() const
{
	String str;
	str += "<sequence:customfunction>";
	return str;
}

//-----------------------------------------------------------------------------
// Sequence_ExprForList
//-----------------------------------------------------------------------------
Sequence_ExprForList::Sequence_ExprForList(Environment *pEnv, ExprOwner *pExprOwner) :
						Sequence(pEnv), _pExprOwner(pExprOwner), _idxExpr(0)
{
	_pValList = &_value.InitAsList(*pEnv);
}

bool Sequence_ExprForList::Step(Signal sig, Value &result)
{
	if (CheckDone()) return false;
	if (_idxExpr >= GetExprOwner().size()) {
		_doneFlag = true;
		return false;
	}
	Environment &env = *_pEnv;
	const Expr *pExpr = GetExprOwner()[_idxExpr++];
	result = pExpr->Exec(env, sig);
	return true;
}

String Sequence_ExprForList::ToString() const
{
	String str;
	str += "<sequence:exprforlist>";
	return str;
}

//-----------------------------------------------------------------------------
// Sequence_Iterator
//-----------------------------------------------------------------------------
Sequence_Iterator::Sequence_Iterator(Environment *pEnv, Iterator *pIterator) :
									Sequence(pEnv), _pIterator(pIterator)
{
}

bool Sequence_Iterator::Step(Signal sig, Value &result)
{
	if (CheckDone()) return false;
	Environment &env = *_pEnv;
	if (!_pIterator->Next(env, sig, result)) {
		_doneFlag = true;
		return false;
	}
	return true;
}

String Sequence_Iterator::ToString() const
{
	String str;
	str += "<sequence:iterator>";
	return str;
}

//-----------------------------------------------------------------------------
// Sequence_Call
//-----------------------------------------------------------------------------
Sequence_Call::Sequence_Call(Environment *pEnv, Function *pFunc, Args &args) :
			Sequence(pEnv), _stat(STAT_Init),
			_pFunc(pFunc), _pArgs(new Args(args, ValueList::Null)),
			_stayDeclPointerFlag(false), _mapFlag(pFunc->GetMapFlag())
{
	_pArgs->SetValueDictArg(new ValueDict());
	_ppDecl = _pFunc->GetDeclOwner().begin();
	_ppExprArg = _pArgs->GetExprListArg().begin();
}

bool Sequence_Call::Step(Signal sig, Value &result)
{
	Environment &env = *_pEnv;
	ValueList &valListArg = _pArgs->GetValueListArg();
	ValueDict &valDictArg = _pArgs->GetValueDictArg();
	bool continueFlag = false;
	do {
	continueFlag = false;
	switch (_stat) {
	//-------------------------------------------------------------------------
	case STAT_Init: {
		if (_pFunc->GetType() == FUNCTYPE_Instance && _pArgs->GetThisObj() == NULL) {
			sig.SetError(ERR_ValueError,
				"object is expected as l-value of field");
			return false;
		} else if (_pFunc->GetType() == FUNCTYPE_Class &&
					_pArgs->GetThisClass() == NULL && _pArgs->GetThisObj() == NULL) {
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
		continueFlag = true;
		_stat = STAT_ExprArgs;
		break;
	}
	//-------------------------------------------------------------------------
	case STAT_ExprArgs: {
		if (_ppExprArg == _pArgs->GetExprListArg().end()) {
			continueFlag = true;
			_stat = STAT_OptArgs;
			break;
		}
		const Expr *pExprArg = *_ppExprArg++;
		bool quoteFlag = _ppDecl != _pFunc->GetDeclOwner().end() && (*_ppDecl)->IsQuote();
		if (!quoteFlag && pExprArg->IsOperatorPair()) {
			const Expr_BinaryOp *pExprBinaryOp =
							dynamic_cast<const Expr_BinaryOp *>(pExprArg);
			const Expr *pExprLeft = pExprBinaryOp->GetLeft()->Unquote();
			const Expr *pExprRight = pExprBinaryOp->GetRight();
			if (pExprLeft->IsSymbol()) {
				const Symbol *pSymbol = dynamic_cast<const Expr_Symbol *>(pExprLeft)->GetSymbol();
				_exprMap[pSymbol] = pExprRight->Reference();
			} else if (pExprLeft->IsValue() || pExprLeft->IsString()) {
				Sequence *pSequence = new Sequence_StoreDict(env.Reference(),
							dynamic_cast<Sequence_Call *>(Reference()),
							pExprLeft->Reference(), pExprRight->Reference());
				result = Sequence::Return(sig, pSequence);
			} else {
				pExprBinaryOp->SetError(sig, ERR_KeyError,
					"l-value of dictionary assignment must be a symbol or a constant value");
				return false;
			}
		} else if (!quoteFlag && Expr_Suffix::IsSuffixed(pExprArg, Gura_Symbol(Char_Mod))) {
			const Expr_Suffix *pExprSuffix = dynamic_cast<const Expr_Suffix *>(pExprArg);
			Sequence *pSequence = new Sequence_ExpandMod(env.Reference(),
						dynamic_cast<Sequence_Call *>(Reference()),
						pExprSuffix->GetChild()->Reference());
			result = Sequence::Return(sig, pSequence);
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
			} else if (pExprArg->IsSuffix()) {
				const Expr_Suffix *pExprSuffix = dynamic_cast<const Expr_Suffix *>(pExprArg);
				if (!pExprSuffix->GetSymbol()->IsIdentical(Gura_Symbol(Char_Mul))) {
					pExprArg->SetError(sig, ERR_SyntaxError, "invalid argument");
					return false;
				}
				Sequence *pSequence = new Sequence_ExpandMul(env.Reference(),
							dynamic_cast<Sequence_Call *>(Reference()),
							pExprSuffix->GetChild()->Reference());
				result = Sequence::Return(sig, pSequence);
			} else {
				Sequence *pSequence = new Sequence_ValListArg(env.Reference(),
							dynamic_cast<Sequence_Call *>(Reference()),
							pExprArg->Reference(), true);
				result = Sequence::Return(sig, pSequence);
			}
		} else if (_pFunc->GetDeclOwner().IsAllowTooManyArgs()) {
			continueFlag = true;
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
			continueFlag = true;
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
				continueFlag = true;
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
		} else if (pDecl->IsType(VTYPE_symbol)) {
			const Expr *pExpr = pExprArg.get();
			if (pExpr->IsQuote()) {
				pExpr = dynamic_cast<const Expr_Quote *>(pExpr)->GetChild();
			}
			if (!pExpr->IsSymbol()) {
				sig.SetError(ERR_TypeError, "symbol is expected");
				return false;
			}
			const Symbol *pSymbol =
						dynamic_cast<const Expr_Symbol *>(pExpr)->GetSymbol();
			value = Value(pSymbol);
			valListArg.push_back(value);
		} else {
			Sequence *pSequence = new Sequence_ValListArg(env.Reference(),
						dynamic_cast<Sequence_Call *>(Reference()),
						pExprArg->Reference(), false);
			result = Sequence::Return(sig, pSequence);
		}
		break;
	}
	//-------------------------------------------------------------------------
	case STAT_NamedArgs: {
		if (_pFunc->GetDeclOwner().GetSymbolDict() == NULL) {
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
			continueFlag = true;
			_stat = STAT_Exec;
			break;
		}
		if (_iterExprMap == _exprMap.end()) {
			continueFlag = true;
			_stat = STAT_Exec;
			break;
		}
		Sequence *pSequence = new Sequence_ValDictArg(env.Reference(),
					dynamic_cast<Sequence_Call *>(Reference()));
		result = Sequence::Return(sig, pSequence);
		break;
	}
	//-------------------------------------------------------------------------
	case STAT_Exec: {
		if (_mapFlag && _pFunc->GetDeclOwner().ShouldImplicitMap(*_pArgs)) {
			result = _pFunc->EvalMap(env, sig, *_pArgs);
		} else {
			result = _pFunc->Eval(env, sig, *_pArgs);
		}
		_doneFlag = true;
		break;
	}
	} } while (continueFlag);
	return !sig.IsSignalled();
}

String Sequence_Call::ToString() const
{
	String str;
	str += "<sequence:call>";
	return str;
}

void Sequence_Call::SkipDeclarations(size_t nSkipDecl)
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
// Sequence_Call::ExprMap
//-----------------------------------------------------------------------------
Sequence_Call::ExprMap::~ExprMap()
{
	foreach (ExprMap, iter, *this) {
		Expr *pExpr = iter->second;
		Expr::Delete(pExpr);
	}
}

//-----------------------------------------------------------------------------
// Sequence_Call::Sequence_StoreDict
//-----------------------------------------------------------------------------
bool Sequence_Call::Sequence_StoreDict::Step(Signal sig, Value &result)
{
	Environment &env = *_pEnv;
	ValueDict &valDictArg = _pSequenceCall->GetArgs()->GetValueDictArg();
	Value valueKey = _pExprLeft->IsValue()?
		dynamic_cast<const Expr_Value *>(_pExprLeft.get())->GetValue() :
		 Value(env, dynamic_cast<const Expr_String *>(_pExprLeft.get())->GetString());
	result = _pExprRight->Exec(env, sig);
	if (sig.IsSignalled()) return false;
	valDictArg[valueKey] = result;
	_doneFlag = true;
	return true;
}

String Sequence_Call::Sequence_StoreDict::ToString() const
{
	String str;
	str += "<sequence:call:storedict>";
	return str;
}

//-----------------------------------------------------------------------------
// Sequence_Call::Sequence_ExpandMod
//-----------------------------------------------------------------------------
bool Sequence_Call::Sequence_ExpandMod::Step(Signal sig, Value &result)
{
	Environment &env = *_pEnv;
	ValueDict &valDictArg = _pSequenceCall->GetArgs()->GetValueDictArg();
	ExprMap &exprMap = _pSequenceCall->GetExprMap();
	result = _pExprArg->Exec(env, sig);
	if (sig.IsSignalled()) return false;
	if (!result.IsDict()) {
		sig.SetError(ERR_ValueError, "modulo argument must take a dictionary");
		return false;
	}
	foreach_const (ValueDict, item, result.GetDict()) {
		const Value &valueKey = item->first;
		const Value &value = item->second;
		if (valueKey.IsSymbol()) {
			Expr *pExpr;
			if (value.IsExpr()) {
				pExpr = new Expr_Quote(Expr::Reference(value.GetExpr()));
			} else {
				pExpr = new Expr_Value(value);
			}
			exprMap[valueKey.GetSymbol()] = pExpr;
		} else {
			valDictArg.insert(*item);
		}
	}
	_doneFlag = true;
	return true;
}

String Sequence_Call::Sequence_ExpandMod::ToString() const
{
	String str;
	str += "<sequence:call:expandmod>";
	return str;
}

//-----------------------------------------------------------------------------
// Sequence_Call::Sequence_ExpandMul
//-----------------------------------------------------------------------------
bool Sequence_Call::Sequence_ExpandMul::Step(Signal sig, Value &result)
{
	Environment &env = *_pEnv;
	ValueList &valListArg = _pSequenceCall->GetArgs()->GetValueListArg();
	size_t nSkipDecl = 1;
	result = _pExprArg->Exec(env, sig);
	if (sig.IsSignalled()) {
		sig.AddExprCause(_pExprArg.get());
		return false;
	}
	if (result.IsList()) {
		const ValueList &valList = result.GetList();
		nSkipDecl = valList.size();
		foreach_const (ValueList, pValue, valList) {
			valListArg.push_back(*pValue);
		}
	} else {
		valListArg.push_back(result);
	}
	_pSequenceCall->SkipDeclarations(nSkipDecl);
	_doneFlag = true;
	return true;
}

String Sequence_Call::Sequence_ExpandMul::ToString() const
{
	String str;
	str += "<sequence:call:expandmul>";
	return str;
}

//-----------------------------------------------------------------------------
// Sequence_Call::Sequence_ValListArg
//-----------------------------------------------------------------------------
bool Sequence_Call::Sequence_ValListArg::Step(Signal sig, Value &result)
{
	Environment &env = *_pEnv;
	ValueList &valListArg = _pSequenceCall->GetArgs()->GetValueListArg();
	result = _pExprArg->Exec(env, sig);
	if (sig.IsSignalled()) return false;
	valListArg.push_back(result);
	if (_skipDeclFlag) _pSequenceCall->SkipDeclarations(1);
	_doneFlag = true;
	return true;
}

String Sequence_Call::Sequence_ValListArg::ToString() const
{
	String str;
	str += "<sequence:call:vallistarg>";
	return str;
}

//-----------------------------------------------------------------------------
// Sequence_Call::Sequence_ValDictArg
//-----------------------------------------------------------------------------
bool Sequence_Call::Sequence_ValDictArg::Step(Signal sig, Value &result)
{
	Environment &env = *_pEnv;
	ValueDict &valDictArg = _pSequenceCall->GetArgs()->GetValueDictArg();
	ExprMap::iterator iterExprMap = _pSequenceCall->NextIterExprMap();
	const Symbol *pSymbol = iterExprMap->first;
	const Expr *pExprArg = iterExprMap->second;
	Value value = pExprArg->Exec(env, sig);
	if (sig.IsSignalled()) return false;
	valDictArg[Value(pSymbol)] = value;
	_doneFlag = true;
	return true;
}

String Sequence_Call::Sequence_ValDictArg::ToString() const
{
	String str;
	str += "<sequence:call:valdictarg>";
	return str;
}

//-----------------------------------------------------------------------------
// SequenceStack
//-----------------------------------------------------------------------------
SequenceStack::~SequenceStack()
{
	Clear();
}

void SequenceStack::Clear()
{
	foreach (SequenceStack, ppSequence, *this) {
		Sequence *pSequence = *ppSequence;
		Sequence::Delete(pSequence);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Processor
//-----------------------------------------------------------------------------
Processor::Processor() : _cntRef(1)
{
}

bool Processor::Step(Signal sig, Value &result)
{
	if (CheckDone()) return true;
	Sequence *pSequence = _sequenceStack.back();
	pSequence->Step(sig, result);
	if (sig.IsSignalled()) return false;
	if (pSequence->CheckDone()) {
		Sequence::Delete(pSequence);
		_sequenceStack.pop_back();
	}
	if (result.IsSequence()) {
		_sequenceStack.push_back(result.GetSequence()->Reference());
		return true;
	}
	return true;
}

Value Processor::Run(Signal sig)
{
	Value result;
	while (!CheckDone()) {
		if (!Step(sig, result)) return Value::Null;
	}
	return result;
}

}
