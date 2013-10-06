//-----------------------------------------------------------------------------
// Gura basement module
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include <gura.h>

Gura_BeginModule(basement)

#define REPEATER_HELP \
"It returns the last evaluated value in the block as its own result,\n" \
"but, if one of `:list`, `:xlist`, `:set`, `:xset` or `:iter` is specified,\n" \
"it returns a list or evaluated value or an iterator. The rule is as follows.\n" \
"- `:list` - returns a list of result values\n" \
"- `:xlist` - returns a list of result values eliminating `nil`\n" \
"- `:set` - returns a list of unique values of results\n" \
"- `:xset` - returns a list of unique values of results eliminating `nil`\n" \
"- `:iter` - returns an iterator that executes the block\n" \
"- `:xiter` - returns an iterator that executes the block, skipping `nil`\n"

//-----------------------------------------------------------------------------
// Gura module functions: basement
//-----------------------------------------------------------------------------
// class(superclass?) {block?}
Gura_DeclareFunctionAlias(class_, "class")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "superclass", VTYPE_function, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Returns a function object that constructs an instance with methods and\n"
	"properties specified in the block. If superclass, which is supposed to\n"
	"be a constructor function, is specified, the new class shall inherits\n"
	"methods and properties of the class associated with it.");
}

Gura_ImplementFunction(class_)
{
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	Class *pClassSuper = env.LookupClass(VTYPE_object);
	const Value &valueSuper = args.GetValue(0);
	if (valueSuper.IsFunction()) {
		pClassSuper = valueSuper.GetFunction()->GetClassToConstruct();
		if (pClassSuper == NULL) {
			valueSuper.GetFunction()->SetError_NotConstructor(sig);
			return Value::Null;
		}
	}
	CustomClass *pClassCustom = new CustomClass(&env, pClassSuper,
			pClassSuper->GetValueType(),
			dynamic_cast<Expr_Block *>(Expr::Reference(pExprBlock)), sig);
	return Value(pClassCustom);
}

// struct(`args*) {block?}
// if :loose attribute is specified, arguments in the generated function
// will get the following modification.
// - Once attribute will be modified to ZeroOrOnce.
// - OnceOrMore attribute will be modified to ZeroOrMore
Gura_DeclareFunctionAlias(struct_, "struct")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "args", VTYPE_quote, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(loose));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Returns a function object that constructs a structure instance that\n"
	"contains properties specified by args. It can optionally take block\n"
	"which declares some additional methods for constructed instances.\n"
	"If :loose attribute is speicied, the generated constructor function\n"
	"makes an existence check of arguments in a loose way.");
}

Gura_ImplementFunction(struct_)
{
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	Class *pClassSuper = env.LookupClass(VTYPE_Struct);
	CustomClass *pClassCustom = new CustomClass(&env, pClassSuper,
			pClassSuper->GetValueType(),
			dynamic_cast<Expr_Block *>(Expr::Reference(pExprBlock)), sig);
	AutoPtr<ExprOwner> pExprOwnerArg(new ExprOwner());
	foreach_const (ValueList, pValue, args.GetList(0)) {
		pExprOwnerArg->push_back(pValue->GetExpr()->Reference());
	}
	AutoPtr<ConstructorOfStruct> pFunc(new ConstructorOfStruct(env));
	pFunc->SetClassToConstruct(pClassCustom); // constructor is registered in this class
	pFunc->DeclareBlock(OCCUR_ZeroOrOnce);
	//AutoPtr<Args> pArgsSub(new Args(pExprOwnerArg.release(), Value::Null, NULL, false, NULL, args.GetAttrs()));
	AutoPtr<Args> pArgsSub(new Args());
	pArgsSub->SetExprOwnerArg(pExprOwnerArg.release());
	pArgsSub->SetAttrs(args.GetAttrs());
	if (!pFunc->CustomDeclare(env, sig, _attrsOpt, *pArgsSub)) return false;
	if (args.IsSet(Gura_Symbol(loose))) {
		pFunc->GetDeclOwner().SetAsLoose();
	}
	return Value(pClassCustom);
}

// super(obj) {block?}
Gura_DeclareFunction(super)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(super)
{
	Value rtn(args.GetValue(0));
	int cntSuperSkip = rtn.GetSuperSkipCount() + 1;
	if (cntSuperSkip > Value::MaxSuperSkipCount) {
		sig.SetError(ERR_SystemError,
			"number of super reference is limited under %d", Value::MaxSuperSkipCount);
		return Value::Null;
	}
	rtn.SetSuperSkipCount(cntSuperSkip);
	return ReturnValue(env, sig, args, rtn);
}

// nomap(obj) {block?}
Gura_DeclareFunction(nomap)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(nomap)
{
	Value rtn(args.GetValue(0));
	rtn.AddFlags(VFLAG_NoMap);
	return ReturnValue(env, sig, args, rtn);
}

// module {block}
Gura_DeclareFunction(module)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Creates a module that contains functions and variables defined in the block\n"
	"and returns it as a module object. This can be used to realize a namespace.");
}

Gura_ImplementFunction(module)
{
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	Module *pModule = new Module(&env, Gura_Symbol(_anonymous_), "", NULL, NULL);
	pExprBlock->Exec(*pModule, sig);
	return Value(pModule);
}

// import(`module, `alias?):void:[binary,overwrite,mixin_type] {block?}
Gura_DeclareFunctionAlias(import_, "import")
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "module", VTYPE_quote);
	DeclareArg(env, "alias", VTYPE_quote, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(overwrite));
	DeclareAttr(Gura_Symbol(binary));
	DeclareAttr(Gura_Symbol(mixin_type));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Imports a module stored in directories specified by a variable sys.path.\n"
	"There are three ways of calling this function like follow:\n"
	"\n"
	"1. `import(foo)`\n"
	"2. `import(foo, bar)`\n"
	"3. `import(foo) {symbol1, symbol2, symbol3}`\n"
	"\n"
	"In the first format, it creates a module object named foo.\n"
	"In the second, it names the module object as bar instead of foo.\n"
	"In the third, it doesn't register the module name into the environment,\n"
	"but it looks up symbols specified in the block and registers them.\n"
	"In thie case, if specified symbols conflict with the existing one,\n"
	"it will cause an error. Attribute `:overwrite` will disable such an error\n"
	"detection and allow overwriting of symbols. You can specify an asterisk\n"
	"character to include all the registered symbols like follows.\n"
	"\n"
	"    import(foo) {*}");
}

