#include "stdafx.h"
#include "Sample.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Sample
//-----------------------------------------------------------------------------
Sample *Sample::Create(const ValueList &valListX, int *pIndexMax)
{
	int nNodes = 0;
	foreach_const (ValueList, pValueX, valListX) {
		if (pValueX->GetDouble() != 0) nNodes++;
	}
	// We have to allocate memory for a bias and a teminator node as well as value nodes.
	// The structure Sample already has space for one feature_node, so we only add one
	// extra space for it.
	Sample *pSample = reinterpret_cast<Sample *>(
		::malloc(sizeof(Sample) + sizeof(struct feature_node) * (nNodes + 1)));
	pSample->y = 0;
	pSample->nNodes = nNodes + 2;
	int index = 0;
	int iNode = 0;
	foreach_const (ValueList, pValueX, valListX) {
		index++;
		if (pValueX->GetDouble() != 0) {
			pSample->nodes[iNode].index = index;
			pSample->nodes[iNode].value = pValueX->GetDouble();
			iNode++;
		}
	}
	// append nodes of bias and terminator.
	for (size_t i = 0; i < 2; i++, iNode++) {
		pSample->nodes[iNode].index = -1;
		pSample->nodes[iNode].value = 0;
	}
	if (pIndexMax != nullptr) *pIndexMax = index;
	return pSample;
}

Sample *Sample::Create(const Value &valueY, const ValueList &valListX, int *pIndexMax)
{
	Sample *pSample = Create(valListX, pIndexMax);
	pSample->y = valueY.GetDouble();
	return pSample;
}

//-----------------------------------------------------------------------------
// SampleOwner
//-----------------------------------------------------------------------------
SampleOwner::~SampleOwner()
{
	Clear();
}

void SampleOwner::Clear()
{
	foreach (SampleOwner, ppSample, *this) {
		::free(*ppSample);
	}
}

Gura_EndModuleScope(ml_linear)
