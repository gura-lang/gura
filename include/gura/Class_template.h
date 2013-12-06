#ifndef __GURA_CLASS_TEMPLATE_H__
#define __GURA_CLASS_TEMPLATE_H__

#include "Class.h"
#include "Template.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_template
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_template : public Class {
public:
	Class_template(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_template
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_template : public Object {
public:
	Gura_DeclareObjectAccessor(template)
private:
	AutoPtr<Template> _pTemplate;
public:
	Object_template(Environment &env, Template *pTemplate);
	Object_template(Class *pClass, Template *pTemplate);
	inline Template *GetTemplate() { return _pTemplate.get(); }
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

}

#endif
