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
	_mapMode(MAPMODE_None)
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
	_mapMode(MAPMODE_None)
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
			_slots.push_back(Slot(pDecl->Reference(), value, pIterator.release(), false));
		} else {
			_slots.push_back(Slot(pDecl->Reference()));
		}
	}
	_pSlotCur = _slots.begin();
}

void Argument::SetIteratorThis(Iterator *pIteratorThis)
{
	_pIteratorThis.reset(pIteratorThis);
	if (!_pIteratorThis.IsNull() && _mapMode != MAPMODE_ToIter) {
		_mapMode = pIteratorThis->IsListOrigin()? MAPMODE_ToList : MAPMODE_ToIter;
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
	bool mapFlag = GetFlag(FLAG_Map);
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
				Slot *pSlot = _slots.FindBySymbol(pSymbol);
				if (pSlot == nullptr) {
					Value valueKey(pSymbol);
					Value value = pExprRight->Exec(env, nullptr);
					if (sig.IsSignalled()) return false;
					AddValueDictItem(valueKey, value);
				} else if (pSlot->GetDeclaration().IsQuote()) {
					Value value(new Object_expr(env, pExprRight->Reference()));
					if (!pSlot->StoreValue(env, value, mapFlag, &_mapMode)) return false;
				} else {
					Value value = pExprRight->Exec(env, nullptr);
					if (sig.IsSignalled()) return false;
					if (!pSlot->StoreValue(env, value, mapFlag, &_mapMode)) return false;
				}
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
					const Symbol *pSymbol = valueKey.GetSymbol();
					Slot *pSlot = _slots.FindBySymbol(pSymbol);
					if (pSlot == nullptr) {
						Value valueKey(pSymbol);
						AddValueDictItem(valueKey, value);
					} else if (pSlot->GetDeclaration().IsQuote()) {
						sig.SetError(ERR_ValueError, "invalid argument");
						return false;
					} else if (!pSlot->StoreValue(env, value, mapFlag, &_mapMode)) {
						return false;
					}
				} else {
					AddValueDictItem(valueKey, value);
				}
			}
		} else if (_pSlotCur == _slots.end()) {
			if (GetFlag(FLAG_CutExtraArgs)) break;
			Declaration::SetError_TooManyArguments(env);
			return false;
		} else if (_pSlotCur->GetDeclaration().IsQuote()) {
			// func(..., `var, ...)
			Value value(new Object_expr(env, Expr::Reference(pExprArg)));
			if (!StoreValue(env, value)) return false;
		} else if (Expr_UnaryOp::IsSuffixed(pExprArg, Symbol::Ast)) {
			// func(..., value*, ...)
			const Expr_UnaryOp *pExprUnaryOp = dynamic_cast<const Expr_UnaryOp *>(pExprArg);
			Value value = pExprUnaryOp->GetChild()->Exec(env, nullptr);
			if (sig.IsSignalled()) return false;
			if (value.Is_list()) {
				const ValueList &valList = value.GetList();
				foreach_const (ValueList, pValue, valList) {
					if (!StoreValue(env, *pValue)) return false;
				}
			} else if (!StoreValue(env, value)) {
				return false;
			}
		} else {
			// func(..., value, ...)
			Value value = pExprArg->Exec(env, nullptr);
			if (sig.IsSignalled()) return false;
			if (!StoreValue(env, value)) return false;
		}
	}
	return Complete(env);
}

bool Argument::StoreValue(Environment &env, const Value &value)
{
	if (_pSlotCur != _slots.end()) {
		if (!_pSlotCur->StoreValue(env, value, GetFlag(FLAG_Map), &_mapMode)) return false;
		if (!_pSlotCur->GetDeclaration().IsVariableLength()) _pSlotCur++;
		return true;
	} else if (GetFlag(FLAG_CutExtraArgs)) {
		return true;
	} else {
		Declaration::SetError_TooManyArguments(env);
		return false;
	}
}

bool Argument::StoreValues(Environment &env, const ValueList &valList)
{
	foreach_const (ValueList, pValue, valList) {
		if (!StoreValue(env, *pValue)) return false;
	}
	return true;
}

bool Argument::UpdateValue(Environment &env, size_t iSlot, const Value &value)
{
	return (iSlot >= _slots.size()) || _slots[iSlot].UpdateValue(env, value);
}

bool Argument::UpdateValues(Environment &env, const ValueList &valList)
{
	Slots::iterator pSlot = _slots.begin();
	foreach_const (ValueList, pValue, valList) {
		if (pSlot == _slots.end()) break;
		if (!pSlot->UpdateValue(env, *pValue)) return false;
		pSlot++;
	}
	return true;
}

