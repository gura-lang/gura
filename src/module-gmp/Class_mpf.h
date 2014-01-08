#ifndef __GMP_CLASS_MPF_H__
#define __GMP_CLASS_MPF_H__

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpf declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(mpf);

class Object_mpf : public Object {
private:
	mpf_class _num;
public:
	Gura_DeclareObjectAccessor(mpf)
public:
	Object_mpf(mpf_t num);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline const mpf_class &GetEntity() const { return _num; }
	inline static const mpf_class &GetEntity(const Value &value) {
		return GetObject(value)->GetEntity();
	}
};

Gura_EndModuleScope(gmp)

#endif
