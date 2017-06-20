//=============================================================================
// Gura class: symbol
//=============================================================================
#ifndef __GURA_CLASS_SYMBOL_H__
#define __GURA_CLASS_SYMBOL_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_symbol
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_symbol : public ClassPrimitive {
public:
	Class_symbol(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
	virtual SerializeFmtVer GetSerializeFmtVer() const;
	virtual bool Serialize(Environment &env, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const;
};

}

#endif
