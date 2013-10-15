#ifndef __GURA_FUNCTION_H__
#define __GURA_FUNCTION_H__

#include "Common.h"
#include "Declaration.h"
#include "Environment.h"
#include "Parser.h"
#include "Iterator.h"
#include "Help.h"

// DeclareFunction
#define Gura_DeclareFunctionAlias(name, nameAlias) \
class Func_##name : public Function { \
public: \
	Func_##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const; \
}; \
Func_##name::Func_##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareFunction(name) Gura_DeclareFunctionAlias(name, #name)

// DeclareFunctionWithDiffUnary
#define Gura_DeclareFunctionWithDiffUnaryAlias(name, nameAlias) \
class Func_##name : public Function { \
public: \
	Func_##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const; \
	virtual Expr *DiffUnary(Environment &env, Signal sig, const Expr *pExprArg, const Symbol *pSymbol) const; \
}; \
Func_##name::Func_##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareFunctionWithDiffUnary(name) \
Gura_DeclareFunctionWithDiffUnaryAlias(name, #name)

// DeclareFunctionTrailer
#define Gura_DeclareFunctionTrailerAlias(name, nameAlias) \
class Func_##name : public Function { \
public: \
	Func_##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const; \
}; \
Func_##name::Func_##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareFunctionTrailer(name) \
Gura_DeclareFunctionTrailerAlias(name, #name)

// DeclareMethod
#define Gura_DeclareMethodAlias(className, name, nameAlias) \
class Func_##className##__##name : public Function { \
public: \
	Func_##className##__##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const; \
}; \
Func_##className##__##name::Func_##className##__##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Instance, FLAG_None)

#define Gura_DeclareMethod(className, name) Gura_DeclareMethodAlias(className, name, #name)

// DeclareMethodPrimitive
#define Gura_DeclareMethodPrimitiveAlias(className, name, nameAlias) \
class Func_##className##__##name : public Function { \
public: \
	Func_##className##__##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const; \
}; \
Func_##className##__##name::Func_##className##__##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareMethodPrimitive(className, name) Gura_DeclareMethodPrimitiveAlias(className, name, #name)

// DeclareClassMethod
#define Gura_DeclareClassMethodAlias(className, name, nameAlias) \
class Func_##className##__##name : public Function { \
public: \
	Func_##className##__##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const; \
}; \
Func_##className##__##name::Func_##className##__##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Class, FLAG_None)

#define Gura_DeclareClassMethod(className, name) Gura_DeclareClassMethodAlias(className, name, #name)

#define Gura_ImplementFunction(name) \
Value Func_##name::DoEval(Environment &env, Signal sig, Args &args) const

#define Gura_ImplementMethod(className, name) \
Value Func_##className##__##name::DoEval(Environment &env, Signal sig, Args &args) const

#define Gura_ImplementClassMethod(className, name) \
Value Func_##className##__##name::DoEval(Environment &env, Signal sig, Args &args) const

#define Gura_ImplementDiffUnary(name) \
Expr *Func_##name::DiffUnary(Environment &env, Signal sig, const Expr *pExprArg, const Symbol *pSymbol) const

#define Gura_Function(name) Func_##name

#define Gura_Method(className, name) Func_##className##__##name

#define Gura_DeclareFunctionBegin(name) \
class Func_##name : public Function {

#define Gura_DeclareFunctionEnd(name) \
public: \
	Func_##name(Environment &env, const char *name = #name); \
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const; \
}; \
Func_##name::Func_##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

