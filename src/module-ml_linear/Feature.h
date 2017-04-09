#ifndef __ML_LINEAR_FEATURE_H__
#define __ML_LINEAR_FEATURE_H__
#include <gura.h>

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Feature
//-----------------------------------------------------------------------------
class Feature {
private:
	// Content of _nodes should be as follows:
	// [without bias]
	//   {{index_0, value_0}, {index_1, value_1}, .. {index_k, value_k},
	//    {-1, 0}, {-1, 0}}
	// [with bias]
	//   {{index_0, value_0}, {index_1, value_1}, .. {index_k, value_k},
	//    {n, value_bias}, {-1, 0}}
	size_t _nNodes;
	struct feature_node *_nodes;
public:
	Feature();
	~Feature();
	void Store(const ValueList &valList, int *pIndexMax);
	void ClearBias();
	void SetBias(int indexForBias, double bias);
	inline struct feature_node *GetNodes() { return _nodes; }
};

Gura_EndModuleScope(ml_linear)

#endif
