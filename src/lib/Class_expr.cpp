//=============================================================================
// Gura class: expr
//=============================================================================
#include "stdafx.h"

#define ImplementTypeChecker(symbol, func) \
Gura_DeclareMethod(expr, is##symbol) { \
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None); \
	AddHelp( \
		Gura_Symbol(en), Help::FMT_markdown, \
		"Returns `true` if expr is an expression of " #symbol "."); \
} \
Gura_ImplementMethod(expr, is##symbol) { \
	return Value(Object_expr::GetObjectThis(args)->GetExpr()->func()); \
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

bool Object_expr::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(attrs));
	symbols.insert(Gura_Symbol(attrsopt));
	symbols.insert(Gura_Symbol(block));
	symbols.insert(Gura_Symbol(blockparam));
	symbols.insert(Gura_Symbol(body));
	symbols.insert(Gura_Symbol(car));
	symbols.insert(Gura_Symbol(cdr));
	symbols.insert(Gura_Symbol(child));
	symbols.insert(Gura_Symbol(children));
	symbols.insert(Gura_Symbol(left));
	symbols.insert(Gura_Symbol(lineno));
	symbols.insert(Gura_Symbol(linenobtm));
	symbols.insert(Gura_Symbol(operator_));
	symbols.insert(Gura_Symbol(postext));
	symbols.insert(Gura_Symbol(right));
	symbols.insert(Gura_Symbol(source));
	symbols.insert(Gura_Symbol(suffix));
	symbols.insert(Gura_Symbol(symbol));
	symbols.insert(Gura_Symbol(trailer));
	symbols.insert(Gura_Symbol(typename_));
	symbols.insert(Gura_Symbol(typesym));
	symbols.insert(Gura_Symbol(value));
	return true;
}

