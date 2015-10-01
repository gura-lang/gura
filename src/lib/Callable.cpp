//=============================================================================
// Callable
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// CallerInfo
//-----------------------------------------------------------------------------
const CallerInfo CallerInfo::Empty(ExprList::Empty, nullptr, nullptr, nullptr);

bool CallerInfo::UpdateByAttrSymbol(const Symbol *pSymbol)
{
	/*
	const ULong flagsAcceptable =
		FLAG_CutExtraArgs |
		FLAG_DynamicScope |
		FLAG_EndMarker |
		FLAG_Finalizer |
		FLAG_Flat |
		FLAG_Leader |
		FLAG_Map |
		FLAG_NoMap |
		FLAG_NoNamed |
		FLAG_Private |
		FLAG_Public |
		FLAG_SymbolFunc |
		FLAG_Trailer;
	*/
	ULong flag = Symbol::ToFlag(pSymbol);
	if (flag != 0) {
		_flagsToSet |= flag;
		if (flag == FLAG_Map) {
			_flagsToSet &= ~FLAG_NoMap;
			_flagsToClear = (_flagsToClear | FLAG_NoMap) & ~FLAG_Map;
		} else if (flag == FLAG_NoMap) {
			_flagsToSet &= ~FLAG_Map;
			_flagsToClear = (_flagsToClear | FLAG_Map) & ~FLAG_NoMap;
		}
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(noflat))) {
		_flagsToSet &= ~FLAG_Flat;
		_flagsToClear |= FLAG_Flat;
		return true;
	}
	ResultMode resultMode = Symbol::ToResultMode(pSymbol);
	if (resultMode != RSLTMODE_Normal) {
		_resultMode = resultMode;
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
// Callable
//-----------------------------------------------------------------------------
Callable::~Callable()
{
	// virtual destructor
}

Value Callable::DoCall(
	Environment &env, const CallerInfo &callerInfo,
	const Value &valueThis, const Iterator *pIteratorThis, bool listThisFlag,
	const TrailCtrlHolder *pTrailCtrlHolder)
{
	env.SetError(ERR_TypeError, "object is not callable");
	return Value::Nil;
}

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
