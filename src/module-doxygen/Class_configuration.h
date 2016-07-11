//=============================================================================
// Class_configuration.h
//=============================================================================
#ifndef __GURA_DOXYGEN_CLASS_CONFIGURATION_H__
#define __GURA_DOXYGEN_CLASS_CONFIGURATION_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// doxygen.configuration class
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(configuration);

class Object_configuration : public Object {
public:
	Gura_DeclareObjectAccessor(configuration)
private:
	AutoPtr<Configuration> _pCfg;
public:
	inline Object_configuration(Configuration *pCfg) :
				Object(Gura_UserClass(configuration)), _pCfg(pCfg) {}
	virtual ~Object_configuration();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline const Configuration *GetConfiguration() const { return _pCfg.get(); }
};

Gura_EndModuleScope(doxygen)

#endif
