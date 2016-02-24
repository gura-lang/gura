//=============================================================================
// Argument
//=============================================================================
#ifndef __GURA_ARGUMENT_H__
#define __GURA_ARGUMENT_H__

#include "Common.h"
#include "Declaration.h"
#include "Environment.h"
#include "Parser.h"
#include "Help.h"

namespace Gura {

class Function;

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
	enum SlotStat {
		SLOTSTAT_Invalid,
		SLOTSTAT_Valid,
		SLOTSTAT_ValidAssigned,
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
		SlotStat _slotStat;
	public:
		inline Slot(Declaration *pDecl) :
			_pDecl(pDecl),
			_value(Value::Undefined),
			_slotStat(SLOTSTAT_Invalid) {}
		inline Slot(Declaration *pDecl, const Value &value,
					Iterator *pIteratorMap, SlotStat slotStat) :
			_pDecl(pDecl),
			_value(value),
			_pIteratorMap(pIteratorMap),
			_slotStat(slotStat) {}
		inline Slot(const Slot &slot) :
			_pDecl(slot._pDecl->Reference()),
			_value(slot._value),
			_pIteratorMap(Iterator::Reference(slot._pIteratorMap.get())),
			_slotStat(slot._slotStat) {}
		inline void operator=(const Slot &slot) {
			_pDecl.reset(slot._pDecl->Reference());
			_value = slot._value;
			_pIteratorMap.reset(Iterator::Reference(slot._pIteratorMap.get()));
			_slotStat = slot._slotStat;
		}
		inline const Declaration &GetDeclaration() const { return *_pDecl; }
		inline const Value &GetValue() const { return _value; }
		inline void SetIteratorMap(Iterator *pIteratorMap) { _pIteratorMap.reset(pIteratorMap); }
		inline Iterator *GetIteratorMap() { return _pIteratorMap.get(); }
		inline const Iterator *GetIteratorMap() const { return _pIteratorMap.get(); }
		inline SlotStat GetSlotStat() const { return _slotStat; }
		inline void SetSlotStat(SlotStat slotStat) { _slotStat = slotStat; }
		inline bool NextMap(Environment &env) {
			if (_pIteratorMap.IsNull()) return true;
			_slotStat = SLOTSTAT_Valid;
			return (_pIteratorMap->Next(env, _value) &&
					(_pDecl->IsVariableLength() || _pDecl->ValidateAndCast(env, _value)));
		}
		bool StoreValue(Environment &env, const Value &value, bool mapFlag, MapMode *pMapMode);
		bool UpdateValue(Environment &env, const Value &value);
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
	AutoPtr<Environment> _pEnvPrepared;
public:
	Gura_DeclareReferenceAccessor(Argument);
public:
	inline static void *operator new(size_t size) {
		return MemoryPool::Allocate(size, "Argument");
	}
	inline static void operator delete(void *pv) {
		MemoryPool::Deallocate(pv);
	}
public:
	Argument(const Function *pFunc);
	Argument(const Function *pFunc, const CallerInfo &callerInfo);
protected:
	~Argument();
	void InitializeSlot(const Function *pFunc);
public:
	inline Function *GetFunction() const { return _pFunc.get(); }
	inline bool IsAttrEmpty() const { return GetAttrs().empty(); }
	inline void SetAttrsShared(SymbolSetShared *pAttrsShared) {
		_pAttrsShared.reset(pAttrsShared);
	}
	inline const SymbolSetShared *GetAttrsShared() const { return _pAttrsShared.get(); }
	inline const SymbolSet &GetAttrs() const {
		return _pAttrsShared.IsNull()? SymbolSet::Empty : _pAttrsShared->GetSymbolSet();
	}
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
	bool EvalExpr(Environment &env, const ExprList &exprListArg);
	bool StoreValue(Environment &env, const Value &value);
	inline bool StoreValue(Environment &env, const Value &v1, const Value &v2) {
		return StoreValue(env, v1) && StoreValue(env, v2);
	}
	inline bool StoreValue(Environment &env, const Value &v1, const Value &v2, const Value &v3) {
		return StoreValue(env, v1) && StoreValue(env, v2) && StoreValue(env, v3);
	}
	inline bool StoreValue(Environment &env, const Value &v1, const Value &v2,
						 const Value &v3, const Value &v4) {
		return StoreValue(env, v1) && StoreValue(env, v2) && StoreValue(env, v3) && StoreValue(env, v4);
	}
	bool StoreValues(Environment &env, const ValueList &valList);
	bool UpdateValue(Environment &env, size_t iSlot, const Value &value);
	bool UpdateValues(Environment &env, const ValueList &valList);
	void SetIteratorThis(Iterator *pIteratorThis);
	bool IsSet(const Symbol *pSymbol) const;
	bool Complete(Environment &env);
	inline const Value &GetValue(size_t idxArg) const	{ return _slots[idxArg].GetValue();				}
	void GetSlotValues(ValueList &valList) const;
	void GetSlotValues(Object_list *pObjList) const;
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
	inline bool Is_array_char(size_t idxArg) const		{ return GetValue(idxArg).Is_array_char();		}
	inline bool Is_array_uchar(size_t idxArg) const		{ return GetValue(idxArg).Is_array_uchar();		}
	inline bool Is_array_short(size_t idxArg) const		{ return GetValue(idxArg).Is_array_short();		}
	inline bool Is_array_ushort(size_t idxArg) const	{ return GetValue(idxArg).Is_array_ushort();	}
	inline bool Is_array_int(size_t idxArg) const		{ return GetValue(idxArg).Is_array_int();		}
	inline bool Is_array_uint(size_t idxArg) const		{ return GetValue(idxArg).Is_array_uint();		}
	inline bool Is_array_int32(size_t idxArg) const		{ return GetValue(idxArg).Is_array_int32();		}
	inline bool Is_array_uint32(size_t idxArg) const	{ return GetValue(idxArg).Is_array_uint32();	}
	inline bool Is_array_int64(size_t idxArg) const		{ return GetValue(idxArg).Is_array_int64();		}
	inline bool Is_array_uint64(size_t idxArg) const	{ return GetValue(idxArg).Is_array_uint64();	}
	inline bool Is_array_float(size_t idxArg) const		{ return GetValue(idxArg).Is_array_float();		}
	inline bool Is_array_double(size_t idxArg) const	{ return GetValue(idxArg).Is_array_double();	}
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
	inline bool Is_memory(size_t idxArg) const			{ return GetValue(idxArg).Is_memory();			}
	inline bool Is_operator(size_t idxArg) const		{ return GetValue(idxArg).Is_operator();		}
	inline bool Is_palette(size_t idxArg) const			{ return GetValue(idxArg).Is_palette();			}
	inline bool Is_pointer(size_t idxArg) const			{ return GetValue(idxArg).Is_pointer();			}
	inline bool Is_semaphore(size_t idxArg) const		{ return GetValue(idxArg).Is_semaphore();		}
	inline bool Is_stream(size_t idxArg) const			{ return GetValue(idxArg).Is_stream();			}
	inline bool Is_suffixmgr(size_t idxArg) const		{ return GetValue(idxArg).Is_suffixmgr();		}
	inline bool Is_template(size_t idxArg) const		{ return GetValue(idxArg).Is_template();		}
	inline bool Is_timedelta(size_t idxArg) const		{ return GetValue(idxArg).Is_timedelta();		}
	inline bool Is_uri(size_t idxArg) const				{ return GetValue(idxArg).Is_uri();				}
	inline bool Is_vertex(size_t idxArg) const			{ return GetValue(idxArg).Is_vertex();			}
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
	inline Int32 GetInt32(size_t idxArg) const			{ return GetValue(idxArg).GetInt32();			}
	inline UInt32 GetUInt32(size_t idxArg) const		{ return GetValue(idxArg).GetUInt32();			}
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
	inline size_t CountSlot() const { return _slots.size(); }
	inline Slot *FindSlotBySymbol(const Symbol *pSymbol) { return _slots.FindBySymbol(pSymbol); }
	bool IsInfiniteMap() const;
	void AssignSlotValuesToEnvironment(Environment &env);
	void AssignSlotValuesToEnvironmentFast(Environment &env);
	Environment *PrepareEnvironment(Environment &env);
	inline void SetBlock(Expr_Block *pExprBlock) { _pExprBlock.reset(pExprBlock); }
	inline const Expr_Block *GetBlock() const { return _pExprBlock.get(); }
	const Expr_Block *GetBlockCooked(Environment &env) const;
	const Function *GetBlockFunc(Environment &env, const Symbol *pSymbol);
	bool NextMap(Environment &env);
	void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

}

#endif
