//=============================================================================
// Gura class: function
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_function
//-----------------------------------------------------------------------------
bool Object_function::IsFunction() const { return true; }

Object_function::~Object_function()
{
}

bool Object_function::IsLeader() const
{
	return GetFunction()->GetFlag(FLAG_Leader);
}

bool Object_function::IsTrailer() const
{
	return GetFunction()->GetFlag(FLAG_Trailer);
}

bool Object_function::IsFinalizer() const
{
	return GetFunction()->GetFlag(FLAG_Finalizer);
}

bool Object_function::IsEndMarker() const
{
	return GetFunction()->GetFlag(FLAG_EndMarker);
}

OccurPattern Object_function::GetBlockOccurPattern() const
{
	return GetFunction()->GetBlockOccurPattern();
}

Value Object_function::DoCall(
	Environment &env, const CallerInfo &callerInfo, ULong flags,
	const Value &valueThis, const Iterator *pIteratorThis,
	const TrailCtrlHolder *pTrailCtrlHolder)
{
	const Value &valueThisSel = (valueThis.IsInvalid() ||
			(valueThis.IsModule() && _valueThis.IsValid()))? _valueThis : valueThis;
	AutoPtr<Argument> pArg(new Argument(GetFunction(), callerInfo, flags));
	pArg->SetValueThis(valueThisSel);
	pArg->SetIteratorThis(Iterator::Reference(pIteratorThis));
	pArg->SetTrailCtrlHolder(TrailCtrlHolder::Reference(pTrailCtrlHolder));
	if (!pArg->EvalExpr(env, callerInfo.GetExprListArg())) return Value::Nil;
	return GetFunction()->EvalAuto(env, *pArg);
}

Value Object_function::Eval(Environment &env) const
{
	AutoPtr<Argument> pArg(new Argument(GetFunction()));
	pArg->SetValueThis(_valueThis);
	if (pArg->Complete(env)) {
		return GetFunction()->Eval(env, *pArg);
	}
	return Value::Nil;
}

Value Object_function::Eval(Environment &env, const Value &v1) const
{
	AutoPtr<Argument> pArg(new Argument(GetFunction()));
	pArg->SetValueThis(_valueThis);
	if (pArg->StoreValue(env, v1) && pArg->Complete(env)) {
		return GetFunction()->Eval(env, *pArg);
	}
	return Value::Nil;
}

Value Object_function::Eval(Environment &env, const Value &v1, const Value &v2) const
{
	AutoPtr<Argument> pArg(new Argument(GetFunction()));
	pArg->SetValueThis(_valueThis);
	if (pArg->StoreValue(env, v1, v2) && pArg->Complete(env)) {
		return GetFunction()->Eval(env, *pArg);
	}
	return Value::Nil;
}

Value Object_function::Eval(Environment &env, const Value &v1,
							const Value &v2, const Value &v3) const
{
	AutoPtr<Argument> pArg(new Argument(GetFunction()));
	pArg->SetValueThis(_valueThis);
	if (pArg->StoreValue(env, v1, v2, v3) && pArg->Complete(env)) {
		return GetFunction()->Eval(env, *pArg);
	}
	return Value::Nil;
}

Value Object_function::Eval(Environment &env, const Value &v1,
							const Value &v2, const Value &v3, const Value &v4) const
{
	AutoPtr<Argument> pArg(new Argument(GetFunction()));
	pArg->SetValueThis(_valueThis);
	if (pArg->StoreValue(env, v1, v2, v3, v4) && pArg->Complete(env)) {
		return GetFunction()->Eval(env, *pArg);
	}
	return Value::Nil;
}

Value Object_function::Eval(Environment &env, const ValueList &valList) const
{
	AutoPtr<Argument> pArg(new Argument(GetFunction()));
	pArg->SetValueThis(_valueThis);
	if (pArg->StoreValues(env, valList) && pArg->Complete(env)) {
		return GetFunction()->Eval(env, *pArg);
	}
	return Value::Nil;
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "args", VTYPE_quote, OCCUR_ZeroOrMore);
	if (::strcmp(GetName(), "function") == 0) {
		SetClassToConstruct(env.LookupClass(VTYPE_function));
	}
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Creates a `function` instance with an argument list of `args` and a procedure body\n"
		"provided by `block`.\n"
		"\n"
		"Following two codes have the same effect with each other.\n"
		"\n"
		"- `f = function(a, b, c) { /* any job */ }`\n"
		"- `f(a, b, c) = { /* any job */ }`\n");
}

