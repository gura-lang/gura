//-----------------------------------------------------------------------------
// Gura os module
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include <gura.h>

Gura_BeginModule(os)

static Environment *_pEnvThis = NULL;

//-----------------------------------------------------------------------------
// Gura module functions: os
//-----------------------------------------------------------------------------
// os.redirect(stdin:stream:nil:r, stdout:stream:nil:w, stderr?:stream:w) {block?}
Gura_DeclareFunction(redirect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stdin", VTYPE_stream, OCCUR_Once, FLAG_Nil | FLAG_Read);
	DeclareArg(env, "stdout", VTYPE_stream, OCCUR_Once, FLAG_Nil | FLAG_Write);
	DeclareArg(env, "stderr", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(redirect)
{
	Value *pValue = NULL;
	Value value_stdin, value_stdout, value_stderr;
	if ((pValue = _pEnvThis->LookupValue(Gura_Symbol(stdin), ENVREF_NoEscalate)) != NULL) {
		value_stdin = *pValue;
	}
	if ((pValue = _pEnvThis->LookupValue(Gura_Symbol(stdout), ENVREF_NoEscalate)) != NULL) {
		value_stdout = *pValue;
	}
	if ((pValue = _pEnvThis->LookupValue(Gura_Symbol(stderr), ENVREF_NoEscalate)) != NULL) {
		value_stderr = *pValue;
	}
	_pEnvThis->AssignValue(Gura_Symbol(stdin), args.GetValue(0), EXTRA_Public);
	_pEnvThis->AssignValue(Gura_Symbol(stdout), args.GetValue(1), EXTRA_Public);
	if (args.IsDefined(2)) {
		_pEnvThis->AssignValue(Gura_Symbol(stderr), args.GetValue(2), EXTRA_Public);
	} else {
		_pEnvThis->AssignValue(Gura_Symbol(stderr), args.GetValue(1), EXTRA_Public);
	}
	Value result;
	if (args.IsBlockSpecified()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_local));
		const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
		if (sig.IsSignalled()) return Value::Null;
		result = pExprBlock->Exec2(*pEnvBlock, sig, pSeqPostHandler);
		_pEnvThis->AssignValue(Gura_Symbol(stdin), value_stdin, EXTRA_Public);
		_pEnvThis->AssignValue(Gura_Symbol(stdout), value_stdout, EXTRA_Public);
		_pEnvThis->AssignValue(Gura_Symbol(stderr), value_stderr, EXTRA_Public);
	}
	return result;
}

// os.exec(pathname:string, args*:string):map:[fork,binary]
Gura_DeclareFunction(exec)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareArg(env, "args", VTYPE_string, OCCUR_ZeroOrMore);
	DeclareAttr(Gura_Symbol(fork));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Executes the specified executable file.");
}

Gura_ImplementFunction(exec)
{
	bool forkFlag = args.IsSet(Gura_Symbol(fork));
	const char *pathName = args.GetString(0);
	if (forkFlag) {
		OAL::ExecProgram(env, sig, pathName, args.GetList(1),
										NULL, NULL, forkFlag);
		return Value::Null;
	}
	const Value *pValue = NULL;
	pValue = _pEnvThis->LookupValue(Gura_Symbol(stdout), ENVREF_NoEscalate);
	Stream *pStreamStdout = (pValue != NULL && pValue->IsStream())?
										&pValue->GetStream() : NULL;
	pValue = _pEnvThis->LookupValue(Gura_Symbol(stderr), ENVREF_NoEscalate);
	Stream *pStreamStderr = (pValue != NULL && pValue->IsStream())?
										&pValue->GetStream() : NULL;
	int rtn = OAL::ExecProgram(env, sig, pathName, args.GetList(1),
					pStreamStdout, pStreamStderr, forkFlag);
	if (sig.IsSignalled()) return Value::Null;
	return Value(rtn);
}

// os.fromnative(buff:binary):map
Gura_DeclareFunction(fromnative)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buff", VTYPE_binary);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Converts binary data that includes OS's native string into Gura's regulated string.");
}

Gura_ImplementFunction(fromnative)
{
	const Binary &buff = args.GetBinary(0);
	String str = OAL::FromNativeString(buff.data(), static_cast<int>(buff.size()));
	return Value(env, str.c_str());
}

// os.tonative(str:string):map
Gura_DeclareFunction(tonative)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Converts Gura's regulated string into binary data that includes OS's native string.");
}

Gura_ImplementFunction(tonative)
{
	const char *str = args.GetString(0);
	String buff = OAL::ToNativeString(str);
	return Value(new Object_binary(env, buff.data(), buff.size(), true));
}

// os.getenv(name:string):map
Gura_DeclareFunction(getenv)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns the value of a environment variable.");
}

Gura_ImplementFunction(getenv)
{
	String str = OAL::GetEnv(args.GetString(0));
	return Value(env, str.c_str());
}

// os.putenv(name:string, value:string):void
Gura_DeclareFunction(putenv)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "name", VTYPE_string);
	DeclareArg(env, "value", VTYPE_string);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Set the value of a environment variable.");
}

Gura_ImplementFunction(putenv)
{
	OAL::PutEnv(args.GetString(0), args.GetString(1));
	return Value::Null;
}

// Module entry
Gura_ModuleEntry()
{
	_pEnvThis = &env;
	// value assignment
	Module *pModuleSys = env.GetGlobal()->GetModule_sys();
	do {
		const Value *pValue = pModuleSys->LookupValue(Gura_Symbol(stdin), ENVREF_NoEscalate);
		if (pValue == NULL) pValue = &Value::Null;
		Gura_AssignValue(stdin, *pValue);
	} while (0);
	do {
		const Value *pValue = pModuleSys->LookupValue(Gura_Symbol(stdout), ENVREF_NoEscalate);
		if (pValue == NULL) pValue = &Value::Null;
		Gura_AssignValue(stdout, *pValue);
	} while (0);
	do {
		const Value *pValue = pModuleSys->LookupValue(Gura_Symbol(stderr), ENVREF_NoEscalate);
		if (pValue == NULL) pValue = &Value::Null;
		Gura_AssignValue(stderr, *pValue);
	} while (0);
	// function assignment
	Gura_AssignFunction(redirect);
	Gura_AssignFunction(exec);
	Gura_AssignFunction(fromnative);
	Gura_AssignFunction(tonative);
	Gura_AssignFunction(getenv);
	Gura_AssignFunction(putenv);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(os, os)

Gura_RegisterModule(os)