Value Object_expr::DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(attrfront))) {
		const SymbolList *pAttrFront = nullptr;
		if (GetExpr()->IsIdentifier()) {
			const Expr_Identifier *pExpr = dynamic_cast<const Expr_Identifier *>(GetExpr());
			pAttrFront = &pExpr->GetAttrFront();
		} else if (GetExpr()->IsCaller()) {
			const Expr_Caller *pExpr = dynamic_cast<const Expr_Caller *>(GetExpr());
			pAttrFront = &pExpr->GetAttrFront();
		}
		if (pAttrFront != nullptr) {
			Value rtn;
			ValueList &valList = rtn.InitAsList(env, pAttrFront->size());
			foreach_const (SymbolList, ppSymbol, *pAttrFront) {
				valList.push_back(Value(*ppSymbol));
			}
			return rtn;
		}
		sig.SetError(ERR_ValueError, "expression is not an identifier nor caller");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(attrs))) {
		const SymbolSet *pAttrs = nullptr;
		if (GetExpr()->IsIdentifier()) {
			const Expr_Identifier *pExpr = dynamic_cast<const Expr_Identifier *>(GetExpr());
			pAttrs = &pExpr->GetAttrs();
		} else if (GetExpr()->IsCaller()) {
			const Expr_Caller *pExpr = dynamic_cast<const Expr_Caller *>(GetExpr());
			pAttrs = &pExpr->GetAttrs();
		}
		if (pAttrs != nullptr) {
			Value rtn;
			ValueList &valList = rtn.InitAsList(env, pAttrs->size());
			foreach_const (SymbolSet, ppSymbol, *pAttrs) {
				valList.push_back(Value(*ppSymbol));
			}
			return rtn;
		}
		sig.SetError(ERR_ValueError, "expression is not an identifier nor caller");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(attrsopt))) {
		const SymbolSet *pAttrsOpt = nullptr;
		if (GetExpr()->IsIdentifier()) {
			const Expr_Identifier *pExpr = dynamic_cast<const Expr_Identifier *>(GetExpr());
			pAttrsOpt = &pExpr->GetAttrsOpt();
		} else if (GetExpr()->IsCaller()) {
			const Expr_Caller *pExpr = dynamic_cast<const Expr_Caller *>(GetExpr());
			pAttrsOpt = &pExpr->GetAttrsOpt();
		}
		if (pAttrsOpt == nullptr) {
			Value rtn;
			ValueList &valList = rtn.InitAsList(env, pAttrsOpt->size());
			foreach_const (SymbolSet, ppSymbol, *pAttrsOpt) {
				valList.push_back(Value(*ppSymbol));
			}
			return rtn;
		}
		sig.SetError(ERR_ValueError, "expression is not an identifier nor caller");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(block))) {
		if (GetExpr()->IsCaller()) {
			const Expr_Caller *pExpr = dynamic_cast<const Expr_Caller *>(GetExpr());
			const Expr_Block *pExprBlock = pExpr->GetBlock();
			if (pExprBlock == nullptr) return Value::Nil;
			return Value(new Object_expr(env, Expr::Reference(pExprBlock)));
		}
		sig.SetError(ERR_ValueError, "not a caller expression");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(blockparam))) {
		if (GetExpr()->IsBlock()) {
			const Expr_Block *pExpr = dynamic_cast<const Expr_Block *>(GetExpr());
			const ExprOwner *pExprOwnerParam = pExpr->GetExprOwnerParam();
			if (pExprOwnerParam == nullptr) return Value::Nil;
			return Value(new Object_iterator(env, new ExprOwner::Iterator(pExprOwnerParam->Reference())));
		}
		sig.SetError(ERR_ValueError, "expression is not a block");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(body))) {
		if (GetExpr()->IsSuffixed()) {
			const Expr_Suffixed *pExpr = dynamic_cast<const Expr_Suffixed *>(GetExpr());
			return Value(pExpr->GetBody());
		}
		sig.SetError(ERR_ValueError, "expression is not a suffixed");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(car))) {
		if (GetExpr()->IsCompound()) {
			const Expr_Compound *pExpr = dynamic_cast<const Expr_Compound *>(GetExpr());
			return Value(new Object_expr(env, Expr::Reference(pExpr->GetCar())));
		}
		sig.SetError(ERR_ValueError, "not a compound expression");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(cdr))) {
		if (GetExpr()->IsCompound()) {
			const Expr_Compound *pExpr = dynamic_cast<const Expr_Compound *>(GetExpr());
			return Value(new Object_iterator(env, new ExprOwner::Iterator(pExpr->GetExprOwner().Reference())));
		}
		sig.SetError(ERR_ValueError, "not a compound expression");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(child))) {
		if (GetExpr()->IsUnary()) {
			const Expr_Unary *pExpr = dynamic_cast<const Expr_Unary *>(GetExpr());
			return Value(new Object_expr(env, Expr::Reference(pExpr->GetChild())));
		}
		sig.SetError(ERR_ValueError, "not a unary expression");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(children))) {
		if (GetExpr()->IsCollector()) {
			const Expr_Collector *pExpr = dynamic_cast<const Expr_Collector *>(GetExpr());
			return Value(new Object_iterator(env, new ExprOwner::Iterator(pExpr->GetExprOwner().Reference())));
		}
		sig.SetError(ERR_ValueError, "not a collector expression");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(left))) {
		if (GetExpr()->IsBinary()) {
			const Expr_Binary *pExpr = dynamic_cast<const Expr_Binary *>(GetExpr());
			return Value(new Object_expr(env, Expr::Reference(pExpr->GetLeft())));
		}
		sig.SetError(ERR_ValueError, "not a binary expression");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(lineno))) {
		return Value(GetExpr()->GetLineNoTop());
	} else if (pSymbol->IsIdentical(Gura_Symbol(linenobtm))) {
		return Value(GetExpr()->GetLineNoBtm());
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
			if (pOperator == nullptr) return Value::Nil;
			return Value(new Object_operator(env, OPTYPE_None, pOperator->GetOpType()));
		}
		sig.SetError(ERR_ValueError, "expression is not a unaryop, binaryop nor assign");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(postext))) {
		return Value(GetExpr()->MakePosText());
	} else if (pSymbol->IsIdentical(Gura_Symbol(right))) {
		if (GetExpr()->IsBinary()) {
			const Expr_Binary *pExpr = dynamic_cast<const Expr_Binary *>(GetExpr());
			return Value(new Object_expr(env, Expr::Reference(pExpr->GetRight())));
		}
		sig.SetError(ERR_ValueError, "not a binary expression");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(source))) {
		const char *sourceName = GetExpr()->GetSourceName();
		if (sourceName == nullptr) return Value::Nil;
		return Value(sourceName);
	} else if (pSymbol->IsIdentical(Gura_Symbol(suffix))) {
		if (GetExpr()->IsSuffixed()) {
			const Expr_Suffixed *pExpr = dynamic_cast<const Expr_Suffixed *>(GetExpr());
			return Value(pExpr->GetSymbolSuffix());
		}
		sig.SetError(ERR_ValueError, "expression is not a suffixed");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(symbol))) {
		if (GetExpr()->IsIdentifier()) {
			const Expr_Identifier *pExpr = dynamic_cast<const Expr_Identifier *>(GetExpr());
			return Value(pExpr->GetSymbol());
		}
		sig.SetError(ERR_ValueError, "expression is not an identifier");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(trailer))) {
		if (GetExpr()->IsCaller()) {
			const Expr_Caller *pExpr = dynamic_cast<const Expr_Caller *>(GetExpr());
			const Expr_Caller *pExprTrailer = pExpr->GetTrailer();
			if (pExprTrailer == nullptr) return Value::Nil;
			return Value(new Object_expr(env, Expr::Reference(pExprTrailer)));
		}
		sig.SetError(ERR_ValueError, "not a caller expression");
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_Symbol(typename_))) {
		return Value(GetExpr()->GetTypeName());
	} else if (pSymbol->IsIdentical(Gura_Symbol(typesym))) {
		return Value(Symbol::Add(GetExpr()->GetTypeName()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(value))) {
		if (GetExpr()->IsValue()) {
			const Expr_Value *pExpr = dynamic_cast<const Expr_Value *>(GetExpr());
			return pExpr->GetValue();
		}
		sig.SetError(ERR_ValueError, "expression is not a value");
		return Value::Nil;
	}
	evaluatedFlag = false;
	return Value::Nil;
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
// Implementation of expr
//-----------------------------------------------------------------------------
// expr(src:stream:r) {block?}
Gura_DeclareFunction(expr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_expr));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Parses a Gura script from the stream `src` and creates an `expr` instance.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("expr", "expr"));
}

