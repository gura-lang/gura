//-----------------------------------------------------------------------------
// Gura module: llvm
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(llvm)

//-----------------------------------------------------------------------------
// CodeGeneratorLLVM
//-----------------------------------------------------------------------------
class CodeGeneratorLLVM : public CodeGenerator {
private:
	llvm::LLVMContext &_context;
	std::unique_ptr<llvm::Module> _pModule;
	llvm::IRBuilder<> _builder;
	llvm::Value *_pValueResult;
	llvm::Value *_pValue_env;
	llvm::Value *_pValue_sig;
	llvm::StructType *_pStructType_Value;
public:
	CodeGeneratorLLVM();
	inline llvm::Module *GetModule() { return _pModule.get(); }
	bool Generate(Environment &env, Signal sig, const Expr *pExpr);
	void Run(Environment &env, Signal sig);
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
};

CodeGeneratorLLVM::CodeGeneratorLLVM() :
	_context(llvm::getGlobalContext()),	_builder(llvm::getGlobalContext()),
	_pValueResult(nullptr), _pValue_env(nullptr), _pValue_sig(nullptr),
	_pStructType_Value(nullptr)
{
}

extern "C" void Gura_LookupValue(Environment &env, Signal &sig, Value &result, const char *name)
{
	::memset(&result, 0x00, sizeof(result));
	Value *pValue = env.LookupValue(Symbol::Add(name), ENVREF_Escalate);
	if (pValue == NULL) {
		sig.SetError(ERR_ValueError, "undefined variable %s", name);
	} else {
		result = *pValue;
	}
}

extern "C" void Gura_AddValueList(ValueList &valList, const Value &value)
{
	valList.push_back(value);
}

extern "C" void Gura_SetValue_number(Value &value, double num)
{
	Gura_CopyValue(value, Value(num));
}

extern "C" void Gura_SetValue_string(Value &value, const char *str)
{
	Gura_CopyValue(value, Value(str));
}

extern "C" void Gura_SetValue_binary(Environment &env, Value &value, const char *buff, ULong bytes)
{
	Gura_CopyValue(value, Value(new Object_binary(env, buff, bytes, false)));
}

extern "C" ValueList &Gura_SetValue_list(Environment &env, Value &value)
{
	Object_list *pObj = new Object_list(env);
	value._SetObject(pObj);
	return pObj->GetList();
}

#define ImplementPrefixedUnaryOpStub(name) \
extern "C" void Gura_UnaryOp_##name(Environment &env, Signal &sig, \
									Value &valueResult, const Value &value)	\
{ \
	Gura_CopyValue(valueResult, Operator::name->EvalMapUnary(env, sig, value, false)); \
}

#define ImplementSuffixedUnaryOpStub(name) \
extern "C" void Gura_UnaryOp_##name(Environment &env, Signal &sig, \
									Value &valueResult, const Value &value)	\
{ \
	Gura_CopyValue(valueResult, Operator::name->EvalMapUnary(env, sig, value, true)); \
}

#define ImplementBinaryOpStub(name) \
extern "C" void Gura_BinaryOp_##name(Environment &env, Signal &sig, \
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

