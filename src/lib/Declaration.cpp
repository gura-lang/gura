//=============================================================================
// Declaration
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Declaration
//-----------------------------------------------------------------------------
Declaration::Declaration(const Declaration &decl) :
	_cntRef(1), _pSymbol(decl._pSymbol), _valType(decl._valType),
	_occurPattern(decl._occurPattern),
	_flags(decl._flags), _nListElems(decl._nListElems),
	_pExprDefault(Expr::Reference(decl._pExprDefault.get()))
{
}

Declaration::Declaration(const Symbol *pSymbol, ValueType valType) :
	_cntRef(1), _pSymbol(pSymbol), _valType(valType), _occurPattern(OCCUR_Once),
	_flags(0), _nListElems(0), _pExprDefault(nullptr)
{
}

Declaration::Declaration(const Symbol *pSymbol, ValueType valType,
						 OccurPattern occurPattern, ULong flags, size_t nListElems,
						 Expr *pExprDefault) :
	_cntRef(1), _pSymbol(pSymbol), _valType(valType), _occurPattern(occurPattern),
	_flags(flags), _nListElems(nListElems), _pExprDefault(pExprDefault)
{
}

Declaration::~Declaration()
{
	// virtual destructor
}

Declaration *Declaration::CreateFromExpr(Environment &env, const Expr *pExpr)
{
	ULong flags = 0;
	size_t nListElems = 0;
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
			env.SetError(ERR_SyntaxError, "invalid argument expression");
			return nullptr;
		}
		if (pExprDefault != nullptr) {
			env.SetError(ERR_SyntaxError, "optional arguments cannot take default value");
			return nullptr;
		}
	}
	if (pExpr->IsQuote()) {
		pExpr = pExpr->Unquote();
		valType = VTYPE_quote;
	}
	if (pExpr->IsIndexer()) {
		const Expr_Indexer *pExprIndexer = dynamic_cast<const Expr_Indexer *>(pExpr);
		pExpr = pExprIndexer->GetCar();
		flags |= FLAG_ListVar;
		const ExprOwner &exprOwner = pExprIndexer->GetExprOwner();
		if (exprOwner.empty()) {
			// nothing to do
		} else if (exprOwner.size() == 1) {
			const Expr *pExprElem = exprOwner.front();
			if (!pExprElem->IsValue()) {
				env.SetError(ERR_SyntaxError, "invalid format of list declaration");
				return nullptr;
			}
			const Value &value = dynamic_cast<const Expr_Value *>(pExprElem)->GetValue();
			if (!value.Is_number()) {
				env.SetError(ERR_SyntaxError, "invalid format of list declaration");
				return nullptr;
			}
			nListElems = value.GetSizeT();
		} else {
			env.SetError(ERR_SyntaxError, "invalid format of list declaration");
			return nullptr;
		}
	}
	if (!pExpr->IsIdentifier()) {
		env.SetError(ERR_SyntaxError, "invalid argument expression");
		return nullptr;
	}
	const Expr_Identifier *pExprIdentifier = dynamic_cast<const Expr_Identifier *>(pExpr);
	const SymbolList &attrFront = pExprIdentifier->GetAttrFront();
	const Symbol *pSymbolForType = nullptr;
	if (!attrFront.empty()) {
		if (valType != VTYPE_any) {
			env.SetError(ERR_SyntaxError, "incompatible type declaration");
			return nullptr;
		}
		const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(attrFront);
		if (pValueTypeInfo != nullptr) {
			pSymbolForType = attrFront.front();
			valType = pValueTypeInfo->GetValueType();
		} else if (attrFront.size() > 1) {
			env.SetError(ERR_TypeError, "invalid type declaration: %s",
						 attrFront.Join('.').c_str());
			return nullptr;
		}
	}
	foreach_const (SymbolSet, ppSymbol, pExprIdentifier->GetAttrs()) {
		const Symbol *pSymbol = *ppSymbol;
		ULong flag = Symbol::ToFlag(pSymbol);
		if (flag != 0) {
			flags |= flag;
		} else if (pSymbolForType == nullptr || !pSymbol->IsIdentical(pSymbolForType)) {
			env.SetError(ERR_SyntaxError,
				"cannot accept a symbol %s in argument declaration", pSymbol->GetName());
		}
	}
	return new Declaration(pExprIdentifier->GetSymbol(), valType,
						   occurPattern, flags, nListElems, pExprDefault);
}