Gura_ImplementFunction(import_)
{
	SymbolSet symbolsToMixIn;
	SymbolSet *pSymbolsToMixIn = NULL;
	if (args.IsBlockSpecified()) {
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		foreach_const (ExprList, ppExpr, pExprBlock->GetExprOwner()) {
			if (!(*ppExpr)->IsSymbol()) {
				sig.SetError(ERR_SyntaxError,
					"wrong format for an element in import list");
				return Value::Null;
			}
			const Expr_Symbol *pExprSymbol =
							dynamic_cast<const Expr_Symbol *>(*ppExpr);
			symbolsToMixIn.insert(pExprSymbol->GetSymbol());
		}
		pSymbolsToMixIn = &symbolsToMixIn;
	}
	const Symbol *pSymbol = NULL;
	if (!args.IsExpr(1)) {
		// nothing to do
	} else if (!args.GetExpr(1)->IsSymbol()) {
		sig.SetError(ERR_ValueError, "symbol is expected as a module name");
		return Value::Null;
	} else {
		pSymbol =
			dynamic_cast<const Expr_Symbol *>(args.GetExpr(1))->GetSymbol();
	}
	bool overwriteFlag = args.IsSet(Gura_Symbol(overwrite));
	bool binaryOnlyFlag = args.IsSet(Gura_Symbol(binary));
	bool mixinTypeFlag = args.IsSet(Gura_Symbol(mixin_type));
	if (!env.ImportModule(sig, args.GetExpr(0), pSymbol, pSymbolsToMixIn,
								overwriteFlag, binaryOnlyFlag, mixinTypeFlag)) {
		return Value::Null;
	}
	return Value::Null;
}

// eval(expr:expr):map
Gura_DeclareFunction(eval)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expr", VTYPE_expr);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Evaluate an expr object.");
}

Gura_ImplementFunction(eval)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	return args.GetExpr(0)->Exec(*pEnvBlock, sig);
}

// scope(target?) {block}
Gura_DeclareFunction(scope)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Evaluates block with a local scope.");
}

Gura_ImplementFunction(scope)
{
	if (args.IsInvalid(0)) {
		AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_local));
		const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
		if (sig.IsSignalled()) return Value::Null;
		return pExprBlock->Exec(*pEnvBlock, sig);
	} else {
		Environment *pEnv = NULL;
		if (args.IsModule(0)) {
			pEnv = args.GetModule(0);
		} else if (args.IsClass(0)) {
			pEnv = args.GetClass(0);
		} else if (args.IsFunction(0)) {
			pEnv = args.GetFunction(0)->GetClassToConstruct();
		} else if (args.IsType(0, VTYPE_environment)) {
			pEnv = &Object_environment::GetObject(args, 0)->GetEnv();
		}
		if (pEnv != NULL) {
			const Expr_Block *pExprBlock = args.GetBlock(*pEnv, sig);
			if (sig.IsSignalled()) return Value::Null;
			return pExprBlock->Exec(*pEnv, sig);
		}
	}
	sig.SetError(ERR_ValueError, "module or environment must be specified");
	return Value::Null;
}

// locals(module?:module) {block?}
Gura_DeclareFunction(locals)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "module", VTYPE_Module, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Returns an environment object that belongs to a specified module.\n"
	"If module is omitted, it returns an environment object of the current scope.");
}

Gura_ImplementFunction(locals)
{
	Value value;
	if (args.IsModule(0)) {
		value = Value(new Object_environment(*args.GetModule(0)));
	} else {
		value = Value(new Object_environment(env));
	}
	return ReturnValue(env, sig, args, value);
}

// outers() {block?}
Gura_DeclareFunction(outers)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Returns an environment object that accesses to an outer scope.");
}

Gura_ImplementFunction(outers)
{
	AutoPtr<Environment> pEnvOuter(new Environment());
	pEnvOuter->AddOuterFrame(env.GetFrameOwner());
	return ReturnValue(env, sig, args, Value(new Object_environment(*pEnvOuter)));
}

// extern(`syms+)
Gura_DeclareFunctionAlias(extern_, "extern")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "syms", VTYPE_quote, OCCUR_OnceOrMore);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Declares symbols that is supposed to access variables in outer scopes.");
}

Gura_ImplementFunction(extern_)
{
	foreach_const (ValueList, pValue, args.GetList(0)) {
		const Expr *pExpr = pValue->GetExpr();
		if (!pExpr->IsSymbol()) {
			sig.SetError(ERR_ValueError, "symbol must be specified");
			return Value::Null;
		}
		const Symbol *pSymbol = dynamic_cast<const Expr_Symbol *>(pExpr)->GetSymbol();
		if (env.LookupValue(pSymbol, ENVREF_Escalate) == NULL) {
			sig.SetError(ERR_ValueError, "undefined symbol '%s'", pSymbol->GetName());
		}
	}
	return Value::Null;
}

// local(`syms+)
Gura_DeclareFunction(local)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "syms", VTYPE_quote, OCCUR_OnceOrMore);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Declares symbols that is supposed to access variables in a local scope.");
}

Gura_ImplementFunction(local)
{
	foreach_const (ValueList, pValue, args.GetList(0)) {
		const Expr *pExpr = pValue->GetExpr();
		if (!pExpr->IsSymbol()) {
			sig.SetError(ERR_ValueError, "symbol must be specified");
			return Value::Null;
		}
		const Symbol *pSymbol = dynamic_cast<const Expr_Symbol *>(pExpr)->GetSymbol();
		if (env.LookupValue(pSymbol, ENVREF_NoEscalate) == NULL) {
			env.AssignValue(pSymbol, Value::Null, EXTRA_Public);
		}
	}
	return Value::Null;
}

// public():void {block}
Gura_DeclareFunctionAlias(public_, "public")
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementFunction(public_)
{
	SymbolSet &symbolsPublic = env.PrepareSymbolsPublic();
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	foreach_const (ExprOwner, ppExpr, pExprBlock->GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		if (pExpr->IsSymbol()) {
			const Expr_Symbol *pExprSymbol = dynamic_cast<const Expr_Symbol *>(pExpr);
			symbolsPublic.Insert(pExprSymbol->GetSymbol());
		} else if (pExpr->IsAssign()) {
			const Expr_Assign *pExprAssign = dynamic_cast<const Expr_Assign *>(pExpr);
			if (!pExprAssign->GetLeft()->IsSymbol()) {
				sig.SetError(ERR_ValueError, "invalid element for public");
				return Value::Null;
			}
			const Expr_Symbol *pExprSymbol = dynamic_cast<const Expr_Symbol *>(pExprAssign->GetLeft());
			symbolsPublic.Insert(pExprSymbol->GetSymbol());
			pExpr->Exec(env, sig);
			if (sig.IsSignalled()) return Value::Null;
		} else {
			sig.SetError(ERR_ValueError, "invalid element for public");
			return Value::Null;
		}
	}
	return Value::Null;
}

