//=============================================================================
// Gura class: function
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_function
//-----------------------------------------------------------------------------
bool Object_function::IsFunction() const { return true; }

Object_function::~Object_function()
{
}

bool Object_function::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	Class *pClass = GetFunction()->GetClassToConstruct();
	if (pClass != NULL) return pClass->DoDirProp(env, sig, symbols);
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(decls));
	symbols.insert(Gura_Symbol(expr));
	symbols.insert(Gura_Symbol(format));
	symbols.insert(Gura_Symbol(fullname));
	symbols.insert(Gura_Symbol(name));
	symbols.insert(Gura_Symbol(symbol));
	return true;
}

Value Object_function::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(decls))) {
		Iterator *pIterator = new Iterator_declaration(GetFunction()->GetDeclOwner().Reference());
		return Value(new Object_iterator(env, pIterator));
	} else if (pSymbol->IsIdentical(Gura_Symbol(expr))) {
		if (!GetFunction()->IsCustom()) return Value::Null;
		const FunctionCustom *pFuncCustom =
						dynamic_cast<const FunctionCustom *>(GetFunction());
		return Value(new Object_expr(env, Expr::Reference(pFuncCustom->GetExprBody())));
	} else if (pSymbol->IsIdentical(Gura_Symbol(format))) {
		return Value(GetFunction()->ToString());
	} else if (pSymbol->IsIdentical(Gura_Symbol(fullname))) {
		return Value(GetFunction()->MakeFullName());
	} else if (pSymbol->IsIdentical(Gura_Symbol(name))) {
		return Value(GetFunction()->GetName());
	} else if (pSymbol->IsIdentical(Gura_Symbol(symbol))) {
		return Value(GetFunction()->GetSymbol());
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_function::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(symbol)) ||
						pSymbol->IsIdentical(Gura_Symbol(name))) {
		if (value.Is_symbol()) {
			GetFunction()->SetSymbol(value.GetSymbol());
		} else if (value.Is_string()) {
			GetFunction()->SetSymbol(Symbol::Add(value.GetString()));
		} else {
			sig.SetError(ERR_TypeError, "symbol or string must be specified");
			return Value::Null;
		}
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(expr))) {
		if (!GetFunction()->IsCustom()) {
			sig.SetError(ERR_TypeError, "not a custom function");
			return Value::Null;
		}
		if (!value.Is_expr()) {
			sig.SetError(ERR_TypeError, "expr must be specified");
			return Value::Null;
		}
		FunctionCustom *pFuncCustom = dynamic_cast<FunctionCustom *>(GetFunction());
		pFuncCustom->SetExprBody(Expr::Reference(value.GetExpr()));
		return value;
	}
	return DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
}

bool Object_function::IsLeader() const
{
	return GetFunction()->GetLeaderFlag();
}

bool Object_function::IsTrailer() const
{
	return GetFunction()->GetTrailerFlag();
}

bool Object_function::IsFinalizer() const
{
	return GetFunction()->GetFinalizerFlag();
}

bool Object_function::IsEndMarker() const
{
	return GetFunction()->GetEndMarkerFlag();
}

OccurPattern Object_function::GetBlockOccurPattern() const
{
	return GetFunction()->GetBlockOccurPattern();
}

Value Object_function::DoCall(Environment &env, Signal sig, Args &args)
{
	if (args.GetThis().IsInvalid() ||
					(args.GetThis().IsModule() && _valueThis.IsValid())) {
		args.SetThis(_valueThis);
	}
	return GetFunction()->Call(env, sig, args);
}

Value Object_function::Eval(Environment &env, Signal sig, ValueList &valListArg) const
{
	GetFunction()->GetDeclOwner().Compensate(env, sig, valListArg);
	if (sig.IsSignalled()) return Value::Null;
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetThis(_valueThis);
	pArgs->SetValueListArg(valListArg);
	return GetFunction()->Eval(env, sig, *pArgs);
}

Object *Object_function::Clone() const
{
	return new Object_function(*this);
}

String Object_function::ToString(bool exprFlag)
{
	return GetFunction()->ToString();
}

void Object_function::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		GetFunction()->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// function(`args*) {block}
Gura_DeclareFunction(function)
{
	DeclareArg(env, "args", VTYPE_quote, OCCUR_ZeroOrMore);
	SetClassToConstruct(env.LookupClass(VTYPE_function));
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `function` instance with an argument list of `args` and a procedure body\n"
		"provided by `block`.\n"
		"\n"
		"Following two codes have the same effect with each other.\n"
		"\n"
		"    f = function(a, b, c) { /* any job */ }\n"
		"\n"
		"    f(a, b, c) = { /* any job */ }\n");
}

