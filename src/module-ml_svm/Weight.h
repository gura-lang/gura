#ifndef __ML_SVM_WEIGHT_H__
#define __ML_SVM_WEIGHT_H__
#include <gura.h>

Gura_BeginModuleScope(ml_svm)

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

Gura_EndModuleScope(ml_svm)

#endif
