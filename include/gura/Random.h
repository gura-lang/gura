//=============================================================================
// Random
//=============================================================================
#ifndef __GURA_RANDOM_H__
#define __GURA_RANDOM_H__

namespace Gura {

//-----------------------------------------------------------------------------
// RandomGenerator
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE RandomGenerator {
public:
	static void Initialize(ULong seed);
	static double Real2();
	int operator()(int n);
};

}

#endif