extern "C" void Gura_CallFunction(Environment &env, Signal &sig,
					  Value &valueResult, const Value &valueCar, ...)
{
	if (!valueCar.Is_function()) {
		sig.SetError(ERR_TypeError, "object is not a function");
		Gura_CopyValue(valueResult, Value::Null);
		return;
	}
	va_list vargs;
	va_start(vargs, valueCar);
	AutoPtr<Args> pArgs(new Args());
	while (Value *pValue = va_arg(vargs, Value *)) {
		pArgs->AddValue(*pValue);
	}
	const Function *pFunc = valueCar.GetFunction();
	Gura_CopyValue(valueResult, pFunc->Eval(env, sig, *pArgs));
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
		llvm::Function *pFunction = llvm::Function::Create(
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
		llvm::Function *pFunction = llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"Gura_CopyValue",
			_pModule.get());
	} while (0);
	do {
		// declare void @Gura_SetValue_number(struct.Value*, double)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		typeArgs.push_back(_builder.getDoubleTy());					// num
		bool isVarArg = false;
		llvm::Function *pFunction = llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"Gura_SetValue_number",
			_pModule.get());
	} while (0);
	do {
		// declare void @Gura_SetValue_string(struct.Value*, i8*)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// str
		bool isVarArg = false;
		llvm::Function *pFunction = llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"Gura_SetValue_string",
			_pModule.get());
	} while (0);
	do {
		// declare void @Gura_SetValue_binary(i8*, struct.Value*, i8*, i32)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// buff
		typeArgs.push_back(_builder.getInt32Ty());					// bytes
		bool isVarArg = false;
		llvm::Function *pFunction = llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"Gura_SetValue_binary",
			_pModule.get());
	} while (0);
	do {
		// declare void @Gura_SetValue_list(i8*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getInt8Ty()->getPointerTo();	// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		bool isVarArg = false;
		llvm::Function *pFunction = llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"Gura_SetValue_list",
			_pModule.get());
	} while (0);
	do {
		// declare void @Gura_LookupValue(i8*, i8*, struct.Value*, i8*)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// name
		bool isVarArg = false;
		llvm::Function *pFunction = llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"Gura_LookupValue",
			_pModule.get());
	} while (0);
	do {
		// declare void @Gura_AddValueList(i8*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// valList
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		bool isVarArg = false;
		llvm::Function *pFunction = llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"Gura_AddValueList",
			_pModule.get());
	} while (0);
	for (const char *opName : {
				"Pos", "Neg", "Inv", "Not", "SeqInf", "Question", "Each" }) {
		// declare void @Gura_UnaryOp_*(i8*, i8*, struct.Value*, struct.Value*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueResult
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// value
		bool isVarArg = false;
		llvm::Function *pFunction = llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			std::string("Gura_UnaryOp_") + opName,
			_pModule.get());
	}
	for (const char *opName : {
				"Add", "Sub", "Mul", "Div", "Mod", "Pow",
				"Eq", "Ne", "Gt", "lt", "Ge", "Lt", "Ge", "Le", "Cmp", "Contains",
				"And", "Or", "Xor",	"Shl", "Shr", "OrOr", "AndAnd",
				"Seq", "Pair" }) {
		// declare void @Gura_BinaryOp_*(i8*, i8*, struct.Value*, struct.Value*, struct.Value*)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueResult
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueLeft
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueRight
		bool isVarArg = false;
		llvm::Function *pFunction = llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			std::string("Gura_BinaryOp_") + opName,
			_pModule.get());
	}
	do {
		// declare void @Gura_CallFunction(i8*, i8*, struct.Value*, struct.Value*, ...)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueResult
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// ValueCar
		bool isVarArg = true;
		llvm::Function *pFunction = llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"Gura_CallFunction",
			_pModule.get());
		//pFunction->setCallingConv(llvm::CallingConv::C);
	} while (0);
	do {
		// define void @GuraEntry(i8* env, i8* sig, %struct.Value* valueResult)
		llvm::Type *pTypeResult = _builder.getVoidTy();				// return
		std::vector<llvm::Type *> typeArgs;
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// env
		typeArgs.push_back(_builder.getInt8Ty()->getPointerTo());	// sig
		typeArgs.push_back(_pStructType_Value->getPointerTo());		// valueResult
		bool isVarArg = false;
		llvm::Function *pFunction = llvm::Function::Create(
			llvm::FunctionType::get(pTypeResult, typeArgs, isVarArg),
			llvm::Function::ExternalLinkage,
			"GuraEntry",
			_pModule.get());
		llvm::Function::arg_iterator pArg = pFunction->arg_begin();
		pArg->setName("env");
		_pValue_env = pArg++;
		pArg->setName("sig");
		_pValue_sig = pArg++;
		pArg->setName("valueResult");
		llvm::Value *pValue_result = pArg++;
		llvm::BasicBlock *pBasicBlock = llvm::BasicBlock::Create(_context, "entrypoint", pFunction);
		_builder.SetInsertPoint(pBasicBlock);
		if (!pExpr->GenerateCode(env, sig, *this)) return false;
		if (_pValueResult != nullptr) {
			std::vector<llvm::Value *> args;
			args.push_back(pValue_result);
			args.push_back(_pValueResult);
			_builder.CreateCall(
				_pModule->getFunction("Gura_CopyValue"),
				args);
		}
		_builder.CreateRetVoid();
	} while (0);
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
	void (*pGuraEntry)(Environment &env, Signal &sig, Value &) =
		reinterpret_cast<void (*)(Environment &env, Signal &sig, Value &)>(
			pExecutionEngine->getPointerToFunction(pFunction_GuraEntry));
	Value result;
	(*pGuraEntry)(env, sig, result);
	::printf("value = %s\n", result.ToString().c_str());
    pExecutionEngine->runStaticConstructorsDestructors(true);
}

