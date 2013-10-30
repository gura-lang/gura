//-----------------------------------------------------------------------------
// Gura llvm module
//-----------------------------------------------------------------------------
#ifndef __MODULE_LLVM_H__
#define __MODULE_LLVM_H__
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Constants.h>
#include <llvm/DerivedTypes.h>
#include <llvm/Instructions.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/ExecutionEngine/Interpreter.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Target/TargetSelect.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/raw_ostream.h>

#include <llvm/Analysis/Verifier.h>
#include <llvm/Support/IRBuilder.h>

#undef GURA_ON_MSWIN
#include <gura.h>

Gura_BeginModuleHeader(llvm, llvm)
Gura_EndModuleHeader(llvm, llvm)

#endif