// try ():leader {block}
Gura_DeclareFunctionAlias(try_, "try")
{
	SetMode(RSLTMODE_Normal, FLAG_Leader);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Specify a try block of a statement of try-catch-else.\n"
	"It catches signals that occur in the block and executes a corresponding\n"
	"catch() or else() function that follow after it.");
}

Gura_ImplementFunction(try_)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
	if (sig.IsSignalled()) return Value::Null;
	Value result = pExprBlock->Exec(*pEnvBlock, sig);
	if (sig.IsError()) {
		sig.SuspendError();
	} else {
		//args.FinalizeTrailer();
	}
	return result;
}

// catch (errors*:error):leader:trailer {block}
Gura_DeclareFunctionTrailerAlias(catch_, "catch")
{
	SetMode(RSLTMODE_Normal, FLAG_Leader | FLAG_Trailer);
	DeclareArg(env, "errors", VTYPE_error, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Specify an catch block of a statement of try-catch-else.\n"
	"It can take multiple numbers of arguments of error objects to handle.\n"
	"If there's no error objects specified, it handles all the errors that are\n"
	"not handled in the preceding catch() function calls.\n"
	"Block parameter format: |error:error|\n"
	"error is an error object that contains information of the handled error.");
}

Gura_ImplementFunction(catch_)
{
	if (!sig.IsErrorSuspended()) return Value::Null;
	bool handleFlag = false;
	if (args.GetList(0).empty()) {
		handleFlag = true;
	} else {
		foreach_const (ValueList, pValue, args.GetList(0)) {
			if (pValue->GetErrorType() == sig.GetError().GetType()) {
				handleFlag = true;
				break;
			}
		}
	}
	if (!handleFlag) return Value::Null;
	//args.FinalizeTrailer();
	args.QuitTrailer();
	Object_error *pObj = new Object_error(env, sig.GetError());
	sig.ClearSignal(); // clear even the suspended state
	const Function *pFuncBlock =
						args.GetBlockFunc(env, sig, GetSymbolForBlock());
	if (sig.IsSignalled()) return Value::Null;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	AutoPtr<Args> pArgsSub(new Args());
	pArgsSub->SetValue(Value(pObj));
	return pFuncBlock->Eval(*pEnvBlock, sig, *pArgsSub);
}

// finally ():trailer:finalizer {block}
Gura_DeclareFunctionTrailerAlias(finally_, "finally")
{
	SetMode(RSLTMODE_Normal, FLAG_Trailer | FLAG_Finalizer);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementFunction(finally_)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
	if (sig.IsSignalled()) return Value::Null;
	return pExprBlock->Exec(*pEnvBlock, sig);
}

// if (`cond):leader {block}
Gura_DeclareFunctionAlias(if_, "if")
{
	SetMode(RSLTMODE_Normal, FLAG_Leader);
	DeclareArg(env, "cond", VTYPE_quote);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Specify an if block of a statement of if-elsif-else.\n"
	"After evaluating an expr object cond, the block shall be executed\n"
	"if it has a value of true.");
}

Gura_ImplementFunction(if_)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	Value value = args.GetExpr(0)->Exec(*pEnvBlock, sig);
	if (value.GetBoolean()) {
		args.QuitTrailer();
		const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
		if (sig.IsSignalled()) return Value::Null;
		return pExprBlock->Exec(*pEnvBlock, sig);
	}
	return Value::Null;
}

// elsif (`cond):leader:trailer {block}
Gura_DeclareFunctionTrailerAlias(elsif_, "elsif")
{
	SetMode(RSLTMODE_Normal, FLAG_Leader | FLAG_Trailer);
	DeclareArg(env, "cond", VTYPE_quote);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Specify an elsif block of a statement of if-elsif-else.\n"
	"After evaluating an expr object cond, the block shall be executed\n"
	"if it has a value of true.");
}

Gura_ImplementFunction(elsif_)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	Value value = args.GetExpr(0)->Exec(*pEnvBlock, sig);
	if (value.GetBoolean()) {
		const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
		if (sig.IsSignalled()) return Value::Null;
		args.QuitTrailer();
		return pExprBlock->Exec(*pEnvBlock, sig);
	}
	return Value::Null;
}

// else ():trailer {block}
Gura_DeclareFunctionTrailerAlias(else_, "else")
{
	SetMode(RSLTMODE_Normal, FLAG_Trailer);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Specify an else block of a statement of if-elsif-else or try-catch-else.\n");
}

Gura_ImplementFunction(else_)
{
	// this function works as a terminater of if-else and try-catch
	if (sig.IsErrorSuspended()) return Value::Null;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
	if (sig.IsSignalled()) return Value::Null;
	return pExprBlock->Exec(*pEnvBlock, sig);
}

// end ():void:symbol_func:trailer:end_marker
Gura_DeclareFunction(end)
{
	SetMode(RSLTMODE_Void, FLAG_SymbolFunc | FLAG_Trailer | FLAG_EndMarker);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Specify an end of a sequence. It just works as a marker.\n");
}

Gura_ImplementFunction(end)
{
	return Value::Null;
}

// switch {block}
Gura_DeclareFunctionAlias(switch_, "switch")
{
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Form a switch block that contains case() and default() function calls.\n"
	"It calls these functions sequentially and exits the execution\n"
	"when one of the conditions is evaluated as true.");
}

Gura_ImplementFunction(switch_)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));;
	const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
	if (sig.IsSignalled()) return Value::Null;
	pExprBlock->Exec(*pEnvBlock, sig);
	if (sig.IsSwitchDone()) {
		Value result = sig.GetValue();
		sig.ClearSignal();
		return result;
	}
	return Value::Null;
}

// case (`cond) {block}
Gura_DeclareFunctionAlias(case_, "case")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "cond", VTYPE_quote);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Specify an case block within a switch block.\n"
	"After evaluating an expr object cond, the block shall be executed\n"
	"if it has a value of true.");
}

Gura_ImplementFunction(case_)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	Value value = args.GetExpr(0)->Exec(*pEnvBlock, sig);
	if (value.GetBoolean()) {
		const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
		if (sig.IsSignalled()) return Value::Null;
		Value result = pExprBlock->Exec(*pEnvBlock, sig);
		if (sig.IsSignalled()) return Value::Null;
		sig.SetSignal(SIGTYPE_SwitchDone, result);
		return result;
	}
	return Value::Null;
}