Gura_ImplementFunction(function)
{
	Signal &sig = env.GetSignal();
	const Expr_Block *pExprBlock = arg.GetBlockCooked(env);
	if (sig.IsSignalled()) return Value::Nil;
	const ExprOwner *pExprOwnerParam = pExprBlock->GetExprOwnerParam();
	AutoPtr<ExprOwner> pExprOwnerArg;
	if (pExprOwnerParam == nullptr) {
		pExprOwnerArg.reset(new ExprOwner());
		foreach_const (ValueList, pValue, arg.GetList(0)) {
			pExprOwnerArg->push_back(pValue->GetExpr()->Reference());
		}
		if (pExprOwnerArg->empty()) {
			pExprBlock->GatherSimpleLambdaArgs(*pExprOwnerArg);
		}
	} else if (!arg.GetList(0).empty()) {
		sig.SetError(ERR_SyntaxError, "argument list conflicts with block parameter.");
		return Value::Nil;
	} else {
		pExprOwnerArg.reset(pExprOwnerParam->Reference());
	}
	AutoPtr<FunctionCustom> pFunc(new FunctionCustom(env,
			Gura_Symbol(_anonymous_), Expr::Reference(pExprBlock), FUNCTYPE_Function));
	CallerInfo callerInfo(*pExprOwnerArg, nullptr, arg.GetAttrsShared(), nullptr);
	callerInfo.SetFlagsToSet(arg.GetFlags());
	callerInfo.SetResultMode(arg.GetResultMode());
	if (!pFunc->CustomDeclare(env, callerInfo, SymbolSet::Empty)) return Value::Nil;
	return Value(new Object_function(env, pFunc.release()));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// function#decls
Gura_DeclareProperty_R(function, decls)
{
	SetPropAttr(VTYPE_iterator);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(function, decls)
{
	const Function *pFunc = Object_function::GetObject(valueThis)->GetFunction();
	Iterator *pIterator = new Iterator_declaration(pFunc->GetDeclOwner().Reference());
	return Value(new Object_iterator(env, pIterator));
}

// function#expr
Gura_DeclareProperty_RW(function, expr)
{
	SetPropAttr(VTYPE_expr);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(function, expr)
{
	const Function *pFunc = Object_function::GetObject(valueThis)->GetFunction();
	if (!pFunc->IsCustom()) return Value::Nil;
	const FunctionCustom *pFuncCustom = dynamic_cast<const FunctionCustom *>(pFunc);
	return Value(new Object_expr(env, Expr::Reference(pFuncCustom->GetExprBody())));
}

Gura_ImplementPropertySetter(function, expr)
{
	Function *pFunc = Object_function::GetObject(valueThis)->GetFunction();
	if (!pFunc->IsCustom()) {
		env.SetError(ERR_TypeError, "not a custom function");
		return Value::Nil;
	}
	FunctionCustom *pFuncCustom = dynamic_cast<FunctionCustom *>(pFunc);
	pFuncCustom->SetExprBody(value.GetExpr()->Reference());
	return value;
}

// function#format
Gura_DeclareProperty_R(function, format)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(function, format)
{
	const Function *pFunc = Object_function::GetObject(valueThis)->GetFunction();
	return Value(pFunc->ToString());
}

// function#fullname
Gura_DeclareProperty_R(function, fullname)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(function, fullname)
{
	const Function *pFunc = Object_function::GetObject(valueThis)->GetFunction();
	return Value(pFunc->MakeFullName());
}

// function#name
Gura_DeclareProperty_RW(function, name)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(function, name)
{
	const Function *pFunc = Object_function::GetObject(valueThis)->GetFunction();
	return Value(pFunc->GetName());
}

Gura_ImplementPropertySetter(function, name)
{
	Function *pFunc = Object_function::GetObject(valueThis)->GetFunction();
	pFunc->SetSymbol(Symbol::Add(value.GetString()));
	return value;
}

// function#symbol
Gura_DeclareProperty_RW(function, symbol)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(function, symbol)
{
	const Function *pFunc = Object_function::GetObject(valueThis)->GetFunction();
	return Value(pFunc->GetSymbol());
}

Gura_ImplementPropertySetter(function, symbol)
{
	Function *pFunc = Object_function::GetObject(valueThis)->GetFunction();
	pFunc->SetSymbol(value.GetSymbol());
	return value;
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// function.getdecls(func:function):static:map
Gura_DeclareClassMethod(function, getdecls)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator of `declaration` instances that provide information\n"
		"about argument declaration that the function instance `func` defines.\n"
		"\n"
		"This class method returns the same information as the property `function#decls`.\n");
}

Gura_ImplementClassMethod(function, getdecls)
{
	const Function *pFunc = Object_function::GetObject(arg, 0)->GetFunction();
	Iterator *pIterator = new Iterator_declaration(pFunc->GetDeclOwner().Reference());
	return Value(new Object_iterator(env, pIterator));
}

// function.getexpr(func:function):static:map
Gura_DeclareClassMethod(function, getexpr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	AddHelp(
		Gura_Symbol(en),
		"Returns an expression of the function instance `func`.\n"
		"\n"
		"It would return `nil` if the function is implemented with binary programs, not scripts.\n"
		"\n"
		"This class method returns the same information as the property `function#expr`.\n");
}

Gura_ImplementClassMethod(function, getexpr)
{
	const Function *pFunc = Object_function::GetObject(arg, 0)->GetFunction();
	if (!pFunc->IsCustom()) return Value::Nil;
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
		Gura_Symbol(en),
		"Returns a string showing a declared format of the function instance `func`.\n"
		"\n"
		"This class method returns the same information as the property `function#format`.\n");
}

Gura_ImplementClassMethod(function, getformat)
{
	const Function *pFunc = Object_function::GetObject(arg, 0)->GetFunction();
	return Value(pFunc->ToString());
}

// function.getfullname(func:function):static:map
Gura_DeclareClassMethod(function, getfullname)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	AddHelp(
		Gura_Symbol(en),
		"Returns a full name of the function instance `func`,\n"
		"which is prefixed by a name of the module or the class the instance belongs to.\n"
		"\n"
		"This class method returns the same information as the property `function#fullname`.\n");
}

