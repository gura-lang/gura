//=============================================================================
// Declaration
//=============================================================================
#ifndef __GURA_DECLARATION_H__
#define __GURA_DECLARATION_H__

#include "Value.h"

namespace Gura {

class Class;
class Expr;
class ExprList;
class Environment;
class Argument;
class CallerInfo;

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
	size_t _nListElems;
	AutoPtr<Expr> _pExprDefault;	// maybe nullptr
public:
	Gura_DeclareReferenceAccessor(Declaration)
public:
	inline static void *operator new(size_t size) {
		return MemoryPool::Allocate(size, "Declaration");
	}
	inline static void operator delete(void *pv) {
		MemoryPool::Deallocate(pv);
	}
public:
	Declaration(const Declaration &decl);
	Declaration(const Symbol *pSymbol, ValueType valType);
	Declaration(const Symbol *pSymbol, ValueType valType,
				OccurPattern occurPattern, ULong flags, size_t nListElems,
				Expr *pExprDefault);
private:
	~Declaration();
public:
	static Declaration *CreateFromExpr(Environment &env, const Expr *pExpr);
	bool ValidateAndCast(Environment &env, Value &value, bool listElemFlag = false) const;
	inline Declaration *Clone() const { return new Declaration(*this); }
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline const char *GetName() const { return _pSymbol->GetName(); }
	inline bool GetFlag(ULong flag) const { return (_flags & flag) != 0; }
	inline void SetOccurPattern(OccurPattern occurPattern) { _occurPattern = occurPattern; }
	inline OccurPattern GetOccurPattern() const { return _occurPattern; }
	inline const Expr *GetExprDefault() const { return _pExprDefault.get(); }
	inline ValueType GetValueType() const { return _valType; }
	inline bool IsMandatory() const {
		return _occurPattern == OCCUR_Once || _occurPattern == OCCUR_OnceOrMore;
	}
	inline bool IsBlankAcceptable() const {
		return _occurPattern == OCCUR_ZeroOrOnce || !_pExprDefault.IsNull();
	}
	inline bool IsVariableLength() const {
		return _occurPattern == OCCUR_ZeroOrMore || _occurPattern == OCCUR_OnceOrMore;
	}
	inline bool IsType(ValueType valType) const { return _valType == valType; }
	inline bool IsQuote() const { return IsType(VTYPE_quote); }
	inline bool IsAlwaysMappable() const {
		return (_occurPattern == OCCUR_Once || _occurPattern == OCCUR_ZeroOrOnce) &&
				!IsType(VTYPE_any) && !IsType(VTYPE_list) && !GetFlag(FLAG_ListVar);
	}
	inline bool ShouldImplicitMap(const Value &value) const {
		return (value.Is_list() || value.Is_iterator()) && !value.GetNoMapFlag() &&
			!IsType(VTYPE_list) && !IsType(VTYPE_iterator) && !GetFlag(FLAG_NoMap | FLAG_ListVar);
	}
	static String ToString(const Symbol *pSymbol, ValueType valType, OccurPattern occurPattern,
						   ULong flags, size_t nListElems, const Expr *pExprDefault);
	inline String ToString() const {
		return ToString(_pSymbol, _valType, _occurPattern, _flags, _nListElems, _pExprDefault.get());
	}
	void SetError_ArgumentType(Environment &env, const Value &value) const;
	void SetError_ArgumentMustBeList(Environment &env, const Value &value) const;
	static void SetError_InvalidArgument(Environment &env);
	static void SetError_NotEnoughArguments(Environment &env);
	static void SetError_TooManyArguments(Environment &env);
};

//-----------------------------------------------------------------------------
// DeclarationList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE DeclarationList : public std::vector<Declaration *, Allocator<Declaration *> > {
public:
	static const DeclarationList Empty;
public:
	inline DeclarationList() {}
	~DeclarationList();
	bool IsVariableLength() const;
	void SetAsLoose();
	//bool Compensate(Environment &env, ValueList &valList) const;
	String ToString() const;
};

//-----------------------------------------------------------------------------
// DeclarationOwner
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE DeclarationOwner : public DeclarationList {
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(DeclarationOwner)
public:
	inline DeclarationOwner() : _cntRef(1) {}
private:
	DeclarationOwner(const DeclarationOwner &declOwner);
	inline void operator=(const DeclarationOwner &declOwner) {}
private:
	~DeclarationOwner();
public:
	void Clear();
	inline DeclarationOwner *Clone() const { return new DeclarationOwner(*this); }
};

}

#endif
