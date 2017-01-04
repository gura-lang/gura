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
	virtual String ToString(bool exprFlag);
	inline mpf_class &GetEntity() { return _num; }
	inline const mpf_class &GetEntity() const { return _num; }
	inline static const mpf_class &GetEntity(const Value &value) {
		return GetObject(value)->GetEntity();
	}
	inline static const mpf_class &GetEntity(Argument &arg, size_t idx) {
		return GetObject(arg, idx)->GetEntity();
	}
	inline static const mpf_class &GetThisEntity(Argument &arg) {
		return GetObjectThis(arg)->GetEntity();
	}
};

Gura_EndModuleScope(gmp)

#endif
