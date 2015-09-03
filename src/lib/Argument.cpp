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
	_pAttrsOptShared(SymbolSetShared::Reference(callerInfo.GetAttrsOptShared())),
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
