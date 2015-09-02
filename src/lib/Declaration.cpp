//=============================================================================
// Declaration
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Declaration
//-----------------------------------------------------------------------------
Declaration::Declaration(const Declaration &decl) : _cntRef(1),
	_pSymbol(decl._pSymbol), _valType(decl._valType),
	_occurPattern(decl._occurPattern), _flags(decl._flags),
	_pExprDefault(Expr::Reference(decl._pExprDefault.get()))
{
}

Declaration::Declaration(const Symbol *pSymbol, ValueType valType) : _cntRef(1),
	_pSymbol(pSymbol), _valType(valType),
	_occurPattern(OCCUR_Once), _flags(0), _pExprDefault(nullptr)
{
}

Declaration::Declaration(const Symbol *pSymbol, ValueType valType,
		OccurPattern occurPattern, ULong flags, Expr *pExprDefault) : _cntRef(1),
	_pSymbol(pSymbol), _valType(valType),
	_occurPattern(occurPattern), _flags(flags), _pExprDefault(pExprDefault)
{
}

Declaration::~Declaration()
{
	// virtual destructor
}

Declaration *Declaration::Create(Environment &env, const Expr *pExpr)
{
	Signal &sig = env.GetSignal();
	ULong flags = 0;
	OccurPattern occurPattern = OCCUR_Once;
	ValueType valType = VTYPE_any;
	Expr *pExprDefault = nullptr;
	if (pExpr->IsBinaryOp(OPTYPE_Pair)) {
		const Expr_BinaryOp *pExprBinaryOp =
								dynamic_cast<const Expr_BinaryOp *>(pExpr);
		pExpr = pExprBinaryOp->GetLeft();
		const Expr *pExprRight = pExprBinaryOp->GetRight();
		pExprDefault = Expr::Reference(pExprRight);
	}
	if (pExpr->IsUnaryOpSuffix()) {
		const Expr_UnaryOp *pExprUnaryOp = dynamic_cast<const Expr_UnaryOp *>(pExpr);
		pExpr = pExprUnaryOp->GetChild();
		occurPattern = Symbol::ToOccurPattern(pExprUnaryOp->GetOperator()->GetSymbol());
		if (occurPattern == OCCUR_Invalid) {
			sig.SetError(ERR_SyntaxError, "invalid argument expression");
			return nullptr;
		}
		if (pExprDefault != nullptr) {
			sig.SetError(ERR_SyntaxError, "optional arguments cannot take default value");
			return nullptr;
		}
	}
	if (pExpr->IsQuote()) {
		pExpr = pExpr->Unquote();
		valType = VTYPE_quote;
	}
	if (pExpr->IsIndexer()) {
		pExpr = dynamic_cast<const Expr_Indexer *>(pExpr)->GetCar();
		flags |= FLAG_ListVar;
	}
	if (!pExpr->IsIdentifier()) {
		sig.SetError(ERR_SyntaxError, "invalid argument expression");
		return nullptr;
	}
	const Expr_Identifier *pExprIdentifier = dynamic_cast<const Expr_Identifier *>(pExpr);
	const SymbolList &attrFront = pExprIdentifier->GetAttrFront();
	const Symbol *pSymbolForType = nullptr;
	if (!attrFront.empty()) {
		if (valType != VTYPE_any) {
			sig.SetError(ERR_SyntaxError, "incompatible type declaration");
			return nullptr;
		}
		const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(attrFront);
		if (pValueTypeInfo != nullptr) {
			pSymbolForType = attrFront.front();
			valType = pValueTypeInfo->GetValueType();
		}
	}
	foreach_const (SymbolSet, ppSymbol, pExprIdentifier->GetAttrs()) {
		const Symbol *pSymbol = *ppSymbol;
#if 0
		if (pSymbol->IsIdentical(Gura_Symbol(nomap))) {
			flags |= FLAG_NoMap;
		} else if (pSymbol->IsIdentical(Gura_Symbol(nil))) {
			flags |= FLAG_Nil;
		} else if (pSymbol->IsIdentical(Gura_Symbol(r))) {
			flags |= FLAG_Read;
		} else if (pSymbol->IsIdentical(Gura_Symbol(w))) {
			flags |= FLAG_Write;
		} else if (pSymbol->IsIdentical(Gura_Symbol(nocast))) {
			flags |= FLAG_NoCast;
		} else if (pSymbol->IsIdentical(Gura_Symbol(privileged))) {
			flags |= FLAG_Privileged;
		}
#endif
		ULong flag = Symbol::ToFlag(pSymbol);
		if (flag != 0) {
			flags |= flag;
		} else if (pSymbolForType == nullptr || !pSymbol->IsIdentical(pSymbolForType)) {
			sig.SetError(ERR_SyntaxError,
				"cannot accept a symbol %s in argument declaration", pSymbol->GetName());
		}
	}
	return new Declaration(pExprIdentifier->GetSymbol(), valType, occurPattern, flags, pExprDefault);
}

