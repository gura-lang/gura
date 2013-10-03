#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ExprType
//-----------------------------------------------------------------------------
const char *GetExprTypeName(ExprType exprType)
{
	static const struct {
		ExprType exprType;
		const char *name;
	} tbl[] = {
		{ EXPRTYPE_UnaryOp,		"unaryop",		},
		{ EXPRTYPE_Quote,		"quote",		},
		{ EXPRTYPE_Force,		"force",		},
		{ EXPRTYPE_Prefix,		"prefix",		},
		{ EXPRTYPE_Suffix,		"suffix",		},
		{ EXPRTYPE_BinaryOp,	"binaryop",		},
		{ EXPRTYPE_Assign,		"assign",		},
		{ EXPRTYPE_DictAssign,	"dictassign",	},
		{ EXPRTYPE_Member,		"member",		},
		{ EXPRTYPE_Root,		"root",			},
		{ EXPRTYPE_BlockParam,	"blockparam",	},
		{ EXPRTYPE_Block,		"block",		},
		{ EXPRTYPE_Lister,		"lister",		},
		{ EXPRTYPE_IterLink,	"iterlink",		},
		{ EXPRTYPE_TmplScript,	"tmplscript",	},
		{ EXPRTYPE_Indexer,		"indexer",		},
		{ EXPRTYPE_Caller,		"caller",		},
		{ EXPRTYPE_Value,		"value",		},
		{ EXPRTYPE_Symbol,		"symbol",		},
		{ EXPRTYPE_String,		"string",		},
		{ EXPRTYPE_TmplString,	"tmplstring",	},
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].exprType == exprType) return tbl[i].name;
	}
	return "unknown";
}

//-----------------------------------------------------------------------------
// Expr
// [class hierarchy under Expr]
// Expr <-+- Expr_Unary <-----+- Expr_UnaryOp
//        |                   +- Expr_Quote
//        |                   +- Expr_Force
//        |                   +- Expr_Prefix
//        |                   `- Expr_Suffix
//        +- Expr_Binary <----+- Expr_BinaryOp
//        |                   +- Expr_Assign
//        |                   +- Expr_DictAssign
//        |                   `- Expr_Member
//        +- Expr_Container <-+- Expr_Root
//        |                   +- Expr_BlockParam
//        |                   +- Expr_Block
//        |                   +- Expr_Lister
//        |                   +- Expr_IterLink
//        |                   `- Expr_TmplScript
//        +- Expr_Compound <--+- Expr_Indexer
//        |                   `- Expr_Caller
//        +- Expr_Value
//        +- Expr_Symbol
//        +- Expr_String
//        `- Expr_TmplString
//-----------------------------------------------------------------------------
Expr::~Expr()
{
}

const char *Expr::GetPathName() const
{
	return (_pExprParent == NULL)? NULL : _pExprParent->GetPathName();
}

bool Expr::ExecInArg(Environment &env, Signal sig,
					ValueList &valListArg, size_t &nElems, bool quoteFlag) const
{
	if (quoteFlag) {
		Object_expr *pObj = new Object_expr(env, Expr::Reference(this));
		valListArg.push_back(Value(pObj));
		nElems = 1;
	} else if (IsSuffix()) {
		const Expr_Suffix *pExprSuffix = dynamic_cast<const Expr_Suffix *>(this);
		if (!pExprSuffix->GetSymbol()->IsIdentical(Gura_Symbol(Char_Mul))) {
			SetError(sig, ERR_SyntaxError, "invalid argument");
			return false;
		}
		Value value = pExprSuffix->GetChild()->Exec(env, sig);
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return false;
		}
		if (value.IsList()) {
			const ValueList &valList = value.GetList();
			nElems = valList.size();
			foreach_const (ValueList, pValue, valList) {
				valListArg.push_back(*pValue);
			}
		} else {
			nElems = 1;
			valListArg.push_back(value);
		}
	} else {
		Value value = Exec(env, sig);
		if (sig.IsSignalled()) return false;
		valListArg.push_back(value);
		nElems = 1;
	}
	return true;
}

Value Expr::DoAssign(Environment &env, Signal sig, Value &value,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	SetError(sig, ERR_SyntaxError, "l-value is required");
	return Value::Null;
}

Expr *Expr::MathDiff(Environment &env, Signal sig, const Symbol *pSymbol) const
{
	SetError(sig, ERR_ValueError,
				"differential operation is not supported for this expression");
	return NULL;
}

Expr *Expr::MathOptimize(Environment &env, Signal sig) const
{
	SetError(sig, ERR_ValueError,
				"mathematical optimization is not supported for this expression");
	return NULL;
}

Function *Expr::ToFunction(Environment &env, Signal sig,
				const ValueList &valListArg, const SymbolSet &attrs) const
{
	Expr_Block *pExprBlock;
	if (IsBlock()) {
		pExprBlock = dynamic_cast<Expr_Block *>(Expr::Reference(this));
	} else {
		pExprBlock = new Expr_Block();
		pExprBlock->AddExpr(Expr::Reference(this));
	}
	Value result;
	AutoPtr<CustomFunction> pFunc(CustomFunction::CreateBlockFunc(env, sig,
					Gura_Symbol(_anonymous_), pExprBlock, FUNCTYPE_Function));
	if (sig.IsSignalled()) return NULL;
	if (!valListArg.empty()) {
		if (!pFunc->GetDeclOwner().empty()) {
			sig.SetError(ERR_TypeError, "argument declaration conflicts");
			return NULL;
		}
		ExprList exprListArg;
		foreach_const (ValueList, pValue, valListArg) {
			exprListArg.push_back(const_cast<Expr *>(pValue->GetExpr()));
		}
		Args args(exprListArg, Value::Null, NULL, false, NULL, attrs);
		if (!pFunc->CustomDeclare(env, sig, SymbolSet::Null, args)) {
			return NULL;
		}
	}
	return pFunc.release();
}

bool Expr::IsAtSameLine(const Expr *pExpr) const
{
	if (GetLineNoTop() != pExpr->GetLineNoTop()) return false;
	const char *pathName1 = GetPathName();
	const char *pathName2 = pExpr->GetPathName();
	if (pathName1 == NULL && pathName2 == NULL) return true;
	if (pathName1 == NULL || pathName2 == NULL) return false;
	return ::strcmp(pathName1, pathName2) == 0;
}

void Expr::GatherSymbol(SymbolSet &symbolSet) const
{
	ExprVisitor_GatherSymbol visitor(symbolSet);
	Accept(visitor);
}

void Expr::GatherSimpleLambdaArgs(ExprList &exprListArg) const
{
	ExprVisitor_GatherSimpleLambdaArgs visitor(exprListArg);
	Accept(visitor);
}

// this function makes a list of symbols chained by member operator "."
bool Expr::GetChainedSymbolList(SymbolList &symbolList) const
{
	for (const Expr *pExpr = this; ; ) {
		if (pExpr->IsMember()) {
			const Expr_Member *pExprMember = dynamic_cast<const Expr_Member *>(pExpr);
			if (pExprMember->GetRight()->IsSymbol()) {
				const Expr_Symbol *pExprSymbol =
						dynamic_cast<const Expr_Symbol *>(pExprMember->GetRight());
				symbolList.insert(symbolList.begin(), pExprSymbol->GetSymbol());
				pExpr = pExprMember->GetLeft();
			} else {
				return false;
			}
		} else if (pExpr->IsSymbol()) {
			const Expr_Symbol *pExprSymbol = dynamic_cast<const Expr_Symbol *>(pExpr);
			symbolList.insert(symbolList.begin(), pExprSymbol->GetSymbol());
			break;
		} else {
			return false;
		}
	}
	return true;
}

const Expr *Expr::Unquote() const
{
	return this;
}

bool Expr::NeedParenthesis(const Operator *pOperatorOuter,
									const Operator *pOperator, bool rightFlag)
{
	int rtn = Parser::CompareOpTypePrec(pOperatorOuter->GetOpType(), pOperator->GetOpType());
	if (rtn == 0) return rightFlag;
	return rtn > 0;
}

bool Expr::IsConstNumber(Number num) const
{
	if (!IsValue()) return false;
	const Value &value = dynamic_cast<const Expr_Value *>(this)->GetValue();
	return value.IsNumber() && value.GetNumber() == num;
}

bool Expr::IsConstEvenNumber() const
{
	if (!IsValue()) return false;
	const Value &value = dynamic_cast<const Expr_Value *>(this)->GetValue();
	return value.IsNumber() && ::fmod(value.GetNumber(), 2) == 0;
}

bool Expr::IsConstNegNumber() const
{
	if (!IsValue()) return false;
	const Value &value = dynamic_cast<const Expr_Value *>(this)->GetValue();
	return value.IsNumber() && value.GetNumber() < 0;
}

bool Expr::IsOperatorNeg() const
{
	return IsUnaryOp() &&
			dynamic_cast<const Expr_UnaryOp *>(this)->GetOperator()->GetOpType() == OPTYPE_Neg;
}

bool Expr::IsOperatorMul() const
{
	return IsBinaryOp() &&
		dynamic_cast<const Expr_BinaryOp *>(this)->GetOperator()->GetOpType() == OPTYPE_Mul;
}

bool Expr::IsOperatorPow() const
{
	return IsBinaryOp() &&
		dynamic_cast<const Expr_BinaryOp *>(this)->GetOperator()->GetOpType() == OPTYPE_Pow;
}

bool Expr::IsOperatorSeq() const
{
	return IsBinaryOp() &&
		dynamic_cast<const Expr_BinaryOp *>(this)->GetOperator()->GetOpType() == OPTYPE_Seq;
}

// type chekers - Unary and descendants
bool Expr::IsUnary() const		{ return false; }
bool Expr::IsUnaryOp() const	{ return false; }
bool Expr::IsQuote() const		{ return false; }
bool Expr::IsForce() const		{ return false; }
bool Expr::IsPrefix() const		{ return false; }
bool Expr::IsSuffix() const		{ return false; }
	// type chekers - Binary and descendants
bool Expr::IsBinary() const		{ return false; }
bool Expr::IsBinaryOp() const	{ return false; }
bool Expr::IsAssign() const		{ return false; }
bool Expr::IsDictAssign() const	{ return false; }
bool Expr::IsMember() const		{ return false; }
// type chekers - Container and descendants
bool Expr::IsContainer() const	{ return false; }
bool Expr::IsRoot() const		{ return false; }
bool Expr::IsBlockParam() const	{ return false; }
bool Expr::IsBlock() const		{ return false; }
bool Expr::IsLister() const		{ return false; }
bool Expr::IsIterLink() const	{ return false; }
bool Expr::IsTmplScript() const	{ return false; }
// type chekers - Compound and descendants
bool Expr::IsCompound() const	{ return false; }
bool Expr::IsIndexer() const	{ return false; }
bool Expr::IsCaller() const		{ return false; }
// type chekers - others
bool Expr::IsValue() const		{ return false; }
bool Expr::IsSymbol() const		{ return false; }
bool Expr::IsString() const		{ return false; }
bool Expr::IsTmplString() const	{ return false; }

bool Expr::IsParentOf(const Expr *pExpr) const
{
	return false;
}

void Expr::SetError(Signal sig, ErrorType errType, const char *format, ...) const
{
	va_list list;
	va_start(list, format);
	sig.SetErrorV(errType, format, list);
	sig.AddExprCause(this);
	va_end(list);
}

void Expr::SetError_NotAssignableSymbol(Signal sig, const Symbol *pSymbol) const
{
	SetError(sig, ERR_ValueError,
		"symbol '%s' cannot be assigned in this object", pSymbol->GetName());
}

