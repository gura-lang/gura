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
	_pValueResult(nullptr), _pValue_env(nullptr), _pValue_sig(nullptr)
{
}

extern "C" void MakeValue(Environment &env, Signal &sig, Value &result)
{
	result = Value("hello world");
}

extern "C" void LookupValue(Environment &env, Signal &sig, Value &result, const char *name)
{
	Value *pValue = env.LookupValue(Symbol::Add(name), ENVREF_Escalate);
	if (pValue == NULL) {
		sig.SetError(ERR_ValueError, "undefined variable %s", name);
	} else {
		result = *pValue;
	}
}

bool CodeGeneratorLLVM::Generate(Environment &env, Signal sig, const Expr *pExpr)
{
	_pModule.reset(new llvm::Module("gura", llvm::getGlobalContext()));
	llvm::StructType *pStructType_Hoge = llvm::StructType::create(
		"struct.Hoge",
		_builder.getInt16Ty(),
		_builder.getInt16Ty(),
		_builder.getInt64Ty(),
		nullptr);
	do {
		// declare i32 @puts(i8*)
		_pModule->getOrInsertFunction(
			"puts",
			_builder.getInt32Ty(),
			_builder.getInt8Ty()->getPointerTo(),
			nullptr);
	} while (0);
	do {
		// declare void @MakeValue(i8*, i8*, i8*)
		llvm::cast<llvm::Function>(
			_pModule->getOrInsertFunction(
				"MakeValue",
				_builder.getVoidTy(),
				_builder.getInt8Ty()->getPointerTo(),
				_builder.getInt8Ty()->getPointerTo(),
				_builder.getInt8Ty()->getPointerTo(),
				nullptr));
	} while (0);
	do {
		// declare void @LookupValue(i8*, i8*, i8*, i8*)
		llvm::cast<llvm::Function>(
			_pModule->getOrInsertFunction(
				"LookupValue",
				_builder.getVoidTy(),
				_builder.getInt8Ty()->getPointerTo(),
				_builder.getInt8Ty()->getPointerTo(),
				_builder.getInt8Ty()->getPointerTo(),
				_builder.getInt8Ty()->getPointerTo(),
				nullptr));
	} while (0);
	do {
		// define void @GuraEntry(i8* env, i8* sig, i8* result)
		llvm::Function *pFunction = llvm::cast<llvm::Function>(
			_pModule->getOrInsertFunction(
				"GuraEntry",
				_builder.getVoidTy(),
				_builder.getInt8Ty()->getPointerTo(),
				_builder.getInt8Ty()->getPointerTo(),
				_builder.getInt8Ty()->getPointerTo(),
				nullptr));
		llvm::Function::arg_iterator pArg = pFunction->arg_begin();
		pArg->setName("env");
		_pValue_env = pArg++;
		pArg->setName("sig");
		_pValue_sig = pArg++;
		pArg->setName("result");
		llvm::Value *pValue_result = pArg++;
		llvm::BasicBlock *pBasicBlock = llvm::BasicBlock::Create(_context, "entrypoint", pFunction);
		_builder.SetInsertPoint(pBasicBlock);
		if (!pExpr->GenerateCode(env, sig, *this)) return false;
		//_builder.CreateRet(_pValueResult);
		//_builder.CreateRetVoid();
		//_builder.CreateRet(_builder.CreateAdd(pValue_x, pValue_y));
		//_pValue_pHoge->getOffsetOf(pStructType_Hoge, 0);
		//_builder.CreateStore(
		//	llvm::ConstantInt::get(_builder.getInt16Ty(), 12345),
		//	_pValue_pHoge->getOffsetOf(pStructType_Hoge, 0));
		//_builder.CreateStore(
		//	llvm::ConstantInt::get(_builder.getInt32Ty(), 12345),
		//	pValue_num);
#if 1
		do {
			std::vector<llvm::Value *> args;
			args.push_back(_pValue_env);
			args.push_back(_pValue_sig);
			args.push_back(pValue_result);
			_builder.CreateCall(
				_pModule->getFunction("MakeValue"),
				args);
		} while (0);
#endif
#if 0
		do {
			std::vector<llvm::Value *> args;
			args.push_back(_builder.CreateGlobalStringPtr("hello world!"));
			_builder.CreateCall(
				_pModule->getFunction("puts"),
				args);
		} while (0);
#endif
		do {
			llvm::Value *pValueResult = _builder.CreateAlloca(
				_builder.getInt8Ty(), llvm::ConstantInt::get(_builder.getInt32Ty(), 64));
			std::vector<llvm::Value *> args;
			args.push_back(_pValue_env);
			args.push_back(_pValue_sig);
			args.push_back(pValueResult);
			args.push_back(_builder.CreateGlobalStringPtr("hoge"));
			_builder.CreateCall(
				_pModule->getFunction("LookupValue"),
				args);
		} while (0);
		_builder.CreateRetVoid();
	} while (0);
	return true;
}

struct Hoge {
	UShort x;
	UShort y;
	UInt64 z;
};

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
		_pValueResult = llvm::ConstantFP::get(_builder.getDoubleTy(), value.GetDouble());
	} else if (value.Is_string()) {
		_pValueResult = _builder.CreateGlobalStringPtr(value.GetString());
	} else {
		sig.SetError(ERR_SyntaxError, "GetCode_Value()");
	}
	return true;
}

bool CodeGeneratorLLVM::GenCode_Identifier(Environment &env, Signal sig, const Expr_Identifier *pExpr)
{
	::printf("Identifier\n");
	_pValueResult = _builder.CreateAlloca(_builder.getInt8Ty(), nullptr);
	std::vector<llvm::Value *> args;
	args.push_back(_pValue_env);
	args.push_back(_pValue_sig);
	args.push_back(_builder.CreateGlobalStringPtr(pExpr->GetSymbol()->GetName()));
	args.push_back(_pValueResult);
	_builder.CreateCall(
		_pModule->getFunction("LookupValue"),
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
	return true;
}

bool CodeGeneratorLLVM::GenCode_Iterer(Environment &env, Signal sig, const Expr_Iterer *pExpr)
{
	::printf("Iterer\n");
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
	//_pValueResult = _builder.CreateCall(
	//	_pModule->getFunction("puts"),
	//	_builder.CreateGlobalStringPtr("hello world!"));
	return true;
}

bool CodeGeneratorLLVM::GenCode_UnaryOp(Environment &env, Signal sig, const Expr_UnaryOp *pExpr)
{
	::printf("UnaryOp\n");
	pExpr->GetChild()->GenerateCode(env, sig, *this);
	return true;
}

bool CodeGeneratorLLVM::GenCode_BinaryOp(Environment &env, Signal sig, const Expr_BinaryOp *pExpr)
{
	::printf("BinaryOp\n");
	if (!pExpr->GetLeft()->GenerateCode(env, sig, *this)) return false;
	llvm::Value *pValueLHS = _pValueResult;
	if (!pExpr->GetRight()->GenerateCode(env, sig, *this)) return false;
	llvm::Value *pValueRHS = _pValueResult;
	_pValueResult = _builder.CreateFAdd(pValueLHS, pValueRHS);
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
