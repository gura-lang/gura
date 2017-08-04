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
#define Gura_DeclareFunctionAlias_CustomBegin(funcName, funcNameAlias)	\
class Func_##funcName : public Function { \
public:

#define Gura_DeclareFunctionAlias_CustomEnd(funcName, funcNameAlias)	\
	Func_##funcName(Environment &env, const char *name = funcNameAlias); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
}; \
Func_##funcName::Func_##funcName(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareFunctionAlias(funcName, funcNameAlias) \
Gura_DeclareFunctionAlias_CustomBegin(funcName, funcNameAlias) \
Gura_DeclareFunctionAlias_CustomEnd(funcName, funcNameAlias)

#define Gura_DeclareFunction_CustomBegin(funcName) \
Gura_DeclareFunctionAlias_CustomBegin(funcName, #funcName)

#define Gura_DeclareFunction_CustomEnd(funcName) \
Gura_DeclareFunctionAlias_CustomEnd(funcName, #funcName)

#define Gura_DeclareFunction(funcName) \
Gura_DeclareFunctionAlias(funcName, #funcName)

#define Gura_DeclareStatementAlias_CustomBegin(funcName, funcNameAlias)	\
class Func_##funcName : public Function { \
public: \
	class Expr_Statement : public Expr_Caller { \
	public:

#define Gura_DeclareStatementAlias_CustomEnd(funcName, funcNameAlias) \
		virtual Expr *Clone() const; \
		virtual Value DoExec(Environment &env) const; \
		virtual bool DoPrepare(Environment &env); \
	}; \
public: \
	Func_##funcName(Environment &env, const char *name = funcNameAlias); \
	virtual Expr_Caller *GenerateStatement(Parser *pParser, Expr *pExprCar, \
		Expr_Lister *pExprLister, Expr_Block *pExprBlock, const Expr_Caller *pExprLeader) const; \
}; \
Expr *Func_##funcName::Expr_Statement::Clone() const { \
	return new Expr_Statement(*this); \
} \
Expr_Caller *Func_##funcName::GenerateStatement(Parser *pParser, Expr *pExprCar, \
	Expr_Lister *pExprLister, Expr_Block *pExprBlock, const Expr_Caller *pExprLeader) const { \
	return new Expr_Statement(pExprCar, pExprLister, pExprBlock); \
} \
Func_##funcName::Func_##funcName(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareStatementAlias(funcName, funcNameAlias, flags)	\
Gura_DeclareStatementAlias_CustomBegin(funcName, funcNameAlias)	\
	inline Expr_Statement(Expr *pExprCar, Expr_Lister *pExprLister, Expr_Block *pExprBlock) : \
			Expr_Caller(pExprCar, pExprLister, pExprBlock, flags) {}					\
	inline Expr_Statement(const Expr_Statement &expr) : Expr_Caller(expr) {} \
Gura_DeclareStatementAlias_CustomEnd(funcName, funcNameAlias)

#define Gura_DeclareStatement_CustomBegin(funcName) \
Gura_DeclareStatementAlias_CustomBegin(funcName, #funcName)

#define Gura_DeclareStatement_CustomEnd(funcName) \
Gura_DeclareStatementAlias_CustomEnd(funcName, #funcName)

#define Gura_DeclareStatement(funcName, flags) \
Gura_DeclareStatementAlias(funcName, #funcName, flags)

// DeclareFunctionWithMathDiff
#define Gura_DeclareFunctionWithMathDiffAlias(funcName, funcNameAlias) \
class Func_##funcName : public Function { \
public: \
	Func_##funcName(Environment &env, const char *name = funcNameAlias); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
	virtual Expr *MathDiff(Environment &env, const Expr *pExprArg, const Symbol *pSymbol) const; \
}; \
Func_##funcName::Func_##funcName(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareFunctionWithMathDiff(funcName) \
Gura_DeclareFunctionWithMathDiffAlias(funcName, #funcName)

// DeclareMethod
#define Gura_DeclareMethodAlias(className, funcName, funcNameAlias) \
class Func_##className##__##funcName : public Function { \
public: \
	Func_##className##__##funcName(Environment &env, const char *name = funcNameAlias); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
}; \
Func_##className##__##funcName::Func_##className##__##funcName(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Instance, FLAG_None)

#define Gura_DeclareMethod(className, funcName) Gura_DeclareMethodAlias(className, funcName, #funcName)

// DeclareMethodPrimitive
#define Gura_DeclareMethodPrimitiveAlias(className, funcName, funcNameAlias) \
class Func_##className##__##funcName : public Function { \
public: \
	Func_##className##__##funcName(Environment &env, const char *name = funcNameAlias); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
}; \
Func_##className##__##funcName::Func_##className##__##funcName(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None)

#define Gura_DeclareMethodPrimitive(className, funcName) Gura_DeclareMethodPrimitiveAlias(className, funcName, #funcName)

// DeclareClassMethod
#define Gura_DeclareClassMethodAlias(className, funcName, funcNameAlias) \
class Func_##className##__##funcName : public Function { \
public: \
	Func_##className##__##funcName(Environment &env, const char *name = funcNameAlias); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
}; \
Func_##className##__##funcName::Func_##className##__##funcName(Environment &env, const char *name) : \
					Function(env, Symbol::Add(name), FUNCTYPE_Class, FLAG_None)

#define Gura_DeclareClassMethod(className, funcName) Gura_DeclareClassMethodAlias(className, funcName, #funcName)

#define Gura_ImplementFunction(funcName) \
Value Func_##funcName::DoEval(Environment &env, Argument &arg) const