Gura_ImplementFunction(function)
{
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	const ExprOwner *pExprOwnerParam = pExprBlock->GetExprOwnerParam();
	ExprOwner *pExprOwnerArg = NULL;
	if (pExprOwnerParam == NULL) {
		pExprOwnerArg = new ExprOwner();
		foreach_const (ValueList, pValue, args.GetList(0)) {
			pExprOwnerArg->push_back(pValue->GetExpr()->Reference());
		}
		if (pExprOwnerArg->empty()) {
			pExprBlock->GatherSimpleLambdaArgs(*pExprOwnerArg);
		}
	} else if (!args.GetList(0).empty()) {
		sig.SetError(ERR_SyntaxError, "argument list conflicts with block parameter.");
		return Value::Null;
	} else {
		pExprOwnerArg = pExprOwnerParam->Reference();
	}
	AutoPtr<FunctionCustom> pFunc(new FunctionCustom(env,
			Gura_Symbol(_anonymous_), Expr::Reference(pExprBlock), FUNCTYPE_Function));
	AutoPtr<Args> pArgsSub(new Args());
	pArgsSub->SetExprOwnerArg(pExprOwnerArg);
	pArgsSub->SetAttrs(args.GetAttrs());
	if (!pFunc->CustomDeclare(env, sig, SymbolSet::Null, *pArgsSub)) return Value::Null;
	return Value(new Object_function(env, pFunc.release()));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// function.addhelp(func:function, lang:symbol, format:string, help:string):map
Gura_DeclareClassMethod(function, addhelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	DeclareArg(env, "lang", VTYPE_symbol);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "help", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Adds help information to a `function` instance taking the following arguments:\n"
		"\n"
		"- `func` .. `function` instance to which the help is added.\n"
		"- `lang` .. a symbol of the language in which the help text is described,\n"
		"            `` `en`` for English, `` `ja`` for Japanese and so on.\n"
		"- `format` .. a name of the syntax format in which the help text is described.\n"
		"  Currently, only `'markdown'` is available.\n"
		"- `help`.. the help text.\n"
		"\n"
		"You can add multiple help information with different `lang`.\n"
		"\n"
		"Following two codes have the same effect with each other.\n"
		"\n"
		"    f(a:number, b:number, c:number) = {\n"
		"        (a + b + c) / 3\n"
		"    }\n"
		"    \n"
		"    function.addhelp(\n"
		"        f, `en, 'markdown'\n"
		"        R'''\n"
		"        Computes a mean value of the provided three numbers.\n"
		"        ''')\n"
		"\n"
		"    f(a:number, b:number, c:number) = {\n"
		"        (a + b + c) / 3\n"
		"    } % {\n"
		"        `en, 'markdown'\n"
		"        R'''\n"
		"        Computes a mean value of the provided three numbers.\n"
		"        '''\n"
		"    }\n");
}

Gura_ImplementClassMethod(function, addhelp)
{
	Function *pFunc = Object_function::GetObject(args, 0)->GetFunction();
	pFunc->AddHelp(args.GetSymbol(1), args.GetString(2), args.GetString(3));
	return Value::Null;
}

// function.getdecls(func:function):static:map
Gura_DeclareClassMethod(function, getdecls)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator of `declaration` instances that provide information\n"
		"about argument declaration that the function instance `func` defines.\n"
		"\n"
		"This class method returns the same information as the property `function#decls`.\n");
}

Gura_ImplementClassMethod(function, getdecls)
{
	const Function *pFunc = Object_function::GetObject(args, 0)->GetFunction();
	Iterator *pIterator = new Iterator_declaration(pFunc->GetDeclOwner().Reference());
	return Value(new Object_iterator(env, pIterator));
}

// function.getexpr(func:function):static:map
Gura_DeclareClassMethod(function, getexpr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an expression of the function instance `func`.\n"
		"\n"
		"It would return `nil` if the function is implemented with binary programs, not scripts.\n"
		"\n"
		"This class method returns the same information as the property `function#expr`.\n");
}

Gura_ImplementClassMethod(function, getexpr)
{
	const Function *pFunc = Object_function::GetObject(args, 0)->GetFunction();
	if (!pFunc->IsCustom()) return Value::Null;
	const FunctionCustom *pFuncCustom =
					dynamic_cast<const FunctionCustom *>(pFunc);
	return Value(new Object_expr(env, Expr::Reference(pFuncCustom->GetExprBody())));
}

// function.getformat(func:function):static:map
Gura_DeclareClassMethod(function, getformat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a string showing a declared format of the function instance `func`.\n"
		"\n"
		"This class method returns the same information as the property `function#format`.\n");
}

Gura_ImplementClassMethod(function, getformat)
{
	const Function *pFunc = Object_function::GetObject(args, 0)->GetFunction();
	return Value(pFunc->ToString());
}

// function.getfullname(func:function):static:map
Gura_DeclareClassMethod(function, getfullname)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a full name of the function instance `func`,\n"
		"which is prefixed by a name of the module or the class the instance belongs to.\n"
		"\n"
		"This class method returns the same information as the property `function#fullname`.\n");
}

Gura_ImplementClassMethod(function, getfullname)
{
	const Function *pFunc = Object_function::GetObject(args, 0)->GetFunction();
	return Value(pFunc->MakeFullName());
}

