//=============================================================================
// Argument
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Argument
//-----------------------------------------------------------------------------
Argument::Argument(const Function *pFunc) :
	_cntRef(1),
	_pFunc(pFunc->Reference()),
	_valTypeResult(pFunc->GetValueTypeResult()),
	_resultMode(pFunc->GetResultMode()),
	_flags(pFunc->GetFlags()),
	_listThisFlag(false),
	_iSlotCur(0)
{
	InitializeSlot(pFunc);
}

Argument::Argument(const Function *pFunc, const CallerInfo &callerInfo) :
	_cntRef(1),
	_pFunc(pFunc->Reference()),
	_valTypeResult(callerInfo.ModifyValueTypeResult(pFunc->GetValueTypeResult())),
	_resultMode(callerInfo.ModifyResultMode(pFunc->GetResultMode())),
	_flags(callerInfo.ModifyFlags(pFunc->GetFlags())),
	_pAttrsShared(SymbolSetShared::Reference(callerInfo.GetAttrsShared())),
	_pExprBlock(Expr_Block::Reference(callerInfo.GetBlock())),
	_listThisFlag(false),
	_iSlotCur(0)
{
	InitializeSlot(pFunc);
}

Argument::Argument(const Argument &arg, const ValueList &valListArg) :
	_cntRef(1),
	_pFunc(arg._pFunc->Reference()),
	_valTypeResult(arg._valTypeResult),
	_resultMode(arg._resultMode),
	_flags(arg._flags),
	_pValDictArg(ValueDict::Reference(arg._pValDictArg.get())),
	_pAttrsShared(SymbolSetShared::Reference(arg._pAttrsShared.get())),
	_pExprBlock(Expr_Block::Reference(arg._pExprBlock.get())),
	_pFuncBlock(Function::Reference(arg._pFuncBlock.get())),
	_valueThis(arg._valueThis),
	_pIteratorThis(Iterator::Reference(arg._pIteratorThis.get())),
	_listThisFlag(arg._listThisFlag),
	_pTrailCtrlHolder(TrailCtrlHolder::Reference(arg._pTrailCtrlHolder.get())),
	_valListArg(valListArg),
	_iSlotCur(arg._iSlotCur),
	_slots(arg._slots)
{
}

void Argument::InitializeSlot(const Function *pFunc)
{
	Environment &env = pFunc->GetEnvScope();
	const DeclarationOwner &declOwner = pFunc->GetDeclOwner();
	_valListArg.reserve(declOwner.size());
	_slots.reserve(declOwner.size());
	foreach_const (DeclarationOwner, ppDecl, declOwner) {
		const Declaration *pDecl = *ppDecl;
		if (pDecl->IsVariableLength()) {
			Value value;
			AutoPtr<Iterator> pIterator(new Iterator_VarLength(pDecl, value.InitAsList(env)));
			_slots.push_back(Slot(pDecl->Reference(), value, pIterator.release()));
		} else {
			_slots.push_back(Slot(pDecl->Reference()));
		}
	}
}

Argument::~Argument()
{
}

