//
// Object_expr
//

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
	symbols.insert(Gura_Symbol(typename));
	symbols.insert(Gura_Symbol(typesym));
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
	if (pSymbol->IsIdentical(Gura_Symbol(typename))) {
		return Value(env, GetExpr()->GetTypeName());
	} else if (pSymbol->IsIdentical(Gura_Symbol(typesym))) {
		return Value(Symbol::Add(GetExpr()->GetTypeName()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(child))) {
		if (!GetExpr()->IsUnary()) {
			sig.SetError(ERR_ValueError, "not a unary expression");
			return Value::Null;
		}
		const Expr_Unary *pExpr = dynamic_cast<const Expr_Unary *>(GetExpr());
		return Value(new Object_expr(env, Expr::Reference(pExpr->GetChild())));
	} else if (pSymbol->IsIdentical(Gura_Symbol(children))) {
		if (!GetExpr()->IsContainer()) {
			sig.SetError(ERR_ValueError, "not a container expression");
			return Value::Null;
		}
		const Expr_Container *pExpr = dynamic_cast<const Expr_Container *>(GetExpr());
		return Value(env, new Iterator_expr(pExpr->GetExprOwner().Reference()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(left))) {
		if (!GetExpr()->IsBinary()) {
			sig.SetError(ERR_ValueError, "not a binary expression");
			return Value::Null;
		}
		const Expr_Binary *pExpr = dynamic_cast<const Expr_Binary *>(GetExpr());
		return Value(new Object_expr(env, Expr::Reference(pExpr->GetLeft())));
	} else if (pSymbol->IsIdentical(Gura_Symbol(right))) {
		if (!GetExpr()->IsBinary()) {
			sig.SetError(ERR_ValueError, "not a binary expression");
			return Value::Null;
		}
		const Expr_Binary *pExpr = dynamic_cast<const Expr_Binary *>(GetExpr());
		return Value(new Object_expr(env, Expr::Reference(pExpr->GetRight())));
	} else if (pSymbol->IsIdentical(Gura_Symbol(car))) {
		if (!GetExpr()->IsCompound()) {
			sig.SetError(ERR_ValueError, "not a compound expression");
			return Value::Null;
		}
		const Expr_Compound *pExpr = dynamic_cast<const Expr_Compound *>(GetExpr());
		return Value(new Object_expr(env, Expr::Reference(pExpr->GetCar())));
	} else if (pSymbol->IsIdentical(Gura_Symbol(cdr))) {
		if (!GetExpr()->IsCompound()) {
			sig.SetError(ERR_ValueError, "not a compound expression");
			return Value::Null;
		}
		const Expr_Compound *pExpr = dynamic_cast<const Expr_Compound *>(GetExpr());
		return Value(env, new Iterator_expr(pExpr->GetExprOwner().Reference()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(block))) {
		if (!GetExpr()->IsCaller()) {
			sig.SetError(ERR_ValueError, "not a caller expression");
			return Value::Null;
		}
		const Expr_Caller *pExpr = dynamic_cast<const Expr_Caller *>(GetExpr());
		const Expr_Block *pExprBlock = pExpr->GetBlock();
		if (pExprBlock == NULL) return Value::Null;
		return Value(new Object_expr(env, Expr::Reference(pExprBlock)));
	} else if (pSymbol->IsIdentical(Gura_Symbol(value))) {
		if (!GetExpr()->IsValue()) {
			sig.SetError(ERR_ValueError, "expression is not a value");
			return Value::Null;
		}
		const Expr_Value *pExpr = dynamic_cast<const Expr_Value *>(GetExpr());
		return pExpr->GetValue();
	} else if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		if (!GetExpr()->IsString()) {
			sig.SetError(ERR_ValueError, "expression is not a string");
			return Value::Null;
		}
		const Expr_String *pExpr = dynamic_cast<const Expr_String *>(GetExpr());
		return Value(env, pExpr->GetString());
	} else if (pSymbol->IsIdentical(Gura_Symbol(symbol))) {
		if (!GetExpr()->IsSymbol()) {
			sig.SetError(ERR_ValueError, "expression is not a symbol");
			return Value::Null;
		}
		const Expr_Symbol *pExpr = dynamic_cast<const Expr_Symbol *>(GetExpr());
		return Value(pExpr->GetSymbol());
	} else if (pSymbol->IsIdentical(Gura_Symbol(blockparam))) {
		if (!GetExpr()->IsBlock()) {
			sig.SetError(ERR_ValueError, "expression is not a block");
			return Value::Null;
		}
		const Expr_Block *pExpr = dynamic_cast<const Expr_Block *>(GetExpr());
		const Expr_BlockParam *pExprParam = pExpr->GetParam();
		if (pExprParam == NULL) return Value::Null;
		return Value(new Object_expr(env, Expr::Reference(pExprParam)));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_expr::ToString(Signal sig, bool exprFlag)
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
// Gura interfaces for Object_expr
//-----------------------------------------------------------------------------
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

// expr#tofunction(`args*)
Gura_DeclareMethod(expr, tofunction)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "args", VTYPE_quote, OCCUR_ZeroOrMore);
}

Gura_ImplementMethod(expr, tofunction)
{
	const Expr *pExpr = Object_expr::GetThisObj(args)->GetExpr();
	Function *pFunc = pExpr->ToFunction(env, sig,
								args.GetList(0), args.GetAttrs());
	return Value(env, pFunc, Value::Null);
}

// expr#eval()
Gura_DeclareMethod(expr, eval)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Evaluate an expr object.");
}

