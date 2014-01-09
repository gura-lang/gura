//=============================================================================
// Expr
//=============================================================================
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
		{ EXPRTYPE_UnaryOp,			"unaryop",			},
		{ EXPRTYPE_Quote,			"quote",			},
		{ EXPRTYPE_BinaryOp,		"binaryop",			},
		{ EXPRTYPE_Assign,			"assign",			},
		{ EXPRTYPE_Member,			"member",			},
		{ EXPRTYPE_Root,			"root",				},
		{ EXPRTYPE_Block,			"block",			},
		{ EXPRTYPE_Lister,			"lister",			},
		{ EXPRTYPE_Iterer,			"iterer",			},
		{ EXPRTYPE_Indexer,			"indexer",			},
		{ EXPRTYPE_Caller,			"caller",			},
		{ EXPRTYPE_Value,			"value",			},
		{ EXPRTYPE_Symbol,			"symbol",			},
		{ EXPRTYPE_String,			"string",			},
		{ EXPRTYPE_SuffixedNumber,	"suffixednumber",	},
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
//        |                   `- Expr_Quote
//        +- Expr_Binary <----+- Expr_BinaryOp
//        |                   +- Expr_Assign
//        |                   `- Expr_Member
//        +- Expr_Container <-+- Expr_Root
//        |                   +- Expr_Block
//        |                   +- Expr_Lister
//        |                   `- Expr_Iterer
//        +- Expr_Compound <--+- Expr_Indexer
//        |                   `- Expr_Caller
//        +- Expr_Value
//        +- Expr_Symbol
//        `- Expr_String
//-----------------------------------------------------------------------------
Expr::Expr(ExprType exprType) : _exprType(exprType),
	_cntRef(1), _lineNoTop(0), _lineNoBtm(0), _pExprParent(NULL)
{
}

Expr::Expr(const Expr &expr) : _exprType(expr._exprType),
	_cntRef(1), _lineNoTop(expr._lineNoTop), _lineNoBtm(expr._lineNoBtm), _pExprParent(expr._pExprParent),
	_pSourceName(StringRef::Reference(expr._pSourceName.get()))
{
}

Expr::~Expr()
{
}

Value Expr::Exec(Environment &env, Signal sig,
			AutoPtr<SeqPostHandler> pSeqPostHandler, bool evalSymFuncFlag) const
{
	Value result = DoExec(env, sig, pSeqPostHandler.get());
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
	if (evalSymFuncFlag && result.Is_function() && result.GetFunction()->IsSymbolFunc()) {
		// symbol functions are only evaluated by a sequence of block.
		// in the folloiwng example, "return" shall be evaluated by a block
		// of "if" function.
		//   repeat { if (flag) { return } }
		// in the following example, "&&" operator returns "return" function
		// object as its result, and then the block of "repeat" shall evaluate it.
		//   repeat { flag && return }
		const Function *pFunc = result.GetFunction();
		AutoPtr<Args> pArgs(new Args());
		result = pFunc->Call(env, sig, *pArgs);
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
	}
	return result;
}

Value Expr::Assign(Environment &env, Signal sig, Value &valueAssigned,
				const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	Value result = DoAssign(env, sig, valueAssigned, pSymbolsAssignable, escalateFlag);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
	return result;
}

