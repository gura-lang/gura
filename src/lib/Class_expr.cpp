//=============================================================================
// Gura class: expr
//=============================================================================
#include "stdafx.h"

#define ImplementTypeChecker(symbol, func) \
Gura_DeclareMethod(expr, is##symbol) { \
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None); \
	AddHelp( \
		Gura_Symbol(en), \
		"Returns `true` if expr is an expression of " #symbol "."); \
} \
Gura_ImplementMethod(expr, is##symbol) { \
	return Value(Object_expr::GetObjectThis(arg)->GetExpr()->func()); \
}

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

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

String Object_expr::ToString(bool exprFlag)
{
	String str;
	if (_pExpr->IsValue() || _pExpr->IsIdentifier() || _pExpr->IsCaller()) {
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
// Implementation of function
//-----------------------------------------------------------------------------
// expr(src:stream:r) {block?}
Gura_DeclareFunction(expr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_expr));
	AddHelp(
		Gura_Symbol(en),
		"Parses a Gura script from the stream `src` and creates an `expr` instance.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("expr", "expr"));
}

Gura_ImplementFunction(expr)
{
	Stream &stream = Object_stream::GetObject(arg, 0)->GetStream();
	Parser parser(env.GetSignal(), stream.GetName());
	AutoPtr<Expr_Root> pExprRoot(parser.ParseStream(env, stream));
	if (pExprRoot.IsNull()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_expr(env, pExprRoot.release())));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// expr#attrfront
Gura_DeclareProperty_R(expr, attrfront)
{
	SetPropAttr(VTYPE_list);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, attrfront)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	const SymbolList *pAttrFront = nullptr;
	if (pExpr->IsIdentifier()) {
		const Expr_Identifier *pExprEx = dynamic_cast<const Expr_Identifier *>(pExpr);
		pAttrFront = &pExprEx->GetAttrFront();
	} else if (pExpr->IsCaller()) {
		const Expr_Caller *pExprEx = dynamic_cast<const Expr_Caller *>(pExpr);
		pAttrFront = &pExprEx->GetAttrFront();
	}
	if (pAttrFront != nullptr) {
		Value rtn;
		Object_list *pObjList = rtn.InitAsList(env, pAttrFront->size());
		pObjList->Reserve(pAttrFront->size());
		foreach_const (SymbolList, ppSymbol, *pAttrFront) {
			pObjList->Add(Value(*ppSymbol));
		}
		return rtn;
	}
	env.SetError(ERR_ValueError, "expression is not an identifier nor a caller");
	return Value::Nil;
}

// expr#attrs
Gura_DeclareProperty_R(expr, attrs)
{
	SetPropAttr(VTYPE_list);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, attrs)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	ULong flags = 0;
	ResultMode resultMode = RSLTMODE_Normal;
	const SymbolSet *pAttrs = nullptr;
	if (pExpr->IsIdentifier()) {
		const Expr_Identifier *pExprEx = dynamic_cast<const Expr_Identifier *>(pExpr);
		pAttrs = &pExprEx->GetAttrs();
	} else if (pExpr->IsCaller()) {
		const Expr_Caller *pExprEx = dynamic_cast<const Expr_Caller *>(pExpr);
		pAttrs = &pExprEx->GetAttrs();
		flags = pExprEx->GetCallerInfo().GetFlagsToSet();
		resultMode = pExprEx->GetCallerInfo().GetResultMode();
	}
	if (pAttrs == nullptr) {
		env.SetError(ERR_ValueError, "expression is not an identifier nor a caller");
		return Value::Nil;
	}
	Value rtn;
	Object_list *pObjList = rtn.InitAsList(env);
	pObjList->Reserve(pAttrs->size() + 8);
	foreach_const (SymbolSet, ppSymbol, *pAttrs) {
		pObjList->Add(Value(*ppSymbol));
	}
	ULong flag = 1;
	const Symbol *pSymbol = nullptr;
	for ( ; flags != 0; flags >>= 1, flag <<= 1) {
		if ((flags & 1) != 0 && (pSymbol = Symbol::FromFlag(flag)) != nullptr) {
			pObjList->Add(Value(pSymbol));
		}
	}
	if (resultMode != RSLTMODE_Normal &&
		(pSymbol = Symbol::FromResultMode(resultMode)) != nullptr) {
		pObjList->Add(Value(pSymbol));
	}
	return rtn;
}

