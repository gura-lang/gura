#include "stdafx.h"
#include "Feature.h"

Gura_BeginModuleScope(ml_linear)

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

Feature *Feature::Create(const ValueList &valList, int *pIndexMax)
{
	AutoPtr<Feature> pFeature(new Feature());
	pFeature->Store(valList, pIndexMax);
	return pFeature.release();
}

void Feature::Store(const ValueList &valList, int *pIndexMax)
{
	int nNodes = 0;
	foreach_const (ValueList, pValue, valList) {
		if (pValue->GetDouble() != 0) nNodes++;
	}
	_nNodes = nNodes + 2;
	delete[] _nodes;
	_nodes = new struct feature_node[_nNodes];
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
	// append nodes of bias and terminator.
	for (size_t i = 0; i < 2; i++, iNode++) {
		_nodes[iNode].index = -1;
		_nodes[iNode].value = 0;
	}
	if (pIndexMax != nullptr) *pIndexMax = index;
}

void Feature::ClearBias()
{
	size_t iNode = _nNodes - 2;
	_nodes[iNode].index = -1;
	_nodes[iNode].value = 0;
}

void Feature::SetBias(int indexForBias, double bias)
{
	size_t iNode = _nNodes - 2;
	_nodes[iNode].index = indexForBias;
	_nodes[iNode].value = bias;
}

Gura_EndModuleScope(ml_linear)
