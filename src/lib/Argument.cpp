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
	_mapMode(MAPMODE_None),
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
	_mapMode(MAPMODE_None),
	_iSlotCur(0)
{
	InitializeSlot(pFunc);
}

void Argument::InitializeSlot(const Function *pFunc)
{
	Environment &env = pFunc->GetEnvScope();
	const DeclarationOwner &declOwner = pFunc->GetDeclOwner();
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

void Argument::SetIteratorThis(Iterator *pIteratorThis, bool listThisFlag)
{
	_pIteratorThis.reset(pIteratorThis);
	if (!_pIteratorThis.IsNull() && _mapMode != MAPMODE_ToIter) {
		_mapMode = listThisFlag? MAPMODE_ToList : MAPMODE_ToIter;
	}
}

bool Argument::IsSet(const Symbol *pSymbol) const
{
	return GetAttrs().IsSet(pSymbol) || (_flags & Symbol::ToFlag(pSymbol)) != 0 ||
		(_resultMode != RSLTMODE_Normal && _resultMode == Symbol::ToResultMode(pSymbol));
}

bool Argument::EvalExpr(Environment &env, const ExprList &exprListArg)
{
	Signal &sig = env.GetSignal();
	Function::ExprMap exprMap;
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
#if 1
				exprMap[pSymbol] = pExprRight->Reference();
#else
				Slot *pSlot = _slots.FindBySymbol(pSymbol);
				if (pSlot == nullptr) {
					Value value = pExprRight->Exec(env, nullptr);
					if (sig.IsSignalled()) return false;
					AddValueDictItem(valueKey, value);
				} else if (decl.IsQuote()) {
					Value value(new Object_expr(env, pExprRight->Reference()));
					if (!pSlot->SetValue(env, value)) return false;
				} else {
					Value value = pExprRight->Exec(env, nullptr);
					if (sig.IsSignalled()) return false;
					if (!pSlot->SetValue(env, value)) return false;
				}
#endif
			} else if (pExprLeft->IsValue()) {
				const Value &valueKey = dynamic_cast<const Expr_Value *>(pExprLeft)->GetValue();
				Value value = pExprRight->Exec(env, nullptr);
				if (sig.IsSignalled()) return false;
				AddValueDictItem(valueKey, value);
			} else {
				pExprBinaryOp->SetError(sig, ERR_KeyError,
					"l-value of dictionary assignment must be an identifier or a constant value");
				return false;
			}
		} else if (Expr_UnaryOp::IsSuffixed(pExprArg, Symbol::Percnt)) {
			// func(..., value%, ...)
			const Expr_UnaryOp *pExprUnaryOp = dynamic_cast<const Expr_UnaryOp *>(pExprArg);
			Value value = pExprUnaryOp->GetChild()->Exec(env, nullptr);
			if (sig.IsSignalled()) return false;
			if (!value.Is_dict()) {
				sig.SetError(ERR_ValueError, "modulo argument must take a dictionary");
				return false;
			}
			foreach_const (ValueDict, item, value.GetDict()) {
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
					AddValueDictItem(valueKey, value);
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
			Value value = pExprUnaryOp->GetChild()->Exec(env, nullptr);
			if (sig.IsSignalled()) return false;
			if (value.Is_list()) {
				const ValueList &valList = value.GetList();
				foreach_const (ValueList, pValue, valList) {
					if (!AddValue(env, *pValue)) return false;
				}
				continue;
			}
			if (!AddValue(env, value)) return false;
		} else {
			// func(..., value, ...)
			Value value = pExprArg->Exec(env, nullptr);
			if (sig.IsSignalled()) return false;
			if (!AddValue(env, value)) return false;
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
				Value value = pExprArg->Exec(env, nullptr);
				if (sig.IsSignalled()) return false;
				if (!AddValue(env, value)) return false;
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
		foreach (Function::ExprMap, iterExprMap, exprMap) {
			const Symbol *pSymbol = iterExprMap->first;
			const Expr *pExprArg = iterExprMap->second;
			Value value = pExprArg->Exec(env, nullptr);
			if (sig.IsSignalled()) return false;
			AddValueDictItem(Value(pSymbol), value);
		}
	}
	//-------------------------------------------------------------------------
	return CheckValidity(env);
}

bool Argument::AddValue(Environment &env, const Value &value)
{
	if (_iSlotCur < _slots.size()) {
		Slot &slot = _slots[_iSlotCur];
		if (!slot.SetValue(env, value, GetFlag(FLAG_Map), &_mapMode)) return false;
		if (!slot.GetDeclaration().IsVariableLength()) _iSlotCur++;
		return true;
	} else if (GetFlag(FLAG_CutExtraArgs)) {
		return true;
	}
	Declaration::SetError_TooManyArguments(env);
	return false;
}