bool Argument::EvalExpr(Environment &env, const ExprList &exprListArg)
{
	Signal &sig = env.GetSignal();
	Function::ExprMap exprMap;
	ValueDict *pValDictArg = nullptr;
	bool namedArgFlag = !GetFlag(FLAG_NoNamed);
	foreach_const (ExprList, ppExprArg, exprListArg) {
		const Expr *pExprArg = *ppExprArg;
		if (namedArgFlag && pExprArg->IsBinaryOp(OPTYPE_Pair)) {
			// func(..., var => value, ...)
			const Expr_BinaryOp *pExprBinaryOp = dynamic_cast<const Expr_BinaryOp *>(pExprArg);
			const Expr *pExprLeft = pExprBinaryOp->GetLeft()->Unquote();
			const Expr *pExprRight = pExprBinaryOp->GetRight();
			if (pExprLeft->IsIdentifier()) {
				const Symbol *pSymbol =
					dynamic_cast<const Expr_Identifier *>(pExprLeft)->GetSymbol();
				exprMap[pSymbol] = pExprRight->Reference();
			} else if (pExprLeft->IsValue()) {
				const Value &valueKey = dynamic_cast<const Expr_Value *>(pExprLeft)->GetValue();
				Value result = pExprRight->Exec(env, nullptr);
				if (sig.IsSignalled()) return false;
				if (pValDictArg == nullptr) pValDictArg = new ValueDict();
				(*pValDictArg)[valueKey] = result;
			} else {
				pExprBinaryOp->SetError(sig, ERR_KeyError,
					"l-value of dictionary assignment must be an identifier or a constant value");
				return false;
			}
		} else if (Expr_UnaryOp::IsSuffixed(pExprArg, Symbol::Percnt)) {
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
					if (pValDictArg == nullptr) pValDictArg = new ValueDict();
					pValDictArg->insert(*item);
				}
			}
		}
	}
	foreach_const (ExprList, ppExprArg, exprListArg) {
		const Expr *pExprArg = *ppExprArg;
		if ((namedArgFlag && pExprArg->IsBinaryOp(OPTYPE_Pair)) ||
			Expr_UnaryOp::IsSuffixed(pExprArg, Symbol::Percnt)) continue;
		if (_iSlotCur >= _slots.size()) {
			if (GetFlag(FLAG_CutExtraArgs)) break;
			Declaration::SetError_TooManyArguments(env);
			return false;
		}
		const Slot &slot = _slots[_iSlotCur];
		if (exprMap.find(slot.GetDeclaration().GetSymbol()) != exprMap.end()) {
			sig.SetError(ERR_ValueError, "argument confliction");
			return false;
		}
		if (slot.GetDeclaration().IsQuote()) {
			// func(..., `var, ...)
			if (!AddValue(env,
						Value(new Object_expr(env, Expr::Reference(pExprArg))))) return false;
		} else if (Expr_UnaryOp::IsSuffixed(pExprArg, Symbol::Ast)) {
			// func(..., value*, ...)
			const Expr_UnaryOp *pExprUnaryOp = dynamic_cast<const Expr_UnaryOp *>(pExprArg);
			Value result = pExprUnaryOp->GetChild()->Exec(env, nullptr);
			if (sig.IsSignalled()) return false;
			if (result.Is_list()) {
				const ValueList &valList = result.GetList();
				foreach_const (ValueList, pValue, valList) {
					if (!AddValue(env, *pValue)) return false;
				}
				continue;
			}
			if (!AddValue(env, result)) return false;
		} else {
			// func(..., value, ...)
			Value result = pExprArg->Exec(env, nullptr);
			if (sig.IsSignalled()) return false;
			if (!AddValue(env, result)) return false;
		}
	}
	//-------------------------------------------------------------------------
	Slots::const_iterator pSlot = _slots.begin() + _iSlotCur;
	if (pSlot != _slots.end() && (!pSlot->GetDeclaration().IsVariableLength() ||
								  pSlot->GetValue().GetList().empty())) {
		for ( ; pSlot != _slots.end(); pSlot++) {
			// handling named arguments and arguments with a default value
			const Declaration &decl = pSlot->GetDeclaration();
			const Expr *pExprArg = decl.GetExprDefault();
			Function::ExprMap::iterator iter = exprMap.find(decl.GetSymbol());
			if (iter != exprMap.end()) {
				pExprArg = iter->second;
				exprMap.erase(iter);
			}
			if (pExprArg == nullptr) {
				if (decl.GetOccurPattern() == OCCUR_ZeroOrOnce) {
					if (!AddValue(env, Value::Undefined)) return false;
					continue;
				} else if (decl.GetOccurPattern() == OCCUR_ZeroOrMore) {
					break;
				} else {
					Declaration::SetError_NotEnoughArguments(env);
					return false;
				}
			} else if (decl.IsQuote()) {
				if (!AddValue(env,
							  Value(new Object_expr(env, pExprArg->Reference())))) return false;
				continue;
			} else {
				Value result = pExprArg->Exec(env, nullptr);
				if (sig.IsSignalled()) return false;
				if (!AddValue(env, result)) return false;
			}
		}
	}
	//-------------------------------------------------------------------------
	if (exprMap.empty()) {
		// nothing to do
	} else if (_pFunc->GetSymbolDict() == nullptr) {
		String str;
		str = "invalid argument named ";
		foreach_const (Function::ExprMap, iter, exprMap) {
			if (iter != exprMap.begin()) str += ", ";
			str += iter->first->GetName();
		}
		sig.SetError(ERR_ValueError, "%s", str.c_str());
		return false;
	} else {
		if (pValDictArg == nullptr) pValDictArg = new ValueDict();
		foreach (Function::ExprMap, iterExprMap, exprMap) {
			const Symbol *pSymbol = iterExprMap->first;
			const Expr *pExprArg = iterExprMap->second;
			Value result = pExprArg->Exec(env, nullptr);
			if (sig.IsSignalled()) return false;
			(*pValDictArg)[Value(pSymbol)] = result;
		}
	}
	//-------------------------------------------------------------------------
	SetValueDictArg(pValDictArg);
	return CheckValidity(env);
}

