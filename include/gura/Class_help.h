#ifndef __GURA_CLASS_HELP_H__
#define __GURA_CLASS_HELP_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_help
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_help : public Class {
public:
	Class_help(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
};

//-----------------------------------------------------------------------------
// Object_help
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_help : public Object {
public:
	Gura_DeclareObjectAccessor(help)
private:
	AutoPtr<Help> _pHelp;
public:
	Object_help(Environment &env, Help *pHelp);
	Object_help(Class *pClass, Help *pHelp);
	inline Help *GetHelp() { return _pHelp.get(); }
	inline const Help *GetHelp() const { return _pHelp.get(); }
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

}

#endif
