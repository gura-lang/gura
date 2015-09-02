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
#if 1
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
#else
	if (pSymbol->IsIdentical(Gura_Symbol(cut_extra_args))) {
		_flagsToSet |= FLAG_CutExtraArgs;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(dynamic_scope))) {
		_flagsToSet |= FLAG_DynamicScope;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(end_marker))) {
		_flagsToSet |= FLAG_EndMarker;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(finalizer))) {
		_flagsToSet |= FLAG_Finalizer;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(flat))) {
		_flagsToSet |= FLAG_Flat;
		_flagsToClear &= ~FLAG_Flat;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(leader))) {
		_flagsToSet |= FLAG_Leader;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(map))) {
		_flagsToSet = (_flagsToSet | FLAG_Map) & ~FLAG_NoMap;
		_flagsToClear = (_flagsToClear | FLAG_NoMap) & ~FLAG_Map;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(nomap))) {
		_flagsToSet = (_flagsToSet | FLAG_NoMap) & ~FLAG_Map;
		_flagsToClear = (_flagsToClear | FLAG_Map) & ~FLAG_NoMap;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(nonamed))) {
		_flagsToSet |= FLAG_NoNamed;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(private_))) {
		_flagsToSet |= FLAG_Private;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(public_))) {
		_flagsToSet |= FLAG_Public;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(symbol_func))) {
		_flagsToSet |= FLAG_SymbolFunc;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(trailer))) {
		_flagsToSet |= FLAG_Trailer;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(noflat))) {
		_flagsToSet &= ~FLAG_Flat;
		_flagsToClear |= FLAG_Flat;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(iter))) {
		_resultMode = RSLTMODE_Iterator;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(list))) {
		_resultMode = RSLTMODE_List;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(reduce))) {
		_resultMode = RSLTMODE_Reduce;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(set))) {
		_resultMode = RSLTMODE_Set;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(void_))) {
		_resultMode = RSLTMODE_Void;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(xiter))) {
		_resultMode = RSLTMODE_XIterator;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(xlist))) {
		_resultMode = RSLTMODE_XList;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(xreduce))) {
		_resultMode = RSLTMODE_XReduce;
		return true;
	}
	if (pSymbol->IsIdentical(Gura_Symbol(xset))) {
		_resultMode = RSLTMODE_XSet;
		return true;
	}
	return false;
#endif
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