bool CodeGeneratorLLVM::GenCode_Value(Environment &env, Signal sig, const Expr_Value *pExprValue)
{
	::printf("Value\n");
	const Value &value = pExprValue->GetValue();
	if (value.Is_number()) {
		_pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
		std::vector<llvm::Value *> args;
		args.push_back(_pValueResult);
		args.push_back(llvm::ConstantFP::get(_builder.getDoubleTy(), value.GetDouble()));
		_builder.CreateCall(
			_pModule->getFunction("Gura_SetValue_number"),
			args);
	} else if (value.Is_string()) {
		_pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
		std::vector<llvm::Value *> args;
		args.push_back(_pValueResult);
		args.push_back(_builder.CreateGlobalStringPtr(value.GetString()));
		_builder.CreateCall(
			_pModule->getFunction("Gura_SetValue_string"),
			args);
	} else if (value.Is_binary()) {
		const Binary &binary = value.GetBinary();
		std::string buff(binary.data(), binary.size());
		_pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
		std::vector<llvm::Value *> args;
		args.push_back(_pValue_env);
		args.push_back(_pValueResult);
		args.push_back(_builder.CreateGlobalStringPtr(buff));
		args.push_back(llvm::ConstantInt::get(_builder.getInt32Ty(), binary.size()));
		_builder.CreateCall(
			_pModule->getFunction("Gura_SetValue_binary"),
			args);
	} else {
		sig.SetError(ERR_SyntaxError, "GetCode_Value()");
		return false;
	}
	return true;
}

bool CodeGeneratorLLVM::GenCode_Identifier(Environment &env, Signal sig, const Expr_Identifier *pExpr)
{
	::printf("Identifier\n");
	_pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
	std::vector<llvm::Value *> args;
	args.push_back(_pValue_env);
	args.push_back(_pValue_sig);
	args.push_back(_pValueResult);
	args.push_back(_builder.CreateGlobalStringPtr(pExpr->GetSymbol()->GetName()));
	_builder.CreateCall(
		_pModule->getFunction("Gura_LookupValue"),
		args);
	return true;
}

bool CodeGeneratorLLVM::GenCode_Suffixed(Environment &env, Signal sig, const Expr_Suffixed *pExpr)
{
	::printf("Suffixed\n");
	return true;
}

bool CodeGeneratorLLVM::GenCode_Root(Environment &env, Signal sig, const Expr_Root *pExpr)
{
	::printf("Root\n");
	return true;
}

bool CodeGeneratorLLVM::GenCode_Block(Environment &env, Signal sig, const Expr_Block *pExpr)
{
	::printf("Block\n");
	pExpr->GetExprOwner().GenerateCode(env, sig, *this);
	//pExpr->GetExprOwnerParam();
	return true;
}