// expr#attrsopt
Gura_DeclareProperty_R(expr, attrsopt)
{
	SetPropAttr(VTYPE_list);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, attrsopt)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	const SymbolSet *pAttrsOpt = nullptr;
	if (pExpr->IsIdentifier()) {
		const Expr_Identifier *pExprEx = dynamic_cast<const Expr_Identifier *>(pExpr);
		pAttrsOpt = &pExprEx->GetAttrsOpt();
	} else if (pExpr->IsCaller()) {
		const Expr_Caller *pExprEx = dynamic_cast<const Expr_Caller *>(pExpr);
		pAttrsOpt = &pExprEx->GetAttrsOpt();
	}
	if (pAttrsOpt == nullptr) {
		Value rtn;
		Object_list *pObjList = rtn.InitAsList(env, pAttrsOpt->size());
		pObjList->Reserve(pAttrsOpt->size());
		foreach_const (SymbolSet, ppSymbol, *pAttrsOpt) {
			pObjList->Add(Value(*ppSymbol));
		}
		return rtn;
	}
	env.SetError(ERR_ValueError, "expression is not an identifier nor a caller");
	return Value::Nil;
}

// expr#block
Gura_DeclareProperty_R(expr, block)
{
	SetPropAttr(VTYPE_expr);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, block)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	if (pExpr->IsCaller()) {
		const Expr_Caller *pExprEx = dynamic_cast<const Expr_Caller *>(pExpr);
		const Expr_Block *pExprBlock = pExprEx->GetBlock();
		if (pExprBlock == nullptr) return Value::Nil;
		return Value(new Object_expr(env, Expr::Reference(pExprBlock)));
	}
	env.SetError(ERR_ValueError, "not a caller expression");
	return Value::Nil;
}

// expr#blockparam
Gura_DeclareProperty_R(expr, blockparam)
{
	SetPropAttr(VTYPE_iterator);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, blockparam)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	if (pExpr->IsBlock()) {
		const Expr_Block *pExprEx = dynamic_cast<const Expr_Block *>(pExpr);
		const ExprOwner *pExprOwnerParam = pExprEx->GetExprOwnerParam();
		if (pExprOwnerParam == nullptr) return Value::Nil;
		return Value(new Object_iterator(env, new ExprOwner::Iterator(pExprOwnerParam->Reference())));
	}
	env.SetError(ERR_ValueError, "expression is not a block");
	return Value::Nil;
}

// expr#body
Gura_DeclareProperty_R(expr, body)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, body)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	if (pExpr->IsSuffixed()) {
		const Expr_Suffixed *pExprEx = dynamic_cast<const Expr_Suffixed *>(pExpr);
		return Value(pExprEx->GetBody());
	}
	env.SetError(ERR_ValueError, "expression is not a suffixed");
	return Value::Nil;
}

// expr#car
Gura_DeclareProperty_R(expr, car)
{
	SetPropAttr(VTYPE_expr);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, car)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	if (pExpr->IsCompound()) {
		const Expr_Compound *pExprEx = dynamic_cast<const Expr_Compound *>(pExpr);
		return Value(new Object_expr(env, Expr::Reference(pExprEx->GetCar())));
	}
	env.SetError(ERR_ValueError, "not a compound expression");
	return Value::Nil;
}

// expr#cdr
Gura_DeclareProperty_R(expr, cdr)
{
	SetPropAttr(VTYPE_expr);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, cdr)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	if (pExpr->IsCompound()) {
		const Expr_Compound *pExprEx = dynamic_cast<const Expr_Compound *>(pExpr);
		return Value(new Object_iterator(env, new ExprOwner::Iterator(pExprEx->GetExprOwner().Reference())));
	}
	env.SetError(ERR_ValueError, "not a compound expression");
	return Value::Nil;
}

// expr#child
Gura_DeclareProperty_R(expr, child)
{
	SetPropAttr(VTYPE_expr);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, child)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	if (pExpr->IsUnary()) {
		const Expr_Unary *pExprEx = dynamic_cast<const Expr_Unary *>(pExpr);
		return Value(new Object_expr(env, Expr::Reference(pExprEx->GetChild())));
	}
	env.SetError(ERR_ValueError, "not a unary expression");
	return Value::Nil;
}

