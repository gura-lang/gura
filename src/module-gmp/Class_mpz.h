//=============================================================================
// Gura class: gmp.mpz
//=============================================================================
#ifndef __GMP_CLASS_MPZ_H__
#define __GMP_CLASS_MPZ_H__

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpz declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClassBegin(mpz)
public:
	virtual bool Format_d(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_u(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_b(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_o(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_x(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_e(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_f(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_g(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
Gura_DeclareUserClassEnd(mpz)

class Object_mpz : public Object {
private:
	mpz_class _num;
public:
	Gura_DeclareObjectAccessor(mpz)
public:
	Object_mpz(mpz_t num);
	Object_mpz(const mpz_class &num);
	virtual bool DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline const mpz_class &GetEntity() const { return _num; }
	inline static const mpz_class &GetEntity(const Value &value) {
		return GetObject(value)->GetEntity();
	}
	inline static const mpz_class &GetEntity(Args &args, size_t idx) {
		return GetObject(args, idx)->GetEntity();
	}
};

Gura_EndModuleScope(gmp)

#endif