Value Expr::DoAssign(Environment &env, Signal sig, Value &valueAssigned,
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

Expr_Block *Expr::ToExprBlock() const
{
	if (IsBlock()) return dynamic_cast<Expr_Block *>(Expr::Reference(this));
	Expr_Block *pExprBlock = new Expr_Block();
	pExprBlock->AddExpr(Expr::Reference(this));
	return pExprBlock;
}

bool Expr::IsAtSameLine(const Expr *pExpr) const
{
	if (GetLineNoTop() != pExpr->GetLineNoTop()) return false;
	const char *sourceName1 = GetSourceName();
	const char *sourceName2 = pExpr->GetSourceName();
	if (sourceName1 == NULL && sourceName2 == NULL) return true;
	if (sourceName1 == NULL || sourceName2 == NULL) return false;
	return ::strcmp(sourceName1, sourceName2) == 0;
}

void Expr::GatherSymbol(SymbolSet &symbolSet) const
{
	ExprVisitor_GatherSymbol visitor(symbolSet);
	Accept(visitor);
}

void Expr::GatherSimpleLambdaArgs(ExprOwner &exprOwnerArg) const
{
	ExprVisitor_GatherSimpleLambdaArgs visitor(exprOwnerArg);
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
	return value.Is_number() && value.GetNumber() == num;
}

bool Expr::IsConstEvenNumber() const
{
	if (!IsValue()) return false;
	const Value &value = dynamic_cast<const Expr_Value *>(this)->GetValue();
	return value.Is_number() && ::fmod(value.GetNumber(), 2) == 0;
}

bool Expr::IsConstNegNumber() const
{
	if (!IsValue()) return false;
	const Value &value = dynamic_cast<const Expr_Value *>(this)->GetValue();
	return value.Is_number() && value.GetNumber() < 0;
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

bool Expr::IsOperatorPair() const
{
	return IsBinaryOp() &&
		dynamic_cast<const Expr_BinaryOp *>(this)->GetOperator()->GetOpType() == OPTYPE_Pair;
}

// type chekers - Unary and descendants
bool Expr::IsUnary() const			{ return false; }
bool Expr::IsUnaryOp() const		{ return false; }
bool Expr::IsUnaryOpSuffix() const	{ return false; }
bool Expr::IsQuote() const			{ return false; }
	// type chekers - Binary and descendants
bool Expr::IsBinary() const			{ return false; }
bool Expr::IsBinaryOp() const		{ return false; }
bool Expr::IsAssign() const			{ return false; }
bool Expr::IsMember() const			{ return false; }
// type chekers - Container and descendants
bool Expr::IsContainer() const		{ return false; }
bool Expr::IsRoot() const			{ return false; }
bool Expr::IsBlock() const			{ return false; }
bool Expr::IsLister() const			{ return false; }
bool Expr::IsIterer() const			{ return false; }
// type chekers - Compound and descendants
bool Expr::IsCompound() const		{ return false; }
bool Expr::IsIndexer() const		{ return false; }
bool Expr::IsCaller() const			{ return false; }
// type chekers - others
bool Expr::IsValue() const			{ return false; }
bool Expr::IsSymbol() const			{ return false; }
bool Expr::IsString() const			{ return false; }
bool Expr::IsSuffixedNumber() const	{ return false; }

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
	SimpleStream_StringWriter stream(str);
	GenerateScript(sig, stream, scriptStyle, 0);
	return str;
}

String Expr::MakePosText() const
{
	String str;
	const char *sourceName = GetSourceName();
	if (sourceName == NULL) {
		str += SRCNAME_unknown;
	} else {
		String fileName;
		PathManager::SplitFileName(sourceName, NULL, &fileName);
		str += fileName;
	}
	char buff[64];
	if (GetLineNoTop() == GetLineNoBtm()) {
		::sprintf(buff, ":%d", GetLineNoTop());
	} else {
		::sprintf(buff, ":%d-%d", GetLineNoTop(), GetLineNoBtm());
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
	} else if (pSymbol->IsIdentical(Gura_Symbol(brief))) {
		return SCRSTYLE_Brief;
	} else if (pSymbol->IsIdentical(Gura_Symbol(fancy))) {
		return SCRSTYLE_Fancy;
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
			_exprOwnerArg.push_back(pExpr->Reference());
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
// Expr::SequenceRoot
//-----------------------------------------------------------------------------
Expr::SequenceRoot::SequenceRoot(Environment *pEnv, ExprOwner *pExprOwner) :
								Sequence(pEnv), _pExprOwner(pExprOwner), _idxExpr(0)
{
}

bool Expr::SequenceRoot::DoStep(Signal sig, Value &result)
{
	if (_idxExpr >= _pExprOwner->size()) {
		_doneFlag = true;
		return false;
	}
	Environment &env = *_pEnv;
	const Expr *pExpr = (*_pExprOwner)[_idxExpr++];
	//::printf("# %s\n", pExpr->ToString(Expr::SCRSTYLE_Brief).c_str());
	SeqPostHandler *pSeqPostHandler = NULL;
	result = pExpr->Exec(env, sig, pSeqPostHandler);
	if (sig.IsError()) {
		sig.AddExprCause(pExpr);
		result = Value::Null;
		_doneFlag = true;
		return false;
	} else if (sig.IsTerminate()) {
		sig.PrintSignal(*env.GetConsoleErr());
		sig.ClearSignal();
		result = Value::Null;
		_doneFlag = true;
		return false;
	} else if (sig.IsSignalled()) {
		sig.PrintSignal(*env.GetConsoleErr());
		sig.ClearSignal();
	} else if (!env.GetGlobal()->GetEchoFlag()) {
		// nothing to do
	} else if (result.IsValid()) {
		env.GetConsole()->Println(sig, result.ToString().c_str());
	}
	_doneFlag = (_idxExpr >= _pExprOwner->size());
	return true;
}

String Expr::SequenceRoot::ToString() const
{
	String str;
	str += "<sequence:expr_root>";
	return str;
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
	if (pExprTop->GetLineNoTop() != pExprTop->GetLineNoBtm()) return false;
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
// ExprOwner::Iterator
//-----------------------------------------------------------------------------
ExprOwner::Iterator::Iterator(ExprOwner *pExprOwner) :
					Gura::Iterator(false), _idx(0), _pExprOwner(pExprOwner)
{
}

Iterator *ExprOwner::Iterator::GetSource()
{
	return NULL;
}

bool ExprOwner::Iterator::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_idx < _pExprOwner->size()) {
		Expr *pExpr = (*_pExprOwner)[_idx++];
		value = Value(new Object_expr(env, pExpr->Reference()));
		return true;
	}
	return false;
}

String ExprOwner::Iterator::ToString() const
{
	String rtn;
	rtn += "exprowner";
	return rtn;
}

void ExprOwner::Iterator::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// ExprOwner::SequenceEach
//-----------------------------------------------------------------------------
ExprOwner::SequenceEach::SequenceEach(Environment *pEnv, ExprOwner *pExprOwner) :
						Sequence(pEnv), _pExprOwner(pExprOwner), _idxExpr(0)
{
}

bool ExprOwner::SequenceEach::DoStep(Signal sig, Value &result)
{
	if (_idxExpr >= _pExprOwner->size()) {
		_doneFlag = true;
		return false;
	}
	SeqPostHandler *pSeqPostHandlerEach = NULL;
	Environment &env = *_pEnv;
	const Expr *pExpr = (*_pExprOwner)[_idxExpr++];
	result = pExpr->Exec(env, sig, pSeqPostHandlerEach, true);
	if (sig.IsSignalled()) return false;
	if (_idxExpr < _pExprOwner->size()) return true;
	_doneFlag = true;
	return true;
}

String ExprOwner::SequenceEach::ToString() const
{
	String str;
	str += "<sequence:expr>";
	return str;
}

//-----------------------------------------------------------------------------
// ExprOwner::SequenceToList
//-----------------------------------------------------------------------------
ExprOwner::SequenceToList::SequenceToList(Environment *pEnv, ExprOwner *pExprOwner) :
						Sequence(pEnv), _pExprOwner(pExprOwner), _idxExpr(0)
{
	_pValList = &_result.InitAsList(*pEnv);
	_pSeqPostHandlerEach.reset(new SeqPostHandlerEach(pEnv->Reference(), *_pValList));
}

bool ExprOwner::SequenceToList::DoStep(Signal sig, Value &result)
{
	if (_idxExpr >= _pExprOwner->size()) {
		_doneFlag = true;
		return false;
	}
	Environment &env = *_pEnv;
	const Expr *pExpr = (*_pExprOwner)[_idxExpr++];
	result = pExpr->Exec(env, sig, _pSeqPostHandlerEach->Reference(), true);
	if (sig.IsSignalled()) return false;
	if (result.IsSequence()) return true;
	if (_idxExpr < _pExprOwner->size()) return false;
	result = _result;
	_doneFlag = true;
	return true;
}

String ExprOwner::SequenceToList::ToString() const
{
	String str;
	str += "<sequence:expr>";
	return str;
}

bool ExprOwner::SequenceToList::SeqPostHandlerEach::DoPost(Signal sig, const Value &result)
{
	Environment &env = *_pEnv;
	if (result.Is_iterator()) {
		AutoPtr<Gura::Iterator> pIterator(result.CreateIterator(sig));
		if (sig.IsSignalled()) return false;
		if (pIterator->IsInfinite()) {
			Iterator::SetError_InfiniteNotAllowed(sig);
			return false;
		}
		Value value;
		while (pIterator->Next(env, sig, value)) {
			_valList.push_back(value);
		}
		if (sig.IsSignalled()) return false;
	} else {
		_valList.push_back(result);
	}
	//_valList.push_back(result);
	return true;
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

Expr_Container::Expr_Container(ExprType exprType) :
						Expr(exprType), _pExprOwner(new ExprOwner())
{
}

Expr_Container::Expr_Container(ExprType exprType, ExprOwner *pExprOwner) :
						Expr(exprType), _pExprOwner(pExprOwner)
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

Expr *Expr_Value::Clone() const
{
	return new Expr_Value(*this);
}

Value Expr_Value::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	Value result;
	if (_value.Is_expr()) {
		result = _value.GetExpr()->Exec(env, sig, pSeqPostHandler);
	} else {
		result = _value;
		if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, result)) return Value::Null;
	}
	return result;
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
	if (_value.Is_binary()) {
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
			str = _value.ToString();
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
// Expr_Symbol
//-----------------------------------------------------------------------------
bool Expr_Symbol::IsSymbol() const { return true; }

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

Value Expr_Symbol::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	Value result = env.GetProp(env, sig, GetSymbol(), GetAttrs());
	if (sig.IsSignalled()) return Value::Null;
	if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, result)) return Value::Null;
	return result;
}

