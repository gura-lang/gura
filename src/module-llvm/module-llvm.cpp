//-----------------------------------------------------------------------------
// Gura module: llvm
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(llvm)

//-----------------------------------------------------------------------------
// Restorer
//-----------------------------------------------------------------------------
template<typename T> class Restorer {
private:
	T &_target;
	T _valueOrg;
public:
	inline Restorer(T &target, T value) : _target(target), _valueOrg(target) {
		_target = value;
	}
	inline ~Restorer() {
		_target = _valueOrg;
	}
};

//-----------------------------------------------------------------------------
// Gura Stub Functions
//-----------------------------------------------------------------------------
extern "C" bool GuraStub_LookupValue(Environment &env, Signal &sig, Value &result, const Symbol *pSymbol)
{
	Value *pValue = env.LookupValue(pSymbol, ENVREF_Escalate);
	if (pValue == NULL) {
		sig.SetError(ERR_ValueError, "undefined variable %s", pSymbol->GetName());
		return false;
	} else {
		Gura_CopyValue(result, *pValue);
		return true;
	}
}

extern "C" bool GuraStub_AssignValue(Environment &env, Signal &sig,
									 const Symbol *pSymbol, const Value &value, ULong extra)
{
	env.AssignValue(pSymbol, value, extra);
	return true;
}

extern "C" bool GuraStub_AddValueList(Environment &env, Signal &sig,
									  ValueList &valList, const Value &value)
{
	if (value.Is_iterator()) {
		AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
		if (sig.IsSignalled()) return false;
		if (pIterator->IsInfinite()) {
			Iterator::SetError_InfiniteNotAllowed(sig);
			return false;
		}
		Value value;
		while (pIterator->Next(env, sig, value)) {
			valList.push_back(value);
		}
		return sig.IsNoSignalled();
	} else {
		valList.push_back(value);
		return true;
	}
}

extern "C" void GuraStub_CreateValue_number(Value &value, double num)
{
	Gura_CopyValue(value, Value(num));
}

extern "C" void GuraStub_CreateValue_string(Value &value, const char *str)
{
	Gura_CopyValue(value, Value(str));
}

extern "C" void GuraStub_CreateValue_binary(Environment &env, Value &value, const char *buff, ULong bytes)
{
	Gura_CopyValue(value, Value(new Object_binary(env, buff, bytes, false)));
}

extern "C" ValueList *GuraStub_CreateValueList(Environment &env, Value &value)
{
	Object_list *pObj = new Object_list(env);
	value._SetObject(pObj);
	return &pObj->GetList();
}

#define ImplementPrefixedUnaryOpStub(name) \
extern "C" bool GuraStub_UnaryOp_##name(Environment &env, Signal &sig, \
									Value &valueResult, const Value &value)	\
{ \
	Gura_CopyValue(valueResult, Operator::name->EvalMapUnary(env, sig, value, false)); \
	return sig.IsNoSignalled(); \
}

#define ImplementSuffixedUnaryOpStub(name) \
extern "C" bool GuraStub_UnaryOp_##name(Environment &env, Signal &sig, \
									Value &valueResult, const Value &value)	\
{ \
	Gura_CopyValue(valueResult, Operator::name->EvalMapUnary(env, sig, value, true)); \
	return sig.IsNoSignalled(); \
}

#define ImplementBinaryOpStub(name) \
extern "C" bool GuraStub_BinaryOp_##name(Environment &env, Signal &sig, \
					Value &valueResult, const Value &valueLeft, const Value &valueRight) \
{ \
	Gura_CopyValue(valueResult, Operator::name->EvalMapBinary(env, sig, valueLeft, valueRight)); \
	return sig.IsNoSignalled(); \
}

ImplementPrefixedUnaryOpStub(Pos)
ImplementPrefixedUnaryOpStub(Neg)
ImplementPrefixedUnaryOpStub(Inv)
ImplementPrefixedUnaryOpStub(Not)
ImplementSuffixedUnaryOpStub(SeqInf)
ImplementSuffixedUnaryOpStub(Question)
ImplementPrefixedUnaryOpStub(Each)
ImplementBinaryOpStub(Add)
ImplementBinaryOpStub(Sub)
ImplementBinaryOpStub(Mul)
ImplementBinaryOpStub(Div)
ImplementBinaryOpStub(Mod)
ImplementBinaryOpStub(Pow)
ImplementBinaryOpStub(Eq)
ImplementBinaryOpStub(Ne)
ImplementBinaryOpStub(Gt)
ImplementBinaryOpStub(Lt)
ImplementBinaryOpStub(Ge)
ImplementBinaryOpStub(Le)
ImplementBinaryOpStub(Cmp)
ImplementBinaryOpStub(Contains)
ImplementBinaryOpStub(And)
ImplementBinaryOpStub(Or)
ImplementBinaryOpStub(Xor)
ImplementBinaryOpStub(Shl)
ImplementBinaryOpStub(Shr)
ImplementBinaryOpStub(OrOr)
ImplementBinaryOpStub(AndAnd)
ImplementBinaryOpStub(Seq)
ImplementBinaryOpStub(Pair)

extern "C" bool GuraStub_IndexGet(
	Environment &env, Signal &sig,
	ValueList &valList, const Value &valueCar, const Value &valueIdx)
{
	if (valueIdx.IsListOrIterator()) {
		AutoPtr<Iterator> pIterator(valueIdx.CreateIterator(sig));
		if (sig.IsSignalled()) return false;
		if (pIterator->IsInfinite()) {
			Iterator::SetError_InfiniteNotAllowed(sig);
			return false;
		}
		Value valueIdxElem;
		while (pIterator->Next(env, sig, valueIdxElem)) {
			Value value = valueCar.IndexGet(env, sig, valueIdxElem);
			if (sig.IsSignalled()) return false;
			valList.push_back(value);
		}
		return sig.IsNoSignalled();
	} else {
		Value value = valueCar.IndexGet(env, sig, valueIdx);
		if (sig.IsSignalled()) return false;
		valList.push_back(value);
	}
	return true;
}

extern "C" bool GuraStub_IndexSet(
	Environment &env, Signal &sig,
	Value &valueCar, const Value &valueIdx, const Value &valueAssigned)
{
	if (!valueIdx.IsListOrIterator()) {
		valueCar.IndexSet(env, sig, valueIdx, valueAssigned);
		return sig.IsNoSignalled();
	} else if (valueAssigned.IsListOrIterator()) {
		AutoPtr<Iterator> pIteratorIdx(valueIdx.CreateIterator(sig));
		if (sig.IsSignalled()) return false;
		AutoPtr<Iterator> pIteratorAssigned(valueAssigned.CreateIterator(sig));
		if (sig.IsSignalled()) return false;
		if (pIteratorIdx->IsInfinite() && pIteratorAssigned->IsInfinite()) {
			Iterator::SetError_InfiniteNotAllowed(sig);
			return false;
		}
		Value valueIdxElem, valueAssignedElem;
		while (pIteratorIdx->Next(env, sig, valueIdxElem) &&
			   pIteratorAssigned->Next(env, sig, valueAssignedElem)) {
			valueCar.IndexSet(env, sig, valueIdxElem, valueAssignedElem);
			if (sig.IsSignalled()) return false;
		}
		return sig.IsNoSignalled();
	} else {
		AutoPtr<Iterator> pIteratorIdx(valueIdx.CreateIterator(sig));
		if (sig.IsSignalled()) return false;
		if (pIteratorIdx->IsInfinite()) {
			Iterator::SetError_InfiniteNotAllowed(sig);
			return false;
		}
		Value valueIdxElem;
		while (pIteratorIdx->Next(env, sig, valueIdxElem)) {
			valueCar.IndexSet(env, sig, valueIdxElem, valueAssigned);
			if (sig.IsSignalled()) return false;
		}
		return sig.IsNoSignalled();
	}
}