#define Gura_ImplementMethod(className, funcName) \
Value Func_##className##__##funcName::DoEval(Environment &env, Argument &arg) const

#define Gura_ImplementClassMethod(className, funcName) Gura_ImplementMethod(className, funcName)

#define Gura_ImplementMathDiff(funcName) \
Expr *Func_##funcName::MathDiff(Environment &env, const Expr *pExprArg, const Symbol *pSymbol) const

#define Gura_ImplementStatement(funcName) \
Value Func_##funcName::Expr_Statement::DoExec(Environment &env) const

#define Gura_ImplementStatementPreparator(funcName) \
bool Func_##funcName::Expr_Statement::DoPrepare(Environment &env)

#define Gura_Function(funcName) Func_##funcName

#define Gura_Method(className, funcName) Func_##className##__##funcName

namespace Gura {

class CallerInfo;
class Argument;
class ExprList;
class Expr_Block;
class Expr_Caller;
class CustomClass;
class CustomFunction;
class Object_dict;
class Object_list;
class Callable;
class Iterator;
class IteratorOwner;
class FunctionOwner;

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
class GURA_DLLDECLARE Function : public HelpProvider::Holder {
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
	Class *_pClassContainer;
	AutoPtr<Environment> _pEnvScope;
	FunctionType _funcType;
	AutoPtr<HelpProvider> _pHelpProvider;
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
	inline Environment &GetEnvScope() { return *_pEnvScope; }
	inline Environment &GetEnvScope() const { return *const_cast<Function *>(this)->_pEnvScope; }
	inline DeclarationOwner &GetDeclOwner() { return *_pDeclOwner; }
	inline const DeclarationOwner &GetDeclOwner() const { return *_pDeclOwner; }
	inline void SetType(FunctionType funcType) { _funcType = funcType; }
	inline FunctionType GetType() const { return _funcType; }
	inline const char *GetTypeName() const { return GetFuncTypeName(_funcType); }
	inline HelpProvider &GetHelpProvider() { return *_pHelpProvider; }
	inline const HelpProvider &GetHelpProvider() const { return *_pHelpProvider; }
	inline void AddHelp(const Symbol *pSymbol, const String &doc) {
		_pHelpProvider->AddHelp(pSymbol, doc);
	}
	inline void AddHelpTemplate(Environment &env, const Symbol *pSymbol, const String &doc) {
		_pHelpProvider->AddHelpTemplate(env, pSymbol, doc);
	}
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
	Value Eval(Environment &env, Argument &arg) const;
	Value EvalAuto(Environment &env, Argument &arg) const;
	void SetFuncAttr(ValueType valTypeResult, ResultMode resultMode, ULong flags);
	void SetClassToConstruct(Class *pClassToConstruct);
	Class *GetClassToConstruct() const;
	void SetClassContainer(Class *pClassContainer) { _pClassContainer = pClassContainer; }
	Class *GetClassContainer() const { return _pClassContainer; }
	bool CustomDeclare(Environment &env,
					   const CallerInfo &callerInfo, const SymbolSet &attrsAcceptable);
	void CopyDeclarationInfo(const Function &func);
	Declaration *DeclareArg(
		Environment &env, const Symbol *pSymbol, ValueType valType,
		OccurPattern occurPattern = OCCUR_Once, ULong flags = FLAG_None,
		size_t nListElems = 0, Expr *pExprDefault = nullptr);
	inline Declaration *DeclareArg(
		Environment &env, const char *name, ValueType valType,
		OccurPattern occurPattern = OCCUR_Once, ULong flags = FLAG_None,
		size_t nListElems = 0, Expr *pExprDefault = nullptr) {
		return DeclareArg(env, Symbol::Add(name), valType,
						  occurPattern, flags, nListElems, pExprDefault);
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
	void DeclareBlock(OccurPattern occurPattern, const Symbol *pSymbol = nullptr,
					  bool quoteFlag = false, BlockScope blockScope = BLKSCOPE_Through);
	bool LinkHelp(const Environment *pEnv, const Symbol *pSymbol);
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
	virtual Expr_Caller *GenerateStatement(
		Parser *pParser, Expr *pExprCar, Expr_Lister *pExprLister,
		Expr_Block *pExprBlock, const Expr_Caller *pExprLeader) const;
	virtual Expr *MathDiff(Environment &env,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *MathOptimize(Environment &env, Expr *pExprOpt) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
public:
	Value ReturnValue(Environment &env, Argument &arg, const Value &result) const;
	Value ReturnValues(Environment &env, Argument &arg, const ValueList &valListArg) const;
	Value ReturnIterator(Environment &env, Argument &arg, Iterator *pIterator) const;
	Environment *PrepareEnvironment(Environment &env, Argument &arg, bool thisAssignFlag) const;
private:
	virtual Value DoEval(Environment &env, Argument &arg) const;
public:
	// inherited from HelpProvider
	virtual String MakeHelpTitle() const;
};

//-----------------------------------------------------------------------------
// FunctionList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE FunctionList : public std::vector<Function *, Allocator<Function *> > {
public:
	static const FunctionList Empty;
public:
	inline FunctionList() {}
	~FunctionList();
};

//-----------------------------------------------------------------------------
// FunctionOwner
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE FunctionOwner : public FunctionList {
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(FunctionOwner)
public:
	inline FunctionOwner() : _cntRef(1) {}
private:
	inline FunctionOwner(const FunctionOwner &declOwner) {}
	inline void operator=(const FunctionOwner &declOwner) {}
private:
	~FunctionOwner();
public:
	void Clear();
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
	Object_list *_pObjList;
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
			_pObjList = _valueResult.InitAsList(env);
		}
	}
};

}

#endif