// default {block}
Gura_DeclareFunctionAlias(default_, "default")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Specify a default block within a switch block.\n"
	"If all the preceding condition of case block are not evaluated as true,\n"
	"this block shall be executed.\n");
}

Gura_ImplementFunction(default_)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Expr_Block *pExprBlock = args.GetBlock(*pEnvBlock, sig);
	if (sig.IsSignalled()) return Value::Null;
	Value result = pExprBlock->Exec(*pEnvBlock, sig);
	if (sig.IsSignalled()) return Value::Null;
	sig.SetSignal(SIGTYPE_SwitchDone, result);
	return result;
}

// repeat (n?:number) {block}
Gura_DeclareFunction(repeat)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Executes the block for n times. If n is omitted, it repeats the block\n"
	"execution forever.\n"
	"\n"
	REPEATER_HELP
	"\n"
	"Block parameter format: |idx:number|");
}

Gura_ImplementFunction(repeat)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
						args.GetBlockFunc(*pEnvBlock, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) return Value::Null;
	bool standaloneFlag = (args.IsRsltIterator() || args.IsRsltXIterator());
	Iterator *pIterator = new Iterator_repeat(pEnvBlock->Reference(), sig, Function::Reference(pFuncBlock),
			args.IsRsltXIterator(), standaloneFlag,
			args.IsNumber(0)? args.GetInt(0) : -1);
	return DoRepeater(env, sig, args, pIterator);
}

// while (`cond) {block}
Gura_DeclareFunctionAlias(while_, "while")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "cond", VTYPE_quote);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Executes the block while the evaluation result of cond is true.\n"
	"\n"
	REPEATER_HELP
	"\n"
	"Block parameter format: |idx:number|");
}

Gura_ImplementFunction(while_)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
						args.GetBlockFunc(*pEnvBlock, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) return Value::Null;
	bool standaloneFlag = (args.IsRsltIterator() || args.IsRsltXIterator());
	Iterator *pIterator = new Iterator_while(pEnvBlock->Reference(), sig, Function::Reference(pFuncBlock),
			args.IsRsltXIterator(), standaloneFlag, Expr::Reference(args.GetExpr(0)));
	return DoRepeater(env, sig, args, pIterator);
}

// for (`expr+) {block}
Gura_DeclareFunctionAlias(for_, "for")
{
	DeclareArg(env, "expr", VTYPE_quote, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Executes the block until any of the exprs of \"var in iteratable\" reach at\n"
	"their ends. You can specify one or more such exprs as arguments.\n"
	"Iterators and lists are the most popular iteratables, but even any objects that\n"
	"are cable of generating iterators can be specified as such.\n"
	"\n"
	REPEATER_HELP
	"\n"
	"Block parameter format: |idx:number|");
}

Gura_ImplementFunction(for_)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
						args.GetBlockFunc(*pEnvBlock, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) return Value::Null;
	bool standaloneFlag = (args.IsRsltIterator() || args.IsRsltXIterator());
	Iterator *pIterator = new Iterator_for(pEnvBlock->Reference(), sig, Function::Reference(pFuncBlock),
				args.IsRsltXIterator(), standaloneFlag, args.GetList(0));
	return DoRepeater(env, sig, args, pIterator);
}

// cross (`expr+) {block}
Gura_DeclareFunction(cross)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "expr", VTYPE_quote, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Executes the block until it evaluates all the combinations of results from exprs\n"
	"\"var in iteratable.\" You can specify one or more such exprs as arguments and\n"
	"they are counted up from the one on the right side.\n"
	"Iterators and lists are the most popular iteratables, but even any objects that\n"
	"are cable of generating iterators can be specified as such.\n"
	"\n"
	REPEATER_HELP
	"\n"
	"Block parameter format: |idx:number, i0:number, i1:number, ..|");
}

Gura_ImplementFunction(cross)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
						args.GetBlockFunc(*pEnvBlock, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) return Value::Null;
	bool standaloneFlag = (args.IsRsltIterator() || args.IsRsltXIterator());
	Iterator *pIterator = new Iterator_cross(pEnvBlock->Reference(), sig, Function::Reference(pFuncBlock),
				args.IsRsltXIterator(), standaloneFlag, args.GetList(0));
	return DoRepeater(env, sig, args, pIterator);
}

// break(value?):void:symbol_func
Gura_DeclareFunctionAlias(break_, "break")
{
	SetMode(RSLTMODE_Void, FLAG_SymbolFunc);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Exits from an inside of a loop that is formed with functions repeat(), while()\n"
	"for() and cross(). If it takes an argument, that value is treated as a result of\n"
	"the loop function. Otherwise, the result is nil and an argument list\n"
	"can be omitted. If the loop function is specified with one of :list, :xlist, :set,\n"
	":xset, :iter and :xiter, break()'s value is NOT included in the result.");
}

Gura_ImplementFunction(break_)
{
	sig.SetSignal(SIGTYPE_Break, args.GetValue(0));
	return Value::Null;
}

// continue(value?):void:symbol_func
Gura_DeclareFunctionAlias(continue_, "continue")
{
	SetMode(RSLTMODE_Void, FLAG_SymbolFunc);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"In a loop that is formed with functions repeat(), while(), for() and cross(),\n"
	"skips the following part of it and gets to the top of its process.\n"
	"If it takes an argument, that value is treated as a result of the loop function.\n"
	"Otherwise, the result is nil and an argument list can be omitted.\n"
	"If the loop function is specified with one of :list, :xlist, :set,\n"
	":xset, :iter and :xiter, continue()'s value is included in the result.");
}

Gura_ImplementFunction(continue_)
{
	sig.SetSignal(SIGTYPE_Continue, args.GetValue(0));
	return Value::Null;
}

// return(value?):void:symbol_func
Gura_DeclareFunctionAlias(return_, "return")
{
	SetMode(RSLTMODE_Void, FLAG_SymbolFunc);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Exits from a function skipping the following part of it.\n"
	"If it takes an argument, that value is treated as a result of the function.\n"
	"Otherwise, the result is nil and an argument list can be omitted.");
}

Gura_ImplementFunction(return_)
{
	sig.SetSignal(SIGTYPE_Return, args.GetValue(0));
	return Value::Null;
}

// raise(error:error, msg:string => "error", value?)
Gura_DeclareFunction(raise)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "error", VTYPE_error);
	DeclareArg(env, "msg", VTYPE_string, OCCUR_Once, FLAG_None, new Expr_String("error"));
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Raises an error signal with a specified error object, a message string and\n"
	"an additional value.");
}