extern "C" bool GuraStub_IndexSetByIterator(
	Environment &env, Signal &sig,
	Value &valueCar, const Value &valueIdx, Iterator *pIteratorAssigned)
{
	if (valueIdx.IsListOrIterator()) {
		AutoPtr<Iterator> pIteratorIdx(valueIdx.CreateIterator(sig));
		if (sig.IsSignalled()) return false;
		if (pIteratorIdx->IsInfinite() && pIteratorAssigned->IsInfinite()) {
			Iterator::SetError_InfiniteNotAllowed(sig);
			return false;
		}
		Value valueIdxElem, valueAssignedElem;
		while (pIteratorIdx->Next(env, sig, valueIdxElem)) {
			if (!pIteratorAssigned->Next(env, sig, valueAssignedElem)) return false;
			valueCar.IndexSet(env, sig, valueIdxElem, valueAssignedElem);
			if (sig.IsSignalled()) return false;
		}
		return sig.IsNoSignalled();
	} else {
		Value valueAssignedElem;
		if (!pIteratorAssigned->Next(env, sig, valueAssignedElem)) return false;
		valueCar.IndexSet(env, sig, valueIdx, valueAssignedElem);
		return sig.IsNoSignalled();
	}
	return true;
}

extern "C" bool GuraStub_EmptyIndexGet(
	Environment &env, Signal &sig, Value &valueResult, const Value &valueCar)
{
	valueResult = valueCar.EmptyIndexGet(env, sig);
	return sig.IsNoSignalled();
}

extern "C" bool GuraStub_EmptyIndexSet(
	Environment &env, Signal &sig, Value &valueCar, const Value &value)
{
	valueCar.EmptyIndexSet(env, sig, value);
	return sig.IsNoSignalled();
}

extern "C" bool GuraStub_CallFunction(
	Environment &env, Signal &sig,
	Value &valueResult, const Value &valueCar,
	BridgeFunctionT bridgeFuncBlockParam, BridgeFunctionT bridgeFuncBlock, ...)
{
	if (!valueCar.Is_function()) {
		sig.SetError(ERR_TypeError, "object is not a function");
		Gura_CopyValue(valueResult, Value::Null);
		return false;
	}
	const Function *pFunc = valueCar.GetFunction();
	va_list vargs;
	va_start(vargs, bridgeFuncBlock);
	AutoPtr<Args> pArgs(new Args());
	while (BridgeFunctionT bridgeFuncArg = va_arg(vargs, BridgeFunctionT)) {
		Value value;
		bridgeFuncArg(env, sig, value);
		if (sig.IsSignalled()) return false;
		pArgs->AddValue(value);
	}
	Gura_CopyValue(valueResult, pFunc->Eval(env, sig, *pArgs));
	return sig.IsNoSignalled();
}

extern "C" bool GuraStub_CreateIterator(Environment &env, Signal &sig,
										Value &value, Iterator **ppIterator)
{
	*ppIterator = value.CreateIterator(sig);
	return *ppIterator != nullptr;
}

extern "C" void GuraStub_ReleaseIterator(Iterator *pIterator)
{
	Iterator::Delete(pIterator);
}

extern "C" bool GuraStub_NextIterator(Environment &env, Signal &sig, Iterator *pIterator, Value &value)
{
	return pIterator->Next(env, sig, value);
}

//-----------------------------------------------------------------------------
// CodeGeneratorLLVM
//-----------------------------------------------------------------------------
class CodeGeneratorLLVM : public CodeGenerator {
public:
	class Context {
	private:
		llvm::Value *_plv_env;
		llvm::Value *_plv_sig;
		llvm::BasicBlock *_pBasicBlockEntry;
		llvm::BasicBlock *_pBasicBlockExit;
		llvm::BasicBlock *_pBasicBlockRelease;
	public:
		inline Context(llvm::Value *plv_env, llvm::Value *plv_sig,
					   llvm::BasicBlock *pBasicBlockEntry, llvm::BasicBlock *pBasicBlockExit,
					   llvm::BasicBlock *pBasicBlockRelease) :
			_plv_env(plv_env), _plv_sig(plv_sig),
			_pBasicBlockEntry(pBasicBlockEntry), _pBasicBlockExit(pBasicBlockExit),
			_pBasicBlockRelease(pBasicBlockRelease) {}
		inline llvm::Value *Get_env() { return _plv_env; }
		inline llvm::Value *Get_sig() { return _plv_sig; }
		inline llvm::BasicBlock *GetBasicBlockEntry() { return _pBasicBlockEntry; }
		inline llvm::BasicBlock *GetBasicBlockExit() { return _pBasicBlockExit; }
		inline llvm::BasicBlock *GetBasicBlockRelease() { return _pBasicBlockRelease; }
	};
	typedef std::vector<Context *> ContextStack;
private:
	llvm::LLVMContext &_context;
	std::unique_ptr<llvm::Module> _pModule;
	llvm::IRBuilder<> _builder;
	ContextStack _contextStack;
	llvm::Value *_plv_valueResult;
	llvm::BasicBlock *_pBasicBlockExit;
	llvm::StructType *_pStructType_Value;
	llvm::StructType *_pStructType_ValueList;
	llvm::StructType *_pStructType_Environment;
	llvm::StructType *_pStructType_Signal;
	llvm::StructType *_pStructType_Symbol;
	llvm::StructType *_pStructType_Iterator;
public:
	CodeGeneratorLLVM();
	inline llvm::Module *GetModule() { return _pModule.get(); }
	bool Generate(Environment &env, Signal &sig, const Expr *pExpr);
	Value Run(Environment &env, Signal &sig);
private:
	inline llvm::Function *GetFunctionCur() {
		return _builder.GetInsertBlock()->getParent();
	}
	inline llvm::Value *Get_env() { return _contextStack.back()->Get_env(); }
	inline llvm::Value *Get_sig() { return _contextStack.back()->Get_sig(); }
	inline llvm::BasicBlock *GetBasicBlockEntry() {
		return _contextStack.back()->GetBasicBlockEntry();
	}
	inline llvm::BasicBlock *GetBasicBlockExit() {
		return (_pBasicBlockExit == nullptr)?
			_contextStack.back()->GetBasicBlockExit() : _pBasicBlockExit;
	}
	inline llvm::BasicBlock *GetBasicBlockRelease() {
		return _contextStack.back()->GetBasicBlockRelease();
	}
	llvm::Function *CreateBridgeFunction(Environment &env, Signal &sig,
										 const Expr *pExpr, const char *name);
private:
	virtual bool GenCode_Value(Environment &env, Signal &sig, const Expr_Value *pExprValue);
	virtual bool GenCode_Identifier(Environment &env, Signal &sig, const Expr_Identifier *pExpr);
	virtual bool GenCode_Suffixed(Environment &env, Signal &sig, const Expr_Suffixed *pExpr);
	virtual bool GenCode_Root(Environment &env, Signal &sig, const Expr_Root *pExpr);
	virtual bool GenCode_Block(Environment &env, Signal &sig, const Expr_Block *pExpr);
	virtual bool GenCode_Lister(Environment &env, Signal &sig, const Expr_Lister *pExpr);
	virtual bool GenCode_Iterer(Environment &env, Signal &sig, const Expr_Iterer *pExpr);
	virtual bool GenCode_Indexer(Environment &env, Signal &sig, const Expr_Indexer *pExpr);
	virtual bool GenCode_Caller(Environment &env, Signal &sig, const Expr_Caller *pExpr);
	virtual bool GenCode_UnaryOp(Environment &env, Signal &sig, const Expr_UnaryOp *pExpr);
	virtual bool GenCode_BinaryOp(Environment &env, Signal &sig, const Expr_BinaryOp *pExpr);
	virtual bool GenCode_Quote(Environment &env, Signal &sig, const Expr_Quote *pExpr);
	virtual bool GenCode_Assign(Environment &env, Signal &sig, const Expr_Assign *pExpr);
	virtual bool GenCode_Member(Environment &env, Signal &sig, const Expr_Member *pExpr);
	bool GenCode_AssignToIdentifier(Environment &env, Signal &sig,
									const Expr_Identifier *pExpr, llvm::Value *plv_valueAssigned);
	bool GenCode_AssignToLister(Environment &env, Signal &sig,
								const Expr_Lister *pExpr, llvm::Value *plv_valueAssigned,
								bool alwaysIterableFlag);
	bool GenCode_AssignToIndexer(Environment &env, Signal &sig,
								 const Expr_Indexer *pExpr, llvm::Value *plv_valueAssigned,
								 bool alwaysIterableFlag);
	bool GenCode_AssignToCaller(Environment &env, Signal &sig,
								const Expr_Caller *pExpr, const Expr *pExprAssigned);
	bool GenCode_AssignToMember(Environment &env, Signal &sig,
								const Expr_Member *pExpr, llvm::Value *plv_valueAssigned);
private:
	void GenCode_CondBrExitWhenSignalled(const llvm::Twine &nameForContinueBB);
	void GenCode_CondBrContinueOrExit(llvm::Value *plv_successFlag, const llvm::Twine &nameForContinueBB);
	llvm::Value *GenCode_CheckValType(llvm::Value *plv_value, UShort valType);
	llvm::Value *GenCode_CheckValTypeListOrIterator(llvm::Value *plv_value);
	llvm::Value *GenCode_CallBinaryOp(
		Environment &env, Signal &sig, const Operator *pOperator,
		const Expr *pExprLeft, const Expr *pExprRight);
	llvm::Value *GenCode_CallUnaryOp(
		Environment &env, Signal &sig, const Operator *pOperator, const Expr *pExprChild);
	llvm::Value *GenCode_AllocaValue(const llvm::Twine &name, bool initFlag = true);
	llvm::Value *GenCode_CastCPointerToPtr(const void *p, llvm::Type *pType);
	llvm::Value *GenCode_CreateIterator(
		llvm::Value *plv_value, const llvm::Twine &nameForPP, const llvm::Twine &nameForP);
	llvm::Value *GenCode_ReleaseIterator(llvm::Value *plv_pIterator);
};

