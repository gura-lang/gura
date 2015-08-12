//=============================================================================
// Function
//=============================================================================
#ifndef __GURA_FUNCTION_H__
#define __GURA_FUNCTION_H__

#include "Common.h"
#include "Declaration.h"
#include "Environment.h"
#include "Parser.h"
#include "Iterator.h"
#include "Help.h"

// DeclareFunction
#define Gura_DeclareFunctionBegin(name) \
class Func_##name : public Function {

#define Gura_DeclareFunctionEnd(name) \
public: \
	Func_##name(Environment &env, const char *name = #name); \
	virtual Value DoEval(Environment &env, Args &args) const; \
}; \
Func_##name::Func_##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareFunctionAlias(name, nameAlias) \
class Func_##name : public Function { \
public: \
	Func_##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Args &args) const; \
}; \
Func_##name::Func_##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareFunction(name) Gura_DeclareFunctionAlias(name, #name)

// DeclareFunctionWithMathDiff
#define Gura_DeclareFunctionWithMathDiffAlias(name, nameAlias) \
class Func_##name : public Function { \
public: \
	Func_##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Args &args) const; \
	virtual Expr *MathDiff(Environment &env, const Expr *pExprArg, const Symbol *pSymbol) const; \
}; \
Func_##name::Func_##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareFunctionWithMathDiff(name) \
Gura_DeclareFunctionWithMathDiffAlias(name, #name)

// DeclareFunctionTrailer
#define Gura_DeclareFunctionTrailerAlias(name, nameAlias) \
class Func_##name : public Function { \
public: \
	Func_##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Args &args) const; \
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
	virtual Value DoEval(Environment &env, Args &args) const; \
}; \
Func_##className##__##name::Func_##className##__##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Instance, FLAG_None)

#define Gura_DeclareMethod(className, name) Gura_DeclareMethodAlias(className, name, #name)

// DeclareMethodPrimitive
#define Gura_DeclareMethodPrimitiveAlias(className, name, nameAlias) \
class Func_##className##__##name : public Function { \
public: \
	Func_##className##__##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Args &args) const; \
}; \
Func_##className##__##name::Func_##className##__##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareMethodPrimitive(className, name) Gura_DeclareMethodPrimitiveAlias(className, name, #name)

// DeclareClassMethod
#define Gura_DeclareClassMethodAlias(className, name, nameAlias) \
class Func_##className##__##name : public Function { \
public: \
	Func_##className##__##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Args &args) const; \
}; \
Func_##className##__##name::Func_##className##__##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Class, FLAG_None)

#define Gura_DeclareClassMethod(className, name) Gura_DeclareClassMethodAlias(className, name, #name)

#define Gura_ImplementFunction(name) \
Value Func_##name::DoEval(Environment &env, Args &args) const

#define Gura_ImplementMethod(className, name) \
Value Func_##className##__##name::DoEval(Environment &env, Args &args) const

#define Gura_ImplementClassMethod(className, name) \
Value Func_##className##__##name::DoEval(Environment &env, Args &args) const

#define Gura_ImplementMathDiff(name) \
Expr *Func_##name::MathDiff(Environment &env, const Expr *pExprArg, const Symbol *pSymbol) const

#define Gura_Function(name) Func_##name

