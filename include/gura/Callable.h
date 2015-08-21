//=============================================================================
// Callable
//=============================================================================
#ifndef __GURA_CALLABLE_H__
#define __GURA_CALLABLE_H__

#include "Common.h"
#include "Expr.h"

namespace Gura {

//-----------------------------------------------------------------------------
// CallerInfo
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CallerInfo {
private:
	ExprList::const_iterator _ppExprListArgBegin;
	ExprList::const_iterator _ppExprListArgEnd;
	const Expr_Block *_pExprBlock;
	const SymbolSetShared *_pAttrsShrd;
	const SymbolSetShared *_pAttrsOptShrd;
	//ULong _flagsToSet;
	//ULong _flagsToClear;
	//ResultMode _resultMode;
	//ValueType _valTypeResult;
public:
	inline CallerInfo(
		ExprList::const_iterator ppExprListArgBegin,
		ExprList::const_iterator ppExprListArgEnd,
		const Expr_Block *pExprBlock,
		const SymbolSetShared *pAttrsShrd, const SymbolSetShared *pAttrsOptShrd) :
		_ppExprListArgBegin(ppExprListArgBegin),
		_ppExprListArgEnd(ppExprListArgEnd),
		_pExprBlock(pExprBlock),
		_pAttrsShrd(pAttrsShrd), _pAttrsOptShrd(pAttrsOptShrd) {}
	inline CallerInfo(const CallerInfo &callerInfo) :
		_ppExprListArgBegin(callerInfo._ppExprListArgBegin),
		_ppExprListArgEnd(callerInfo._ppExprListArgEnd),
		_pExprBlock(callerInfo._pExprBlock),
		_pAttrsShrd(callerInfo._pAttrsShrd), _pAttrsOptShrd(callerInfo._pAttrsOptShrd) {}
	inline void AdvanceExprListArgBegin() {
		if (_ppExprListArgBegin != _ppExprListArgEnd) _ppExprListArgBegin++;
	}
	inline ExprList::const_iterator GetExprListArgBegin() const { return _ppExprListArgBegin; }
	inline ExprList::const_iterator GetExprListArgEnd() const { return _ppExprListArgEnd; }
	inline const Expr_Block *GetBlock() const { return _pExprBlock; }
	inline const SymbolSetShared *GetAttrsShared() const { return _pAttrsShrd; }
	inline const SymbolSetShared *GetAttrsOptShared() const { return _pAttrsOptShrd; }
	inline const SymbolSet &GetAttrs() const {
		return (_pAttrsShrd == nullptr)? SymbolSet::Empty : _pAttrsShrd->GetSymbolSet();
	}
	inline const SymbolSet &GetAttrsOpt() const {
		return (_pAttrsOptShrd == nullptr)? SymbolSet::Empty : _pAttrsOptShrd->GetSymbolSet();
	}
};

//-----------------------------------------------------------------------------
// Callable
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Callable {
public:
	virtual Value DoCall(
		Environment &env, const CallerInfo &callerInfo,
		const Value &valueThis, const Iterator *pIteratorThis, bool listThisFlag,
		const TrailCtrlHolder *pTrailCtrlHolder) = 0;
	virtual bool IsLeader() const;
	virtual bool IsTrailer() const;
	virtual bool IsFinalizer() const;
	virtual bool IsEndMarker() const;
	virtual OccurPattern GetBlockOccurPattern() const;
};

}

#endif
