//=============================================================================
// Gura class: any
//=============================================================================
#ifndef __GURA_CLASS_ANY_H__
#define __GURA_CLASS_ANY_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_any
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_any : public ClassPrimitive {
public:
	Class_any(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
	virtual bool Serialize(Environment &env, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Stream &stream, Value &value) const;
};

}

#endif
