//=============================================================================
// Gura class: Class
//=============================================================================
#ifndef __GURA_CLASS_CLASS_H__
#define __GURA_CLASS_CLASS_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_Class
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_Class : public ClassFundamental {
public:
	Class_Class(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
	virtual bool Serialize(Environment &env, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Stream &stream, Value &value) const;
};

}

#endif
