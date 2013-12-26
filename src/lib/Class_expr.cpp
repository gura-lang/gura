//=============================================================================
// Gura class: expr
//=============================================================================
#include "stdafx.h"

#define ImplementTypeChecker(funcName, func) \
Gura_DeclareMethod(expr, funcName) {} \
Gura_ImplementMethod(expr, funcName) { \
	return Value(Object_expr::GetThisObj(args)->GetExpr()->func()); \
}

namespace Gura {

//-----------------------------------------------------------------------------
// Object_expr
//-----------------------------------------------------------------------------
Object_expr::Object_expr(const Object_expr &obj) :
							Object(obj), _pExpr(obj.GetExpr()->Reference())
{
}

Object *Object_expr::Clone() const
{
	return new Object_expr(*this);
}

bool Object_expr::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(typename_));
	symbols.insert(Gura_Symbol(typesym));
	symbols.insert(Gura_Symbol(source));
	symbols.insert(Gura_Symbol(lineno));
	symbols.insert(Gura_Symbol(linenobtm));
	symbols.insert(Gura_Symbol(postext));
	symbols.insert(Gura_Symbol(child));
	symbols.insert(Gura_Symbol(children));
	symbols.insert(Gura_Symbol(left));
	symbols.insert(Gura_Symbol(right));
	symbols.insert(Gura_Symbol(car));
	symbols.insert(Gura_Symbol(cdr));
	symbols.insert(Gura_Symbol(block));
	symbols.insert(Gura_Symbol(value));
	symbols.insert(Gura_Symbol(string));
	symbols.insert(Gura_Symbol(symbol));
	symbols.insert(Gura_Symbol(blockparam));
	return true;
}

