#include "stdafx.h"

namespace Gura {

inline bool IsSuffixed(const Expr *pExpr, const Symbol *pSymbol)
{
	return pExpr->IsSuffix() &&
		dynamic_cast<const Expr_Suffix *>(pExpr)->GetSymbol()->IsIdentical(pSymbol);
}

//-----------------------------------------------------------------------------
// Declaration
//-----------------------------------------------------------------------------
Declaration::Declaration(const Declaration &decl) :
	_pSymbol(decl._pSymbol), _valType(decl._valType),
	_occurPattern(decl._occurPattern), _flags(decl._flags),
	_pExprDefault(Expr::Reference(decl._pExprDefault.get()))
{
}

Declaration::Declaration(const Symbol *pSymbol, ValueType valType) :
	_pSymbol(pSymbol), _valType(valType),
	_occurPattern(OCCUR_Once), _flags(0), _pExprDefault(NULL)
{
}

Declaration::Declaration(const Symbol *pSymbol, ValueType valType,
		OccurPattern occurPattern, ULong flags, Expr *pExprDefault) :
	_pSymbol(pSymbol), _valType(valType),
	_occurPattern(occurPattern), _flags(flags), _pExprDefault(pExprDefault)
{
}

Declaration::~Declaration()
{
	// virtual destructor
}

Declaration *Declaration::Create(Environment &env, Signal sig, const Expr *pExpr)
{
	ULong flags = 0;
	OccurPattern occurPattern = OCCUR_Once;
	ValueType valType = VTYPE_any;
	Expr *pExprDefault = NULL;
	if (pExpr->IsDictAssign()) {
		const Expr_DictAssign *pExprDictAssign =
								dynamic_cast<const Expr_DictAssign *>(pExpr);
		pExpr = pExprDictAssign->GetLeft();
		const Expr *pExprRight = pExprDictAssign->GetRight();
		if (pExprRight->IsForce()) {
			Value value = pExprRight->Exec(env, sig);
			if (sig.IsSignalled()) return NULL;
			pExprDefault = new Expr_Value(value);
		} else {
			pExprDefault = Expr::Reference(pExprRight);
		}
	}
	if (pExpr->IsSuffix()) {
		const Expr_Suffix *pExprSuffix = dynamic_cast<const Expr_Suffix *>(pExpr);
		pExpr = pExprSuffix->GetChild();
		occurPattern = pExprSuffix->GetOccurPattern();
		if (occurPattern == OCCUR_Invalid) {
			sig.SetError(ERR_SyntaxError, "invalid argument expression");
			return NULL;
		}
		if (pExprDefault != NULL) {
			sig.SetError(ERR_SyntaxError, "optional arguments cannot take default value");
			return NULL;
		}
	}
	if (pExpr->IsQuote()) {
		pExpr = pExpr->Unquote();
		valType = VTYPE_quote;
	}
	if (pExpr->IsIndexer()) {
		pExpr = dynamic_cast<const Expr_Indexer *>(pExpr)->GetCar();
		flags |= FLAG_List;
	}
	if (!pExpr->IsSymbol()) {
		sig.SetError(ERR_SyntaxError, "invalid argument expression");
		return NULL;
	}
	const Expr_Symbol *pExprSym = dynamic_cast<const Expr_Symbol *>(pExpr);
	const SymbolList &attrFront = pExprSym->GetAttrFront();
	const Symbol *pSymbolForType = NULL;
	if (!attrFront.empty()) {
		if (valType != VTYPE_any) {
			sig.SetError(ERR_SyntaxError, "incompatible type declaration");
			return NULL;
		}
		const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(attrFront);
		if (pValueTypeInfo != NULL) {
			pSymbolForType = attrFront.front();
			valType = pValueTypeInfo->GetValueType();
		}
	}
	foreach_const (SymbolSet, ppSymbol, pExprSym->GetAttrs()) {
		const Symbol *pSymbol = *ppSymbol;
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
		} else if (pSymbolForType == NULL || !pSymbol->IsIdentical(pSymbolForType)) {
			sig.SetError(ERR_SyntaxError,
				"cannot accept a symbol %s in argument declaration", pSymbol->GetName());
		}
	}
	return new Declaration(pExprSym->GetSymbol(), valType, occurPattern, flags, pExprDefault);
}

