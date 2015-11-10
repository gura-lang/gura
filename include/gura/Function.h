//=============================================================================
// Function
//=============================================================================
#ifndef __GURA_FUNCTION_H__
#define __GURA_FUNCTION_H__

#include "Common.h"
#include "Declaration.h"
#include "Environment.h"
#include "Parser.h"
#include "Help.h"

// DeclareFunction
#define Gura_DeclareFunctionBegin(name) \
class Func_##name : public Function {

#define Gura_DeclareFunctionEnd(name) \
public: \
	Func_##name(Environment &env, const char *name = #name); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
}; \
Func_##name::Func_##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareFunctionAlias(name, nameAlias) \
class Func_##name : public Function { \
public: \
	Func_##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
}; \
Func_##name::Func_##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareFunction(name) Gura_DeclareFunctionAlias(name, #name)

#define Gura_DeclareFastFunctionAlias(name, nameAlias) \
class Func_##name : public Function { \
public: \
	class ExprEx : public Expr_Caller { \
	public: \
		inline ExprEx(Expr *pExprCar, Expr_Lister *pExprLister, Expr_Block *pExprBlock) : \
			Expr_Caller(pExprCar, pExprLister, pExprBlock) {} \
		virtual Value DoExec(Environment &env) const; \
	}; \
public: \
	Func_##name(Environment &env, const char *name = nameAlias); \
	virtual Expr_Caller *GenerateSpecificExpr(Parser *pParser, Expr *pExprCar, \
		Expr_Lister *pExprLister, Expr_Block *pExprBlock, const Expr_Caller *pExprLeader) const; \
}; \
Func_##name::Func_##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareFastFunction(name) Gura_DeclareFastFunctionAlias(name, #name)

// DeclareFunctionWithMathDiff
#define Gura_DeclareFunctionWithMathDiffAlias(name, nameAlias) \
class Func_##name : public Function { \
public: \
	Func_##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
	virtual Expr *MathDiff(Environment &env, const Expr *pExprArg, const Symbol *pSymbol) const; \
}; \
Func_##name::Func_##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareFunctionWithMathDiff(name) \
Gura_DeclareFunctionWithMathDiffAlias(name, #name)

#if 0
// DeclareFunctionTrailer
#define Gura_DeclareFunctionTrailerAlias(name, nameAlias) \
class Func_##name : public Function { \
public: \
	Func_##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
}; \
Func_##name::Func_##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareFunctionTrailer(name) \
Gura_DeclareFunctionTrailerAlias(name, #name)
#endif

// DeclareMethod
#define Gura_DeclareMethodAlias(className, name, nameAlias) \
class Func_##className##__##name : public Function { \
public: \
	Func_##className##__##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
}; \
Func_##className##__##name::Func_##className##__##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Instance, FLAG_None)

#define Gura_DeclareMethod(className, name) Gura_DeclareMethodAlias(className, name, #name)

// DeclareMethodPrimitive
#define Gura_DeclareMethodPrimitiveAlias(className, name, nameAlias) \
class Func_##className##__##name : public Function { \
public: \
	Func_##className##__##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
}; \
Func_##className##__##name::Func_##className##__##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareMethodPrimitive(className, name) Gura_DeclareMethodPrimitiveAlias(className, name, #name)

// DeclareClassMethod
#define Gura_DeclareClassMethodAlias(className, name, nameAlias) \
class Func_##className##__##name : public Function { \
public: \
	Func_##className##__##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
}; \
Func_##className##__##name::Func_##className##__##name(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Class, FLAG_None)

#define Gura_DeclareClassMethod(className, name) Gura_DeclareClassMethodAlias(className, name, #name)

#define Gura_ImplementFunction(name) \
Value Func_##name::DoEval(Environment &env, Argument &arg) const

#define Gura_ImplementMethod(className, name) \
Value Func_##className##__##name::DoEval(Environment &env, Argument &arg) const

#define Gura_ImplementClassMethod(className, name) \
Value Func_##className##__##name::DoEval(Environment &env, Argument &arg) const

#define Gura_ImplementMathDiff(name) \
Expr *Func_##name::MathDiff(Environment &env, const Expr *pExprArg, const Symbol *pSymbol) const

#define Gura_ImplementFastFunction(name) \
Value Func_##name::ExprEx::DoExec(Environment &env) const

#define Gura_ImplementFastFunctionGenerator(name) \
Expr_Caller *Func_##name::GenerateSpecificExpr(Parser *pParser, Expr *pExprCar, \
	   Expr_Lister *pExprLister, Expr_Block *pExprBlock, const Expr_Caller *pExprLeader) const