Gura_ImplementFunction(raise)
{
	sig.SetError(args.GetErrorType(0), "%s", args.GetString(1));
	sig.SetValue(args.GetValue(2));
	return Value::Null;
}

// dim(n+:number) {block}
Gura_DeclareFunction(dim)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Creates and returns a multi-dementional list that contains nested lists as\n"
	"specified by the arguments.\n"
	"Block parameter format: |i0:number, i1:number, ..|");
}

bool Func_dim_Sub(Environment &env, Signal sig, const Function *pFuncBlock, ValueList &valListParent,
	IntList &cntList, IntList::iterator pCnt, IntList &idxList, IntList::iterator pIdx)
{
	if (pCnt + 1 == cntList.end()) {
		if (pFuncBlock == NULL) {
			for (*pIdx = 0; *pIdx < *pCnt; (*pIdx)++) {
				valListParent.push_back(Value::Null);
			}
		} else {
			for (*pIdx = 0; *pIdx < *pCnt; (*pIdx)++) {
				AutoPtr<Args> pArgs(new Args());
				pArgs->ReserveValueListArg(idxList.size());
				foreach (IntList, pIdxWk, idxList) {
					pArgs->AddValue(Value(*pIdxWk));
				}
				Value result = pFuncBlock->Eval(env, sig, *pArgs);
				if (sig.IsSignalled()) return false;
				valListParent.push_back(result);
			}
		}
	} else {
		for (*pIdx = 0; *pIdx < *pCnt; (*pIdx)++) {
			Value result;
			ValueList &valList = result.InitAsList(env);
			valListParent.push_back(result);
			if (!Func_dim_Sub(env, sig, pFuncBlock, valList,
									cntList, pCnt + 1, idxList, pIdx + 1)) {
				return false;
			}
		}
	}
	return true;
}

Gura_ImplementFunction(dim)
{
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
						args.GetBlockFunc(*pEnvBlock, sig, GetSymbolForBlock());
	const ValueList &valListArg = args.GetList(0);
	size_t nArgs = valListArg.size();
	IntList cntList, idxList;
	cntList.reserve(nArgs);
	idxList.reserve(nArgs);
	foreach_const (ValueList, pValArg, valListArg) {
		cntList.push_back(pValArg->GetInt());
		idxList.push_back(0);
	}
	Value result;
	ValueList &valList = result.InitAsList(env);
	if (!Func_dim_Sub(*pEnvBlock, sig, pFuncBlock, valList,
						cntList, cntList.begin(), idxList, idxList.begin())) {
		return Value::Null;
	}
	return result;
}

// min(values+):map
Gura_DeclareFunction(min)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_OnceOrMore);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Returns the minimum value among the given arguments.");
}

Gura_ImplementFunction(min)
{
	const ValueList &valList = args.GetList(0);
	ValueList::const_iterator pValue = valList.begin();
	Value result = *pValue++;
	for ( ; pValue != valList.end(); pValue++) {
		int cmp = Value::Compare(result, *pValue);
		if (cmp > 0) result = *pValue;
	}
	return result;
}

// max(values+):map
Gura_DeclareFunction(max)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_OnceOrMore);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Returns the maximum value among the given arguments.");
}

Gura_ImplementFunction(max)
{
	const ValueList &valList = args.GetList(0);
	ValueList::const_iterator pValue = valList.begin();
	Value result = *pValue++;
	for ( ; pValue != valList.end(); pValue++) {
		int cmp = Value::Compare(result, *pValue);
		if (cmp < 0) result = *pValue;
	}
	return result;
}

// choose(index:number, values+):map
Gura_DeclareFunction(choose)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number);
	DeclareArg(env, "values", VTYPE_any, OCCUR_OnceOrMore);
}

Gura_ImplementFunction(choose)
{
	size_t index = args.GetSizeT(0);
	const ValueList &valList = args.GetList(1);
	if (index >= valList.size()) {
		sig.SetError(ERR_IndexError, "index is out of range");
		return Value::Null;
	}
	return valList[index];
}

// cond(flag:boolean, value1:nomap, value2:nomap?):map
Gura_DeclareFunction(cond)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean);
	DeclareArg(env, "value1", VTYPE_any, OCCUR_Once, FLAG_NoMap);
	DeclareArg(env, "value2", VTYPE_any, OCCUR_ZeroOrOnce, FLAG_NoMap);
}

Gura_ImplementFunction(cond)
{
	return args.GetBoolean(0)? args.GetValue(1) : args.GetValue(2);
}

// conds(flag:boolean, value1, value2?):map
Gura_DeclareFunction(conds)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean);
	DeclareArg(env, "value1", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "value2", VTYPE_any, OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(conds)
{
	return args.GetBoolean(0)? args.GetValue(1) : args.GetValue(2);
}

// tostring(value):map
Gura_DeclareFunction(tostring)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_any);
}

Gura_ImplementFunction(tostring)
{
	return Value(env, args.GetValue(0).ToString(sig, false).c_str());
}

// tonumber(value):map:[strict,raise,zero,nil]
Gura_DeclareFunction(tonumber)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_any);
	DeclareAttr(Gura_Symbol(strict));
	DeclareAttr(Gura_Symbol(raise));
	DeclareAttr(Gura_Symbol(zero));
	DeclareAttr(Gura_Symbol(nil));
}

Gura_ImplementFunction(tonumber)
{
	bool allowPartFlag = !args.IsSet(Gura_Symbol(strict));
	bool successFlag;
	Number num = args.GetValue(0).ToNumber(allowPartFlag, successFlag);
	if (successFlag) {
		return Value(num);
	} else if (args.IsSet(Gura_Symbol(raise))) {
		sig.SetError(ERR_ValueError, "failed to convert to a number");
		return Value::Null;
	} else if (args.IsSet(Gura_Symbol(zero))) {
		return Value(0.);
	} else { // args.IsSet(Gura_UserSymbol(nil)
		return Value::Null;
	}
}

// tosymbol(str:string):map
Gura_DeclareFunction(tosymbol)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
}

Gura_ImplementFunction(tosymbol)
{
	return Value(Symbol::Add(args.GetString(0)));
}

// int(value):map
Gura_DeclareFunctionAlias(int_, "int")
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Converts any value into an integer number.");
}

Gura_ImplementFunction(int_)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		result.SetNumber(value.GetLong());
	} else if (value.IsComplex()) {
		result.SetNumber(static_cast<long>(std::abs(value.GetComplex())));
	} else if (value.IsString()) {
		bool successFlag;
		Number num = value.ToNumber(true, successFlag);
		if (!successFlag) {
			sig.SetError(ERR_ValueError, "failed to convert to a number");
			return Value::Null;
		}
		result.SetNumber(static_cast<long>(num));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// ord(str:string):map
Gura_DeclareFunction(ord)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
}

