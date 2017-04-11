#include "stdafx.h"
#include "Feature.h"

Gura_BeginModuleScope(ml_svm)

//-----------------------------------------------------------------------------
// Feature
//-----------------------------------------------------------------------------
Feature::Feature() : _cntRef(1), _nNodes(0), _nodes(nullptr)
{
}

Feature::~Feature()
{
	delete[] _nodes;
}

Feature *Feature::Create(Environment &env, const ValueList &valList)
{
	AutoPtr<Feature> pFeature(new Feature());
	if (!pFeature->Store(env, valList)) return nullptr;
	return pFeature.release();
}

bool Feature::Store(Environment &env, const ValueList &valList)
{
	if (valList.GetValueTypeOfElements() != VTYPE_number) {
		env.SetError(ERR_TypeError,
					 "feature instance can be created from a list that consists of numbers");
		return false;
	}
	int nNodes = 0;
	foreach_const (ValueList, pValue, valList) {
		if (pValue->GetDouble() != 0) nNodes++;
	}
	_nNodes = nNodes + 1;
	delete[] _nodes;
	_nodes = new struct svm_node[_nNodes];
	int index = 0;
	int iNode = 0;
	foreach_const (ValueList, pValue, valList) {
		index++;
		if (pValue->GetDouble() != 0) {
			_nodes[iNode].index = index;
			_nodes[iNode].value = pValue->GetDouble();
			iNode++;
		}
	}
	// append a terminator node.
	_nodes[iNode].index = -1;
	_nodes[iNode].value = 0;
	return true;
}

Gura_EndModuleScope(ml_svm)