Value Object_expr::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(typename_))) {
		return Value(GetExpr()->GetTypeName());
	} else if (pSymbol->IsIdentical(Gura_Symbol(typesym))) {
		return Value(Symbol::Add(GetExpr()->GetTypeName()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(source))) {
		const char *sourceName = GetExpr()->GetSourceName();
		if (sourceName == NULL) return Value::Null;
		return Value(sourceName);
	} else if (pSymbol->IsIdentical(Gura_Symbol(lineno))) {
		return Value(GetExpr()->GetLineNoTop());
	} else if (pSymbol->IsIdentical(Gura_Symbol(linenobtm))) {
		return Value(GetExpr()->GetLineNoBtm());
	} else if (pSymbol->IsIdentical(Gura_Symbol(postext))) {
		return Value(GetExpr()->MakePosText());
	} else if (pSymbol->IsIdentical(Gura_Symbol(child))) {
		if (GetExpr()->IsUnary()) {
			const Expr_Unary *pExpr = dynamic_cast<const Expr_Unary *>(GetExpr());
			return Value(new Object_expr(env, Expr::Reference(pExpr->GetChild())));
		}
		sig.SetError(ERR_ValueError, "not a unary expression");
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_Symbol(children))) {
		if (GetExpr()->IsContainer()) {
			const Expr_Container *pExpr = dynamic_cast<const Expr_Container *>(GetExpr());
			return Value(new Object_iterator(env, new ExprOwner::Iterator(pExpr->GetExprOwner().Reference())));
		}
		sig.SetError(ERR_ValueError, "not a container expression");
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_Symbol(left))) {
		if (GetExpr()->IsBinary()) {
			const Expr_Binary *pExpr = dynamic_cast<const Expr_Binary *>(GetExpr());
			return Value(new Object_expr(env, Expr::Reference(pExpr->GetLeft())));
		}
		sig.SetError(ERR_ValueError, "not a binary expression");
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_Symbol(right))) {
		if (GetExpr()->IsBinary()) {
			const Expr_Binary *pExpr = dynamic_cast<const Expr_Binary *>(GetExpr());
			return Value(new Object_expr(env, Expr::Reference(pExpr->GetRight())));
		}
		sig.SetError(ERR_ValueError, "not a binary expression");
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_Symbol(car))) {
		if (GetExpr()->IsCompound()) {
			const Expr_Compound *pExpr = dynamic_cast<const Expr_Compound *>(GetExpr());
			return Value(new Object_expr(env, Expr::Reference(pExpr->GetCar())));
		}
		sig.SetError(ERR_ValueError, "not a compound expression");
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_Symbol(cdr))) {
		if (GetExpr()->IsCompound()) {
			const Expr_Compound *pExpr = dynamic_cast<const Expr_Compound *>(GetExpr());
			return Value(new Object_iterator(env, new ExprOwner::Iterator(pExpr->GetExprOwner().Reference())));
		}
		sig.SetError(ERR_ValueError, "not a compound expression");
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_Symbol(block))) {
		if (GetExpr()->IsCaller()) {
			const Expr_Caller *pExpr = dynamic_cast<const Expr_Caller *>(GetExpr());
			const Expr_Block *pExprBlock = pExpr->GetBlock();
			if (pExprBlock == NULL) return Value::Null;
			return Value(new Object_expr(env, Expr::Reference(pExprBlock)));
		}
		sig.SetError(ERR_ValueError, "not a caller expression");
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_Symbol(trailer))) {
		if (GetExpr()->IsCaller()) {
			const Expr_Caller *pExpr = dynamic_cast<const Expr_Caller *>(GetExpr());
			const Expr_Caller *pExprTrailer = pExpr->GetTrailer();
			if (pExprTrailer == NULL) return Value::Null;
			return Value(new Object_expr(env, Expr::Reference(pExprTrailer)));
		}
		sig.SetError(ERR_ValueError, "not a caller expression");
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_Symbol(value))) {
		if (GetExpr()->IsValue()) {
			const Expr_Value *pExpr = dynamic_cast<const Expr_Value *>(GetExpr());
			return pExpr->GetValue();
		}
		sig.SetError(ERR_ValueError, "expression is not a value");
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		if (GetExpr()->IsString()) {
			const Expr_String *pExpr = dynamic_cast<const Expr_String *>(GetExpr());
			return Value(pExpr->GetString());
		}
		sig.SetError(ERR_ValueError, "expression is not a string");
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_Symbol(symbol))) {
		if (GetExpr()->IsSymbol()) {
			const Expr_Symbol *pExpr = dynamic_cast<const Expr_Symbol *>(GetExpr());
			return Value(pExpr->GetSymbol());
		}
		sig.SetError(ERR_ValueError, "expression is not a symbol");
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_Symbol(blockparam))) {
		if (GetExpr()->IsBlock()) {
			const Expr_Block *pExpr = dynamic_cast<const Expr_Block *>(GetExpr());
			const ExprOwner *pExprOwnerParam = pExpr->GetExprOwnerParam();
			if (pExprOwnerParam == NULL) return Value::Null;
			return Value(new Object_iterator(env, new ExprOwner::Iterator(pExprOwnerParam->Reference())));
		}
		sig.SetError(ERR_ValueError, "expression is not a block");
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_Symbol(operator_))) {
		if (GetExpr()->IsUnaryOp()) {
			const Expr_UnaryOp *pExpr = dynamic_cast<const Expr_UnaryOp *>(GetExpr());
			return Value(new Object_operator(env,
							pExpr->GetOperator()->GetOpType(), OPTYPE_None));
		} else if (GetExpr()->IsBinaryOp()) {
			const Expr_BinaryOp *pExpr = dynamic_cast<const Expr_BinaryOp *>(GetExpr());
			return Value(new Object_operator(env,
							OPTYPE_None, pExpr->GetOperator()->GetOpType()));
		} else if (GetExpr()->IsAssign()) {
			const Expr_Assign *pExpr = dynamic_cast<const Expr_Assign *>(GetExpr());
			const Operator *pOperator = pExpr->GetOperatorToApply();
			if (pOperator == NULL) return Value::Null;
			return Value(new Object_operator(env, OPTYPE_None, pOperator->GetOpType()));
		}
		sig.SetError(ERR_ValueError, "expression is not a unaryop, binaryop nor assign");
		return Value::Null;
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_expr::ToString(bool exprFlag)
{
	String str;
	if (_pExpr->IsValue() || _pExpr->IsSymbol() || _pExpr->IsCaller()) {
		if (exprFlag) str += '`';
		str += _pExpr->ToString(Expr::SCRSTYLE_OneLine);
	} else if (exprFlag) {
		if (_pExpr->IsUnary() || _pExpr->IsBinary()) {
			str += "`(";
			str += _pExpr->ToString(Expr::SCRSTYLE_OneLine);
			str += ")";
		} else {
			str += "`";
			str += _pExpr->ToString(Expr::SCRSTYLE_OneLine);
		}
	} else {
		str += _pExpr->ToString(Expr::SCRSTYLE_OneLine);
	}
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of expr
//-----------------------------------------------------------------------------
// expr() {block?}
Gura_DeclareFunction(expr)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_expr));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(expr)
{
	return Value::Null;
}