Value Expr_Symbol::Exec(Environment &env, Signal sig,
				const Value &valueThis, SeqPostHandler *pSeqPostHandler) const
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

Value Expr_Symbol::DoAssign(Environment &env, Signal sig, Value &valueAssigned,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	bool evaluatedFlag = false;
	const SymbolSet &attrs = SymbolSet::Null;
	Value result = env.DoSetProp(env, sig, GetSymbol(), valueAssigned, attrs, evaluatedFlag);
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
	if (valueAssigned.IsModule()) {
		Module *pModule = valueAssigned.GetModule();
		if (pModule->IsAnonymous()) {
			pModule->SetSymbol(GetSymbol());
		}
		extra = EXTRA_Public;
	} else if (valueAssigned.IsClass() && valueAssigned.GetClass()->IsCustom()) {
		ClassCustom *pClass = dynamic_cast<ClassCustom *>(valueAssigned.GetClass());
		if (pClass->IsAnonymous()) {
			ValueTypeInfo *pValueTypeInfo =
							ValueTypePool::GetInstance()->Add(GetSymbol());
			pValueTypeInfo->SetClass(Class::Reference(pClass));
			env.AssignValueType(pValueTypeInfo);
			Function *pFunc = pClass->PrepareConstructor(env, sig);
			if (pFunc == NULL) return Value::Null;
			valueAssigned = Value(new Object_function(env, pFunc));
		}
		extra = EXTRA_Public;
	} else if (valueAssigned.Is_function()) {
		Function *pFunc = valueAssigned.GetFunction();
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
		pDecl->ValidateAndCast(env, sig, valueAssigned);
		if (sig.IsSignalled()) return Value::Null;
	}
	if (escalateFlag) {
		env.AssignValueFromBlock(GetSymbol(), valueAssigned, extra);
	} else {
		env.AssignValue(GetSymbol(), valueAssigned, extra);
	}
	return valueAssigned;
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
// Expr_String
//-----------------------------------------------------------------------------
bool Expr_String::IsString() const { return true; }

Expr *Expr_String::Clone() const
{
	return new Expr_String(*this);
}

Value Expr_String::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	Value result(_str);
	if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, result)) return Value::Null;
	return result;
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
	if (scriptStyle == SCRSTYLE_Brief && _str.size() > 32) {
		stream.Print(sig, "' .. '");
	} else {
		stream.Print(sig, MakeQuotedString(_str.c_str()).c_str());
	}
	if (sig.IsSignalled()) return false;
	return true;
}

//-----------------------------------------------------------------------------
// Expr_SuffixedNumber
//-----------------------------------------------------------------------------
bool Expr_SuffixedNumber::IsSuffixedNumber() const { return true; }

Expr *Expr_SuffixedNumber::Clone() const
{
	return new Expr_SuffixedNumber(*this);
}

Value Expr_SuffixedNumber::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	Value result;
	SuffixHandler *pSuffixHandler = SuffixHandler::Lookup(env, _pSymbolSuffix);
	if (pSuffixHandler == NULL) {
		sig.SetError(ERR_SyntaxError, "unknown suffix %s", _pSymbolSuffix->GetName());
		return Value::Null;
	}
	result = pSuffixHandler->DoEval(env, sig, _str.c_str());
	if (sig.IsSignalled()) return Value::Null;
	if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, result)) return Value::Null;
	return result;
}

void Expr_SuffixedNumber::Accept(ExprVisitor &visitor) const
{
	visitor.Visit(this);
}

bool Expr_SuffixedNumber::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "SuffixedNumber");
	return true;
}

bool Expr_SuffixedNumber::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	if (scriptStyle == SCRSTYLE_Brief && _str.size() > 32) {
		stream.Print(sig, "' .. '");
	} else {
		stream.Print(sig, _str.c_str());
	}
	if (sig.IsSignalled()) return false;
	return true;
}

//-----------------------------------------------------------------------------
// Expr_Root
//-----------------------------------------------------------------------------
bool Expr_Root::IsRoot() const { return true; }

Expr_Root::Expr_Root() : Expr_Container(EXPRTYPE_Root)
{
}

Expr_Root::Expr_Root(const Expr_Root &expr) : Expr_Container(expr)
{
}

Expr *Expr_Root::Clone() const
{
	return new Expr_Root(*this);
}

Value Expr_Root::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	//AutoPtr<Processor> pProcessor(new Processor());
	//pProcessor->PushSequence(new SequenceRoot(env.Reference(), GetExprOwner().Reference()));
	//return pProcessor->Run(sig);
	return Value::Null;
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

Expr_Block::Expr_Block() : Expr_Container(EXPRTYPE_Block)
{
}

Expr_Block::Expr_Block(ExprOwner *pExprOwner, ExprOwner *pExprOwnerParam) :
	Expr_Container(EXPRTYPE_Block, pExprOwner), _pExprOwnerParam(pExprOwnerParam)
{
}

Expr_Block::Expr_Block(const Expr_Block &expr) : Expr_Container(expr)
{
	if (expr.GetExprOwnerParam() != NULL) {
		SetExprOwnerParam(new ExprOwner());
		foreach_const (ExprOwner, ppExpr, *expr.GetExprOwnerParam()) {
			Expr *pExpr = (*ppExpr)->Clone();
			GetExprOwnerParam()->push_back(pExpr);
			pExpr->SetParent(this);
		}
	}
}

Expr_Block::~Expr_Block()
{
	if (GetExprOwnerParam() != NULL) {
		GetExprOwnerParam()->SetParent(GetParent());
	}
}

Expr *Expr_Block::Clone() const
{
	return new Expr_Block(*this);
}

Value Expr_Block::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
#if 1
	Value result;
	if (env.IsType(ENVTYPE_lister)) {
		ValueList &valList = result.InitAsList(env);
		SeqPostHandler *pSeqPostHandlerEach = NULL;
		foreach_const (ExprOwner, ppExpr, GetExprOwner()) {
			Value value = (*ppExpr)->Exec2(env, sig, pSeqPostHandlerEach, true);
			if (sig.IsSignalled()) return Value::Null;
			
			valList.push_back(value);
		}
	} else {
		SeqPostHandler *pSeqPostHandlerEach = NULL;
		foreach_const (ExprList, ppExpr, GetExprOwner()) {
			result = (*ppExpr)->Exec2(env, sig, pSeqPostHandlerEach, true);
			if (sig.IsSignalled()) return Value::Null;
		}
	}
	if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, result)) return Value::Null;
	return result;
#else
	Sequence *pSequence = NULL;
	if (env.IsType(ENVTYPE_lister)) {
		pSequence = new ExprOwner::SequenceToList(env.Reference(), GetExprOwner().Reference());
	} else {
		pSequence = new ExprOwner::SequenceEach(env.Reference(), GetExprOwner().Reference());
	}
	pSequence->SetSeqPostHandler(SeqPostHandler::Reference(pSeqPostHandler));
	return Sequence::Return(sig, pSequence);
#endif
}

