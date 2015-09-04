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
	_valTypeResult(pFunc->GetValueTypeResult()),
	_resultMode(pFunc->GetResultMode()),
	_flags(pFunc->GetFlags()),
	_pSymbolDict(pFunc->GetSymbolDict()),
	_listThisFlag(false),
	_iSlotCur(0)
{
	InitializeSlot(pFunc);
}

Argument::Argument(const Function *pFunc, const CallerInfo &callerInfo) :
	_cntRef(1),
	_valTypeResult(callerInfo.ModifyValueTypeResult(pFunc->GetValueTypeResult())),
	_resultMode(callerInfo.ModifyResultMode(pFunc->GetResultMode())),
	_flags(callerInfo.ModifyFlags(pFunc->GetFlags())),
	_pSymbolDict(pFunc->GetSymbolDict()),
	_pAttrsShared(SymbolSetShared::Reference(callerInfo.GetAttrsShared())),
	_pAttrsOptShared(SymbolSetShared::Reference(pFunc->GetAttrsOptShared())),
	_pExprBlock(Expr_Block::Reference(callerInfo.GetBlock())),
	_listThisFlag(false),
	_iSlotCur(0)
{
	InitializeSlot(pFunc);
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
			_slots.emplace_back(pDecl->Reference(), Value::CreateList(env));
		} else {
			_slots.emplace_back(pDecl->Reference());
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
	bool stayDeclPointerFlag = false;
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
	Slots::const_iterator pSlot = _slots.begin();
	foreach_const (ExprList, ppExprArg, exprListArg) {
		const Expr *pExprArg = *ppExprArg;
		if ((namedArgFlag && pExprArg->IsBinaryOp(OPTYPE_Pair)) ||
			Expr_UnaryOp::IsSuffixed(pExprArg, Symbol::Percnt)) continue;
		if (pSlot == _slots.end()) {
			if (GetFlag(FLAG_CutExtraArgs)) break;
			Declaration::SetError_TooManyArguments(sig);
			return false;
		}
		if (exprMap.find(pSlot->GetDeclaration().GetSymbol()) != exprMap.end()) {
			sig.SetError(ERR_ValueError, "argument confliction");
			return false;
		}
		if (pSlot->GetDeclaration().IsQuote()) {
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
					if (pSlot->GetDeclaration().IsVariableLength()) {
						stayDeclPointerFlag = true;
					} else {
						pSlot++;
					}
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
		if (pSlot->GetDeclaration().IsVariableLength()) {
			stayDeclPointerFlag = true;
		} else {
			pSlot++;
		}
	}
	//-------------------------------------------------------------------------
	for ( ; !stayDeclPointerFlag && pSlot != _slots.end(); pSlot++) {
		// handling named arguments and arguments with a default value
		const Expr *pExprArg = pSlot->GetDeclaration().GetExprDefault();
		Function::ExprMap::iterator iter = exprMap.find(pSlot->GetDeclaration().GetSymbol());
		if (iter != exprMap.end()) {
			pExprArg = iter->second;
			exprMap.erase(iter);
		}
		if (pExprArg == nullptr) {
			if (pSlot->GetDeclaration().GetOccurPattern() == OCCUR_ZeroOrOnce) {
				if (!AddValue(env, Value::Undefined)) return false;
				continue;
			} else if (pSlot->GetDeclaration().GetOccurPattern() == OCCUR_ZeroOrMore) {
				break;
			} else {
				Declaration::SetError_NotEnoughArguments(sig);
				return false;
			}
		} else if (pSlot->GetDeclaration().IsQuote()) {
			if (!AddValue(env,
					Value(new Object_expr(env, pExprArg->Reference())))) return false;
			continue;
		} else {
			Value result = pExprArg->Exec(env, nullptr);
			if (sig.IsSignalled()) return false;
			if (!AddValue(env, result)) return false;
		}
	}
	//-------------------------------------------------------------------------
	if (exprMap.empty()) {
		// nothing to do
	} else if (_pSymbolDict == nullptr) {
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
	return true;
}


bool Argument::AddValue(Environment &env, const Value &value)
{
	//Signal &sig = env.GetSignal();
	_valListArg.push_back(value);
	if (_iSlotCur >= _slots.size()) {
		//if (GetFlag(FLAG_CutExtraArgs)) return true;
		//Declaration::SetError_TooManyArguments(sig);
		//return false;
		return true;
	}
	Slot &slot = _slots[_iSlotCur];
	if (slot.GetDeclaration().IsVariableLength()) {
		slot.GetValue().GetList().push_back(value);
	} else {
		slot.SetValue(value);
		_iSlotCur++;
	}
	return true;
}

bool Argument::AddValue(Environment &env, const ValueList &valList)
{
	foreach_const (ValueList, pValue, valList) {
		if (!AddValue(env, *pValue)) return false;
	}
	return true;
}

bool Argument::ShouldGenerateIterator(const DeclarationList &declList) const
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
// Argument::Slot
//-----------------------------------------------------------------------------

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
