//=============================================================================
// Half
//=============================================================================
#ifndef __GURA_HALF_H__
#define __GURA_HALF_H__

namespace Gura {

class GURA_DLLDECLARE Half {
private:
	UInt16 _num;
public:
	inline Half(const Half &half) : _num(half._num) {}
	Half(Double num);
	Half(Float num);
public:
	inline Half &operator=(const Half &half) { _num = half._num; return *this; }
};

}

#endif
