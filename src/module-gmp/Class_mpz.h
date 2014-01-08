#ifndef __GMP_CLASS_MPZ_H__
#define __GMP_CLASS_MPZ_H__

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpz declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(mpz);

class Object_mpz : public Object {
public:
	Gura_DeclareObjectAccessor(mpz)
public:
	Object_mpz();
	virtual String ToString(bool exprFlag);
};

Gura_EndModuleScope(gmp)

#endif
