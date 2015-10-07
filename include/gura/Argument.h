//=============================================================================
// Argument
//=============================================================================
#ifndef __GURA_ARGUMENT_H__
#define __GURA_ARGUMENT_H__

#include "Function.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Argument
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Argument {
public:
	enum MapMode {
		MAPMODE_None,
		MAPMODE_ToList,
		MAPMODE_ToIter,
	};
public:
	class GURA_DLLDECLARE Iterator_VarLength : public Iterator {
	private:
		const Declaration *_pDecl;
		ValueList &_valList;
		IteratorOwner _iterOwner;
		bool _finiteFoundFlag;
	public:
		inline Iterator_VarLength(const Declaration *pDecl, ValueList &valList) :
			Iterator(false), _pDecl(pDecl), _valList(valList), _finiteFoundFlag(false) {}
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
		void AddIterator(Iterator *pIterator);
	};
	class GURA_DLLDECLARE Slot {
	private:
		AutoPtr<Declaration> _pDecl;
		Value _value;
		AutoPtr<Iterator> _pIteratorMap;
		bool _valueExistFlag;
	public:
		inline Slot(Declaration *pDecl) :
			_pDecl(pDecl),
			_value(Value::Undefined),
			_valueExistFlag(false) {}
		inline Slot(Declaration *pDecl, const Value &value,
					Iterator *pIteratorMap, bool valueExistFlag) :
			_pDecl(pDecl),
			_value(value),
			_pIteratorMap(pIteratorMap),
			_valueExistFlag(valueExistFlag) {}
		inline Slot(const Slot &slot) :
			_pDecl(slot._pDecl->Reference()),
			_value(slot._value),
			_pIteratorMap(Iterator::Reference(slot._pIteratorMap.get())),
			_valueExistFlag(slot._valueExistFlag) {}
		inline void operator=(const Slot &slot) {
			_pDecl.reset(slot._pDecl->Reference());
			_value = slot._value;
			_pIteratorMap.reset(Iterator::Reference(slot._pIteratorMap.get()));
			_valueExistFlag = slot._valueExistFlag;
		}
		inline const Declaration &GetDeclaration() const { return *_pDecl; }
		inline const Value &GetValue() const { return _value; }
		inline void SetIteratorMap(Iterator *pIteratorMap) { _pIteratorMap.reset(pIteratorMap); }
		inline Iterator *GetIteratorMap() { return _pIteratorMap.get(); }
		inline const Iterator *GetIteratorMap() const { return _pIteratorMap.get(); }
		inline bool GetValueExistFlag() const { return _valueExistFlag; }
		inline bool NextMap(Environment &env) {
			return _pIteratorMap.IsNull() ||
				(_pIteratorMap->Next(env, _value) &&
				 (_pDecl->IsVariableLength() || _pDecl->ValidateAndCast(env, _value)));
		}
		bool SetValue(Environment &env, const Value &value, bool mapFlag, MapMode *pMapMode);
	};
	class Slots : public std::vector<Slot> {
	public:
		inline Slots() {}
		Slot *FindBySymbol(const Symbol *pSymbol);
	};
private:
	int _cntRef;
	AutoPtr<Function> _pFunc;
	ValueType _valTypeResult;
	ResultMode _resultMode;
	ULong _flags;
	AutoPtr<ValueDict> _pValDictArg;
	AutoPtr<SymbolSetShared> _pAttrsShared;
	AutoPtr<Expr_Block> _pExprBlock;
	AutoPtr<Function> _pFuncBlock;
	Value _valueThis;
	AutoPtr<Iterator> _pIteratorThis;
	MapMode _mapMode;
	AutoPtr<TrailCtrlHolder> _pTrailCtrlHolder;
	Slots _slots;
	Slots::iterator _pSlotCur;
public:
	Gura_DeclareReferenceAccessor(Argument);
#if 0
public:
	inline static void *operator new(size_t size) {
		::printf("[Argument: %ld bytes]\n", size);
		return ::malloc(size);
	}
	inline static void operator delete(void *pv) noexcept {
		::free(pv);
	}
#endif
public:
	Argument(const Function *pFunc);
	Argument(const Function *pFunc, const CallerInfo &callerInfo);
protected:
	void InitializeSlot(const Function *pFunc);
	inline ~Argument() {}
public:
	inline Function *GetFunction() const { return _pFunc.get(); }
	inline bool IsAttrEmpty() const { return GetAttrs().empty(); }
	inline void SetAttrsShared(SymbolSetShared *pAttrsShared) {
		_pAttrsShared.reset(pAttrsShared);
	}
	inline const SymbolSetShared *GetAttrsShared() const { return _pAttrsShared.get(); }
	inline const SymbolSetShared *GetAttrsOptShared() const { return _pFunc->GetAttrsOptShared(); }
	inline const SymbolSet &GetAttrs() const {
		return _pAttrsShared.IsNull()? SymbolSet::Empty : _pAttrsShared->GetSymbolSet();
	}
	inline const SymbolSet &GetAttrsOpt() const { return _pFunc->GetAttrsOpt(); }
	inline void SetValueTypeResult(ValueType valTypeResult) { _valTypeResult = valTypeResult; }
	inline ValueType GetValueTypeResult() const { return _valTypeResult; }
	inline void SetResultMode(ResultMode resultMode) { _resultMode = resultMode; }
	inline ResultMode GetResultMode() const { return _resultMode; }
	inline void SetFlags(ULong flags) { _flags = flags; }
	inline ULong GetFlags() const { return _flags; }
	inline bool GetFlag(ULong flag) const { return (_flags & flag) != 0; }
	inline void SetValueThis(const Value &valueThis) { _valueThis = valueThis; }
	inline Value &GetValueThis() { return _valueThis; }
	inline const Value &GetValueThis() const { return _valueThis; }
	inline Object *GetObjectThis() { return _valueThis.GetObject(); }
	inline const Object *GetObjectThis() const { return _valueThis.GetObject(); }
	inline Fundamental *GetFundamentalThis() { return _valueThis.GetFundamental(); }
	inline const Fundamental *GetFundamentalThis() const { return _valueThis.GetFundamental(); }
	inline Iterator *GetIteratorThis() { return _pIteratorThis.get(); }
	inline bool IsThisIterable() const { return !_pIteratorThis.IsNull(); }
	inline bool IsBlockSpecified() const { return !_pExprBlock.IsNull(); }
	inline bool IsResultIterator() const	{ return _resultMode == RSLTMODE_Iterator;	}
	inline bool IsResultList() const		{ return _resultMode == RSLTMODE_List;		}
	inline bool IsResultNormal() const		{ return _resultMode == RSLTMODE_Normal;	}
	inline bool IsResultReduce() const		{ return _resultMode == RSLTMODE_Reduce;	}
	inline bool IsResultSet() const			{ return _resultMode == RSLTMODE_Set;		}
	inline bool IsResultVoid() const		{ return _resultMode == RSLTMODE_Void;		}
	inline bool IsResultXIterator() const	{ return _resultMode == RSLTMODE_XIterator;	}
	inline bool IsResultXList() const		{ return _resultMode == RSLTMODE_XList;		}
	inline bool IsResultXReduce() const		{ return _resultMode == RSLTMODE_XReduce;	}
	inline bool IsResultXSet() const		{ return _resultMode == RSLTMODE_XSet;		} 
	inline bool IsResultMulti() const {
		return IsResultList() || IsResultXList() ||
			IsResultSet() || IsResultXSet() || IsResultIterator() || IsResultXIterator();
	}
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
	bool EvalExpr(Environment &env, const ExprList &exprListArg);
	bool AddValue(Environment &env, const Value &value);
	inline bool AddValue(Environment &env, const Value &v1, const Value &v2) {
		return AddValue(env, v1) && AddValue(env, v2);
	}
	inline bool AddValue(Environment &env, const Value &v1, const Value &v2, const Value &v3) {
		return AddValue(env, v1) && AddValue(env, v2) && AddValue(env, v3);
	}
	inline bool AddValue(Environment &env, const Value &v1, const Value &v2,
						 const Value &v3, const Value &v4) {
		return AddValue(env, v1) && AddValue(env, v2) && AddValue(env, v3) && AddValue(env, v4);
	}
	bool AddValues(Environment &env, const ValueList &valList);
	void SetIteratorThis(Iterator *pIteratorThis);
	bool IsSet(const Symbol *pSymbol) const;
	bool Complete(Environment &env);
	inline const Value &GetValue(size_t idxArg) const	{ return _slots[idxArg].GetValue();				}
	void GetValues(ValueList &valList) const;
	inline bool IsType(size_t idxArg, ValueType valType) const
														{ return GetValue(idxArg).IsType(valType); 		}
	// invalid types
	inline bool IsValid(size_t idxArg) const			{ return GetValue(idxArg).IsValid();			}
	inline bool IsInvalid(size_t idxArg) const			{ return GetValue(idxArg).IsInvalid();			}
	inline bool IsDefined(size_t idxArg) const			{ return GetValue(idxArg).IsDefined();			}
	inline bool IsUndefined(size_t idxArg) const		{ return GetValue(idxArg).IsUndefined();		}
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
	inline bool Is_argument(size_t idxArg) const		{ return GetValue(idxArg).Is_argument();		}
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
	inline Number GetNumber(size_t idxArg) const		{ return GetValue(idxArg).GetNumber();			}
	inline int GetInt(size_t idxArg) const				{ return GetValue(idxArg).GetInt();				}
	inline UInt GetUInt(size_t idxArg) const			{ return GetValue(idxArg).GetUInt();			}
	inline size_t GetSizeT(size_t idxArg) const			{ return GetValue(idxArg).GetSizeT();			}
	inline char GetChar(size_t idxArg) const			{ return GetValue(idxArg).GetChar();			}
	inline UChar GetUChar(size_t idxArg) const			{ return GetValue(idxArg).GetUChar();			}
	inline short GetShort(size_t idxArg) const			{ return GetValue(idxArg).GetShort();			}
	inline UShort GetUShort(size_t idxArg) const		{ return GetValue(idxArg).GetUShort();			}
	inline long GetLong(size_t idxArg) const			{ return GetValue(idxArg).GetLong();			}
	inline ULong GetULong(size_t idxArg) const			{ return GetValue(idxArg).GetULong();			}
	inline Int64 GetInt64(size_t idxArg) const			{ return GetValue(idxArg).GetInt64();			}
	inline UInt64 GetUInt64(size_t idxArg) const		{ return GetValue(idxArg).GetUInt64();			}
	inline float GetFloat(size_t idxArg) const			{ return GetValue(idxArg).GetFloat();			}
	inline double GetDouble(size_t idxArg) const		{ return GetValue(idxArg).GetDouble();			}
	inline bool GetBoolean(size_t idxArg) const			{ return GetValue(idxArg).GetBoolean();			}
	inline const Symbol *GetSymbol(size_t idxArg) const	{ return GetValue(idxArg).GetSymbol();			}
	inline Fundamental *GetFundamental(size_t idxArg) const
														{ return GetValue(idxArg).GetFundamental();		}
	inline Module *GetModule(size_t idxArg) const		{ return GetValue(idxArg).GetModule();			}
	inline Class *GetClassItself(size_t idxArg) const	{ return GetValue(idxArg).GetClassItself();		}
	inline Object *GetObject(size_t idxArg) const		{ return GetValue(idxArg).GetObject();			}
	inline const char *GetString(size_t idxArg) const	{ return GetValue(idxArg).GetString();			}
	inline String GetStringSTL(size_t idxArg) const		{ return GetValue(idxArg).GetStringSTL();		}
	inline const Binary &GetBinary(size_t idxArg) const	{ return GetValue(idxArg).GetBinary();			}
	inline Complex GetComplex(size_t idxArg) const		{ return GetValue(idxArg).GetComplex();			}
	inline const ValueList &GetList(size_t idxArg) const{ return GetValue(idxArg).GetList();			}
	inline const ValueDict &GetDict(size_t idxArg) const{ return GetValue(idxArg).GetDict();			}
	inline Iterator *GetIterator(size_t idxArg) const	{ return GetValue(idxArg).GetIterator();		}
	inline Stream &GetStream(size_t idxArg) const		{ return GetValue(idxArg).GetStream();			}
	inline const Expr *GetExpr(size_t idxArg) const		{ return GetValue(idxArg).GetExpr();			}
	inline Function *GetFunction(size_t idxArg) const	{ return GetValue(idxArg).GetFunction();		}
	inline ErrorType GetErrorType(size_t idxArg) const	{ return GetValue(idxArg).GetErrorType();		}
	inline void AddValueDictItem(const Value &valueKey, const Value &value) {
		if (_pValDictArg.IsNull()) _pValDictArg.reset(new ValueDict());
		(*_pValDictArg)[valueKey] = value;
	}
	inline const ValueDict &GetValueDictArg() const { 
		return _pValDictArg.IsNull()? ValueDict::Empty : *_pValDictArg;
	}
	inline MapMode GetMapMode() const { return _mapMode; }
	bool IsInfiniteMap() const;
	void AssignToEnvironment(Environment &env) const;
	Environment *PrepareEnvironment(Environment &env, bool thisAssignFlag) const;
	inline void SetBlock(Expr_Block *pExprBlock) { _pExprBlock.reset(pExprBlock); }
	inline const Expr_Block *GetBlock() const { return _pExprBlock.get(); }
	const Expr_Block *GetBlockCooked(Environment &env) const;
	const Function *GetBlockFunc(Environment &env, const Symbol *pSymbol);
	bool NextMap(Environment &env);
	void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

}

#endif