CodeGeneratorLLVM::CodeGeneratorLLVM() :
	_context(llvm::getGlobalContext()),	_builder(llvm::getGlobalContext()),
	_plv_valueResult(nullptr), _pBasicBlockExit(nullptr),
	_pStructType_Value(nullptr), _pStructType_ValueList(nullptr), _pStructType_Signal(nullptr),
	_pStructType_Symbol(nullptr), _pStructType_Iterator(nullptr)
{
}

bool CodeGeneratorLLVM::Generate(Environment &env, Signal &sig, const Expr *pExpr)
{
	_pModule.reset(new llvm::Module("gura", llvm::getGlobalContext()));
	do {
		// %struct.Value = type { [sizeof(Value) x i8] }
		_pStructType_Value = llvm::StructType::create(
			"struct.Value",
			llvm::ArrayType::get(_builder.getInt8Ty(), sizeof(Value)),
			nullptr);
	} while (0);
	do {
		// %struct.ValueList = type { i32 }
		_pStructType_ValueList = llvm::StructType::create(
			"struct.ValueList",
			_builder.getInt32Ty(),		// (dummy)
			nullptr);
	} while (0);
	do {
		// %struct.Environment = type { i32 }
		_pStructType_Environment = llvm::StructType::create(
			"struct.Environment",
			_builder.getInt32Ty(),		// (dummy)
			nullptr);
	} while (0);
	do {
		// %struct.Signal = type { i32 }
		_pStructType_Signal = llvm::StructType::create(
			"struct.Signal",
			_builder.getInt32Ty(),		// sigType
			nullptr);
	} while (0);
	do {
		// %struct.Symbol = type { i32 }
		_pStructType_Symbol = llvm::StructType::create(
			"struct.Symbol",
			_builder.getInt32Ty(),		// uniqNum
			nullptr);
	} while (0);
	do {
		// %struct.Iterator = type { i32 }
		_pStructType_Iterator = llvm::StructType::create(
			"struct.Iterator",
			_builder.getInt32Ty(),		// (dummy)
			nullptr);
	} while (0);
	do {
		// declare i32 @puts(i8*)
		llvm::Type *pTypeResult = _builder.getInt32Ty();			// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// str
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"puts",
			_pModule.get());
	} while (0);
	do {
		// declare void @Gura_CopyValue(struct.Value*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueDst
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueSrc
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"Gura_CopyValue",
			_pModule.get());
	} while (0);
	do {
		// declare void @Gura_ReleaseValue(struct.Value*)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"Gura_ReleaseValue",
			_pModule.get());
	} while (0);
	do {
		// declare void @GuraStub_CreateValue_number(struct.Value*, double)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		typeArgs.push_back(_builder.getDoubleTy());					// num
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_CreateValue_number",
			_pModule.get());
	} while (0);
	do {
		// declare void @GuraStub_CreateValue_string(struct.Value*, i8*)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// str
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_CreateValue_string",
			_pModule.get());
	} while (0);
	do {
		// declare void @GuraStub_CreateValue_binary(i8*, struct.Value*, i8*, i32)
		llvm::Type *pTypeResult = _builder.getVoidTy();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());		// env
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// value
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());		// buff
		typeArgs.push_back(_builder.getInt32Ty());						// bytes
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_CreateValue_binary",
			_pModule.get());
	} while (0);
	do {
		// declare struct.ValueList* @GuraStub_CreateValueList(i8*, struct.Value*)
		llvm::Type *pTypeResult = _pStructType_ValueList->getPointerTo(); // return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// value
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_CreateValueList",
			_pModule.get());
	} while (0);
	do {
		// declare i1 @GuraStub_LookupValue(i8*, i8*, struct.Value*, i8*)
		llvm::Type *pTypeResult = _builder.getInt1Ty();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Signal->getPointerTo());		// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// value
		typeArgs.push_back(_pStructType_Symbol->getPointerTo());		// pSymbol
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_LookupValue",
			_pModule.get());
	} while (0);
	do {
		// declare i1 @GuraStub_AssignValue(struct.Environment*, struct.Signal*, i8*, struct.Value*, i32)
		llvm::Type *pTypeResult = _builder.getInt1Ty();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Signal->getPointerTo());		// sig
		typeArgs.push_back(_pStructType_Symbol->getPointerTo());		// pSymbol
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// value
		typeArgs.push_back(_builder.getInt32Ty());						// extra
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_AssignValue",
			_pModule.get());
	} while (0);
	do {
		// declare i1 @GuraStub_AddValueList(struct.Environment*, struct.Signal*,
		//                                   struct.ValueList*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getInt1Ty();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Signal->getPointerTo());		// sig
		typeArgs.push_back(_pStructType_ValueList->getPointerTo());		// valList
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// value
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_AddValueList",
			_pModule.get());
	} while (0);
	for (const char *opName : {
				"Pos", "Neg", "Inv", "Not", "SeqInf", "Question", "Each" }) {
		// declare i1 @GuraStub_UnaryOp_*(strct.Environment*, struct.Signal*,
		//                                struct.Value*, struct.Value*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getInt1Ty();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Signal->getPointerTo());		// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueResult
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// value
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			std::string("GuraStub_UnaryOp_") + opName,
			_pModule.get());
	}
	for (const char *opName : {
				"Add", "Sub", "Mul", "Div", "Mod", "Pow",
				"Eq", "Ne", "Gt", "lt", "Ge", "Lt", "Ge", "Le", "Cmp", "Contains",
				"And", "Or", "Xor",	"Shl", "Shr", "OrOr", "AndAnd",
				"Seq", "Pair" }) {
		// declare i1 @GuraStub_BinaryOp_*(struct.Environment*, struct.Signal*,
		//                                 struct.Value*, struct.Value*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getInt1Ty();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Signal->getPointerTo());		// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueResult
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueLeft
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueRight
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			std::string("GuraStub_BinaryOp_") + opName,
			_pModule.get());
	}
	do {
		// declare i1 @GuraStub_IndexGet(struct.Environment*, struct.Signal*,
		//                               struct.ValueList*, struct.Value*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getInt1Ty();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Signal->getPointerTo());		// sig
		typeArgs.push_back(_pStructType_ValueList->getPointerTo());		// valList
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueCar
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueIdx
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_IndexGet",
			_pModule.get());
	} while (0);
	do {
		// declare i1 @GuraStub_IndexSet(struct.Environment*, struct.Signal*,
		//                               struct.Value*, struct.Value*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getInt1Ty();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Signal->getPointerTo());		// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueCar
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueIdx
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// value
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_IndexSet",
			_pModule.get());
	} while (0);
	do {
		// declare i1 @GuraStub_IndexSetByIterator(struct.Environment*, struct.Signal*,
		//                               struct.Value*, struct.Value*, struct.Iterator*)
		llvm::Type *pTypeResult = _builder.getInt1Ty();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Signal->getPointerTo());		// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueCar
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueIdx
		typeArgs.push_back(_pStructType_Iterator->getPointerTo());		// pIterator
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_IndexSetByIterator",
			_pModule.get());
	} while (0);
	do {
		// declare i1 @GuraStub_EmptyIndexGet(struct.Environment*, struct.Signal*,
		//                                    struct.Value*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getInt1Ty();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Signal->getPointerTo());		// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueResult
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueCar
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_EmptyIndexGet",
			_pModule.get());
	} while (0);
	do {
		// declare i1 @GuraStub_EmptyIndexSet(struct.Environment*, struct.Signal*,
		//                                    struct.Value*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getInt1Ty();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Signal->getPointerTo());		// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueResult
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueCar
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_EmptyIndexSet",
			_pModule.get());
	} while (0);
	do {
		// declare i1 @GuraStub_CallFunction(struct.Environment*, struct.Signal*,
		//                                   struct.Value*, struct.Value*, ...)
		llvm::Type *pTypeResult = _builder.getInt1Ty();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Signal->getPointerTo());		// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueResult
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueCar
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());		// bridgeFuncBlockParam
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());		// bridgeFuncBlock
		bool isVarArg = true;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_CallFunction",
			_pModule.get());
		//pFunction->setCallingConv(llvm::CallingConv::C);
	} while (0);
	do {
		// declare i1 @GuraStub_CreateIterator(struct.Environment*, struct.Signal*,
		//                                     struct.Value*, struct.Iterator**)
		llvm::Type *pTypeResult = _builder.getInt1Ty();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Signal->getPointerTo());		// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// value
		typeArgs.push_back(_pStructType_Iterator->getPointerTo()->getPointerTo()); // ppIterator
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_CreateIterator",
			_pModule.get());
	} while (0);
	do {
		// declare void @GuraStub_ReleaseIterator(struct.Iterator*)
		llvm::Type *pTypeResult = _builder.getVoidTy();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Iterator->getPointerTo());		// pIterator
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_ReleaseIterator",
			_pModule.get());
	} while (0);
	do {
		// declare i1 @GuraStub_NextIterator(struct.Environment*, struct.Signal*,
		//                                   struct.Iterator*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getInt1Ty();					// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Signal->getPointerTo());		// sig
		typeArgs.push_back(_pStructType_Iterator->getPointerTo());		// pIterator
		typeArgs.push_back(_pStructType_Value->getPointerTo());			// value
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_NextIterator",
			_pModule.get());
	} while (0);
	llvm::Function *pFunction = CreateBridgeFunction(env, sig, pExpr, "GuraEntry");
	if (pFunction == nullptr) return false;
	return true;
}

