//=============================================================================
// Random
//=============================================================================
#include "stdafx.h"

extern "C" {
#include "../dSFMT-src-2.2.1/dSFMT.h"
}

namespace Gura {

//-----------------------------------------------------------------------------
// RandomGenerator
//-----------------------------------------------------------------------------
void RandomGenerator::Initialize(ULong seed)
{
	::dsfmt_gv_init_gen_rand(seed);	// initialize random generator dSFMT
}

double RandomGenerator::Real2()
{
	return ::dsfmt_gv_genrand_close_open();
}

int RandomGenerator::operator()(int n)
{
	return static_cast<int>(Real2() * n);
}

}
