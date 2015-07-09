//-----------------------------------------------------------------------------
// Gura module: llvm
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(llvm)

typedef void (*BridgeFunctionT)(Environment &env, Signal &sig, Value &result);

//-----------------------------------------------------------------------------
// CodeGeneratorLLVM
//-----------------------------------------------------------------------------
class CodeGeneratorLLVM : public CodeGenerator {
public:
	class Context {
	private:
		llvm::Value *_pValue_env;
		llvm::Value *_pValue_sig;
	public:
		inline Context(llvm::Value *pValue_env, llvm::Value *pValue_sig) :
			_pValue_env(pValue_env), _pValue_sig(pValue_sig) {}
		inline llvm::Value *GetValue_env() { return _pValue_env; }
		inline llvm::Value *GetValue_sig() { return _pValue_sig; }
	};
	typedef std::vector<Context *> ContextStack;
private:
	llvm::LLVMContext &_context;
	std::unique_ptr<llvm::Module> _pModule;
	llvm::IRBuilder<> _builder;
	llvm::Value *_pValueResult;
	ContextStack _contextStack;
	llvm::StructType *_pStructType_Value;
public:
	CodeGeneratorLLVM();
	inline llvm::Module *GetModule() { return _pModule.get(); }
	bool Generate(Environment &env, Signal sig, const Expr *pExpr);
	void Run(Environment &env, Signal sig);
	llvm::Value *GetValue_env() { return _contextStack.back()->GetValue_env(); }
	llvm::Value *GetValue_sig() { return _contextStack.back()->GetValue_sig(); }
public:
	virtual bool GenCode_Value(Environment &env, Signal sig, const Expr_Value *pExprValue);
	virtual bool GenCode_Identifier(Environment &env, Signal sig, const Expr_Identifier *pExpr);
	virtual bool GenCode_Suffixed(Environment &env, Signal sig, const Expr_Suffixed *pExpr);
	virtual bool GenCode_Root(Environment &env, Signal sig, const Expr_Root *pExpr);
	virtual bool GenCode_Block(Environment &env, Signal sig, const Expr_Block *pExpr);
	virtual bool GenCode_Lister(Environment &env, Signal sig, const Expr_Lister *pExpr);
	virtual bool GenCode_Iterer(Environment &env, Signal sig, const Expr_Iterer *pExpr);
	virtual bool GenCode_Indexer(Environment &env, Signal sig, const Expr_Indexer *pExpr);
	virtual bool GenCode_Caller(Environment &env, Signal sig, const Expr_Caller *pExpr);
	virtual bool GenCode_UnaryOp(Environment &env, Signal sig, const Expr_UnaryOp *pExpr);
	virtual bool GenCode_BinaryOp(Environment &env, Signal sig, const Expr_BinaryOp *pExpr);
	virtual bool GenCode_Quote(Environment &env, Signal sig, const Expr_Quote *pExpr);
	virtual bool GenCode_Assign(Environment &env, Signal sig, const Expr_Assign *pExpr);
	virtual bool GenCode_Member(Environment &env, Signal sig, const Expr_Member *pExpr);
private:
	llvm::Function *CreateBridgeFunction(Environment &env, Signal sig,
										 const Expr *pExpr, const char *name);
};

CodeGeneratorLLVM::CodeGeneratorLLVM() :
	_context(llvm::getGlobalContext()),	_builder(llvm::getGlobalContext()),
	_pValueResult(nullptr), _pStructType_Value(nullptr)
{
}

extern "C" void GuraStub_LookupValue(Environment &env, Signal &sig, Value &result, const char *name)
{
	Value *pValue = env.LookupValue(Symbol::Add(name), ENVREF_Escalate);
	if (pValue == NULL) {
		sig.SetError(ERR_ValueError, "undefined variable %s", name);
	} else {
		Gura_CopyValue(result, *pValue);
	}
}

extern "C" void GuraStub_AssignValue(Environment &env, Signal &sig,
								 const char *name, const Value &value, ULong extra)
{
	env.AssignValue(Symbol::Add(name), value, extra);
}