bool Argument::AddValue(Environment &env, const Value &value)
{
	_valListArg.push_back(value);
	if (_iSlotCur < _slots.size()) {
		Slot &slot = _slots[_iSlotCur];
		if (!slot.SetValue(env, value, GetFlag(FLAG_Map))) return false;
		if (!slot.GetDeclaration().IsVariableLength()) _iSlotCur++;
		return true;
	} else if (GetFlag(FLAG_CutExtraArgs)) {
		return true;
	}
	Declaration::SetError_TooManyArguments(env);
	return false;
}

bool Argument::AddValue(Environment &env, const ValueList &valList)
{
	foreach_const (ValueList, pValue, valList) {
		if (!AddValue(env, *pValue)) return false;
	}
	return true;
}

bool Argument::Compensate(Environment &env)
{
	Signal &sig = env.GetSignal();
	if (_iSlotCur >= _slots.size()) return true;
	Slots::const_iterator pSlot = _slots.begin() + _iSlotCur;
	for ( ; pSlot != _slots.end(); pSlot++) {
		// handling named arguments and arguments with a default value

		const Declaration &decl = pSlot->GetDeclaration();
		const Expr *pExprArg = decl.GetExprDefault();
		if (pExprArg == nullptr) {
			if (decl.GetOccurPattern() == OCCUR_ZeroOrOnce) {
				if (!AddValue(env, Value::Undefined)) return false;
			} else if (decl.GetOccurPattern() == OCCUR_ZeroOrMore) {
				break;
			} else {
				Declaration::SetError_NotEnoughArguments(env);
				return false;
			}
		} else if (decl.IsQuote()) {
			if (!AddValue(env,
				  Value(new Object_expr(env, Expr::Reference(pExprArg))))) return false;
		} else if (decl.IsType(VTYPE_symbol)) {
			const Expr *pExpr = pExprArg;
			if (pExpr->IsQuote()) {
				pExpr = dynamic_cast<const Expr_Quote *>(pExpr)->GetChild();
			}
			if (!pExpr->IsIdentifier()) {
				env.SetError(ERR_TypeError, "identifier is expected");
				return false;
			}
			const Symbol *pSymbol = dynamic_cast<const Expr_Identifier *>(pExpr)->GetSymbol();
			if (!AddValue(env, Value(pSymbol))) return false;
		} else {
			Value result = pExprArg->Exec(env);
			if (sig.IsSignalled()) return false;
			if (!AddValue(env, result)) return false;
		}
	}
	return true;
}

//Value Argument::GetValue(size_t idxArg)
//{
//	return (idxArg < _valListArg.size())? _valListArg[idxArg] : Value::Nil;
//	//return (idxArg < _slots.size())? _slots[idxArg].GetValue() : Value::Nil;
//}

const Value &Argument::GetValue(size_t idxArg) const
{
	return (idxArg < _valListArg.size())? _valListArg[idxArg] : Value::Nil;
	//return (idxArg < _slots.size())? _slots[idxArg].GetValue() : Value::Nil;
}

void Argument::GetValues(ValueList &valList) const
{
	//foreach_const (ValueList, pValue, _valListArg) {
	//	valList.push_back(*pValue);
	//}
	foreach_const (Slots, pSlot, _slots) {
		valList.push_back(pSlot->GetValue());
	}
}

