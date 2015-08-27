#ifndef __GMP_CLASS_MPF_H__
#define __GMP_CLASS_MPF_H__

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpf declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClassBegin(mpf)
public:
	virtual bool Format_d(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_u(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_b(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_o(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_x(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_e(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_f(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_g(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
Gura_DeclareUserClassEnd(mpf)

class Object_mpf : public Object {
private:
	mpf_class _num;
public:
	Gura_DeclareObjectAccessor(mpf)
public:
	Object_mpf(mpf_t num);
	Object_mpf(const mpf_class &num);
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline const mpf_class &GetEntity() const { return _num; }
	inline static const mpf_class &GetEntity(const Value &value) {
		return GetObject(value)->GetEntity();
	}
	inline static const mpf_class &GetEntity(Args &args, size_t idx) {
		return GetObject(args, idx)->GetEntity();
	}
	inline static const mpf_class &GetThisEntity(Args &args) {
		return GetObjectThis(args)->GetEntity();
	}
};

Gura_EndModuleScope(gmp)

#endif
