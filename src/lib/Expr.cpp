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
		{ EXPRTYPE_Force,			"force",			},
		{ EXPRTYPE_Prefix,			"prefix",			},
		{ EXPRTYPE_Suffix,			"suffix",			},
		{ EXPRTYPE_BinaryOp,		"binaryop",			},
		{ EXPRTYPE_Assign,			"assign",			},
		{ EXPRTYPE_DictAssign,		"dictassign",		},
		{ EXPRTYPE_Member,			"member",			},
		{ EXPRTYPE_Root,			"root",				},
		{ EXPRTYPE_BlockParam,		"blockparam",		},
		{ EXPRTYPE_Block,			"block",			},
		{ EXPRTYPE_Lister,			"lister",			},
		{ EXPRTYPE_TemplateBlock,	"templateblock",	},
		{ EXPRTYPE_Indexer,			"indexer",			},
		{ EXPRTYPE_Caller,			"caller",			},
		{ EXPRTYPE_Value,			"value",			},
		{ EXPRTYPE_Symbol,			"symbol",			},
		{ EXPRTYPE_String,			"string",			},
		{ EXPRTYPE_TemplateString,	"templatestring",	},
	};
	for (int i = 0; i < NUMBEROF(tbl); i++) {
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
//        |                   `- Expr_TemplateBlock
//        +- Expr_Compound <--+- Expr_Indexer
//        |                   `- Expr_Caller
//        +- Expr_Value
//        +- Expr_Symbol
//        +- Expr_String
//        `- Expr_TemplateString
//-----------------------------------------------------------------------------
Expr::~Expr()
{
}

Expr *Expr::IncRef() const
{
	Expr *pExpr = const_cast<Expr *>(this);
	pExpr->_cntRef++;
	return pExpr;
}

const char *Expr::GetPathName() const
{
	return (_pExprParent == NULL)? NULL : _pExprParent->GetPathName();
}

bool Expr::ExecInArg(Environment &env, Signal sig,
					ValueList &valListArg, size_t &nElems, bool quoteFlag) const
{
	if (quoteFlag) {
		Value value;
		value.InitAsExpr(env, IncRef());
		valListArg.push_back(value);
		nElems = 1;
	} else if (IsSuffix()) {
		const Expr_Suffix *pExprSuffix = dynamic_cast<const Expr_Suffix *>(this);
		if (!pExprSuffix->GetSymbol()->IsIdentical(Gura_Symbol(Char_Multiply))) {
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
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return false;
		}
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
		pExprBlock = dynamic_cast<Expr_Block *>(IncRef());
	} else {
		pExprBlock = new Expr_Block();
		pExprBlock->AddExpr(IncRef());
	}
	Value result;
	AutoPtr<FunctionCustom> pFunc(FunctionCustom::CreateBlockFunc(env, sig,
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

bool Expr::NeedParenthesis(const Function &funcOuter,
									const Function &func, bool rightFlag)
{
	Parser::Precedence prec = Parser::LookupPrec(
									funcOuter.GetElemType(), func.GetElemType());
	if (prec == Parser::PREC_EQ || funcOuter.GetElemType() == func.GetElemType()) {
		return rightFlag;
	} else if (prec == Parser::PREC_GT) {
		return true;
	} else {
		return false;
	}
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
			dynamic_cast<const Expr_UnaryOp *>(this)->GetFunction().IsNeg();
}

bool Expr::IsOperatorMultiply() const
{
	return IsBinaryOp() &&
		dynamic_cast<const Expr_BinaryOp *>(this)->GetFunction().IsMultiply();
}

bool Expr::IsOperatorPower() const
{
	return IsBinaryOp() &&
		dynamic_cast<const Expr_BinaryOp *>(this)->GetFunction().IsPower();
}

bool Expr::IsOperatorSequence() const
{
	return IsBinaryOp() &&
		dynamic_cast<const Expr_BinaryOp *>(this)->GetFunction().IsSequence();
}

bool Expr::IsUnary() const			{ return false; }
bool Expr::IsQuote() const			{ return false; }
bool Expr::IsForce() const			{ return false; }
bool Expr::IsPrefix() const			{ return false; }
bool Expr::IsSuffix() const			{ return false; }
bool Expr::IsUnaryOp() const		{ return false; }

bool Expr::IsBinary() const			{ return false; }
bool Expr::IsAssign() const			{ return false; }
bool Expr::IsDictAssign() const		{ return false; }
bool Expr::IsBinaryOp() const		{ return false; }
bool Expr::IsMember() const			{ return false; }

bool Expr::IsContainer() const		{ return false; }
bool Expr::IsRoot() const			{ return false; }
bool Expr::IsBlockParam() const		{ return false; }
bool Expr::IsBlock() const			{ return false; }
bool Expr::IsLister() const			{ return false; }
bool Expr::IsTemplateBlock() const	{ return false; }

bool Expr::IsCompound() const		{ return false; }
bool Expr::IsIndexer() const		{ return false; }
bool Expr::IsCaller() const			{ return false; }

bool Expr::IsValue() const			{ return false; }
bool Expr::IsSymbol() const			{ return false; }
bool Expr::IsString() const			{ return false; }
bool Expr::IsTemplateString() const	{ return false; }

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

ICallable *Expr::LookupCallable(Environment &env, Signal sig) const
{
	return NULL;
}

bool Expr::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	return false;
}

bool Expr::Serialize(Environment &env, Signal sig, Stream &stream, const Expr *pExpr)
{
	if (pExpr == NULL) {
		unsigned char exprType = static_cast<unsigned char>(EXPRTYPE_None);
		return stream.Write(sig, &exprType, 1) == 1;
	}
	unsigned char exprType = static_cast<unsigned char>(pExpr->GetType());
	if (stream.Write(sig, &exprType, 1) < 1) return false;
	return pExpr->DoSerialize(env, sig, stream);
}

bool Expr::Deserialize(Environment &env, Signal sig, Stream &stream, Expr **ppExpr, bool mustBeValidFlag)
{
	*ppExpr = NULL;
	unsigned char exprType = 0x00;
	if (stream.Read(sig, &exprType, 1) < 1) return false;
	AutoPtr<Expr> pExpr;
	//::printf("exprType = 0x%02x\n", exprType);
	switch (exprType) {
	case EXPRTYPE_None:
		if (mustBeValidFlag) {
			sig.SetError(ERR_IOError, "invalid expr in the stream");
			return false;
		}
		return true;
	case EXPRTYPE_UnaryOp:
		pExpr.reset(new Expr_UnaryOp(NULL, NULL, false));
		break;
	case EXPRTYPE_Quote:
		pExpr.reset(new Expr_Quote(NULL));
		break;
	case EXPRTYPE_Force:
		pExpr.reset(new Expr_Force(NULL));
		break;
	case EXPRTYPE_Prefix:
		pExpr.reset(new Expr_Prefix(NULL, NULL));
		break;
	case EXPRTYPE_Suffix:
		pExpr.reset(new Expr_Suffix(NULL, NULL));
		break;
	case EXPRTYPE_BinaryOp:
		pExpr.reset(new Expr_BinaryOp(NULL, NULL, NULL));
		break;
	case EXPRTYPE_Assign:
		pExpr.reset(new Expr_Assign(NULL, NULL, NULL));
		break;
	case EXPRTYPE_DictAssign:
		pExpr.reset(new Expr_DictAssign(NULL, NULL));
		break;
	case EXPRTYPE_Member:
		pExpr.reset(new Expr_Member(NULL, NULL));
		break;
	case EXPRTYPE_Root:
		pExpr.reset(new Expr_Root(""));
		break;
	case EXPRTYPE_BlockParam:
		pExpr.reset(new Expr_BlockParam());
		break;
	case EXPRTYPE_Block:
		pExpr.reset(new Expr_Block());
		break;
	case EXPRTYPE_Lister:
		pExpr.reset(new Expr_Lister());
		break;
	case EXPRTYPE_TemplateBlock:
		sig.SetError(ERR_IOError, "can't serialize template block");
		return false;
	case EXPRTYPE_Indexer:
		pExpr.reset(new Expr_Indexer(NULL, NULL));
		break;
	case EXPRTYPE_Caller:
		pExpr.reset(new Expr_Caller(NULL, NULL, NULL));
		break;
	case EXPRTYPE_Value:
		pExpr.reset(new Expr_Value(Value::Null));
		break;
	case EXPRTYPE_Symbol:
		pExpr.reset(new Expr_Symbol(Gura_Symbol(nil)));
		break;
	case EXPRTYPE_String:
		pExpr.reset(new Expr_String(""));
		break;
	case EXPRTYPE_TemplateString:
		sig.SetError(ERR_IOError, "can't serialize template string");
		return false;
	default:
		sig.SetError(ERR_IOError, "unknown expr type %d", exprType);
		return false;
	}
	if (pExpr->DoDeserialize(env, sig, stream)) {
		*ppExpr = pExpr.release();
		return true;
	}
	return false;
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
// Expr_Unary
//-----------------------------------------------------------------------------
bool Expr_Unary::IsUnary() const { return true; }

Expr_Unary::Expr_Unary(ExprType exprType, Expr *pExprChild) : Expr(exprType)
{
	_exprOwner.reserve(1);
	_exprOwner.push_back(pExprChild);
	if (pExprChild != NULL) _exprOwner.SetParent(this);
}

Expr_Unary::Expr_Unary(const Expr_Unary &expr) : Expr(expr), _exprOwner(expr._exprOwner)
{
	_exprOwner.SetParent(this);
}

Expr_Unary::~Expr_Unary()
{
	_exprOwner.SetParent(GetParent());
}

Expr *Expr_Unary::IncRef() const
{
	GetChild()->IncRef();
	return Expr::IncRef();
}

void Expr_Unary::Accept(ExprVisitor &visitor) const
{
	if (visitor.Visit(this)) {
		GetChild()->Accept(visitor);
	}
}

bool Expr_Unary::IsParentOf(const Expr *pExpr) const
{
	return _exprOwner.IsContained(pExpr);
}

bool Expr_Unary::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	return _exprOwner.Serialize(env, sig, stream);
}

bool Expr_Unary::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!_exprOwner.Deserialize(env, sig, stream)) return false;
	_exprOwner.SetParent(this);
	return true;
}

//-----------------------------------------------------------------------------
// Expr_Binary
//-----------------------------------------------------------------------------
bool Expr_Binary::IsBinary() const { return true; }

Expr_Binary::Expr_Binary(ExprType exprType, Expr *pExprLeft, Expr *pExprRight) : Expr(exprType)
{
	_exprOwner.reserve(2);
	_exprOwner.push_back(pExprLeft); _exprOwner.push_back(pExprRight);
	if (pExprLeft != NULL && pExprRight != NULL) _exprOwner.SetParent(this);
}

Expr_Binary::Expr_Binary(const Expr_Binary &expr) : Expr(expr), _exprOwner(expr._exprOwner)
{
	_exprOwner.SetParent(this);
}

Expr_Binary::~Expr_Binary()
{
	_exprOwner.SetParent(GetParent());
}

Expr *Expr_Binary::IncRef() const
{
	GetLeft()->IncRef();
	GetRight()->IncRef();
	return Expr::IncRef();
}

void Expr_Binary::Accept(ExprVisitor &visitor) const
{
	if (visitor.Visit(this)) {
		GetLeft()->Accept(visitor);
		GetRight()->Accept(visitor);
	}
}

bool Expr_Binary::IsParentOf(const Expr *pExpr) const
{
	return _exprOwner.IsContained(pExpr);
}

bool Expr_Binary::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	return _exprOwner.Serialize(env, sig, stream);
}

