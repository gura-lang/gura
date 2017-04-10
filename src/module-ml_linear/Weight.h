#ifndef __ML_LINEAR_WEIGHT_H__
#define __ML_LINEAR_WEIGHT_H__
#include <gura.h>

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Weight
//-----------------------------------------------------------------------------
struct Weight {
	int label;
	double weight;
public:
	inline Weight(int label_, double weight_) : label(label_), weight(weight_) {}
};

//-----------------------------------------------------------------------------
// WeightList
//-----------------------------------------------------------------------------
typedef std::vector<Weight> WeightList;

//-----------------------------------------------------------------------------
// WeightOwner
//-----------------------------------------------------------------------------
typedef WeightList WeightOwner;

Gura_EndModuleScope(ml_linear)

#endif