bool Argument::AddValues(Environment &env, const ValueList &valList)
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
		const Declaration &decl = pSlot->GetDeclaration();
		const Expr *pExprArg = decl.GetExprDefault();
		if (pExprArg == nullptr) {
			if (decl.GetOccurPattern() == OCCUR_ZeroOrOnce) {
				if (!AddValue(env, Value::Undefined)) return false;
			} else if (decl.GetOccurPattern() == OCCUR_ZeroOrMore) {
				break;
			} else if (decl.GetOccurPattern() == OCCUR_OnceOrMore &&
					   !pSlot->GetValue().GetList().empty()) {
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
			Value value = pExprArg->Exec(env);
			if (sig.IsSignalled()) return false;
			if (!AddValue(env, value)) return false;
		}
	}
	return true;
}

const Value &Argument::GetValue(size_t idxArg) const
{
	return (idxArg < _slots.size())? _slots[idxArg].GetValue() : Value::Nil;
}

void Argument::GetValues(ValueList &valList) const
{
	foreach_const (Slots, pSlot, _slots) {
		valList.push_back(pSlot->GetValue());
	}
}

bool Argument::CheckValidity(Environment &env) const
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
#if 0
	foreach_const (Slots, pSlot, _slots) {
		const Declaration &decl = pSlot->GetDeclaration();
		if (decl.GetOccurPattern() == OCCUR_Once) {
			if (pSlot->GetValue().IsUndefined()) {
				Declaration::SetError_NotEnoughArguments(env);
				return false;
			}
		} else if (decl.GetOccurPattern() == OCCUR_OnceOrMore) {
			if (pSlot->GetValue().GetList().empty()) {
				Declaration::SetError_NotEnoughArguments(env);
				return false;
			}
		}
	}
#endif
	return true;
}

void Argument::AssignToEnvironment(Environment &env) const
{
	foreach_const (Slots, pSlot, _slots) {
		const Declaration &decl = pSlot->GetDeclaration();
		const Value &value = pSlot->GetValue();
		env.AssignValue(decl.GetSymbol(), value, EXTRA_Public);
	}
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

bool Argument::NextMap(Environment &env)
{
	foreach (Slots, pSlot, _slots) {
		if (!pSlot->NextMap(env)) return false;
	}
	return true;
}

void Argument::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (!_pIteratorThis.IsNull()) {
		_pIteratorThis->GatherFollower(pFrame, envSet);
	}
	foreach (Slots, pSlot, _slots) {
		Iterator *pIterator = pSlot->GetIteratorMap();
		if (pIterator != nullptr) pIterator->GatherFollower(pFrame, envSet);
	}
	_pFunc->GatherFollower(pFrame, envSet);
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
bool Argument::Slot::SetValue(Environment &env, const Value &value, bool mapFlag, MapMode *pMapMode)
{
	Signal &sig = env.GetSignal();
	if (mapFlag && _pDecl->ShouldImplicitMap(value)) {
		if (*pMapMode != MAPMODE_ToIter) {
			*pMapMode = value.Is_iterator()? MAPMODE_ToIter : MAPMODE_ToList;
		}
		if (_pDecl->IsVariableLength()) {
			_value.GetList().push_back(Value::Undefined);
			AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
			if (pIterator.IsNull()) return false;
			dynamic_cast<Iterator_VarLength *>(_pIteratorMap.get())->
											AddIterator(pIterator.release());
		} else if (_value.IsUndefined()) {
			AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
			if (pIterator.IsNull()) return false;
			_pIteratorMap.reset(pIterator.release());
		} else {
			env.SetError(ERR_ValueError, "argument confliction");
			return false;
		}
		return true;
	}
	Value valueCasted = value;
	if (_pDecl->ValidateAndCast(env, valueCasted)) {
		if (_pDecl->IsVariableLength()) {
			_value.GetList().push_back(valueCasted);
			dynamic_cast<Iterator_VarLength *>(_pIteratorMap.get())->AddIterator(nullptr);
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

bool Argument::Slot::NextMap(Environment &env)
{
	if (_pIteratorMap.IsNull()) return true;
	if (!_pIteratorMap->Next(env, _value)) return false;
	return _pDecl->IsVariableLength() || _pDecl->ValidateAndCast(env, _value);
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

}