Callable *Expr::LookupCallable(Environment &env, Signal sig) const
{
	return NULL;
}

bool Expr::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	return false;
}

bool Expr::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	return false;
}

String Expr::ToString(ScriptStyle scriptStyle) const
{
	Signal sig;
	String str;
	SimpleStream_StringWrite stream(str);
	GenerateScript(sig, stream, scriptStyle, 0);
	return str;
}

String Expr::MakePosText() const
{
	String str;
	const char *pathName = GetPathName();
	if (pathName == NULL) {
		str += "<console>";
	} else {
		String fileName;
		PathManager::SplitFileName(pathName, NULL, &fileName);
		str += fileName;
	}
	char buff[64];
	if (GetLineNoTop() == GetLineNoBtm()) {
		::sprintf(buff, ":%d", GetLineNoTop());
	} else {
		::sprintf(buff, ":%d:%d", GetLineNoTop(), GetLineNoBtm());
	}
	str += buff;
	return str;
}

bool Expr::PutNestIndent(Signal sig, SimpleStream &stream, int nestLevel)
{
	for (int i = 0; i < nestLevel; i++) {
		stream.Print(sig, "    ");
		if (sig.IsSignalled()) return false;
	}
	return true;
}

Expr::ScriptStyle Expr::SymbolToScriptStyle(const Symbol *pSymbol)
{
	if (pSymbol->IsIdentical(Gura_Symbol(crammed))) {
		return SCRSTYLE_Crammed;
	} else if (pSymbol->IsIdentical(Gura_Symbol(oneline))) {
		return SCRSTYLE_OneLine;
	} else if (pSymbol->IsIdentical(Gura_Symbol(fancy))) {
		return SCRSTYLE_Fancy;
	} else if (pSymbol->IsIdentical(Gura_Symbol(digest))) {
		return SCRSTYLE_Digest;
	} else {
		return SCRSTYLE_None;
	}
}

//-----------------------------------------------------------------------------
// Expr::ExprVisitor_GatherSymbol
//-----------------------------------------------------------------------------
bool Expr::ExprVisitor_GatherSymbol::Visit(const Expr *pExpr)
{
	if (pExpr->IsSymbol()) {
		const Expr_Symbol *pExprSym = dynamic_cast<const Expr_Symbol *>(pExpr);
		_symbolSet.insert(pExprSym->GetSymbol());
	}
	return true;
}

//-----------------------------------------------------------------------------
// Expr::ExprVisitor_GatherSimpleLambdaArgs
//-----------------------------------------------------------------------------
bool Expr::ExprVisitor_GatherSimpleLambdaArgs::Visit(const Expr *pExpr)
{
	if (pExpr->IsCaller()) {
		// avoid searching in a simple lambda inside
		const Expr *pExprCar =
					dynamic_cast<const Expr_Caller *>(pExpr)->GetCar();
		if (pExprCar->IsSymbol()) {
			const Symbol *pSymbol =
					dynamic_cast<const Expr_Symbol *>(pExprCar)->GetSymbol();
			if (pSymbol->IsIdentical(Gura_Symbol(Char_And))) return false;
		}
		
	} else if (pExpr->IsSymbol()) {
		const Symbol *pSymbol =
						dynamic_cast<const Expr_Symbol *>(pExpr)->GetSymbol();
		if (pSymbol->GetName()[0] == '$' &&
								_symbolSet.find(pSymbol) == _symbolSet.end()) {
			_exprListArg.push_back(const_cast<Expr *>(pExpr));
			_symbolSet.insert(pSymbol);
		}
	}
	return true;
}

//-----------------------------------------------------------------------------
// Expr::ExprVisitor_SearchBar
//-----------------------------------------------------------------------------
bool Expr::ExprVisitor_SearchBar::Visit(const Expr *pExpr)
{
	OpType opType = OPTYPE_None;
	if (pExpr->IsBinaryOp()) {
		const Operator *pOperator =
				dynamic_cast<const Expr_BinaryOp *>(pExpr)->GetOperator();
		opType = pOperator->GetOpType();
	} else if (pExpr->IsAssign()) {
		const Operator *pOperator =
				dynamic_cast<const Expr_Assign *>(pExpr)->GetOperatorToApply();
		if (pOperator != NULL) opType = pOperator->GetOpType();
	}
	if (opType == OPTYPE_Or || opType == OPTYPE_OrOr) {
		_foundFlag = true;
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// ExprList
//-----------------------------------------------------------------------------
const ExprList ExprList::Null;

void ExprList::ExtractTrace(ExprOwner &exprOwner) const
{
	foreach_const (ExprOwner, ppExpr, *this) {
		const Expr *pExpr = *ppExpr;
		if (pExpr->IsRoot() || pExpr->IsBlock()) continue;
		const Expr *pExprParent = pExpr->GetParent();
		if (pExprParent != NULL && !pExprParent->IsRoot() && !pExprParent->IsBlock()) continue;
		exprOwner.push_back(pExpr->Reference());
	}
}

Value ExprList::Exec2(Environment &env, Signal sig, bool evalSymFuncFlag) const
{
	Value result;
	foreach_const (ExprList, ppExpr, *this) {
		result = (*ppExpr)->Exec(env, sig);
		if (sig.IsSignalled()) {
			sig.AddExprCause(*ppExpr);
			break;
		}
		if (evalSymFuncFlag && result.IsFunction() &&
									result.GetFunction()->IsSymbolFunc()) {
			// symbol functions are only evaluated by a sequence of block.
			// in the folloiwng example, "return" shall be evaluated by a block
			// of "if" function.
			//   repeat { if (flag) { return } }
			// in the following example, "&&" operator returns "return" function
			// object as its result, and then the block of "repeat" shall evaluate it.
			//   repeat { flag && return }
			const Function *pFunc = result.GetFunction();
			Args args(ExprList::Null);
			Value result = pFunc->EvalExpr(env, sig, args);
			if (sig.IsSignalled()) {
				sig.AddExprCause(*ppExpr);
				return Value::Null;
			}
		}
	}
	return result;
}

Value ExprList::Exec2ForList(Environment &env, Signal sig, bool flattenFlag) const
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	foreach_const (ExprList, ppExpr, *this) {
		Value value = (*ppExpr)->Exec(env, sig);
		if (sig.IsSignalled()) {
			sig.AddExprCause(*ppExpr);
			return Value::Null;
		}
		if (flattenFlag && value.IsList()) {
			ValueVisitorEx visitor(valList);
			value.Accept(sig, visitor);
		} else {
			valList.push_back(value);
		}
	}
	return result;
}

void ExprList::Accept(ExprVisitor &visitor) const
{
	foreach_const (ExprList, ppExpr, *this) {
		(*ppExpr)->Accept(visitor);
	}
}

bool ExprList::IsContained(const Expr *pExpr) const
{
	return std::find(begin(), end(), const_cast<Expr *>(pExpr)) != end();
}

bool ExprList::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	foreach_const (ExprList, ppExpr, *this) {
		if (!(*ppExpr)->GenerateCode(env, sig, stream)) return false;
	}
	return true;
}

bool ExprList::GenerateScript(Signal sig, SimpleStream &stream,
			Expr::ScriptStyle scriptStyle, int nestLevel, Expr::Separator sep) const
{
	const char *sepText =
		(sep == Expr::SEP_Comma)? ((scriptStyle == Expr::SCRSTYLE_Crammed)? "," : ", ") :
		(sep == Expr::SEP_NewLine)? "\n" : ",";
	foreach_const (ExprList, ppExpr, *this) {
		const Expr *pExpr = *ppExpr;
		if (ppExpr != begin()) {
			stream.Print(sig, sepText);
			if (sig.IsSignalled()) return false;
		}
		if (sep == Expr::SEP_NewLine &&
					!Expr::PutNestIndent(sig, stream, nestLevel)) return false;
		if (!pExpr->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	}
	return true;
}

void ExprList::ValueVisitorEx::Visit(Signal sig, const Value &value)
{
	_valList.push_back(value);
}

void ExprList::SetParent(const Expr *pExpr)
{
	foreach_const (ExprList, ppExpr, *this) {
		(*ppExpr)->SetParent(pExpr);
	}
}

bool ExprList::IsAtSameLine() const
{
	if (empty()) return false;
	ExprList::const_iterator ppExpr = begin();
	const Expr *pExprTop = *ppExpr++;
	for ( ; ppExpr != end(); ppExpr++) {
		const Expr *pExpr = *ppExpr;
		if (pExprTop->GetLineNoTop() != pExpr->GetLineNoTop()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// ExprOwner
//-----------------------------------------------------------------------------
ExprOwner::ExprOwner() : _cntRef(1)
{
}

ExprOwner::ExprOwner(const ExprList &exprList) : _cntRef(1)
{
	foreach_const (ExprList, ppExpr, exprList) {
		push_back(Expr::Reference(*ppExpr));
	}
}

ExprOwner::ExprOwner(const ExprOwner &exprOwner) : _cntRef(1)
{
	foreach_const (ExprOwner, ppExpr, exprOwner) {
		push_back(Expr::Reference(*ppExpr));
	}
}

ExprOwner::~ExprOwner()
{
	Clear();
}

void ExprOwner::Clear()
{
	foreach (ExprOwner, ppExpr, *this) {
		Expr::Delete(*ppExpr);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Expr_Unary
//-----------------------------------------------------------------------------
bool Expr_Unary::IsUnary() const { return true; }

Expr_Unary::Expr_Unary(ExprType exprType, Expr *pExprChild) :
								Expr(exprType), _pExprChild(pExprChild)
{
	if (pExprChild != NULL) pExprChild->SetParent(this);
}

Expr_Unary::Expr_Unary(const Expr_Unary &expr) : Expr(expr)
{
	if (expr.GetChild() != NULL) {
		_pExprChild.reset(expr.GetChild()->Clone());
		_pExprChild->SetParent(this);
	}
}

Expr_Unary::~Expr_Unary()
{
	if (!_pExprChild.IsNull()) _pExprChild->SetParent(GetParent());
}

void Expr_Unary::Accept(ExprVisitor &visitor) const
{
	if (visitor.Visit(this) && !_pExprChild.IsNull()) {
		_pExprChild->Accept(visitor);
	}
}

bool Expr_Unary::IsParentOf(const Expr *pExpr) const
{
	return GetChild() == pExpr;
}

//-----------------------------------------------------------------------------
// Expr_Binary
//-----------------------------------------------------------------------------
bool Expr_Binary::IsBinary() const { return true; }

Expr_Binary::Expr_Binary(ExprType exprType, Expr *pExprLeft, Expr *pExprRight) :
				Expr(exprType), _pExprLeft(pExprLeft), _pExprRight(pExprRight)
{
	if (!_pExprLeft.IsNull()) _pExprLeft->SetParent(this);
	if (!_pExprRight.IsNull()) _pExprRight->SetParent(this);
}

Expr_Binary::Expr_Binary(const Expr_Binary &expr) : Expr(expr)
{
	if (expr.GetLeft() != NULL) {
		_pExprLeft.reset(expr.GetLeft()->Clone());
		_pExprLeft->SetParent(this);
	}
	if (expr.GetRight() != NULL) {
		_pExprRight.reset(expr.GetRight()->Clone());
		_pExprRight->SetParent(this);
	}
}

Expr_Binary::~Expr_Binary()
{
	if (!_pExprLeft.IsNull()) _pExprLeft->SetParent(GetParent());
	if (!_pExprRight.IsNull()) _pExprRight->SetParent(GetParent());
}

void Expr_Binary::Accept(ExprVisitor &visitor) const
{
	if (visitor.Visit(this)) {
		if (!_pExprLeft.IsNull()) _pExprLeft->Accept(visitor);
		if (!_pExprRight.IsNull()) _pExprRight->Accept(visitor);
	}
}

bool Expr_Binary::IsParentOf(const Expr *pExpr) const
{
	return GetLeft() == pExpr || GetRight() == pExpr;
}

//-----------------------------------------------------------------------------
// Expr_Container
//-----------------------------------------------------------------------------
bool Expr_Container::IsContainer() const { return true; }

Expr_Container::Expr_Container(ExprType exprType) : Expr(exprType), _pExprOwner(new ExprOwner())
{
}

Expr_Container::Expr_Container(const Expr_Container &expr) : Expr(expr), _pExprOwner(new ExprOwner())
{
	foreach_const (ExprOwner, ppExpr, expr.GetExprOwner()) {
		AddExpr((*ppExpr)->Clone());
	}
}

Expr_Container::~Expr_Container()
{
	GetExprOwner().SetParent(GetParent());
}

void Expr_Container::Accept(ExprVisitor &visitor) const
{
	if (visitor.Visit(this)) {
		GetExprOwner().Accept(visitor);
	}
}

bool Expr_Container::IsParentOf(const Expr *pExpr) const
{
	return GetExprOwner().IsContained(pExpr);
}

//-----------------------------------------------------------------------------
// Expr_Value
//-----------------------------------------------------------------------------
bool Expr_Value::IsValue() const { return true; }

Expr_Value::~Expr_Value()
{
}

Expr *Expr_Value::Clone() const
{
	return new Expr_Value(*this);
}

Value Expr_Value::DoExec(Environment &env, Signal sig) const
{
	if (_value.IsExpr()) {
		return _value.GetExpr()->Exec(env, sig);
	} else {
		return _value;
	}
}

Expr *Expr_Value::MathDiff(Environment &env, Signal sig, const Symbol *pSymbol) const
{
	return new Expr_Value(0);
}

Expr *Expr_Value::MathOptimize(Environment &env, Signal sig) const
{
	return Clone();
}

void Expr_Value::Accept(ExprVisitor &visitor) const
{
	visitor.Visit(this);
}

bool Expr_Value::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Value");
	return true;
}

bool Expr_Value::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	if (_value.IsBinary()) {
		char buff[32];
		const Binary &binary = _value.GetBinary();
		stream.Print(sig, "b'");
		if (sig.IsSignalled()) return false;
		foreach_const (Binary, p, binary) {
			unsigned char ch = static_cast<unsigned char>(*p);
			::sprintf(buff, "\\x%02x", ch);
			stream.Print(sig, buff);
			if (sig.IsSignalled()) return false;
		}
		stream.Print(sig, "'");
		if (sig.IsSignalled()) return false;
		return true;
	} else {
		String str;
		if (_pScript.get() == NULL) {
			str = _value.ToString(sig);
			if (sig.IsSignalled()) return false;
		} else {
			str = *_pScript;
		}
		if (_value.IsNumberOrComplex() && str[0] == '-') {
			str = "(" + str + ")";
		}
		stream.Print(sig, str.c_str());
		if (sig.IsSignalled()) return false;
		return true;
	}
}

//-----------------------------------------------------------------------------
// Expr_String
//-----------------------------------------------------------------------------
bool Expr_String::IsString() const { return true; }

Expr_String::~Expr_String()
{
}

Expr *Expr_String::Clone() const
{
	return new Expr_String(*this);
}

Value Expr_String::DoExec(Environment &env, Signal sig) const
{
	return Value(env, _str.c_str());
}

void Expr_String::Accept(ExprVisitor &visitor) const
{
	visitor.Visit(this);
}

bool Expr_String::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "String");
	return true;
}

bool Expr_String::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	stream.Print(sig, MakeQuotedString(_str.c_str()).c_str());
	if (sig.IsSignalled()) return false;
	return true;
}

//-----------------------------------------------------------------------------
// Expr_TmplString
//-----------------------------------------------------------------------------
bool Expr_TmplString::IsTmplString() const { return true; }

Expr_TmplString::~Expr_TmplString()
{
}

Expr *Expr_TmplString::Clone() const
{
	return new Expr_TmplString(*this);
}

Value Expr_TmplString::DoExec(Environment &env, Signal sig) const
{
	_streamDst.Print(sig, _str.c_str());
	return Value::Null;
}

void Expr_TmplString::Accept(ExprVisitor &visitor) const
{
	visitor.Visit(this);
}

bool Expr_TmplString::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "TmplString");
	return true;
}