bool Expr_Binary::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!_exprOwner.Deserialize(env, sig, stream)) return false;
	_exprOwner.SetParent(this);
	return true;
}

//-----------------------------------------------------------------------------
// Expr_Container
//-----------------------------------------------------------------------------
bool Expr_Container::IsContainer() const { return true; }

Expr_Container::Expr_Container(const Expr_Container &expr) : Expr(expr), _exprOwner(expr._exprOwner)
{
	foreach (ExprOwner, ppExpr, _exprOwner) (*ppExpr)->SetParent(this);
}

Expr_Container::~Expr_Container()
{
	_exprOwner.SetParent(GetParent());
}

Expr *Expr_Container::IncRef() const
{
	_exprOwner.IncRef();
	return Expr::IncRef();
}

void Expr_Container::Accept(ExprVisitor &visitor) const
{
	if (visitor.Visit(this)) {
		_exprOwner.Accept(visitor);
	}
}

bool Expr_Container::IsParentOf(const Expr *pExpr) const
{
	return _exprOwner.IsContained(pExpr);
}

bool Expr_Container::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	return _exprOwner.Serialize(env, sig, stream);
}

bool Expr_Container::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	return _exprOwner.Deserialize(env, sig, stream);
}

//-----------------------------------------------------------------------------
// Expr_Value
//-----------------------------------------------------------------------------
bool Expr_Value::IsValue() const { return true; }

Expr_Value::~Expr_Value()
{
}

Expr *Expr_Value::IncRef() const
{
	return Expr::IncRef();
}

Expr *Expr_Value::Clone() const
{
	return new Expr_Value(*this);
}

Value Expr_Value::Exec(Environment &env, Signal sig) const
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

bool Expr_Value::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	return Value::Serialize(env, sig, stream, _value);
}

bool Expr_Value::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	return Value::Deserialize(env, sig, stream, _value, false);
}

String Expr_Value::ToString() const
{
	Signal sig;
	String str = _value.ToString(sig);
	if (_value.IsNumberOrComplex() && str[0] == '-') {
		str = "(" + str + ")";
	}
	return str;
}

//-----------------------------------------------------------------------------
// Expr_String
//-----------------------------------------------------------------------------
bool Expr_String::IsString() const { return true; }

Expr_String::~Expr_String()
{
}

Expr *Expr_String::IncRef() const
{
	return Expr::IncRef();
}

Expr *Expr_String::Clone() const
{
	return new Expr_String(*this);
}

Value Expr_String::Exec(Environment &env, Signal sig) const
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

bool Expr_String::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	return stream.SerializeString(sig, _str.c_str());
}

bool Expr_String::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	return stream.DeserializeString(sig, _str);
}

String Expr_String::ToString() const
{
	return MakeQuotedString(_str.c_str());
}

//-----------------------------------------------------------------------------
// Expr_TemplateString
//-----------------------------------------------------------------------------
bool Expr_TemplateString::IsTemplateString() const { return true; }