Expr *Expr_Block::MathDiff(Environment &env, Signal sig, const Symbol *pSymbol) const
{
	return (GetExprOwner().size() == 1)?
			GetExprOwner().front()->MathDiff(env, sig, pSymbol) :
			Expr::MathDiff(env, sig, pSymbol);
}

void Expr_Block::Accept(ExprVisitor &visitor) const
{
	if (GetExprOwnerParam() != NULL) GetExprOwnerParam()->Accept(visitor);
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
	if (GetExprOwnerParam() != NULL) {
		stream.PutChar(sig, '|');
		if (sig.IsSignalled()) return false;
		const char *sepText = (scriptStyle == Expr::SCRSTYLE_Crammed)? "," : ", ";
		foreach_const (ExprList, ppExpr, *GetExprOwnerParam()) {
			const Expr *pExpr = *ppExpr;
			if (ppExpr != GetExprOwnerParam()->begin()) {
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
	}
	const Expr_Caller *pExprCaller =
			(GetParent() == NULL || !GetParent()->IsCaller())? NULL :
			dynamic_cast<const Expr_Caller *>(GetParent());
	if (GetExprOwner().empty()) {
		// nothing to do
	} else if (scriptStyle == SCRSTYLE_Brief && (!GetExprOwner().IsAtSameLine() ||
			(pExprCaller != NULL && !pExprCaller->IsAtSameLine(GetExprOwner().front())))) {
		stream.Print(sig, " .. ");
		if (sig.IsSignalled()) return false;
	} else {
		const char *sepText =
			(scriptStyle == SCRSTYLE_Crammed)? "" :
			(scriptStyle == SCRSTYLE_OneLine)? " " :
			(scriptStyle == SCRSTYLE_Brief)? " " :
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
// Expr_Lister
//-----------------------------------------------------------------------------
bool Expr_Lister::IsLister() const { return true; }

Expr *Expr_Lister::Clone() const
{
	return new Expr_Lister(*this);
}

Value Expr_Lister::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
#if 1
	Value result;
	SeqPostHandler *pSeqPostHandlerEach = NULL;
	ValueList &valList = result.InitAsList(env);
	foreach_const (ExprOwner, ppExpr, GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		Value value = pExpr->Exec2(env, sig, pSeqPostHandlerEach);
		if (sig.IsSignalled()) return Value::Null;
		if (value.Is_iterator()) {
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
	if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, result)) return Value::Null;
	return result;
#else
	Sequence *pSequence = new ExprOwner::SequenceToList(env.Reference(), GetExprOwner().Reference());
	pSequence->SetSeqPostHandler(SeqPostHandler::Reference(pSeqPostHandler));
	return Sequence::Return(sig, pSequence);
#endif
}

Value Expr_Lister::DoAssign(Environment &env, Signal sig, Value &valueAssigned,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	const ExprList &exprList = GetExprOwner();
	if (valueAssigned.Is_list() || valueAssigned.Is_iterator()) {
		ValueList *pValList = NULL;
		ExprList::const_iterator ppExpr = exprList.begin();
		AutoPtr<Iterator> pIterator(valueAssigned.CreateIterator(sig));
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
			if (pExpr->IsUnaryOpSuffix()) {
				const Expr_UnaryOp *pExprUnaryOp =
										dynamic_cast<const Expr_UnaryOp *>(pExpr);
				pExpr = pExprUnaryOp->GetChild();
				occurPattern = Declaration::SymbolToOccurPattern(
										pExprUnaryOp->GetOperator()->GetSymbol());
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
			if (pExpr->IsUnaryOpSuffix()) {
				const Expr_UnaryOp *pExprUnaryOp =
								dynamic_cast<const Expr_UnaryOp *>(pExpr);
				pExpr = pExprUnaryOp->GetChild();
				occurPattern = Declaration::SymbolToOccurPattern(
										pExprUnaryOp->GetOperator()->GetSymbol());
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
			pExpr->Assign(env, sig, valueAssigned, pSymbolsAssignable, escalateFlag);
			if (sig.IsSignalled()) return Value::Null;
		}
	}
	return valueAssigned;
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
	} else if (scriptStyle == SCRSTYLE_Brief && !GetExprOwner().IsAtSameLine()) {
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

Expr_Lister::SequenceEx::SequenceEx(Environment *pEnv) : Sequence(pEnv)
{
}

bool Expr_Lister::SequenceEx::DoStep(Signal sig, Value &result)
{
	return false;
}

String Expr_Lister::SequenceEx::ToString() const
{
	String str;
	str += "<sequence:expr_lister>";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_Iterer
//-----------------------------------------------------------------------------
bool Expr_Iterer::IsIterer() const { return true; }

Expr *Expr_Iterer::Clone() const
{
	return new Expr_Iterer(*this);
}

Value Expr_Iterer::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	SeqPostHandler *pSeqPostHandlerEach = NULL;
	AutoPtr<Iterator_Concat> pIterator(new Iterator_Concat());
	foreach_const (ExprOwner, ppExpr, GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		Value value = pExpr->Exec2(env, sig, pSeqPostHandlerEach);
		if (sig.IsSignalled()) return Value::Null;
		Iterator *pIteratorArg = NULL;
		if (value.Is_iterator()) {
			pIteratorArg = value.CreateIterator(sig);
			if (sig.IsSignalled()) return Value::Null;
		} else {
			pIteratorArg = new Iterator_OneShot(value);
		}
		pIterator->Add(pIteratorArg);
	}
	Value result(new Object_iterator(env, pIterator.release()));
	if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, result)) return Value::Null;
	return result;
}

bool Expr_Iterer::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Iterer");
	return true;
}

bool Expr_Iterer::GenerateScript(Signal sig, SimpleStream &stream,
								ScriptStyle scriptStyle, int nestLevel) const
{
	stream.PutChar(sig, '(');
	if (sig.IsSignalled()) return false;
	if (GetExprOwner().empty()) {
		// nothing to do
	} else if (scriptStyle == SCRSTYLE_Brief && !GetExprOwner().IsAtSameLine()) {
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

Expr_Iterer::SequenceEx::SequenceEx(Environment *pEnv) : Sequence(pEnv)
{
}

bool Expr_Iterer::SequenceEx::DoStep(Signal sig, Value &result)
{
	return false;
}

String Expr_Iterer::SequenceEx::ToString() const
{
	String str;
	str += "<sequence:expr_iterer>";
	return str;
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

Expr *Expr_Indexer::Clone() const
{
	return new Expr_Indexer(*this);
}

Value Expr_Indexer::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	SeqPostHandler *pSeqPostHandlerCar = NULL;
	Value valueCar = GetCar()->Exec2(env, sig, pSeqPostHandlerCar);
	if (sig.IsSignalled()) return Value::Null;
	const ExprList &exprList = GetLister()->GetExprOwner();
	Value result;
	if (exprList.empty()) {
		result = valueCar.EmptyIndexGet(env, sig);
		if (sig.IsSignalled()) return Value::Null;
	} else {
		SeqPostHandler *pSeqPostHandlerEach = NULL;
		ValueList valIdxList;
		foreach_const (ExprList, ppExpr, exprList) {
			Value value = (*ppExpr)->Exec2(env, sig, pSeqPostHandlerEach);
			if (sig.IsSignalled()) {
				sig.AddExprCause(*ppExpr);
				return Value::Null;
			}
			if (value.Is_list()) {
				ValueVisitor_Flatten visitor(valIdxList);
				value.Accept(visitor);
			} else {
				valIdxList.push_back(value);
			}
		}
		if (valIdxList.size() > 0) {
			if (valIdxList.size() == 1 && !valIdxList.front().IsListOrIterator()) {
				// obj[idx]
				result = valueCar.IndexGet(env, sig, valIdxList.front());
				if (sig.IsSignalled()) return Value::Null;
			} else {
				// obj[idx, idx, ..]
				ValueList &valListDst = result.InitAsList(env);
				foreach_const (ValueList, pValueIdx, valIdxList) {
					if (pValueIdx->Is_list() || pValueIdx->Is_iterator()) {
						AutoPtr<Iterator> pIteratorIdx(pValueIdx->CreateIterator(sig));
						if (sig.IsSignalled()) break;
						Value valueIdxEach;
						while (pIteratorIdx->Next(env, sig, valueIdxEach)) {
							Value value = valueCar.IndexGet(env, sig, valueIdxEach);
							if (sig.IsSignalled()) {
								if (sig.GetError().GetType() == ERR_IndexError &&
														pIteratorIdx->IsInfinite()) {
									sig.ClearSignal();
								}
								break;
							}
							valListDst.push_back(value);
						}
						if (sig.IsSignalled()) return Value::Null;
					} else {
						Value value = valueCar.IndexGet(env, sig, *pValueIdx);
						if (sig.IsSignalled()) break;
						valListDst.push_back(value);
					}
				}
			}
		}
	}
	if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, result)) return Value::Null;
	return result;
}

Value Expr_Indexer::DoAssign(Environment &env, Signal sig, Value &valueAssigned,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	SeqPostHandler *pSeqPostHandlerCar = NULL;
	Value valueCar = GetCar()->Exec2(env, sig, pSeqPostHandlerCar);
	if (sig.IsSignalled()) return Value::Null;
	const ExprList &exprList = GetLister()->GetExprOwner();
	if (exprList.empty()) {
		valueCar.EmptyIndexSet(env, sig, valueAssigned);
		if (sig.IsSignalled()) return Value::Null;
		return valueAssigned;
	}
	if (exprList.size() == 1) {
		SeqPostHandler *pSeqPostHandlerIdx = NULL;
		// obj[idx] = v / obj[idx] = [v, v, ..]
		Value valueIdx = exprList.front()->Exec2(env, sig, pSeqPostHandlerIdx);
		if (sig.IsSignalled()) return Value::Null;
		if (valueIdx.Is_list() || valueIdx.Is_iterator()) {
			Iterator *pIteratorIdx = valueIdx.CreateIterator(sig);
			if (sig.IsSignalled()) return Value::Null;
			if (valueAssigned.Is_list() || valueAssigned.Is_iterator()) {
				Iterator *pIterator = valueAssigned.CreateIterator(sig);
				if (sig.IsSignalled()) return Value::Null;
				Value valueIdxEach, valueEach;
				while (pIteratorIdx->Next(env, sig, valueIdxEach) &&
											pIterator->Next(env, sig, valueEach)) {
					valueCar.IndexSet(env, sig, valueIdxEach, valueEach);
					if (sig.IsSignalled()) break;
				}
			} else {
				Value valueIdxEach;
				while (pIteratorIdx->Next(env, sig, valueIdxEach)) {
					valueCar.IndexSet(env, sig, valueIdxEach, valueAssigned);
				}
			}
		} else {
			valueCar.IndexSet(env, sig, valueIdx, valueAssigned);
		}
	} else if (valueAssigned.Is_list() || valueAssigned.Is_iterator()) {
		SeqPostHandler *pSeqPostHandlerCdr = NULL;
		// obj[idx, idx, ..] = [v, v, ..]
		AutoPtr<Iterator> pIterator(valueAssigned.CreateIterator(sig));
		if (sig.IsSignalled()) return Value::Null;
		foreach_const (ExprList, ppExprCdr, exprList) {
			Value valueIdx = (*ppExprCdr)->Exec2(env, sig, pSeqPostHandlerCdr);
			if (sig.IsSignalled()) break;
			if (valueIdx.Is_list() || valueIdx.Is_iterator()) {
				AutoPtr<Iterator> pIteratorIdx(valueIdx.CreateIterator(sig));
				if (sig.IsSignalled()) break;
				Value valueIdxEach, valueEach;
				while (pIteratorIdx->Next(env, sig, valueIdxEach) &&
											pIterator->Next(env, sig, valueEach)) {
					valueCar.IndexSet(env, sig, valueIdxEach, valueEach);
					if (sig.IsSignalled()) break;
				}
			} else {
				Value valueEach;
				if (!pIterator->Next(env, sig, valueEach)) break;
				valueCar.IndexSet(env, sig, valueIdx, valueEach);
				if (sig.IsSignalled()) break;
			}
		}
	} else {
		SeqPostHandler *pSeqPostHandlerCdr = NULL;
		// obj[idx, idx, ..] = v
		foreach_const (ExprList, ppExprCdr, exprList) {
			Value valueIdx = (*ppExprCdr)->Exec2(env, sig, pSeqPostHandlerCdr);
			if (sig.IsSignalled()) return Value::Null;
			if (valueIdx.Is_list() || valueIdx.Is_iterator()) {
				AutoPtr<Iterator> pIteratorIdx(valueIdx.CreateIterator(sig));
				if (sig.IsSignalled()) break;
				Value valueIdxEach;
				while (pIteratorIdx->Next(env, sig, valueIdxEach)) {
					valueCar.IndexSet(env, sig, valueIdxEach, valueAssigned);
					if (sig.IsSignalled()) break;
				}
				if (sig.IsSignalled()) break;
			} else {
				valueCar.IndexSet(env, sig, valueIdx, valueAssigned);
				if (sig.IsSignalled()) break;
			}
		}
	}
	return valueAssigned;
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
		} else if (scriptStyle == SCRSTYLE_Brief && !GetExprOwner().IsAtSameLine()) {
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
		bool needParenthesisFlag = false;
		if (GetCar()->IsCaller()) {
			const Expr_Caller *pExprCaller = dynamic_cast<const Expr_Caller *>(GetCar());
			needParenthesisFlag = !pExprCaller->GetAttrs().empty();
		}
		if (needParenthesisFlag) {
			stream.PutChar(sig, '(');
			if (sig.IsSignalled()) return false;
		}
		if (!GetCar()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
		if (needParenthesisFlag) {
			stream.PutChar(sig, ')');
			if (sig.IsSignalled()) return false;
		}
		stream.PutChar(sig, '[');
		if (sig.IsSignalled()) return false;
		if (GetExprOwner().empty()) {
			// nothing to do
		} else if (scriptStyle == SCRSTYLE_Brief && !GetExprOwner().IsAtSameLine()) {
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

Expr_Indexer::SequenceEx::SequenceEx(Environment *pEnv) : Sequence(pEnv)
{
}

bool Expr_Indexer::SequenceEx::DoStep(Signal sig, Value &result)
{
	return false;
}

String Expr_Indexer::SequenceEx::ToString() const
{
	String str;
	str += "<sequence:expr_indexer>";
	return str;
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
	SeqPostHandler *pSeqPostHandlerCar = NULL;
	if (_pExprCar->IsMember()) return NULL;
	Value valueCar = _pExprCar->Exec2(env, sig, pSeqPostHandlerCar);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return NULL;
	}
	return valueCar.GetObject();
}

Value Expr_Caller::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	Value result;
	AutoPtr<TrailCtrlHolder> pTrailCtrlHolder(new TrailCtrlHolder(TRAILCTRL_Continue));
	for (const Expr_Caller *pExprCaller = this; pExprCaller != NULL;
									pExprCaller = pExprCaller->GetTrailer()) {
		result = pExprCaller->DoExec(env, sig, pTrailCtrlHolder.get());
		TrailCtrl trailCtrl = pTrailCtrlHolder->Get();
		if (trailCtrl == TRAILCTRL_Quit) break;
		if (trailCtrl == TRAILCTRL_Finalize) {
			// doesn't work correctly yet.
			SignalType sigType = SIGTYPE_None;
			Value valueSig;
			if (sig.IsErrorSuspended() || sig.IsError() || sig.IsTerminate()) break;
			if (sig.IsBreak() || sig.IsContinue() || sig.IsReturn()) {
				sigType = sig.GetType();
				valueSig = sig.GetValue();
			}
			sig.ClearSignal();
			for ( ; pExprCaller != NULL; pExprCaller = pExprCaller->GetTrailer()) {
				Callable *pCallable = pExprCaller->LookupCallable(env, sig);
				if (sig.IsSignalled()) return Value::Null;
				if (pCallable != NULL && pCallable->IsFinalizer()) {
					result = pExprCaller->DoExec(env, sig, pTrailCtrlHolder.get());
					if (sig.IsSignalled()) return Value::Null;
					
					sig.SetType(sigType);
					sig.SetValue(valueSig);
					return Value::Null;
				}
			}
			sig.SetType(sigType);
			sig.SetValue(valueSig);
			break;
		}
	}
	// if there's an error suspended by try() function, it would be resumed below.
	// otherwise, nothing would happen and any error would be kept intact.
	sig.ResumeError();
	if (sig.IsSignalled()) return Value::Null;
	if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, result)) return Value::Null;
	return result;
}

Value Expr_Caller::DoExec(Environment &env, Signal sig, TrailCtrlHolder *pTrailCtrlHolder) const
{
	// Expr_Caller::Exec(), Expr_Member::Exec() and Expr_Member::DoAssign()
	// correspond to method-calling, property-getting and property-setting.
	if (_pExprCar->IsMember()) {
		const Expr_Member *pExprMember = dynamic_cast<const Expr_Member *>(GetCar());
		SeqPostHandler *pSeqPostHandlerLeft = NULL;
		Value valueThis = pExprMember->GetLeft()->Exec2(env, sig, pSeqPostHandlerLeft);
		if (sig.IsSignalled()) return Value::Null;
		Expr_Member::Mode mode = pExprMember->GetMode();
		if (mode != Expr_Member::MODE_Normal) {
			if (valueThis.Is_list() && valueThis.GetList().empty()) {
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
								pIteratorThis, valueThis.Is_list(), pTrailCtrlHolder);
			} else {
				AutoPtr<Iterator> pIteratorMap(new Iterator_MethodMap(new Environment(env), sig,
									pIteratorThis, Expr_Caller::Reference(this)));
				if (mode == Expr_Member::MODE_MapToIter) {
					return Value(new Object_iterator(env, pIteratorMap.release()));
				}
				Value result = pIteratorMap->ToList(env, sig, false, false);
				if (sig.IsSignalled()) return Value::Null;
				return result;
			}
		}
		return EvalEach(env, sig, valueThis, NULL, false, pTrailCtrlHolder);
	} else {
		SeqPostHandler *pSeqPostHandler = NULL;
		Value valueCar = _pExprCar->Exec2(env, sig, pSeqPostHandler);
		if (sig.IsSignalled()) return Value::Null;
		Callable *pCallable = valueCar.GetObject();
		if (pCallable == NULL) {
			SetError(sig, ERR_TypeError, "object is not callable");
			return Value::Null;
		}
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetExprOwnerArg(GetExprOwner().Reference());
		pArgs->SetTrailCtrlHolder(TrailCtrlHolder::Reference(pTrailCtrlHolder));
		pArgs->SetAttrs(GetAttrs());
		pArgs->SetAttrsOpt(GetAttrsOpt());
		pArgs->SetBlock(Expr_Block::Reference(GetBlock()));
		return pCallable->DoCall(env, sig, *pArgs);
	}
}