bool Expr_TmplString::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	return false;
}

//-----------------------------------------------------------------------------
// Expr_Symbol
//-----------------------------------------------------------------------------
bool Expr_Symbol::IsSymbol() const { return true; }

Expr_Symbol::~Expr_Symbol()
{
}

Expr *Expr_Symbol::Clone() const
{
	return new Expr_Symbol(*this);
}

Callable *Expr_Symbol::LookupCallable(Environment &env, Signal sig) const
{
	Value rtn = env.GetProp(env, sig, GetSymbol(), GetAttrs());
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return NULL;
	}
	return rtn.GetObject();
}

Value Expr_Symbol::DoExec(Environment &env, Signal sig) const
{
	Value rtn = env.GetProp(env, sig, GetSymbol(), GetAttrs());
	if (sig.IsSignalled()) return Value::Null;
	return rtn;
}

Value Expr_Symbol::Exec(Environment &env, Signal sig, const Value &valueThis) const
{
	if (valueThis.IsPrimitive()) {
		bool evaluatedFlag = false;
		Class *pClass = valueThis.GetValueTypeInfo()->GetClass();
		Value rtn = pClass->GetPropPrimitive(env, sig,
						valueThis, GetSymbol(), GetAttrs(), evaluatedFlag);
		if (evaluatedFlag) return rtn;
	}
	EnvRefMode envRefMode =
			env.IsModule()? ENVREF_Module :
			!(env.IsClass() || env.IsObject())? ENVREF_Escalate :
			valueThis.IsPrivileged()? ENVREF_Escalate : ENVREF_Restricted;
	int cntSuperSkip = valueThis.GetSuperSkipCount();
	Value rtn = env.GetProp(env, sig, GetSymbol(), GetAttrs(),
										NULL, envRefMode, cntSuperSkip);
	if (sig.IsSignalled()) return Value::Null;
	return rtn;
}

Value Expr_Symbol::DoAssign(Environment &env, Signal sig, Value &value,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	bool evaluatedFlag = false;
	const SymbolSet &attrs = SymbolSet::Null;
	Value result = env.DoSetProp(env, sig, GetSymbol(), value, attrs, evaluatedFlag);
	if (sig.IsSignalled()) return Value::Null;
	if (evaluatedFlag) return result;
	if (pSymbolsAssignable != NULL && !pSymbolsAssignable->IsSet(GetSymbol())) {
		SetError_NotAssignableSymbol(sig, GetSymbol());
		return Value::Null;
	}
	if (_attrs.IsSet(Gura_Symbol(extern_))) {
		escalateFlag = true;
		if (env.LookupValue(GetSymbol(), ENVREF_Escalate) == NULL) {
			SetError(sig, ERR_ValueError, "undefined symbol '%s'",
												GetSymbol()->GetName());
			return Value::Null;
		}
	}
	if (_attrs.IsSet(Gura_Symbol(local))) {
		escalateFlag = false;
	}
	ValueType valTypeCast = VTYPE_any;
	if (!_attrFront.empty()) {
		const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(_attrFront);
		if (pValueTypeInfo != NULL) {
			valTypeCast = pValueTypeInfo->GetValueType();
		}
	}
	ULong extra = EXTRA_None;
	if (_attrs.IsSet(Gura_Symbol(public_))) {
		extra = EXTRA_Public;
	}
	if (value.IsModule()) {
		Module *pModule = value.GetModule();
		if (pModule->IsAnonymous()) {
			pModule->SetSymbol(GetSymbol());
		}
		extra = EXTRA_Public;
	} else if (value.IsClass() && value.GetClass()->IsCustom()) {
		CustomClass *pClass = dynamic_cast<CustomClass *>(value.GetClass());
		if (pClass->IsAnonymous()) {
			ValueTypeInfo *pValueTypeInfo =
							ValueTypePool::GetInstance()->Add(GetSymbol());
			pValueTypeInfo->SetClass(Class::Reference(pClass));
			env.AssignValueType(pValueTypeInfo);
			Function *pFunc = pClass->PrepareConstructor(env, sig);
			if (pFunc == NULL) return Value::Null;
			value = Value(env, pFunc, Value::Null);
		}
		extra = EXTRA_Public;
	} else if (value.IsFunction()) {
		Function *pFunc = value.GetFunction();
		if (pFunc->IsAnonymous()) {
			pFunc->SetSymbol(GetSymbol());
		}
		Class *pClassToConstruct = pFunc->GetClassToConstruct();
		if (pClassToConstruct != NULL && pClassToConstruct->IsAnonymous()) {
			ValueTypeInfo *pValueTypeInfo =
							ValueTypePool::GetInstance()->Add(GetSymbol());
			pValueTypeInfo->SetClass(pClassToConstruct);
			env.AssignValueType(pValueTypeInfo);
		}
		if (!pFunc->GetPrivateFlag()) extra = EXTRA_Public;
	}
	if (valTypeCast != VTYPE_any) {
		AutoPtr<Declaration> pDecl(
				new Declaration(GetSymbol(), valTypeCast, OCCUR_Once, 0, NULL));
		pDecl->ValidateAndCast(env, sig, value);
		if (sig.IsSignalled()) return Value::Null;
	}
	if (escalateFlag) {
		env.AssignValueFromBlock(GetSymbol(), value, extra);
	} else {
		env.AssignValue(GetSymbol(), value, extra);
	}
	return value;
}

void Expr_Symbol::Accept(ExprVisitor &visitor) const
{
	visitor.Visit(this);
}

Expr *Expr_Symbol::MathDiff(Environment &env, Signal sig, const Symbol *pSymbol) const
{
	Number num = GetSymbol()->IsIdentical(pSymbol)? 1 : 0;
	return new Expr_Value(num);
}

Expr *Expr_Symbol::MathOptimize(Environment &env, Signal sig) const
{
	return Clone();
}

bool Expr_Symbol::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Symbol");
	return true;
}

bool Expr_Symbol::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	if (!GenerateScriptHead(sig, stream, scriptStyle, nestLevel)) return false;
	if (!GenerateScriptTail(sig, stream, scriptStyle, nestLevel)) return false;
	return true;
}

bool Expr_Symbol::GenerateScriptHead(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	stream.Print(sig, GetSymbol()->GetName());
	if (sig.IsSignalled()) return false;
	return true;
}

