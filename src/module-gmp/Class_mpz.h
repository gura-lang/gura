#ifndef __GMP_CLASS_MPZ_H__
#define __GMP_CLASS_MPZ_H__

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpz declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(mpz);

class Object_mpz : public Object {
private:
	mpz_class _num;
public:
	Gura_DeclareObjectAccessor(mpz)
public:
	Object_mpz(mpz_t num);
	Object_mpz(const mpz_class &num);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
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