bool CodeGeneratorLLVM::GenCode_Lister(Environment &env, Signal sig, const Expr_Lister *pExpr)
{
	::printf("Lister\n");
	std::vector<llvm::Value *> args;
	args.push_back(_pValue_env);
	llvm::Value *pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
	args.push_back(pValueResult);
	llvm::Value *pValue_valList = _builder.CreateCall(
		_pModule->getFunction("Gura_SetValue_list"),
		args);
	foreach_const (ExprOwner, ppExpr, pExpr->GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		if (!pExpr->GenerateCode(env, sig, *this)) return false;
		std::vector<llvm::Value *> args;
		args.push_back(pValue_valList);
		args.push_back(_pValueResult);
		_builder.CreateCall(
			_pModule->getFunction("Gura_AddValueList"),
			args);
	}
	_pValueResult = pValueResult;
	return true;
}

bool CodeGeneratorLLVM::GenCode_Iterer(Environment &env, Signal sig, const Expr_Iterer *pExpr)
{
	::printf("Iterer\n");
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
	::printf("Caller\n");
	if (pExpr->GetCar()->IsMember()) {
		
	} else {
		std::vector<llvm::Value *> args;
		args.push_back(_pValue_env);
		args.push_back(_pValue_sig);
		llvm::Value *pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
		args.push_back(pValueResult);
		if (!pExpr->GetCar()->GenerateCode(env, sig, *this)) return false;
		args.push_back(_pValueResult);
		foreach_const (ExprOwner, ppExprArg, pExpr->GetExprOwner()) {
			const Expr *pExprArg = *ppExprArg;
			if (!pExprArg->GenerateCode(env, sig, *this)) return false;
			args.push_back(_pValueResult);
		}
		args.push_back(llvm::ConstantPointerNull::get(_pStructType_Value->getPointerTo()));
		_builder.CreateCall(
			_pModule->getFunction("Gura_CallFunction"),
			args);
		_pValueResult = pValueResult;
	}
	return true;
}

bool CodeGeneratorLLVM::GenCode_UnaryOp(Environment &env, Signal sig, const Expr_UnaryOp *pExpr)
{
	::printf("UnaryOp\n");
	std::vector<llvm::Value *> args;
	args.push_back(_pValue_env);
	args.push_back(_pValue_sig);
	llvm::Value *pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
	args.push_back(pValueResult);
	if (!pExpr->GetChild()->GenerateCode(env, sig, *this)) return false;
	args.push_back(_pValueResult);
	_builder.CreateCall(
		_pModule->getFunction(std::string("Gura_UnaryOp_") + pExpr->GetOperator()->GetName()),
		args);
	_pValueResult = pValueResult;
	return true;
}

bool CodeGeneratorLLVM::GenCode_BinaryOp(Environment &env, Signal sig, const Expr_BinaryOp *pExpr)
{
	::printf("BinaryOp\n");
	std::vector<llvm::Value *> args;
	args.push_back(_pValue_env);
	args.push_back(_pValue_sig);
	llvm::Value *pValueResult = _builder.CreateAlloca(_pStructType_Value, nullptr, "value");
	args.push_back(pValueResult);
	if (!pExpr->GetLeft()->GenerateCode(env, sig, *this)) return false;
	args.push_back(_pValueResult);
	if (!pExpr->GetRight()->GenerateCode(env, sig, *this)) return false;
	args.push_back(_pValueResult);
	_builder.CreateCall(
		_pModule->getFunction(std::string("Gura_BinaryOp_") + pExpr->GetOperator()->GetName()),
		args);
	_pValueResult = pValueResult;
	return true;
}

bool CodeGeneratorLLVM::GenCode_Quote(Environment &env, Signal sig, const Expr_Quote *pExpr)
{
	::printf("Quote\n");
	return true;
}

bool CodeGeneratorLLVM::GenCode_Assign(Environment &env, Signal sig, const Expr_Assign *pExpr)
{
	::printf("Assign\n");
	return true;
}

bool CodeGeneratorLLVM::GenCode_Member(Environment &env, Signal sig, const Expr_Member *pExpr)
{
	::printf("Member\n");
	return true;
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