bool Argument::CheckValidity(Environment &env)
{
	foreach_const (SymbolSet, ppSymbol, GetAttrs()) {
		const Symbol *pSymbol = *ppSymbol;
		if (!GetAttrsOpt().IsSet(pSymbol)) {
			env.SetError(ERR_AttributeError, "unsupported attribute '%s' for '%s'",
						 pSymbol->GetName(), _pFunc->ToString().c_str());
			return false;
		}
	}
	if (_pFunc->GetType() == FUNCTYPE_Instance &&
			!GetValueThis().IsPrimitive() && GetObjectThis() == nullptr) {
		env.SetError(ERR_ValueError,
					 "object is expected as l-value of field");
		return false;
	} else if (_pFunc->GetType() == FUNCTYPE_Class &&
			GetValueThis().GetClassItself() == nullptr && GetObjectThis() == nullptr) {
		env.SetError(ERR_ValueError,
					 "class or object is expected as l-value of field");
		return false;
	}
	if (IsBlockSpecified()) {
		if (_pFunc->GetBlockInfo().occurPattern == OCCUR_Zero) {
			env.SetError(ERR_ValueError,
						 "block is unnecessary for '%s'", _pFunc->ToString().c_str());
			return false;
		}
	} else {
		if (_pFunc->GetBlockInfo().occurPattern == OCCUR_Once) {
			env.SetError(ERR_ValueError,
						 "block must be specified for '%s'", _pFunc->ToString().c_str());
			return false;
		}
	}
	return true;
}

Argument::MapMode Argument::DetermineMapMode() const
{
	MapMode mapMode = MAPMODE_None;
	if (!_pIteratorThis.IsNull()) {
		if (!_listThisFlag) return MAPMODE_ToIter;
		mapMode = MAPMODE_ToList;
	}
#if 1
	ValueList::const_iterator pValue = _valListArg.begin();
	Slots::const_iterator pSlot = _slots.begin();
	for ( ; pValue != _valListArg.end() && pSlot != _slots.end(); pValue++) {
		const Declaration &decl = pSlot->GetDeclaration();
		if (decl.ShouldImplicitMap(*pValue)) {
			if (pValue->Is_iterator()) return MAPMODE_ToIter;
			mapMode = MAPMODE_ToList;
		}
		if (!decl.IsVariableLength()) pSlot++;
	}
#else
	foreach_const (Slots, pSlot, _slots) {
		const Declaration &decl = pSlot->GetDeclaration();
		const Value &value = pSlot->GetValue();
		if (decl.IsVariableLength()) {
			foreach_const (ValueList, pValue, value.GetList()) {
				if (decl.ShouldImplicitMap(*pValue)) {
					if (pValue->Is_iterator()) return MAPMODE_ToIter;
					mapMode = MAPMODE_ToList;
				}
			}
		} else if (decl.ShouldImplicitMap(value)) {
			if (value.Is_iterator()) return MAPMODE_ToIter;
			mapMode = MAPMODE_ToList;
		}
	}
#endif
	return mapMode;
}

bool Argument::PrepareForMap(Environment &env, IteratorOwner &iterOwner)
{
	Signal &sig = env.GetSignal();
#if 1
	ValueList::const_iterator pValue = _valListArg.begin();
	Slots::const_iterator pSlot = _slots.begin();
	for ( ; pValue != _valListArg.end() && pSlot != _slots.end(); pValue++) {
		const Declaration &decl = pSlot->GetDeclaration();
		Iterator *pIterator = nullptr;
		if (decl.ShouldImplicitMap(*pValue)) {
			pIterator = pValue->CreateIterator(sig);
			if (pIterator == nullptr) return false;
		} else {
			pIterator = new Iterator_Constant(*pValue);
		}
		iterOwner.push_back(pIterator);
		if (!decl.IsVariableLength()) pSlot++;
	}
#else
	foreach_const (Slots, pSlot, _slots) {
		const Declaration &decl = pSlot->GetDeclaration();
		const Value &value = pSlot->GetValue();
		if (decl.IsVariableLength()) {
			foreach_const (ValueList, pValue, value.GetList()) {
				Iterator *pIterator = nullptr;
				if (decl.ShouldImplicitMap(*pValue)) {
					pIterator = pValue->CreateIterator(sig);
					if (pIterator == nullptr) return false;
				} else {
					pIterator = new Iterator_Constant(*pValue);
				}
				iterOwner.push_back(pIterator);
			}
		} else {
			Iterator *pIterator = nullptr;
			if (decl.ShouldImplicitMap(value)) {
				pIterator = value.CreateIterator(sig);
				if (pIterator == nullptr) return false;
			} else {
				pIterator = new Iterator_Constant(value);
			}
			iterOwner.push_back(pIterator);
		}
	}
#endif
	return true;
}

