//=============================================================================
// Monitor
//=============================================================================
#ifndef __GURA_MONITOR_H__
#define __GURA_MONITOR_H__
#include "Expr.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Monitor
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Monitor {
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(Monitor);
public:
	Monitor();
private:
	inline Monitor(const Monitor &monitor) {}
};

}

#endif