Expr_TemplateString::~Expr_TemplateString()
{
}

Expr *Expr_TemplateString::IncRef() const
{
	return Expr::IncRef();
}

Expr *Expr_TemplateString::Clone() const
{
	return new Expr_TemplateString(*this);
}

Value Expr_TemplateString::Exec(Environment &env, Signal sig) const
{
	_streamDst.Print(sig, _str.c_str());
	return Value::Null;
}

void Expr_TemplateString::Accept(ExprVisitor &visitor) const
{
	visitor.Visit(this);
}

bool Expr_TemplateString::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "TemplateString");
	return true;
}

bool Expr_TemplateString::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	sig.SetError(ERR_IOError, "can't serialize template string");
	return false;
}

bool Expr_TemplateString::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	sig.SetError(ERR_IOError, "can't deserialize template string");
	return false;
}

String Expr_TemplateString::ToString() const
{
	return MakeQuotedString(_str.c_str());
}

//-----------------------------------------------------------------------------
// Expr_Symbol
//-----------------------------------------------------------------------------
bool Expr_Symbol::IsSymbol() const { return true; }

Expr_Symbol::~Expr_Symbol()
{
}

Expr *Expr_Symbol::IncRef() const
{
	return Expr::IncRef();
}

Expr *Expr_Symbol::Clone() const
{
	return new Expr_Symbol(*this);
}

ICallable *Expr_Symbol::LookupCallable(Environment &env, Signal sig) const
{
	Value rtn = env.GetProp(sig, GetSymbol(), GetAttrs());
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return NULL;
	}
	return rtn.GetObject();
}

Value Expr_Symbol::Exec(Environment &env, Signal sig) const
{
	Value rtn = env.GetProp(sig, GetSymbol(), GetAttrs());
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
	return rtn;
}

Value Expr_Symbol::DoAssign(Environment &env, Signal sig, Value &value,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	bool evaluatedFlag = false;
	const SymbolSet &attrs = SymbolSet::Null;
	Value result = env.DoSetProp(sig, GetSymbol(), value, attrs, evaluatedFlag);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
	if (evaluatedFlag) return result;
	if (pSymbolsAssignable != NULL && !pSymbolsAssignable->IsSet(GetSymbol())) {
		SetError_NotAssignableSymbol(sig, GetSymbol());
		return Value::Null;
	}
	if (_attrs.IsSet(Gura_Symbol(extern_))) {
		escalateFlag = true;
		if (env.LookupValue(GetSymbol(), true) == NULL) {
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
	if (value.IsModule()) {
		Module *pModule = value.GetModule();
		if (pModule->IsAnonymous()) {
			pModule->SetSymbol(GetSymbol());
		}
	} else if (value.IsClass() && value.GetClass()->IsCustom()) {
		CustomClass *pClass = dynamic_cast<CustomClass *>(value.GetClass());
		if (pClass->IsAnonymous()) {
			ValueTypeInfo *pValueTypeInfo =
								ValueTypePool::GetInstance()->Add(GetSymbol());
			pValueTypeInfo->SetClass(Class::Reference(pClass));
			env.AssignValueType(pValueTypeInfo);
			Function *pFunc = pClass->Prepare(env, sig);
			if (pFunc == NULL) return Value::Null;
			value = Value(env, pFunc, Value::Null);
		}
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
	}
	if (valTypeCast != VTYPE_any) {
		AutoPtr<Declaration> pDecl(
				new Declaration(GetSymbol(), valTypeCast, OCCUR_Once, 0, NULL));
		pDecl->ValidateAndCast(env, sig, value);
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
	}
	env.AssignValue(GetSymbol(), value, escalateFlag);
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

bool Expr_Symbol::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!stream.SerializeSymbol(sig, _pSymbol)) return false;
	if (!stream.SerializeSymbolSet(sig, _attrs)) return false;
	if (!stream.SerializeSymbolSet(sig, _attrsOpt)) return false;
	if (!stream.SerializeSymbolList(sig, _attrFront)) return false;
	return true;
}

bool Expr_Symbol::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!stream.DeserializeSymbol(sig, &_pSymbol)) return false;
	if (!stream.DeserializeSymbolSet(sig, _attrs)) return false;
	if (!stream.DeserializeSymbolSet(sig, _attrsOpt)) return false;
	if (!stream.DeserializeSymbolList(sig, _attrFront)) return false;
	return true;
}

String Expr_Symbol::ToString() const
{
	return GetSymbol()->GetName();
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

Value Expr_Root::Exec(Environment &env, Signal sig) const
{
	return _exprOwner.ExecInRoot(env, sig);
}

bool Expr_Root::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	return _exprOwner.GenerateCode(env, sig, stream);
}

bool Expr_Root::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Container::DoSerialize(env, sig, stream)) return false;
	if (!stream.SerializeString(sig, _pathName.c_str())) return false;
	return true;
}

bool Expr_Root::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Container::DoDeserialize(env, sig, stream)) return false;
	if (!stream.DeserializeString(sig, _pathName)) return false;
	return true;
}

String Expr_Root::ToString() const
{
	return GetExprOwner().ToString();
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

Value Expr_Block::Exec(Environment &env, Signal sig) const
{
	if (!_pExprBlockParam.IsNull()) {} // needs to do something here?
	if (env.IsType(ENVTYPE_lister)) {
		return _exprOwner.ExecForList(env, sig, false, true);
	}
	return _exprOwner.Exec(env, sig, true);
}

Expr *Expr_Block::MathDiff(Environment &env, Signal sig, const Symbol *pSymbol) const
{
	return (_exprOwner.size() == 1)?
			_exprOwner.front()->MathDiff(env, sig, pSymbol) :
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

bool Expr_Block::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Container::DoSerialize(env, sig, stream)) return false;
	if (!Expr::Serialize(env, sig, stream, _pExprBlockParam.get())) return false;
	return true;
}

bool Expr_Block::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Container::DoDeserialize(env, sig, stream)) return false;
	Expr *pExprBlockParam = NULL;
	if (!Expr::Deserialize(env, sig, stream, &pExprBlockParam, false)) return false;
	if (pExprBlockParam != NULL && !pExprBlockParam->IsBlockParam()) {
		sig.SetError(ERR_IOError, "block parameter is expected in the stream");
		return false;
	}
	_pExprBlockParam.reset(dynamic_cast<Expr_BlockParam *>(pExprBlockParam));
	return true;
}

String Expr_Block::ToString() const
{
	String str;
	str += "{";
	if (!_pExprBlockParam.IsNull()) {
		str += _pExprBlockParam->ToString();
	}
	str += " ";
	str += GetExprOwner().ToString();
	if (!GetExprOwner().empty()) str += " ";
	str += "}";
	return str;
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

Value Expr_BlockParam::Exec(Environment &env, Signal sig) const
{
	return _exprOwner.Exec(env, sig, false);
}

bool Expr_BlockParam::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "BlockParam");
	return true;
}

bool Expr_BlockParam::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Container::DoSerialize(env, sig, stream)) return false;
	return true;
}

bool Expr_BlockParam::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Container::DoDeserialize(env, sig, stream)) return false;
	return true;
}