Value Expr_Caller::EvalEach(Environment &env, Signal sig, const Value &valueThis,
		Iterator *pIteratorThis, bool listThisFlag, TrailCtrlHolder *pTrailCtrlHolder) const
{
	const Expr_Member *pExprMember = dynamic_cast<const Expr_Member *>(GetCar());
	const Expr *pExprRight = pExprMember->GetRight();
	Value valueCar;
	Callable *pCallable = NULL;
	Fundamental *pFund = NULL;
	if (valueThis.IsPrimitive()) {
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
			SeqPostHandler *pSeqPostHandler = NULL;
			const Expr_Symbol *pExprSymbol =
								dynamic_cast<const Expr_Symbol *>(pExprRight);
			valueCar = pExprSymbol->Exec(*pFund, sig, valueThis, pSeqPostHandler);
		} else {
			SeqPostHandler *pSeqPostHandler = NULL;
			valueCar = pExprRight->Exec2(*pFund, sig, pSeqPostHandler);
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
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetExprOwnerArg(GetExprOwner().Reference());
	pArgs->SetThis(valueThis);
	pArgs->SetIteratorThis(Iterator::Reference(pIteratorThis), listThisFlag);
	pArgs->SetTrailCtrlHolder(TrailCtrlHolder::Reference(pTrailCtrlHolder));
	pArgs->SetAttrs(GetAttrs());
	pArgs->SetAttrsOpt(GetAttrsOpt());
	pArgs->SetBlock(Expr_Block::Reference(GetBlock()));
	return pCallable->DoCall(env, sig, *pArgs);
}

Value Expr_Caller::DoAssign(Environment &env, Signal sig, Value &valueAssigned,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	if (!valueAssigned.Is_expr()) {
		SetError(sig, ERR_SyntaxError, "invalid function expression");
		return Value::Null;
	}
	Expr *pExprBody = Expr::Reference(valueAssigned.GetExpr());
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
	FunctionCustom *pFunc = new FunctionCustom(env, pSymbol, pExprBody, funcType);
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetExprOwnerArg(GetExprOwner().Reference());
	pArgs->SetAttrs(GetAttrs());
	pArgs->SetAttrsOpt(GetAttrsOpt());
	pArgs->SetBlock(Expr_Block::Reference(GetBlock()));
	if (!pFunc->CustomDeclare(env, sig, SymbolSet::Null, *pArgs)) {
		Function::Delete(pFunc);
		return Value::Null;
	}
	Value valueFunc(new Object_function(env, pFunc));
	GetCar()->Assign(env, sig, valueFunc, pSymbolsAssignable, escalateFlag);
	if (sig.IsSignalled()) return Value::Null;
	if (pFunc->GetSymbolFuncFlag()) return Value::Null;
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
	SeqPostHandler *pSeqPostHandler = NULL;
	const Expr *pExprArg = GetExprOwner().front();
	Value value = GetCar()->Exec2(env, sig, pSeqPostHandler);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return NULL;
	}
	if (!value.Is_function()) {
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

Expr_Caller::SequenceEx::SequenceEx(Environment *pEnv) : Sequence(pEnv)
{
}

bool Expr_Caller::SequenceEx::DoStep(Signal sig, Value &result)
{
	return false;
}

String Expr_Caller::SequenceEx::ToString() const
{
	String str;
	str += "<sequence:expr_caller>";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_UnaryOp
//-----------------------------------------------------------------------------
bool Expr_UnaryOp::IsUnaryOp() const { return true; }
bool Expr_UnaryOp::IsUnaryOpSuffix() const { return _suffixFlag; }

Expr *Expr_UnaryOp::Clone() const
{
	return new Expr_UnaryOp(*this);
}

Value Expr_UnaryOp::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	SeqPostHandler *pSeqPostHandlerChild = NULL;
	Value value = GetChild()->Exec2(env, sig, pSeqPostHandlerChild);
	if (sig.IsSignalled()) return Value::Null;
	Value result = _pOperator->EvalMapUnary(env, sig, value, _suffixFlag);
	if (sig.IsSignalled()) return Value::Null;
	if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, result)) return Value::Null;
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
	if (!_suffixFlag) {
		stream.Print(sig, _pOperator->GetSymbol()->GetName());
		if (sig.IsSignalled()) return false;
	}
	if (!GetChild()->GenerateScript(sig, stream, scriptStyle, nestLevel)) return false;
	if (_suffixFlag) {
		stream.Print(sig, _pOperator->GetSymbol()->GetName());
		if (sig.IsSignalled()) return false;
	}
	if (needParenthesisFlag) {
		stream.PutChar(sig, ')');
		if (sig.IsSignalled()) return false;
	}
	return true;
}