Value CodeGeneratorLLVM::Run(Environment &env, Signal &sig)
{
	llvm::InitializeNativeTarget();
	llvm::InitializeNativeTargetAsmPrinter();
	llvm::InitializeNativeTargetAsmParser();
	llvm::EngineBuilder engineBuilder(std::move(_pModule));
	std::string errStr;
	engineBuilder.setMArch("");
	engineBuilder.setMCPU("");
	std::vector<std::string> attrs;
	engineBuilder.setMAttrs(attrs);
	engineBuilder.setRelocationModel(llvm::Reloc::Default);
	engineBuilder.setCodeModel(llvm::CodeModel::JITDefault);
	engineBuilder.setErrorStr(&errStr);
	//engineBuilder.setEngineKind(llvm::EngineKind::Interpreter);
	engineBuilder.setEngineKind(llvm::EngineKind::JIT);
	llvm::ExecutionEngine *pExecutionEngine = engineBuilder.create();
	if (pExecutionEngine == nullptr) {
		::fprintf(stderr, "error while building execution engine\n");
		::exit(1);
	}
	pExecutionEngine->finalizeObject();
    pExecutionEngine->runStaticConstructorsDestructors(false);
	llvm::Function *pFunction_GuraEntry = pExecutionEngine->FindFunctionNamed("GuraEntry");
	if (pFunction_GuraEntry == nullptr) {
		::fprintf(stderr, "failed to find function main\n");
		::exit(1);
	}
	BridgeFunctionT bridgeFuncGuraEntry = reinterpret_cast<BridgeFunctionT>(
		pExecutionEngine->getPointerToFunction(pFunction_GuraEntry));
	Value result;
	bridgeFuncGuraEntry(env, sig, result);
    pExecutionEngine->runStaticConstructorsDestructors(true);
	return result;
}

llvm::Function *CodeGeneratorLLVM::CreateBridgeFunction(
	Environment &env, Signal &sig, const Expr *pExpr, const char *name)
{
	// define void @BridgeFunction(i8* env, i8* sig, %struct.Value* valueResult)
	llvm::Type *pTypeResult = _builder.getVoidTy();					// return
	std::vector<llvm::Type *> typeArgs;
	typeArgs.push_back(_pStructType_Environment->getPointerTo());	// env
	typeArgs.push_back(_pStructType_Signal->getPointerTo());		// sig
	typeArgs.push_back(_pStructType_Value->getPointerTo());			// valueResult
	bool isVarArg = false;
	llvm::Function *pFunction = llvm::Function::Create(
		llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
		llvm::Function::ExternalLinkage,
		name,
		_pModule.get());
	llvm::Function::arg_iterator pArg = pFunction->arg_begin();
	pArg->setName("env");
	llvm::Value *plv_env = pArg++;
	pArg->setName("sig");
	llvm::Value *plv_sig = pArg++;
	pArg->setName("valueResult");
	llvm::Value *plv_result = pArg++;
	llvm::BasicBlock *pBasicBlockSaved = _builder.GetInsertBlock();
	llvm::BasicBlock *pBasicBlockEntry =
		llvm::BasicBlock::Create(_context, "bb.Function.entry", pFunction);
	llvm::BasicBlock *pBasicBlockBody =
		llvm::BasicBlock::Create(_context, "bb.Function.body", pFunction);
	llvm::BasicBlock *pBasicBlockExit =
		llvm::BasicBlock::Create(_context, "bb.Function.exit");
	llvm::BasicBlock *pBasicBlockRelease =
		llvm::BasicBlock::Create(_context, "bb.Function.release");
	llvm::Value *plv_valueResultSaved = _plv_valueResult;
	_plv_valueResult = nullptr;
	_contextStack.push_back(new Context(plv_env, plv_sig,
										pBasicBlockEntry, pBasicBlockExit, pBasicBlockRelease));
	_builder.SetInsertPoint(pBasicBlockBody);
	if (pExpr->GenerateCode(env, sig, *this)) {
		llvm::Value *plv_valueRtn = _plv_valueResult;
		pFunction->getBasicBlockList().push_back(pBasicBlockExit);
		pFunction->getBasicBlockList().push_back(pBasicBlockRelease);
		_builder.CreateBr(pBasicBlockExit);
		_builder.SetInsertPoint(pBasicBlockEntry);
		_builder.CreateBr(pBasicBlockBody);
		_builder.SetInsertPoint(pBasicBlockExit);
		if (plv_valueRtn != nullptr) {
			std::vector<llvm::Value *> args;
			args.push_back(plv_result);
			args.push_back(plv_valueRtn);
			_builder.CreateCall(
				_pModule->getFunction("Gura_CopyValue"),
				args);
		}
		_builder.CreateBr(pBasicBlockRelease);
		_builder.SetInsertPoint(pBasicBlockRelease);
		_builder.CreateRetVoid();
		llvm::verifyFunction(*pFunction);
	} else {
		pFunction = nullptr;
	}
	delete _contextStack.back();
	_contextStack.pop_back();
	_plv_valueResult = plv_valueResultSaved;
	if (pBasicBlockSaved != nullptr) _builder.SetInsertPoint(pBasicBlockSaved);
	return pFunction;
}