String Expr_BlockParam::ToString() const
{
	String str;
	str += "|";
	str += GetExprOwner().ToString();
	str += "|";
	return str;
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

Value Expr_Lister::Exec(Environment &env, Signal sig) const
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	foreach_const (ExprOwner, ppExpr, _exprOwner) {
		const Expr *pExpr = *ppExpr;
		Value value = pExpr->Exec(env, sig);
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
		if (value.IsIterator()) {
			AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
			if (sig.IsSignalled()) {
				sig.AddExprCause(this);
				return Value::Null;
			}
			if (pIterator->IsInfinite()) {
				Iterator::SetError_InfiniteNotAllowed(sig);
				sig.AddExprCause(this);
				return Value::Null;
			}
			Value value;
			while (pIterator->Next(env, sig, value)) {
				valList.push_back(value);
			}
			if (sig.IsSignalled()) {
				sig.AddExprCause(this);
				return Value::Null;
			}
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
				pExpr->DoAssign(env, sig, value, pSymbolsAssignable, escalateFlag);
				if (sig.IsSignalled()) {
					sig.AddExprCause(this);
					return Value::Null;
				}
				pValList->push_back(valueElem);
			} else {
				pExpr->DoAssign(env, sig, valueElem, pSymbolsAssignable, escalateFlag);
				if (sig.IsSignalled()) {
					sig.AddExprCause(this);
					return Value::Null;
				}
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
				pExpr->DoAssign(env, sig, value, pSymbolsAssignable, escalateFlag);
				if (sig.IsSignalled()) {
					sig.AddExprCause(this);
					return Value::Null;
				}
			} else if (occurPattern == OCCUR_Once || occurPattern == OCCUR_OnceOrMore) {
				SetError(sig, ERR_ValueError,
						"not enough value to initialize arrayed variables");
				return Value::Null;
			}
		}
	} else {
		foreach_const (ExprList, ppExpr, exprList) {
			const Expr *pExpr = *ppExpr;
			pExpr->DoAssign(env, sig, value, pSymbolsAssignable, escalateFlag);
			if (sig.IsSignalled()) {
				sig.AddExprCause(this);
				return Value::Null;
			}
		}
	}
	return value;
}

bool Expr_Lister::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Lister");
	return true;
}

bool Expr_Lister::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Container::DoSerialize(env, sig, stream)) return false;
	return true;
}

bool Expr_Lister::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Container::DoDeserialize(env, sig, stream)) return false;
	return true;
}

String Expr_Lister::ToString() const
{
	String str;
	str += "[";
	str += GetExprOwner().ToString();
	str += "]";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_TemplateBlock
//-----------------------------------------------------------------------------
bool Expr_TemplateBlock::IsTemplateBlock() const { return true; }

Expr_TemplateBlock::~Expr_TemplateBlock()
{
}

Expr *Expr_TemplateBlock::Clone() const
{
	return new Expr_TemplateBlock(*this);
}

Value Expr_TemplateBlock::Exec(Environment &env, Signal sig) const
{
	if (_exprOwner.empty()) {
		//stat = STAT_SkipEOL;
		return Value::Null;
	}
	Value value = _exprOwner.Exec(env, sig, true);
	if (sig.IsSignalled()) {
		return Value::Null;
	} else if (value.IsInvalid()) {
		//stat = STAT_SkipEOL;
		return Value::Null;
	}
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
	return Value::Null;
}

bool Expr_TemplateBlock::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "TemplateBlock");
	return true;
}

bool Expr_TemplateBlock::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	sig.SetError(ERR_IOError, "can't serialize template string");
	return false;
}

bool Expr_TemplateBlock::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	sig.SetError(ERR_IOError, "can't deserialize template string");
	return false;
}

String Expr_TemplateBlock::ToString() const
{
	String str;
	str += "[";
	str += GetExprOwner().ToString();
	str += "]";
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

Expr *Expr_Compound::IncRef() const
{
	if (!_pExprCar.IsNull()) _pExprCar->IncRef();
	if (!_pExprLister.IsNull()) _pExprLister->IncRef();
	return Expr::IncRef();
}

bool Expr_Compound::IsParentOf(const Expr *pExpr) const
{
	return _pExprCar.get() == pExpr || _pExprLister.get() == pExpr ||
			(!_pExprCar.IsNull() && _pExprCar->IsParentOf(pExpr)) ||
			(!_pExprLister.IsNull() && _pExprLister->IsParentOf(pExpr));
}

bool Expr_Compound::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr::Serialize(env, sig, stream, _pExprCar.get())) return false;
	if (!Expr::Serialize(env, sig, stream, _pExprLister.get())) return false;
	return true;
}

bool Expr_Compound::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	Expr *pExprCar = NULL, *pExprLister = NULL;
	if (!Expr::Deserialize(env, sig, stream, &pExprCar, true)) return false;
	if (!Expr::Deserialize(env, sig, stream, &pExprLister, true)) return false;
	if (!pExprLister->IsLister()) {
		sig.SetError(ERR_IOError, "lister is expected in the stream");
		return false;
	}
	_pExprCar.reset(pExprCar);
	_pExprLister.reset(dynamic_cast<Expr_Lister *>(pExprLister));
	_pExprCar->SetParent(this);
	_pExprLister->SetParent(this);
	return true;
}

//-----------------------------------------------------------------------------
// Expr_Indexer
//-----------------------------------------------------------------------------
bool Expr_Indexer::IsIndexer() const { return true; }

Expr_Indexer::~Expr_Indexer()
{
}

Expr *Expr_Indexer::IncRef() const
{
	return Expr_Compound::IncRef();
}

Expr *Expr_Indexer::Clone() const
{
	return new Expr_Indexer(*this);
}