#define Gura_Method(className, name) Func_##className##__##name

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
		MAP_Off				= (0 << 0),
		MAP_On				= (1 << 0),
		FLAT_Off			= (0 << 1),
		FLAT_On				= (1 << 1),
	};
	enum BlockScope {
		BLKSCOPE_Through,
		BLKSCOPE_Inside,
		BLKSCOPE_SameAsFunc,
	};
	class GURA_DLLDECLARE ResultComposer {
	private:
		Args &_args;
		Value &_result;
		ValueList *_pValList;
		size_t _cnt;
		bool _excludeNilFlag;
		bool _setFlag;
	public:
		ResultComposer(Environment &env, Args &args, Value &result);
		bool Store(Environment &env, const Value &value);
	};
	class GURA_DLLDECLARE ExprMap : public std::map<const Symbol *, Expr *, Symbol::KeyCompare_UniqNumber> {
	public:
		~ExprMap();
	};
	struct BlockInfo {
		OccurPattern occurPattern;
		BlockScope blockScope;
		bool quoteFlag;	// don't create function object from block
		const Symbol *pSymbol;
	};
	class GURA_DLLDECLARE SequenceEx : public Sequence {
	private:
		enum Stat {
			STAT_Init, STAT_ExprArgs, STAT_OptArgs, STAT_NamedArgs, STAT_Exec,
		};
	private:
		Stat _stat;
		AutoPtr<Function> _pFunc;
		AutoPtr<Args> _pArgs;
		ExprMap _exprMap;
		ExprMap::iterator _iterExprMap;
		DeclarationList::const_iterator _ppDecl;
		ExprList::const_iterator _ppExprArg;
		bool _stayDeclPointerFlag;
		bool _mapFlag;
	public:
		SequenceEx(Environment *pEnv, Function *pFunc, Args &args);
	public:
		inline Args *GetArgs() { return _pArgs.get(); }
		inline ExprMap &GetExprMap() { return _exprMap; }
		virtual bool DoStep(Signal &sig, Value &result);
		virtual String ToString() const;
		void SkipDeclarations(size_t nSkipDecl);
	};
	class GURA_DLLDECLARE SeqPostHandler_StoreDict : public SeqPostHandler {
	private:
		AutoPtr<SequenceEx> _pSequenceCall;
		Value _valueKey;
	public:
		inline SeqPostHandler_StoreDict(Environment *pEnv, SequenceEx *pSequenceCall, const Value &valueKey) :
				SeqPostHandler(pEnv), _pSequenceCall(pSequenceCall), _valueKey(valueKey) {}
		virtual bool DoPost(Signal &sig, const Value &result);
	};
	class GURA_DLLDECLARE SeqPostHandler_ExpandMod : public SeqPostHandler {
	private:
		AutoPtr<SequenceEx> _pSequenceCall;
	public:
		inline SeqPostHandler_ExpandMod(Environment *pEnv, SequenceEx *pSequenceCall) :
				SeqPostHandler(pEnv), _pSequenceCall(pSequenceCall) {}
		virtual bool DoPost(Signal &sig, const Value &result);
	};
	class GURA_DLLDECLARE SeqPostHandler_ExpandMul : public SeqPostHandler {
	private:
		AutoPtr<SequenceEx> _pSequenceCall;
	public:
		inline SeqPostHandler_ExpandMul(Environment *pEnv, SequenceEx *pSequenceCall) :
				SeqPostHandler(pEnv), _pSequenceCall(pSequenceCall) {}
		virtual bool DoPost(Signal &sig, const Value &result);
	};
	class GURA_DLLDECLARE SeqPostHandler_ValListArg : public SeqPostHandler {
	private:
		AutoPtr<SequenceEx> _pSequenceCall;
		bool _skipDeclFlag;
	public:
		inline SeqPostHandler_ValListArg(Environment *pEnv, SequenceEx *pSequenceCall, bool skipDeclFlag) :
				SeqPostHandler(pEnv), _pSequenceCall(pSequenceCall), _skipDeclFlag(skipDeclFlag) {}
		virtual bool DoPost(Signal &sig, const Value &result);
	};
	class GURA_DLLDECLARE SeqPostHandler_ValDictArg : public SeqPostHandler {
	private:
		AutoPtr<SequenceEx> _pSequenceCall;
		const Symbol *_pSymbol;
	public:
		inline SeqPostHandler_ValDictArg(Environment *pEnv, SequenceEx *pSequenceCall, const Symbol *pSymbol) :
				SeqPostHandler(pEnv), _pSequenceCall(pSequenceCall), _pSymbol(pSymbol) {}
		virtual bool DoPost(Signal &sig, const Value &result);
	};
