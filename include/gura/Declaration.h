#ifndef __GURA_DECLARATION_H__
#define __GURA_DECLARATION_H__

#include "Value.h"

namespace Gura {

class Class;
class Expr;
class ExprList;
class Environment;
class Args;

//-----------------------------------------------------------------------------
// Declaration
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Declaration {
private:
	int _cntRef;
	const Symbol *_pSymbol;
	ValueType _valType;
	OccurPattern _occurPattern;
	ULong _flags;
	AutoPtr<Expr> _pExprDefault;	// maybe NULL
public:
	Gura_DeclareReferenceAccessor(Declaration)
public:
	Declaration(const Declaration &decl);
	Declaration(const Symbol *pSymbol, ValueType valType);
	Declaration(const Symbol *pSymbol, ValueType valType,
			OccurPattern occurPattern, ULong flags, Expr *pExprDefault);
private:
	~Declaration();
public:
	static Declaration *Create(Environment &env, Signal sig, const Expr *pExpr);
	bool ValidateAndCast(Environment &env, Signal sig,
							Value &value, bool listElemFlag = false) const;
	inline Declaration *Clone() const { return new Declaration(*this); }
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline const char *GetName() const { return _pSymbol->GetName(); }
	inline bool GetListFlag() const { return (_flags & FLAG_List)? true : false; }
	inline bool GetNoMapFlag() const { return (_flags & FLAG_NoMap)? true : false; }
	inline bool GetNilFlag() const { return (_flags & FLAG_Nil)? true : false; }
	inline bool GetReadFlag() const { return (_flags & FLAG_Read)? true : false; }
	inline bool GetWriteFlag() const { return (_flags & FLAG_Write)? true : false; }
	inline bool GetNoCastFlag() const { return (_flags & FLAG_NoCast)? true : false; }
	inline bool GetPrivilegedFlag() const { return (_flags & FLAG_Privileged)? true : false; }
	inline void SetOccurPattern(OccurPattern occurPattern) { _occurPattern = occurPattern; }
	inline OccurPattern GetOccurPattern() const { return _occurPattern; }
	inline const Expr *GetExprDefault() const { return _pExprDefault.get(); }
	inline ValueType GetValueType() const { return _valType; }
	inline bool IsMandatory() const {
		return _occurPattern == OCCUR_Once || _occurPattern == OCCUR_OnceOrMore;
	}
	inline bool IsOptional() const {
		return _occurPattern == OCCUR_ZeroOrOnce || !_pExprDefault.IsNull();
	}
	inline bool IsVariableLength() const {
		return _occurPattern == OCCUR_ZeroOrMore || _occurPattern == OCCUR_OnceOrMore;
	}
	inline bool IsType(ValueType valType) const { return _valType == valType; }
	inline bool IsQuote() const { return IsType(VTYPE_quote); }
	inline bool IsAlwaysMappable() const {
		return (_occurPattern == OCCUR_Once || _occurPattern == OCCUR_ZeroOrOnce) &&
				!IsType(VTYPE_any) && !IsType(VTYPE_list) && !GetListFlag();
	}
	inline bool ShouldImplicitMap(const Value &value) const {
		return (value.IsList() || value.IsIterator()) && !GetNoMapFlag() &&
				!((IsType(VTYPE_list) || GetListFlag()) && value.IsFlatList());
	}
	String ToString() const;
	void SetError_ArgumentType(Signal sig, const Value &value) const;
	void SetError_ArgumentMustBeList(Signal sig, const Value &value) const;
	static void SetError_InvalidArgument(Signal sig);
	static void SetError_NotEnoughArguments(Signal sig);
	static void SetError_TooManyArguments(Signal sig);
};

//-----------------------------------------------------------------------------
// DeclarationList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE DeclarationList : public std::vector<Declaration *> {
public:
	typedef std::map<const Symbol *, const Expr *, Symbol::KeyCompare_UniqNumber> ExprMap;
public:
	static const DeclarationList Null;
public:
	inline DeclarationList() {}
	~DeclarationList();
	bool IsVariableLength() const;
	void SetAsLoose();
	bool Compensate(Environment &env, Signal sig, ValueList &valList) const;
	bool ShouldImplicitMap(const ValueList &valList) const;
	bool ShouldImplicitMap(const Args &args) const;
	String ToString() const;
};

//-----------------------------------------------------------------------------
// DeclarationOwner
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE DeclarationOwner : public DeclarationList {
private:
	int _cntRef;
	const Symbol *_pSymbolDict;
	bool _allowTooManyArgsFlag;
public:
	Gura_DeclareReferenceAccessor(DeclarationOwner)
public:
	inline DeclarationOwner() : _cntRef(1), _pSymbolDict(NULL), _allowTooManyArgsFlag(false) {}
	DeclarationOwner(const DeclarationOwner &declOwner);
private:
	~DeclarationOwner();
public:
	void Clear();
	void operator=(const DeclarationOwner &declOwner);
	inline const Symbol *GetSymbolDict() const { return _pSymbolDict; }
	inline void SetSymbolDict(const Symbol *pSymbol) { _pSymbolDict = pSymbol; }
	inline void AllowTooManyArgs(bool flag) { _allowTooManyArgsFlag = flag; }
	inline bool IsAllowTooManyArgs() const { return _allowTooManyArgsFlag; }
	Declaration *Declare(Environment &env, const Symbol *pSymbol, ValueType valType,
				OccurPattern occurPattern = OCCUR_Once, ULong flags = FLAG_None,
				Expr *pExprDefault = NULL);
	inline Declaration *Declare(Environment &env, const char *name, ValueType valType,
				OccurPattern occurPattern = OCCUR_Once, ULong flags = FLAG_None,
				Expr *pExprDefault = NULL) {
		return Declare(env, Symbol::Add(name), valType, occurPattern, flags, pExprDefault);
	}
	bool Declare(Environment &env, Signal sig, const ExprList &exprList);
	bool ValidateAndCast(Environment &env, Signal sig,
		const ValueList &valList, ValueList &valListCasted) const;
	String ToString() const;
};

}

#endif