Value Expr_Indexer::Exec(Environment &env, Signal sig) const
{
	Value valueCar = GetCar()->Exec(env, sig);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
	const ExprList &exprList = GetLister()->GetExprOwner();
	Object &objCar = *valueCar.GetObject();
	if (exprList.empty()) {
		return objCar.EmptyIndexGet(env, sig);
	}
	Value valueIdx = exprList.ExecForList(env, sig, true, false);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
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
				Value valueIdxEach;
				while (pIteratorIdx->Next(env, sig, valueIdxEach)) {
					Value value = objCar.IndexGet(env, sig, valueIdxEach);
					if (sig.IsSignalled()) {
						if (sig.GetErrorType() == ERR_IndexError &&
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
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
	return result;
}

Value Expr_Indexer::DoAssign(Environment &env, Signal sig, Value &value,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	Value valueDst = GetCar()->Exec(env, sig);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
	if (!valueDst.IsObject()) {
		SetError(sig, ERR_ValueError, "object is expected as l-value of indexer");
		return Value::Null;
	}
	const ExprList &exprList = GetLister()->GetExprOwner();
	Object &objDst = *valueDst.GetObject();
	if (exprList.empty()) {
		objDst.EmptyIndexSet(env, sig, value);
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
		return value;
	}
	if (exprList.size() == 1) {
		// obj[idx] = v / obj[idx] = [v, v, ..]
		Value valueIdx = exprList.front()->Exec(env, sig);
		if (sig.IsSignalled()) goto done;
		if (valueIdx.IsList() || valueIdx.IsIterator()) {
			Iterator *pIteratorIdx = valueIdx.CreateIterator(sig);
			if (sig.IsSignalled()) goto done;
			if (value.IsList() || value.IsIterator()) {
				Iterator *pIterator = value.CreateIterator(sig);
				if (sig.IsSignalled()) goto done;
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
		if (sig.IsSignalled()) goto done;
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
			if (sig.IsSignalled()) goto done;
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
done:
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
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

bool Expr_Indexer::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Compound::DoSerialize(env, sig, stream)) return false;
	return true;
}

bool Expr_Indexer::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Compound::DoDeserialize(env, sig, stream)) return false;
	return true;
}

String Expr_Indexer::ToString() const
{
	String str;
	str += GetCar()->ToString();
	str += "[";
	str += GetLister()->GetExprOwner().ToString();
	str += "]";
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

Expr *Expr_Caller::IncRef() const
{
	if (!_pExprBlock.IsNull()) _pExprBlock->IncRef();
	if (!_pExprTrailer.IsNull()) _pExprTrailer->IncRef();
	return Expr_Compound::IncRef();
}

Expr *Expr_Caller::Clone() const
{
	return new Expr_Caller(*this);
}

ICallable *Expr_Caller::LookupCallable(Environment &env, Signal sig) const
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

Value Expr_Caller::Exec(Environment &env, Signal sig) const
{
	Value result;
	const Function *pFuncLeader = NULL;
	for (const Expr_Caller *pExprCaller = this; pExprCaller != NULL;
									pExprCaller = pExprCaller->GetTrailer()) {
		result = pExprCaller->DoExec(env, sig, &pFuncLeader);
		if (pFuncLeader == NULL) break;
	}
	// if there's an error suspended by try() function, it would be resumed below.
	// otherwise, nothing would happen and any error would be kept intact.
	sig.ResumeError();
	return result;
}

Value Expr_Caller::DoExec(Environment &env, Signal sig,
									const Function **ppFuncLeader) const
{
	// Expr_Caller::Exec(), Expr_Member::Exec() and Expr_Member::DoAssign()
	// correspond to method-calling, property-getting and property-setting.
	if (!_pExprCar->IsMember()) {
		Value valueCar = _pExprCar->Exec(env, sig);
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
		ICallable *pCallable = valueCar.GetObject();
		if (pCallable == NULL) {
			SetError(sig, ERR_TypeError, "object is not callable");
			return Value::Null;
		}
		return pCallable->Call(env, sig, Value::Null, NULL, false,
									this, GetExprOwner(), ppFuncLeader);
	}
	const Expr_Member *pExprMember = dynamic_cast<const Expr_Member *>(GetCar());
	Value valueThis = pExprMember->GetLeft()->Exec(env, sig);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
	if (valueThis.IsInvalid()) return valueThis;
	Expr_Member::Mode mode = pExprMember->GetMode();
	if (mode != Expr_Member::MODE_Normal) {
		if (valueThis.IsList() && valueThis.GetList().empty()) {
			return valueThis;
		}
		Fundamental *pFund = valueThis.ExtractFundamental(sig);
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
		Iterator *pIteratorThis = pFund->CreateIterator(sig);
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
		if (pIteratorThis == NULL) {
			// nothing to do
		} else if (mode == Expr_Member::MODE_MapAlong) {
			Value valueThisEach;
			if (!pIteratorThis->Next(env, sig, valueThisEach)) return Value::Null;
			return EvalEach(env, sig, valueThisEach,
						pIteratorThis, valueThis.IsList(), ppFuncLeader);
		} else {
			AutoPtr<Iterator> pIteratorMap(new Iterator_MethodMap(env, sig,
						pIteratorThis, dynamic_cast<Expr_Caller *>(IncRef())));
			if (mode == Expr_Member::MODE_MapToIter) {
				return Value(env, pIteratorMap.release());
			}
			Value result = pIteratorMap->ToList(env, sig, true, false);
			if (sig.IsSignalled()) {
				sig.AddExprCause(this);
				return Value::Null;
			}
			return result;
		}
	}
	return EvalEach(env, sig, valueThis, NULL, false, ppFuncLeader);
}

Value Expr_Caller::EvalEach(Environment &env, Signal sig, const Value &valueThis,
	Iterator *pIteratorThis, bool listThisFlag, const Function **ppFuncLeader) const
{
	const Expr_Member *pExprMember = dynamic_cast<const Expr_Member *>(GetCar());
	const Expr *pExprRight = pExprMember->GetRight();
	Value valueCar;
	ICallable *pCallable = NULL;
	Fundamental *pFund = NULL;
	if (valueThis.IsPrimitive() || valueThis.GetTinyBuffFlag()) {
		pFund = env.LookupClass(valueThis.GetType());
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
		//*** WATCH THIS PART ***
		int cntSuperSkip = 0;
		if (pFund->IsModule()) {
			Environment envLocal(pFund, ENVTYPE_member);
			valueCar = pExprRight->Exec(envLocal, sig);
		} else if ((cntSuperSkip = valueThis.GetSuperSkipCount()) > 0) {
			Environment envLocal(pFund, pFund->GetEnvType());
			envLocal.SetSuperSkipCount(cntSuperSkip);
			valueCar = pExprRight->Exec(envLocal, sig);
		} else {
			valueCar = pExprRight->Exec(*pFund, sig);
		}
		//*** WATCH THIS PART ***
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
								this, GetExprOwner(), ppFuncLeader);
}

Value Expr_Caller::DoAssign(Environment &env, Signal sig, Value &value,
					const SymbolSet *pSymbolsAssignable, bool escalateFlag) const
{
	if (!value.IsExpr()) {
		SetError(sig, ERR_SyntaxError, "invalid function expression");
		return Value::Null;
	}
	Expr *pExprBody = value.GetExpr()->IncRef();
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
	Args args(GetExprOwner(), Value::Null, NULL, false,
								NULL, GetAttrs(), GetAttrsOpt(), GetBlock());
	if (!pFunc->CustomDeclare(env, sig, SymbolSet::Null, args)) {
		sig.AddExprCause(this);
		Function::Delete(pFunc);
		return Value::Null;
	}
	Value valueFunc(env, pFunc, Value::Null);
	GetCar()->DoAssign(env, sig, valueFunc, pSymbolsAssignable, escalateFlag);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
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
	return Func_Multiply::OptimizedExpr(env, sig, pExprFuncDiff, pExprArgDiff);
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

bool Expr_Caller::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Compound::DoSerialize(env, sig, stream)) return false;
	if (!Expr::Serialize(env, sig, stream, _pExprBlock.get())) return false;
	if (!Expr::Serialize(env, sig, stream, _pExprTrailer.get())) return false;
	if (!stream.SerializeSymbolSet(sig, _attrs)) return false;
	if (!stream.SerializeSymbolSet(sig, _attrsOpt)) return false;
	if (!stream.SerializeSymbolList(sig, _attrFront)) return false;
	return true;
}

bool Expr_Caller::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Compound::DoDeserialize(env, sig, stream)) return false;
	Expr *pExprBlock = NULL, *pExprTrailer = NULL;
	if (!Expr::Deserialize(env, sig, stream, &pExprBlock, false)) return false;
	if (!Expr::Deserialize(env, sig, stream, &pExprTrailer, false)) return false;
	if (pExprBlock != NULL && !pExprBlock->IsBlock()) {
		sig.SetError(ERR_IOError, "block is expected in the stream");
		return false;
	}
	if (pExprTrailer != NULL && !pExprTrailer->IsCaller()) {
		sig.SetError(ERR_IOError, "caller is expected in the stream");
		return false;
	}
	_pExprBlock.reset(dynamic_cast<Expr_Block *>(pExprBlock));
	_pExprTrailer.reset(dynamic_cast<Expr_Caller *>(pExprTrailer));
	if (!stream.DeserializeSymbolSet(sig, _attrs)) return false;
	if (!stream.DeserializeSymbolSet(sig, _attrsOpt)) return false;
	if (!stream.DeserializeSymbolList(sig, _attrFront)) return false;
	return true;
}

String Expr_Caller::ToString() const
{
	String str;
	str += _pExprCar->ToString();
	bool argListFlag = !GetExprOwner().empty() ||
									!_attrs.empty() || _pExprBlock.IsNull();
	if (_pExprCar->IsSymbol()) {
		const Symbol *pSymbol = dynamic_cast<const Expr_Symbol *>(GetCar())->GetSymbol();
		if (pSymbol->IsFlowControlSymbol() && argListFlag) {
			str += " ";
		}
	}
	if (argListFlag) {
		str += "(";
		str += GetExprOwner().ToString();
		str += ")";
	}
	foreach_const (SymbolSet, ppSymbol, _attrs) {
		const Symbol *pSymbol = *ppSymbol;
		str += ":";
		str += pSymbol->GetName();
	}
	if (!_pExprBlock.IsNull()) {
		str += " ";
		str += _pExprBlock->ToString();
	}
	if (!_pExprTrailer.IsNull()) {
		str += " ";
		str += _pExprTrailer->ToString();
	}
	return str;
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

Value Expr_UnaryOp::Exec(Environment &env, Signal sig) const
{
	Args args(GetExprOwner());
	Value result = _pFunc->EvalExpr(env, sig, args);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
	return result;
}

Expr *Expr_UnaryOp::MathDiff(Environment &env, Signal sig, const Symbol *pSymbol) const
{
	return _pFunc->DiffUnary(env, sig, GetChild(), pSymbol);
}

Expr *Expr_UnaryOp::MathOptimize(Environment &env, Signal sig) const
{
	Expr *pExprOpt = GetChild()->MathOptimize(env, sig);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return NULL;
	}
	return _pFunc->OptimizeUnary(env, sig, pExprOpt);
}

bool Expr_UnaryOp::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "UnaryOp");
	return true;
}

