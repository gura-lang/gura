#ifndef __ML_LINEAR_SAMPLE_H__
#define __ML_LINEAR_SAMPLE_H__
#include <gura.h>

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Sample
//-----------------------------------------------------------------------------
struct Sample {
	double y;
	// Content of nodes[] should be as follows:
	// [without bias]
	//   {{index_0, value_0}, {index_1, value_1}, .. {index_k, value_k},
	//    {-1, 0}, {-1, 0}}
	// [with bias]
	//   {{index_0, value_0}, {index_1, value_1}, .. {index_k, value_k},
	//    {n, value_bias}, {-1, 0}}
	size_t nNodes;
	struct feature_node nodes[1];
	//AutoPtr<Feature> _pFeature;
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
