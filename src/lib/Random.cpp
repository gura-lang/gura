//=============================================================================
// Random
//=============================================================================
#include "stdafx.h"

extern "C" {
#undef UINT64_C
#include "../dSFMT-src-2.2.1/dSFMT.h"
}

namespace Gura {

//-----------------------------------------------------------------------------
// Random
//-----------------------------------------------------------------------------
void Random::Bootup()
{
	SetRandSeed(1234);
}

void Random::SetRandSeed(ULong seed)
{
	::dsfmt_gv_init_gen_rand(seed);	// initialize random generator dSFMT
}

// uniform random numbers (0, 1)
double Random::Uniform_OpenOpen()
{
	return ::dsfmt_gv_genrand_open_open();
}

// uniform random numbers [0, 1)
double Random::Uniform_CloseOpen()
{
	return ::dsfmt_gv_genrand_close_open();
}

// uniform random numbers (0, 1]
double Random::Uniform_OpenClose()
{
	return ::dsfmt_gv_genrand_open_close();
}

// normal distribution random numbers
double Random::Normal()
{
	return ::sqrt(-2.0 * ::log(Uniform_OpenOpen())) * ::sin(2.0 * Math_PI * Uniform_OpenOpen());
}

int Random::operator()(int n)
{
	return static_cast<int>(Uniform_CloseOpen() * n);
}

}