Gura_ImplementFunction(expr)
{
	Stream &stream = Object_stream::GetObject(args, 0)->GetStream();
	Parser parser(stream.GetName());
	AutoPtr<Expr_Root> pExprRoot(parser.ParseStream(env, stream));
	if (pExprRoot.IsNull()) return Value::Nil;
	return ReturnValue(env, args, Value(new Object_expr(env, pExprRoot.release())));
}

// expr#eval(env?:environment)
Gura_DeclareMethod(expr, eval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "env", VTYPE_environment, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Evaluates the `expr` instance.\n"
		"\n"
		"If the argument `env` is specified, that environment is used for evaluation.\n"
		"If omitted, the current scope is used.\n");
}

Gura_ImplementMethod(expr, eval)
{
	Signal &sig = env.GetSignal();
	const Expr *pExpr = Object_expr::GetObjectThis(args)->GetExpr();
	Environment *pEnv = args.Is_environment(0)?
			Object_environment::GetObject(args, 0)->GetEnv().Reference() :
			new Environment(&env, ENVTYPE_block);
	return Processor::Run(pEnv, sig, pExpr);
}

// expr.parse(script:string) {block?}
Gura_DeclareClassMethod(expr, parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "script", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Parses a Gura script in the string `script` and creates an `expr` instance.\n"
		"\n"
		"If `block` is specified, it will be evaluated with block parameter\n"
		"in a format of `|expr:expr|` where `expr` is the created instance.");
}