Gura_ImplementFunction(ord)
{
	const char *str = args.GetString(0);
	ULong num = static_cast<UChar>(*str);
	if (IsUTF8First(*str)) {
		str++;
		for ( ; IsUTF8Follower(*str); str++) {
			num = (num << 8) | static_cast<UChar>(*str);
		}
	}
	return Value(num);
}

// chr(num:number):map
Gura_DeclareFunction(chr)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_number);
}

Gura_ImplementFunction(chr)
{
	ULong num = args.GetULong(0);
	int i = 0;
	char buff[4];
	buff[i++] = static_cast<UChar>(num & 0xff);
	num >>= 8;
	for ( ; num != 0; num >>= 8) {
		buff[i++] = static_cast<UChar>(num & 0xff);
	}
	String str;
	for ( ; i > 0; i--) {
		str.push_back(buff[i - 1]);
	}
	return Value(env, str.c_str());
}

// hex(num:number, digits?:number):map:[upper]
Gura_DeclareFunction(hex)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_number);
	DeclareArg(env, "digits", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(upper));
}

Gura_ImplementFunction(hex)
{
	int digits = args.IsNumber(1)? args.GetInt(1) : 0;
	bool upperFlag = args.IsSet(Gura_Symbol(upper));
	String str;
	if (digits <= 0) {
		str = Formatter::Format(sig, upperFlag? "%X" : "%x",
						ValueList(args.GetValue(0)));
	} else {
		str = Formatter::Format(sig, upperFlag? "%0*X" : "%0*x",
						ValueList(Value(digits), args.GetValue(0)));
	}
	if (sig.IsSignalled()) return Value::Null;
	return Value(env, str.c_str());
}

// print(value*):map:void
Gura_DeclareFunction(print)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Converts `values` into string and outputs the results to standard output."
	);
}

Gura_ImplementFunction(print)
{
	Stream *pConsole = env.GetConsole();
	if (pConsole == NULL) return Value::Null;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		pConsole->Print(sig, pValue->ToString(sig, false).c_str());
		if (sig.IsSignalled()) break;
	}
	return Value::Null;
}

// println(value*):map:void
Gura_DeclareFunction(println)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Converts `values` into string and outputs the results to standard output before a carriage return."
	);
}

Gura_ImplementFunction(println)
{
	Stream *pConsole = env.GetConsole();
	if (pConsole == NULL) return Value::Null;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		pConsole->Print(sig, pValue->ToString(sig, false).c_str());
		if (sig.IsSignalled()) break;
	}
	pConsole->Print(sig, "\n");
	return Value::Null;
}

// printf(format, values*):map:void
Gura_DeclareFunction(printf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Converts `values` into string depending on formatter specification in `format` and outputs the result to standard output.\n"
	"The format specifier comes like `%[flags][width][.precision]specifier`.\n"
	"\n"
	"`specifier` is one of the following.\n"
	"\n"
	"- `d`, `i` .. decimal integer number with a sign mark\n"
	"- `u` .. decimal integer number wihout a sign mark\n"
	"- `b` .. binary integer number without a sign mark\n"
	"- `o` .. octal integer number without a sign mark\n"
	"- `x` .. hexadecimal integer number in lower character without a sign mark\n"
	"- `X` .. hexadecimal integer number in upper character without a sign mark\n"
	"- `e` .. floating number in exponential form\n"
	"- `E` .. floating number in exponential form (in upper character)\n"
	"- `f` .. floating number in decimal form\n"
	"- `F` .. floating number in decimal form (in upper character)\n"
	"- `g` .. better form between `e` and `f`\n"
	"- `G` .. better form between `E` and `F`\n"
	"- `s` .. string\n"
	"- `c` .. character\n"
	"\n"
	"`flags` is one of the following.\n"
	"\n"
	"- `+` .. `+` precedes for positive numbers\n"
	"- `-` .. adjust a string to left\n"
	"- `[SPC]` .. space character precedes for positive numbers\n"
	"- `#` .. converted results of binary, octdecimal and hexadecimal are preceded by `'0b'`, `'0'` and `'0x'` respectively\n"
	"- `0` .. fill lacking columns with `'0'`\n"
	);
}

Gura_ImplementFunction(printf)
{
	Stream *pConsole = env.GetConsole();
	if (pConsole == NULL) return Value::Null;
	pConsole->Printf(sig, args.GetString(0), args.GetList(1));
	return Value::Null;
}

// format(format, value*):map
Gura_DeclareFunction(format)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(format)
{
	return Value(env, Formatter::Format(sig, args.GetString(0), args.GetList(1)));
}

// dir(obj?):[noesc]
Gura_DeclareFunction(dir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(noesc));
	//DeclareAttr(Gura_Symbol(nosort));
}

Gura_ImplementFunction(dir)
{
	bool escalateFlag = !args.IsSet(Gura_Symbol(noesc));
	bool sortFlag = !args.IsSet(Gura_Symbol(nosort));
	SymbolList symbolList;
	if (args.IsValid(0)) {
		SymbolSet symbols;
		if (!args.GetValue(0).DirProp(env, sig, symbols, escalateFlag)) return Value::Null;
		foreach_const (SymbolSet, ppSymbol, symbols) {
			const Symbol *pSymbol = *ppSymbol;
			symbolList.push_back(pSymbol);
		}
	} else {
		foreach_const (ValueMap, iter, env.GetBottomFrame()->GetValueMap()) {
			const Symbol *pSymbol = iter->first;
			symbolList.push_back(pSymbol);
		}
	}
	if (sortFlag) symbolList.SortByName();
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(symbolList.size());
	foreach_const (SymbolList, ppSymbol, symbolList) {
		const Symbol *pSymbol = *ppSymbol;
		valList.push_back(Value(pSymbol));
	}
	return result;
}

// dirtype(obj?):[noesc]
Gura_DeclareFunction(dirtype)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(noesc));
	//DeclareAttr(Gura_Symbol(nosort));
}