namespace Gura {

class Args;
class ExprList;
class ExprOwner;
class Expr_Block;
class Expr_Caller;
class CustomClass;
class CustomFunction;
class Object_dict;
class Callable;
class Iterator;
class IteratorOwner;

//-----------------------------------------------------------------------------
// FunctionType
//-----------------------------------------------------------------------------
enum FunctionType {
	FUNCTYPE_Function,
	FUNCTYPE_Class,
	FUNCTYPE_Instance,
	FUNCTYPE_Block,
};

const char *GetFuncTypeName(FunctionType funcType);

//----------------------------------------------------------------------------
// Function
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Function {
public:
	enum {
		MAP_Off				= (0 << 0),	// 
		MAP_On				= (1 << 0),	// 
		FLAT_Off			= (0 << 1),	// 
		FLAT_On				= (1 << 1),	// 
	};
	enum BlockScope {
		BLKSCOPE_Through,
		BLKSCOPE_Inside,
		BLKSCOPE_SameAsFunc,
	};
	class GURA_DLLDECLARE ResultComposer {
	private:
		Environment &_env;
		Args &_args;
		Value &_result;
		ValueList *_pValList;
		size_t _cnt;
		bool _excludeNilFlag;
		bool _setFlag;
	public:
		ResultComposer(Environment &env, Args &args, Value &result);
		Environment &GetEnv() { return _env; }
		void Store(const Value &value);
	};
	struct BlockInfo {
		OccurPattern occurPattern;
		BlockScope blockScope;
		bool quoteFlag;	// don't create function object from block
		const Symbol *pSymbol;
	};
protected:
	int _cntRef;
	const Symbol *_pSymbol;
	Class *_pClassToConstruct;
	AutoPtr<Environment> _pEnvScope;
	DeclarationOwner _declOwner;
	FunctionType _funcType;
	ResultMode _resultMode;
	ULong _flags;
	SymbolSet _attrsOpt;
	HelpOwner _helpOwner;
	BlockInfo _blockInfo;
public:
	Gura_DeclareReferenceAccessor(Function);
public:
	Function(const Function &func);
	Function(Environment &envScope, const Symbol *pSymbol,
								FunctionType funcType, ULong flags);
	virtual ~Function();
	inline Class *GetClassToConstruct() const { return _pClassToConstruct; }
	inline bool IsSymbolFunc() const { return GetSymbolFuncFlag(); }
	inline bool IsAnonymous() const { return _pSymbol->IsIdentical(Gura_Symbol(_anonymous_)); }
	inline void SetSymbol(const Symbol *pSymbol) { _pSymbol = pSymbol; }
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline OccurPattern GetBlockOccurPattern() const { return _blockInfo.occurPattern; }
	inline BlockScope GetBlockScope() const { return _blockInfo.blockScope; }
	inline bool GetBlockQuoteFlag() const { return _blockInfo.quoteFlag; }
	inline const Symbol *GetSymbolForBlock() const { return _blockInfo.pSymbol; }
	inline const char *GetName() const { return _pSymbol->GetName(); }
	inline Environment &GetEnvScope() { return *_pEnvScope; }
	inline Environment &GetEnvScope() const {
		return *const_cast<Function *>(this)->_pEnvScope;
	}
	virtual bool IsCustom() const;
	virtual bool IsConstructorOfStruct() const;
	virtual Value Call(Environment &env, Signal sig, Args &args) const;
	Value Eval(Environment &env, Signal sig, Args &args) const;
	Value EvalMap(Environment &env, Signal sig, Args &args) const;
	inline FunctionType GetType() const { return _funcType; }
	inline const char *GetTypeName() const { return GetFuncTypeName(_funcType); }
	inline void SetMode(ResultMode resultMode, ULong flags) {
		_resultMode = resultMode, _flags |= flags;
	}
	inline ResultMode GetResultMode() const { return _resultMode; }
	inline ULong GetFlags() const { return _flags; }
	inline const SymbolSet &GetAttrsOpt() const { return _attrsOpt; }
	inline const HelpOwner &GetHelpOwner() const { return _helpOwner; }
	inline const BlockInfo &GetBlockInfo() const { return _blockInfo; }
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
	void SetClassToConstruct(Class *pClassToConstruct);
	bool CustomDeclare(Environment &env, Signal sig,
			const SymbolSet &attrsAcceptable, Args &args);
	void CopyDeclare(const Function &func);
	Declaration *DeclareArg(Environment &env, const Symbol *pSymbol, ValueType valType,
			OccurPattern occurPattern = OCCUR_Once, ULong flags = FLAG_None,
			Expr *pExprDefault = NULL);
	inline Declaration *DeclareArg(Environment &env, const char *name, ValueType valType,
			OccurPattern occurPattern = OCCUR_Once, ULong flags = FLAG_None,
			Expr *pExprDefault = NULL) {
		return DeclareArg(env, Symbol::Add(name), valType, occurPattern, flags, pExprDefault);
	}
	inline void DeclareDictArg(const Symbol *pSymbol) { _declOwner.SetSymbolDict(pSymbol); }
	inline void DeclareDictArg(const char *name) { DeclareDictArg(Symbol::Add(name)); }
	inline void DeclareAttr(const Symbol *pSymbol) { _attrsOpt.Insert(pSymbol); }
	inline DeclarationOwner &GetDeclOwner() { return _declOwner; }
	inline const DeclarationOwner &GetDeclOwner() const { return _declOwner; }
	inline bool IsUnary() const {
		return _declOwner.size() == 1 && !_declOwner.front()->IsVariableLength();
	}
	inline bool IsUnaryable() const { return _declOwner.size() == 1; }
	inline bool IsHelpExist() const { return !_helpOwner.empty(); }
	void DeclareBlock(OccurPattern occurPattern, const Symbol *pSymbol = NULL,
			BlockScope blockScope = BLKSCOPE_Through, bool quoteFlag = false);
	void AddHelp(const Symbol *pSymbol, const String &formatName, const String &text);
	const Help *GetHelp(const Symbol *pSymbol) const;
	String ToString() const;
	void SetError_DivideByZero(Signal sig) const;
	void SetError_UnsupportedAttr(Signal sig, const SymbolSet &attrs) const;
	void SetError_NotConstructor(Signal sig) const;
	void SetError_ArgumentTypeByIndex(Signal sig, Args &args, size_t idxArg) const;
	void SetError_InvalidValue(Signal sig, const Value &value) const;
	void SetError_InvalidValue(Signal sig, const Value &value1, const Value &value2) const;
	void SetError_InvalidValType(Signal sig, const Value &value) const;
	void SetError_InvalidValType(Signal sig, const Value &value1, const Value &value2) const;
	void SetError_InvalidFunctionExpression(Signal sig) const;
	void SetError_MathDiffError(Signal sig) const;
	void SetError_MathOptimizeError(Signal sig) const;
	virtual Expr *DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
			const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
protected:
	Value ReturnValue(Environment &env, Signal sig,
					Args &args, const Value &result) const;
	Value ReturnValues(Environment &env, Signal sig,
					Args &args, const ValueList &valListArg) const;
	Value ReturnIterator(Environment &env, Signal sig,
					Args &args, Iterator *pIterator) const;
	Environment *PrepareEnvironment(Environment &env, Signal sig, Args &args) const;
private:
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const = 0;
};

//-----------------------------------------------------------------------------
// CustomFunction
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CustomFunction : public Function {
private:
	AutoPtr<Expr> _pExprBody;
public:
	CustomFunction(Environment &envScope, const Symbol *pSymbol,
									Expr *pExprBody, FunctionType funcType);
	virtual ~CustomFunction();
	virtual bool IsCustom() const;
	inline const Expr *GetExprBody() const { return _pExprBody.get(); }
	inline void SetExprBody(Expr *pExprBody) { _pExprBody.reset(pExprBody); }
	virtual Expr *DiffUnary(Environment &env, Signal sig,
						const Expr *pExprArg, const Symbol *pSymbol) const;
	static CustomFunction *CreateBlockFunc(Environment &env, Signal sig,
		const Symbol *pSymbol, const Expr_Block *pExprBlock, FunctionType funcType);
private:
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

//-----------------------------------------------------------------------------
// Args
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Args {
private:
	int _cntRef;
	ResultMode _resultMode;
	ULong _flags;
	bool _listThisFlag;
	SymbolSet _attrs;
	SymbolSet _attrsOpt;
	Value _valueThis;
	ValueList _valListArg;
	AutoPtr<ValueDict> _pValDictArg;
	AutoPtr<TrailCtrlHolder> _pTrailCtrlHolder;
	AutoPtr<Iterator> _pIteratorThis;
	AutoPtr<ExprOwner> _pExprOwnerArg;
	AutoPtr<Expr_Block> _pExprBlock;
	AutoPtr<Function> _pFuncBlock;
public:
	Gura_DeclareReferenceAccessor(Args);
public:
	inline Args() : _cntRef(1),
		_resultMode(RSLTMODE_Normal),
		_flags(FLAG_None),
		_listThisFlag(false),
		_pValDictArg(new ValueDict()) {}
	inline Args(const Args &args) : _cntRef(1),
		_resultMode(args._resultMode),
		_flags(args._flags),
		_listThisFlag(args._listThisFlag),
		_attrs(args._attrs),
		_attrsOpt(args._attrsOpt),
		_valueThis(args._valueThis),
		_valListArg(args._valListArg),
		_pValDictArg(ValueDict::Reference(args._pValDictArg.get())),
		_pTrailCtrlHolder(TrailCtrlHolder::Reference(args._pTrailCtrlHolder.get())),
		_pIteratorThis(Iterator::Reference(args._pIteratorThis.get())),
		_pExprOwnerArg(ExprOwner::Reference(args._pExprOwnerArg.get())),
		_pExprBlock(Expr_Block::Reference(args._pExprBlock.get())),
		_pFuncBlock(Function::Reference(args._pFuncBlock.get())) {}
	inline Args(const Args &args, const ValueList &valListArg) : _cntRef(1),
		_resultMode(args._resultMode),
		_flags(args._flags),
		_listThisFlag(args._listThisFlag),
		_attrs(args._attrs),
		_attrsOpt(args._attrsOpt),
		_valueThis(args._valueThis),
		_valListArg(valListArg),
		_pValDictArg(ValueDict::Reference(args._pValDictArg.get())),
		_pTrailCtrlHolder(TrailCtrlHolder::Reference(args._pTrailCtrlHolder.get())),
		_pIteratorThis(Iterator::Reference(args._pIteratorThis.get())),
		_pExprOwnerArg(ExprOwner::Reference(args._pExprOwnerArg.get())),
		_pExprBlock(Expr_Block::Reference(args._pExprBlock.get())),
		_pFuncBlock(Function::Reference(args._pFuncBlock.get())) {}
protected:
	virtual ~Args();
public:
	inline bool IsSet(const Symbol *pSymbol) const { return _attrs.IsSet(pSymbol); }
	inline bool IsAttrEmpty() const { return _attrs.empty(); }
	inline void SetAttrs(const SymbolSet &attrs) { _attrs = attrs; }
	inline void SetAttrsOpt(const SymbolSet &attrsOpt) { _attrsOpt = attrsOpt; }
	inline const SymbolSet &GetAttrs() const { return _attrs; }
	inline const SymbolSet &GetAttrsOpt() const { return _attrsOpt; }
	inline void SetResultMode(ResultMode resultMode) { _resultMode = resultMode; }
	inline ResultMode GetResultMode() const { return _resultMode; }
	inline void SetFlags(ULong flags) { _flags = flags; }
	inline bool GetFlatFlag() const { return (_flags & FLAG_Flat)? true : false; }
	inline void SetThis(const Value &valueThis) { _valueThis = valueThis; }
	inline Value &GetThis() { return _valueThis; }
	inline const Value &GetThis() const { return _valueThis; }
	inline Class *GetThisClass() { return _valueThis.GetClass(); }
	inline const Class *GetThisClass() const { return _valueThis.GetClass(); }
	inline Object *GetThisObj() { return _valueThis.GetObject(); }
	inline const Object *GetThisObj() const { return _valueThis.GetObject(); }
	inline Fundamental *GetThisFundamental() { return _valueThis.GetFundamental(); }
	inline const Fundamental *GetThisFundamental() const { return _valueThis.GetFundamental(); }
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
	inline bool IsRsltFlat() const { return GetFlatFlag(); }
	inline void SetTrailCtrlHolder(TrailCtrlHolder *pTrailCtrlHolder) {
		_pTrailCtrlHolder.reset(pTrailCtrlHolder);
	}
	inline void QuitTrailer() {
		if (!_pTrailCtrlHolder.IsNull()) _pTrailCtrlHolder->Set(TRAILCTRL_Quit);
	}
	inline void FinalizeTrailer() {
		if (!_pTrailCtrlHolder.IsNull()) _pTrailCtrlHolder->Set(TRAILCTRL_Finalize);
	}
	inline void SetExprOwnerArg(ExprOwner *pExprOwnerArg) { _pExprOwnerArg.reset(pExprOwnerArg); }
	inline const ExprList &GetExprListArg() const {
		return (_pExprOwnerArg.IsNull())? ExprList::Null : *_pExprOwnerArg;
	}
	inline ValueList &GetValueListArg() { return _valListArg; }
	inline const ValueList &GetValueListArg() const { return _valListArg; }
	inline size_t CountArgs() const { return _valListArg.size(); }
	inline void ReserveValueListArg(size_t n) { _valListArg.reserve(n); }
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
		return (idxArg < _valListArg.size())? _valListArg[idxArg] : Value::Null;
	}
	inline const Value &GetValue(size_t idxArg) const {
		return (idxArg < _valListArg.size())? _valListArg[idxArg] : Value::Null;
	}
	inline bool IsValid(size_t idxArg) const			{ return GetValue(idxArg).IsValid();	}
	inline bool IsInvalid(size_t idxArg) const			{ return GetValue(idxArg).IsInvalid();	}
	inline bool IsDefined(size_t idxArg) const			{ return GetValue(idxArg).IsDefined();	}
	inline bool IsUndefined(size_t idxArg) const		{ return GetValue(idxArg).IsUndefined();}
	inline bool IsType(size_t idxArg, ValueType valType) const { return GetValue(idxArg).IsType(valType); }
	inline bool IsNumber(size_t idxArg) const			{ return GetValue(idxArg).IsNumber();	}
	inline bool IsBoolean(size_t idxArg) const			{ return GetValue(idxArg).IsBoolean();	}
	inline bool IsSymbol(size_t idxArg) const			{ return GetValue(idxArg).IsSymbol();	}
	inline bool IsString(size_t idxArg) const			{ return GetValue(idxArg).IsString();	}
	inline bool IsBinary(size_t idxArg) const			{ return GetValue(idxArg).IsBinary();	}
	inline bool IsComplex(size_t idxArg) const			{ return GetValue(idxArg).IsComplex();	}
	inline bool IsModule(size_t idxArg) const			{ return GetValue(idxArg).IsModule();	}
	inline bool IsClass(size_t idxArg) const			{ return GetValue(idxArg).IsClass();	}
	inline bool IsGenericObject(size_t idxArg) const	{ return GetValue(idxArg).IsGenericObject(); }
	inline bool IsHelp(size_t idxArg) const				{ return GetValue(idxArg).IsHelp();		}
	inline bool IsFunction(size_t idxArg) const			{ return GetValue(idxArg).IsFunction();	}
	inline bool IsIterator(size_t idxArg) const			{ return GetValue(idxArg).IsIterator();	}
	inline bool IsList(size_t idxArg) const				{ return GetValue(idxArg).IsList();		}
	inline bool IsMatrix(size_t idxArg) const			{ return GetValue(idxArg).IsMatrix();	}
	inline bool IsDict(size_t idxArg) const				{ return GetValue(idxArg).IsDict();		}
	inline bool IsStream(size_t idxArg) const			{ return GetValue(idxArg).IsStream();	}
	inline bool IsDirectory(size_t idxArg) const		{ return GetValue(idxArg).IsDirectory();}
	inline bool IsImage(size_t idxArg) const			{ return GetValue(idxArg).IsImage();	}
	inline bool IsColor(size_t idxArg) const			{ return GetValue(idxArg).IsColor();	}
	inline bool IsPalette(size_t idxArg) const			{ return GetValue(idxArg).IsPalette();	}
	inline bool IsExpr(size_t idxArg) const				{ return GetValue(idxArg).IsExpr();		}
	inline bool IsError(size_t idxArg) const			{ return GetValue(idxArg).IsError();	}
	inline bool IsNumberOrComplex(size_t idxArg) const	{ return GetValue(idxArg).IsNumberOrComplex(); }
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
	inline Class *GetClass(size_t idxArg)				{ return GetValue(idxArg).GetClass();	}
	inline const Class *GetClass(size_t idxArg) const	{ return GetValue(idxArg).GetClass();	}
	inline const ValueList &GetList(size_t idxArg) const{ return GetValue(idxArg).GetList();	}
	inline const ValueDict &GetDict(size_t idxArg) const{ return GetValue(idxArg).GetDict();	}
	inline Iterator *GetIterator(size_t idxArg) const	{ return GetValue(idxArg).GetIterator();}
	inline Stream &GetStream(size_t idxArg)				{ return GetValue(idxArg).GetStream();	}
	inline Stream &GetStream(size_t idxArg) const		{
		return const_cast<Args *>(this)->GetValue(idxArg).GetStream();
	}
	inline Directory *GetDirectory(size_t idxArg)		{ return GetValue(idxArg).GetDirectory();}
	inline Directory *GetDirectory(size_t idxArg) const	{
		return const_cast<Args *>(this)->GetValue(idxArg).GetDirectory();
	}
	inline const Expr *GetExpr(size_t idxArg) const		{ return GetValue(idxArg).GetExpr();	}
	inline Function *GetFunction(size_t idxArg)			{ return GetValue(idxArg).GetFunction(); }
	inline const Function *GetFunction(size_t idxArg) const	{ return GetValue(idxArg).GetFunction(); }
	inline ErrorType GetErrorType(size_t idxArg) const	{ return GetValue(idxArg).GetErrorType(); }
	inline void SetValueListArg(const ValueList &valListArg) { _valListArg = valListArg; }
	inline void SetValueDictArg(ValueDict *pValDictArg) { _pValDictArg.reset(pValDictArg); }
	inline ValueDict &GetValueDictArg() { return *_pValDictArg; }
	inline const ValueDict &GetValueDictArg() const { return *_pValDictArg; }
	bool ShouldGenerateIterator(const DeclarationList &declList) const;
	inline void SetBlock(Expr_Block *pExprBlock) { _pExprBlock.reset(pExprBlock); }
	const Expr_Block *GetBlock(Environment &env, Signal sig) const;
	const Function *GetBlockFunc(Environment &env, Signal sig, const Symbol *pSymbol);
};

//-----------------------------------------------------------------------------
// Callable
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Callable {
public:
	virtual Value DoCall(Environment &env, Signal sig, Args &args) = 0;
	virtual bool IsLeader() const;
	virtual bool IsTrailer() const;
	virtual bool IsFinalizer() const;
	virtual bool IsEndMarker() const;
	virtual OccurPattern GetBlockOccurPattern() const;
};

}

#endif
