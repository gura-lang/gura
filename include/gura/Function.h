#ifndef __GURA_FUNCTION_H__
#define __GURA_FUNCTION_H__

#include "Common.h"
#include "Declaration.h"
#include "Environment.h"
#include "Parser.h"
#include "Iterator.h"

// DeclareFunction
#define Gura_DeclareFunctionAlias(name, nameAlias) \
class Func_##name : public Function { \
public: \
	Func_##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const; \
}; \
Func_##name::Func_##name(Environment &env, const char *name) : \
							Function(env, Symbol::Add(name), FUNCTYPE_Function)

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
							Function(env, Symbol::Add(name), FUNCTYPE_Function)

#define Gura_DeclareFunctionWithDiffUnary(name) \
Gura_DeclareFunctionWithDiffUnaryAlias(name, #name)

// DeclareFunctionSucceedable
#define Gura_DeclareFunctionSucceedableAlias(name, nameAlias) \
class Func_##name : public Function { \
public: \
	Func_##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const; \
	virtual bool IsSucceedable(const ICallable *pCallable) const; \
}; \
Func_##name::Func_##name(Environment &env, const char *name) : \
							Function(env, Symbol::Add(name), FUNCTYPE_Function)

#define Gura_DeclareFunctionSucceedable(name) \
Gura_DeclareFunctionSucceedableAlias(name, #name)

// DeclareMethod
#define Gura_DeclareMethodAlias(className, name, nameAlias) \
class Func_##className##__##name : public Function { \
public: \
	Func_##className##__##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const; \
}; \
Func_##className##__##name::Func_##className##__##name(Environment &env, const char *name) : \
							Function(env, Symbol::Add(name), FUNCTYPE_Instance)

#define Gura_DeclareMethod(className, name) Gura_DeclareMethodAlias(className, name, #name)

// DeclareMethodPrimitive
#define Gura_DeclareMethodPrimitiveAlias(className, name, nameAlias) \
class Func_##className##__##name : public Function { \
public: \
	Func_##className##__##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const; \
}; \
Func_##className##__##name::Func_##className##__##name(Environment &env, const char *name) : \
							Function(env, Symbol::Add(name), FUNCTYPE_Function)

#define Gura_DeclareMethodPrimitive(className, name) Gura_DeclareMethodPrimitiveAlias(className, name, #name)

// DeclareClassMethod
#define Gura_DeclareClassMethodAlias(className, name, nameAlias) \
class Func_##className##__##name : public Function { \
public: \
	Func_##className##__##name(Environment &env, const char *name = nameAlias); \
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const; \
}; \
Func_##className##__##name::Func_##className##__##name(Environment &env, const char *name) : \
							Function(env, Symbol::Add(name), FUNCTYPE_Class)

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
							Function(env, Symbol::Add(name), FUNCTYPE_Function)

