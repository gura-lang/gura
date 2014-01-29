#ifndef __GMP_CLASS_MPF_H__
#define __GMP_CLASS_MPF_H__

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpf declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClassBegin(mpf)
public:
	virtual bool Format_d(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_u(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_b(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_o(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_x(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_e(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_f(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_g(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
Gura_DeclareUserClassEnd(mpf)

class Object_mpf : public Object {
private:
	mpf_class _num;
public:
	Gura_DeclareObjectAccessor(mpf)
public:
	Object_mpf(mpf_t num);
	Object_mpf(const mpf_class &num);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline const mpf_class &GetEntity() const { return _num; }
	inline static const mpf_class &GetEntity(const Value &value) {
		return GetObject(value)->GetEntity();
	}
	inline static const mpf_class &GetEntity(Args &args, size_t idx) {
		return GetObject(args, idx)->GetEntity();
	}
};

Gura_EndModuleScope(gmp)

#endif
