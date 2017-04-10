#ifndef __ML_LINEAR_CLASS_MODEL_H__
#define __ML_LINEAR_CLASS_MODEL_H__
#include <gura.h>

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_model declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(model);

class Object_model : public Object {
private:
	struct model *_pModel;
public:
	Gura_DeclareObjectAccessor(model)
public:
	Object_model(struct model *pModel);
	virtual ~Object_model();
	virtual String ToString(bool exprFlag);
	inline struct model *GetEntity() { return _pModel; }
};

Gura_EndModuleScope(ml_linear)

#endif