Gura_ImplementMethod(expr, eval)
{
	Environment envBlock(&env, ENVTYPE_block);
	return Object_expr::GetThisObj(args)->GetExpr()->Exec(envBlock, sig);
}

// expr#genscript(stream?:stream:w, style?:symbol):void
Gura_DeclareMethod(expr, genscript)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareArg(env, "style", VTYPE_symbol, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Outputs a script that describes the expression to the specified `stream`.\n"
	"If `stream` is omitted, script shall be written into standard output.\n");
}

Gura_ImplementMethod(expr, genscript)
{
	const Expr *pExpr = Object_expr::GetThisObj(args)->GetExpr();
	Stream *pStream = args.IsStream(0)? &args.GetStream(0) : env.GetConsole();
	Expr::ScriptStyle scriptStyle = Expr::SCRSTYLE_Fancy;
	if (args.IsSymbol(1)) {
		const Symbol *pSymbol = args.GetSymbol(1);
		scriptStyle = Expr::SymbolToScriptStyle(pSymbol);
		if (scriptStyle == Expr::SCRSTYLE_None) {
			sig.SetError(ERR_ValueError,
					"invalid symbol for script style: %s", pSymbol->GetName());
			return Value::Null;
		}
	}
	pExpr->GenerateScript(sig, *pStream, scriptStyle, 0);
	return Value::Null;
}

// type chekers - Unary and descendants
ImplementTypeChecker(isunary,		IsUnary)
ImplementTypeChecker(isunaryop,		IsUnaryOp)
ImplementTypeChecker(isquote,		IsQuote)
ImplementTypeChecker(isforce,		IsForce)
ImplementTypeChecker(isprefix,		IsPrefix)
ImplementTypeChecker(issuffix,		IsSuffix)
// type chekers - Binary and descendants
ImplementTypeChecker(isbinary,		IsBinary)
ImplementTypeChecker(isbinaryop,	IsBinaryOp)
ImplementTypeChecker(isassign,		IsAssign)
ImplementTypeChecker(isdictassign,	IsDictAssign)
ImplementTypeChecker(ismember,		IsMember)
// type chekers - Container and descendants
ImplementTypeChecker(iscontainer,	IsContainer)
ImplementTypeChecker(isroot,		IsRoot)
ImplementTypeChecker(isblockparam,	IsBlockParam)
ImplementTypeChecker(isblock,		IsBlock)
ImplementTypeChecker(islister,		IsLister)
ImplementTypeChecker(isiterlink,	IsIterLink)
ImplementTypeChecker(istmplscript,	IsTmplScript)
// type chekers - Compound and descendants
ImplementTypeChecker(iscompound,	IsCompound)
ImplementTypeChecker(isindexer,		IsIndexer)
ImplementTypeChecker(iscaller,		IsCaller)
// type chekers - others
ImplementTypeChecker(isvalue,		IsValue)
ImplementTypeChecker(issymbol,		IsSymbol)
ImplementTypeChecker(isstring,		IsString)
ImplementTypeChecker(istmplstring,	IsTmplString)

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_expr::Class_expr(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_expr)
{
}

void Class_expr::Prepare(Environment &env)
{
	Gura_AssignMethod(expr, unquote);
	Gura_AssignMethod(expr, tofunction);
	Gura_AssignMethod(expr, eval);
	Gura_AssignMethod(expr, genscript);
	// type chekers - Unary and descendants
	Gura_AssignMethod(expr,	isunary);
	Gura_AssignMethod(expr,	isunaryop);
	Gura_AssignMethod(expr,	isquote);
	Gura_AssignMethod(expr,	isforce);
	Gura_AssignMethod(expr,	isprefix);
	Gura_AssignMethod(expr,	issuffix);
	// type chekers - Binary and descendants
	Gura_AssignMethod(expr,	isbinary);
	Gura_AssignMethod(expr,	isbinaryop);
	Gura_AssignMethod(expr,	isassign);
	Gura_AssignMethod(expr,	isdictassign);
	Gura_AssignMethod(expr,	ismember);
	// type chekers - Container and descendants
	Gura_AssignMethod(expr,	iscontainer);
	Gura_AssignMethod(expr,	isroot);
	Gura_AssignMethod(expr,	isblockparam);
	Gura_AssignMethod(expr,	isblock);
	Gura_AssignMethod(expr,	islister);
	Gura_AssignMethod(expr,	isiterlink);
	Gura_AssignMethod(expr,	istmplscript);
	// type chekers - Compound and descendants
	Gura_AssignMethod(expr,	iscompound);
	Gura_AssignMethod(expr,	isindexer);
	Gura_AssignMethod(expr,	iscaller);
	// type chekers - others
	Gura_AssignMethod(expr,	isvalue);
	Gura_AssignMethod(expr,	issymbol);
	Gura_AssignMethod(expr,	isstring);
	Gura_AssignMethod(expr,	istmplstring);
}

bool Class_expr::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsSymbol()) {		// cast Symbol to Expr
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

//-----------------------------------------------------------------------------
// Iterator_expr
//-----------------------------------------------------------------------------
Iterator_expr::Iterator_expr(ExprOwner *pExprOwner) :
						Iterator(false), _idxExpr(0), _pExprOwner(pExprOwner)
{
}

Iterator *Iterator_expr::GetSource()
{
	return NULL;
}

bool Iterator_expr::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_idxExpr < _pExprOwner->size()) {
		Expr *pExpr = (*_pExprOwner)[_idxExpr++];
		value = Value(new Object_expr(env, pExpr->Reference()));
		return true;
	}
	return false;
}

String Iterator_expr::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:expr";
	rtn += ">";
	return rtn;
}

void Iterator_expr::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
