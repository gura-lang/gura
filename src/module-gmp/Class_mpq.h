#ifndef __GMP_CLASS_MPQ_H__
#define __GMP_CLASS_MPQ_H__

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpq declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClassBegin(mpq)
public:
	virtual bool Format_d(Signal &__to_delete__, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_b(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_o(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_x(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
Gura_DeclareUserClassEnd(mpq)

class Object_mpq : public Object {
private:
	mpq_class _num;
public:
	Gura_DeclareObjectAccessor(mpq)
public:
	Object_mpq(mpq_t num);
	Object_mpq(const mpq_class &num);
	virtual bool DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline const mpq_class &GetEntity() const { return _num; }
	inline static const mpq_class &GetEntity(const Value &value) {
		return GetObject(value)->GetEntity();
	}
	inline static const mpq_class &GetEntity(Args &args, size_t idx) {
		return GetObject(args, idx)->GetEntity();
	}
	inline static const mpq_class &GetThisEntity(Args &args) {
		return GetThisObj(args)->GetEntity();
	}
};

Gura_EndModuleScope(gmp)

#endif
