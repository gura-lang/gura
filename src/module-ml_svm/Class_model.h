#ifndef __ML_SVM_CLASS_MODEL_H__
#define __ML_SVM_CLASS_MODEL_H__
#include <gura.h>

Gura_BeginModuleScope(ml_svm)

//-----------------------------------------------------------------------------
// Object_model declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(model);

class Object_model : public Object {
private:
	struct svm_model *_pModel;
public:
	Gura_DeclareObjectAccessor(model)
public:
	Object_model(struct svm_model *pModel);
	virtual ~Object_model();
	virtual String ToString(bool exprFlag);
	inline struct svm_model *GetEntity() { return _pModel; }
};

Gura_EndModuleScope(ml_svm)

#endif
