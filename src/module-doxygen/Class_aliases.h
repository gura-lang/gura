//=============================================================================
// Class_aliases.h
//=============================================================================
#ifndef __GURA_DOXYGEN_CLASS_ALIASES_H__
#define __GURA_DOXYGEN_CLASS_ALIASES_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// doxygen.aliases class
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(aliases);

class Object_aliases : public Object {
public:
	Gura_DeclareObjectAccessor(aliases)
private:
	AutoPtr<Aliases> _pAliases;
public:
	inline Object_aliases(Aliases *pAliases) : Object(Gura_UserClass(aliases)), _pAliases(pAliases) {}
	virtual ~Object_aliases();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline const Aliases *GetAliases() const { return _pAliases.get(); }
};

Gura_EndModuleScope(doxygen)

#endif