// expr.parse(script:string) {block?}
Gura_DeclareClassMethod(expr, parse)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "script", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Parse a string returns an expr object.");
}

Gura_ImplementClassMethod(expr, parse)
{
	AutoPtr<Expr_Block> pExpr(new Expr_Block());
	Parser parser(SRCNAME_string);
	if (!parser.ParseString(env, sig, pExpr->GetExprOwner(),
								args.GetString(0), true)) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_expr(env, pExpr.release())));
}

// expr.read(src:stream:r) {block?}
Gura_DeclareClassMethod(expr, read)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Parse a content of a script stream and returns an expr object.");
}

Gura_ImplementClassMethod(expr, read)
{
	Stream &stream = Object_stream::GetObject(args, 0)->GetStream();
	Parser parser(stream.GetName());
	AutoPtr<Expr_Root> pExprRoot(parser.ParseStream(env, sig, stream));
	if (pExprRoot.IsNull()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_expr(env, pExprRoot.release())));
}

// expr#eval(env?:environment)
Gura_DeclareMethod(expr, eval)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "env", VTYPE_environment, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Evaluate an expr object.");
}

Gura_ImplementMethod(expr, eval)
{
	const Expr *pExpr = Object_expr::GetThisObj(args)->GetExpr();
	Environment *pEnv = args.Is_environment(0)?
			Object_environment::GetObject(args, 0)->GetEnv().Reference() :
			new Environment(&env, ENVTYPE_block);
	return Processor::Run(pEnv, sig, pExpr);
}

// expr#genscript(dst?:stream:w, style?:symbol)
Gura_DeclareMethod(expr, genscript)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareArg(env, "style", VTYPE_symbol, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Outputs a script that describes the expression to the specified `stream`.\n"
	"If `stream` is omitted, script shall be written into standard output.\n");
}

Gura_ImplementMethod(expr, genscript)
{
	const Expr *pExpr = Object_expr::GetThisObj(args)->GetExpr();
	Expr::ScriptStyle scriptStyle = Expr::SCRSTYLE_Fancy;
	if (args.Is_symbol(1)) {
		const Symbol *pSymbol = args.GetSymbol(1);
		scriptStyle = Expr::SymbolToScriptStyle(pSymbol);
		if (scriptStyle == Expr::SCRSTYLE_None) {
			sig.SetError(ERR_ValueError,
					"invalid symbol for script style: %s", pSymbol->GetName());
			return Value::Null;
		}
	}
	if (args.Is_stream(0)) {
		pExpr->GenerateScript(sig, args.GetStream(0), scriptStyle, 0);
		return Value::Null;
	} else {
		String strDst;
		SimpleStream_StringWriter streamDst(strDst);
		if (!pExpr->GenerateScript(sig, streamDst, scriptStyle, 0)) return Value::Null;
		return Value(strDst);
	}
}

// expr#tofunction(`args*)
Gura_DeclareMethod(expr, tofunction)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "args", VTYPE_quote, OCCUR_ZeroOrMore);
}

