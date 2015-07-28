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
class GURA_DLLDECLARE Class_any : public Class {
public:
	Class_any(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal &__to_delete__, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal &__to_delete__, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal &sig, Stream &stream, Value &value) const;
};

}

#endif