void Argument::AssignToEnvironment(Environment &env) const
{
#if 1
	Slots::const_iterator pSlot = _slots.begin();
	ValueList::const_iterator pValue = _valListArg.begin();
	for ( ; pSlot != _slots.end() && pValue != _valListArg.end(); pSlot++, pValue++) {
		const Declaration &decl = pSlot->GetDeclaration();
		env.AssignValue(decl.GetSymbol(), *pValue, EXTRA_Public);
	}
#else
	foreach_const (Slots, pSlot, _slots) {
		const Declaration &decl = pSlot->GetDeclaration();
		const Value &value = pSlot->GetValue();
		env.AssignValue(decl.GetSymbol(), value, EXTRA_Public);
	}
#endif
}

Environment *Argument::PrepareEnvironment(Environment &env, bool thisAssignFlag) const
{
	Signal &sig = env.GetSignal();
	Environment *pEnvOuter = GetFlag(FLAG_DynamicScope)? &env : &_pFunc->GetEnvScope();
	EnvType envType = (_pFunc->GetType() == FUNCTYPE_Block)? ENVTYPE_block : ENVTYPE_local;
	AutoPtr<Environment> pEnvLocal(new Environment(pEnvOuter, envType));
	if (thisAssignFlag) {
		Value valueThis(_valueThis);
		valueThis.AddFlags(VFLAG_Privileged);
		pEnvLocal->AssignValue(Gura_Symbol(this_), valueThis, EXTRA_Public);
	}
	AssignToEnvironment(*pEnvLocal);
	const Symbol *pSymbolDict = _pFunc->GetSymbolDict();
	if (pSymbolDict != nullptr) {
		pEnvLocal->AssignValue(pSymbolDict,
			   Value(new Object_dict(env, GetValueDictArg().Reference(), false)), EXTRA_Public);
	}
	pEnvLocal->AssignValue(Gura_Symbol(__arg__),
				Value(new Object_argument(env, Reference())), EXTRA_Public);
	const Function::BlockInfo &blockInfo = _pFunc->GetBlockInfo();
	if (blockInfo.pSymbol == nullptr) return pEnvLocal.release();
	const Expr_Block *pExprBlock = GetBlockCooked(env);
	if (sig.IsSignalled()) return nullptr;
	if (pExprBlock == nullptr) {
		// set nil value to the variable with a symbol specified by blockInfo.pSymbol
		pEnvLocal->AssignValue(blockInfo.pSymbol, Value::Nil, EXTRA_Public);
	} else if (blockInfo.quoteFlag) {
		Object_expr *pObj = new Object_expr(env, Expr::Reference(pExprBlock));
		pEnvLocal->AssignValue(blockInfo.pSymbol, Value(pObj), EXTRA_Public);
	} else {
		Environment *pEnv = (blockInfo.blockScope == Function::BLKSCOPE_Inside)?
			pEnvLocal.get() : &env;
		FunctionType funcType = (blockInfo.blockScope == Function::BLKSCOPE_SameAsFunc)?
			FUNCTYPE_Function : FUNCTYPE_Block;
		FunctionCustom *pFuncBlock = FunctionCustom::CreateBlockFunc(
			*pEnv, blockInfo.pSymbol, pExprBlock, funcType);
		if (pFuncBlock == nullptr) return nullptr;
		pEnvLocal->AssignFunction(pFuncBlock);
	}
	return pEnvLocal.release();
}

