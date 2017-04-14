#ifndef __ML_SVM_FEATURE_H__
#define __ML_SVM_FEATURE_H__
#include <gura.h>

Gura_BeginModuleScope(ml_svm)

//-----------------------------------------------------------------------------
// Feature
//-----------------------------------------------------------------------------
class Feature {
private:
	int _cntRef;
	// Content of _nodes should be as follows:
	// [without bias]
	//   {{index_0, value_0}, {index_1, value_1}, .. {index_k, value_k},
	//    {-1, 0}, {-1, 0}}
	// [with bias]
	//   {{index_0, value_0}, {index_1, value_1}, .. {index_k, value_k},
	//    {n, value_bias}, {-1, 0}}
	size_t _nNodes;
	std::unique_ptr<struct svm_node []> _nodes;
public:
	Gura_DeclareReferenceAccessor(Feature);
public:
	Feature();
protected:
	inline ~Feature() {}
public:
	static Feature *Create(Environment &env, const ValueList &valList);
	bool Store(Environment &env, const ValueList &valList);
	void ClearBias();
	void SetBias(int indexForBias, double bias);
	inline int GetIndexMax() const { return (_nNodes < 3)? 0 : _nodes[_nNodes - 3].index; }
	inline size_t CountNodes() const { return _nNodes; }
	inline struct svm_node *GetNodes() { return _nodes.get(); }
};

Gura_EndModuleScope(ml_svm)

#endif
