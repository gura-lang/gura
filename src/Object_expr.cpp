//
// Object_expr
//

#include "stdafx.h"

#define ImplementTypeChecker(funcName, func) \
Gura_DeclareMethod(expr, funcName) {} \
Gura_ImplementMethod(expr, funcName) { \
	return Value(Object_expr::GetSelfObj(args)->GetExpr()->func()); \
}

namespace Gura {

//-----------------------------------------------------------------------------
// Object_expr
//-----------------------------------------------------------------------------
Object_expr::Object_expr(const Object_expr &obj) :
								Object(obj), _pExpr(obj._pExpr->IncRef())
{
}

Object_expr::~Object_expr()
{
	Expr::Delete(_pExpr);
}

Object *Object_expr::Clone() const
{
	return new Object_expr(*this);
}

String Object_expr::ToString(Signal sig, bool exprFlag)
{
	String str;
	if (_pExpr->IsValue() || _pExpr->IsSymbol() || _pExpr->IsCaller()) {
		if (exprFlag) str += '`';
		str += _pExpr->ToString();
	} else if (exprFlag) {
		if (_pExpr->IsUnary() || _pExpr->IsBinary()) {
			str += "`(";
			str += _pExpr->ToString();
			str += ")";
		} else {
			str += "`";
			str += _pExpr->ToString();
		}
	} else {
		str += _pExpr->ToString();
	}
	return str;
}

bool Object_expr::DoSerialize(Signal sig, Stream &stream) const
{
	return Expr::Serialize(sig, stream, _pExpr);
}

bool Object_expr::DoDeserialize(Signal sig, Stream &stream)
{
	Expr *pExpr = NULL;
	if (!Expr::Deserialize(sig, stream, &pExpr, true)) return false;
	Expr::Delete(_pExpr);
	_pExpr = pExpr;
	return true;
}

//-----------------------------------------------------------------------------
// Object_expr::Iterator_Each
//-----------------------------------------------------------------------------
Object_expr::Iterator_Each::~Iterator_Each()
{
	Expr::Delete(_pExprContainer);
}

bool Object_expr::Iterator_Each::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_ppExpr == _pExprContainer->GetExprList().end()) return false;
	Object_expr *pObj = new Object_expr(_env, (*_ppExpr)->IncRef());
	value = Value(pObj);
	_ppExpr++;
	return true;
}

String Object_expr::Iterator_Each::ToString(Signal sig) const
{
	String rtn = "<iterator:expr:each>";
	return rtn;
}

void Object_expr::Iterator_Each::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_expr
//-----------------------------------------------------------------------------
// expr#child()
Gura_DeclareMethod(expr, child)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(expr, child)
{
	const Expr *pExpr = Object_expr::GetSelfObj(args)->GetExpr();
	if (!pExpr->IsUnary()) {
		sig.SetError(ERR_ValueError, "not a unary expression");
		return Value::Null;
	}
	Value result;
	result.InitAsExpr(env,
			dynamic_cast<const Expr_Unary *>(pExpr)->GetChild()->IncRef());
	return result;
}

// expr#left()
Gura_DeclareMethod(expr, left)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(expr, left)
{
	const Expr *pExpr = Object_expr::GetSelfObj(args)->GetExpr();
	if (!pExpr->IsBinary()) {
		sig.SetError(ERR_ValueError, "not a binary expression");
		return Value::Null;
	}
	Value result;
	result.InitAsExpr(env,
			dynamic_cast<const Expr_Binary *>(pExpr)->GetLeft()->IncRef());
	return result;
}

// expr#right()
Gura_DeclareMethod(expr, right)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(expr, right)
{
	const Expr *pExpr = Object_expr::GetSelfObj(args)->GetExpr();
	if (!pExpr->IsBinary()) {
		sig.SetError(ERR_ValueError, "not a binary expression");
		return Value::Null;
	}
	Value result;
	result.InitAsExpr(env,
			dynamic_cast<const Expr_Binary *>(pExpr)->GetRight()->IncRef());
	return result;
}