bool Expr_Symbol::GenerateScriptTail(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	const Symbol *pSymbolFront = Gura_Symbol(Str_Empty);
	if (!_attrFront.empty()) {
		stream.PutChar(sig, ':');
		if (sig.IsSignalled()) return false;
		pSymbolFront = _attrFront.front();
		foreach_const (SymbolList, ppSymbol, _attrFront) {
			const Symbol *pSymbol = *ppSymbol;
			if (ppSymbol != _attrFront.begin()) {
				stream.PutChar(sig, '.');
				if (sig.IsSignalled()) return false;
			}
			stream.Print(sig, pSymbol->GetName());
			if (sig.IsSignalled()) return false;
		}
	}
	foreach_const (SymbolSet, ppSymbol, _attrs) {
		const Symbol *pSymbol = *ppSymbol;
		if (!pSymbol->IsIdentical(pSymbolFront)) {
			stream.PutChar(sig, ':');
			if (sig.IsSignalled()) return false;
			stream.Print(sig, pSymbol->GetName());
			if (sig.IsSignalled()) return false;
		}
	}
	if (!_attrsOpt.empty()) {
		stream.PutChar(sig, ':');
		if (sig.IsSignalled()) return false;
		stream.PutChar(sig, '[');
		if (sig.IsSignalled()) return false;
		foreach_const (SymbolSet, ppSymbol, _attrsOpt) {
			const Symbol *pSymbol = *ppSymbol;
			if (ppSymbol != _attrsOpt.begin()) {
				stream.PutChar(sig, ',');
				if (sig.IsSignalled()) return false;
			}
			stream.Print(sig, pSymbol->GetName());
			if (sig.IsSignalled()) return false;
		}
		stream.PutChar(sig, ']');
		if (sig.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Expr_Root
//-----------------------------------------------------------------------------
bool Expr_Root::IsRoot() const { return true; }

Expr_Root::~Expr_Root()
{
}

Expr *Expr_Root::Clone() const
{
	return new Expr_Root(*this);
}

const char *Expr_Root::GetPathName() const
{
	return _pathName.c_str();
}

Value Expr_Root::DoExec(Environment &env, Signal sig) const
{
	Value result;
	foreach_const (ExprList, ppExpr, GetExprOwner()) {
		result = (*ppExpr)->Exec(env, sig);
		if (sig.IsError()) {
			sig.AddExprCause(*ppExpr);
			result = Value::Null;
			break;
		} else if (sig.IsTerminate()) {
			env.GetConsoleErr()->PrintSignal(sig, sig);
			sig.ClearSignal();
			result = Value::Null;
			break;
		} else if (sig.IsSignalled()) {
			env.GetConsoleErr()->PrintSignal(sig, sig);
			sig.ClearSignal();
		} else if (!env.GetGlobal()->GetEchoFlag()) {
			// nothing to do
		} else if (result.IsValid()) {
			// pConsole must be retrieved here.
			env.GetConsole()->Println(sig, result.ToString(sig).c_str());
		}
	}
	return result;
}

bool Expr_Root::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	return GetExprOwner().GenerateCode(env, sig, stream);
}

bool Expr_Root::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	if (!GetExprOwner().GenerateScript(sig, stream, scriptStyle, nestLevel,
		(scriptStyle == SCRSTYLE_Fancy)? SEP_NewLine : SEP_Comma)) return false;
	if (scriptStyle == SCRSTYLE_Fancy) {
		stream.PutChar(sig, '\n');
		if (sig.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Expr_Block
//-----------------------------------------------------------------------------
bool Expr_Block::IsBlock() const { return true; }

Expr_Block::Expr_Block(const Expr_Block &expr) : Expr_Container(expr),
		_pExprBlockParam((expr._pExprBlockParam.IsNull())? NULL :
				dynamic_cast<Expr_BlockParam *>(expr._pExprBlockParam->Clone()))
{
	if (!_pExprBlockParam.IsNull()) _pExprBlockParam->SetParent(this);
}

Expr_Block::~Expr_Block()
{
	if (!_pExprBlockParam.IsNull()) {
		_pExprBlockParam->SetParent(GetParent());
	}
}

Expr *Expr_Block::Clone() const
{
	return new Expr_Block(*this);
}

Value Expr_Block::DoExec(Environment &env, Signal sig) const
{
	if (!_pExprBlockParam.IsNull()) {} // needs to do something here?
	if (env.IsType(ENVTYPE_lister)) {
		return GetExprOwner().Exec2ForList(env, sig, false);
	}
	return GetExprOwner().Exec2(env, sig, true);
}

Expr *Expr_Block::MathDiff(Environment &env, Signal sig, const Symbol *pSymbol) const
{
	return (GetExprOwner().size() == 1)?
			GetExprOwner().front()->MathDiff(env, sig, pSymbol) :
			Expr::MathDiff(env, sig, pSymbol);
}

void Expr_Block::Accept(ExprVisitor &visitor) const
{
	if (!_pExprBlockParam.IsNull()) _pExprBlockParam->Accept(visitor);
	Expr_Container::Accept(visitor);
}

bool Expr_Block::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Block");
	return true;
}

bool Expr_Block::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	stream.PutChar(sig, '{');
	if (sig.IsSignalled()) return false;
	if (!_pExprBlockParam.IsNull()) {
		if (!_pExprBlockParam->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	}
	if (GetExprOwner().empty()) {
		// nothing to do
	} else if (scriptStyle == SCRSTYLE_Digest && !GetExprOwner().IsAtSameLine()) {
		stream.Print(sig, " .. ");
		if (sig.IsSignalled()) return false;
	} else {
		const char *sepText =
			(scriptStyle == SCRSTYLE_Crammed)? "" :
			(scriptStyle == SCRSTYLE_OneLine)? " " :
			(scriptStyle == SCRSTYLE_Fancy)? "\n" : "";
		stream.Print(sig, sepText);
		if (sig.IsSignalled()) return false;
		if (!GetExprOwner().GenerateScript(sig, stream, scriptStyle, nestLevel + 1,
			(scriptStyle == SCRSTYLE_Fancy)? SEP_NewLine : SEP_Comma)) return false;
		stream.Print(sig, sepText);
		if (sig.IsSignalled()) return false;
		if (scriptStyle == SCRSTYLE_Fancy &&
					!PutNestIndent(sig, stream, nestLevel)) return false;
	}
	stream.PutChar(sig, '}');
	if (sig.IsSignalled()) return false;
	return true;
}

//-----------------------------------------------------------------------------
// Expr_BlockParam
//-----------------------------------------------------------------------------
bool Expr_BlockParam::IsBlockParam() const { return true; }

Expr_BlockParam::~Expr_BlockParam()
{
}

Expr *Expr_BlockParam::Clone() const
{
	return new Expr_BlockParam(*this);
}

Value Expr_BlockParam::DoExec(Environment &env, Signal sig) const
{
	return GetExprOwner().Exec2(env, sig, false);
}

bool Expr_BlockParam::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "BlockParam");
	return true;
}

bool Expr_BlockParam::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	stream.PutChar(sig, '|');
	if (sig.IsSignalled()) return false;
	const char *sepText = (scriptStyle == Expr::SCRSTYLE_Crammed)? "," : ", ";
	foreach_const (ExprList, ppExpr, GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		if (ppExpr != GetExprOwner().begin()) {
			stream.Print(sig, sepText);
			if (sig.IsSignalled()) return false;
		}
		ExprVisitor_SearchBar visitor;
		pExpr->Accept(visitor);
		if (visitor.GetFoundFlag()) {
			stream.PutChar(sig, '(');
			if (sig.IsSignalled()) return false;
			if (!pExpr->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
			stream.PutChar(sig, ')');
			if (sig.IsSignalled()) return false;
		} else {
			if (!pExpr->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
		}
	}
	stream.PutChar(sig, '|');
	if (sig.IsSignalled()) return false;
	return true;
}

//-----------------------------------------------------------------------------
// Expr_Lister
//-----------------------------------------------------------------------------
bool Expr_Lister::IsLister() const { return true; }

Expr_Lister::~Expr_Lister()
{
}

Expr *Expr_Lister::Clone() const
{
	return new Expr_Lister(*this);
}

Value Expr_Lister::DoExec(Environment &env, Signal sig) const
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	foreach_const (ExprOwner, ppExpr, GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		Value value = pExpr->Exec(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		if (value.IsIterator()) {
			AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
			if (sig.IsSignalled()) return Value::Null;
			if (pIterator->IsInfinite()) {
				Iterator::SetError_InfiniteNotAllowed(sig);
				return Value::Null;
			}
			Value value;
			while (pIterator->Next(env, sig, value)) {
				valList.push_back(value);
			}
			if (sig.IsSignalled()) return Value::Null;
		} else {
			valList.push_back(value);
		}
	}
	return result;
}

Value Expr_Lister::DoAssign(Environment &env, Signal sig, Value &value,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	const ExprList &exprList = GetExprOwner();
	if (value.IsList() || value.IsIterator()) {
		ValueList *pValList = NULL;
		ExprList::const_iterator ppExpr = exprList.begin();
		AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
		if (pIterator.IsNull()) return Value::Null;
		Value valueElem;
		while (pIterator->Next(env, sig, valueElem)) {
			if (pValList != NULL) {
				pValList->push_back(valueElem);
				continue;
			}
			if (ppExpr == exprList.end()) break;
			const Expr *pExpr = *ppExpr;
			OccurPattern occurPattern = OCCUR_Once;
			if (pExpr->IsSuffix()) {
				const Expr_Suffix *pExprSuffix =
								dynamic_cast<const Expr_Suffix *>(pExpr);
				pExpr = pExprSuffix->GetChild();
				occurPattern = pExprSuffix->GetOccurPattern();
				if (occurPattern == OCCUR_Invalid) {
					SetError(sig, ERR_SyntaxError,
								"invalid expression of array assignment");
					return Value::Null;
				}
			}
			if (occurPattern == OCCUR_ZeroOrMore || occurPattern == OCCUR_OnceOrMore) {
				Value value;
				pValList = &value.InitAsList(env);
				pExpr->Assign(env, sig, value, pSymbolsAssignable, escalateFlag);
				if (sig.IsSignalled()) return Value::Null;
				pValList->push_back(valueElem);
			} else {
				pExpr->Assign(env, sig, valueElem, pSymbolsAssignable, escalateFlag);
				if (sig.IsSignalled()) return Value::Null;
			}
			ppExpr++;
		}
		for ( ; ppExpr != exprList.end(); ppExpr++) {
			const Expr *pExpr = *ppExpr;
			OccurPattern occurPattern = OCCUR_Once;
			if (pExpr->IsSuffix()) {
				const Expr_Suffix *pExprSuffix =
								dynamic_cast<const Expr_Suffix *>(pExpr);
				pExpr = pExprSuffix->GetChild();
				occurPattern = pExprSuffix->GetOccurPattern();
			}
			if (occurPattern == OCCUR_ZeroOrMore) {
				Value value;
				pValList = &value.InitAsList(env);
				pExpr->Assign(env, sig, value, pSymbolsAssignable, escalateFlag);
				if (sig.IsSignalled()) return Value::Null;
			} else if (occurPattern == OCCUR_Once || occurPattern == OCCUR_OnceOrMore) {
				SetError(sig, ERR_ValueError,
						"not enough value to initialize arrayed variables");
				return Value::Null;
			}
		}
	} else {
		foreach_const (ExprList, ppExpr, exprList) {
			const Expr *pExpr = *ppExpr;
			pExpr->Assign(env, sig, value, pSymbolsAssignable, escalateFlag);
			if (sig.IsSignalled()) return Value::Null;
		}
	}
	return value;
}

bool Expr_Lister::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Lister");
	return true;
}

bool Expr_Lister::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	stream.PutChar(sig, '[');
	if (sig.IsSignalled()) return false;
	if (GetExprOwner().empty()) {
		// nothing to do
	} else if (scriptStyle == SCRSTYLE_Digest && !GetExprOwner().IsAtSameLine()) {
		stream.Print(sig, " .. ");
		if (sig.IsSignalled()) return false;
	} else {
		if (!GetExprOwner().GenerateScript(sig, stream,
							scriptStyle, nestLevel, SEP_Comma)) return false;
	}
	stream.PutChar(sig, ']');
	if (sig.IsSignalled()) return false;
	return true;
}

//-----------------------------------------------------------------------------
// Expr_IterLink
//-----------------------------------------------------------------------------
bool Expr_IterLink::IsIterLink() const { return true; }

Expr_IterLink::~Expr_IterLink()
{
}

Expr *Expr_IterLink::Clone() const
{
	return new Expr_IterLink(*this);
}

