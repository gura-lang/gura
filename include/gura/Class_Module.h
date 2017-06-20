//=============================================================================
// Gura class: Module
//=============================================================================
#ifndef __GURA_CLASS_MODULE_H__
#define __GURA_CLASS_MODULE_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_Module
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_Module : public ClassFundamental {
public:
	Class_Module(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
	virtual SerializeFmtVer GetSerializeFmtVer() const;
	virtual bool Serialize(Environment &env, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const;
};

}

#endif