Gura_ImplementClassMethod(function, getfullname)
{
	const Function *pFunc = Object_function::GetObject(arg, 0)->GetFunction();
	return Value(pFunc->MakeFullName());
}

// function.getname(func:function):static:map
Gura_DeclareClassMethod(function, getname)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	AddHelp(
		Gura_Symbol(en),
		"Returns a name of the function instance `func` in `string` type.\n"
		"\n"
		"This class method returns the same information as the property `function#name`.\n");
}

Gura_ImplementClassMethod(function, getname)
{
	const Function *pFunc = Object_function::GetObject(arg, 0)->GetFunction();
	return Value(pFunc->GetName());
}

// function.getsymbol(func:function):static:map
Gura_DeclareClassMethod(function, getsymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	AddHelp(
		Gura_Symbol(en),
		"Returns a name of the function instance `func` in `symbol` type.\n"
		"\n"
		"This class method returns the same information as the property `function#symbol`.\n");
}

Gura_ImplementClassMethod(function, getsymbol)
{
	const Function *pFunc = Object_function::GetObject(arg, 0)->GetFunction();
	return Value(pFunc->GetSymbol());
}

// function#mathdiff(var?:symbol)
Gura_DeclareMethod(function, mathdiff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "var", VTYPE_symbol, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
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
	Signal &sig = env.GetSignal();
	Object_function *pThis = Object_function::GetObjectThis(arg);
	const Function *pFunc = pThis->GetFunction();
	const DeclarationOwner &declOwner = pFunc->GetDeclOwner();
	const Symbol *pSymbol = nullptr;
	if (arg.Is_symbol(0)) {
		pSymbol = arg.GetSymbol(0);
	} else if (declOwner.empty()) {
		sig.SetError(ERR_ValueError, "variable symbol must be specified");
		return Value::Nil;
	} else {
		pSymbol = declOwner.front()->GetSymbol();
	}
	AutoPtr<Expr> pExprArg(new Expr_Identifier(pSymbol));
	AutoPtr<Expr> pExprDiff(pFunc->MathDiff(env, pExprArg.get(), pSymbol));
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<FunctionCustom> pFuncDiff(new FunctionCustom(env,
				Gura_Symbol(_anonymous_), pExprDiff.release(), FUNCTYPE_Function));
	pFuncDiff->CopyDeclarationInfo(*pFunc);
	return Value(new Object_function(env, pFuncDiff.release()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_function::Class_function(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_function)
{
}

void Class_function::DoPrepare(Environment &env)
{
	// Assignment of functions
	Gura_AssignFunction(function);
	Gura_AssignFunctionEx(function, "&");
	// Assignment of properties
	Gura_AssignProperty(function, decls);
	Gura_AssignProperty(function, expr);
	Gura_AssignProperty(function, format);
	Gura_AssignProperty(function, fullname);
	Gura_AssignProperty(function, name);
	Gura_AssignProperty(function, symbol);
	// Assignment of methods
	Gura_AssignMethod(function, getdecls);
	Gura_AssignMethod(function, getexpr);
	Gura_AssignMethod(function, getformat);
	Gura_AssignMethod(function, getfullname);
	Gura_AssignMethod(function, getname);
	Gura_AssignMethod(function, getsymbol);
	Gura_AssignMethod(function, mathdiff);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_function::CastFrom(Environment &env, Value &value, ULong flags)
{
	Signal &sig = GetSignal();
	if (value.Is_expr()) {
		Expr_Block *pExprBlock = value.GetExpr()->ToExprBlock();
		AutoPtr<FunctionCustom> pFunc(FunctionCustom::CreateBlockFunc(env,
						Gura_Symbol(_anonymous_), pExprBlock, FUNCTYPE_Function));
		if (sig.IsSignalled()) return false;
		value = Value(new Object_function(env, pFunc.release()));
		return true;
	} else if (value.IsClass()) {
		Class *pClass = value.GetClassItself();
		const Function *pFunc = pClass->GetConstructor();
		if (pFunc == nullptr) {
			pClass->SetError_NoConstructor();
			return false;
		}
		value = Value(new Object_function(env, pFunc->Reference()));
		return true;
	}
	return false;
}

Class::SerializeFmtVer Class_function::GetSerializeFmtVer() const
{
	return SerializeFmtVer_1;
}

bool Class_function::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	return false;
}

bool Class_function::Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const
{
	return false;
}

Object *Class_function::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
