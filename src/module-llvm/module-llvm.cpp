//-----------------------------------------------------------------------------
// Gura module: llvm
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(llvm)

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

extern "C" bool GuraStub_IndexSetIterator(
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
		llvm::Value *_pValue_env;
		llvm::Value *_pValue_sig;
		llvm::BasicBlock *_pBasicBlockEntry;
		llvm::BasicBlock *_pBasicBlockExit;
		llvm::BasicBlock *_pBasicBlockRelease;
	public:
		inline Context(llvm::Value *pValue_env, llvm::Value *pValue_sig,
					   llvm::BasicBlock *pBasicBlockEntry, llvm::BasicBlock *pBasicBlockExit,
					   llvm::BasicBlock *pBasicBlockRelease) :
			_pValue_env(pValue_env), _pValue_sig(pValue_sig),
			_pBasicBlockEntry(pBasicBlockEntry), _pBasicBlockExit(pBasicBlockExit),
			_pBasicBlockRelease(pBasicBlockRelease) {}
		inline llvm::Value *GetValue_env() { return _pValue_env; }
		inline llvm::Value *GetValue_sig() { return _pValue_sig; }
		inline llvm::BasicBlock *GetBasicBlockEntry() { return _pBasicBlockEntry; }
		inline llvm::BasicBlock *GetBasicBlockExit() { return _pBasicBlockExit; }
		inline llvm::BasicBlock *GetBasicBlockRelease() { return _pBasicBlockRelease; }
	};
	typedef std::vector<Context *> ContextStack;
private:
	llvm::LLVMContext &_context;
	std::unique_ptr<llvm::Module> _pModule;
	llvm::IRBuilder<> _builder;
	llvm::Value *_pValueResult;
	ContextStack _contextStack;
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
	inline llvm::Function *GetFunctionCur() {
		return _builder.GetInsertBlock()->getParent();
	}
	inline llvm::Value *GetValue_env() { return _contextStack.back()->GetValue_env(); }
	inline llvm::Value *GetValue_sig() { return _contextStack.back()->GetValue_sig(); }
	inline llvm::BasicBlock *GetBasicBlockEntry() {
		return _contextStack.back()->GetBasicBlockEntry();
	}
	inline llvm::BasicBlock *GetBasicBlockExit() {
		return _contextStack.back()->GetBasicBlockExit();
	}
	inline llvm::BasicBlock *GetBasicBlockRelease() {
		return _contextStack.back()->GetBasicBlockRelease();
	}
public:
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
									const Expr_Identifier *pExpr, llvm::Value *pValueAssigned);
	bool GenCode_AssignToLister(Environment &env, Signal &sig,
								const Expr_Lister *pExpr, llvm::Value *pValueAssigned);
	bool GenCode_AssignToIndexer(Environment &env, Signal &sig,
								 const Expr_Indexer *pExpr, llvm::Value *pValueAssigned);
	bool GenCode_AssignToCaller(Environment &env, Signal &sig,
								const Expr_Caller *pExpr, const Expr *pExprAssigned);
	bool GenCode_AssignToMember(Environment &env, Signal &sig,
								const Expr_Member *pExpr, llvm::Value *pValueAssigned);
private:
	void CreateCondBrErrorExit();
	void CreateCondBrErrorExit(llvm::Value *pValue_successFlag);
	llvm::Value *CreateCheckValType(llvm::Value *pValue, UShort valType);
	llvm::Value *CreateCheckValTypeListOrIterator(llvm::Value *pValue);
	llvm::Value *CreateBinaryOp(
		Environment &env, Signal &sig, const Operator *pOperator,
		const Expr *pExprLeft, const Expr *pExprRight);
	llvm::Value *CreateUnaryOp(
		Environment &env, Signal &sig, const Operator *pOperator, const Expr *pExprChild);
	llvm::Value *CreateAllocaValue(const llvm::Twine &name, bool initFlag = true);
	llvm::Value *GetCPointerToPtr(const void *p, llvm::Type *pType);
	llvm::Function *CreateBridgeFunction(Environment &env, Signal &sig,
										 const Expr *pExpr, const char *name);
};