Expr_UnaryOp::SequenceEx::SequenceEx(Environment *pEnv) : Sequence(pEnv)
{
}

bool Expr_UnaryOp::SequenceEx::DoStep(Signal sig, Value &result)
{
	return false;
}

String Expr_UnaryOp::SequenceEx::ToString() const
{
	String str;
	str += "<sequence:expr_unaryop>";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_BinaryOp
//-----------------------------------------------------------------------------
bool Expr_BinaryOp::IsBinaryOp() const { return true; }

Expr *Expr_BinaryOp::Clone() const
{
	return new Expr_BinaryOp(*this);
}

Value Expr_BinaryOp::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	OpType opType = _pOperator->GetOpType();
	const Expr *pExprLeft = GetLeft();
	const Expr *pExprRight = GetRight();
	Value valueLeft, valueRight, result;
	if (opType == OPTYPE_OrOr) {
		SeqPostHandler *pSeqPostHandlerLeft = NULL;
		SeqPostHandler *pSeqPostHandlerRight = NULL;
		valueLeft = pExprLeft->Exec2(env, sig, pSeqPostHandlerLeft);
		if (sig.IsSignalled()) return Value::Null;
		if (!valueLeft.IsListOrIterator() && valueLeft.GetBoolean()) {
			result = valueLeft;
		} else {
			valueRight = pExprRight->Exec2(env, sig, pSeqPostHandlerRight);
			if (sig.IsSignalled()) return Value::Null;
			result = _pOperator->EvalMapBinary(env, sig, valueLeft, valueRight);
			if (sig.IsSignalled()) return Value::Null;
		}
	} else if (opType == OPTYPE_AndAnd) {
		SeqPostHandler *pSeqPostHandlerLeft = NULL;
		SeqPostHandler *pSeqPostHandlerRight = NULL;
		valueLeft = pExprLeft->Exec2(env, sig, pSeqPostHandlerLeft);
		if (sig.IsSignalled()) return Value::Null;
		if (!valueLeft.IsListOrIterator() && !valueLeft.GetBoolean()) {
			result = valueLeft;
		} else {
			valueRight = pExprRight->Exec2(env, sig, pSeqPostHandlerRight);
			if (sig.IsSignalled()) return Value::Null;
			result = _pOperator->EvalMapBinary(env, sig, valueLeft, valueRight);
			if (sig.IsSignalled()) return Value::Null;
		}
	} else {
		SeqPostHandler *pSeqPostHandlerLeft = NULL;
		SeqPostHandler *pSeqPostHandlerRight = NULL;
		valueLeft = pExprLeft->Exec2(env, sig, pSeqPostHandlerLeft);
		if (sig.IsSignalled()) return Value::Null;
		valueRight = pExprRight->Exec2(env, sig, pSeqPostHandlerRight);
		if (sig.IsSignalled()) return Value::Null;
		result = _pOperator->EvalMapBinary(env, sig, valueLeft, valueRight);
		if (sig.IsSignalled()) return Value::Null;
	}
	if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, result)) return Value::Null;
	return result;
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
	text += _pOperator->GetSymbol()->GetName();
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

