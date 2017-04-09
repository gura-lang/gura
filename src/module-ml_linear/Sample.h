#ifndef __ML_LINEAR_SAMPLE_H__
#define __ML_LINEAR_SAMPLE_H__
#include <gura.h>
#include "Feature.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Sample
//-----------------------------------------------------------------------------
class Sample {
public:
	AutoPtr<Feature> _pFeature;
	double y;
	size_t nNodes;
	struct feature_node nodes[1];
public:
	static Sample *Create(const ValueList &valListX, int *pIndexMax);
	static Sample *Create(const Value &valueY, const ValueList &valListX, int *pIndexMax);
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