#define Gura_Function(name) Func_##name

#define Gura_Method(className, name) Func_##className##__##name

namespace Gura {

class CallerInfo;
class Argument;
class ExprList;
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
	enum BlockScope {
		BLKSCOPE_Through,
		BLKSCOPE_Inside,
		BLKSCOPE_SameAsFunc,
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
	AutoPtr<Function> _pFuncHelpLink;
	FunctionType _funcType;
	HelpOwner _helpOwner;
protected:
	// declaration information
	AutoPtr<DeclarationOwner> _pDeclOwner;
	ValueType _valTypeResult;
	ResultMode _resultMode;
	ULong _flags;
	AutoPtr<SymbolSetShared> _pAttrsOptShared;
	BlockInfo _blockInfo;
	const Symbol *_pSymbolDict;
public:
	Gura_DeclareReferenceAccessor(Function);
public:
	inline static void *operator new(size_t size) {
		return MemoryPool::Allocate(size, "Function");
	}
	inline static void operator delete(void *pv) {
		MemoryPool::Deallocate(pv);
	}
public:
	Function(const Function &func);
	Function(Environment &envScope, const Symbol *pSymbol, FunctionType funcType, ULong flags);
	virtual ~Function();
public:
	inline void SetSymbol(const Symbol *pSymbol) { _pSymbol = pSymbol; }
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline const char *GetName() const { return _pSymbol->GetName(); }
	inline bool IsAnonymous() const { return _pSymbol->IsIdentical(Gura_Symbol(_anonymous_)); }
	inline Class *GetClassToConstruct() const { return _pClassToConstruct; }
	inline Environment &GetEnvScope() { return *_pEnvScope; }
	inline Environment &GetEnvScope() const { return *const_cast<Function *>(this)->_pEnvScope; }
	inline DeclarationOwner &GetDeclOwner() { return *_pDeclOwner; }
	inline const DeclarationOwner &GetDeclOwner() const { return *_pDeclOwner; }
	inline FunctionType GetType() const { return _funcType; }
	inline const char *GetTypeName() const { return GetFuncTypeName(_funcType); }
	inline ValueType GetValueTypeResult() const { return _valTypeResult; }
	inline ResultMode GetResultMode() const { return _resultMode; }
	inline bool IsResultNormal() const { return _resultMode == RSLTMODE_Normal; }
	inline bool IsResultIterator() const { return _resultMode == RSLTMODE_Iterator; }
	inline bool IsResultList() const { return _resultMode == RSLTMODE_List; }
	inline bool IsResultReduce() const { return _resultMode == RSLTMODE_Reduce; }
	inline bool IsResultSet() const { return _resultMode == RSLTMODE_Set; }
	inline bool IsResultVoid() const { return _resultMode == RSLTMODE_Void; }
	inline bool IsResultXIterator() const { return _resultMode == RSLTMODE_XIterator; }
	inline bool IsResultXList() const { return _resultMode == RSLTMODE_XList; }
	inline bool IsResultXReduce() const { return _resultMode == RSLTMODE_XReduce; }
	inline bool IsResultXSet() const { return _resultMode == RSLTMODE_XSet; }
	inline ULong GetFlags() const { return _flags; }
	inline void SetFlag(ULong flag) { _flags |= flag; }
	inline bool GetFlag(ULong flag) const { return (_flags & flag) != 0; }
	inline const SymbolSet &GetAttrsOpt() const {
		return _pAttrsOptShared.IsNull()? SymbolSet::Empty : _pAttrsOptShared->GetSymbolSet();
	}
	inline const SymbolSetShared *GetAttrsOptShared() const {
		return _pAttrsOptShared.get();
	}
	inline const HelpOwner &GetHelpOwner() const { return _helpOwner; }
	inline const BlockInfo &GetBlockInfo() const { return _blockInfo; }
	inline OccurPattern GetBlockOccurPattern() const { return _blockInfo.occurPattern; }
	inline BlockScope GetBlockScope() const { return _blockInfo.blockScope; }
	inline bool GetBlockQuoteFlag() const { return _blockInfo.quoteFlag; }
	inline const Symbol *GetSymbolForBlock() const { return _blockInfo.pSymbol; }
	inline void SetSymbolDict(const Symbol *pSymbolDict) { _pSymbolDict = pSymbolDict; }
	inline const Symbol *GetSymbolDict() const { return _pSymbolDict; }
public:
	virtual bool IsCustom() const;
	virtual bool IsConstructorOfStruct() const;
	inline Value Eval(Environment &env, Argument &arg) const {
		Value value = DoEval(env, arg);
		return arg.IsResultVoid()? Value::Undefined : value;
	}
	Value EvalAuto(Environment &env, Argument &arg) const;
	void SetFuncAttr(ValueType valTypeResult, ResultMode resultMode, ULong flags);
	void SetClassToConstruct(Class *pClassToConstruct);
	bool CustomDeclare(Environment &env,
					   const CallerInfo &callerInfo, const SymbolSet &attrsAcceptable);
	void CopyDeclarationInfo(const Function &func);
	Declaration *DeclareArg(Environment &env, const Symbol *pSymbol, ValueType valType,
			OccurPattern occurPattern = OCCUR_Once, ULong flags = FLAG_None,
			Expr *pExprDefault = nullptr);
	inline Declaration *DeclareArg(Environment &env, const char *name, ValueType valType,
			OccurPattern occurPattern = OCCUR_Once, ULong flags = FLAG_None,
			Expr *pExprDefault = nullptr) {
		return DeclareArg(env, Symbol::Add(name), valType, occurPattern, flags, pExprDefault);
	}
	inline void DeclareDictArg(const Symbol *pSymbolDict) { _pSymbolDict = pSymbolDict; }
	inline void DeclareDictArg(const char *name) { DeclareDictArg(Symbol::Add(name)); }
	inline void DeclareAttr(const Symbol *pSymbol) {
		// Use this function only in a constructor of a derived class from Function.
		if (_pAttrsOptShared.IsNull()) _pAttrsOptShared.reset(new SymbolSetShared());
		_pAttrsOptShared->GetSymbolSet().Insert(pSymbol);
	}
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
	void SetError_ArgumentTypeByIndex(Environment &env, Argument &arg, size_t idxArg) const;
	void SetError_InvalidValue(Signal &sig, const Value &value) const;
	void SetError_InvalidValue(Signal &sig, const Value &value1, const Value &value2) const;
	void SetError_InvalidValType(Signal &sig, const Value &value) const;
	void SetError_InvalidValType(Signal &sig, const Value &value1, const Value &value2) const;
	void SetError_InvalidFunctionExpression(Signal &sig) const;
	void SetError_MathDiffError(Signal &sig) const;
	void SetError_MathOptimizeError(Signal &sig) const;
	virtual Expr_Caller *GenerateSpecificExpr(
		Parser *pParser, Expr *pExprCar, Expr_Lister *pExprLister,
		Expr_Block *pExprBlock, const Expr_Caller *pExprLeader) const;
	virtual Expr *MathDiff(Environment &env,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *MathOptimize(Environment &env, Expr *pExprOpt) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
protected:
	Value ReturnValue(Environment &env, Argument &arg, const Value &result) const;
	Value ReturnValues(Environment &env, Argument &arg, const ValueList &valListArg) const;
	Value ReturnIterator(Environment &env, Argument &arg, Iterator *pIterator) const;
	Environment *PrepareEnvironment(Environment &env, Argument &arg, bool thisAssignFlag) const;
private:
	virtual Value DoEval(Environment &env, Argument &arg) const;
};

//----------------------------------------------------------------------------
// ResultComposer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ResultComposer {
private:
	ValueType _valTypeResult;
	ResultMode _resultMode;
	ULong _flags;
	Value _valueResult;
	ValueList *_pValList;
	size_t _cntAdded;
public:
	ResultComposer(Environment &env, ValueType valTypeResult,
				   ResultMode resultMode, ULong flags);
	ResultComposer(Environment &env, const Function *pFunc);
	ResultComposer(Environment &env, Argument &arg);
	bool StoreValue(Environment &env, const Value &value);
	bool StoreValues(Environment &env, Iterator *pIterator);
	inline bool GetFlag(ULong flag) const { return (_flags & flag) != 0; }
	inline const Value &GetValueResult() const { return _valueResult; }
	inline size_t CountAdded() const { return _cntAdded; }
private:
	inline void Initialize(Environment &env) {
		if (_resultMode == RSLTMODE_List || _resultMode == RSLTMODE_XList ||
			_resultMode == RSLTMODE_Set || _resultMode == RSLTMODE_XSet) {
			_pValList = &_valueResult.InitAsList(env);
		}
	}
};

}

#endif