Expr_BinaryOp::SequenceEx::SequenceEx(Environment *pEnv) : Sequence(pEnv)
{
}

bool Expr_BinaryOp::SequenceEx::DoStep(Signal sig, Value &result)
{
	return false;
}

String Expr_BinaryOp::SequenceEx::ToString() const
{
	String str;
	str += "<sequence:expr_binaryop>";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_Quote
//-----------------------------------------------------------------------------
bool Expr_Quote::IsQuote() const { return true; }

Expr *Expr_Quote::Clone() const
{
	return new Expr_Quote(*this);
}

const Expr *Expr_Quote::Unquote() const
{
	return GetChild();
}

Value Expr_Quote::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	Value result;
	if (GetChild()->IsSymbol()) {
		const Expr_Symbol *pExprSym =
						dynamic_cast<const Expr_Symbol *>(GetChild());
		result.SetSymbol(pExprSym->GetSymbol());
	} else {
		result = Value(new Object_expr(env, Expr::Reference(GetChild())));
	}
	if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, result)) return Value::Null;
	return result;
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

Expr_Quote::SequenceEx::SequenceEx(Environment *pEnv) : Sequence(pEnv)
{
}

bool Expr_Quote::SequenceEx::DoStep(Signal sig, Value &result)
{
	return false;
}