bool Expr_UnaryOp::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Unary::DoSerialize(env, sig, stream)) return false;
	unsigned char opType = static_cast<unsigned char>(_pFunc->GetOpType());
	if (!stream.SerializeUChar(sig, opType)) return false;
	return true;
}

bool Expr_UnaryOp::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Unary::DoDeserialize(env, sig, stream)) return false;
	unsigned char opTypeRaw = 0x00;
	if (!stream.DeserializeUChar(sig, opTypeRaw)) return false;
	OpType opType = static_cast<OpType>(opTypeRaw);
	const Function *pFunc = env.GetOpFuncWithCheck(opType);
	if (pFunc == NULL) {
		sig.SetError(ERR_IOError, "invalid binary operator in the stream");
		return false;
	}
	_pFunc = pFunc;
	return true;
}

String Expr_UnaryOp::ToString() const
{
	bool needParenthesisFlag = false;
	if (GetParent() != NULL) {
		needParenthesisFlag = (GetParent()->IsUnaryOp() ||
					GetParent()->IsBinaryOp() || GetParent()->IsMember());
	}
	String str;
	if (needParenthesisFlag) str += "(";
	if (!_suffixSymbolFlag) str += _pFunc->GetMathSymbol();
	str += GetChild()->ToString();
	if (_suffixSymbolFlag) str += _pFunc->GetMathSymbol();
	if (needParenthesisFlag) str += ")";
	return str;
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

Value Expr_BinaryOp::Exec(Environment &env, Signal sig) const
{
	Args args(GetExprOwner());
	Value result = _pFunc->EvalExpr(env, sig, args);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
	return result;
}

Expr *Expr_BinaryOp::MathDiff(Environment &env, Signal sig, const Symbol *pSymbol) const
{
	return _pFunc->DiffBinary(env, sig, GetLeft(), GetRight(), pSymbol);
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
	return _pFunc->OptimizeBinary(env, sig, pExprOpt1.release(), pExprOpt2.release());
}

bool Expr_BinaryOp::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "BinaryOp");
	return true;
}

bool Expr_BinaryOp::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Binary::DoSerialize(env, sig, stream)) return false;
	unsigned char opType = static_cast<unsigned char>(_pFunc->GetOpType());
	if (!stream.SerializeUChar(sig, opType)) return false;
	return true;
}

bool Expr_BinaryOp::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Binary::DoDeserialize(env, sig, stream)) return false;
	unsigned char opTypeRaw = 0x00;
	if (!stream.DeserializeUChar(sig, opTypeRaw)) return false;
	OpType opType = static_cast<OpType>(opTypeRaw);
	const Function *pFunc = env.GetOpFuncWithCheck(opType);
	if (pFunc == NULL) {
		sig.SetError(ERR_IOError, "invalid binary operator in the stream");
		return false;
	}
	_pFunc = pFunc;
	return true;
}

String Expr_BinaryOp::ToString() const
{
	bool needParenthesisFlag = false;
	if (GetParent() == NULL) {
		// nothing to do
	} else if (GetParent()->IsUnaryOp()) {
		const Expr_UnaryOp *pExprOuter =
								dynamic_cast<const Expr_UnaryOp *>(GetParent());
		needParenthesisFlag = NeedParenthesis(pExprOuter->GetFunction(),
							GetFunction(), false);
	} else if (GetParent()->IsBinaryOp()) {
		const Expr_BinaryOp *pExprOuter =
								dynamic_cast<const Expr_BinaryOp *>(GetParent());
		needParenthesisFlag = NeedParenthesis(pExprOuter->GetFunction(),
							GetFunction(), pExprOuter->GetRight() == this);
	} else if (GetParent()->IsMember()) {
		needParenthesisFlag = true;
	}
	String str;
	if (needParenthesisFlag) str += "(";
	str += GetLeft()->ToString();
	str += " ";
	str += _pFunc->GetMathSymbol();
	str += " ";
	str += GetRight()->ToString();
	if (needParenthesisFlag) str += ")";
	return str;
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

Value Expr_Quote::Exec(Environment &env, Signal sig) const
{
	Value value;
	if (GetChild()->IsSymbol()) {
		const Expr_Symbol *pExprSym =
						dynamic_cast<const Expr_Symbol *>(GetChild());
		value.SetSymbol(pExprSym->GetSymbol());
	} else {
		value.InitAsExpr(env, GetChild()->IncRef());
	}
	return value;
}

bool Expr_Quote::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Quote");
	return true;
}

bool Expr_Quote::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Unary::DoSerialize(env, sig, stream)) return false;
	return true;
}

bool Expr_Quote::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Unary::DoDeserialize(env, sig, stream)) return false;
	return true;
}

String Expr_Quote::ToString() const
{
	String str;
	str += "`";
	str += GetChild()->ToString();
	return str;
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

Value Expr_Force::Exec(Environment &env, Signal sig) const
{
	Value result = GetChild()->Exec(env, sig);
	return result;
}

bool Expr_Force::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Force");
	return true;
}

bool Expr_Force::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Unary::DoSerialize(env, sig, stream)) return false;
	return true;
}

