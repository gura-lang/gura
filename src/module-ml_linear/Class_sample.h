#ifndef __ML_LINEAR_CLASS_SAMPLE_H__
#define __ML_LINEAR_CLASS_SAMPLE_H__
#include <gura.h>
#include "Sample.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_sample declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(sample);

class Object_sample : public Object {
private:
	AutoPtr<Sample> _pSample;
public:
	Gura_DeclareObjectAccessor(sample)
public:
	Object_sample(Sample *pSample);
	virtual String ToString(bool exprFlag);
	inline Sample *GetEntity() { return _pSample.get(); }
};

Gura_EndModuleScope(ml_linear)

#endif