String Expr_Quote::SequenceEx::ToString() const
{
	String str;
	str += "<sequence:expr_quote>";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_Assign
//-----------------------------------------------------------------------------
bool Expr_Assign::IsAssign() const { return true; }

Expr *Expr_Assign::Clone() const
{
	return new Expr_Assign(*this);
}

Value Expr_Assign::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	Value result = Exec(env, sig, env, NULL, pSeqPostHandler);
	if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, result)) return Value::Null;
	return result;
}

Value Expr_Assign::Exec(Environment &env, Signal sig, Environment &envDst,
		const SymbolSet *pSymbolsAssignable, SeqPostHandler *pSeqPostHandler) const
{
	Value valueAssigned;
	const Expr *pExpr = GetLeft();
	bool funcAssignFlag = false;
	if (pExpr->IsCaller()) {
		if (_pOperatorToApply != NULL) {
			SetError(sig, ERR_SyntaxError, "invalid operation");
			return Value::Null;
		}
		Expr *pExprBody = Expr::Reference(GetRight()->Unquote());
		valueAssigned = Value(new Object_expr(env, pExprBody));
	} else {
		SeqPostHandler *pSeqPostHandlerRight = NULL;
		valueAssigned = GetRight()->Exec2(env, sig, pSeqPostHandlerRight);
		if (sig.IsSignalled()) return Value::Null;
		if (_pOperatorToApply != NULL) {
			SeqPostHandler *pSeqPostHandlerLeft = NULL;
			Value valueLeft = pExpr->Exec2(env, sig, pSeqPostHandlerLeft);
			if (sig.IsSignalled()) return Value::Null;
			valueAssigned = _pOperatorToApply->EvalMapBinary(env, sig, valueLeft, valueAssigned);
			if (sig.IsSignalled()) return Value::Null;
		}
	}
	return GetLeft()->Assign(envDst, sig, valueAssigned, pSymbolsAssignable, true);
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
		text += _pOperatorToApply->GetSymbol()->GetName();
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

Expr_Assign::SequenceEx::SequenceEx(Environment *pEnv) : Sequence(pEnv)
{
}

bool Expr_Assign::SequenceEx::DoStep(Signal sig, Value &result)
{
	return false;
}

String Expr_Assign::SequenceEx::ToString() const
{
	String str;
	str += "<sequence:expr>";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_Member
//-----------------------------------------------------------------------------
bool Expr_Member::IsMember() const { return true; }

Expr *Expr_Member::Clone() const
{
	return new Expr_Member(*this);
}

Value Expr_Member::DoExec(Environment &env, Signal sig, SeqPostHandler *pSeqPostHandler) const
{
	SeqPostHandler *pSeqPostHandlerLeft = NULL;
	// Expr_Caller::Exec(), Expr_Member::Exec() and Expr_Member::DoAssign()
	// correspond to method-calling, property-getting and property-setting.
	Value valueThis = GetLeft()->Exec2(env, sig, pSeqPostHandlerLeft);
	if (sig.IsSignalled()) return Value::Null;
	Fundamental *pFund = NULL;
	if (valueThis.IsPrimitive()) {
		pFund = env.LookupClass(valueThis.GetValueType());
	} else {
		pFund = valueThis.ExtractFundamental(sig);
		if (sig.IsSignalled()) return Value::Null;
	}
	Value result;
	Mode mode = GetMode();
	if (mode == MODE_Normal) {
		const Expr *pExprRight = GetRight();
		if (pExprRight->IsSymbol()) {
			SeqPostHandler *pSeqPostHandlerRight = NULL;
			const Expr_Symbol *pExprSymbol =
								dynamic_cast<const Expr_Symbol *>(pExprRight);
			result = pExprSymbol->Exec(*pFund, sig, valueThis, pSeqPostHandlerRight);
		} else {
			SeqPostHandler *pSeqPostHandlerRight = NULL;
			result = pExprRight->Exec2(*pFund, sig, pSeqPostHandlerRight);
		}
		if (result.Is_function()) {
			Object_function *pObjFunc =
				dynamic_cast<Object_function *>(Object_function::GetObject(result)->Clone());
			pObjFunc->SetThis(valueThis);
			result = Value(pObjFunc);
		}
	} else {
		if (valueThis.Is_list() && valueThis.GetList().empty()) {
			result = valueThis;
		} else {
			Iterator *pIterator = pFund->CreateIterator(sig);
			if (sig.IsSignalled()) return Value::Null;
			if (pIterator != NULL) {
				AutoPtr<Iterator> pIteratorMap(new Iterator_MemberMap(
							new Environment(env), sig, pIterator, Expr::Reference(GetRight())));
				if (mode == MODE_MapToIter) {
					result = Value(new Object_iterator(env, pIteratorMap.release()));
				} else {
					result = pIteratorMap->ToList(env, sig, false, false);
					if (sig.IsSignalled()) return Value::Null;
				}
			}
		}
	}
	if (pSeqPostHandler != NULL && !pSeqPostHandler->DoPost(sig, result)) return Value::Null;
	return result;
}

Value Expr_Member::DoAssign(Environment &env, Signal sig, Value &valueAssigned,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	// Expr_Caller::Exec(), Expr_Member::Exec() and Expr_Member::DoAssign()
	// correspond to method-calling, property-getting and property-setting.
	SeqPostHandler *pSeqPostHandlerLeft = NULL;
	Value valueThis = GetLeft()->Exec2(env, sig, pSeqPostHandlerLeft);
	if (sig.IsSignalled()) return Value::Null;
	Fundamental *pFund = valueThis.ExtractFundamental(sig);
	if (sig.IsSignalled()) return Value::Null;
	Mode mode = GetMode();
	if (mode == MODE_Normal) {
		return GetRight()->Assign(*pFund, sig, valueAssigned, pSymbolsAssignable, escalateFlag);
	}
	AutoPtr<Iterator> pIteratorThis(pFund->CreateIterator(sig));
	if (pIteratorThis.IsNull()) {
		if (sig.IsSignalled()) return Value::Null;
		return GetRight()->Assign(*pFund, sig, valueAssigned, pSymbolsAssignable, escalateFlag);
	}
	if (valueAssigned.Is_list() || valueAssigned.Is_iterator()) {
		AutoPtr<Iterator> pIteratorValue(valueAssigned.CreateIterator(sig));
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
			GetRight()->Assign(*pFundEach, sig, valueAssigned, pSymbolsAssignable, escalateFlag);
			if (sig.IsSignalled()) break;
		}
		if (sig.IsSignalled()) return Value::Null;
	}
	return valueAssigned;
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

Expr_Member::SequenceEx::SequenceEx(Environment *pEnv) : Sequence(pEnv)
{
}

bool Expr_Member::SequenceEx::DoStep(Signal sig, Value &result)
{
	return false;
}

String Expr_Member::SequenceEx::ToString() const
{
	String str;
	str += "<sequence:expr_member>";
	return str;
}

}
