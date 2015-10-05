//=============================================================================
// Callable
//=============================================================================
#ifndef __GURA_CALLABLE_H__
#define __GURA_CALLABLE_H__

#include "ValueType.h"

namespace Gura {

class ExprList;
class Expr_Block;
class Environment;
class Value;
class TrailCtrlHolder;
class Iterator;

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
		_resultMode(RSLTMODE_Normal), _valTypeResult(VTYPE_undefined) {}
	inline CallerInfo(const CallerInfo &callerInfo) :
		_exprListArg(callerInfo._exprListArg),
		_pExprBlock(callerInfo._pExprBlock),
		_pAttrsShrd(callerInfo._pAttrsShrd), _pAttrsOptShrd(callerInfo._pAttrsOptShrd),
		_flagsToSet(callerInfo._flagsToSet), _flagsToClear(callerInfo._flagsToClear),
		_resultMode(callerInfo._resultMode), _valTypeResult(callerInfo._valTypeResult) {}
	inline const ExprList &GetExprListArg() const { return _exprListArg; }
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
	bool UpdateByAttrSymbol(const Symbol *pSymbol);
	inline String MakeAttrForFlags() const {
		return Symbol::MakeAttrForFlags(_flagsToSet, _flagsToClear);
	}
	inline String MakeAttrForResultMode() const {
		return Symbol::MakeAttrForResultMode(_resultMode);
	}
};

//-----------------------------------------------------------------------------
// Callable
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Callable {
protected:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(Callable)
public:
	inline Callable() : _cntRef(1) {}
protected:
	virtual ~Callable();
public:
	virtual Value DoCall(
		Environment &env, const CallerInfo &callerInfo,
		const Value &valueThis, const Iterator *pIteratorThis,
		const TrailCtrlHolder *pTrailCtrlHolder);
	virtual bool IsLeader() const;
	virtual bool IsTrailer() const;
	virtual bool IsFinalizer() const;
	virtual bool IsEndMarker() const;
	virtual OccurPattern GetBlockOccurPattern() const;
};

}

#endif