extern "C" void GuraStub_AddValueList(Environment &env, Signal &sig, ValueList &valList, const Value &value)
{
	if (value.Is_iterator()) {
		AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
		if (sig.IsSignalled()) return;
		if (pIterator->IsInfinite()) {
			Iterator::SetError_InfiniteNotAllowed(sig);
			return;
		}
		Value value;
		while (pIterator->Next(env, sig, value)) {
			valList.push_back(value);
		}
	} else {
		valList.push_back(value);
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

extern "C" ValueList *GuraStub_CreateValue_list(Environment &env, Value &value)
{
	Object_list *pObj = new Object_list(env);
	value._SetObject(pObj);
	return &pObj->GetList();
}

#define ImplementPrefixedUnaryOpStub(name) \
extern "C" void GuraStub_UnaryOp_##name(Environment &env, Signal &sig, \
									Value &valueResult, const Value &value)	\
{ \
	Gura_CopyValue(valueResult, Operator::name->EvalMapUnary(env, sig, value, false)); \
}

#define ImplementSuffixedUnaryOpStub(name) \
extern "C" void GuraStub_UnaryOp_##name(Environment &env, Signal &sig, \
									Value &valueResult, const Value &value)	\
{ \
	Gura_CopyValue(valueResult, Operator::name->EvalMapUnary(env, sig, value, true)); \
}

#define ImplementBinaryOpStub(name) \
extern "C" void GuraStub_BinaryOp_##name(Environment &env, Signal &sig, \
					Value &valueResult, const Value &valueLeft, const Value &valueRight) \
{ \
	Gura_CopyValue(valueResult, Operator::name->EvalMapBinary(env, sig, valueLeft, valueRight)); \
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

extern "C" void GuraStub_CallFunction(
	Environment &env, Signal &sig,
	Value &valueResult, const Value &valueCar,
	BridgeFunctionT bridgeFuncBlockParam, BridgeFunctionT bridgeFuncBlock, ...)
{
	if (!valueCar.Is_function()) {
		sig.SetError(ERR_TypeError, "object is not a function");
		Gura_CopyValue(valueResult, Value::Null);
		return;
	}
	va_list vargs;
	va_start(vargs, bridgeFuncBlock);
	AutoPtr<Args> pArgs(new Args());
	while (Value *pValue = va_arg(vargs, Value *)) {
		pArgs->AddValue(*pValue);
	}
	const Function *pFunc = valueCar.GetFunction();
	Gura_CopyValue(valueResult, pFunc->Eval(env, sig, *pArgs));
}

extern "C" void GuraStub_PrintFunctionPointer(void *pFunc)
{
	::printf("%p\n", pFunc);
}

bool CodeGeneratorLLVM::Generate(Environment &env, Signal sig, const Expr *pExpr)
{
	_pModule.reset(new llvm::Module("gura", llvm::getGlobalContext()));
	
	_pStructType_Value = llvm::StructType::create(
		"struct.Value",
		llvm::ArrayType::get(_builder.getInt8Ty(), sizeof(Value)),
		nullptr);
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
		llvm::Type *pTypeResult = _builder.getInt32Ty();			// return
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
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// buff
		typeArgs.push_back(_builder.getInt32Ty());					// bytes
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_CreateValue_binary",
			_pModule.get());
	} while (0);
	do {
		// declare void @GuraStub_CreateValue_list(i8*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getInt8Ty()->getPointerTo();	// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_CreateValue_list",
			_pModule.get());
	} while (0);
	do {
		// declare void @GuraStub_LookupValue(i8*, i8*, struct.Value*, i8*)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// name
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_LookupValue",
			_pModule.get());
	} while (0);
	do {
		// declare void @GuraStub_AssignValue(i8*, i8*, i8*, struct.Value*, i32)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// sig
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// name
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		typeArgs.push_back(_builder.getInt32Ty());					// extra
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_AssignValue",
			_pModule.get());
	} while (0);
	do {
		// declare void @GuraStub_AddValueList(i8*, i8*, i8*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// sig
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// valList
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_AddValueList",
			_pModule.get());
	} while (0);
	for (const char *opName : {
				"Pos", "Neg", "Inv", "Not", "SeqInf", "Question", "Each" }) {
		// declare void @GuraStub_UnaryOp_*(i8*, i8*, struct.Value*, struct.Value*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueResult
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
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
		// declare void @GuraStub_BinaryOp_*(i8*, i8*, struct.Value*, struct.Value*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueResult
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueLeft
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueRight
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			std::string("GuraStub_BinaryOp_") + opName,
			_pModule.get());
	}
	do {
		// declare void @GuraStub_CallFunction(i8*, i8*, struct.Value*, struct.Value*, ...)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueResult
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueCar
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// bridgeFuncBlockParam
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// bridgeFuncBlock
		bool isVarArg = true;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_CallFunction",
			_pModule.get());
		//pFunction->setCallingConv(llvm::CallingConv::C);
	} while (0);

	do {
		// declare void @GuraStub_PrintFunctionPointer(i8*)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// pFunc
		bool isVarArg = false;
		llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraStub_PrintFunctionPointer",
			_pModule.get());
	} while (0);
	llvm::Function *pFunction = CreateBridgeFunction(env, sig, pExpr, "GuraEntry");
	if (pFunction == nullptr) return false;
	return true;
}

