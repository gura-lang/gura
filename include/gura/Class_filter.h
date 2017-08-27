//=============================================================================
// Gura class: filter
//=============================================================================
#ifndef __GURA_CLASS_FILTER_H__
#define __GURA_CLASS_FILTER_H__

#include "Class.h"
#include "Filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_filter : public ClassFundamental {
public:
	Class_filter(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

}

#endif