// value will be casted only when that is valid for declaration.
// it will not be casted if validation fails.
bool Declaration::ValidateAndCast(Environment &env, Value &value, bool listElemFlag) const
{
	Signal &sig = env.GetSignal();
	if (!listElemFlag && GetFlag(FLAG_ListVar)) {
		env.LookupClass(VTYPE_list)->CastFrom(env, value, this);
		if (sig.IsSignalled()) return false;
		if (value.Is_list()) {
			foreach (ValueList, pValue, value.GetList()) {
				if (!ValidateAndCast(env, *pValue, true)) {
					SetError_ArgumentType(sig, *pValue);
					return false;
				}
			}
			goto done;
		} else if (IsOptional() && value.IsInvalid()) {
			goto done;
		} else {
			SetError_ArgumentMustBeList(sig, value);
			return false;
		}
	}
	if (((IsOptional() || GetFlag(FLAG_Nil)) && value.IsInvalid()) ||
												GetValueType() == VTYPE_quote) {
		goto done;
	} else if (GetValueType() == VTYPE_any || value.IsInstanceOf(GetValueType())) {
		if (value.Is_iterator()) {
			// make a clone of the iterator
			Iterator *pIterator = value.CreateIterator(sig);
			if (pIterator == nullptr) return false;
			value = Value(new Object_iterator(env, pIterator));
		}
		goto done;
	} else if (GetValueType() == VTYPE_Class && value.IsInstanceOf(VTYPE_function)) {
		const Function *pFunc = value.GetFunction();
		Class *pClass = pFunc->GetClassToConstruct();
		if (pClass == nullptr) {
			sig.SetError(ERR_ValueError, "constructor function must be specified");
			return false;
		}
		value = Value(pClass);
		goto done;
	}
	if (!GetFlag(FLAG_NoCast)) {
		Class *pClass = env.LookupClass(GetValueType());
		for ( ; pClass != nullptr; pClass = pClass->GetClassSuper()) {
			if (pClass->GetValueType() == VTYPE_undefined) {
				sig.SetError(ERR_TypeError, "type '%s' is not defined", pClass->GetName());
				return false;
			}
			if (pClass->CastFrom(env, value, this)) goto done;
			if (sig.IsSignalled()) return false;
		}
		pClass = env.LookupClass(value.GetValueType());
		for ( ; pClass != nullptr; pClass = pClass->GetClassSuper()) {
			if (pClass->CastTo(env, value, *this)) goto done;
			if (sig.IsSignalled()) return false;
		}
	}
	SetError_ArgumentType(sig, value);
	return false;
done:
	if (GetFlag(FLAG_Privileged)) value.AddFlags(VFLAG_Privileged);
	return true;
}

void Declaration::SetError_ArgumentType(Signal &sig, const Value &value) const
{
	sig.SetError(ERR_TypeError, "variable '%s' cannot take %s value in '%s'",
				GetSymbol()->GetName(), value.MakeValueTypeName().c_str(), ToString().c_str());
}

void Declaration::SetError_ArgumentMustBeList(Signal &sig, const Value &value) const
{
	sig.SetError(ERR_TypeError, "variable '%s' can only take a list in '%s'",
				GetSymbol()->GetName(), ToString().c_str());
}

String Declaration::ToString() const
{
	String str;
	if (_valType == VTYPE_quote) {
		str += "`";
	}
	str += _pSymbol->GetName();
	if (GetFlag(FLAG_ListVar)) str += "[]";
	const Symbol *pSymbol = Symbol::FromOccurPattern(_occurPattern);
	if (pSymbol != nullptr) str += pSymbol->GetName();
	if (_valType != VTYPE_nil && _valType != VTYPE_undefined &&
					_valType != VTYPE_any && _valType != VTYPE_quote) {
		str += ":";
		str += ValueTypePool::GetInstance()->Lookup(_valType)->MakeFullName();
	}
	str += Symbol::MakeAttrForFlags(_flags & ~FLAG_ListVar, 0);
#if 0
	if (GetFlag(FLAG_NoMap)) {
		str += ":";
		str += Gura_Symbol(nomap)->GetName();
	}
	if (GetFlag(FLAG_Nil)) {
		str += ":";
		str += Gura_Symbol(nil)->GetName();
	}
	if (GetFlag(FLAG_Read)) {
		str += ":";
		str += Gura_Symbol(r)->GetName();
	}
	if (GetFlag(FLAG_Write)) {
		str += ":";
		str += Gura_Symbol(w)->GetName();
	}
	if (GetFlag(FLAG_NoCast)) {
		str += ":";
		str += Gura_Symbol(nocast)->GetName();
	}
	if (GetFlag(FLAG_Privileged)) {
		str += ":";
		str += Gura_Symbol(privileged)->GetName();
	}
#endif
	if (!_pExprDefault.IsNull()) {
		str += " ";
		str += "=>";
		str += " ";
		str += _pExprDefault->ToString(Expr::SCRSTYLE_OneLine);
	}
	return str;
}

