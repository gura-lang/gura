#include "stdafx.h"
#include "Sample.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Sample
//-----------------------------------------------------------------------------

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
		Sample::Delete(*ppSample);
	}
}

Gura_EndModuleScope(ml_linear)
