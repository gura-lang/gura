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
class GURA_DLLDECLARE Class_Class : public Class {
public:
	Class_Class(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

}

#endif