// not tested yet
bool Argument::IsInfiniteMap() const
{
	bool infiniteFoundFlag = false;
	if (!_pIteratorThis.IsNull()) {
		if (!_pIteratorThis->IsInfinite()) return false;
		infiniteFoundFlag = true;
	}
	foreach_const (Slots, pSlot, _slots) {
		const Iterator *pIterator = pSlot->GetIteratorMap();
		if (pIterator != nullptr) {
			if(!pIterator->IsInfinite()) return false;
			infiniteFoundFlag = true;
		}
	}
	return infiniteFoundFlag;
}

const Expr_Block *Argument::GetBlockCooked(Environment &env) const
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
const Function *Argument::GetBlockFunc(Environment &env, const Symbol *pSymbol)
{
	const Expr_Block *pExprBlock = GetBlockCooked(env);
	if (pExprBlock == nullptr || pSymbol == nullptr) return nullptr;
	if (_pFuncBlock.IsNull()) {
		_pFuncBlock.reset(FunctionCustom::CreateBlockFunc(env,
										pSymbol, pExprBlock, FUNCTYPE_Block));
	}
	return _pFuncBlock.get();
}

bool Argument::IsSet(const Symbol *pSymbol) const
{
	return GetAttrs().IsSet(pSymbol) || (_flags & Symbol::ToFlag(pSymbol)) != 0 ||
		(_resultMode != RSLTMODE_Normal && _resultMode == Symbol::ToResultMode(pSymbol));
}

//-----------------------------------------------------------------------------
// Argument::Iterator_VarLength
//-----------------------------------------------------------------------------
Iterator *Argument::Iterator_VarLength::GetSource()
{
	return nullptr;
}

bool Argument::Iterator_VarLength::DoNext(Environment &env, Value &value)
{
	size_t idx = 0;
	foreach_const (IteratorOwner, ppIterator, _iterOwner) {
		Iterator *pIterator = *ppIterator;
		if (pIterator != nullptr) {
			Value valueItem;
			if (!pIterator->Next(env, valueItem)) return false;
			if (!_pDecl->ValidateAndCast(env, valueItem)) return false;
			_valList[idx] = valueItem;
		}
		idx++;
	}
	return true;
}

String Argument::Iterator_VarLength::ToString() const
{
	String rtn = "varlength(";
	rtn += ")";
	return rtn;
}

void Argument::Iterator_VarLength::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_iterOwner.GatherFollower(pFrame, envSet);
	}
}

void Argument::Iterator_VarLength::AddIterator(Iterator *pIterator)
{
	if (pIterator != nullptr && !_finiteFoundFlag) {
		SetInfiniteFlag(pIterator->IsInfinite());
		_finiteFoundFlag = !pIterator->IsInfinite();
	}
	_iterOwner.push_back(pIterator);
}

//-----------------------------------------------------------------------------
// Argument::Slot
//-----------------------------------------------------------------------------
bool Argument::Slot::SetValue(Environment &env, const Value &value, bool mapFlag)
{
	if (mapFlag && _pDecl->ShouldImplicitMap(value)) {
		if (_pDecl->IsVariableLength()) {
			//_value.GetList().push_back(Value::Undefined);
			_value.GetList().push_back(value);
			
		} else if (_value.IsUndefined()) {
			_value = value;

		} else {
			env.SetError(ERR_ValueError, "argument confliction");
			return false;
		}
		return true;
	}
	Value valueCasted = value;
	//if (_pDecl->ValidateAndCast(env, valueCasted)) { // casting would be duplicated
	if (true) {
		if (_pDecl->IsVariableLength()) {
			_value.GetList().push_back(valueCasted);
			
		} else if (_value.IsUndefined()) {
			_value = valueCasted;
		} else {
			env.SetError(ERR_ValueError, "argument confliction");
			return false;
		}
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
// Argument::Slots
//-----------------------------------------------------------------------------
Argument::Slot *Argument::Slots::FindBySymbol(const Symbol *pSymbol)
{
	foreach (Slots, pSlot, *this) {
		if (pSlot->GetDeclaration().GetSymbol()->IsIdentical(pSymbol)) return &*pSlot;
	}
	return nullptr;
}

bool Argument::Slots::NextMap(Environment &env)
{
	foreach (Slots, pSlot, *this) {
		if (!pSlot->NextMap(env)) return false;
	}
	return true;
}

}