bool Expr_Force::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Unary::DoDeserialize(env, sig, stream)) return false;
	return true;
}

String Expr_Force::ToString() const
{
	String str;
	str += "!!";
	str += GetChild()->ToString();
	return str;
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

Value Expr_Prefix::Exec(Environment &env, Signal sig) const
{
	SetError(sig, ERR_SyntaxError, "invalid expression");
	return Value::Null;
}

bool Expr_Prefix::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Prefix");
	return true;
}

bool Expr_Prefix::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Unary::DoSerialize(env, sig, stream)) return false;
	if (stream.SerializeSymbol(sig, _pSymbol)) return false;
	return true;
}

bool Expr_Prefix::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Unary::DoDeserialize(env, sig, stream)) return false;
	if (stream.DeserializeSymbol(sig, &_pSymbol)) return false;
	return true;
}

String Expr_Prefix::ToString() const
{
	String str;
	str += _pSymbol->GetName();
	str += GetChild()->ToString();
	return str;
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

Value Expr_Suffix::Exec(Environment &env, Signal sig) const
{
	SetError(sig, ERR_SyntaxError, "invalid expression");
	return Value::Null;
}

OccurPattern Expr_Suffix::GetOccurPattern() const
{
	return
		(_pSymbol->IsIdentical(Gura_Symbol(Char_Multiply)))?	OCCUR_ZeroOrMore :
		(_pSymbol->IsIdentical(Gura_Symbol(Char_Plus)))?		OCCUR_OnceOrMore :
		(_pSymbol->IsIdentical(Gura_Symbol(Char_Question)))?	OCCUR_ZeroOrOnce :
		OCCUR_Invalid;
}

bool Expr_Suffix::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Suffix");
	return true;
}

bool Expr_Suffix::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Unary::DoSerialize(env, sig, stream)) return false;
	if (stream.SerializeSymbol(sig, _pSymbol)) return false;
	return true;
}

bool Expr_Suffix::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Unary::DoDeserialize(env, sig, stream)) return false;
	if (stream.DeserializeSymbol(sig, &_pSymbol)) return false;
	return true;
}

String Expr_Suffix::ToString() const
{
	String str;
	str += GetChild()->ToString();
	str += _pSymbol->GetName();
	return str;
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

Value Expr_Assign::Exec(Environment &env, Signal sig) const
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
		if (_pFuncToApply != NULL) {
			SetError(sig, ERR_SyntaxError, "invalid operation");
			return Value::Null;
		}
		if (GetRight()->IsForce()) {
			value = GetRight()->Exec(env, sig);
			if (sig.IsSignalled()) {
				sig.AddExprCause(this);
				return Value::Null;
			}
		} else {
			Expr *pExprBody = GetRight()->Unquote()->IncRef();
			value.InitAsExpr(env, pExprBody);
		}
	} else {
		value = GetRight()->Exec(env, sig);
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
		if (_pFuncToApply != NULL) {
			Value valueLeft = pExpr->Exec(env, sig);
			if (sig.IsSignalled()) {
				sig.AddExprCause(this);
				return Value::Null;
			}
			ValueList valListArg(valueLeft, value);
			Args args(valListArg);
			value = _pFuncToApply->GetDeclOwner().ShouldImplicitMap(valListArg)?
							_pFuncToApply->EvalMap(env, sig, args) :
							_pFuncToApply->Eval(env, sig, args);
			if (sig.IsSignalled()) {
				sig.AddExprCause(this);
				return Value::Null;
			}
		}
	}
	return GetLeft()->DoAssign(envDst, sig, value, pSymbolsAssignable, true);
}

bool Expr_Assign::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Assign");
	return true;
}

bool Expr_Assign::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Binary::DoSerialize(env, sig, stream)) return false;
	OpType opType = (_pFuncToApply == NULL)? OPTYPE_None : _pFuncToApply->GetOpType();
	unsigned char opTypeRaw = static_cast<unsigned char>(opType);
	if (!stream.SerializeUChar(sig, opTypeRaw)) return false;
	return true;
}

bool Expr_Assign::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Binary::DoDeserialize(env, sig, stream)) return false;
	unsigned char opTypeRaw = 0x00;
	if (!stream.DeserializeUChar(sig, opTypeRaw)) return false;
	OpType opType = static_cast<OpType>(opTypeRaw);
	const Function *pFuncToApply = NULL;
	if (opType != OPTYPE_None) {
		pFuncToApply = env.GetOpFuncWithCheck(opType);
		if (pFuncToApply == NULL) {
			sig.SetError(ERR_IOError, "invalid binary operator in the stream");
			return false;
		}
	}
	_pFuncToApply = pFuncToApply;
	return true;
}

String Expr_Assign::ToString() const
{
	String str;
	str += GetLeft()->ToString();
	str += " ";
	if (_pFuncToApply != NULL) str += _pFuncToApply->GetMathSymbol();
	str += "= ";
	str += GetRight()->ToString();
	return str;
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

Value Expr_DictAssign::Exec(Environment &env, Signal sig) const
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	Value valueKey = GetLeft()->Exec(env, sig);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
	Value value = GetRight()->Exec(env, sig);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
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

bool Expr_DictAssign::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Binary::DoSerialize(env, sig, stream)) return false;
	return true;
}

bool Expr_DictAssign::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Binary::DoDeserialize(env, sig, stream)) return false;
	return true;
}