Gura_ImplementMethod(expr, tofunction)
{
	Expr_Block *pExprBlock = Object_expr::GetThisObj(args)->GetExpr()->ToExprBlock();
	AutoPtr<FunctionCustom> pFunc(FunctionCustom::CreateBlockFunc(env, sig,
					Gura_Symbol(_anonymous_), pExprBlock, FUNCTYPE_Function));
	if (sig.IsSignalled()) return Value::Null;
	const ValueList &valListArg = args.GetList(0);
	if (!valListArg.empty()) {
		if (!pFunc->GetDeclOwner().empty()) {
			sig.SetError(ERR_TypeError, "argument declaration conflicts");
			return Value::Null;
		}
		AutoPtr<ExprOwner> pExprOwnerArg(new ExprOwner());
		foreach_const (ValueList, pValue, valListArg) {
			pExprOwnerArg->push_back(pValue->GetExpr()->Reference());
		}
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetExprOwnerArg(pExprOwnerArg.release());
		pArgs->SetAttrs(args.GetAttrs());
		if (!pFunc->CustomDeclare(env, sig, SymbolSet::Null, *pArgs)) return Value::Null;
	}
	return Value(new Object_function(env, pFunc.release()));
}

// expr#unquote()
Gura_DeclareMethod(expr, unquote)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(expr, unquote)
{
	const Expr *pExpr = Object_expr::GetThisObj(args)->GetExpr();
	Object_expr *pObj = new Object_expr(env, Expr::Reference(pExpr->Unquote()));
	return Value(pObj);
}

// type chekers - Unary and descendants
ImplementTypeChecker(isunary,		IsUnary)
ImplementTypeChecker(isunaryop,		IsUnaryOp)
ImplementTypeChecker(isquote,		IsQuote)
// type chekers - Binary and descendants
ImplementTypeChecker(isbinary,		IsBinary)
ImplementTypeChecker(isbinaryop,	IsBinaryOp)
ImplementTypeChecker(isassign,		IsAssign)
ImplementTypeChecker(ismember,		IsMember)
// type chekers - Container and descendants
ImplementTypeChecker(iscontainer,	IsContainer)
ImplementTypeChecker(isroot,		IsRoot)
ImplementTypeChecker(isblock,		IsBlock)
ImplementTypeChecker(islister,		IsLister)
ImplementTypeChecker(isiterer,		IsIterer)
// type chekers - Compound and descendants
ImplementTypeChecker(iscompound,	IsCompound)
ImplementTypeChecker(isindexer,		IsIndexer)
ImplementTypeChecker(iscaller,		IsCaller)
// type chekers - others
ImplementTypeChecker(isvalue,		IsValue)
ImplementTypeChecker(issymbol,		IsSymbol)
ImplementTypeChecker(isstring,		IsString)

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_expr::Class_expr(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_expr)
{
}

void Class_expr::Prepare(Environment &env)
{
	Gura_AssignFunction(expr);
	Gura_AssignMethod(expr, parse);
	Gura_AssignMethod(expr, read);
	Gura_AssignMethod(expr, eval);
	Gura_AssignMethod(expr, genscript);
	Gura_AssignMethod(expr, tofunction);
	Gura_AssignMethod(expr, unquote);
	// type chekers - Unary and descendants
	Gura_AssignMethod(expr,	isunary);
	Gura_AssignMethod(expr,	isunaryop);
	Gura_AssignMethod(expr,	isquote);
	// type chekers - Binary and descendants
	Gura_AssignMethod(expr,	isbinary);
	Gura_AssignMethod(expr,	isbinaryop);
	Gura_AssignMethod(expr,	isassign);
	Gura_AssignMethod(expr,	ismember);
	// type chekers - Container and descendants
	Gura_AssignMethod(expr,	iscontainer);
	Gura_AssignMethod(expr,	isroot);
	Gura_AssignMethod(expr,	isblock);
	Gura_AssignMethod(expr,	islister);
	Gura_AssignMethod(expr,	isiterer);
	// type chekers - Compound and descendants
	Gura_AssignMethod(expr,	iscompound);
	Gura_AssignMethod(expr,	isindexer);
	Gura_AssignMethod(expr,	iscaller);
	// type chekers - others
	Gura_AssignMethod(expr,	isvalue);
	Gura_AssignMethod(expr,	issymbol);
	Gura_AssignMethod(expr,	isstring);
}

bool Class_expr::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.Is_symbol()) {		// cast Symbol to Expr
		const Symbol *pSymbol = value.GetSymbol();
		value = Value(new Object_expr(env, new Expr_Symbol(pSymbol)));
		return true;
	}
	return false;
}

Object *Class_expr::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
