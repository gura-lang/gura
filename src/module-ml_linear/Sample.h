#ifndef __ML_LINEAR_SAMPLE_H__
#define __ML_LINEAR_SAMPLE_H__
#include <gura.h>
#include "Feature.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Sample
//-----------------------------------------------------------------------------
class Sample {
private:
	double _label;
	AutoPtr<Feature> _pFeature;
public:
	inline Sample(double label, Feature *pFeature) : _label(label), _pFeature(pFeature) {}
	double GetLabel() const { return _label; }
	Feature *GetFeature() { return _pFeature.get(); }
};

//-----------------------------------------------------------------------------
// SampleList
//-----------------------------------------------------------------------------
typedef std::vector<Sample *> SampleList;

//-----------------------------------------------------------------------------
// SampleOwner
//-----------------------------------------------------------------------------
class SampleOwner : public SampleList {
public:
	~SampleOwner();
	void Clear();
};

Gura_EndModuleScope(ml_linear)

#endif