String Expr_DictAssign::ToString() const
{
	String str;
	str += GetLeft()->Unquote()->ToString();
	str += " => ";
	str += GetRight()->ToString();
	return str;
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

Value Expr_Member::Exec(Environment &env, Signal sig) const
{
	// Expr_Caller::Exec(), Expr_Member::Exec() and Expr_Member::DoAssign()
	// correspond to method-calling, property-getting and property-setting.
	Value valueThis = GetLeft()->Exec(env, sig);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
	Fundamental *pFund = NULL;
	if (valueThis.IsPrimitive() || valueThis.GetTinyBuffFlag()) {
		pFund = env.LookupClass(valueThis.GetType());
	} else {
		pFund = valueThis.ExtractFundamental(sig);
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
	}
	Mode mode = GetMode();
	if (mode != MODE_Normal) {
		if (valueThis.IsList() && valueThis.GetList().empty()) {
			return valueThis;
		}
		Iterator *pIterator = pFund->CreateIterator(sig);
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
		if (pIterator != NULL) {
			AutoPtr<Iterator> pIteratorMap(new Iterator_MemberMap(
								env, sig, pIterator, GetRight()->IncRef()));
			if (mode == MODE_MapToIter) {
				return Value(env, pIteratorMap.release());
			}
			Value result = pIteratorMap->ToList(env, sig, true, false);
			if (sig.IsSignalled()) {
				sig.AddExprCause(this);
				return Value::Null;
			}
			return result;
		}
	}
	Value result;
	if (pFund->IsModule()) {
		Environment envLocal(pFund, ENVTYPE_member);
		result = GetRight()->Exec(envLocal, sig);
	} else {
		result = GetRight()->Exec(*pFund, sig);
	}
	if (result.IsFunction()) {
		Object_function *pObjFunc =
			dynamic_cast<Object_function *>(result.GetFunctionObj()->Clone());
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
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
	Fundamental *pFund = valueThis.ExtractFundamental(sig);
	if (sig.IsSignalled()) {
		sig.AddExprCause(this);
		return Value::Null;
	}
	Mode mode = GetMode();
	if (mode == MODE_Normal) {
		return GetRight()->DoAssign(*pFund, sig, value, pSymbolsAssignable, escalateFlag);
	}
	AutoPtr<Iterator> pIteratorThis(pFund->CreateIterator(sig));
	if (pIteratorThis.IsNull()) {
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
		return GetRight()->DoAssign(*pFund, sig, value, pSymbolsAssignable, escalateFlag);
	}
	if (value.IsList() || value.IsIterator()) {
		AutoPtr<Iterator> pIteratorValue(value.CreateIterator(sig));
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
		Value value;
		Value valueThisEach;
		while (pIteratorThis->Next(env, sig, valueThisEach) &&
								pIteratorValue->Next(env, sig, value)) {
			Fundamental *pFundEach = valueThisEach.ExtractFundamental(sig);
			if (sig.IsSignalled()) break;
			GetRight()->DoAssign(*pFundEach, sig, value,
									pSymbolsAssignable, escalateFlag);
			if (sig.IsSignalled()) break;
		}
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
	} else {
		Value valueThisEach;
		while (pIteratorThis->Next(env, sig, valueThisEach)) {
			Fundamental *pFundEach = valueThisEach.ExtractFundamental(sig);
			if (sig.IsSignalled()) break;
			GetRight()->DoAssign(*pFundEach, sig, value, pSymbolsAssignable, escalateFlag);
			if (sig.IsSignalled()) break;
		}
		if (sig.IsSignalled()) {
			sig.AddExprCause(this);
			return Value::Null;
		}
	}
	return value;
}

bool Expr_Member::GenerateCode(Environment &env, Signal sig, Stream &stream)
{
	stream.Println(sig, "Member");
	return true;
}

bool Expr_Member::DoSerialize(Environment &env, Signal sig, Stream &stream) const
{
	if (!Expr_Binary::DoSerialize(env, sig, stream)) return false;
	unsigned char mode = static_cast<unsigned char>(_mode);
	if (!stream.SerializeUChar(sig, mode)) return false;
	return true;
}

bool Expr_Member::DoDeserialize(Environment &env, Signal sig, Stream &stream)
{
	if (!Expr_Binary::DoDeserialize(env, sig, stream)) return false;
	unsigned char mode = 0;
	if (!stream.DeserializeUChar(sig, mode)) return false;
	if (mode >= MODE_max) {
		sig.SetError(ERR_IOError, "invalid mode number");
		return false;
	}
	_mode = static_cast<Mode>(mode);
	return true;
}

String Expr_Member::ToString() const
{
	String str;
	str += GetLeft()->ToString();
	str +=
		(_mode == MODE_Normal)? "." :
		(_mode == MODE_MapToList)? "::" :
		(_mode == MODE_MapToIter)? ":*" :
		(_mode == MODE_MapAlong)? ":::" : "????";
	str += GetRight()->ToString();
	return str;
}

//-----------------------------------------------------------------------------
// ExprList
//-----------------------------------------------------------------------------
const ExprList ExprList::Null;

void ExprList::IncRef() const
{
	foreach (ExprList, ppExpr, *const_cast<ExprList *>(this)) {
		(*ppExpr)->IncRef();
	}
}

Value ExprList::Exec(Environment &env, Signal sig, bool evalSymFuncFlag) const
{
	Value result;
	foreach_const (ExprList, ppExpr, *this) {
		result = (*ppExpr)->Exec(env, sig);
		if (sig.IsSignalled()) {
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

Value ExprList::ExecInRoot(Environment &env, Signal sig) const
{
	Value result;
	foreach_const (ExprList, ppExpr, *this) {
		result = (*ppExpr)->Exec(env, sig);
		if (sig.IsError()) {
			// pConsole must be retrieved here.
			//Stream *pConsole = env.GetConsoleErr();
			//if (pConsole != NULL) {
			//	String str;
			//	str += sig.GetErrString();
			//	str += "\n";
			//	str += sig.GetErrTrace();
			//	pConsole->Print(sig, str.c_str());
			//}
			//sig.ClearSignal();
			return Value::Null;
		} else if (sig.IsSignalled()) {
			// pConsole must be retrieved here.
			Stream *pConsole = env.GetConsoleErr();
			if (pConsole != NULL) {
				pConsole->Println(sig, sig.GetSignalName());
			}
			sig.ClearSignal();
		} else if (!env.GetEchoFlag()) {
			// nothing to do
		} else if (result.IsValid()) {
			// pConsole must be retrieved here.
			Stream *pConsole = env.GetConsole();
			if (pConsole != NULL) {
				pConsole->Println(sig, result.ToString(sig).c_str());
			}
		}
	}
	return result;
}

Value ExprList::ExecForList(Environment &env, Signal sig,
									bool flattenFlag, bool evalSymFuncFlag) const
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	foreach_const (ExprList, ppExpr, *this) {
		Value value = (*ppExpr)->Exec(env, sig);
		if (sig.IsSignalled()) {
			return Value::Null;
		}
		if (evalSymFuncFlag && value.IsFunction() &&
									value.GetFunction()->IsSymbolFunc()) {
			const Function *pFunc = result.GetFunction();
			Args args(ExprList::Null);
			Value result = pFunc->EvalExpr(env, sig, args);
			if (sig.IsSignalled()) {
				sig.AddExprCause(*ppExpr);
				return Value::Null;
			}
		} else if (flattenFlag && value.IsList()) {
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

bool ExprList::Serialize(Environment &env, Signal sig, Stream &stream) const
{
	unsigned long num = static_cast<unsigned long>(size());
	if (!stream.SerializePackedULong(sig, num)) return false;
	foreach_const (ExprList, ppExpr, *this) {
		const Expr *pExpr = *ppExpr;
		if (!Expr::Serialize(env, sig, stream, pExpr)) return false;
	}
	return true;
}

String ExprList::ToString(const char *sep) const
{
	String str;
	foreach_const (ExprList, ppExpr, *this) {
		if (ppExpr != begin()) str += sep;
		str += (*ppExpr)->ToString();
	}
	return str;
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

//-----------------------------------------------------------------------------
// ExprOwner
//-----------------------------------------------------------------------------
ExprOwner::ExprOwner(const ExprList &exprList)
{
	foreach_const (ExprList, ppExpr, exprList) {
		push_back((*ppExpr)->IncRef());
	}
}

ExprOwner::ExprOwner(const ExprOwner &exprOwner)
{
	foreach_const (ExprOwner, ppExpr, exprOwner) {
		push_back((*ppExpr)->IncRef());
	}
}

ExprOwner::~ExprOwner()
{
	Clear();
}

void ExprOwner::Clear()
{
	foreach (ExprOwner, ppExpr, *this) {
		Expr::Delete(const_cast<Expr *>(*ppExpr));
	}
	clear();
}

bool ExprOwner::Deserialize(Environment &env, Signal sig, Stream &stream)
{
	unsigned long num = 0;
	if (!stream.DeserializePackedULong(sig, num)) return false;
	Clear();
	reserve(num);
	while (num-- > 0) {
		Expr *pExpr = NULL;
		if (!Expr::Deserialize(env, sig, stream, &pExpr, true)) return false;
		push_back(pExpr);
	}
	return true;
}

}
