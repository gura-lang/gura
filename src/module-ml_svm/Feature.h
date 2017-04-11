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
	//   {{index_0, value_0}, {index_1, value_1}, .. {index_k, value_k}, {-1, 0}}
	size_t _nNodes;
	struct svm_node *_nodes;
public:
	Gura_DeclareReferenceAccessor(Feature);
public:
	Feature();
protected:
	~Feature();
public:
	static Feature *Create(Environment &env, const ValueList &valList);
	bool Store(Environment &env, const ValueList &valList);
	inline int GetIndexMax() const { return (_nNodes < 2)? 0 : _nodes[_nNodes - 2].index; }
	inline struct svm_node *GetNodes() { return _nodes; }
};

Gura_EndModuleScope(ml_svm)

#endif