protected:
	int _cntRef;
	const Symbol *_pSymbol;
	Class *_pClassToConstruct;
	AutoPtr<Environment> _pEnvScope;
	AutoPtr<DeclarationOwner> _pDeclOwner;
	AutoPtr<Function> _pFuncHelpLink;
	FunctionType _funcType;
	ValueType _valTypeResult;
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
	virtual Value Call(
		Environment &env, const ExprList &exprListArg, const Expr_Block *pExprBlock,
		const SymbolSet &attrs, const SymbolSet &attrsOpt,
		const Value &valueThis, Iterator *pIteratorThis, bool listThisFlag,
		TrailCtrlHolder *pTrailCtrlHolder) const;
	Value Eval(Environment &env, Args &args) const;
	Value EvalMap(Environment &env, Args &args) const;
	inline FunctionType GetType() const { return _funcType; }
	inline const char *GetTypeName() const { return GetFuncTypeName(_funcType); }
	inline ValueType GetValueTypeResult() const { return _valTypeResult; }
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
	void SetFuncAttr(ValueType valTypeResult, ResultMode resultMode, ULong flags);
	void SetClassToConstruct(Class *pClassToConstruct);
	//bool CustomDeclare(Environment &env, const SymbolSet &attrsAcceptable, Args &args);
	bool CustomDeclare(
		Environment &env, const ExprList &exprListArg, const Expr_Block *pExprBlock,
		const SymbolSet &attrs, const SymbolSet &attrsOpt, const SymbolSet &attrsAcceptable);
	void CopyDeclare(const Function &func);
	Declaration *DeclareArg(Environment &env, const Symbol *pSymbol, ValueType valType,
			OccurPattern occurPattern = OCCUR_Once, ULong flags = FLAG_None,
			Expr *pExprDefault = nullptr);
	inline Declaration *DeclareArg(Environment &env, const char *name, ValueType valType,
			OccurPattern occurPattern = OCCUR_Once, ULong flags = FLAG_None,
			Expr *pExprDefault = nullptr) {
		return DeclareArg(env, Symbol::Add(name), valType, occurPattern, flags, pExprDefault);
	}
	inline void DeclareDictArg(const Symbol *pSymbol) { GetDeclOwner().SetSymbolDict(pSymbol); }
	inline void DeclareDictArg(const char *name) { DeclareDictArg(Symbol::Add(name)); }
	inline void DeclareAttr(const Symbol *pSymbol) { _attrsOpt.Insert(pSymbol); }
	inline DeclarationOwner &GetDeclOwner() { return *_pDeclOwner; }
	inline const DeclarationOwner &GetDeclOwner() const { return *_pDeclOwner; }
	inline bool IsUnary() const {
		return GetDeclOwner().size() == 1 && !GetDeclOwner().front()->IsVariableLength();
	}
	inline bool IsUnaryable() const { return GetDeclOwner().size() == 1; }
	inline bool IsHelpExist() const { return !_helpOwner.empty(); }
	void DeclareBlock(OccurPattern occurPattern, const Symbol *pSymbol = nullptr,
			BlockScope blockScope = BLKSCOPE_Through, bool quoteFlag = false);
	void AddHelp(Help *pHelp);
	void AddHelp(const Symbol *pSymbol, const String &formatName, const String &text);
	void LinkHelp(const Function *pFunc);
	bool LinkHelp(const Environment *pEnv, const Symbol *pSymbol);
	const Help *GetHelp(const Symbol *pSymbol, bool defaultFirstFlag) const;
	String MakeFullName() const;
	String ToString() const;
	void SetError_DivideByZero(Signal &sig) const;
	void SetError_UnsupportedAttr(Signal &sig, const SymbolSet &attrs) const;
	void SetError_NotConstructor(Signal &sig) const;
	void SetError_ArgumentTypeByIndex(Signal &sig, Args &args, size_t idxArg) const;
	void SetError_InvalidValue(Signal &sig, const Value &value) const;
	void SetError_InvalidValue(Signal &sig, const Value &value1, const Value &value2) const;
	void SetError_InvalidValType(Signal &sig, const Value &value) const;
	void SetError_InvalidValType(Signal &sig, const Value &value1, const Value &value2) const;
	void SetError_InvalidFunctionExpression(Signal &sig) const;
	void SetError_MathDiffError(Signal &sig) const;
	void SetError_MathOptimizeError(Signal &sig) const;
	virtual Expr *MathDiff(Environment &env,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *MathOptimize(Environment &env, Expr *pExprOpt) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
protected:
	Value ReturnValue(Environment &env, Args &args, const Value &result) const;
	Value ReturnValues(Environment &env, Args &args, const ValueList &valListArg) const;
	Value ReturnIterator(Environment &env, Args &args, Iterator *pIterator) const;
	Environment *PrepareEnvironment(Environment &env, Args &args, bool thisAssignFlag) const;
private:
	virtual Value DoEval(Environment &env, Args &args) const = 0;
};