// expr#children
Gura_DeclareProperty_R(expr, children)
{
	SetPropAttr(VTYPE_iterator);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, children)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	if (pExpr->IsCollector()) {
		const Expr_Collector *pExprEx = dynamic_cast<const Expr_Collector *>(pExpr);
		return Value(new Object_iterator(env, new ExprOwner::Iterator(pExprEx->GetExprOwner().Reference())));
	}
	env.SetError(ERR_ValueError, "not a collector expression");
	return Value::Nil;
}

// expr#left
Gura_DeclareProperty_R(expr, left)
{
	SetPropAttr(VTYPE_expr);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, left)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	if (pExpr->IsBinary()) {
		const Expr_Binary *pExprEx = dynamic_cast<const Expr_Binary *>(pExpr);
		return Value(new Object_expr(env, Expr::Reference(pExprEx->GetLeft())));
	} else if (pExpr->IsMember()) {
		const Expr_Member *pExprEx = dynamic_cast<const Expr_Member *>(pExpr);
		return Value(new Object_expr(env, Expr::Reference(pExprEx->GetTarget())));
	}
	env.SetError(ERR_ValueError, "expression is not a binary nor a member");
	return Value::Nil;
}

// expr#lineno
Gura_DeclareProperty_R(expr, lineno)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, lineno)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	return Value(pExpr->GetLineNoTop());
}

// expr#linenobtm
Gura_DeclareProperty_R(expr, linenobtm)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, linenobtm)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	return Value(pExpr->GetLineNoBtm());
}

// expr#operator
Gura_DeclarePropertyAlias_R(expr, operator_, "operator")
{
	SetPropAttr(VTYPE_operator);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, operator_)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	if (pExpr->IsUnaryOp()) {
		const Expr_UnaryOp *pExprEx = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		return Value(new Object_operator(env,
										 pExprEx->GetOperator()->GetOpType(), OPTYPE_None));
	} else if (pExpr->IsBinaryOp()) {
		const Expr_BinaryOp *pExprEx = dynamic_cast<const Expr_BinaryOp *>(pExpr);
		return Value(new Object_operator(env,
										 OPTYPE_None, pExprEx->GetOperator()->GetOpType()));
	} else if (pExpr->IsAssign()) {
		const Expr_Assign *pExprEx = dynamic_cast<const Expr_Assign *>(pExpr);
		const Operator *pOperator = pExprEx->GetOperatorToApply();
		if (pOperator == nullptr) return Value::Nil;
		return Value(new Object_operator(env, OPTYPE_None, pOperator->GetOpType()));
	}
	env.SetError(ERR_ValueError, "expression is not a unaryop, a binaryop nor an assign");
	return Value::Nil;
}

// expr#postext
Gura_DeclareProperty_R(expr, postext)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, postext)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	return Value(pExpr->MakePosText());
}

// expr#right
Gura_DeclareProperty_R(expr, right)
{
	SetPropAttr(VTYPE_expr);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, right)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	if (pExpr->IsBinary()) {
		const Expr_Binary *pExprEx = dynamic_cast<const Expr_Binary *>(pExpr);
		return Value(new Object_expr(env, Expr::Reference(pExprEx->GetRight())));
	} else if (pExpr->IsMember()) {
		const Expr_Member *pExprEx = dynamic_cast<const Expr_Member *>(pExpr);
		return Value(new Object_expr(env, Expr::Reference(pExprEx->GetSelector())));
	}
	env.SetError(ERR_ValueError, "expression is not a binary nor a member");
	return Value::Nil;
}

// expr#source
Gura_DeclareProperty_R(expr, source)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, source)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	const char *sourceName = pExpr->GetSourceName();
	if (sourceName == nullptr) return Value::Nil;
	return Value(sourceName);
}

// expr#suffix
Gura_DeclareProperty_R(expr, suffix)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, suffix)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	if (pExpr->IsSuffixed()) {
		const Expr_Suffixed *pExprEx = dynamic_cast<const Expr_Suffixed *>(pExpr);
		return Value(pExprEx->GetSymbolSuffix());
	}
	env.SetError(ERR_ValueError, "expression is not a suffixed");
	return Value::Nil;
}