bool CodeGeneratorLLVM::GenCode_Value(Environment &env, Signal &sig, const Expr_Value *pExprValue)
{
	const Value &value = pExprValue->GetValue();
	if (value.Is_number()) {
		_plv_valueResult = GenCode_AllocaValue("value");
		std::vector<llvm::Value *> args;
		args.push_back(_plv_valueResult);
		args.push_back(llvm::ConstantFP::get(_builder.getDoubleTy(), value.GetDouble()));
		_builder.CreateCall(
			_pModule->getFunction("GuraStub_CreateValue_number"),
			args);
	} else if (value.Is_string()) {
		_plv_valueResult = GenCode_AllocaValue("value");
		std::vector<llvm::Value *> args;
		args.push_back(_plv_valueResult);
		args.push_back(_builder.CreateGlobalStringPtr(value.GetString()));
		_builder.CreateCall(
			_pModule->getFunction("GuraStub_CreateValue_string"),
			args);
	} else if (value.Is_binary()) {
		const Binary &binary = value.GetBinary();
		std::string buff(binary.data(), binary.size());
		_plv_valueResult = GenCode_AllocaValue("value");
		std::vector<llvm::Value *> args;
		args.push_back(Get_env());
		args.push_back(_plv_valueResult);
		args.push_back(_builder.CreateGlobalStringPtr(buff));
		args.push_back(llvm::ConstantInt::get(_builder.getInt32Ty(), binary.size()));
		_builder.CreateCall(
			_pModule->getFunction("GuraStub_CreateValue_binary"),
			args);
	} else {
		sig.SetError(ERR_SyntaxError, "GetCode_Value()");
		return false;
	}
	return true;
}

bool CodeGeneratorLLVM::GenCode_Identifier(Environment &env, Signal &sig, const Expr_Identifier *pExpr)
{
	_plv_valueResult = GenCode_AllocaValue(std::string("value.") + pExpr->GetSymbol()->GetName());
	std::vector<llvm::Value *> args;
	args.push_back(Get_env());
	args.push_back(Get_sig());
	args.push_back(_plv_valueResult);
	args.push_back(GenCode_CastCPointerToPtr(
					   pExpr->GetSymbol(), _pStructType_Symbol->getPointerTo()));
	llvm::Value *plv_successFlag = _builder.CreateCall(
		_pModule->getFunction("GuraStub_LookupValue"),
		args, "successFlag");
	GenCode_CondBrContinueOrExit(plv_successFlag, "bb.identifier.success");
	return true;
}

bool CodeGeneratorLLVM::GenCode_AssignToIdentifier(
	Environment &env, Signal &sig,
	const Expr_Identifier *pExpr, llvm::Value *plv_valueAssigned)
{
	ULong extra = EXTRA_None;
	std::vector<llvm::Value *> args;
	args.push_back(Get_env());
	args.push_back(Get_sig());
	args.push_back(GenCode_CastCPointerToPtr(
					   pExpr->GetSymbol(), _pStructType_Symbol->getPointerTo()));
	args.push_back(plv_valueAssigned);
	args.push_back(llvm::ConstantInt::get(_builder.getInt32Ty(), extra));
	llvm::Value *plv_successFlag = _builder.CreateCall(
		_pModule->getFunction("GuraStub_AssignValue"),
		args, "successFlag");
	GenCode_CondBrContinueOrExit(plv_successFlag, "bb.assignToIdentifier.success");
	return true;
}

bool CodeGeneratorLLVM::GenCode_Suffixed(Environment &env, Signal &sig, const Expr_Suffixed *pExpr)
{
	return true;
}

bool CodeGeneratorLLVM::GenCode_Root(Environment &env, Signal &sig, const Expr_Root *pExpr)
{
	pExpr->GetExprOwner().GenerateCode(env, sig, *this);
	return true;
}

bool CodeGeneratorLLVM::GenCode_Block(Environment &env, Signal &sig, const Expr_Block *pExpr)
{
	pExpr->GetExprOwner().GenerateCode(env, sig, *this);
	return true;
}

bool CodeGeneratorLLVM::GenCode_Lister(Environment &env, Signal &sig, const Expr_Lister *pExpr)
{
	llvm::Value *plv_valueResult = GenCode_AllocaValue("value");
	std::vector<llvm::Value *> args;
	args.push_back(Get_env());
	args.push_back(plv_valueResult);
	llvm::Value *plv_valList = _builder.CreateCall(
		_pModule->getFunction("GuraStub_CreateValueList"),
		args, "valList");
	foreach_const (ExprOwner, ppExpr, pExpr->GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		if (!pExpr->GenerateCode(env, sig, *this)) return false;
		llvm::Value *plv_valueElem = _plv_valueResult;
		std::vector<llvm::Value *> args;
		args.push_back(Get_env());
		args.push_back(Get_sig());
		args.push_back(plv_valList);
		args.push_back(plv_valueElem);
		llvm::Value *plv_successFlag = _builder.CreateCall(
			_pModule->getFunction("GuraStub_AddValueList"),
			args, "successFlag");
		GenCode_CondBrContinueOrExit(plv_successFlag, "bb.lister.continue");
	}
	_plv_valueResult = plv_valueResult;
	return true;
}

bool CodeGeneratorLLVM::GenCode_AssignToLister(
	Environment &env, Signal &sig,
	const Expr_Lister *pExpr, llvm::Value *plv_valueAssigned, bool alwaysIterableFlag)
{
	if (pExpr->GetExprOwner().empty()) {
		// .....
	}
	llvm::BasicBlock *pBasicBlockDone =
		llvm::BasicBlock::Create(_context, "bb.assignToLister.done");
	if (!alwaysIterableFlag) {
		llvm::BasicBlock *pBasicBlockScalar =
			llvm::BasicBlock::Create(_context, "bb.assignToLister.scalar");
		llvm::BasicBlock *pBasicBlockIterable =
			llvm::BasicBlock::Create(_context, "bb.assignToLister.iterable");
		_builder.CreateCondBr(
			GenCode_CheckValTypeListOrIterator(plv_valueAssigned),
			pBasicBlockIterable, pBasicBlockScalar);
		GetFunctionCur()->getBasicBlockList().push_back(pBasicBlockScalar);
		_builder.SetInsertPoint(pBasicBlockScalar);
		// [i] = scalar
		// [i, j, k] = scalar
		foreach_const (ExprOwner, ppExprElem, pExpr->GetExprOwner()) {
			const Expr *pExprElem = *ppExprElem;
			if (pExprElem->IsIdentifier()) {
				const Expr_Identifier *pExprElemEx =
					dynamic_cast<const Expr_Identifier *>(pExprElem);
				if (!GenCode_AssignToIdentifier(
						env, sig, pExprElemEx, plv_valueAssigned)) return false;
			} else if (pExprElem->IsIndexer()) {
				const Expr_Indexer *pExprElemEx =
					dynamic_cast<const Expr_Indexer *>(pExprElem);
				if (!GenCode_AssignToIndexer(
						env, sig, pExprElemEx, plv_valueAssigned, false)) return false;
			} else if (pExprElem->IsMember()) {
				const Expr_Member *pExprElemEx =
					dynamic_cast<const Expr_Member *>(pExprElem);
				if (!GenCode_AssignToMember(
						env, sig, pExprElemEx, plv_valueAssigned)) return false;
			} else {
				sig.SetError(ERR_SyntaxError, "invalid element in lister assignment");
				return false;
			}
		}
		_builder.CreateBr(pBasicBlockDone);
		GetFunctionCur()->getBasicBlockList().push_back(pBasicBlockIterable);
		_builder.SetInsertPoint(pBasicBlockIterable);
	}
	do {
		// [i, j, k] = iterable
		llvm::BasicBlock *pBasicBlockDone =
			llvm::BasicBlock::Create(_context, "bb.assignToLister.iterable.done");
		llvm::Value *plv_pIteratorAssigned = GenCode_CreateIterator(
			plv_valueAssigned, "ppIteratorAssigned", "pIteratorAssigned");
		llvm::Value *plv_valueAssignedElem = GenCode_AllocaValue("valueAssigned");
		do {
			Restorer<llvm::BasicBlock *> restorer(_pBasicBlockExit, pBasicBlockDone);
			foreach_const (ExprOwner, ppExprElem, pExpr->GetExprOwner()) {
				const Expr *pExprElem = *ppExprElem;
				std::vector<llvm::Value *> args;
				args.push_back(Get_env());
				args.push_back(Get_sig());
				args.push_back(plv_pIteratorAssigned);
				args.push_back(plv_valueAssignedElem);
				llvm::Value *plv_continueFlag = _builder.CreateCall(
					_pModule->getFunction("GuraStub_NextIterator"),
					args, "continueFlag");
				GenCode_CondBrContinueOrExit(
					plv_continueFlag, "bb.assignToLister.iterable.continue");
				if (pExprElem->IsIdentifier()) {
					const Expr_Identifier *pExprElemEx =
						dynamic_cast<const Expr_Identifier *>(pExprElem);
					if (!GenCode_AssignToIdentifier(
							env, sig, pExprElemEx, plv_valueAssignedElem)) return false;
				} else if (pExprElem->IsIndexer()) {
					const Expr_Indexer *pExprElemEx =
						dynamic_cast<const Expr_Indexer *>(pExprElem);
					if (!GenCode_AssignToIndexer(
							env, sig, pExprElemEx, plv_valueAssignedElem, false)) return false;
				} else if (pExprElem->IsMember()) {
					const Expr_Member *pExprElemEx =
						dynamic_cast<const Expr_Member *>(pExprElem);
					if (!GenCode_AssignToMember(
							env, sig, pExprElemEx, plv_valueAssignedElem)) return false;
				} else {
					sig.SetError(ERR_SyntaxError, "invalid element in lister assignment");
					return false;
				}
			}
		} while (0);
		_builder.CreateBr(pBasicBlockDone);
		GetFunctionCur()->getBasicBlockList().push_back(pBasicBlockDone);
		_builder.SetInsertPoint(pBasicBlockDone);
		GenCode_ReleaseIterator(plv_pIteratorAssigned);
		GenCode_CondBrExitWhenSignalled("bb.assignToLister.continue");
	} while (0);
	_builder.CreateBr(pBasicBlockDone);
	GetFunctionCur()->getBasicBlockList().push_back(pBasicBlockDone);
	_builder.SetInsertPoint(pBasicBlockDone);
	_plv_valueResult = plv_valueAssigned;
	return true;
}

