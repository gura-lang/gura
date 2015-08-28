//=============================================================================
// Argument
//=============================================================================
#ifndef __GURA_ARGUMENT_H__
#define __GURA_ARGUMENT_H__

#include "Function.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Args
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Args {
public:
	class GURA_DLLDECLARE Slot {
	private:
		AutoPtr<Declaration> _pDecl;
		Value _value;
	public:
		inline Slot(Declaration *pDecl) : _pDecl(pDecl), _value(Value::Undefined) {}
		inline Slot(const Slot &slot) : _pDecl(slot._pDecl->Reference()), _value(slot._value) {}
		inline void operator=(const Slot &slot) {
			_pDecl.reset(slot._pDecl->Reference());
			_value = slot._value;
		}
		inline const Declaration &GetDeclaration() const { return *_pDecl; }
		inline const Value &GetValue() const { return _value; }
		inline void SetValue(const Value &value) { _value = value; }
	};
	class SlotList : public std::vector<Slot> {
	public:
		inline SlotList() {}
		Slot *FindBySymbol(const Symbol *pSymbol);
	};
private:
	int _cntRef;
	ValueType _valTypeResult;
	ResultMode _resultMode;
	ULong _flags;
	bool _listThisFlag;
	AutoPtr<SymbolSetShared> _pAttrsShared;
	AutoPtr<SymbolSetShared> _pAttrsOptShared;
	Value _valueThis;
	ValueList _valListArg;
	SlotList _slotList;
	AutoPtr<ValueDict> _pValDictArg;
	AutoPtr<ValueMap> _pValMapHiddenArg;
	AutoPtr<TrailCtrlHolder> _pTrailCtrlHolder;
	AutoPtr<Iterator> _pIteratorThis;
	AutoPtr<Expr_Block> _pExprBlock;
	AutoPtr<Function> _pFuncBlock;
public:
	Gura_DeclareReferenceAccessor(Args);
public:
	Args(const Function *pFunc);
	inline Args(const Args &args) : _cntRef(1),
		_valTypeResult(args._valTypeResult),
		_resultMode(args._resultMode),
		_flags(args._flags),
		_listThisFlag(args._listThisFlag),
		_pAttrsShared(SymbolSetShared::Reference(args._pAttrsShared.get())),
		_pAttrsOptShared(SymbolSetShared::Reference(args._pAttrsOptShared.get())),
		_valueThis(args._valueThis),
		_valListArg(args._valListArg),
		_slotList(args._slotList),
		_pValDictArg(ValueDict::Reference(args._pValDictArg.get())),
		_pValMapHiddenArg(ValueMap::Reference(args._pValMapHiddenArg.get())),
		_pTrailCtrlHolder(TrailCtrlHolder::Reference(args._pTrailCtrlHolder.get())),
		_pIteratorThis(Iterator::Reference(args._pIteratorThis.get())),
		_pExprBlock(Expr_Block::Reference(args._pExprBlock.get())),
		_pFuncBlock(Function::Reference(args._pFuncBlock.get())) {}
	inline Args(const Args &args, const ValueList &valListArg) : _cntRef(1),
		_valTypeResult(args._valTypeResult),
		_resultMode(args._resultMode),
		_flags(args._flags),
		_listThisFlag(args._listThisFlag),
		_pAttrsShared(SymbolSetShared::Reference(args._pAttrsShared.get())),
		_pAttrsOptShared(SymbolSetShared::Reference(args._pAttrsOptShared.get())),
		_valueThis(args._valueThis),
		_valListArg(valListArg),
		_slotList(args._slotList),
		_pValDictArg(ValueDict::Reference(args._pValDictArg.get())),
		_pValMapHiddenArg(ValueMap::Reference(args._pValMapHiddenArg.get())),
		_pTrailCtrlHolder(TrailCtrlHolder::Reference(args._pTrailCtrlHolder.get())),
		_pIteratorThis(Iterator::Reference(args._pIteratorThis.get())),
		_pExprBlock(Expr_Block::Reference(args._pExprBlock.get())),
		_pFuncBlock(Function::Reference(args._pFuncBlock.get())) {}
protected:
	virtual ~Args();
public:
	inline bool IsSet(const Symbol *pSymbol) const { return GetAttrs().IsSet(pSymbol); }
	inline bool IsAttrEmpty() const { return GetAttrs().empty(); }
	inline void SetAttrsShared(SymbolSetShared *pAttrsShared) {
		_pAttrsShared.reset(pAttrsShared);
	}
	inline void SetAttrsOptShared(SymbolSetShared *pAttrsOptShared) {
		_pAttrsOptShared.reset(pAttrsOptShared);
	}
	inline const SymbolSetShared *GetAttrsShared() const { return _pAttrsShared.get(); }
	inline const SymbolSetShared *GetAttrsOptShared() const { return _pAttrsOptShared.get(); }
	inline const SymbolSet &GetAttrs() const {
		return _pAttrsShared.IsNull()? SymbolSet::Empty : _pAttrsShared->GetSymbolSet();
	}
	inline const SymbolSet &GetAttrsOpt() const {
		return _pAttrsOptShared.IsNull()? SymbolSet::Empty : _pAttrsOptShared->GetSymbolSet();
	}
	inline void SetValueTypeResult(ValueType valTypeResult) { _valTypeResult = valTypeResult; }
	inline ValueType GetValueTypeResult() const { return _valTypeResult; }
	inline void SetResultMode(ResultMode resultMode) { _resultMode = resultMode; }
	inline ResultMode GetResultMode() const { return _resultMode; }
	inline void SetFlags(ULong flags) { _flags = flags; }
	inline ULong GetFlags() const { return _flags; }
	inline void SetValueThis(const Value &valueThis) { _valueThis = valueThis; }
	inline Value &GetValueThis() { return _valueThis; }
	inline const Value &GetValueThis() const { return _valueThis; }
	inline Object *GetObjectThis() { return _valueThis.GetObject(); }
	inline const Object *GetObjectThis() const { return _valueThis.GetObject(); }
	inline Fundamental *GetFundamentalThis() { return _valueThis.GetFundamental(); }
	inline const Fundamental *GetFundamentalThis() const { return _valueThis.GetFundamental(); }
	inline void SetIteratorThis(Iterator *pIteratorThis, bool listThisFlag) {
		_pIteratorThis.reset(pIteratorThis);
		_listThisFlag = listThisFlag;
	}
	inline Iterator *GetIteratorThis() { return _pIteratorThis.get(); }
	inline bool IsThisIterable() const { return !_pIteratorThis.IsNull(); }
	inline bool IsThisList() const { return !_pIteratorThis.IsNull() && _listThisFlag; }
	inline bool IsThisIterator() const { return !_pIteratorThis.IsNull() && !_listThisFlag; }
	inline bool IsBlockSpecified() const { return !_pExprBlock.IsNull(); }
	inline bool IsRsltNormal() const { return _resultMode == RSLTMODE_Normal; }
	inline bool IsRsltList() const { return _resultMode == RSLTMODE_List; }
	inline bool IsRsltXList() const { return _resultMode == RSLTMODE_XList; }
	inline bool IsRsltSet() const { return _resultMode == RSLTMODE_Set; }
	inline bool IsRsltXSet() const { return _resultMode == RSLTMODE_XSet; }
	inline bool IsRsltIterator() const { return _resultMode == RSLTMODE_Iterator; }
	inline bool IsRsltXIterator() const { return _resultMode == RSLTMODE_XIterator; }
	inline bool IsRsltVoid() const { return _resultMode == RSLTMODE_Void; }
	inline bool IsRsltReduce() const { return _resultMode == RSLTMODE_Reduce; }
	inline bool IsRsltXReduce() const { return _resultMode == RSLTMODE_XReduce; }
	inline bool IsRsltMulti() const {
		return IsRsltList() || IsRsltXList() ||
			IsRsltSet() || IsRsltXSet() || IsRsltIterator() || IsRsltXIterator();
	}
	inline bool GetMapFlag() const { return (_flags & FLAG_Map)? true : false; }
	inline bool GetFlatFlag() const { return (_flags & FLAG_Flat)? true : false; }
	inline bool GetForkFlag() const { return (_flags & FLAG_Fork)? true : false; }
	inline bool GetDynamicScopeFlag() const { return (_flags & FLAG_DynamicScope)? true : false; }
	inline bool GetSymbolFuncFlag() const { return (_flags & FLAG_SymbolFunc)? true : false; }
	inline bool GetLeaderFlag() const { return (_flags & FLAG_Leader)? true : false; }
	inline bool GetTrailerFlag() const { return (_flags & FLAG_Trailer)? true : false; }
	inline bool GetFinalizerFlag() const { return (_flags & FLAG_Finalizer)? true : false; }
	inline bool GetEndMarkerFlag() const { return (_flags & FLAG_EndMarker)? true : false; }
	inline bool GetPublicFlag() const { return (_flags & FLAG_Public)? true : false; }
	inline bool GetPrivateFlag() const { return (_flags & FLAG_Private)? true : false; }
	inline bool GetNoNamedFlag() const { return (_flags & FLAG_NoNamed)? true : false; }
	inline void SetTrailCtrlHolder(TrailCtrlHolder *pTrailCtrlHolder) {
		_pTrailCtrlHolder.reset(pTrailCtrlHolder);
	}
	inline TrailCtrlHolder *GetTrailCtrlHolder() { return _pTrailCtrlHolder.get(); }
	inline void QuitTrailer() {
		if (!_pTrailCtrlHolder.IsNull()) _pTrailCtrlHolder->Set(TRAILCTRL_Quit);
	}
	inline void FinalizeTrailer() {
		if (!_pTrailCtrlHolder.IsNull()) _pTrailCtrlHolder->Set(TRAILCTRL_Finalize);
	}
	inline const ValueList &GetValueListArg() const { return _valListArg; }
	inline size_t CountArgs() const { return _valListArg.size(); }
	inline void ReserveValueCount(size_t n) { _valListArg.reserve(n); }
	bool AddValue(Environment &env, const Declaration *pDecl, const Value &value);
	inline void AddValue(const Value &value) { _valListArg.push_back(value); }
	inline void SetValue(const Value &value) {
		_valListArg.reserve(1);
		_valListArg.push_back(value);
	}
	inline void SetValues(const Value &v1, const Value &v2) {
		_valListArg.reserve(2);
		_valListArg.push_back(v1);
		_valListArg.push_back(v2);
	}
	inline void SetValues(const Value &v1, const Value &v2, const Value &v3) {
		_valListArg.reserve(3);
		_valListArg.push_back(v1);
		_valListArg.push_back(v2);
		_valListArg.push_back(v3);
	}
	inline void SetValues(const Value &v1, const Value &v2, const Value &v3, const Value &v4) {
		_valListArg.reserve(4);
		_valListArg.push_back(v1);
		_valListArg.push_back(v2);
		_valListArg.push_back(v3);
		_valListArg.push_back(v4);
	}
	inline void SetValues(const Value &v1, const Value &v2, const Value &v3, const Value &v4, const Value &v5) {
		_valListArg.reserve(5);
		_valListArg.push_back(v1);
		_valListArg.push_back(v2);
		_valListArg.push_back(v3);
		_valListArg.push_back(v4);
		_valListArg.push_back(v5);
	}
	inline Value GetValue(size_t idxArg) {
		return (idxArg < _valListArg.size())? _valListArg[idxArg] : Value::Nil;
	}
	inline const Value &GetValue(size_t idxArg) const {
		return (idxArg < _valListArg.size())? _valListArg[idxArg] : Value::Nil;
	}
	// nil / undefined
	inline bool IsValid(size_t idxArg) const			{ return GetValue(idxArg).IsValid();			}
	inline bool IsInvalid(size_t idxArg) const			{ return GetValue(idxArg).IsInvalid();			}
	inline bool IsDefined(size_t idxArg) const			{ return GetValue(idxArg).IsDefined();			}
	inline bool IsUndefined(size_t idxArg) const		{ return GetValue(idxArg).IsUndefined();		}
	inline bool IsType(size_t idxArg, ValueType valType) const { return GetValue(idxArg).IsType(valType); }
	// primitive types
	inline bool Is_boolean(size_t idxArg) const			{ return GetValue(idxArg).Is_boolean();			}
	inline bool Is_complex(size_t idxArg) const			{ return GetValue(idxArg).Is_complex();			}
	inline bool Is_rational(size_t idxArg) const		{ return GetValue(idxArg).Is_rational();		}
	inline bool Is_number(size_t idxArg) const			{ return GetValue(idxArg).Is_number();			}
	inline bool Is_string(size_t idxArg) const			{ return GetValue(idxArg).Is_string();			}
	inline bool Is_symbol(size_t idxArg) const			{ return GetValue(idxArg).Is_symbol();			}
	inline bool IsNumberOrComplex(size_t idxArg) const	{ return GetValue(idxArg).IsNumberOrComplex();	}
	// container types
	inline bool IsModule(size_t idxArg) const			{ return GetValue(idxArg).IsModule();			}
	inline bool IsClass(size_t idxArg) const			{ return GetValue(idxArg).IsClass();			}
	// object types
	inline bool IsGenericObject(size_t idxArg) const	{ return GetValue(idxArg).IsGenericObject();	}
	inline bool IsStruct(size_t idxArg) const			{ return GetValue(idxArg).IsStruct();			}
	inline bool Is_args(size_t idxArg) const			{ return GetValue(idxArg).Is_args();			}
	inline bool Is_audio(size_t idxArg) const			{ return GetValue(idxArg).Is_audio();			}
	inline bool Is_binary(size_t idxArg) const			{ return GetValue(idxArg).Is_binary();			}
	inline bool Is_codec(size_t idxArg) const			{ return GetValue(idxArg).Is_codec();			}
	inline bool Is_color(size_t idxArg) const			{ return GetValue(idxArg).Is_color();			}
	inline bool Is_datetime(size_t idxArg) const		{ return GetValue(idxArg).Is_datetime();		}
	inline bool Is_declaration(size_t idxArg) const		{ return GetValue(idxArg).Is_declaration();		}
	inline bool Is_dict(size_t idxArg) const			{ return GetValue(idxArg).Is_dict();			}
	inline bool Is_directory(size_t idxArg) const		{ return GetValue(idxArg).Is_directory();		}
	inline bool Is_environment(size_t idxArg) const		{ return GetValue(idxArg).Is_environment();		}
	inline bool Is_error(size_t idxArg) const			{ return GetValue(idxArg).Is_error();			}
	inline bool Is_expr(size_t idxArg) const			{ return GetValue(idxArg).Is_expr();			}
	inline bool Is_formatter(size_t idxArg) const		{ return GetValue(idxArg).Is_formatter();		}
	inline bool Is_function(size_t idxArg) const		{ return GetValue(idxArg).Is_function();		}
	inline bool Is_help(size_t idxArg) const			{ return GetValue(idxArg).Is_help();			}
	inline bool Is_image(size_t idxArg) const			{ return GetValue(idxArg).Is_image();			}
	inline bool Is_iterator(size_t idxArg) const		{ return GetValue(idxArg).Is_iterator();		}
	inline bool Is_list(size_t idxArg) const			{ return GetValue(idxArg).Is_list();			}
	inline bool Is_matrix(size_t idxArg) const			{ return GetValue(idxArg).Is_matrix();			}
	inline bool Is_operator(size_t idxArg) const		{ return GetValue(idxArg).Is_operator();		}
	inline bool Is_palette(size_t idxArg) const			{ return GetValue(idxArg).Is_palette();			}
	inline bool Is_pointer(size_t idxArg) const			{ return GetValue(idxArg).Is_pointer();			}
	inline bool Is_semaphore(size_t idxArg) const		{ return GetValue(idxArg).Is_semaphore();		}
	inline bool Is_stream(size_t idxArg) const			{ return GetValue(idxArg).Is_stream();			}
	inline bool Is_suffixmgr(size_t idxArg) const		{ return GetValue(idxArg).Is_suffixmgr();		}
	inline bool Is_template(size_t idxArg) const		{ return GetValue(idxArg).Is_template();		}
	inline bool Is_timedelta(size_t idxArg) const		{ return GetValue(idxArg).Is_timedelta();		}
	inline bool Is_uri(size_t idxArg) const				{ return GetValue(idxArg).Is_uri();				}
	inline bool IsInstanceOf(size_t idxArg, ValueType valType) { return GetValue(idxArg).IsInstanceOf(valType); }
	inline Number GetNumber(size_t idxArg) const		{ return GetValue(idxArg).GetNumber();	}
	inline int GetInt(size_t idxArg) const				{ return GetValue(idxArg).GetInt();		}
	inline UInt GetUInt(size_t idxArg) const			{ return GetValue(idxArg).GetUInt();	}
	inline size_t GetSizeT(size_t idxArg) const			{ return GetValue(idxArg).GetSizeT();	}
	inline char GetChar(size_t idxArg) const			{ return GetValue(idxArg).GetChar();	}
	inline UChar GetUChar(size_t idxArg) const			{ return GetValue(idxArg).GetUChar();	}
	inline short GetShort(size_t idxArg) const			{ return GetValue(idxArg).GetShort();	}
	inline UShort GetUShort(size_t idxArg) const		{ return GetValue(idxArg).GetUShort();	}
	inline long GetLong(size_t idxArg) const			{ return GetValue(idxArg).GetLong();	}
	inline ULong GetULong(size_t idxArg) const			{ return GetValue(idxArg).GetULong();	}
	inline Int64 GetInt64(size_t idxArg) const			{ return GetValue(idxArg).GetInt64();	}
	inline UInt64 GetUInt64(size_t idxArg) const		{ return GetValue(idxArg).GetUInt64();	}
	inline float GetFloat(size_t idxArg) const			{ return GetValue(idxArg).GetFloat();	}
	inline double GetDouble(size_t idxArg) const		{ return GetValue(idxArg).GetDouble();	}
	inline bool GetBoolean(size_t idxArg) const			{ return GetValue(idxArg).GetBoolean();	}
	inline const Symbol *GetSymbol(size_t idxArg) const	{ return GetValue(idxArg).GetSymbol();	}
	inline Object *GetObject(size_t idxArg)				{ return GetValue(idxArg).GetObject();	}
	inline Object *GetObject(size_t idxArg) const		{ return GetValue(idxArg).GetObject();	}
	inline const char *GetString(size_t idxArg) const	{ return GetValue(idxArg).GetString();	}
	inline String GetStringSTL(size_t idxArg) const		{ return GetValue(idxArg).GetStringSTL(); }
	inline const Binary &GetBinary(size_t idxArg) const	{ return GetValue(idxArg).GetBinary();	}
	inline Complex GetComplex(size_t idxArg) const		{ return GetValue(idxArg).GetComplex();	}
	inline Module *GetModule(size_t idxArg)				{ return GetValue(idxArg).GetModule();	}
	inline const Module *GetModule(size_t idxArg) const	{ return GetValue(idxArg).GetModule();	}
	inline const ValueList &GetList(size_t idxArg) const{ return GetValue(idxArg).GetList();	}
	inline const ValueDict &GetDict(size_t idxArg) const{ return GetValue(idxArg).GetDict();	}
	inline Iterator *GetIterator(size_t idxArg) const	{ return GetValue(idxArg).GetIterator();}
	inline Stream &GetStream(size_t idxArg)				{ return GetValue(idxArg).GetStream();	}
	inline Stream &GetStream(size_t idxArg) const		{
		return const_cast<Args *>(this)->GetValue(idxArg).GetStream();
	}
	inline const Expr *GetExpr(size_t idxArg) const		{ return GetValue(idxArg).GetExpr();	}
	inline Function *GetFunction(size_t idxArg)			{ return GetValue(idxArg).GetFunction(); }
	inline const Function *GetFunction(size_t idxArg) const	{ return GetValue(idxArg).GetFunction(); }
	inline ErrorType GetErrorType(size_t idxArg) const	{ return GetValue(idxArg).GetErrorType(); }
	inline void SetValueListArg(const ValueList &valListArg) { _valListArg = valListArg; }
	inline void SetValueDictArg(ValueDict *pValDictArg) { _pValDictArg.reset(pValDictArg); }
	inline const ValueDict &GetValueDictArg() const { 
		return _pValDictArg.IsNull()? ValueDict::Empty : *_pValDictArg;
	}
	inline void SetValueMapHiddenArg(ValueMap *pValMapHiddenArg) { _pValMapHiddenArg.reset(pValMapHiddenArg); }
	inline ValueMap *GetValueMapHiddenArg() { return _pValMapHiddenArg.get(); }
	bool ShouldGenerateIterator(const DeclarationList &declList) const;
	inline void SetBlock(Expr_Block *pExprBlock) { _pExprBlock.reset(pExprBlock); }
	const Expr_Block *GetBlock() const { return _pExprBlock.get(); }
	const Expr_Block *GetBlockCooked(Environment &env) const;
	const Function *GetBlockFunc(Environment &env, const Symbol *pSymbol);
};

}

#endif
