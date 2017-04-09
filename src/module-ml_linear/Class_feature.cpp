#include "stdafx.h"
#include "Class_feature.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Feature
//-----------------------------------------------------------------------------
Feature::Feature() : _nNodes(0), _nodes(nullptr)
{
}

Feature::~Feature()
{
	delete[] _nodes;
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

//-----------------------------------------------------------------------------
// Object_feature implementation
//-----------------------------------------------------------------------------
Object_feature::Object_feature() : Object(Gura_UserClass(feature))
{
}

String Object_feature::ToString(bool exprFlag)
{
	return String("<ml.linear.feature>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(feature)
{
	// Assignment of properties
	// Assignment of value
	Gura_AssignValue(feature, Value(Reference()));
}

Gura_EndModuleScope(ml_linear)