Gura_ImplementFunction(dirtype)
{
	bool escalateFlag = !args.IsSet(Gura_Symbol(noesc));
	bool sortFlag = !args.IsSet(Gura_Symbol(nosort));
	SymbolList symbolList;
	if (args.IsValid(0)) {
		SymbolSet symbols;
		args.GetValue(0).DirValueType(symbols, escalateFlag);
		foreach_const (SymbolSet, ppSymbol, symbols) {
			const Symbol *pSymbol = *ppSymbol;
			symbolList.push_back(pSymbol);
		}
	} else {
		foreach_const (ValueTypeMap, iter, env.GetBottomFrame()->GetValueTypeMap()) {
			const Symbol *pSymbol = iter->first;
			symbolList.push_back(pSymbol);
		}
	}
	if (sortFlag) symbolList.SortByName();
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(symbolList.size());
	foreach_const (SymbolList, ppSymbol, symbolList) {
		const Symbol *pSymbol = *ppSymbol;
		valList.push_back(Value(pSymbol));
	}
	return result;
}

// help(func:function, lang?:symbol):map:void
Gura_DeclareFunction(help)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	DeclareArg(env, "lang", VTYPE_symbol, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Print a help message for the specified function object.");
}

Gura_ImplementFunction(help)
{
	Object_function *pFuncObj = Object_function::GetObject(args, 0);
	const Symbol *pSymbol = args.IsSymbol(1)? args.GetSymbol(1) : NULL;
	HelpPresenter::Present(env, sig, pFuncObj->ToString(sig, true).c_str(),
									pFuncObj->GetFunction()->GetHelp(pSymbol));
	return Value::Null;
}

// isdefined(`symbol)
Gura_DeclareFunction(isdefined)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_quote);
}

Gura_ImplementFunction(isdefined)
{
	bool definedFlag = false;
	const Expr *pExpr = args.GetExpr(0);
	if (pExpr->IsSymbol() || pExpr->IsMember()) {
		Value result = pExpr->Exec(env, sig);
		if (sig.IsSignalled() && !sig.IsError()) return Value::Null;
		definedFlag = !sig.IsError() && result.IsDefined();
		sig.ClearSignal();
	} else {
		sig.SetError(ERR_ValueError, "argument must be a symbol");
		return Value::Null;
	}
	return Value(definedFlag);
}

// istype*(value)
class Gura_Function(istype_) : public Function {
private:
	ValueType _valType;
public:
	Gura_Function(istype_)(Environment &env, const char *name, ValueType valType);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};
Gura_Function(istype_)::Gura_Function(istype_)(
					Environment &env, const char *name, ValueType valType) :
	Function(env, Symbol::Add(name), FUNCTYPE_Function, FLAG_None), _valType(valType)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	char buff[1024];
	::sprintf(buff, "Check if the type of the specified value is %s.",
		ValueTypePool::GetInstance()->Lookup(_valType)->MakeFullName().c_str());
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, buff);
}

Gura_ImplementFunction(istype_)
{
	ValueType valType = args.GetValue(0).GetValueType();
	ValueType valTypeCmp = _valType;
	if ((valType == VTYPE_number || valType == VTYPE_fraction) &&
								valTypeCmp == VTYPE_complex) return Value(true);
	if (valType == VTYPE_fraction && valTypeCmp == VTYPE_number) return Value(true);
	return Value(valType == valTypeCmp);
}

// istype(value, type+:expr):map
Gura_DeclareFunction(istype)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_any);
	DeclareArg(env, "type", VTYPE_expr, OCCUR_OnceOrMore);
}

Gura_ImplementFunction(istype)
{
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, args.GetList(1));
	if (pValueTypeInfo == NULL) return Value::Null;
	ValueType valType = args.GetValue(0).GetValueType();
	ValueType valTypeCmp = pValueTypeInfo->GetValueType();
	if ((valType == VTYPE_number || valType == VTYPE_fraction) &&
								valTypeCmp == VTYPE_complex) return Value(true);
	if (valType == VTYPE_fraction && valTypeCmp == VTYPE_number) return Value(true);
	return Value(valType == valTypeCmp);
}

// isinstance(value, type+:expr):map
Gura_DeclareFunction(isinstance)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_any);
	DeclareArg(env, "type", VTYPE_expr, OCCUR_OnceOrMore);
}

Gura_ImplementFunction(isinstance)
{
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, args.GetList(1));
	if (pValueTypeInfo == NULL) return Value::Null;
	return args.GetValue(0).IsInstanceOf(pValueTypeInfo->GetValueType());
}

// classref(type+:expr):map {block?}
Gura_DeclareFunction(classref)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "type", VTYPE_expr, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(classref)
{
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, args.GetList(0));
	if (pValueTypeInfo == NULL) return Value::Null;
	if (pValueTypeInfo->GetClass() == NULL) {
		sig.SetError(ERR_ValueError, "not a class type");
		return Value::Null;
	}
	Value result(Class::Reference(pValueTypeInfo->GetClass()));
	return ReturnValue(env, sig, args, result);
}

// typename(`value)
Gura_DeclareFunctionAlias(typename_, "typename")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_quote);
}

Gura_ImplementFunction(typename_)
{
	const Expr *pExpr = args.GetExpr(0);
	String typeName = "unknown";
	if (pExpr->IsSymbol() || pExpr->IsMember()) {
		Value value = pExpr->Exec(env, sig);
		if (sig.IsSignalled() && !sig.IsError()) return Value::Null;
		if (sig.IsError()) {
			typeName = "undefined";
		} else {
			typeName = value.MakeValueTypeName();
		}
		sig.ClearSignal();
	} else {
		Value value = pExpr->Exec(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		typeName = value.MakeValueTypeName();
	}
	return Value(env, typeName);
}

// undef(`value+):[raise]
Gura_DeclareFunctionAlias(undef_, "undef")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_quote, OCCUR_OnceOrMore);
	DeclareAttr(Gura_Symbol(raise));
}

Gura_ImplementFunction(undef_)
{
	bool raiseFlag = args.IsSet(Gura_Symbol(raise));
	foreach_const (ValueList, pValueArg, args.GetList(0)) {
		const Expr *pExpr = pValueArg->GetExpr();
		Environment *pEnv = &env;
		const Symbol *pSymbol = NULL;
		if (pExpr->IsSymbol()) {
			pSymbol = dynamic_cast<const Expr_Symbol *>(pExpr)->GetSymbol();
		} else {
			SymbolList symbolList;
			if (!pExpr->GetChainedSymbolList(symbolList)) {
				sig.SetError(ERR_ValueError, "invalid symbol name");
				return Value::Null;
			}
			for (SymbolList::iterator ppSymbol = symbolList.begin();
								ppSymbol + 1 != symbolList.end(); ppSymbol++) {
				Value *pValue = pEnv->LookupValue(*ppSymbol, ENVREF_NoEscalate);
				if (pValue == NULL) {
					if (raiseFlag) {
						sig.SetError(ERR_ValueError, "undefined symbol");
					}
					return Value::Null;
				}
				if (pValue->IsModule()) {
					pEnv = pValue->GetModule();
				} else if (pValue->IsClass()) {
					pEnv = pValue->GetClass();
				} else if (pValue->IsObject()) {
					pEnv = pValue->GetObject();
				} else {
					sig.SetError(ERR_ValueError, "invalid symbol name");
					return Value::Null;
				}
			}
			pSymbol = symbolList.back();
		}
		if (raiseFlag && !pEnv->LookupValue(pSymbol, ENVREF_NoEscalate)) {
			sig.SetError(ERR_ValueError, "undefined symbol");
			return Value::Null;
		}
		pEnv->RemoveValue(pSymbol);
	}
	return Value::Null;
}