bool CodeGeneratorLLVM::GenCode_Iterer(Environment &env, Signal &sig, const Expr_Iterer *pExpr)
{
	pExpr->GetExprOwner().GenerateCode(env, sig, *this);
	return true;
}

bool CodeGeneratorLLVM::GenCode_Indexer(Environment &env, Signal &sig, const Expr_Indexer *pExpr)
{
	if (!pExpr->GetCar()->GenerateCode(env, sig, *this)) return false;
	llvm::Value *plv_valueCar = _plv_valueResult;
	llvm::Value *plv_valueResult = GenCode_AllocaValue("value");
	if (pExpr->GetExprOwner().empty()) {
		std::vector<llvm::Value *> args;
		args.push_back(Get_env());
		args.push_back(Get_sig());
		args.push_back(plv_valueResult);
		args.push_back(plv_valueCar);
		llvm::Value *plv_successFlag = _builder.CreateCall(
			_pModule->getFunction("GuraStub_EmptyIndexGet"),
			args, "successFlag");
		GenCode_CondBrContinueOrExit(plv_successFlag, "bb.indexer.continue");
		_plv_valueResult = plv_valueResult;
		return true;
	}
	std::vector<llvm::Value *> args;
	args.push_back(Get_env());
	args.push_back(plv_valueResult);
	llvm::Value *plv_valList = _builder.CreateCall(
		_pModule->getFunction("GuraStub_CreateValueList"),
		args, "valList");
	foreach_const (ExprOwner, ppExprIdx, pExpr->GetExprOwner()) {
		const Expr *pExprIdx = *ppExprIdx;
		if (!pExprIdx->GenerateCode(env, sig, *this)) return false;
		llvm::Value *plv_valueIdx = _plv_valueResult;
		std::vector<llvm::Value *> args;
		args.push_back(Get_env());
		args.push_back(Get_sig());
		args.push_back(plv_valList);
		args.push_back(plv_valueCar);
		args.push_back(plv_valueIdx);
		llvm::Value *plv_successFlag = _builder.CreateCall(
			_pModule->getFunction("GuraStub_IndexGet"),
			args, "successFlag");
		GenCode_CondBrContinueOrExit(plv_successFlag, "bb.indexer.continue");
	}
	_plv_valueResult = plv_valueResult;
	return true;
}

bool CodeGeneratorLLVM::GenCode_AssignToIndexer(
	Environment &env, Signal &sig,
	const Expr_Indexer *pExpr, llvm::Value *plv_valueAssigned, bool alwaysIterableFlag)
{
	if (!pExpr->GetCar()->GenerateCode(env, sig, *this)) return false;
	llvm::Value *plv_valueCar = _plv_valueResult;
	if (pExpr->GetExprOwner().empty()) {
		std::vector<llvm::Value *> args;
		args.push_back(Get_env());
		args.push_back(Get_sig());
		args.push_back(plv_valueCar);
		args.push_back(plv_valueAssigned);
		llvm::Value *plv_successFlag = _builder.CreateCall(
			_pModule->getFunction("GuraStub_EmptyIndexSet"),
			args, "successFlag");
		GenCode_CondBrContinueOrExit(plv_successFlag, "bb.assignToIndexer.continue");
		_plv_valueResult = plv_valueAssigned;
		return true;
	}
	llvm::BasicBlock *pBasicBlockDone =
		llvm::BasicBlock::Create(_context, "bb.assignToIndexer.done");
	if (!alwaysIterableFlag) {
		llvm::BasicBlock *pBasicBlockScalar =
			llvm::BasicBlock::Create(_context, "bb.assignToIndexer.scalar");
		llvm::BasicBlock *pBasicBlockIterable =
			llvm::BasicBlock::Create(_context, "bb.assignToIndexer.iterable");
		_builder.CreateCondBr(
			GenCode_CheckValTypeListOrIterator(plv_valueAssigned),
			pBasicBlockIterable, pBasicBlockScalar);
		GetFunctionCur()->getBasicBlockList().push_back(pBasicBlockScalar);
		_builder.SetInsertPoint(pBasicBlockScalar);
		do {
			// tgt[i] = scalar
			// tgt[i, j, k] = scalar
			foreach_const (ExprOwner, ppExprIdx, pExpr->GetExprOwner()) {
				const Expr *pExprIdx = *ppExprIdx;
				if (!pExprIdx->GenerateCode(env, sig, *this)) return false;
				llvm::Value *plv_valueIdx = _plv_valueResult;
				std::vector<llvm::Value *> args;
				args.push_back(Get_env());
				args.push_back(Get_sig());
				args.push_back(plv_valueCar);
				args.push_back(plv_valueIdx);
				args.push_back(plv_valueAssigned);
				llvm::Value *plv_successFlag = _builder.CreateCall(
					_pModule->getFunction("GuraStub_IndexSet"),
					args, "successFlag");
				GenCode_CondBrContinueOrExit(plv_successFlag, "bb.assignToIndexer.continue");
			}
		} while (0);
		_builder.CreateBr(pBasicBlockDone);
		GetFunctionCur()->getBasicBlockList().push_back(pBasicBlockIterable);
		_builder.SetInsertPoint(pBasicBlockIterable);
	}
	if (pExpr->GetExprOwner().size() == 1) {
		// tgt[i] = iterable
		const Expr *pExprIdx = pExpr->GetExprOwner().front();
		if (!pExprIdx->GenerateCode(env, sig, *this)) return false;
		llvm::Value *plv_valueIdx = _plv_valueResult;
		std::vector<llvm::Value *> args;
		args.push_back(Get_env());
		args.push_back(Get_sig());
		args.push_back(plv_valueCar);
		args.push_back(plv_valueIdx);
		args.push_back(plv_valueAssigned);
		llvm::Value *plv_successFlag = _builder.CreateCall(
			_pModule->getFunction("GuraStub_IndexSet"),
			args, "successFlag");
		GenCode_CondBrContinueOrExit(plv_successFlag, "bb.assignToIndexer.continue");
	} else {
		// tgt[i, j, k] = iterable
		llvm::BasicBlock *pBasicBlockDone =
			llvm::BasicBlock::Create(_context, "bb.assignToIndexer.iterable.done");
		llvm::Value *plv_pIteratorAssigned = GenCode_CreateIterator(
			plv_valueAssigned, "ppIteratorAssigned", "pIteratorAssigned");
		do {
			Restorer<llvm::BasicBlock *> restorer(_pBasicBlockExit, pBasicBlockDone);
			foreach_const (ExprOwner, ppExprIdx, pExpr->GetExprOwner()) {
				const Expr *pExprIdx = *ppExprIdx;
				if (!pExprIdx->GenerateCode(env, sig, *this)) return false;
				llvm::Value *plv_valueIdx = _plv_valueResult;
				std::vector<llvm::Value *> args;
				args.push_back(Get_env());
				args.push_back(Get_sig());
				args.push_back(plv_valueCar);
				args.push_back(plv_valueIdx);
				args.push_back(plv_pIteratorAssigned);
				llvm::Value *plv_continueFlag = _builder.CreateCall(
					_pModule->getFunction("GuraStub_IndexSetByIterator"),
					args, "continueFlag");
				GenCode_CondBrContinueOrExit(
					plv_continueFlag, "bb.assignToIndexer.iterable.continue");
			}
		} while (0);
		_builder.CreateBr(pBasicBlockDone);
		GetFunctionCur()->getBasicBlockList().push_back(pBasicBlockDone);
		_builder.SetInsertPoint(pBasicBlockDone);
		GenCode_ReleaseIterator(plv_pIteratorAssigned);
		GenCode_CondBrExitWhenSignalled("bb.assignToIndexer.continue");
	}
	_builder.CreateBr(pBasicBlockDone);
	GetFunctionCur()->getBasicBlockList().push_back(pBasicBlockDone);
	_builder.SetInsertPoint(pBasicBlockDone);
	_plv_valueResult = plv_valueAssigned;
	return true;
}

