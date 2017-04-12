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

//-----------------------------------------------------------------------------
// Iterator_sample
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Iterator_sample : public Iterator {
private:
	AutoPtr<SampleOwner> _pSampleOwner;
	size_t _idx;
public:
	inline Iterator_sample(SampleOwner *pSampleOwner) :
		Iterator(Finite), _pSampleOwner(pSampleOwner), _idx(0) {}
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleScope(ml_linear)

#endif