bool Argument::Complete(Environment &env)
{
	bool mapFlag = GetFlag(FLAG_Map);
	for ( ; _pSlotCur != _slots.end(); _pSlotCur++) {
		const Declaration &decl = _pSlotCur->GetDeclaration();
		const Expr *pExprDefault = decl.GetExprDefault();
		if (_pSlotCur->GetValueExistFlag()) {
			// nothing to do
		} else if (pExprDefault == nullptr) {
			if (decl.GetOccurPattern() != OCCUR_ZeroOrOnce &&
									decl.GetOccurPattern() != OCCUR_ZeroOrMore) {
				Declaration::SetError_NotEnoughArguments(env);
				return false;
			}
		} else if (decl.IsQuote()) {
			Value value(new Object_expr(env, pExprDefault->Reference()));
			if (!_pSlotCur->StoreValue(env, value, mapFlag, &_mapMode)) return false;
		} else {
			Value value = pExprDefault->Exec(env, nullptr);
			if (env.IsSignalled()) return false;
			if (!_pSlotCur->StoreValue(env, value, mapFlag, &_mapMode)) return false;
		}
	}
	foreach_const (SymbolSet, ppSymbol, GetAttrs()) {
		const Symbol *pSymbol = *ppSymbol;
		if (!_pFunc->GetAttrsOpt().IsSet(pSymbol)) {
			env.SetError(ERR_AttributeError, "unsupported attribute '%s' for '%s'",
						 pSymbol->GetName(), _pFunc->ToString().c_str());
			return false;
		}
	}
	if (_pFunc->GetType() == FUNCTYPE_Instance &&
				!GetValueThis().IsPrimitive() && !GetValueThis().IsObject()) {
		env.SetError(ERR_ValueError,
					 "object is expected as l-value of field");
		return false;
	} else if (_pFunc->GetType() == FUNCTYPE_Class &&
			   !GetValueThis().IsClass() && !GetValueThis().IsObject()) {
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

void Argument::GetValues(ValueList &valList) const
{
	foreach_const (Slots, pSlot, _slots) {
		valList.push_back(pSlot->GetValue());
	}
}

void Argument::AssignValuesToEnvironment(Environment &env) const
{
	foreach_const (Slots, pSlot, _slots) {
		const Declaration &decl = pSlot->GetDeclaration();
		const Value &value = pSlot->GetValue();
		env.AssignValue(decl.GetSymbol(), value, EXTRA_Public);
	}
}

Environment *Argument::PrepareEnvironment(Environment &env) const
{
	Signal &sig = env.GetSignal();
	Environment *pEnvOuter = GetFlag(FLAG_DynamicScope)? &env : &_pFunc->GetEnvScope();
	EnvType envType = (_pFunc->GetType() == FUNCTYPE_Block)? ENVTYPE_block : ENVTYPE_local;
	AutoPtr<Environment> pEnvLocal(pEnvOuter->Derive(envType));
	//if (_pFunc->GetType() != FUNCTYPE_Block) {
	//	Value valueThis(_valueThis);
	//	valueThis.AddFlags(VFLAG_Privileged);
	//	pEnvLocal->AssignValue(Gura_Symbol(this_), valueThis, EXTRA_Public);
	//}
	AssignValuesToEnvironment(*pEnvLocal);
	const Symbol *pSymbolDict = _pFunc->GetSymbolDict();
	if (pSymbolDict != nullptr) {
		pEnvLocal->AssignValue(pSymbolDict,
			   Value(new Object_dict(env, GetValueDictArg().Reference(), false)), EXTRA_Public);
	}
	//pEnvLocal->AssignValue(Gura_Symbol(__arg__),
	//			Value(new Object_argument(env, Reference())), EXTRA_Public);
	pEnvLocal->SetArgument(Reference());
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
bool Argument::Slot::StoreValue(Environment &env, const Value &value, bool mapFlag, MapMode *pMapMode)
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
		_valueExistFlag = true;
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
		_valueExistFlag = true;
		return true;
	}
	return false;
}

bool Argument::Slot::UpdateValue(Environment &env, const Value &value)
{
	Value valueCasted = value;
	if (!_pDecl->ValidateAndCast(env, valueCasted)) return false;
	if (_pDecl->IsVariableLength()) {
		// nothing to do
	} else {
		_value = valueCasted;
	}
	_valueExistFlag = true;
	return true;
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