// value will be casted only when that is valid for declaration.
// it will not be casted if validation fails.
bool Declaration::ValidateAndCast(Environment &env, Signal sig,
									Value &value, bool listElemFlag) const
{
	if (!listElemFlag && GetListFlag()) {
		env.LookupClass(VTYPE_list)->CastFrom(env, sig, value, this);
		if (sig.IsSignalled()) return false;
		if (value.IsList()) {
			foreach (ValueList, pValue, value.GetList()) {
				if (!ValidateAndCast(env, sig, *pValue, true)) {
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
	if (((IsOptional() || GetNilFlag()) && value.IsInvalid()) ||
												GetValueType() == VTYPE_quote) {
		goto done;
	} else if (GetValueType() == VTYPE_any || value.IsInstanceOf(GetValueType())) {
		if (value.IsIterator()) {
			// make a clone of the iterator
			Iterator *pIterator = value.CreateIterator(sig);
			if (pIterator == NULL) return false;
			value = Value(env, pIterator);
		}
		goto done;
	} else if (GetValueType() == VTYPE_Class && value.IsInstanceOf(VTYPE_function)) {
		const Function *pFunc = value.GetFunction();
		Class *pClass = pFunc->GetClassToConstruct();
		if (pClass == NULL) {
			sig.SetError(ERR_ValueError, "constructor function must be specified");
			return false;
		}
		value = Value(pClass);
		goto done;
	}
	if (!GetNoCastFlag()) {
		Class *pClass = env.LookupClass(GetValueType());
		for ( ; pClass != NULL; pClass = pClass->GetClassSuper()) {
			if (pClass->GetValueType() == VTYPE_undefined) {
				sig.SetError(ERR_TypeError, "type '%s' is not defined", pClass->GetName());
				return false;
			}
			if (pClass->CastFrom(env, sig, value, this)) goto done;
			if (sig.IsSignalled()) return false;
		}
		pClass = env.LookupClass(value.GetValueType());
		for ( ; pClass != NULL; pClass = pClass->GetClassSuper()) {
			if (pClass->CastTo(env, sig, value, *this)) goto done;
			if (sig.IsSignalled()) return false;
		}
	}
	SetError_ArgumentType(sig, value);
	return false;
done:
	if (GetPrivilegedFlag()) value.AddFlags(VFLAG_Privileged);
	return true;
}

void Declaration::SetError_ArgumentType(Signal sig, const Value &value) const
{
	sig.SetError(ERR_TypeError, "variable '%s' cannot take %s value in '%s'",
				GetSymbol()->GetName(), value.MakeValueTypeName().c_str(), ToString().c_str());
}

void Declaration::SetError_ArgumentMustBeList(Signal sig, const Value &value) const
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
	if (GetListFlag()) str += "[]";
	str += GetOccurPatternSymbol(_occurPattern)->GetName();
	if (_valType != VTYPE_nil && _valType != VTYPE_undefined &&
					_valType != VTYPE_any && _valType != VTYPE_quote) {
		str += ":";
		str += ValueTypePool::GetInstance()->Lookup(_valType)->MakeFullName();
	}
	if (GetNoMapFlag()) {
		str += ":";
		str += Gura_Symbol(nomap)->GetName();
	}
	if (GetNilFlag()) {
		str += ":";
		str += Gura_Symbol(nil)->GetName();
	}
	if (GetReadFlag()) {
		str += ":";
		str += Gura_Symbol(r)->GetName();
	}
	if (GetWriteFlag()) {
		str += ":";
		str += Gura_Symbol(w)->GetName();
	}
	if (GetNoCastFlag()) {
		str += ":";
		str += Gura_Symbol(nocast)->GetName();
	}
	if (GetPrivilegedFlag()) {
		str += ":";
		str += Gura_Symbol(privileged)->GetName();
	}
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
const DeclarationList DeclarationList::Null;

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

bool DeclarationList::ShouldImplicitMap(const Args &args) const
{
	return args.IsThisIterable() || ShouldImplicitMap(args.GetValueListArg());
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

bool DeclarationList::Compensate(Environment &env, Signal sig, ValueList &valList) const
{
	if (valList.size() >= size()) return true;
	DeclarationList::const_iterator ppDecl = begin() + valList.size();
	for ( ; ppDecl != end(); ppDecl++) {
		const Declaration *pDecl = *ppDecl;
		const Expr *pExprArg = pDecl->GetExprDefault();
		Value value;
		if (pExprArg == NULL) {
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
			if (!pExpr->IsSymbol()) {
				sig.SetError(ERR_TypeError, "symbol is expected");
				return false;
			}
			const Symbol *pSymbol =
						dynamic_cast<const Expr_Symbol *>(pExpr)->GetSymbol();
			value = Value(pSymbol);
		} else {
			value = pExprArg->Exec(env, sig);
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

void Declaration::SetError_InvalidArgument(Signal sig)
{
	sig.SetError(ERR_SyntaxError, "invalid argument");
}

void Declaration::SetError_NotEnoughArguments(Signal sig)
{
	sig.SetError(ERR_TypeError, "not enough arguments");
}

void Declaration::SetError_TooManyArguments(Signal sig)
{
	sig.SetError(ERR_TypeError, "too many arguments");
}

void DeclarationList::SetError_InvalidArgumentName(Signal sig, const ExprMap &exprMap)
{
	String str;
	str = "invalid argument named ";
	foreach_const (ExprMap, iter, exprMap) {
		if (iter != exprMap.begin()) str += ", ";
		str += iter->first->GetName();
	}
	sig.SetError(ERR_ValueError, "%s", str.c_str());
}

//-----------------------------------------------------------------------------
// DeclarationOwner
//-----------------------------------------------------------------------------
DeclarationOwner::DeclarationOwner(const DeclarationOwner &declOwner) :
			_pSymbolDict(declOwner._pSymbolDict),
			_allowTooManyArgsFlag(declOwner._allowTooManyArgsFlag)
{
	foreach_const (DeclarationList, ppDecl, declOwner) {
		push_back((*ppDecl)->Clone());
	}
}

DeclarationOwner::~DeclarationOwner()
{
	foreach (DeclarationOwner, ppDecl, *this) {
		Declaration::Delete(*ppDecl);
	}
}

void DeclarationOwner::operator=(const DeclarationOwner &declOwner)
{
	_pSymbolDict = declOwner._pSymbolDict;
	_allowTooManyArgsFlag = declOwner._allowTooManyArgsFlag;
	foreach_const (DeclarationList, ppDecl, declOwner) {
		push_back((*ppDecl)->Clone());
	}
}

Declaration *DeclarationOwner::Declare(Environment &env, const Symbol *pSymbol, ValueType valType,
			OccurPattern occurPattern, ULong flags, Expr *pExprDefault)
{
	Declaration *pDecl =
			new Declaration(pSymbol, valType, occurPattern, flags, pExprDefault);
	GURA_ASSUME(env, !IsVariableLength());
	GURA_ASSUME(env, !(!(pDecl->IsOptional() || occurPattern == OCCUR_ZeroOrMore) &&
				!empty() && back()->IsOptional()));
	push_back(pDecl);
	return pDecl;
}

bool DeclarationOwner::Declare(Environment &env, Signal sig, const ExprList &exprList)
{
	foreach_const (ExprList, ppExpr, exprList) {
		const Expr *pExpr = *ppExpr;
		if (pExpr->IsSuffix()) {
			const Expr_Suffix *pExprSuffix =
									dynamic_cast<const Expr_Suffix *>(pExpr);
			const Symbol *pSymbol = pExprSuffix->GetSymbol();
			if (pSymbol->IsIdentical(Gura_Symbol(Char_Mod))) {
				const Expr *pExprChild = pExprSuffix->GetChild();
				if (!pExprChild->IsSymbol()) {
					sig.SetError(ERR_SyntaxError,
									"invalid expression for declaration");
					return false;
				}
				SetSymbolDict(
						dynamic_cast<const Expr_Symbol *>(pExprChild)->GetSymbol());
				continue;
			}
		}
		AutoPtr<Declaration> pDecl(Declaration::Create(env, sig, pExpr));
		if (pDecl.IsNull()) return false;
		if (IsVariableLength()) {
			sig.SetError(ERR_TypeError,
				"any parameters cannot follow after a parameter with variable length");
			return false;
		}
		if (pDecl->IsMandatory() && pDecl->GetExprDefault() == NULL &&
											!empty() && back()->IsOptional()) {
			sig.SetError(ERR_TypeError,
				"mandatory parameters cannot follow after a parameter with variable length");
			return false;
		}
		push_back(pDecl.release());
	}
	return true;
}

bool DeclarationOwner::PrepareArgs(Environment &env, Signal sig,
		const ExprList &exprListArg, ValueList &valListArg, ValueDict &valDictArg) const
{
	ExprMap exprMap;
	DeclarationList::const_iterator ppDecl = begin();
	bool stayDeclPointerFlag = false;
	AutoPtr<ExprOwner> pExprsToDelete(new ExprOwner()); // store temporary Exprs that are to be deleted at the end
	foreach_const (ExprList, ppExprArg, exprListArg) {
		const Expr *pExprArg = *ppExprArg;
		bool quoteFlag = ppDecl != end() && (*ppDecl)->IsQuote();
		if (!quoteFlag && pExprArg->IsDictAssign()) {
			const Expr_DictAssign *pExprDictAssign =
							dynamic_cast<const Expr_DictAssign *>(pExprArg);
			Value valueKey = pExprDictAssign->GetKey(env, sig);
			if (sig.IsSignalled()) return false;
			if (valueKey.IsSymbol()) {
				exprMap[valueKey.GetSymbol()] = pExprDictAssign->GetRight();
			} else {
				Value value = pExprDictAssign->GetRight()->Exec(env, sig);
				if (sig.IsSignalled()) return false;
				valDictArg[valueKey] = value;
			}
		} else if (!quoteFlag && IsSuffixed(pExprArg, Gura_Symbol(Char_Mod))) {
			pExprArg = dynamic_cast<const Expr_Suffix *>(pExprArg)->GetChild();
			Value value = pExprArg->Exec(env, sig);
			if (sig.IsSignalled()) return false;
			if (!value.IsDict()) {
				sig.SetError(ERR_ValueError, "modulo argument must take a dictionary");
				return false;
			}
			foreach_const (ValueDict, item, value.GetDict()) {
				const Value &valueKey = item->first;
				const Value &value = item->second;
				if (valueKey.IsSymbol()) {
					Expr *pExpr;
					if (value.IsExpr()) {
						pExpr = new Expr_Quote(Expr::Reference(value.GetExpr()));
					} else {
						pExpr = new Expr_Value(value);
					}
					pExprsToDelete->push_back(pExpr);
					exprMap[valueKey.GetSymbol()] = pExpr;
				} else {
					valDictArg.insert(*item);
				}
			}
		} else if (ppDecl != end()) {
			const Declaration *pDecl = *ppDecl;
			if (exprMap.find(pDecl->GetSymbol()) != exprMap.end()) {
				sig.SetError(ERR_ValueError, "argument confliction");
				return false;
			}
			size_t nElems = 0;
			if (!pExprArg->ExecInArg(env, sig, valListArg, nElems, quoteFlag)) {
				return false;
			}
			for ( ; nElems > 0 && ppDecl != end(); nElems--) {
				const Declaration *pDecl = *ppDecl;
				if (pDecl->IsVariableLength()) {
					stayDeclPointerFlag = true;
					break;
				}
				ppDecl++;
			}
		} else if (IsAllowTooManyArgs()) {
			break;
		} else {
			Declaration::SetError_TooManyArguments(sig);
			return false;
		}
	}
	if (stayDeclPointerFlag) ppDecl = end();
	for ( ; ppDecl != end(); ppDecl++) {
		const Declaration *pDecl = *ppDecl;
		const Expr *pExprArg = pDecl->GetExprDefault();
		ExprMap::iterator iter = exprMap.find(pDecl->GetSymbol());
		if (iter != exprMap.end()) {
			exprMap.erase(iter);
			pExprArg = iter->second;
		}
		Value value;
		if (pExprArg == NULL) {
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
		} else if (pDecl->IsType(VTYPE_symbol)) {
			const Expr *pExpr = pExprArg;
			if (pExpr->IsQuote()) {
				pExpr = dynamic_cast<const Expr_Quote *>(pExpr)->GetChild();
			}
			if (!pExpr->IsSymbol()) {
				sig.SetError(ERR_TypeError, "symbol is expected");
				return false;
			}
			const Symbol *pSymbol =
						dynamic_cast<const Expr_Symbol *>(pExpr)->GetSymbol();
			value = Value(pSymbol);
		} else {
			value = pExprArg->Exec(env, sig);
			if (sig.IsSignalled()) return false;
		}
		valListArg.push_back(value);
	}
	if (GetSymbolDict() != NULL) {
		foreach (ExprMap, iter, exprMap) {
			const Symbol *pSymbol = iter->first;
			const Expr *pExprArg = iter->second;
			Value value = pExprArg->Exec(env, sig);
			if (sig.IsSignalled()) return false;
			valDictArg[Value(pSymbol)] = value;
		}
	} else if (!exprMap.empty()) {
		SetError_InvalidArgumentName(sig, exprMap);
		return false;
	}
	return true;
}

bool DeclarationOwner::ValidateAndCast(Environment &env, Signal sig,
						const ValueList &valList, ValueList &valListCasted) const
{
	ValueList::const_iterator pValue = valList.begin();
	DeclarationList::const_iterator ppDecl = begin();
	for ( ; ppDecl != end(); ppDecl++) {
		const Declaration *pDecl = *ppDecl;
		OccurPattern occurPattern = pDecl->GetOccurPattern();
		if (occurPattern == OCCUR_ZeroOrMore || occurPattern == OCCUR_OnceOrMore) {
			Value value;
			ValueList &valListElem = value.InitAsList(env);
			valListCasted.push_back(value);
			for ( ; pValue != valList.end(); pValue++) {
				Value value = *pValue;
				if (!pDecl->ValidateAndCast(env, sig, value)) return false;
				valListElem.push_back(value);
			}
			if (occurPattern == OCCUR_OnceOrMore && valListElem.empty()) {
				Declaration::SetError_NotEnoughArguments(sig);
				return false;
			}
			break;
		} else if (pValue == valList.end()) {
			if (occurPattern == OCCUR_ZeroOrOnce) {
				valListCasted.push_back(Value::Undefined);
			} else {
				Declaration::SetError_NotEnoughArguments(sig);
				return false;
			}
		} else {
			Value value = *pValue;
			if (!pDecl->ValidateAndCast(env, sig, value)) return false;
			valListCasted.push_back(value);
			pValue++;
		}
	}
	if (pValue != valList.end() && !IsAllowTooManyArgs()) {
		Declaration::SetError_TooManyArguments(sig);
		return false;
	}
	return true;
}

String DeclarationOwner::ToString() const
{
	String str = DeclarationList::ToString();
	if (_pSymbolDict != NULL) {
		if (!empty()) str += ", ";
		str += _pSymbolDict->GetName();
		str += Gura_Symbol(Char_Mod)->GetName();
	}
	return str;
}

}
