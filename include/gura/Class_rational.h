//=============================================================================
// Gura class: rational
//=============================================================================
#ifndef __GURA_CLASS_RATIONAL_H__
#define __GURA_CLASS_RATIONAL_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_rational
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_rational : public ClassPrimitive {
public:
	Class_rational(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
	virtual SerializeFmtVer GetSerializeFmtVer() const;
	virtual bool Serialize(Environment &env, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const;
	virtual bool Format_d(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
};

}

#endif