// expr#symbol
Gura_DeclareProperty_R(expr, symbol)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, symbol)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	if (pExpr->IsIdentifier()) {
		const Expr_Identifier *pExprEx = dynamic_cast<const Expr_Identifier *>(pExpr);
		return Value(pExprEx->GetSymbol());
	}
	env.SetError(ERR_ValueError, "expression is not an identifier");
	return Value::Nil;
}

// expr#trailer
Gura_DeclareProperty_R(expr, trailer)
{
	SetPropAttr(VTYPE_expr);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, trailer)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	if (pExpr->IsCaller()) {
		const Expr_Caller *pExprEx = dynamic_cast<const Expr_Caller *>(pExpr);
		const Expr_Caller *pExprTrailer = pExprEx->GetTrailer();
		if (pExprTrailer == nullptr) return Value::Nil;
		return Value(new Object_expr(env, Expr::Reference(pExprTrailer)));
	}
	env.SetError(ERR_ValueError, "not a caller expression");
	return Value::Nil;
}

// expr#typename
Gura_DeclarePropertyAlias_R(expr, typename_, "typename")
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, typename_)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	return Value(pExpr->GetTypeName());
}

// expr#typesym
Gura_DeclareProperty_R(expr, typesym)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, typesym)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	return Value(Symbol::Add(pExpr->GetTypeName()));
}

// expr#value
Gura_DeclareProperty_R(expr, value)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(expr, value)
{
	const Expr *pExpr = Object_expr::GetObject(valueThis)->GetExpr();
	if (pExpr->IsValue()) {
		const Expr_Value *pExprEx = dynamic_cast<const Expr_Value *>(pExpr);
		return pExprEx->GetValue();
	}
	env.SetError(ERR_ValueError, "expression is not a value");
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// expr#eval(env?:environment)
Gura_DeclareMethod(expr, eval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "env", VTYPE_environment, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Evaluates the `expr` instance.\n"
		"\n"
		"If the argument `env` is specified, that environment is used for evaluation.\n"
		"If omitted, the current scope is used.\n");
}

Gura_ImplementMethod(expr, eval)
{
	const Expr *pExpr = Object_expr::GetObjectThis(arg)->GetExpr();
	AutoPtr<Environment> pEnv(
		arg.Is_environment(0)?
		Object_environment::GetObject(arg, 0)->GetEnv().Reference() :
		env.Derive(ENVTYPE_block));
	return pExpr->Exec(*pEnv);
}

// expr.parse(script:string) {block?}
Gura_DeclareClassMethod(expr, parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "script", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Parses a Gura script in the string `script` and creates an `expr` instance.\n"
		"\n"
		"If `block` is specified, it will be evaluated with block parameter\n"
		"in a format of `|expr:expr|` where `expr` is the created instance.");
}

Gura_ImplementClassMethod(expr, parse)
{
	AutoPtr<Expr_Block> pExpr(new Expr_Block());
	Parser parser(env.GetSignal(), SRCNAME_string);
	if (!parser.ParseString(env, pExpr->GetExprOwner(),
								arg.GetString(0), true)) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_expr(env, pExpr.release())));
}

// expr#textize(style?:symbol, indent?:string)
Gura_DeclareMethod(expr, textize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "style", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "indent", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Composes a script text from a content of `expr`.\n"
		"\n"
		"Argument `style` specifies the text style output, which takes the following symbols:\n"
		"\n"
		"- `` `crammed`` .. Puts all the text in one line and removes volatile spaces.\n"
		"- `` `oneline`` .. Puts all the text in one line.\n"
		"- `` `brief`` .. Omits content of blocks and long strings with \"`..`\".\n"
		"- `` `fancy`` .. Prints in the most readable style. This is the default.\n"
		"\n"
		"The argument `indent` specifies a string used for indentation.\n"
		"Its default is a sequence of four spaces.");
}

Gura_ImplementMethod(expr, textize)
{
	Signal &sig = env.GetSignal();
	const Expr *pExpr = Object_expr::GetObjectThis(arg)->GetExpr();
	Expr::ScriptStyle scriptStyle = Expr::SCRSTYLE_Fancy;
	if (arg.Is_symbol(0)) {
		const Symbol *pSymbol = arg.GetSymbol(0);
		scriptStyle = Expr::SymbolToScriptStyle(pSymbol);
		if (scriptStyle == Expr::SCRSTYLE_None) {
			sig.SetError(ERR_ValueError,
					"invalid symbol for script style: %s", pSymbol->GetName());
			return Value::Nil;
		}
	}
	const char *strIndent = arg.Is_string(1)? arg.GetString(1) : Expr::IndentDefault;
	String strDst;
	SimpleStream_StringWriter streamDst(strDst);
	if (!pExpr->GenerateScript(sig, streamDst, scriptStyle, 0, strIndent)) return Value::Nil;
	return Value(strDst);
}

