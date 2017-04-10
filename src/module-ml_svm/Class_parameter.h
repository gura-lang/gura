#ifndef __ML_SVM_CLASS_PARAMETER_H__
#define __ML_SVM_CLASS_PARAMETER_H__
#include <gura.h>
#include "Weight.h"

Gura_BeginModuleScope(ml_svm)

//-----------------------------------------------------------------------------
// Object_parameter declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(parameter);

class Object_parameter : public Object {
private:
	double _eps;
	struct svm_parameter _param;
	WeightOwner _weightOwner;
public:
	Gura_DeclareObjectAccessor(parameter)
public:
	Object_parameter();
	virtual ~Object_parameter();
	virtual String ToString(bool exprFlag);
	void AddWeight(int label, double weight);
	inline struct svm_parameter &GetEntity() { return _param; }
	struct svm_parameter &UpdateEntity();
};

Gura_EndModuleScope(ml_svm)

#endif