Value Expr_IterLink::DoExec(Environment &env, Signal sig) const
{
	AutoPtr<Iterator_Concat> pIterator(new Iterator_Concat());
	foreach_const (ExprOwner, ppExpr, GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		Value value = pExpr->Exec(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		Iterator *pIteratorArg = NULL;
		if (value.IsIterator()) {
			pIteratorArg = value.CreateIterator(sig);
			if (sig.IsSignalled()) return Value::Null;
		} else {
			pIteratorArg = new Iterator_OneShot(value);
		}
		pIterator->Add(pIteratorArg);
	}
	return Value(env, pIterator.release());
}

bool Expr_IterLink::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "IterLink");
	return true;
}

bool Expr_IterLink::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	stream.PutChar(sig, '(');
	if (sig.IsSignalled()) return false;
	if (GetExprOwner().empty()) {
		// nothing to do
	} else if (scriptStyle == SCRSTYLE_Digest && !GetExprOwner().IsAtSameLine()) {
		stream.Print(sig, " .. ");
		if (sig.IsSignalled()) return false;
	} else {
		if (!GetExprOwner().GenerateScript(sig, stream,
						scriptStyle, nestLevel, SEP_Comma)) return false;
		if (GetExprOwner().size() == 1) {
			stream.PutChar(sig, ',');
			if (sig.IsSignalled()) return false;
		}
	}
	stream.PutChar(sig, ')');
	if (sig.IsSignalled()) return false;
	return true;
}

//-----------------------------------------------------------------------------
// Expr_TmplScript
//-----------------------------------------------------------------------------
bool Expr_TmplScript::IsTmplScript() const { return true; }

Expr_TmplScript::~Expr_TmplScript()
{
}

Expr *Expr_TmplScript::Clone() const
{
	return new Expr_TmplScript(*this);
}

Value Expr_TmplScript::DoExec(Environment &env, Signal sig) const
{
	if (GetExprOwner().empty()) return Value::Null;
	Value value = GetExprOwner().Exec2(env, sig, true);
	if (sig.IsSignalled()) {
		return Value::Null;
	} else if (value.IsInvalid()) {
		return Value::Null;
	}
	_streamDst.Print(sig, _strIndent.c_str());
	String str;
	if (value.IsString()) {
		str = value.GetStringSTL();
	} else if (value.IsList() || value.IsIterator()) {
		AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
		if (sig.IsSignalled()) return false;
		Value valueElem;
		while (pIterator->Next(env, sig, valueElem)) {
			foreach_const (String, p, str) {
				char ch = *p;
				if (ch == '\n') {
					_streamDst.PutChar(sig, ch);
					if (_autoIndentFlag && valueElem.IsValid()) {
						_streamDst.Print(sig, _strIndent.c_str());
					}
				} else {
					_streamDst.PutChar(sig, ch);
				}
			}
			if (valueElem.IsString()) {
				str = valueElem.GetStringSTL();
			} else if (valueElem.IsValid()) {
				str = valueElem.ToString(sig);
				if (sig.IsSignalled()) return false;
			} else {
				str.clear();
			}
		}
	} else {
		str = value.ToString(sig);
		if (sig.IsSignalled()) return false;
	}
	foreach_const (String, p, str) {
		char ch = *p;
		if (ch != '\n') {
			_streamDst.PutChar(sig, ch);
		} else if (p + 1 != str.end()) {
			_streamDst.PutChar(sig, ch);
			if (_autoIndentFlag) {
				_streamDst.Print(sig, _strIndent.c_str());
			}
		} else if (_appendLastEOLFlag) {
			_streamDst.PutChar(sig, ch);
		}
	}
	_streamDst.Print(sig, _strPost.c_str());
	return Value::Null;
}

bool Expr_TmplScript::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "TmplScript");
	return true;
}

bool Expr_TmplScript::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	return false;
}

//-----------------------------------------------------------------------------
// Expr_Compound
//-----------------------------------------------------------------------------
bool Expr_Compound::IsCompound() const { return true; }

Expr_Compound::Expr_Compound(ExprType exprType, Expr *pExprCar, Expr_Lister *pExprLister) :
			Expr(exprType), _pExprCar(pExprCar), _pExprLister(pExprLister)
{
	if (!_pExprCar.IsNull()) _pExprCar->SetParent(this);
	if (!_pExprLister.IsNull()) _pExprLister->SetParent(this);
}

Expr_Compound::Expr_Compound(const Expr_Compound &expr) : Expr(expr),
			_pExprCar(expr._pExprCar->Clone()),
			_pExprLister(dynamic_cast<Expr_Lister *>(expr._pExprLister->Clone()))
{
	if (!_pExprCar.IsNull()) _pExprCar->SetParent(this);
	if (!_pExprLister.IsNull()) _pExprLister->SetParent(this);
}

Expr_Compound::~Expr_Compound()
{
	if (!_pExprCar.IsNull()) _pExprCar->SetParent(GetParent());
	if (!_pExprLister.IsNull()) _pExprLister->SetParent(GetParent());
}

bool Expr_Compound::IsParentOf(const Expr *pExpr) const
{
	return _pExprCar.get() == pExpr || _pExprLister.get() == pExpr ||
			(!_pExprCar.IsNull() && _pExprCar->IsParentOf(pExpr)) ||
			(!_pExprLister.IsNull() && _pExprLister->IsParentOf(pExpr));
}

//-----------------------------------------------------------------------------
// Expr_Indexer
//-----------------------------------------------------------------------------
bool Expr_Indexer::IsIndexer() const { return true; }

Expr_Indexer::~Expr_Indexer()
{
}

Expr *Expr_Indexer::Clone() const
{
	return new Expr_Indexer(*this);
}

Value Expr_Indexer::DoExec(Environment &env, Signal sig) const
{
	Value valueCar = GetCar()->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	const ExprList &exprList = GetLister()->GetExprOwner();
	Object &objCar = *valueCar.GetObject();
	if (exprList.empty()) {
		return objCar.EmptyIndexGet(env, sig);
	}
	Value valueIdx = exprList.Exec2ForList(env, sig, true);
	if (sig.IsSignalled()) return Value::Null;
	ValueList &valIdxList = valueIdx.GetList();
	if (valIdxList.size() == 0) return Value::Null;
	if (!valueCar.IsObject()) {
		SetError(sig, ERR_ValueError, "object should be specified as l-value of indexer");
		return Value::Null;
	}
	Value result;
	if (valIdxList.size() == 1 && !valIdxList.front().IsListOrIterator()) {
		// obj[idx]
		result = objCar.IndexGet(env, sig, valIdxList.front());
	} else {
		// obj[idx, idx, ..]
		ValueList &valListDst = result.InitAsList(env);
		foreach_const (ValueList, pValueIdx, valIdxList) {
			if (pValueIdx->IsList() || pValueIdx->IsIterator()) {
				AutoPtr<Iterator> pIteratorIdx(pValueIdx->CreateIterator(sig));
				if (sig.IsSignalled()) break;
				//if (pIteratorIdx->IsInfinite() && !pIteratorIdx->IsSequenceInf()) {
				//	Iterator::SetError_InfiniteNotAllowed(sig);
				//	return Value::Null;
				//}
				Value valueIdxEach;
				while (pIteratorIdx->Next(env, sig, valueIdxEach)) {
					Value value = objCar.IndexGet(env, sig, valueIdxEach);
					if (sig.IsSignalled()) {
						if (sig.GetError().GetType() == ERR_IndexError &&
												pIteratorIdx->IsInfinite()) {
							sig.ClearSignal();
						}
						break;
					}
					valListDst.push_back(value);
				}
			} else {
				Value value = objCar.IndexGet(env, sig, *pValueIdx);
				if (sig.IsSignalled()) break;
				valListDst.push_back(value);
			}
		}
	}
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

Value Expr_Indexer::DoAssign(Environment &env, Signal sig, Value &value,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	Value valueDst = GetCar()->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	if (!valueDst.IsObject()) {
		SetError(sig, ERR_ValueError, "object is expected as l-value of indexer");
		return Value::Null;
	}
	const ExprList &exprList = GetLister()->GetExprOwner();
	Object &objDst = *valueDst.GetObject();
	if (exprList.empty()) {
		objDst.EmptyIndexSet(env, sig, value);
		if (sig.IsSignalled()) return Value::Null;
		return value;
	}
	if (exprList.size() == 1) {
		// obj[idx] = v / obj[idx] = [v, v, ..]
		Value valueIdx = exprList.front()->Exec(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		if (valueIdx.IsList() || valueIdx.IsIterator()) {
			Iterator *pIteratorIdx = valueIdx.CreateIterator(sig);
			if (sig.IsSignalled()) return Value::Null;
			if (value.IsList() || value.IsIterator()) {
				Iterator *pIterator = value.CreateIterator(sig);
				if (sig.IsSignalled()) return Value::Null;
				Value valueIdxEach, valueEach;
				while (pIteratorIdx->Next(env, sig, valueIdxEach) &&
											pIterator->Next(env, sig, valueEach)) {
					objDst.IndexSet(env, sig, valueIdxEach, valueEach);
					if (sig.IsSignalled()) break;
				}
			} else {
				Value valueIdxEach;
				while (pIteratorIdx->Next(env, sig, valueIdxEach)) {
					objDst.IndexSet(env, sig, valueIdxEach, value);
				}
			}
		} else {
			objDst.IndexSet(env, sig, valueIdx, value);
		}
	} else if (value.IsList() || value.IsIterator()) {
		// obj[idx, idx, ..] = [v, v, ..]
		AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
		if (sig.IsSignalled()) return Value::Null;
		foreach_const (ExprList, ppExprCdr, exprList) {
			Value valueIdx = (*ppExprCdr)->Exec(env, sig);
			if (sig.IsSignalled()) break;
			if (valueIdx.IsList() || valueIdx.IsIterator()) {
				AutoPtr<Iterator> pIteratorIdx(valueIdx.CreateIterator(sig));
				if (sig.IsSignalled()) break;
				Value valueIdxEach, valueEach;
				while (pIteratorIdx->Next(env, sig, valueIdxEach) &&
											pIterator->Next(env, sig, valueEach)) {
					objDst.IndexSet(env, sig, valueIdxEach, valueEach);
					if (sig.IsSignalled()) break;
				}
			} else {
				Value valueEach;
				if (!pIterator->Next(env, sig, valueEach)) break;
				objDst.IndexSet(env, sig, valueIdx, valueEach);
				if (sig.IsSignalled()) break;
			}
		}
	} else {
		// obj[idx, idx, ..] = v
		foreach_const (ExprList, ppExprCdr, exprList) {
			Value valueIdx = (*ppExprCdr)->Exec(env, sig);
			if (sig.IsSignalled()) return Value::Null;
			if (valueIdx.IsList() || valueIdx.IsIterator()) {
				AutoPtr<Iterator> pIteratorIdx(valueIdx.CreateIterator(sig));
				if (sig.IsSignalled()) break;
				Value valueIdxEach;
				while (pIteratorIdx->Next(env, sig, valueIdxEach)) {
					objDst.IndexSet(env, sig, valueIdxEach, value);
					if (sig.IsSignalled()) break;
				}
				if (sig.IsSignalled()) break;
			} else {
				objDst.IndexSet(env, sig, valueIdx, value);
				if (sig.IsSignalled()) break;
			}
		}
	}
	return value;
}

void Expr_Indexer::Accept(ExprVisitor &visitor) const
{
	if (visitor.Visit(this)) {
		GetCar()->Accept(visitor);
		GetLister()->Accept(visitor);
	}
}

bool Expr_Indexer::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Indexer");
	return true;
}

bool Expr_Indexer::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	if (GetCar()->IsSymbol()) {
		const Expr_Symbol *pExprSymbol = dynamic_cast<const Expr_Symbol *>(GetCar());
		if (!pExprSymbol->GenerateScriptHead(sig, stream, scriptStyle, nestLevel)) return false;
		stream.PutChar(sig, '[');
		if (sig.IsSignalled()) return false;
		if (GetExprOwner().empty()) {
			// nothing to do
		} else if (scriptStyle == SCRSTYLE_Digest && !GetExprOwner().IsAtSameLine()) {
			stream.Print(sig, " .. ");
			if (sig.IsSignalled()) return false;
		} else {
			if (!GetLister()->GetExprOwner().GenerateScript(sig, stream,
								scriptStyle, nestLevel, SEP_Comma)) return false;
		}
		stream.PutChar(sig, ']');
		if (sig.IsSignalled()) return false;
		if (!pExprSymbol->GenerateScriptTail(sig, stream, scriptStyle, nestLevel)) return false;
		return true;
	} else {
		if (!GetCar()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
		stream.PutChar(sig, '[');
		if (sig.IsSignalled()) return false;
		if (GetExprOwner().empty()) {
			// nothing to do
		} else if (scriptStyle == SCRSTYLE_Digest && !GetExprOwner().IsAtSameLine()) {
			stream.Print(sig, " .. ");
			if (sig.IsSignalled()) return false;
		} else {
			if (!GetLister()->GetExprOwner().GenerateScript(sig, stream,
								scriptStyle, nestLevel, SEP_Comma)) return false;
		}
		stream.PutChar(sig, ']');
		if (sig.IsSignalled()) return false;
		return true;
	}
}

//-----------------------------------------------------------------------------
// Expr_Caller
//-----------------------------------------------------------------------------
bool Expr_Caller::IsCaller() const { return true; }

Expr_Caller::Expr_Caller(Expr *pExprCar, Expr_Lister *pExprLister, Expr_Block *pExprBlock) :
		Expr_Compound(EXPRTYPE_Caller,
				pExprCar, (pExprLister == NULL)? new Expr_Lister() : pExprLister),
		_pExprBlock(pExprBlock), _pExprTrailer(NULL)
{
	if (!_pExprBlock.IsNull()) _pExprBlock->SetParent(this);
}

Expr_Caller::Expr_Caller(const Expr_Caller &expr) : Expr_Compound(expr),
		_pExprBlock(expr._pExprBlock.IsNull()? NULL :
					dynamic_cast<Expr_Block *>(expr._pExprBlock->Clone())),
		_pExprTrailer(expr._pExprTrailer.IsNull()? NULL :
					dynamic_cast<Expr_Caller *>(expr._pExprTrailer->Clone())),
		_attrs(expr._attrs), _attrsOpt(expr._attrsOpt)
{
	if (!_pExprBlock.IsNull()) _pExprBlock->SetParent(this);
}

Expr_Caller::~Expr_Caller()
{
	if (!_pExprBlock.IsNull()) _pExprBlock->SetParent(GetParent());
	if (!_pExprTrailer.IsNull()) _pExprTrailer->SetParent(GetParent());
}

Expr *Expr_Caller::Clone() const
{
	return new Expr_Caller(*this);
}

Callable *Expr_Caller::LookupCallable(Environment &env, Signal sig) const
{
	if (!_pExprCar->IsMember()) {
		Value valueCar = _pExprCar->Exec(env, sig);
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return NULL;
		}
		return valueCar.GetObject();
	}
	return NULL;
}