#define Gura_AssignFunction(name) \
env.AssignFunction(new Func_##name(env))

#define Gura_AssignFunctionEx(name, arg1) \
env.AssignFunction(new Func_##name(env, arg1))

#define Gura_AssignFunctionExx(name, arg1, arg2) \
env.AssignFunction(new Func_##name(env, arg1, arg2))

#define Gura_AssignMethod(className, name) \
AssignFunction(new Func_##className##__##name(*this))

#define Gura_AssignClassMethod(className, name) \
AssignFunction(new Func_##className##__##name(*this))

#define Gura_AssignMethodTo(valType, className, name) \
do { \
	Class *pClass = env.LookupClass(valType); \
	pClass->AssignFunction(new Func_##className##__##name(*pClass)); \
} while (0)

#define Gura_AssignMethodEx(className, name, arg1) \
AssignFunction(new Func_##className##__##name(*this, arg1))

#define Gura_AssignMethodExx(className, name, arg1, arg2) \
AssignFunction(new Func_##className##__##name(*this, arg1, arg2))

#define Gura_AssignValue(name, value) \
env.AssignValue(Symbol::Add(#name), value, false)

#define Gura_AssignClassValue(name, value) \
AssignValue(Symbol::Add(#name), value, false)

#define Gura_AssignValueTo(valType, name, value) \
do { \
	Class *pClass = env.LookupClass(valType); \
	pClass->AssignValue(Symbol::Add(#name), value, false); \
} while (0)

#define Gura_AssignValueEx(name, value) \
env.AssignValue(Symbol::Add(name), value, false)

namespace Gura {

class Args;
class ExprList;
class Expr_Block;
class Expr_Caller;
class CustomClass;
class FunctionCustom;
class Object_dict;
class ICallable;
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

//-----------------------------------------------------------------------------
// ICallable
//-----------------------------------------------------------------------------
class DLLDECLARE ICallable {
public:
	Value Call(Environment &env, Signal sig,
			const Value &valueSelf, Iterator *pIteratorSelf, bool listSelfFlag,
			const Expr_Caller *pExprCaller, const ExprList &exprListArg,
			const Function **ppFuncSuccRequester);
protected:
	virtual Value DoCall(Environment &env, Signal sig, Args &args) = 0;
};

//----------------------------------------------------------------------------
// Function
//-----------------------------------------------------------------------------
class DLLDECLARE Function {
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
	class DLLDECLARE ResultComposer {
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
	typedef std::map<const Symbol *, const Expr *, Symbol::KeyCompare_UniqNumber> ExprMap;
protected:
	int _cntRef;
	const Symbol *_pSymbol;
	Class *_pClassToConstruct;
	Environment _envScope;
	DeclarationOwner _declOwner;
	Parser::ElemType _elemType;
	OpType _opType;
	FunctionType _funcType;
	ResultMode _resultMode;
	unsigned long _flags;
	SymbolSet _attrsOpt;
	String _help;
	struct {
		OccurPattern occurPattern;
		BlockScope blockScope;
		bool quoteFlag;	// don't create function object from block
		const Symbol *pSymbol;
	} _blockInfo;
	static const char *_mathSymbolTbl[];
public:
	Function(const Function &func);
	Function(Environment &envScope, const Symbol *pSymbol, FunctionType funcType);
	virtual ~Function();
	inline int DecRef() { if (_cntRef > 0) _cntRef--; return _cntRef; }
	inline int GetRefCnt() const { return _cntRef; }
	inline static Function *Reference(const Function *pFunc) {
		if (pFunc == NULL) return NULL;
		Function *pFuncCasted = const_cast<Function *>(pFunc);
		pFuncCasted->_cntRef++;
		return pFuncCasted;
	}
	inline static void Delete(Function *pFunc) {
		if (pFunc != NULL && pFunc->DecRef() <= 0) delete pFunc;
	}
	inline void SetOperatorInfo(Parser::ElemType elemType, OpType opType) {
		_elemType = elemType; _opType = opType;
	}
	inline Class *GetClassToConstruct() const { return _pClassToConstruct; }
	inline void SetAsSymbolFunc() { _flags |= FLAG_SymbolFunc; }
	inline bool IsSymbolFunc() const { return GetSymbolFuncFlag(); }
	inline bool IsAnonymous() const { return _pSymbol->IsIdentical(Gura_Symbol(_anonymous_)); }
	inline void SetSymbol(const Symbol *pSymbol) { _pSymbol = pSymbol; }
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline const Symbol *GetSymbolForBlock() const { return _blockInfo.pSymbol; }
	inline const char *GetName() const { return _pSymbol->GetName(); }
	inline Parser::ElemType GetElemType() const { return _elemType; }
	inline OpType GetOpType() const { return _opType; }
	inline const char *GetMathSymbol() const { return _mathSymbolTbl[_opType]; }
	inline Environment &GetEnvScope() { return _envScope; }
	inline Environment &GetEnvScope() const {
		return const_cast<Function *>(this)->_envScope;
	}
	virtual bool IsCustom() const;
	virtual bool IsPos() const;
	virtual bool IsNeg() const;
	virtual bool IsPlus() const;
	virtual bool IsMinus() const;
	virtual bool IsMultiply() const;
	virtual bool IsDivide() const;
	virtual bool IsModulo() const;
	virtual bool IsPower() const;
	virtual bool IsContainCheck() const;
	virtual bool IsSequence() const;
	virtual bool IsStructPrototype() const;
	virtual Value EvalExpr(Environment &env, Signal sig, Args &args) const;
	Value Eval(Environment &env, Signal sig, Args &args) const;
	Value EvalFuncBinder(Environment &env, Signal sig, const ValueList &valListArg) const;
	Value EvalMap(Environment &env, Signal sig, Args &args) const;
	Value EvalMapRecursive(Environment &env, Signal sig,
				ResultComposer *pResultComposer, Args &args) const;
	virtual bool IsSucceedable(const ICallable *pCallable) const;
	inline FunctionType GetType() const { return _funcType; }
	inline const char *GetTypeName() const { return GetFuncTypeName(_funcType); }
	inline void SetMode(ResultMode resultMode, unsigned long flags) {
		_resultMode = resultMode, _flags = flags;
	}
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
	void SetClassToConstruct(Class *pClassToConstruct);
	bool CustomDeclare(Environment &env, Signal sig,
			const SymbolSet &attrsAcceptable, Args &args);
	void CopyDeclare(const Function &func);
	Declaration *DeclareArg(Environment &env, const Symbol *pSymbol, ValueType valType,
			OccurPattern occurPattern = OCCUR_Once, unsigned long flags = FLAG_None,
			Expr *pExprDefault = NULL);
	inline Declaration *DeclareArg(Environment &env, const char *name, ValueType valType,
			OccurPattern occurPattern = OCCUR_Once, unsigned long flags = FLAG_None,
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
	inline const char *GetHelp() const { return _help.c_str(); }
	inline bool IsHelpExist() const { return !_help.empty(); }
	void DeclareBlock(OccurPattern occurPattern, const Symbol *pSymbol = NULL,
			BlockScope blockScope = BLKSCOPE_Through, bool quoteFlag = false);
	void SetHelp(const char *help);
	String ToString() const;
	void SetError_DivideByZero(Signal sig) const;
	void SetError_UnsupportedAttr(Signal sig, const SymbolSet &attrs) const;
	void SetError_NotConstructor(Signal sig) const;
	void SetError_ArgumentTypeByIndex(Signal sig, Args &args, size_t idxArg) const;
	void SetError_InvalidValue(Signal sig, const Value &value) const;
	void SetError_InvalidValue(Signal sig, const Value &value1, const Value &value2) const;
	void SetError_InvalidValType(Signal sig, const Value &value) const;
	void SetError_InvalidValType(Signal sig, const Value &value1, const Value &value2) const;
	void SetError_InvalidValTypeM(Signal sig, const Value &value1, const Value &value2) const;
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
	Value EvalOverrideUnary(Signal sig, Args &args, bool &evaluatedFlag) const;
	Value EvalOverrideBinary(Signal sig, Args &args, bool &evaluatedFlag) const;
	Value ReturnIterator(Environment &env, Signal sig,
					Args &args, Iterator *pIterator) const;
	Value ReturnValue(Environment &env, Signal sig,
					Args &args, const Value &result) const;
	Value DoRepeater(Environment &env, Signal sig,
					Args &args, Iterator *pIterator) const;
	Environment *PrepareEnvironment(Environment &env, Signal sig, Args &args) const;
private:
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const = 0;
};

//-----------------------------------------------------------------------------
// FunctionCustom
//-----------------------------------------------------------------------------
class DLLDECLARE FunctionCustom : public Function {
private:
	AutoPtr<Expr> _pExprBody;
public:
	FunctionCustom(Environment &envScope, const Symbol *pSymbol,
									Expr *pExprBody, FunctionType funcType);
	virtual ~FunctionCustom();
	virtual bool IsCustom() const;
	inline const Expr *GetExprBody() const { return _pExprBody.get(); }
	inline void SetExprBody(Expr *pExprBody) { _pExprBody.reset(pExprBody); }
	virtual Expr *DiffUnary(Environment &env, Signal sig,
						const Expr *pExprArg, const Symbol *pSymbol) const;
	static FunctionCustom *CreateBlockFunc(Environment &env, Signal sig,
		const Symbol *pSymbol, const Expr_Block *pExprBlock, FunctionType funcType);
private:
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

//-----------------------------------------------------------------------------
// ClassPrototype
//-----------------------------------------------------------------------------
class DLLDECLARE ClassPrototype : public Function {
private:
	Environment _envScope;
	AutoPtr<Expr> _pExprBody;
public:
	ClassPrototype(Environment &envScope, const Symbol *pSymbol, Expr *pExpr,
													FunctionType funcType);
	virtual ~ClassPrototype();
	inline const Expr *GetExprBody() const { return _pExprBody.get(); }
private:
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

//-----------------------------------------------------------------------------
// StructPrototype
//-----------------------------------------------------------------------------
class DLLDECLARE StructPrototype : public Function {
public:
	StructPrototype(Environment &env);
	virtual ~StructPrototype();
	virtual bool IsStructPrototype() const;
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

//-----------------------------------------------------------------------------
// Args
//-----------------------------------------------------------------------------
class DLLDECLARE Args {
private:
	Value _valueSelf;
	AutoPtr<Iterator> _pIteratorSelf;
	bool _listSelfFlag;
	const Value &_valueWithDict;
	const ExprList &_exprListArg;
	const ValueList &_valListArg;
	const Function **_ppFuncSuccRequester;
	const SymbolSet &_attrs;
	const SymbolSet &_attrsOpt;
	const Expr_Block *_pExprBlock;
	ResultMode _resultMode;
	unsigned long _flags;
	AutoPtr<Function> _pFuncBlock;
public:
	inline Args(const ExprList &exprListArg, const Value &valueSelf = Value::Null,
				Iterator *pIteratorSelf = NULL, bool listSelfFlag = false,
				const Function **ppFuncSuccRequester = NULL,
				const SymbolSet &attrs = SymbolSet::Null,
				const SymbolSet &attrsOpt = SymbolSet::Null,
				const Expr_Block *pExprBlock = NULL) :
		_valueSelf(valueSelf),
		_pIteratorSelf(pIteratorSelf), _listSelfFlag(listSelfFlag),
		_valueWithDict(Value::Null),
		_exprListArg(exprListArg), _valListArg(ValueList::Null),
		_ppFuncSuccRequester(ppFuncSuccRequester),
		_attrs(attrs), _attrsOpt(attrsOpt), _pExprBlock(pExprBlock),
		_resultMode(RSLTMODE_Normal), _flags(FLAG_None),
		_pFuncBlock(NULL) {}
	inline Args(const ValueList &valListArg, const Value &valueSelf = Value::Null,
				Iterator *pIteratorSelf = NULL, bool listSelfFlag = false,
				const Function **ppFuncSuccRequester = NULL,
				const SymbolSet &attrs = SymbolSet::Null,
				const SymbolSet &attrsOpt = SymbolSet::Null,
				const Expr_Block *pExprBlock = NULL) :
		_valueSelf(valueSelf),
		_pIteratorSelf(pIteratorSelf), _listSelfFlag(listSelfFlag),
		_valueWithDict(Value::Null),
		_exprListArg(ExprList::Null), _valListArg(valListArg),
		_ppFuncSuccRequester(ppFuncSuccRequester),
		_attrs(attrs), _attrsOpt(attrsOpt), _pExprBlock(pExprBlock),
		_resultMode(RSLTMODE_Normal), _flags(FLAG_None),
		_pFuncBlock(NULL) {}
	inline Args(Args &args, const ValueList &valListArg,
			const Value &valueWithDict, ResultMode resultMode, unsigned long flags) :
		_valueSelf(args._valueSelf),
		_pIteratorSelf(Iterator::Reference(args._pIteratorSelf.get())), _listSelfFlag(args._listSelfFlag),
		_valueWithDict(valueWithDict),
		_exprListArg(ExprList::Null), _valListArg(valListArg),
		_ppFuncSuccRequester(args._ppFuncSuccRequester),
		_attrs(args._attrs), _attrsOpt(args._attrsOpt), _pExprBlock(args._pExprBlock),
		_resultMode(resultMode), _flags(flags),
		_pFuncBlock(Function::Reference(args._pFuncBlock.get())) {}
	inline Args(Args &args, const ExprList &exprListArg) :
		_valueSelf(args._valueSelf),
		_pIteratorSelf(Iterator::Reference(args._pIteratorSelf.get())), _listSelfFlag(args._listSelfFlag),
		_valueWithDict(Value::Null),
		_exprListArg(exprListArg), _valListArg(ValueList::Null),
		_ppFuncSuccRequester(args._ppFuncSuccRequester),
		_attrs(args._attrs), _attrsOpt(args._attrsOpt), _pExprBlock(args._pExprBlock),
		_resultMode(args._resultMode), _flags(args._flags),
		_pFuncBlock(Function::Reference(args._pFuncBlock.get())) {}
	virtual ~Args();
	inline bool IsSet(const Symbol *pSymbol) const {
		return _attrs.IsSet(pSymbol);
	}
	inline bool IsAttrEmpty() const { return _attrs.empty(); }
	inline const SymbolSet &GetAttrs() const { return _attrs; }
	inline const SymbolSet &GetAttrsOpt() const { return _attrsOpt; }
	inline ResultMode GetResultMode() const { return _resultMode; }
	inline bool GetFlatFlag() const { return (_flags & FLAG_Flat)? true : false; }
	inline void SetSelf(const Value &valueSelf) { _valueSelf = valueSelf; }
	inline Value &GetSelf() { return _valueSelf; }
	inline const Value &GetSelf() const { return _valueSelf; }
	inline Class *GetSelfClass() { return _valueSelf.GetClass(); }
	inline Object *GetSelfObj() { return _valueSelf.GetObject(); }
	inline ObjectBase *GetSelfObjBase() { return _valueSelf.GetObjectBase(); }
	inline Iterator *GetIteratorSelf() { return _pIteratorSelf.get(); }
	inline bool IsSelfIterable() const { return !_pIteratorSelf.IsNull(); }
	inline bool IsSelfList() const { return !_pIteratorSelf.IsNull() && _listSelfFlag; }
	inline bool IsSelfIterator() const { return !_pIteratorSelf.IsNull() && !_listSelfFlag; }
	inline bool IsBlockSpecified() const { return _pExprBlock != NULL; }
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
	inline void RequestSucceeding(const Function *pFuncSuccRequester) {
		if (_ppFuncSuccRequester != NULL) *_ppFuncSuccRequester = pFuncSuccRequester;
	}
	inline const ExprList &GetExprListArg() const { return _exprListArg; }
	inline const ValueList &GetArgs() const { return _valListArg; }
	inline size_t CountArgs() const { return _valListArg.size(); }
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
	inline bool IsFunction(size_t idxArg) const			{ return GetValue(idxArg).IsFunction();	}
	inline bool IsIterator(size_t idxArg) const			{ return GetValue(idxArg).IsIterator();	}
	inline bool IsList(size_t idxArg) const				{ return GetValue(idxArg).IsList();		}
	inline bool IsMatrix(size_t idxArg) const			{ return GetValue(idxArg).IsMatrix();	}
	inline bool IsDict(size_t idxArg) const				{ return GetValue(idxArg).IsDict();		}
	inline bool IsStream(size_t idxArg) const			{ return GetValue(idxArg).IsStream();	}
	inline bool IsImage(size_t idxArg) const			{ return GetValue(idxArg).IsImage();	}
	inline bool IsColor(size_t idxArg) const			{ return GetValue(idxArg).IsColor();	}
	inline bool IsPalette(size_t idxArg) const			{ return GetValue(idxArg).IsPalette();	}
	inline bool IsExpr(size_t idxArg) const				{ return GetValue(idxArg).IsExpr();		}
	inline bool IsError(size_t idxArg) const			{ return GetValue(idxArg).IsError();	}
	inline bool IsNumberOrComplex(size_t idxArg) const	{ return GetValue(idxArg).IsNumberOrComplex(); }
	inline bool IsInstanceOf(size_t idxArg, ValueType valType) { return GetValue(idxArg).IsInstanceOf(valType); }
	inline Number GetNumber(size_t idxArg) const		{ return GetValue(idxArg).GetNumber();	}
	inline int GetInt(size_t idxArg) const				{ return GetValue(idxArg).GetInt();		}
	inline unsigned int GetUInt(size_t idxArg) const	{ return GetValue(idxArg).GetUInt();	}
	inline size_t GetSizeT(size_t idxArg) const			{ return GetValue(idxArg).GetSizeT();	}
	inline char GetChar(size_t idxArg) const			{ return GetValue(idxArg).GetChar();	}
	inline unsigned char GetUChar(size_t idxArg) const	{ return GetValue(idxArg).GetUChar();	}
	inline short GetShort(size_t idxArg) const			{ return GetValue(idxArg).GetShort();	}
	inline unsigned short GetUShort(size_t idxArg) const{ return GetValue(idxArg).GetUShort();	}
	inline long GetLong(size_t idxArg) const			{ return GetValue(idxArg).GetLong();	}
	inline unsigned long GetULong(size_t idxArg) const	{ return GetValue(idxArg).GetULong();	}
	inline int64 GetInt64(size_t idxArg) const			{ return GetValue(idxArg).GetInt64();	}
	inline uint64 GetUInt64(size_t idxArg) const		{ return GetValue(idxArg).GetUInt64();	}
	inline float GetFloat(size_t idxArg) const			{ return GetValue(idxArg).GetFloat();	}
	inline double GetDouble(size_t idxArg) const		{ return GetValue(idxArg).GetDouble();	}
	inline bool GetBoolean(size_t idxArg) const			{ return GetValue(idxArg).GetBoolean();	}
	inline const Symbol *GetSymbol(size_t idxArg) const	{ return GetValue(idxArg).GetSymbol();	}
	inline Object *GetObj(size_t idxArg)				{ return GetValue(idxArg).GetObject();	}
	inline Object *GetObj(size_t idxArg) const			{ return GetValue(idxArg).GetObject();	}
	inline Object *GetObject(size_t idxArg)				{ return GetValue(idxArg).GetObject();	}
	inline Object *GetObject(size_t idxArg) const		{ return GetValue(idxArg).GetObject();	}
	inline const char *GetString(size_t idxArg) const	{ return GetValue(idxArg).GetString();	}
	inline String GetStringSTL(size_t idxArg) const		{ return GetValue(idxArg).GetStringSTL(); }
	inline const Binary &GetBinary(size_t idxArg) const	{ return GetValue(idxArg).GetBinary();	}
	inline Object_stream *GetStreamObj(size_t idxArg)	{ return GetValue(idxArg).GetStreamObj(); }
	inline Complex GetComplex(size_t idxArg) const		{ return GetValue(idxArg).GetComplex();	}
	inline Module *GetModule(size_t idxArg)				{ return GetValue(idxArg).GetModule();	}
	inline const Module *GetModule(size_t idxArg) const	{ return GetValue(idxArg).GetModule();	}
	inline Class *GetClass(size_t idxArg)				{ return GetValue(idxArg).GetClass();	}
	inline const Class *GetClass(size_t idxArg) const	{ return GetValue(idxArg).GetClass();	}
	inline const ValueList &GetList(size_t idxArg) const{ return GetValue(idxArg).GetList();	}
	inline Object_list *GetListObj(size_t idxArg)		{ return GetValue(idxArg).GetListObj(); }
	inline const Object_list *GetListObj(size_t idxArg) const{ return GetValue(idxArg).GetListObj(); }
	inline const ValueDict &GetDict(size_t idxArg) const{ return GetValue(idxArg).GetDict();	}
	inline Object_matrix *GetMatrixObj(size_t idxArg)	{ return GetValue(idxArg).GetMatrixObj(); }
	inline const Object_matrix *GetMatrixObj(size_t idxArg) const{ return GetValue(idxArg).GetMatrixObj(); }
	inline Object_image *GetImageObj(size_t idxArg)		{ return GetValue(idxArg).GetImageObj(); }
	inline const Object_image *GetImageObj(size_t idxArg) const{ return GetValue(idxArg).GetImageObj(); }
	inline Object_color *GetColorObj(size_t idxArg)		{ return GetValue(idxArg).GetColorObj(); }
	inline const Object_color *GetColorObj(size_t idxArg) const{ return GetValue(idxArg).GetColorObj(); }
	inline Object_palette *GetPaletteObj(size_t idxArg)	{ return GetValue(idxArg).GetPaletteObj(); }
	inline const Object_palette *GetPaletteObj(size_t idxArg) const{ return GetValue(idxArg).GetPaletteObj(); }
	inline Iterator *GetIterator(size_t idxArg) const	{ return GetValue(idxArg).GetIterator();}
	inline Stream &GetStream(size_t idxArg)				{ return GetValue(idxArg).GetStream();	}
	inline Stream &GetStream(size_t idxArg) const		{
		return const_cast<Args *>(this)->GetValue(idxArg).GetStream();
	}
	inline const Expr *GetExpr(size_t idxArg) const		{ return GetValue(idxArg).GetExpr();	}
	inline Function *GetFunction(size_t idxArg)			{ return GetValue(idxArg).GetFunction(); }
	inline const Function *GetFunction(size_t idxArg) const	{ return GetValue(idxArg).GetFunction(); }
	inline Object_function *GetFunctionObj(size_t idxArg) { return GetValue(idxArg).GetFunctionObj(); }
	inline const Object_function *GetFunctionObj(size_t idxArg) const { return GetValue(idxArg).GetFunctionObj(); }
	inline ErrorType GetErrorType(size_t idxArg) const	{ return GetValue(idxArg).GetErrorType(); }
	inline const Value &GetValueWithDict() const		{ return _valueWithDict;				}
	inline const ValueDict &GetDictArg() const {
		return _valueWithDict.IsDict()? _valueWithDict.GetDict() : ValueDict::Null;
	}
	const Expr_Block *GetBlock(Environment &env, Signal sig) const;
	bool ShouldGenerateIterator(const DeclarationList &declList) const;
	const Function *GetBlockFunc(Environment &env, Signal sig, const Symbol *pSymbol);
};

}

#endif