bool CodeGeneratorLLVM::GenCode_Caller(Environment &env, Signal &sig, const Expr_Caller *pExpr)
{
	if (pExpr->GetCar()->IsMember()) {
		
	} else {
		llvm::Value *plv_valueResult = GenCode_AllocaValue("value");
		if (!pExpr->GetCar()->GenerateCode(env, sig, *this)) return false;
		llvm::Value *plv_valueCar = _plv_valueResult;
		std::vector<llvm::Value *> args;
		args.push_back(Get_env());
		args.push_back(Get_sig());
		args.push_back(plv_valueResult);
		args.push_back(plv_valueCar);
		if (pExpr->GetBlock() == nullptr) {
			args.push_back(llvm::ConstantPointerNull::get(_builder.getInt8Ty()->getPointerTo()));
			args.push_back(llvm::ConstantPointerNull::get(_builder.getInt8Ty()->getPointerTo()));
		} else {
			args.push_back(llvm::ConstantPointerNull::get(_builder.getInt8Ty()->getPointerTo()));
			llvm::Function *pFunction = CreateBridgeFunction(
				env, sig, pExpr->GetBlock(), "Block");
			if (pFunction == nullptr) return false;
			args.push_back(llvm::ConstantExpr::getBitCast(
							   pFunction, _builder.getInt8Ty()->getPointerTo()));
		}
		foreach_const (ExprOwner, ppExprArg, pExpr->GetExprOwner()) {
			const Expr *pExprArg = *ppExprArg;
			llvm::Function *pFunction = CreateBridgeFunction(env, sig, pExprArg, "Arg");
			if (pFunction == nullptr) return false;
			args.push_back(llvm::ConstantExpr::getBitCast(
							   pFunction, _builder.getInt8Ty()->getPointerTo()));
		}
		args.push_back(llvm::ConstantPointerNull::get(_pStructType_Value->getPointerTo()));
		llvm::Value *plv_successFlag = _builder.CreateCall(
			_pModule->getFunction("GuraStub_CallFunction"),
			args, "successFlag");
		GenCode_CondBrContinueOrExit(plv_successFlag, "bb.caller.continue");
		_plv_valueResult = plv_valueResult;
	}
	return true;
}

bool CodeGeneratorLLVM::GenCode_AssignToCaller(
	Environment &env, Signal &sig,
	const Expr_Caller *pExpr, const Expr *pExprAssigned)
{
	llvm::Function *pFunction = CreateBridgeFunction(env, sig, pExprAssigned, "FunctionBody");
	if (pFunction == nullptr) return false;
	_plv_valueResult = nullptr;
	return true;
}

bool CodeGeneratorLLVM::GenCode_UnaryOp(Environment &env, Signal &sig, const Expr_UnaryOp *pExpr)
{
	_plv_valueResult = GenCode_CallUnaryOp(env, sig, pExpr->GetOperator(), pExpr->GetChild());
	return _plv_valueResult != nullptr;
}

bool CodeGeneratorLLVM::GenCode_BinaryOp(Environment &env, Signal &sig, const Expr_BinaryOp *pExpr)
{
	_plv_valueResult = GenCode_CallBinaryOp(env, sig, pExpr->GetOperator(),
											pExpr->GetLeft(), pExpr->GetRight());
	return _plv_valueResult != nullptr;
}

bool CodeGeneratorLLVM::GenCode_Quote(Environment &env, Signal &sig, const Expr_Quote *pExpr)
{
	::printf("Quote\n");
	if (pExpr->GetChild()->IsIdentifier()) {
		//const Expr_Identifier *pExprIdentifier =
		//				dynamic_cast<const Expr_Identifier *>(GetChild());
		
	} else {
		
	}
	return true;
}

bool CodeGeneratorLLVM::GenCode_Assign(Environment &env, Signal &sig, const Expr_Assign *pExpr)
{
	if (pExpr->GetLeft()->IsCaller()) {
		if (pExpr->GetOperatorToApply() != nullptr) {
			sig.SetError(ERR_SyntaxError, "invalid operation");
			return false;
		}
		const Expr_Caller *pExprEx = dynamic_cast<const Expr_Caller *>(pExpr->GetLeft());
		if (!GenCode_AssignToCaller(env, sig, pExprEx, pExpr->GetRight())) return false;
		return true;
	}
	bool alwaysIterableFlag = false;
	llvm::Value *plv_valueAssigned = nullptr;
	if (pExpr->GetOperatorToApply() == nullptr) {
		if (!pExpr->GetRight()->GenerateCode(env, sig, *this)) return false;
		plv_valueAssigned = _plv_valueResult;
		alwaysIterableFlag = pExpr->GetRight()->IsLister() || pExpr->GetRight()->IsIterer();
	} else {
		plv_valueAssigned = GenCode_CallBinaryOp(env, sig, pExpr->GetOperatorToApply(),
												 pExpr->GetLeft(), pExpr->GetRight());
		if (plv_valueAssigned == nullptr) return false;
		alwaysIterableFlag = true;
	}
	if (pExpr->GetLeft()->IsIdentifier()) {
		const Expr_Identifier *pExprEx = dynamic_cast<const Expr_Identifier *>(pExpr->GetLeft());
		if (!GenCode_AssignToIdentifier(env, sig, pExprEx, plv_valueAssigned)) return false;
	} else if (pExpr->GetLeft()->IsIndexer()) {
		const Expr_Indexer *pExprEx = dynamic_cast<const Expr_Indexer *>(pExpr->GetLeft());
		if (!GenCode_AssignToIndexer(env, sig,
									 pExprEx, plv_valueAssigned, alwaysIterableFlag)) return false;
	} else if (pExpr->GetLeft()->IsLister()) {
		const Expr_Lister *pExprEx = dynamic_cast<const Expr_Lister *>(pExpr->GetLeft());
		if (!GenCode_AssignToLister(env, sig,
									pExprEx, plv_valueAssigned, alwaysIterableFlag)) return false;
	} else if (pExpr->GetLeft()->IsMember()) {
		const Expr_Member *pExprEx = dynamic_cast<const Expr_Member *>(pExpr->GetLeft());
		if (!GenCode_AssignToMember(env, sig, pExprEx, plv_valueAssigned)) return false;
	}
	_plv_valueResult = plv_valueAssigned;
	return true;
}

