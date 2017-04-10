#ifndef __ML_SVM_CLASS_FEATURE_H__
#define __ML_SVM_CLASS_FEATURE_H__
#include <gura.h>
#include "Feature.h"

Gura_BeginModuleScope(ml_svm)

//-----------------------------------------------------------------------------
// Object_feature declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(feature);

class Object_feature : public Object {
private:
	AutoPtr<Feature> _pFeature;
public:
	Gura_DeclareObjectAccessor(feature)
public:
	Object_feature(Feature *pFeature);
	virtual String ToString(bool exprFlag);
	inline Feature *GetEntity() { return _pFeature.get(); }
};

Gura_EndModuleScope(ml_svm)

#endif