// expr#tofunction(`args*)
Gura_DeclareMethod(expr, tofunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "args", VTYPE_quote, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en),
		"Converts the `expr` into a function.\n"
		"\n"
		"If the `expr` is a block that has a block parameter,\n"
		"that would be used as an argument list of the created function.\n"
		"Otherwise, the argument `args` declares the argument list.\n"
		"\n"
		"It would be an error if `args` is specified and a block parameter exists as well.\n");
}

Gura_ImplementMethod(expr, tofunction)
{
	Signal &sig = env.GetSignal();
	Expr_Block *pExprBlock = Object_expr::GetObjectThis(arg)->GetExpr()->ToExprBlock();
	AutoPtr<FunctionCustom> pFunc(FunctionCustom::CreateBlockFunc(env,
					Gura_Symbol(_anonymous_), pExprBlock, FUNCTYPE_Function));
	if (sig.IsSignalled()) return Value::Nil;
	const ValueList &valListArg = arg.GetList(0);
	if (!valListArg.empty()) {
		if (!pFunc->GetDeclOwner().empty()) {
			sig.SetError(ERR_TypeError, "argument declaration conflicts");
			return Value::Nil;
		}
		ExprList exprListArg;
		exprListArg.reserve(arg.GetList(0).size());
		foreach_const (ValueList, pValue, valListArg) {
			exprListArg.push_back(const_cast<Expr *>(pValue->GetExpr()));
		}
		CallerInfo callerInfo(exprListArg, nullptr, arg.GetAttrsShared(), nullptr);
		if (!pFunc->CustomDeclare(env, callerInfo, SymbolSet::Empty)) return Value::Nil;
	}
	return Value(new Object_function(env, pFunc.release()));
}

// expr#unquote()
Gura_DeclareMethod(expr, unquote)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `expr` instance that has removed quote operator from the original `expr`.");
}

Gura_ImplementMethod(expr, unquote)
{
	const Expr *pExpr = Object_expr::GetObjectThis(arg)->GetExpr();
	Object_expr *pObj = new Object_expr(env, Expr::Reference(pExpr->Unquote()));
	return Value(pObj);
}

// expr#write(dst:stream:w, style?:symbol, indent?:string)
Gura_DeclareMethod(expr, write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "style", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "indent", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Outputs a script that describes the expression to the specified `stream`.\n"
		"\n"
		"Argument `style` specifies the text style output, which takes the following symbols:\n"
		"\n"
		"- `` `crammed`` .. Puts all the text in one line and removes volatile spaces.\n"
		"- `` `oneline`` .. Puts all the text in one line.\n"
		"- `` `brief`` .. Omits content of blocks and long strings with \"`..`\".\n"
		"- `` `fancy`` .. Prints in the most readable style. This is the default.\n"
		"\n"
		"The argument `indent` specifies a string used for indentation.\n"
		"Its default is a sequence of four spaces.");
}

Gura_ImplementMethod(expr, write)
{
	Signal &sig = env.GetSignal();
	const Expr *pExpr = Object_expr::GetObjectThis(arg)->GetExpr();
	Expr::ScriptStyle scriptStyle = Expr::SCRSTYLE_Fancy;
	if (arg.Is_symbol(1)) {
		const Symbol *pSymbol = arg.GetSymbol(1);
		scriptStyle = Expr::SymbolToScriptStyle(pSymbol);
		if (scriptStyle == Expr::SCRSTYLE_None) {
			sig.SetError(ERR_ValueError,
					"invalid symbol for script style: %s", pSymbol->GetName());
			return Value::Nil;
		}
	}
	const char *strIndent = arg.Is_string(2)? arg.GetString(2) : Expr::IndentDefault;
	pExpr->GenerateScript(sig, arg.GetStream(0), scriptStyle, 0, strIndent);
	return Value::Nil;
}