Gura_ImplementClassMethod(expr, parse)
{
	AutoPtr<Expr_Block> pExpr(new Expr_Block());
	Parser parser(SRCNAME_string);
	if (!parser.ParseString(env, pExpr->GetExprOwner(),
								args.GetString(0), true)) return Value::Nil;
	return ReturnValue(env, args, Value(new Object_expr(env, pExpr.release())));
}

// expr#textize(style?:symbol, indent?:string)
Gura_DeclareMethod(expr, textize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "style", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "indent", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
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
	const Expr *pExpr = Object_expr::GetObjectThis(args)->GetExpr();
	Expr::ScriptStyle scriptStyle = Expr::SCRSTYLE_Fancy;
	if (args.Is_symbol(0)) {
		const Symbol *pSymbol = args.GetSymbol(0);
		scriptStyle = Expr::SymbolToScriptStyle(pSymbol);
		if (scriptStyle == Expr::SCRSTYLE_None) {
			sig.SetError(ERR_ValueError,
					"invalid symbol for script style: %s", pSymbol->GetName());
			return Value::Nil;
		}
	}
	const char *strIndent = args.Is_string(1)? args.GetString(1) : Expr::IndentDefault;
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
		Gura_Symbol(en), Help::FMT_markdown,
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
	Expr_Block *pExprBlock = Object_expr::GetObjectThis(args)->GetExpr()->ToExprBlock();
	AutoPtr<FunctionCustom> pFunc(FunctionCustom::CreateBlockFunc(env,
					Gura_Symbol(_anonymous_), pExprBlock, FUNCTYPE_Function));
	if (sig.IsSignalled()) return Value::Nil;
	const ValueList &valListArg = args.GetList(0);
	if (!valListArg.empty()) {
		if (!pFunc->GetDeclOwner().empty()) {
			sig.SetError(ERR_TypeError, "argument declaration conflicts");
			return Value::Nil;
		}
		ExprList exprListArg;
		exprListArg.reserve(args.GetList(0).size());
		foreach_const (ValueList, pValue, valListArg) {
			exprListArg.push_back(const_cast<Expr *>(pValue->GetExpr()));
		}
		CallerInfo callerInfo(exprListArg, nullptr, args.GetAttrsShared(), nullptr);
		if (!pFunc->CustomDeclare(env, callerInfo, SymbolSet::Empty)) return Value::Nil;
	}
	return Value(new Object_function(env, pFunc.release()));
}

// expr#unquote()
Gura_DeclareMethod(expr, unquote)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns `expr` instance that has removed quote operator from the original `expr`.");
}

Gura_ImplementMethod(expr, unquote)
{
	const Expr *pExpr = Object_expr::GetObjectThis(args)->GetExpr();
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
		Gura_Symbol(en), Help::FMT_markdown,
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
	const Expr *pExpr = Object_expr::GetObjectThis(args)->GetExpr();
	Expr::ScriptStyle scriptStyle = Expr::SCRSTYLE_Fancy;
	if (args.Is_symbol(1)) {
		const Symbol *pSymbol = args.GetSymbol(1);
		scriptStyle = Expr::SymbolToScriptStyle(pSymbol);
		if (scriptStyle == Expr::SCRSTYLE_None) {
			sig.SetError(ERR_ValueError,
					"invalid symbol for script style: %s", pSymbol->GetName());
			return Value::Nil;
		}
	}
	const char *strIndent = args.Is_string(2)? args.GetString(2) : Expr::IndentDefault;
	pExpr->GenerateScript(sig, args.GetStream(0), scriptStyle, 0, strIndent);
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
Class_expr::Class_expr(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_expr)
{
}

void Class_expr::Prepare(Environment &env)
{
	Gura_AssignFunction(expr);
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
}

bool Class_expr::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	if (value.Is_symbol()) {
		// cast symbol to expr
		const Symbol *pSymbol = value.GetSymbol();
		value = Value(new Object_expr(env, new Expr_Identifier(pSymbol)));
		return true;
	}
	env.LookupClass(VTYPE_stream)->CastFrom(env, value, pDecl);
	if (value.Is_stream()) {
		Stream &stream = value.GetStream();
		Parser parser(stream.GetName());
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
