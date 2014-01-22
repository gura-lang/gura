//=============================================================================
// Random
//=============================================================================
#ifndef __GURA_RANDOM_H__
#define __GURA_RANDOM_H__

namespace Gura {

//-----------------------------------------------------------------------------
// Random
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Random {
public:
	static void Initialize(ULong seed);
	static double Real2();
	int operator()(int n);
};

}

#endif