// function.gethelp(func:function, lang?:symbol):static:map
Gura_DeclareClassMethod(function, gethelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	DeclareArg(env, "lang", VTYPE_symbol, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a `help` instance of the specified function instance `func`.\n"
		"If no help has been registred, it would return `nil`.\n"
		"\n"
		"The argument `lang` is a symbol that indicates a natural language\n"
		"in which the help is written.\n"
		"If this argument is omitted or the specified language doesn't exist,\n"
		"help information that has been registered at first would be returned as a default.\n");
}

Gura_ImplementClassMethod(function, gethelp)
{
	const Function *pFunc = Object_function::GetObject(args, 0)->GetFunction();
	const Symbol *pSymbol = args.Is_symbol(1)? args.GetSymbol(1) : env.GetLangCode();
	const Help *pHelp = pFunc->GetHelp(pSymbol, true);
	if (pHelp == NULL) return Value::Null;
	return Value(new Object_help(env, pHelp->Reference()));
}

// function.getname(func:function):static:map
Gura_DeclareClassMethod(function, getname)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a name of the function instance `func` in `string` type.\n"
		"\n"
		"This class method returns the same information as the property `function#name`.\n");
}

Gura_ImplementClassMethod(function, getname)
{
	const Function *pFunc = Object_function::GetObject(args, 0)->GetFunction();
	return Value(pFunc->GetName());
}

// function.getsymbol(func:function):static:map
Gura_DeclareClassMethod(function, getsymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a name of the function instance `func` in `symbol` type.\n"
		"\n"
		"This class method returns the same information as the property `function#symbol`.\n");
}

Gura_ImplementClassMethod(function, getsymbol)
{
	const Function *pFunc = Object_function::GetObject(args, 0)->GetFunction();
	return Value(pFunc->GetSymbol());
}

// function#mathdiff(var?:symbol)
Gura_DeclareMethod(function, mathdiff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "var", VTYPE_symbol, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a `function` instance that computes derivation of the target function,\n"
		"which is expected to contain only mathematical procedures.\n"
		"An error occurs if the target function has any elements\n"
		"that have nothing to do with mathematics.\n"
		"\n"
		"In default, it differentiates the target function with respect to its first argument.\n"
		"Below is an example:\n"
		"\n"
		"    >>> f(x) = math.sin(x)\n"
		"    >>> g = f.mathdiff()    // g is a function to compute math.cos(x)\n"
		"\n"
		"Specify a symbol to argument `var` when you want to differentiate\n"
		"with respect to another variable.\n"
		"\n"
		"You can check the result of derivation by seeing property `function#expr` like below:\n"
		"\n"
		"    >>> g.expr\n"
		"    `math.cos(x)\n");
}

Gura_ImplementMethod(function, mathdiff)
{
	Object_function *pThis = Object_function::GetThisObj(args);
	const Function *pFunc = pThis->GetFunction();
	const DeclarationOwner &declOwner = pFunc->GetDeclOwner();
	const Symbol *pSymbol = NULL;
	if (args.Is_symbol(0)) {
		pSymbol = args.GetSymbol(0);
	} else if (declOwner.empty()) {
		sig.SetError(ERR_ValueError, "variable symbol must be specified");
		return Value::Null;
	} else {
		pSymbol = declOwner.front()->GetSymbol();
	}
	AutoPtr<Expr> pExprArg(new Expr_Identifier(pSymbol));
	AutoPtr<Expr> pExprDiff(pFunc->MathDiff(env, sig, pExprArg.get(), pSymbol));
	if (sig.IsSignalled()) return Value::Null;
	AutoPtr<FunctionCustom> pFuncDiff(new FunctionCustom(env,
				Gura_Symbol(_anonymous_), pExprDiff.release(), FUNCTYPE_Function));
	pFuncDiff->CopyDeclare(*pFunc);
	return Value(new Object_function(env, pFuncDiff.release()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_function::Class_function(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_function)
{
}

void Class_function::Prepare(Environment &env)
{
	Gura_AssignFunction(function);
	Gura_AssignFunctionEx(function, "&");
	Gura_AssignMethod(function, addhelp);
	Gura_AssignMethod(function, getdecls);
	Gura_AssignMethod(function, getexpr);
	Gura_AssignMethod(function, getformat);
	Gura_AssignMethod(function, getfullname);
	Gura_AssignMethod(function, gethelp);
	Gura_AssignMethod(function, getname);
	Gura_AssignMethod(function, getsymbol);
	Gura_AssignMethod(function, mathdiff);
}

bool Class_function::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.Is_expr()) {
		Expr_Block *pExprBlock = value.GetExpr()->ToExprBlock();
		AutoPtr<FunctionCustom> pFunc(FunctionCustom::CreateBlockFunc(env, sig,
						Gura_Symbol(_anonymous_), pExprBlock, FUNCTYPE_Function));
		if (sig.IsSignalled()) return false;
		value = Value(new Object_function(env, pFunc.release()));
		return true;
	}
	return false;
}

bool Class_function::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return false;
}

bool Class_function::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	return false;
}

Object *Class_function::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
