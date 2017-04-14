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
	//delete[] _nodes;
}

Feature *Feature::Create(Environment &env, const ValueList &valList)
{
	AutoPtr<Feature> pFeature(new Feature());
	if (!pFeature->Store(env, valList)) return nullptr;
	return pFeature.release();
}

bool Feature::Store(Environment &env, const ValueList &valList)
{
	if (valList.GetValueTypeOfElements() != VTYPE_list) {
		env.SetError(
			ERR_TypeError,
			"wrong format for feature initialization: the list must consist of pairs of two numbers");
		return false;
	}
	int indexPrev = 0;
	_nNodes = static_cast<int>(valList.size()) + 2;
	_nodes.reset(new struct feature_node [_nNodes]);
	size_t iNode = 0;
	foreach_const (ValueList, pValue, valList) {
		const ValueList &valListPair = pValue->GetList();
		if (valListPair.GetValueTypeOfElements() != VTYPE_number || valListPair.size() != 2) {
			env.SetError(
				ERR_TypeError,
				"wrong format for feature initialization: the list must consist of pairs of two numbers");
			return false;
		}
		int index = valListPair[0].GetInt();
		if (indexPrev >= index) {
			
		} else {
			_nodes[iNode].index = index;
			_nodes[iNode].value = valListPair[1].GetDouble();
		}
		iNode++;
	}	
	// append nodes of bias and terminator.
	for (size_t i = 0; i < 2; i++, iNode++) {
		_nodes[iNode].index = -1;
		_nodes[iNode].value = 0;
	}
	return true;
}

void Feature::ClearBias()
{
	if (_nNodes >= 2) {
		size_t iNode = _nNodes - 2;
		_nodes[iNode].index = -1;
		_nodes[iNode].value = 0;
	}
}

void Feature::SetBias(int indexForBias, double bias)
{
	if (_nNodes >= 2) {
		size_t iNode = _nNodes - 2;
		_nodes[iNode].index = indexForBias;
		_nodes[iNode].value = bias;
	}
}

Gura_EndModuleScope(ml_linear)
