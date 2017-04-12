#ifndef __ML_SVM_CLASS_PROBLEM_H__
#define __ML_SVM_CLASS_PROBLEM_H__
#include <gura.h>
#include "Sample.h"

Gura_BeginModuleScope(ml_svm)

//-----------------------------------------------------------------------------
// Object_problem declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(problem);

class Object_problem : public Object {
private:
	int _indexMax;
	struct svm_problem _prob;
	AutoPtr<SampleOwner> _pSampleOwner;
public:
	Gura_DeclareObjectAccessor(problem)
public:
	Object_problem();
	virtual ~Object_problem();
	virtual String ToString(bool exprFlag);
	struct svm_problem &UpdateEntity();
	void AddSample(double label, Feature *pFeature);
	inline const SampleOwner *GetSampleOwner() const { return _pSampleOwner.get(); }
};

Gura_EndModuleScope(ml_svm)

#endif