// type chekers - Unary and descendants
ImplementTypeChecker(unary,			IsUnary)
ImplementTypeChecker(unaryop,		IsUnaryOp)
ImplementTypeChecker(quote,			IsQuote)
// type chekers - Binary and descendants
ImplementTypeChecker(binary,		IsBinary)
ImplementTypeChecker(binaryop,		IsBinaryOp)
ImplementTypeChecker(assign,		IsAssign)
ImplementTypeChecker(member,		IsMember)
// type chekers - Collector and descendants
ImplementTypeChecker(collector,		IsCollector)
ImplementTypeChecker(root,			IsRoot)
ImplementTypeChecker(block,			IsBlock)
ImplementTypeChecker(lister,		IsLister)
ImplementTypeChecker(iterer,		IsIterer)
// type chekers - Compound and descendants
ImplementTypeChecker(compound,		IsCompound)
ImplementTypeChecker(indexer,		IsIndexer)
ImplementTypeChecker(caller,		IsCaller)
// type chekers - others
ImplementTypeChecker(value,			IsValue)
ImplementTypeChecker(identifier,	IsIdentifier)
ImplementTypeChecker(suffixed,		IsSuffixed)

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_expr::Class_expr(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_expr)
{
}

void Class_expr::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(expr);
	// Assignment of properties
	Gura_AssignProperty(expr, attrfront);
	Gura_AssignProperty(expr, attrs);
	Gura_AssignProperty(expr, attrsopt);
	Gura_AssignProperty(expr, block);
	Gura_AssignProperty(expr, blockparam);
	Gura_AssignProperty(expr, body);
	Gura_AssignProperty(expr, car);
	Gura_AssignProperty(expr, cdr);
	Gura_AssignProperty(expr, child);
	Gura_AssignProperty(expr, children);
	Gura_AssignProperty(expr, left);
	Gura_AssignProperty(expr, lineno);
	Gura_AssignProperty(expr, linenobtm);
	Gura_AssignProperty(expr, operator_);
	Gura_AssignProperty(expr, postext);
	Gura_AssignProperty(expr, right);
	Gura_AssignProperty(expr, source);
	Gura_AssignProperty(expr, suffix);
	Gura_AssignProperty(expr, symbol);
	Gura_AssignProperty(expr, trailer);
	Gura_AssignProperty(expr, typename_);
	Gura_AssignProperty(expr, typesym);
	Gura_AssignProperty(expr, value);
	// Assignment of methods
	Gura_AssignMethod(expr, eval);
	Gura_AssignMethod(expr, parse);
	Gura_AssignMethod(expr, textize);
	Gura_AssignMethod(expr, tofunction);
	Gura_AssignMethod(expr, unquote);
	Gura_AssignMethod(expr, write);
	// type chekers - Unary and descendants
	Gura_AssignMethod(expr,	isunary);
	Gura_AssignMethod(expr,	isunaryop);
	Gura_AssignMethod(expr,	isquote);
	// type chekers - Binary and descendants
	Gura_AssignMethod(expr,	isbinary);
	Gura_AssignMethod(expr,	isbinaryop);
	Gura_AssignMethod(expr,	isassign);
	Gura_AssignMethod(expr,	ismember);
	// type chekers - Collector and descendants
	Gura_AssignMethod(expr,	iscollector);
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
	Gura_AssignMethod(expr,	isidentifier);
	Gura_AssignMethod(expr,	issuffixed);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_expr::CastFrom(Environment &env, Value &value, ULong flags)
{
	if (value.Is_symbol()) {
		// cast symbol to expr
		const Symbol *pSymbol = value.GetSymbol();
		value = Value(new Object_expr(env, new Expr_Identifier(pSymbol)));
		return true;
	}
	env.LookupClass(VTYPE_stream)->CastFrom(env, value, flags);
	if (value.Is_stream()) {
		Stream &stream = value.GetStream();
		Parser parser(env.GetSignal(), stream.GetName());
		AutoPtr<Expr_Root> pExprRoot(parser.ParseStream(env, stream));
		value = Value::Nil; // delete stream instance
		if (pExprRoot.IsNull()) return false;
		value = Value(new Object_expr(env, pExprRoot.release()));
		return true;
	}
	return false;
}

Object *Class_expr::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