//-----------------------------------------------------------------------------
// Args
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Args {
private:
	int _cntRef;
	ValueType _valTypeResult;
	ResultMode _resultMode;
	ULong _flags;
	bool _listThisFlag;
	SymbolSet _attrs;
	SymbolSet _attrsOpt;
	Value _valueThis;
	ValueList _valListArg;
	AutoPtr<ValueDict> _pValDictArg;
	AutoPtr<ValueMap> _pValMapHiddenArg;
	AutoPtr<TrailCtrlHolder> _pTrailCtrlHolder;
	AutoPtr<Iterator> _pIteratorThis;
	AutoPtr<Expr_Block> _pExprBlock;
	AutoPtr<Function> _pFuncBlock;
public:
	Gura_DeclareReferenceAccessor(Args);
public:
	inline Args() : _cntRef(1),
		_valTypeResult(VTYPE_any),
		_resultMode(RSLTMODE_Normal),
		_flags(FLAG_None),
		_listThisFlag(false),
		_pValDictArg(new ValueDict()) {}
	inline Args(const Args &args) : _cntRef(1),
		_valTypeResult(args._valTypeResult),
		_resultMode(args._resultMode),
		_flags(args._flags),
		_listThisFlag(args._listThisFlag),
		_attrs(args._attrs),
		_attrsOpt(args._attrsOpt),
		_valueThis(args._valueThis),
		_valListArg(args._valListArg),
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
		_attrs(args._attrs),
		_attrsOpt(args._attrsOpt),
		_valueThis(args._valueThis),
		_valListArg(valListArg),
		_pValDictArg(ValueDict::Reference(args._pValDictArg.get())),
		_pValMapHiddenArg(ValueMap::Reference(args._pValMapHiddenArg.get())),
		_pTrailCtrlHolder(TrailCtrlHolder::Reference(args._pTrailCtrlHolder.get())),
		_pIteratorThis(Iterator::Reference(args._pIteratorThis.get())),
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
	inline void SetValueTypeResult(ValueType valTypeResult) { _valTypeResult = valTypeResult; }
	inline ValueType GetValueTypeResult() const { return _valTypeResult; }
	inline void SetResultMode(ResultMode resultMode) { _resultMode = resultMode; }
	inline ResultMode GetResultMode() const { return _resultMode; }
	inline void SetFlags(ULong flags) { _flags = flags; }
	inline bool GetFlatFlag() const { return (_flags & FLAG_Flat)? true : false; }
	inline void SetThis(const Value &valueThis) { _valueThis = valueThis; }
	inline Value &GetThis() { return _valueThis; }
	inline const Value &GetThis() const { return _valueThis; }
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
	inline ValueDict &GetValueDictArg() { return *_pValDictArg; }
	inline const ValueDict &GetValueDictArg() const { return *_pValDictArg; }
	inline void SetValueMapHiddenArg(ValueMap *pValMapHiddenArg) { _pValMapHiddenArg.reset(pValMapHiddenArg); }
	inline ValueMap *GetValueMapHiddenArg() { return _pValMapHiddenArg.get(); }
	bool ShouldGenerateIterator(const DeclarationList &declList) const;
	inline void SetBlock(Expr_Block *pExprBlock) { _pExprBlock.reset(pExprBlock); }
	const Expr_Block *GetBlock(Environment &env) const;
	const Function *GetBlockFunc(Environment &env, const Symbol *pSymbol);
};

//-----------------------------------------------------------------------------
// Callable
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Callable {
public:
	//virtual Value DoCall(Environment &env, Args &args) = 0;
	virtual Value DoCall(
		Environment &env, const ExprList &exprListArg, const Expr_Block *pExprBlock,
		const SymbolSet &attrs, const SymbolSet &attrsOpt,
		const Value &valueThis, Iterator *pIteratorThis, bool listThisFlag,
		TrailCtrlHolder *pTrailCtrlHolder) = 0;
	virtual bool IsLeader() const;
	virtual bool IsTrailer() const;
	virtual bool IsFinalizer() const;
	virtual bool IsEndMarker() const;
	virtual OccurPattern GetBlockOccurPattern() const;
};

}

#endif
