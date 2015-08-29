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
		Argument &_arg;
		Value &_result;
		ValueList *_pValList;
		size_t _cnt;
		bool _excludeNilFlag;
		bool _setFlag;
	public:
		ResultComposer(Environment &env, Argument &arg, Value &result);
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
	AutoPtr<SymbolSetShared> _pAttrsOptShared;
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
	Value Call(
		Environment &env, const CallerInfo &callerInfo,
		const Value &valueThis, const Iterator *pIteratorThis, bool listThisFlag,
		const TrailCtrlHolder *pTrailCtrlHolder) const;
	Value Eval(Environment &env, Argument &arg) const;
	Value EvalMap(Environment &env, Argument &arg) const;
	inline FunctionType GetType() const { return _funcType; }
	inline const char *GetTypeName() const { return GetFuncTypeName(_funcType); }
	inline ValueType GetValueTypeResult() const { return _valTypeResult; }
	inline ResultMode GetResultMode() const { return _resultMode; }
	inline ULong GetFlags() const { return _flags; }
	inline const SymbolSet &GetAttrsOpt() const {
		return _pAttrsOptShared.IsNull()? SymbolSet::Empty : _pAttrsOptShared->GetSymbolSet();
	}
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
	inline bool GetNoNamedFlag() const { return (_flags & FLAG_NoNamed)? true : false; }
	void SetFuncAttr(ValueType valTypeResult, ResultMode resultMode, ULong flags);
	void SetClassToConstruct(Class *pClassToConstruct);
	bool CustomDeclare(Environment &env,
					   const CallerInfo &callerInfo, const SymbolSet &attrsAcceptable);
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
	inline void DeclareAttr(const Symbol *pSymbol) {
		// Use this function only in a constructor of a derived class from Function.
		if (_pAttrsOptShared.IsNull()) _pAttrsOptShared.reset(new SymbolSetShared());
		_pAttrsOptShared->GetSymbolSet().Insert(pSymbol);
	}
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
	void SetError_ArgumentTypeByIndex(Signal &sig, Argument &arg, size_t idxArg) const;
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
	Value ReturnValue(Environment &env, Argument &arg, const Value &result) const;
	Value ReturnValues(Environment &env, Argument &arg, const ValueList &valListArg) const;
	Value ReturnIterator(Environment &env, Argument &arg, Iterator *pIterator) const;
	Environment *PrepareEnvironment(Environment &env, Argument &arg, bool thisAssignFlag) const;
private:
	virtual Value DoEval(Environment &env, Argument &arg) const = 0;
};

}

#endif
