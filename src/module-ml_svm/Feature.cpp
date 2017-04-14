#include "stdafx.h"
#include "Feature.h"

Gura_BeginModuleScope(ml_svm)

//-----------------------------------------------------------------------------
// Feature
//-----------------------------------------------------------------------------
Feature::Feature() : _cntRef(1), _nNodes(0), _nodes(nullptr)
{
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
	_nNodes = static_cast<int>(valList.size()) + 2;
	_nodes.reset(new struct svm_node [_nNodes]);
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
		size_t iNodeSet = iNode;
		// Search for a proper position to set the node if it has an index smaller than
		// the previous one,
		for ( ; iNodeSet > 0 && _nodes[iNodeSet - 1].index >= index; iNodeSet--) {
			if (_nodes[iNodeSet - 1].index == index) {
				env.SetError(
					ERR_IndexError,
					"wrong format for feature initialization: duplicated index");
				return false;
			}
		}
		if (iNodeSet < iNode) {
			::memmove(&_nodes[iNodeSet + 1], &_nodes[iNodeSet],
					  sizeof(_nodes[0]) * (iNode - iNodeSet));
		}
		_nodes[iNodeSet].index = index;
		_nodes[iNodeSet].value = valListPair[1].GetDouble();
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

Gura_EndModuleScope(ml_svm)