void CodeGeneratorLLVM::Run(Environment &env, Signal sig)
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
	BridgeFunctionT pGuraEntry = reinterpret_cast<BridgeFunctionT>(
		pExecutionEngine->getPointerToFunction(pFunction_GuraEntry));
	Value result;
	(*pGuraEntry)(env, sig, result);
	::printf("value = %s\n", result.ToString().c_str());
    pExecutionEngine->runStaticConstructorsDestructors(true);
}

bool CodeGeneratorLLVM::GenCode_Value(Environment &env, Signal sig, const Expr_Value *pExprValue)
{
	//::printf("Value\n");
	const Value &value = pExprValue->GetValue();
	if (value.Is_number()) {
		_pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
		std::vector<llvm::Value *> args;
		args.push_back(_pValueResult);
		args.push_back(llvm::ConstantFP::get(_builder.getDoubleTy(), value.GetDouble()));
		_builder.CreateCall(
			_pModule->getFunction("GuraStub_CreateValue_number"),
			args);
	} else if (value.Is_string()) {
		_pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
		std::vector<llvm::Value *> args;
		args.push_back(_pValueResult);
		args.push_back(_builder.CreateGlobalStringPtr(value.GetString()));
		_builder.CreateCall(
			_pModule->getFunction("GuraStub_CreateValue_string"),
			args);
	} else if (value.Is_binary()) {
		const Binary &binary = value.GetBinary();
		std::string buff(binary.data(), binary.size());
		_pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
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

bool CodeGeneratorLLVM::GenCode_Identifier(Environment &env, Signal sig, const Expr_Identifier *pExpr)
{
	//::printf("Identifier\n");
	_pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
	std::vector<llvm::Value *> args;
	args.push_back(GetValue_env());
	args.push_back(GetValue_sig());
	args.push_back(_pValueResult);
	args.push_back(_builder.CreateGlobalStringPtr(pExpr->GetSymbol()->GetName()));
	_builder.CreateCall(
		_pModule->getFunction("GuraStub_LookupValue"),
		args);
	return true;
}

bool CodeGeneratorLLVM::GenCode_Suffixed(Environment &env, Signal sig, const Expr_Suffixed *pExpr)
{
	//::printf("Suffixed\n");
	return true;
}

bool CodeGeneratorLLVM::GenCode_Root(Environment &env, Signal sig, const Expr_Root *pExpr)
{
	//::printf("Root\n");
	pExpr->GetExprOwner().GenerateCode(env, sig, *this);
	return true;
}

bool CodeGeneratorLLVM::GenCode_Block(Environment &env, Signal sig, const Expr_Block *pExpr)
{
	//::printf("Block\n");
	pExpr->GetExprOwner().GenerateCode(env, sig, *this);
	return true;
}

bool CodeGeneratorLLVM::GenCode_Lister(Environment &env, Signal sig, const Expr_Lister *pExpr)
{
	//::printf("Lister\n");
	std::vector<llvm::Value *> args;
	args.push_back(GetValue_env());
	llvm::Value *pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
	args.push_back(pValueResult);
	llvm::Value *pValue_valList = _builder.CreateCall(
		_pModule->getFunction("GuraStub_CreateValue_list"),
		args);
	foreach_const (ExprOwner, ppExpr, pExpr->GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		if (!pExpr->GenerateCode(env, sig, *this)) return false;
		std::vector<llvm::Value *> args;
		args.push_back(GetValue_env());
		args.push_back(GetValue_sig());
		args.push_back(pValue_valList);
		args.push_back(_pValueResult);
		_builder.CreateCall(
			_pModule->getFunction("GuraStub_AddValueList"),
			args);
	}
	_pValueResult = pValueResult;
	return true;
}

bool CodeGeneratorLLVM::GenCode_Iterer(Environment &env, Signal sig, const Expr_Iterer *pExpr)
{
	//::printf("Iterer\n");
	pExpr->GetExprOwner().GenerateCode(env, sig, *this);
	return true;
}

bool CodeGeneratorLLVM::GenCode_Indexer(Environment &env, Signal sig, const Expr_Indexer *pExpr)
{
	::printf("Indexer\n");
	return true;
}

bool CodeGeneratorLLVM::GenCode_Caller(Environment &env, Signal sig, const Expr_Caller *pExpr)
{
	//::printf("Caller\n");
	if (pExpr->GetCar()->IsMember()) {
		
	} else {
		std::vector<llvm::Value *> args;
		args.push_back(GetValue_env());
		args.push_back(GetValue_sig());
		llvm::Value *pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
		args.push_back(pValueResult);
		if (!pExpr->GetCar()->GenerateCode(env, sig, *this)) return false;
		args.push_back(_pValueResult);
		if (pExpr->GetBlock() == nullptr) {
			args.push_back(llvm::ConstantPointerNull::get(_builder.getInt8Ty()->getPointerTo()));
			args.push_back(llvm::ConstantPointerNull::get(_builder.getInt8Ty()->getPointerTo()));
		} else {
			args.push_back(llvm::ConstantPointerNull::get(_builder.getInt8Ty()->getPointerTo()));
			llvm::Function *pFunction = CreateBridgeFunction(
				env, sig, pExpr->GetBlock(), "BlockFunc");
			if (pFunction == nullptr) return false;
			args.push_back(llvm::ConstantExpr::getBitCast(
							   pFunction, _builder.getInt8Ty()->getPointerTo()));
		}
		foreach_const (ExprOwner, ppExprArg, pExpr->GetExprOwner()) {
			const Expr *pExprArg = *ppExprArg;
			if (!pExprArg->GenerateCode(env, sig, *this)) return false;
			args.push_back(_pValueResult);
		}
		args.push_back(llvm::ConstantPointerNull::get(_pStructType_Value->getPointerTo()));
		_builder.CreateCall(
			_pModule->getFunction("GuraStub_CallFunction"),
			args);
		_pValueResult = pValueResult;
	}
	return true;
}

bool CodeGeneratorLLVM::GenCode_UnaryOp(Environment &env, Signal sig, const Expr_UnaryOp *pExpr)
{
	//::printf("UnaryOp\n");
	std::vector<llvm::Value *> args;
	args.push_back(GetValue_env());
	args.push_back(GetValue_sig());
	llvm::Value *pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
	args.push_back(pValueResult);
	if (!pExpr->GetChild()->GenerateCode(env, sig, *this)) return false;
	args.push_back(_pValueResult);
	_builder.CreateCall(
		_pModule->getFunction(std::string("GuraStub_UnaryOp_") + pExpr->GetOperator()->GetName()),
		args);
	_pValueResult = pValueResult;
	return true;
}

bool CodeGeneratorLLVM::GenCode_BinaryOp(Environment &env, Signal sig, const Expr_BinaryOp *pExpr)
{
	//::printf("BinaryOp\n");
	std::vector<llvm::Value *> args;
	args.push_back(GetValue_env());
	args.push_back(GetValue_sig());
	llvm::Value *pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
	args.push_back(pValueResult);
	if (!pExpr->GetLeft()->GenerateCode(env, sig, *this)) return false;
	args.push_back(_pValueResult);
	if (!pExpr->GetRight()->GenerateCode(env, sig, *this)) return false;
	args.push_back(_pValueResult);
	_builder.CreateCall(
		_pModule->getFunction(std::string("GuraStub_BinaryOp_") + pExpr->GetOperator()->GetName()),
		args);
	_pValueResult = pValueResult;
	return true;
}

bool CodeGeneratorLLVM::GenCode_Quote(Environment &env, Signal sig, const Expr_Quote *pExpr)
{
	::printf("Quote\n");
	if (pExpr->GetChild()->IsIdentifier()) {
		//const Expr_Identifier *pExprIdentifier =
		//				dynamic_cast<const Expr_Identifier *>(GetChild());
		
	} else {
		
	}
	return true;
}

bool CodeGeneratorLLVM::GenCode_Assign(Environment &env, Signal sig, const Expr_Assign *pExpr)
{
	bool successFlag = false;
	//::printf("Assign\n");
	if (pExpr->GetLeft()->IsCaller()) {
		if (pExpr->GetOperatorToApply() != nullptr) {
			sig.SetError(ERR_SyntaxError, "invalid operation");
			return false;
		}
		llvm::Function *pFunction = CreateBridgeFunction(
			env, sig, pExpr->GetRight(), "CustomFunc");
		if (pFunction == nullptr) return false;
		successFlag = true;
	} else if (pExpr->GetOperatorToApply() == nullptr) {
		if (!pExpr->GetRight()->GenerateCode(env, sig, *this)) return false;
		llvm::Value *pValueToAssign = _pValueResult;
		if (pExpr->GetLeft()->IsIdentifier()) {
			const Expr_Identifier *pExprEx =
				dynamic_cast<const Expr_Identifier *>(pExpr->GetLeft());
			ULong extra = EXTRA_None;
			std::vector<llvm::Value *> args;
			args.push_back(GetValue_env());
			args.push_back(GetValue_sig());
			args.push_back(_builder.CreateGlobalStringPtr(pExprEx->GetSymbol()->GetName()));
			args.push_back(pValueToAssign);
			args.push_back(llvm::ConstantInt::get(_builder.getInt32Ty(), extra));
			_builder.CreateCall(
				_pModule->getFunction("GuraStub_AssignValue"),
				args);
		}
		_pValueResult = pValueToAssign;
		successFlag = true;
	} else {
		if (!pExpr->GetRight()->GenerateCode(env, sig, *this)) return false;
		//_pValueResult;
	}
	return successFlag;
}

bool CodeGeneratorLLVM::GenCode_Member(Environment &env, Signal sig, const Expr_Member *pExpr)
{
	::printf("Member\n");
	return true;
}

llvm::Function *CodeGeneratorLLVM::CreateBridgeFunction(
	Environment &env, Signal sig, const Expr *pExpr, const char *name)
{
	// define void @BridgeFunction(i8* env, i8* sig, %struct.Value* valueResult)
	llvm::Type *pTypeResult = _builder.getVoidTy();				// return
	std::vector<llvm::Type *> typeArgs;
	typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
	typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// sig
	typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueResult
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
	_contextStack.push_back(new Context(pValue_env, pValue_sig));
	llvm::BasicBlock *pBasicBlockSaved = _builder.GetInsertBlock();
	llvm::BasicBlock *pBasicBlock = llvm::BasicBlock::Create(_context, "entrypoint", pFunction);
	_builder.SetInsertPoint(pBasicBlock);
	llvm::Value *pValueResultSaved = _pValueResult;
	_pValueResult = nullptr;
	if (pExpr->GenerateCode(env, sig, *this)) {
		if (_pValueResult != nullptr) {
			std::vector<llvm::Value *> args;
			args.push_back(pValue_result);
			args.push_back(_pValueResult);
			_builder.CreateCall(
				_pModule->getFunction("Gura_CopyValue"),
				args);
			_pValueResult = nullptr;
		}
		_builder.CreateRetVoid();
		llvm::verifyFunction(*pFunction);
		//TheFPM->run(*pFunction);
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
	codeGeneratorLLVM.Run(env, sig);
	return Value::Null;
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
