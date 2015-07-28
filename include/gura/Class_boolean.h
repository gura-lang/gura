//=============================================================================
// Gura class: boolean
//=============================================================================
#ifndef __GURA_CLASS_BOOLEAN_H__
#define __GURA_CLASS_BOOLEAN_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_boolean
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_boolean : public Class {
public:
	Class_boolean(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal &__to_delete__, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal &__to_delete__, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal &sig, Stream &stream, Value &value) const;
	virtual bool Format_d(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_u(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
};

}

#endif