CodeGeneratorLLVM::CodeGeneratorLLVM() :
	_context(llvm::getGlobalContext()),	_builder(llvm::getGlobalContext()),
	_pValueResult(nullptr), _pStructType_Value(nullptr),
	_pStructType_ValueList(nullptr), _pStructType_Signal(nullptr),
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
		// declare i1 @GuraStub_IndexSetIterator(struct.Environment*, struct.Signal*,
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
			"GuraStub_IndexSetIterator",
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

bool CodeGeneratorLLVM::GenCode_Value(Environment &env, Signal &sig, const Expr_Value *pExprValue)
{
	const Value &value = pExprValue->GetValue();
	if (value.Is_number()) {
		_pValueResult = CreateAllocaValue("value");
		std::vector<llvm::Value *> args;
		args.push_back(_pValueResult);
		args.push_back(llvm::ConstantFP::get(_builder.getDoubleTy(), value.GetDouble()));
		_builder.CreateCall(
			_pModule->getFunction("GuraStub_CreateValue_number"),
			args);
	} else if (value.Is_string()) {
		_pValueResult = CreateAllocaValue("value");
		std::vector<llvm::Value *> args;
		args.push_back(_pValueResult);
		args.push_back(_builder.CreateGlobalStringPtr(value.GetString()));
		_builder.CreateCall(
			_pModule->getFunction("GuraStub_CreateValue_string"),
			args);
	} else if (value.Is_binary()) {
		const Binary &binary = value.GetBinary();
		std::string buff(binary.data(), binary.size());
		_pValueResult = CreateAllocaValue("value");
		std::vector<llvm::Value *> args;
		args.push_back(GetValue_env());
		args.push_back(_pValueResult);
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
	_pValueResult = CreateAllocaValue(std::string("value.") + pExpr->GetSymbol()->GetName());
	std::vector<llvm::Value *> args;
	args.push_back(GetValue_env());
	args.push_back(GetValue_sig());
	args.push_back(_pValueResult);
	args.push_back(GetCPointerToPtr(pExpr->GetSymbol(), _pStructType_Symbol->getPointerTo()));
	llvm::Value *pValue_successFlag = _builder.CreateCall(
		_pModule->getFunction("GuraStub_LookupValue"),
		args, "successFlag");
	CreateCondBrErrorExit(pValue_successFlag);
	return true;
}

bool CodeGeneratorLLVM::GenCode_AssignToIdentifier(
	Environment &env, Signal &sig,
	const Expr_Identifier *pExpr, llvm::Value *pValueAssigned)
{
	ULong extra = EXTRA_None;
	std::vector<llvm::Value *> args;
	args.push_back(GetValue_env());
	args.push_back(GetValue_sig());
	args.push_back(GetCPointerToPtr(
					   pExpr->GetSymbol(), _pStructType_Symbol->getPointerTo()));
	args.push_back(pValueAssigned);
	args.push_back(llvm::ConstantInt::get(_builder.getInt32Ty(), extra));
	llvm::Value *pValue_successFlag = _builder.CreateCall(
		_pModule->getFunction("GuraStub_AssignValue"),
		args, "successFlag");
	CreateCondBrErrorExit(pValue_successFlag);
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
	llvm::Value *pValueResult = CreateAllocaValue("value");
	std::vector<llvm::Value *> args;
	args.push_back(GetValue_env());
	args.push_back(pValueResult);
	llvm::Value *pValue_valList = _builder.CreateCall(
		_pModule->getFunction("GuraStub_CreateValueList"),
		args, "valList");
	foreach_const (ExprOwner, ppExpr, pExpr->GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		if (!pExpr->GenerateCode(env, sig, *this)) return false;
		llvm::Value *pValueElem = _pValueResult;
		std::vector<llvm::Value *> args;
		args.push_back(GetValue_env());
		args.push_back(GetValue_sig());
		args.push_back(pValue_valList);
		args.push_back(pValueElem);
		llvm::Value *pValue_successFlag = _builder.CreateCall(
			_pModule->getFunction("GuraStub_AddValueList"),
			args, "successFlag");
		CreateCondBrErrorExit(pValue_successFlag);
	}
	_pValueResult = pValueResult;
	return true;
}

bool CodeGeneratorLLVM::GenCode_AssignToLister(
	Environment &env, Signal &sig,
	const Expr_Lister *pExpr, llvm::Value *pValueAssigned)
{
	foreach_const (ExprOwner, ppExprElem, pExpr->GetExprOwner()) {
		const Expr *pExprElem = *ppExprElem;
		if (pExprElem->IsIdentifier()) {
			const Expr_Identifier *pExprElemEx = dynamic_cast<const Expr_Identifier *>(pExprElem);
			if (!GenCode_AssignToIdentifier(env, sig, pExprElemEx, pValueAssigned)) return false;
		} else if (pExprElem->IsIndexer()) {
			const Expr_Indexer *pExprElemEx = dynamic_cast<const Expr_Indexer *>(pExprElem);
			if (!GenCode_AssignToIndexer(env, sig, pExprElemEx, pValueAssigned)) return false;
		} else if (pExprElem->IsMember()) {
			const Expr_Member *pExprElemEx = dynamic_cast<const Expr_Member *>(pExprElem);
			if (!GenCode_AssignToMember(env, sig, pExprElemEx, pValueAssigned)) return false;
		}
	}
	_pValueResult = pValueAssigned;
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
	llvm::Value *pValueCar = _pValueResult;
	llvm::Value *pValueResult = CreateAllocaValue("value");
	if (pExpr->GetExprOwner().empty()) {
		std::vector<llvm::Value *> args;
		args.push_back(GetValue_env());
		args.push_back(GetValue_sig());
		args.push_back(pValueResult);
		args.push_back(pValueCar);
		llvm::Value *pValue_successFlag = _builder.CreateCall(
			_pModule->getFunction("GuraStub_EmptyIndexGet"),
			args, "successFlag");
		CreateCondBrErrorExit(pValue_successFlag);
	} else {
		std::vector<llvm::Value *> args;
		args.push_back(GetValue_env());
		args.push_back(pValueResult);
		llvm::Value *pValue_valList = _builder.CreateCall(
			_pModule->getFunction("GuraStub_CreateValueList"),
			args, "valList");
		foreach_const (ExprOwner, ppExprIdx, pExpr->GetExprOwner()) {
			const Expr *pExprIdx = *ppExprIdx;
			if (!pExprIdx->GenerateCode(env, sig, *this)) return false;
			llvm::Value *pValueIdx = _pValueResult;
			std::vector<llvm::Value *> args;
			args.push_back(GetValue_env());
			args.push_back(GetValue_sig());
			args.push_back(pValue_valList);
			args.push_back(pValueCar);
			args.push_back(pValueIdx);
			llvm::Value *pValue_successFlag = _builder.CreateCall(
				_pModule->getFunction("GuraStub_IndexGet"),
				args, "successFlag");
			CreateCondBrErrorExit(pValue_successFlag);
		}
	}
	_pValueResult = pValueResult;
	return true;
}

bool CodeGeneratorLLVM::GenCode_AssignToIndexer(
	Environment &env, Signal &sig,
	const Expr_Indexer *pExpr, llvm::Value *pValueAssigned)
{
	if (!pExpr->GetCar()->GenerateCode(env, sig, *this)) return false;
	llvm::Value *pValueCar = _pValueResult;
	if (pExpr->GetExprOwner().empty()) {
		std::vector<llvm::Value *> args;
		args.push_back(GetValue_env());
		args.push_back(GetValue_sig());
		args.push_back(pValueCar);
		args.push_back(pValueAssigned);
		llvm::Value *pValue_successFlag = _builder.CreateCall(
			_pModule->getFunction("GuraStub_EmptyIndexSet"),
			args, "successFlag");
		CreateCondBrErrorExit(pValue_successFlag);
	} else {
		llvm::BasicBlock *pBasicBlockScalar =
			llvm::BasicBlock::Create(_context, "bb.assignToIndexer.scalar", GetFunctionCur());
		llvm::BasicBlock *pBasicBlockIterable =
			llvm::BasicBlock::Create(_context, "bb.assignToIndexer.iterable");
		llvm::BasicBlock *pBasicBlockDone =
			llvm::BasicBlock::Create(_context, "bb.assignToIndexer.done");
		_builder.CreateCondBr(
			CreateCheckValTypeListOrIterator(pValueAssigned), pBasicBlockIterable, pBasicBlockScalar);
		_builder.SetInsertPoint(pBasicBlockScalar);
		do {
			// tgt[i] = scalar
			// tgt[i, j, k] = scalar
			foreach_const (ExprOwner, ppExprIdx, pExpr->GetExprOwner()) {
				const Expr *pExprIdx = *ppExprIdx;
				if (!pExprIdx->GenerateCode(env, sig, *this)) return false;
				llvm::Value *pValueIdx = _pValueResult;
				std::vector<llvm::Value *> args;
				args.push_back(GetValue_env());
				args.push_back(GetValue_sig());
				args.push_back(pValueCar);
				args.push_back(pValueIdx);
				args.push_back(pValueAssigned);
				llvm::Value *pValue_successFlag = _builder.CreateCall(
					_pModule->getFunction("GuraStub_IndexSet"),
					args, "successFlag");
				CreateCondBrErrorExit(pValue_successFlag);
			}
		} while (0);
		_builder.CreateBr(pBasicBlockDone);
		GetFunctionCur()->getBasicBlockList().push_back(pBasicBlockIterable);
		_builder.SetInsertPoint(pBasicBlockIterable);
		if (pExpr->GetExprOwner().size() == 1) {
			// tgt[i] = iterable
			const Expr *pExprIdx = pExpr->GetExprOwner().front();
			if (!pExprIdx->GenerateCode(env, sig, *this)) return false;
			llvm::Value *pValueIdx = _pValueResult;
			std::vector<llvm::Value *> args;
			args.push_back(GetValue_env());
			args.push_back(GetValue_sig());
			args.push_back(pValueCar);
			args.push_back(pValueIdx);
			args.push_back(pValueAssigned);
			llvm::Value *pValue_successFlag = _builder.CreateCall(
				_pModule->getFunction("GuraStub_IndexSet"),
				args, "successFlag");
			CreateCondBrErrorExit(pValue_successFlag);
		} else {
			// tgt[i, j, k] = iterable
			llvm::BasicBlock *pBasicBlockDone =
				llvm::BasicBlock::Create(_context, "bb.assignToIndexer.iterable.done");
			llvm::Value *pValue_ppIteratorAssigned = _builder.CreateAlloca(
				_pStructType_Iterator->getPointerTo(), nullptr, "ppIteratorAssigned");
			do {
				std::vector<llvm::Value *> args;
				args.push_back(GetValue_env());
				args.push_back(GetValue_sig());
				args.push_back(pValueAssigned);
				args.push_back(pValue_ppIteratorAssigned);
				llvm::Value *pValue_successFlag = _builder.CreateCall(
					_pModule->getFunction("GuraStub_CreateIterator"),
					args, "successFlag");
				CreateCondBrErrorExit(pValue_successFlag);
			} while (0);
			llvm::Value *pValue_pIteratorAssigned = _builder.CreateLoad(
				pValue_ppIteratorAssigned, "pIteratorAssigned");
			foreach_const (ExprOwner, ppExprIdx, pExpr->GetExprOwner()) {
				const Expr *pExprIdx = *ppExprIdx;
				if (!pExprIdx->GenerateCode(env, sig, *this)) return false;
				llvm::Value *pValueIdx = _pValueResult;
				std::vector<llvm::Value *> args;
				args.push_back(GetValue_env());
				args.push_back(GetValue_sig());
				args.push_back(pValueCar);
				args.push_back(pValueIdx);
				args.push_back(pValue_pIteratorAssigned);
				llvm::Value *pValue_continueFlag = _builder.CreateCall(
					_pModule->getFunction("GuraStub_IndexSetIterator"),
					args, "continueFlag");
				llvm::BasicBlock *pBasicBlockContinue =
					llvm::BasicBlock::Create(_context, "bb.assignToIndexer.iterable.continue", GetFunctionCur());
				_builder.CreateCondBr(pValue_continueFlag, pBasicBlockContinue, pBasicBlockDone);
				_builder.SetInsertPoint(pBasicBlockContinue);
			}
			_builder.CreateBr(pBasicBlockDone);
			GetFunctionCur()->getBasicBlockList().push_back(pBasicBlockDone);
			_builder.SetInsertPoint(pBasicBlockDone);
			do {
				std::vector<llvm::Value *> args;
				args.push_back(pValue_pIteratorAssigned);
				_builder.CreateCall(
					_pModule->getFunction("GuraStub_ReleaseIterator"),
					args);
			} while (0);
			CreateCondBrErrorExit();
		}
		_builder.CreateBr(pBasicBlockDone);
		GetFunctionCur()->getBasicBlockList().push_back(pBasicBlockDone);
		_builder.SetInsertPoint(pBasicBlockDone);
	}
	_pValueResult = pValueAssigned;
	return true;
}

bool CodeGeneratorLLVM::GenCode_Caller(Environment &env, Signal &sig, const Expr_Caller *pExpr)
{
	if (pExpr->GetCar()->IsMember()) {
		
	} else {
		llvm::Value *pValueResult = CreateAllocaValue("value");
		if (!pExpr->GetCar()->GenerateCode(env, sig, *this)) return false;
		llvm::Value *pValueCar = _pValueResult;
		std::vector<llvm::Value *> args;
		args.push_back(GetValue_env());
		args.push_back(GetValue_sig());
		args.push_back(pValueResult);
		args.push_back(pValueCar);
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
		llvm::Value *pValue_successFlag = _builder.CreateCall(
			_pModule->getFunction("GuraStub_CallFunction"),
			args, "successFlag");
		CreateCondBrErrorExit(pValue_successFlag);
		_pValueResult = pValueResult;
	}
	return true;
}

bool CodeGeneratorLLVM::GenCode_AssignToCaller(
	Environment &env, Signal &sig,
	const Expr_Caller *pExpr, const Expr *pExprAssigned)
{
	llvm::Function *pFunction = CreateBridgeFunction(env, sig, pExprAssigned, "FunctionBody");
	if (pFunction == nullptr) return false;
	_pValueResult = nullptr;
	return true;
}

bool CodeGeneratorLLVM::GenCode_UnaryOp(Environment &env, Signal &sig, const Expr_UnaryOp *pExpr)
{
	_pValueResult = CreateUnaryOp(env, sig, pExpr->GetOperator(), pExpr->GetChild());
	return _pValueResult != nullptr;
}

bool CodeGeneratorLLVM::GenCode_BinaryOp(Environment &env, Signal &sig, const Expr_BinaryOp *pExpr)
{
	_pValueResult = CreateBinaryOp(env, sig, pExpr->GetOperator(),
								   pExpr->GetLeft(), pExpr->GetRight());
	return _pValueResult != nullptr;
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
	llvm::Value *pValueAssigned = nullptr;
	if (pExpr->GetOperatorToApply() == nullptr) {
		if (!pExpr->GetRight()->GenerateCode(env, sig, *this)) return false;
		pValueAssigned = _pValueResult;
	} else {
		pValueAssigned = CreateBinaryOp(env, sig, pExpr->GetOperatorToApply(),
										pExpr->GetLeft(), pExpr->GetRight());
		if (pValueAssigned == nullptr) return false;
	}
	if (pExpr->GetLeft()->IsIdentifier()) {
		const Expr_Identifier *pExprEx = dynamic_cast<const Expr_Identifier *>(pExpr->GetLeft());
		if (!GenCode_AssignToIdentifier(env, sig, pExprEx, pValueAssigned)) return false;
	} else if (pExpr->GetLeft()->IsIndexer()) {
		const Expr_Indexer *pExprEx = dynamic_cast<const Expr_Indexer *>(pExpr->GetLeft());
		if (!GenCode_AssignToIndexer(env, sig, pExprEx, pValueAssigned)) return false;
	} else if (pExpr->GetLeft()->IsLister()) {
		const Expr_Lister *pExprEx = dynamic_cast<const Expr_Lister *>(pExpr->GetLeft());
		if (!GenCode_AssignToLister(env, sig, pExprEx, pValueAssigned)) return false;
	} else if (pExpr->GetLeft()->IsMember()) {
		const Expr_Member *pExprEx = dynamic_cast<const Expr_Member *>(pExpr->GetLeft());
		if (!GenCode_AssignToMember(env, sig, pExprEx, pValueAssigned)) return false;
	}
	_pValueResult = pValueAssigned;
	return true;
}

bool CodeGeneratorLLVM::GenCode_Member(Environment &env, Signal &sig, const Expr_Member *pExpr)
{
	::printf("Member\n");
	return true;
}

bool CodeGeneratorLLVM::GenCode_AssignToMember(
	Environment &env, Signal &sig,
	const Expr_Member *pExpr, llvm::Value *pValueAssigned)
{
	return true;
}

llvm::Value *CodeGeneratorLLVM::CreateUnaryOp(
	Environment &env, Signal &sig, const Operator *pOperator, const Expr *pExprChild)
{
	if (!pExprChild->GenerateCode(env, sig, *this)) return nullptr;
	llvm::Value *pValueChild = _pValueResult;
	llvm::Value *pValueResult = CreateAllocaValue("value");
	std::vector<llvm::Value *> args;
	args.push_back(GetValue_env());
	args.push_back(GetValue_sig());
	args.push_back(pValueResult);
	args.push_back(pValueChild);
	llvm::Value *pValue_successFlag = _builder.CreateCall(
		_pModule->getFunction(std::string("GuraStub_UnaryOp_") + pOperator->GetName()),
		args, "successFlag");
	CreateCondBrErrorExit(pValue_successFlag);
	return pValueResult;
}

llvm::Value *CodeGeneratorLLVM::CreateBinaryOp(
	Environment &env, Signal &sig, const Operator *pOperator,
	const Expr *pExprLeft, const Expr *pExprRight)
{
	if (!pExprLeft->GenerateCode(env, sig, *this)) return nullptr;
	llvm::Value *pValueLeft = _pValueResult;
	if (!pExprRight->GenerateCode(env, sig, *this)) return nullptr;
	llvm::Value *pValueRight = _pValueResult;
	llvm::Value *pValueResult = CreateAllocaValue("value");
	std::vector<llvm::Value *> args;
	args.push_back(GetValue_env());
	args.push_back(GetValue_sig());
	args.push_back(pValueResult);
	args.push_back(pValueLeft);
	args.push_back(pValueRight);
	llvm::Value *pValue_successFlag = _builder.CreateCall(
		_pModule->getFunction(std::string("GuraStub_BinaryOp_") + pOperator->GetName()),
		args, "successFlag");
	CreateCondBrErrorExit(pValue_successFlag);
	return pValueResult;
}

llvm::Value *CodeGeneratorLLVM::CreateCheckValType(llvm::Value *pValue, UShort valType)
{
	llvm::Value *pValue_valType = _builder.CreateLoad(
		_builder.CreatePointerCast(
			pValue, _builder.getInt16Ty()->getPointerTo(), "valType"));
	return _builder.CreateICmpEQ(
		llvm::ConstantInt::get(_builder.getInt16Ty(), valType), pValue_valType);
}

llvm::Value *CodeGeneratorLLVM::CreateCheckValTypeListOrIterator(llvm::Value *pValue)
{
	llvm::Value *pValue_valType = _builder.CreateLoad(
		_builder.CreatePointerCast(
			pValue, _builder.getInt16Ty()->getPointerTo(), "valType"));
	return _builder.CreateOr(
		_builder.CreateICmpEQ(
			llvm::ConstantInt::get(_builder.getInt16Ty(), VTYPE_list),
			pValue_valType),
		_builder.CreateICmpEQ(
			llvm::ConstantInt::get(_builder.getInt16Ty(), VTYPE_iterator),
			pValue_valType),
		"valueIsListOrIteratorFlag");
}

void CodeGeneratorLLVM::CreateCondBrErrorExit()
{
	CreateCondBrErrorExit(
		_builder.CreateICmpULE(
			_builder.CreateLoad(_builder.CreateStructGEP(GetValue_sig(), 0), "sigType"),
			llvm::ConstantInt::get(_builder.getInt32Ty(), SIGTYPE_ErrorSuspended)));
}

void CodeGeneratorLLVM::CreateCondBrErrorExit(llvm::Value *pValue_successFlag)
{
	llvm::BasicBlock *pBasicBlockContinue =
		llvm::BasicBlock::Create(_context, "bb.function.continue", GetFunctionCur());
	_builder.CreateCondBr(pValue_successFlag, pBasicBlockContinue, GetBasicBlockExit());
	_builder.SetInsertPoint(pBasicBlockContinue);
}

llvm::Value *CodeGeneratorLLVM::CreateAllocaValue(const llvm::Twine &name, bool initFlag)
{
	llvm::BasicBlock *pBasicBlockSaved = _builder.GetInsertBlock();
	_builder.SetInsertPoint(GetBasicBlockEntry());
	llvm::Value *pValue = _builder.CreateAlloca(_pStructType_Value, nullptr, name);
	if (initFlag) {
		_builder.CreateStore(
			llvm::ConstantInt::get(_builder.getInt32Ty(), 0x00000000),
			_builder.CreatePointerCast(pValue, _builder.getInt32Ty()->getPointerTo(), "valHeader"));
	}
	_builder.SetInsertPoint(GetBasicBlockRelease());
	do {
		std::vector<llvm::Value *> args;
		args.push_back(pValue);
		_builder.CreateCall(
			_pModule->getFunction("Gura_ReleaseValue"),
			args);
	} while (0);
	_builder.SetInsertPoint(pBasicBlockSaved);
	return pValue;
}

llvm::Value *CodeGeneratorLLVM::GetCPointerToPtr(const void *p, llvm::Type *pType)
{
	return llvm::ConstantExpr::getIntToPtr(
		llvm::ConstantInt::get(_builder.getInt64Ty(), reinterpret_cast<uint64_t>(p)),
		pType);
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
	llvm::Value *pValue_env = pArg++;
	pArg->setName("sig");
	llvm::Value *pValue_sig = pArg++;
	pArg->setName("valueResult");
	llvm::Value *pValue_result = pArg++;
	llvm::BasicBlock *pBasicBlockSaved = _builder.GetInsertBlock();
	llvm::BasicBlock *pBasicBlockEntry =
		llvm::BasicBlock::Create(_context, "bb.function.entry", pFunction);
	llvm::BasicBlock *pBasicBlockBody =
		llvm::BasicBlock::Create(_context, "bb.function.body", pFunction);
	llvm::BasicBlock *pBasicBlockExit =
		llvm::BasicBlock::Create(_context, "bb.function.exit");
	llvm::BasicBlock *pBasicBlockRelease =
		llvm::BasicBlock::Create(_context, "bb.function.release");
	llvm::Value *pValueResultSaved = _pValueResult;
	_pValueResult = nullptr;
	_contextStack.push_back(new Context(pValue_env, pValue_sig,
										pBasicBlockEntry, pBasicBlockExit, pBasicBlockRelease));
	_builder.SetInsertPoint(pBasicBlockBody);
	if (pExpr->GenerateCode(env, sig, *this)) {
		llvm::Value *pValueRtn = _pValueResult;
		pFunction->getBasicBlockList().push_back(pBasicBlockExit);
		pFunction->getBasicBlockList().push_back(pBasicBlockRelease);
		_builder.CreateBr(pBasicBlockExit);
		_builder.SetInsertPoint(pBasicBlockEntry);
		_builder.CreateBr(pBasicBlockBody);
		_builder.SetInsertPoint(pBasicBlockExit);
		if (pValueRtn != nullptr) {
			std::vector<llvm::Value *> args;
			args.push_back(pValue_result);
			args.push_back(pValueRtn);
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
	_pValueResult = pValueResultSaved;
	if (pBasicBlockSaved != nullptr) _builder.SetInsertPoint(pBasicBlockSaved);
	return pFunction;
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