Value Expr_Caller::DoExec(Environment &env, Signal sig) const
{
	Value result;
	TrailCtrl trailCtrl = TRAILCTRL_Continue;
	for (const Expr_Caller *pExprCaller = this; pExprCaller != NULL;
									pExprCaller = pExprCaller->GetTrailer()) {
		result = pExprCaller->DoExec(env, sig, &trailCtrl);
		if (trailCtrl == TRAILCTRL_Quit) break;
	}
	// if there's an error suspended by try() function, it would be resumed below.
	// otherwise, nothing would happen and any error would be kept intact.
	sig.ResumeError();
	return result;
}

Value Expr_Caller::DoExec(Environment &env, Signal sig, TrailCtrl *pTrailCtrl) const
{
	// Expr_Caller::Exec(), Expr_Member::Exec() and Expr_Member::DoAssign()
	// correspond to method-calling, property-getting and property-setting.
	if (!_pExprCar->IsMember()) {
		Value valueCar = _pExprCar->Exec(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		Callable *pCallable = valueCar.GetObject();
		if (pCallable == NULL) {
			SetError(sig, ERR_TypeError, "object is not callable");
			return Value::Null;
		}
		return pCallable->Call(env, sig, Value::Null, NULL, false,
									this, GetExprOwner(), pTrailCtrl);
	}
	const Expr_Member *pExprMember = dynamic_cast<const Expr_Member *>(GetCar());
	Value valueThis = pExprMember->GetLeft()->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	Expr_Member::Mode mode = pExprMember->GetMode();
	if (mode != Expr_Member::MODE_Normal) {
		if (valueThis.IsList() && valueThis.GetList().empty()) {
			return valueThis;
		}
		Fundamental *pFund = valueThis.ExtractFundamental(sig);
		if (sig.IsSignalled()) return Value::Null;
		Iterator *pIteratorThis = pFund->CreateIterator(sig);
		if (sig.IsSignalled()) return Value::Null;
		if (pIteratorThis == NULL) {
			// nothing to do
		} else if (mode == Expr_Member::MODE_MapAlong) {
			Value valueThisEach;
			if (!pIteratorThis->Next(env, sig, valueThisEach)) return Value::Null;
			return EvalEach(env, sig, valueThisEach,
							pIteratorThis, valueThis.IsList(), pTrailCtrl);
		} else {
			AutoPtr<Iterator> pIteratorMap(new Iterator_MethodMap(new Environment(env), sig,
								pIteratorThis, Expr_Caller::Reference(this)));
			if (mode == Expr_Member::MODE_MapToIter) {
				return Value(env, pIteratorMap.release());
			}
			Value result = pIteratorMap->ToList(env, sig, false, false);
			if (sig.IsSignalled()) return Value::Null;
			return result;
		}
	}
	return EvalEach(env, sig, valueThis, NULL, false, pTrailCtrl);
}

Value Expr_Caller::EvalEach(Environment &env, Signal sig, const Value &valueThis,
		Iterator *pIteratorThis, bool listThisFlag, TrailCtrl *pTrailCtrl) const
{
	const Expr_Member *pExprMember = dynamic_cast<const Expr_Member *>(GetCar());
	const Expr *pExprRight = pExprMember->GetRight();
	Value valueCar;
	Callable *pCallable = NULL;
	Fundamental *pFund = NULL;
	if (valueThis.IsPrimitive() || valueThis.GetTinyBuffFlag()) {
		pFund = env.LookupClass(valueThis.GetValueType());
	} else {
		pFund = valueThis.ExtractFundamental(sig);
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
	}
	if (pExprRight->IsSymbol()) {
		pCallable = pFund->GetCallable(sig,
					dynamic_cast<const Expr_Symbol *>(pExprRight)->GetSymbol());
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
	}
	if (pCallable == NULL) {
		if (pExprRight->IsSymbol()) {
			const Expr_Symbol *pExprSymbol =
								dynamic_cast<const Expr_Symbol *>(pExprRight);
			valueCar = pExprSymbol->Exec(*pFund, sig, valueThis);
		} else {
			valueCar = pExprRight->Exec(*pFund, sig);
		}
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
		pCallable = valueCar.GetObject();
	}
	if (pCallable == NULL) {
		SetError(sig, ERR_TypeError, "object is not callable");
		return Value::Null;
	}
	return pCallable->Call(env, sig, valueThis, pIteratorThis, listThisFlag,
										this, GetExprOwner(), pTrailCtrl);
}

Value Expr_Caller::DoAssign(Environment &env, Signal sig, Value &value,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	if (!value.IsExpr()) {
		SetError(sig, ERR_SyntaxError, "invalid function expression");
		return Value::Null;
	}
	Expr *pExprBody = Expr::Reference(value.GetExpr());
	// get symbol part of function's declaration
	const Symbol *pSymbol;
	if (GetCar()->IsMember()) {
		const Expr_Member *pExprMember =
						dynamic_cast<const Expr_Member *>(GetCar());
		if (pExprMember->GetRight()->IsSymbol()) {
			const Expr_Symbol *pExprSym =
						dynamic_cast<const Expr_Symbol *>(pExprMember->GetRight());
			pSymbol = pExprSym->GetSymbol();
		}
	} else if (GetCar()->IsSymbol()) {
		const Expr_Symbol *pExprSym =
						dynamic_cast<const Expr_Symbol *>(GetCar());
		pSymbol = pExprSym->GetSymbol();
	} else {
		SetError(sig, ERR_SyntaxError, "invalid function expression");
		return Value::Null;
	}
	if (pSymbolsAssignable != NULL && !pSymbolsAssignable->IsSet(pSymbol)) {
		SetError_NotAssignableSymbol(sig, pSymbol);
		return Value::Null;
	}
	FunctionType funcType = !env.IsClass()? FUNCTYPE_Function :
		GetAttrs().IsSet(Gura_Symbol(static_))? FUNCTYPE_Class : FUNCTYPE_Instance;
	CustomFunction *pFunc = new CustomFunction(env, pSymbol, pExprBody, funcType);
	Args args(GetExprOwner(), Value::Null, NULL, false,
								NULL, GetAttrs(), GetAttrsOpt(), GetBlock());
	if (!pFunc->CustomDeclare(env, sig, SymbolSet::Null, args)) {
		Function::Delete(pFunc);
		return Value::Null;
	}
	Value valueFunc(env, pFunc, Value::Null);
	GetCar()->Assign(env, sig, valueFunc, pSymbolsAssignable, escalateFlag);
	if (sig.IsSignalled()) return Value::Null;
	return valueFunc;
}

void Expr_Caller::Accept(ExprVisitor &visitor) const
{
	if (visitor.Visit(this)) {
		GetCar()->Accept(visitor);
		GetExprOwner().Accept(visitor);
	}
}

bool Expr_Caller::IsParentOf(const Expr *pExpr) const
{
	if (Expr_Compound::IsParentOf(pExpr)) return true;
	if (_pExprBlock.get() == pExpr || _pExprTrailer.get() == pExpr) return true;
	if (!_pExprBlock.IsNull() && _pExprBlock->IsParentOf(pExpr)) return true;
	if (!_pExprTrailer.IsNull() && _pExprTrailer->IsParentOf(pExpr)) return true;
	return false;
}

Expr *Expr_Caller::MathDiff(Environment &env, Signal sig, const Symbol *pSymbol) const
{
	// f(g(x))' = f(u)'g(x)'
	if (GetExprOwner().size() != 1) return NULL;
	const Expr *pExprArg = GetExprOwner().front();
	Value value = GetCar()->Exec(env, sig);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return NULL;
	}
	if (!value.IsFunction()) {
		SetError(sig, ERR_ValueError, "object must be a function");
		return NULL;
	}
	Expr *pExprArgDiff = pExprArg->MathDiff(env, sig, pSymbol);
	if (pExprArgDiff == NULL) return NULL;
	if (pExprArgDiff->IsConstNumber(0)) {
		return pExprArgDiff;
	}
	Expr *pExprFuncDiff = value.GetFunction()->DiffUnary(env, sig, pExprArg, pSymbol);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return NULL;
	}
	if (pExprArgDiff->IsConstNumber(1)) {
		Expr::Delete(pExprArgDiff);
		return pExprFuncDiff;
	}
	return Operator_Mul::OptimizeExpr(env, sig, pExprFuncDiff, pExprArgDiff);
}