//-----------------------------------------------------------------------------
// DeclarationList
//-----------------------------------------------------------------------------
const DeclarationList DeclarationList::Empty;

DeclarationList::~DeclarationList()
{
}

bool DeclarationList::IsVariableLength() const
{
	foreach_const (DeclarationList, ppDecl, *this) {
		if ((*ppDecl)->IsVariableLength()) return true;
	}
	return false;
}

bool DeclarationList::ShouldImplicitMap(const ValueList &valList) const
{
	ValueList::const_iterator pValue = valList.begin();
	const_iterator ppDecl = begin();
	for ( ; pValue != valList.end() && ppDecl != end(); pValue++) {
		const Declaration *pDecl = *ppDecl;
		if (pDecl->ShouldImplicitMap(*pValue)) return true;
		if (!pDecl->IsVariableLength()) ppDecl++;
	}
	return false;
}

bool DeclarationList::ShouldImplicitMap(const Argument &arg) const
{
	return arg.IsThisIterable() || ShouldImplicitMap(arg.GetValueListArg());
}

void DeclarationList::SetAsLoose()
{
	foreach (DeclarationList, ppDecl, *this) {
		Declaration *pDecl = *ppDecl;
		if (pDecl->GetOccurPattern() == OCCUR_Once) {
			pDecl->SetOccurPattern(OCCUR_ZeroOrOnce);
		} else if (pDecl->GetOccurPattern() == OCCUR_OnceOrMore) {
			pDecl->SetOccurPattern(OCCUR_ZeroOrMore);
		}
	}
}

bool DeclarationList::Compensate(Environment &env, ValueList &valList) const
{
	Signal &sig = env.GetSignal();
	if (valList.size() >= size()) return true;
	DeclarationList::const_iterator ppDecl = begin() + valList.size();
	for ( ; ppDecl != end(); ppDecl++) {
		const Declaration *pDecl = *ppDecl;
		const Expr *pExprArg = pDecl->GetExprDefault();
		Value value;
		if (pExprArg == nullptr) {
			if (pDecl->GetOccurPattern() == OCCUR_ZeroOrOnce) {
				value = Value::Undefined;
			} else if (pDecl->GetOccurPattern() == OCCUR_ZeroOrMore) {
				break;
			} else {
				Declaration::SetError_NotEnoughArguments(sig);
				return false;
			}
		} else if (pDecl->IsQuote()) {
			value = Value(new Object_expr(env, Expr::Reference(pExprArg)));
			//valList.push_back(value);
		} else if (pDecl->IsType(VTYPE_symbol)) {
			const Expr *pExpr = pExprArg;
			if (pExpr->IsQuote()) {
				pExpr = dynamic_cast<const Expr_Quote *>(pExpr)->GetChild();
			}
			if (!pExpr->IsIdentifier()) {
				sig.SetError(ERR_TypeError, "identifier is expected");
				return false;
			}
			const Symbol *pSymbol =
						dynamic_cast<const Expr_Identifier *>(pExpr)->GetSymbol();
			value = Value(pSymbol);
		} else {
			SeqPostHandler *pSeqPostHandler = nullptr;
			value = pExprArg->Exec2(env, pSeqPostHandler);
			if (sig.IsSignalled()) return false;
		}
		valList.push_back(value);
	}
	return true;
}

String DeclarationList::ToString() const
{
	String str;
	foreach_const (DeclarationList, ppDecl, *this) {
		if (ppDecl != begin()) str += ", ";
		str += (*ppDecl)->ToString();
	}
	return str;
}

void Declaration::SetError_InvalidArgument(Signal &sig)
{
	sig.SetError(ERR_SyntaxError, "invalid argument");
}

void Declaration::SetError_NotEnoughArguments(Signal &sig)
{
	sig.SetError(ERR_TypeError, "not enough arguments");
}

void Declaration::SetError_TooManyArguments(Signal &sig)
{
	sig.SetError(ERR_TypeError, "too many arguments");
}

//-----------------------------------------------------------------------------
// DeclarationOwner
//-----------------------------------------------------------------------------
DeclarationOwner::DeclarationOwner(const DeclarationOwner &declOwner) : _cntRef(1)
{
	foreach_const (DeclarationList, ppDecl, declOwner) {
		push_back((*ppDecl)->Clone());
	}
}

DeclarationOwner::~DeclarationOwner()
{
	Clear();
}

void DeclarationOwner::Clear()
{
	foreach (DeclarationOwner, ppDecl, *this) {
		Declaration::Delete(*ppDecl);
	}
	clear();
}

}
