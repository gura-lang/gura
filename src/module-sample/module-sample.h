//-----------------------------------------------------------------------------
// Gura sample module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_SAMPLE_H__
#define __GURA_MODULE_SAMPLE_H__
#include <gura.h>

Gura_BeginModuleHeader(sample, sample)

Gura_DeclareUserSymbol(hoge_symbol);

//-----------------------------------------------------------------------------
// foo declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(foo);

class Object_foo : public Object {
public:
	Gura_DeclareObjectAccessor(foo)
public:
	inline Object_foo() : Object(Gura_UserClass(foo)) {}
	inline Object_foo(const Object_foo &obj) : Object(obj) {}
	virtual ~Object_foo();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
};

Gura_EndModuleHeader(sample, sample)

#endif