// randseed(seed:number):void
Gura_DeclareFunction(randseed)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "seed", VTYPE_number);
}

Gura_ImplementFunction(randseed)
{
	RandomGenerator::Initialize(args.GetULong(0));
	return Value::Null;
}

// rand(range?:number) {block?}
Gura_DeclareFunction(rand)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "range", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(rand)
{
	if (args.IsNumber(0)) {
		ULong num = args.GetULong(0);
		Number result = static_cast<ULong>(RandomGenerator::Real2() * num);
		return Value(result);
	}
	return ReturnValue(env, sig, args, Value(RandomGenerator::Real2()));
}

// object()
Gura_DeclareFunction(object)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(object)
{
	Object *pObj = new Object(env.LookupClass(VTYPE_object));
	return Value(pObj);
}

// Module entry
Gura_ModuleEntry()
{
	// value assignment
	Gura_AssignValue(__name__,	Value(env, "__main__"));
	Gura_AssignValue(nil,		Value::Null);
	Gura_AssignValueEx("true",	Value(true));
	Gura_AssignValueEx("false",	Value(false));
	Gura_AssignValueEx("@rem",	Value::Null); // dummy for MS-DOS batch
	Gura_AssignValueEx("*",		Value(env, new Iterator_SequenceInf(0)));
	do {
		Object_environment *pObj = new Object_environment(env);
		Gura_AssignValue(root, Value(pObj));
	} while (0);
	// function assignment
	Gura_AssignFunction(class_);
	Gura_AssignFunction(struct_);
	Gura_AssignFunction(super);
	Gura_AssignFunction(nomap);
	Gura_AssignFunction(module);
	Gura_AssignFunction(public_);
	Gura_AssignFunction(try_);
	Gura_AssignFunction(catch_);
	Gura_AssignFunction(finally_);
	Gura_AssignFunction(if_);
	Gura_AssignFunction(elsif_);
	Gura_AssignFunction(else_);
	Gura_AssignFunction(end);
	Gura_AssignFunction(switch_);
	Gura_AssignFunction(case_);
	Gura_AssignFunction(default_);
	Gura_AssignFunction(repeat);
	Gura_AssignFunction(while_);
	Gura_AssignFunction(for_);
	Gura_AssignFunction(cross);
	Gura_AssignFunction(break_);
	Gura_AssignFunction(continue_);
	Gura_AssignFunction(return_);
	Gura_AssignFunction(raise);
	Gura_AssignFunction(dim);
	Gura_AssignFunction(min);
	Gura_AssignFunction(max);
	Gura_AssignFunction(choose);
	Gura_AssignFunction(cond);
	Gura_AssignFunction(conds);
	Gura_AssignFunction(import_);
	Gura_AssignFunction(eval);
	Gura_AssignFunction(scope);
	Gura_AssignFunction(locals);
	Gura_AssignFunction(outers);
	Gura_AssignFunction(extern_);
	Gura_AssignFunction(local);
	Gura_AssignFunction(tostring);
	Gura_AssignFunction(tonumber);
	Gura_AssignFunction(tosymbol);
	Gura_AssignFunction(int_);
	Gura_AssignFunction(ord);
	Gura_AssignFunction(chr);
	Gura_AssignFunction(hex);
	Gura_AssignFunction(print);
	Gura_AssignFunction(println);
	Gura_AssignFunction(printf);
	Gura_AssignFunction(format);
	Gura_AssignFunction(dir);
	Gura_AssignFunction(dirtype);
	Gura_AssignFunction(help);
	Gura_AssignFunction(isdefined);
	Gura_AssignFunction(typename_);
	Gura_AssignFunction(undef_);
	Gura_AssignFunctionExx(istype_, "isnil",		VTYPE_nil);
	Gura_AssignFunctionExx(istype_, "issymbol",		VTYPE_symbol);
	Gura_AssignFunctionExx(istype_, "isboolean",	VTYPE_boolean);
	Gura_AssignFunctionExx(istype_, "isnumber",		VTYPE_number);
	Gura_AssignFunctionExx(istype_, "iscomplex",	VTYPE_complex);
	Gura_AssignFunctionExx(istype_, "isfraction",	VTYPE_fraction);
	Gura_AssignFunctionExx(istype_, "isfunction",	VTYPE_function);
	Gura_AssignFunctionExx(istype_, "isstring",		VTYPE_string);
	Gura_AssignFunctionExx(istype_, "isbinary",		VTYPE_binary);
	Gura_AssignFunctionExx(istype_, "islist",		VTYPE_list);
	Gura_AssignFunctionExx(istype_, "ismatrix",		VTYPE_matrix);
	Gura_AssignFunctionExx(istype_, "isdict",		VTYPE_dict);
	Gura_AssignFunctionExx(istype_, "isdatetime",	VTYPE_datetime);
	Gura_AssignFunctionExx(istype_, "istimedelta",	VTYPE_timedelta);
	Gura_AssignFunctionExx(istype_, "isiterator",	VTYPE_iterator);
	Gura_AssignFunctionExx(istype_, "isexpr",		VTYPE_expr);
	Gura_AssignFunctionExx(istype_, "isenvironment",VTYPE_environment);
	Gura_AssignFunctionExx(istype_, "iserror",		VTYPE_error);
	Gura_AssignFunctionExx(istype_, "isuri",		VTYPE_uri);
	Gura_AssignFunctionExx(istype_, "issemaphore",	VTYPE_semaphore);
	Gura_AssignFunctionExx(istype_, "ismodule",		VTYPE_Module);
	Gura_AssignFunctionExx(istype_, "isclass",		VTYPE_Class);
	Gura_AssignFunction(istype);
	Gura_AssignFunction(isinstance);
	Gura_AssignFunction(classref);
	Gura_AssignFunction(randseed);
	Gura_AssignFunction(rand);
	Gura_AssignFunction(object);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(basement, basement)

Gura_RegisterModule(basement)
