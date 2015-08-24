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
	const ExprList &_exprListArg;
	const Expr_Block *_pExprBlock;
	const SymbolSetShared *_pAttrsShrd;
	const SymbolSetShared *_pAttrsOptShrd;
	ULong _flagsToSet;
	ULong _flagsToClear;
	ResultMode _resultMode;
	ValueType _valTypeResult;
	size_t _offsetArg;
public:
	static const CallerInfo Empty;
public:
	inline CallerInfo(
		const ExprList &exprListArg, const Expr_Block *pExprBlock,
		const SymbolSetShared *pAttrsShrd, const SymbolSetShared *pAttrsOptShrd) :
		_exprListArg(exprListArg),
		_pExprBlock(pExprBlock),
		_pAttrsShrd(pAttrsShrd), _pAttrsOptShrd(pAttrsOptShrd),
		_flagsToSet(0), _flagsToClear(0),
		_resultMode(RSLTMODE_Normal), _valTypeResult(VTYPE_undefined),
		_offsetArg(0) {}
	inline CallerInfo(const CallerInfo &callerInfo) :
		_exprListArg(callerInfo._exprListArg),
		_pExprBlock(callerInfo._pExprBlock),
		_pAttrsShrd(callerInfo._pAttrsShrd), _pAttrsOptShrd(callerInfo._pAttrsOptShrd),
		_flagsToSet(callerInfo._flagsToSet), _flagsToClear(callerInfo._flagsToClear),
		_resultMode(callerInfo._resultMode), _valTypeResult(callerInfo._valTypeResult),
		_offsetArg(callerInfo._offsetArg) {}
	inline void SetOffsetArg(size_t offsetArg) { _offsetArg = offsetArg; }
	inline ExprList::const_iterator GetExprListArgBegin() const {
		return _exprListArg.begin() + _offsetArg;
	}
	inline ExprList::const_iterator GetExprListArgEnd() const { return _exprListArg.end(); }
	inline const Expr_Block *GetBlock() const { return _pExprBlock; }
	inline const SymbolSetShared *GetAttrsShared() const { return _pAttrsShrd; }
	inline const SymbolSetShared *GetAttrsOptShared() const { return _pAttrsOptShrd; }
	inline const SymbolSet &GetAttrs() const {
		return (_pAttrsShrd == nullptr)? SymbolSet::Empty : _pAttrsShrd->GetSymbolSet();
	}
	inline const SymbolSet &GetAttrsOpt() const {
		return (_pAttrsOptShrd == nullptr)? SymbolSet::Empty : _pAttrsOptShrd->GetSymbolSet();
	}
	inline void SetFlagsToSet(ULong flagsToSet) { _flagsToSet = flagsToSet; }
	inline void SetFlagsToClear(ULong flagsToClear) { _flagsToClear = flagsToClear; }
	inline void SetResultMode(ResultMode resultMode) { _resultMode = resultMode; }
	inline void SetValueTypeResult(ValueType valTypeResult) { _valTypeResult = valTypeResult; }
	inline ULong GetFlagsToSet() const { return _flagsToSet; }
	inline ULong GetFlagsToClear() const { return _flagsToClear; }
	inline ResultMode GetResultMode() const { return _resultMode; }
	inline ValueType GetValueTypeResult() const { return _valTypeResult; }
	inline ULong ModifyFlags(ULong flags) const {
		return (flags & ~_flagsToClear) | _flagsToSet;
	}
	inline ResultMode ModifyResultMode(ResultMode resultMode) const {
		return (_resultMode == RSLTMODE_Normal)? resultMode : _resultMode;
	}
	inline ValueType ModifyValueTypeResult(ValueType valTypeResult) const {
		return (_valTypeResult == VTYPE_undefined)? valTypeResult : _valTypeResult;
	}
	inline bool HasAttrs() const {
		return !GetAttrs().empty() || _resultMode != RSLTMODE_Normal ||
			_flagsToSet != 0 || _flagsToClear != 0 || _valTypeResult != VTYPE_undefined;
	}
	inline bool HasAttrsOpt() const { return !GetAttrsOpt().empty(); }
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
