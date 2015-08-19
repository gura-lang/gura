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
	const SymbolSet &_attrs;
	const SymbolSet &_attrsOpt;
	//ValueType _valTypeResult;
	//ResultMode _resultMode;
	//ULong _flags;
public:
	inline CallerInfo(
		ExprList::const_iterator ppExprListArgBegin,
		ExprList::const_iterator ppExprListArgEnd,
		const Expr_Block *pExprBlock,
		const SymbolSet &attrs, const SymbolSet &attrsOpt) :
		_ppExprListArgBegin(ppExprListArgBegin),
		_ppExprListArgEnd(ppExprListArgEnd),
		_pExprBlock(pExprBlock),
		_attrs(attrs), _attrsOpt(attrsOpt) {}
	inline CallerInfo(const CallerInfo &callerInfo) :
		_ppExprListArgBegin(callerInfo._ppExprListArgBegin),
		_ppExprListArgEnd(callerInfo._ppExprListArgEnd),
		_pExprBlock(callerInfo._pExprBlock),
		_attrs(callerInfo._attrs), _attrsOpt(callerInfo._attrsOpt) {}
	inline void AdvanceExprListArgBegin() {
		if (_ppExprListArgBegin != _ppExprListArgEnd) _ppExprListArgBegin++;
	}
	inline ExprList::const_iterator GetExprListArgBegin() const { return _ppExprListArgBegin; }
	inline ExprList::const_iterator GetExprListArgEnd() const { return _ppExprListArgEnd; }
	inline const Expr_Block *GetBlock() const { return _pExprBlock; }
	inline const SymbolSet &GetAttrs() const { return _attrs; }
	inline const SymbolSet &GetAttrsOpt() const { return _attrsOpt; }
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