// expr#each() {block?}
Gura_DeclareMethod(expr, each)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(expr, each)
{
	const Expr *pExpr = Object_expr::GetSelfObj(args)->GetExpr();
	if (!pExpr->IsContainer()) {
		sig.SetError(ERR_ValueError, "not a container expression");
		return Value::Null;
	}
	Iterator *pIterator = new Object_expr::Iterator_Each(env, 
							dynamic_cast<Expr_Container *>(pExpr->IncRef()));
	return ReturnIterator(env, sig, args, pIterator);
}

// expr#car()
Gura_DeclareMethod(expr, car)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(expr, car)
{
	const Expr *pExpr = Object_expr::GetSelfObj(args)->GetExpr();
	if (!pExpr->IsCompound()) {
		sig.SetError(ERR_ValueError, "not a compound expression");
		return Value::Null;
	}
	Value result;
	result.InitAsExpr(env,
			dynamic_cast<const Expr_Compound *>(pExpr)->GetCar()->IncRef());
	return result;
}

// expr#cdr()
Gura_DeclareMethod(expr, cdr)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(expr, cdr)
{
	const Expr *pExpr = Object_expr::GetSelfObj(args)->GetExpr();
	if (!pExpr->IsCompound()) {
		sig.SetError(ERR_ValueError, "not a compound expression");
		return Value::Null;
	}
	Value result;
	ValueList &valList = result.InitAsList(env);
	foreach_const (ExprList, ppExpr,
					dynamic_cast<const Expr_Compound *>(pExpr)->GetExprList()) {
		const Expr *pExpr = *ppExpr;
		Value value;
		value.InitAsExpr(env, pExpr->IncRef());
		valList.push_back(value);
	}
	return result;
}

// expr#unquote()
Gura_DeclareMethod(expr, unquote)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(expr, unquote)
{
	const Expr *pExpr = Object_expr::GetSelfObj(args)->GetExpr();
	Value result;
	result.InitAsExpr(env, pExpr->Unquote()->IncRef());
	return result;
}

// expr#block()
Gura_DeclareMethod(expr, block)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(expr, block)
{
	const Expr *pExpr = Object_expr::GetSelfObj(args)->GetExpr();
	if (!pExpr->IsCaller()) {
		sig.SetError(ERR_ValueError, "not a caller expression");
		return Value::Null;
	}
	const Expr_Block *pExprBlock =
						dynamic_cast<const Expr_Caller *>(pExpr)->GetBlock();
	if (pExprBlock == NULL) return Value::Null;
	Value result;
	result.InitAsExpr(env, pExprBlock->IncRef());
	return result;
}

// expr#exprname()
Gura_DeclareMethod(expr, exprname)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(expr, exprname)
{
	const Expr *pExpr = Object_expr::GetSelfObj(args)->GetExpr();
	return Value(env, pExpr->GetTypeName());
}

// expr#getvalue()
Gura_DeclareMethod(expr, getvalue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(expr, getvalue)
{
	const Expr *pExpr = Object_expr::GetSelfObj(args)->GetExpr();
	if (!pExpr->IsValue()) {
		sig.SetError(ERR_ValueError, "expression is not a value");
		return Value::Null;
	}
	return dynamic_cast<const Expr_Value *>(pExpr)->GetValue();
}

// expr#getstring()
Gura_DeclareMethod(expr, getstring)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(expr, getstring)
{
	const Expr *pExpr = Object_expr::GetSelfObj(args)->GetExpr();
	if (!pExpr->IsString()) {
		sig.SetError(ERR_ValueError, "expression is not a string");
		return Value::Null;
	}
	return Value(env, dynamic_cast<const Expr_String *>(pExpr)->GetString());
}

// expr#getsymbol()
Gura_DeclareMethod(expr, getsymbol)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(expr, getsymbol)
{
	const Expr *pExpr = Object_expr::GetSelfObj(args)->GetExpr();
	if (!pExpr->IsSymbol()) {
		sig.SetError(ERR_ValueError, "expression is not a symbol");
		return Value::Null;
	}
	return Value(dynamic_cast<const Expr_Symbol *>(pExpr)->GetSymbol());
}

// expr#tofunction(`args*)
Gura_DeclareMethod(expr, tofunction)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "args", VTYPE_quote, OCCUR_ZeroOrMore);
}

