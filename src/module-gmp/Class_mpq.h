#ifndef __GMP_CLASS_MPQ_H__
#define __GMP_CLASS_MPQ_H__

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpq declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(mpq);

class Object_mpq : public Object {
private:
	mpq_class _num;
public:
	Gura_DeclareObjectAccessor(mpq)
public:
	Object_mpq(mpq_t num);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline const mpq_class &GetEntity() const { return _num; }
	inline static const mpq_class &GetEntity(const Value &value) {
		return GetObject(value)->GetEntity();
	}
};

Gura_EndModuleScope(gmp)

#endif
