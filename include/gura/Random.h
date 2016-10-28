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
	static double Uniform_OpenOpen();	// (0, 1)
	static double Uniform_CloseOpen();	// [0, 1)
	static double Uniform_OpenClose();	// (0, 1]
	static double Normal();
	int operator()(int n);
};

}

#endif
