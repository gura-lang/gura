//-----------------------------------------------------------------------------
// Gura llvm module
//-----------------------------------------------------------------------------
#include "module-llvm.h"

Gura_BeginModule(llvm)

static const llvm::Type *NullTy = reinterpret_cast<llvm::Type *>(0);

//-----------------------------------------------------------------------------
// Gura module functions: llvm
//-----------------------------------------------------------------------------
// llvm.test()
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(test)
{
	llvm::InitializeNativeTarget();
	llvm::LLVMContext context;
	llvm::Module *pModule = new llvm::Module("test", context);
	llvm::Value *pValue_1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 1);
	llvm::Value *pValue_10 =llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 10);
	llvm::Function *pFunction_add1 = NULL, *pFunction_foo = NULL;
	llvm::IRBuilder<> builder(context);
	do {
		pFunction_add1 = llvm::cast<llvm::Function>(pModule->getOrInsertFunction("add1",
			builder.getInt32Ty(), builder.getInt32Ty(), NullTy));
		builder.SetInsertPoint(llvm::BasicBlock::Create(context, "entry", pFunction_add1));
		llvm::Argument *pArgument = pFunction_add1->arg_begin();
		pArgument->setName("AnArg");
		llvm::Value *pValue = builder.CreateAdd(pValue_1, pArgument, "addresult");
		builder.CreateRet(pValue);
	} while (0);
	do {
		pFunction_foo = llvm::cast<llvm::Function>(pModule->getOrInsertFunction("foo",
			builder.getInt32Ty(), NullTy));
		builder.SetInsertPoint(llvm::BasicBlock::Create(context, "entry", pFunction_foo));
		llvm::CallInst *pValue = builder.CreateCall(pFunction_add1, pValue_10, "add1");
		pValue->setTailCall(true);
		builder.CreateRet(pValue);
	} while (0);
	do {
		llvm::ExecutionEngine *pExecutionEngine = llvm::EngineBuilder(pModule).create();
		llvm::outs() << "We just constructed this LLVM module:\n\n";
		llvm::outs() << *pModule;
		llvm::outs() << "\n\nRunning foo: ";
		llvm::outs().flush();
		std::vector<llvm::GenericValue> genericValueList;
		llvm::GenericValue genericValue = pExecutionEngine->runFunction(pFunction_foo, genericValueList);
		llvm::outs() << "Result: " << genericValue.IntVal << "\n";
		pExecutionEngine->freeMachineCodeForFunction(pFunction_foo);
		delete pExecutionEngine;
	} while (0);
	llvm::llvm_shutdown();
	return Value::Null;
}

// llvm.fibonacci()
Gura_DeclareFunction(fibonacci)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

static llvm::Function *CreateFibFunction(llvm::Module *pModule, llvm::LLVMContext &context)
{
	llvm::IRBuilder<> builder(context);
	// Create the fib function and insert it into module pModule.  This function is said
	// to return an int and take an int parameter.
	llvm::Function *pFunction = llvm::cast<llvm::Function>(
			pModule->getOrInsertFunction("fib", llvm::Type::getInt32Ty(context),
			llvm::Type::getInt32Ty(context), (llvm::Type *)0));
	// Get pointers to the constants.
	llvm::Value *pValue_1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 1);
	llvm::Value *pValue_2 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 2);
	// Get pointer to the integer argument of the add1 function...
	llvm::Argument *pArgument = pFunction->arg_begin();
	pArgument->setName("AnArg"); // Give it a nice symbolic name for fun.
	llvm::BasicBlock *pBasicBlock_entry = llvm::BasicBlock::Create(context, "entry", pFunction);
	llvm::BasicBlock* pBasicBlock_recurse = llvm::BasicBlock::Create(context, "recurse", pFunction);
	llvm::BasicBlock *pBasicBlock_hoge = llvm::BasicBlock::Create(context, "hoge", pFunction);
	llvm::BasicBlock *pBasicBlock_return = llvm::BasicBlock::Create(context, "return", pFunction);
	do {
		builder.SetInsertPoint(pBasicBlock_entry);
		// if (arg <= 2) goto return else goto recurse
		llvm::Value *pValue = builder.CreateICmpSLE(pArgument, pValue_2, "cond");
		builder.CreateCondBr(pValue, pBasicBlock_return, pBasicBlock_recurse);
	} while (0);
	do {
		builder.SetInsertPoint(pBasicBlock_recurse);
		llvm::CallInst *pCallInst_fibx1 = NULL;
		do {
			// fib(x - 1)
			llvm::Value *pValue = builder.CreateSub(pArgument, pValue_1, "arg");
			pCallInst_fibx1 = builder.CreateCall(pFunction, pValue, "fibx1");
			pCallInst_fibx1->setTailCall();
		} while (0);
		llvm::CallInst *pCallInst_fibx2 = NULL;
		do {
			// fib(x - 2)
			llvm::Value *pValue = builder.CreateSub(pArgument, pValue_2, "arg");
			pCallInst_fibx2 = builder.CreateCall(pFunction, pValue, "fibx2");
			pCallInst_fibx2->setTailCall();
		} while (0);
		// fib(x - 1) + fib(x - 2)
		llvm::Value *pValue = builder.CreateAdd(pCallInst_fibx1, pCallInst_fibx2, "addresult");
		builder.CreateRet(pValue);
	} while (0);
	do {
		builder.SetInsertPoint(pBasicBlock_hoge);
		builder.CreateBr(pBasicBlock_return);
	} while (0);
	do {
		builder.SetInsertPoint(pBasicBlock_return);
		builder.CreateRet(pValue_1);
	} while (0);
	return pFunction;
}

Gura_ImplementFunction(fibonacci)
{
	int n = 24;
	llvm::InitializeNativeTarget();
	llvm::LLVMContext context;
	llvm::OwningPtr<llvm::Module> pModule(new llvm::Module("test", context));
	llvm::Function *pFunction_fib = CreateFibFunction(pModule.get(), context);
	std::string errStr;
	llvm::ExecutionEngine *pExecutionEngine = llvm::EngineBuilder(pModule.get()).setErrorStr(&errStr).setEngineKind(llvm::EngineKind::JIT).create();
	if (pExecutionEngine == NULL) {
		llvm::errs() << "Failed to construct ExecutionEngine: " << errStr << "\n";
		return Value::Null;
	}
	llvm::errs() << "verifying... ";
	if (llvm::verifyModule(*pModule)) {
		llvm::errs() << "Error constructing function!\n";
		return Value::Null;
	}
	llvm::errs() << "OK\n";
	llvm::errs() << "We just constructed this LLVM module:\n\n---------\n";
	llvm::errs() << *pModule;
	llvm::errs() << "---------\nstarting fibonacci(" << n << ") with JIT...\n";
	std::vector<llvm::GenericValue> genericValueList(1);
	genericValueList[0].IntVal = llvm::APInt(32, n);
	llvm::GenericValue genericValue = pExecutionEngine->runFunction(pFunction_fib, genericValueList);
	llvm::outs() << "Result: " << genericValue.IntVal << "\n";
	return Value::Null;
}

// Module entry
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(test);
	Gura_AssignFunction(fibonacci);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(llvm, llvm)

Gura_RegisterModule(llvm)
