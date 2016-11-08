//=============================================================================
// Array
//=============================================================================
#include "stdafx.h"
#include "gura/Array.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Array
//-----------------------------------------------------------------------------
void Array::UpdateMetrics()
{
	size_t stride = 1;
	foreach_reverse (Dimensions, pDim, _dims) {
		pDim->SetStride(stride);
		stride *= pDim->GetCount();
	}
	_cntTotal = stride;
}

bool Array::CheckShape(Signal &sig, const Array &arrayA, const Array &arrayB)
{
	if (Dimensions::IsSameShape(arrayA.GetDimensions(), arrayB.GetDimensions())) {
		return true;
	}
	sig.SetError(ERR_ValueError, "different dimension of arrays");
	return false;
}

bool Array::CheckElemwiseCalculatable(Signal &sig, const Array &arrayA, const Array &arrayB)
{
	if (Dimensions::IsElemwiseCalculatable(
			arrayA.GetDimensions(), arrayB.GetDimensions())) {
		return true;
	}
	sig.SetError(ERR_ValueError, "dimensions mismatch for the operation");
	return false;
}

//-----------------------------------------------------------------------------
// Array::Dimension
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Array::Dimensions
//-----------------------------------------------------------------------------
bool Array::Dimensions::IsSameShape(const Dimensions &dimsA, const Dimensions &dimsB)
{
	if (dimsA.size() != dimsB.size()) return false;
	Dimensions::const_iterator pDimA = dimsA.begin();
	Dimensions::const_iterator pDimB = dimsB.begin();
	for ( ; pDimA != dimsA.end(); pDimA++, pDimB++) {
		if (pDimA->GetCount() != pDimB->GetCount()) return false;
	}
	return true;
}

bool Array::Dimensions::IsElemwiseCalculatable(const Dimensions &dimsA, const Dimensions &dimsB)
{
	Dimensions::const_reverse_iterator pA = dimsA.rbegin();
	Dimensions::const_reverse_iterator pB = dimsB.rbegin();
	for ( ; pA != dimsA.rend() && pB != dimsB.rend(); pA++, pB++) {
		if (pA->GetCount() != pB->GetCount()) return false;
	}
	return true;
}

}