Gura_ImplementMethod(expr, tofunction)
{
	const Expr *pExpr = Object_expr::GetSelfObj(args)->GetExpr();
	Function *pFunc = pExpr->ToFunction(env, sig,
								args.GetList(0), args.GetAttrs());
	return Value(env, pFunc, Value::Null);
}

// expr#eval()
Gura_DeclareMethod(expr, eval)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetHelp("Evaluate an expr object.");
}

Gura_ImplementMethod(expr, eval)
{
	Environment envBlock(&env, ENVTYPE_block);
	return Object_expr::GetSelfObj(args)->GetExpr()->Exec(envBlock, sig);
}

// type chekers
ImplementTypeChecker(isunary,		IsUnary)
ImplementTypeChecker(isunaryop,		IsUnaryOp)
ImplementTypeChecker(isquote,		IsQuote)
ImplementTypeChecker(isforce,		IsForce)
ImplementTypeChecker(isprefix,		IsPrefix)
ImplementTypeChecker(issuffix,		IsSuffix)

ImplementTypeChecker(isbinary,		IsBinary)
ImplementTypeChecker(isbinaryop,	IsBinaryOp)
ImplementTypeChecker(isassign,		IsAssign)
ImplementTypeChecker(isdictassign,	IsDictAssign)
ImplementTypeChecker(ismember,		IsMember)

ImplementTypeChecker(iscontainer,	IsContainer)
ImplementTypeChecker(isblockparam,	IsBlockParam)
ImplementTypeChecker(isblock,		IsBlock)
ImplementTypeChecker(islister,		IsLister)

ImplementTypeChecker(isvalue,		IsValue)
ImplementTypeChecker(isstring,		IsString)
ImplementTypeChecker(issymbol,		IsSymbol)
ImplementTypeChecker(isindexer,		IsIndexer)
ImplementTypeChecker(iscaller,		IsCaller)

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_expr::Class_expr(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_expr)
{
	Gura_AssignMethod(expr, child);
	Gura_AssignMethod(expr, left);
	Gura_AssignMethod(expr, right);
	Gura_AssignMethod(expr, each);
	Gura_AssignMethod(expr, car);
	Gura_AssignMethod(expr, cdr);
	Gura_AssignMethod(expr, unquote);
	Gura_AssignMethod(expr, block);
	Gura_AssignMethod(expr, exprname);
	Gura_AssignMethod(expr, getvalue);
	Gura_AssignMethod(expr, getstring);
	Gura_AssignMethod(expr, getsymbol);
	Gura_AssignMethod(expr, tofunction);
	Gura_AssignMethod(expr, eval);
	Gura_AssignMethod(expr, isunary);
	Gura_AssignMethod(expr, isunaryop);
	Gura_AssignMethod(expr, isquote);
	Gura_AssignMethod(expr, isforce);
	Gura_AssignMethod(expr, isprefix);
	Gura_AssignMethod(expr, issuffix);
	Gura_AssignMethod(expr, isbinary);
	Gura_AssignMethod(expr, isbinaryop);
	Gura_AssignMethod(expr, isassign);
	Gura_AssignMethod(expr, isdictassign);
	Gura_AssignMethod(expr, ismember);
	Gura_AssignMethod(expr, iscontainer);
	Gura_AssignMethod(expr, isblockparam);
	Gura_AssignMethod(expr, isblock);
	Gura_AssignMethod(expr, islister);
	Gura_AssignMethod(expr, isvalue);
	Gura_AssignMethod(expr, isstring);
	Gura_AssignMethod(expr, issymbol);
	Gura_AssignMethod(expr, isindexer);
	Gura_AssignMethod(expr, iscaller);
}

bool Class_expr::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsSymbol()) {		// cast Symbol to Expr
		const Symbol *pSymbol = value.GetSymbol();
		value.InitAsExpr(env, new Expr_Symbol(pSymbol));
		return true;
	}
	return false;
}

Object *Class_expr::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	ERROREND(env, "this function must not be called");
	return NULL;
}

void Class_expr::OnModuleEntry(Environment &env, Signal sig)
{
}

}