// value will be casted only when that is valid for declaration.
// it will not be casted if validation fails.
bool Declaration::ValidateAndCast(Environment &env, Value &value, bool listElemFlag) const
{
	if (!listElemFlag && GetFlag(FLAG_ListVar)) {
		env.LookupClass(VTYPE_list)->CastFrom(env, value, _flags);
		if (env.IsSignalled()) return false;
		if (value.Is_list()) {
			Object_list *pObjList = value.GetObjList();
			if (_nListElems > 0 && pObjList->Size() != _nListElems) {
				env.SetError(ERR_TypeError, "unmatched element size");
				return false;
			}
			if (!pObjList->ValidateAndCast(env, this, true)) return false;
		} else if (value.IsValid() || !IsOptional()) {
			SetError_ArgumentMustBeList(env, value);
			return false;
		}
	} else if (((IsOptional() || GetFlag(FLAG_Nil)) && value.IsInvalid()) ||
												GetValueType() == VTYPE_quote) {
		// nothing to do
	} else if (GetValueType() == VTYPE_any || value.IsInstanceOf(GetValueType())) {
		if (value.Is_iterator()) {
			// make a clone of the iterator
			Iterator *pIterator = value.CreateIterator(env.GetSignal());
			if (pIterator == nullptr) return false;
			value = Value(new Object_iterator(env, pIterator));
		}
	} else {
		if (!GetFlag(FLAG_NoCast)) {
			Class *pClass = env.LookupClass(GetValueType());
			for ( ; pClass != nullptr; pClass = pClass->GetClassSuper()) {
				if (pClass->GetValueType() == VTYPE_undefined) {
					env.SetError(ERR_TypeError, "type '%s' is not defined", pClass->GetName());
					return false;
				}
				if (pClass->CastFrom(env, value, _flags)) {
					if (GetFlag(FLAG_Privileged)) value.AddFlags(VFLAG_Privileged);
					return true;
				}
				if (env.IsSignalled()) return false;
			}
			pClass = env.LookupClass(value.GetValueType());
			for ( ; pClass != nullptr; pClass = pClass->GetClassSuper()) {
				if (pClass->CastTo(env, value, *this)) {
					if (GetFlag(FLAG_Privileged)) value.AddFlags(VFLAG_Privileged);
					return true;
				}
				if (env.IsSignalled()) return false;
			}
		}
		SetError_ArgumentType(env, value);
		return false;
	}
	if (GetFlag(FLAG_Privileged)) value.AddFlags(VFLAG_Privileged);
	return true;
}

void Declaration::SetError_ArgumentType(Environment &env, const Value &value) const
{
	env.SetError(ERR_TypeError, "variable '%s' cannot take %s value in '%s'",
				GetSymbol()->GetName(), value.MakeValueTypeName().c_str(), ToString().c_str());
}

void Declaration::SetError_ArgumentMustBeList(Environment &env, const Value &value) const
{
	env.SetError(ERR_TypeError, "variable '%s' can only take a list in '%s'",
				GetSymbol()->GetName(), ToString().c_str());
}

#if 0
String Declaration::ToString() const
{
	String str;
	if (_valType == VTYPE_quote) {
		str += "`";
	}
	str += _pSymbol->GetName();
	if (GetFlag(FLAG_ListVar)) {
		str += "[";
		if (_nListElems > 0) {
			char buff[32];
			::sprintf(buff, "%ld", _nListElems);
			str += buff;
		}
		str += "]";
	}
	const Symbol *pSymbol = Symbol::FromOccurPattern(_occurPattern);
	if (pSymbol != nullptr) str += pSymbol->GetName();
	if (_valType != VTYPE_nil && _valType != VTYPE_undefined &&
					_valType != VTYPE_any && _valType != VTYPE_quote) {
		str += ":";
		str += ValueTypeInfo::MakeFullName(_valType);
	}
	str += Symbol::MakeAttrForFlags(_flags & ~FLAG_ListVar, 0);
	if (!_pExprDefault.IsNull()) {
		str += " ";
		str += "=>";
		str += " ";
		str += _pExprDefault->ToString(Expr::SCRSTYLE_OneLine);
	}
	return str;
}
#endif

String Declaration::ToString(const Symbol *pSymbol, ValueType valType, OccurPattern occurPattern,
							 ULong flags, size_t nListElems, const Expr *pExprDefault)
{
	String str;
	if (valType == VTYPE_quote) {
		str += "`";
	}
	str += pSymbol->GetName();
	if (flags & FLAG_ListVar) {
		str += "[";
		if (nListElems > 0) {
			char buff[32];
			::sprintf(buff, "%ld", nListElems);
			str += buff;
		}
		str += "]";
	}
	do {
		const Symbol *pSymbol = Symbol::FromOccurPattern(occurPattern);
		if (pSymbol != nullptr) str += pSymbol->GetName();
	} while (0);
	if (valType != VTYPE_nil && valType != VTYPE_undefined &&
					valType != VTYPE_any && valType != VTYPE_quote) {
		str += ":";
		str += ValueTypeInfo::MakeFullName(valType);
	}
	str += Symbol::MakeAttrForFlags(flags & ~FLAG_ListVar, 0);
	if (pExprDefault != nullptr) {
		str += " ";
		str += "=>";
		str += " ";
		str += pExprDefault->ToString(Expr::SCRSTYLE_OneLine);
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

String DeclarationList::ToString() const
{
	String str;
	foreach_const (DeclarationList, ppDecl, *this) {
		if (ppDecl != begin()) str += ", ";
		str += (*ppDecl)->ToString();
	}
	return str;
}

void Declaration::SetError_InvalidArgument(Environment &env)
{
	env.SetError(ERR_SyntaxError, "invalid argument");
}

void Declaration::SetError_NotEnoughArguments(Environment &env)
{
	env.SetError(ERR_TypeError, "not enough arguments");
}

void Declaration::SetError_TooManyArguments(Environment &env)
{
	env.SetError(ERR_TypeError, "too many arguments");
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