Expr *Expr_Caller::MathOptimize(Environment &env, Signal sig) const
{
	return Clone();
}

bool Expr_Caller::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Caller");
	if (!_pExprCar->GenerateCode(env, sig, stream)) return false;
	if (!GetExprOwner().GenerateCode(env, sig, stream)) return false;
	if (!_pExprBlock.IsNull() && _pExprBlock->GenerateCode(env, sig, stream)) return false;
	if (!_pExprTrailer.IsNull() && _pExprTrailer->GenerateCode(env, sig, stream)) return false;
	return true;
}

bool Expr_Caller::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	bool argListFlag = !GetExprOwner().empty() ||
									!_attrs.empty() || _pExprBlock.IsNull();
	if (_pExprCar->IsSymbol()) {
		const Symbol *pSymbol = dynamic_cast<const Expr_Symbol *>(GetCar())->GetSymbol();
		if (!_pExprCar->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
		if (pSymbol->IsFlowControlSymbol() && argListFlag) {
			stream.PutChar(sig, ' ');
			if (sig.IsSignalled()) return false;
		}
	} else if (_pExprCar->IsCaller()) {
		stream.PutChar(sig, '(');
		if (sig.IsSignalled()) return false;
		if (!_pExprCar->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
		stream.PutChar(sig, ')');
		if (sig.IsSignalled()) return false;
	} else {
		if (!_pExprCar->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	}
	if (argListFlag) {
		stream.PutChar(sig, '(');
		if (sig.IsSignalled()) return false;
		if (!GetExprOwner().GenerateScript(sig, stream, scriptStyle, nestLevel, SEP_Comma)) return false;
		stream.PutChar(sig, ')');
		if (sig.IsSignalled()) return false;
	}
	const Symbol *pSymbolFront = Gura_Symbol(Str_Empty);
	if (!_attrFront.empty()) {
		stream.PutChar(sig, ':');
		if (sig.IsSignalled()) return false;
		pSymbolFront = _attrFront.front();
		foreach_const (SymbolList, ppSymbol, _attrFront) {
			const Symbol *pSymbol = *ppSymbol;
			if (ppSymbol != _attrFront.begin()) {
				stream.PutChar(sig, '.');
				if (sig.IsSignalled()) return false;
			}
			stream.Print(sig, pSymbol->GetName());
			if (sig.IsSignalled()) return false;
		}
	}
	foreach_const (SymbolSet, ppSymbol, _attrs) {
		const Symbol *pSymbol = *ppSymbol;
		if (!pSymbol->IsIdentical(pSymbolFront)) {
			stream.PutChar(sig, ':');
			if (sig.IsSignalled()) return false;
			stream.Print(sig, pSymbol->GetName());
			if (sig.IsSignalled()) return false;
		}
	}
	if (!_attrsOpt.empty()) {
		stream.PutChar(sig, ':');
		if (sig.IsSignalled()) return false;
		stream.PutChar(sig, '[');
		if (sig.IsSignalled()) return false;
		foreach_const (SymbolSet, ppSymbol, _attrsOpt) {
			const Symbol *pSymbol = *ppSymbol;
			if (ppSymbol != _attrsOpt.begin()) {
				stream.PutChar(sig, ',');
				if (sig.IsSignalled()) return false;
			}
			stream.Print(sig, pSymbol->GetName());
			if (sig.IsSignalled()) return false;
		}
		stream.PutChar(sig, ']');
		if (sig.IsSignalled()) return false;
	}
	if (!_pExprBlock.IsNull()) {
		if (scriptStyle != SCRSTYLE_Crammed) {
			stream.PutChar(sig, ' ');
			if (sig.IsSignalled()) return false;
		}
		if (!_pExprBlock->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	}
	if (!_pExprTrailer.IsNull()) {
		if (scriptStyle != SCRSTYLE_Crammed) {
			stream.PutChar(sig, ' ');
			if (sig.IsSignalled()) return false;
		}
		if (!_pExprTrailer->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Expr_UnaryOp
//-----------------------------------------------------------------------------
bool Expr_UnaryOp::IsUnaryOp() const { return true; }

Expr_UnaryOp::~Expr_UnaryOp()
{
}

Expr *Expr_UnaryOp::Clone() const
{
	return new Expr_UnaryOp(*this);
}

Value Expr_UnaryOp::DoExec(Environment &env, Signal sig) const
{
	Value value = GetChild()->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	Value result = _pOperator->EvalMapUnary(env, sig, value);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

Expr *Expr_UnaryOp::MathDiff(Environment &env, Signal sig, const Symbol *pSymbol) const
{
	return _pOperator->DiffUnary(env, sig, GetChild(), pSymbol);
}

Expr *Expr_UnaryOp::MathOptimize(Environment &env, Signal sig) const
{
	Expr *pExprOpt = GetChild()->MathOptimize(env, sig);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return NULL;
	}
	return _pOperator->OptimizeUnary(env, sig, pExprOpt);
}

bool Expr_UnaryOp::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "UnaryOp");
	return true;
}

bool Expr_UnaryOp::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	bool needParenthesisFlag = false;
	if (GetParent() != NULL) {
		needParenthesisFlag = (GetParent()->IsUnaryOp() ||
					GetParent()->IsBinaryOp() || GetParent()->IsMember());
	}
	if (needParenthesisFlag) {
		stream.PutChar(sig, '(');
		if (sig.IsSignalled()) return false;
	}
	if (!_suffixSymbolFlag) {
		stream.Print(sig, _pOperator->GetMathSymbol());
		if (sig.IsSignalled()) return false;
	}
	if (!GetChild()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	if (_suffixSymbolFlag) {
		stream.Print(sig, _pOperator->GetMathSymbol());
		if (sig.IsSignalled()) return false;
	}
	if (needParenthesisFlag) {
		stream.PutChar(sig, ')');
		if (sig.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Expr_BinaryOp
//-----------------------------------------------------------------------------
bool Expr_BinaryOp::IsBinaryOp() const { return true; }

Expr_BinaryOp::~Expr_BinaryOp()
{
}

Expr *Expr_BinaryOp::Clone() const
{
	return new Expr_BinaryOp(*this);
}

Value Expr_BinaryOp::DoExec(Environment &env, Signal sig) const
{
	OpType opType = _pOperator->GetOpType();
	const Expr *pExprLeft = GetLeft();
	const Expr *pExprRight = GetRight();
	Value valueLeft, valueRight;
	if (opType == OPTYPE_OrOr) {
		valueLeft = pExprLeft->Exec(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		if (!valueLeft.IsListOrIterator() && valueLeft.GetBoolean()) {
			return valueLeft;
		}
		valueRight = pExprRight->Exec(env, sig);
		if (sig.IsSignalled()) return Value::Null;
	} else if (opType == OPTYPE_AndAnd) {
		valueLeft = pExprLeft->Exec(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		if (!valueLeft.IsListOrIterator() && !valueLeft.GetBoolean()) {
			return valueLeft;
		}
		valueRight = pExprRight->Exec(env, sig);
		if (sig.IsSignalled()) return Value::Null;
	} else {
		valueLeft = pExprLeft->Exec(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		valueRight = pExprRight->Exec(env, sig);
		if (sig.IsSignalled()) return Value::Null;
	}
	return _pOperator->EvalMapBinary(env, sig, valueLeft, valueRight);
}

Expr *Expr_BinaryOp::MathDiff(Environment &env, Signal sig, const Symbol *pSymbol) const
{
	return _pOperator->DiffBinary(env, sig, GetLeft(), GetRight(), pSymbol);
}

Expr *Expr_BinaryOp::MathOptimize(Environment &env, Signal sig) const
{
	AutoPtr<Expr> pExprOpt1(GetLeft()->MathOptimize(env, sig));
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return NULL;
	}
	AutoPtr<Expr> pExprOpt2(GetRight()->MathOptimize(env, sig));
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return NULL;
	}
	return _pOperator->OptimizeBinary(env, sig, pExprOpt1.release(), pExprOpt2.release());
}

bool Expr_BinaryOp::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "BinaryOp");
	return true;
}

bool Expr_BinaryOp::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	bool needParenthesisFlag = false;
	if (GetParent() == NULL) {
		// nothing to do
	} else if (GetParent()->IsUnaryOp()) {
		//const Expr_UnaryOp *pExprOuter =
		//						dynamic_cast<const Expr_UnaryOp *>(GetParent());
		//needParenthesisFlag = NeedParenthesis(pExprOuter->GetOperator(),
		//					GetOperator(), false);
		needParenthesisFlag = true;
	} else if (GetParent()->IsBinaryOp()) {
		const Expr_BinaryOp *pExprOuter =
								dynamic_cast<const Expr_BinaryOp *>(GetParent());
		needParenthesisFlag = NeedParenthesis(pExprOuter->GetOperator(),
							GetOperator(), pExprOuter->GetRight() == this);
	} else if (GetParent()->IsMember()) {
		needParenthesisFlag = true;
	}
	if (needParenthesisFlag) {
		stream.PutChar(sig, '(');
		if (sig.IsSignalled()) return false;
	}
	if (!GetLeft()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	String text;
	if (scriptStyle != SCRSTYLE_Crammed) text += ' ';
	text += _pOperator->GetMathSymbol();
	if (scriptStyle != SCRSTYLE_Crammed) text += ' ';
	stream.Print(sig, text.c_str());
	if (sig.IsSignalled()) return false;
	if (!GetRight()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	if (needParenthesisFlag) {
		stream.PutChar(sig, ')');
		if (sig.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Expr_Quote
//-----------------------------------------------------------------------------
bool Expr_Quote::IsQuote() const { return true; }

Expr_Quote::~Expr_Quote()
{
}

Expr *Expr_Quote::Clone() const
{
	return new Expr_Quote(*this);
}

const Expr *Expr_Quote::Unquote() const
{
	return GetChild();
}

Value Expr_Quote::DoExec(Environment &env, Signal sig) const
{
	Value value;
	if (GetChild()->IsSymbol()) {
		const Expr_Symbol *pExprSym =
						dynamic_cast<const Expr_Symbol *>(GetChild());
		value.SetSymbol(pExprSym->GetSymbol());
	} else {
		value = Value(new Object_expr(env, Expr::Reference(GetChild())));
	}
	return value;
}

bool Expr_Quote::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Quote");
	return true;
}

bool Expr_Quote::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	if (GetChild()->IsUnary() || GetChild()->IsBinary()) {
		stream.Print(sig, "`(");
		if (sig.IsSignalled()) return false;
		if (!GetChild()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
		stream.Print(sig, ")");
		if (sig.IsSignalled()) return false;
	} else {
		stream.Print(sig, "`");
		if (sig.IsSignalled()) return false;
		if (!GetChild()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Expr_Force
//-----------------------------------------------------------------------------
bool Expr_Force::IsForce() const { return true; }

Expr_Force::~Expr_Force()
{
}

Expr *Expr_Force::Clone() const
{
	return new Expr_Force(*this);
}

Value Expr_Force::DoExec(Environment &env, Signal sig) const
{
	Value result = GetChild()->Exec(env, sig);
	return result;
}

bool Expr_Force::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Force");
	return true;
}

bool Expr_Force::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	stream.Print(sig, "!!");
	if (sig.IsSignalled()) return false;
	if (!GetChild()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	return true;
}

//-----------------------------------------------------------------------------
// Expr_Prefix
//-----------------------------------------------------------------------------
bool Expr_Prefix::IsPrefix() const { return true; }

Expr_Prefix::~Expr_Prefix()
{
}

Expr *Expr_Prefix::Clone() const
{
	return new Expr_Prefix(*this);
}

Value Expr_Prefix::DoExec(Environment &env, Signal sig) const
{
	SetError(sig, ERR_SyntaxError, "invalid expression");
	return Value::Null;
}

bool Expr_Prefix::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Prefix");
	return true;
}

bool Expr_Prefix::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	stream.Print(sig, _pSymbol->GetName());
	if (sig.IsSignalled()) return false;
	if (!GetChild()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	return true;
}

//-----------------------------------------------------------------------------
// Expr_Suffix
//-----------------------------------------------------------------------------
bool Expr_Suffix::IsSuffix() const { return true; }

Expr_Suffix::~Expr_Suffix()
{
}

Expr *Expr_Suffix::Clone() const
{
	return new Expr_Suffix(*this);
}

Value Expr_Suffix::DoExec(Environment &env, Signal sig) const
{
	SetError(sig, ERR_SyntaxError, "invalid expression");
	return Value::Null;
}

OccurPattern Expr_Suffix::GetOccurPattern() const
{
	return
		(_pSymbol->IsIdentical(Gura_Symbol(Char_Mul)))?			OCCUR_ZeroOrMore :
		(_pSymbol->IsIdentical(Gura_Symbol(Char_Add)))?			OCCUR_OnceOrMore :
		(_pSymbol->IsIdentical(Gura_Symbol(Char_Question)))?	OCCUR_ZeroOrOnce :
		OCCUR_Invalid;
}

bool Expr_Suffix::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Suffix");
	return true;
}

bool Expr_Suffix::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	if (!GetChild()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	stream.Print(sig, _pSymbol->GetName());
	if (sig.IsSignalled()) return false;
	return true;
}

//-----------------------------------------------------------------------------
// Expr_Assign
//-----------------------------------------------------------------------------
bool Expr_Assign::IsAssign() const { return true; }

Expr_Assign::~Expr_Assign()
{
}

Expr *Expr_Assign::Clone() const
{
	return new Expr_Assign(*this);
}

Value Expr_Assign::DoExec(Environment &env, Signal sig) const
{
	return Exec(env, sig, env, NULL);
}

Value Expr_Assign::Exec(Environment &env, Signal sig,
					Environment &envDst, const SymbolSet *pSymbolsAssignable) const
{
	Value value;
	const Expr *pExpr = GetLeft();
	bool funcAssignFlag = false;
	if (pExpr->IsCaller()) {
		if (_pOperatorToApply != NULL) {
			SetError(sig, ERR_SyntaxError, "invalid operation");
			return Value::Null;
		}
		if (GetRight()->IsForce()) {
			value = GetRight()->Exec(env, sig);
			if (sig.IsSignalled()) return Value::Null;
		} else {
			Expr *pExprBody = Expr::Reference(GetRight()->Unquote());
			value = Value(new Object_expr(env, pExprBody));
		}
	} else {
		value = GetRight()->Exec(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		if (_pOperatorToApply != NULL) {
			Value valueLeft = pExpr->Exec(env, sig);
			if (sig.IsSignalled()) return Value::Null;
			value = _pOperatorToApply->EvalMapBinary(env, sig, valueLeft, value);
			if (sig.IsSignalled()) return Value::Null;
		}
	}
	return GetLeft()->Assign(envDst, sig, value, pSymbolsAssignable, true);
}

bool Expr_Assign::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Assign");
	return true;
}

bool Expr_Assign::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	bool needParenthesisFlag = false;
	if (GetParent() != NULL) {
		needParenthesisFlag = (GetParent()->IsUnary() ||
						GetParent()->IsBinary()) && !GetParent()->IsQuote();
	}
	if (needParenthesisFlag) {
		stream.PutChar(sig, '(');
		if (sig.IsSignalled()) return false;
	}
	if (!GetLeft()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	String text;
	if (scriptStyle != SCRSTYLE_Crammed) text += ' ';
	if (_pOperatorToApply != NULL) {
		text += _pOperatorToApply->GetMathSymbol();
	}
	text += '=';
	if (scriptStyle != SCRSTYLE_Crammed) text += ' ';
	stream.Print(sig, text.c_str());
	if (sig.IsSignalled()) return false;
	if (!GetRight()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	if (needParenthesisFlag) {
		stream.PutChar(sig, ')');
		if (sig.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Expr_DictAssign
//-----------------------------------------------------------------------------
bool Expr_DictAssign::IsDictAssign() const { return true; }

Expr_DictAssign::~Expr_DictAssign()
{
}

Expr *Expr_DictAssign::Clone() const
{
	return new Expr_DictAssign(*this);
}

Value Expr_DictAssign::DoExec(Environment &env, Signal sig) const
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	Value valueKey = GetLeft()->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	Value value = GetRight()->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	valList.reserve(2);
	valList.push_back(valueKey);
	valList.push_back(value);
	return result;
}

bool Expr_DictAssign::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "DictAssign");
	return true;
}

bool Expr_DictAssign::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	if (!GetLeft()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	stream.Print(sig, (scriptStyle == SCRSTYLE_Crammed)? "=>" : " => ");
	if (sig.IsSignalled()) return false;
	if (!GetRight()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	return true;
}

Value Expr_DictAssign::GetKey(Environment &env, Signal sig) const
{
	const Expr *pExpr = GetLeft()->Unquote();
	if (pExpr->IsSymbol()) {
		const Symbol *pSymbol = dynamic_cast<const Expr_Symbol *>(pExpr)->GetSymbol();
		return Value(pSymbol);
	} else if (pExpr->IsValue()) {
		return dynamic_cast<const Expr_Value *>(pExpr)->GetValue();
	} else if (pExpr->IsString()) {
		return Value(env, dynamic_cast<const Expr_String *>(pExpr)->GetString());
	} else {
		SetError(sig, ERR_KeyError,
				"l-value of dictionary assignment must be a symbol or a constant value");
		return Value::Null;
	}
}

//-----------------------------------------------------------------------------
// Expr_Member
//-----------------------------------------------------------------------------
bool Expr_Member::IsMember() const { return true; }

Expr_Member::~Expr_Member()
{
}

Expr *Expr_Member::Clone() const
{
	return new Expr_Member(*this);
}

Value Expr_Member::DoExec(Environment &env, Signal sig) const
{
	// Expr_Caller::Exec(), Expr_Member::Exec() and Expr_Member::DoAssign()
	// correspond to method-calling, property-getting and property-setting.
	Value valueThis = GetLeft()->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	Fundamental *pFund = NULL;
	if (valueThis.IsPrimitive() || valueThis.GetTinyBuffFlag()) {
		pFund = env.LookupClass(valueThis.GetValueType());
	} else {
		pFund = valueThis.ExtractFundamental(sig);
		if (sig.IsSignalled()) return Value::Null;
	}
	Mode mode = GetMode();
	if (mode != MODE_Normal) {
		if (valueThis.IsList() && valueThis.GetList().empty()) {
			return valueThis;
		}
		Iterator *pIterator = pFund->CreateIterator(sig);
		if (sig.IsSignalled()) return Value::Null;
		if (pIterator != NULL) {
			AutoPtr<Iterator> pIteratorMap(new Iterator_MemberMap(
						new Environment(env), sig, pIterator, Expr::Reference(GetRight())));
			if (mode == MODE_MapToIter) {
				return Value(env, pIteratorMap.release());
			}
			Value result = pIteratorMap->ToList(env, sig, false, false);
			if (sig.IsSignalled()) return Value::Null;
			return result;
		}
	}
	Value result;
	const Expr *pExprRight = GetRight();
	if (pExprRight->IsSymbol()) {
		const Expr_Symbol *pExprSymbol =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		result = pExprSymbol->Exec(*pFund, sig, valueThis);
	} else {
		result = pExprRight->Exec(*pFund, sig);
	}
	if (result.IsFunction()) {
		Object_function *pObjFunc =
			dynamic_cast<Object_function *>(Object_function::GetObject(result)->Clone());
		pObjFunc->SetThis(valueThis);
		result = Value(pObjFunc);
	}
	return result;
}

Value Expr_Member::DoAssign(Environment &env, Signal sig, Value &value,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	// Expr_Caller::Exec(), Expr_Member::Exec() and Expr_Member::DoAssign()
	// correspond to method-calling, property-getting and property-setting.
	Value valueThis = GetLeft()->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	Fundamental *pFund = valueThis.ExtractFundamental(sig);
	if (sig.IsSignalled()) return Value::Null;
	Mode mode = GetMode();
	if (mode == MODE_Normal) {
		return GetRight()->Assign(*pFund, sig, value, pSymbolsAssignable, escalateFlag);
	}
	AutoPtr<Iterator> pIteratorThis(pFund->CreateIterator(sig));
	if (pIteratorThis.IsNull()) {
		if (sig.IsSignalled()) return Value::Null;
		return GetRight()->Assign(*pFund, sig, value, pSymbolsAssignable, escalateFlag);
	}
	if (value.IsList() || value.IsIterator()) {
		AutoPtr<Iterator> pIteratorValue(value.CreateIterator(sig));
		if (sig.IsSignalled()) return Value::Null;
		Value value;
		Value valueThisEach;
		while (pIteratorThis->Next(env, sig, valueThisEach) &&
								pIteratorValue->Next(env, sig, value)) {
			Fundamental *pFundEach = valueThisEach.ExtractFundamental(sig);
			if (sig.IsSignalled()) break;
			GetRight()->Assign(*pFundEach, sig, value,
									pSymbolsAssignable, escalateFlag);
			if (sig.IsSignalled()) break;
		}
		if (sig.IsSignalled()) return Value::Null;
	} else {
		Value valueThisEach;
		while (pIteratorThis->Next(env, sig, valueThisEach)) {
			Fundamental *pFundEach = valueThisEach.ExtractFundamental(sig);
			if (sig.IsSignalled()) break;
			GetRight()->Assign(*pFundEach, sig, value, pSymbolsAssignable, escalateFlag);
			if (sig.IsSignalled()) break;
		}
		if (sig.IsSignalled()) return Value::Null;
	}
	return value;
}

bool Expr_Member::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Member");
	return true;
}

bool Expr_Member::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	bool needParenthesisFlag = false;
	const Expr *pExprLeft = GetLeft();
	if (pExprLeft->IsIndexer()) {
		const Expr_Indexer *pExprIndexer = dynamic_cast<const Expr_Indexer *>(pExprLeft);
		pExprLeft = pExprIndexer->GetCar();
	}
	if (pExprLeft->IsSymbol()) {
		const Expr_Symbol *pExprSymbol = dynamic_cast<const Expr_Symbol *>(pExprLeft);
		needParenthesisFlag = !pExprSymbol->GetAttrs().empty();
	} else if (pExprLeft->IsCaller()) {
		const Expr_Caller *pExprCaller = dynamic_cast<const Expr_Caller *>(pExprLeft);
		needParenthesisFlag = !pExprCaller->GetAttrs().empty();
	}
	if (needParenthesisFlag) {
		stream.PutChar(sig, '(');
		if (sig.IsSignalled()) return false;
		if (!GetLeft()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
		stream.PutChar(sig, ')');
		if (sig.IsSignalled()) return false;
	} else {
		if (!GetLeft()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	}
	const char *str =
		(_mode == MODE_Normal)? "." :
		(_mode == MODE_MapToList)? "::" :
		(_mode == MODE_MapToIter)? ":*" :
		(_mode == MODE_MapAlong)? ":&" : NULL;
	if (str == NULL) {
		sig.SetError(ERR_SyntaxError, "unknown mapping operator");
		return false;
	}
	stream.Print(sig, str);
	if (!GetRight()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	return true;
}

}