bool CodeGeneratorLLVM::GenCode_Member(Environment &env, Signal &sig, const Expr_Member *pExpr)
{
	::printf("Member\n");
	return true;
}

bool CodeGeneratorLLVM::GenCode_AssignToMember(
	Environment &env, Signal &sig,
	const Expr_Member *pExpr, llvm::Value *plv_valueAssigned)
{
	return true;
}

llvm::Value *CodeGeneratorLLVM::GenCode_CallUnaryOp(
	Environment &env, Signal &sig, const Operator *pOperator, const Expr *pExprChild)
{
	if (!pExprChild->GenerateCode(env, sig, *this)) return nullptr;
	llvm::Value *plv_valueChild = _plv_valueResult;
	llvm::Value *plv_valueResult = GenCode_AllocaValue("value");
	std::vector<llvm::Value *> args;
	args.push_back(Get_env());
	args.push_back(Get_sig());
	args.push_back(plv_valueResult);
	args.push_back(plv_valueChild);
	llvm::Value *plv_successFlag = _builder.CreateCall(
		_pModule->getFunction(std::string("GuraStub_UnaryOp_") + pOperator->GetName()),
		args, "successFlag");
	GenCode_CondBrContinueOrExit(plv_successFlag, "bb.callUnaryOp.success");
	return plv_valueResult;
}

llvm::Value *CodeGeneratorLLVM::GenCode_CallBinaryOp(
	Environment &env, Signal &sig, const Operator *pOperator,
	const Expr *pExprLeft, const Expr *pExprRight)
{
	if (!pExprLeft->GenerateCode(env, sig, *this)) return nullptr;
	llvm::Value *plv_valueLeft = _plv_valueResult;
	if (!pExprRight->GenerateCode(env, sig, *this)) return nullptr;
	llvm::Value *plv_valueRight = _plv_valueResult;
	llvm::Value *plv_valueResult = GenCode_AllocaValue("value");
	std::vector<llvm::Value *> args;
	args.push_back(Get_env());
	args.push_back(Get_sig());
	args.push_back(plv_valueResult);
	args.push_back(plv_valueLeft);
	args.push_back(plv_valueRight);
	llvm::Value *plv_successFlag = _builder.CreateCall(
		_pModule->getFunction(std::string("GuraStub_BinaryOp_") + pOperator->GetName()),
		args, "successFlag");
	GenCode_CondBrContinueOrExit(plv_successFlag, "bb.callBinaryOp.success");
	return plv_valueResult;
}

llvm::Value *CodeGeneratorLLVM::GenCode_CheckValType(llvm::Value *plv_value, UShort valType)
{
	llvm::Value *plv_valType = _builder.CreateLoad(
		_builder.CreatePointerCast(
			plv_value, _builder.getInt16Ty()->getPointerTo(), "valType"));
	return _builder.CreateICmpEQ(
		llvm::ConstantInt::get(_builder.getInt16Ty(), valType), plv_valType);
}

llvm::Value *CodeGeneratorLLVM::GenCode_CheckValTypeListOrIterator(llvm::Value *plv_value)
{
	llvm::Value *plv_valType = _builder.CreateLoad(
		_builder.CreatePointerCast(
			plv_value, _builder.getInt16Ty()->getPointerTo(), "valType"));
	return _builder.CreateOr(
		_builder.CreateICmpEQ(
			llvm::ConstantInt::get(_builder.getInt16Ty(), VTYPE_list),
			plv_valType),
		_builder.CreateICmpEQ(
			llvm::ConstantInt::get(_builder.getInt16Ty(), VTYPE_iterator),
			plv_valType),
		"valueIsListOrIteratorFlag");
}

void CodeGeneratorLLVM::GenCode_CondBrExitWhenSignalled(const llvm::Twine &nameForContinueBB)
{
	GenCode_CondBrContinueOrExit(
		_builder.CreateICmpULE(
			_builder.CreateLoad(_builder.CreateStructGEP(Get_sig(), 0), "sigType"),
			llvm::ConstantInt::get(_builder.getInt32Ty(), SIGTYPE_ErrorSuspended)),
		nameForContinueBB);
}

void CodeGeneratorLLVM::GenCode_CondBrContinueOrExit(
	llvm::Value *plv_successFlag, const llvm::Twine &nameForContinueBB)
{
	llvm::BasicBlock *pBasicBlockContinue =
		llvm::BasicBlock::Create(_context, nameForContinueBB, GetFunctionCur());
	_builder.CreateCondBr(plv_successFlag, pBasicBlockContinue, GetBasicBlockExit());
	_builder.SetInsertPoint(pBasicBlockContinue);
}

llvm::Value *CodeGeneratorLLVM::GenCode_AllocaValue(const llvm::Twine &name, bool initFlag)
{
	llvm::BasicBlock *pBasicBlockSaved = _builder.GetInsertBlock();
	_builder.SetInsertPoint(GetBasicBlockEntry());
	llvm::Value *plv_value = _builder.CreateAlloca(_pStructType_Value, nullptr, name);
	if (initFlag) {
		_builder.CreateStore(
			llvm::ConstantInt::get(_builder.getInt32Ty(), 0x00000000),
			_builder.CreatePointerCast(plv_value, _builder.getInt32Ty()->getPointerTo(), "valHeader"));
	}
	_builder.SetInsertPoint(GetBasicBlockRelease());
	do {
		std::vector<llvm::Value *> args;
		args.push_back(plv_value);
		_builder.CreateCall(
			_pModule->getFunction("Gura_ReleaseValue"),
			args);
	} while (0);
	_builder.SetInsertPoint(pBasicBlockSaved);
	return plv_value;
}

llvm::Value *CodeGeneratorLLVM::GenCode_CastCPointerToPtr(const void *p, llvm::Type *pType)
{
	return llvm::ConstantExpr::getIntToPtr(
		llvm::ConstantInt::get(_builder.getInt64Ty(), reinterpret_cast<uint64_t>(p)),
		pType);
}

llvm::Value *CodeGeneratorLLVM::GenCode_CreateIterator(
	llvm::Value *plv_value, const llvm::Twine &nameForPP, const llvm::Twine &nameForP)
{
	llvm::Value *plv_ppIterator = _builder.CreateAlloca(
		_pStructType_Iterator->getPointerTo(), nullptr, nameForPP);
	std::vector<llvm::Value *> args;
	args.push_back(Get_env());
	args.push_back(Get_sig());
	args.push_back(plv_value);
	args.push_back(plv_ppIterator);
	llvm::Value *plv_successFlag = _builder.CreateCall(
		_pModule->getFunction("GuraStub_CreateIterator"),
		args, "successFlag");
	GenCode_CondBrContinueOrExit(plv_successFlag, "bb.createIterator.success");
	return _builder.CreateLoad(plv_ppIterator, nameForP);
}

llvm::Value *CodeGeneratorLLVM::GenCode_ReleaseIterator(llvm::Value *plv_pIterator)
{
	std::vector<llvm::Value *> args;
	args.push_back(plv_pIterator);
	_builder.CreateCall(
		_pModule->getFunction("GuraStub_ReleaseIterator"),
		args);
}

//-----------------------------------------------------------------------------
// Gura module functions: llvm
//-----------------------------------------------------------------------------
// llvm.gencode() {block}
Gura_DeclareFunction(gencode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementFunction(gencode)
{
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	CodeGeneratorLLVM codeGeneratorLLVM;
	codeGeneratorLLVM.Generate(env, sig, pExprBlock);
	codeGeneratorLLVM.GetModule()->dump();
	return codeGeneratorLLVM.Run(env, sig);
}

// llvm.test()
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(test)
{
	const char *fileName = "sample.ll";
	llvm::LLVMContext &context = llvm::getGlobalContext();
	llvm::SMDiagnostic err;
	std::unique_ptr<llvm::Module> pModule(llvm::parseIRFile(fileName, err, context));
	if (pModule == nullptr) {
		::fprintf(stderr, "error while createing module\n");
		::exit(1);
	}
	pModule->dump();
	return Value::Null;
}

// Module entry
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(gencode);
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(llvm, llvm)

Gura_RegisterModule(llvm)
